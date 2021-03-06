﻿using System;
using System.Collections.Generic;
using System.IO;
using System.Runtime.InteropServices;
using System.Text;

namespace VXHelper
{
    /// <summary>
    /// INI格式的配置文件
    /// </summary>
    public class XINI
    {
        [DllImport("kernel32")]
        private static extern int WritePrivateProfileString(string section, string key, string val, string filepath);
        [DllImport("kernel32")]
        private static extern int GetPrivateProfileString(string section, string key, string def, StringBuilder retval, int size, string filePath);
        private static object lockObject = new object();   //对象锁，用于控制多线程异步操作
        private static XINI ini = null;//全局设置
        //获取ini文件路径
        private static string workbenchPath = null;// Path.Combine(AppDomain.CurrentDomain.BaseDirectory, string.Format(@"Config\{0}", DesignINI));
        private static string INIFilename = null;
        private static Dictionary<string, dynamic> cache = new Dictionary<string, dynamic>();
        /// <summary>
        /// 全局设置
        /// </summary>
        public XINI() { }
        /// <summary>
        /// 默认的全局设置
        /// </summary>
        public static XINI INIEXT {
            get {
                lock(lockObject)  //上锁，解决多线程异步操作时的相互影响
                {
                    if(null == ini) {
                        ini = new XINI();
                    }
                }
                return ini;
            }
        }
        /// <summary>
        /// 工作区位置
        /// </summary>
        private static string StaticWorkbenchPath {
            get {
                if(string.IsNullOrEmpty(workbenchPath))
                    workbenchPath = XConfigurationManager.StaticGetConfiguration<string>("WorkbenchPath");
                if(string.IsNullOrEmpty(workbenchPath)) {
                    workbenchPath = Path.Combine(System.Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments), "MODELWORX","config");
                    XConfigurationManager.StaticSetConfiguration("WorkbenchPath", workbenchPath);
                }
                if(!Directory.Exists(workbenchPath))
                    Directory.CreateDirectory(workbenchPath);
                return workbenchPath;
            }
            set {
                workbenchPath = Path.Combine(value, "MODELWORX");
                XConfigurationManager.StaticSetConfiguration("WorkbenchPath", workbenchPath);
                if(!Directory.Exists(workbenchPath))
                    Directory.CreateDirectory(workbenchPath);
            }
        }
        /// <summary>
        /// Sets the application name override used for the configuration file name (e.g. Design).
        /// </summary>
        /// <param name="inifilename">配置文件名称,不带后缀</param>
        public void SetCustomOverride(string inifilename = "Design") {
            StaticSetCustomOverride(inifilename);
        }
        /// <summary>
        /// Sets the application name override used for the configuration file name (e.g. Design).
        /// </summary>
        /// <param name="inifilename">配置文件名称,不带后缀</param>
        public static void StaticSetCustomOverride(string inifilename = "Design") {
            INIFilename = Path.Combine(StaticWorkbenchPath, string.Format("{0}.ini", inifilename));
            if(!File.Exists(INIFilename))
                File.Create(INIFilename);
            cache.Clear();
        }
        /// <summary>
        /// return Value of the given setting as variant or defaultValue.
        /// </summary>
        /// <param name="section"></param>
        /// <param name="key"></param>
        /// <returns></returns>
        public T GetValue<T>(string section, string key) {
            return StaticGetValue<T>(section, key);
        }
        /// <summary>
        /// return Value of the given setting as variant or defaultValue.
        /// </summary>
        /// <param name="section"></param>
        /// <param name="key"></param>
        /// <returns></returns>
        public static T StaticGetValue<T>(string section, string key) {
            StringBuilder value = new StringBuilder(1024);
            GetPrivateProfileString(section, key, "", value, 1024, INIFilename);
            return XConvert.staticChangeType<T>(value);
        }
        /// <summary>
        /// return Value of the given setting as variant or defaultValue.
        /// </summary>
        /// <param name="section"></param>
        /// <param name="key"></param>
        /// <returns></returns>
        public string GetValue(string section, string key) {
            return StaticGetValue(section, key);
        }
        /// <summary>
        /// return Value of the given setting as variant or defaultValue.
        /// </summary>
        /// <param name="section"></param>
        /// <param name="key"></param>
        /// <returns></returns>
        public static string StaticGetValue(string section, string key) {
            StringBuilder s = new StringBuilder(1024);
            GetPrivateProfileString(section, key, "", s, 1024, INIFilename);
            return s.ToString();
        }
        /// <summary>
        /// Sets the variable with the given key and value, overwriting an existing value if overwrite is true (default).
        /// </summary>
        /// <param name="section"></param>
        /// <param name="key"></param>
        /// <param name="value"></param>
        /// <returns></returns>
        public int SetValue(string section, string key, string value) {
            return StaticSetValue(section, key, value);
        }
        /// <summary>
        /// Sets the variable with the given key and value, overwriting an existing value if overwrite is true (default).
        /// </summary>
        /// <param name="section"></param>
        /// <param name="key"></param>
        /// <param name="value"></param>
        /// <returns></returns>
        public static int StaticSetValue(string section, string key, string value) {
            return WritePrivateProfileString(section, key, value, INIFilename);
        }
        /// <summary>
        /// 删除节
        /// </summary>
        /// <param name="section">节点名</param>
        /// <returns>非零表示成功，零表示失败</returns>
        public int RemoveSection(string section) {
            return StaticRemoveSection(section);
        }
        /// <summary>
        /// 删除节
        /// </summary>
        /// <param name="section">节点名</param>
        /// <returns>非零表示成功，零表示失败</returns>
        public static int StaticRemoveSection(string section) {
            return StaticSetValue(section, null, null);
        }
        /// <summary>
        /// Removes the value for the given key.
        /// </summary>
        /// <param name="section">分组</param>
        /// <param name="key">属性名称</param>
        /// <returns>是否成功</returns>
        public int RemoveValue(string section, string key) {
            return StaticRemoveValue(section, key);
        }
        /// <summary>
        /// Removes the value for the given key.
        /// </summary>
        /// <param name="section">分组</param>
        /// <param name="key">属性名称</param>
        /// <returns>是否成功</returns>
        public static int StaticRemoveValue(string section, string key) {
            return StaticSetValue(section, key, null);
        }
    }
}
