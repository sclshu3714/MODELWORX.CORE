#include <XBRepBuilderAPI_NurbsConvert.h>
namespace TKTopAlgo {
	void XBRepBuilderAPI_NurbsConvert::SetNurbsConvertHandle(BRepBuilderAPI_NurbsConvert* handle) {
		NativeHandle = handle;
		SetModifyShapeHandle(NativeHandle);
	};

	BRepBuilderAPI_NurbsConvert* XBRepBuilderAPI_NurbsConvert::GetNurbsConvert() {
		return NativeHandle;
	};

	BRepBuilderAPI_ModifyShape* XBRepBuilderAPI_NurbsConvert::GetModifyShape() {
		return NativeHandle;
	};

	BRepBuilderAPI_MakeShape* XBRepBuilderAPI_NurbsConvert::GetMakeShape() {
		return NativeHandle;
	};

	//! Constructs a framework for converting the geometry of a
	//! shape into NURBS geometry. Use the function Perform
	//! to define the shape to convert.
	XBRepBuilderAPI_NurbsConvert::XBRepBuilderAPI_NurbsConvert() {
		NativeHandle = new BRepBuilderAPI_NurbsConvert();
		SetModifyShapeHandle(NativeHandle);
	};

	//! Builds a new shape by converting the geometry of the
	//! shape S into NURBS geometry. Specifically, all curves
	//! supporting edges of S are converted into BSpline
	//! curves, and all surfaces supporting its faces are
	//! converted into BSpline surfaces.
	//! Use the function Shape to access the new shape.
	//! Note: theructed framework can be reused to
	//! convert other shapes. You specify these with the
	//! function Perform.
	//! Standard_Boolean Copy = Standard_False
	XBRepBuilderAPI_NurbsConvert::XBRepBuilderAPI_NurbsConvert(XTopoDS_Shape^ S, Standard_Boolean Copy) {
		NativeHandle = new BRepBuilderAPI_NurbsConvert(*S->GetShape(), Copy);
		SetModifyShapeHandle(NativeHandle);
	};

	//! Builds a new shape by converting the geometry of the
	//! shape S into NURBS geometry.
	//! Specifically, all curves supporting edges of S are
	//! converted into BSpline curves, and all surfaces
	//! supporting its faces are converted into BSpline surfaces.
	//! Use the function Shape to access the new shape.
	//! Note: this framework can be reused to convert other
	//! shapes: you specify them by calling the function Perform again.
	//! Standard_Boolean Copy = Standard_False
	void XBRepBuilderAPI_NurbsConvert::Perform(XTopoDS_Shape^ S, Standard_Boolean Copy) {
		NativeHandle->Perform(*S->GetShape(), Copy);
	};


	//! Returns the list  of shapes modified from the shape
	//! <S>.
	XTopTools_ListOfShape^ XBRepBuilderAPI_NurbsConvert::Modified(XTopoDS_Shape^ S) {
		TopTools_ListOfShape* temp = new TopTools_ListOfShape(NativeHandle->Modified(*S->GetShape()));
		return gcnew XTopTools_ListOfShape(temp);
	};

	//! Returns the modified shape corresponding to <S>.
	//! S can correspond to the entire initial shape or to its subshape.
	//! Exceptions
	//! Standard_NoSuchObject if S is not the initial shape or
	//! a subshape of the initial shape to which the
	//! transformation has been applied. 
	XTopoDS_Shape^ XBRepBuilderAPI_NurbsConvert::ModifiedShape(XTopoDS_Shape^ S) {
		TopoDS_Shape* temp = new TopoDS_Shape(NativeHandle->ModifiedShape(*S->GetShape()));
		return gcnew XTopoDS_Shape(temp);
	};
}