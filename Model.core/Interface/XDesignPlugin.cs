using System;
using System.Linq;
using System.Collections.Generic;
using System.Drawing;
using System.Reflection;
using System.Text;
using XModel.Users;
using XModel.Events;

namespace XModel.Interface
{
    public class XDesignPlugin : MarshalByRefObject, IPlugin
    {
        #region 插件加载
        /// <summary>
        /// void
        /// </summary>
        public XDesignPlugin() { 
            
        }
        /// <summary>
        /// 加载插件
        /// </summary>
        /// <param name="dllName"></param>
        /// <returns></returns>
        public XDesignPlugin LoadAssembly(string dllName)
        {
            try {
                if (PluginAssembly == null) {
                    PluginAssembly = Assembly.LoadFrom(dllName);
                    IEnumerable<Type> tempTypes = PluginAssembly.GetTypes().Where(type => type.BaseType != null && type.BaseType.Name == "XDesignPlugin");
                    foreach (Type tempType in tempTypes) {
                        XDesignPlugin DesignPlugin = (XDesignPlugin)PluginAssembly.CreateInstance(tempType.FullName);
                        return DesignPlugin;
                    }
                }
            } catch (Exception) {
                return null;
            }
            return null;
        }
        /// <summary>
        /// 加载参数额void
        /// </summary>
        /// <param name="dllName"></param>
        public XDesignPlugin(string dllName)
        {
            if (PluginAssembly == null) {
                PluginAssembly = Assembly.LoadFrom(dllName);
            }
        }
        /// <summary>
        /// 加载插件
        /// </summary>
        /// <param name="dllName"></param>
        /// <returns></returns>
        public XDesignPlugin LoadAssembly()
        {
            try {
                if (PluginAssembly != null) {
                    IEnumerable<Type> tempTypes = PluginAssembly.GetTypes().Where(type => type.BaseType != null && type.BaseType.Name == "XDesignPlugin");
                    foreach (Type tempType in tempTypes) {
                        XDesignPlugin DesignPlugin = (XDesignPlugin)PluginAssembly.CreateInstance(tempType.FullName);
                        return DesignPlugin;
                    }
                }
            } catch (Exception) {
                return null;
            }
            return null;
        }

        /// <summary>
        /// 执行方法
        /// </summary>
        /// <param name="fullClassName"></param>
        /// <param name="methodName"></param>
        /// <param name="args"></param>
        /// <returns></returns>
 
        public virtual object Invoke(string fullClassName, string methodName, params Object[] args) {
            if (PluginAssembly == null)
                return false;
            Type tp = PluginAssembly.GetType(fullClassName);
            if (tp == null)
                return false;
            MethodInfo method = tp.GetMethod(methodName);
            if (method == null || method.GetParameters().Count() != args.Length)
                return false;
            Object obj = Activator.CreateInstance(tp);
            return method.Invoke(obj, args);
        }
        #endregion

        #region 方法行为
        /// <summary>
        /// 委托事件
        /// </summary>
        public event OperationEvent OnDelegateEvent {
            add { OnCustomEvent += value; }
            remove { OnCustomEvent -= value; }
        
        }

        public object Clone() // 复制
        {
            //throw new NotImplementedException();
            return (XDesignPlugin)this.MemberwiseClone(true);
        }

        public void DisplayMessage(string logid, string code, string explain, string position, int level)
        {//显示消息
            //throw new NotImplementedException();
        }

        public void DisplayStatusInfo(string strStatusInfo = "就绪")
        {//显示状态
            //throw new NotImplementedException();
        }

        public void Dispose()
        {//释放
            //throw new NotImplementedException();
        }

        public void OpenWorkbench(string ProjectId = null)
        {//打开工作区
            //throw new NotImplementedException();
        }
        #endregion

        #region 字段属性

        public string PluginId { get; set; }// => Guid.NewGuid().ToString();

        public string PluginName { get; set; }//=> "NewName";

        public string PluginCaption { get; set; }//=> "新名称";

        public object PluginTag { get; set; }//=> "记录JSON结构的信息";

        public Image PluginIcon { get; set; }//=> null;

        public string PluginCategory { get; set; }//=> "类别分类";

        public User LogonUser { get; set; }//=> new User();// "登录的用户";

        public string ProjectId { get; set; }//=> Guid.NewGuid().ToString();// 项目编号 throw new NotImplementedException();

        public string ProjectName { get; set; }//=> "项目名称";// throw new NotImplementedException();

        public dynamic MDIForm { get; set; }//=> null;//父窗体 throw new NotImplementedException();

        public Assembly PluginAssembly { get; set; } = null;
        /// <summary>
        /// 委托事件
        /// </summary>
        public OperationEvent OnCustomEvent { get; set; } = null;
        #endregion

    }
}
