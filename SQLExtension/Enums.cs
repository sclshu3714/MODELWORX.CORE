namespace SQLExtension
{
    #region DatabaseType
    /// <summary>
    /// 数据库类型
    /// </summary>
    public enum DatabaseType
    {
        /// <summary>
        /// SqlServer数据库类型
        /// </summary>
        SQLServer,

        /// <summary>
        /// MySQL数据库类型
        /// </summary>
        MySQL,

        /// <summary>
        /// Oracle数据库类型
        /// </summary>
        Oracle,

        /// <summary>
        /// SQLite数据库类型
        /// </summary>
        SQLite,

        /// <summary>
        /// PostgreSQL数据库类型
        /// </summary>
        PostgreSQL,
    }
    #endregion

    #region OrderType
    /// <summary>
    /// 排序方式
    /// </summary>
    public enum OrderType
    {
        /// <summary>
        /// 升序
        /// </summary>
        Ascending,

        /// <summary>
        /// 降序
        /// </summary>
        Descending
    }
    #endregion

    #region DependencyInjectionType
    /// <summary>
    /// 依赖注入模式
    /// </summary>
    public enum DependencyInjectionType
    {
        /// <summary>
        /// 单例模式
        /// </summary>
        Singleton,

        /// <summary>
        /// 瞬时模式
        /// </summary>
        Transient,

        /// <summary>
        /// 作用域模式
        /// </summary>
        Scoped
    }
    #endregion
}