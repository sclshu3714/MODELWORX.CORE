#include <XBRepPrimAPI_MakeRevol.h>
namespace TKPrim {

	XBRepPrimAPI_MakeRevol::XBRepPrimAPI_MakeRevol() {
		//NativeHandle = new BRepPrimAPI_MakeRevol();
	};

	XBRepPrimAPI_MakeRevol::XBRepPrimAPI_MakeRevol(BRepPrimAPI_MakeRevol* pos) {
		NativeHandle = pos;
		SetMakeSweepHandle(NativeHandle);
	};

	void XBRepPrimAPI_MakeRevol::SetMakeRevolHandle(BRepPrimAPI_MakeRevol* pos) {
		NativeHandle = pos;
		SetMakeSweepHandle(NativeHandle);
	};

	BRepPrimAPI_MakeRevol* XBRepPrimAPI_MakeRevol::GetMakeRevol() {
		return NativeHandle;
	};

	BRepPrimAPI_MakeSweep* XBRepPrimAPI_MakeRevol::GetMakeSweep() {
		return NativeHandle;
	};

	BRepBuilderAPI_MakeShape* XBRepPrimAPI_MakeRevol::GetMakeShape() {
		return NativeHandle;
	};

	XTopoDS_Shape^ XBRepPrimAPI_MakeRevol::Shape() {
		TopoDS_Shape* aShape = new TopoDS_Shape(NativeHandle->Shape());
		return gcnew XTopoDS_Shape(aShape);
	};

	//! Builds the Revol of base S, axis  A and angle  D. If C
	//! is true, S is copied.
	//! Standard_Boolean Copy = Standard_False
	XBRepPrimAPI_MakeRevol::XBRepPrimAPI_MakeRevol(XTopoDS_Shape^ S, xgp_Ax1^ A, Standard_Real D, Standard_Boolean C) {
		NativeHandle = new BRepPrimAPI_MakeRevol(*S->GetShape(), *A->GetAx1(), D, C);
		SetMakeSweepHandle(NativeHandle);
	};

	//! Builds the Revol of base S, axis  A and angle 2*Pi. If
	//! C is true, S is copied.
	//! Standard_Boolean Copy = Standard_False
	XBRepPrimAPI_MakeRevol::XBRepPrimAPI_MakeRevol(XTopoDS_Shape^ S, xgp_Ax1^ A, Standard_Boolean Copy) {
		NativeHandle = new BRepPrimAPI_MakeRevol(*S->GetShape(), *A->GetAx1(), Copy);
		SetMakeSweepHandle(NativeHandle);
	};

	//! Returns the internal sweeping algorithm.
	XBRepSweep_Revol^ XBRepPrimAPI_MakeRevol::Revol() {
		BRepSweep_Revol* aRevol = new BRepSweep_Revol(NativeHandle->Revol());
		return gcnew XBRepSweep_Revol(aRevol);
	};

	//! Builds the resulting shape (redefined from MakeShape).
	void XBRepPrimAPI_MakeRevol::Build() {
		NativeHandle->Build();
	};

	//! Returns the first shape of the revol  (coinciding with
	//! the generating shape).
	XTopoDS_Shape^ XBRepPrimAPI_MakeRevol::FirstShape() {
		TopoDS_Shape* aShape = new TopoDS_Shape(NativeHandle->FirstShape());
		return gcnew XTopoDS_Shape(aShape);
	};

	//! Returns the TopoDS Shape of the end of the revol.
	XTopoDS_Shape^ XBRepPrimAPI_MakeRevol::LastShape() {
		TopoDS_Shape* aShape = new TopoDS_Shape(NativeHandle->LastShape());
		return gcnew XTopoDS_Shape(aShape);
	};

	//! Returns list of shape generated from shape S
	//! Warning: shape S must be shape of type VERTEX, EDGE, FACE, SOLID.
	//! For shapes of other types method always returns empty list
	XTopTools_ListOfShape^ XBRepPrimAPI_MakeRevol::Generated(XTopoDS_Shape^ S) {
		TopTools_ListOfShape* aListOfShape = new TopTools_ListOfShape(NativeHandle->Generated(*S->GetShape()));
		return gcnew XTopTools_ListOfShape(aListOfShape);
	};

	//! Returns true if the shape S has been deleted.
	Standard_Boolean XBRepPrimAPI_MakeRevol::IsDeleted(XTopoDS_Shape^ S) {
		return NativeHandle->IsDeleted(*S->GetShape());
	};


	//! Returns the TopoDS Shape of the beginning of the revolution,
	//! generated with theShape  (subShape of the generating shape).
	XTopoDS_Shape^ XBRepPrimAPI_MakeRevol::FirstShape(XTopoDS_Shape^ theShape) {
		TopoDS_Shape* aShape = new TopoDS_Shape(NativeHandle->FirstShape(*theShape->GetShape()));
		return gcnew XTopoDS_Shape(aShape);
	};

	//! Returns the TopoDS Shape of the end of the revolution,
	//! generated with  theShape (subShape of the  generating shape).
	XTopoDS_Shape^ XBRepPrimAPI_MakeRevol::LastShape(XTopoDS_Shape^ theShape) {
		TopoDS_Shape* aShape = new TopoDS_Shape(NativeHandle->LastShape(*theShape->GetShape()));
		return gcnew XTopoDS_Shape(aShape);
	};

	//! Check if there are degenerated edges in the result.
	Standard_Boolean XBRepPrimAPI_MakeRevol::HasDegenerated() {
		return NativeHandle->HasDegenerated();
	};

	//! Returns the list of degenerated edges
	XTopTools_ListOfShape^ XBRepPrimAPI_MakeRevol::Degenerated() {
		TopTools_ListOfShape* aListOfShape = new TopTools_ListOfShape(NativeHandle->Degenerated());
		return gcnew XTopTools_ListOfShape(aListOfShape);
	};
}