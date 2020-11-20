#include <XSelectMgr_SelectableObject.h>
namespace TKV3d {
    //!
    XSelectMgr_SelectableObject::XSelectMgr_SelectableObject() {

    };

    //!
    XSelectMgr_SelectableObject::XSelectMgr_SelectableObject(Handle(SelectMgr_SelectableObject) pos) {
        NativeHandle() = pos;
        SetBaseNativeHandle(NativeHandle());
    };

    //! 
    void XSelectMgr_SelectableObject::SetSelectMgr_SelectableObjectNativeHandle(Handle(SelectMgr_SelectableObject) pos) {
        NativeHandle() = pos;
        SetBaseNativeHandle(NativeHandle());
    };

    //! Clears all selections of the object
    XSelectMgr_SelectableObject::~XSelectMgr_SelectableObject() {
        NativeHandle()->~SelectMgr_SelectableObject();
    };

    //! Computes sensitive primitives for the given selection mode - key interface method of Selectable Object.
    //! @param theSelection selection to fill
    //! @param theMode selection mode to create sensitive primitives
    void XSelectMgr_SelectableObject::ComputeSelection(const Handle(SelectMgr_Selection)& theSelection, Standard_Integer theMode) {
        NativeHandle()->ComputeSelection(theSelection, theMode);
    };

    //! Informs the graphic context that the interactive Object may be decomposed into sub-shapes for dynamic selection.
    //! The most used Interactive Object is AIS_Shape.
    Standard_Boolean XSelectMgr_SelectableObject::AcceptShapeDecomposition() {
        return NativeHandle()->AcceptShapeDecomposition();
    }

    //! Re-computes the sensitive primitives for all modes. IMPORTANT: Do not use
    //! this method to update selection primitives except implementing custom selection manager!
    //! This method does not take into account necessary BVH updates, but may invalidate the pointers
    //! it refers to. TO UPDATE SELECTION properly from outside classes, use method UpdateSelection.
    void XSelectMgr_SelectableObject::RecomputePrimitives() {
        NativeHandle()->RecomputePrimitives();
    };

    //! Re-computes the sensitive primitives which correspond to the <theMode>th selection mode.
    //! IMPORTANT: Do not use this method to update selection primitives except implementing custom selection manager!
    //! selection manager! This method does not take into account necessary BVH updates, but may invalidate
    //! the pointers it refers to. TO UPDATE SELECTION properly from outside classes, use method UpdateSelection.
    void XSelectMgr_SelectableObject::RecomputePrimitives(const Standard_Integer theMode) {
        NativeHandle()->RecomputePrimitives(theMode);
    };

    //! Adds the selection aSelection with the selection mode
    //! index aMode to this framework.
    void XSelectMgr_SelectableObject::AddSelection(const Handle(SelectMgr_Selection)& aSelection, Standard_Integer aMode) {
        NativeHandle()->AddSelection(aSelection, aMode);
    };

    //! Empties all the selections in the SelectableObject
    //! <update> parameter defines whether all object's
    //! selections should be flagged for further update or not.
    //! This improved method can be used to recompute an
    //! object's selection (without redisplaying the object
    //! completely) when some selection mode is activated not for the first time.
    //! update = Standard_False
    void XSelectMgr_SelectableObject::ClearSelections(const Standard_Boolean update) {
        NativeHandle()->ClearSelections(update);
    };

    //! Returns the selection having specified selection mode or NULL.
    Handle(SelectMgr_Selection) XSelectMgr_SelectableObject::Selection(const Standard_Integer theMode) {
        return NativeHandle()->Selection(theMode);
    };

    //! Returns true if a selection corresponding to the selection mode theMode was computed for this object.
    Standard_Boolean XSelectMgr_SelectableObject::HasSelection(const Standard_Integer theMode) {
        return NativeHandle()->HasSelection(theMode);
    }

    //! Return the sequence of selections.
    SelectMgr_SequenceOfSelection XSelectMgr_SelectableObject::Selections() {
        return NativeHandle()->Selections();
    };

    void XSelectMgr_SelectableObject::ResetTransformation() {
        NativeHandle()->ResetTransformation();
    };

    //! Recomputes the location of the selection aSelection.
    void XSelectMgr_SelectableObject::UpdateTransformation() {
        NativeHandle()->UpdateTransformation();
    };

    //! Updates locations in all sensitive entities from <aSelection>
    //! and in corresponding entity owners.
    void XSelectMgr_SelectableObject::UpdateTransformations(const Handle(SelectMgr_Selection)& aSelection) {
        NativeHandle()->UpdateTransformations(aSelection);
    };

    //! Method which draws selected owners ( for fast presentation draw )
    void XSelectMgr_SelectableObject::HilightSelected(const Handle(PrsMgr_PresentationManager)& thePrsMgr, SelectMgr_SequenceOfOwner& theSeq) {
        NativeHandle()->HilightSelected(thePrsMgr, theSeq);
    };

