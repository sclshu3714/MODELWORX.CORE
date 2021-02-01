using System;
using System.Collections.Generic;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Windows.Forms;
using DevExpress.Data.Utils;
using DevExpress.Utils.Helpers;
using DevExpress.XtraBars;
using DevExpress.XtraEditors;
using DevExpress.XtraEditors.Behaviors;
using DevExpress.XtraEditors.Controls;
using DevExpress.XtraTreeList;
using DevExpress.XtraTreeList.Nodes;
using static OCCT.Foundation.Net.OperationEvents;

namespace UniversalCAD.Modules
{
    public partial class ExplorerNew : XtraForm {
        public TreeList MainControl {
            get { return this.mainTreeList; }
        }
        public ExplorerNew() {
            InitializeComponent();
            CalcImageSize();
        }
        private bool IsSaveState = false;

        public string FullName { get; set; }
        /// <summary>
        /// 自定义事件
        /// </summary>
        private OperationEvent OnOperationEvent;
        /// <summary>
        /// 自定义事件
        /// </summary>
        public event OperationEvent OnCustomEvent {
            add { OnOperationEvent += value; }
            remove { OnOperationEvent -= value; }
        }

        protected string[] WhatsThisCodeFileNames { get { return new string[] { "Modules\\ExplorerNew" }; } }
        protected string WhatsThisXMLFileName { get { return "ExplorerNew"; } }
        void CalcImageSize() {
            Item.ImageSize = new Size(16, 16);
            if(ScaleHelper.ScaleFactor.Width < 1.5)
                return;
            Item.ImageSize = ScaleHelper.ScaleSize(Item.ImageSize);
        }
        protected override void OnLoad(EventArgs e) {
            base.OnLoad(e);
            InitializeBreadCrumb();
            InitializeDisplayTreeList();
            InitializeNavigationTreeList();
            UpdateButtonsState();
            UpdateSaveButtonsState();
        }


        #region Initialize
        //<navigationTreeList>
        void InitializeNavigationTreeList() {
            navigationTreeList.DataSource = new RootItem();
            navigationTreeList.VirtualTreeGetChildNodes += OnNavigationTreeListGetChildNodes;
            navigationTreeList.VirtualTreeGetCellValue += OnNavigationTreeListGetCellValue;
            navigationTreeList.FocusedNodeChanged += OnNavigationTreeListFocusedNodeChanged;
            navigationTreeList.CustomDrawNodeImages += OnTreeListCustomDrawNodeImages;
            navigationTreeList.GetSelectImage += OnTreeListGetStateImage;
            navigationTreeList.ForceInitialize();
            navigationTreeList.Nodes[0].Expand();
            if(navigationTreeList.Nodes[0].Nodes.Count > 2) {
                navigationTreeList.Nodes[0].Nodes[1].Expand();
                navigationTreeList.FocusedNode = navigationTreeList.Nodes[0].Nodes[1];
            }
            else
                navigationTreeList.FocusedNode = navigationTreeList.Nodes[0];
        }
        //</navigationTreeList>
        //<breadCrumbEdit>
        void InitializeBreadCrumb() {
            breadCrumbEdit.Properties.RootImageIndex = 0;
            //breadCrumbEdit.EditValueChanged += BreadCrumbEdit_EditValueChanged;
            breadCrumbEdit.PathChanged += OnBreadCrumbEditPathChanged;
            breadCrumbEvents1.CustomItemContents += OnBreadCrumbEventsCustomItemContents;
            this.btnReturnMain.Click += BtnReturnMain_Click;
        }

        private void BreadCrumbEdit_EditValueChanged(object sender, EventArgs e)
        {
            string path = breadCrumbEdit.Path;
        }

