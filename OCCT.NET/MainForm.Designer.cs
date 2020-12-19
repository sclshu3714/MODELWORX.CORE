namespace OCCT.NET
{
    partial class MainForm
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing) {
            if(disposing && (components != null)) {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要修改
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent() {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MainForm));
            this.toolStrip1 = new System.Windows.Forms.ToolStrip();
            this.btnSetModel = new System.Windows.Forms.ToolStripButton();
            this.btnBgColor = new System.Windows.Forms.ToolStripButton();
            this.btnStep = new System.Windows.Forms.ToolStripButton();
            this.btnDisk = new System.Windows.Forms.ToolStripButton();
            this.btnClearAll = new System.Windows.Forms.ToolStripButton();
            this.RWControl = new System.Windows.Forms.Panel();
            this.tableLayoutPanel1 = new System.Windows.Forms.TableLayoutPanel();
            this.tvwNode = new System.Windows.Forms.TreeView();
            this.toolStripDropDownButton1 = new System.Windows.Forms.ToolStripDropDownButton();
            this.btnGrid = new System.Windows.Forms.ToolStripMenuItem();
            this.btnLine = new System.Windows.Forms.ToolStripMenuItem();
            this.btnFace = new System.Windows.Forms.ToolStripMenuItem();
            this.btnSolid = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripDropDownButton2 = new System.Windows.Forms.ToolStripDropDownButton();
            this.btnAnimation = new System.Windows.Forms.ToolStripMenuItem();
            this.暂停ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.停止ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.btnDeleteSelect = new System.Windows.Forms.ToolStripButton();
            this.btnShell = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStrip1.SuspendLayout();
            this.tableLayoutPanel1.SuspendLayout();
            this.SuspendLayout();
            // 
            // toolStrip1
            // 
            this.toolStrip1.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.toolStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.btnSetModel,
            this.btnBgColor,
            this.btnStep,
            this.btnDisk,
            this.btnClearAll,
            this.toolStripDropDownButton1,
            this.toolStripDropDownButton2,
            this.btnDeleteSelect});
            this.toolStrip1.Location = new System.Drawing.Point(0, 0);
            this.toolStrip1.Name = "toolStrip1";
            this.toolStrip1.Size = new System.Drawing.Size(800, 27);
            this.toolStrip1.TabIndex = 0;
            this.toolStrip1.Text = "toolStrip1";
            // 
            // btnSetModel
            // 
            this.btnSetModel.Image = global::OCCT.NET.Properties.Resources.group2_16x16;
            this.btnSetModel.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.btnSetModel.Name = "btnSetModel";
            this.btnSetModel.Size = new System.Drawing.Size(93, 24);
            this.btnSetModel.Text = "显示模式";
            this.btnSetModel.Click += new System.EventHandler(this.btnSetModel_Click);
            // 
            // btnBgColor
            // 
            this.btnBgColor.Image = global::OCCT.NET.Properties.Resources.group2_16x16;
            this.btnBgColor.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.btnBgColor.Name = "btnBgColor";
            this.btnBgColor.Size = new System.Drawing.Size(78, 24);
            this.btnBgColor.Text = "背景色";
            this.btnBgColor.Click += new System.EventHandler(this.btnBgColor_Click);
            // 
            // btnStep
            // 
            this.btnStep.Image = global::OCCT.NET.Properties.Resources.article_16x16;
            this.btnStep.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.btnStep.Name = "btnStep";
            this.btnStep.Size = new System.Drawing.Size(68, 24);
            this.btnStep.Text = "STEP";
            this.btnStep.Click += new System.EventHandler(this.btnStep_Click);
            // 
            // btnDisk
            // 
            this.btnDisk.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Text;
            this.btnDisk.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.btnDisk.Name = "btnDisk";
            this.btnDisk.Size = new System.Drawing.Size(43, 24);
            this.btnDisk.Text = "管道";
            this.btnDisk.ToolTipText = "Disk";
            this.btnDisk.Click += new System.EventHandler(this.toolStripButton1_Click);
            // 
            // btnClearAll
            // 
            this.btnClearAll.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Text;
            this.btnClearAll.Image = ((System.Drawing.Image)(resources.GetObject("btnClearAll.Image")));
            this.btnClearAll.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.btnClearAll.Name = "btnClearAll";
            this.btnClearAll.Size = new System.Drawing.Size(43, 24);
            this.btnClearAll.Text = "清空";
            this.btnClearAll.ToolTipText = "Clear";
            // 
            // RWControl
            // 
            this.RWControl.Dock = System.Windows.Forms.DockStyle.Fill;
            this.RWControl.Location = new System.Drawing.Point(229, 3);
            this.RWControl.Name = "RWControl";
            this.RWControl.Size = new System.Drawing.Size(568, 417);
            this.RWControl.TabIndex = 1;
            // 
            // tableLayoutPanel1
            // 
            this.tableLayoutPanel1.ColumnCount = 2;
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 28.25F));
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 71.75F));
            this.tableLayoutPanel1.Controls.Add(this.tvwNode, 0, 0);
            this.tableLayoutPanel1.Controls.Add(this.RWControl, 1, 0);
            this.tableLayoutPanel1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tableLayoutPanel1.Location = new System.Drawing.Point(0, 27);
            this.tableLayoutPanel1.Name = "tableLayoutPanel1";
            this.tableLayoutPanel1.RowCount = 1;
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel1.Size = new System.Drawing.Size(800, 423);
            this.tableLayoutPanel1.TabIndex = 2;
            // 
            // tvwNode
            // 
            this.tvwNode.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tvwNode.Location = new System.Drawing.Point(3, 3);
            this.tvwNode.Name = "tvwNode";
            this.tvwNode.Size = new System.Drawing.Size(220, 417);
            this.tvwNode.TabIndex = 0;
            // 
            // toolStripDropDownButton1
            // 
            this.toolStripDropDownButton1.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.btnGrid,
            this.btnLine,
            this.btnFace,
            this.btnSolid,
            this.btnShell});
            this.toolStripDropDownButton1.Image = ((System.Drawing.Image)(resources.GetObject("toolStripDropDownButton1.Image")));
            this.toolStripDropDownButton1.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripDropDownButton1.Name = "toolStripDropDownButton1";
            this.toolStripDropDownButton1.Size = new System.Drawing.Size(103, 24);
            this.toolStripDropDownButton1.Text = "几何图形";
            // 
            // btnGrid
            // 
            this.btnGrid.Name = "btnGrid";
            this.btnGrid.Size = new System.Drawing.Size(224, 26);
            this.btnGrid.Text = "点";
            // 
            // btnLine
            // 
            this.btnLine.Name = "btnLine";
            this.btnLine.Size = new System.Drawing.Size(224, 26);
            this.btnLine.Text = "线";
            // 
            // btnFace
            // 
            this.btnFace.Name = "btnFace";
            this.btnFace.Size = new System.Drawing.Size(224, 26);
            this.btnFace.Text = "面";
            // 
            // btnSolid
            // 
            this.btnSolid.Name = "btnSolid";
            this.btnSolid.Size = new System.Drawing.Size(224, 26);
            this.btnSolid.Text = "体";
            // 
            // toolStripDropDownButton2
            // 
            this.toolStripDropDownButton2.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.btnAnimation,
            this.暂停ToolStripMenuItem,
            this.停止ToolStripMenuItem});
            this.toolStripDropDownButton2.Image = ((System.Drawing.Image)(resources.GetObject("toolStripDropDownButton2.Image")));
            this.toolStripDropDownButton2.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripDropDownButton2.Name = "toolStripDropDownButton2";
            this.toolStripDropDownButton2.Size = new System.Drawing.Size(73, 24);
            this.toolStripDropDownButton2.Text = "动画";
            // 
            // btnAnimation
            // 
            this.btnAnimation.Name = "btnAnimation";
            this.btnAnimation.Size = new System.Drawing.Size(224, 26);
            this.btnAnimation.Text = "开始";
            // 
            // 暂停ToolStripMenuItem
            // 
            this.暂停ToolStripMenuItem.Name = "暂停ToolStripMenuItem";
            this.暂停ToolStripMenuItem.Size = new System.Drawing.Size(224, 26);
            this.暂停ToolStripMenuItem.Text = "暂停";
            // 
            // 停止ToolStripMenuItem
            // 
            this.停止ToolStripMenuItem.Name = "停止ToolStripMenuItem";
            this.停止ToolStripMenuItem.Size = new System.Drawing.Size(224, 26);
            this.停止ToolStripMenuItem.Text = "停止";
            // 
            // btnDeleteSelect
            // 
            this.btnDeleteSelect.Image = ((System.Drawing.Image)(resources.GetObject("btnDeleteSelect.Image")));
            this.btnDeleteSelect.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.btnDeleteSelect.Name = "btnDeleteSelect";
            this.btnDeleteSelect.Size = new System.Drawing.Size(93, 24);
            this.btnDeleteSelect.Text = "删除选择";
            // 
            // btnShell
            // 
            this.btnShell.Name = "btnShell";
            this.btnShell.Size = new System.Drawing.Size(224, 26);
            this.btnShell.Text = "壳";
            // 
            // MainFormOld
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.tableLayoutPanel1);
            this.Controls.Add(this.toolStrip1);
            this.Name = "MainFormOld";
            this.Text = "OCCT";
            this.toolStrip1.ResumeLayout(false);
            this.toolStrip1.PerformLayout();
            this.tableLayoutPanel1.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ToolStrip toolStrip1;
        private System.Windows.Forms.ToolStripButton btnStep;
        private System.Windows.Forms.ToolStripButton btnBgColor;
        private System.Windows.Forms.Panel RWControl;
        private System.Windows.Forms.ToolStripButton btnSetModel;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel1;
        private System.Windows.Forms.TreeView tvwNode;
        private System.Windows.Forms.ToolStripButton btnDisk;
        private System.Windows.Forms.ToolStripButton btnClearAll;
        private System.Windows.Forms.ToolStripDropDownButton toolStripDropDownButton1;
        private System.Windows.Forms.ToolStripMenuItem btnGrid;
        private System.Windows.Forms.ToolStripMenuItem btnLine;
        private System.Windows.Forms.ToolStripMenuItem btnFace;
        private System.Windows.Forms.ToolStripMenuItem btnSolid;
        private System.Windows.Forms.ToolStripDropDownButton toolStripDropDownButton2;
        private System.Windows.Forms.ToolStripMenuItem btnAnimation;
        private System.Windows.Forms.ToolStripMenuItem 暂停ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 停止ToolStripMenuItem;
        private System.Windows.Forms.ToolStripButton btnDeleteSelect;
        private System.Windows.Forms.ToolStripMenuItem btnShell;
    }
}

