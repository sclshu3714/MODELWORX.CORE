namespace OCCTPreview
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
            this.btnStep = new System.Windows.Forms.ToolStripButton();
            this.btnBgColor = new System.Windows.Forms.ToolStripButton();
            this.RWControl = new System.Windows.Forms.Panel();
            this.btnSetModel = new System.Windows.Forms.ToolStripButton();
            this.toolStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // toolStrip1
            // 
            this.toolStrip1.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.toolStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.btnSetModel,
            this.btnBgColor,
            this.btnStep});
            this.toolStrip1.Location = new System.Drawing.Point(0, 0);
            this.toolStrip1.Name = "toolStrip1";
            this.toolStrip1.Size = new System.Drawing.Size(800, 27);
            this.toolStrip1.TabIndex = 0;
            this.toolStrip1.Text = "toolStrip1";
            // 
            // btnStep
            // 
            this.btnStep.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.btnStep.Image = ((System.Drawing.Image)(resources.GetObject("btnStep.Image")));
            this.btnStep.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.btnStep.Name = "btnStep";
            this.btnStep.Size = new System.Drawing.Size(29, 28);
            this.btnStep.Text = "STEP";
            this.btnStep.Click += new System.EventHandler(this.btnStep_Click);
            // 
            // btnBgColor
            // 
            this.btnBgColor.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.btnBgColor.Image = ((System.Drawing.Image)(resources.GetObject("btnBgColor.Image")));
            this.btnBgColor.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.btnBgColor.Name = "btnBgColor";
            this.btnBgColor.Size = new System.Drawing.Size(29, 28);
            this.btnBgColor.Text = "背景色";
            this.btnBgColor.Click += new System.EventHandler(this.btnBgColor_Click);
            // 
            // RWControl
            // 
            this.RWControl.Dock = System.Windows.Forms.DockStyle.Fill;
            this.RWControl.Location = new System.Drawing.Point(0, 27);
            this.RWControl.Name = "RWControl";
            this.RWControl.Size = new System.Drawing.Size(800, 423);
            this.RWControl.TabIndex = 1;
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
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.RWControl);
            this.Controls.Add(this.toolStrip1);
            this.Name = "MainForm";
            this.Text = "OCCT";
            this.toolStrip1.ResumeLayout(false);
            this.toolStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ToolStrip toolStrip1;
        private System.Windows.Forms.ToolStripButton btnStep;
        private System.Windows.Forms.ToolStripButton btnBgColor;
        private System.Windows.Forms.Panel RWControl;
        private System.Windows.Forms.ToolStripButton btnSetModel;
    }
}

