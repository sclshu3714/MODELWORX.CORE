﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Text;
using VXModel.Common;

namespace VXConverter.Common
{
    /// <summary>
    /// 自定义扩展下拉框
    /// </summary>
    /// <example>
    /// TypeConverter(typeof(VXComboConverter)), VXArrayAttribute("铆钉", "螺栓")]
    /// </example>
    public class VXComboConverter : TypeConverter
    {
        public override bool GetStandardValuesSupported(ITypeDescriptorContext context) {
            return true;
        }
        public override bool GetStandardValuesExclusive(ITypeDescriptorContext context) {
            return true;
        }
        public override StandardValuesCollection GetStandardValues(ITypeDescriptorContext context) {
            VXArrayAttribute listAttribute = (VXArrayAttribute)context.PropertyDescriptor.Attributes[typeof(VXArrayAttribute)];
            StandardValuesCollection vals = new TypeConverter.StandardValuesCollection(listAttribute.list);
            return vals;
        }
        public override bool CanConvertTo(ITypeDescriptorContext context, Type destinationType) {
            return true;
        }
    }
}
