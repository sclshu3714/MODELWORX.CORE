using System;
using System.Collections.Generic;
using System.Configuration;
using System.Linq;
using System.Text;

namespace VXHelper
{
    /// <summary>
    /// 配置管理器
    /// </summary>
    public class XConfigurationManager
    {
        private static Configuration config = null;
        private static AppSettingsSection appSettings = null;
        private static object lockObject = new object();   //对象锁，用于控制多线程异步操作
        private static XConfigurationManager ConfigManager = null;//全局设置

        /// <summary>
        /// 全局设置
        /// </summary>
        public XConfigurationManager() { }

        /// <summary>
        /// 默认的全局设置
        /// </summary>
        public static XConfigurationManager AppConfiguration {
            get {
                lock(lockObject)  //上锁，解决多线程异步操作时的相互影响
                {
                    if(null == ConfigManager) {
                        ConfigManager = new XConfigurationManager();
                    }
                }
                return ConfigManager;
            }
        }
        /// <summary>
        /// 索引器
        /// </summary>
        /// <param name="key"></param>
        /// <returns></returns>
        public string this[string key] {
            get { return GetConfiguration<string>(key); }
            set { AddConfiguration(key, value); }
        }

        /// <summary>
        /// 初始化
        /// </summary>
        public bool InitConfiguration() {
            StaticInitConfiguration();
            return true;
        }
        /// <summary>
        /// 初始化
        /// </summary>
        public static bool StaticInitConfiguration() {
            if(System.Reflection.Assembly.GetEntryAssembly() == null)
                return false;
            string assemblyConfigFile = System.Reflection.Assembly.GetEntryAssembly().Location;//读取程序集的配置文件
            config = System.Configuration.ConfigurationManager.OpenExeConfiguration(assemblyConfigFile);
            if(config == null)
                return false;
            ConfigurationSection ConfigSection = config.GetSection("appSettings");
            if(ConfigSection == null)
                return false;
            appSettings = (System.Configuration.AppSettingsSection)ConfigSection;//获取appSettings节点
            return true;
        }

        /// <summary>
        /// 获取配置节点值
        /// </summary>
        /// <param name="key"></param>
        public T GetConfiguration<T>(string key) {
            return StaticGetConfiguration<T>(key);
        }
        /// <summary>
        /// 获取配置节点值
        /// </summary>
        /// <param name="key"></param>
        public static T StaticGetConfiguration<T>(string key) {
            if(appSettings == null && !StaticInitConfiguration())
                return default(T);
            if(appSettings != null && appSettings.Settings != null && appSettings.Settings.AllKeys != null && appSettings.Settings.AllKeys.Contains(key)) {
                Type conversionType = typeof(T);
                return (T)Convert.ChangeType(appSettings.Settings[key].Value, conversionType);
            }
            return default(T);
        }

        /// <summary>
        /// 添加配置节点，保存
        /// </summary>
        /// <param name="key"></param>
        /// <param name="value"></param>
        public bool AddConfiguration(string key, string value) {
            return StaticAddConfiguration(key, value);
        }

        /// <summary>
        /// 添加配置节点，保存
        /// </summary>
        /// <param name="key"></param>
        /// <param name="value"></param>
        public static bool StaticAddConfiguration(string key, string value) {
            if(appSettings == null && !StaticInitConfiguration())
                return false;
            if(appSettings != null && appSettings.Settings != null && appSettings.Settings.AllKeys != null && !appSettings.Settings.AllKeys.Contains(key)) {
                appSettings.Settings.Add(key, value);
                config.Save(ConfigurationSaveMode.Modified);//一定要记得保存，写不带参数的config.Save()也可以
                ConfigurationManager.RefreshSection("appSettings");//刷新，否则程序读取的还是之前的值（可能已装入内存）
                return true;
            }
            else
                StaticUpdataConfiguration(key, value);
            return false;
        }

        /// <summary>
        /// 删除配置节点，保存
        /// </summary>
        /// <param name="key"></param>
        public void RemoveConfiguration(string key) {
            StaticRemoveConfiguration(key);
        }
        /// <summary>
        /// 删除配置节点，保存
        /// </summary>
        /// <param name="key"></param>
        public static void StaticRemoveConfiguration(string key) {
            if(appSettings == null && !StaticInitConfiguration())
                return;
            if(appSettings != null && appSettings.Settings != null) {
                appSettings.Settings.Remove(key);
                config.Save(ConfigurationSaveMode.Modified);//一定要记得保存，写不带参数的config.Save()也可以
                ConfigurationManager.RefreshSection("appSettings");//刷新，否则程序读取的还是之前的值（可能已装入内存）
            }
        }
        /// <summary>
        /// 修改配置节点值，保存
        /// </summary>
        /// <param name="key"></param>
        /// <param name="value"></param>
        public bool UpdataConfiguration(string key, string value) {
            return StaticUpdataConfiguration(key, value);
        }
        /// <summary>
        /// 修改配置节点值，保存
        /// </summary>
        /// <param name="key"></param>
        /// <param name="value"></param>
        public static bool StaticUpdataConfiguration(string key, string value) {
            if(appSettings == null && !StaticInitConfiguration())
                return false;
            if(appSettings != null && appSettings.Settings != null && appSettings.Settings.AllKeys != null && appSettings.Settings.AllKeys.Contains(key)) {
                appSettings.Settings[key].Value = value;
                config.Save(ConfigurationSaveMode.Modified);//一定要记得保存，写不带参数的config.Save()也可以
                ConfigurationManager.RefreshSection("appSettings");//刷新，否则程序读取的还是之前的值（可能已装入内存）
                return true;
            }
            return false;
        }
        /// <summary>
        /// 设置配置节点值,不保存
        /// </summary>
        /// <param name="key"></param>
        /// <param name="value"></param>
        public void SetConfiguration(string key, string value) {
            StaticSetConfiguration(key, value);
        }
        /// <summary>
        /// 设置配置节点值,不保存
        /// </summary>
        /// <param name="key"></param>
        /// <param name="value"></param>
        public static void StaticSetConfiguration(string key, string value) {
            if(appSettings == null && !StaticInitConfiguration())
                return;
            if(appSettings != null && appSettings.Settings != null && appSettings.Settings.AllKeys != null && appSettings.Settings.AllKeys.Contains(key))
                appSettings.Settings[key].Value = value;
            else if(appSettings != null && appSettings.Settings != null)
                appSettings.Settings.Add(key, value);
            config.Save(ConfigurationSaveMode.Modified);//一定要记得保存，写不带参数的config.Save()也可以
            ConfigurationManager.RefreshSection("appSettings");//刷新，否则程序读取的还是之前的值（可能已装入内存）
        }
        /// <summary>
        /// 保存配置节点
        /// </summary>
        public void SaveConfiguration() {
            StaticSaveConfiguration();
        }
        /// <summary>
        /// 保存配置节点
        /// </summary>
        public static void StaticSaveConfiguration() {
            if(appSettings == null && !StaticInitConfiguration())
                return;
            config.Save(ConfigurationSaveMode.Modified);//一定要记得保存，写不带参数的config.Save()也可以
            ConfigurationManager.RefreshSection("appSettings");//刷新，否则程序读取的还是之前的值（可能已装入内存）
        }
    }
}
