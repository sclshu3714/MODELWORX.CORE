
namespace OCCT.NET.Layout
{
    partial class OCCTViewForm
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
            this.RWControl = new System.Windows.Forms.Panel();
            this.SuspendLayout();
            // 
            // RWControl
            // 
            this.RWControl.Dock = System.Windows.Forms.DockStyle.Fill;
            this.RWControl.Location = new System.Drawing.Point(0, 0);
            this.RWControl.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.RWControl.Name = "RWControl";
            this.RWControl.Size = new System.Drawing.Size(1000, 746);
            this.RWControl.TabIndex = 2;
            // 
            // OCCTViewForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 18F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1000, 746);
            this.Controls.Add(this.RWControl);
            this.Font = new System.Drawing.Font("宋体", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.Name = "OCCTViewForm";
            this.Text = "OCCTViewForm";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Panel RWControl;
    }
}