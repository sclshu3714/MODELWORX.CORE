#pragma once
// include required OCCT headers
#include <Standard_Version.hxx>
#include <Message_ProgressIndicator.hxx>
//for OCC graphic
#include <Aspect_DisplayConnection.hxx>
#include <WNT_Window.hxx>
#include <OpenGl_GraphicDriver.hxx>
//for object display
#include <V3d_Viewer.hxx>
#include <V3d_View.hxx>
#include <AIS_InteractiveContext.hxx>
#include <AIS_Shape.hxx>
//topology
#include <TopoDS_Shape.hxx>
#include <TopoDS_Compound.hxx>
//brep tools
#include <BRep_Builder.hxx>
#include <BRepTools.hxx>
// iges I/E
#include <IGESControl_Reader.hxx>
#include <IGESControl_Controller.hxx>
#include <IGESControl_Writer.hxx>
#include <IFSelect_ReturnStatus.hxx>
#include <Interface_Static.hxx>
//step I/E
#include <STEPControl_Reader.hxx>
#include <STEPControl_Writer.hxx>
//for stl export
#include <StlAPI_Writer.hxx>
//for vrml export
#include <VrmlAPI_Writer.hxx>
//wrapper of pure C++ classes to ref classes
#include <NCollection_Haft.h>

#include <vcclr.h>
#include <XCAFApp_Application.hxx>
#include <STEPCAFControl_Reader.hxx>
#include <XCAFDoc_ColorTool.hxx>
#include <XCAFDoc_ShapeTool.hxx>
#include <TDataStd_Name.hxx>
#include <XCAFDoc_DocumentTool.hxx>
#include <TDF_ChildIterator.hxx>
#include <XCAFPrs_AISObject.hxx>
#include <TPrsStd_AISPresentation.hxx>
#include <XCAFPrs_Driver.hxx>
#include <TNaming_NamedShape.hxx>
#include <XAIS_InteractiveContext.h>
#include <ViewerTest.hxx>
#include <TPrsStd_AISViewer.hxx>
#include <XV3d_View.h>
#include <AIS_TextLabel.hxx>
#include <Resource_ConvertUnicode.hxx>//Resource_Unicode
#include <Resource_Unicode.hxx>
#include <Aspect_TypeOfTriedronPosition.hxx>
#include <TDataStd_Integer.hxx>
#include <AIS_ViewCube.hxx>

#pragma region required OCCT libraries
// list of required OCCT libraries
#pragma comment(lib, "TKernel.lib")
#pragma comment(lib, "TKMath.lib")
#pragma comment(lib, "TKBRep.lib")
#pragma comment(lib, "TKXSBase.lib")
#pragma comment(lib, "TKService.lib")
#pragma comment(lib, "TKV3d.lib")
#pragma comment(lib, "TKOpenGl.lib")
#pragma comment(lib, "TKIGES.lib")
#pragma comment(lib, "TKSTEP.lib")
#pragma comment(lib, "TKStl.lib")
#pragma comment(lib, "TKVrml.lib")
#pragma comment(lib, "TKLCAF.lib")
#pragma endregion
class XCAFDoc_ShapeTool;
using namespace TKV3d;
ref class TKV3d::XAIS_InteractiveContext;

//! Auxiliary tool for converting C# string into UTF-8 string.
static TCollection_AsciiString toAsciiString(String^ theString) {
    if (theString == nullptr) {
        return TCollection_AsciiString();
    }

    pin_ptr<const wchar_t> aPinChars = PtrToStringChars(theString);
    const wchar_t* aWCharPtr = aPinChars;
    if (aWCharPtr == NULL
        || *aWCharPtr == L'\0') {
        return TCollection_AsciiString();
    }
    return TCollection_AsciiString(aWCharPtr);
}

