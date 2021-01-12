using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text.RegularExpressions;
using System.Threading;
using System.Windows.Forms;

namespace UniversalCAD
{
    static class Program
    {
        /// <summary>
        /// 应用程序的主入口点。
        /// </summary>
        [STAThread]
        static void Main()
        {
            //设置应用程序处理异常方式：ThreadException处理
            //Application.SetUnhandledExceptionMode(UnhandledExceptionMode.CatchException);
            Application.SetUnhandledExceptionMode(UnhandledExceptionMode.CatchException);
            //处理UI线程异常
            Application.ThreadException += new System.Threading.ThreadExceptionEventHandler(Application_ThreadException);
            //处理非UI线程异常
            AppDomain.CurrentDomain.UnhandledException += new UnhandledExceptionEventHandler(CurrentDomain_UnhandledException);
            //当程序集(Assembly)通过反射加载失败的时候会触发AssemblyResolve事件，这里注册AssemblyResolve事件的处理函数为CurrentDomain_AssemblyResolve
            AppDomain.CurrentDomain.AssemblyResolve += new ResolveEventHandler(CurrentDomain_AssemblyResolve);
            //当类型(Type)通过反射加载失败的时候会触发TypeResolve事件，这里注册TypeResolve事件的处理函数为CurrentDomain_TypeResolve
            AppDomain.CurrentDomain.TypeResolve += new ResolveEventHandler(CurrentDomain_TypeResolve);

            //DevExpress.UserSkins.BonusSkins.Register();
            //DevExpress.Skins.SkinManager.EnableFormSkins();
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);

            //DevExpress.UserSkins.BonusSkins.Register();//皮肤
            //DevExpress.Skins.SkinManager.EnableFormSkins();
            //string SkinName = "DevExpress Style";// "Office 2019 Colorful";// DesignSettings.AppConfiguration.GetConfig<string>("SkinName");
            //if (SkinName != default(string))
            //    DevExpress.LookAndFeel.UserLookAndFeel.Default.SetSkinStyle(SkinName);
            //else
            //    DevExpress.LookAndFeel.UserLookAndFeel.Default.SetSkinStyle("DevExpress Style");
            Application.Run(new MainForm());
        }
        #region 异常捕获
        private static void CurrentDomain_UnhandledException(object sender, UnhandledExceptionEventArgs e)
        {
            string strErr = GetExceptionMsg(e.ExceptionObject as Exception, e.ToString());
            //string logName = VXRuntime.WriteSystemLog(strErr, "ERROR");
        }

        private static void Application_ThreadException(object sender, ThreadExceptionEventArgs e)
        {
            string strErr = GetExceptionMsg(e.Exception, e.ToString());
            //string logName = VXRuntime.WriteSystemLog(strErr, "ERROR");
        }

