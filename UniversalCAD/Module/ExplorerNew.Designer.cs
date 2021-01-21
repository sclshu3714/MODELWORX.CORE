namespace UniversalCAD.Module {
    partial class ExplorerNew {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;
        protected override void Dispose(bool disposing) {
            if(disposing) {
                if(components != null) {
                    components.Dispose();
                }
            }
            base.Dispose(disposing);
        }

        #region Designer generated code
        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent() {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(ExplorerNew));
            this.navigationTreeList = new DevExpress.XtraTreeList.TreeList();
            this.navNameCol = new DevExpress.XtraTreeList.Columns.TreeListColumn();
            this.svgImageCollection1 = new DevExpress.Utils.SvgImageCollection(this.components);
            this.breadCrumbEdit = new DevExpress.XtraEditors.BreadCrumbEdit();
            this.layoutControl1 = new DevExpress.XtraLayout.LayoutControl();
            this.backButton = new DevExpress.XtraEditors.SimpleButton();
            this.forwardButton = new DevExpress.XtraEditors.SimpleButton();
            this.recentButton = new DevExpress.XtraEditors.CheckButton();
            this.upButton = new DevExpress.XtraEditors.SimpleButton();
            this.searchControl = new DevExpress.XtraEditors.SearchControl();
            this.treeList1 = new DevExpress.XtraTreeList.TreeList();
            this.displayNameCol = new DevExpress.XtraTreeList.Columns.TreeListColumn();
            this.displayModifiedCol = new DevExpress.XtraTreeList.Columns.TreeListColumn();
            this.displaySizeCol = new DevExpress.XtraTreeList.Columns.TreeListColumn();
            this.displayCreateCol = new DevExpress.XtraTreeList.Columns.TreeListColumn();
            this.displayTypeColumn = new DevExpress.XtraTreeList.Columns.TreeListColumn();
            this.displayPathColumn = new DevExpress.XtraTreeList.Columns.TreeListColumn();
            this.Root = new DevExpress.XtraLayout.LayoutControlGroup();
            this.breadCrumbItem = new DevExpress.XtraLayout.LayoutControlItem();
            this.searchControlItem = new DevExpress.XtraLayout.LayoutControlItem();
            this.upButtonItem = new DevExpress.XtraLayout.LayoutControlItem();
            this.recentButtonItem = new DevExpress.XtraLayout.LayoutControlItem();
            this.forwardButtonItem = new DevExpress.XtraLayout.LayoutControlItem();
            this.backButtonItem = new DevExpress.XtraLayout.LayoutControlItem();
            this.sidePanel2 = new DevExpress.XtraEditors.SidePanel();
            this.sidePanel1 = new DevExpress.XtraEditors.SidePanel();
            this.behaviorManager1 = new DevExpress.Utils.Behaviors.BehaviorManager(this.components);
            this.breadCrumbEvents1 = new DevExpress.XtraEditors.Behaviors.BreadCrumbEvents(this.components);
            ((System.ComponentModel.ISupportInitialize)(this.navigationTreeList)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.svgImageCollection1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.breadCrumbEdit.Properties)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.layoutControl1)).BeginInit();
            this.layoutControl1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.searchControl.Properties)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.treeList1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.Root)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.breadCrumbItem)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.searchControlItem)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.upButtonItem)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.recentButtonItem)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.forwardButtonItem)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.backButtonItem)).BeginInit();
            this.sidePanel2.SuspendLayout();
            this.sidePanel1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.behaviorManager1)).BeginInit();
            this.SuspendLayout();
            // 
            // navigationTreeList
            // 
            this.behaviorManager1.SetBehaviors(this.navigationTreeList, new DevExpress.Utils.Behaviors.Behavior[] {
            ((DevExpress.Utils.Behaviors.Behavior)(DevExpress.XtraEditors.Behaviors.BreadCrumbBehavior.Create(typeof(DevExpress.XtraTreeList.TreeListBreadCrumbSource), this.breadCrumbEdit, "DisplayName", "Name", this.breadCrumbEvents1)))});
            this.navigationTreeList.BorderStyle = DevExpress.XtraEditors.Controls.BorderStyles.NoBorder;
            this.navigationTreeList.Columns.AddRange(new DevExpress.XtraTreeList.Columns.TreeListColumn[] {
            this.navNameCol});
            this.navigationTreeList.Dock = System.Windows.Forms.DockStyle.Fill;
            this.navigationTreeList.Location = new System.Drawing.Point(0, 0);
            this.navigationTreeList.Name = "navigationTreeList";
            this.navigationTreeList.OptionsBehavior.Editable = false;
            this.navigationTreeList.OptionsFind.AllowFindPanel = false;
            this.navigationTreeList.OptionsSelection.EnableAppearanceFocusedCell = false;
            this.navigationTreeList.OptionsView.FocusRectStyle = DevExpress.XtraTreeList.DrawFocusRectStyle.None;
            this.navigationTreeList.OptionsView.ShowColumns = false;
            this.navigationTreeList.OptionsView.ShowHorzLines = false;
            this.navigationTreeList.OptionsView.ShowIndentAsRowStyle = true;
            this.navigationTreeList.OptionsView.ShowIndicator = false;
            this.navigationTreeList.OptionsView.ShowVertLines = false;
            this.navigationTreeList.RowHeight = 22;
            this.navigationTreeList.SelectImageList = this.svgImageCollection1;
            this.navigationTreeList.Size = new System.Drawing.Size(239, 572);
            this.navigationTreeList.TabIndex = 1;
            // 
            // navNameCol
            // 
            this.navNameCol.Caption = "DisplayName";
            this.navNameCol.FieldName = "DisplayName";
            this.navNameCol.Name = "navNameCol";
            this.navNameCol.Visible = true;
            this.navNameCol.VisibleIndex = 0;
            // 
            // svgImageCollection1
            // 
            this.svgImageCollection1.Add("electronics_desktopmac", "image://svgimages/icon builder/electronics_desktopmac.svg");
            // 
            // breadCrumbEdit
            // 
            this.breadCrumbEdit.Location = new System.Drawing.Point(141, 5);
            this.breadCrumbEdit.Name = "breadCrumbEdit";
            this.breadCrumbEdit.Properties.Buttons.AddRange(new DevExpress.XtraEditors.Controls.EditorButton[] {
            new DevExpress.XtraEditors.Controls.EditorButton(DevExpress.XtraEditors.Controls.ButtonPredefines.Combo)});
            this.breadCrumbEdit.Properties.Images = this.svgImageCollection1;
            this.breadCrumbEdit.Size = new System.Drawing.Size(710, 22);
            this.breadCrumbEdit.TabIndex = 0;
            // 
            // layoutControl1
            // 
            this.layoutControl1.AllowCustomization = false;
            this.layoutControl1.Controls.Add(this.backButton);
            this.layoutControl1.Controls.Add(this.forwardButton);
            this.layoutControl1.Controls.Add(this.recentButton);
            this.layoutControl1.Controls.Add(this.upButton);
            this.layoutControl1.Controls.Add(this.searchControl);
            this.layoutControl1.Controls.Add(this.breadCrumbEdit);
            this.layoutControl1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.layoutControl1.Location = new System.Drawing.Point(0, 0);
            this.layoutControl1.Name = "layoutControl1";
            this.layoutControl1.OptionsCustomizationForm.DesignTimeCustomizationFormPositionAndSize = new System.Drawing.Rectangle(814, 217, 650, 400);
            this.layoutControl1.OptionsView.ShareLookAndFeelWithChildren = false;
            this.layoutControl1.Root = this.Root;
            this.layoutControl1.Size = new System.Drawing.Size(1020, 32);
            this.layoutControl1.TabIndex = 6;
            this.layoutControl1.Text = "layoutControl1";
            // 
            // backButton
            // 
            this.backButton.AllowFocus = false;
            this.backButton.ButtonStyle = DevExpress.XtraEditors.Controls.BorderStyles.NoBorder;
            this.backButton.ImageOptions.Location = DevExpress.XtraEditors.ImageLocation.MiddleCenter;
            this.backButton.ImageOptions.SvgImage = ((DevExpress.Utils.Svg.SvgImage)(resources.GetObject("backButton.ImageOptions.SvgImage")));
            this.backButton.ImageOptions.SvgImageSize = new System.Drawing.Size(16, 16);
            this.backButton.Location = new System.Drawing.Point(7, 3);
            this.backButton.MinimumSize = new System.Drawing.Size(26, 26);
            this.backButton.Name = "backButton";
            this.backButton.Size = new System.Drawing.Size(26, 26);
            this.backButton.TabIndex = 10;
            this.backButton.Click += new System.EventHandler(this.OnBackButtonClick);
            this.backButton.MouseEnter += new System.EventHandler(this.OnMouseEnterButton);
            this.backButton.MouseLeave += new System.EventHandler(this.OnMouseLeaveButton);
            // 
            // forwardButton
            // 
            this.forwardButton.AllowFocus = false;
            this.forwardButton.ButtonStyle = DevExpress.XtraEditors.Controls.BorderStyles.NoBorder;
            this.forwardButton.ImageOptions.Location = DevExpress.XtraEditors.ImageLocation.MiddleCenter;
            this.forwardButton.ImageOptions.SvgImage = ((DevExpress.Utils.Svg.SvgImage)(resources.GetObject("forwardButton.ImageOptions.SvgImage")));
            this.forwardButton.ImageOptions.SvgImageSize = new System.Drawing.Size(16, 16);
            this.forwardButton.Location = new System.Drawing.Point(41, 3);
            this.forwardButton.MinimumSize = new System.Drawing.Size(26, 26);
            this.forwardButton.Name = "forwardButton";
            this.forwardButton.Size = new System.Drawing.Size(26, 26);
            this.forwardButton.TabIndex = 11;
            this.forwardButton.Click += new System.EventHandler(this.OnForwardButtonClick);
            this.forwardButton.MouseEnter += new System.EventHandler(this.OnMouseEnterButton);
            this.forwardButton.MouseLeave += new System.EventHandler(this.OnMouseLeaveButton);
            // 
            // recentButton
            // 
            this.recentButton.AllowFocus = false;
            this.recentButton.ButtonStyle = DevExpress.XtraEditors.Controls.BorderStyles.NoBorder;
            this.recentButton.Enabled = false;
            this.recentButton.ImageOptions.Location = DevExpress.XtraEditors.ImageLocation.MiddleCenter;
            this.recentButton.ImageOptions.SvgImage = ((DevExpress.Utils.Svg.SvgImage)(resources.GetObject("recentButton.ImageOptions.SvgImage")));
            this.recentButton.ImageOptions.SvgImageSize = new System.Drawing.Size(16, 16);
            this.recentButton.Location = new System.Drawing.Point(75, 3);
            this.recentButton.MinimumSize = new System.Drawing.Size(26, 26);
            this.recentButton.Name = "recentButton";
            this.recentButton.Size = new System.Drawing.Size(26, 26);
            this.recentButton.TabIndex = 15;
            this.recentButton.Text = "checkButton1";
            this.recentButton.CheckedChanged += new System.EventHandler(this.OnRecentButtonCheckedChanged);
            this.recentButton.MouseEnter += new System.EventHandler(this.OnMouseEnterButton);
            this.recentButton.MouseLeave += new System.EventHandler(this.OnMouseLeaveButton);
            // 
            // upButton
            // 
            this.upButton.AllowFocus = false;
            this.upButton.ButtonStyle = DevExpress.XtraEditors.Controls.BorderStyles.NoBorder;
            this.upButton.ImageOptions.Location = DevExpress.XtraEditors.ImageLocation.MiddleCenter;
            this.upButton.ImageOptions.SvgImage = ((DevExpress.Utils.Svg.SvgImage)(resources.GetObject("upButton.ImageOptions.SvgImage")));
            this.upButton.ImageOptions.SvgImageSize = new System.Drawing.Size(16, 16);
            this.upButton.Location = new System.Drawing.Point(109, 3);
            this.upButton.MinimumSize = new System.Drawing.Size(26, 26);
            this.upButton.Name = "upButton";
            this.upButton.Size = new System.Drawing.Size(26, 26);
            this.upButton.TabIndex = 13;
            this.upButton.Click += new System.EventHandler(this.OnUpButtonClick);
            this.upButton.MouseEnter += new System.EventHandler(this.OnMouseEnterButton);
            this.upButton.MouseLeave += new System.EventHandler(this.OnMouseLeaveButton);
            // 
            // searchControl
            // 
            this.searchControl.Client = this.treeList1;
            this.searchControl.Location = new System.Drawing.Point(861, 5);
            this.searchControl.MinimumSize = new System.Drawing.Size(0, 22);
            this.searchControl.Name = "searchControl";
            this.searchControl.Properties.Buttons.AddRange(new DevExpress.XtraEditors.Controls.EditorButton[] {
            new DevExpress.XtraEditors.Repository.ClearButton(),
            new DevExpress.XtraEditors.Repository.SearchButton()});
            this.searchControl.Properties.Client = this.treeList1;
            this.searchControl.Size = new System.Drawing.Size(154, 20);
            this.searchControl.TabIndex = 14;
            // 
            // treeList
            // 
            this.treeList1.AutoFillColumn = this.displayNameCol;
            this.treeList1.Columns.AddRange(new DevExpress.XtraTreeList.Columns.TreeListColumn[] {
            this.displayNameCol,
            this.displayModifiedCol,
            this.displaySizeCol,
            this.displayCreateCol,
            this.displayTypeColumn,
            this.displayPathColumn});
            this.treeList1.Cursor = System.Windows.Forms.Cursors.Default;
            this.treeList1.CustomizationFormBounds = new System.Drawing.Rectangle(1108, 497, 260, 232);
            this.treeList1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.treeList1.Location = new System.Drawing.Point(240, 33);
            this.treeList1.Name = "treeList";
            this.treeList1.OptionsBehavior.Editable = false;
            this.treeList1.OptionsFind.AllowFindPanel = false;
            this.treeList1.OptionsMenu.EnableFooterMenu = false;
            this.treeList1.OptionsMenu.ShowAutoFilterRowItem = false;
            this.treeList1.OptionsSelection.EnableAppearanceFocusedCell = false;
            this.treeList1.OptionsView.AutoWidth = false;
            this.treeList1.OptionsView.FocusRectStyle = DevExpress.XtraTreeList.DrawFocusRectStyle.None;
            this.treeList1.OptionsView.ShowHorzLines = false;
            this.treeList1.OptionsView.ShowIndentAsRowStyle = true;
            this.treeList1.OptionsView.ShowIndicator = false;
            this.treeList1.OptionsView.ShowVertLines = false;
            this.treeList1.RowHeight = 20;
            this.treeList1.SelectImageList = this.svgImageCollection1;
            this.treeList1.Size = new System.Drawing.Size(780, 572);
            this.treeList1.TabIndex = 2;
            // 
            // displayNameCol
            // 
            this.displayNameCol.Caption = "Name";
            this.displayNameCol.FieldName = "Name";
            this.displayNameCol.Name = "displayNameCol";
            this.displayNameCol.Visible = true;
            this.displayNameCol.VisibleIndex = 0;
            this.displayNameCol.Width = 399;
            // 
            // displayModifiedCol
            // 
            this.displayModifiedCol.AppearanceCell.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(109)))), ((int)(((byte)(109)))), ((int)(((byte)(109)))));
            this.displayModifiedCol.AppearanceCell.Options.UseForeColor = true;
            this.displayModifiedCol.Caption = "Date Modified";
            this.displayModifiedCol.FieldName = "DateModified";
            this.displayModifiedCol.Name = "displayModifiedCol";
            this.displayModifiedCol.Visible = true;
            this.displayModifiedCol.VisibleIndex = 1;
            this.displayModifiedCol.Width = 174;
            // 
            // displaySizeCol
            // 
            this.displaySizeCol.AppearanceCell.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(109)))), ((int)(((byte)(109)))), ((int)(((byte)(109)))));
            this.displaySizeCol.AppearanceCell.Options.UseForeColor = true;
            this.displaySizeCol.AppearanceCell.Options.UseTextOptions = true;
            this.displaySizeCol.AppearanceCell.TextOptions.HAlignment = DevExpress.Utils.HorzAlignment.Far;
            this.displaySizeCol.Caption = "Size";
            this.displaySizeCol.FieldName = "Size";
            this.displaySizeCol.Name = "displaySizeCol";
            this.displaySizeCol.Visible = true;
            this.displaySizeCol.VisibleIndex = 3;
            this.displaySizeCol.Width = 99;
            // 
            // displayCreateCol
            // 
            this.displayCreateCol.AppearanceCell.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(109)))), ((int)(((byte)(109)))), ((int)(((byte)(109)))));
            this.displayCreateCol.AppearanceCell.Options.UseForeColor = true;
            this.displayCreateCol.Caption = "Date Created";
            this.displayCreateCol.FieldName = "DateCreated";
            this.displayCreateCol.Name = "displayCreateCol";
            this.displayCreateCol.Width = 135;
            // 
            // displayTypeColumn
            // 
            this.displayTypeColumn.AppearanceCell.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(109)))), ((int)(((byte)(109)))), ((int)(((byte)(109)))));
            this.displayTypeColumn.AppearanceCell.Options.UseForeColor = true;
            this.displayTypeColumn.Caption = "Type";
            this.displayTypeColumn.FieldName = "TypeName";
            this.displayTypeColumn.Name = "displayTypeColumn";
            this.displayTypeColumn.Visible = true;
            this.displayTypeColumn.VisibleIndex = 2;
            this.displayTypeColumn.Width = 106;
            // 
            // displayPathColumn
            // 
            this.displayPathColumn.AppearanceCell.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(109)))), ((int)(((byte)(109)))), ((int)(((byte)(109)))));
            this.displayPathColumn.AppearanceCell.Options.UseForeColor = true;
            this.displayPathColumn.Caption = "Path";
            this.displayPathColumn.FieldName = "FullName";
            this.displayPathColumn.Name = "displayPathColumn";
            // 
            // Root
            // 
            this.Root.EnableIndentsWithoutBorders = DevExpress.Utils.DefaultBoolean.True;
            this.Root.GroupBordersVisible = false;
            this.Root.Items.AddRange(new DevExpress.XtraLayout.BaseLayoutItem[] {
            this.breadCrumbItem,
            this.searchControlItem,
            this.upButtonItem,
            this.recentButtonItem,
            this.forwardButtonItem,
            this.backButtonItem});
            this.Root.Name = "Root";
            this.Root.Padding = new DevExpress.XtraLayout.Utils.Padding(3, 3, 3, 3);
            this.Root.Size = new System.Drawing.Size(1020, 32);
            this.Root.TextVisible = false;
            // 
            // breadCrumbItem
            // 
            this.breadCrumbItem.Control = this.breadCrumbEdit;
            this.breadCrumbItem.Location = new System.Drawing.Point(136, 0);
            this.breadCrumbItem.MaxSize = new System.Drawing.Size(0, 26);
            this.breadCrumbItem.MinSize = new System.Drawing.Size(54, 26);
            this.breadCrumbItem.Name = "breadCrumbItem";
            this.breadCrumbItem.Padding = new DevExpress.XtraLayout.Utils.Padding(2, 5, 2, 2);
            this.breadCrumbItem.Size = new System.Drawing.Size(717, 26);
            this.breadCrumbItem.SizeConstraintsType = DevExpress.XtraLayout.SizeConstraintsType.Custom;
            this.breadCrumbItem.TextSize = new System.Drawing.Size(0, 0);
            this.breadCrumbItem.TextVisible = false;
            // 
            // searchControlItem
            // 
            this.searchControlItem.Control = this.searchControl;
            this.searchControlItem.Location = new System.Drawing.Point(853, 0);
            this.searchControlItem.MaxSize = new System.Drawing.Size(161, 26);
            this.searchControlItem.MinSize = new System.Drawing.Size(161, 26);
            this.searchControlItem.Name = "searchControlItem";
            this.searchControlItem.Padding = new DevExpress.XtraLayout.Utils.Padding(5, 2, 2, 2);
            this.searchControlItem.Size = new System.Drawing.Size(161, 26);
            this.searchControlItem.SizeConstraintsType = DevExpress.XtraLayout.SizeConstraintsType.Custom;
            this.searchControlItem.TextSize = new System.Drawing.Size(0, 0);
            this.searchControlItem.TextVisible = false;
            // 
            // upButtonItem
            // 
            this.upButtonItem.Control = this.upButton;
            this.upButtonItem.Location = new System.Drawing.Point(102, 0);
            this.upButtonItem.MaxSize = new System.Drawing.Size(34, 26);
            this.upButtonItem.MinSize = new System.Drawing.Size(34, 26);
            this.upButtonItem.Name = "upButtonItem";
            this.upButtonItem.Padding = new DevExpress.XtraLayout.Utils.Padding(4, 4, 0, 0);
            this.upButtonItem.Size = new System.Drawing.Size(34, 26);
            this.upButtonItem.SizeConstraintsType = DevExpress.XtraLayout.SizeConstraintsType.Custom;
            this.upButtonItem.TextSize = new System.Drawing.Size(0, 0);
            this.upButtonItem.TextVisible = false;
            // 
            // recentButtonItem
            // 
            this.recentButtonItem.Control = this.recentButton;
            this.recentButtonItem.Location = new System.Drawing.Point(68, 0);
            this.recentButtonItem.MaxSize = new System.Drawing.Size(34, 26);
            this.recentButtonItem.MinSize = new System.Drawing.Size(34, 26);
            this.recentButtonItem.Name = "recentButtonItem";
            this.recentButtonItem.Padding = new DevExpress.XtraLayout.Utils.Padding(4, 4, 0, 0);
            this.recentButtonItem.Size = new System.Drawing.Size(34, 26);
            this.recentButtonItem.SizeConstraintsType = DevExpress.XtraLayout.SizeConstraintsType.Custom;
            this.recentButtonItem.TextSize = new System.Drawing.Size(0, 0);
            this.recentButtonItem.TextVisible = false;
            // 
            // forwardButtonItem
            // 
            this.forwardButtonItem.Control = this.forwardButton;
            this.forwardButtonItem.Location = new System.Drawing.Point(34, 0);
            this.forwardButtonItem.MaxSize = new System.Drawing.Size(34, 26);
            this.forwardButtonItem.MinSize = new System.Drawing.Size(34, 26);
            this.forwardButtonItem.Name = "forwardButtonItem";
            this.forwardButtonItem.Padding = new DevExpress.XtraLayout.Utils.Padding(4, 4, 0, 0);
            this.forwardButtonItem.Size = new System.Drawing.Size(34, 26);
            this.forwardButtonItem.SizeConstraintsType = DevExpress.XtraLayout.SizeConstraintsType.Custom;
            this.forwardButtonItem.TextSize = new System.Drawing.Size(0, 0);
            this.forwardButtonItem.TextVisible = false;
            // 
            // backButtonItem
            // 
            this.backButtonItem.Control = this.backButton;
            this.backButtonItem.Location = new System.Drawing.Point(0, 0);
            this.backButtonItem.MaxSize = new System.Drawing.Size(34, 26);
            this.backButtonItem.MinSize = new System.Drawing.Size(34, 26);
            this.backButtonItem.Name = "backButtonItem";
            this.backButtonItem.Padding = new DevExpress.XtraLayout.Utils.Padding(4, 4, 0, 0);
            this.backButtonItem.Size = new System.Drawing.Size(34, 26);
            this.backButtonItem.SizeConstraintsType = DevExpress.XtraLayout.SizeConstraintsType.Custom;
            this.backButtonItem.TextSize = new System.Drawing.Size(0, 0);
            this.backButtonItem.TextVisible = false;
            // 
            // sidePanel2
            // 
            this.sidePanel2.Controls.Add(this.navigationTreeList);
            this.sidePanel2.Dock = System.Windows.Forms.DockStyle.Left;
            this.sidePanel2.Location = new System.Drawing.Point(0, 33);
            this.sidePanel2.Name = "sidePanel2";
            this.sidePanel2.Size = new System.Drawing.Size(240, 572);
            this.sidePanel2.TabIndex = 4;
            this.sidePanel2.Text = "sidePanel2";
            // 
            // sidePanel1
            // 
            this.sidePanel1.AllowResize = false;
            this.sidePanel1.Controls.Add(this.layoutControl1);
            this.sidePanel1.Dock = System.Windows.Forms.DockStyle.Top;
            this.sidePanel1.Location = new System.Drawing.Point(0, 0);
            this.sidePanel1.Name = "sidePanel1";
            this.sidePanel1.Size = new System.Drawing.Size(1020, 33);
            this.sidePanel1.TabIndex = 5;
            this.sidePanel1.Text = "sidePanel1";
            // 
            // ExplorerNew
            // 
            this.Appearance.Options.UseBackColor = true;
            this.Appearance.Options.UseFont = true;
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.treeList1);
            this.Controls.Add(this.sidePanel2);
            this.Controls.Add(this.sidePanel1);
            this.Name = "ExplorerNew";
            this.Size = new System.Drawing.Size(1020, 605);
            ((System.ComponentModel.ISupportInitialize)(this.navigationTreeList)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.svgImageCollection1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.breadCrumbEdit.Properties)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.layoutControl1)).EndInit();
            this.layoutControl1.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.searchControl.Properties)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.treeList1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.Root)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.breadCrumbItem)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.searchControlItem)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.upButtonItem)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.recentButtonItem)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.forwardButtonItem)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.backButtonItem)).EndInit();
            this.sidePanel2.ResumeLayout(false);
            this.sidePanel1.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.behaviorManager1)).EndInit();
            this.ResumeLayout(false);

        }
        #endregion
        private DevExpress.XtraEditors.BreadCrumbEdit breadCrumbEdit;
        private DevExpress.XtraTreeList.TreeList navigationTreeList;
        private DevExpress.XtraTreeList.TreeList treeList1;
        private DevExpress.XtraTreeList.Columns.TreeListColumn navNameCol;
        private DevExpress.XtraTreeList.Columns.TreeListColumn displayNameCol;
        private DevExpress.XtraTreeList.Columns.TreeListColumn displayModifiedCol;
        private DevExpress.XtraTreeList.Columns.TreeListColumn displaySizeCol;
        private DevExpress.XtraTreeList.Columns.TreeListColumn displayCreateCol;
        private DevExpress.XtraEditors.SidePanel sidePanel2;
        private DevExpress.XtraEditors.SidePanel sidePanel1;
        private DevExpress.Utils.Behaviors.BehaviorManager behaviorManager1;
        private DevExpress.XtraEditors.Behaviors.BreadCrumbEvents breadCrumbEvents1;
        private DevExpress.XtraEditors.SimpleButton upButton;
        private DevExpress.XtraEditors.SimpleButton forwardButton;
        private DevExpress.XtraEditors.SimpleButton backButton;
        private DevExpress.XtraEditors.SearchControl searchControl;
        private DevExpress.Utils.SvgImageCollection svgImageCollection1;
        private DevExpress.XtraTreeList.Columns.TreeListColumn displayTypeColumn;
        private DevExpress.XtraTreeList.Columns.TreeListColumn displayPathColumn;
        private DevExpress.XtraEditors.CheckButton recentButton;
        private DevExpress.XtraLayout.LayoutControl layoutControl1;
        private DevExpress.XtraLayout.LayoutControlGroup Root;
        private DevExpress.XtraLayout.LayoutControlItem breadCrumbItem;
        private DevExpress.XtraLayout.LayoutControlItem searchControlItem;
        private DevExpress.XtraLayout.LayoutControlItem upButtonItem;
        private DevExpress.XtraLayout.LayoutControlItem recentButtonItem;
        private DevExpress.XtraLayout.LayoutControlItem forwardButtonItem;
        private DevExpress.XtraLayout.LayoutControlItem backButtonItem;
    }
}
