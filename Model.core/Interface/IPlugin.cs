using System;
using System.Collections.Generic;
using System.Drawing;
using System.Text;
using Model.core.Users;

namespace Model.core.Interface
{
    /// <summary>
    /// 插件接口
    /// </summary>
    public interface IPlugin : IViewInfo
    {
        /// <summary>
        /// 模块Guid
        /// </summary>
        string PluginId { get; }
        /// <summary>
        /// 模块名称
        /// </summary>
        string PluginName { get; }
        /// <summary>
        /// 模块现在名称
        /// </summary>
        string PluginCaption { get; }
        /// <summary>
        /// 模块扩展属性
        /// </summary>
        object PluginTag { get; }
        /// <summary>
        /// 模块图标
        /// </summary>
        Image PluginIcon { get; }
        /// <summary>
        /// 模块归类
        /// </summary>
        string PluginModule { get; }
    }
}
