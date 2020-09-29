﻿using System.Collections.Generic;
using System.Linq.Expressions;
using System.Text;

namespace SQLExtension
{
    /// <summary>
    /// 表示调用构造函数并初始化新对象的一个或多个成员
    /// </summary>
    public class MemberInitExpressionResolve : BaseSqlBuilder<MemberInitExpression>
    {
        #region Override Base Class Methods
        /// <summary>
        /// Insert
        /// </summary>
        /// <param name="expression">表达式树</param>
        /// <param name="sqlPack">sql打包对象</param>
        /// <returns>SqlPack</returns>
        public override SqlPack Insert(MemberInitExpression expression, SqlPack sqlPack)
        {
            if (sqlPack.DatabaseType != DatabaseType.Oracle)
                sqlPack.Sql.Append("(");
            var fields = new List<string>();
            foreach (MemberAssignment m in expression.Bindings)
            {
                var type = m.Member.DeclaringType.ToString().Contains("AnonymousType") ? sqlPack.DefaultType : m.Member.DeclaringType;
                (string columnName, bool isInsert, bool isUpdate) = sqlPack.GetColumnInfo(type, m.Member);
                if (isInsert)
                {
                    var value = m.Expression.ToObject();
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
                    sqlPack.Sql.Append(")");
                else
                    sqlPack.Sql.Append(" FROM DUAL");
            }
            sqlPack.Sql = new StringBuilder(string.Format(sqlPack.ToString(), string.Join(",", fields).TrimEnd(',')));
            return sqlPack;
        }

        /// <summary>
        /// Update
        /// </summary>
        /// <param name="expression">表达式树</param>
        /// <param name="sqlPack">sql打包对象</param>
        /// <returns>SqlPack</returns>
        public override SqlPack Update(MemberInitExpression expression, SqlPack sqlPack)
        {
            foreach (MemberAssignment m in expression.Bindings)
            {
                var type = m.Member.DeclaringType.ToString().Contains("AnonymousType") ? sqlPack.DefaultType : m.Member.DeclaringType;
                (string columnName, bool isInsert, bool isUpdate) = sqlPack.GetColumnInfo(type, m.Member);
                if (isUpdate)
                {
                    var value = m.Expression.ToObject();
                    if (value != null || (sqlPack.IsEnableNullValue && value == null))
                    {
                        sqlPack += columnName + " = ";
                        sqlPack.AddDbParameter(value);
                        sqlPack += ",";
                    }
                }
            }
            if (sqlPack[sqlPack.Length - 1] == ',')
                sqlPack.Sql.Remove(sqlPack.Length - 1, 1);
            return sqlPack;
        }
        #endregion
    }
}