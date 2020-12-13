using DevExpress.XtraBars;
using OCCT.Foundation.Net.TKBRep;
using OCCT.Foundation.Net.TKPrim;
using OCCT.TKMath.GP;
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
    public partial class MainForm : DevExpress.XtraBars.Ribbon.RibbonForm
    {
        private RenderWindow render { get; set; } = null;
        public MainForm()
        {
            InitializeComponent();
            RegistrationEvents();
        }

        private void MainForm_Load(object sender, EventArgs e)
        {
            render = new RenderWindow(this.RWControl);
            render.SetDisplayMode(1);
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
        private void RegistrationEvents() {
            this.Load += MainForm_Load;
            this.btnGrid.ItemClick += BtnGrid_ItemClick;
            this.btnLine.ItemClick += BtnLine_ItemClick;
            this.btnFace.ItemClick += BtnFace_ItemClick;
            this.btnSolid.ItemClick += BtnSolid_ItemClick;
            this.btnShell.ItemClick += BtnShell_ItemClick;

            this.btnClearAll.ItemClick += BtnClearAll_ItemClick;
            this.btnDeleteSelect.ItemClick += BtnDeleteSelect_ItemClick;
            this.btnAnimation.ItemClick += BtnAnimation_ItemClick;


        }

        #region 动画
        /// <summary>
        /// 动画
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void BtnAnimation_ItemClick(object sender, ItemClickEventArgs e)
        {
            XBRepPrimAPI_MakeBox obj1 = new XBRepPrimAPI_MakeBox(100, 100, 20);
            XAIS_Shape ais_obj1 = render.AddShape(obj1.Shape(), true);

            xgp_Trsf end_pnt0 = new xgp_Trsf();
            xgp_Trsf end_pnt1 = new xgp_Trsf();
            xgp_Trsf end_pnt2 = new xgp_Trsf();
            xgp_Trsf end_pnt3 = new xgp_Trsf();
            xgp_Trsf end_pnt4 = new xgp_Trsf();
            xgp_Trsf end_pnt5 = new xgp_Trsf();
            xgp_Trsf end_pnt6 = new xgp_Trsf();

            end_pnt0.SetValues(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0);
            end_pnt1.SetValues(1, 0, 0, 100, 0, 1, 0, 100, 0, 0, 1, 100);
            end_pnt2.SetValues(1, 0, 0, 200, 0, 1, 0, 200, 0, 0, 1, 100);
            end_pnt3.SetValues(1, 0, 0, 300, 0, 1, 0, 300, 0, 0, 1, 100);
            end_pnt4.SetValues(1, 0, 0, 400, 0, 1, 0, 400, 0, 0, 1, 100);
            end_pnt5.SetValues(1, 0, 0, 500, 0, 1, 0, 500, 0, 0, 1, 100);
            end_pnt6.SetValues(1, 0, 0, 600, 0, 1, 0, 600, 0, 0, 1, 100);

            XAIS_Animation ais_animation = new XAIS_Animation(new XTCollection_AsciiString("obj1_Ani"));

            ais_obj1.SetColor(new XQuantity_Color(XQuantity_NameOfColor.Quantity_NOC_ANTIQUEWHITE1));
            SetFaceBoundaryAspect(ais_obj1, true);
            XAIS_AnimationObject ais_ao0 = new XAIS_AnimationObject(new XTCollection_AsciiString("obj0"), render.GetInteractiveContext(), ais_obj1, end_pnt0, end_pnt1);
            ais_ao0.SetOwnDuration(10);
            ais_ao0.SetStartPts(0);
            ais_animation.Add(ais_ao0);

            ais_obj1.SetColor(new XQuantity_Color(XQuantity_NameOfColor.Quantity_NOC_ANTIQUEWHITE4));
            SetFaceBoundaryAspect(ais_obj1, false);
            XAIS_AnimationObject ais_ao1 = new XAIS_AnimationObject(new XTCollection_AsciiString("ais_ao1"), render.GetInteractiveContext(), ais_obj1, end_pnt1, end_pnt2);
            ais_ao1.SetOwnDuration(10);
            ais_ao1.SetStartPts(10);
            ais_animation.Add(ais_ao1);

            ais_obj1.SetColor(new XQuantity_Color(XQuantity_NameOfColor.Quantity_NOC_AZURE4));
            SetFaceBoundaryAspect(ais_obj1, true);
            XAIS_AnimationObject ais_ao2 = new XAIS_AnimationObject(new XTCollection_AsciiString("ais_ao2"), render.GetInteractiveContext(), ais_obj1, end_pnt2, end_pnt3);
            ais_ao2.SetOwnDuration(10);
            ais_ao2.SetStartPts(20);
            ais_animation.Add(ais_ao2);

            ais_obj1.SetColor(new XQuantity_Color(XQuantity_NameOfColor.Quantity_NOC_BISQUE)); 
            SetFaceBoundaryAspect(ais_obj1, false);
            XAIS_AnimationObject ais_ao3 = new XAIS_AnimationObject(new XTCollection_AsciiString("ais_ao3"), render.GetInteractiveContext(), ais_obj1, end_pnt3, end_pnt4);
            ais_ao3.SetOwnDuration(10);
            ais_ao3.SetStartPts(30);
            ais_animation.Add(ais_ao3);

            ais_obj1.SetColor(new XQuantity_Color(XQuantity_NameOfColor.Quantity_NOC_BLACK));
            SetFaceBoundaryAspect(ais_obj1, true);
            XAIS_AnimationObject ais_ao4 = new XAIS_AnimationObject(new XTCollection_AsciiString("ais_ao4"), render.GetInteractiveContext(), ais_obj1, end_pnt4, end_pnt5);
            ais_ao4.SetOwnDuration(10);
            ais_ao4.SetStartPts(40);
            ais_animation.Add(ais_ao4);

            ais_obj1.SetColor(new XQuantity_Color(XQuantity_NameOfColor.Quantity_NOC_BLUE3));
            SetFaceBoundaryAspect(ais_obj1, false);
            XAIS_AnimationObject ais_ao5 = new XAIS_AnimationObject(new XTCollection_AsciiString("ais_ao5"), render.GetInteractiveContext(), ais_obj1, end_pnt5, end_pnt6);
            ais_ao5.SetOwnDuration(10);
            ais_ao5.SetStartPts(50);
            ais_animation.Add(ais_ao5);

            ais_obj1.SetColor(new XQuantity_Color(XQuantity_NameOfColor.Quantity_NOC_BURLYWOOD1));
            SetFaceBoundaryAspect(ais_obj1, true);
            XAIS_AnimationObject ais_ao6 = new XAIS_AnimationObject(new XTCollection_AsciiString("ais_ao6"), render.GetInteractiveContext(), ais_obj1, end_pnt6, end_pnt6);
            ais_ao6.SetOwnDuration(10);
            ais_ao6.SetStartPts(60);
            ais_animation.Add(ais_ao6);

            double duration = ais_animation.Duration();
            ais_animation.StartTimer(0.0, 1.0, true, false);
            while (!ais_animation.IsStopped())
            {
                ais_animation.UpdateTimer();
                render.UpdateCurrentViewer();
            }
        }
        #endregion


        #region 几何图形
        /// <summary>
        /// 绘制壳图像
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void BtnShell_ItemClick(object sender, ItemClickEventArgs e)
        {
            xgp_Circ CR = new xgp_Circ(new xgp_Ax2(new xgp_Pnt(200.0, 200.0, 0.0), new xgp_Dir(0.0, 0.0, 1.0)), 80.0);
            XTopoDS_Edge REc = new XBRepBuilderAPI_MakeEdge(CR).Edge();
            XTopoDS_Wire RWc = new XBRepBuilderAPI_MakeWire(REc).Wire();
            XBRepBuilderAPI_MakeFace aRMakeFace = new XBRepBuilderAPI_MakeFace(RWc, false);
            //XBRepBuilderAPI_MakeShell tempA = new XBRepBuilderAPI_MakeShell();
            XAIS_Shape WAIS_ECD = new XAIS_Shape(aRMakeFace.Shape());
            SetFaceBoundaryAspect(WAIS_ECD, true);

            render.AddShape(WAIS_ECD, true);
        }


        /// <summary>
        /// 绘制体图像
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void BtnSolid_ItemClick(object sender, ItemClickEventArgs e)
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
            render.AddShape(WAIS_EC, true);

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
        private void BtnFace_ItemClick(object sender, ItemClickEventArgs e)
        {
            xgp_Pnt P = new xgp_Pnt(0.0, 0.0, 0.0);
            XBRepBuilderAPI_MakeVertex MV1 = new XBRepBuilderAPI_MakeVertex(P);
            XBRepPrimAPI_MakePrism S1 = new XBRepPrimAPI_MakePrism(MV1.Shape(), new xgp_Vec(100.0, 0.0, 0.0), false, true);
            XBRepPrimAPI_MakePrism S2 = new XBRepPrimAPI_MakePrism(S1.Shape(), new xgp_Vec(0.0, 100.0, 0.0), false, true);
            XAIS_Shape WAIS_EC = new XAIS_Shape(S2.Shape());
            SetFaceBoundaryAspect(WAIS_EC, true);
            render.AddShape(WAIS_EC, true);

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
        private void BtnLine_ItemClick(object sender, ItemClickEventArgs e)
        {
            xgp_Pnt P = new xgp_Pnt(0.0, 0.0, 0.0);
            XBRepBuilderAPI_MakeVertex MV1 = new XBRepBuilderAPI_MakeVertex(P);
            XBRepPrimAPI_MakePrism S1 = new XBRepPrimAPI_MakePrism(MV1.Shape(), new xgp_Vec(100.0, 0.0, 0.0), false, true);
            render.AddShape(S1.Shape(), true);
        }

        /// <summary>
        /// 绘制点图像
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void BtnGrid_ItemClick(object sender, ItemClickEventArgs e)
        {
            xgp_Pnt P = new xgp_Pnt(0.0, 0.0, 0.0);
            XBRepBuilderAPI_MakeVertex MV1 = new XBRepBuilderAPI_MakeVertex(P);
            XTopoDS_Vertex V1 = MV1.Vertex();
            render.AddShape(V1, true);
        }
        #endregion

        #region 视图操作
        /// <summary>
        /// 删除选中
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void BtnDeleteSelect_ItemClick(object sender, ItemClickEventArgs e)
        {
            render.ClearSelected(true);
        }
        /// <summary>
        /// 全部清除
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void BtnClearAll_ItemClick(object sender, ItemClickEventArgs e)
        {
            render.RemoveAll(true);
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