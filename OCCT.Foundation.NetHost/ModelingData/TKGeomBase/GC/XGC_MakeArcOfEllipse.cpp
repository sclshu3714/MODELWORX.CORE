#include <XGC_MakeArcOfEllipse.h>
namespace TKGeomBase {

	//! DEFINE_STANDARD_ALLOC
	XGC_MakeArcOfEllipse::XGC_MakeArcOfEllipse(GC_MakeArcOfEllipse* pos) {
		NativeHandle = pos;
		SetRoot(NativeHandle);
	};

	void XGC_MakeArcOfEllipse::SetMakeArcOfEllipseHandle(GC_MakeArcOfEllipse* pos) {
		NativeHandle = pos;
		SetRoot(NativeHandle);
	};

	GC_MakeArcOfEllipse* XGC_MakeArcOfEllipse::GetMakeArcOfEllipse() {
		return NativeHandle;
	};

	//! Constructs an arc of Ellipse (TrimmedCurve from Geom) from
	//! a Ellipse between two parameters Alpha1 and Alpha2.
	XGC_MakeArcOfEllipse::XGC_MakeArcOfEllipse(xgp_Elips^ Elips, Standard_Real Alpha1, Standard_Real Alpha2, Standard_Boolean Sense) {
		NativeHandle = new GC_MakeArcOfEllipse(*Elips->GetElips(), Alpha1, Alpha2, Sense);
		SetRoot(NativeHandle);
	};

	//! Constructs an arc of Ellipse (TrimmedCurve from Geom) from
	//! a Ellipse between point <P> and the angle Alpha
	//! given in radians.
	XGC_MakeArcOfEllipse::XGC_MakeArcOfEllipse(xgp_Elips^ Elips, xgp_Pnt^ P, Standard_Real Alpha, Standard_Boolean Sense) {
		NativeHandle = new GC_MakeArcOfEllipse(*Elips->GetElips(), *P->GetPnt(), Alpha, Sense);
		SetRoot(NativeHandle);
	};

	//! Constructs an arc of Ellipse (TrimmedCurve from Geom) from
	//! a Ellipse between two points P1 and P2.
	//! The orientation of the arc of ellipse is:
	//! -   the sense of Elips if Sense is true, or
	//! -   the opposite sense if Sense is false.
	//! Notes:
	//! -   Alpha1, Alpha2 and Alpha are angle values, given in radians.
	//! -   IsDone always returns true.
	XGC_MakeArcOfEllipse::XGC_MakeArcOfEllipse(xgp_Elips^ Elips, xgp_Pnt^ P1, xgp_Pnt^ P2, Standard_Boolean Sense) {
		NativeHandle = new GC_MakeArcOfEllipse(*Elips->GetElips(), *P1->GetPnt(), *P2->GetPnt(), Sense);
		SetRoot(NativeHandle);
	};

	//! Returns the constructed arc of ellipse.
	XGeom_TrimmedCurve^ XGC_MakeArcOfEllipse::Value() {
		return gcnew XGeom_TrimmedCurve(NativeHandle->Value());
	};

	//! Returns true if the construction is successful.
	Standard_Boolean XGC_MakeArcOfEllipse::IsDone() {
		return NativeHandle->IsDone();
	};

	//! Returns the status of the construction:
	//! -   gce_Done, if the construction is successful, or
	//! -   another value of the gce_ErrorType enumeration
	//! indicating why the construction failed.
	xgce_ErrorType XGC_MakeArcOfEllipse::Status() {
		return safe_cast<xgce_ErrorType>(NativeHandle->Status());
	};
}
