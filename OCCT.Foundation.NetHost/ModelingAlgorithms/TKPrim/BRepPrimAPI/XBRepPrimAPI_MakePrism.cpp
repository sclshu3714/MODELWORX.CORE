#include <XBRepPrimAPI_MakePrism.h>

namespace TKPrim {

	void XBRepPrimAPI_MakePrism::SetMakePrismHandle(BRepPrimAPI_MakePrism* pos) {
		NativeHandle = pos;
	};

	BRepPrimAPI_MakePrism* XBRepPrimAPI_MakePrism::GetMakePrism() {
		return NativeHandle;
	};

	BRepPrimAPI_MakeSweep* XBRepPrimAPI_MakePrism::GetMakeSweep() {
		return NativeHandle;
	};

	BRepBuilderAPI_MakeShape XBRepPrimAPI_MakePrism::GetMakeShape() {
		return *NativeHandle;
	};

	//! Builds the prism of base S and vector V. If C is true,
	//! S is copied. If Canonize is true then generated surfaces
	//! are attempted to be canonized in simple types
	//! const Standard_Boolean Copy = Standard_False, const Standard_Boolean Canonize = Standard_True
	XBRepPrimAPI_MakePrism::XBRepPrimAPI_MakePrism(XTopoDS_Shape^ S, xgp_Vec^ V, Standard_Boolean Copy, Standard_Boolean Canonize) {
		NativeHandle = new BRepPrimAPI_MakePrism(S->GetShape(), V->GetVec(), Copy, Canonize);
	};

	//! Builds a semi-infinite or an infinite prism of base S.
	//! If Inf is true the prism  is infinite, if Inf is false
	//! the prism is semi-infinite (in the direction D).  If C
	//! is true S is copied (for semi-infinite prisms).
	//! If Canonize is true then generated surfaces
	//! are attempted to be canonized in simple types
	//!  const Standard_Boolean Inf = Standard_True, const Standard_Boolean Copy = Standard_False, const Standard_Boolean Canonize = Standard_True
	XBRepPrimAPI_MakePrism::XBRepPrimAPI_MakePrism(XTopoDS_Shape^ S, xgp_Dir^ D, Standard_Boolean Inf, Standard_Boolean Copy, Standard_Boolean Canonize) {
		NativeHandle = new BRepPrimAPI_MakePrism(S->GetShape(), D->GetDir(), Inf, Copy, Canonize);
	};

	//! Returns the internal sweeping algorithm.
	BRepSweep_Prism XBRepPrimAPI_MakePrism::Prism() {
		return NativeHandle->Prism();
	};

	//! Builds the resulting shape (redefined from MakeShape).
	void XBRepPrimAPI_MakePrism::Build() {
		NativeHandle->Build();
	};

	//! Returns the  TopoDS  Shape of the bottom of the prism.
	XTopoDS_Shape^ XBRepPrimAPI_MakePrism::FirstShape() {
		return gcnew XTopoDS_Shape(NativeHandle->FirstShape());
	};

	//! Returns the TopoDS Shape of the top of the prism.
	//! In the case of a finite prism, FirstShape returns the
	//! basis of the prism, in other words, S if Copy is false;
	//! otherwise, the copy of S belonging to the prism.
	//! LastShape returns the copy of S translated by V at the
	//! time of construction.
	XTopoDS_Shape^ XBRepPrimAPI_MakePrism::LastShape() {
		return gcnew XTopoDS_Shape(NativeHandle->LastShape());
	};

	//! Returns ListOfShape from TopTools.
	XTopTools_ListOfShape^ XBRepPrimAPI_MakePrism::Generated(XTopoDS_Shape^ S) {
		return gcnew XTopTools_ListOfShape(NativeHandle->Generated(S->GetShape()));
	};

	//! Returns true if the shape S has been deleted.
	Standard_Boolean XBRepPrimAPI_MakePrism::IsDeleted(XTopoDS_Shape^ S) {
		return NativeHandle->IsDeleted(S->GetShape());
	};

	//! Returns the TopoDS Shape of the bottom  of the  prism.
	//! generated  with  theShape (subShape of the  generating shape).
	XTopoDS_Shape^ XBRepPrimAPI_MakePrism::FirstShape(XTopoDS_Shape^ theShape) {
		return gcnew XTopoDS_Shape(NativeHandle->FirstShape(theShape->GetShape()));
	};

	//! Returns the  TopoDS  Shape of the top  of  the  prism.
	//! generated  with  theShape (subShape of the  generating shape).
	XTopoDS_Shape^ XBRepPrimAPI_MakePrism::LastShape(XTopoDS_Shape^ theShape) {
		return gcnew XTopoDS_Shape(NativeHandle->LastShape(theShape->GetShape()));
	};

}

