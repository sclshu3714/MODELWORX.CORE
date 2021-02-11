using System;
using System.Collections.Generic;
using System.IO;
using System.Text;
using XModel.Users;
using XModel.Events;

namespace VXHelper.Helps
{
    public class DesignSettings
    {
        #region 构型
        /// <summary>
        /// 全局设置
        /// </summary>
        public DesignSettings() { }
        /// <summary>
        /// 默认的全局设置
        /// </summary>
        public static DesignSettings Default {
            get {
                lock(lockObject)  //上锁，解决多线程异步操作时的相互影响
                {
                    if(null == designSettings) {
                        designSettings = new DesignSettings();
                    }
                }
                return designSettings;
            }
        }
        #endregion

        #region 格式转换
        /// <summary>
        /// app.config配置管理
        /// </summary>
        public static XConfigurationManager AppManager { 
            get { return XConfigurationManager.AppConfiguration; } 
        }
        /// <summary>
        /// ini备份扩展
        /// </summary>
        public static XINI INI {
            get { return XINI.INIEXT; }
        }
        /// <summary>
        /// Serialize序列化
        /// </summary>
        public static XSerialize Serialize {
            get { return XSerialize.Serialize; }
        }
        /// <summary>
        /// JSON转换帮助
        /// </summary>
        public static XJson JsonUntity {
            get { return XJson.JSONEXT; }
        }
        /// <summary>
        /// 加密解密，格式转换
        /// </summary>
        public static XConvert DConvert {
            get { return XConvert.CONVERTEXT; }
        }
        /// <summary>
        /// 内存清理
        /// </summary>
        public static void FlushMemory() {
            XFlushMemory.StaticFlushMemory();
        }
        #endregion

        #region 工作区位置
        /// <summary>
        /// 工作区位置
        /// </summary>
        public string WorkbenchPath {
            get {
                if(string.IsNullOrEmpty(workbenchPath))
                    workbenchPath = DesignSettings.AppManager.GetConfiguration<string>("WorkbenchPath");
                if(string.IsNullOrEmpty(workbenchPath)) {
                    workbenchPath = Path.Combine(System.Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments), "MODELWORX");
                    DesignSettings.AppManager.SetConfiguration("WorkbenchPath", workbenchPath);
                }
                if(!Directory.Exists(workbenchPath))
                    Directory.CreateDirectory(workbenchPath);
                return workbenchPath;
            }
            set {
                workbenchPath = Path.Combine(value, "MODELWORX");
                DesignSettings.AppManager.SetConfiguration("WorkbenchPath", workbenchPath);
                if(!Directory.Exists(workbenchPath))
                    Directory.CreateDirectory(workbenchPath);
            }
        }
        #endregion

        #region 字段属性
        /// <summary>
        /// 委托事件
        /// </summary>
        public event OperationEvent OnDelegateEvent {
            add { OnCustomEvent += value; }
            remove { OnCustomEvent -= value; }

        }
        /// <summary>
        /// 登录用户
        /// </summary>
        public static User LogonUser {
            get { return logonUser; }
            set { logonUser = value; }
        }
        private string workbenchPath = null;                //工作区
        private static User logonUser = null;             // 登录用户
        private static object lockObject = new object();    //对象锁，用于控制多线程异步操作
        private static DesignSettings designSettings = null;//全局设置
        /// <summary>
        /// 委托事件
        /// </summary>
        public OperationEvent OnCustomEvent { get; set; } = null;
        #endregion
    }
}
