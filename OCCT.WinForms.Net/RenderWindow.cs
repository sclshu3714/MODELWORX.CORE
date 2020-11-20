using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using OCCT.Foundation.Net;
using TKXDESTEP;
using TKLCAF;
using TKXCAF;
using TKVCAF;
using TKV3d;

namespace OCCT.WinForms.Net
{
    public partial class RenderWindow : UserControl
    {
        #region 构型
        public RenderWindow() {
            InitializeComponent();
            OCCTView = new OCCTProxy();
            IsInitViewer = OCCTView.InitViewer(this.Handle);
            if (!IsInitViewer) {
                MessageBox.Show("初始化图形失败");
            }
            myCurrentMode = CurrentAction3d.CurAction3d_DynamicRotation;
            myCurrentPressedKey = CurrentPressedKey.CurPressedKey_Nothing;
            myCurrentMode = CurrentAction3d.CurAction3d_DynamicRotation;
            myCurrentPressedKey = CurrentPressedKey.CurPressedKey_Nothing;
            myDegenerateModeIsOn = true;
            IsRectVisible = false;
            OCCTView.SetLight(true);

            this.SizeChanged += RenderWindow_SizeChanged;
            this.Paint += RenderWindow_Paint;
            this.KeyDown += RenderWindow_KeyDown;
            this.KeyUp += RenderWindow_KeyUp;
            this.MouseDown += RenderWindow_MouseDown;
            this.MouseUp += RenderWindow_MouseUp;
            this.MouseMove += RenderWindow_MouseMove;
            this.MouseWheel += RenderWindow_MouseWheel;
        }

        public RenderWindow(Control parent) : this() {
            if (parent != null) {
                parent.Controls.Add(this);
                Dock = DockStyle.Fill;
            }
        }
        #endregion

