using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Reflection;
using System.Runtime.InteropServices;
using System.Text;
using System.Text.RegularExpressions;

namespace VXHelper
{
    public class VXFlushMemory
    {
        private static object lockObject = new object();   //对象锁，用于控制多线程异步操作
        private static VXFlushMemory flushMemory = null;//全局设置

        /// <summary>
        /// 全局设置
        /// </summary>
        public VXFlushMemory() { }
        /// <summary>
        /// 默认的全局设置
        /// </summary>
        public static VXFlushMemory FlushMemoryExt {
            get {
                lock(lockObject)  //上锁，解决多线程异步操作时的相互影响
                {
                    if(null == flushMemory) {
                        flushMemory = new VXFlushMemory();
                    }
                }
                return flushMemory;
            }
        }
        private static List<string> NoEmptys = new List<string>(){ "qmbsrv", "RuntimeBroker", "Memory Compression", "System", "Idle",
                    "SgrmBroker", "wininit", "services", "WmiPrvSE", "csrss", "SecurityHealthService", "Registry", "emdctl",
                    "cmd", "smss", "svchost" };
        /// <summary>
        /// 释放内存
        /// </summary>
        /// <param name="hwProc"></param>
        /// <returns></returns>
        [DllImport("psapi.dll")]
        static extern int EmptyWorkingSet(IntPtr hwProc);
        /// <summary>
        /// 释放内存
        /// </summary>
        public void FlushMemory() {
            staticFlushMemory();
        }
        /// <summary>
        /// 释放内存
        /// </summary>
        public static void staticFlushMemory() {
            GC.Collect();
            GC.WaitForPendingFinalizers();
            Process[] processes = Process.GetProcesses();
            foreach(Process process in processes) {
                //以下系统进程没有权限，所以跳过，防止出错影响效率。
                if(NoEmptys.Contains(process.ProcessName) || process.ProcessName.Contains("System"))
                    continue;
                try {
                    EmptyWorkingSet(process.Handle);
                }
                catch {
                    if(!NoEmptys.Contains(process.ProcessName))
                        NoEmptys.Add(process.ProcessName);
                }
            }
        }
        /// <summary>
        /// 结束进程
        /// </summary>
        /// <param name="fileName"></param>
        /// <returns></returns>
        public static bool Taskkill(string fileName) {
            Assembly assembly = Assembly.GetExecutingAssembly();
            string[] handlepaths = assembly.GetManifestResourceNames();
            string handlepath = null;
            using(Stream stream = assembly.GetManifestResourceStream("handle.exe")) {
                if(IntPtr.Size == 8)
                    handlepath = string.Format(@"{0}Common/x64/handle.exe", AppDomain.CurrentDomain.BaseDirectory);
                else
                    handlepath = string.Format(@"{0}Common/x86/handle.exe", AppDomain.CurrentDomain.BaseDirectory);
            }
            Process tool = new Process();
            tool.StartInfo.FileName = handlepath;
            tool.StartInfo.Arguments = fileName + " /accepteula";
            tool.StartInfo.WindowStyle = ProcessWindowStyle.Hidden;
            tool.StartInfo.CreateNoWindow = true;
            tool.StartInfo.UseShellExecute = false;
            tool.StartInfo.RedirectStandardOutput = true;
            tool.Start();
            tool.WaitForExit();
            string outputTool = tool.StandardOutput.ReadToEnd();
            string matchPattern = @"(?<=\s+pid:\s+)\b(\d+)\b(?=\s+)";
            foreach(Match match in Regex.Matches(outputTool, matchPattern)) {
                Process.GetProcessById(int.Parse(match.Value)).Kill();
            }
            return true;
        }
    }
}
