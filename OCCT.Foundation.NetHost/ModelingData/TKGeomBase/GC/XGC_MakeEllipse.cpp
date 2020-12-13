#include <XGC_MakeEllipse.h>
namespace TKGeomBase {

	//! DEFINE_STANDARD_ALLOC
	XGC_MakeEllipse::XGC_MakeEllipse(GC_MakeEllipse* pos) {
		NativeHandle = pos;
		SetRoot(NativeHandle);
	};

	void XGC_MakeEllipse::SetMakeEllipseHandle(GC_MakeEllipse* pos) {
		NativeHandle = pos;
		SetRoot(NativeHandle);
	};

	GC_MakeEllipse* XGC_MakeEllipse::GetMakeEllipse() {
		return NativeHandle;
	};

	//! Creates an ellipse from a non persistent ellipse E from package gp by its conversion.
	XGC_MakeEllipse::XGC_MakeEllipse(xgp_Elips^ E) {
		NativeHandle = new GC_MakeEllipse(*E->GetElips());
		SetRoot(NativeHandle);
	};

	//! Constructs an ellipse with major and minor radii MajorRadius and
	//! MinorRadius, and located in the plane defined by
	//! the "X Axis" and "Y Axis" of the coordinate system A2, where:
	//! -   its center is the origin of A2, and
	//! -   its major axis is the "X Axis" of A2;
	//! Warnings :
	//! The MakeEllipse class does not prevent the
	//! construction of an ellipse where MajorRadius is equal to MinorRadius.
	//! If an error occurs (that is, when IsDone returns
	//! false), the Status function returns:
	//! -   gce_InvertRadius if MajorRadius is less than MinorRadius;
	//! -   gce_NegativeRadius if MinorRadius is less than 0.0;
	//! -   gce_NullAxis if the points S1 and Center are coincident; or
	//! -   gce_InvertAxis if:
	//! -   the major radius computed with Center and S1
	//! is less than the minor radius computed with Center, S1 and S2, or
	//! -   Center, S1 and S2 are collinear.
	XGC_MakeEllipse::XGC_MakeEllipse(xgp_Ax2^ A2, Standard_Real MajorRadius, Standard_Real MinorRadius) {
		NativeHandle = new GC_MakeEllipse(*A2->GetAx2(), MajorRadius, MinorRadius);
		SetRoot(NativeHandle);
	};

	//! Constructs an ellipse centered on the point Center, where
	//! -   the plane of the ellipse is defined by Center, S1 and S2,
	//! -   its major axis is defined by Center and S1,
	//! -   its major radius is the distance between Center and S1, and
	//! -   its minor radius is the distance between S2 and the major axis.
	XGC_MakeEllipse::XGC_MakeEllipse(xgp_Pnt^ S1, xgp_Pnt^ S2, xgp_Pnt^ Center) {
		NativeHandle = new GC_MakeEllipse(*S1->GetPnt(), *S2->GetPnt(), *Center->GetPnt());
		SetRoot(NativeHandle);
	};

	//! Returns the constructed ellipse.
	//! Exceptions StdFail_NotDone if no ellipse is constructed.
	XGeom_Ellipse^ XGC_MakeEllipse::Value() {
		return gcnew XGeom_Ellipse(NativeHandle->Value());
	};

	//! Returns true if the construction is successful.
	Standard_Boolean XGC_MakeEllipse::IsDone() {
		return NativeHandle->IsDone();
	};

	//! Returns the status of the construction:
	//! -   gce_Done, if the construction is successful, or
	//! -   another value of the gce_ErrorType enumeration
	//! indicating why the construction failed.
	xgce_ErrorType XGC_MakeEllipse::Status() {
		return safe_cast<xgce_ErrorType>(NativeHandle->Status());
	};
}
