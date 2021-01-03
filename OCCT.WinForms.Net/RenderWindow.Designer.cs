namespace OCCT.WinForms.Net
{
    partial class RenderWindow
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

        #region 组件设计器生成的代码

        /// <summary> 
        /// 设计器支持所需的方法 - 不要修改
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent() {
            this.RWControl = new System.Windows.Forms.Panel();
            this.SuspendLayout();
            // 
            // RWControl
            // 
            this.RWControl.Dock = System.Windows.Forms.DockStyle.Fill;
            this.RWControl.Location = new System.Drawing.Point(0, 0);
            this.RWControl.Name = "RWControl";
            this.RWControl.Size = new System.Drawing.Size(518, 402);
            this.RWControl.TabIndex = 0;
            // 
            // RenderWindow
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.RWControl);
            this.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.Name = "RenderWindow";
            this.Size = new System.Drawing.Size(518, 402);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Panel RWControl;
    }
}