        static string GetExceptionMsg(Exception ex, string backStr)
        {
            System.Text.StringBuilder sbMsg = new System.Text.StringBuilder();
            sbMsg.AppendLine("****************************异常文本****************************");
            sbMsg.AppendLine("【出现时间】：" + DateTime.Now.ToString());
            if (ex != null)
            {
                sbMsg.AppendLine("【异常类型】：" + ex.GetType().Name);
                sbMsg.AppendLine("【异常信息】：" + ex.Message);
                sbMsg.AppendLine("【堆栈调用】：" + ex.StackTrace);
                sbMsg.AppendLine("【异常方法】：" + ex.TargetSite);
            }
            else
            {
                sbMsg.AppendLine("【未处理异常】：" + backStr);
            }
            sbMsg.AppendLine("***************************************************************");
            return sbMsg.ToString();
        }
        #endregion
        #region 对外解析dll失败时调用
        /// <summary>
        /// AssemblyResolve事件的处理函数，该函数用来自定义程序集加载逻辑
        /// </summary>
        /// <param name="sender">事件引发源</param>
        /// <param name="args">事件参数，从该参数中可以获取加载失败的程序集的名称</param>
        /// <returns></returns>
        private static Assembly CurrentDomain_AssemblyResolve(object sender, ResolveEventArgs args)
        {
            string assembly_dllName = Regex.Split(args.Name, @"\s*,\s*")[0];
            //string logName = SystemRuntimeHelper.WriteSystemLog(assembly_dllName, "ERROR");
            switch (assembly_dllName)
            {
                default:
                    string assembly_dll = new AssemblyName(args.Name).Name + ".dll";
                    string assembly_directory = string.Format(@"{0}3dparty\", AppDomain.CurrentDomain.BaseDirectory); //"Parent directory of the C++ dlls";
                    if (assembly_dll.Contains("resources"))
                        assembly_directory = string.Format(@"{0}zh-Hans\", AppDomain.CurrentDomain.BaseDirectory); //"Parent directory of the C++ dlls";
                    string assembly_dllPath = GetAssembly_dllPath(assembly_directory, assembly_dll);
                    if (File.Exists(assembly_dllPath))
                    {
                        Assembly assembly = null;
                        if (Environment.Is64BitProcess)
                            assembly = Assembly.LoadFrom(assembly_dllPath);
                        else
                            assembly = Assembly.LoadFrom(assembly_dllPath);
                        return assembly;
                    }
                    break;
            }
            return null;
        }
        /// <summary>
        /// 便利文件夹获取dll
        /// </summary>
        /// <param name="assembly_dllName"></param>
        private static string GetAssembly_dllPath(string BaseDirectory, string assembly_dllName)
        {
            try
            {
                string assembly_directory = BaseDirectory;
                string assembly_dllPath = string.Format(@"{0}{1}", BaseDirectory, assembly_dllName);
                if (File.Exists(assembly_dllPath))
                    return assembly_dllPath;
                DirectoryInfo assembly_directoryInfo = new DirectoryInfo(BaseDirectory);
                foreach (FileInfo fileInfo in assembly_directoryInfo.GetFiles())
                {
                    if (fileInfo.Name == assembly_dllName)
                        return fileInfo.FullName;
                }
                foreach (DirectoryInfo childInfo in assembly_directoryInfo.GetDirectories())
                {
                    assembly_dllPath = string.Format(@"{0}\{1}", childInfo.FullName, assembly_dllName);
                    if (File.Exists(assembly_dllPath))
                        return assembly_dllPath;
                    assembly_dllPath = GetAssembly_dllPath(childInfo.FullName, assembly_dllName);
                    if (File.Exists(assembly_dllPath))
                        return assembly_dllPath;
                }
                if (File.Exists(assembly_dllPath))
                    return assembly_dllPath;
            }
            catch (Exception)
            {
            }
            return null;
        }
        /// <summary>
        /// TypeResolve事件的处理函数，该函数用来自定义程序集加载逻辑
        /// </summary>
        /// <param name="sender">事件引发源</param>
        /// <param name="args">事件参数，从该参数中可以获取加载失败的类型的名称</param>
        /// <returns></returns>
        private static Assembly CurrentDomain_TypeResolve(object sender, ResolveEventArgs args)
        {
            ////根据加载失败类型的名字找到其所属程序集并返回
            //if (Regex.Split(args.Name,@"\s*,\s*")[0] == "MessageDisplay.MessageDisplayHelper")
            //{
            //    //我们自定义的程序集加载逻辑知道MessageDisplay.MessageDisplayHelper类属于MessageDisplay程序集，而MessageDisplay程序集在C:\AssemblyResolverConsle\Reference\MessageDisplay.dll这个路径下，所以这里加载这个路径下的dll文件作为TypeResolve事件处理函数的返回值
            //    return Assembly.LoadFile(@"C:\AssemblyResolverConsle\Reference\MessageDisplay.dll");
            //}
            ////如果TypeResolve事件的处理函数返回null，说明TypeResolve事件的处理函数也不知道加载失败的类型属于哪个程序集
            string assembly_dllName = Regex.Split(args.Name, @"\s*,\s*")[0];
            switch (assembly_dllName)
            {
                default:
                    string assembly_dll = new AssemblyName(args.Name).Name + ".dll";
                    string assembly_directory = string.Format(@"{0}3dparty\", AppDomain.CurrentDomain.BaseDirectory); //"Parent directory of the C++ dlls";
                    string assembly_dllPath = GetAssembly_dllPath(assembly_directory, assembly_dll);
                    if (File.Exists(assembly_dllPath))
                    {
                        Assembly assembly = null;
                        if (Environment.Is64BitProcess)
                            assembly = Assembly.LoadFrom(assembly_dllPath);
                        else
                            assembly = Assembly.LoadFrom(assembly_dllPath);
                        return assembly;
                    }
                    break;
            }
            return null;
        }
        #endregion
    }
}
