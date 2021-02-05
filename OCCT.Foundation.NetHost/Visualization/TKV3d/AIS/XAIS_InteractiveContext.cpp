#include <XAIS_InteractiveContext.h>

#include <AIS_DataMapIteratorOfDataMapOfIOStatus.hxx>
#include <AIS_ConnectedInteractive.hxx>
#include <AIS_GlobalStatus.hxx>
#include <AIS_InteractiveObject.hxx>
#include <AIS_ListIteratorOfListOfInteractive.hxx>
#include <AIS_MapIteratorOfMapOfInteractive.hxx>
#include <AIS_MultipleConnectedInteractive.hxx>
#include <AIS_Shape.hxx>
#include <AIS_Trihedron.hxx>
#include <Geom_Axis2Placement.hxx>
#include <Graphic3d_AspectFillArea3d.hxx>
#include <HLRBRep.hxx>
#include <OSD_Environment.hxx>
#include <Precision.hxx>
#include <Prs3d_BasicAspect.hxx>
#include <Prs3d_DatumAspect.hxx>
#include <Prs3d_IsoAspect.hxx>
#include <Prs3d_LineAspect.hxx>
#include <Prs3d_PlaneAspect.hxx>
#include <Prs3d_PointAspect.hxx>
#include <Prs3d_ShadingAspect.hxx>
#include <PrsMgr_PresentableObject.hxx>
#include <Quantity_Color.hxx>
#include <SelectMgr_EntityOwner.hxx>
#include <SelectMgr_Filter.hxx>
#include <SelectMgr_OrFilter.hxx>
#include <SelectMgr_SelectionManager.hxx>
#include <Standard_Atomic.hxx>
#include <Standard_Transient.hxx>
#include <Standard_Type.hxx>
#include <StdSelect_ViewerSelector3d.hxx>
#include <TCollection_AsciiString.hxx>
#include <TCollection_ExtendedString.hxx>
#include <TColStd_ListIteratorOfListOfInteger.hxx>
#include <TColStd_MapIteratorOfMapOfTransient.hxx>
#include <TopLoc_Location.hxx>
#include <TopoDS_Shape.hxx>
#include <UnitsAPI.hxx>
#include <V3d_View.hxx>
#include <V3d_Viewer.hxx>

namespace TKV3d {
    //=======================================================================
    //function : AIS_InteractiveContext
    //purpose  : 
    //=======================================================================

    XAIS_InteractiveContext::XAIS_InteractiveContext(XV3d_Viewer^ MainViewer)
    {
        NativeHandle() = new AIS_InteractiveContext(MainViewer->GetViewer());
    }

    //! Constructs the interactive context object defined by the principal viewer MainViewer.
    XAIS_InteractiveContext::XAIS_InteractiveContext(Handle(AIS_InteractiveContext) pos) {
        NativeHandle() = pos;
    };

    Handle(AIS_InteractiveContext)  XAIS_InteractiveContext::GetInteractiveContext() {
        return NativeHandle();
    };


    //=======================================================================
    //function : ~AIS_InteractiveContext
    //purpose  :
    //=======================================================================
    XAIS_InteractiveContext::~XAIS_InteractiveContext()
    {
        NativeHandle()->~AIS_InteractiveContext();
    }

    //=======================================================================
    //function : LastActiveView
    //purpose  :
    //=======================================================================
    XV3d_View^ XAIS_InteractiveContext::LastActiveView()
    {
        return gcnew XV3d_View(NativeHandle()->LastActiveView());
    }

    //! Returns the default attribute manager.
        //! This contains all the color and line attributes which can be used by interactive objects which do not have their own attributes.
    XPrs3d_Drawer^ XAIS_InteractiveContext::DefaultDrawer() {
        return gcnew XPrs3d_Drawer(NativeHandle()->DefaultDrawer());
    };

    //! Returns the current viewer.
    XV3d_Viewer^ XAIS_InteractiveContext::CurrentViewer() {
        return gcnew XV3d_Viewer(NativeHandle()->CurrentViewer());
    };

    Handle(SelectMgr_SelectionManager) XAIS_InteractiveContext::SelectionManager() {
        return NativeHandle()->SelectionManager();
    };

    Handle(PrsMgr_PresentationManager3d) XAIS_InteractiveContext::MainPrsMgr() {
        return NativeHandle()->MainPrsMgr();
    };

    Handle(StdSelect_ViewerSelector3d) XAIS_InteractiveContext::MainSelector() {
        return NativeHandle()->MainSelector();
    };

    //=======================================================================
    //function : UpdateCurrentViewer
    //purpose  : 
    //=======================================================================

    void XAIS_InteractiveContext::UpdateCurrentViewer()
    {
        NativeHandle()->UpdateCurrentViewer();
    }

    //=======================================================================
    //function : DisplayedObjects
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::DisplayedObjects(AIS_ListOfInteractive theListOfIO)
    {
        NativeHandle()->DisplayedObjects(theListOfIO);
    }

    //=======================================================================
    //function : DisplayedObjects
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::DisplayedObjects(XAIS_KindOfInteractive theKind, Standard_Integer theSign, AIS_ListOfInteractive theListOfIO)
    {
        ObjectsByDisplayStatus(theKind, theSign, XAIS_DisplayStatus(AIS_DS_Displayed), theListOfIO);
    };

    //=======================================================================
    //function : ErasedObjects
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::ErasedObjects(AIS_ListOfInteractive theListOfIO)
    {
        ObjectsByDisplayStatus(XAIS_DisplayStatus(AIS_DS_Erased), theListOfIO);
    };

    //=======================================================================
    //function : ErasedObjects
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::ErasedObjects(XAIS_KindOfInteractive theKind, Standard_Integer theSign, AIS_ListOfInteractive theListOfIO)
    {
        ObjectsByDisplayStatus(theKind, theSign, XAIS_DisplayStatus(AIS_DS_Erased), theListOfIO);
    };

