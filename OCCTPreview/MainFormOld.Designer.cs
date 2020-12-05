namespace OCCTPreview
{
    partial class MainFormOld
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MainFormOld));
            this.toolStrip1 = new System.Windows.Forms.ToolStrip();
            this.btnSetModel = new System.Windows.Forms.ToolStripButton();
            this.btnBgColor = new System.Windows.Forms.ToolStripButton();
            this.btnStep = new System.Windows.Forms.ToolStripButton();
            this.RWControl = new System.Windows.Forms.Panel();
            this.tableLayoutPanel1 = new System.Windows.Forms.TableLayoutPanel();
            this.tvwNode = new System.Windows.Forms.TreeView();
            this.toolStripButton1 = new System.Windows.Forms.ToolStripButton();
            this.toolStripButton2 = new System.Windows.Forms.ToolStripButton();
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
            this.toolStripButton1,
            this.toolStripButton2});
            this.toolStrip1.Location = new System.Drawing.Point(0, 0);
            this.toolStrip1.Name = "toolStrip1";
            this.toolStrip1.Size = new System.Drawing.Size(800, 27);
            this.toolStrip1.TabIndex = 0;
            this.toolStrip1.Text = "toolStrip1";
            // 
            // btnSetModel
            // 
            this.btnSetModel.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.btnSetModel.Image = ((System.Drawing.Image)(resources.GetObject("btnSetModel.Image")));
            this.btnSetModel.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.btnSetModel.Name = "btnSetModel";
            this.btnSetModel.Size = new System.Drawing.Size(29, 24);
            this.btnSetModel.Text = "显示模式";
            this.btnSetModel.Click += new System.EventHandler(this.btnSetModel_Click);
            // 
            // btnBgColor
            // 
            this.btnBgColor.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.btnBgColor.Image = ((System.Drawing.Image)(resources.GetObject("btnBgColor.Image")));
            this.btnBgColor.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.btnBgColor.Name = "btnBgColor";
            this.btnBgColor.Size = new System.Drawing.Size(29, 24);
            this.btnBgColor.Text = "背景色";
            this.btnBgColor.Click += new System.EventHandler(this.btnBgColor_Click);
            // 
            // btnStep
            // 
            this.btnStep.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.btnStep.Image = ((System.Drawing.Image)(resources.GetObject("btnStep.Image")));
            this.btnStep.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.btnStep.Name = "btnStep";
            this.btnStep.Size = new System.Drawing.Size(29, 24);
            this.btnStep.Text = "STEP";
            this.btnStep.Click += new System.EventHandler(this.btnStep_Click);
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
            // toolStripButton1
            // 
            this.toolStripButton1.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.toolStripButton1.Image = ((System.Drawing.Image)(resources.GetObject("toolStripButton1.Image")));
            this.toolStripButton1.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripButton1.Name = "toolStripButton1";
            this.toolStripButton1.Size = new System.Drawing.Size(29, 24);
            this.toolStripButton1.Text = "toolStripButton1";
            this.toolStripButton1.ToolTipText = "Disk";
            this.toolStripButton1.Click += new System.EventHandler(this.toolStripButton1_Click);
            // 
            // toolStripButton2
            // 
            this.toolStripButton2.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.toolStripButton2.Image = ((System.Drawing.Image)(resources.GetObject("toolStripButton2.Image")));
            this.toolStripButton2.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripButton2.Name = "toolStripButton2";
            this.toolStripButton2.Size = new System.Drawing.Size(29, 24);
            this.toolStripButton2.Text = "toolStripButton2";
            this.toolStripButton2.ToolTipText = "Clear";
            this.toolStripButton2.Click += new System.EventHandler(this.toolStripButton2_Click);
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.tableLayoutPanel1);
            this.Controls.Add(this.toolStrip1);
            this.Name = "MainForm";
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
        private System.Windows.Forms.ToolStripButton toolStripButton1;
        private System.Windows.Forms.ToolStripButton toolStripButton2;
    }
}

