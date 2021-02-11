using System;
using System.Collections.Generic;
using System.Text;

namespace XModel.Elements
{
    /// <summary>
    /// 插件反射基本信息
    /// </summary>
    public class XPluginAssembly
    {
        /// <summary>
        /// 插件反射基本信息
        /// </summary>
        public XPluginAssembly() { }
        /// <summary>
        /// 序号
        /// </summary>
        public int index { get { return _index; } set { _index = value; } }
        /// <summary>
        /// 插件编号
        /// </summary>
        public string PluginId { get { return _PluginId; } set { _PluginId = value; } }
        /// <summary>
        /// 插件名称
        /// </summary>
        public string PluginName { get { return _PluginName; } set { _PluginName = value; } }
        /// <summary>
        /// 插件说明
        /// </summary>
        public string PluginCaption { get { return _PluginCaption; } set { _PluginCaption = value; } }
        /// <summary>
        /// 插件分组
        /// </summary>
        public string PluginGroup { get { return _PluginGroup; } set { _PluginGroup = value; } }
        /// <summary>
        /// 是否可以加载插件
        /// </summary>
        public bool PluginLoaded { get { return _PluginLoaded; } set { _PluginLoaded = value; } }
        /// <summary>
        /// 插件程序集名称
        /// </summary>
        public string AssemblyName { get { return _AssemblyName; } set { _AssemblyName = value; } }
        /// <summary>
        /// 插件程序集区间名称
        /// </summary>
        public string AssemblyFullName { get { return _AssemblyFullName; } set { _AssemblyFullName = value; } }
        /// <summary>
        /// 插件备注信息
        /// </summary>
        public string PluginTag { get { return _PluginTag; } set { _PluginTag = value; } }
        /// <summary>
        /// 插件位置
        /// </summary>
        public string PluginPath {
            get {
                if (_PluginPath != null && System.IO.File.Exists(_PluginPath))
                    return _PluginPath;
                else
                    return System.IO.Path.Combine(AppDomain.CurrentDomain.BaseDirectory, "Plugins", string.Format("{0}.dll", PluginName));
            }
            set { _PluginPath = value; }
        }
        private int _index = -1;
        private string _PluginId = null;
        private string _PluginName = null;
        private string _PluginCaption = null;
        private string _PluginGroup = null;
        private bool _PluginLoaded = true;
        private string _AssemblyName = null;
        private string _AssemblyFullName = null;
        private string _PluginTag = null;
        private string _PluginPath = null;
    }
}
