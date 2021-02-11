using System;
using System.Collections.Generic;
using System.Text;
using XModel.Users;

namespace XModel.Interface
{
    public interface IViewInfo : IDisposable, ICloneable
    {
        /// <summary>
        /// 登录用户
        /// </summary>
        User LogonUser { get; }
        /// <summary>
        /// 项目GUID编号
        /// </summary>
        string ProjectId { get; }
        /// <summary>
        /// 项目名称
        /// </summary>
        string ProjectName { get; }

        /// <summary>
        /// 主窗体
        /// </summary>
        dynamic MDIForm { get; }
        /// <summary>
        /// 显示状态信息
        /// </summary>
        /// <param name="strStatusInfo">信息参数</param>
        void DisplayStatusInfo(string strStatusInfo = "就绪");
        /// <summary>
        /// 更新各种信息消息
        /// </summary>
        /// <param name="logid">信息GUID编号</param>
        /// <param name="code">信息代码或者标题</param>
        /// <param name="explain">说明</param>
        /// <param name="position">位置</param>
        /// <param name="level">错误级别:未知Unknown0;普通消息Message1;警告消息Warning2;错误消息Error3;操作信息Operate4</param>
        void DisplayMessage(string logid, string code, string explain, string position, int level);
    }
}
