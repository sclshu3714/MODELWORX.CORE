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

IMPLEMENT_STANDARD_RTTIEXT(AIS_InteractiveContext, Standard_Transient)

namespace
{
    typedef NCollection_DataMap<Handle(SelectMgr_SelectableObject), Handle(SelectMgr_IndexedMapOfOwner)> AIS_MapOfObjectOwners;
    typedef NCollection_DataMap<Handle(SelectMgr_SelectableObject), Handle(SelectMgr_IndexedMapOfOwner)>::Iterator AIS_MapIteratorOfMapOfObjectOwners;

    //! Initialize default highlighting attributes.
    static void initDefaultHilightAttributes(const Handle(Prs3d_Drawer)& theDrawer)
    {
        theDrawer->SetMethod(Aspect_TOHM_COLOR);
        theDrawer->SetDisplayMode(0);

        theDrawer->SetPointAspect(new Prs3d_PointAspect(Aspect_TOM_POINT, Quantity_NOC_BLACK, 1.0));
        *theDrawer->PointAspect()->Aspect() = *theDrawer->Link()->PointAspect()->Aspect();
        theDrawer->SetLineAspect(new Prs3d_LineAspect(Quantity_NOC_BLACK, Aspect_TOL_SOLID, 1.0));
        *theDrawer->LineAspect()->Aspect() = *theDrawer->Link()->LineAspect()->Aspect();
        theDrawer->SetWireAspect(new Prs3d_LineAspect(Quantity_NOC_BLACK, Aspect_TOL_SOLID, 1.0));
        *theDrawer->WireAspect()->Aspect() = *theDrawer->Link()->WireAspect()->Aspect();
        theDrawer->SetPlaneAspect(new Prs3d_PlaneAspect());
        *theDrawer->PlaneAspect()->EdgesAspect() = *theDrawer->Link()->PlaneAspect()->EdgesAspect();
        theDrawer->SetFreeBoundaryAspect(new Prs3d_LineAspect(Quantity_NOC_BLACK, Aspect_TOL_SOLID, 1.0));
        *theDrawer->FreeBoundaryAspect()->Aspect() = *theDrawer->Link()->FreeBoundaryAspect()->Aspect();
        theDrawer->SetUnFreeBoundaryAspect(new Prs3d_LineAspect(Quantity_NOC_BLACK, Aspect_TOL_SOLID, 1.0));
        *theDrawer->UnFreeBoundaryAspect()->Aspect() = *theDrawer->Link()->UnFreeBoundaryAspect()->Aspect();

        theDrawer->WireAspect()->SetWidth(2.0);
        theDrawer->LineAspect()->SetWidth(2.0);
        theDrawer->PlaneAspect()->EdgesAspect()->SetWidth(2.0);
        theDrawer->FreeBoundaryAspect()->SetWidth(2.0);
        theDrawer->UnFreeBoundaryAspect()->SetWidth(2.0);
        theDrawer->PointAspect()->SetTypeOfMarker(Aspect_TOM_O_POINT);
        theDrawer->PointAspect()->SetScale(2.0);

        // the triangulation should be computed using main presentation attributes,
        // and should not be overridden by highlighting
        theDrawer->SetAutoTriangulation(Standard_False);
    }
}
namespace TKV3d {
    //=======================================================================
    //function : AIS_InteractiveContext
    //purpose  : 
    //=======================================================================

