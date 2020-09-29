using System.Linq.Expressions;

namespace SQLExtension
{
    /// <summary>
    /// 表示命名参数表达式
    /// </summary>
    public class ParameterExpressionResolve : BaseSqlBuilder<ParameterExpression>
    {
        #region Override Base Class Methods
        /// <summary>
        /// Select
        /// </summary>
        /// <param name="expression">表达式树</param>
        /// <param name="sqlPack">sql打包对象</param>
        /// <returns>SqlPack</returns>
		public override SqlPack Select(ParameterExpression expression, SqlPack sqlPack)
        {
            var tableName = sqlPack.GetTableName(expression.Type);
            sqlPack.SetTableAlias(tableName);
            var tableAlias = sqlPack.GetTableAlias(tableName);
            sqlPack.SelectFields.Add($"{tableAlias}.*");
            return sqlPack;
        }
        #endregion
    }
}