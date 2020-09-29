﻿using System.Collections.Generic;
using System.Linq;
using System.Linq.Expressions;
using System.Text;

namespace SQLExtension
{
    /// <summary>
    /// 表示包含集合初始值设定项的构造函数调用
    /// </summary>
    public class ListInitExpressionResolve : BaseSqlBuilder<ListInitExpression>
    {
        #region Override Base Class Methods
        /// <summary>
        /// Insert
        /// </summary>
        /// <param name="expression">表达式树</param>
        /// <param name="sqlPack">sql打包对象</param>
        /// <returns>SqlPack</returns>
        public override SqlPack Insert(ListInitExpression expression, SqlPack sqlPack)
        {
            var fields = new List<string>();
            var array = expression.ToObject() as IEnumerable<object>;
            for (var i = 0; i < array.Count(); i++)
            {
                if (sqlPack.DatabaseType != DatabaseType.Oracle)
                    sqlPack.Sql.Append("(");
                if (i > 0 && sqlPack.DatabaseType == DatabaseType.Oracle)
                    sqlPack.Sql.Append(" UNION ALL SELECT ");
                var properties = array.ElementAt(i)?.GetType().GetProperties();
                foreach (var p in properties)
                {
                    var type = p.DeclaringType.ToString().Contains("AnonymousType") ? sqlPack.DefaultType : p.DeclaringType;
                    (string columnName, bool isInsert, bool isUpdate) = sqlPack.GetColumnInfo(type, p);
                    if (isInsert)
                    {
                        var value = p.GetValue(array.ElementAt(i), null);
                        if (value != null || (sqlPack.IsEnableNullValue && value == null))
                        {
                            sqlPack.AddDbParameter(value);
                            if (!fields.Contains(columnName)) fields.Add(columnName);
                            sqlPack += ",";
                        }
                    }
                }
                if (sqlPack[sqlPack.Length - 1] == ',')
                {
                    sqlPack.Sql.Remove(sqlPack.Length - 1, 1);
                    if (sqlPack.DatabaseType != DatabaseType.Oracle)
                        sqlPack.Sql.Append("),");
                    else
                        sqlPack.Sql.Append(" FROM DUAL");
                }
            }
            if (sqlPack.Sql[sqlPack.Sql.Length - 1] == ',')
                sqlPack.Sql.Remove(sqlPack.Sql.Length - 1, 1);
            sqlPack.Sql = new StringBuilder(string.Format(sqlPack.ToString(), string.Join(",", fields).TrimEnd(',')));
            return sqlPack;
        }

        /// <summary>
        /// GroupBy
        /// </summary>
        /// <param name="expression">表达式树</param>
        /// <param name="sqlPack">sql打包对象</param>
        /// <returns>SqlPack</returns>
		public override SqlPack GroupBy(ListInitExpression expression, SqlPack sqlPack)
        {
            var array = (expression.ToObject() as IEnumerable<object>)?.ToList();
            if (array != null)
            {
                for (var i = 0; i < array.Count; i++)
                {
                    SqlBuilderProvider.GroupBy(Expression.Constant(array[i], array[i].GetType()), sqlPack);
                }
                sqlPack.Sql.Remove(sqlPack.Length - 1, 1);
            }
            return sqlPack;
        }

        /// <summary>
        /// OrderBy
        /// </summary>
        /// <param name="expression">表达式树</param>
        /// <param name="sqlPack">sql打包对象</param>
        /// <param name="orders">排序方式</param>
        /// <returns>SqlPack</returns>
        public override SqlPack OrderBy(ListInitExpression expression, SqlPack sqlPack, params OrderType[] orders)
        {
            var array = (expression.ToObject() as IEnumerable<object>)?.ToList();
            if (array != null)
            {
                for (var i = 0; i < array.Count; i++)
                {
                    SqlBuilderProvider.OrderBy(Expression.Constant(array[i], array[i].GetType()), sqlPack);
                    if (i <= orders.Length - 1)
                    {
                        sqlPack += $" { (orders[i] == OrderType.Descending ? "DESC" : "ASC")},";
                    }
                    else if (!array[i].ToString().ToUpper().Contains("ASC") && !array[i].ToString().ToUpper().Contains("DESC"))
                    {
                        sqlPack += " ASC,";
                    }
                    else
                    {
                        sqlPack += ",";
                    }
                }
                sqlPack.Sql.Remove(sqlPack.Length - 1, 1);
            }
            return sqlPack;
        }
        #endregion
    }
}
