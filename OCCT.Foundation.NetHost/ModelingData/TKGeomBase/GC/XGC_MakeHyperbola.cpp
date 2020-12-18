#include <XGC_MakeHyperbola.h>
namespace TKGeomBase {
	//! DEFINE_STANDARD_ALLOC

	XGC_MakeHyperbola::XGC_MakeHyperbola() {
		/*NativeHandle = new GC_MakeHyperbola();
		SetRoot(NativeHandle);*/
	};

	XGC_MakeHyperbola::XGC_MakeHyperbola(GC_MakeHyperbola* pos) {
		NativeHandle = pos;
		SetRoot(NativeHandle);
	};

	void XGC_MakeHyperbola::SetMakeHyperbola(GC_MakeHyperbola* pos) {
		NativeHandle = pos;
		SetRoot(NativeHandle);
	};

	GC_MakeHyperbola* XGC_MakeHyperbola::GetMakeHyperbola() {
		return NativeHandle;
	};

	GC_Root* XGC_MakeHyperbola::GetRoot() {
		return NativeHandle;
	};

	//! Creates  an Hyperbola from a non persistent hyperbola  from package gp by conversion.
	XGC_MakeHyperbola::XGC_MakeHyperbola(xgp_Hypr^ H) {
		NativeHandle = new GC_MakeHyperbola(*H->GetHypr());
		SetRoot(NativeHandle);
	};

	//! Constructs a hyperbola centered on the origin of the coordinate system
	//! A2, with major and minor radii MajorRadius and MinorRadius, where:
	//! the plane of the hyperbola is defined by the "X Axis" and "Y Axis" of A2,
	//! -   its major axis is the "X Axis" of A2.
	XGC_MakeHyperbola::XGC_MakeHyperbola(xgp_Ax2^ A2, Standard_Real MajorRadius, Standard_Real MinorRadius) {
		NativeHandle = new GC_MakeHyperbola(*A2->GetAx2(), MajorRadius, MinorRadius);
		SetRoot(NativeHandle);
	};

	//! Constructs a hyperbola centered on the point Center, where
	//! -   the plane of the hyperbola is defined by Center, S1 and S2,
	//! -   its major axis is defined by Center and S1,
	//! -   its major radius is the distance between Center and S1, and
	//! -   its minor radius is the distance between S2 and the major axis;
	XGC_MakeHyperbola::XGC_MakeHyperbola(xgp_Pnt^ S1, xgp_Pnt^ S2, xgp_Pnt^ Center) {
		NativeHandle = new GC_MakeHyperbola(*S1->GetPnt(), *S2->GetPnt(), *Center->GetPnt());
		SetRoot(NativeHandle);
	};

	//! Returns the constructed hyperbola.
	//! Exceptions StdFail_NotDone if no hyperbola is constructed.
	XGeom_Hyperbola^ XGC_MakeHyperbola::Value() {
		return gcnew XGeom_Hyperbola(NativeHandle->Value());
	};

	//! Returns true if the construction is successful.
	Standard_Boolean XGC_MakeHyperbola::IsDone() {
		return NativeHandle->IsDone();
	};

	//! Returns the status of the construction:
	//! -   gce_Done, if the construction is successful, or
	//! -   another value of the gce_ErrorType enumeration
	//! indicating why the construction failed.
	xgce_ErrorType XGC_MakeHyperbola::Status() {
		return safe_cast<xgce_ErrorType>(NativeHandle->Status());
	};
}