using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Text;

namespace VXConverter.Common
{
    /// <summary>
    /// 数组转字符串
    /// </summary>
    /// <example>
    /// </example>
    public class VXArrayConverter : ArrayConverter
    {
        public override bool CanConvertFrom(ITypeDescriptorContext context, Type sourceType) {
            if(sourceType == typeof(string[]))
                return true;
            return base.CanConvertFrom(context, sourceType);
        }
        public override bool CanConvertTo(ITypeDescriptorContext context, Type destinationType) {
            return true;
        }
        public override object ConvertTo(ITypeDescriptorContext context, System.Globalization.CultureInfo culture, object value, Type destinationType) {
            if(value != null && value.GetType().IsArray) {
                string[] strs = value as string[];
                return string.Join(",", strs);
            }
            else
                return base.ConvertTo(context, culture, value, destinationType);
        }
    }
}
