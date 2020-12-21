using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using WeifenLuo.WinFormsUI.Docking;
using OCCT.Foundation.Net;
using OCCT.WinForms.Net;
using TKBO;
using TKBRep;
using TKernel;
using TKFillet;
using TKMath;
using TKPrim;
using TKTopAlgo;
using TKV3d;
using System.IO;
using TKG3d;
using TKGeomBase;
using static OCCT.Foundation.Net.OperationEvents;

namespace OCCT.NET.Layout
{
    public partial class OCCTViewForm : DockContent
    {
        private static readonly object lockObject = new object();
        private RenderWindow IRender { get; set; } = null;

        private int ModeIndex = 1;

        private OperationEvent operationEvent;
        /// <summary>
        /// 委托操作
        /// </summary>
        public event OperationEvent OnOperationEvent
        {
            add { operationEvent += value; }
            remove { operationEvent -= value; }
        }

        public OCCTViewForm()
        {
            InitializeComponent();
            this.Text = "显示区";
            this.Load += OCCTViewForm_Load;
        }

        private void OCCTViewForm_Load(object sender, EventArgs e)
        {
            IRender = new RenderWindow(this.RWControl);
            IRender.SetDisplayMode(ModeIndex);
            IRender.MouseUp += IRender_MouseUp;
        }

        private void IRender_MouseUp(object sender, MouseEventArgs e)
        {
            if (operationEvent != null) operationEvent();
        }

        #region 导出文件

        public void TranslateModel(string file)
        {
            CurrentModelFormat theFormat = CurrentModelFormat.STEP;
            switch (Path.GetExtension(file)?.ToLower())
            {
                case ".rle":
                case ".brep":
                    theFormat = CurrentModelFormat.BREP;
                    break;
                case ".stp":
                case ".step":
                    theFormat = CurrentModelFormat.STEP;
                    break;
                case ".igs":
                case ".iges":
                    theFormat = CurrentModelFormat.IGES;
                    break;
                case ".vrml":
                    theFormat = CurrentModelFormat.VRML;
                    break;
                case ".stl":
                    theFormat = CurrentModelFormat.STL;
                    break;
                case ".jpg":
                case ".png":
                    theFormat = CurrentModelFormat.IMAGE;
                    break;
                default:
                    return;
            }
            IRender.TranslateModel(file, theFormat, true);
            //OpenFileDialog dialog = new OpenFileDialog();
            //dialog.InitialDirectory = @"D:\DataSource\TESTSTEP";
            //dialog.Filter = "STEP文件(*.stp;*step)|*.stp;*step|所有文件(*.*)|*.*";
            //if (dialog.ShowDialog() == DialogResult.OK)
            //    IRender.TranslateModel(ref this.tvwNode, dialog.FileName, CurrentModelFormat.STEP, true);
            //this.tvwNode.ExpandAll();
        }
        public void SetDisplayMode(int ModeIndex)
        {
            this.ModeIndex = ModeIndex;
            IRender.SetDisplayMode(ModeIndex);
        }

        public void MakeDisk(object sender, EventArgs e)
        {
            IRender.AddDisk();
            IRender.ZoomAllView();
        }

        public void ExportModel(string file)
        {
            CurrentModelFormat theFormat = CurrentModelFormat.STEP;
            switch (Path.GetExtension(file)?.ToLower())
            {
                case ".rle":
                case ".brep":
                    theFormat = CurrentModelFormat.BREP;
                    break;
                case ".stp":
                case ".step":
                    theFormat = CurrentModelFormat.STEP;
                    break;
                case ".igs":
                case ".iges":
                    theFormat = CurrentModelFormat.IGES;
                    break;
                case ".vrml":
                    theFormat = CurrentModelFormat.VRML;
                    break;
                case ".stl":
                    theFormat = CurrentModelFormat.STL;
                    break;
                case ".jpg":
                case ".png":
                    theFormat = CurrentModelFormat.IMAGE;
                    break;
                default:
                    return;
            }
            if (!IRender.TranslateModel(file, theFormat, false))
                MessageBox.Show("Cann't write this file", "Error!", MessageBoxButtons.OK, MessageBoxIcon.Warning);
        }

        public void ExportModel(CurrentModelFormat theformat)
        {
            System.Windows.Forms.SaveFileDialog saveDialog = new SaveFileDialog();
            string DataDir = Environment.GetEnvironmentVariable("CSF_OCCTDataPath");
            string filter = "";
            switch (theformat)
            {
                case CurrentModelFormat.BREP:
                    saveDialog.InitialDirectory = (DataDir + "\\occ");
                    filter = "BREP Files (*.brep *.rle)|*.brep; *.rle";
                    break;
                case CurrentModelFormat.STEP:
                    saveDialog.InitialDirectory = (DataDir + "\\step");
                    filter = "STEP Files (*.stp *.step)|*.step; *.stp";
                    break;
                case CurrentModelFormat.IGES:
                    saveDialog.InitialDirectory = (DataDir + "\\iges");
                    filter = "IGES Files (*.igs *.iges)| *.iges; *.igs";
                    break;
                case CurrentModelFormat.VRML:
                    saveDialog.InitialDirectory = (DataDir + "\\vrml");
                    filter = "VRML Files (*.vrml)|*.vrml";
                    break;
                case CurrentModelFormat.STL:
                    saveDialog.InitialDirectory = (DataDir + "\\stl");
                    filter = "STL Files (*.stl)|*.stl";
                    break;
                case CurrentModelFormat.IMAGE:
                    saveDialog.InitialDirectory = (DataDir + "\\images");
                    filter = "Images Files (*.bmp *.gif)| *.bmp; *.gif";
                    break;
                default:
                    break;
            }
            saveDialog.Filter = filter;
            if (saveDialog.ShowDialog() == DialogResult.OK)
            {
                string filename = saveDialog.FileName;
                if (filename == "")
                    return;
                this.Cursor = System.Windows.Forms.Cursors.WaitCursor;
                if (!IRender.TranslateModel(filename, theformat, false))
                    MessageBox.Show("Cann't write this file", "Error!",
                            MessageBoxButtons.OK, MessageBoxIcon.Warning);
                this.Cursor = System.Windows.Forms.Cursors.Default;
            }
        }

        #endregion

        #region 动画
        /// <summary>
        /// 动画
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        public void StartAnimation()
        {
            XBRepPrimAPI_MakeBox obj1 = new XBRepPrimAPI_MakeBox(100, 100, 20);
            XAIS_Shape ais_obj1 = new XAIS_Shape(obj1.Shape());
            SetFaceBoundaryAspect(ais_obj1, true);
            IRender.AddShape(ais_obj1, true);

            xgp_Trsf end_pnt0 = new xgp_Trsf();
            xgp_Trsf end_pnt1 = new xgp_Trsf();
            end_pnt0.SetTranslation(new xgp_Vec(0.0, 0.0, 0.0));
            end_pnt1.SetTranslation(new xgp_Vec(100.0, 100.0, 0.0));
            XAIS_AnimationObject ais_animation = new XAIS_AnimationObject(new XTCollection_AsciiString($"F1{Guid.NewGuid().ToString()}"), IRender.GetInteractiveContext(), ais_obj1, end_pnt0, end_pnt1);
            ais_animation.SetOwnDuration(30.0);
            ais_animation.SetStartPts(0);
            ais_animation.StartTimer(0.0, 1.0, true, false);
            ais_animation.Start(true);
            Timer timer = new Timer();
            timer.Interval = 100;
            timer.Tag = ais_animation;
            timer.Tick += Timer_Tick;
            timer.Start();
            //var task = new Task(() => {
            //    while (!ais_animation.IsStopped()) {
            //        lock (lockObject)
            //        {
            //            ais_animation.UpdateTimer();
            //            render.UpdateCurrentViewer();
            //        }
            //    }; ais_animation.Stop(); });
            //task.Start();
        }

