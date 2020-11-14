using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using OCCT.Foundation.Net;
using OCCT.WinForms.Net;

namespace OCCTPreview
{
    public partial class MainForm : Form
    {
        private RenderWindow render { get; set; } = null;
        public MainForm() {
            InitializeComponent();
            this.Load += Form1_Load;
        }

        private void Form1_Load(object sender, EventArgs e) {
            render = new RenderWindow(this.RWControl);
            
        }

        private void btnBgColor_Click(object sender, EventArgs e) {
            render.ChangeColor(false);
        }

        private void btnStep_Click(object sender, EventArgs e) {
            OpenFileDialog dialog = new OpenFileDialog();
            dialog.InitialDirectory = @"D:\DataSource\TESTSTEP";
            dialog.Filter = "STEP文件(*.stp;*step)|*.stp;*step|所有文件(*.*)|*.*";
            if(dialog.ShowDialog() == DialogResult.OK)
                render.TranslateModel(dialog.FileName, CurrentModelFormat.STEP, true);
        }
        int index = 0;
        private void btnSetModel_Click(object sender, EventArgs e) {
            render.SetDisplayMode(index++);
        }
    }
}
