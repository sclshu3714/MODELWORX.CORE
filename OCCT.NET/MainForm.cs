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
using TKBO;
using TKBRep;
using TKernel;
using TKFillet;
using TKMath;
using TKPrim;
using TKTopAlgo;
using TKV3d;

namespace OCCT.NET
{
    public partial class MainForm : Form
    {
        private static readonly object lockObject = new object();
        private RenderWindow IRender { get; set; } = null;
        public MainForm() {
            InitializeComponent();
            RegistrationEvents();
        }

        private void MainForm_Load(object sender, EventArgs e) {
            IRender = new RenderWindow(this.RWControl);
            IRender.SetDisplayMode(1);

        }

        private void btnBgColor_Click(object sender, EventArgs e) {
            IRender.ChangeColor(IRender.IsSelectObject);
        }

        private void btnStep_Click(object sender, EventArgs e) {
            OpenFileDialog dialog = new OpenFileDialog();
            dialog.InitialDirectory = @"D:\DataSource\TESTSTEP";
            dialog.Filter = "STEP文件(*.stp;*step)|*.stp;*step|所有文件(*.*)|*.*";
            if(dialog.ShowDialog() == DialogResult.OK)
                IRender.TranslateModel(ref this.tvwNode, dialog.FileName, CurrentModelFormat.STEP, true);
            this.tvwNode.ExpandAll();
        }
        int index = 0;
        private void btnSetModel_Click(object sender, EventArgs e) {
            index = index == 0 ? 1 : 0;
            IRender.SetDisplayMode(index);
        }

        private void toolStripButton1_Click(object sender, EventArgs e)
        {
            IRender.AddDisk();
            IRender.ZoomAllView();
        }

        private void toolStripButton2_Click(object sender, EventArgs e)
        {
            IRender.RemoveAll(true);
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
            this.Load += MainForm_Load;
            this.btnGrid.Click += BtnGrid_ItemClick;
            this.btnLine.Click += BtnLine_ItemClick;
            this.btnFace.Click += BtnFace_ItemClick;
            this.btnSolid.Click += BtnSolid_ItemClick;
            this.btnShell.Click += BtnShell_ItemClick;

            this.btnClearAll.Click += BtnClearAll_ItemClick;
            this.btnDeleteSelect.Click += BtnDeleteSelect_ItemClick;
            this.btnAnimation.Click += BtnAnimation_ItemClick;


        }

        #region 动画
        /// <summary>
        /// 动画
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void BtnAnimation_ItemClick(object sender, EventArgs e)
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
        private void BtnShell_ItemClick(object sender, EventArgs e)
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
        private void BtnSolid_ItemClick(object sender, EventArgs e)
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
        private void BtnFace_ItemClick(object sender, EventArgs e)
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
        private void BtnLine_ItemClick(object sender, EventArgs e)
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
        private void BtnGrid_ItemClick(object sender, EventArgs e)
        {
            xgp_Pnt P = new xgp_Pnt(0.0, 0.0, 0.0);
            XBRepBuilderAPI_MakeVertex MV1 = new XBRepBuilderAPI_MakeVertex(P);
            XTopoDS_Vertex V1 = MV1.Vertex();
            IRender.AddShape(V1, true);
        }
        #endregion

        #region 视图操作
        /// <summary>
        /// 删除选中
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void BtnDeleteSelect_ItemClick(object sender, EventArgs e)
        {
            IRender.DeleteObjects();
        }
        /// <summary>
        /// 全部清除
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void BtnClearAll_ItemClick(object sender, EventArgs e)
        {
            IRender.RemoveAll(true);
        }
        #endregion

        #region 全局设置配置
        /// <summary>
        /// 图形边框显示
        /// </summary>
        /// <param name="anInteractive"></param>
        /// <param name="IsBoundaryDraw"></param>
        void SetFaceBoundaryAspect(XAIS_InteractiveObject anInteractive, bool IsBoundaryDraw)
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
