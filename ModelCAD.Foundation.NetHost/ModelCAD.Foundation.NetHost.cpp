#include <d3d9.h>
#include <windows.h>

// include required OCCT headers
#include <Standard_Version.hxx>
#include <Message_ProgressIndicator.hxx>
//for OCC graphic
#include <WNT_Window.hxx>
#include <WNT_WClass.hxx>
#include <Graphic3d_CView.hxx>
#include <Graphic3d_Camera.hxx>
#include <Graphic3d_TextureParams.hxx>
#include <D3DHost_GraphicDriver.hxx>
#include <D3DHost_View.hxx>
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

// list of required OCCT libraries
#pragma comment(lib, "TKernel.lib")
#pragma comment(lib, "TKMath.lib")
#pragma comment(lib, "TKBRep.lib")
#pragma comment(lib, "TKXSBase.lib")
#pragma comment(lib, "TKService.lib")
#pragma comment(lib, "TKV3d.lib")
#pragma comment(lib, "TKOpenGl.lib")
#pragma comment(lib, "TKD3dHost.lib")
#pragma comment(lib, "TKIGES.lib")
#pragma comment(lib, "TKSTEP.lib")
#pragma comment(lib, "TKStl.lib")
#pragma comment(lib, "TKVrml.lib")
#pragma comment(lib, "TKLCAF.lib")

#pragma comment(lib, "D3D9.lib")

//! Auxiliary tool for converting C# string into UTF-8 string.
static TCollection_AsciiString toAsciiString (String^ theString)
{
  if (theString == nullptr)
  {
    return TCollection_AsciiString();
  }

  pin_ptr<const wchar_t> aPinChars = PtrToStringChars (theString);
  const wchar_t* aWCharPtr = aPinChars;
  if (aWCharPtr == NULL
  || *aWCharPtr == L'\0')
  {
    return TCollection_AsciiString();
  }
  return TCollection_AsciiString (aWCharPtr);
}

