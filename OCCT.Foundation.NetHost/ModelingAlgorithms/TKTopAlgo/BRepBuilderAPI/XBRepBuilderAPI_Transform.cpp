#include <XBRepBuilderAPI_Transform.h>
namespace TKTopAlgo {
	XBRepBuilderAPI_Transform::XBRepBuilderAPI_Transform() {
		//NativeHandle = new BRepBuilderAPI_Transform();
	};

	void XBRepBuilderAPI_Transform::SetTransformHandle(BRepBuilderAPI_Transform* handle) {
		NativeHandle = handle;
		SetModifyShapeHandle(NativeHandle);
	};

	BRepBuilderAPI_Transform* XBRepBuilderAPI_Transform::GetTransform() {
		return NativeHandle;
	};

	BRepBuilderAPI_ModifyShape* XBRepBuilderAPI_Transform::GetModifyShape() {
		return NativeHandle;
	};

	BRepBuilderAPI_MakeShape* XBRepBuilderAPI_Transform::GetMakeShape() {
		return NativeHandle;
	};

	//! Constructs a framework for applying the geometric
	//! transformation T to a shape. Use the function Perform
	//! to define the shape to transform.
	XBRepBuilderAPI_Transform::XBRepBuilderAPI_Transform(xgp_Trsf^ T) {
		NativeHandle = new BRepBuilderAPI_Transform(*T->GetTrsf());
		SetModifyShapeHandle(NativeHandle);
	};

	//! Creates a transformation from the gp_Trsf <T>, and
	//! applies it to the shape <S>. If the transformation
	//! is  direct   and isometric (determinant  =  1) and
	//! <Copy> =  Standard_False,  the resulting shape  is
	//! <S> on   which  a  new  location has    been  set.
	//! Otherwise,  the   transformation is applied   on a
	//! duplication of <S>.
	//! const Standard_Boolean Copy = Standard_False
	XBRepBuilderAPI_Transform::XBRepBuilderAPI_Transform(XTopoDS_Shape^ S, xgp_Trsf^ T, Standard_Boolean Copy) {
		NativeHandle = new BRepBuilderAPI_Transform(*S->GetShape(), *T->GetTrsf(), Copy);
		SetModifyShapeHandle(NativeHandle);
	};

	//! pplies the geometric transformation defined at the
	//! time of construction of this framework to the shape S.
	//! - If the transformation T is direct and isometric, in
	//! other words, if the determinant of the vectorial part
	//! of T is equal to 1., and if Copy equals false (the
	//! default value), the resulting shape is the same as
	//! the original but with a new location assigned to it.
	//! -   In all other cases, the transformation is applied to a duplicate of S.
	//! Use the function Shape to access the result.
	//! Note: this framework can be reused to apply the same
	//! geometric transformation to other shapes. You only
	//! need to specify them by calling the function Perform again.
	//! Standard_Boolean Copy = Standard_False
	void XBRepBuilderAPI_Transform::Perform(XTopoDS_Shape^ S, Standard_Boolean Copy) {
		NativeHandle->Perform(*S->GetShape(), Copy);
	};

	//! Returns the modified shape corresponding to <S>.
	XTopoDS_Shape^ XBRepBuilderAPI_Transform::ModifiedShape(XTopoDS_Shape^ S) {
		TopoDS_Shape* temp = new TopoDS_Shape(NativeHandle->ModifiedShape(*S->GetShape()));
		return gcnew XTopoDS_Shape(temp);
	};

	//! Returns the list  of shapes modified from the shape
	//! <S>.
	XTopTools_ListOfShape^ XBRepBuilderAPI_Transform::Modified(XTopoDS_Shape^ S) {
		TopTools_ListOfShape* temp = new TopTools_ListOfShape(NativeHandle->Modified(*S->GetShape()));
		return gcnew XTopTools_ListOfShape(temp);
	};
}