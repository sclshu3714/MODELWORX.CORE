
namespace OCCT.NET
{
    partial class MainForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            DevExpress.XtraBars.Docking2010.Views.Tabbed.DockingContainer dockingContainer1 = new DevExpress.XtraBars.Docking2010.Views.Tabbed.DockingContainer();
            this.documentGroup1 = new DevExpress.XtraBars.Docking2010.Views.Tabbed.DocumentGroup(this.components);
            this.document1 = new DevExpress.XtraBars.Docking2010.Views.Tabbed.Document(this.components);
            this.ribbon = new DevExpress.XtraBars.Ribbon.RibbonControl();
            this.btnGrid = new DevExpress.XtraBars.BarButtonItem();
            this.btnLine = new DevExpress.XtraBars.BarButtonItem();
            this.btnFace = new DevExpress.XtraBars.BarButtonItem();
            this.btnSolid = new DevExpress.XtraBars.BarButtonItem();
            this.btnShell = new DevExpress.XtraBars.BarButtonItem();
            this.btnDeleteSelect = new DevExpress.XtraBars.BarButtonItem();
            this.btnClearAll = new DevExpress.XtraBars.BarButtonItem();
            this.ribbonPage1 = new DevExpress.XtraBars.Ribbon.RibbonPage();
            this.ribbonPageGroup1 = new DevExpress.XtraBars.Ribbon.RibbonPageGroup();
            this.ribbonPageGroup3 = new DevExpress.XtraBars.Ribbon.RibbonPageGroup();
            this.ribbonPageGroup4 = new DevExpress.XtraBars.Ribbon.RibbonPageGroup();
            this.ribbonPageGroup5 = new DevExpress.XtraBars.Ribbon.RibbonPageGroup();
            this.ribbonPageGroup6 = new DevExpress.XtraBars.Ribbon.RibbonPageGroup();
            this.ribbonPage2 = new DevExpress.XtraBars.Ribbon.RibbonPage();
            this.ribbonPageGroup2 = new DevExpress.XtraBars.Ribbon.RibbonPageGroup();
            this.ribbonStatusBar = new DevExpress.XtraBars.Ribbon.RibbonStatusBar();
            this.dockManager1 = new DevExpress.XtraBars.Docking.DockManager(this.components);
            this.hideContainerBottom = new DevExpress.XtraBars.Docking.AutoHideContainer();
            this.dockPanel3 = new DevExpress.XtraBars.Docking.DockPanel();
            this.dockPanel3_Container = new DevExpress.XtraBars.Docking.ControlContainer();
            this.gclInfo = new DevExpress.XtraGrid.GridControl();
            this.gvwInfo = new DevExpress.XtraGrid.Views.Grid.GridView();
            this.dockPanel1 = new DevExpress.XtraBars.Docking.DockPanel();
            this.dockPanel1_Container = new DevExpress.XtraBars.Docking.ControlContainer();
            this.trlShape = new DevExpress.XtraTreeList.TreeList();
            this.treeListColumn1 = new DevExpress.XtraTreeList.Columns.TreeListColumn();
            this.dockPanel2 = new DevExpress.XtraBars.Docking.DockPanel();
            this.dockPanel2_Container = new DevExpress.XtraBars.Docking.ControlContainer();
            this.vgcProperty = new DevExpress.XtraVerticalGrid.VGridControl();
            this.dockViewPanel = new DevExpress.XtraBars.Docking.DockPanel();
            this.dockPanel4_Container = new DevExpress.XtraBars.Docking.ControlContainer();
            this.RWControl = new DevExpress.XtraEditors.PanelControl();
            this.documentManager1 = new DevExpress.XtraBars.Docking2010.DocumentManager(this.components);
            this.tabbedView1 = new DevExpress.XtraBars.Docking2010.Views.Tabbed.TabbedView(this.components);
            this.btnAnimation = new DevExpress.XtraBars.BarButtonItem();
            ((System.ComponentModel.ISupportInitialize)(this.documentGroup1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.document1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.ribbon)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dockManager1)).BeginInit();
            this.hideContainerBottom.SuspendLayout();
            this.dockPanel3.SuspendLayout();
            this.dockPanel3_Container.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.gclInfo)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.gvwInfo)).BeginInit();
            this.dockPanel1.SuspendLayout();
            this.dockPanel1_Container.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.trlShape)).BeginInit();
            this.dockPanel2.SuspendLayout();
            this.dockPanel2_Container.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.vgcProperty)).BeginInit();
            this.dockViewPanel.SuspendLayout();
            this.dockPanel4_Container.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.RWControl)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.documentManager1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.tabbedView1)).BeginInit();
            this.SuspendLayout();
            // 
            // documentGroup1
            // 
            this.documentGroup1.Items.AddRange(new DevExpress.XtraBars.Docking2010.Views.Tabbed.Document[] {
            this.document1});
            // 
            // document1
            // 
            this.document1.Caption = "显示";
            this.document1.ControlName = "dockViewPanel";
            this.document1.FloatLocation = new System.Drawing.Point(0, 0);
            this.document1.FloatSize = new System.Drawing.Size(200, 200);
            this.document1.Properties.AllowClose = DevExpress.Utils.DefaultBoolean.True;
            this.document1.Properties.AllowFloat = DevExpress.Utils.DefaultBoolean.True;
            this.document1.Properties.AllowFloatOnDoubleClick = DevExpress.Utils.DefaultBoolean.True;
            // 
            // ribbon
            // 
            this.ribbon.ExpandCollapseItem.Id = 0;
            this.ribbon.Items.AddRange(new DevExpress.XtraBars.BarItem[] {
            this.ribbon.ExpandCollapseItem,
            this.ribbon.SearchEditItem,
            this.btnGrid,
            this.btnLine,
            this.btnFace,
            this.btnSolid,
            this.btnShell,
            this.btnDeleteSelect,
            this.btnClearAll,
            this.btnAnimation});
            this.ribbon.Location = new System.Drawing.Point(0, 0);
            this.ribbon.MaxItemId = 9;
            this.ribbon.Name = "ribbon";
            this.ribbon.Pages.AddRange(new DevExpress.XtraBars.Ribbon.RibbonPage[] {
            this.ribbonPage1,
            this.ribbonPage2});
            this.ribbon.Size = new System.Drawing.Size(1093, 197);
            this.ribbon.StatusBar = this.ribbonStatusBar;
            // 
            // btnGrid
            // 
            this.btnGrid.Caption = "点图形";
            this.btnGrid.Id = 1;
            this.btnGrid.ImageOptions.Image = global::OCCT.NET.Properties.Resources.point_16x16;
            this.btnGrid.ImageOptions.LargeImage = global::OCCT.NET.Properties.Resources.point_32x32;
            this.btnGrid.Name = "btnGrid";
            // 
            // btnLine
            // 
            this.btnLine.Caption = "线图形";
            this.btnLine.Id = 2;
            this.btnLine.ImageOptions.Image = global::OCCT.NET.Properties.Resources.lineitem_16x16;
            this.btnLine.ImageOptions.LargeImage = global::OCCT.NET.Properties.Resources.lineitem_32x32;
            this.btnLine.Name = "btnLine";
            // 
            // btnFace
            // 
            this.btnFace.Caption = "面图形";
            this.btnFace.Id = 3;
            this.btnFace.ImageOptions.Image = global::OCCT.NET.Properties.Resources.morelayoutoptions_16x16;
            this.btnFace.ImageOptions.LargeImage = global::OCCT.NET.Properties.Resources.morelayoutoptions_32x32;
            this.btnFace.Name = "btnFace";
            // 
            // btnSolid
            // 
            this.btnSolid.Caption = "体图形";
            this.btnSolid.Id = 4;
            this.btnSolid.ImageOptions.Image = global::OCCT.NET.Properties.Resources.cube_16x16;
            this.btnSolid.ImageOptions.LargeImage = global::OCCT.NET.Properties.Resources.cube_32x32;
            this.btnSolid.Name = "btnSolid";
            // 
            // btnShell
            // 
            this.btnShell.Caption = "壳图像";
            this.btnShell.Id = 5;
            this.btnShell.ImageOptions.Image = global::OCCT.NET.Properties.Resources.group2_16x16;
            this.btnShell.ImageOptions.LargeImage = global::OCCT.NET.Properties.Resources.group2_32x32;
            this.btnShell.Name = "btnShell";
            // 
            // btnDeleteSelect
            // 
            this.btnDeleteSelect.Caption = "删除选择";
            this.btnDeleteSelect.Id = 6;
            this.btnDeleteSelect.ImageOptions.Image = global::OCCT.NET.Properties.Resources.deletedatasource_16x16;
            this.btnDeleteSelect.ImageOptions.LargeImage = global::OCCT.NET.Properties.Resources.deletedatasource_32x32;
            this.btnDeleteSelect.Name = "btnDeleteSelect";
            // 
            // btnClearAll
            // 
            this.btnClearAll.Caption = "清除";
            this.btnClearAll.Id = 7;
            this.btnClearAll.ImageOptions.Image = global::OCCT.NET.Properties.Resources.resetmodeldifferences_16x16;
            this.btnClearAll.ImageOptions.LargeImage = global::OCCT.NET.Properties.Resources.resetmodeldifferences_32x32;
            this.btnClearAll.Name = "btnClearAll";
            // 
            // ribbonPage1
            // 
            this.ribbonPage1.Groups.AddRange(new DevExpress.XtraBars.Ribbon.RibbonPageGroup[] {
            this.ribbonPageGroup1,
            this.ribbonPageGroup3,
            this.ribbonPageGroup4,
            this.ribbonPageGroup5,
            this.ribbonPageGroup6});
            this.ribbonPage1.Name = "ribbonPage1";
            this.ribbonPage1.Text = "演示";
            // 
            // ribbonPageGroup1
            // 
            this.ribbonPageGroup1.ItemLinks.Add(this.btnGrid);
            this.ribbonPageGroup1.ItemLinks.Add(this.btnLine);
            this.ribbonPageGroup1.ItemLinks.Add(this.btnFace);
            this.ribbonPageGroup1.ItemLinks.Add(this.btnSolid);
            this.ribbonPageGroup1.ItemLinks.Add(this.btnShell);
            this.ribbonPageGroup1.ItemLinks.Add(this.btnAnimation);
            this.ribbonPageGroup1.Name = "ribbonPageGroup1";
            this.ribbonPageGroup1.Text = "几何图形";
            // 
            // ribbonPageGroup3
            // 
            this.ribbonPageGroup3.Name = "ribbonPageGroup3";
            this.ribbonPageGroup3.Text = "布尔运算";
            // 
            // ribbonPageGroup4
            // 
            this.ribbonPageGroup4.Name = "ribbonPageGroup4";
            this.ribbonPageGroup4.Text = "显示设置";
            // 
            // ribbonPageGroup5
            // 
            this.ribbonPageGroup5.ItemLinks.Add(this.btnDeleteSelect);
            this.ribbonPageGroup5.ItemLinks.Add(this.btnClearAll);
            this.ribbonPageGroup5.Name = "ribbonPageGroup5";
            this.ribbonPageGroup5.Text = "视图操作";
            // 
            // ribbonPageGroup6
            // 
            this.ribbonPageGroup6.Name = "ribbonPageGroup6";
            this.ribbonPageGroup6.Text = "文件处理";
            // 
            // ribbonPage2
            // 
            this.ribbonPage2.Groups.AddRange(new DevExpress.XtraBars.Ribbon.RibbonPageGroup[] {
            this.ribbonPageGroup2});
            this.ribbonPage2.Name = "ribbonPage2";
            this.ribbonPage2.Text = "系统";
            // 
            // ribbonPageGroup2
            // 
            this.ribbonPageGroup2.Name = "ribbonPageGroup2";
            this.ribbonPageGroup2.Text = "帮助文档";
            // 
            // ribbonStatusBar
            // 
            this.ribbonStatusBar.Location = new System.Drawing.Point(0, 625);
            this.ribbonStatusBar.Name = "ribbonStatusBar";
            this.ribbonStatusBar.Ribbon = this.ribbon;
            this.ribbonStatusBar.Size = new System.Drawing.Size(1093, 30);
            // 
            // dockManager1
            // 
            this.dockManager1.AutoHideContainers.AddRange(new DevExpress.XtraBars.Docking.AutoHideContainer[] {
            this.hideContainerBottom});
            this.dockManager1.Form = this;
            this.dockManager1.RootPanels.AddRange(new DevExpress.XtraBars.Docking.DockPanel[] {
            this.dockPanel1,
            this.dockPanel2,
            this.dockViewPanel});
            this.dockManager1.TopZIndexControls.AddRange(new string[] {
            "DevExpress.XtraBars.BarDockControl",
            "DevExpress.XtraBars.StandaloneBarDockControl",
            "System.Windows.Forms.MenuStrip",
            "System.Windows.Forms.StatusStrip",
            "System.Windows.Forms.StatusBar",
            "DevExpress.XtraBars.Ribbon.RibbonStatusBar",
            "DevExpress.XtraBars.Ribbon.RibbonControl",
            "DevExpress.XtraBars.Navigation.OfficeNavigationBar",
            "DevExpress.XtraBars.Navigation.TileNavPane",
            "DevExpress.XtraBars.TabFormControl",
            "DevExpress.XtraBars.FluentDesignSystem.FluentDesignFormControl",
            "DevExpress.XtraBars.ToolbarForm.ToolbarFormControl"});
            // 
            // hideContainerBottom
            // 
            this.hideContainerBottom.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(240)))), ((int)(((byte)(240)))), ((int)(((byte)(240)))));
            this.hideContainerBottom.Controls.Add(this.dockPanel3);
            this.hideContainerBottom.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.hideContainerBottom.Location = new System.Drawing.Point(0, 597);
            this.hideContainerBottom.Name = "hideContainerBottom";
            this.hideContainerBottom.Size = new System.Drawing.Size(1093, 28);
            // 
            // dockPanel3
            // 
            this.dockPanel3.Controls.Add(this.dockPanel3_Container);
            this.dockPanel3.Dock = DevExpress.XtraBars.Docking.DockingStyle.Bottom;
            this.dockPanel3.ID = new System.Guid("f58f3234-472f-4a2a-9c06-41bc657f0420");
            this.dockPanel3.Location = new System.Drawing.Point(0, 0);
            this.dockPanel3.Name = "dockPanel3";
            this.dockPanel3.OriginalSize = new System.Drawing.Size(200, 200);
            this.dockPanel3.SavedDock = DevExpress.XtraBars.Docking.DockingStyle.Bottom;
            this.dockPanel3.SavedIndex = 2;
            this.dockPanel3.Size = new System.Drawing.Size(1093, 200);
            this.dockPanel3.Text = "消息";
            this.dockPanel3.Visibility = DevExpress.XtraBars.Docking.DockVisibility.AutoHide;
            // 
            // dockPanel3_Container
            // 
            this.dockPanel3_Container.Controls.Add(this.gclInfo);
            this.dockPanel3_Container.Location = new System.Drawing.Point(4, 34);
            this.dockPanel3_Container.Name = "dockPanel3_Container";
            this.dockPanel3_Container.Size = new System.Drawing.Size(1085, 162);
            this.dockPanel3_Container.TabIndex = 0;
            // 
            // gclInfo
            // 
            this.gclInfo.Dock = System.Windows.Forms.DockStyle.Fill;
            this.gclInfo.Location = new System.Drawing.Point(0, 0);
            this.gclInfo.MainView = this.gvwInfo;
            this.gclInfo.MenuManager = this.ribbon;
            this.gclInfo.Name = "gclInfo";
            this.gclInfo.Size = new System.Drawing.Size(1085, 162);
            this.gclInfo.TabIndex = 0;
            this.gclInfo.ViewCollection.AddRange(new DevExpress.XtraGrid.Views.Base.BaseView[] {
            this.gvwInfo});
            // 
            // gvwInfo
            // 
            this.gvwInfo.GridControl = this.gclInfo;
            this.gvwInfo.Name = "gvwInfo";
            // 
            // dockPanel1
            // 
            this.dockPanel1.Controls.Add(this.dockPanel1_Container);
            this.dockPanel1.Dock = DevExpress.XtraBars.Docking.DockingStyle.Left;
            this.dockPanel1.ID = new System.Guid("6b94067b-3ff1-443f-9a68-b804d9174aa3");
            this.dockPanel1.Location = new System.Drawing.Point(0, 197);
            this.dockPanel1.Name = "dockPanel1";
            this.dockPanel1.OriginalSize = new System.Drawing.Size(237, 200);
            this.dockPanel1.Size = new System.Drawing.Size(237, 400);
            this.dockPanel1.Text = "工作";
            // 
            // dockPanel1_Container
            // 
            this.dockPanel1_Container.Controls.Add(this.trlShape);
            this.dockPanel1_Container.Location = new System.Drawing.Point(4, 32);
            this.dockPanel1_Container.Name = "dockPanel1_Container";
            this.dockPanel1_Container.Size = new System.Drawing.Size(227, 364);
            this.dockPanel1_Container.TabIndex = 0;
            // 
            // trlShape
            // 
            this.trlShape.Columns.AddRange(new DevExpress.XtraTreeList.Columns.TreeListColumn[] {
            this.treeListColumn1});
            this.trlShape.Dock = System.Windows.Forms.DockStyle.Fill;
            this.trlShape.Location = new System.Drawing.Point(0, 0);
            this.trlShape.MenuManager = this.ribbon;
            this.trlShape.Name = "trlShape";
            this.trlShape.Size = new System.Drawing.Size(227, 364);
            this.trlShape.TabIndex = 0;
            // 
            // treeListColumn1
            // 
            this.treeListColumn1.Caption = "图形";
            this.treeListColumn1.FieldName = "图形";
            this.treeListColumn1.Name = "treeListColumn1";
            this.treeListColumn1.Visible = true;
            this.treeListColumn1.VisibleIndex = 0;
            // 
            // dockPanel2
            // 
            this.dockPanel2.Controls.Add(this.dockPanel2_Container);
            this.dockPanel2.Dock = DevExpress.XtraBars.Docking.DockingStyle.Right;
            this.dockPanel2.ID = new System.Guid("3e54aa7e-7fad-493c-a6b8-179124d769e6");
            this.dockPanel2.Location = new System.Drawing.Point(803, 197);
            this.dockPanel2.Name = "dockPanel2";
            this.dockPanel2.OriginalSize = new System.Drawing.Size(290, 200);
            this.dockPanel2.Size = new System.Drawing.Size(290, 400);
            this.dockPanel2.Text = "属性";
            // 
            // dockPanel2_Container
            // 
            this.dockPanel2_Container.Controls.Add(this.vgcProperty);
            this.dockPanel2_Container.Location = new System.Drawing.Point(6, 32);
            this.dockPanel2_Container.Name = "dockPanel2_Container";
            this.dockPanel2_Container.Size = new System.Drawing.Size(280, 364);
            this.dockPanel2_Container.TabIndex = 0;
            // 
            // vgcProperty
            // 
            this.vgcProperty.Cursor = System.Windows.Forms.Cursors.Default;
            this.vgcProperty.Dock = System.Windows.Forms.DockStyle.Fill;
            this.vgcProperty.Location = new System.Drawing.Point(0, 0);
            this.vgcProperty.MenuManager = this.ribbon;
            this.vgcProperty.Name = "vgcProperty";
            this.vgcProperty.Size = new System.Drawing.Size(280, 364);
            this.vgcProperty.TabIndex = 0;
            // 
            // dockViewPanel
            // 
            this.dockViewPanel.Controls.Add(this.dockPanel4_Container);
            this.dockViewPanel.DockedAsTabbedDocument = true;
            this.dockViewPanel.ID = new System.Guid("df1475ee-61c6-422e-adb5-1ab808fec082");
            this.dockViewPanel.Name = "dockViewPanel";
            this.dockViewPanel.OriginalSize = new System.Drawing.Size(200, 200);
            this.dockViewPanel.Text = "显示";
            // 
            // dockPanel4_Container
            // 
            this.dockPanel4_Container.Controls.Add(this.RWControl);
            this.dockPanel4_Container.Location = new System.Drawing.Point(0, 0);
            this.dockPanel4_Container.Name = "dockPanel4_Container";
            this.dockPanel4_Container.Size = new System.Drawing.Size(560, 365);
            this.dockPanel4_Container.TabIndex = 0;
            // 
            // RWControl
            // 
            this.RWControl.Appearance.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(224)))), ((int)(((byte)(224)))), ((int)(((byte)(224)))));
            this.RWControl.Appearance.Options.UseBackColor = true;
            this.RWControl.Dock = System.Windows.Forms.DockStyle.Fill;
            this.RWControl.Location = new System.Drawing.Point(0, 0);
            this.RWControl.Name = "RWControl";
            this.RWControl.Size = new System.Drawing.Size(560, 365);
            this.RWControl.TabIndex = 0;
            // 
            // documentManager1
            // 
            this.documentManager1.ContainerControl = this;
            this.documentManager1.View = this.tabbedView1;
            this.documentManager1.ViewCollection.AddRange(new DevExpress.XtraBars.Docking2010.Views.BaseView[] {
            this.tabbedView1});
            // 
            // tabbedView1
            // 
            this.tabbedView1.DocumentGroups.AddRange(new DevExpress.XtraBars.Docking2010.Views.Tabbed.DocumentGroup[] {
            this.documentGroup1});
            this.tabbedView1.Documents.AddRange(new DevExpress.XtraBars.Docking2010.Views.BaseDocument[] {
            this.document1});
            dockingContainer1.Element = this.documentGroup1;
            this.tabbedView1.RootContainer.Nodes.AddRange(new DevExpress.XtraBars.Docking2010.Views.Tabbed.DockingContainer[] {
            dockingContainer1});
            // 
            // btnAnimation
            // 
            this.btnAnimation.Caption = "动画";
            this.btnAnimation.Id = 8;
            this.btnAnimation.ImageOptions.Image = global::OCCT.NET.Properties.Resources.video_16x16;
            this.btnAnimation.ImageOptions.LargeImage = global::OCCT.NET.Properties.Resources.video_32x32;
            this.btnAnimation.Name = "btnAnimation";
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 18F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1093, 655);
            this.Controls.Add(this.dockPanel2);
            this.Controls.Add(this.dockPanel1);
            this.Controls.Add(this.hideContainerBottom);
            this.Controls.Add(this.ribbonStatusBar);
            this.Controls.Add(this.ribbon);
            this.Name = "MainForm";
            this.Ribbon = this.ribbon;
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.StatusBar = this.ribbonStatusBar;
            this.Text = "OCCT.NET";
            this.WindowState = System.Windows.Forms.FormWindowState.Maximized;
            ((System.ComponentModel.ISupportInitialize)(this.documentGroup1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.document1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.ribbon)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dockManager1)).EndInit();
            this.hideContainerBottom.ResumeLayout(false);
            this.dockPanel3.ResumeLayout(false);
            this.dockPanel3_Container.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.gclInfo)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.gvwInfo)).EndInit();
            this.dockPanel1.ResumeLayout(false);
            this.dockPanel1_Container.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.trlShape)).EndInit();
            this.dockPanel2.ResumeLayout(false);
            this.dockPanel2_Container.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.vgcProperty)).EndInit();
            this.dockViewPanel.ResumeLayout(false);
            this.dockPanel4_Container.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.RWControl)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.documentManager1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.tabbedView1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private DevExpress.XtraBars.Ribbon.RibbonControl ribbon;
        private DevExpress.XtraBars.Ribbon.RibbonPage ribbonPage1;
        private DevExpress.XtraBars.Ribbon.RibbonPageGroup ribbonPageGroup1;
        private DevExpress.XtraBars.Ribbon.RibbonStatusBar ribbonStatusBar;
        private DevExpress.XtraBars.Ribbon.RibbonPageGroup ribbonPageGroup3;
        private DevExpress.XtraBars.Ribbon.RibbonPageGroup ribbonPageGroup4;
        private DevExpress.XtraBars.Ribbon.RibbonPageGroup ribbonPageGroup5;
        private DevExpress.XtraBars.Ribbon.RibbonPage ribbonPage2;
        private DevExpress.XtraBars.Ribbon.RibbonPageGroup ribbonPageGroup2;
        private DevExpress.XtraBars.Docking.DockManager dockManager1;
        private DevExpress.XtraBars.Docking.DockPanel dockPanel3;
        private DevExpress.XtraBars.Docking.ControlContainer dockPanel3_Container;
        private DevExpress.XtraGrid.GridControl gclInfo;
        private DevExpress.XtraGrid.Views.Grid.GridView gvwInfo;
        private DevExpress.XtraBars.Docking.DockPanel dockPanel2;
        private DevExpress.XtraBars.Docking.ControlContainer dockPanel2_Container;
        private DevExpress.XtraVerticalGrid.VGridControl vgcProperty;
        private DevExpress.XtraBars.Docking.DockPanel dockPanel1;
        private DevExpress.XtraBars.Docking.ControlContainer dockPanel1_Container;
        private DevExpress.XtraTreeList.TreeList trlShape;
        private DevExpress.XtraBars.Docking.DockPanel dockViewPanel;
        private DevExpress.XtraBars.Docking.ControlContainer dockPanel4_Container;
        private DevExpress.XtraBars.Docking2010.DocumentManager documentManager1;
        private DevExpress.XtraBars.Docking2010.Views.Tabbed.TabbedView tabbedView1;
        private DevExpress.XtraBars.Docking2010.Views.Tabbed.DocumentGroup documentGroup1;
        private DevExpress.XtraBars.Docking2010.Views.Tabbed.Document document1;
        private DevExpress.XtraEditors.PanelControl RWControl;
        private DevExpress.XtraTreeList.Columns.TreeListColumn treeListColumn1;
        private DevExpress.XtraBars.Docking.AutoHideContainer hideContainerBottom;
        private DevExpress.XtraBars.BarButtonItem btnGrid;
        private DevExpress.XtraBars.BarButtonItem btnLine;
        private DevExpress.XtraBars.BarButtonItem btnFace;
        private DevExpress.XtraBars.BarButtonItem btnSolid;
        private DevExpress.XtraBars.Ribbon.RibbonPageGroup ribbonPageGroup6;
        private DevExpress.XtraBars.BarButtonItem btnShell;
        private DevExpress.XtraBars.BarButtonItem btnDeleteSelect;
        private DevExpress.XtraBars.BarButtonItem btnClearAll;
        private DevExpress.XtraBars.BarButtonItem btnAnimation;
    }
}