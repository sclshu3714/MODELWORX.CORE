using System;
using System.Collections.Generic;
using System.Drawing;
using System.Drawing.Imaging;
using System.IO;
using System.Runtime.InteropServices;
using System.Security.Cryptography;
using System.Text;

namespace VXHelper
{
    public class XConvert
    {
        private static object lockObject = new object();   //对象锁，用于控制多线程异步操作
        private static XConvert convert = null;//全局设置

        /// <summary>
        /// 全局设置
        /// </summary>
        public XConvert() { }
        /// <summary>
        /// 默认的全局设置
        /// </summary>
        public static XConvert CONVERTEXT {
            get {
                lock(lockObject)  //上锁，解决多线程异步操作时的相互影响
                {
                    if(null == convert) {
                        convert = new XConvert();
                    }
                }
                return convert;
            }
        }

        #region 数据类型转换
        /// <summary>
        /// 类型转换
        /// </summary>
        /// <typeparam name="T"></typeparam>
        /// <param name="value"></param>
        /// <returns></returns>
        public T ChangeType<T>(object value) {
            return staticChangeType<T>(value);
        }
        /// <summary>
        /// 类型转换
        /// </summary>
        /// <typeparam name="T"></typeparam>
        /// <param name="value"></param>
        /// <returns></returns>
        public static T staticChangeType<T>(object value) {
            return (T)staticChangeType(value, typeof(T));
        }
        /// <summary>
        /// 类型转换
        /// </summary>
        /// <param name="value"></param>
        /// <param name="type"></param>
        /// <returns></returns>
        public object ChangeType(object value, Type type) {
            return staticChangeType(value, type);
        }
        /// <summary>
        /// 类型转换
        /// </summary>
        /// <param name="value"></param>
        /// <param name="type"></param>
        /// <returns></returns>
        public static object staticChangeType(object value, Type type) {
            try {
                if(value == null && type.IsGenericType) return Activator.CreateInstance(type);
                if(value == null) return default;
                if(type == value.GetType()) return value;
                if(type.IsEnum) {
                    if(value is string)
                        return Enum.Parse(type, value as string);
                    else
                        return Enum.ToObject(type, value);
                }
                if(!type.IsInterface && type.IsGenericType) {
                    Type innerType = type.GetGenericArguments()[0];
                    object innerValue = staticChangeType(value, innerType);
                    return Activator.CreateInstance(type, new object[] { innerValue });
                }
                if(value is string && type == typeof(Guid)) return new Guid(value as string);
                if(value is string && type == typeof(Version)) return new Version(value as string);
                if(!(value is IConvertible)) return value;
                return Convert.ChangeType(value, type);
            }
            catch(Exception) {
                return Activator.CreateInstance(type);
            }
        }
        /// <summary>
        /// 字符串转类型
        /// </summary>
        /// <param name="type"></param>
        /// <returns></returns>
        public static Type ConvertTotype(string type) {
            switch(type.ToLower()) {
                case "bool":
                case "system.boolean":
                    return Type.GetType("System.Boolean", true, true);
                case "byte":
                case "system.byte":
                    return Type.GetType("System.Byte", true, true);
                case "sbyte":
                case "system.sbyte":
                    return Type.GetType("System.SByte", true, true);
                case "char":
                case "system.char":
                    return Type.GetType("System.Char", true, true);
                case "decimal":
                case "system.decimal":
                    return Type.GetType("System.Decimal", true, true);
                case "double":
                case "System.Double":
                    return Type.GetType("System.Double", true, true);
                case "float":
                case "system.single":
                    return Type.GetType("System.Single", true, true);
                case "int":
                case "int32":
                case "system.int32":
                    return Type.GetType("System.Int32", true, true);
                case "uint":
                case "system.uint32":
                    return Type.GetType("System.UInt32", true, true);
                case "int64":
                case "long":
                case "system.int64":
                    return Type.GetType("System.Int64", true, true);
                case "ulong":
                case "system.uint64":
                    return Type.GetType("System.UInt64", true, true);
                case "object":
                case "system.object":
                    return Type.GetType("System.Object", true, true);
                case "short":
                case "system.int16":
                    return Type.GetType("System.Int16", true, true);
                case "ushort":
                case "System.UInt16":
                    return Type.GetType("System.UInt16", true, true);
                case "string":
                case "system.string":
                    return Type.GetType("System.String", true, true);
                case "date":
                case "datetime":
                case "system.datetime":
                    return Type.GetType("System.DateTime", true, true);
                case "guid":
                case "system.guid":
                    return Type.GetType("System.Guid", true, true);
                default:
                    return Type.GetType(type, true, true);
            }
        }
        #endregion