        void InitializeDisplayTreeList() {
            mainTreeList.CustomDrawNodeImages += OnTreeListCustomDrawNodeImages;
            mainTreeList.GetSelectImage += OnTreeListGetStateImage;
            mainTreeList.MouseDoubleClick += OnTreeListMouseDoubleClick;
        }
        //</breadCrumbEdit>
        #endregion
        //<navigationTreeList>
        void OnNavigationTreeListGetCellValue(object sender, VirtualTreeGetCellValueInfo e) {
            e.CellData = ((Item)e.Node).DisplayName;
        }
        void OnNavigationTreeListGetChildNodes(object sender, VirtualTreeGetChildNodesInfo e) {
            Cursor current = Cursor.Current;
            Cursor.Current = Cursors.WaitCursor;
            e.Children = ((Item)e.Node).GetDirectories();
            Cursor.Current = current;
        }
        //</navigationTreeList>
        void OnNavigationTreeListFocusedNodeChanged(object sender, FocusedNodeChangedEventArgs e) {
            if(navigationTreeList.FocusedNode == null)
                return;
            Cursor current = Cursor.Current;
            Cursor.Current = Cursors.WaitCursor;
            searchControl.ClearFilter();
            searchControl.Properties.NullValuePrompt = "Search " + navigationTreeList.FocusedNode.GetDisplayText(0);
            Item _item = (Item)navigationTreeList.GetRow(navigationTreeList.FocusedNode.Id);
            breadCrumbEdit.Properties.RootGlyph = _item.Image;
            mainTreeList.DataSource = _item.GetFilesSystemInfo();
            Cursor.Current = current;
        }
        void OnTreeListCustomDrawNodeImages(object sender, CustomDrawNodeImagesEventArgs e) {
            TreeList tree = (TreeList)sender;
            IFileImage _item = (IFileImage)tree.GetRow(e.Node.Id);
            if(_item.Image == null)
                return;
            e.Cache.DrawImage(_item.Image, e.SelectImageLocation);
            e.Handled = true;
        }
        void OnTreeListGetStateImage(object sender, GetSelectImageEventArgs e) {
            e.NodeImageIndex = 0;
        }
        void OnTreeListMouseDoubleClick(object sender, MouseEventArgs e) {
            if(e.Button != MouseButtons.Left)
                return;
            TreeListHitInfo hitInfo = mainTreeList.CalcHitInfo(e.Location);
            if(hitInfo.Node == null)
                return;
            TreeListNode pressedNode = hitInfo.Node;
            CustomFileInfo fileInfo = (CustomFileInfo)mainTreeList.GetRow(pressedNode.Id);
            if (fileInfo.Type == FileType.File)
            {   //选择的文件
                //SafeProcess.Open(fileInfo.FullName);
                if (!IsSaveState) { //打开
                    FullName = fileInfo.FullName;
                    this.DialogResult = DialogResult.OK;
                    this.Close();
                }
                else { //保存
                    //FullName = fileInfo.FullName;
                    //保存文件执行，save
                }
               
            }
            else
                navigationTreeList.FocusedNode = navigationTreeList.FocusedNode.Nodes[pressedNode.Id];
        }

        /// <summary>
        /// 退出当前文档
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void BtnReturnMain_Click(object sender, EventArgs e)
        {
            this.DialogResult = DialogResult.Cancel;
            this.Close();
        }

        void OnBackButtonClick(object sender, EventArgs e) {
            breadCrumbEdit.GoBack();
        }
        void OnForwardButtonClick(object sender, EventArgs e) {
            breadCrumbEdit.GoForward();
        }
        void OnUpButtonClick(object sender, EventArgs e) {
            breadCrumbEdit.GoUp();
        }

        // <breadCrumbEdit>
        void OnBreadCrumbPathChanged(object sender, BreadCrumbPathChangedEventArgs e)
        {
            UpdateButtonsState();
        }
        //<breadCrumbEdit>
        void OnBreadCrumbEditPathChanged(object sender, BreadCrumbPathChangedEventArgs e) {
            UpdateButtonsState();
        }
        void OnBreadCrumbEventsCustomItemContents(object sender, CustomItemContentsEventArgs e) {
            BreadCrumbNode node = e.Item;
            Item _item = (Item)navigationTreeList.GetRow(((TreeListNode)e.Source).Id);
            node.Value = _item.Name;
            node.Image = _item.Image;
        }
        //</breadCrumbEdit>
        void UpdateButtonsState() {
            forwardButton.Enabled = breadCrumbEdit.CanGoForward;
            backButton.Enabled = breadCrumbEdit.CanGoBack;
            upButton.Enabled = breadCrumbEdit.CanGoUp;
        }
        void OnRecentButtonCheckedChanged(object sender, EventArgs e) {

        }
        void OnMouseEnterButton(object sender, EventArgs e) {
            SimpleButton button = (SimpleButton)sender;
            button.ButtonStyle = BorderStyles.Default;
        }
        void OnMouseLeaveButton(object sender, EventArgs e) {
            SimpleButton button = (SimpleButton)sender;
            button.ButtonStyle = BorderStyles.NoBorder;
        }