        #region 操作事件
        /// <summary>
        /// 窗体大小变化事件
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void RenderWindow_SizeChanged(object sender, EventArgs e) {
            OCCTView.UpdateView();
        }
        /// <summary>
        /// 窗体绘制事件
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void RenderWindow_Paint(object sender, PaintEventArgs e) {
            //if(mCanvas != null) {
            //	mCanvas.GetContext().RequestUpdate(EnumUpdateFlags.Camera);
            //}
            if (IsInitViewer) {
                OCCTView.RedrawView();
                OCCTView.UpdateView();
            }
        }
        /// <summary>
        /// 键盘按下事件
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void RenderWindow_KeyDown(object sender, KeyEventArgs e) {
            if (e.Shift)
                myCurrentPressedKey = CurrentPressedKey.CurPressedKey_Shift;
            if (e.Control)
                myCurrentPressedKey |= CurrentPressedKey.CurPressedKey_Ctrl;
            if (e.Alt)
                myCurrentPressedKey |= CurrentPressedKey.CurPressedKey_Alt;
        }
        /// <summary>
        /// 键盘弹起事件
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void RenderWindow_KeyUp(object sender, KeyEventArgs e) {
            myCurrentPressedKey = CurrentPressedKey.CurPressedKey_Nothing;
        }
        /// <summary>
        /// 鼠标按下事件
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void RenderWindow_MouseDown(object sender, MouseEventArgs e) {
            //InputHandler.MouseDown(mCanvas, e, Control.ModifierKeys);
            switch (e.Button) {
                case MouseButtons.Left:
                    #region 鼠标左键按下
                    myXmin = e.X; myYmin = e.Y;
                    myXmax = e.X; myYmax = e.Y;
                    if (myCurrentPressedKey == CurrentPressedKey.CurPressedKey_Ctrl)
                        // start the dinamic zooming....
                        myCurrentMode = CurrentAction3d.CurAction3d_Nothing;
                    else {
                        switch (myCurrentMode) {
                            case CurrentAction3d.CurAction3d_Nothing:
                                if (myCurrentPressedKey == CurrentPressedKey.CurPressedKey_Shift)
                                    MultiDragEvent(myXmax, myYmax, -1);
                                else
                                    DragEvent(myXmax, myYmax, -1);
                                break;
                            case CurrentAction3d.CurAction3d_DynamicRotation:
                                if (!myDegenerateModeIsOn)
                                    OCCTView.SetDegenerateModeOn();
                                //start the rotation
                                OCCTView.StartRotation(e.X, e.Y);
                                break;
                            case CurrentAction3d.CurAction3d_WindowZooming:
                                this.Cursor = System.Windows.Forms.Cursors.Hand;
                                break;
                            default:
                                break;
                        }
                    }
                    #endregion
                    break;
                case MouseButtons.Right:
                    #region 鼠标右键按下
                    //MessageBox.Show("right mouse button is down");
                    if (myCurrentPressedKey == CurrentPressedKey.CurPressedKey_Ctrl) {
                        if (!myDegenerateModeIsOn)
                            OCCTView.SetDegenerateModeOn();
                        OCCTView.StartRotation(e.X, e.Y);
                    }
                    //else
                    //    Popup(e.X, e.Y);
                    #endregion
                    break;
                case MouseButtons.Middle:
                    #region 鼠标中键按下
                    {
                        if (!myDegenerateModeIsOn)
                            OCCTView.SetDegenerateModeOn();
                        myCurrentMode = CurrentAction3d.CurAction3d_DynamicPanning;
                    }
                    #endregion
                    break;
                default:
                    break;
            }
        }
        /// <summary>
        /// 鼠标弹起事件
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
		private void RenderWindow_MouseUp(object sender, MouseEventArgs e) {
            //InputHandler.MouseUp(mCanvas, e, Control.ModifierKeys);
            switch (e.Button) {
                case MouseButtons.Left:
                    #region 鼠标左键弹起
                    if (myCurrentPressedKey == CurrentPressedKey.CurPressedKey_Ctrl) {
                        if (e.X == myXmin && e.Y == myYmin)
                        {
                            myXmax = e.X; myYmax = e.Y;
                            if (myCurrentPressedKey == CurrentPressedKey.CurPressedKey_Shift)
                                MultiInputEvent(myXmax, myYmax);
                            else
                                InputEvent(myXmax, myYmax);
                        }
                        else
                        {
                            myXmax = e.X; myYmax = e.Y;
                            DrawRectangle(false);
                            if (myCurrentPressedKey == CurrentPressedKey.CurPressedKey_Shift)
                                MultiDragEvent(myXmax, myYmax, 1);
                            else
                                DragEvent(myXmax, myYmax, 1);
                        }
                        myCurrentMode = CurrentAction3d.CurAction3d_DynamicRotation;
                        return;
                    }
                    switch (myCurrentMode) {
                        case CurrentAction3d.CurAction3d_Nothing:
                            if (e.X == myXmin && e.Y == myYmin) {
                                myXmax = e.X; myYmax = e.Y;
                                if (myCurrentPressedKey == CurrentPressedKey.CurPressedKey_Shift)
                                    MultiInputEvent(myXmax, myYmax);
                                else
                                    InputEvent(myXmax, myYmax);
                            }
                            else {
                                myXmax = e.X; myYmax = e.Y;
                                DrawRectangle(false);
                                if (myCurrentPressedKey == CurrentPressedKey.CurPressedKey_Shift)
                                    MultiDragEvent(myXmax, myYmax, 1);
                                else
                                    DragEvent(myXmax, myYmax, 1);
                            }
                            break;
                        case CurrentAction3d.CurAction3d_DynamicZooming:
                            myCurrentMode = CurrentAction3d.CurAction3d_DynamicZooming;
                            break;
                        case CurrentAction3d.CurAction3d_WindowZooming:
                            myXmax = e.X; myYmax = e.Y;
                            DrawRectangle(false);
                            int ValZWMin = 1;
                            if (Math.Abs(myXmax - myXmin) > ValZWMin && Math.Abs(myXmax - myYmax) > ValZWMin)
                                OCCTView.WindowFitAll(myXmin, myYmin, myXmax, myYmax);
                            this.Cursor = System.Windows.Forms.Cursors.Default;
                            //IE_WinForms.Form1 f = (IE_WinForms.Form1)this.ParentForm;
                            //f.SelectionChanged();
                            myCurrentMode = CurrentAction3d.CurAction3d_WindowZooming;
                            break;
                        case CurrentAction3d.CurAction3d_DynamicPanning:
                            myCurrentMode = CurrentAction3d.CurAction3d_DynamicPanning;
                            break;
                        case CurrentAction3d.CurAction3d_GlobalPanning:
                            OCCTView.Place(e.X, e.Y, myCurZoom);
                            myCurrentMode = CurrentAction3d.CurAction3d_GlobalPanning;
                            break;
                        case CurrentAction3d.CurAction3d_DynamicRotation:
                            myCurrentMode = CurrentAction3d.CurAction3d_DynamicRotation;
                            if (!myDegenerateModeIsOn) {
                                OCCTView.SetDegenerateModeOff();
                                myDegenerateModeIsOn = false;
                            }
                            else {
                                OCCTView.SetDegenerateModeOn();
                                myDegenerateModeIsOn = true;
                            }
                            break;
                        default:
                            break;

                    }
                    #endregion
                    break;
                case MouseButtons.Right:
                    #region 鼠标右键弹起
                    if (!myDegenerateModeIsOn) {
                        OCCTView.SetDegenerateModeOff();
                        myDegenerateModeIsOn = false;
                    }
                    else {
                        OCCTView.SetDegenerateModeOn();
                        myDegenerateModeIsOn = true;
                    }
                    #endregion
                    break;
                case MouseButtons.Middle:
                    #region 鼠标中键弹出
                    if (!myDegenerateModeIsOn) {
                        OCCTView.SetDegenerateModeOff();
                        myDegenerateModeIsOn = false;
                    }
                    else {
                        OCCTView.SetDegenerateModeOn();
                        myDegenerateModeIsOn = true;
                    }
                    myCurrentMode = CurrentAction3d.CurAction3d_DynamicRotation;
                    #endregion
                    break;
                default:
                    break;
            }
        }
        /// <summary>
        /// 鼠标移动事件
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
		private void RenderWindow_MouseMove(object sender, MouseEventArgs e) {
            //InputHandler.MouseMove(mCanvas, e, Control.ModifierKeys);
            if (e.Button == MouseButtons.Left) //left button is pressed
            {
                if (myCurrentPressedKey == CurrentPressedKey.CurPressedKey_Ctrl) {
                    //OCCTView.Zoom(myXmax, myYmax, e.X, e.Y);
                    //myXmax = e.X; myYmax = e.Y;
                    DrawRectangle(false);
                    myXmax = e.X; myYmax = e.Y;
                    DrawRectangle(true);
                }
                else {
                    switch (myCurrentMode) {
                        case CurrentAction3d.CurAction3d_Nothing:
                            DrawRectangle(false);
                            myXmax = e.X; myYmax = e.Y;
                            DrawRectangle(true);
                            break;
                        case CurrentAction3d.CurAction3d_DynamicZooming:
                            OCCTView.Zoom(myXmax, myYmax, e.X, e.Y);
                            myXmax = e.X; myYmax = e.Y;
                            break;
                        case CurrentAction3d.CurAction3d_WindowZooming:
                            DrawRectangle(false);
                            myXmax = e.X; myYmax = e.Y;
                            DrawRectangle(true);//add brush here
                            break;
                        case CurrentAction3d.CurAction3d_DynamicPanning:
                            OCCTView.Pan(e.X - myXmax, myYmax - e.Y);
                            myXmax = e.X; myYmax = e.Y;
                            break;
                        case CurrentAction3d.CurAction3d_GlobalPanning:
                            break;
                        case CurrentAction3d.CurAction3d_DynamicRotation:
                            OCCTView.Rotation(e.X, e.Y);
                            OCCTView.RedrawView();
                            break;
                        default:
                            break;
                    }
                }
            } // e.Button == MouseButtons.Left
            else if (e.Button == MouseButtons.Middle) {
                OCCTView.Pan(e.X - myXmax, myYmax - e.Y);
                myXmax = e.X; myYmax = e.Y;
            }//e.Button=MouseButtons.Middle
            else if (e.Button == MouseButtons.Right) //right button is pressed
            {
                if (myCurrentPressedKey == CurrentPressedKey.CurPressedKey_Ctrl)
                    OCCTView.Rotation(e.X, e.Y);
            }
            else // no buttons are pressed
            {
                myXmax = e.X; myYmax = e.Y;
                if (myCurrentPressedKey == CurrentPressedKey.CurPressedKey_Shift)
                    MultiMoveEvent(e.X, e.Y);
                else
                    MoveEvent(e.X, e.Y);
            }
        }
        /// <summary>
        /// 鼠标滚轮事件
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
		private void RenderWindow_MouseWheel(object sender, MouseEventArgs e) {
            //InputHandler.MouseWheel(mCanvas, e, Control.ModifierKeys);
            int addsd = 1;
            if (e.Delta > 0) addsd = -1;
            else addsd = 1;
            OCCTView.Zoom(e.X + addsd, e.Y, e.X, e.Y);
            myXmax = e.X; myYmax = e.Y;
        }

