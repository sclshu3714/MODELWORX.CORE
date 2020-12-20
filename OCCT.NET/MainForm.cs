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
using OCCT.NET.Layout;
using OCCT.WinForms.Net;
using TKBO;
using TKBRep;
using TKernel;
using TKFillet;
using TKMath;
using TKPrim;
using TKTopAlgo;
using TKV3d;
using WeifenLuo.WinFormsUI.Docking;

namespace OCCT.NET
{
    public partial class MainForm : System.Windows.Forms.Form
    {
        public WorkspaceForm WorkspaceView { get; set; }
        public OCCTViewForm OCCTView { get; set; }
        public PropertyGridForm PropertyView { get; set; }
        public MainForm() {
            InitializeComponent(); 
            this.Load += MainForm_Load;
        }

        private void MainForm_Load(object sender, EventArgs e) {
            InitializeLayout();
            RegistrationEvents();
        }
        /// <summary>
        /// 初始化布局
        /// </summary>
        private void InitializeLayout() {
            WorkspaceView = new WorkspaceForm();
            WorkspaceView.HideOnClose = true;
            WorkspaceView.Width = 200;
            WorkspaceView.DockAreas = DockAreas.DockLeft;
            WorkspaceView.Show(this.MainPanel);

            OCCTView = new OCCTViewForm();
            OCCTView.HideOnClose = true;
            OCCTView.DockAreas = WeifenLuo.WinFormsUI.Docking.DockAreas.Document;
            OCCTView.OnOperationEvent += SelectionChanged;
            OCCTView.Show(this.MainPanel);

            PropertyView = new PropertyGridForm();
            PropertyView.Width = 200;
            PropertyView.HideOnClose = true;
            PropertyView.DockAreas = DockAreas.DockRight;
            PropertyView.ShowHint = DockState.DockRightAutoHide;
            PropertyView.Show(this.MainPanel, DockState.DockRightAutoHide);

            this.wireframe.Visible = true;
            this.shading.Visible = true;
            this.color.Visible = true;
            this.material.Visible = true;
            this.transparency.Visible = true;
            this.delete.Visible = true;
            this.Cursor = System.Windows.Forms.Cursors.Default;
            this.toolBarView.Visible = true;
        }

        /// <summary>
        /// 注销事件
        /// </summary>
        private void UnregisterEvents()
        {

        }
        /// <summary>
        /// 注册事件
        /// </summary>
        private void RegistrationEvents()
        {
            this.toolBarTool.ButtonClick += toolBar_ButtonClick;
            this.toolBarView.ButtonClick += toolBarView_ButtonClick;
            foreach (MenuItem item in menuStrip.MenuItems)
            {
                item.Click += OnMenuClick;
                if (item.MenuItems.Count > 0)
                    SubMenuItems(item);
            }
            //this.btnGrid.Click += OCCTView.MakeVertex;
            //this.btnLine.Click += OCCTView.MakePrism_Line;
            //this.btnFace.Click += OCCTView.MakePrism_Face;
            //this.btnSolid.Click += OCCTView.MakePrism_Solid;
            //this.btnShell.Click += OCCTView.MakePrism_Shell;

            //this.btnClearAll.Click += OCCTView.RemoveAll;
            //this.btnDeleteSelect.Click += OCCTView.DeleteObjects;
            //this.btnAnimation.Click += OCCTView.StartAnimation;
        }

        private void SubMenuItems(MenuItem item)
        {
            foreach (MenuItem subItem in item.MenuItems)
            {
                subItem.Click += OnMenuClick;
                if (subItem.MenuItems.Count > 0)
                    SubMenuItems(subItem);
            }
        }

        public void SelectionChanged(params object[] args)
        {
            switch (OCCTView.DisplayMode())
            {
                case -1:
                    this.shading.Enabled = false;
                    this.wireframe.Enabled = false;
                    break;
                case 0:
                    this.wireframe.Enabled = false;
                    this.shading.Enabled = true;
                    this.transparency.Enabled = false;
                    break;
                case 1:
                    this.wireframe.Enabled = true;
                    this.shading.Enabled = false;
                    this.transparency.Enabled = true;
                    break;
                case 10:
                    this.wireframe.Enabled = true;
                    this.shading.Enabled = true;
                    this.transparency.Enabled = true;
                    break;
                default:
                    break;
            }
            bool IsSelected = OCCTView.IsObjectSelected;
            if (IsSelected)
            {
                this.color.Enabled = true;
                this.material.Enabled = true;
                this.delete.Enabled = true;
            }
            else
            {
                this.color.Enabled = false;
                this.material.Enabled = false;
                this.transparency.Enabled = false;
                this.delete.Enabled = false;
            }
            if (OCCTView.DegenerateMode)
            {
                this.HlrOff.Pushed = false;
                this.HlrOn.Pushed = true;
            }
            else
            {
                this.HlrOff.Pushed = true;
                this.HlrOn.Pushed = false;
            }
            if (OCCTView.Mode == CurrentAction3d.CurAction3d_WindowZooming)
                this.ZoomWin.Pushed = false;

        }