        /// <summary>
        /// 是打开文件还是保存文件
        /// </summary>
        public void SetOperationSave(bool IsSave) {
            IsSaveState = IsSave;
            sideSavePanel.Visible = IsSaveState;
        }

        /// <summary>
        /// 保存栏设置
        /// </summary>
        private void UpdateSaveButtonsState()
        {
            sideSavePanel.Visible = IsSaveState;
            this.btnSetting.Click += BtnSetting_Click;
            this.btnSave.Click += BtnSave_Click;
        }


        /// <summary>
        /// 设置栏是否显示
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void BtnSetting_Click(object sender, EventArgs e)
        {
            if (this.flyoutSetPanel.IsPopupOpen)
                this.flyoutSetPanel.HideBeakForm();
            else
                this.flyoutSetPanel.ShowBeakForm();
        }


        /// <summary>
        /// 保存
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void BtnSave_Click(object sender, EventArgs e)
        {
            if (string.IsNullOrEmpty(this.txtNameEdit.Text))
                return;
            FullName = $"{breadCrumbEdit.Path}\\{this.txtNameEdit.Text}{((ImageComboBoxItem)this.cmbExtension.SelectedItem).Value}";
            this.DialogResult = DialogResult.OK;
            this.Close();
        }
    }
    public class RootItem : Item {
        public RootItem() : base("Root") { }
        public override List<Item> GetDirectories() {
            return new List<Item>() { new ThisPCItem() };
        }
        public override Image Image {
            get { return null; }
            set { }
        }
        public override List<CustomFileInfo> GetFilesSystemInfo() {
            return null;
        }
    }
    public class ThisPCItem : Item {
        public ThisPCItem() : base("此电脑") { }
        public override List<Item> GetDirectories() {
            List<Item> items = new List<Item>(10);
            items.Add(new DirectoryItem(Environment.GetFolderPath(Environment.SpecialFolder.DesktopDirectory)));
            items.Add(new DirectoryItem(Environment.GetFolderPath(Environment.SpecialFolder.Recent)));
            items.Add(new DirectoryItem(Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments)));
            items.Add(new DirectoryItem(Environment.GetFolderPath(Environment.SpecialFolder.MyMusic)));
            items.Add(new DirectoryItem(Environment.GetFolderPath(Environment.SpecialFolder.MyPictures)));
            items.Add(new DirectoryItem(Environment.GetFolderPath(Environment.SpecialFolder.MyVideos)));
            string[] drives = Environment.GetLogicalDrives();
            foreach(string drive in drives)
                items.Add(new DriveItem(drive));
            return items;
        }
        public override List<CustomFileInfo> GetFilesSystemInfo() {
            List<CustomFileInfo> infos = new List<CustomFileInfo>(15);
            infos.Add(CreateSystemFolderInfo(new DirectoryInfo(Environment.GetFolderPath(Environment.SpecialFolder.DesktopDirectory))));
            infos.Add(CreateSystemFolderInfo(new DirectoryInfo(Environment.GetFolderPath(Environment.SpecialFolder.Recent))));
            infos.Add(CreateSystemFolderInfo(new DirectoryInfo(Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments))));
            infos.Add(CreateSystemFolderInfo(new DirectoryInfo(Environment.GetFolderPath(Environment.SpecialFolder.MyMusic))));
            infos.Add(CreateSystemFolderInfo(new DirectoryInfo(Environment.GetFolderPath(Environment.SpecialFolder.MyPictures))));
            infos.Add(CreateSystemFolderInfo(new DirectoryInfo(Environment.GetFolderPath(Environment.SpecialFolder.MyVideos))));
            string[] drives = Environment.GetLogicalDrives();
            foreach(string drive in drives) {
                DriveInfo driveInfo = new DriveInfo(drive);
                infos.Add(new CustomFileInfo() {
                    FullName = driveInfo.Name,
                    Name = drive,
                    Image = GetImage(drive),
                    TypeName = "驱动器",
                    Type = FileType.Drive
                });
            }
            return infos;
        }
        CustomFileInfo CreateSystemFolderInfo(FileSystemInfo info) {
            return new CustomFileInfo() {
                Name = info.Name,
                FullName = info.FullName,
                DateCreated = info.CreationTime,
                DateModified = info.LastWriteTime,
                Image = GetImage(info.FullName),
                TypeName = "系统文件夹",
                Type = FileType.SystemFolder
            };
        }
        public override Image Image {
            get { return null; }
            set { }
        }
    }
    public class DriveItem : DirectoryItem {
        public DriveItem(string fullName) : base(fullName) { }
        protected override string GetDirectoryName(string path) {
            string _name = path.Replace(Path.DirectorySeparatorChar.ToString(), "");
            return _name;
        }
        protected override string GetDisplayName(string fullName) {
            return "本地磁盘 (" + Name + ")";
        }
    }
    public class DirectoryItem : Item {
        public DirectoryItem(string fullName) : base(fullName) { }
        public override List<Item> GetDirectories() {
            List<Item> items = new List<Item>(10);
            try {
                if(Directory.Exists(FullName)) {
                    string[] dirs = Directory.GetDirectories(FullName);
                    foreach(string dir in dirs) {
                        var attributes = File.GetAttributes(dir);
                        if((attributes & FileAttributes.Hidden) != FileAttributes.Hidden)
                            items.Add(new DirectoryItem(dir));
                    }
                }
            }
            catch { }
            finally { }
            return items;
        }
        protected override string GetDirectoryName(string path) {
            return Path.GetFileName(path);
        }
    }
    public abstract class Item : IFileImage {
        public Item(string fullName) {
            Image = GetImage(fullName);
            Name = GetDirectoryName(fullName);
            FullName = fullName;
            DisplayName = GetDisplayName(fullName);
        }
        protected virtual string GetDisplayName(string fullName) {
            return Name;
        }
        public string DisplayName {
            get;
            private set;
        }
        public string Name {
            get;
            private set;
        }
        public string FullName {
            get;
            private set;
        }
        public virtual Image Image {
            get;
            set;
        }
        public abstract List<Item> GetDirectories();
        public static Size ImageSize {
            get;
            set;
        }
        protected Image GetImage(string fullName) {
            return FileSystemHelper.GetImage(fullName, IconSizeType.Small, ImageSize);
        }
        protected virtual string GetDirectoryName(string fullName) {
            return fullName;
        }
        public virtual List<CustomFileInfo> GetFilesSystemInfo() {
            List<CustomFileInfo> infos = new List<CustomFileInfo>(15);
            try {
                DirectoryInfo dInfo = new DirectoryInfo(FullName);
                if((int)dInfo.Attributes == -1)
                    return infos;
                var directories = dInfo.GetDirectories();
                foreach(var directory in directories) {
                    if((directory.Attributes & FileAttributes.Hidden) != FileAttributes.Hidden) {
                        infos.Add(new CustomFileInfo() {
                            Name = directory.Name,
                            FullName = directory.FullName,
                            DateCreated = directory.CreationTime,
                            DateModified = directory.LastWriteTime,
                            Image = GetImage(directory.FullName),
                            TypeName = "文件夹",
                            Type = FileType.FileFolder
                        });
                    }
                }
                var files = dInfo.GetFiles();
                foreach(var file in files) {
                    if((file.Attributes & FileAttributes.Hidden) != FileAttributes.Hidden) {
                        infos.Add(new CustomFileInfo() {
                            Name = file.Name,
                            FullName = file.FullName,
                            DateCreated = file.CreationTime,
                            DateModified = file.LastWriteTime,
                            Image = GetImage(file.FullName),
                            TypeName = "文件",
                            Type = FileType.File,
                            Size = file.Length
                        });
                    }
                }
            }
            catch { }
            return infos;
        }
    }
    public class CustomFileInfo : IFileImage {
        public CustomFileInfo() { }
        public Image Image {
            get;
            set;
        }
        public string FullName {
            get;
            set;
        }
        public string Name {
            get;
            set;
        }
        public FileType Type {
            get;
            set;
        }
        public string TypeName {
            get;
            set;
        }
        public DateTime? DateModified {
            get;
            set;
        }
        public DateTime? DateCreated {
            get;
            set;
        }
        public long? Size {
            get;
            set;
        }
    }
    public enum FileType { Drive, SystemFolder, FileFolder, File }
    interface IFileImage {
        Image Image { get; }
    }
}