        #region 文件类型
        [DllImport("kernel32.dll")]
        private static extern IntPtr _lopen(string lpPathName, int iReadWrite);
        [DllImport("kernel32.dll")]
        private static extern bool CloseHandle(IntPtr hObject);
        private const int OF_READWRITE = 2;
        private const int OF_SHARE_DENY_NONE = 0x40;
        private static readonly IntPtr HFILE_ERROR = new IntPtr(-1);
        /// <summary>
        /// 判断文件是否被独占
        /// </summary>
        /// <param name="fileFullName"></param>
        /// <returns></returns>
        public static int FileIsOpen(string path) {
            if(!File.Exists(path)) {
                return -1;
            }
            IntPtr handle = _lopen(path, OF_READWRITE | OF_SHARE_DENY_NONE);
            if(handle == HFILE_ERROR) {
                return 1;
            }
            CloseHandle(handle);
            return 0;
        }
        /// <summary>
        /// 获取文件名称，带后缀
        /// </summary>
        /// <param name="path"></param>
        /// <returns></returns>
        public static string GetFileName(string path) {
            return Path.GetFileName(path);
        }
        /// <summary>
        /// 获取文件的后缀带点
        /// </summary>
        /// <param name="path"></param>
        /// <returns></returns>
        public static string GetExtension(string path) {
            return Path.GetExtension(path);
        }
        /// <summary>
        /// 将Bitmap转换为byte[]
        /// </summary>
        /// <param name="original"></param>
        /// <returns></returns>
        public static byte[] GetByteFormImage(Bitmap original) {
            return GetByteFormImage(original);
        }
        /// <summary>
        /// 将Bitmap转换为byte[]
        /// </summary>
        /// <param name="original"></param>
        /// <returns></returns>
        public static byte[] GetByteFormImage(Image original) {
            if(original == null)
                return new byte[0];
            original = new Bitmap(original, 150, 150);
            ImageFormat format = original.RawFormat;
            using(MemoryStream ms = new MemoryStream()) {
                if(format.Equals(ImageFormat.MemoryBmp)) {
                    string filePath = string.Format(@"{0}Temp\Temp.png", AppDomain.CurrentDomain.BaseDirectory);
                    original.Save(filePath, ImageFormat.Png);
                    using(FileStream imageFileStream = new FileStream(filePath, FileMode.Open)) {
                        original = Image.FromStream(imageFileStream);
                        format = original.RawFormat;
                        imageFileStream.Close();
                    }
                    File.Delete(filePath);
                }
                original.Save(ms, format);
                byte[] buffer = new byte[ms.Length];
                //ms.Seek(0, SeekOrigin.Begin);//Image.Save()会改变MemoryStream的Position，需要重新Seek到Begin
                //ms.Read(buffer, 0, buffer.Length);
                buffer = ms.ToArray();
                return buffer;
            }
        }
        /// <summary>
        /// 将String转换为byte[]
        /// </summary>
        /// <param name="imageStr"></param>
        /// <returns></returns>
        public static byte[] GetByteFormString(string imageStr) {
            if(imageStr == null || string.IsNullOrEmpty(imageStr))
                return null;
            byte[] imgPhoto = Convert.FromBase64String(imageStr);
            return imgPhoto;
        }
        /// <summary>
        /// 将byte[]转换为String
        /// </summary>
        /// <param name="imageByte"></param>
        /// <returns></returns>
        public static string GetStringFormByte(byte[] imageByte) {
            if(imageByte == null || imageByte.Length == 0)
                return null;
            string imgPhoto = Convert.ToBase64String(imageByte);
            return imgPhoto;
        }
        /// <summary>
        /// 将byte[]转为Bitmap
        /// </summary>
        /// <param name="imgPhoto"></param>
        /// <returns></returns>
        public static Bitmap GetBitmapFromByte(byte[] imgPhoto) {
            if(imgPhoto == null || imgPhoto.Length == 0)
                return null;
            using(MemoryStream ms = new MemoryStream(imgPhoto)) {
                using(Bitmap image = new Bitmap(ms)) {
                    return image;
                }
            }
        }
        /// <summary>
        /// 将byte[]转为图片
        /// </summary>
        /// <param name="buffer"></param>
        /// <returns></returns>
        public static Image GetImageFromByte(byte[] buffer) {
            if(buffer == null || buffer.Length == 0)
                return null;
            using(MemoryStream ms = new MemoryStream(buffer)) {
                return Image.FromStream(ms);
            }
        }
        #endregion

