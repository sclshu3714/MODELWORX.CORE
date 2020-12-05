﻿using DevExpress.XtraBars;
using OCCT.WinForms.Net;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace OCCTPreview
{
    public partial class MainForm : DevExpress.XtraBars.Ribbon.RibbonForm
    {
        private RenderWindow render { get; set; } = null;
        public MainForm()
        {
            InitializeComponent();
            this.Load += MainForm_Load;
        }

        private void MainForm_Load(object sender, EventArgs e)
        {
            render = new RenderWindow(this.RWControl);
        }
    }
}