        protected void MultiDragEvent(int x, int y, int theState) {
            if (theState == -1) {
                theButtonDownX = x;
                theButtonDownY = y;
            }
            else if (theState == 1)
                OCCTView.ShiftSelect(Math.Min(theButtonDownX, x), Math.Min(theButtonDownY, y),
                        Math.Max(theButtonDownX, x), Math.Max(theButtonDownY, y));
        }

        protected void DragEvent(int x, int y, int theState) {
            if (theState == -1) //mouse is down
            {
                theButtonDownX = x;
                theButtonDownY = y;
            }
            else if (theState == 1) //mouse is up
            {
                OCCTView.Select(Math.Min(theButtonDownX, x), Math.Min(theButtonDownY, y),
                        Math.Max(theButtonDownX, x), Math.Max(theButtonDownY, y));
            }
        }

        //protected void Popup(int x, int y) {
        //    System.Drawing.Point p = new Point(x, y);
        //    if(this.OCCTView.IsObjectSelected())
        //        this.myPopupObject.Show(this, p);
        //    else
        //        this.myPopup.Show(this, p);
        //}

        protected void MultiInputEvent(int x, int y) {
            OCCTView.ShiftSelect();
        }

        protected void InputEvent(int x, int y) {
            OCCTView.Select();
        }

