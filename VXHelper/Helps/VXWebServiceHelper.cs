using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net;
using System.Net.NetworkInformation;
using System.Text;
using System.Xml;

namespace VXHelper
{
    public class VXWebService
    {
        private static readonly object lockObject = new object();   //对象锁，用于控制多线程异步操作
        private static VXWebService webService = null;//全局设置
        private static System.Diagnostics.Process WebServiceProcess = null;

        /// <summary>
        /// 全局设置
        /// </summary>
        public VXWebService() { }
        /// <summary>
        /// 默认的全局设置
        /// </summary>
        public static VXWebService WebService
        {
            get
            {
                lock (lockObject)  //上锁，解决多线程异步操作时的相互影响
                {
                    if (null == webService)
                    {
                        webService = new VXWebService();
                    }
                }
                return webService;
            }
        }


        #region 当没有检查到服务时启动IIS站点
        /// <summary>
        /// 启动IIS站点
        /// </summary>
        /// <param name="siteName">网站名称DesignService</param>
        /// <param name="applicationPool">应用池DesignService</param>
        /// <param name="physicalPath">物理位置</param>
        /// <param name="bindingInformation">地址端口127.0.0.1:28373:</param>
        public static void IISStartService(string siteName, string applicationPool, string physicalPath, string bindingInformation)
        {
            string folder = Path.Combine(AppDomain.CurrentDomain.BaseDirectory, "IISService");
            DirectoryInfo dirInfo = new DirectoryInfo(folder);
            if (dirInfo.Exists == false)
                dirInfo.Create();
            string configPath = Path.Combine(folder, "applicationhost.config");
            string batFilePath = Path.Combine(folder, "StartService.bat");
            InitIISConfig(configPath, siteName, applicationPool, physicalPath, bindingInformation);
            if (File.Exists(batFilePath) == false) return;
            WebServiceProcess = new System.Diagnostics.Process();
            System.Diagnostics.ProcessStartInfo ProcessStartInfo = new System.Diagnostics.ProcessStartInfo();
            ProcessStartInfo.CreateNoWindow = true;
            ProcessStartInfo.FileName = batFilePath;
            ProcessStartInfo.UseShellExecute = false;
            //ProcessStartInfo.RedirectStandardOutput = true;
            WebServiceProcess.StartInfo = ProcessStartInfo;
            WebServiceProcess.Start();
            //string output = process.StandardOutput.ReadToEnd();//读取进程的输出  
        }
        /// <summary>
        /// 关闭IIS服务站
        /// </summary>
        private static void StopService()
        {
            if (WebServiceProcess == null || !WebServiceProcess.HasExited)
                return;
            WebServiceProcess.Close();
            WebServiceProcess.Kill();
            WebServiceProcess = null;
        }
        /// <summary>
        /// 修改IIS的配置文件
        /// </summary>
        /// <param name="configPath">配置路径</param>
        /// <param name="siteName">站点名称</param>
        /// <param name="applicationPool">应用池</param>
        /// <param name="physicalPath">物理路径</param>
        /// <param name="bindingInformation">地址端口</param>
        private static void InitIISConfig(string configPath, string siteName, string applicationPool, string physicalPath, string bindingInformation)
        {
            XmlDocument config = new XmlDocument();
            config.Load(configPath);
            //1 应用池
            XmlNode applicationPoolsNode = config.SelectSingleNode(string.Format(@"descendant::applicationPools"));
            XmlElement PoolNode = applicationPoolsNode.SelectSingleNode(string.Format(@"descendant::add[@name='{0}']", applicationPool)) as XmlElement;
            if (PoolNode == null)
            {
                //<add name="DesignService" enable32BitAppOnWin64="true" managedRuntimeVersion="v4.0" managedPipelineMode="Classic" />
                XmlElement PoolElement = config.CreateElement("add");
                XmlAttribute enable32BitAppOnWin64Attribute = config.CreateAttribute("enable32BitAppOnWin64");
                enable32BitAppOnWin64Attribute.Value = "true";
                PoolElement.Attributes.Append(enable32BitAppOnWin64Attribute);
                XmlAttribute managedRuntimeVersionAttribute = config.CreateAttribute("managedRuntimeVersion");
                managedRuntimeVersionAttribute.Value = "v4.0";
                PoolElement.Attributes.Append(managedRuntimeVersionAttribute);
                XmlAttribute managedPipelineModeAttribute = config.CreateAttribute("managedPipelineMode");
                managedPipelineModeAttribute.Value = "Classic";
                PoolElement.Attributes.Append(managedPipelineModeAttribute);
            }
            else
            {
                if (PoolNode.HasAttribute("enable32BitAppOnWin64"))
                    PoolNode.Attributes["enable32BitAppOnWin64"].Value = "true";
                if (PoolNode.HasAttribute("managedRuntimeVersion"))
                    PoolNode.Attributes["managedRuntimeVersion"].Value = "v4.0";
                if (PoolNode.HasAttribute("managedPipelineMode"))
                    PoolNode.Attributes["managedPipelineMode"].Value = "Classic";
            }
            //2 站点
            XmlNode sitesNode = config.SelectSingleNode(string.Format(@"descendant::sites"));
            XmlElement siteNode = sitesNode.SelectSingleNode(string.Format(@"descendant::site[@name='{0}']", siteName)) as XmlElement;
            if (siteNode == null)
            {
                XmlElement siteElement = config.CreateElement("site");
                XmlAttribute nameAttribute = config.CreateAttribute("name");
                nameAttribute.Value = siteName;
                siteElement.Attributes.Append(nameAttribute);
                XmlAttribute idAttribute = config.CreateAttribute("id");
                idAttribute.Value = Convert.ToString(sitesNode.ChildNodes.Count);
                siteElement.Attributes.Append(idAttribute);
                XmlAttribute serverAutoStartAttribute = config.CreateAttribute("serverAutoStart");
                serverAutoStartAttribute.Value = "true";
                siteElement.Attributes.Append(serverAutoStartAttribute);
                XmlElement applicationElement = config.CreateElement("application");
                XmlAttribute pathAttribute = config.CreateAttribute("path");
                pathAttribute.Value = "/";
                applicationElement.Attributes.Append(pathAttribute);
                XmlAttribute applicationPoolAttribute = config.CreateAttribute("applicationPool");
                applicationPoolAttribute.Value = applicationPool;
                applicationElement.Attributes.Append(applicationPoolAttribute);
                XmlElement virtualDirectoryElement = config.CreateElement("virtualDirectory");
                XmlAttribute vpathAttribute = config.CreateAttribute("path");
                vpathAttribute.Value = "/";
                virtualDirectoryElement.Attributes.Append(vpathAttribute);
                XmlAttribute physicalPathAttribute = config.CreateAttribute("physicalPath");
                physicalPathAttribute.Value = physicalPath;
                virtualDirectoryElement.Attributes.Append(physicalPathAttribute);
                applicationElement.AppendChild(virtualDirectoryElement);
                siteElement.AppendChild(applicationElement);
                XmlElement bindingsElement = config.CreateElement("bindings");
                XmlElement bindingElement = config.CreateElement("binding");
                XmlAttribute protocolAttribute = config.CreateAttribute("protocol");
                protocolAttribute.Value = "http";
                bindingElement.Attributes.Append(protocolAttribute);
                XmlAttribute bindingInformationAttribute = config.CreateAttribute("bindingInformation");
                bindingInformationAttribute.Value = bindingInformation;
                bindingElement.Attributes.Append(bindingInformationAttribute);
                bindingsElement.AppendChild(bindingElement);
                siteElement.AppendChild(bindingsElement);
                sitesNode.InsertAfter(siteElement, sitesNode.ChildNodes[0]);
            }
            else
            {
                if (siteNode.HasAttribute("name"))
                    siteNode.Attributes["name"].Value = siteName;
                //if (siteNode.HasAttribute("id"))
                //    siteNode.Attributes["id"].Value = Convert.ToString(siteNode.ChildNodes.Count);
                if (siteNode.HasAttribute("serverAutoStart"))
                    siteNode.Attributes["serverAutoStart"].Value = "true";
                XmlElement applicationNode = siteNode.SelectSingleNode(string.Format(@"application")) as XmlElement;
                if (applicationNode == null)
                {
                    #region application
                    XmlElement applicationElement = config.CreateElement("application");
                    XmlAttribute pathAttribute = config.CreateAttribute("path");
                    pathAttribute.Value = "/";
                    applicationElement.Attributes.Append(pathAttribute);
                    XmlAttribute applicationPoolAttribute = config.CreateAttribute("applicationPool");
                    applicationPoolAttribute.Value = applicationPool;
                    applicationElement.Attributes.Append(applicationPoolAttribute);
                    XmlElement virtualDirectoryElement = config.CreateElement("virtualDirectory");
                    XmlAttribute vpathAttribute = config.CreateAttribute("path");
                    vpathAttribute.Value = "/";
                    virtualDirectoryElement.Attributes.Append(vpathAttribute);
                    XmlAttribute physicalPathAttribute = config.CreateAttribute("physicalPath");
                    physicalPathAttribute.Value = physicalPath;
                    virtualDirectoryElement.Attributes.Append(physicalPathAttribute);
                    applicationElement.AppendChild(virtualDirectoryElement);
                    siteNode.AppendChild(applicationElement);
                    XmlElement bindingsElement = config.CreateElement("bindings");
                    XmlElement bindingElement = config.CreateElement("binding");
                    XmlAttribute protocolAttribute = config.CreateAttribute("protocol");
                    protocolAttribute.Value = "http";
                    bindingElement.Attributes.Append(protocolAttribute);
                    XmlAttribute bindingInformationAttribute = config.CreateAttribute("bindingInformation");
                    bindingInformationAttribute.Value = bindingInformation;
                    bindingElement.Attributes.Append(bindingInformationAttribute);
                    bindingsElement.AppendChild(bindingElement);
                    siteNode.AppendChild(bindingsElement);
                    #endregion
                }
                else
                {
                    if (applicationNode.HasAttribute("path"))
                        applicationNode.Attributes["path"].Value = "/";
                    if (applicationNode.HasAttribute("applicationPool"))
                        applicationNode.Attributes["applicationPool"].Value = applicationPool;
                    XmlElement virtualDirectoryNode = applicationNode.SelectSingleNode(string.Format(@"virtualDirectory")) as XmlElement;
                    if (virtualDirectoryNode == null)
                    {
                        XmlElement virtualDirectoryElement = config.CreateElement("virtualDirectory");
                        XmlAttribute vpathAttribute = config.CreateAttribute("path");
                        vpathAttribute.Value = "/";
                        virtualDirectoryElement.Attributes.Append(vpathAttribute);
                        XmlAttribute physicalPathAttribute = config.CreateAttribute("physicalPath");
                        physicalPathAttribute.Value = physicalPath;
                        virtualDirectoryElement.Attributes.Append(physicalPathAttribute);
                        applicationNode.AppendChild(virtualDirectoryElement);
                    }
                    else
                    {
                        if (virtualDirectoryNode.HasAttribute("path"))
                            virtualDirectoryNode.Attributes["path"].Value = "/";
                        if (virtualDirectoryNode.HasAttribute("physicalPath"))
                            virtualDirectoryNode.Attributes["physicalPath"].Value = physicalPath;
                    }
                }
                XmlElement bindingsNode = siteNode.SelectSingleNode(string.Format(@"bindings")) as XmlElement;
                if (bindingsNode == null)
                {
                    XmlElement bindingsElement = config.CreateElement("bindings");
                    XmlElement bindingElement = config.CreateElement("binding");
                    XmlAttribute protocolAttribute = config.CreateAttribute("protocol");
                    protocolAttribute.Value = "http";
                    bindingElement.Attributes.Append(protocolAttribute);
                    XmlAttribute bindingInformationAttribute = config.CreateAttribute("bindingInformation");
                    bindingInformationAttribute.Value = bindingInformation;
                    bindingElement.Attributes.Append(bindingInformationAttribute);
                    bindingsElement.AppendChild(bindingElement);
                    siteNode.AppendChild(bindingsElement);
                }
                else
                {
                    XmlElement bindingNode = bindingsNode.SelectSingleNode(string.Format(@"binding")) as XmlElement;
                    if (bindingNode == null)
                    {
                        XmlElement bindingElement = config.CreateElement("binding");
                        XmlAttribute protocolAttribute = config.CreateAttribute("protocol");
                        protocolAttribute.Value = "http";
                        bindingElement.Attributes.Append(protocolAttribute);
                        XmlAttribute bindingInformationAttribute = config.CreateAttribute("bindingInformation");
                        bindingInformationAttribute.Value = bindingInformation;
                        bindingElement.Attributes.Append(bindingInformationAttribute);
                        bindingsNode.AppendChild(bindingElement);
                    }
                    else
                    {
                        if (bindingNode.HasAttribute("protocol"))
                            bindingNode.Attributes["protocol"].Value = "http";
                        if (bindingNode.HasAttribute("bindingInformation"))
                            bindingNode.Attributes["bindingInformation"].Value = bindingInformation;
                    }
                }
            }
            config.Save(configPath);
        }
        #endregion

