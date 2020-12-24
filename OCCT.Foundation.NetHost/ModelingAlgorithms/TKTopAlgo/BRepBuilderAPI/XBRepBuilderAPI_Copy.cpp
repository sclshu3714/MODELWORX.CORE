#include <XBRepBuilderAPI_Copy.h>
namespace TKTopAlgo {
	//! DEFINE_STANDARD_ALLOC
	//! Constructs an empty copy framework. Use the function
	//! Perform to copy shapes.
	XBRepBuilderAPI_Copy::XBRepBuilderAPI_Copy() {
		NativeHandle = new BRepBuilderAPI_Copy();
		SetModifyShapeHandle(NativeHandle);
	};

	void XBRepBuilderAPI_Copy::SetCopyHandle(BRepBuilderAPI_Copy* handle) {
		NativeHandle = handle;
		SetModifyShapeHandle(NativeHandle);
	};

	BRepBuilderAPI_Copy* XBRepBuilderAPI_Copy::GetCopy() {
		return NativeHandle;
	};

	BRepBuilderAPI_ModifyShape* XBRepBuilderAPI_Copy::GetModifyShape() {
		return NativeHandle;
	};

	BRepBuilderAPI_MakeShape* XBRepBuilderAPI_Copy::GetMakeShape() {
		return NativeHandle;
	};

	//! Constructs a copy framework and copies the shape S.
	//! Use the function Shape to access the result.
	//! If copyMesh is True, triangulation contained in original shape will be 
	//! copied along with geometry (by default, triangulation gets lost).
	//! If copyGeom is False, only topological objects will be copied, while 
	//! geometry and triangulation will be shared with original shape.
	//! Note: the constructed framework can be reused to copy
	//! other shapes: just specify them with the function Perform.
	//! const Standard_Boolean copyGeom = Standard_True, const Standard_Boolean copyMesh = Standard_False
	XBRepBuilderAPI_Copy::XBRepBuilderAPI_Copy(XTopoDS_Shape^ S, Standard_Boolean copyGeom, Standard_Boolean copyMesh) {
		NativeHandle = new BRepBuilderAPI_Copy(*S->GetShape(), copyGeom, copyMesh);
		SetModifyShapeHandle(NativeHandle);
	};

	//! Copies the shape S.
	//! Use the function Shape to access the result.
	//! If copyMesh is True, triangulation contained in original shape will be 
	//! copied along with geometry (by default, triangulation gets lost).
	//! If copyGeom is False, only topological objects will be copied, while 
	//! geometry and triangulation will be shared with original shape.
	//! const Standard_Boolean copyGeom = Standard_True, const Standard_Boolean copyMesh = Standard_False
	void XBRepBuilderAPI_Copy::Perform(XTopoDS_Shape^ S, Standard_Boolean copyGeom, Standard_Boolean copyMesh) {
		NativeHandle->Perform(*S->GetShape(), copyGeom, copyMesh);
	};
}