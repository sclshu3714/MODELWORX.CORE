using OCCT.Foundation.Net;
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
            this.FormClosed += MainForm_FormClosed;
        }

        private void MainForm_FormClosed(object sender, FormClosedEventArgs e)
        {
            if (InitViewer) {
                OCCTView.InitOCCTProxy();
            }
        }

        public bool Initialize()
        {
            OCCTView = new OCCTProxy();
            if (!(InitViewer = OCCTView.InitViewer(this.Handle)))
            {
                MessageBox.Show("初始化图形失败");
                return InitViewer;
            }
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
            return InitViewer;
        }

        private void ToolStripMain_ItemClicked(object sender, ToolStripItemClickedEventArgs e)
        {
            ToolStripButton stripButton = e.ClickedItem as ToolStripButton;
            stripButton.Checked = !stripButton.Checked;
        }



        #region 操作事件
        /// <summary>
        /// 窗体大小变化事件
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void RenderWindow_SizeChanged(object sender, EventArgs e)
        {
            OCCTView.UpdateView();
        }
        /// <summary>
        /// 窗体绘制事件
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void RenderWindow_Paint(object sender, PaintEventArgs e)
        {
            if (InitViewer)
            {
                OCCTView.RedrawView();
                OCCTView.UpdateView();
            }
        }
        /// <summary>
        /// 键盘按下事件
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void RenderWindow_KeyDown(object sender, KeyEventArgs e)
        {
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
        private void RenderWindow_KeyUp(object sender, KeyEventArgs e)
        {
            myCurrentPressedKey = CurrentPressedKey.CurPressedKey_Nothing;
        }
        /// <summary>
        /// 鼠标按下事件
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void RenderWindow_MouseDown(object sender, MouseEventArgs e)
        {
            //InputHandler.MouseDown(mCanvas, e, Control.ModifierKeys);
            switch (e.Button)
            {
                case MouseButtons.Left:
                    #region 鼠标左键按下
                    myXmin = e.X; myYmin = e.Y;
                    myXmax = e.X; myYmax = e.Y;
                    if (myCurrentPressedKey == CurrentPressedKey.CurPressedKey_Ctrl)
                        // start the dinamic zooming....
                        myCurrentMode = CurrentAction3d.CurAction3d_Nothing;
                    else
                    {
                        switch (myCurrentMode)
                        {
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
                    if (myCurrentPressedKey == CurrentPressedKey.CurPressedKey_Ctrl)
                    {
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
		private void RenderWindow_MouseUp(object sender, MouseEventArgs e)
        {
            switch (e.Button)
            {
                case MouseButtons.Left:
                    #region 鼠标左键弹起
                    if (myCurrentPressedKey == CurrentPressedKey.CurPressedKey_Ctrl)
                    {
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
                    switch (myCurrentMode)
                    {
                        case CurrentAction3d.CurAction3d_Nothing:
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
                                if (myCurrentPressedKey == CurrentPressedKey.CurPressedKey_Shift)
                                    MultiDragEvent(myXmax, myYmax, 1);
                                else
                                    DragEvent(myXmax, myYmax, 1);
                            }
                            if (!myDegenerateModeIsOn)
                            {
                                OCCTView.SetDegenerateModeOff();
                                myDegenerateModeIsOn = false;
                            }
                            else
                            {
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
                    if (!myDegenerateModeIsOn)
                    {
                        OCCTView.SetDegenerateModeOff();
                        myDegenerateModeIsOn = false;
                    }
                    else
                    {
                        OCCTView.SetDegenerateModeOn();
                        myDegenerateModeIsOn = true;
                    }
                    #endregion
                    break;
                case MouseButtons.Middle:
                    #region 鼠标中键弹出
                    if (!myDegenerateModeIsOn)
                    {
                        OCCTView.SetDegenerateModeOff();
                        myDegenerateModeIsOn = false;
                    }
                    else
                    {
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
		private void RenderWindow_MouseMove(object sender, MouseEventArgs e)
        {
            //InputHandler.MouseMove(mCanvas, e, Control.ModifierKeys);
            if (e.Button == MouseButtons.Left) //left button is pressed
            {
                if (myCurrentPressedKey == CurrentPressedKey.CurPressedKey_Ctrl)
                {
                    //OCCTView.Zoom(myXmax, myYmax, e.X, e.Y);
                    //myXmax = e.X; myYmax = e.Y;
                    DrawRectangle(false);
                    myXmax = e.X; myYmax = e.Y;
                    DrawRectangle(true);
                }
                else
                {
                    switch (myCurrentMode)
                    {
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
            else if (e.Button == MouseButtons.Middle)
            {
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
		private void RenderWindow_MouseWheel(object sender, MouseEventArgs e)
        {
            //InputHandler.MouseWheel(mCanvas, e, Control.ModifierKeys);
            int addsd = 1;
            if (e.Delta > 0) addsd = -1;
            else addsd = 1;
            OCCTView.Zoom(e.X + addsd, e.Y, e.X, e.Y);
            myXmax = e.X; myYmax = e.Y;
        }

        protected void MultiDragEvent(int x, int y, int theState)
        {
            if (theState == -1)
            {
                theButtonDownX = x;
                theButtonDownY = y;
            }
            else if (theState == 1)
                OCCTView.ShiftSelect(Math.Min(theButtonDownX, x), Math.Min(theButtonDownY, y),
                        Math.Max(theButtonDownX, x), Math.Max(theButtonDownY, y));
        }

        protected void DragEvent(int x, int y, int theState)
        {
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

        protected void MultiInputEvent(int x, int y)
        {
            OCCTView.ShiftSelect();
        }

        protected void InputEvent(int x, int y)
        {
            OCCTView.Select();
        }

        private void DrawRectangle(bool draw)
        {
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
            else if (draw)
            {
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

        protected void MultiMoveEvent(int x, int y)
        {
            OCCTView.MoveTo(x, y);
        }

        protected void MoveEvent(int x, int y)
        {
            OCCTView.MoveTo(x, y);
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
        public bool InitViewer { get; set; } = false;
        #endregion
    }
}
