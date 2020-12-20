using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using WeifenLuo.WinFormsUI.Docking;

namespace OCCT.NET.Layout
{
    public partial class WorkspaceForm : DockContent
    {
        public WorkspaceForm()
        {
            InitializeComponent();
            this.Text = "工作区";
            this.Load += WorkspaceForm_Load;
        }

        private void WorkspaceForm_Load(object sender, EventArgs e)
        {
            
        }
    }
}