        private void Timer_Tick(object sender, EventArgs e)
        {
            Timer timer = sender as Timer;
            XAIS_AnimationObject ais_animation = timer.Tag as XAIS_AnimationObject;
            if (ais_animation != null && !ais_animation.IsStopped())
            {
                lock (lockObject)
                {
                    ais_animation.UpdateTimer();
                    IRender.UpdateCurrentViewer();
                }
            };
        }
        #endregion

        #region 几何图形
        /// <summary>
        /// 绘制壳图像
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        public void MakePrism_Shell(object sender, EventArgs e)
        {
            xgp_Circ CR = new xgp_Circ(new xgp_Ax2(new xgp_Pnt(200.0, 200.0, 0.0), new xgp_Dir(0.0, 0.0, 1.0)), 80.0);
            XTopoDS_Edge REc = new XBRepBuilderAPI_MakeEdge(CR).Edge();
            XTopoDS_Wire RWc = new XBRepBuilderAPI_MakeWire(REc).Wire();
            XBRepBuilderAPI_MakeFace aRMakeFace = new XBRepBuilderAPI_MakeFace(RWc, false);
            //XBRepBuilderAPI_MakeShell tempA = new XBRepBuilderAPI_MakeShell();
            XAIS_Shape WAIS_ECD = new XAIS_Shape(aRMakeFace.Shape());
            SetFaceBoundaryAspect(WAIS_ECD, true);

            IRender.AddShape(WAIS_ECD, true);
        }


        /// <summary>
        /// 绘制体图像
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        public void MakePrism_Solid(object sender, EventArgs e)
        {
            xgp_Pnt P = new xgp_Pnt(0.0, 0.0, 0.0);
            XBRepBuilderAPI_MakeVertex MV1 = new XBRepBuilderAPI_MakeVertex(P);
            XBRepPrimAPI_MakePrism S1 = new XBRepPrimAPI_MakePrism(MV1.Shape(), new xgp_Vec(100.0, 0.0, 0.0), false, true);
            XBRepPrimAPI_MakePrism S2 = new XBRepPrimAPI_MakePrism(S1.Shape(), new xgp_Vec(0.0, 100.0, 0.0), false, true);
            XBRepPrimAPI_MakePrism S3 = new XBRepPrimAPI_MakePrism(S2.Shape(), new xgp_Vec(0.0, 0.0, 100.0), false, true);
            //倒圆
            XBRepFilletAPI_MakeFillet MFBox = new XBRepFilletAPI_MakeFillet(S3.Shape(), XChFi3d_FilletShape.ChFi3d_Rational);
            XTopExp_Explorer exp = new XTopExp_Explorer(S3.Shape(), XTopAbs_ShapeEnum.TopAbs_EDGE, XTopAbs_ShapeEnum.TopAbs_SHAPE);
            while (exp.More())
            {
                MFBox.Add(5, XTopoDS.Edge(exp.Current()));
                exp.Next();
            }
            XAIS_Shape WAIS_EC = new XAIS_Shape(MFBox.Shape());
            SetFaceBoundaryAspect(WAIS_EC, true);
            IRender.AddShape(WAIS_EC, true);

            //XBRepPrimAPI_MakeBox tempA = new XBRepPrimAPI_MakeBox(200.0, 150.0, 100.0);
            //XBRepPrimAPI_MakeBox tempB = new XBRepPrimAPI_MakeBox(new xgp_Pnt(60, 60, 0), 200.0, 150.0, 100.0);
            //XBRepPrimAPI_MakeBox tempC = new XBRepPrimAPI_MakeBox(new xgp_Pnt(60, 60, 0), new xgp_Pnt(200.0, 150.0, 100.0));
            //XBRepPrimAPI_MakeBox tempD = new XBRepPrimAPI_MakeBox(new xgp_Ax2(new xgp_Pnt(100.0, 80.0, 70.0), new xgp_Dir(1.0, 2.0, 1.0)), 80.0, 90.0, 120.0);

            //XAIS_Shape WAIS_ECA = new XAIS_Shape(tempA.Shape());
            //SetFaceBoundaryAspect(WAIS_ECA, true);

            //XAIS_Shape WAIS_ECB = new XAIS_Shape(tempB.Shape());
            //SetFaceBoundaryAspect(WAIS_ECB, true);

            //XAIS_Shape WAIS_ECC = new XAIS_Shape(tempC.Shape());
            //SetFaceBoundaryAspect(WAIS_ECC, true);

            //XAIS_Shape WAIS_ECD = new XAIS_Shape(tempD.Shape());
            //SetFaceBoundaryAspect(WAIS_ECD, true);

            //render.AddShape(WAIS_ECA, true);
            //render.AddShape(WAIS_ECB, true);
            //render.AddShape(WAIS_ECC, true);
            //render.AddShape(WAIS_ECD, true);
        }

        /// <summary>
        /// 绘制面图像
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        public void MakePrism_Face(object sender, EventArgs e)
        {
            xgp_Pnt P = new xgp_Pnt(0.0, 0.0, 0.0);
            XBRepBuilderAPI_MakeVertex MV1 = new XBRepBuilderAPI_MakeVertex(P);
            XBRepPrimAPI_MakePrism S1 = new XBRepPrimAPI_MakePrism(MV1.Shape(), new xgp_Vec(100.0, 0.0, 0.0), false, true);
            XBRepPrimAPI_MakePrism S2 = new XBRepPrimAPI_MakePrism(S1.Shape(), new xgp_Vec(0.0, 100.0, 0.0), false, true);
            XAIS_Shape WAIS_EC = new XAIS_Shape(S2.Shape());
            SetFaceBoundaryAspect(WAIS_EC, true);
            IRender.AddShape(WAIS_EC, true);

            //xgp_Circ CR = new xgp_Circ(new xgp_Ax2(new xgp_Pnt(200.0, 200.0, 0.0), new xgp_Dir(0.0, 0.0, 1.0)), 80.0);
            //XTopoDS_Edge REc = new XBRepBuilderAPI_MakeEdge(CR).Edge();
            //XTopoDS_Wire RWc = new XBRepBuilderAPI_MakeWire(REc).Wire();
            //XBRepBuilderAPI_MakeFace aRMakeFace = new XBRepBuilderAPI_MakeFace(RWc, false);

            //xgp_Circ Cr = new xgp_Circ(new xgp_Ax2(new xgp_Pnt(200.0, 200.0, 0.0), new xgp_Dir(0.0, 0.0, 1.0)), 60.0);
            //XTopoDS_Edge rEc = new XBRepBuilderAPI_MakeEdge(Cr).Edge();
            //XTopoDS_Wire rWc = new XBRepBuilderAPI_MakeWire(rEc).Wire();
            //XBRepBuilderAPI_MakeFace arMakeFace = new XBRepBuilderAPI_MakeFace(rWc, false);

            //XBRepAlgoAPI_Cut PipeProfile = new XBRepAlgoAPI_Cut(aRMakeFace.Shape(), arMakeFace.Shape());

            //xgp_Vec sVec = new xgp_Vec(0, 0, 1 * 200);
            //XBRepPrimAPI_MakePrism BRPA_MP = new XBRepPrimAPI_MakePrism(PipeProfile.Shape(), sVec, false, false);
            //XAIS_Shape WAIS_EC = new XAIS_Shape(BRPA_MP.Shape());
            //SetFaceBoundaryAspect(WAIS_EC, true);
            //render.AddShape(WAIS_EC, true);
        }



