#include <XGC_MakeArcOfCircle.h>

namespace TKGeomBase {

	//! DEFINE_STANDARD_ALLOC
	XGC_MakeArcOfCircle::XGC_MakeArcOfCircle(GC_MakeArcOfCircle* pos) {
		NativeHandle = pos;
		SetRoot(NativeHandle);
	};

	void XGC_MakeArcOfCircle::SetMakeArcOfCircleHandle(GC_MakeArcOfCircle* pos) {
		NativeHandle = pos;
		SetRoot(NativeHandle);
	};

	GC_MakeArcOfCircle* XGC_MakeArcOfCircle::GetMakeArcOfCircle() {
		return NativeHandle;
	};

	//! Make an arc of circle (TrimmedCurve from Geom) from
	//! a circle between two angles Alpha1 and Alpha2
	//! given in radiians.
	XGC_MakeArcOfCircle::XGC_MakeArcOfCircle(xgp_Circ^ Circ, Standard_Real Alpha1, Standard_Real Alpha2, Standard_Boolean Sense) {
		NativeHandle = new GC_MakeArcOfCircle(*Circ->GetCirc(), Alpha1, Alpha2, Sense);
		SetRoot(NativeHandle);
	};

	//! Make an arc of circle (TrimmedCurve from Geom) from
	//! a circle between point <P> and the angle Alpha
	//! given in radians.
	XGC_MakeArcOfCircle::XGC_MakeArcOfCircle(xgp_Circ^ Circ, xgp_Pnt^ P, Standard_Real Alpha, Standard_Boolean Sense) {
		NativeHandle = new GC_MakeArcOfCircle(*Circ->GetCirc(),*P->GetPnt(), Alpha, Sense);
		SetRoot(NativeHandle);
	};

	//! Make an arc of circle (TrimmedCurve from Geom) from
	//! a circle between two points P1 and P2.
	XGC_MakeArcOfCircle::XGC_MakeArcOfCircle(xgp_Circ^ Circ, xgp_Pnt^ P1, xgp_Pnt^ P2, Standard_Boolean Sense) {
		NativeHandle = new GC_MakeArcOfCircle(*Circ->GetCirc(), *P1->GetPnt(), *P2->GetPnt(), Sense);
		SetRoot(NativeHandle);
	};

	//! Make an arc of circle (TrimmedCurve from Geom) from
	//! three points P1,P2,P3 between two points P1 and P2.
	XGC_MakeArcOfCircle::XGC_MakeArcOfCircle(xgp_Pnt^ P1, xgp_Pnt^ P2, xgp_Pnt^ P3) {
		NativeHandle = new GC_MakeArcOfCircle(*P1->GetPnt(), *P2->GetPnt(), *P3->GetPnt());
		SetRoot(NativeHandle);
	};

	//! Make an arc of circle (TrimmedCurve from Geom) from
	//! two points P1,P2 and the tangente to the solution at
	//! the point P1.
	//! The orientation of the arc is:
	//! -   the sense determined by the order of the points P1, P3 and P2;
	//! -   the sense defined by the vector V; or
	//! -   for other syntaxes:
	//! -   the sense of Circ if Sense is true, or
	//! -   the opposite sense if Sense is false.
	//! Note: Alpha1, Alpha2 and Alpha are angle values, given in radians.
	//! Warning
	//! If an error occurs (that is, when IsDone returns
	//! false), the Status function returns:
	//! -   gce_ConfusedPoints if:
	//! -   any 2 of the 3 points P1, P2 and P3 are coincident, or
	//! -   P1 and P2 are coincident; or
	//! -   gce_IntersectionError if:
	//! -   P1, P2 and P3 are collinear and not coincident, or
	//! -   the vector defined by the points P1 and
	//! P2 is collinear with the vector V.
	XGC_MakeArcOfCircle::XGC_MakeArcOfCircle(xgp_Pnt^ P1, xgp_Vec^ V, xgp_Pnt^ P2) {
		NativeHandle = new GC_MakeArcOfCircle(*P1->GetPnt(), *V->GetVec(), *P2->GetPnt());
		SetRoot(NativeHandle);
	};

	//! Returns the constructed arc of circle.
	//! Exceptions StdFail_NotDone if no arc of circle is constructed.
	XGeom_TrimmedCurve^ XGC_MakeArcOfCircle::Value() {
		return gcnew XGeom_TrimmedCurve(NativeHandle->Value());
	};


	//! Returns true if the construction is successful.
	Standard_Boolean XGC_MakeArcOfCircle::IsDone() {
		return NativeHandle->IsDone();
	};

	//! Returns the status of the construction:
	//! -   gce_Done, if the construction is successful, or
	//! -   another value of the gce_ErrorType enumeration
	//! indicating why the construction failed.
	xgce_ErrorType XGC_MakeArcOfCircle::Status() {
		return safe_cast<xgce_ErrorType>(NativeHandle->Status());
	};
}
