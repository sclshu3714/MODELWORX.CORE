#include <XBRepBuilderAPI_ModifyShape.h>
namespace TKTopAlgo {
	//! DEFINE_STANDARD_ALLOC
	XBRepBuilderAPI_ModifyShape::XBRepBuilderAPI_ModifyShape() {
		//NativeHandle = new BRepBuilderAPI_ModifyShape();
	};

	void XBRepBuilderAPI_ModifyShape::SetModifyShapeHandle(BRepBuilderAPI_ModifyShape* handle) {
		NativeHandle = handle;
		SetMakeShapeHandle(NativeHandle);
	};

	BRepBuilderAPI_ModifyShape* XBRepBuilderAPI_ModifyShape::GetModifyShape() {
		return NativeHandle;
	};

	BRepBuilderAPI_MakeShape* XBRepBuilderAPI_ModifyShape::GetMakeShape() {
		return NativeHandle;
	};

	//! Returns the list  of shapes modified from the shape
	//! <S>.
	XTopTools_ListOfShape^ XBRepBuilderAPI_ModifyShape::Modified(XTopoDS_Shape^ S) {
		TopTools_ListOfShape* temp = new TopTools_ListOfShape(NativeHandle->Modified(*S->GetShape()));
		return gcnew XTopTools_ListOfShape(temp);
	};

	//! Returns the modified shape corresponding to <S>.
	//! S can correspond to the entire initial shape or to its subshape.
	//! Exceptions
	//! Standard_NoSuchObject if S is not the initial shape or
	//! a subshape of the initial shape to which the
	//! transformation has been applied. Raises NoSuchObject from Standard
	//! if S is not the initial shape or a sub-shape
	//! of the initial shape.
	XTopoDS_Shape^ XBRepBuilderAPI_ModifyShape::ModifiedShape(XTopoDS_Shape^ S) {
		TopoDS_Shape* temp = new TopoDS_Shape(NativeHandle->ModifiedShape(*S->GetShape()));
		return gcnew XTopoDS_Shape(temp);
	};
}