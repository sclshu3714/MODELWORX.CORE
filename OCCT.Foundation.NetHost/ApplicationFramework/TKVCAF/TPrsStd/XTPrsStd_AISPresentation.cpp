#include "XTPrsStd_AISPresentation.h"

namespace TKVCAF {
	XTPrsStd_AISPresentation::XTPrsStd_AISPresentation(){
		NativeHandle() = new TPrsStd_AISPresentation();
		SetNativeHandle(NativeHandle());
	};

	XTPrsStd_AISPresentation::XTPrsStd_AISPresentation(Handle(TPrsStd_AISPresentation) pos) {
		NativeHandle() = pos;
		SetNativeHandle(NativeHandle());
	};

	Handle(TPrsStd_AISPresentation) XTPrsStd_AISPresentation::GetAISPresentation() {
		return NativeHandle();
	};

	//! Returns the GUID for TPrsStd_AISPresentation attributes.
	//! static
	const Standard_GUID& XTPrsStd_AISPresentation::GetID() {
		return  TPrsStd_AISPresentation::GetID();
	};

	//! Returns the GUID for TPrsStd_AISPresentation attributes.
	//! static 
	const XStandard_GUID^ XTPrsStd_AISPresentation::GetIDx() {
		return gcnew XStandard_GUID(TPrsStd_AISPresentation::GetID());
	};

	//! Creates or retrieves the presentation attribute on
	//! the label L, and sets the GUID driver.
	//! static 
	Handle(TPrsStd_AISPresentation) XTPrsStd_AISPresentation::Set(const TDF_Label& L, const Standard_GUID& driver) {
		return  TPrsStd_AISPresentation::Set(L, driver);
	};

	//! Creates or retrieves the presentation attribute on
	//! the label L, and sets the GUID driver.
	//! static 
	XTPrsStd_AISPresentation^ XTPrsStd_AISPresentation::Set(XTDF_Label^ L, XStandard_GUID^ driver) {
		return gcnew XTPrsStd_AISPresentation(TPrsStd_AISPresentation::Set(L->GetLabel(), driver->GetGUID()));
	};

	//! Delete (if exist) the presentation attribute associated to the label <L>.
	//! static 
	void XTPrsStd_AISPresentation::Unset(const TDF_Label& L) {
		TPrsStd_AISPresentation::Unset(L);
	};

	//! Delete (if exist) the presentation attribute associated to the label <L>.
	//! static 
	void XTPrsStd_AISPresentation::Unset(XTDF_Label^ L) {
		TPrsStd_AISPresentation::Unset(L->GetLabel());
	};

	//! Creates or retrieves the AISPresentation
	//! attribute attached to master.
	//! The GUID of the driver will be the GUID of master.
	//! master is the attribute you want to display.
	//! static 
	Handle(TPrsStd_AISPresentation) XTPrsStd_AISPresentation::Set(const Handle(TDF_Attribute)& master) {
		return TPrsStd_AISPresentation::Set(master);
	};

	//! Creates or retrieves the AISPresentation
	//! attribute attached to master.
	//! The GUID of the driver will be the GUID of master.
	//! master is the attribute you want to display.
	//! static 
	XTPrsStd_AISPresentation^ XTPrsStd_AISPresentation::Set(XTDF_Attribute^ master) {
		return gcnew XTPrsStd_AISPresentation(TPrsStd_AISPresentation::Set(master->GetAttribute()));
	};

	void XTPrsStd_AISPresentation::SetDisplayed(const Standard_Boolean B) {
		NativeHandle()->SetDisplayed(B);
	};

	//! Display presentation of object in AIS viewer.
	//! If <update> = True then AISObject is recomputed and all
	//! the visualization settings are applied
	//! update = Standard_False
	void XTPrsStd_AISPresentation::Display(const Standard_Boolean update) {
		NativeHandle()->Display(update);
	};

	//! Removes the presentation of this AIS
	//! presentation attribute from the TPrsStd_AISViewer.
	//! If remove is true, this AIS presentation attribute
	//! is removed from the interactive context.
	//! remove = Standard_False
	void XTPrsStd_AISPresentation::Erase(const Standard_Boolean remove) {
		NativeHandle()->Erase(remove);
	};

	//! Recompute presentation of object and apply the visualization settings
	void XTPrsStd_AISPresentation::Update() {
		NativeHandle()->Update();
	};