        /// <summary>
        /// 绘制线视图
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        public void MakePrism_Line(object sender, EventArgs e)
        {
            xgp_Pnt P = new xgp_Pnt(0.0, 0.0, 0.0);
            XBRepBuilderAPI_MakeVertex MV1 = new XBRepBuilderAPI_MakeVertex(P);
            XBRepPrimAPI_MakePrism S1 = new XBRepPrimAPI_MakePrism(MV1.Shape(), new xgp_Vec(100.0, 0.0, 0.0), false, true);
            IRender.AddShape(S1.Shape(), true);
        }

        /// <summary>
        /// 绘制点图像
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        public void MakeVertex(object sender, EventArgs e)
        {
            xgp_Pnt P = new xgp_Pnt(0.0, 0.0, 0.0);
            XBRepBuilderAPI_MakeVertex MV1 = new XBRepBuilderAPI_MakeVertex(P);
            XTopoDS_Vertex V1 = MV1.Vertex();
            IRender.AddShape(V1, true);
        }
        #endregion

        #region 演示图形
        /// <summary>
        /// MakeBox
        /// </summary>
        internal void MakeBox()
        {
            xgp_Pnt P = new xgp_Pnt(0, 0, 0);
            xgp_Dir V = new xgp_Dir(1, 0, 0);
            xgp_Ax2 Axes = new xgp_Ax2(P, V);
            XBRepPrimAPI_MakeBox tempMake = new XBRepPrimAPI_MakeBox(Axes, 80, 80, 80);
            IRender.AddShape(tempMake.Shape(), true, true);
        }
        /// <summary>
        /// MakeCone
        /// </summary>
        internal void PMakeCone()
        {
            xgp_Pnt P = new xgp_Pnt(200, 0, 0);
            xgp_Dir V = new xgp_Dir(1, 0, 0);
            xgp_Ax2 Axes = new xgp_Ax2(P, V);
            XBRepPrimAPI_MakeCone tempMake = new XBRepPrimAPI_MakeCone(Axes, 80, 40, 100);
            IRender.AddShape(tempMake.Shape(), true, true);
        }
        /// <summary>
        /// MakeCylinder
        /// </summary>
        internal void PMakeCylinder()
        {
            xgp_Pnt P = new xgp_Pnt(300, 0, 0);
            xgp_Dir V = new xgp_Dir(1, 0, 0);
            xgp_Ax2 Axes = new xgp_Ax2(P, V);
            XBRepPrimAPI_MakeCylinder tempMake = new XBRepPrimAPI_MakeCylinder(Axes, 80, 100, 90);
            IRender.AddShape(tempMake.Shape(), true, true);
        }

        /// <summary>
        /// MakeHalfSpace
        /// </summary>
        internal void PMakeHalfSpace()
        {
            xgp_Circ CR = new xgp_Circ(new xgp_Ax2(new xgp_Pnt(400.0, 400.0, 0.0), new xgp_Dir(0.0, 0.0, 1.0)), 80.0);
            XTopoDS_Edge REc = new XBRepBuilderAPI_MakeEdge(CR).Edge();
            XTopoDS_Wire RWc = new XBRepBuilderAPI_MakeWire(REc).Wire();
            XBRepBuilderAPI_MakeFace aRMakeFace = new XBRepBuilderAPI_MakeFace(RWc, false);
            xgp_Pnt P = new xgp_Pnt(400, 400, 400);
            XBRepPrimAPI_MakeHalfSpace tempMake = new XBRepPrimAPI_MakeHalfSpace(aRMakeFace.Face(), P);
            IRender.AddShape(tempMake.Shape(), true, true);
        }

        /// <summary>
        /// MakePrism
        /// </summary>
        internal void PMakePrism()
        {
            xgp_Pnt P = new xgp_Pnt(500.0, 0.0, 0.0);
            XBRepBuilderAPI_MakeVertex MV1 = new XBRepBuilderAPI_MakeVertex(P);
            XBRepPrimAPI_MakePrism S1 = new XBRepPrimAPI_MakePrism(MV1.Shape(), new xgp_Vec(100.0, 0.0, 0.0), false, true);
            XBRepPrimAPI_MakePrism S2 = new XBRepPrimAPI_MakePrism(S1.Shape(), new xgp_Vec(0.0, 100.0, 0.0), false, true);
            XBRepPrimAPI_MakePrism tempMake = new XBRepPrimAPI_MakePrism(S2.Shape(), new xgp_Vec(0.0, 0.0, 100.0), false, true);
            IRender.AddShape(tempMake.Shape(), true, true);
        }

        /// <summary>
        /// MakeRevol
        /// </summary>
        internal void PMakeRevol()
        {
            xgp_Pnt P = new xgp_Pnt(600.0, 0.0, 0.0);
            xgp_Dir V = new xgp_Dir(1, 0, 0);
            XBRepBuilderAPI_MakeVertex MV1 = new XBRepBuilderAPI_MakeVertex(P);
            XBRepPrimAPI_MakePrism S1 = new XBRepPrimAPI_MakePrism(MV1.Shape(), new xgp_Vec(100.0, 0.0, 0.0), false, true);
            XBRepPrimAPI_MakePrism S2 = new XBRepPrimAPI_MakePrism(S1.Shape(), new xgp_Vec(0.0, 100.0, 0.0), false, true);
            XBRepPrimAPI_MakeRevol tempMake = new XBRepPrimAPI_MakeRevol(S2.Shape(), new xgp_Ax1(P, V), false);
            IRender.AddShape(tempMake.Shape(), true, true);
        }

        /// <summary>
        /// MakeRevolution
        /// </summary>
        internal void PMakeRevolution()
        {
            xgp_Pnt P = new xgp_Pnt(0, 200.0, 0.0);
            xgp_Dir V = new xgp_Dir(1, 0, 0);
            XGeom_Line line = new XGeom_Line(P, V);
            XBRepPrimAPI_MakeRevolution tempMake = new XBRepPrimAPI_MakeRevolution(line, 270);
            IRender.AddShape(tempMake.Shape(), true, true);
        }

