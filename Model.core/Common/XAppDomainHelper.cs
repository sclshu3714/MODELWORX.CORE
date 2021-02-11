using System;
using System.Collections.Generic;
using System.IO;
using System.Reflection;
using System.Text;
using XModel.Interface;

namespace XModel.Common
{
    /// <summary>
    /// 
    /// </summary>
    public class XAppDomainHelper
    {
        /// <summary>
        /// 构建插件
        /// </summary>
        /// <param name="dllName">插件反射基本信息</param>
        /// <param name="DesignPlugin">插件结果</param>
        /// <returns>应用程序域</returns>
        public static AppDomain DesignPluginInitialize(string dllName, ref XDesignPlugin DesignPlugin)
        {
            
            //PermissionSet perSet = new PermissionSet(PermissionState.Unrestricted);
            //AppDomainSetup setup = new AppDomainSetup();
            ////应用程序目录
            //setup.ApplicationName = dllName;
            ////应用程序根目录
            //setup.ApplicationBase = AppDomain.CurrentDomain.BaseDirectory;
            ////子目录（相对形式）在AppDomainSetup中加入外部程序集的所在目录，多个目录用分号间隔
            ////setup.PrivateBinPath = string.Format("{0};{1};{2};{3};{4};{5};{6};{7};{8};{9};" +
            ////                                    "{10};{11};{12};{13};{14};{15};{16};{17};{18};{19};{20};" +
            ////                                    "{20};{21};{22};{23};{24};{25};{26};{27};{28};{28};",
            ////Path.Combine(AppDomain.CurrentDomain.BaseDirectory),
            ////Path.Combine(AppDomain.CurrentDomain.BaseDirectory, "Plugins"),
            ////设置缓存目录
            //setup.CachePath = Path.Combine(setup.ApplicationBase, "Cache");
            ////获取或设置指示影像复制是打开还是关闭
            //setup.ShadowCopyFiles = "true";
            ////获取或设置目录的名称，这些目录包含要影像复制的程序集
            //setup.ShadowCopyDirectories = setup.ApplicationBase;
            //setup.DisallowBindingRedirects = true;
            //setup.DisallowCodeDownload = true;
            //setup.ConfigurationFile = AppDomain.CurrentDomain.SetupInformation.ConfigurationFile;
            ////Create evidence for the new application domain from evidence of
            //Evidence adevidence = AppDomain.CurrentDomain.Evidence;
            string friendlyName = $"{Path.GetFileNameWithoutExtension(dllName)}Domain";
            AppDomain appDomain = AppDomain.CreateDomain(friendlyName);
            ////iDesignPlugin = (IDesignModelPlugin)appDomain.CreateInstance("DesignData", "com.Design.Data.Interface.IDesignModelPlugin").Unwrap();
            //String assemblyName = Assembly.GetExecutingAssembly().GetName().FullName;
            ////AppDomain.CurrentDomain.SetShadowCopyFiles();
            ////iDesignPlugin = (IDesignModelPlugin)appDomain.CreateInstanceAndUnwrap(assemblyName, typeof(IDesignModelPlugin).FullName);
            //DesignPlugin = (XDesignPlugin)appDomain.CreateInstanceAndUnwrap(plugin.AssemblyName, plugin.AssemblyFullName);
            //////iDesignPlugin = iDesignPlugin.LoadAssembly(plugin);
            ////string fullName = iDesignPlugin.LoadedAssembly(plugin.PluginPath);
            ////if (fullName != null)
            ////{
            ////    Assembly pluginAssembly = iDesignPlugin.PluginAssembly;
            ////    iDesignPlugin = (IDesignModelPlugin)pluginAssembly.CreateInstance(fullName);
            ////    iDesignPlugin.PluginAssembly = pluginAssembly;
            ////}
            return appDomain;
        }
        /// <summary>
        /// 卸载插件模块
        /// </summary>
        /// <param name="iDesignPlugin">插件类</param>
        /// <returns>是否加载完成</returns>
        public static bool UnLoadPlugin(XDesignPlugin DesignPlugin)
        {
            if (LoadedAssemblys.ContainsKey(DesignPlugin.PluginId)) {
                AppDomain.Unload(LoadedAssemblys[DesignPlugin.PluginId]);
                LoadedAssemblys.Remove(DesignPlugin.PluginId);
            }

            return true;
        }

        #region 字段属性
        private static Dictionary<string, AppDomain> LoadedAssemblys;
        #endregion
    }
}
