using System;
using System.Collections.Generic;
using System.Text;

namespace VXModel.Common
{
    public class VXArrayAttribute : Attribute
    {
        /// <summary>
        /// 记录数组数据
        /// </summary>
        public object[] list = null;
        public VXArrayAttribute(params object[] list) {
            this.list = list;
        }
    }
}