    //=======================================================================
    //function : ObjectsByDisplayStatus
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::ObjectsByDisplayStatus(XAIS_DisplayStatus theStatus, AIS_ListOfInteractive theListOfIO)
    {
        NativeHandle()->ObjectsByDisplayStatus(safe_cast<AIS_DisplayStatus>(theStatus), theListOfIO);
    };

    //=======================================================================
    //function : ObjectsByDisplayStatus
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::ObjectsByDisplayStatus(XAIS_KindOfInteractive theKind, Standard_Integer theSign, XAIS_DisplayStatus theStatus, AIS_ListOfInteractive theListOfIO)
    {
        NativeHandle()->ObjectsByDisplayStatus(safe_cast<AIS_KindOfInteractive>(theKind), theSign, safe_cast<AIS_DisplayStatus>(theStatus), theListOfIO);
    };

    //=======================================================================
    //function : ObjectsInside
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::ObjectsInside(AIS_ListOfInteractive theListOfIO, XAIS_KindOfInteractive theKind, Standard_Integer theSign)
    {
        NativeHandle()->ObjectsInside(theListOfIO, safe_cast<AIS_KindOfInteractive>(theKind), theSign);
    };

    //=======================================================================
    //function : ObjectsForView
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::ObjectsForView(AIS_ListOfInteractive theListOfIO, XV3d_View^ theView, Standard_Boolean theIsVisibleInView, XAIS_DisplayStatus theStatus)
    {
        NativeHandle()->ObjectsForView(theListOfIO, theView->GetView(), theIsVisibleInView, safe_cast<AIS_DisplayStatus>(theStatus));
    };

    //=======================================================================
    //function : Display
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::Display(XAIS_InteractiveObject^ theIObj, Standard_Boolean theToUpdateViewer)
    {
        NativeHandle()->Display(theIObj->GetInteractiveObject(), theToUpdateViewer);
    };

    //=======================================================================
    //function : SetViewAffinity
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::SetViewAffinity(XAIS_InteractiveObject^ theIObj, XV3d_View^ theView, Standard_Boolean theIsVisible)
    {
        NativeHandle()->SetViewAffinity(theIObj->GetInteractiveObject(), theView->GetView(), theIsVisible);
    };

    //! Returns the Display Mode setting to be used by default.
    Standard_Integer XAIS_InteractiveContext::DisplayMode() {
        return NativeHandle()->DisplayMode();
    };

    //=======================================================================
    //function : Display
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::Display(XAIS_InteractiveObject^ theIObj, Standard_Integer theDispMode, Standard_Integer theSelectionMode, Standard_Boolean theToUpdateViewer, XAIS_DisplayStatus theDispStatus)
    {
        NativeHandle()->Display(theIObj->GetInteractiveObject(), theDispMode, theSelectionMode, theToUpdateViewer, safe_cast<AIS_DisplayStatus>(theDispStatus));
    };


    //=======================================================================
    //function : Load
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::Load(XAIS_InteractiveObject^ theIObj, Standard_Integer theSelMode)
    {
        NativeHandle()->Load(theIObj->GetInteractiveObject(), theSelMode);
    };

    //! Hides the object. The object's presentations are simply flagged as invisible and therefore excluded from redrawing.
        //! To show hidden objects, use Display().
    void XAIS_InteractiveContext::Erase(XAIS_InteractiveObject^ theIObj, Standard_Boolean theToUpdateViewer) {
        NativeHandle()->Erase(theIObj->GetInteractiveObject(), theToUpdateViewer);
    };

    //=======================================================================
    //function : EraseAll
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::EraseAll(Standard_Boolean theToUpdateViewer)
    {
        NativeHandle()->EraseAll(theToUpdateViewer);
    };

    //=======================================================================
    //function : DisplayAll
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::DisplayAll(Standard_Boolean theToUpdateViewer)
    {
        NativeHandle()->DisplayAll(theToUpdateViewer);
    };

    //=======================================================================
    //function : DisplaySelected
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::DisplaySelected(Standard_Boolean theToUpdateViewer)
    {
        NativeHandle()->DisplaySelected(theToUpdateViewer);
    };

    //! Empties the graphic presentation of the mode indexed by aMode.
        //! Warning! Removes theIObj. theIObj is still active if it was previously activated.
    void XAIS_InteractiveContext::ClearPrs(XAIS_InteractiveObject^ theIObj, Standard_Integer theMode, Standard_Boolean theToUpdateViewer) {
        NativeHandle()->ClearPrs(theIObj->GetInteractiveObject(), theMode, theToUpdateViewer);
    };


    //=======================================================================
    //function : EraseSelected
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::EraseSelected(Standard_Boolean theToUpdateViewer)
    {
        NativeHandle()->EraseSelected(theToUpdateViewer);
    };

    //=======================================================================
    //function : DisplayStatus
    //purpose  :
    //=======================================================================
    XAIS_DisplayStatus XAIS_InteractiveContext::DisplayStatus(XAIS_InteractiveObject^ theIObj)
    {
       return safe_cast<XAIS_DisplayStatus>(NativeHandle()->DisplayStatus(theIObj->GetInteractiveObject()));
    };


    //! Removes Object from every viewer.
    void XAIS_InteractiveContext::Remove(XAIS_InteractiveObject^ theIObj, Standard_Boolean theToUpdateViewer) {
        NativeHandle()->Remove(theIObj->GetInteractiveObject(), theToUpdateViewer);
    };

    //=======================================================================
    //function : RemoveAll
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::RemoveAll(Standard_Boolean theToUpdateViewer)
    {
        NativeHandle()->RemoveAll(theToUpdateViewer);
    };

