using System;

namespace SQLExtension
{
    #region TableAttribute
    /// <summary>
    /// 指定表名
    /// </summary>
    [AttributeUsage(AttributeTargets.Class | AttributeTargets.Interface, AllowMultiple = false)]
    public class TableAttribute : Attribute
    {
        /// <summary>
        /// 构造函数
        /// </summary>
        /// <param name="name">数据库表名</param>
        public TableAttribute(string name = null)
        {
            if (name != null) this.Name = name;
        }

        /// <summary>
        /// 数据库表名
        /// </summary>
        public string Name { get; private set; }

        /// <summary>
        /// 数据库模式
        /// </summary>
        public string Schema { get; set; }
    }
    #endregion

    #region ColumnAttribute
    /// <summary>
    /// 指定列名
    /// </summary>
    [AttributeUsage(AttributeTargets.Property | AttributeTargets.Field, AllowMultiple = false, Inherited = true)]
    public class ColumnAttribute : Attribute
    {
        /// <summary>
        /// 构造函数
        /// </summary>
        /// <param name="name">列名</param>    
        public ColumnAttribute(string name = null)
        {
            if (name != null) this.Name = name;
        }

        /// <summary>
        /// 数据库表列名
        /// </summary>
        public string Name { get; private set; }

        /// <summary>
        /// 新增是否有效
        /// </summary>
        public bool Insert { get; set; } = true;

        /// <summary>
        /// 更新是否有效
        /// </summary>
        public bool Update { get; set; } = true;
    }
    #endregion

    #region KeyAttribute
    /// <summary>
    /// 指定表主键
    /// </summary>
    [AttributeUsage(AttributeTargets.Property | AttributeTargets.Field, AllowMultiple = false, Inherited = true)]
    public class KeyAttribute : Attribute
    {
        /// <summary>
        /// 构造函数
        /// </summary>
        /// <param name="name"></param>
        public KeyAttribute(string name = null)
        {
            if (name != null) this.Name = name;
        }

        /// <summary>
        /// 主键名称
        /// </summary>
        public string Name { get; set; }
    }
    #endregion
}
