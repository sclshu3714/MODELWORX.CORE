
namespace UniversalCAD
{
    partial class MainForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MainForm));
            this.fluentDesignFormContainer = new DevExpress.XtraBars.FluentDesignSystem.FluentDesignFormContainer();
            this.RWControl = new System.Windows.Forms.Panel();
            this.accordionControl = new DevExpress.XtraBars.Navigation.AccordionControl();
            this.accElementOperation = new DevExpress.XtraBars.Navigation.AccordionControlElement();
            this.accElementOpen = new DevExpress.XtraBars.Navigation.AccordionControlElement();
            this.accElementSave = new DevExpress.XtraBars.Navigation.AccordionControlElement();
            this.accElementTLable = new DevExpress.XtraBars.Navigation.AccordionControlElement();
            this.accElementView = new DevExpress.XtraBars.Navigation.AccordionControlElement();
            this.accElementViewer = new DevExpress.XtraBars.Navigation.AccordionControlElement();
            this.accElementSection = new DevExpress.XtraBars.Navigation.AccordionControlElement();
            this.accElementMeasure = new DevExpress.XtraBars.Navigation.AccordionControlElement();
            this.accElementSetting = new DevExpress.XtraBars.Navigation.AccordionControlElement();
            this.accElementAbout = new DevExpress.XtraBars.Navigation.AccordionControlElement();
            this.fluentDesignFormControl = new DevExpress.XtraBars.FluentDesignSystem.FluentDesignFormControl();
            this.fluentFormDefaultManager = new DevExpress.XtraBars.FluentDesignSystem.FluentFormDefaultManager(this.components);
            this.imgList16 = new DevExpress.Utils.ImageCollection(this.components);
            this.imgList32 = new DevExpress.Utils.ImageCollection(this.components);
            this.fluentDesignFormContainer.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.accordionControl)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.fluentDesignFormControl)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.fluentFormDefaultManager)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.imgList16)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.imgList32)).BeginInit();
            this.SuspendLayout();
            // 
            // fluentDesignFormContainer
            // 
            this.fluentDesignFormContainer.Controls.Add(this.RWControl);
            this.fluentDesignFormContainer.Dock = System.Windows.Forms.DockStyle.Fill;
            this.fluentDesignFormContainer.Location = new System.Drawing.Point(52, 31);
            this.fluentDesignFormContainer.Name = "fluentDesignFormContainer";
            this.fluentDesignFormContainer.Size = new System.Drawing.Size(958, 668);
            this.fluentDesignFormContainer.TabIndex = 0;
            // 
            // RWControl
            // 
            this.RWControl.BackColor = System.Drawing.Color.Black;
            this.RWControl.Dock = System.Windows.Forms.DockStyle.Fill;
            this.RWControl.Location = new System.Drawing.Point(0, 0);
            this.RWControl.Name = "RWControl";
            this.RWControl.Size = new System.Drawing.Size(958, 668);
            this.RWControl.TabIndex = 0;
            // 
            // accordionControl
            // 
            this.accordionControl.Appearance.Item.Disabled.Font = new System.Drawing.Font("Tahoma", 10F);
            this.accordionControl.Appearance.Item.Disabled.Options.UseFont = true;
            this.accordionControl.Appearance.Item.Hovered.Font = new System.Drawing.Font("Tahoma", 12F);
            this.accordionControl.Appearance.Item.Hovered.Options.UseFont = true;
            this.accordionControl.Appearance.Item.Normal.Font = new System.Drawing.Font("Tahoma", 10F);
            this.accordionControl.Appearance.Item.Normal.Options.UseFont = true;
            this.accordionControl.Appearance.Item.Pressed.Font = new System.Drawing.Font("Tahoma", 10F);
            this.accordionControl.Appearance.Item.Pressed.Options.UseFont = true;
            this.accordionControl.Dock = System.Windows.Forms.DockStyle.Left;
            this.accordionControl.Elements.AddRange(new DevExpress.XtraBars.Navigation.AccordionControlElement[] {
            this.accElementOperation,
            this.accElementSetting,
            this.accElementAbout});
            this.accordionControl.Location = new System.Drawing.Point(0, 31);
            this.accordionControl.LookAndFeel.SkinName = "Office 2016 Black";
            this.accordionControl.LookAndFeel.UseDefaultLookAndFeel = false;
            this.accordionControl.Name = "accordionControl";
            this.accordionControl.OptionsMinimizing.State = DevExpress.XtraBars.Navigation.AccordionControlState.Minimized;
            this.accordionControl.RootDisplayMode = DevExpress.XtraBars.Navigation.AccordionControlRootDisplayMode.Footer;
            this.accordionControl.ScrollBarMode = DevExpress.XtraBars.Navigation.ScrollBarMode.Touch;
            this.accordionControl.ShowFilterControl = DevExpress.XtraBars.Navigation.ShowFilterControl.Always;
            this.accordionControl.Size = new System.Drawing.Size(52, 668);
            this.accordionControl.TabIndex = 1;
            this.accordionControl.ViewType = DevExpress.XtraBars.Navigation.AccordionControlViewType.HamburgerMenu;
            // 
            // accElementOperation
            // 
            this.accElementOperation.Elements.AddRange(new DevExpress.XtraBars.Navigation.AccordionControlElement[] {
            this.accElementOpen,
            this.accElementSave,
            this.accElementTLable,
            this.accElementView,
            this.accElementViewer,
            this.accElementSection,
            this.accElementMeasure});
            this.accElementOperation.Expanded = true;
            this.accElementOperation.ImageOptions.Image = global::UniversalCAD.Properties.Resources.Img_351;
            this.accElementOperation.Name = "accElementOperation";
            this.accElementOperation.Tag = "Operation";
            this.accElementOperation.Text = "功能";
            // 
            // accElementOpen
            // 
            this.accElementOpen.ImageOptions.Image = global::UniversalCAD.Properties.Resources.Img_351;
            this.accElementOpen.Name = "accElementOpen";
            this.accElementOpen.Style = DevExpress.XtraBars.Navigation.ElementStyle.Item;
            this.accElementOpen.Tag = "Open";
            this.accElementOpen.Text = "打开";
            // 
            // accElementSave
            // 
            this.accElementSave.ImageOptions.Image = global::UniversalCAD.Properties.Resources.Img_345;
            this.accElementSave.Name = "accElementSave";
            this.accElementSave.Style = DevExpress.XtraBars.Navigation.ElementStyle.Item;
            this.accElementSave.Tag = "Save";
            this.accElementSave.Text = "保存";
            // 
            // accElementTLable
            // 
            this.accElementTLable.ImageOptions.Image = global::UniversalCAD.Properties.Resources.Img_176;
            this.accElementTLable.Name = "accElementTLable";
            this.accElementTLable.Tag = "TLable";
            this.accElementTLable.Text = "模型";
            // 
            // accElementView
            // 
            this.accElementView.ImageOptions.Image = global::UniversalCAD.Properties.Resources.Img_416;
            this.accElementView.Name = "accElementView";
            this.accElementView.Tag = "View";
            this.accElementView.Text = "显示";
            // 
            // accElementViewer
            // 
            this.accElementViewer.ImageOptions.Image = global::UniversalCAD.Properties.Resources.Img_306;
            this.accElementViewer.Name = "accElementViewer";
            this.accElementViewer.Style = DevExpress.XtraBars.Navigation.ElementStyle.Item;
            this.accElementViewer.Tag = "Viewer";
            this.accElementViewer.Text = "视图";
            // 
            // accElementSection
            // 
            this.accElementSection.ImageOptions.Image = global::UniversalCAD.Properties.Resources.Img_312;
            this.accElementSection.Name = "accElementSection";
            this.accElementSection.Style = DevExpress.XtraBars.Navigation.ElementStyle.Item;
            this.accElementSection.Tag = "Section";
            this.accElementSection.Text = "剪辑";
            // 
            // accElementMeasure
            // 
            this.accElementMeasure.ImageOptions.Image = global::UniversalCAD.Properties.Resources.Img_32;
            this.accElementMeasure.Name = "accElementMeasure";
            this.accElementMeasure.Style = DevExpress.XtraBars.Navigation.ElementStyle.Item;
            this.accElementMeasure.Tag = "Measure";
            this.accElementMeasure.Text = "标记";
            // 
            // accElementSetting
            // 
            this.accElementSetting.ControlFooterAlignment = DevExpress.XtraBars.Navigation.AccordionItemFooterAlignment.Far;
            this.accElementSetting.Expanded = true;
            this.accElementSetting.ImageOptions.Image = global::UniversalCAD.Properties.Resources.Img_388;
            this.accElementSetting.Name = "accElementSetting";
            this.accElementSetting.Tag = "Setting";
            this.accElementSetting.Text = "设置";
            // 
            // accElementAbout
            // 
            this.accElementAbout.ControlFooterAlignment = DevExpress.XtraBars.Navigation.AccordionItemFooterAlignment.Far;
            this.accElementAbout.Expanded = true;
            this.accElementAbout.ImageOptions.Image = global::UniversalCAD.Properties.Resources.Img_400;
            this.accElementAbout.Name = "accElementAbout";
            this.accElementAbout.Tag = "About";
            this.accElementAbout.Text = "关于";
            // 
            // fluentDesignFormControl
            // 
            this.fluentDesignFormControl.FluentDesignForm = this;
            this.fluentDesignFormControl.Location = new System.Drawing.Point(0, 0);
            this.fluentDesignFormControl.Manager = this.fluentFormDefaultManager;
            this.fluentDesignFormControl.Name = "fluentDesignFormControl";
            this.fluentDesignFormControl.Size = new System.Drawing.Size(1010, 31);
            this.fluentDesignFormControl.TabIndex = 2;
            this.fluentDesignFormControl.TabStop = false;
            // 
            // fluentFormDefaultManager
            // 
            this.fluentFormDefaultManager.DockingEnabled = false;
            this.fluentFormDefaultManager.Form = this;
            // 
            // imgList16
            // 
            this.imgList16.ImageStream = ((DevExpress.Utils.ImageCollectionStreamer)(resources.GetObject("imgList16.ImageStream")));
            // 
            // imgList32
            // 
            this.imgList32.ImageStream = ((DevExpress.Utils.ImageCollectionStreamer)(resources.GetObject("imgList32.ImageStream")));
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 14F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1010, 699);
            this.ControlContainer = this.fluentDesignFormContainer;
            this.Controls.Add(this.fluentDesignFormContainer);
            this.Controls.Add(this.accordionControl);
            this.Controls.Add(this.fluentDesignFormControl);
            this.DoubleBuffered = true;
            this.FluentDesignFormControl = this.fluentDesignFormControl;
            this.IconOptions.Icon = ((System.Drawing.Icon)(resources.GetObject("MainForm.IconOptions.Icon")));
            this.Name = "MainForm";
            this.NavigationControl = this.accordionControl;
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "CAD";
            this.fluentDesignFormContainer.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.accordionControl)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.fluentDesignFormControl)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.fluentFormDefaultManager)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.imgList16)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.imgList32)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion
        private DevExpress.XtraBars.FluentDesignSystem.FluentDesignFormContainer fluentDesignFormContainer;
        private DevExpress.XtraBars.Navigation.AccordionControl accordionControl;
        private DevExpress.XtraBars.FluentDesignSystem.FluentDesignFormControl fluentDesignFormControl;
        private DevExpress.XtraBars.Navigation.AccordionControlElement accElementOperation;
        private DevExpress.XtraBars.FluentDesignSystem.FluentFormDefaultManager fluentFormDefaultManager;
        private DevExpress.Utils.ImageCollection imgList16;
        private DevExpress.Utils.ImageCollection imgList32;
        private DevExpress.XtraBars.Navigation.AccordionControlElement accElementOpen;
        private DevExpress.XtraBars.Navigation.AccordionControlElement accElementSave;
        private DevExpress.XtraBars.Navigation.AccordionControlElement accElementTLable;
        private DevExpress.XtraBars.Navigation.AccordionControlElement accElementView;
        private DevExpress.XtraBars.Navigation.AccordionControlElement accElementViewer;
        private DevExpress.XtraBars.Navigation.AccordionControlElement accElementSection;
        private DevExpress.XtraBars.Navigation.AccordionControlElement accElementMeasure;
        private DevExpress.XtraBars.Navigation.AccordionControlElement accElementAbout;
        private DevExpress.XtraBars.Navigation.AccordionControlElement accElementSetting;
        private System.Windows.Forms.Panel RWControl;
    }
}