        /// <summary>
        /// MakeSphere
        /// </summary>
        internal void PMakeSphere()
        {
            xgp_Pnt P = new xgp_Pnt(100, 200, 0);
            xgp_Dir V = new xgp_Dir(1, 0, 0);
            xgp_Ax2 Axes = new xgp_Ax2(P, V);
            XBRepPrimAPI_MakeSphere tempMake = new XBRepPrimAPI_MakeSphere(Axes,80);
            IRender.AddShape(tempMake.Shape(), true, true);
        }

        /// <summary>
        /// MakeTorus
        /// </summary>
        internal void PMakeTorus()
        {
            xgp_Pnt P = new xgp_Pnt(200, 200, 0);
            xgp_Dir V = new xgp_Dir(1, 0, 0);
            xgp_Ax2 Axes = new xgp_Ax2(P, V);
            XBRepPrimAPI_MakeTorus tempMake = new XBRepPrimAPI_MakeTorus(Axes, 80, 40);
            IRender.AddShape(tempMake.Shape(), true, true);
        }

        /// <summary>
        /// MakeWedge
        /// </summary>
        internal void PMakeWedge()
        {
            xgp_Pnt P = new xgp_Pnt(300, 200, 0);
            xgp_Dir V = new xgp_Dir(1, 0, 0);
            xgp_Ax2 Axes = new xgp_Ax2(P, V);
            XBRepPrimAPI_MakeWedge tempMake = new XBRepPrimAPI_MakeWedge(Axes, 40, 40, 40, 10);
            IRender.AddShape(tempMake.Shape(), true, true);
        }

        /// <summary>
        /// MakeEdge
        /// </summary>
        internal void BMakeEdge()
        {
            xgp_Pnt P = new xgp_Pnt(400, 200, 0);
            xgp_Dir V = new xgp_Dir(1, 0, 0);
            xgp_Ax2 Axes = new xgp_Ax2(P, V);
            xgp_Circ circ = new xgp_Circ(Axes, 80);
            XBRepBuilderAPI_MakeEdge tempMake = new XBRepBuilderAPI_MakeEdge(circ);
            IRender.AddShape(tempMake.Shape(), true, true);
        }

        /// <summary>
        /// MakeFace
        /// </summary>
        internal void BMakeFace()
        {
            xgp_Pnt P = new xgp_Pnt(500, 200, 0);
            xgp_Dir V = new xgp_Dir(1, 0, 0);
            xgp_Ax3 Axes = new xgp_Ax3(P, V);
            xgp_Cylinder C = new xgp_Cylinder(Axes, 80);
            XBRepBuilderAPI_MakeFace tempMake = new XBRepBuilderAPI_MakeFace(C);
            IRender.AddShape(tempMake.Shape(), true, true);
        }

        /// <summary>
        /// MakeShell
        /// </summary>
        internal void BMakeShell()
        {
            xgp_Pnt P = new xgp_Pnt(600, 200, 0);
            xgp_Dir V = new xgp_Dir(1, 0, 0);
            xgp_Ax3 Axes = new xgp_Ax3(P, V);
            XGeom_CylindricalSurface cylindricalSurface = new XGeom_CylindricalSurface(Axes, 80);
            XBRepBuilderAPI_MakeShell tempMake = new XBRepBuilderAPI_MakeShell(cylindricalSurface, false);
            IRender.AddShape(tempMake.Shape(), true, true);
        }

        /// <summary>
        /// MakeSolid
        /// </summary>
        internal void BMakeSolid()
        {
            xgp_Pnt P = new xgp_Pnt(600, 200, 0);
            xgp_Dir V = new xgp_Dir(1, 0, 0);
            xgp_Ax3 Axes = new xgp_Ax3(P, V);
            XGeom_CylindricalSurface cylindricalSurface = new XGeom_CylindricalSurface(Axes, 80);
            XBRepBuilderAPI_MakeShell tempMakeShell = new XBRepBuilderAPI_MakeShell(cylindricalSurface, false);
            XBRepBuilderAPI_MakeSolid tempMake = new XBRepBuilderAPI_MakeSolid(tempMakeShell.Shell());
            IRender.AddShape(tempMake.Shape(), true, true);
        }

        /// <summary>
        /// MakeVertex
        /// </summary>
        internal void BMakeVertex()
        {
            xgp_Pnt P = new xgp_Pnt(0, 300, 0);
            XBRepBuilderAPI_MakeVertex tempMake = new XBRepBuilderAPI_MakeVertex(P);
            IRender.AddShape(tempMake.Shape(), true, true);
        }

        /// <summary>
        /// MakeWire
        /// </summary>
        internal void BMakeWire()
        {
            xgp_Pnt P = new xgp_Pnt(100, 300, 0);
            xgp_Dir V = new xgp_Dir(1, 0, 0);
            xgp_Ax2 Axes = new xgp_Ax2(P, V);
            xgp_Circ circ = new xgp_Circ(Axes, 80);
            XBRepBuilderAPI_MakeEdge tempEdge = new XBRepBuilderAPI_MakeEdge(circ);
            XBRepBuilderAPI_MakeWire tempMake = new XBRepBuilderAPI_MakeWire(tempEdge.Edge());
            IRender.AddShape(tempMake.Shape(), true, true);
        }

        /// <summary>
        /// MakeArcOfCircle
        /// </summary>
        internal void MakeArcOfCircle()
        {
            xgp_Pnt P = new xgp_Pnt(200, 300, 0);
            xgp_Dir V = new xgp_Dir(1, 0, 0);
            xgp_Ax2 Axes = new xgp_Ax2(P, V);
            xgp_Circ circ = new xgp_Circ(Axes, 80);
            XGC_MakeArcOfCircle tempMake = new XGC_MakeArcOfCircle(circ, 90, 270, false);
            XBRepBuilderAPI_MakeEdge tempEdge = new XBRepBuilderAPI_MakeEdge(tempMake.Value());
            IRender.AddShape(tempEdge.Edge(), true, true);
        }

        /// <summary>
        /// MakeArcOfEllipse
        /// </summary>
        internal void MakeArcOfEllipse()
        {
            xgp_Pnt P = new xgp_Pnt(400, 300, 0);
            xgp_Dir V = new xgp_Dir(1, 0, 0);
            xgp_Ax2 Axes = new xgp_Ax2(P, V);
            xgp_Elips elips = new xgp_Elips(Axes, 80, 40);
            xgp_Pnt P1 = new xgp_Pnt(480, 300, 0);
            xgp_Pnt P2 = new xgp_Pnt(320, 300, 0);
            XGC_MakeArcOfEllipse tempMake = new XGC_MakeArcOfEllipse(elips, P1, P2, false);
            XBRepBuilderAPI_MakeEdge tempEdge = new XBRepBuilderAPI_MakeEdge(tempMake.Value());
            IRender.AddShape(tempEdge.Edge(), true, true);
        }

