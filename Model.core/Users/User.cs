using System;
using System.Collections.Generic;
using System.Drawing;
using System.IO;
using System.Runtime.Serialization;
using System.Text;

namespace Model.core.Users
{
    /// <summary>
    /// 用户
    /// </summary>
    [DataContract]
    public class User
    {
        /// <summary>
        /// 用户
        /// </summary>
        public User() { }
        /// <summary>
        /// 用户编号
        /// </summary>
        [DataMember]
        public string UserId { get { return _UserId; } set { _UserId = value; } }  //用户编号
        /// <summary>
        /// 用户名
        /// </summary>
        [DataMember]
        public string UserName { get { return _UserName; } set { _UserName = value; } }  //用户名
        /// <summary>
        /// 密码
        /// </summary>
        [DataMember]
        public string PassWord { get { return _PassWord; } set { _PassWord = value; } }  //密码
        /// <summary>
        /// 工号
        /// </summary>
        [DataMember]
        public string JobNumber { get { return _JobNumber; } set { _JobNumber = value; } } //工号
        /// <summary>
        /// 名
        /// </summary>
        [DataMember]
        public string FirstName { get { return _FirstName; } set { _FirstName = value; } }  //名
        /// <summary>
        /// 姓
        /// </summary>
        [DataMember]
        public string LastName { get { return _LastName; } set { _LastName = value; } }  //姓
        /// <summary>
        /// 姓名
        /// </summary>
        [DataMember]
        public string FullName { get { return _FullName; } set { _FullName = value; } }  //姓名
        /// <summary>
        /// 性别
        /// </summary>
        [DataMember]
        public string Sex { get { return _Sex; } set { _Sex = value; } }  //性别
        /// <summary>
        /// 出生日期
        /// </summary>
        [DataMember]
        public string BirthDate { get { return _BirthDate; } set { _BirthDate = value; } }  //出生日期
        /// <summary>
        /// 后缀 博士 先生 女士 工程师 ....
        /// </summary>
        [DataMember]
        public string Prefix { get { return _Prefix; } set { _Prefix = value; } }    //后缀 博士 先生 女士 工程师 
        /// <summary>
        /// 职称 职业
        /// </summary>
        [DataMember]
        public string Title { get { return _Title; } set { _Title = value; } }    //职称
        /// <summary>
        /// 部门
        /// </summary>
        [DataMember]
        public string DepartmentId { get { return _DepartmentId; } set { _DepartmentId = value; } }  //部门
        /// <summary>
        /// 职位
        /// </summary>
        [DataMember]
        public string Status { get { return _Status; } set { _Status = value; } }//职位
        /// <summary>
        /// 雇佣日期
        /// </summary>
        [DataMember]
        public string HireDate { get { return _HireDate; } set { _HireDate = value; } }//雇佣日期
        /// <summary>
        /// 地址
        /// </summary>
        [DataMember]
        public string Address { get { return _Address; } set { _Address = value; } }  //地址
        /// <summary>
        /// 家庭电话
        /// </summary>
        [DataMember]
        public string HomePhone { get { return _HomePhone; } set { _HomePhone = value; } }  //家庭电话
        /// <summary>
        /// 手机
        /// </summary>
        [DataMember]
        public string MobilePhone { get { return _MobilePhone; } set { _MobilePhone = value; } }  //手机
        /// <summary>
        /// 邮箱
        /// </summary>
        [DataMember]
        public string Email { get { return _Email; } set { _Email = value; } }  //邮箱
        /// <summary>
        /// 相片
        /// </summary>
        public Image ImagePhoto {
            get {
                if(Photo == null || Photo.Length == 0)
                    return default;
                using(MemoryStream ms = new MemoryStream(Photo)) {
                    return Image.FromStream(ms);
                }
            }
        }
        /// <summary>
        /// 相片
        /// </summary>
        [DataMember]
        public byte[] Photo { get { return _Photo; } set { _Photo = value; } }  //邮箱
        /// <summary>
        /// 简介
        /// </summary>
        [DataMember]
        public string Profile { get { return _Profile; } set { _Profile = value; } }  //邮箱
        private string _UserId;  //用户编号
        private string _UserName;  //用户名
        private string _PassWord;//密码
        private string _JobNumber; //工号
        private string _FirstName;  //姓
        private string _LastName;  //姓
        private string _FullName;  //姓名
        private string _Sex;//性别
        private string _BirthDate;  //出生日期
        private string _Prefix;    //后缀 博士 先生 女士 工程师 
        private string _Title;//职称
        private string _DepartmentId;  //部门
        private string _Status;//职位
        private string _HireDate;//雇佣日期
        private string _Address;  //地址
        private string _HomePhone;  //家庭电话
        private string _MobilePhone;  //手机
        private string _Email;  //邮箱
        private byte[] _Photo;  //照片
        private string _Profile;  //简介
    }
}