	Standard_GUID XTPrsStd_AISPresentation::GetDriverGUID() {
		return NativeHandle()->GetDriverGUID();
	};

	XStandard_GUID^ XTPrsStd_AISPresentation::GetDriverGUIDx() {
		return gcnew XStandard_GUID(NativeHandle()->GetDriverGUID());
	};

	void XTPrsStd_AISPresentation::SetDriverGUID(const Standard_GUID& guid) {
		NativeHandle()->SetDriverGUID(guid);
	};

	void XTPrsStd_AISPresentation::SetDriverGUID(XStandard_GUID^ guid) {
		NativeHandle()->SetDriverGUID(guid->GetGUID());
	};

	//! Returns true if this AIS presentation attribute is displayed.
	Standard_Boolean XTPrsStd_AISPresentation::IsDisplayed() {
		return NativeHandle()->IsDisplayed();
	};

	//! Returns AIS_InteractiveObject stored in the presentation attribute
	Handle(AIS_InteractiveObject) XTPrsStd_AISPresentation::GetAIS() {
		return NativeHandle()->GetAIS();
	};

	//! Returns AIS_InteractiveObject stored in the presentation attribute
	XAIS_InteractiveObject^ XTPrsStd_AISPresentation::GetAISx() {
		return gcnew XAIS_InteractiveObject(NativeHandle()->GetAIS());
	};

	//! Returns the material setting for this presentation attribute.
	Graphic3d_NameOfMaterial XTPrsStd_AISPresentation::Material() {
		return NativeHandle()->Material();
	};			   

	//! Sets the material aName for this presentation  attribute.
	void XTPrsStd_AISPresentation::SetMaterial(const Graphic3d_NameOfMaterial aName) {
		NativeHandle()->SetMaterial(aName);
	};

	//! Sets the material aName for this presentation  attribute.
	void XTPrsStd_AISPresentation::SetMaterial(const Standard_Integer aName) {
		NativeHandle()->SetMaterial(Graphic3d_NameOfMaterial(aName));
	};

	//! Returns true if this presentation attribute already has a material setting.
	Standard_Boolean XTPrsStd_AISPresentation::HasOwnMaterial() {
		return NativeHandle()->HasOwnMaterial();
	};

	//! Removes the material setting from this presentation attribute.
	void XTPrsStd_AISPresentation::UnsetMaterial() {
		NativeHandle()->UnsetMaterial();
	};


	//! Sets the transparency value aValue for this
	//! presentation attribute.
	//! This value is 0.6 by default.
	//! aValue = 0.6
	void XTPrsStd_AISPresentation::SetTransparency(const Standard_Real aValue) {
		NativeHandle()->SetTransparency(aValue);
	};

	Standard_Real XTPrsStd_AISPresentation::Transparency() {
		return NativeHandle()->Transparency();
	};

	//! Returns true if this presentation attribute already has a transparency setting.
	Standard_Boolean XTPrsStd_AISPresentation::HasOwnTransparency() {
		return NativeHandle()->HasOwnTransparency();
	};

	//! Removes the transparency setting from this presentation attribute.
	void XTPrsStd_AISPresentation::UnsetTransparency() {
		NativeHandle()->UnsetTransparency();
	};

	Quantity_NameOfColor XTPrsStd_AISPresentation::Color() {
		return NativeHandle()->Color();
	};

	//! Sets the color aColor for this presentation attribute.
	void XTPrsStd_AISPresentation::SetColor(const Quantity_NameOfColor aColor) {
		NativeHandle()->SetColor(aColor);
	};

	//! Returns true if this presentation attribute already has a color setting.
	Standard_Boolean XTPrsStd_AISPresentation::HasOwnColor() {
		return NativeHandle()->HasOwnColor();
	};

	//! Removes the color setting from this presentation attribute.
	void XTPrsStd_AISPresentation::UnsetColor() {
		NativeHandle()->UnsetColor();
	};

	Standard_Real XTPrsStd_AISPresentation::Width() {
		return NativeHandle()->Width();
	};

	//! Sets the width aWidth for this presentation attribute.
	void XTPrsStd_AISPresentation::SetWidth(const Standard_Real aWidth) {
		NativeHandle()->SetWidth(aWidth);
	};

	//! Returns true if this presentation attribute already has a width setting.
	Standard_Boolean XTPrsStd_AISPresentation::HasOwnWidth() {
		return NativeHandle()->HasOwnWidth();
	};

