using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Reflection;
using System.Text;
using VXModel.Common;

namespace VXHelper
{
    public class XPropertyEdit
    {
        /// <summary>
        /// 设置属性是否可见
        /// </summary>
        /// <param name="obj"></param>
        /// <param name="propertyName"></param>
        /// <param name="visible"></param>
        public static void SetPropertyVisibility(object obj, string propertyName, bool visible) {
            Type type = typeof(BrowsableAttribute);
            PropertyDescriptorCollection props = TypeDescriptor.GetProperties(obj);
            if(props.Find(propertyName, true) != null) {
                AttributeCollection attrs = props[propertyName].Attributes;
                FieldInfo fld = type.GetField("browsable", BindingFlags.Instance | BindingFlags.NonPublic);
                fld.SetValue(attrs[type], visible);
            }
        }
        /// <summary>
        /// 设置属性的显示名称
        /// </summary>
        /// <param name="obj"></param>
        /// <param name="propertyName"></param>
        /// <param name="name"></param>
        public static void SetPropertyDisplayName(object obj, string propertyName, string name) {
            Type type = typeof(BrowsableAttribute);
            PropertyDescriptorCollection props = TypeDescriptor.GetProperties(obj);
            if(props.Find(propertyName, true) != null) {
                AttributeCollection attrs = props[propertyName].Attributes;
                FieldInfo fld = type.GetField("displayname");
                fld.SetValue(attrs[type], name);
            }
        }
        /// <summary>
        /// 设置属性只读取
        /// </summary>
        /// <param name="obj"></param>
        /// <param name="propertyName"></param>
        /// <param name="readOnly"></param>
        public static void SetPropertyReadOnly(object obj, string propertyName, bool readOnly) {
            Type type = typeof(ReadOnlyAttribute);
            PropertyDescriptorCollection props = TypeDescriptor.GetProperties(obj);
            if(props.Find(propertyName, true) != null) {
                AttributeCollection attrs = props[propertyName].Attributes;
                FieldInfo fld = type.GetField("isReadOnly", BindingFlags.Instance | BindingFlags.NonPublic | BindingFlags.CreateInstance);
                fld.SetValue(attrs[type], readOnly);
            }
        }
        /// <summary>
        /// 设置属性的下拉可选择项
        /// 类中必须包含list排序序列
        /// </summary>
        /// <param name="obj"></param>
        /// <param name="propertyName"></param>
        /// <param name="WriteArray"></param>
        public static void SetPropertyWriteArray(object obj, string propertyName, string[] WriteArray) {
            Type type = typeof(XArrayAttribute);
            PropertyDescriptorCollection props = TypeDescriptor.GetProperties(obj);
            if(props.Find(propertyName, true) != null) {
                AttributeCollection attrs = props[propertyName].Attributes;
                FieldInfo fld = type.GetField("list");//, BindingFlags.Instance | BindingFlags.NonPublic | BindingFlags.CreateInstance | BindingFlags.Default);
                fld.SetValue(attrs[type], WriteArray);
            }
        }
    }
}