        #region 加密解密
        #region MD5加密
        /// <summary>
        /// GetMD5
        /// </summary>
        /// <param name="source">加密原文</param>
        /// <returns>加密成功返回加密后的字符串，失败返回源串</returns>
        public string ConvertEncryptMD5(string source) {
            try {
                byte[] b = System.Text.Encoding.Default.GetBytes(source);
                b = new System.Security.Cryptography.MD5CryptoServiceProvider().ComputeHash(b);
                string ret = "";
                for(int i = 0; i < b.Length; i++) {
                    ret += b[i].ToString("x").PadLeft(2, '0');
                }
                return ret;
            }
            catch(Exception) {
                return source;
            }
        }

        /// <summary>
        /// 用MD5加密，全大写
        /// </summary>
        /// <param name="source">待加密字符串</param>
        /// <returns>加密后字符串</returns>
        public string ConvertEncryptMD5ToUpper(string source) {
            return ConvertEncryptMD5(source)?.ToUpper();
        }
        #endregion

        #region DES加密

        //默认密钥向量
        private static byte[] Keys = { 0xEF, 0xAB, 0x56, 0x78, 0x90, 0x34, 0xCD, 0x12 };
        /// <summary>
        /// DES加密字符串
        /// </summary>
        /// <param name="encryptString">待加密的字符串</param>
        /// <param name="encryptKey">加密密钥,要求为8位</param>
        /// <returns>加密成功返回加密后的字符串，失败返回源串</returns>
        public string ConvertEncryptDES(string encryptString, string encryptKey) {
            try {
                byte[] rgbKey = Encoding.UTF8.GetBytes(encryptKey.Substring(0, 8));
                byte[] rgbIV = Keys;
                byte[] inputByteArray = Encoding.UTF8.GetBytes(encryptString);
                DESCryptoServiceProvider dCSP = new DESCryptoServiceProvider();
                MemoryStream mStream = new MemoryStream();
                CryptoStream cStream = new CryptoStream(mStream, dCSP.CreateEncryptor(rgbKey, rgbIV), CryptoStreamMode.Write);
                cStream.Write(inputByteArray, 0, inputByteArray.Length);
                cStream.FlushFinalBlock();
                return Convert.ToBase64String(mStream.ToArray());
            }
            catch {
                return encryptString;
            }
        }