        private void DrawRectangle(bool draw) {
            Graphics gr = Graphics.FromHwnd(this.Handle);
            System.Drawing.Pen p = null;
            if (this.IsRectVisible || (!draw))//erase the rect
            {
                int r = OCCTView.GetBGColR();
                int g = OCCTView.GetBGColG();
                int b = OCCTView.GetBGColB();
                p = new Pen(System.Drawing.Color.FromArgb(r, g, b));
                this.IsRectVisible = false;
                this.OCCTView.UpdateView();
            }
            else if (draw) {
                p = new Pen(System.Drawing.Color.White);
                this.IsRectVisible = true;
            }
            if (p == null)
                return;
            int x = Math.Min(this.myXmin, this.myXmax);
            int y = Math.Min(this.myYmin, this.myYmax);
            gr.DrawRectangle(p, x, y, Math.Abs(myXmax - myXmin), Math.Abs(myYmax - myYmin));
            this.theRectDownX = Math.Max(this.myXmin, this.myXmax);
            this.theRectDownY = Math.Max(this.myYmin, this.myYmax);
        }

        protected void MultiMoveEvent(int x, int y) {
            OCCTView.MoveTo(x, y);
        }

        protected void MoveEvent(int x, int y) {
            OCCTView.MoveTo(x, y);
        }
        #endregion

        #region 设置配置

        /// <summary>
        /// 立即绘制
        /// </summary>
        public void RedrawView() {
            OCCTView.RedrawView();
        }

        /// <summary>
        /// 设置显示模式
        /// Set display mode
        /// </summary>
        /// <param name="aMode">显示模式</param>
        public void SetDisplayMode(int aMode) {
            OCCTView.SetDisplayMode(aMode);
            OCCTView.RedrawView();
        }