    //=======================================================================
    //function : HilightWithColor
    //purpose  : 
    //=======================================================================
    void XAIS_InteractiveContext::HilightWithColor(XAIS_InteractiveObject^ theObj, XPrs3d_Drawer^ theStyle, Standard_Boolean theIsToUpdate)
    {
        NativeHandle()->HilightWithColor(theObj->GetInteractiveObject(), theStyle->GetDrawer(), theIsToUpdate);
    };

    //=======================================================================
    //function : Unhilight
    //purpose  : 
    //=======================================================================
    void XAIS_InteractiveContext::Unhilight(XAIS_InteractiveObject^ anIObj, Standard_Boolean updateviewer)
    {
        NativeHandle()->Unhilight(anIObj->GetInteractiveObject(), updateviewer);
    };

    //=======================================================================
    //function : IsHilighted
    //purpose  : Returns true if the objects global status is set to highlighted.
    //=======================================================================
    Standard_Boolean XAIS_InteractiveContext::IsHilighted(XAIS_InteractiveObject^ theObj)
    {
        return  NativeHandle()->IsHilighted(theObj->GetInteractiveObject());
    };

    //=======================================================================
    //function : IsHilighted
    //purpose  : Returns true if the owner is highlighted with selection style.
    //=======================================================================
    Standard_Boolean XAIS_InteractiveContext::IsHilighted(Handle(SelectMgr_EntityOwner) theOwner)
    {
        return  NativeHandle()->IsHilighted(theOwner);
    };

    //! Updates the display in the viewer to take dynamic detection into account.
        //! On dynamic detection by the mouse cursor, sensitive primitives are highlighted.
        //! The highlight color of entities detected by mouse movement is white by default.
    /*void XAIS_InteractiveContext::Hilight(XAIS_InteractiveObject^ theObj, Standard_Boolean theIsToUpdateViewer) {
        NativeHandle()->Hilight(theObj, theIsToUpdateViewer);
    };*/


    //=======================================================================
    //function : HighlightStyle
    //purpose  :
    //=======================================================================
    Standard_Boolean XAIS_InteractiveContext::HighlightStyle(XAIS_InteractiveObject^ theObj, XPrs3d_Drawer^ theStyle)
    {
        return  NativeHandle()->HighlightStyle(theObj->GetInteractiveObject(), theStyle->GetDrawer());
    };

    //=======================================================================
    //function : HighlightStyle
    //purpose  :
    //=======================================================================
    Standard_Boolean XAIS_InteractiveContext::HighlightStyle(Handle(SelectMgr_EntityOwner) theOwner, XPrs3d_Drawer^ theStyle)
    {
        return  NativeHandle()->HighlightStyle(theOwner, theStyle->GetDrawer());
    };

    //=======================================================================
    //function : IsDisplayed
    //purpose  : 
    //=======================================================================

    Standard_Boolean XAIS_InteractiveContext::IsDisplayed(XAIS_InteractiveObject^ theObj)
    {
        return  NativeHandle()->IsDisplayed(theObj->GetInteractiveObject());
    };

    //=======================================================================
    //function : IsDisplayed
    //purpose  :
    //=======================================================================
    Standard_Boolean XAIS_InteractiveContext::IsDisplayed(XAIS_InteractiveObject^ theIObj, Standard_Integer theMode)
    {
        return  NativeHandle()->IsDisplayed(theIObj->GetInteractiveObject(), theMode);
    };

    //! Enable or disable automatic activation of default selection mode while displaying the object.
    void XAIS_InteractiveContext::SetAutoActivateSelection(Standard_Boolean theIsAuto) {
        NativeHandle()->SetAutoActivateSelection(theIsAuto);
    };

    //! Manages displaying the new object should also automatically activate default selection mode; TRUE by default.
    Standard_Boolean XAIS_InteractiveContext::GetAutoActivateSelection() {
        return NativeHandle()->GetAutoActivateSelection();
    };

    //=======================================================================
    //function : DisplayPriority
    //purpose  :
    //=======================================================================
    Standard_Integer XAIS_InteractiveContext::DisplayPriority(XAIS_InteractiveObject^ theIObj)
    {
        return  NativeHandle()->DisplayPriority(theIObj->GetInteractiveObject());
    };

    //=======================================================================
    //function : SetDisplayPriority
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::SetDisplayPriority(XAIS_InteractiveObject^ theIObj, Standard_Integer thePriority)
    {
         NativeHandle()->SetDisplayPriority(theIObj->GetInteractiveObject(), thePriority);
    };

    //! Recomputes the seen parts presentation of the Object.
        //! If theAllModes equals true, all presentations are present in the object even if unseen.
    void XAIS_InteractiveContext::Redisplay(XAIS_InteractiveObject^ theIObj, Standard_Boolean theToUpdateViewer, Standard_Boolean theAllModes) {
        NativeHandle()->Redisplay(theIObj->GetInteractiveObject(), theToUpdateViewer, theAllModes);
    };

    //=======================================================================
    //function : Redisplay
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::Redisplay(XAIS_KindOfInteractive theKOI, Standard_Integer theSign, Standard_Boolean theToUpdateViewer)
    {
        NativeHandle()->Redisplay(safe_cast<AIS_KindOfInteractive>(theKOI), theSign, theToUpdateViewer);
    };

    //! Recomputes the displayed presentations, flags the others.
        //! Doesn't update presentations.
    void XAIS_InteractiveContext::RecomputePrsOnly(XAIS_InteractiveObject^ theIObj, Standard_Boolean theToUpdateViewer, Standard_Boolean theAllModes) {
        NativeHandle()->RecomputePrsOnly(theIObj->GetInteractiveObject(), theToUpdateViewer, theAllModes);
    };


    //! Recomputes the active selections, flags the others.
        //! Doesn't update presentations.
    void XAIS_InteractiveContext::RecomputeSelectionOnly(XAIS_InteractiveObject^ anIObj) {
        NativeHandle()->RecomputeSelectionOnly(anIObj->GetInteractiveObject());
    };

