#include "XXCAFDoc_DocumentTool.h"

namespace TKXCAF {
	//! static 
	XStandard_GUID^ XXCAFDoc_DocumentTool::GetID() {
		return gcnew XStandard_GUID(XCAFDoc_DocumentTool::GetID());
	};

	//! Create (if not exist) DocumentTool attribute
	//! on 0.1 label if <IsAcces> is true, else
	//! on <L> label.
	//! This label will be returned by DocLabel();
	//! If the attribute is already set it won't be reset on
	//! <L> even if <IsAcces> is false.
	//! ColorTool and ShapeTool attributes are also set by this method.
	//! IsAcces = Standard_True
	//! static 
	XXCAFDoc_DocumentTool^ XXCAFDoc_DocumentTool::Set(XTDF_Label^ L, Standard_Boolean IsAcces) {
		return gcnew XXCAFDoc_DocumentTool(XCAFDoc_DocumentTool::Set(L->GetLabel(), IsAcces));
	};

	//! static 
	Standard_Boolean XXCAFDoc_DocumentTool::IsXCAFDocument(const Handle(TDocStd_Document)& Doc) {
		return XCAFDoc_DocumentTool::IsXCAFDocument(Doc);
	};

	//! Returns label where the DocumentTool attribute is or
	//! 0.1 if DocumentTool is not yet set.
	//! static 
	XTDF_Label^ XXCAFDoc_DocumentTool::DocLabel(XTDF_Label^ acces) {
		return gcnew XTDF_Label(XCAFDoc_DocumentTool::DocLabel(acces->GetLabel()));
	};

	//! Returns sub-label of DocLabel() with tag 1.
	//! static 
	XTDF_Label^ XXCAFDoc_DocumentTool::ShapesLabel(XTDF_Label^ acces) {
		return gcnew XTDF_Label(XCAFDoc_DocumentTool::ShapesLabel(acces->GetLabel()));
	};

	//! Returns sub-label of DocLabel() with tag 2.
	//! static 
	XTDF_Label^ XXCAFDoc_DocumentTool::ColorsLabel(XTDF_Label^ acces) {
		return gcnew XTDF_Label(XCAFDoc_DocumentTool::ColorsLabel(acces->GetLabel()));
	};

	//! Returns sub-label of DocLabel() with tag 3.
	//! static 
	XTDF_Label^ XXCAFDoc_DocumentTool::LayersLabel(XTDF_Label^ acces) {
		return gcnew XTDF_Label(XCAFDoc_DocumentTool::LayersLabel(acces->GetLabel()));
	};

	//! Returns sub-label of DocLabel() with tag 4.
	//! static 
	XTDF_Label^ XXCAFDoc_DocumentTool::DGTsLabel(XTDF_Label^ acces) {
		return gcnew XTDF_Label(XCAFDoc_DocumentTool::DGTsLabel(acces->GetLabel()));
	};

	//! Returns sub-label of DocLabel() with tag 5.
	//! static 
	XTDF_Label^ XXCAFDoc_DocumentTool::MaterialsLabel(XTDF_Label^ acces) {
		return gcnew XTDF_Label(XCAFDoc_DocumentTool::MaterialsLabel(acces->GetLabel()));
	};

	//! Returns sub-label of DocLabel() with tag 7.
	//! static 
	XTDF_Label^ XXCAFDoc_DocumentTool::ViewsLabel(XTDF_Label^ acces) {
		return gcnew XTDF_Label(XCAFDoc_DocumentTool::ViewsLabel(acces->GetLabel()));
	};

	//! Returns sub-label of DocLabel() with tag 8.
	//! static 
	XTDF_Label^ XXCAFDoc_DocumentTool::ClippingPlanesLabel(XTDF_Label^ acces) {
		return gcnew XTDF_Label(XCAFDoc_DocumentTool::ClippingPlanesLabel(acces->GetLabel()));
	};

	//! Returns sub-label of DocLabel() with tag 9.
	//! static 
	XTDF_Label^ XXCAFDoc_DocumentTool::NotesLabel(XTDF_Label^ acces) {
		return gcnew XTDF_Label(XCAFDoc_DocumentTool::NotesLabel(acces->GetLabel()));
	};

