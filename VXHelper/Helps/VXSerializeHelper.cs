using System;
using System.Collections.Generic;
using System.IO;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Formatters.Binary;
using System.Text;

namespace VXHelper
{
    public class VXSerialize
    {
        private static object lockObject = new object();   //对象锁，用于控制多线程异步操作
        private static VXSerialize serialize = null;//全局设置

        /// <summary>
        /// 全局设置
        /// </summary>
        public VXSerialize() { }
        /// <summary>
        /// 默认的全局设置
        /// </summary>
        public static VXSerialize Serialize {
            get {
                lock(lockObject)  //上锁，解决多线程异步操作时的相互影响
                {
                    if(null == serialize) {
                        serialize = new VXSerialize();
                    }
                }
                return serialize;
            }
        }
		/// <summary>
		/// 序列化
		/// </summary>
		/// <param name="obj"></param>
		/// <returns></returns>
		public string SerializeObject(object obj) {
			return StaticSerializeObject(obj);
		}
		/// <summary>
		/// 序列化
		/// </summary>
		/// <param name="obj"></param>
		/// <returns></returns>
		public static string StaticSerializeObject(object obj) {
			IFormatter formatter = new BinaryFormatter();
			string result = string.Empty;
			using(MemoryStream memoryStream = new MemoryStream()) {
				formatter.Serialize(memoryStream, obj);
				byte[] inArray = new byte[memoryStream.Length];
				inArray = memoryStream.ToArray();
				result = Convert.ToBase64String(inArray);
				memoryStream.Flush();
			}
			return result;
		}
		/// <summary>
		/// 反序列化
		/// </summary>
		/// <typeparam name="T"></typeparam>
		/// <param name="str"></param>
		/// <returns></returns>
		public T DeserializeObject<T>(string str) {
			return StaticDeserializeObject<T>(str);
		}
		/// <summary>
		/// 反序列化
		/// </summary>
		/// <typeparam name="T"></typeparam>
		/// <param name="str"></param>
		/// <returns></returns>
		public static T StaticDeserializeObject<T>(string str) {
			bool flag = string.IsNullOrEmpty(str);
			object result;
			if(flag) {
				result = null;
			}
			else {
				IFormatter formatter = new BinaryFormatter();
				byte[] array = Convert.FromBase64String(str);
				object obj = null;
				using(Stream stream = new MemoryStream(array, 0, array.Length)) {
					obj = formatter.Deserialize(stream);
				}
				result = obj;
			}
			return result == null ? default : (T)result;
		}
	}
}
