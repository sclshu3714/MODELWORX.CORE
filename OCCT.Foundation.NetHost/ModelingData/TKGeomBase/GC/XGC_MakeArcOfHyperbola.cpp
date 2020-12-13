#include <XGC_MakeArcOfHyperbola.h>
namespace TKGeomBase {
	//! DEFINE_STANDARD_ALLOC
	XGC_MakeArcOfHyperbola::XGC_MakeArcOfHyperbola(GC_MakeArcOfHyperbola* pos) {
		NativeHandle = pos;
		SetRoot(NativeHandle);
	};

	void XGC_MakeArcOfHyperbola::SetMakeArcOfHyperbolaHandle(GC_MakeArcOfHyperbola* pos) {
		NativeHandle = pos;
		SetRoot(NativeHandle);
	};

	GC_MakeArcOfHyperbola* XGC_MakeArcOfHyperbola::GetMakeArcOfHyperbola() {
		return NativeHandle;
	};

	//! Creates an arc of Hyperbola (TrimmedCurve from Geom) from
		//! a Hyperbola between two parameters Alpha1 and Alpha2
		//! (given in radians).
	XGC_MakeArcOfHyperbola::XGC_MakeArcOfHyperbola(xgp_Hypr^ Hypr, Standard_Real Alpha1, Standard_Real Alpha2, Standard_Boolean Sense) {
		NativeHandle = new GC_MakeArcOfHyperbola(*Hypr->GetHypr(), Alpha1, Alpha2, Sense);
		SetRoot(NativeHandle);
	};

	//! Creates an arc of Hyperbola (TrimmedCurve from Geom) from
	//! a Hyperbola between point <P> and the parameter
	//! Alpha (given in radians).
	XGC_MakeArcOfHyperbola::XGC_MakeArcOfHyperbola(xgp_Hypr^ Hypr, xgp_Pnt^ P, Standard_Real Alpha, Standard_Boolean Sense) {
		NativeHandle = new GC_MakeArcOfHyperbola(*Hypr->GetHypr(), *P->GetPnt(), Alpha, Sense);
		SetRoot(NativeHandle);
	};

	//! Creates an arc of Hyperbola (TrimmedCurve from Geom) from
	//! a Hyperbola between two points P1 and P2.
	//! The orientation of the arc of hyperbola is:
	//! -   the sense of Hypr if Sense is true, or
	//! -   the opposite sense if Sense is false.
	XGC_MakeArcOfHyperbola::XGC_MakeArcOfHyperbola(xgp_Hypr^ Hypr, xgp_Pnt^ P1, xgp_Pnt^ P2, Standard_Boolean Sense) {
		NativeHandle = new GC_MakeArcOfHyperbola(*Hypr->GetHypr(), *P1->GetPnt(), *P2->GetPnt(), Sense);
		SetRoot(NativeHandle);
	};

	//! Returns the constructed arc of ellipse.
	XGeom_TrimmedCurve^ XGC_MakeArcOfHyperbola::Value() {
		return gcnew XGeom_TrimmedCurve(NativeHandle->Value());
	};

	//! Returns true if the construction is successful.
	Standard_Boolean XGC_MakeArcOfHyperbola::IsDone() {
		return NativeHandle->IsDone();
	};

	//! Returns the status of the construction:
	//! -   gce_Done, if the construction is successful, or
	//! -   another value of the gce_ErrorType enumeration
	//! indicating why the construction failed.
	xgce_ErrorType XGC_MakeArcOfHyperbola::Status() {
		return safe_cast<xgce_ErrorType>(NativeHandle->Status());
	};
}