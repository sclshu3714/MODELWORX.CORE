using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using SharpCompress.Archives;
using SharpCompress.Archives.Zip;
using SharpCompress.Common;
using SharpCompress.Readers;
using SharpCompress.Writers;

namespace VXHelper
{
    public class VXZip
    {
        private static readonly object lockObject = new object();   //对象锁，用于控制多线程异步操作
        private static VXZip zip = null;//全局设置

        /// <summary>
        /// 全局设置
        /// </summary>
        public VXZip() { }
        /// <summary>
        /// 默认的全局设置
        /// </summary>
        public static VXZip ZIPExt {
            get {
                lock(lockObject)  //上锁，解决多线程异步操作时的相互影响
                {
                    if(null == zip) {
                        zip = new VXZip();
                    }
                }
                return zip;
            }
        }
        /// <summary>
        /// 解压文件
        /// </summary>
        /// <param name="filePath"></param>
        /// <returns></returns>
        public bool UnZipFile(string filePath, string destinationDirectory) {
            return StaticUnZipFile(filePath, destinationDirectory);
        }
        /// <summary>
        /// 解压文件
        /// </summary>
        /// <param name="filePath"></param>
        /// <returns></returns>
        public static bool StaticUnZipFile(string filePath, string destinationDirectory) {
            string Extension = Path.GetExtension(filePath);
            switch(Extension?.ToUpper()) {
                case ".RAR":
                    using(Stream stream = File.OpenRead(filePath)) {
                        var reader = ReaderFactory.Open(stream);
                        while(reader.MoveToNextEntry()) {
                            if(!reader.Entry.IsDirectory) {
                                //Console.WriteLine(reader.Entry.FilePath);
                                ExtractionOptions options = new ExtractionOptions() {
                                    ExtractFullPath = true,
                                    Overwrite = true,
                                };
                                reader.WriteEntryToDirectory(destinationDirectory, options);
                            }
                        }
                    }
                    break;
                case ".ZIP": {
                        var archive = ArchiveFactory.Open(filePath);
                        foreach(var entry in archive.Entries) {
                            if(!entry.IsDirectory) {
                                ExtractionOptions options = new ExtractionOptions() {
                                    ExtractFullPath = true,
                                    Overwrite = true,
                                };
                                entry.WriteToDirectory(destinationDirectory, options);
                            }
                        }
                    }
                    break;
                default:
                    return false;
            }
            return true;
        }
        /// <summary>
        /// 压缩文件
        /// </summary>
        /// <param name="filePath"></param>
        /// <returns></returns>
        public bool ZipFile(string filePath, string destinationDirectory) {
            return StaticZipFile(filePath, destinationDirectory);
        }
        /// <summary>
        /// 压缩文件
        /// </summary>
        /// <param name="filePath"></param>
        /// <returns></returns>
        public static bool StaticZipFile(string filePath, string destinationDirectory) {
            string Extension = Path.GetExtension(filePath);
            switch(Extension?.ToUpper()) {
                case ".RAR":
                    using(var archive = File.OpenWrite(filePath)) {
                        using(var zipWriter = WriterFactory.Open(archive, ArchiveType.Rar, CompressionType.Deflate)) {
                            zipWriter.WriteAll(destinationDirectory, "*", SearchOption.AllDirectories);
                        }
                    }
                    break;
                case ".ZIP":
                    using(var archive = File.OpenWrite(filePath)) {
                        using(var zipWriter = WriterFactory.Open(archive, ArchiveType.Zip, CompressionType.Deflate)) {
                            zipWriter.WriteAll(destinationDirectory, "*", SearchOption.AllDirectories);
                        }
                    }
                    break;
                default:
                    return false;
            }
            return true;
        }

        ///// <summary>
        ///// 压缩文件/文件夹
        ///// </summary>
        ///// <param name="filePath">需要压缩的文件/文件夹路径</param>
        ///// <param name="zipPath">压缩文件路径（zip后缀）</param>
        ///// <param name="password">密码</param>
        ///// <param name="filterExtenList">需要过滤的文件后缀名</param>
        //public static void CompressionFile(string filePath, string zipPath, string password = "", List<string> filterExtenList = null) {
        //    try {
        //        using(ZipFile zip = new ZipFile(Encoding.UTF8)) {
        //            if(!string.IsNullOrWhiteSpace(password)) {
        //                zip.Password = password;
        //            }
        //            if(Directory.Exists(filePath)) {
        //                if(filterExtenList == null)
        //                    zip.AddDirectory(filePath);
        //                else
        //                    AddDirectory(zip, filePath, filePath, filterExtenList);
        //            }
        //            else if(File.Exists(filePath)) {
        //                zip.AddFile(filePath, "");
        //            }
        //            zip.Save(zipPath);
        //        }
        //    }
        //    catch(Exception ex) {
        //        throw ex;
        //    }
        //}