        /// <summary>
        /// 启动vs自带的WebServer40
        /// </summary>
        /// <param name="_AppRoot">WebDev.WebServer40.EXE的全路径</param>
        /// <param name="_Port">端口</param>
        /// <param name="_WebPath">物理路径</param>
        /// <param name="_WebvPath">虚拟路径</param>
        /// <returns>是否启动</returns>
        public static bool WebServerStart(string _AppRoot = null, string _Port = null, string _WebPath = null, string _WebvPath = "/")
        {
            if (string.IsNullOrEmpty(_AppRoot) || !File.Exists(_AppRoot))
                _AppRoot = System.IO.Path.GetFullPath(Path.Combine(AppDomain.CurrentDomain.BaseDirectory, VXConfigurationManager.StaticGetConfiguration<string>("WebServer")));
            if (string.IsNullOrEmpty(_Port))
                _Port = "28373";
            if (string.IsNullOrEmpty(_WebPath))
                _WebPath = System.IO.Path.GetFullPath(Path.Combine(AppDomain.CurrentDomain.BaseDirectory, VXConfigurationManager.StaticGetConfiguration<string>("LocalService")));
            if (string.IsNullOrEmpty(_Port))
                _WebvPath = "/";
            //简单校验
            if (!CheckWebServer(_AppRoot, _Port, _WebPath, _WebvPath))
                return false;
            string arguments = string.Format("/port:{0} /path:{1} /vpath:{2}", _Port, _WebPath, _WebvPath);
            //System.Diagnostics.Process.Start(_AppRoot, arguments);
            WebServiceProcess = new System.Diagnostics.Process();
            System.Diagnostics.ProcessStartInfo ProcessStartInfo = new System.Diagnostics.ProcessStartInfo();
            ProcessStartInfo.CreateNoWindow = true;
            ProcessStartInfo.FileName = _AppRoot;
            ProcessStartInfo.Arguments = arguments;
            ProcessStartInfo.UseShellExecute = false;
            WebServiceProcess.StartInfo = ProcessStartInfo;
            WebServiceProcess.Start();
            return true;
        }
        /// <summary>
        /// 简单校验
        /// </summary>
        /// <param name="_AppRoot">WebDev.WebServer40.EXE的全路径</param>
        /// <param name="_Port">端口</param>
        /// <param name="_WebPath">物理路径</param>
        /// <param name="_WebvPath">虚拟路径</param>
        /// <returns>是否可用</returns>
        public static bool CheckWebServer(string _AppRoot = null, string _Port = null, string _WebPath = null, string _WebvPath = "/")
        {
            if (string.IsNullOrEmpty(_AppRoot) || !File.Exists(_AppRoot))
                _AppRoot = System.IO.Path.GetFullPath(Path.Combine(AppDomain.CurrentDomain.BaseDirectory, VXConfigurationManager.StaticGetConfiguration<string>("WebServer")));
            if (string.IsNullOrEmpty(_Port))
                _Port = "28373";
            if (string.IsNullOrEmpty(_WebPath))
                _WebPath = System.IO.Path.GetFullPath(Path.Combine(AppDomain.CurrentDomain.BaseDirectory, VXConfigurationManager.StaticGetConfiguration<string>("LocalService")));
            if (string.IsNullOrEmpty(_Port))
                _WebvPath = "/";
            if (!System.IO.File.Exists(_AppRoot))
            {
                return false;
                //throw new Exception("找不到指定程序！");
            }
            if (Convert.ToInt32(_Port) <= 1024 || Convert.ToInt32(_Port) >= 65535)  //^[1-6]?[\d]{0,4}$
            {
                return false;
                //throw new Exception("端口：1-65535之间未使用的端口号！");
            }
            if (!System.IO.Directory.Exists(_WebPath))
            {
                return false;
                //throw new Exception("物理路径不存在，请指定有效的目录！");
            }
            if (!_WebvPath.Contains("/"))
            {
                return false;
                //throw new Exception("虚拟目录必须以'/'开头！");
            }
            IPGlobalProperties ipProperties = IPGlobalProperties.GetIPGlobalProperties();
            IPEndPoint[] ipEndPoints = ipProperties.GetActiveTcpListeners();
            int counts = ipEndPoints.Count<IPEndPoint>(o => o.Port == int.Parse(_Port));
            if (counts > 0)
            {
                return false;
                //throw new Exception("端口已被占用!");
            }
            return true;
        }
    }
}