/// <summary>
/// Proxy class encapsulating calls to OCCT C++ classes within
/// C++/CLI class visible from .Net (CSharp)
/// </summary>
public ref class OCCTProxy
{
public:
#pragma region 构造函数初始化
    OCCTProxy() {

    }

    // ============================================
    // Viewer functionality
    // ============================================

    /// <summary>
    ///Initialize a viewer
    /// </summary>
    /// <param name="theWnd">System.IntPtr that contains the window handle (HWND) of the control</param>
    bool InitViewer(System::IntPtr theWnd) {        
        //SetDllDirectory((LPCWSTR)L".\\3dparty\OCCT");
        TCHAR path[MAX_PATH] = L".\\3dparty\\OCCT" ;
        SetDllDirectory(path);
        try {
            Handle(Aspect_DisplayConnection) aDisplayConnection;// = new Aspect_DisplayConnection();
            mainGraphicDriver() = new OpenGl_GraphicDriver(aDisplayConnection);
        }
        catch (Standard_Failure) {
            return false;
        }
        mainViewer() = new V3d_Viewer(mainGraphicDriver());
        mainViewer()->SetDefaultLights();
        mainViewer()->SetLightOn();
        mainView() = mainViewer()->CreateView();
        Handle(WNT_Window) aWNTWindow = new WNT_Window(reinterpret_cast<HWND>(theWnd.ToPointer()));
        mainView()->SetWindow(aWNTWindow);
        if (!aWNTWindow->IsMapped()) {
            aWNTWindow->Map();
        }
        mainAISContext() = new AIS_InteractiveContext(mainViewer());
        mainAISContext()->UpdateCurrentViewer();
        mainView()->Redraw();
        mainView()->MustBeResized();

        TriedronDisplay(true, XAspect_TypeOfTriedronPosition(Aspect_TOTP_RIGHT_LOWER), 100, 100);
        mainView()->SetBgGradientColors(Quantity_Color(158 / 255.0, 165 / 255.0, 172 / 255.0, Quantity_TOC_RGB), Quantity_Color(229 / 255.0, 234 / 255.0, 236 / 255.0, Quantity_TOC_RGB), Aspect_GFM_VER, true);
        Graphic3d_Vec2i anoffset(0, 10);
       /* DisplayExplainText("中间 - sclshu3714@163.com - 中间", Aspect_TOTP_CENTER, anoffset = Graphic3d_Vec2i(127, 0));
        DisplayExplainText("左中 - sclshu3714@163.com - 左中", Aspect_TOTP_LEFT, anoffset = Graphic3d_Vec2i(0, 0));
        DisplayExplainText("左上 - sclshu3714@163.com - 左上", Aspect_TOTP_LEFT_UPPER, anoffset = Graphic3d_Vec2i(0, 15));
        DisplayExplainText("上中 - sclshu3714@163.com - 上中", Aspect_TOTP_TOP, anoffset = Graphic3d_Vec2i(127, 15));
        DisplayExplainText("右上 - sclshu3714@163.com - 右上", Aspect_TOTP_RIGHT_UPPER, anoffset = Graphic3d_Vec2i(254, 15));
        DisplayExplainText("右中 - sclshu3714@163.com - 右中", Aspect_TOTP_RIGHT, anoffset = Graphic3d_Vec2i(254, 0));
        DisplayExplainText("右下 - sclshu3714@163.com - 右下", Aspect_TOTP_RIGHT_LOWER, anoffset = Graphic3d_Vec2i(254, 0));
        DisplayExplainText("下中 - sclshu3714@163.com - 下中", Aspect_TOTP_BOTTOM, anoffset = Graphic3d_Vec2i(127, 0));*/
        DisplayExplainText("sclshu3714@163.com", Aspect_TOTP_LEFT_LOWER, anoffset = Graphic3d_Vec2i(0, 0));

        ////把图片添加到句柄控件上
        //Standard_Real Width = 0.0;
        //Standard_Real Height = 0.0;
        //mainView()->Size(Width, Height);

        return true;
    }

    void AISTextLabel(Standard_CString CString) {
        TCollection_ExtendedString toExtendedString;
        Resource_Unicode::ConvertGBToUnicode(CString, toExtendedString);
        Handle(AIS_TextLabel) aLabel = new AIS_TextLabel();
        aLabel->SetText(toExtendedString);
        aLabel->SetColor(Quantity_NOC_RED);
        aLabel->SetFont("SimHei");//一定要设置合适的字体，不然不能实现功能
        mainAISContext()->Display(aLabel, Standard_True);
    }
    /// <summary>
    /// 左上角显示text
    /// </summary>
    /// <param name="CString"></param>
    void DisplayExplainText(Standard_CString CString, Aspect_TypeOfTriedronPosition post, Graphic3d_Vec2i anoffset)
    {
        //Handle(AIS_InteractiveContext) aContext = ...;
        //Handle(AIS_InteractiveObject) anObj = ...; // create an AIS object
        TCollection_ExtendedString toExtendedString;
        Resource_Unicode::ConvertGBToUnicode(CString, toExtendedString);
        Handle(AIS_TextLabel) anObj = new AIS_TextLabel();
        anObj->SetText(toExtendedString);
        anObj->SetColor(Quantity_NOC_RED);
        anObj->SetFont("SimHei");//一定要设置合适的字体，不然不能实现功能
        anObj->SetZLayer(Graphic3d_ZLayerId_TopOSD); // display object in overlay
        Handle(Graphic3d_TransformPers) TransformPers = new Graphic3d_TransformPers(Graphic3d_TMF_2d, post, anoffset);
        anObj->SetTransformPersistence(TransformPers);
        mainAISContext()->Display(anObj, Standard_True); // display the object
    }
#pragma endregion

#pragma region 设置操作
    /// <summary>
    /// 全局坐标系显示
    /// </summary>
    /// <param name="IsViewCube"></param>
    /// <param name="thePosition"></param>
    void TriedronDisplay(bool IsViewCube, XAspect_TypeOfTriedronPosition thePosition, Standard_Integer theOffsetX, Standard_Integer theOffsetY) {
        if (!IsViewCube) {
            mainView()->TriedronDisplay(safe_cast<Aspect_TypeOfTriedronPosition>(thePosition), Quantity_NOC_BLACK, 0.20, V3d_ZBUFFER);   //画三维坐标系
        }
        else
        {
            Handle(AIS_ViewCube) HViewCube = new AIS_ViewCube();
            HViewCube->SetTransformPersistence(new Graphic3d_TransformPers(Graphic3d_TMF_TriedronPers, safe_cast<Aspect_TypeOfTriedronPosition>(thePosition), Graphic3d_Vec2i(theOffsetX, theOffsetY))); // set 2d flag, coordinate origin is set to down-left corner
            mainAISContext()->Display(HViewCube, Standard_True);
        }
    }
    /// <summary>
    /// Make dump of current view to file
    /// </summary>
    /// <param name="theFileName">Name of dump file</param>
    bool Dump(const TCollection_AsciiString& theFileName) {
        if (mainView().IsNull()) {
            return false;
        }
        mainView()->Redraw();
        return mainView()->Dump(theFileName.ToCString()) != Standard_False;
    }

    /// <summary>
    ///Redraw view
    /// </summary>
    void RedrawView(void) {
        if (!mainView().IsNull()) {
            mainView()->Redraw();
        }
    }

    /// <summary>
    ///Update view
    /// </summary>
    void UpdateView(void) {
        if (!mainView().IsNull()) {
            mainView()->MustBeResized();
        }
    }

    /// <summary>
    ///Set computed mode in false
    /// </summary>
    void SetDegenerateModeOn(void) {
        if (!mainView().IsNull()) {
            mainView()->SetComputedMode(Standard_False);
            mainView()->Redraw();
        }
    }

    /// <summary>
    ///Set computed mode in true
    /// </summary>
    void SetDegenerateModeOff(void) {
        if (!mainView().IsNull()) {
            mainView()->SetComputedMode(Standard_True);
            mainView()->Redraw();
        }
    }

    /// <summary>
    ///Fit all
    /// </summary>
    void WindowFitAll(Standard_Integer theXmin, Standard_Integer theYmin, Standard_Integer theXmax, Standard_Integer theYmax) {
        if (!mainView().IsNull()) {
            mainView()->WindowFitAll(theXmin, theYmin, theXmax, theYmax);
        }
    }

    /// <summary>
    ///Current place of window
    /// </summary>
    /// <param name="theZoomFactor">Current zoom</param>
    void Place(Standard_Integer theX, Standard_Integer theY, Standard_Real theZoomFactor) {
        Standard_Real aZoomFactor = theZoomFactor;
        if (!mainView().IsNull()) {
            mainView()->Place(theX, theY, aZoomFactor);
        }
    }

    /// <summary>
    ///Set Zoom
    /// </summary>
    void Zoom(Standard_Integer theX1, Standard_Integer theY1, Standard_Integer theX2, Standard_Integer theY2) {
        if (!mainView().IsNull()) {
            mainView()->Zoom(theX1, theY1, theX2, theY2);
        }
    }

    /// <summary>
    ///Set Pan
    /// </summary>
    void Pan(Standard_Integer theX, Standard_Integer theY) {
        if (!mainView().IsNull()) {
            mainView()->Pan(theX, theY);
        }
    }

    /// <summary>
    ///Rotation
    /// </summary>
    void Rotation(Standard_Integer theX, Standard_Integer theY) {
        if (!mainView().IsNull()) {
            mainView()->Rotation(theX, theY);
        }
    }

    /// <summary>
    ///Start rotation
    /// </summary>
    void StartRotation(Standard_Integer theX, Standard_Integer theY) {
        if (!mainView().IsNull()) {
            mainView()->StartRotation(theX, theY);
        }
    }

    /// <summary>
    ///Select by rectangle
    /// </summary>
    void Select(Standard_Integer theX1, Standard_Integer theY1, Standard_Integer theX2, Standard_Integer theY2) {
        if (!mainAISContext().IsNull()) {
            mainAISContext()->Select(theX1, theY1, theX2, theY2, mainView(), Standard_True);
        }
    }

    /// <summary>
    ///Select by click
    /// </summary>
    void Select(void) {
        if (!mainAISContext().IsNull()) {
            mainAISContext()->Select(Standard_True);
        }
    }

    /// <summary>
    ///Move view
    /// </summary>
    void MoveTo(Standard_Integer theX, Standard_Integer theY) {
        if ((!mainAISContext().IsNull()) && (!mainView().IsNull())) {
            mainAISContext()->MoveTo(theX, theY, mainView(), Standard_True);
        }
    }

    /// <summary>
    ///Select by rectangle with pressed "Shift" key
    /// </summary>
    void ShiftSelect(Standard_Integer theX1, Standard_Integer theY1, Standard_Integer theX2, Standard_Integer theY2) {
        if ((!mainAISContext().IsNull()) && (!mainView().IsNull())) {
            mainAISContext()->ShiftSelect(theX1, theY1, theX2, theY2, mainView(), Standard_True);
        }
    }

    /// <summary>
    ///Select by "Shift" key
    /// </summary>
    void ShiftSelect(void) {
        if (!mainAISContext().IsNull()) {
            mainAISContext()->ShiftSelect(Standard_True);
        }
    }

    /// <summary>
    ///Set background color
    /// </summary>
    void BackgroundColor(Standard_Integer% theRed, Standard_Integer% theGreen, Standard_Integer% theBlue) {
        Standard_Real R1 = 0;
        Standard_Real G1 = 0;
        Standard_Real B1 = 0;
        if (!mainView().IsNull()) {
            mainView()->BackgroundColor(Quantity_TOC_RGB, R1, G1, B1);
        }
        theRed = (Standard_Integer)(R1 * 255);
        theGreen = (Standard_Integer)(G1 * 255);
        theBlue = (Standard_Integer)(B1 * 255);
    }

    /// <summary>
    ///Get background color Red
    /// </summary>
    Standard_Integer GetBGColR(void) {
        Standard_Integer aRed = 0, aGreen = 0, aBlue = 0;
        BackgroundColor(aRed, aGreen, aBlue);
        return aRed;
    }

    /// <summary>
    ///Get background color Green
    /// </summary>
    Standard_Integer GetBGColG(void) {
        Standard_Integer aRed = 0, aGreen = 0, aBlue = 0;
        BackgroundColor(aRed, aGreen, aBlue);
        return aGreen;
    }

    /// <summary>
    ///Get background color Blue
    /// </summary>
    Standard_Integer GetBGColB(void) {
        Standard_Integer aRed = 0, aGreen = 0, aBlue = 0;
        BackgroundColor(aRed, aGreen, aBlue);
        return aBlue;
    }

    /// <summary>
    ///Update current viewer
    /// </summary>
    void UpdateCurrentViewer(void) {
        if (!mainAISContext().IsNull()) {
            mainAISContext()->UpdateCurrentViewer();
        }
    }

    /// <summary>
    ///Front side
    /// </summary>
    void FrontView(void) {
        if (!mainView().IsNull()) {
            mainView()->SetProj(V3d_Yneg);
        }
    }

    /// <summary>
    ///Top side
    /// </summary>
    void TopView(void) {
        if (!mainView().IsNull()) {
            mainView()->SetProj(V3d_Zpos);
        }
    }

    /// <summary>
    ///Left side
    /// </summary>
    void LeftView(void) {
        if (!mainView().IsNull()) {
            mainView()->SetProj(V3d_Xneg);
        }
    }

    /// <summary>
    ///Back side
    /// </summary>
    void BackView(void) {
        if (!mainView().IsNull()) {
            mainView()->SetProj(V3d_Ypos);
        }
    }

    /// <summary>
    ///Right side
    /// </summary>
    void RightView(void) {
        if (!mainView().IsNull()) {
            mainView()->SetProj(V3d_Xpos);
        }
    }

    /// <summary>
    ///Bottom side
    /// </summary>
    void BottomView(void) {
        if (!mainView().IsNull()) {
            mainView()->SetProj(V3d_Zneg);
        }
    }

    /// <summary>
    ///Axo side
    /// </summary>
    void AxoView(void) {
        if (!mainView().IsNull()) {
            mainView()->SetProj(V3d_XposYnegZpos);
        }
    }

    /// <summary>
    ///Scale
    /// </summary>
    Standard_Real Scale(void) {
        if (mainView().IsNull()) {
            return -1;
        }
        else {
            return (Standard_Real)mainView()->Scale();
        }
    }

    /// <summary>
    ///Zoom in all view
    /// </summary>
    void ZoomAllView(void) {
        if (!mainView().IsNull()) {
            mainView()->FitAll();
            mainView()->ZFitAll();
        }
    }

    void SetLight(bool OnLight) {
        if (OnLight)
            mainView()->SetLightOn();
        else
            mainView()->SetLightOff();
    }

    void SetGridActivity(bool GridActivity) {
        mainView()->SetGridActivity(GridActivity);
    }


    /// <summary>
    ///Reset view
    /// </summary>
    void Reset(void) {
        if (!mainView().IsNull()) {
            mainView()->Reset();
        }
    }

    /// <summary>
    ///Set display mode of objects
    /// </summary>
    /// <param name="theMode">Set current mode</param>
    void SetDisplayMode(Standard_Integer theMode) {
        if (mainAISContext().IsNull()) {
            return;
        }
        AIS_DisplayMode aCurrentMode;
        if (theMode == 0) {
            aCurrentMode = AIS_WireFrame;
        }
        else {
            aCurrentMode = AIS_Shaded;
        }

        if (mainAISContext()->NbSelected() == 0) {
            mainAISContext()->SetDisplayMode(aCurrentMode, Standard_False);
        }
        else {
            for (mainAISContext()->InitSelected(); mainAISContext()->MoreSelected(); mainAISContext()->NextSelected()) {
                mainAISContext()->SetDisplayMode(mainAISContext()->SelectedInteractive(), theMode, Standard_False);
            }
        }
        mainAISContext()->UpdateCurrentViewer();
    }

    /// <summary>
    ///Set color
    /// </summary>
    void SetColor(Standard_Integer theR, Standard_Integer theG, Standard_Integer theB) {
        if (mainAISContext().IsNull()) {
            return;
        }
        Quantity_Color aCol = Quantity_Color(theR / 255., theG / 255., theB / 255., Quantity_TOC_RGB);
        for (; mainAISContext()->MoreSelected(); mainAISContext()->NextSelected()) {
            mainAISContext()->SetColor(mainAISContext()->SelectedInteractive(), aCol, Standard_False);
        }
        mainAISContext()->UpdateCurrentViewer();
    }

    /// <summary>
    ///Get object color red
    /// </summary>
    Standard_Integer GetObjColR(void) {
        Standard_Integer aRed = 0, aGreen = 0, aBlue = 0;
        ObjectColor(aRed, aGreen, aBlue);
        return aRed;
    }

    /// <summary>
    ///Get object color green
    /// </summary>
    Standard_Integer GetObjColG(void) {
        Standard_Integer aRed = 0, aGreen = 0, aBlue = 0;
        ObjectColor(aRed, aGreen, aBlue);
        return aGreen;
    }

    /// <summary>
    ///Get object color R/G/B
    /// </summary>
    void ObjectColor(Standard_Integer theRed, Standard_Integer theGreen, Standard_Integer theBlue) {
        if (mainAISContext().IsNull()) {
            return;
        }
        theRed = 255;
        theGreen = 255;
        theBlue = 255;
        Handle(AIS_InteractiveObject) aCurrent;
        mainAISContext()->InitSelected();
        if (!mainAISContext()->MoreSelected()) {
            return;
        }
        aCurrent = mainAISContext()->SelectedInteractive();
        if (aCurrent->HasColor()) {
            Quantity_Color anObjCol;
            mainAISContext()->Color(aCurrent, anObjCol);
            Standard_Real r1, r2, r3;
            anObjCol.Values(r1, r2, r3, Quantity_TOC_RGB);
            theRed = (Standard_Integer)(r1 * 255);
            theGreen = (Standard_Integer)(r2 * 255);
            theBlue = (Standard_Integer)(r3 * 255);
        }
    }

    /// <summary>
    ///Get object color blue
    /// </summary>
    Standard_Integer GetObjColB(void) {
        Standard_Integer aRed = 0, aGreen = 0, aBlue = 0;
        ObjectColor(aRed, aGreen, aBlue);
        return aBlue;
    }

    /// <summary>
    ///Set background color R/G/B
    /// </summary>
    void SetBackgroundColor(Standard_Integer theRed, Standard_Integer theGreen, Standard_Integer theBlue) {
        if (!mainView().IsNull()) {
            mainView()->SetBackgroundColor(Quantity_TOC_RGB, theRed / 255., theGreen / 255., theBlue / 255.);
        }
    }

    /// <summary>
    /// 设置渐变背景色
    /// </summary>
    void SetBgGradientColors(XQuantity_Color^ theColor1, XQuantity_Color^ theColor2, XAspect_GradientFillMethod theFillStyle, Standard_Boolean theToUpdate) {
        if (!mainView().IsNull()) {
            mainView()->SetBgGradientColors(*theColor1->GetColor(), *theColor2->GetColor(), safe_cast<Aspect_GradientFillMethod>(theFillStyle), theToUpdate);
        }
    }

    /// <summary>
    ///Erase objects（删除对象）
    /// </summary>
    void EraseObjects(void) {
        if (mainAISContext().IsNull()) {
            return;
        }

        mainAISContext()->EraseSelected(Standard_False);
        mainAISContext()->ClearSelected(Standard_True);
    }

    /// <summary>
    ///Get version （获取版本）
    /// </summary>
    Standard_Real GetOCCVersion(void) {
        return (Standard_Real)OCC_VERSION;
    }

    /// <summary>
    ///set material （设置材料）
    /// </summary>
    void SetMaterial(Standard_Integer theMaterial) {
        if (mainAISContext().IsNull()) {
            return;
        }
        for (mainAISContext()->InitSelected(); mainAISContext()->MoreSelected(); mainAISContext()->NextSelected()) {
            mainAISContext()->SetMaterial(mainAISContext()->SelectedInteractive(), (Graphic3d_NameOfMaterial)theMaterial, Standard_False);
        }
        mainAISContext()->UpdateCurrentViewer();
    }

    /// <summary>
    ///set transparency (设置透明度)
    /// </summary>
    void SetTransparency(Standard_Integer theTrans) {
        if (mainAISContext().IsNull()) {
            return;
        }
        for (mainAISContext()->InitSelected(); mainAISContext()->MoreSelected(); mainAISContext()->NextSelected()) {
            mainAISContext()->SetTransparency(mainAISContext()->SelectedInteractive(), ((Standard_Real)theTrans) / 10.0, Standard_False);
        }
        mainAISContext()->UpdateCurrentViewer();
    }

    /// <summary>
    ///Return true if object is selected （如果选择了对象，则返回true）
    /// </summary>
    bool IsObjectSelected(void) {
        if (mainAISContext().IsNull()) {
            return false;
        }
        mainAISContext()->InitSelected();
        return mainAISContext()->MoreSelected() != Standard_False;
    }

    /// <summary>
    ///Return display mode   (返回显示模式)
    /// </summary>
    Standard_Integer DisplayMode(void) {
        if (mainAISContext().IsNull()) {
            return -1;
        }
        Standard_Integer aMode = -1;
        bool OneOrMoreInShading = false;
        bool OneOrMoreInWireframe = false;
        for (mainAISContext()->InitSelected(); mainAISContext()->MoreSelected(); mainAISContext()->NextSelected()) {
            if (mainAISContext()->IsDisplayed(mainAISContext()->SelectedInteractive(), 1)) {
                OneOrMoreInShading = true;
            }
            if (mainAISContext()->IsDisplayed(mainAISContext()->SelectedInteractive(), 0)) {
                OneOrMoreInWireframe = true;
            }
        }
        if (OneOrMoreInShading && OneOrMoreInWireframe) {
            aMode = 10;
        }
        else if (OneOrMoreInShading) {
            aMode = 1;
        }
        else if (OneOrMoreInWireframe) {
            aMode = 0;
        }

        return aMode;
    }

    /// <summary>
    ///Create new view
    /// </summary>
    /// <param name="theWnd">System.IntPtr that contains the window handle (HWND) of the control</param>
    void CreateNewView(System::IntPtr theWnd) {
        if (mainAISContext().IsNull()) {
            return;
        }
        mainView() = mainAISContext()->CurrentViewer()->CreateView();
        if (mainGraphicDriver().IsNull()) {
            mainGraphicDriver() = new OpenGl_GraphicDriver(Handle(Aspect_DisplayConnection)());
        }
        Handle(WNT_Window) aWNTWindow = new WNT_Window(reinterpret_cast<HWND> (theWnd.ToPointer()));
        mainView()->SetWindow(aWNTWindow);
        Standard_Integer w = 100, h = 100;
        aWNTWindow->Size(w, h);
        if (!aWNTWindow->IsMapped()) {
            aWNTWindow->Map();
        }
    }

    //! Must be called when the window supporting the
    //! view changes size.
    //! if the view is not mapped on a window.
    //! Warning: The view is centered and resized to preserve
    //! the height/width ratio of the window.
    void SetMustBeResized() {
        mainView()->MustBeResized();
    }


#pragma endregion

#pragma region AISContext
    /// <summary>
    ///Set AISContext
    /// </summary>
    bool SetAISContext(OCCTProxy^ theViewer) {
        this->mainAISContext() = theViewer->GetContext();
        if (mainAISContext().IsNull()) {
            return false;
        }
        return true;
    }

    /// <summary>
    ///Get AISContext
    /// </summary>
    Handle(AIS_InteractiveContext) GetContext(void) {
        return mainAISContext();
    }

    /// <summary>
     ///Get AISContext
     /// </summary>
    XAIS_InteractiveContext^ GetInteractiveContext(void)
    {
        return gcnew XAIS_InteractiveContext(mainAISContext());
    }

    /// <summary>
    ///Get V3d_View
    /// </summary>
    XV3d_View^ GetV3dView(void) {
        return gcnew XV3d_View(mainView());
    }

#pragma endregion

public:
    // ============================================
    // Import / export functionality
    // ============================================
    #pragma region  Import / export functionality
    /// <summary>
    ///Import BRep file
    /// </summary>
    /// <param name="theFileName">Name of import file</param>
    bool ImportBrep(System::String^ theFileName) {
        return ImportBrep(toAsciiString(theFileName));
    }

    /// <summary>
    ///Import BRep file
    /// </summary>
    /// <param name="theFileName">Name of import file</param>
    bool ImportBrep(const TCollection_AsciiString& theFileName) {
        TopoDS_Shape aShape;
        BRep_Builder aBuilder;
        Standard_Boolean isResult = BRepTools::Read(aShape, theFileName.ToCString(), aBuilder);
        if (!isResult) {
            return false;
        }

        mainAISContext()->Display(new AIS_Shape(aShape), Standard_True);
        return true;
    }

    /// <summary>
    ///Import Step file
    /// </summary>
    /// <param name="theFileName">Name of import file</param>
    bool ImportStep(const TCollection_AsciiString& theFileName) {
        STEPControl_Reader aReader;
        IFSelect_ReturnStatus aStatus = aReader.ReadFile(theFileName.ToCString());
        if (aStatus == IFSelect_RetDone) {
            bool isFailsonly = false;
            aReader.PrintCheckLoad(isFailsonly, IFSelect_ItemsByEntity);

            Standard_Integer aNbRoot = aReader.NbRootsForTransfer();
            aReader.PrintCheckTransfer(isFailsonly, IFSelect_ItemsByEntity);
            for (Standard_Integer n = 1; n <= aNbRoot; n++) {
                Standard_Boolean ok = aReader.TransferRoot(n);
                Standard_Integer aNbShap = aReader.NbShapes();
                if (aNbShap > 0) {
                    for (Standard_Integer i = 1; i <= aNbShap; i++) {
                        TopoDS_Shape aShape = aReader.Shape(i);
                        mainAISContext()->Display(new AIS_Shape(aShape), Standard_False);
                    }
                    mainAISContext()->UpdateCurrentViewer();
                }
            }
        }
        else {
            return false;
        }

        return true;
    }

    /// <summary>
    /// Import Step file
    /// </summary>
    /// <param name="theFileName">Name of import file</param>
    /// <param name="ColorMode">default: Standard_True</param>
    /// <param name="NameMode">default: Standard_True</param>
    /// <param name="LayerMode">default: Standard_True</param>
    /// <param name="PropsMode">default: Standard_True</param>
    /// <param name="SHUOMode">default: Standard_False</param>
    /// <param name="GDTMode">default: Standard_True</param>
    /// <param name="ViewMode">default: Standard_True</param>
    /// <returns></returns>
    bool ImportStep(const TCollection_AsciiString& theFileName, Boolean ColorMode, Boolean NameMode, Boolean LayerMode, Boolean PropsMode, Boolean SHUOMode, Boolean GDTMode, Boolean ViewMode) {
        STEPCAFControl_Reader aReader;
        aReader.SetColorMode(ColorMode);
        aReader.SetNameMode(NameMode);
        /*aReader.SetLayerMode(LayerMode);
        aReader.SetPropsMode(PropsMode);
        aReader.SetSHUOMode(SHUOMode);
        aReader.SetGDTMode(GDTMode);
        aReader.SetViewMode(ViewMode);*/
        IFSelect_ReturnStatus aStatus = IFSelect_RetVoid;
        aStatus = aReader.ReadFile(theFileName.ToCString());
        //Handle(TDocStd_Document) aDoc = new TDocStd_Document("XSEFSTEP");
        Handle(TDocStd_Document) aDoc;
        Handle(XCAFApp_Application) anApp = XCAFApp_Application::GetApplication();
        anApp->NewDocument("XSEFSTEP", aDoc);
        if (aStatus != IFSelect_RetDone || !aReader.Transfer(aDoc)) {
            return false;
        }
        TDF_Label aRootLabel = aDoc->Main();
        visit(aRootLabel, Standard_True);
        return true;
    }
    bool ImportStepB(const TCollection_AsciiString& theFileName, Boolean ColorMode, Boolean NameMode, Boolean LayerMode, Boolean PropsMode, Boolean SHUOMode, Boolean GDTMode, Boolean ViewMode) {
        Handle(TDocStd_Document) aDoc;
        STEPCAFControl_Reader aReader;
        aReader.SetColorMode(ColorMode);
        aReader.SetNameMode(NameMode);
        IFSelect_ReturnStatus aStatus = IFSelect_RetVoid;
        aStatus = aReader.ReadFile(theFileName.ToCString());
        Handle(XCAFApp_Application) anApp = XCAFApp_Application::GetApplication();
        anApp->NewDocument("XSEFSTEP", aDoc);
        if (aStatus != IFSelect_RetDone || !aReader.Transfer(aDoc)) {
            return false;
        }
        Handle(XCAFDoc_ShapeTool) Assembly = XCAFDoc_DocumentTool::ShapeTool(aDoc->Main());
        TDF_LabelSequence aRootLabels;
        //Assembly->GetShapes(aRootLabels);
        Assembly->GetFreeShapes(aRootLabels);
        for (TDF_LabelSequence::Iterator aRootIter(aRootLabels); aRootIter.More(); aRootIter.Next())
        {
           const TDF_Label& aRootLabel = aRootIter.Value();
           visitB(aRootLabel, true);
        }
        return true;
    }
    /// <summary>
    /// 遍历结构
    /// </summary>
    /// <param name="theLabel"></param>
    /// <param name="IsBoundaryDraw"></param>
    void visit(const TDF_Label& theLabel, Standard_Boolean IsBoundaryDraw)
    {
        //Handle(TDataStd_Name) aName;
        //if (theLabel.FindAttribute(TDataStd_Name::GetID(), aName)) {
        //    std::cout << "  Name: " << aName->Get() << std::endl;
        //}
        if (!theLabel.HasChild()) {
            Display(theLabel, IsBoundaryDraw);
            return;
        }
        TDF_ChildIterator iter;
        for (iter.Initialize(theLabel, Standard_False); iter.More(); iter.Next()) {
            if (iter.Value().IsNull())
                continue;
            visit(iter.Value(), IsBoundaryDraw);
        }
    }
    /// <summary>
    /// 遍历结构
    /// </summary>
    /// <param name="theLabel"></param>
    /// <param name="IsBoundaryDraw"></param>
    void visitB(const TDF_Label& theLabel,Standard_Boolean IsBoundaryDraw)
    {
        if (!theLabel.IsNull() && !theLabel.HasChild()) {
            Display(theLabel, IsBoundaryDraw);
            return;
        }
        TDF_ChildIterator iter;
        for (iter.Initialize(theLabel, Standard_False); iter.More(); iter.Next()) {
            visit(iter.Value(), IsBoundaryDraw);
        }
    }
    /// <summary>
    /// 显示图形
    /// </summary>
    /// <param name="theLabel"></param>
    /// <param name="IsBoundaryDraw"></param>
    void Display(const TDF_Label& theLabel, Standard_Boolean IsBoundaryDraw) {
        Handle(TDataStd_Name) aName;
        if (theLabel.FindAttribute(TDataStd_Name::GetID(), aName)) {
            //std::cout << "  Name: " << aName->Get() << std::endl;
        }
        Handle(TPrsStd_AISPresentation) aPrs;
        if (!theLabel.FindAttribute(TPrsStd_AISPresentation::GetID(), aPrs)) {
            aPrs = TPrsStd_AISPresentation::Set(theLabel, XCAFPrs_Driver::GetID());
            aPrs->SetMaterial(Graphic3d_NOM_PLASTIC);
            aPrs->Display(Standard_True);

            Handle(AIS_InteractiveObject) anInteractive = aPrs->GetAIS();
            if (!anInteractive.IsNull()) {
                // get drawer
                const Handle(Prs3d_Drawer)& aDrawer = anInteractive->Attributes();
                // default attributes
                Standard_Real aRed = 0.0;
                Standard_Real aGreen = 0.0;
                Standard_Real aBlue = 0.0;
                Standard_Real aWidth = 1.0;
                Aspect_TypeOfLine aLineType = Aspect_TOL_SOLID;
                // turn boundaries on/off
                Standard_Boolean isBoundaryDraw = Standard_True;
                aDrawer->SetFaceBoundaryDraw(isBoundaryDraw);
                Quantity_Color aColor(aRed, aGreen, aBlue, Quantity_TOC_RGB);
                Handle(Prs3d_LineAspect) aBoundaryAspect = new Prs3d_LineAspect(aColor, aLineType, aWidth);
                aDrawer->SetFaceBoundaryAspect(aBoundaryAspect);
                mainAISContext()->Display(anInteractive, Standard_True);
            }
            //mainAISContext()->UpdateCurrentViewer();
        }
    }


    /// <summary>
    ///Import Iges file
    /// </summary>
    /// <param name="theFileName">Name of import file</param>
    bool ImportIges(const TCollection_AsciiString& theFileName) {
        IGESControl_Reader aReader;
        Standard_Integer aStatus = aReader.ReadFile(theFileName.ToCString());

        if (aStatus == IFSelect_RetDone) {
            aReader.TransferRoots();
            TopoDS_Shape aShape = aReader.OneShape();
            mainAISContext()->Display(new AIS_Shape(aShape), Standard_False);
        }
        else {
            return false;
        }

        mainAISContext()->UpdateCurrentViewer();
        return true;
    }

    /// <summary>
    ///Export BRep file
    /// </summary>
    /// <param name="theFileName">Name of export file</param>
    bool ExportBRep(const TCollection_AsciiString& theFileName) {
        mainAISContext()->InitSelected();
        if (!mainAISContext()->MoreSelected()) {
            return false;
        }

        Handle(AIS_InteractiveObject) anIO = mainAISContext()->SelectedInteractive();
        Handle(AIS_Shape) anIS = Handle(AIS_Shape)::DownCast(anIO);
        return BRepTools::Write(anIS->Shape(), theFileName.ToCString()) != Standard_False;
    }

    /// <summary>
    ///Export Step file
    /// </summary>
    /// <param name="theFileName">Name of export file</param>
    bool ExportStep(const TCollection_AsciiString& theFileName) {
        STEPControl_StepModelType aType = STEPControl_AsIs;
        IFSelect_ReturnStatus aStatus;
        STEPControl_Writer aWriter;
        for (mainAISContext()->InitSelected(); mainAISContext()->MoreSelected(); mainAISContext()->NextSelected()) {
            Handle(AIS_InteractiveObject) anIO = mainAISContext()->SelectedInteractive();
            Handle(AIS_Shape) anIS = Handle(AIS_Shape)::DownCast(anIO);
            TopoDS_Shape aShape = anIS->Shape();
            aStatus = aWriter.Transfer(aShape, aType);
            if (aStatus != IFSelect_RetDone) {
                return false;
            }
        }

        aStatus = aWriter.Write(theFileName.ToCString());
        if (aStatus != IFSelect_RetDone) {
            return false;
        }

        return true;
    }

    /// <summary>
    ///Export Iges file
    /// </summary>
    /// <param name="theFileName">Name of export file</param>
    bool ExportIges(const TCollection_AsciiString& theFileName) {
        IGESControl_Controller::Init();
        IGESControl_Writer aWriter(Interface_Static::CVal("XSTEP.iges.unit"),
            Interface_Static::IVal("XSTEP.iges.writebrep.mode"));

        for (mainAISContext()->InitSelected(); mainAISContext()->MoreSelected(); mainAISContext()->NextSelected()) {
            Handle(AIS_InteractiveObject) anIO = mainAISContext()->SelectedInteractive();
            Handle(AIS_Shape) anIS = Handle(AIS_Shape)::DownCast(anIO);
            TopoDS_Shape aShape = anIS->Shape();
            aWriter.AddShape(aShape);
        }

        aWriter.ComputeModel();
        return aWriter.Write(theFileName.ToCString()) != Standard_False;
    }

    /// <summary>
    ///Export Vrml file
    /// </summary>
    /// <param name="theFileName">Name of export file</param>
    bool ExportVrml(const TCollection_AsciiString& theFileName) {
        TopoDS_Compound aRes;
        BRep_Builder aBuilder;
        aBuilder.MakeCompound(aRes);

        for (mainAISContext()->InitSelected(); mainAISContext()->MoreSelected(); mainAISContext()->NextSelected()) {
            Handle(AIS_InteractiveObject) anIO = mainAISContext()->SelectedInteractive();
            Handle(AIS_Shape) anIS = Handle(AIS_Shape)::DownCast(anIO);
            TopoDS_Shape aShape = anIS->Shape();
            if (aShape.IsNull()) {
                return false;
            }

            aBuilder.Add(aRes, aShape);
        }

        VrmlAPI_Writer aWriter;
        aWriter.Write(aRes, theFileName.ToCString());

        return true;
    }

    /// <summary>
    ///Export Stl file
    /// </summary>
    /// <param name="theFileName">Name of export file</param>
    bool ExportStl(const TCollection_AsciiString& theFileName) {
        TopoDS_Compound aComp;
        BRep_Builder aBuilder;
        aBuilder.MakeCompound(aComp);

        for (mainAISContext()->InitSelected(); mainAISContext()->MoreSelected(); mainAISContext()->NextSelected()) {
            Handle(AIS_InteractiveObject) anIO = mainAISContext()->SelectedInteractive();
            Handle(AIS_Shape) anIS = Handle(AIS_Shape)::DownCast(anIO);
            TopoDS_Shape aShape = anIS->Shape();
            if (aShape.IsNull()) {
                return false;
            }
            aBuilder.Add(aComp, aShape);
        }

        StlAPI_Writer aWriter;
        aWriter.Write(aComp, theFileName.ToCString());
        return true;
    }

    /// <summary>
    ///Define which Import/Export function must be called
    /// </summary>
    /// <param name="theFileName">Name of Import/Export file</param>
    /// <param name="theFormat">Determines format of Import/Export file</param>
    /// <param name="theIsImport">Determines is Import or not</param>
    bool TranslateModel(System::String^ theFileName, Standard_Integer theFormat, bool theIsImport) {
        bool isResult;

        const TCollection_AsciiString aFilename = toAsciiString(theFileName);
        if (theIsImport) {
            switch (theFormat) {
            case 0:
                isResult = ImportBrep(aFilename);
                break;
            case 1:
                isResult = ImportStepB(aFilename, true, true, true, true, false, true, true);// ImportStep(aFilename);
                break;
            case 2:
                isResult = ImportIges(aFilename);
                break;
            default:
                isResult = false;
            }
        }
        else {
            switch (theFormat) {
            case 0:
                isResult = ExportBRep(aFilename);
                break;
            case 1:
                isResult = ExportStep(aFilename);
                break;
            case 2:
                isResult = ExportIges(aFilename);
                break;
            case 3:
                isResult = ExportVrml(aFilename);
                break;
            case 4:
                isResult = ExportStl(aFilename);
                break;
            case 5:
                isResult = Dump(aFilename);
                break;
            default:
                isResult = false;
            }
        }
        return isResult;
    }

    #pragma endregion

    /// <summary>
    ///Initialize OCCTProxy
    /// </summary>
    void InitOCCTProxy(void) {
        mainGraphicDriver() = NULL;
        mainViewer() = NULL;
        mainView() = NULL;
        mainAISContext() = NULL;
    }

private:

    NCollection_Haft<Handle(V3d_Viewer)>             mainViewer;
    NCollection_Haft<Handle(V3d_View)>               mainView;
    NCollection_Haft<Handle(AIS_InteractiveContext)> mainAISContext;
    NCollection_Haft<Handle(OpenGl_GraphicDriver)>   mainGraphicDriver;
    NCollection_Haft<Handle(Graphic3d_AspectText3d)> m_hLayer;
};
