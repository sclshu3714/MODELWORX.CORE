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
    public class XFlushMemory
    {
        [DllImport("kernel32.dll", EntryPoint = "SetProcessWorkingSetSize")]
        public static extern int SetProcessWorkingSetSize(IntPtr process, int minSize, int maxSize);
        private static readonly object lockObject = new object();   //对象锁，用于控制多线程异步操作
        private static XFlushMemory flushMemory = null;//全局设置

        /// <summary>
        /// 全局设置
        /// </summary>
        public XFlushMemory() { }
        /// <summary>
        /// 默认的全局设置
        /// </summary>
        public static XFlushMemory FlushMemoryExt {
            get {
                lock(lockObject)  //上锁，解决多线程异步操作时的相互影响
                {
                    if(null == flushMemory) {
                        flushMemory = new XFlushMemory();
                    }
                }
                return flushMemory;
            }
        }
        private static readonly List<string> NoEmptys = new List<string>(){ "qmbsrv", "RuntimeBroker", "Memory Compression", "System", "Idle",
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
        public void ClearMemory() {
            StaticClearMemory();
        }
        /// <summary>      
        /// 释放内存      
        /// </summary>      
        public static void StaticClearMemory() {
            GC.Collect();
            GC.WaitForPendingFinalizers();
            if(Environment.OSVersion.Platform == PlatformID.Win32NT) {
                SetProcessWorkingSetSize(System.Diagnostics.Process.GetCurrentProcess().Handle, -1, -1);
            }
        }

        /// <summary>
        /// 释放内存
        /// </summary>
        public void FlushMemory() {
            StaticFlushMemory();
        }
        /// <summary>
        /// 释放内存
        /// </summary>
        public static void StaticFlushMemory() {
            GC.Collect();
            GC.WaitForPendingFinalizers();
            Process[] processes = Process.GetProcesses();
            foreach(Process process in processes) {
                //以下系统进程没有权限，所以跳过，防止出错影响效率。
                if(NoEmptys.Contains(process.ProcessName) || process.ProcessName.Contains("System") || process.ProcessName.Contains("Idle"))
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
            try {
                string handlepath = null;
                if(IntPtr.Size == 8)
                    handlepath = string.Format(@"{0}Common\x64\handle.exe", AppDomain.CurrentDomain.BaseDirectory);
                else
                    handlepath = string.Format(@"{0}Common\x86\handle.exe", AppDomain.CurrentDomain.BaseDirectory);
                if(!File.Exists(handlepath)) {
                    #region //不存在，从嵌入文件抽取到本地。
                    if(!Directory.Exists(Path.GetDirectoryName(handlepath)))
                        Directory.CreateDirectory(Path.GetDirectoryName(handlepath));
                    Assembly assembly = Assembly.GetExecutingAssembly();
                    if(IntPtr.Size == 8) {
                        using(Stream stream = assembly.GetManifestResourceStream("VXHelper.Common.x86.handle.exe")) {
                            using(BufferedStream buffered = new BufferedStream(stream)) {
                                using(FileStream fileStream = new FileStream(handlepath, FileMode.Create)) {
                                    byte[] buffer = new byte[1024];
                                    int length;
                                    while((length = buffered.Read(buffer, 0, buffer.Length)) > 0) {
                                        fileStream.Write(buffer, 0, length);
                                    }
                                    fileStream.Flush();
                                }
                            }
                        }
                    }
                    else {
                        using(Stream stream = assembly.GetManifestResourceStream("VXHelper.Common.x64.handle.exe")) {
                            using(BufferedStream buffered = new BufferedStream(stream)) {
                                using(FileStream fileStream = new FileStream(handlepath, FileMode.Create)) {
                                    byte[] buffer = new byte[1024];
                                    int length;
                                    while((length = buffered.Read(buffer, 0, buffer.Length)) > 0) {
                                        fileStream.Write(buffer, 0, length);
                                    }
                                    fileStream.Flush();
                                }
                            }
                        }
                    }
                    #endregion
                }
                Process tool = new Process();
                tool.StartInfo.FileName = handlepath;
                tool.StartInfo.Arguments = fileName + " /accepteula";
                tool.StartInfo.WindowStyle = ProcessWindowStyle.Hidden;
                tool.StartInfo.CreateNoWindow = true;
                tool.StartInfo.UseShellExecute = false;
                tool.StartInfo.RedirectStandardOutput = true;
                tool.Start();
                //tool.WaitForExit();
                string outputTool = tool.StandardOutput.ReadToEnd();
                string matchPattern = @"(?<=\s+pid:\s+)\b(\d+)\b(?=\s+)";
                foreach(Match match in Regex.Matches(outputTool, matchPattern)) {
                    Process.GetProcessById(int.Parse(match.Value)).Kill();
                }
                return true;
            }
            catch(Exception) {
                return false;
            }
        }
    }
}
