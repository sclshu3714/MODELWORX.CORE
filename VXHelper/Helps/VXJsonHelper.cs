using System;
using System.Collections.Generic;
using System.Text;
using Newtonsoft.Json;

namespace VXHelper
{
    public class VXJson
    {
        private static object lockObject = new object();   //对象锁，用于控制多线程异步操作
        private static VXJson json = null;//全局设置

        /// <summary>
        /// 全局设置
        /// </summary>
        public VXJson() { }
        /// <summary>
        /// 默认的全局设置
        /// </summary>
        public static VXJson JSONEXT {
            get {
                lock(lockObject)  //上锁，解决多线程异步操作时的相互影响
                {
                    if(null == json) {
                        json = new VXJson();
                    }
                }
                return json;
            }
        }

        /// <summary>
        /// 把对象转换为JSON字符串
        /// </summary>
        /// <param name="_Object">对象</param>
        /// <returns>JSON字符串</returns>
        public string JsonObjectToString(object _Object) {
            return StaticJsonObjectToString(_Object);
        }
        /// <summary>
        /// 把对象转换为JSON字符串
        /// </summary>
        /// <param name="_Object">对象</param>
        /// <returns>JSON字符串</returns>
        public static string StaticJsonObjectToString(object _Object) {
            if(_Object == null)
                return null;
            return JsonConvert.SerializeObject(_Object);
        }
        /// <summary>
        /// 把Json文本转为实体
        /// </summary>
        /// <typeparam name="T">转换类型</typeparam>
        /// <param name="input">json字符串</param>
        /// <returns>返回T</returns>
        public T JsonStringToObject<T>(string input) {
            return StaticJsonStringToObject<T>(input);
        }
        /// <summary>
        /// 把Json文本转为实体
        /// </summary>
        /// <typeparam name="T"></typeparam>
        /// <param name="input"></param>
        /// <returns></returns>
        public static T StaticJsonStringToObject<T>(string input) {
            try {
                return JsonConvert.DeserializeObject<T>(input);
            }
            catch(Exception) {
                return default(T);
            }
        }
    }
}