    XAIS_InteractiveContext::XAIS_InteractiveContext(Handle(V3d_Viewer) MainViewer)
    {
        NativeHandle() = new AIS_InteractiveContext(MainViewer);
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
    Handle(V3d_View) XAIS_InteractiveContext::LastActiveView()
    {
        return NativeHandle()->LastActiveView();
    }

    //! Returns the default attribute manager.
        //! This contains all the color and line attributes which can be used by interactive objects which do not have their own attributes.
    Handle(Prs3d_Drawer) XAIS_InteractiveContext::DefaultDrawer() {
        return NativeHandle()->DefaultDrawer();
    };

    //! Returns the current viewer.
    Handle(V3d_Viewer) XAIS_InteractiveContext::CurrentViewer() {
        return NativeHandle()->CurrentViewer();
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
    void XAIS_InteractiveContext::DisplayedObjects(AIS_KindOfInteractive theKind, Standard_Integer theSign, AIS_ListOfInteractive theListOfIO)
    {
        ObjectsByDisplayStatus(theKind, theSign, AIS_DS_Displayed, theListOfIO);
    };

    //=======================================================================
    //function : ErasedObjects
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::ErasedObjects(AIS_ListOfInteractive theListOfIO)
    {
        ObjectsByDisplayStatus(AIS_DS_Erased, theListOfIO);
    };

    //=======================================================================
    //function : ErasedObjects
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::ErasedObjects(AIS_KindOfInteractive theKind, Standard_Integer theSign, AIS_ListOfInteractive theListOfIO)
    {
        ObjectsByDisplayStatus(theKind, theSign, AIS_DS_Erased, theListOfIO);
    };

    //=======================================================================
    //function : ObjectsByDisplayStatus
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::ObjectsByDisplayStatus(AIS_DisplayStatus theStatus, AIS_ListOfInteractive theListOfIO)
    {
        NativeHandle()->ObjectsByDisplayStatus(theStatus, theListOfIO);
    };

    //=======================================================================
    //function : ObjectsByDisplayStatus
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::ObjectsByDisplayStatus(AIS_KindOfInteractive theKind, Standard_Integer theSign, AIS_DisplayStatus theStatus, AIS_ListOfInteractive theListOfIO)
    {
        NativeHandle()->ObjectsByDisplayStatus(theKind, theSign, theStatus, theListOfIO);
    };

    //=======================================================================
    //function : ObjectsInside
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::ObjectsInside(AIS_ListOfInteractive theListOfIO, AIS_KindOfInteractive theKind, Standard_Integer theSign)
    {
        NativeHandle()->ObjectsInside(theListOfIO, theKind, theSign);
    };

    //=======================================================================
    //function : ObjectsForView
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::ObjectsForView(AIS_ListOfInteractive theListOfIO, Handle(V3d_View) theView, Standard_Boolean theIsVisibleInView, AIS_DisplayStatus theStatus)
    {
        NativeHandle()->ObjectsForView(theListOfIO, theView, theIsVisibleInView, theStatus);
    };

    //=======================================================================
    //function : Display
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::Display(Handle(AIS_InteractiveObject) theIObj, Standard_Boolean theToUpdateViewer)
    {
        NativeHandle()->Display(theIObj, theToUpdateViewer);
    };

    //=======================================================================
    //function : SetViewAffinity
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::SetViewAffinity(Handle(AIS_InteractiveObject) theIObj, Handle(V3d_View) theView, Standard_Boolean theIsVisible)
    {
        NativeHandle()->SetViewAffinity(theIObj, theView, theIsVisible);
    };

    //! Returns the Display Mode setting to be used by default.
    Standard_Integer XAIS_InteractiveContext::DisplayMode() {
        return NativeHandle()->DisplayMode();
    };

    //=======================================================================
    //function : Display
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::Display(Handle(AIS_InteractiveObject) theIObj, Standard_Integer theDispMode, Standard_Integer theSelectionMode, Standard_Boolean theToUpdateViewer, AIS_DisplayStatus theDispStatus)
    {
        NativeHandle()->Display(theIObj, theDispMode, theSelectionMode, theToUpdateViewer, theDispStatus);
    };

    //! Displays the object in this Context using default Display Mode.
        //! This will be the object's default display mode, if there is one. Otherwise, it will be the context mode.
        //! The Interactive Object's default selection mode is activated if GetAutoActivateSelection() is TRUE. In general, this is 0.
    void XAIS_InteractiveContext::Display(XAIS_InteractiveObject^ theIObj, Standard_Boolean theToUpdateViewer) {
        NativeHandle()->Display(theIObj->GetInteractiveObject(), theToUpdateViewer);
    };

    //! Sets status, display mode and selection mode for specified Object
        //! If theSelectionMode equals -1, theIObj will not be activated: it will be displayed but will not be selectable.
        //! AIS_DisplayStatus theDispStatus
    void XAIS_InteractiveContext::Display(XAIS_InteractiveObject^ theIObj, Standard_Integer theDispMode, Standard_Integer theSelectionMode, Standard_Boolean theToUpdateViewer, Standard_Integer theDispStatus) {
        NativeHandle()->Display(theIObj->GetInteractiveObject(), theDispMode, theSelectionMode, theToUpdateViewer, AIS_DisplayStatus(theDispStatus));
    };

    //=======================================================================
    //function : Load
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::Load(Handle(AIS_InteractiveObject) theIObj, Standard_Integer theSelMode)
    {
        NativeHandle()->Load(theIObj, theSelMode);
    };

    //! Allows you to load the Interactive Object with a given selection mode,
        //! and/or with the desired decomposition option, whether the object is visualized or not.
        //! The loaded objects will be selectable but displayable in highlighting only when detected by the Selector.
    void XAIS_InteractiveContext::Load(XAIS_InteractiveObject^ theObj, Standard_Integer theSelectionMode) {
        NativeHandle()->Load(theObj->GetInteractiveObject(), theSelectionMode);
    };

    //! AIS_DisplayStatus   theDispStatus
    void XAIS_InteractiveContext::Display(XAIS_InteractiveObject^ theIObj, Standard_Integer theDispMode, Standard_Integer theSelectionMode, Standard_Boolean theToUpdateViewer, Standard_Boolean theToAllowDecomposition, Standard_Integer theDispStatus) {
        (void)theToAllowDecomposition;
        NativeHandle()->Display(theIObj->GetInteractiveObject(), theDispMode, theSelectionMode, theToUpdateViewer, AIS_DisplayStatus(theDispStatus));
    }

    void XAIS_InteractiveContext::Load(XAIS_InteractiveObject^ theObj, Standard_Integer theSelectionMode, Standard_Boolean) {
        NativeHandle()->Load(theObj->GetInteractiveObject(), theSelectionMode);
    }


    //=======================================================================
    //function : Erase
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::Erase(Handle(AIS_InteractiveObject) theIObj, Standard_Boolean theToUpdateViewer)
    {
        NativeHandle()->Erase(theIObj, theToUpdateViewer);
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
    void XAIS_InteractiveContext::ClearPrs(Handle(AIS_InteractiveObject) theIObj, Standard_Integer theMode, Standard_Boolean theToUpdateViewer) {
        NativeHandle()->ClearPrs(theIObj, theMode, theToUpdateViewer);
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
    AIS_DisplayStatus XAIS_InteractiveContext::DisplayStatus(Handle(AIS_InteractiveObject) theIObj)
    {
       return NativeHandle()->DisplayStatus(theIObj);
    };

    //=======================================================================
    //function : Remove
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::Remove(Handle(AIS_InteractiveObject) theIObj, Standard_Boolean theToUpdateViewer)
    {
        NativeHandle()->Remove(theIObj, theToUpdateViewer);
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
    void XAIS_InteractiveContext::HilightWithColor(Handle(AIS_InteractiveObject) theObj, Handle(Prs3d_Drawer) theStyle, Standard_Boolean theIsToUpdate)
    {
        NativeHandle()->HilightWithColor(theObj, theStyle, theIsToUpdate);
    };

    //=======================================================================
    //function : Unhilight
    //purpose  : 
    //=======================================================================
    void XAIS_InteractiveContext::Unhilight(Handle(AIS_InteractiveObject) anIObj, Standard_Boolean updateviewer)
    {
        NativeHandle()->Unhilight(anIObj, updateviewer);
    };

    //=======================================================================
    //function : IsHilighted
    //purpose  : Returns true if the objects global status is set to highlighted.
    //=======================================================================
    Standard_Boolean XAIS_InteractiveContext::IsHilighted(Handle(AIS_InteractiveObject) theObj)
    {
        return  NativeHandle()->IsHilighted(theObj);
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
    /*void XAIS_InteractiveContext::Hilight(Handle(AIS_InteractiveObject) theObj, Standard_Boolean theIsToUpdateViewer) {
        NativeHandle()->Hilight(theObj, theIsToUpdateViewer);
    };*/


    //=======================================================================
    //function : HighlightStyle
    //purpose  :
    //=======================================================================
    Standard_Boolean XAIS_InteractiveContext::HighlightStyle(Handle(AIS_InteractiveObject) theObj, Handle(Prs3d_Drawer) theStyle)
    {
        return  NativeHandle()->HighlightStyle(theObj, theStyle);
    };

    //=======================================================================
    //function : HighlightStyle
    //purpose  :
    //=======================================================================
    Standard_Boolean XAIS_InteractiveContext::HighlightStyle(Handle(SelectMgr_EntityOwner) theOwner, Handle(Prs3d_Drawer) theStyle)
    {
        return  NativeHandle()->HighlightStyle(theOwner, theStyle);
    };

    //=======================================================================
    //function : IsDisplayed
    //purpose  : 
    //=======================================================================

    Standard_Boolean XAIS_InteractiveContext::IsDisplayed(Handle(AIS_InteractiveObject) theObj)
    {
        return  NativeHandle()->IsDisplayed(theObj);
    };

    //=======================================================================
    //function : IsDisplayed
    //purpose  :
    //=======================================================================
    Standard_Boolean XAIS_InteractiveContext::IsDisplayed(Handle(AIS_InteractiveObject) theIObj, Standard_Integer theMode)
    {
        return  NativeHandle()->IsDisplayed(theIObj, theMode);
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
    Standard_Integer XAIS_InteractiveContext::DisplayPriority(Handle(AIS_InteractiveObject) theIObj)
    {
        return  NativeHandle()->DisplayPriority(theIObj);
    };

    //=======================================================================
    //function : SetDisplayPriority
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::SetDisplayPriority(Handle(AIS_InteractiveObject) theIObj, Standard_Integer thePriority)
    {
         NativeHandle()->SetDisplayPriority(theIObj, thePriority);
    };

    //=======================================================================
    //function : Redisplay
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::Redisplay(Handle(AIS_InteractiveObject) theIObj, Standard_Boolean theToUpdateViewer, Standard_Boolean theAllModes)
    {
         NativeHandle()->Redisplay(theIObj, theToUpdateViewer, theAllModes);
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
    void XAIS_InteractiveContext::Redisplay(AIS_KindOfInteractive theKOI, Standard_Integer theSign, Standard_Boolean theToUpdateViewer)
    {
        NativeHandle()->Redisplay(theKOI, theSign, theToUpdateViewer);
    };

    //=======================================================================
    //function : RecomputePrsOnly
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::RecomputePrsOnly(Handle(AIS_InteractiveObject) theIObj, Standard_Boolean theToUpdateViewer, Standard_Boolean theAllModes)
    {
        NativeHandle()->RecomputePrsOnly(theIObj, theToUpdateViewer, theAllModes);
    };

    //! Recomputes the displayed presentations, flags the others.
        //! Doesn't update presentations.
    void XAIS_InteractiveContext::RecomputePrsOnly(XAIS_InteractiveObject^ theIObj, Standard_Boolean theToUpdateViewer, Standard_Boolean theAllModes) {
        NativeHandle()->RecomputePrsOnly(theIObj->GetInteractiveObject(), theToUpdateViewer, theAllModes);
    };

    //=======================================================================
    //function : RecomputeSelectionOnly
    //purpose  : 
    //=======================================================================
    void XAIS_InteractiveContext::RecomputeSelectionOnly(Handle(AIS_InteractiveObject) theIO)
    {
        NativeHandle()->RecomputeSelectionOnly(theIO);
    };

    //! Recomputes the active selections, flags the others.
        //! Doesn't update presentations.
    void XAIS_InteractiveContext::RecomputeSelectionOnly(XAIS_InteractiveObject^ anIObj) {
        NativeHandle()->RecomputeSelectionOnly(anIObj->GetInteractiveObject());
    };

    //=======================================================================
    //function : Update
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::Update(Handle(AIS_InteractiveObject) theIObj, Standard_Boolean theUpdateViewer)
    {
        NativeHandle()->Update(theIObj, theUpdateViewer);
    };

    //! Updates displayed interactive object by checking and recomputing its flagged as "to be recomputed" presentation and selection structures.
        //! This method does not force any recomputation on its own.
        //! The method recomputes selections even if they are loaded without activation in particular selector.
    void XAIS_InteractiveContext::Update(XAIS_InteractiveObject^ theIObj, Standard_Boolean theUpdateViewer) {
        NativeHandle()->Update(theIObj->GetInteractiveObject(), theUpdateViewer);
    };

    //! Returns highlight style settings.   enum:Prs3d_TypeOfHighlight
    Handle(Prs3d_Drawer) XAIS_InteractiveContext::HighlightStyle(Prs3d_TypeOfHighlight theStyleType) {
       return  NativeHandle()->HighlightStyle(theStyleType);
    };


    //! enum:Prs3d_TypeOfHighlight
    void XAIS_InteractiveContext::SetHighlightStyle(Prs3d_TypeOfHighlight theStyleType, Handle(Prs3d_Drawer) theStyle) {
        NativeHandle()->SetHighlightStyle(theStyleType, theStyle);
    };

    //! Returns current dynamic highlight style settings.
    //! By default:
    //!   - the color of dynamic highlight is Quantity_NOC_CYAN1;
    //!   - the presentation for dynamic highlight is completely opaque;
    //!   - the type of highlight is Aspect_TOHM_COLOR.
    Handle(Prs3d_Drawer) XAIS_InteractiveContext::HighlightStyle() {
       return NativeHandle()->HighlightStyle();
    };

    void XAIS_InteractiveContext::SetHighlightStyle(Handle(Prs3d_Drawer) theStyle) {
        NativeHandle()->SetHighlightStyle(theStyle);
    };

    //! Returns current selection style settings.
    //! By default:
    //!   - the color of selection is Quantity_NOC_GRAY80;
    //!   - the presentation for selection is completely opaque;
    //!   - the type of highlight is Aspect_TOHM_COLOR.
    Handle(Prs3d_Drawer) XAIS_InteractiveContext::SelectionStyle() {
        return NativeHandle()->SelectionStyle();
    };

    //! Setup the style of selection highlighting.
    void XAIS_InteractiveContext::SetSelectionStyle(Handle(Prs3d_Drawer) theStyle) {
        NativeHandle()->SetSelectionStyle(theStyle);
    };

    //=======================================================================
    //function : SetLocation
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::SetLocation(Handle(AIS_InteractiveObject) theIObj, XTopLoc_Location^ theLoc)
    {
        NativeHandle()->SetLocation(theIObj, theLoc->GetLocation());
    };

    //=======================================================================
    //function : ResetLocation
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::ResetLocation(Handle(AIS_InteractiveObject) theIObj)
    {
        NativeHandle()->ResetLocation(theIObj);
    };

    //=======================================================================
    //function : HasLocation
    //purpose  :
    //=======================================================================
    Standard_Boolean XAIS_InteractiveContext::HasLocation(Handle(AIS_InteractiveObject) theIObj)
    {
        return NativeHandle()->HasLocation(theIObj);
    };

    //=======================================================================
    //function : Location
    //purpose  :
    //=======================================================================
    XTopLoc_Location^ XAIS_InteractiveContext::Location(Handle(AIS_InteractiveObject) theIObj)
    {
        return gcnew XTopLoc_Location(NativeHandle()->Location(theIObj));
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
    void XAIS_InteractiveContext::SetHLRDeviationCoefficient(Standard_Real theCoefficient)
    {
        NativeHandle()->SetHLRDeviationCoefficient(theCoefficient);
    };

    //=======================================================================
    //function : HLRDeviationCoefficient
    //purpose  :
    //=======================================================================
    Standard_Real XAIS_InteractiveContext::HLRDeviationCoefficient()
    {
        return NativeHandle()->HLRDeviationCoefficient();
    };

    //=======================================================================
    //function : SetHLRAngle
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::SetHLRAngle(Standard_Real theAngle)
    {
        NativeHandle()->SetHLRAngle(theAngle);
    };

    //=======================================================================
    //function : SetHLRAngleAndDeviation
    //purpose  : compute with anangle a HLRAngle and a HLRDeviationCoefficient 
    //           and set them in myHLRAngle and in myHLRDeviationCoefficient
    //           of myDefaultDrawer 
    //=======================================================================
    void XAIS_InteractiveContext::SetHLRAngleAndDeviation(Standard_Real theAngle)
    {
        NativeHandle()->SetHLRAngleAndDeviation(theAngle);
    };

    //=======================================================================
    //function : HLRAngle
    //purpose  :
    //=======================================================================
    Standard_Real XAIS_InteractiveContext::HLRAngle()
    {
        return NativeHandle()->HLRAngle();
    };

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
    void XAIS_InteractiveContext::SetDisplayMode(Handle(AIS_InteractiveObject) theIObj, Standard_Integer theMode, Standard_Boolean theToUpdateViewer)
    {
        NativeHandle()->SetDisplayMode(theIObj, theMode, theToUpdateViewer);
    };

    //=======================================================================
    //function : UnsetDisplayMode
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::UnsetDisplayMode(Handle(AIS_InteractiveObject) theIObj, Standard_Boolean theToUpdateViewer)
    {
        NativeHandle()->UnsetDisplayMode(theIObj, theToUpdateViewer);
    };

    //=======================================================================
    //function : SetCurrentFacingModel
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::SetCurrentFacingModel(Handle(AIS_InteractiveObject) theIObj, Aspect_TypeOfFacingModel theModel)
    {
        NativeHandle()->SetCurrentFacingModel(theIObj, theModel);
    };

    //=======================================================================
    //function : SetColor
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::SetColor(Handle(AIS_InteractiveObject) theIObj, Quantity_Color theColor, Standard_Boolean theToUpdateViewer)
    {
        NativeHandle()->SetColor(theIObj, theColor, theToUpdateViewer);
    };

    //=======================================================================
    //function : SetIsoOnTriangulation
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::IsoOnTriangulation(Standard_Boolean theIsEnabled, Handle(AIS_InteractiveObject) theObject)
    {
        NativeHandle()->IsoOnTriangulation(theIsEnabled, theObject);
    };

    //=======================================================================
    //function : SetDeviationCoefficient
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::SetDeviationCoefficient(Handle(AIS_InteractiveObject) theIObj, Standard_Real theCoefficient, Standard_Boolean theToUpdateViewer)
    {
        NativeHandle()->SetDeviationCoefficient(theIObj, theCoefficient, theToUpdateViewer);
    };

    //=======================================================================
    //function : SetHLRDeviationCoefficient
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::SetHLRDeviationCoefficient(Handle(AIS_InteractiveObject) theIObj, Standard_Real theCoefficient, Standard_Boolean theToUpdateViewer)
    {
        NativeHandle()->SetHLRDeviationCoefficient(theIObj, theCoefficient, theToUpdateViewer);
    };

    //=======================================================================
    //function : SetDeviationAngle
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::SetDeviationAngle(Handle(AIS_InteractiveObject) theIObj, Standard_Real theAngle, Standard_Boolean theToUpdateViewer)
    {
        NativeHandle()->SetDeviationAngle(theIObj, theAngle, theToUpdateViewer);
    };

    //=======================================================================
    //function : SetAngleAndDeviation
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::SetAngleAndDeviation(Handle(AIS_InteractiveObject) theIObj, Standard_Real theAngle, Standard_Boolean theToUpdateViewer)
    {
        NativeHandle()->SetAngleAndDeviation(theIObj, theAngle, theToUpdateViewer);
    };

    //=======================================================================
    //function : SetHLRAngleAndDeviation
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::SetHLRAngleAndDeviation(Handle(AIS_InteractiveObject) theIObj, Standard_Real theAngle, Standard_Boolean theToUpdateViewer)
    {
        NativeHandle()->SetHLRAngleAndDeviation(theIObj, theAngle, theToUpdateViewer);
    };

    //=======================================================================
    //function : SetHLRDeviationAngle
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::SetHLRDeviationAngle(Handle(AIS_InteractiveObject) theIObj, Standard_Real theAngle, Standard_Boolean theToUpdateViewer)
    {
        NativeHandle()->SetHLRDeviationAngle(theIObj, theAngle, theToUpdateViewer);
    };

    //=======================================================================
    //function : UnsetColor
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::UnsetColor(Handle(AIS_InteractiveObject) theIObj, Standard_Boolean theToUpdateViewer)
    {
        NativeHandle()->UnsetColor(theIObj, theToUpdateViewer);
    };

    //=======================================================================
    //function : HasColor
    //purpose  :
    //=======================================================================
    Standard_Boolean XAIS_InteractiveContext::HasColor(Handle(AIS_InteractiveObject) theIObj)
    {
        return NativeHandle()->HasColor(theIObj);
    };

    //=======================================================================
    //function : Color
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::Color(Handle(AIS_InteractiveObject) theIObj, Quantity_Color theColor)
    {
        NativeHandle()->Color(theIObj, theColor);
    };

    //=======================================================================
    //function : Width
    //purpose  :
    //=======================================================================
    Standard_Real XAIS_InteractiveContext::Width(Handle(AIS_InteractiveObject) theIObj)
    {
        return NativeHandle()->Width(theIObj);
    };

    //=======================================================================
    //function : SetWidth
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::SetWidth(Handle(AIS_InteractiveObject) theIObj, Standard_Real theWidth, Standard_Boolean theToUpdateViewer)
    {
        return NativeHandle()->SetWidth(theIObj, theWidth, theToUpdateViewer);
    };

    //=======================================================================
    //function : UnsetWidth
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::UnsetWidth(Handle(AIS_InteractiveObject) theIObj, Standard_Boolean theToUpdateViewer)
    {
        return NativeHandle()->UnsetWidth(theIObj, theToUpdateViewer);
    };

    //=======================================================================
    //function : SetMaterial
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::SetMaterial(Handle(AIS_InteractiveObject) theIObj, Graphic3d_MaterialAspect theMaterial, Standard_Boolean theToUpdateViewer)
    {
        NativeHandle()->SetMaterial(theIObj, theMaterial, theToUpdateViewer);
    };

    //=======================================================================
    //function : UnsetMaterial
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::UnsetMaterial(Handle(AIS_InteractiveObject) theIObj, Standard_Boolean theToUpdateViewer)
    {
        NativeHandle()->UnsetMaterial(theIObj, theToUpdateViewer);
    };

    //=======================================================================
    //function : SetTransparency
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::SetTransparency(Handle(AIS_InteractiveObject) theIObj, Standard_Real theValue, Standard_Boolean theToUpdateViewer)
    {
        NativeHandle()->SetTransparency(theIObj, theValue, theToUpdateViewer);
    };

    //=======================================================================
    //function : UnsetTransparency
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::UnsetTransparency(Handle(AIS_InteractiveObject) theIObj, Standard_Boolean theToUpdateViewer)
    {
        NativeHandle()->UnsetTransparency(theIObj, theToUpdateViewer);
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
    void XAIS_InteractiveContext::SetLocalAttributes(Handle(AIS_InteractiveObject) theIObj, Handle(Prs3d_Drawer) theDrawer, Standard_Boolean theToUpdateViewer)
    {
        NativeHandle()->SetLocalAttributes(theIObj, theDrawer, theToUpdateViewer);
    };

    //=======================================================================
    //function : UnsetLocalAttributes
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::UnsetLocalAttributes(Handle(AIS_InteractiveObject) theIObj, Standard_Boolean theToUpdateViewer)
    {
        NativeHandle()->UnsetLocalAttributes(theIObj, theToUpdateViewer);
    };

    //=======================================================================
    //function : Status
    //purpose  :
    //=======================================================================
    void XAIS_InteractiveContext::Status(Handle(AIS_InteractiveObject) theIObj, TCollection_ExtendedString theStatus)
    {
        NativeHandle()->Status(theIObj, theStatus);
    };

    //=======================================================================
    //function : GetDefModes
    //purpose  :
    //=======================================================================
    //void XAIS_InteractiveContext::GetDefModes(Handle(AIS_InteractiveObject) theIObj, Standard_Integer& theDispMode, Standard_Integer& theHiMode, Standard_Integer& theSelMode)
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
    //void XAIS_InteractiveContext::EraseGlobal(Handle(AIS_InteractiveObject)& theIObj, Standard_Boolean theToUpdateviewer)
    //{
    //    NativeHandle()->EraseGlobal(theIObj, theToUpdateviewer);
    //};

    ////=======================================================================
    ////function : unselectOwners
    ////purpose  :
    ////=======================================================================
    //void XAIS_InteractiveContext::unselectOwners(Handle(AIS_InteractiveObject)& theObject)
    //{
    //    NativeHandle()->unselectOwners(theObject);
    //};

    ////=======================================================================
    ////function : ClearGlobal
    ////purpose  :
    ////=======================================================================
    //void XAIS_InteractiveContext::ClearGlobal(Handle(AIS_InteractiveObject)& theIObj, Standard_Boolean theToUpdateviewer)
    //{
    //    NativeHandle()->ClearGlobal(theIObj, theToUpdateviewer);
    //};

    ////=======================================================================
    ////function : ClearGlobalPrs
    ////purpose  :
    ////=======================================================================
    //void XAIS_InteractiveContext::ClearGlobalPrs(Handle(AIS_InteractiveObject)& theIObj, Standard_Integer theMode, Standard_Boolean theToUpdateViewer)
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
    //! In general this is just a wrapper for Handle(AIS_InteractiveObject)::DownCast(DetectedOwner()->Selectable()).
    //! @sa DetectedOwner()
    Handle(AIS_InteractiveObject) XAIS_InteractiveContext::DetectedInteractive() {
        return NativeHandle()->DetectedInteractive();
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
    void XAIS_InteractiveContext::SetIsoNumber(Standard_Integer theNb, AIS_TypeOfIso theType)
    {
        NativeHandle()->SetIsoNumber(theNb, theType);
    };

    //=======================================================================
    //function : IsoNumber
    //purpose  :
    //=======================================================================
    Standard_Integer XAIS_InteractiveContext::IsoNumber(AIS_TypeOfIso theType)
    {
        return NativeHandle()->IsoNumber(theType);
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
    void XAIS_InteractiveContext::SetSelectionSensitivity(Handle(AIS_InteractiveObject) theObject, Standard_Integer theMode, Standard_Integer theNewSensitivity)
    {
        NativeHandle()->SetSelectionSensitivity(theObject, theMode, theNewSensitivity);
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
    void XAIS_InteractiveContext::SetZLayer(Handle(AIS_InteractiveObject) theIObj, Graphic3d_ZLayerId theLayerId)
    {
        NativeHandle()->SetZLayer(theIObj, theLayerId);
    };

    //=======================================================================
    //function : GetZLayer
    //purpose  :
    //=======================================================================
    Graphic3d_ZLayerId XAIS_InteractiveContext::GetZLayer(Handle(AIS_InteractiveObject) theIObj)
    {
        return NativeHandle()->GetZLayer(theIObj);
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
    void XAIS_InteractiveContext::Disconnect(Handle(AIS_InteractiveObject) theAssembly, Handle(AIS_InteractiveObject) theObjToDisconnect)
    {
        NativeHandle()->Disconnect(theAssembly, theObjToDisconnect);
    };

    //=======================================================================
    //function : FitSelected
    //purpose  : Fits the view corresponding to the bounds of selected objects
    //=======================================================================
    void XAIS_InteractiveContext::FitSelected(Handle(V3d_View) theView)
    {
        FitSelected(theView, 0.01, Standard_True);
    };

    //=======================================================================
    //function : BoundingBoxOfSelection
    //purpose  :
    //=======================================================================
    Bnd_Box XAIS_InteractiveContext::BoundingBoxOfSelection()
    {
        return NativeHandle()->BoundingBoxOfSelection();
    };

    //=======================================================================
    //function : FitSelected
    //purpose  : Fits the view corresponding to the bounds of selected objects
    //=======================================================================
    void XAIS_InteractiveContext::FitSelected(Handle(V3d_View) theView, Standard_Real theMargin, Standard_Boolean theToUpdate)
    {
        NativeHandle()->FitSelected(theView, theMargin, theToUpdate);
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
    void XAIS_InteractiveContext::SetTransformPersistence(Handle(AIS_InteractiveObject) theObject, Handle(Graphic3d_TransformPers) theTrsfPers)
    {
        NativeHandle()->SetTransformPersistence(theObject, theTrsfPers);
    };

    //=======================================================================
    //function : GravityPoint
    //purpose  :
    //=======================================================================
    xgp_Pnt^ XAIS_InteractiveContext::GravityPoint(Handle(V3d_View) theView)
    {
        return gcnew xgp_Pnt(NativeHandle()->GravityPoint(theView));
    };
    ////=======================================================================
    ////function : setObjectStatus
    ////purpose  :
    ////=======================================================================
    //void XAIS_InteractiveContext::setObjectStatus(Handle(AIS_InteractiveObject)& theIObj, AIS_DisplayStatus theStatus, Standard_Integer theDispMode, Standard_Integer theSelectionMode)
    //{
    //    NativeHandle()->setObjectStatus(theIObj, theStatus, theDispMode, theSelectionMode);
    //};
}
