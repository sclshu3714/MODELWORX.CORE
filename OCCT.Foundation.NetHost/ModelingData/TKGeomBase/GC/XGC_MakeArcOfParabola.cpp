#include <XGC_MakeArcOfParabola.h>
namespace TKGeomBase {
	//! DEFINE_STANDARD_ALLOC
	XGC_MakeArcOfParabola::XGC_MakeArcOfParabola(GC_MakeArcOfParabola* pos) {
		NativeHandle = pos;
		SetRoot(NativeHandle);
	};

	void XGC_MakeArcOfParabola::SetMakeArcOfParabolaHandle(GC_MakeArcOfParabola* pos) {
		NativeHandle = pos;
		SetRoot(NativeHandle);
	};

	GC_MakeArcOfParabola* XGC_MakeArcOfParabola::GetMakeArcOfParabola() {
		return NativeHandle;
	};

	//! Creates an arc of Parabola (TrimmedCurve from Geom) from
	//! a Parabola between two parameters Alpha1 and Alpha2
	//! (given in radians).
	XGC_MakeArcOfParabola::XGC_MakeArcOfParabola(xgp_Parab^ Parab, Standard_Real Alpha1, Standard_Real Alpha2, Standard_Boolean Sense) {
		NativeHandle = new GC_MakeArcOfParabola(*Parab->GetParab(), Alpha1, Alpha2, Sense);
		SetRoot(NativeHandle);
	};

	//! Creates an arc of Parabola (TrimmedCurve from Geom) from
	//! a Parabola between point <P> and the parameter
	//! Alpha (given in radians).
	XGC_MakeArcOfParabola::XGC_MakeArcOfParabola(xgp_Parab^ Parab, xgp_Pnt^ P, Standard_Real Alpha, Standard_Boolean Sense) {
		NativeHandle = new GC_MakeArcOfParabola(*Parab->GetParab(), *P->GetPnt(), Alpha, Sense);
		SetRoot(NativeHandle);
	};

	//! Creates an arc of Parabola (TrimmedCurve from Geom) from
	//! a Parabola between two points P1 and P2.
	XGC_MakeArcOfParabola::XGC_MakeArcOfParabola(xgp_Parab^ Parab, xgp_Pnt^ P1, xgp_Pnt^ P2, Standard_Boolean Sense) {
		NativeHandle = new GC_MakeArcOfParabola(*Parab->GetParab(), *P1->GetPnt(), *P2->GetPnt(), Sense);
		SetRoot(NativeHandle);
	};

	//! Returns the constructed arc of parabola.
	XGeom_TrimmedCurve^ XGC_MakeArcOfParabola::Value() {
		return gcnew XGeom_TrimmedCurve(NativeHandle->Value());
	};

	//! Returns true if the construction is successful.
	Standard_Boolean XGC_MakeArcOfParabola::IsDone() {
		return NativeHandle->IsDone();
	};

	//! Returns the status of the construction:
	//! -   gce_Done, if the construction is successful, or
	//! -   another value of the gce_ErrorType enumeration
	//! indicating why the construction failed.
	xgce_ErrorType XGC_MakeArcOfParabola::Status() {
		return safe_cast<xgce_ErrorType>(NativeHandle->Status());
	};
}