        /// <summary>
        /// MakeArcOfHyperbola
        /// </summary>
        internal void MakeArcOfHyperbola()
        {
            xgp_Pnt P = new xgp_Pnt(600, 300, 0);
            xgp_Dir V = new xgp_Dir(1, 0, 0);
            xgp_Ax2 Axes = new xgp_Ax2(P, V);
            xgp_Hypr hypr = new xgp_Hypr(Axes, 80, 40);
            xgp_Pnt P2 = new xgp_Pnt(700, 300, 0);
            XGC_MakeArcOfHyperbola tempMake = new XGC_MakeArcOfHyperbola(hypr, P, P2, false);
            XBRepBuilderAPI_MakeEdge tempEdge = new XBRepBuilderAPI_MakeEdge(tempMake.Value());
            IRender.AddShape(tempEdge.Edge(), true, true);
        }

        /// <summary>
        /// MakeArcOfParabola
        /// </summary>
        internal void MakeArcOfParabola()
        {
            xgp_Pnt P = new xgp_Pnt(600, 300, 0);
            xgp_Dir V = new xgp_Dir(1, 0, 0);
            xgp_Ax1 Axes = new xgp_Ax1(P, V);
            xgp_Pnt F = new xgp_Pnt(650, 300, 0);
            xgp_Parab parab = new xgp_Parab(Axes, F);
            xgp_Pnt P2 = new xgp_Pnt(700, 300, 0);
            XGC_MakeArcOfParabola tempMake = new XGC_MakeArcOfParabola(parab, P, P2, false);
            XBRepBuilderAPI_MakeEdge tempEdge = new XBRepBuilderAPI_MakeEdge(tempMake.Value());
            IRender.AddShape(tempEdge.Edge(), true, true);
        }

        /// <summary>
        /// MakeCircle
        /// </summary>
        internal void MakeCircle()
        {
            xgp_Pnt P = new xgp_Pnt(600, 300, 0);
            xgp_Dir V = new xgp_Dir(1, 0, 0);
            xgp_Ax1 Axes = new xgp_Ax1(P, V);
            XGC_MakeCircle tempMake = new XGC_MakeCircle(Axes, 80);
            XBRepBuilderAPI_MakeEdge tempEdge = new XBRepBuilderAPI_MakeEdge(tempMake.Value());
            IRender.AddShape(tempEdge.Edge(), true, true);
        }

        /// <summary>
        /// MakeConicalSurface
        /// </summary>
        internal void MakeConicalSurface()
        {
            xgp_Pnt P1 = new xgp_Pnt(700, 300, 0);
            xgp_Pnt P2 = new xgp_Pnt(800, 300, 0);
            XGC_MakeConicalSurface tempSurface = new XGC_MakeConicalSurface(P1, P2, 80, 60);
            XBRepBuilderAPI_MakeShell tempMake = new XBRepBuilderAPI_MakeShell(tempSurface.Value(), false);
            IRender.AddShape(tempMake.Shape(), true, true);
        }

        /// <summary>
        /// MakeCylindricalSurface
        /// </summary>
        internal void MakeCylindricalSurface()
        {
            xgp_Pnt P = new xgp_Pnt(0, 400, 0);
            xgp_Dir V = new xgp_Dir(1, 0, 0);
            xgp_Ax2 Axes = new xgp_Ax2(P, V);
            xgp_Circ circ = new xgp_Circ();
            XGC_MakeCylindricalSurface tempSurface = new XGC_MakeCylindricalSurface(circ);
            XBRepBuilderAPI_MakeShell tempMake = new XBRepBuilderAPI_MakeShell(tempSurface.Value(), false);
            IRender.AddShape(tempMake.Shape(), true, true);
        }

        /// <summary>
        /// MakeEllipse
        /// </summary>
        internal void MakeEllipse()
        {
            xgp_Pnt P = new xgp_Pnt(0, 400, 0);
            xgp_Dir V = new xgp_Dir(1, 0, 0);
            xgp_Ax2 Axes = new xgp_Ax2(P, V);
            xgp_Elips elips = new xgp_Elips(Axes, 80, 60);
            XGC_MakeEllipse tempSurface = new XGC_MakeEllipse(elips);
            XBRepBuilderAPI_MakeEdge tempMake = new XBRepBuilderAPI_MakeEdge(tempSurface.Value());
            IRender.AddShape(tempMake.Shape(), true, true);
        }

        /// <summary>
        /// MakeHyperbola
        /// </summary>
        internal void MakeHyperbola()
        {
            xgp_Pnt P = new xgp_Pnt(0, 400, 0);
            xgp_Dir V = new xgp_Dir(1, 0, 0);
            xgp_Ax2 Axes = new xgp_Ax2(P, V);
            xgp_Hypr hypr = new xgp_Hypr(Axes, 80, 60);
            XGC_MakeHyperbola tempGC = new XGC_MakeHyperbola(hypr);
            XBRepBuilderAPI_MakeEdge tempMake = new XBRepBuilderAPI_MakeEdge(tempGC.Value());
            IRender.AddShape(tempMake.Shape(), true, true);
        }

        /// <summary>
        /// MakeLine
        /// </summary>
        internal void MakeLine()
        {
            xgp_Pnt P = new xgp_Pnt(200, 400, 0);
            xgp_Pnt P1 = new xgp_Pnt(300, 400, 0);
            XGC_MakeLine tempGC = new XGC_MakeLine(P, P1);
            XBRepBuilderAPI_MakeEdge tempMake = new XBRepBuilderAPI_MakeEdge(tempGC.Value());
            IRender.AddShape(tempMake.Shape(), true, true);
        }

        /// <summary>
        /// MakePlane
        /// </summary>
        internal void MakePlane()
        {
            xgp_Pnt P = new xgp_Pnt(400, 400, 0);
            xgp_Dir V = new xgp_Dir(1, 0, 0);
            xgp_Ax1 Axes = new xgp_Ax1(P, V);
            XGC_MakePlane tempGC = new XGC_MakePlane(Axes);
            XBRepBuilderAPI_MakeShell tempMake = new XBRepBuilderAPI_MakeShell(tempGC.Value(), false);
            IRender.AddShape(tempMake.Shape(), true, true);
        }


        /// <summary>
        /// MakeRotation
        /// </summary>
        internal void MakeRotation()
        {
            //xgp_Pnt P = new xgp_Pnt(400, 400, 0);
            //xgp_Dir V = new xgp_Dir(1, 0, 0);
            //xgp_Ax1 Axes = new xgp_Ax1(P, V);
            //XGC_MakeRotation tempGC = new XGC_MakeRotation(Axes, 270);
            //XBRepBuilderAPI_MakeShell tempMake = new XBRepBuilderAPI_MakeShell(tempGC.Value(), false);
            //IRender.AddShape(tempMake.Shape(), true, true);
        }

        /// <summary>
        /// MakeScale
        /// </summary>
        internal void MakeScale()
        {
            //xgp_Pnt P = new xgp_Pnt(400, 400, 0);
            //xgp_Dir V = new xgp_Dir(1, 0, 0);
            //xgp_Ax1 Axes = new xgp_Ax1(P, V);
            //XGC_MakeRotation tempGC = new XGC_MakeRotation(Axes, 270);
            //XBRepBuilderAPI_MakeShell tempMake = new XBRepBuilderAPI_MakeShell(tempGC.Value(), false);
            //IRender.AddShape(tempMake.Shape(), true, true);
        }

