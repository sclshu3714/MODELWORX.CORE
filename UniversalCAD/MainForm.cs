using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace UniversalCAD
{
    public partial class MainForm : Form
    {
        private OCCTProxy OCCTView { get; set; }
        private bool InitViewer { get; set; } = false;

        public MainForm()
        {
            InitializeComponent();
            //OCCTView = new OCCTProxy();
            this.ToolStripMain.Renderer = new CustomRenderer() { RoundedEdges = false };
            this.Load += MainForm_Load;
        }
        /// <summary>
        /// 选中样式
        /// </summary>
        private class CustomRenderer : ToolStripProfessionalRenderer
        {
            protected override void OnRenderButtonBackground(ToolStripItemRenderEventArgs e)
            {
                var btn = e.Item as ToolStripButton;
                if (btn != null && (btn.CheckOnClick || btn.Checked))
                {
                    Rectangle bounds = new Rectangle(Point.Empty, e.Item.Size);
                    e.Graphics.FillRectangle(Brushes.Teal, bounds);
                }
                else base.OnRenderButtonBackground(e);

                var y = e.ToolStrip.Height - 1;
                e.Graphics.DrawLine(new Pen(SystemColors.ControlDark, 1), new Point(0, y), new Point(e.ToolStrip.Width, y));
            }
        }

        /// <summary>
        /// 初始化
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void MainForm_Load(object sender, EventArgs e)
        {
            if (!Initialize())
            {
                Application.Exit();
                return;
            }
            this.ToolStripMain.ItemClicked += ToolStripMain_ItemClicked;
        }

        private bool Initialize()
        {
            //if (!(InitViewer = OCCTView.InitViewer(this.Handle)))
            //    return false;
            return true;
        }

        private void ToolStripMain_ItemClicked(object sender, ToolStripItemClickedEventArgs e)
        {
            ToolStripButton stripButton = e.ClickedItem as ToolStripButton;
            stripButton.Checked = !stripButton.Checked;
        }
    }
}