        private void toolBar_ButtonClick(object sender, System.Windows.Forms.ToolBarButtonClickEventArgs e)
        {
            switch (toolBarTool.Buttons.IndexOf(e.Button))
            {
                //case 0:
                //    this.Cursor = System.Windows.Forms.Cursors.WaitCursor;
                //    this.OnNewFile();
                //    break;
                //case 1:
                //    AboutDialog myDlg = new AboutDialog();
                //    myDlg.ShowDialog(this);
                //    break;

                case 1: //just separator
                    break;
                case 2:
                    OCCTView.SetDisplayMode(0); //wireframe
                    this.wireframe.Enabled = false;
                    this.shading.Enabled = true;
                    this.transparency.Enabled = false;
                    break;
                case 3:
                    OCCTView.SetDisplayMode(1); //shading
                    this.shading.Enabled = false;
                    this.wireframe.Enabled = true;
                    this.transparency.Enabled = true;
                    break;
                case 4:
                    OCCTView.ChangeColor(true);
                    break;
                case 5:
                    //if (curForm == null)
                    //    return;
                    //MaterialDialog m = new MaterialDialog();
                    //m.View = curForm.View;
                    //m.ShowDialog(curForm);
                    break;
                case 6:
                    int transp = 1;// (int)this.MyTransparency.Value;
                    OCCTView.SetTransparency(transp);
                    break;
                case 7:
                    OCCTView.DeleteObjects();
                    break;
                default:
                    break;
            }
        }

        private void toolBarView_ButtonClick(object sender, System.Windows.Forms.ToolBarButtonClickEventArgs e)
        {
            switch (toolBarView.Buttons.IndexOf(e.Button))
            {
                case 0:
                    OCCTView.ZoomAllView();
                    break;
                case 1:
                    OCCTView.Mode = CurrentAction3d.CurAction3d_WindowZooming;
                    this.ZoomWin.Pushed = true;
                    break;
                case 2:
                    OCCTView.Mode = CurrentAction3d.CurAction3d_DynamicZooming;
                    break;
                case 3:
                    OCCTView.Mode = CurrentAction3d.CurAction3d_DynamicPanning;
                    break;
                case 4:
                    OCCTView.Zoom = (float)OCCTView.Scale();
                    OCCTView.Mode = CurrentAction3d.CurAction3d_GlobalPanning;
                    break;
                case 5:
                    OCCTView.FrontView();
                    break;
                case 6:
                    OCCTView.BackView();
                    break;
                case 7:
                    OCCTView.TopView();
                    break;
                case 8:
                    OCCTView.BottomView();
                    break;
                case 9:
                    OCCTView.LeftView();
                    break;
                case 10:
                    OCCTView.RightView();
                    break;
                case 11:
                    OCCTView.AxoView();
                    break;
                case 12:
                    OCCTView.Mode = CurrentAction3d.CurAction3d_DynamicRotation;
                    break;
                case 13:
                    OCCTView.Reset();
                    break;
                case 14:
                    OCCTView.SetDegenerateModeOn();
                    OCCTView.DegenerateMode = true;
                    this.HlrOff.Pushed = false;
                    this.HlrOn.Pushed = true;
                    break;
                case 15:
                    OCCTView.SetDegenerateModeOff();
                    OCCTView.DegenerateMode = false;
                    this.HlrOn.Pushed = false;
                    this.HlrOff.Pushed = true;
                    break;
                default:
                    break;
            }
        }