        /// <summary>
        /// MakeSegment
        /// </summary>
        internal void MakeSegment()
        {
            xgp_Pnt P1 = new xgp_Pnt(200, 300, 0);
            xgp_Pnt P2 = new xgp_Pnt(300, 300, 0);
            XGC_MakeSegment tempMake = new XGC_MakeSegment(P1, P2);
            XBRepBuilderAPI_MakeEdge tempEdge = new XBRepBuilderAPI_MakeEdge(tempMake.Value());
            IRender.AddShape(tempEdge.Edge(), true, true);
        }

        /// <summary>
        /// Transformation
        /// </summary>
        internal void Transformation()
        {
            //xgp_Pnt P = new xgp_Pnt(400, 400, 0);
            //xgp_Dir V = new xgp_Dir(1, 0, 0);
            //xgp_Ax1 Axes = new xgp_Ax1(P, V);
            //XGC_MakeRotation tempGC = new XGC_MakeRotation(Axes, 270);
            //XBRepBuilderAPI_MakeShell tempMake = new XBRepBuilderAPI_MakeShell(tempGC.Value(), false);
            //IRender.AddShape(tempMake.Shape(), true, true);
        }

        /// <summary>
        /// MakeTrimmedCone
        /// </summary>
        internal void MakeTrimmedCone()
        {
            //xgp_Pnt P = new xgp_Pnt(400, 400, 0);
            //xgp_Dir V = new xgp_Dir(1, 0, 0);
            //xgp_Ax1 Axes = new xgp_Ax1(P, V);
            //XGC_MakeRotation tempGC = new XGC_MakeRotation(Axes, 270);
            //XBRepBuilderAPI_MakeShell tempMake = new XBRepBuilderAPI_MakeShell(tempGC.Value(), false);
            //IRender.AddShape(tempMake.Shape(), true, true);
        }

        /// <summary>
        /// MakeTrimmedCylinder
        /// </summary>
        internal void MakeTrimmedCylinder()
        {
            //xgp_Pnt P = new xgp_Pnt(400, 400, 0);
            //xgp_Dir V = new xgp_Dir(1, 0, 0);
            //xgp_Ax1 Axes = new xgp_Ax1(P, V);
            //XGC_MakeRotation tempGC = new XGC_MakeRotation(Axes, 270);
            //XBRepBuilderAPI_MakeShell tempMake = new XBRepBuilderAPI_MakeShell(tempGC.Value(), false);
            //IRender.AddShape(tempMake.Shape(), true, true);
        }

        /// <summary>
        /// EMakeCirc
        /// </summary>
        internal void EMakeCirc()
        {
            //xgp_Pnt P = new xgp_Pnt(400, 400, 0);
            //xgp_Dir V = new xgp_Dir(1, 0, 0);
            //xgp_Ax1 Axes = new xgp_Ax1(P, V);
            //XGC_MakeRotation tempGC = new XGC_MakeRotation(Axes, 270);
            //XBRepBuilderAPI_MakeShell tempMake = new XBRepBuilderAPI_MakeShell(tempGC.Value(), false);
            //IRender.AddShape(tempMake.Shape(), true, true);
        }

        /// <summary>
        /// EMakeCirc2d
        /// </summary>
        internal void EMakeCirc2d()
        {
            //xgp_Pnt P = new xgp_Pnt(400, 400, 0);
            //xgp_Dir V = new xgp_Dir(1, 0, 0);
            //xgp_Ax1 Axes = new xgp_Ax1(P, V);
            //XGC_MakeRotation tempGC = new XGC_MakeRotation(Axes, 270);
            //XBRepBuilderAPI_MakeShell tempMake = new XBRepBuilderAPI_MakeShell(tempGC.Value(), false);
            //IRender.AddShape(tempMake.Shape(), true, true);
        }

        /// <summary>
        /// EMakeCone
        /// </summary>
        internal void EMakeCone()
        {
            //xgp_Pnt P = new xgp_Pnt(400, 400, 0);
            //xgp_Dir V = new xgp_Dir(1, 0, 0);
            //xgp_Ax1 Axes = new xgp_Ax1(P, V);
            //XGC_MakeRotation tempGC = new XGC_MakeRotation(Axes, 270);
            //XBRepBuilderAPI_MakeShell tempMake = new XBRepBuilderAPI_MakeShell(tempGC.Value(), false);
            //IRender.AddShape(tempMake.Shape(), true, true);
        }

        /// <summary>
        /// EMakeCylinder
        /// </summary>
        internal void EMakeCylinder()
        {
            //xgp_Pnt P = new xgp_Pnt(400, 400, 0);
            //xgp_Dir V = new xgp_Dir(1, 0, 0);
            //xgp_Ax1 Axes = new xgp_Ax1(P, V);
            //XGC_MakeRotation tempGC = new XGC_MakeRotation(Axes, 270);
            //XBRepBuilderAPI_MakeShell tempMake = new XBRepBuilderAPI_MakeShell(tempGC.Value(), false);
            //IRender.AddShape(tempMake.Shape(), true, true);
        }

        /// <summary>
        /// EMakeDir
        /// </summary>
        internal void EMakeDir()
        {
            //xgp_Pnt P = new xgp_Pnt(400, 400, 0);
            //xgp_Dir V = new xgp_Dir(1, 0, 0);
            //xgp_Ax1 Axes = new xgp_Ax1(P, V);
            //XGC_MakeRotation tempGC = new XGC_MakeRotation(Axes, 270);
            //XBRepBuilderAPI_MakeShell tempMake = new XBRepBuilderAPI_MakeShell(tempGC.Value(), false);
            //IRender.AddShape(tempMake.Shape(), true, true);
        }

        /// <summary>
        /// EMakeDir2d
        /// </summary>
        internal void EMakeDir2d()
        {
            //xgp_Pnt P = new xgp_Pnt(400, 400, 0);
            //xgp_Dir V = new xgp_Dir(1, 0, 0);
            //xgp_Ax1 Axes = new xgp_Ax1(P, V);
            //XGC_MakeRotation tempGC = new XGC_MakeRotation(Axes, 270);
            //XBRepBuilderAPI_MakeShell tempMake = new XBRepBuilderAPI_MakeShell(tempGC.Value(), false);
            //IRender.AddShape(tempMake.Shape(), true, true);
        }

        /// <summary>
        /// EMakeElips
        /// </summary>
        internal void EMakeElips()
        {
            //xgp_Pnt P = new xgp_Pnt(400, 400, 0);
            //xgp_Dir V = new xgp_Dir(1, 0, 0);
            //xgp_Ax1 Axes = new xgp_Ax1(P, V);
            //XGC_MakeRotation tempGC = new XGC_MakeRotation(Axes, 270);
            //XBRepBuilderAPI_MakeShell tempMake = new XBRepBuilderAPI_MakeShell(tempGC.Value(), false);
            //IRender.AddShape(tempMake.Shape(), true, true);
        }

        /// <summary>
        /// EMakeElips2d
        /// </summary>
        internal void EMakeElips2d()
        {
            //xgp_Pnt P = new xgp_Pnt(400, 400, 0);
            //xgp_Dir V = new xgp_Dir(1, 0, 0);
            //xgp_Ax1 Axes = new xgp_Ax1(P, V);
            //XGC_MakeRotation tempGC = new XGC_MakeRotation(Axes, 270);
            //XBRepBuilderAPI_MakeShell tempMake = new XBRepBuilderAPI_MakeShell(tempGC.Value(), false);
            //IRender.AddShape(tempMake.Shape(), true, true);
        }