        /// <summary>
        /// DES解密字符串
        /// </summary>
        /// <param name="decryptString">待解密的字符串</param>
        /// <param name="decryptKey">解密密钥,要求为8位,和加密密钥相同</param>
        /// <returns>解密成功返回解密后的字符串，失败返源串</returns>
        public string ConvertDecryptDES(string decryptString, string decryptKey) {
            try {
                byte[] rgbKey = Encoding.UTF8.GetBytes(decryptKey.Substring(0, 8));
                byte[] rgbIV = Keys;
                byte[] inputByteArray = Convert.FromBase64String(decryptString);
                DESCryptoServiceProvider DCSP = new DESCryptoServiceProvider();
                MemoryStream mStream = new MemoryStream();
                CryptoStream cStream = new CryptoStream(mStream, DCSP.CreateDecryptor(rgbKey, rgbIV), CryptoStreamMode.Write);
                cStream.Write(inputByteArray, 0, inputByteArray.Length);
                cStream.FlushFinalBlock();
                return Encoding.UTF8.GetString(mStream.ToArray());
            }
            catch {
                return decryptString;
            }
        }
        #endregion

        #region SHA1加密
        /// <summary>
        /// use sha1 to encrypt string
        /// </summary>
        public string ConvertEncryptSHA1(string source) {
            byte[] StrRes = Encoding.Default.GetBytes(source);
            HashAlgorithm iSHA = new SHA1CryptoServiceProvider();
            StrRes = iSHA.ComputeHash(StrRes);
            StringBuilder EnText = new StringBuilder();
            foreach(byte iByte in StrRes) {
                EnText.AppendFormat("{0:x2}", iByte);
            }
            return EnText.ToString();
        }
        #endregion

        #region RSA加密
        /// <summary>
        /// RSA加密
        /// </summary>
        /// <param name="publickey"></param>
        /// <param name="content"></param>
        /// <returns></returns>
        public string ConvertEncryptRSA(string publickey, string content) {
            RSACryptoServiceProvider rsa = new RSACryptoServiceProvider();
            byte[] cipherbytes;
            rsa.FromXmlString(publickey);
            cipherbytes = rsa.Encrypt(Encoding.UTF8.GetBytes(content), false);

            return Convert.ToBase64String(cipherbytes);
        }

        /// <summary>
        /// RSA解密
        /// </summary>
        /// <param name="privatekey"></param>
        /// <param name="content"></param>
        /// <returns></returns>
        public string ConvertDecryptRSA(string privatekey, string content) {
            RSACryptoServiceProvider rsa = new RSACryptoServiceProvider();
            byte[] cipherbytes;
            rsa.FromXmlString(privatekey);
            cipherbytes = rsa.Decrypt(Convert.FromBase64String(content), false);

            return Encoding.UTF8.GetString(cipherbytes);
        }
        #endregion

        #region AES加密
        /*
          * 跨程序使用AES加密，需要注意运算模式和填充模式;
          * 比如java
          * 需要设置
          * Mode = CipherMode.ECB; //C#默认运算模式为CBC，java默认为ECB，因此要将C#的加密方式改为ECB
          * Padding = PaddingMode.PKCS7; //设置为PKCS7，否则解密后字符串结尾会出现多余字符
          * 测试地址：http://www.seacha.com/tools/aes.html 
          */

        //默认密钥向量 
        private static byte[] _Aeskey = { 0x12, 0x34, 0x56, 0x78, 0x90, 0xAB, 0xCD, 0xEF, 0x12, 0x34, 0x56, 0x78, 0x90, 0xAB, 0xCD, 0xEF };

