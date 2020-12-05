using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;

namespace VXHelper
{
    public class VXRuntime
    {
        private static readonly object lockObject = new object();   //对象锁，用于控制多线程异步操作
        private static VXRuntime runtime = null;//全局设置

        /// <summary>
        /// 全局设置
        /// </summary>
        public VXRuntime() { }
        /// <summary>
        /// 默认的全局设置
        /// </summary>
        public static VXRuntime SystemRuntime
        {
            get
            {
                lock (lockObject)  //上锁，解决多线程异步操作时的相互影响
                {
                    if (null == runtime)
                    {
                        runtime = new VXRuntime();
                    }
                }
                return runtime;
            }
        }

        /// <summary>
        /// 写文件
        /// </summary>
        /// <param name="log">日志内容</param>
        /// <param name="state">状态级别</param>
        public static string WriteSystemLog(string log, string state)
        {
            if (!System.IO.Directory.Exists("Log"))
                System.IO.Directory.CreateDirectory("Log");
            DeleteOldFiles("Log", 30);//删除30天前的log文件
            string startlog = string.Format("**************************** Start {0} 【出现时间】：{1} ****************************", state, DateTime.Now.ToString());
            string elog = string.Format(" End {0} ", state);
            string endlog = string.Format("{0}{1}{2}", "*".PadLeft((startlog.Length - elog.Length) / 2, '*'), elog, "*".PadRight((startlog.Length - elog.Length) / 2, '*'));
            StringBuilder logMessage = new StringBuilder();
            logMessage.AppendLine(startlog);
            logMessage.AppendLine(log);
            logMessage.AppendLine(endlog);
            string logName = string.Format("{0}.log", DateTime.Now.ToString("yyyy-MM-dd"));
            IEnumerable<string> oldMessage = null;
            if (File.Exists(string.Format(@"Log\{0}", logName)))
            {
                oldMessage = File.ReadAllLines(string.Format(@"Log\{0}", logName), Encoding.UTF8);
                if (oldMessage.Count() > 1000)
                {
                    oldMessage = oldMessage.Take(1000);
                    int count = 1000;
                    while (oldMessage.Count() > 0 && !oldMessage.Last().Contains("****"))
                        oldMessage = oldMessage.Take(count--);
                }
                while (File.Exists(string.Format(@"Log\{0}", logName)))
                {
                    try { File.Delete(string.Format(@"Log\{0}", logName)); }
                    catch (Exception) { }
                }
            }
            File.WriteAllText(string.Format(@"Log\{0}", logName), string.Format("\r\n{0}", logMessage), Encoding.UTF8);
            if (oldMessage != null && oldMessage.Count() > 0)
                File.AppendAllLines(string.Format(@"Log\{0}", logName), oldMessage, Encoding.UTF8);
            return logName;
        }
        /// <summary>
        /// 删除文件夹strDir中nDays天以前的文件
        /// </summary>
        /// <param name="folder">文件夹</param>
        /// <param name="days">时间</param>
        public static void DeleteOldFiles(string folder, int days = 30)
        {
            try
            {
                if (!Directory.Exists(folder) || days < 1) return;
                var now = DateTime.Now;
                foreach (var file in Directory.GetFileSystemEntries(folder).Where(f => File.Exists(f) && Path.GetFileNameWithoutExtension(f).Contains('-')))
                {
                    var time = File.GetCreationTime(file);
                    var elapsedTicks = now.Ticks - time.Ticks;
                    var elapsedSpan = new TimeSpan(elapsedTicks);
                    if (elapsedSpan.TotalDays > days) File.Delete(file);
                }
            }
            catch (Exception)
            {
                // ignored
            }
        }

        /// <summary>
        /// 运行cmd命令
        /// 会显示命令窗口
        /// </summary>
        /// <param name="cmdExe">指定应用程序的完整路径</param>
        /// <param name="cmdStr">执行命令行参数</param>
        public static bool RunCmd(string cmdExe, string cmdStr)
        {
            bool result = false;
            try
            {
                using (Process myPro = new Process())
                {
                    //指定启动进程是调用的应用程序和命令行参数
                    ProcessStartInfo psi = new ProcessStartInfo(cmdExe, cmdStr);
                    myPro.StartInfo = psi;
                    myPro.Start();
                    myPro.WaitForExit();
                    result = true;
                }
            }
            catch
            {

            }
            return result;
        }

        /// <summary>
        /// 运行cmd命令
        /// 不显示命令窗口
        /// </summary>
        /// <param name="cmdExe">指定应用程序的完整路径</param>
        /// <param name="cmdStr">执行命令行参数</param>
        public static bool RunCmd2(string cmdExe, string cmdStr)
        {
            bool result = false;
            try
            {
                using (Process myPro = new Process())
                {
                    myPro.StartInfo.FileName = "cmd.exe";
                    myPro.StartInfo.UseShellExecute = false;
                    myPro.StartInfo.RedirectStandardInput = true;
                    myPro.StartInfo.RedirectStandardOutput = true;
                    myPro.StartInfo.RedirectStandardError = true;
                    myPro.StartInfo.CreateNoWindow = true;
                    myPro.Start();
                    //如果调用程序路径中有空格时，cmd命令执行失败，可以用双引号括起来 ，在这里两个引号表示一个引号（转义）
                    string str = string.Format(@"""{0}"" {1} {2}", cmdExe, cmdStr, "&exit");

                    myPro.StandardInput.WriteLine(str);
                    myPro.StandardInput.AutoFlush = true;
                    myPro.WaitForExit();

                    result = true;
                }
            }
            catch
            {

            }
            return result;
        }
    }
}