    //! Updates displayed interactive object by checking and recomputing its flagged as "to be recomputed" presentation and selection structures.
        //! This method does not force any recomputation on its own.
        //! The method recomputes selections even if they are loaded without activation in particular selector.
    void XAIS_InteractiveContext::Update(XAIS_InteractiveObject^ theIObj, Standard_Boolean theUpdateViewer) {
        NativeHandle()->Update(theIObj->GetInteractiveObject(), theUpdateViewer);
    };

    //! Returns highlight style settings.   enum:Prs3d_TypeOfHighlight
    XPrs3d_Drawer^ XAIS_InteractiveContext::HighlightStyle(XPrs3d_TypeOfHighlight theStyleType) {
       return gcnew XPrs3d_Drawer(NativeHandle()->HighlightStyle(safe_cast<Prs3d_TypeOfHighlight>(theStyleType)));
    };


    //! enum:Prs3d_TypeOfHighlight
    void XAIS_InteractiveContext::SetHighlightStyle(XPrs3d_TypeOfHighlight theStyleType, XPrs3d_Drawer^ theStyle) {
        NativeHandle()->SetHighlightStyle(safe_cast<Prs3d_TypeOfHighlight>(theStyleType), theStyle->GetDrawer());
    };

    //! Returns current dynamic highlight style settings.
    //! By default:
    //!   - the color of dynamic highlight is Quantity_NOC_CYAN1;
    //!   - the presentation for dynamic highlight is completely opaque;
    //!   - the type of highlight is Aspect_TOHM_COLOR.
    XPrs3d_Drawer^ XAIS_InteractiveContext::HighlightStyle() {
       return gcnew XPrs3d_Drawer(NativeHandle()->HighlightStyle());
    };

    void XAIS_InteractiveContext::SetHighlightStyle(XPrs3d_Drawer^ theStyle) {
        NativeHandle()->SetHighlightStyle(theStyle->GetDrawer());
    };

    //! Returns current selection style settings.
    //! By default:
    //!   - the color of selection is Quantity_NOC_GRAY80;
    //!   - the presentation for selection is completely opaque;
    //!   - the type of highlight is Aspect_TOHM_COLOR.
    XPrs3d_Drawer^ XAIS_InteractiveContext::SelectionStyle() {
        return gcnew XPrs3d_Drawer(NativeHandle()->SelectionStyle());
    };

    //! Setup the style of selection highlighting.
    void XAIS_InteractiveContext::SetSelectionStyle(XPrs3d_Drawer^ theStyle) {
        NativeHandle()->SetSelectionStyle(theStyle->GetDrawer());
    };

    //=======================================================================
    //function : SetLocation
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::SetLocation(XAIS_InteractiveObject^ theIObj, XTopLoc_Location^ theLoc)
    {
        NativeHandle()->SetLocation(theIObj->GetInteractiveObject(), *theLoc->GetLocation());
    };

    //=======================================================================
    //function : ResetLocation
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::ResetLocation(XAIS_InteractiveObject^ theIObj)
    {
        NativeHandle()->ResetLocation(theIObj->GetInteractiveObject());
    };

    //=======================================================================
    //function : HasLocation
    //purpose  :
    //=======================================================================
    Standard_Boolean XAIS_InteractiveContext::HasLocation(XAIS_InteractiveObject^ theIObj)
    {
        return NativeHandle()->HasLocation(theIObj->GetInteractiveObject());
    };

    //=======================================================================
    //function : Location
    //purpose  :
    //=======================================================================
    XTopLoc_Location^ XAIS_InteractiveContext::Location(XAIS_InteractiveObject^ theIObj)
    {
        return gcnew XTopLoc_Location(NativeHandle()->Location(theIObj->GetInteractiveObject()));
    };

    //=======================================================================
    //function : SetDeviationCoefficient
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::SetDeviationCoefficient(Standard_Real theCoefficient)
    {
        NativeHandle()->SetDeviationCoefficient(theCoefficient);
    };

    //=======================================================================
    //function : SetDeviationAngle
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::SetDeviationAngle(Standard_Real theAngle)
    {
        NativeHandle()->SetDeviationAngle(theAngle);
    };

    //=======================================================================
    //function : DeviationAngle
    //purpose  : Gets  deviationAngle
    //=======================================================================
    Standard_Real XAIS_InteractiveContext::DeviationAngle()
    {
        return NativeHandle()->DeviationAngle();
    };

    //=======================================================================
    //function : DeviationCoefficient
    //purpose  :
    //=======================================================================
    Standard_Real XAIS_InteractiveContext::DeviationCoefficient()
    {
        return NativeHandle()->DeviationCoefficient();
    };

    //=======================================================================
    //function : SetHLRDeviationCoefficient
    //purpose  :
    //=======================================================================
   /* void XAIS_InteractiveContext::SetHLRDeviationCoefficient(Standard_Real theCoefficient)
    {
        NativeHandle()->SetHLRDeviationCoefficient(theCoefficient);
    };*/

    //=======================================================================
    //function : HLRDeviationCoefficient
    //purpose  :
    //=======================================================================
    /*Standard_Real XAIS_InteractiveContext::HLRDeviationCoefficient()
    {
        return NativeHandle()->HLRDeviationCoefficient();
    };*/

    //=======================================================================
    //function : SetHLRAngle
    //purpose  :
    //=======================================================================
    /*void XAIS_InteractiveContext::SetHLRAngle(Standard_Real theAngle)
    {
        NativeHandle()->SetHLRAngle(theAngle);
    };*/

    //=======================================================================
    //function : SetHLRAngleAndDeviation
    //purpose  : compute with anangle a HLRAngle and a HLRDeviationCoefficient 
    //           and set them in myHLRAngle and in myHLRDeviationCoefficient
    //           of myDefaultDrawer 
    //=======================================================================
    /*void XAIS_InteractiveContext::SetHLRAngleAndDeviation(Standard_Real theAngle)
    {
        NativeHandle()->SetHLRAngleAndDeviation(theAngle);
    };*/