	//! Creates (if it does not exist) ShapeTool attribute on ShapesLabel().
	//! static 
	XXCAFDoc_ShapeTool^ XXCAFDoc_DocumentTool::ShapeTool(XTDF_Label^ acces) {
		return gcnew XXCAFDoc_ShapeTool(XCAFDoc_DocumentTool::ShapeTool(acces->GetLabel()));
	};

	//! Creates (if it does not exist) ColorTool attribute on ColorsLabel().
	//! static 
	Handle(XCAFDoc_ColorTool) XXCAFDoc_DocumentTool::ColorTool(XTDF_Label^ acces) {
		return XCAFDoc_DocumentTool::ColorTool(acces->GetLabel());
	};

	//! Creates (if it does not exist) LayerTool attribute on LayersLabel().
	//! static 
	Handle(XCAFDoc_LayerTool) XXCAFDoc_DocumentTool::LayerTool(XTDF_Label^ acces) {
		return XCAFDoc_DocumentTool::LayerTool(acces->GetLabel());
	};

	//! Creates (if it does not exist) DimTolTool attribute on DGTsLabel().
	//! static 
	Handle(XCAFDoc_DimTolTool) XXCAFDoc_DocumentTool::DimTolTool(XTDF_Label^ acces){
		return XCAFDoc_DocumentTool::DimTolTool(acces->GetLabel());
	};

	//! Creates (if it does not exist) DimTolTool attribute on DGTsLabel().
	//! static 
	Handle(XCAFDoc_MaterialTool) XXCAFDoc_DocumentTool::MaterialTool(XTDF_Label^ acces) {
		return XCAFDoc_DocumentTool::MaterialTool(acces->GetLabel());
	};

	//! Creates (if it does not exist) ViewTool attribute on ViewsLabel().
	//! static 
	Handle(XCAFDoc_ViewTool) XXCAFDoc_DocumentTool::ViewTool(XTDF_Label^ acces) {
		return XCAFDoc_DocumentTool::ViewTool(acces->GetLabel());
	};

	//! Creates (if it does not exist) ClippingPlaneTool attribute on ClippingPlanesLabel().
	//! static 
	Handle(XCAFDoc_ClippingPlaneTool) XXCAFDoc_DocumentTool::ClippingPlaneTool(XTDF_Label^ acces) {
		return XCAFDoc_DocumentTool::ClippingPlaneTool(acces->GetLabel());
	};

	//! Creates (if it does not exist) NotesTool attribute on NotesLabel().
	//! static 
	Handle(XCAFDoc_NotesTool) XXCAFDoc_DocumentTool::NotesTool(XTDF_Label^ acces) {
		return XCAFDoc_DocumentTool::NotesTool(acces->GetLabel());
	};

	XXCAFDoc_DocumentTool::XXCAFDoc_DocumentTool() {
		NativeHandle() = new XCAFDoc_DocumentTool();
	};

	//! to be called when reading this attribute from file
	void XXCAFDoc_DocumentTool::Init() {
		NativeHandle()->Init();
	};

	//!
	XXCAFDoc_DocumentTool::XXCAFDoc_DocumentTool(Handle(XCAFDoc_DocumentTool) pos) {
		NativeHandle() = pos;
	};

	XStandard_GUID^ XXCAFDoc_DocumentTool::ID() {
		return gcnew XStandard_GUID(NativeHandle()->ID());
	};

	void XXCAFDoc_DocumentTool::Restore(XTDF_Attribute^ with) {
		NativeHandle()->Restore(with->GetAttribute());
	};

	XTDF_Attribute^ XXCAFDoc_DocumentTool::NewEmpty() {
		return gcnew XTDF_Attribute(NativeHandle()->NewEmpty());
	};

	void XXCAFDoc_DocumentTool::Paste(XTDF_Attribute^ into, Handle(TDF_RelocationTable)& RT) {
		NativeHandle()->Paste(into->GetAttribute(), RT);
	};

	Handle(XCAFDoc_DocumentTool) XXCAFDoc_DocumentTool::GetDocumentTool() {
		return NativeHandle();
	};
	//£¡
	Handle(TDF_Attribute) XXCAFDoc_DocumentTool::GetAttribute() {
		return NativeHandle();
	};
}