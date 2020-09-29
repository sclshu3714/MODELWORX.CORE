using System.Linq.Expressions;

namespace SQLExtension
{
    /// <summary>
    /// 描述一个lambda表达式
    /// </summary>
    public class LambdaExpressionResolve : BaseSqlBuilder<LambdaExpression>
    {
        #region Override Base Class Methods
        /// <summary>
        /// Where
        /// </summary>
        /// <param name="expression">表达式树</param>
        /// <param name="sqlPack">sql打包对象</param>
        /// <returns>SqlPack</returns>
        public override SqlPack Where(LambdaExpression expression, SqlPack sqlPack)
        {
            SqlBuilderProvider.Where(expression.Body, sqlPack);
            return sqlPack;
        }
        #endregion
    }
}