        /// <summary>
        /// 修改对象的显示颜色或者背景色
        /// Change the display color or background color of the object
        /// </summary>
        /// <param name="IsObjectColor">是否是对象</param>
        public void ChangeColor(bool IsObjectColor) {
            int r, g, b;
            if (IsObjectColor) {
                r = OCCTView.GetObjColR();
                g = OCCTView.GetObjColG();
                b = OCCTView.GetObjColB();
            }
            else {
                r = OCCTView.GetBGColR();
                g = OCCTView.GetBGColG();
                b = OCCTView.GetBGColB();
            }
            System.Windows.Forms.ColorDialog ColDlg = new ColorDialog();
            ColDlg.Color = System.Drawing.Color.FromArgb(r, g, b);
            if (ColDlg.ShowDialog() == DialogResult.OK) {
                Color c = ColDlg.Color;
                r = c.R;
                g = c.G;
                b = c.B;
                if (IsObjectColor)
                    OCCTView.SetColor(r, g, b);
                else
                    OCCTView.SetBackgroundColor(r, g, b);
            }
            this.OCCTView.UpdateCurrentViewer();
        }

        /// <summary>
        /// 设置透明度
        /// </summary>
        /// <param name="theTrans"></param>
        public void SetTransparency(int theTrans) {
            OCCTView.SetTransparency(theTrans);
            OCCTView.RedrawView();
        }

        /// <summary>
        /// 修改对象的显示颜色或者背景色
        /// Change the display color or background color of the object
        /// </summary>
        /// <param name="IsObjectColor">是否是对象</param>
        /// <param name="color">要修改的颜色</param>
        public void ChangeColor(bool IsObjectColor, Color color) {
            int r, g, b;
            if (IsObjectColor) {
                r = OCCTView.GetObjColR();
                g = OCCTView.GetObjColG();
                b = OCCTView.GetObjColB();
            }
            else {
                r = OCCTView.GetBGColR();
                g = OCCTView.GetBGColG();
                b = OCCTView.GetBGColB();
            }
            if (color == Color.Empty) {
                System.Windows.Forms.ColorDialog ColDlg = new ColorDialog();
                ColDlg.Color = System.Drawing.Color.FromArgb(r, g, b);
                if (ColDlg.ShowDialog() == DialogResult.OK) {
                    color = ColDlg.Color;
                }
            }
            r = color.R; g = color.G; b = color.B;
            if (IsObjectColor)
                OCCTView.SetColor(r, g, b);
            else
                OCCTView.SetBackgroundColor(r, g, b);
            this.OCCTView.UpdateCurrentViewer();

        }

        /// <summary>
        /// 删除对象
        /// delete objects
        /// </summary>
        public void DeleteObjects() {
            OCCTView.EraseObjects();
            //IE_WinForms.Form1 parent = (IE_WinForms.Form1)this.ParentForm;
            //parent.SelectionChanged();
        }

        /// <summary>
        /// 设置材料
        /// Setting materials
        /// </summary>
        /// <param name="NameOfMaterial"></param>
        public void SetMaterial(Graphic3d_NameOfMaterial NameOfMaterial) {
            OCCTView.SetMaterial((int)NameOfMaterial);
            OCCTView.RedrawView();
        }
        #endregion

        #region 导入/导出
        /// <summary>
        /// 定义必须调用的导入/导出函数
        /// Define which Import/Export function must be called
        /// </summary>
        /// <param name="theFileName">Name of Import/Export file</param>
        /// <param name="theFormat">Determines format of Import/Export file</param>
        /// <param name="theIsImport">Determines is Import or not</param>
        public bool TranslateModel(string theFileName, CurrentModelFormat theFormat, bool theIsImport) {
            //bool reuslt = OCCTView.TranslateModel(theFileName, (int)theFormat, theIsImport);
            //OCCTView.SetDisplayMode(1);
            //OCCTView.RedrawView();
            //OCCTView.ZoomAllView();
            XSTEPCAFControl_Reader aReader = new XSTEPCAFControl_Reader();
            aReader.SetColorMode(true);
            aReader.SetNameMode(true);
            IFSelect_ReturnStatus aStatus = (IFSelect_ReturnStatus)aReader.ReadFile(theFileName);
            XTDocStd_Document aDoc = new XTDocStd_Document("STEPCAF");
            XXCAFApp_Application anApp = new XXCAFApp_Application();// XXCAFApp_Application::GetApplication();
            anApp.NewDocument("XSEFSTEP", aDoc);
            if (aStatus != IFSelect_ReturnStatus.IFSelect_RetDone || !aReader.Transfer(aDoc))
                return false;
            XTDF_Label aRootLabel = aDoc.Main();
            XTDF_Label RootLabel = aRootLabel.Root();
            VisibleSettings(RootLabel, true);
            OCCTView.SetDisplayMode(1);
            OCCTView.RedrawView();
            OCCTView.ZoomAllView();
            return true;
        }

