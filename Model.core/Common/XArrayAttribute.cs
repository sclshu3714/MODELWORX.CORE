using System;
using System.Collections.Generic;
using System.Text;

namespace XModel.Common
{
    public class XArrayAttribute : Attribute
    {
        /// <summary>
        /// 记录数组数据
        /// </summary>
        public object[] list = null;
        public XArrayAttribute(params object[] list) {
            this.list = list;
        }
    }
}