    //=======================================================================
    //function : HLRAngle
    //purpose  :
    //=======================================================================
    /*Standard_Real XAIS_InteractiveContext::HLRAngle()
    {
        return NativeHandle()->HLRAngle();
    };*/

    //=======================================================================
    //function : SetDisplayMode
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::SetDisplayMode(Standard_Integer theMode, Standard_Boolean theToUpdateViewer)
    {
        NativeHandle()->SetDisplayMode(theMode, theToUpdateViewer);
    };

    //=======================================================================
    //function : SetDisplayMode
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::SetDisplayMode(XAIS_InteractiveObject^ theIObj, Standard_Integer theMode, Standard_Boolean theToUpdateViewer)
    {
        NativeHandle()->SetDisplayMode(theIObj->GetInteractiveObject(), theMode, theToUpdateViewer);
    };

    //=======================================================================
    //function : UnsetDisplayMode
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::UnsetDisplayMode(XAIS_InteractiveObject^ theIObj, Standard_Boolean theToUpdateViewer)
    {
        NativeHandle()->UnsetDisplayMode(theIObj->GetInteractiveObject(), theToUpdateViewer);
    };

    //=======================================================================
    //function : SetCurrentFacingModel
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::SetCurrentFacingModel(XAIS_InteractiveObject^ theIObj, XAspect_TypeOfFacingModel theModel)
    {
        NativeHandle()->SetCurrentFacingModel(theIObj->GetInteractiveObject(), safe_cast<Aspect_TypeOfFacingModel>(theModel));
    };

    //=======================================================================
    //function : SetColor
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::SetColor(XAIS_InteractiveObject^ theIObj, XQuantity_Color^ theColor, Standard_Boolean theToUpdateViewer)
    {
        NativeHandle()->SetColor(theIObj->GetInteractiveObject(), *theColor->GetColor(), theToUpdateViewer);
    };

    //=======================================================================
    //function : SetIsoOnTriangulation
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::IsoOnTriangulation(Standard_Boolean theIsEnabled, XAIS_InteractiveObject^ theObject)
    {
        NativeHandle()->IsoOnTriangulation(theIsEnabled, theObject->GetInteractiveObject());
    };

    //=======================================================================
    //function : SetDeviationCoefficient
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::SetDeviationCoefficient(XAIS_InteractiveObject^ theIObj, Standard_Real theCoefficient, Standard_Boolean theToUpdateViewer)
    {
        NativeHandle()->SetDeviationCoefficient(theIObj->GetInteractiveObject(), theCoefficient, theToUpdateViewer);
    };

    //=======================================================================
    //function : SetHLRDeviationCoefficient
    //purpose  :
    //=======================================================================
    /*void XAIS_InteractiveContext::SetHLRDeviationCoefficient(XAIS_InteractiveObject^ theIObj, Standard_Real theCoefficient, Standard_Boolean theToUpdateViewer)
    {
        NativeHandle()->SetHLRDeviationCoefficient(theIObj, theCoefficient, theToUpdateViewer);
    };*/

    //=======================================================================
    //function : SetDeviationAngle
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::SetDeviationAngle(XAIS_InteractiveObject^ theIObj, Standard_Real theAngle, Standard_Boolean theToUpdateViewer)
    {
        NativeHandle()->SetDeviationAngle(theIObj->GetInteractiveObject(), theAngle, theToUpdateViewer);
    };

    //=======================================================================
    //function : SetAngleAndDeviation
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::SetAngleAndDeviation(XAIS_InteractiveObject^ theIObj, Standard_Real theAngle, Standard_Boolean theToUpdateViewer)
    {
        NativeHandle()->SetAngleAndDeviation(theIObj->GetInteractiveObject(), theAngle, theToUpdateViewer);
    };

    //=======================================================================
    //function : SetHLRAngleAndDeviation
    //purpose  :
    //=======================================================================
    /*void XAIS_InteractiveContext::SetHLRAngleAndDeviation(XAIS_InteractiveObject^ theIObj, Standard_Real theAngle, Standard_Boolean theToUpdateViewer)
    {
        NativeHandle()->SetHLRAngleAndDeviation(theIObj, theAngle, theToUpdateViewer);
    };*/

    //=======================================================================
    //function : SetHLRDeviationAngle
    //purpose  :
    //=======================================================================
   /* void XAIS_InteractiveContext::SetHLRDeviationAngle(XAIS_InteractiveObject^ theIObj, Standard_Real theAngle, Standard_Boolean theToUpdateViewer)
    {
        NativeHandle()->SetHLRDeviationAngle(theIObj, theAngle, theToUpdateViewer);
    };*/

    //=======================================================================
    //function : UnsetColor
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::UnsetColor(XAIS_InteractiveObject^ theIObj, Standard_Boolean theToUpdateViewer)
    {
        NativeHandle()->UnsetColor(theIObj->GetInteractiveObject(), theToUpdateViewer);
    };

    //=======================================================================
    //function : HasColor
    //purpose  :
    //=======================================================================
    Standard_Boolean XAIS_InteractiveContext::HasColor(XAIS_InteractiveObject^ theIObj)
    {
        return NativeHandle()->HasColor(theIObj->GetInteractiveObject());
    };

    //=======================================================================
    //function : Color
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::Color(XAIS_InteractiveObject^ theIObj, XQuantity_Color^ theColor)
    {
        NativeHandle()->Color(theIObj->GetInteractiveObject(), *theColor->GetColor());
    };

    //=======================================================================
    //function : Width
    //purpose  :
    //=======================================================================
    Standard_Real XAIS_InteractiveContext::Width(XAIS_InteractiveObject^ theIObj)
    {
        return NativeHandle()->Width(theIObj->GetInteractiveObject());
    };