        ///// <summary>
        ///// 添加文件夹
        ///// </summary>
        ///// <param name="zip">ZipFile对象</param>
        ///// <param name="dirPath">需要压缩的文件夹路径</param>
        ///// <param name="rootPath">根目录路径</param>
        ///// <param name="filterExtenList">需要过滤的文件后缀名</param>
        //public static void AddDirectory(ZipFile zip, string dirPath, string rootPath, List<string> filterExtenList) {
        //    var files = Directory.GetFiles(dirPath);
        //    for(int i = 0; i < files.Length; i++) {
        //        //如果Contains不支持第二个参数，就用.ToLower()
        //        if(filterExtenList == null || (filterExtenList != null && !filterExtenList.Any(d => Path.GetExtension(files[i]).Contains(d, StringComparison.OrdinalIgnoreCase)))) {
        //            //获取相对路径作为zip文件中目录路径
        //            //zip.AddFile(files[i], Path.GetRelativePath(rootPath, dirPath));

        //            //如果没有Path.GetRelativePath方法，可以用下面代码替换
        //            string relativePath = Path.GetFullPath(dirPath).Replace(Path.GetFullPath(rootPath), "");
        //            zip.AddFile(files[i], relativePath);
        //        }
        //    }
        //    var dirs = Directory.GetDirectories(dirPath);
        //    for(int i = 0; i < dirs.Length; i++) {
        //        AddDirectory(zip, dirs[i], rootPath, filterExtenList);
        //    }
        //}

        /// <summary>
        /// 压缩文件/文件夹
        /// </summary>
        /// <param name="filePath">需要压缩的文件/文件夹路径</param>
        /// <param name="zipPath">压缩文件路径（zip后缀）</param>
        /// <param name="filterExtenList">需要过滤的文件后缀名</param>
        public static void CompressionFile(string filePath, string zipPath, List<string> filterExtenList = null) {
            try {
                using(var zip = File.Create(zipPath)) {
                    var option = new WriterOptions(CompressionType.Deflate) {
                        ArchiveEncoding = new SharpCompress.Common.ArchiveEncoding() {
                            Default = Encoding.UTF8
                        }
                    };
                    using(var zipWriter = WriterFactory.Open(zip, ArchiveType.Zip, option)) {
                        if(Directory.Exists(filePath)) {
                            //添加文件夹
                            zipWriter.WriteAll(filePath, "*", (path) => filterExtenList == null ? true : !filterExtenList.Any(d => Path.GetExtension(path).Contains(d/*, StringComparison.OrdinalIgnoreCase*/)), SearchOption.AllDirectories);
                        }
                        else if(File.Exists(filePath)) {
                            zipWriter.Write(Path.GetFileName(filePath), filePath);
                        }
                    }
                }
            }
            catch(Exception ex) {
                throw ex;
            }
        }
        /// <summary>
        /// 解压文件
        /// </summary>
        /// <param name="zipPath">压缩文件路径</param>
        /// <param name="destinationDirectory">目标目录-解压到文件夹路径</param>
        /// <param name="password">密码</param>
        public static void DeCompressionFile(string zipPath, string destinationDirectory, string password = "") {
            if(!File.Exists(zipPath)) {
                throw new ArgumentNullException("zipPath压缩文件不存在");
            }
            Directory.CreateDirectory(destinationDirectory);
            try {
                using(Stream stream = File.OpenRead(zipPath)) {
                    var option = new ReaderOptions() {
                        ArchiveEncoding = new SharpCompress.Common.ArchiveEncoding() {
                            Default = Encoding.UTF8
                        }
                    };
                    if(!string.IsNullOrWhiteSpace(password)) {
                        option.Password = password;
                    }

                    var reader = ReaderFactory.Open(stream, option);
                    while(reader.MoveToNextEntry()) {
                        if(reader.Entry.IsDirectory) {
                            Directory.CreateDirectory(Path.Combine(destinationDirectory, reader.Entry.Key));
                        }
                        else {
                            //创建父级目录，防止Entry文件,解压时由于目录不存在报异常
                            var file = Path.Combine(destinationDirectory, reader.Entry.Key);
                            Directory.CreateDirectory(Path.GetDirectoryName(file));
                            reader.WriteEntryToFile(file);
                        }
                    }
                }
            }
            catch(Exception ex) {
                throw ex;
            }
        }
    }
}