        private void OnMenuClick(object sender, EventArgs e) {
            MenuItem tempMenu = sender as MenuItem;
            if (tempMenu == null || tempMenu.Tag == null)
                return;
            switch (tempMenu.Tag.ToString())
            {
                #region //文件
                case "Import":
                    {
                        OpenFileDialog dialog = new OpenFileDialog();
                        dialog.InitialDirectory = @"D:\DataSource\TESTSTEP";
                        dialog.Filter = "STEP文件(*.stp;*step)|*.stp;*step|BREP Files (*.brep *.rle)|*.brep; *.rle|IGES Files (*.igs *.iges)|*.igs; *.iges|所有文件(*.*)|*.*";
                        if (dialog.ShowDialog() == DialogResult.OK)
                        {
                            string filename = dialog.FileName;
                            if (filename == "")
                                return;
                            OCCTView.TranslateModel(filename);
                        }
                    }
                    break;
                case "Save":
                    {
                        SaveFileDialog dialog = new SaveFileDialog();
                        dialog.InitialDirectory = @"D:\DataSource\TESTSTEP";
                        dialog.Filter = "STEP文件(*.stp;*step)|*.stp;*step|BREP Files (*.brep *.rle)|*.brep; *.rle|IGES Files (*.igs *.iges)|*.igs; *.iges|所有文件(*.*)|*.*";
                        if (dialog.ShowDialog() == DialogResult.OK)
                        {
                            string filename = dialog.FileName;
                            if (filename == "")
                                return;
                            OCCTView.ExportModel(filename);
                        }
                    }
                    break;
                #endregion
                #region//视图
                case "Front":
                    OCCTView.FrontView();
                    break;
                case "Back":
                    OCCTView.BackView();
                    break;
                case "Top":
                    OCCTView.TopView();
                    break;
                case "Bottom":
                    OCCTView.BottomView();
                    break;
                case "Left":
                    OCCTView.LeftView();
                    break;
                case "Right":
                    OCCTView.RightView();
                    break;
                case "Axo":
                    OCCTView.AxoView();
                    break;
                #endregion
                #region//几何 - PrimAPIMake
                case "PMakeBox":
                    OCCTView.MakeBox();
                    break;
                case "PMakeCone":
                    OCCTView.PMakeCone();
                    break;
                case "PMakeCylinder":
                    OCCTView.PMakeCylinder();
                    break;
                case "PMakeHalfSpace":
                    OCCTView.PMakeHalfSpace();
                    break;
                case "PMakePrism":
                    OCCTView.PMakePrism();
                    break;
                case "PMakeRevol":
                    OCCTView.PMakeRevol();
                    break;
                case "PMakeRevolution":
                    OCCTView.PMakeRevolution();
                    break;
                case "PMakeSphere":
                    OCCTView.PMakeSphere();
                    break;
                case "PMakeTorus":
                    OCCTView.PMakeTorus();
                    break;
                case "PMakeWedge":
                    OCCTView.PMakeWedge();
                    break;
                #endregion
                #region //几何 - BuilderAPIMake
                case "BMakeEdge":
                    OCCTView.BMakeEdge();
                    break;
                case "BMakeFace":
                    OCCTView.BMakeFace();
                    break;
                case "BMakeShell":
                    OCCTView.BMakeShell();
                    break;
                case "BMakeSolid":
                    OCCTView.BMakeSolid();
                    break;
                case "BMakeVertex":
                    OCCTView.BMakeVertex();
                    break;
                case "BMakeWire":
                    OCCTView.BMakeWire();
                    break;
                #endregion
                #region//几何 - GCMake
                case "MakeArcOfCircle":
                    OCCTView.MakeArcOfCircle();
                    break;
                case "MakeArcOfEllipse":
                    OCCTView.MakeArcOfEllipse();
                    break;
                case "MakeArcOfHyperbola":
                    OCCTView.MakeArcOfHyperbola();
                    break;
                case "MakeArcOfParabola":
                    OCCTView.MakeArcOfParabola();
                    break;
                case "MakeCircle":
                    OCCTView.MakeCircle();
                    break;
                case "MakeConicalSurface":
                    OCCTView.MakeConicalSurface();
                    break;
                case "MakeCylindricalSurface":
                    OCCTView.MakeCylindricalSurface();
                    break;
                case "MakeEllipse":
                    OCCTView.MakeEllipse();
                    break;
                case "MakeHyperbola":
                    OCCTView.MakeHyperbola();
                    break;
                case "MakeLine":
                    OCCTView.MakeLine();
                    break;
                case "MakePlane":
                    OCCTView.MakePlane();
                    break;
                case "MakeRotation":
                    OCCTView.MakeRotation();
                    break;
                case "MakeScale":
                    OCCTView.MakeScale();
                    break;
                case "MakeSegment":
                    OCCTView.MakeSegment();
                    break;
                case "Transformation":
                    OCCTView.Transformation();
                    break;
                case "MakeTrimmedCone":
                    OCCTView.MakeTrimmedCone();
                    break;
                case "MakeTrimmedCylinder":
                    OCCTView.MakeTrimmedCylinder();
                    break;
                #endregion
                #region//几何 - gceMake
                case "EMakeCirc":
                    OCCTView.EMakeCirc();
                    break;
                case "EMakeCirc2d":
                    OCCTView.EMakeCirc2d();
                    break;
                case "EMakeCone":
                    OCCTView.EMakeCone();
                    break;
                case "EMakeCylinder":
                    OCCTView.EMakeCylinder();
                    break;
                case "EMakeDir":
                    OCCTView.EMakeDir();
                    break;
                case "EMakeDir2d":
                    OCCTView.EMakeDir2d();
                    break;
                case "EMakeElips":
                    OCCTView.EMakeElips();
                    break;
                case "EMakeElips2d":
                    OCCTView.EMakeElips2d();
                    break;
                case "EMakeHypr":
                    OCCTView.EMakeHypr();
                    break;
                case "EMakeHypr2d":
                    OCCTView.EMakeHypr2d();
                    break;
                case "EMakeLin":
                    OCCTView.EMakeLin();
                    break;
                case "EMakeLin2d":
                    OCCTView.EMakeLin2d();
                    break;
                case "EMakeMirror":
                    OCCTView.EMakeMirror();
                    break;
                case "EMakeMirror2d":
                    OCCTView.EMakeMirror2d();
                    break;
                case "EMakeParab":
                    OCCTView.EMakeParab();
                    break;
                case "EMakeParab2d":
                    OCCTView.EMakeParab2d();
                    break;
                case "EMakePln":
                    OCCTView.EMakePln();
                    break;
                case "EMakeRotation":
                    OCCTView.EMakeRotation();
                    break;
                case "EMakeRotation2d":
                    OCCTView.EMakeRotation2d();
                    break;
                case "EMakeScale":
                    OCCTView.EMakeScale();
                    break;
                case "EMakeScale2d":
                    OCCTView.EMakeScale2d();
                    break;
                case "EMakeTranslation":
                    OCCTView.EMakeTranslation();
                    break;
                case "EMakeTranslation2d":
                    OCCTView.EMakeTranslation2d();
                    break;
                #endregion
                #region//编辑 - 
                case "DelectSelected":
                    OCCTView.DeleteObjects();
                    break;
                case "DelectAll":
                    OCCTView.RemoveAll();
                    break;
                case "SetObjectColor":
                    OCCTView.ChangeColor(true);
                    break;
                case "Graphic3d_NOM_BRASS":
                case "Graphic3d_NOM_BRONZE":
                case "Graphic3d_NOM_COPPER":
                case "Graphic3d_NOM_GOLD":
                case "Graphic3d_NOM_PEWTER":
                case "Graphic3d_NOM_PLASTER":
                case "Graphic3d_NOM_PLASTIC":
                case "Graphic3d_NOM_SILVER":
                case "Graphic3d_NOM_STEEL":
                case "Graphic3d_NOM_STONE":
                case "Graphic3d_NOM_SHINY_PLASTIC":
                case "Graphic3d_NOM_SATIN":
                case "Graphic3d_NOM_METALIZED":
                case "Graphic3d_NOM_NEON_GNC":
                case "Graphic3d_NOM_CHROME":
                case "Graphic3d_NOM_ALUMINIUM":
                case "Graphic3d_NOM_OBSIDIAN":
                case "Graphic3d_NOM_NEON_PHC":
                case "Graphic3d_NOM_JADE":
                case "Graphic3d_NOM_CHARCOAL":
                case "Graphic3d_NOM_WATER":
                case "Graphic3d_NOM_GLASS":
                case "Graphic3d_NOM_DIAMOND":
                case "Graphic3d_NOM_TRANSPARENT":
                case "Graphic3d_NOM_DEFAULT":
                case "Graphic3d_NOM_UserDefined":
                    OCCTView.SetMaterial((Graphic3d_NameOfMaterial)Enum.Parse(typeof(Graphic3d_NameOfMaterial), tempMenu.Tag.ToString()));
                    break;
                #endregion
                #region//分析 -
                case "StartAnimation":
                    OCCTView.StartAnimation();
                    break;
                case "EndAnimation":
                    break;
                #endregion
                #region//系统 - 
                case "SetBackgroundColor":
                    OCCTView.ChangeColor(false);
                    break;
                #endregion
                default:
                    break;
            }
        }
    }
}