    //=======================================================================
    //function : SetWidth
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::SetWidth(XAIS_InteractiveObject^ theIObj, Standard_Real theWidth, Standard_Boolean theToUpdateViewer)
    {
        return NativeHandle()->SetWidth(theIObj->GetInteractiveObject(), theWidth, theToUpdateViewer);
    };

    //=======================================================================
    //function : UnsetWidth
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::UnsetWidth(XAIS_InteractiveObject^ theIObj, Standard_Boolean theToUpdateViewer)
    {
        return NativeHandle()->UnsetWidth(theIObj->GetInteractiveObject(), theToUpdateViewer);
    };

    //=======================================================================
    //function : SetMaterial
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::SetMaterial(XAIS_InteractiveObject^ theIObj, Graphic3d_MaterialAspect theMaterial, Standard_Boolean theToUpdateViewer)
    {
        NativeHandle()->SetMaterial(theIObj->GetInteractiveObject(), theMaterial, theToUpdateViewer);
    };

    //=======================================================================
    //function : UnsetMaterial
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::UnsetMaterial(XAIS_InteractiveObject^ theIObj, Standard_Boolean theToUpdateViewer)
    {
        NativeHandle()->UnsetMaterial(theIObj->GetInteractiveObject(), theToUpdateViewer);
    };

    //=======================================================================
    //function : SetTransparency
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::SetTransparency(XAIS_InteractiveObject^ theIObj, Standard_Real theValue, Standard_Boolean theToUpdateViewer)
    {
        NativeHandle()->SetTransparency(theIObj->GetInteractiveObject(), theValue, theToUpdateViewer);
    };

    //=======================================================================
    //function : UnsetTransparency
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::UnsetTransparency(XAIS_InteractiveObject^ theIObj, Standard_Boolean theToUpdateViewer)
    {
        NativeHandle()->UnsetTransparency(theIObj->GetInteractiveObject(), theToUpdateViewer);
    };

    //=======================================================================
    //function : SetSelectedAspect
    //purpose  :
    //=======================================================================
    /*void XAIS_InteractiveContext::SetSelectedAspect(Handle(Prs3d_BasicAspect) theAspect, Standard_Boolean theToUpdateViewer)
    {
        NativeHandle()->SetSelectedAspect(theAspect, theToUpdateViewer);
    };*/

    //=======================================================================
    //function : SetLocalAttributes
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::SetLocalAttributes(XAIS_InteractiveObject^ theIObj, XPrs3d_Drawer^ theDrawer, Standard_Boolean theToUpdateViewer)
    {
        NativeHandle()->SetLocalAttributes(theIObj->GetInteractiveObject(), theDrawer->GetDrawer(), theToUpdateViewer);
    };

    //=======================================================================
    //function : UnsetLocalAttributes
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::UnsetLocalAttributes(XAIS_InteractiveObject^ theIObj, Standard_Boolean theToUpdateViewer)
    {
        NativeHandle()->UnsetLocalAttributes(theIObj->GetInteractiveObject(), theToUpdateViewer);
    };

    //=======================================================================
    //function : Status
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::Status(XAIS_InteractiveObject^ theIObj, XTCollection_ExtendedString^ theStatus)
    {
        NativeHandle()->Status(theIObj->GetInteractiveObject(), *theStatus->GetExtendedString());
    };

    //=======================================================================
    //function : GetDefModes
    //purpose  :
    //=======================================================================
    //void XAIS_InteractiveContext::GetDefModes(XAIS_InteractiveObject^ theIObj, Standard_Integer& theDispMode, Standard_Integer& theHiMode, Standard_Integer& theSelMode)
    //{
    //    //NativeHandle()->GetDefModes(theIObj, theDispMode, theHiMode, theSelMode);
    //    if (theIObj.IsNull())
    //    {
    //        return;
    //    }

    //    theDispMode = theIObj->HasDisplayMode() ? theIObj->DisplayMode()
    //        : (theIObj->AcceptDisplayMode(NativeHandle()->DisplayMode()) ? NativeHandle()->DisplayMode() : 0);
    //    theHiMode = theIObj->HasHilightMode() ? theIObj->HilightMode() : theDispMode;
    //    theSelMode = theIObj->GlobalSelectionMode();
    //};

    ////=======================================================================
    ////function : EraseGlobal
    ////purpose  :
    ////=======================================================================
    //void XAIS_InteractiveContext::EraseGlobal(XAIS_InteractiveObject^& theIObj, Standard_Boolean theToUpdateviewer)
    //{
    //    NativeHandle()->EraseGlobal(theIObj, theToUpdateviewer);
    //};

    ////=======================================================================
    ////function : unselectOwners
    ////purpose  :
    ////=======================================================================
    //void XAIS_InteractiveContext::unselectOwners(XAIS_InteractiveObject^& theObject)
    //{
    //    NativeHandle()->unselectOwners(theObject);
    //};

    ////=======================================================================
    ////function : ClearGlobal
    ////purpose  :
    ////=======================================================================
    //void XAIS_InteractiveContext::ClearGlobal(XAIS_InteractiveObject^& theIObj, Standard_Boolean theToUpdateviewer)
    //{
    //    NativeHandle()->ClearGlobal(theIObj, theToUpdateviewer);
    //};

    ////=======================================================================
    ////function : ClearGlobalPrs
    ////purpose  :
    ////=======================================================================
    //void XAIS_InteractiveContext::ClearGlobalPrs(XAIS_InteractiveObject^& theIObj, Standard_Integer theMode, Standard_Boolean theToUpdateViewer)
    //{
    //    NativeHandle()->ClearGlobalPrs(theIObj, theMode, theToUpdateViewer);
    //};

