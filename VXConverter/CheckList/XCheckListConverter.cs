using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Text;
using VXModel.Common;

namespace VXConverter.CheckList
{
    /// <summary>
    /// 属性支持复选
    /// </summary>
    public class XCheckListConverter : TypeConverter
    {
        public override bool CanConvertFrom(ITypeDescriptorContext context, Type sourceType) {
            if(sourceType == typeof(string))
                return true;
            return base.CanConvertFrom(context, sourceType);
        }
        public override bool CanConvertTo(ITypeDescriptorContext context, Type destinationType) {
            return true;
        }
        public override object ConvertTo(ITypeDescriptorContext context, System.Globalization.CultureInfo culture, object value, Type destType) {
            if(destType == typeof(string) && value is Dictionary<string, bool> boolKey) {
                string strValue = null;
                foreach(string item in boolKey.Keys) {
                    if(string.IsNullOrEmpty(strValue) && boolKey[item])
                        strValue = item;
                    else if(!string.IsNullOrEmpty(strValue) && boolKey[item])
                        strValue += "," + item;
                }
                return strValue;
            }
            if(destType == typeof(string) && value is List<string> list) {
                XArrayAttribute listAttribute = (XArrayAttribute)context.PropertyDescriptor.Attributes[typeof(XArrayAttribute)];
                string strValue = null;
                foreach(string item in list) {
                    strValue += "," + item;
                }
                return string.Join(",", list);
            }
            return base.ConvertTo(context, culture, value, destType);
        }
        public override bool GetStandardValuesSupported(ITypeDescriptorContext context) {
            return true;
        }
        public override bool GetStandardValuesExclusive(ITypeDescriptorContext context) {
            return true;
        }
    }
}