        /// <summary>
        /// EMakeHypr
        /// </summary>
        internal void EMakeHypr()
        {
            //xgp_Pnt P = new xgp_Pnt(400, 400, 0);
            //xgp_Dir V = new xgp_Dir(1, 0, 0);
            //xgp_Ax1 Axes = new xgp_Ax1(P, V);
            //XGC_MakeRotation tempGC = new XGC_MakeRotation(Axes, 270);
            //XBRepBuilderAPI_MakeShell tempMake = new XBRepBuilderAPI_MakeShell(tempGC.Value(), false);
            //IRender.AddShape(tempMake.Shape(), true, true);
        }

        /// <summary>
        /// EMakeHypr2d
        /// </summary>
        internal void EMakeHypr2d()
        {
            //xgp_Pnt P = new xgp_Pnt(400, 400, 0);
            //xgp_Dir V = new xgp_Dir(1, 0, 0);
            //xgp_Ax1 Axes = new xgp_Ax1(P, V);
            //XGC_MakeRotation tempGC = new XGC_MakeRotation(Axes, 270);
            //XBRepBuilderAPI_MakeShell tempMake = new XBRepBuilderAPI_MakeShell(tempGC.Value(), false);
            //IRender.AddShape(tempMake.Shape(), true, true);
        }

        /// <summary>
        /// EMakeLin
        /// </summary>
        internal void EMakeLin()
        {
            //xgp_Pnt P = new xgp_Pnt(400, 400, 0);
            //xgp_Dir V = new xgp_Dir(1, 0, 0);
            //xgp_Ax1 Axes = new xgp_Ax1(P, V);
            //XGC_MakeRotation tempGC = new XGC_MakeRotation(Axes, 270);
            //XBRepBuilderAPI_MakeShell tempMake = new XBRepBuilderAPI_MakeShell(tempGC.Value(), false);
            //IRender.AddShape(tempMake.Shape(), true, true);
        }

        /// <summary>
        /// EMakeLin2d
        /// </summary>
        internal void EMakeLin2d()
        {
            //xgp_Pnt P = new xgp_Pnt(400, 400, 0);
            //xgp_Dir V = new xgp_Dir(1, 0, 0);
            //xgp_Ax1 Axes = new xgp_Ax1(P, V);
            //XGC_MakeRotation tempGC = new XGC_MakeRotation(Axes, 270);
            //XBRepBuilderAPI_MakeShell tempMake = new XBRepBuilderAPI_MakeShell(tempGC.Value(), false);
            //IRender.AddShape(tempMake.Shape(), true, true);
        }

        /// <summary>
        /// EMakeMirror
        /// </summary>
        internal void EMakeMirror()
        {
            //xgp_Pnt P = new xgp_Pnt(400, 400, 0);
            //xgp_Dir V = new xgp_Dir(1, 0, 0);
            //xgp_Ax1 Axes = new xgp_Ax1(P, V);
            //XGC_MakeRotation tempGC = new XGC_MakeRotation(Axes, 270);
            //XBRepBuilderAPI_MakeShell tempMake = new XBRepBuilderAPI_MakeShell(tempGC.Value(), false);
            //IRender.AddShape(tempMake.Shape(), true, true);
        }

        /// <summary>
        /// EMakeMirror2d
        /// </summary>
        internal void EMakeMirror2d()
        {
            //xgp_Pnt P = new xgp_Pnt(400, 400, 0);
            //xgp_Dir V = new xgp_Dir(1, 0, 0);
            //xgp_Ax1 Axes = new xgp_Ax1(P, V);
            //XGC_MakeRotation tempGC = new XGC_MakeRotation(Axes, 270);
            //XBRepBuilderAPI_MakeShell tempMake = new XBRepBuilderAPI_MakeShell(tempGC.Value(), false);
            //IRender.AddShape(tempMake.Shape(), true, true);
        }

        /// <summary>
        /// EMakeParab
        /// </summary>
        internal void EMakeParab()
        {
            //xgp_Pnt P = new xgp_Pnt(400, 400, 0);
            //xgp_Dir V = new xgp_Dir(1, 0, 0);
            //xgp_Ax1 Axes = new xgp_Ax1(P, V);
            //XGC_MakeRotation tempGC = new XGC_MakeRotation(Axes, 270);
            //XBRepBuilderAPI_MakeShell tempMake = new XBRepBuilderAPI_MakeShell(tempGC.Value(), false);
            //IRender.AddShape(tempMake.Shape(), true, true);
        }

        /// <summary>
        /// EMakeParab2d
        /// </summary>
        internal void EMakeParab2d()
        {
            //xgp_Pnt P = new xgp_Pnt(400, 400, 0);
            //xgp_Dir V = new xgp_Dir(1, 0, 0);
            //xgp_Ax1 Axes = new xgp_Ax1(P, V);
            //XGC_MakeRotation tempGC = new XGC_MakeRotation(Axes, 270);
            //XBRepBuilderAPI_MakeShell tempMake = new XBRepBuilderAPI_MakeShell(tempGC.Value(), false);
            //IRender.AddShape(tempMake.Shape(), true, true);
        }

        /// <summary>
        /// EMakePln
        /// </summary>
        internal void EMakePln()
        {
            //xgp_Pnt P = new xgp_Pnt(400, 400, 0);
            //xgp_Dir V = new xgp_Dir(1, 0, 0);
            //xgp_Ax1 Axes = new xgp_Ax1(P, V);
            //XGC_MakeRotation tempGC = new XGC_MakeRotation(Axes, 270);
            //XBRepBuilderAPI_MakeShell tempMake = new XBRepBuilderAPI_MakeShell(tempGC.Value(), false);
            //IRender.AddShape(tempMake.Shape(), true, true);
        }

        /// <summary>
        /// EMakeRotation
        /// </summary>
        internal void EMakeRotation()
        {
            //xgp_Pnt P = new xgp_Pnt(400, 400, 0);
            //xgp_Dir V = new xgp_Dir(1, 0, 0);
            //xgp_Ax1 Axes = new xgp_Ax1(P, V);
            //XGC_MakeRotation tempGC = new XGC_MakeRotation(Axes, 270);
            //XBRepBuilderAPI_MakeShell tempMake = new XBRepBuilderAPI_MakeShell(tempGC.Value(), false);
            //IRender.AddShape(tempMake.Shape(), true, true);
        }

        /// <summary>
        /// EMakeRotation2d
        /// </summary>
        internal void EMakeRotation2d()
        {
            //xgp_Pnt P = new xgp_Pnt(400, 400, 0);
            //xgp_Dir V = new xgp_Dir(1, 0, 0);
            //xgp_Ax1 Axes = new xgp_Ax1(P, V);
            //XGC_MakeRotation tempGC = new XGC_MakeRotation(Axes, 270);
            //XBRepBuilderAPI_MakeShell tempMake = new XBRepBuilderAPI_MakeShell(tempGC.Value(), false);
            //IRender.AddShape(tempMake.Shape(), true, true);
        }