    //! Method which clear all selected owners belonging
    //! to this selectable object ( for fast presentation draw )
    void XSelectMgr_SelectableObject::ClearSelected() {
        NativeHandle()->ClearSelected();
    };

    //! Method that needs to be implemented when the object
    //! manages selection and dynamic highlighting on its own.
    //! Clears or invalidates dynamic highlight presentation.
    //! By default it clears immediate draw of given presentation
    //! manager.
    void XSelectMgr_SelectableObject::ClearDynamicHighlight(const Handle(PrsMgr_PresentationManager)& theMgr) {
        NativeHandle()->ClearDynamicHighlight(theMgr);
    };

    //! Method which hilight an owner belonging to
    //! this selectable object  ( for fast presentation draw )
    void XSelectMgr_SelectableObject::HilightOwnerWithColor(const Handle(PrsMgr_PresentationManager)& thePM, Handle(Prs3d_Drawer)& theStyle, Handle(SelectMgr_EntityOwner)& theOwner) {
        NativeHandle()->HilightOwnerWithColor(thePM, theStyle, theOwner);
    };

    //! If returns True, the old mechanism for highlighting selected objects is used (HilightSelected Method may be empty).
    //! If returns False, the HilightSelected method will be fully responsible for highlighting selected entity owners belonging to this selectable object.
    Standard_Boolean XSelectMgr_SelectableObject::IsAutoHilight() {
        return NativeHandle()->IsAutoHilight();
    };

    //! Set AutoHilight property to true or false.
    void XSelectMgr_SelectableObject::SetAutoHilight(const Standard_Boolean theAutoHilight) {
        NativeHandle()->SetAutoHilight(theAutoHilight);
    };

    //! Creates or returns existing presentation for highlighting detected object.
    //! @param thePrsMgr presentation manager to create new presentation
    //! @return existing or newly created presentation (when thePrsMgr is not NULL)
    Handle(Prs3d_Presentation) XSelectMgr_SelectableObject::GetHilightPresentation(const Handle(PrsMgr_PresentationManager)& thePrsMgr) {
        return NativeHandle()->GetHilightPresentation(thePrsMgr);
    };

    //! Creates or returns existing presentation for highlighting selected object.
    //! @param thePrsMgr presentation manager to create new presentation
    //! @return existing or newly created presentation (when thePrsMgr is not NULL)
    Handle(Prs3d_Presentation) XSelectMgr_SelectableObject::GetSelectPresentation(const Handle(PrsMgr_PresentationManager)& thePrsMgr) {
        return NativeHandle()->GetSelectPresentation(thePrsMgr);
    };

    //! Removes presentations returned by GetHilightPresentation() and GetSelectPresentation().
    void XSelectMgr_SelectableObject::ErasePresentations(Standard_Boolean theToRemove) {
        NativeHandle()->ErasePresentations(theToRemove);
    };

    //! Set Z layer ID and update all presentations of the selectable object.
    //! The layers mechanism allows drawing objects in higher layers in overlay of objects in lower layers.
    void XSelectMgr_SelectableObject::SetZLayer(const Graphic3d_ZLayerId theLayerId) {
        NativeHandle()->SetZLayer(theLayerId);
    };

    //! Sets update status FULL to selections of the object. Must be used as the only method of UpdateSelection
    //! from outer classes to prevent BVH structures from being outdated.
    //! theMode = -1
    void XSelectMgr_SelectableObject::UpdateSelection(const Standard_Integer theMode) {
        NativeHandle()->UpdateSelection(theMode);
    };

    //! Sets common entity owner for assembly sensitive object entities
    //! theMode = -1
    void XSelectMgr_SelectableObject::SetAssemblyOwner(const Handle(SelectMgr_EntityOwner)& theOwner, Standard_Integer theModel) {
        NativeHandle()->SetAssemblyOwner(theOwner, theModel);
    };

    //! Returns a bounding box of sensitive entities with the owners given if they are a part of activated selection
    Bnd_Box XSelectMgr_SelectableObject::BndBoxOfSelected(const Handle(SelectMgr_IndexedMapOfOwner)& theOwners) {
        return NativeHandle()->BndBoxOfSelected(theOwners);
    };

    //! Returns the mode for selection of object as a whole; 0 by default.
    Standard_Integer XSelectMgr_SelectableObject::GlobalSelectionMode() {
        return NativeHandle()->GlobalSelectionMode();
    };

    //! Returns the owner of mode for selection of object as a whole
    Handle(SelectMgr_EntityOwner) XSelectMgr_SelectableObject::GlobalSelOwner() {
        return NativeHandle()->GlobalSelOwner();
    };

    //! Returns common entity owner if the object is an assembly
    Handle(SelectMgr_EntityOwner) XSelectMgr_SelectableObject::GetAssemblyOwner() {
        return NativeHandle()->GetAssemblyOwner();
    };

    //! Dumps the content of me into the stream
    //! theDepth = -1
    void XSelectMgr_SelectableObject::DumpJson(Standard_OStream& theOStream, Standard_Integer theDepth) {
        NativeHandle()->DumpJson(theOStream, theDepth);
    };
}