        private void VisibleSettings(XTDF_Label theLabel, bool IsBoundaryDraw)
        {
            if (!theLabel.HasChild())
            {
                Display(theLabel, IsBoundaryDraw);
                return;
            }
            XTDF_ChildIterator iter = new XTDF_ChildIterator();
            for (iter.Initialize(theLabel, false); iter.More(); iter.Next())
            {
                if (iter.EditValue().IsNull())
                    continue;
                VisibleSettings(iter.EditValue(), IsBoundaryDraw);
            }
        }
        /// <summary>
        /// 显示图形
        /// </summary>
        /// <param name="theLabel"></param>
        /// <param name="IsBoundaryDraw"></param>
        void Display(XTDF_Label theLabel, bool IsBoundaryDraw)
        {
            XTDataStd_Name aName = new XTDataStd_Name();
            if (theLabel.FindAttribute(XTDataStd_Name.GetIDx(), aName))
            {
                //std::cout << "  Name: " << aName->Get() << std::endl;
            }
            XTPrsStd_AISPresentation aPrs = new XTPrsStd_AISPresentation();
            if (!theLabel.FindAttribute(XTPrsStd_AISPresentation.GetIDx(), aPrs))
            {
                aPrs = XTPrsStd_AISPresentation.Set(theLabel, XXCAFPrs_Driver.GetID());
                aPrs.SetMaterial((int)Graphic3d_NameOfMaterial.Graphic3d_NOM_PLASTIC);
                aPrs.Display(true);

                XAIS_InteractiveObject anInteractive = aPrs.GetAISx();
                if (anInteractive != null)
                {
                    //XAIS_InteractiveContext context = OCCTView.GetInteractiveContext();
                    //context.Display(anInteractive, true);
                    // get drawer
                    XPrs3d_Drawer aDrawer = anInteractive.Attributes();
                    //// default attributes
                    //float aRed = 0.0;
                    //float aGreen = 0.0;
                    //float aBlue = 0.0;
                    //float aWidth = 1.0;
                    //XAspect_TypeOfLine aLineType = XAspect_TypeOfLine.Aspect_TOL_SOLID;
                    //// turn boundaries on/off
                    //bool isBoundaryDraw = true;
                    //aDrawer.SetFaceBoundaryDraw(isBoundaryDraw);
                    //XQuantity_Color aColor = new XQuantity_Color(aRed, aGreen, aBlue, Quantity_TOC_RGB);
                    //XPrs3d_LineAspect aBoundaryAspect = new XPrs3d_LineAspect(aColor, aLineType, aWidth);
                    //aDrawer->SetFaceBoundaryAspect(aBoundaryAspect);
                    //XAIS_InteractiveContext context = OCCTView.GetInteractiveContext();
                    //context.Display(anInteractive, true);
                }
                ////mainAISContext()->UpdateCurrentViewer();
            }
        }
        #endregion

        #region 字段
        protected CurrentAction3d myCurrentMode;
		protected CurrentPressedKey myCurrentPressedKey;
		protected float myCurZoom;
		protected bool myDegenerateModeIsOn;
		protected int myXmin;
		protected int myYmin;
		protected int myXmax;
		protected int myYmax;
		protected int theButtonDownX;
		protected int theButtonDownY;
		// for erasing of rectangle
		protected int theRectDownX;
		protected int theRectDownY;
		protected bool IsRectVisible;

        public OCCTProxy OCCTView { get; set; } = null;
        public bool IsInitViewer { get; set; } = false;
        #endregion
    }
}