        /// <summary>
        /// AES加密，返回Base64编码后的字符
        /// </summary>
        /// <param name="plainText">明文字符串</param>
        /// <param name="strKey">密钥</param>
        /// <returns>返回加密后的Base64编码字符串</returns>
        public string ConvertEncryptAES(string plainText, string strKey) {
            byte[] byteArray = Encoding.UTF8.GetBytes(plainText);

            RijndaelManaged rDel = new RijndaelManaged();
            rDel.Key = Encoding.UTF8.GetBytes(strKey);
            rDel.IV = _Aeskey;
            rDel.BlockSize = 128;
            rDel.Mode = CipherMode.ECB;//设置为ECB
            rDel.Padding = PaddingMode.PKCS7;//设置为PKCS7，否则解密后字符串结尾会出现多余字符

            ICryptoTransform cTransform = rDel.CreateEncryptor();
            var s = cTransform.TransformFinalBlock(byteArray, 0, byteArray.Length);
            var encrypt = Convert.ToBase64String(s);
            rDel.Clear();
            return encrypt;
        }
        /// <summary>
        /// AES解密，返回解密后的字符串
        /// </summary>
        /// <param name="cipherText">Base64编码的密文</param>
        /// <param name="strKey">密钥</param>
        /// <returns>返回解密后的字符串</returns>
        public string ConvertDecryptAES(string cipherText, string strKey) {
            byte[] byteArray = Convert.FromBase64String(cipherText);

            RijndaelManaged rDel = new RijndaelManaged();
            rDel.Key = Encoding.UTF8.GetBytes(strKey);
            rDel.IV = _Aeskey;
            rDel.BlockSize = 128;
            rDel.Mode = CipherMode.ECB;//必须设置为ECB
            rDel.Padding = PaddingMode.PKCS7;//必须设置为PKCS7

            ICryptoTransform cTransform = rDel.CreateDecryptor();

            var s = cTransform.TransformFinalBlock(byteArray, 0, byteArray.Length);

            var decrypt = Encoding.UTF8.GetString(s);
            rDel.Clear();
            return decrypt;



        }
        #endregion

        #region Base64编码
        /// <summary>
        /// Base64加密
        /// </summary>
        /// <param name="source"></param>
        /// <returns></returns>
        public string ConvertEncryptBase64(string source) {
            byte[] bytes = Encoding.Default.GetBytes(source);
            return Convert.ToBase64String(bytes);
        }
        /// <summary>
        /// Base64加密
        /// </summary>
        /// <param name="bytes"></param>
        /// <returns></returns>
        public string ConvertEncryptBase64(byte[] bytes) {
            return Convert.ToBase64String(bytes);
        }
        /// <summary>
        /// Base64解密
        /// </summary>
        /// <param name="source"></param>
        /// <returns></returns>
        public string ConvertDecryptBase64(string source) {
            if(string.IsNullOrEmpty(source))
                return null;
            try {
                byte[] outputb = Convert.FromBase64String(source);
                return Encoding.Default.GetString(outputb);
            }
            catch(Exception) {
                return null;
            }
        }
        #endregion

        #region RSA-SHA1 数字签名
        /// <summary>
        /// 数字签名 
        /// </summary>
        /// <param name="plaintext">原文</param>
        /// <param name="privateKey">私钥</param>
        /// <returns>Base64 签名</returns>
        public string ConvertHashAndSignString(string plaintext, string privateKey) {
            UTF8Encoding ByteConverter = new UTF8Encoding();
            byte[] dataToEncrypt = ByteConverter.GetBytes(plaintext);

            using(RSACryptoServiceProvider RSAalg = new RSACryptoServiceProvider()) {
                RSAalg.FromXmlString(privateKey);
                //使用SHA1进行摘要算法，生成签名
                byte[] encryptedData = RSAalg.SignData(dataToEncrypt, new SHA1CryptoServiceProvider());
                return Convert.ToBase64String(encryptedData);
            }
        }
        /// <summary>
        /// 验证签名
        /// </summary>
        /// <param name="plaintext">原文</param>
        /// <param name="SignedData">Base64 签名</param>
        /// <param name="publicKey">公钥</param>
        /// <returns></returns>
        public bool ConvertVerifySigned(string plaintext, string SignedData, string publicKey) {
            try {
                using(RSACryptoServiceProvider RSAalg = new RSACryptoServiceProvider()) {
                    RSAalg.FromXmlString(publicKey);
                    UTF8Encoding ByteConverter = new UTF8Encoding();
                    byte[] dataToVerifyBytes = ByteConverter.GetBytes(plaintext);
                    byte[] signedDataBytes = Convert.FromBase64String(SignedData);
                    return RSAalg.VerifyData(dataToVerifyBytes, new SHA1CryptoServiceProvider(), signedDataBytes);
                }
            }
            catch(Exception) {
                return false;
            }
        }
        #endregion
        #endregion
    }
}