    //=======================================================================
    //function : ClearDetected
    //purpose  :
    //=======================================================================
    Standard_Boolean XAIS_InteractiveContext::ClearDetected(Standard_Boolean theToRedrawImmediate)
    {
        return NativeHandle()->ClearDetected(theToRedrawImmediate);
    };

    //! Returns true if there is a mouse-detected entity in context.
       //! @sa DetectedOwner()/HasNextDetected()/HilightPreviousDetected()/HilightNextDetected().
    Standard_Boolean XAIS_InteractiveContext::HasDetected() {
        return NativeHandle()->HasDetected();
    };

    //! Returns the owner of the detected sensitive primitive which is currently dynamically highlighted.
    //! WARNING! This method is irrelevant to InitDetected()/MoreDetected()/NextDetected().
    //! @sa HasDetected()/HasNextDetected()/HilightPreviousDetected()/HilightNextDetected().
    Handle(SelectMgr_EntityOwner) XAIS_InteractiveContext::DetectedOwner() {
        return NativeHandle()->DetectedOwner();
    };

    //! Returns the interactive objects last detected in context.
    //! In general this is just a wrapper for XAIS_InteractiveObject^::DownCast(DetectedOwner()->Selectable()).
    //! @sa DetectedOwner()
    XAIS_InteractiveObject^ XAIS_InteractiveContext::DetectedInteractive() {
        return gcnew XAIS_InteractiveObject(NativeHandle()->DetectedInteractive());
    };

    //=======================================================================
    //function : DrawHiddenLine
    //purpose  :
    //=======================================================================
    Standard_Boolean XAIS_InteractiveContext::DrawHiddenLine()
    {
        return NativeHandle()->DrawHiddenLine();
    };

    //=======================================================================
    //function : EnableDrawHiddenLine
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::EnableDrawHiddenLine()
    {
        NativeHandle()->EnableDrawHiddenLine();
    };

    //=======================================================================
    //function : DisableDrawHiddenLine 
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::DisableDrawHiddenLine()
    {
        NativeHandle()->DisableDrawHiddenLine();
    };

    //=======================================================================
    //function : HiddenLineAspect
    //purpose  :
    //=======================================================================
    Handle(Prs3d_LineAspect) XAIS_InteractiveContext::HiddenLineAspect()
    {
        return NativeHandle()->HiddenLineAspect();
    };

    //=======================================================================
    //function : SetHiddenLineAspect
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::SetHiddenLineAspect(Handle(Prs3d_LineAspect) theAspect)
    {
        NativeHandle()->SetHiddenLineAspect(theAspect);
    };

    //=======================================================================
    //function : SetIsoNumber
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::SetIsoNumber(Standard_Integer theNb, XAIS_TypeOfIso theType)
    {
        NativeHandle()->SetIsoNumber(theNb, safe_cast<AIS_TypeOfIso>(theType));
    };

    //=======================================================================
    //function : IsoNumber
    //purpose  :
    //=======================================================================
    Standard_Integer XAIS_InteractiveContext::IsoNumber(XAIS_TypeOfIso theType)
    {
        return NativeHandle()->IsoNumber(safe_cast<AIS_TypeOfIso>(theType));
    };

    //=======================================================================
    //function : IsoOnPlane
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::IsoOnPlane(Standard_Boolean theToSwitchOn)
    {
        NativeHandle()->IsoOnPlane(theToSwitchOn);
    };

    //=======================================================================
    //function : IsoOnPlane
    //purpose  :
    //=======================================================================
    Standard_Boolean XAIS_InteractiveContext::IsoOnPlane()
    {
        return NativeHandle()->IsoOnPlane();
    };

    //=======================================================================
    //function : IsoOnTriangulation
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::IsoOnTriangulation(Standard_Boolean theToSwitchOn)
    {
        NativeHandle()->IsoOnTriangulation(theToSwitchOn);
    };

    //=======================================================================
    //function : IsoOnTriangulation
    //purpose  :
    //=======================================================================
    Standard_Boolean XAIS_InteractiveContext::IsoOnTriangulation()
    {
        return NativeHandle()->IsoOnTriangulation();
    };

    //=======================================================================
    //function : SetPixelTolerance
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::SetPixelTolerance(Standard_Integer thePrecision)
    {
        NativeHandle()->SetPixelTolerance(thePrecision);
    };

    //=======================================================================
    //function : PixelTolerance
    //purpose  :
    //=======================================================================
    Standard_Integer XAIS_InteractiveContext::PixelTolerance()
    {
        return NativeHandle()->PixelTolerance();
    };

    //=======================================================================
    //function : SetSelectionSensitivity
    //purpose  : Allows to manage sensitivity of a particular selection of interactive object theObject
    //=======================================================================
    void XAIS_InteractiveContext::SetSelectionSensitivity(XAIS_InteractiveObject^ theObject, Standard_Integer theMode, Standard_Integer theNewSensitivity)
    {
        NativeHandle()->SetSelectionSensitivity(theObject->GetInteractiveObject(), theMode, theNewSensitivity);
    };

    ////=======================================================================
    ////function : InitAttributes
    ////purpose  :
    ////=======================================================================
    //void XAIS_InteractiveContext::InitAttributes()
    //{
    //    NativeHandle()->InitAttributes();
    //};

    //=======================================================================
    //function : TrihedronSize
    //purpose  :
    //=======================================================================
    Standard_Real XAIS_InteractiveContext::TrihedronSize()
    {
        return NativeHandle()->TrihedronSize();
    };

    //=======================================================================
    //function : SetTrihedronSize
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::SetTrihedronSize(Standard_Real theVal, Standard_Boolean updateviewer)
    {
        NativeHandle()->SetTrihedronSize(theVal, updateviewer);
    };

    //=======================================================================
    //function : SetPlaneSize
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::SetPlaneSize(Standard_Real theValX, Standard_Real theValY, Standard_Boolean theToUpdateViewer)
    {
        NativeHandle()->SetPlaneSize(theValX, theValY, theToUpdateViewer);
    };