	//! Removes the width setting from this presentation attribute.
	void XTPrsStd_AISPresentation::UnsetWidth() {
		NativeHandle()->UnsetWidth();
	};

	Standard_Integer XTPrsStd_AISPresentation::Mode() {
		return NativeHandle()->Mode();
	};

	void XTPrsStd_AISPresentation::SetMode(const Standard_Integer theMode) {
		NativeHandle()->SetMode(theMode);
	};

	Standard_Boolean XTPrsStd_AISPresentation::HasOwnMode() {
		return NativeHandle()->HasOwnMode();
	};

	void XTPrsStd_AISPresentation::UnsetMode() {
		NativeHandle()->UnsetMode();
	};

	//! Returns selection mode(s) of the attribute.
	//! It starts with 1 .. GetNbSelectionModes().
	Standard_Integer XTPrsStd_AISPresentation::GetNbSelectionModes() {
		return NativeHandle()->GetNbSelectionModes();
	};
	//£¡index = 1
	Standard_Integer XTPrsStd_AISPresentation::SelectionMode(const int index) {
		return NativeHandle()->SelectionMode(index);
	};

	//! Sets selection mode.
	//! If "theTransaction" flag is OFF, modification of the attribute doesn't influence the transaction mechanism
	//! (the attribute doesn't participate in undo/redo because of this modification).
	//! Certainly, if any other data of the attribute is modified (display mode, color, ...),
	//! the attribute will be included into undo/redo.
	//! theTransaction = Standard_True
	void XTPrsStd_AISPresentation::SetSelectionMode(const Standard_Integer theSelectionMode, const Standard_Boolean theTransaction) {
		NativeHandle()->SetSelectionMode(theSelectionMode, theTransaction);
	};
	//! theTransaction = Standard_True
	void XTPrsStd_AISPresentation::AddSelectionMode(const Standard_Integer theSelectionMode, const Standard_Boolean theTransaction) {
		NativeHandle()->AddSelectionMode(theSelectionMode, theTransaction);
	};

	Standard_Boolean XTPrsStd_AISPresentation::HasOwnSelectionMode() {
		return NativeHandle()->HasOwnSelectionMode();
	};

	//! Clears all selection modes of the attribute.
	void XTPrsStd_AISPresentation::UnsetSelectionMode() {
		NativeHandle()->UnsetSelectionMode();
	};


	XStandard_GUID^ XTPrsStd_AISPresentation::ID() {
		return gcnew XStandard_GUID(NativeHandle()->ID());
	};

	XTDF_Attribute^ XTPrsStd_AISPresentation::NewEmpty() {
		return gcnew XTDF_Attribute(NativeHandle()->NewEmpty());
	};

	void XTPrsStd_AISPresentation::Restore(XTDF_Attribute^ with) {
		NativeHandle()->Restore(with->GetAttribute());
	};

	void XTPrsStd_AISPresentation::Paste(XTDF_Attribute^ into, Handle(TDF_RelocationTable)& RT) {
		NativeHandle()->Paste(into->GetAttribute(), RT);
	};

	XTDF_Attribute^ XTPrsStd_AISPresentation::BackupCopy() {
		return gcnew XTDF_Attribute(NativeHandle()->BackupCopy());
	};

	void XTPrsStd_AISPresentation::AfterAddition() {
		NativeHandle()->AfterAddition();
	};

	void XTPrsStd_AISPresentation::BeforeRemoval() {
		NativeHandle()->BeforeRemoval();
	};

	void XTPrsStd_AISPresentation::BeforeForget() {
		NativeHandle()->BeforeForget();
	};

	void XTPrsStd_AISPresentation::AfterResume() {
		NativeHandle()->AfterResume();
	};

	//forceIt = Standard_False
	Standard_Boolean XTPrsStd_AISPresentation::BeforeUndo(const Handle(TDF_AttributeDelta)& anAttDelta, const Standard_Boolean forceIt) {
		return NativeHandle()->BeforeUndo(anAttDelta, forceIt);
	};

	//! update AIS viewer according to delta
	//! forceIt = Standard_False
	Standard_Boolean XTPrsStd_AISPresentation::AfterUndo(const Handle(TDF_AttributeDelta)& anAttDelta, const Standard_Boolean forceIt) {
		return NativeHandle()->AfterUndo(anAttDelta, forceIt);
	};
}