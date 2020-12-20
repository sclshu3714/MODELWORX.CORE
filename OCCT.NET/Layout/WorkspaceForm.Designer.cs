
namespace OCCT.NET.Layout
{
    partial class WorkspaceForm
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
            this.trvTask = new System.Windows.Forms.TreeView();
            this.SuspendLayout();
            // 
            // trvTask
            // 
            this.trvTask.Dock = System.Windows.Forms.DockStyle.Fill;
            this.trvTask.Location = new System.Drawing.Point(0, 0);
            this.trvTask.Name = "trvTask";
            this.trvTask.Size = new System.Drawing.Size(428, 771);
            this.trvTask.TabIndex = 0;
            // 
            // WorkspaceForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 18F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(428, 771);
            this.Controls.Add(this.trvTask);
            this.Font = new System.Drawing.Font("宋体", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.Name = "WorkspaceForm";
            this.Text = "WorkspaceForm";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.TreeView trvTask;
    }
}