    //=======================================================================
    //function : SetPlaneSize
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::SetPlaneSize(Standard_Real theVal, Standard_Boolean theToUpdateViewer)
    {
        SetPlaneSize(theVal, theVal, theToUpdateViewer);
    };

    //=======================================================================
    //function : PlaneSize
    //purpose  :
    //=======================================================================
    Standard_Boolean XAIS_InteractiveContext::PlaneSize(Standard_Real theX, Standard_Real theY)
    {
        return NativeHandle()->PlaneSize(theX, theY);
    };

    //=======================================================================
    //function : SetZLayer
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::SetZLayer(XAIS_InteractiveObject^ theIObj, Graphic3d_ZLayerId theLayerId)
    {
        NativeHandle()->SetZLayer(theIObj->GetInteractiveObject(), theLayerId);
    };

    //=======================================================================
    //function : GetZLayer
    //purpose  :
    //=======================================================================
    Graphic3d_ZLayerId XAIS_InteractiveContext::GetZLayer(XAIS_InteractiveObject^ theIObj)
    {
        return NativeHandle()->GetZLayer(theIObj->GetInteractiveObject());
    };

    //=======================================================================
    //function : RebuildSelectionStructs
    //purpose  : Rebuilds 1st level of BVH selection forcibly
    //=======================================================================
    void XAIS_InteractiveContext::RebuildSelectionStructs()
    {
        NativeHandle()->RebuildSelectionStructs();
    };

    //=======================================================================
    //function : Disconnect
    //purpose  : Disconnects selectable object from an assembly and updates selection structures
    //=======================================================================
    void XAIS_InteractiveContext::Disconnect(XAIS_InteractiveObject^ theAssembly, XAIS_InteractiveObject^ theObjToDisconnect)
    {
        NativeHandle()->Disconnect(theAssembly->GetInteractiveObject(), theObjToDisconnect->GetInteractiveObject());
    };

    //=======================================================================
    //function : FitSelected
    //purpose  : Fits the view corresponding to the bounds of selected objects
    //=======================================================================
    void XAIS_InteractiveContext::FitSelected(XV3d_View^ theView)
    {
        FitSelected(theView, 0.01, Standard_True);
    };

    //=======================================================================
    //function : BoundingBoxOfSelection
    //purpose  :
    //=======================================================================
    XBnd_Box^ XAIS_InteractiveContext::BoundingBoxOfSelection()
    {
        return gcnew XBnd_Box(&NativeHandle()->BoundingBoxOfSelection());
    };

    //=======================================================================
    //function : FitSelected
    //purpose  : Fits the view corresponding to the bounds of selected objects
    //=======================================================================
    void XAIS_InteractiveContext::FitSelected(XV3d_View^ theView, Standard_Real theMargin, Standard_Boolean theToUpdate)
    {
        NativeHandle()->FitSelected(theView->GetView(), theMargin, theToUpdate);
    };

    //! Return value specified whether selected object must be hilighted when mouse cursor is moved above it
        //! @sa MoveTo()
    Standard_Boolean XAIS_InteractiveContext::ToHilightSelected() {
        return NativeHandle()->ToHilightSelected();
    };

    //! Specify whether selected object must be hilighted when mouse cursor is moved above it (in MoveTo method).
    //! By default this value is false and selected object is not hilighted in this case.
    //! @sa MoveTo()
    void XAIS_InteractiveContext::SetToHilightSelected(Standard_Boolean toHilight) {
        NativeHandle()->SetToHilightSelected(toHilight);
    };

    //! Returns true if the automatic highlight mode is active; TRUE by default.
    //! @sa MoveTo(), Select(), HilightWithColor(), Unhilight()
    Standard_Boolean XAIS_InteractiveContext::AutomaticHilight() {
          return NativeHandle()->AutomaticHilight();
    };

    //! Sets the highlighting status of detected and selected entities.
    //! This function allows you to disconnect the automatic mode.
    //!
    //! MoveTo() will fill the list of detected entities
    //! and Select() will set selected state to detected objects regardless of this flag,
    //! but with disabled AutomaticHiligh() their highlighting state will be left unaffected,
    //! so that application will be able performing custom highlighting in a different way, if needed.
    //!
    //! This API should be distinguished from SelectMgr_SelectableObject::SetAutoHilight()
    //! that is used to implement custom highlighting logic for a specific interactive object class.
    //!
    //! @sa MoveTo(), Select(), HilightWithColor(), Unhilight()
    void XAIS_InteractiveContext::SetAutomaticHilight(Standard_Boolean theStatus) {
        NativeHandle()->SetAutomaticHilight(theStatus);
    };

    //=======================================================================
    //function : SetTransformPersistence
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::SetTransformPersistence(XAIS_InteractiveObject^ theObject, Handle(Graphic3d_TransformPers) theTrsfPers)
    {
        NativeHandle()->SetTransformPersistence(theObject->GetInteractiveObject(), theTrsfPers);
    };

    //=======================================================================
    //function : GravityPoint
    //purpose  :
    //=======================================================================
    xgp_Pnt^ XAIS_InteractiveContext::GravityPoint(XV3d_View^ theView)
    {
        gp_Pnt* temp = new gp_Pnt(NativeHandle()->GravityPoint(theView->GetView()));
        return gcnew xgp_Pnt(temp);
    };
    ////=======================================================================
    ////function : setObjectStatus
    ////purpose  :
    ////=======================================================================
    //void XAIS_InteractiveContext::setObjectStatus(XAIS_InteractiveObject^& theIObj, AIS_DisplayStatus theStatus, Standard_Integer theDispMode, Standard_Integer theSelectionMode)
    //{
    //    NativeHandle()->setObjectStatus(theIObj, theStatus, theDispMode, theSelectionMode);
    //};
}
