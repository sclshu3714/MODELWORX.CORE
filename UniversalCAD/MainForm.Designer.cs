
namespace UniversalCAD
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
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要修改
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MainForm));
            this.ToolStripMain = new System.Windows.Forms.ToolStrip();
            this.btnOpen = new System.Windows.Forms.ToolStripButton();
            this.btnSave = new System.Windows.Forms.ToolStripButton();
            this.btnTLable = new System.Windows.Forms.ToolStripButton();
            this.btnDemonstration = new System.Windows.Forms.ToolStripButton();
            this.btnOperation = new System.Windows.Forms.ToolStripButton();
            this.btnSection = new System.Windows.Forms.ToolStripButton();
            this.btnMeasure = new System.Windows.Forms.ToolStripButton();
            this.btnHelp = new System.Windows.Forms.ToolStripButton();
            this.btnSetting = new System.Windows.Forms.ToolStripButton();
            this.img32List = new System.Windows.Forms.ImageList(this.components);
            this.img16List = new System.Windows.Forms.ImageList(this.components);
            this.ToolStripMain.SuspendLayout();
            this.SuspendLayout();
            // 
            // ToolStripMain
            // 
            this.ToolStripMain.AutoSize = false;
            this.ToolStripMain.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(66)))), ((int)(((byte)(66)))), ((int)(((byte)(66)))));
            this.ToolStripMain.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.ToolStripMain.Dock = System.Windows.Forms.DockStyle.Left;
            this.ToolStripMain.GripMargin = new System.Windows.Forms.Padding(0);
            this.ToolStripMain.GripStyle = System.Windows.Forms.ToolStripGripStyle.Hidden;
            this.ToolStripMain.ImageScalingSize = new System.Drawing.Size(32, 32);
            this.ToolStripMain.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.btnOpen,
            this.btnSave,
            this.btnTLable,
            this.btnDemonstration,
            this.btnOperation,
            this.btnSection,
            this.btnMeasure,
            this.btnHelp,
            this.btnSetting});
            this.ToolStripMain.LayoutStyle = System.Windows.Forms.ToolStripLayoutStyle.VerticalStackWithOverflow;
            this.ToolStripMain.Location = new System.Drawing.Point(0, 0);
            this.ToolStripMain.Name = "ToolStripMain";
            this.ToolStripMain.Padding = new System.Windows.Forms.Padding(0);
            this.ToolStripMain.Size = new System.Drawing.Size(52, 522);
            this.ToolStripMain.TabIndex = 0;
            this.ToolStripMain.Text = "tspMain";
            // 
            // btnOpen
            // 
            this.btnOpen.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.btnOpen.Image = global::UniversalCAD.Properties.Resources.Img_245;
            this.btnOpen.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.btnOpen.Margin = new System.Windows.Forms.Padding(0);
            this.btnOpen.Name = "btnOpen";
            this.btnOpen.Padding = new System.Windows.Forms.Padding(8, 9, 8, 7);
            this.btnOpen.Size = new System.Drawing.Size(51, 52);
            this.btnOpen.Tag = "Open";
            this.btnOpen.Text = "打开文件&(Ctrl+O)";
            // 
            // btnSave
            // 
            this.btnSave.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.btnSave.Image = global::UniversalCAD.Properties.Resources.Img_216;
            this.btnSave.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.btnSave.Margin = new System.Windows.Forms.Padding(0);
            this.btnSave.Name = "btnSave";
            this.btnSave.Padding = new System.Windows.Forms.Padding(8, 8, 8, 7);
            this.btnSave.Size = new System.Drawing.Size(51, 51);
            this.btnSave.Tag = "Save";
            this.btnSave.Text = "保存文件";
            // 
            // btnTLable
            // 
            this.btnTLable.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.btnTLable.Image = global::UniversalCAD.Properties.Resources.Img_176;
            this.btnTLable.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.btnTLable.Margin = new System.Windows.Forms.Padding(0);
            this.btnTLable.Name = "btnTLable";
            this.btnTLable.Padding = new System.Windows.Forms.Padding(8, 8, 8, 7);
            this.btnTLable.Size = new System.Drawing.Size(51, 51);
            this.btnTLable.Tag = "TLable";
            this.btnTLable.Text = "模型结构";
            // 
            // btnDemonstration
            // 
            this.btnDemonstration.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.btnDemonstration.Image = global::UniversalCAD.Properties.Resources.Img_254;
            this.btnDemonstration.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.btnDemonstration.Margin = new System.Windows.Forms.Padding(0);
            this.btnDemonstration.Name = "btnDemonstration";
            this.btnDemonstration.Padding = new System.Windows.Forms.Padding(8);
            this.btnDemonstration.Size = new System.Drawing.Size(51, 52);
            this.btnDemonstration.Tag = "Demonstration";
            this.btnDemonstration.Text = "演示模式";
            // 
            // btnOperation
            // 
            this.btnOperation.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.btnOperation.Image = global::UniversalCAD.Properties.Resources.Img_178;
            this.btnOperation.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.btnOperation.Margin = new System.Windows.Forms.Padding(0);
            this.btnOperation.Name = "btnOperation";
            this.btnOperation.Padding = new System.Windows.Forms.Padding(8);
            this.btnOperation.Size = new System.Drawing.Size(51, 52);
            this.btnOperation.Tag = "Operation";
            this.btnOperation.Text = "操作设置";
            // 
            // btnSection
            // 
            this.btnSection.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.btnSection.Image = global::UniversalCAD.Properties.Resources.Img_273;
            this.btnSection.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.btnSection.Margin = new System.Windows.Forms.Padding(0);
            this.btnSection.Name = "btnSection";
            this.btnSection.Padding = new System.Windows.Forms.Padding(8);
            this.btnSection.Size = new System.Drawing.Size(51, 52);
            this.btnSection.Tag = "Section";
            this.btnSection.Text = "切面";
            // 
            // btnMeasure
            // 
            this.btnMeasure.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.btnMeasure.Image = global::UniversalCAD.Properties.Resources.Img_32;
            this.btnMeasure.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.btnMeasure.Margin = new System.Windows.Forms.Padding(0);
            this.btnMeasure.Name = "btnMeasure";
            this.btnMeasure.Padding = new System.Windows.Forms.Padding(8);
            this.btnMeasure.Size = new System.Drawing.Size(51, 52);
            this.btnMeasure.Tag = "Measure";
            this.btnMeasure.Text = "标记";
            // 
            // btnHelp
            // 
            this.btnHelp.Alignment = System.Windows.Forms.ToolStripItemAlignment.Right;
            this.btnHelp.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.btnHelp.Image = global::UniversalCAD.Properties.Resources.Img_280;
            this.btnHelp.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.btnHelp.Margin = new System.Windows.Forms.Padding(0);
            this.btnHelp.Name = "btnHelp";
            this.btnHelp.Padding = new System.Windows.Forms.Padding(8);
            this.btnHelp.Size = new System.Drawing.Size(51, 52);
            this.btnHelp.Tag = "Help";
            this.btnHelp.Text = "帮助";
            // 
            // btnSetting
            // 
            this.btnSetting.Alignment = System.Windows.Forms.ToolStripItemAlignment.Right;
            this.btnSetting.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.btnSetting.Image = global::UniversalCAD.Properties.Resources.Img_320;
            this.btnSetting.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.btnSetting.Margin = new System.Windows.Forms.Padding(0);
            this.btnSetting.Name = "btnSetting";
            this.btnSetting.Padding = new System.Windows.Forms.Padding(8);
            this.btnSetting.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.btnSetting.Size = new System.Drawing.Size(51, 52);
            this.btnSetting.Tag = "Setting";
            this.btnSetting.Text = "设置";
            // 
            // img32List
            // 
            this.img32List.ColorDepth = System.Windows.Forms.ColorDepth.Depth8Bit;
            this.img32List.ImageSize = new System.Drawing.Size(32, 32);
            this.img32List.TransparentColor = System.Drawing.Color.Transparent;
            // 
            // img16List
            // 
            this.img16List.ColorDepth = System.Windows.Forms.ColorDepth.Depth32Bit;
            this.img16List.ImageSize = new System.Drawing.Size(16, 16);
            this.img16List.TransparentColor = System.Drawing.Color.Transparent;
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(66)))), ((int)(((byte)(66)))), ((int)(((byte)(66)))));
            this.ClientSize = new System.Drawing.Size(886, 522);
            this.Controls.Add(this.ToolStripMain);
            this.DoubleBuffered = true;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.Name = "MainForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "CAD";
            this.ToolStripMain.ResumeLayout(false);
            this.ToolStripMain.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.ToolStrip ToolStripMain;
        private System.Windows.Forms.ToolStripButton btnOpen;
        private System.Windows.Forms.ToolStripButton btnSave;
        private System.Windows.Forms.ToolStripButton btnTLable;
        private System.Windows.Forms.ToolStripButton btnDemonstration;
        private System.Windows.Forms.ToolStripButton btnOperation;
        private System.Windows.Forms.ToolStripButton btnSection;
        private System.Windows.Forms.ToolStripButton btnMeasure;
        private System.Windows.Forms.ToolStripButton btnHelp;
        private System.Windows.Forms.ToolStripButton btnSetting;
        private System.Windows.Forms.ImageList img32List;
        private System.Windows.Forms.ImageList img16List;
    }
}

