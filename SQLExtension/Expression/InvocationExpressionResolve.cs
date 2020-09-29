using System.Linq.Expressions;

namespace SQLExtension
{
    /// <summary>
    /// 表示将委托或lambda表达式应用于参数表达式列表的表达式
    /// </summary>
    public class InvocationExpressionResolve : BaseSqlBuilder<InvocationExpression>
    {
        #region Override Base Class Methods
        /// <summary>
        /// Where
        /// </summary>
        /// <param name="expression">表达式树</param>
        /// <param name="sqlPack">sql打包对象</param>
        /// <returns>SqlPack</returns>
        public override SqlPack Where(InvocationExpression expression, SqlPack sqlPack)
        {
            SqlBuilderProvider.Where(expression.Expression, sqlPack);
            return sqlPack;
        }
        #endregion
    }
}