        /// <summary>
        /// EMakeScale
        /// </summary>
        internal void EMakeScale()
        {
            //xgp_Pnt P = new xgp_Pnt(400, 400, 0);
            //xgp_Dir V = new xgp_Dir(1, 0, 0);
            //xgp_Ax1 Axes = new xgp_Ax1(P, V);
            //XGC_MakeRotation tempGC = new XGC_MakeRotation(Axes, 270);
            //XBRepBuilderAPI_MakeShell tempMake = new XBRepBuilderAPI_MakeShell(tempGC.Value(), false);
            //IRender.AddShape(tempMake.Shape(), true, true);
        }

        /// <summary>
        /// EMakeScale2d
        /// </summary>
        internal void EMakeScale2d()
        {
            //xgp_Pnt P = new xgp_Pnt(400, 400, 0);
            //xgp_Dir V = new xgp_Dir(1, 0, 0);
            //xgp_Ax1 Axes = new xgp_Ax1(P, V);
            //XGC_MakeRotation tempGC = new XGC_MakeRotation(Axes, 270);
            //XBRepBuilderAPI_MakeShell tempMake = new XBRepBuilderAPI_MakeShell(tempGC.Value(), false);
            //IRender.AddShape(tempMake.Shape(), true, true);
        }

        /// <summary>
        /// EMakeTranslation
        /// </summary>
        internal void EMakeTranslation()
        {
            //xgp_Pnt P = new xgp_Pnt(400, 400, 0);
            //xgp_Dir V = new xgp_Dir(1, 0, 0);
            //xgp_Ax1 Axes = new xgp_Ax1(P, V);
            //XGC_MakeRotation tempGC = new XGC_MakeRotation(Axes, 270);
            //XBRepBuilderAPI_MakeShell tempMake = new XBRepBuilderAPI_MakeShell(tempGC.Value(), false);
            //IRender.AddShape(tempMake.Shape(), true, true);
        }

        /// <summary>
        /// EMakeTranslation2d
        /// </summary>
        internal void EMakeTranslation2d()
        {
            //xgp_Pnt P = new xgp_Pnt(400, 400, 0);
            //xgp_Dir V = new xgp_Dir(1, 0, 0);
            //xgp_Ax1 Axes = new xgp_Ax1(P, V);
            //XGC_MakeRotation tempGC = new XGC_MakeRotation(Axes, 270);
            //XBRepBuilderAPI_MakeShell tempMake = new XBRepBuilderAPI_MakeShell(tempGC.Value(), false);
            //IRender.AddShape(tempMake.Shape(), true, true);
        }
        #endregion

        #region 视图操作
        /// <summary>
        /// 删除选中
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        public void DeleteObjects()
        {
            IRender.DeleteObjects();
        }
        /// <summary>
        /// 全部清除
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        public void RemoveAll()
        {
            IRender.RemoveAll(true);
        }

        /// <summary>
        ///set material （设置材料）
        /// </summary>
        public void SetMaterial(Graphic3d_NameOfMaterial theMaterial)
        {
            IRender.SetMaterial(theMaterial);
        }

        /// <summary>
        ///set transparency (设置透明度)
        /// </summary>
        public void SetTransparency(int theTrans)
        {
            IRender.SetTransparency(theTrans);
        }


        public int DisplayMode() {
           return IRender.GetDisplayMode();
        }
        /// <summary>
        /// 判断是否选择对象
        /// </summary>
        /// <returns></returns>
        public bool IsObjectSelected
        {
            get { return IRender.IsObjectSelected; }
        }
        public bool DegenerateMode
        {
            get { return IRender.DegenerateMode; }
            set { IRender.DegenerateMode = value; }
        }


        public CurrentAction3d Mode
        {
            get { return IRender.Mode; }
            set { IRender.Mode = value; }
        }

        public float Zoom
        {
            set { IRender.Zoom = value; }
        }
        /// <summary>
        ///Update view
        /// </summary>
        public void UpdateView()
        {
            IRender.UpdateView();
        }

        /// <summary>
        ///Set computed mode in false
        /// </summary>
        public void SetDegenerateModeOn()
        {

            IRender.SetDegenerateModeOn();
        }

        /// <summary>
        ///Set computed mode in true
        /// </summary>
        public void SetDegenerateModeOff()
        {
            IRender.SetDegenerateModeOff();
        }

        /// <summary>
        ///Fit all
        /// </summary>
        public void WindowFitAll(int theXmin, int theYmin, int theXmax, int theYmax)
        {
            IRender.WindowFitAll(theXmin, theYmin, theXmax, theYmax);
        }

        /// <summary>
        ///Front side
        /// </summary>
        public void FrontView()
        {
            IRender.FrontView();
        }

        /// <summary>
        ///Top side
        /// </summary>
        public void TopView()
        {
            IRender.TopView();
        }

        /// <summary>
        ///Left side
        /// </summary>
        public void LeftView()
        {
            IRender.LeftView();
        }

        /// <summary>
        ///Back side
        /// </summary>
        public void BackView()
        {
            IRender.BackView();
        }

        /// <summary>
        ///Right side
        /// </summary>
        public void RightView()
        {
            IRender.RightView();
        }

        /// <summary>
        ///Bottom side
        /// </summary>
        public void BottomView()
        {
            IRender.BottomView();
        }

        /// <summary>
        ///Axo side
        /// </summary>
        public void AxoView()
        {
            IRender.AxoView();
        }

        /// <summary>
        ///Zoom in all view
        /// </summary>
        public void ZoomAllView()
        {
            IRender.ZoomAllView();
        }

        /// <summary>
        ///Scale
        /// </summary>
        public double Scale()
        {
            return IRender.Scale();
        }


        public void SetLight(bool OnLight)
        {
            IRender.SetLight(OnLight);
        }

        public void SetGridActivity(bool GridActivity)
        {
            IRender.SetLight(GridActivity);
        }


        /// <summary>
        ///Reset view
        /// </summary>
        public void Reset()
        {
            IRender.Reset();
        }
        #endregion

        #region 全局设置配置

        public void ChangeColor(bool IsSelectObject = false)
        {
            IRender.ChangeColor(IsSelectObject);
        }
        /// <summary>
        /// 图形边框显示
        /// </summary>
        /// <param name="anInteractive"></param>
        /// <param name="IsBoundaryDraw"></param>
        public void SetFaceBoundaryAspect(XAIS_InteractiveObject anInteractive, bool IsBoundaryDraw)
        {
            XPrs3d_Drawer aDrawer = anInteractive.Attributes();
            aDrawer.SetFaceBoundaryDraw(IsBoundaryDraw);
            if (IsBoundaryDraw)
            {
                XPrs3d_LineAspect aBoundaryAspect = aDrawer.FaceBoundaryAspect();
                aBoundaryAspect.SetColor(new XQuantity_Color(0.0, 0.0, 0.0, XQuantity_TypeOfColor.Quantity_TOC_RGB));
                aBoundaryAspect.SetTypeOfLine(XAspect_TypeOfLine.Aspect_TOL_SOLID);
                aBoundaryAspect.SetWidth(1.0);
            }
        }
        #endregion
    }
}