/// <summary>
/// Proxy class encapsulating calls to OCCT C++ classes within
/// C++/CLI class visible from .Net (CSharp)
/// </summary>
public ref class ModelCAD
{
public:

  ModelCAD() {}

  // ============================================
  // Viewer functionality
  // ============================================

  /// <summary>
  ///Initialize a viewer
  /// </summary>
  /// <param name="theWnd">System.IntPtr that contains the window handle (HWND) of the control</param>
  bool InitViewer()
  {
    mainGraphicDriver() = new D3DHost_GraphicDriver();
    mainGraphicDriver()->ChangeOptions().buffersNoSwap = true;
    //mainGraphicDriver()->ChangeOptions().contextDebug = true;

    mainViewer() = new V3d_Viewer (mainGraphicDriver());
    mainViewer()->SetDefaultLights();
    mainViewer()->SetLightOn();
    mainView() = mainViewer()->CreateView();

    static Handle(WNT_WClass) aWClass = new WNT_WClass ("OCC_Viewer", NULL, CS_OWNDC);
    Handle(WNT_Window) aWNTWindow = new WNT_Window ("OCC_Viewer", aWClass, WS_POPUP, 64, 64, 64, 64);
    aWNTWindow->SetVirtual (Standard_True);
    mainView()->SetWindow(aWNTWindow);
    mainAISContext() = new AIS_InteractiveContext (mainViewer());
    mainAISContext()->UpdateCurrentViewer();
    mainView()->MustBeResized();
    return true;
  }

  /// <summary> Resizes custom FBO for Direct3D output. </summary>
  System::IntPtr ResizeBridgeFBO (int theWinSizeX,
                                  int theWinSizeY)
  {
    Handle(WNT_Window) aWNTWindow = Handle(WNT_Window)::DownCast (mainView()->Window());
    aWNTWindow->SetPos (0, 0, theWinSizeX, theWinSizeY);
    mainView()->MustBeResized();
    mainView()->Invalidate();
    return System::IntPtr(Handle(D3DHost_View)::DownCast (mainView()->View())->D3dColorSurface());
  }

  /// <summary>
  /// Make dump of current view to file
  /// </summary>
  /// <param name="theFileName">Name of dump file</param>
  bool Dump (const TCollection_AsciiString& theFileName)
  {
    if (mainView().IsNull())
    {
      return false;
    }
    mainView()->Redraw();
    return mainView()->Dump (theFileName.ToCString()) != Standard_False;
  }

  /// <summary>
  ///Redraw view
  /// </summary>
  void RedrawView()
  {
    if (!mainView().IsNull())
    {
      mainView()->Redraw();
    }
  }

  /// <summary>
  ///Update view
  /// </summary>
  void UpdateView(void)
  {
    if (!mainView().IsNull())
    {
      mainView()->MustBeResized();
    }
  }

  /// <summary>
  ///Set computed mode in false
  /// </summary>
  void SetDegenerateModeOn()
  {
    if (!mainView().IsNull())
    {
      mainView()->SetComputedMode (Standard_False);
      mainView()->Redraw();
    }
  }

  /// <summary>
  ///Set computed mode in true
  /// </summary>
  void SetDegenerateModeOff()
  {
    if (!mainView().IsNull())
    {
      mainView()->SetComputedMode (Standard_True);
      mainView()->Redraw();
    }
  }

  /// <summary>
  ///Fit all
  /// </summary>
  void WindowFitAll (int theXmin, int theYmin,
                     int theXmax, int theYmax)
  {
    if (!mainView().IsNull())
    {
      mainView()->WindowFitAll (theXmin, theYmin, theXmax, theYmax);
    }
  }

  /// <summary>
  ///Current place of window
  /// </summary>
  /// <param name="theZoomFactor">Current zoom</param>
  void Place (int theX, int theY, float theZoomFactor)
  {	
    Standard_Real aZoomFactor = theZoomFactor;
    if (!mainView().IsNull())
    {
      mainView()->Place (theX, theY, aZoomFactor);
    }
  }

  /// <summary>
  ///Set Zoom
  /// </summary>
  void Zoom (int theX1, int theY1, int theX2, int theY2)
  {
    if (!mainView().IsNull())
    {
      mainView()->Zoom (theX1, theY1, theX2, theY2);
    }
  }

  /// <summary>
  ///Set Pan
  /// </summary>
  void Pan (int theX, int theY)
  {
    if (!mainView().IsNull())
    {
      mainView()->Pan (theX, theY);
    }
  }

  /// <summary>
  ///Rotation
  /// </summary>
  void Rotation (int theX, int theY)
  {
    if (!mainView().IsNull())
    {
      mainView()->Rotation (theX, theY);
    }
  }

  /// <summary>
  ///Start rotation
  /// </summary>
  void StartRotation (int theX, int theY)
  {
    if (!mainView().IsNull())
    {
      mainView()->StartRotation (theX, theY);
    }
  }

  /// <summary>
  ///Select by rectangle
  /// </summary>
  void Select (int theX1, int theY1, int theX2, int theY2)
  {
    if (!mainAISContext().IsNull())
    {
      mainAISContext()->Select (theX1, theY1, theX2, theY2, mainView(), Standard_True);
    }
  }

  /// <summary>
  ///Select by click
  /// </summary>
  void Select()
  {
    if (!mainAISContext().IsNull())
    {
      mainAISContext()->Select (Standard_True);
    }
  }

  /// <summary>
  ///Move view
  /// </summary>
  void MoveTo (int theX, int theY)
  {
    if (!mainAISContext().IsNull() && !mainView().IsNull())
    {
      mainAISContext()->MoveTo (theX, theY, mainView(), Standard_True);
    }
  }

  /// <summary>
  ///Select by rectangle with pressed "Shift" key
  /// </summary>
  void ShiftSelect (int theX1, int theY1, int theX2, int theY2)
  {
    if (!mainAISContext().IsNull() && !mainView().IsNull())
    {
      mainAISContext()->ShiftSelect (theX1, theY1, theX2, theY2, mainView(), Standard_True);
    }
  }

  /// <summary>
  ///Select by "Shift" key
  /// </summary>
  void ShiftSelect()
  {
    if (!mainAISContext().IsNull())
    {
      mainAISContext()->ShiftSelect (Standard_True);
    }
  }

  /// <summary>
  ///Set background color
  /// </summary>
  void BackgroundColor (int& theRed, int& theGreen, int& theBlue)
  {
    if (!mainView().IsNull())
    {
      Quantity_Color aColor = mainView()->BackgroundColor();
      theRed   = (int )aColor.Red()   * 255;
      theGreen = (int )aColor.Green() * 255;
      theBlue  = (int )aColor.Blue()  * 255;
    }
  }

  /// <summary>
  ///Get background color Red
  /// </summary>
  int GetBGColR()
  {
    int anRgb[3];
    BackgroundColor (anRgb[0], anRgb[1], anRgb[2]);
    return anRgb[0];
  }

  /// <summary>
  ///Get background color Green
  /// </summary>
  int GetBGColG()
  {
    int anRgb[3];
    BackgroundColor (anRgb[0], anRgb[1], anRgb[2]);
    return anRgb[1];
  }

  /// <summary>
  ///Get background color Blue
  /// </summary>
  int GetBGColB()
  {
    int anRgb[3];
    BackgroundColor (anRgb[0], anRgb[1], anRgb[2]);
    return anRgb[2];
  }

  /// <summary>
  ///Update current viewer
  /// </summary>
  void UpdateCurrentViewer()
  {
    if (!mainAISContext().IsNull())
    {
      mainAISContext()->UpdateCurrentViewer();
    }
  }

  /// <summary>
  ///Front side
  /// </summary>
  void FrontView()
  {
    if (!mainView().IsNull())
    {
      mainView()->SetProj (V3d_Yneg);
    }
  }

  /// <summary>
  ///Top side
  /// </summary>
  void TopView()
  {
    if (!mainView().IsNull())
    {
      mainView()->SetProj (V3d_Zpos);
    }
  }

  /// <summary>
  ///Left side
  /// </summary>
  void LeftView()
  {
    if (!mainView().IsNull())
    {
      mainView()->SetProj (V3d_Xneg);
    }
  }

  /// <summary>
  ///Back side
  /// </summary>
  void BackView()
  {
    if (!mainView().IsNull())
    {
      mainView()->SetProj (V3d_Ypos);
    }
  }

  /// <summary>
  ///Right side
  /// </summary>
  void RightView()
  {
    if (!mainView().IsNull())
    {
      mainView()->SetProj (V3d_Xpos);
    }
  }

  /// <summary>
  ///Bottom side
  /// </summary>
  void BottomView()
  {
    if (!mainView().IsNull())
    {
      mainView()->SetProj (V3d_Zneg);
    }
  }

  /// <summary>
  ///Axo side
  /// </summary>
  void AxoView()
  {
    if (!mainView().IsNull())
    {
      mainView()->SetProj (V3d_XposYnegZpos);
    }
  }

  /// <summary>
  ///Scale
  /// </summary>
  float Scale()
  {
    return mainView().IsNull()
         ? -1.0f
         : float(mainView()->Scale());
  }

  /// <summary>
  ///Zoom in all view
  /// </summary>
  void ZoomAllView()
  {
    if (!mainView().IsNull())
    {
      mainView()->FitAll();
      mainView()->ZFitAll();
    }
  }

  /// <summary>
  ///Reset view
  /// </summary>
  void Reset()
  {
    if (!mainView().IsNull())
    {
      mainView()->Reset();
    }
  }

  /// <summary>
  ///Set display mode of objects
  /// </summary>
  /// <param name="theMode">Set current mode</param>
  void SetDisplayMode (int theMode)
  {
    if (mainAISContext().IsNull())
    {
      return;
    }

    AIS_DisplayMode aCurrentMode = theMode == 0
                                 ? AIS_WireFrame
                                 : AIS_Shaded;
    if (mainAISContext()->NbSelected() == 0)
    {
       mainAISContext()->SetDisplayMode (aCurrentMode, Standard_False);
    }
    else
    {
       for (mainAISContext()->InitSelected(); mainAISContext()->MoreSelected(); mainAISContext()->NextSelected())
       {
         mainAISContext()->SetDisplayMode (mainAISContext()->SelectedInteractive(), theMode, Standard_False);
       }
    }
    mainAISContext()->UpdateCurrentViewer();
  }

  /// <summary>
  ///Set color
  /// </summary>
  void SetColor (int theR, int theG, int theB)
  {
    if (mainAISContext().IsNull())
    {
      return;
    }

    Quantity_Color aCol (theR / 255.0, theG / 255.0, theB / 255.0, Quantity_TOC_RGB);
    for (; mainAISContext()->MoreSelected(); mainAISContext()->NextSelected())
    {
      mainAISContext()->SetColor (mainAISContext()->SelectedInteractive(), aCol, false);
    }
    mainAISContext()->UpdateCurrentViewer();
  }

  /// <summary>
  ///Get object color red
  /// </summary>
  int GetObjColR()
  {
    int anRgb[3];
    ObjectColor (anRgb[0], anRgb[1], anRgb[2]);
    return anRgb[0];
  }

  /// <summary>
  ///Get object color green
  /// </summary>
  int GetObjColG()
  {
    int anRgb[3];
    ObjectColor (anRgb[0], anRgb[1], anRgb[2]);
    return anRgb[1];
  }

  /// <summary>
  ///Get object color blue
  /// </summary>
  int GetObjColB()
  {
    int anRgb[3];
    ObjectColor (anRgb[0], anRgb[1], anRgb[2]);
    return anRgb[2];
  }

  /// <summary>
  ///Get object color R/G/B
  /// </summary>
  void ObjectColor (int& theRed, int& theGreen, int& theBlue)
  {
    if (mainAISContext().IsNull())
    {
      return;
    }

    theRed   = 255;
    theGreen = 255;
    theBlue  = 255;
    mainAISContext()->InitSelected();
    if (!mainAISContext()->MoreSelected())
    {
      return;
    }

    Handle(AIS_InteractiveObject) aCurrent = mainAISContext()->SelectedInteractive();
    if (aCurrent->HasColor())
    {
      Quantity_Color anObjCol;
      mainAISContext()->Color (aCurrent, anObjCol);
      theRed   = int(anObjCol.Red()   * 255.0);
      theGreen = int(anObjCol.Green() * 255.0);
      theBlue  = int(anObjCol.Blue()  * 255.0);
    }
  }

  /// <summary>
  ///Set background color R/G/B
  /// </summary>
  void SetBackgroundColor (int theRed, int theGreen, int theBlue)
  {
    if (!mainView().IsNull())
    {
      mainView()->SetBackgroundColor (Quantity_TOC_RGB, theRed / 255.0, theGreen / 255.0, theBlue / 255.0);
    }
  }

  /// <summary>
  ///Erase objects
  /// </summary>
  void EraseObjects()
  {
    if (mainAISContext().IsNull())
    {
      return;
    }

    mainAISContext()->EraseSelected (Standard_False);
    mainAISContext()->ClearSelected (Standard_True);
  }

  /// <summary>
  ///Get version
  /// </summary>
  float GetOCCVersion()
  {
    return (float )OCC_VERSION;
  }

  /// <summary>
  ///set material
  /// </summary>
  void SetMaterial (int theMaterial)
  {
    if (mainAISContext().IsNull())
    {
      return;
    }
    for (mainAISContext()->InitSelected(); mainAISContext()->MoreSelected(); mainAISContext()->NextSelected())
    {
      mainAISContext()->SetMaterial (mainAISContext()->SelectedInteractive(), (Graphic3d_NameOfMaterial )theMaterial, Standard_False);
    }
    mainAISContext()->UpdateCurrentViewer();
  }

  /// <summary>
  ///set transparency
  /// </summary>
  void SetTransparency (int theTrans)
  {
    if (mainAISContext().IsNull())
    {
      return;
    }
    for (mainAISContext()->InitSelected(); mainAISContext()->MoreSelected(); mainAISContext()->NextSelected())
    {
      mainAISContext()->SetTransparency (mainAISContext()->SelectedInteractive(), ((Standard_Real )theTrans) / 10.0, Standard_False);
    }
    mainAISContext()->UpdateCurrentViewer();
  }

  /// <summary>
  ///Return true if object is selected
  /// </summary>
  bool IsObjectSelected()
  {
    if (mainAISContext().IsNull())
    {
      return false;
    }
    mainAISContext()->InitSelected();
    return mainAISContext()->MoreSelected() != Standard_False;
  }

  /// <summary>
  ///Return display mode
  /// </summary>
  int DisplayMode()
  {
    if (mainAISContext().IsNull())
    {
      return -1;
    }

    bool isOneOrMoreInShading   = false;
    bool isOneOrMoreInWireframe = false;
    for (mainAISContext()->InitSelected(); mainAISContext()->MoreSelected(); mainAISContext()->NextSelected())
    {
      if (mainAISContext()->IsDisplayed (mainAISContext()->SelectedInteractive(), AIS_Shaded))
      {
        isOneOrMoreInShading = true;
      }
      if (mainAISContext()->IsDisplayed (mainAISContext()->SelectedInteractive(), AIS_WireFrame))
      {
        isOneOrMoreInWireframe = true;
      }
    }
    if (isOneOrMoreInShading
     && isOneOrMoreInWireframe)
    {
      return 10;
    }
    else if (isOneOrMoreInShading)
    {
      return 1;
    }
    else if (isOneOrMoreInWireframe)
    {
      return 0;
    }
    return -1;
  }

  /// <summary>
  ///Set AISContext
  /// </summary>
  bool SetAISContext (ModelCAD^ theViewer)
  {
     this->mainAISContext() = theViewer->GetContext();
     if (mainAISContext().IsNull())
     {
       return false;
     }
    return true;
  }

  /// <summary>
  ///Get AISContext
  /// </summary>
  Handle(AIS_InteractiveContext) GetContext()
  {
    return mainAISContext();
  }

public:
  // ============================================
  // Import / export functionality
  // ============================================

  /// <summary>
  ///Import BRep file
  /// </summary>
  /// <param name="theFileName">Name of import file</param>
  bool ImportBrep (System::String^ theFileName)
  {
    return ImportBrep (toAsciiString (theFileName));
  }

  /// <summary>
  ///Import BRep file
  /// </summary>
  /// <param name="theFileName">Name of import file</param>
  bool ImportBrep (const TCollection_AsciiString& theFileName)
  {
    TopoDS_Shape aShape;
    BRep_Builder aBuilder;
    if (!BRepTools::Read (aShape, theFileName.ToCString(), aBuilder))
    {
      return false;
    }

    Handle(AIS_Shape) aPrs = new AIS_Shape (aShape);
    mainAISContext()->SetMaterial   (aPrs, Graphic3d_NOM_GOLD, Standard_False);
    mainAISContext()->SetDisplayMode(aPrs, AIS_Shaded, Standard_False);
    mainAISContext()->Display (aPrs, Standard_True);
    return true;
  }

  /// <summary>
  ///Import Step file
  /// </summary>
  /// <param name="theFileName">Name of import file</param>
  bool ImportStep (const TCollection_AsciiString& theFileName)
  {
    STEPControl_Reader aReader;
    if (aReader.ReadFile (theFileName.ToCString()) != IFSelect_RetDone)
    {
      return false;
    }

    bool isFailsonly = false;
    aReader.PrintCheckLoad( isFailsonly, IFSelect_ItemsByEntity );

    int aNbRoot = aReader.NbRootsForTransfer();
    aReader.PrintCheckTransfer (isFailsonly, IFSelect_ItemsByEntity);
    for (Standard_Integer aRootIter = 1; aRootIter <= aNbRoot; ++aRootIter)
    {
      aReader.TransferRoot (aRootIter);
      int aNbShap = aReader.NbShapes();
      if (aNbShap > 0)
      {
        for (int aShapeIter = 1; aShapeIter <= aNbShap; ++aShapeIter)
        {
          mainAISContext()->Display (new AIS_Shape (aReader.Shape (aShapeIter)), Standard_False);
        }
        mainAISContext()->UpdateCurrentViewer();
      }
    }
    return true;
  }

  /// <summary>
  ///Import Iges file
  /// </summary>
  /// <param name="theFileName">Name of import file</param>
  bool ImportIges (const TCollection_AsciiString& theFileName)
  {
    IGESControl_Reader aReader;
    if (aReader.ReadFile (theFileName.ToCString()) != IFSelect_RetDone)
    {
      return false;
    }

    aReader.TransferRoots();
    TopoDS_Shape aShape = aReader.OneShape();
    mainAISContext()->Display (new AIS_Shape (aShape), Standard_False);
    mainAISContext()->UpdateCurrentViewer();
    return true;
  }

  /// <summary>
  ///Export BRep file
  /// </summary>
  /// <param name="theFileName">Name of export file</param>
  bool ExportBRep (const TCollection_AsciiString& theFileName)
  {
    mainAISContext()->InitSelected();
    if (!mainAISContext()->MoreSelected())
    {
      return false;
    }

    Handle(AIS_Shape) anIS = Handle(AIS_Shape)::DownCast (mainAISContext()->SelectedInteractive());
    return !anIS.IsNull()
         && BRepTools::Write (anIS->Shape(), theFileName.ToCString());
  }

  /// <summary>
  ///Export Step file
  /// </summary>
  /// <param name="theFileName">Name of export file</param>
  bool ExportStep (const TCollection_AsciiString& theFileName)
  {
    STEPControl_StepModelType aType = STEPControl_AsIs;
    STEPControl_Writer        aWriter;
    for (mainAISContext()->InitSelected(); mainAISContext()->MoreSelected(); mainAISContext()->NextSelected())
    {
      Handle(AIS_Shape) anIS = Handle(AIS_Shape)::DownCast (mainAISContext()->SelectedInteractive());
      if (anIS.IsNull())
      {
        return false;
      }

      TopoDS_Shape aShape = anIS->Shape();
      if (aWriter.Transfer (aShape, aType) != IFSelect_RetDone)
      {
        return false;
      }
    }
    return aWriter.Write (theFileName.ToCString()) == IFSelect_RetDone;
  }

  /// <summary>
  ///Export Iges file
  /// </summary>
  /// <param name="theFileName">Name of export file</param>
  bool ExportIges (const TCollection_AsciiString& theFileName)
  {
    IGESControl_Controller::Init();
    IGESControl_Writer aWriter (Interface_Static::CVal ("XSTEP.iges.unit"),
                                Interface_Static::IVal ("XSTEP.iges.writebrep.mode"));
    for (mainAISContext()->InitSelected(); mainAISContext()->MoreSelected(); mainAISContext()->NextSelected())
    {
      Handle(AIS_Shape) anIS = Handle(AIS_Shape)::DownCast (mainAISContext()->SelectedInteractive());
      if (anIS.IsNull())
      {
        return false;
      }

      aWriter.AddShape (anIS->Shape());
    }

    aWriter.ComputeModel();
    return aWriter.Write (theFileName.ToCString()) != Standard_False;
  }

  /// <summary>
  ///Export Vrml file
  /// </summary>
  /// <param name="theFileName">Name of export file</param>
  bool ExportVrml (const TCollection_AsciiString& theFileName)
  {
    TopoDS_Compound aRes;
    BRep_Builder    aBuilder;
    aBuilder.MakeCompound (aRes);
    for (mainAISContext()->InitSelected(); mainAISContext()->MoreSelected(); mainAISContext()->NextSelected())
    {
      Handle(AIS_Shape) anIS = Handle(AIS_Shape)::DownCast (mainAISContext()->SelectedInteractive());
      if (anIS.IsNull())
      {
        return false;
      }
      aBuilder.Add (aRes, anIS->Shape());
    }

    VrmlAPI_Writer aWriter;
    aWriter.Write (aRes, theFileName.ToCString());
    return true;
  }

  /// <summary>
  ///Export Stl file
  /// </summary>
  /// <param name="theFileName">Name of export file</param>
  bool ExportStl (const TCollection_AsciiString& theFileName)
  {
    TopoDS_Compound aComp;
    BRep_Builder    aBuilder;
    aBuilder.MakeCompound (aComp);
    for (mainAISContext()->InitSelected(); mainAISContext()->MoreSelected(); mainAISContext()->NextSelected())
    {
      Handle(AIS_Shape) anIS = Handle(AIS_Shape)::DownCast (mainAISContext()->SelectedInteractive());
      if (anIS.IsNull())
      {
        return false;
      }
      aBuilder.Add (aComp, anIS->Shape());
    }

    StlAPI_Writer aWriter;
    aWriter.Write (aComp, theFileName.ToCString());
    return true;
  }

  /// <summary>
  ///Define which Import/Export function must be called
  /// </summary>
  /// <param name="theFileName">Name of Import/Export file</param>
  /// <param name="theFormat">Determines format of Import/Export file</param>
  /// <param name="theIsImport">Determines is Import or not</param>
  bool TranslateModel (System::String^ theFileName, int theFormat, bool theIsImport)
  {
    bool  isResult  = false;
    const TCollection_AsciiString aFilename = toAsciiString (theFileName);
    if (theIsImport)
    {
      switch (theFormat)
      {
        case 0: isResult = ImportBrep  (aFilename); break;
        case 1: isResult = ImportStep  (aFilename); break;
        case 2: isResult = ImportIges  (aFilename); break;
      }
    }
    else 
    {
      switch (theFormat)
      {
        case 0: isResult = ExportBRep (aFilename); break;
        case 1: isResult = ExportStep (aFilename); break;
        case 2: isResult = ExportIges (aFilename); break;
        case 3: isResult = ExportVrml (aFilename); break;
        case 4: isResult = ExportStl  (aFilename); break;
        case 5: isResult = Dump (aFilename);      break;
      }
    }
    return isResult;
  }

  /// <summary>
  ///Initialize ModelCAD
  /// </summary>
  void InitOCCTProxy()
  {
    mainGraphicDriver().Nullify();
    mainViewer().Nullify();
    mainView().Nullify();
    mainAISContext().Nullify();
  }

private:

  NCollection_Haft<Handle(V3d_Viewer)>             mainViewer;
  NCollection_Haft<Handle(V3d_View)>               mainView;
  NCollection_Haft<Handle(AIS_InteractiveContext)> mainAISContext;
  NCollection_Haft<Handle(D3DHost_GraphicDriver)>  mainGraphicDriver;

};
