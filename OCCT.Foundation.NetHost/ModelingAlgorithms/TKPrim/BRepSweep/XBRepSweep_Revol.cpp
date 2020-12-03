#include <XBRepSweep_Revol.h>

namespace TKPrim {

	XBRepSweep_Revol::XBRepSweep_Revol() {

	};

	XBRepSweep_Revol::XBRepSweep_Revol(BRepSweep_Revol* pos) {
		NativeHandle = pos;
	};

	void XBRepSweep_Revol::SetSweepRevolHandle(BRepSweep_Revol* pos) {
		NativeHandle = pos;
	};

	BRepSweep_Revol* XBRepSweep_Revol::GetSweepRevol() {
		return NativeHandle;
	};

	//! Builds the Revol of meridian S axis A  and angle D. If
	//! C is true S is copied.
	//! Standard_Boolean C = Standard_False
	XBRepSweep_Revol::XBRepSweep_Revol(XTopoDS_Shape^ S, xgp_Ax1^ A, Standard_Real D, Standard_Boolean C) {
		NativeHandle = new BRepSweep_Revol(*S->GetShape(), A->GetAx1(), D, C);
	};

	//! Builds the Revol of meridian S  axis A and angle 2*Pi.
	//! If C is true S is copied.
	//! Standard_Boolean C = Standard_False
	XBRepSweep_Revol::XBRepSweep_Revol(XTopoDS_Shape^ S, xgp_Ax1^ A, Standard_Boolean C) {
		NativeHandle = new BRepSweep_Revol(*S->GetShape(), A->GetAx1(), C);
	};

	//! Returns the TopoDS Shape attached to the Revol.
	XTopoDS_Shape^ XBRepSweep_Revol::Shape(){
		TopoDS_Shape* aShape = new TopoDS_Shape(NativeHandle->Shape());
		return gcnew XTopoDS_Shape(aShape);
	};

	//! Returns    the  TopoDS  Shape   generated  with  aGenS
	//! (subShape  of the generating shape).
	XTopoDS_Shape^ XBRepSweep_Revol::Shape(XTopoDS_Shape^ aGenS) {
		TopoDS_Shape* aShape = new TopoDS_Shape(NativeHandle->Shape(*aGenS->GetShape()));
		return gcnew XTopoDS_Shape(aShape);
	};

	//! Returns the first shape of the revol  (coinciding with
	//! the generating shape).
	XTopoDS_Shape^ XBRepSweep_Revol::FirstShape() {
		TopoDS_Shape* aShape = new TopoDS_Shape(NativeHandle->FirstShape());
		return gcnew XTopoDS_Shape(aShape);
	};

	//! Returns the first shape of the revol  (coinciding with
	//! the generating shape).
	XTopoDS_Shape^ XBRepSweep_Revol::FirstShape(XTopoDS_Shape^ aGenS) {
		TopoDS_Shape* aShape = new TopoDS_Shape(NativeHandle->FirstShape(*aGenS->GetShape()));
		return gcnew XTopoDS_Shape(aShape);
	};

	//! Returns the TopoDS Shape of the top of the prism.
	XTopoDS_Shape^ XBRepSweep_Revol::LastShape() {
		TopoDS_Shape* aShape = new TopoDS_Shape(NativeHandle->LastShape());
		return gcnew XTopoDS_Shape(aShape);
	};

	//! Returns the  TopoDS  Shape of the top  of  the  prism.
	//! generated  with  aGenS  (subShape  of  the  generating
	//! shape).
	XTopoDS_Shape^ XBRepSweep_Revol::LastShape(XTopoDS_Shape^ aGenS) {
		TopoDS_Shape* aShape = new TopoDS_Shape(NativeHandle->LastShape(*aGenS->GetShape()));
		return gcnew XTopoDS_Shape(aShape);
	};

	//! returns the axis
	xgp_Ax1^ XBRepSweep_Revol::Axe() {
		gp_Ax1* aAx1 = new gp_Ax1(NativeHandle->Axe());
		return gcnew xgp_Ax1(aAx1);
	};

	//! returns the angle.
	Standard_Real XBRepSweep_Revol::Angle() {
		return NativeHandle->Angle();
	};

	//! Returns true if the aGenS is used in resulting Shape 
	Standard_Boolean XBRepSweep_Revol::IsUsed(XTopoDS_Shape^ aGenS) {
		return NativeHandle->IsUsed(*aGenS->GetShape());
	};
}
