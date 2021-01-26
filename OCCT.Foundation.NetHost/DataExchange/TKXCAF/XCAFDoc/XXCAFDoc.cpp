#include "XXCAFDoc.h"

namespace TKXCAF {
	//! class for containing GraphNodes.
		//! Returns GUID for UAttribute identifying assembly
	XStandard_GUID^ XXCAFDoc::AssemblyGUID() {
		return gcnew XStandard_GUID(XCAFDoc::AssemblyGUID());
	};

	//! Returns GUID for TreeNode representing assembly link
	XStandard_GUID^ XXCAFDoc::ShapeRefGUID() {
		return gcnew XStandard_GUID(XCAFDoc::ShapeRefGUID());
	};

	//! Return GUIDs for TreeNode representing specified types of colors
	XStandard_GUID^ XXCAFDoc::ColorRefGUID(XXCAFDoc_ColorType type) {
		return gcnew XStandard_GUID(XCAFDoc::ColorRefGUID(safe_cast<XCAFDoc_ColorType>(type)));
	};

	//! Return GUIDs for TreeNode representing specified types of DGT
	XStandard_GUID^ XXCAFDoc::DimTolRefGUID() {
		return gcnew XStandard_GUID(XCAFDoc::DimTolRefGUID());
	};

	//! Return GUIDs for TreeNode representing specified types of Dimension
	XStandard_GUID^ XXCAFDoc::DimensionRefFirstGUID() {
		return gcnew XStandard_GUID(XCAFDoc::DimensionRefFirstGUID());
	};

	//! Return GUIDs for TreeNode representing specified types of Dimension
	XStandard_GUID^ XXCAFDoc::DimensionRefSecondGUID() {
		return gcnew XStandard_GUID(XCAFDoc::DimensionRefSecondGUID());
	};

	//! Return GUIDs for TreeNode representing specified types of GeomTolerance
	XStandard_GUID^ XXCAFDoc::GeomToleranceRefGUID() {
		return gcnew XStandard_GUID(XCAFDoc::GeomToleranceRefGUID());
	};

	//! Return GUIDs for TreeNode representing specified types of datum
	XStandard_GUID^ XXCAFDoc::DatumRefGUID() {
		return gcnew XStandard_GUID(XCAFDoc::DatumRefGUID());
	};

	//! Return GUIDs for TreeNode representing connections Datum-Toler
	XStandard_GUID^ XXCAFDoc::DatumTolRefGUID() {
		return gcnew XStandard_GUID(XCAFDoc::DatumTolRefGUID());
	};

	XStandard_GUID^ XXCAFDoc::LayerRefGUID() {
		return gcnew XStandard_GUID(XCAFDoc::ShapeRefGUID());
	};

	XStandard_GUID^ XXCAFDoc::MaterialRefGUID() {
		return gcnew XStandard_GUID(XCAFDoc::MaterialRefGUID());
	};

	//! Return GUIDs for representing notes
	XStandard_GUID^ XXCAFDoc::NoteRefGUID() {
		return gcnew XStandard_GUID(XCAFDoc::NoteRefGUID());
	};

	XStandard_GUID^ XXCAFDoc::InvisibleGUID() {
		return gcnew XStandard_GUID(XCAFDoc::ShapeRefGUID());
	};

	XStandard_GUID^ XXCAFDoc::ColorByLayerGUID() {
		return gcnew XStandard_GUID(XCAFDoc::ColorByLayerGUID());
	};

	//! Returns GUID for UAttribute identifying external reference on no-step file
	XStandard_GUID^ XXCAFDoc::ExternRefGUID() {
		return gcnew XStandard_GUID(XCAFDoc::ShapeRefGUID());
	};

	//! Returns GUID for UAttribute identifying specified higher usage occurrence
	XStandard_GUID^ XXCAFDoc::SHUORefGUID() {
		return gcnew XStandard_GUID(XCAFDoc::SHUORefGUID());
	};

	//! Return GUIDs for TreeNode representing specified types of View
	XStandard_GUID^ XXCAFDoc::ViewRefGUID() {
		return gcnew XStandard_GUID(XCAFDoc::ViewRefGUID());
	};

	//! Return GUIDs for TreeNode representing specified types of View
	XStandard_GUID^ XXCAFDoc::ViewRefShapeGUID() {
		return gcnew XStandard_GUID(XCAFDoc::ViewRefShapeGUID());
	};

	//! Return GUIDs for TreeNode representing specified types of View
	XStandard_GUID^ XXCAFDoc::ViewRefGDTGUID() {
		return gcnew XStandard_GUID(XCAFDoc::ViewRefGDTGUID());
	};

	//! Return GUIDs for TreeNode representing specified types of View
	XStandard_GUID^ XXCAFDoc::ViewRefPlaneGUID() {
		return gcnew XStandard_GUID(XCAFDoc::ViewRefPlaneGUID());
	};

	//! Return GUIDs for GraphNode representing specified types of View
	XStandard_GUID^ XXCAFDoc::ViewRefNoteGUID() {
		return gcnew XStandard_GUID(XCAFDoc::ViewRefNoteGUID());
	};
	XStandard_GUID^ XXCAFDoc::ViewRefAnnotationGUID() {
		return gcnew XStandard_GUID(XCAFDoc::ViewRefAnnotationGUID());
	};

	//! Returns GUID for UAttribute identifying lock flag
	XStandard_GUID^ XXCAFDoc::LockGUID() {
		return gcnew XStandard_GUID(XCAFDoc::LockGUID());
	};
}