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

        }

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
            XBRepPrimAPI_MakeBox tempA = new XBRepPrimAPI_MakeBox(200.0, 150.0, 100.0);
            XBRepPrimAPI_MakeBox tempB = new XBRepPrimAPI_MakeBox(new xgp_Pnt(60, 60, 0), 200.0, 150.0, 100.0);
            XBRepPrimAPI_MakeBox tempC = new XBRepPrimAPI_MakeBox(new xgp_Pnt(60, 60, 0), new xgp_Pnt(200.0, 150.0, 100.0));
            XBRepPrimAPI_MakeBox tempD = new XBRepPrimAPI_MakeBox(new xgp_Ax2(new xgp_Pnt(100.0, 80.0, 70.0), new xgp_Dir(1.0, 2.0, 1.0)), 80.0, 90.0, 120.0);

            XAIS_Shape WAIS_ECA = new XAIS_Shape(tempA.Shape());
            SetFaceBoundaryAspect(WAIS_ECA, true);

            XAIS_Shape WAIS_ECB = new XAIS_Shape(tempB.Shape());
            SetFaceBoundaryAspect(WAIS_ECB, true);

            XAIS_Shape WAIS_ECC = new XAIS_Shape(tempC.Shape());
            SetFaceBoundaryAspect(WAIS_ECC, true);

            XAIS_Shape WAIS_ECD = new XAIS_Shape(tempD.Shape());
            SetFaceBoundaryAspect(WAIS_ECD, true);

            render.AddShape(WAIS_ECA, true);
            render.AddShape(WAIS_ECB, true);
            render.AddShape(WAIS_ECC, true);
            render.AddShape(WAIS_ECD, true);
        }

        /// <summary>
        /// 绘制面图像
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void BtnFace_ItemClick(object sender, ItemClickEventArgs e)
        {
            xgp_Circ CR = new xgp_Circ(new xgp_Ax2(new xgp_Pnt(200.0, 200.0, 0.0), new xgp_Dir(0.0, 0.0, 1.0)), 80.0);
            XTopoDS_Edge REc = new XBRepBuilderAPI_MakeEdge(CR).Edge();
            XTopoDS_Wire RWc = new XBRepBuilderAPI_MakeWire(REc).Wire();
            XBRepBuilderAPI_MakeFace aRMakeFace = new XBRepBuilderAPI_MakeFace(RWc, false);

            xgp_Circ Cr = new xgp_Circ(new xgp_Ax2(new xgp_Pnt(200.0, 200.0, 0.0), new xgp_Dir(0.0, 0.0, 1.0)), 60.0);
            XTopoDS_Edge rEc = new XBRepBuilderAPI_MakeEdge(Cr).Edge();
            XTopoDS_Wire rWc = new XBRepBuilderAPI_MakeWire(rEc).Wire();
            XBRepBuilderAPI_MakeFace arMakeFace = new XBRepBuilderAPI_MakeFace(rWc, false);

            XBRepAlgoAPI_Cut PipeProfile = new XBRepAlgoAPI_Cut(aRMakeFace.Shape(), arMakeFace.Shape());

            xgp_Vec sVec = new xgp_Vec(0, 0, 1 * 200);
            XBRepPrimAPI_MakePrism BRPA_MP = new XBRepPrimAPI_MakePrism(PipeProfile.Shape(), sVec, false, false);
            XAIS_Shape WAIS_EC = new XAIS_Shape(BRPA_MP.Shape());
            SetFaceBoundaryAspect(WAIS_EC, true);
            render.AddShape(WAIS_EC, true);
        }


        /// <summary>
        /// 图形显示边框
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

        /// <summary>
        /// 绘制线视图
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void BtnLine_ItemClick(object sender, ItemClickEventArgs e)
        {
            xgp_Pnt P = new xgp_Pnt(-200.0, -200.0, 0.0);
            XBRepBuilderAPI_MakeVertex MV1 = new XBRepBuilderAPI_MakeVertex(P);
            XBRepPrimAPI_MakePrism S1 = new XBRepPrimAPI_MakePrism(MV1.Shape(), new xgp_Vec(0.0, 0.0, 100.0), false, true);
            render.AddShape(S1.Shape(), true);
        }

        /// <summary>
        /// 绘制点图像
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void BtnGrid_ItemClick(object sender, ItemClickEventArgs e)
        {
            xgp_Pnt P = new xgp_Pnt(-200.0, -200.0, 0.0);
            XBRepBuilderAPI_MakeVertex MV1 = new XBRepBuilderAPI_MakeVertex(P);
            XTopoDS_Vertex V1 = MV1.Vertex();
            render.AddShape(V1, true);
        }
    }
}