#include <XBRepBuilderAPI_GTransform.h>
namespace TKTopAlgo {
	XBRepBuilderAPI_GTransform::XBRepBuilderAPI_GTransform() {
		//NativeHandle = new BRepBuilderAPI_GTransform();
	};

	void XBRepBuilderAPI_GTransform::SetGTransformHandle(BRepBuilderAPI_GTransform* handle) {
		NativeHandle = handle;
		SetModifyShapeHandle(NativeHandle);
	};

	BRepBuilderAPI_GTransform* XBRepBuilderAPI_GTransform::GetGTransform() {
		return NativeHandle;
	};

	BRepBuilderAPI_ModifyShape* XBRepBuilderAPI_GTransform::GetModifyShape() {
		return NativeHandle;
	};

	BRepBuilderAPI_MakeShape* XBRepBuilderAPI_GTransform::GetMakeShape() {
		return NativeHandle;
	};

	//! Constructs a framework for applying the geometric
	//! transformation T to a shape. Use the function
	//! Perform to define the shape to transform.
	XBRepBuilderAPI_GTransform::XBRepBuilderAPI_GTransform(xgp_GTrsf^ T) {
		NativeHandle = new BRepBuilderAPI_GTransform(*T->GetGTrsf());
		SetModifyShapeHandle(NativeHandle);
	};

	//! Constructs a framework for applying the geometric
	//! transformation T to a shape, and applies it to the shape S.
	//! -   If the transformation T is direct and isometric (i.e. if
	//! the determinant of the vectorial part of T is equal to
	//! 1.), and if Copy equals false (default value), the
	//! resulting shape is the same as the original but with
	//! a new location assigned to it.
	//! -   In all other cases, the transformation is applied to
	//! a duplicate of S.
	//! Use the function Shape to access the result.
	//! Note: the constructed framework can be reused to
	//! apply the same geometric transformation to other
	//! shapes: just specify them with the function Perform.
	//! const Standard_Boolean Copy = Standard_False
	XBRepBuilderAPI_GTransform::XBRepBuilderAPI_GTransform(XTopoDS_Shape^ S, xgp_GTrsf^ T, Standard_Boolean Copy) {
		NativeHandle = new BRepBuilderAPI_GTransform(*S->GetShape(), *T->GetGTrsf(), Copy);
		SetModifyShapeHandle(NativeHandle);
	};

	//! Applies the geometric transformation defined at the
	//! time of construction of this framework to the shape S.
	//! -   If the transformation T is direct and isometric (i.e. if
	//! the determinant of the vectorial part of T is equal to
	//! 1.), and if Copy equals false (default value), the
	//! resulting shape is the same as the original but with
	//! a new location assigned to it.
	//! -   In all other cases, the transformation is applied to a duplicate of S.
	//! Use the function Shape to access the result.
	//! Note: this framework can be reused to apply the same
	//! geometric transformation to other shapes: just specify
	//! them by calling the function Perform again.
	//!  const Standard_Boolean Copy = Standard_False
	void XBRepBuilderAPI_GTransform::Perform(XTopoDS_Shape^ S, Standard_Boolean Copy) {
		NativeHandle->Perform(*S->GetShape(), Copy);
	};

	//! Returns the list  of shapes modified from the shape
	//! <S>.
	XTopTools_ListOfShape^ XBRepBuilderAPI_GTransform::Modified(XTopoDS_Shape^ S) {
		TopTools_ListOfShape* temp = new TopTools_ListOfShape(NativeHandle->Modified(*S->GetShape()));
		return gcnew XTopTools_ListOfShape(temp);
	};

	//! Returns the modified shape corresponding to <S>.
	XTopoDS_Shape^ XBRepBuilderAPI_GTransform::ModifiedShape(XTopoDS_Shape^ S) {
		TopoDS_Shape* temp = new TopoDS_Shape(NativeHandle->ModifiedShape(*S->GetShape()));
		return gcnew XTopoDS_Shape(temp);
	};
}