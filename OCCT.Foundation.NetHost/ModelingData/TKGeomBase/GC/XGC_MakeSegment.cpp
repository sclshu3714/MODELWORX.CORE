#include <XGC_MakeSegment.h>
namespace TKGeomBase {
	//! DEFINE_STANDARD_ALLOC
	XGC_MakeSegment::XGC_MakeSegment() {
		/*NativeHandle = new GC_MakeSegment();
		SetRoot(NativeHandle);*/
	};

	XGC_MakeSegment::XGC_MakeSegment(GC_MakeSegment* pos) {
		NativeHandle = pos;
		SetRoot(NativeHandle);
	};

	void XGC_MakeSegment::SetMakeSegment(GC_MakeSegment* pos) {
		NativeHandle = pos;
		SetRoot(NativeHandle);
	};

	GC_MakeSegment* XGC_MakeSegment::GetMakeSegment() {
		return NativeHandle;
	};

	GC_Root* XGC_MakeSegment::GetRoot() {
		return NativeHandle;
	};

	//! Make a segment of Line from the 2 points <P1> and <P2>.
	//! It returns NullObject if <P1> and <P2> are confused.
	XGC_MakeSegment::XGC_MakeSegment(xgp_Pnt^ P1, xgp_Pnt^ P2) {
		NativeHandle = new GC_MakeSegment(*P1->GetPnt(), *P2->GetPnt());
		SetRoot(NativeHandle);
	};

	//! Make a segment of Line from the line <Line1>
	//! between the two parameters U1 and U2.
	//! It returns NullObject if <U1> is equal <U2>.
	XGC_MakeSegment::XGC_MakeSegment(xgp_Lin^ Line, Standard_Real U1, Standard_Real U2) {
		NativeHandle = new GC_MakeSegment(*Line->GetLin(), U1, U2);
		SetRoot(NativeHandle);
	};

	//! Make a segment of Line from the line <Line1>
	//! between the point <Point> and the parameter Ulast.
	//! It returns NullObject if <U1> is equal <U2>.
	XGC_MakeSegment::XGC_MakeSegment(xgp_Lin^ Line, xgp_Pnt^ Point, Standard_Real Ulast) {
		NativeHandle = new GC_MakeSegment(*Line->GetLin(), *Point->GetPnt(), Ulast);
		SetRoot(NativeHandle);
	};

	//! Make a segment of Line from the line <Line1>
	//! between the two points <P1> and <P2>.
	//! It returns NullObject if <U1> is equal <U2>.
	XGC_MakeSegment::XGC_MakeSegment(xgp_Lin^ Line, xgp_Pnt^ P1, xgp_Pnt^ P2) {
		NativeHandle = new GC_MakeSegment(*Line->GetLin(), *P1->GetPnt(), *P2->GetPnt());
		SetRoot(NativeHandle);
	};

	//! Returns the constructed line segment.
	XGeom_TrimmedCurve^ XGC_MakeSegment::Value() {
		return gcnew XGeom_TrimmedCurve(NativeHandle->Value());
	};

	//! Returns true if the construction is successful.
	Standard_Boolean XGC_MakeSegment::IsDone() {
		return NativeHandle->IsDone();
	};

	//! Returns the status of the construction:
	//! -   gce_Done, if the construction is successful, or
	//! -   another value of the gce_ErrorType enumeration
	//! indicating why the construction failed.
	xgce_ErrorType XGC_MakeSegment::Status() {
		return safe_cast<xgce_ErrorType>(NativeHandle->Status());
	};
}
