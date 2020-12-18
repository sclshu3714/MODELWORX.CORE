#include <xgce_MakeHypr.h>
namespace TKGeomBase {
	xgce_MakeHypr::xgce_MakeHypr() {
		/*NativeHandle = new gce_MakeHypr();
		SetRoot(NativeHandle);*/
	};

	xgce_MakeHypr::xgce_MakeHypr(gce_MakeHypr* pos) {
		NativeHandle = pos;
		SetRoot(NativeHandle);
	};

	void xgce_MakeHypr::SetMakeHypr(gce_MakeHypr* pos) {
		NativeHandle = pos;
		SetRoot(NativeHandle);
	};

	gce_MakeHypr* xgce_MakeHypr::GetMakeHypr() {
		return NativeHandle;
	};

	gce_Root* xgce_MakeHypr::GetRoot() {
		return NativeHandle;
	};


	//! A2 is the local coordinate system of the hyperbola.
	//! In the local coordinates system A2 the equation of the
	//! hyperbola is :
	//! X*X / MajorRadius*MajorRadius - Y*Y / MinorRadius*MinorRadius = 1.0
	//! It is not forbidden to create an Hyperbola with MajorRadius =
	//! MinorRadius.
	//! For the hyperbola the MajorRadius can be lower than the
	//! MinorRadius.
	//! The status is "NegativeRadius" if MajorRadius < 0.0 and
	//! "InvertRadius" if MinorRadius > MajorRadius.
	xgce_MakeHypr::xgce_MakeHypr(xgp_Ax2^ A2, Standard_Real MajorRadius, Standard_Real MinorRadius) {
		NativeHandle = new gce_MakeHypr(*A2->GetAx2(), MajorRadius, MinorRadius);
		SetRoot(NativeHandle);
	};

	//! Constructs a hyperbola
	//! -   centered on the point Center, where:
	//! -   the plane of the hyperbola is defined by Center, S1 and S2,
	//! -   its major axis is defined by Center and S1,
	//! -   its major radius is the distance between Center and S1, and
	//! -   its minor radius is the distance between S2 and the major axis.
	//! Warning
	//! If an error occurs (that is, when IsDone returns
	//! false), the Status function returns:
	//! -   gce_NegativeRadius if MajorRadius is less than 0.0;
	//! -   gce_InvertRadius if:
	//! -   the major radius (computed with Center, S1) is
	//! less than the minor radius (computed with Center, S1 and S2), or
	//! -   MajorRadius is less than MinorRadius; or
	//! -   gce_ColinearPoints if S1, S2 and Center are collinear.
	xgce_MakeHypr::xgce_MakeHypr(xgp_Pnt^ S1, xgp_Pnt^ S2, xgp_Pnt^ Center) {
		NativeHandle = new gce_MakeHypr(*S1->GetPnt(), *S2->GetPnt(), *Center->GetPnt());
		SetRoot(NativeHandle);
	};
	
	//! Returns theructed hyperbola.
	//! Exceptions StdFail_NotDone if no hyperbola isructed.
	xgp_Hypr^ xgce_MakeHypr::Value() {
		gp_Hypr* temp = new gp_Hypr(NativeHandle->Value());
		return gcnew xgp_Hypr(temp);
	};

	xgp_Hypr^ xgce_MakeHypr::Operator() {
		gp_Hypr* temp = new gp_Hypr(NativeHandle->Operator());
		return gcnew xgp_Hypr(temp);
	};
	xgce_MakeHypr::operator xgp_Hypr^() {
		gp_Hypr* temp = new gp_Hypr(NativeHandle->Operator());
		return gcnew xgp_Hypr(temp);
	};
	//! Returns true if the construction is successful.
	Standard_Boolean xgce_MakeHypr::IsDone() {
		return NativeHandle->IsDone();
	};

	//! Returns the status of the construction:
	//! -   gce_Done, if the construction is successful, or
	//! -   another value of the gce_ErrorType enumeration
	//! indicating why the construction failed.
	xgce_ErrorType xgce_MakeHypr::Status() {
		return safe_cast<xgce_ErrorType>(NativeHandle->Status());
	};
}