#include <xgce_MakeElips.h>
namespace TKGeomBase {
	//DEFINE_STANDARD_ALLOC
	xgce_MakeElips::xgce_MakeElips() {

	};

	xgce_MakeElips::xgce_MakeElips(gce_MakeElips* pos) {
		NativeHandle = pos;
		SetRoot(NativeHandle);
	};

	void xgce_MakeElips::SetMakeElips(gce_MakeElips* pos) {
		NativeHandle = pos;
		SetRoot(NativeHandle);
	};

	gce_MakeElips* xgce_MakeElips::GetMakeElips() {
		return NativeHandle;
	};

	gce_Root* xgce_MakeElips::GetRoot() {
		return NativeHandle;
	};


	//! The major radius of the ellipse is on the "XAxis" and the
	//! minor radius is on the "YAxis" of the ellipse. The "XAxis"
	//! is defined with the "XDirection" of A2 and the "YAxis" is
	//! defined with the "YDirection" of A2.
	//! Warnings :
	//! It is not forbidden to create an ellipse with
	//! MajorRadius = MinorRadius.
	xgce_MakeElips::xgce_MakeElips(xgp_Ax2^ A2, Standard_Real MajorRadius, Standard_Real MinorRadius) {
		NativeHandle = new gce_MakeElips(*A2->GetAx2(), MajorRadius, MinorRadius);
		SetRoot(NativeHandle);
	};

	//! Make an ellipse with its center and two points.
	//! Warning
	//! The MakeElips class does not prevent the
	//!ruction of an ellipse where the MajorRadius is
	//! equal to the MinorRadius.
	//! If an error occurs (that is, when IsDone returns
	//! false), the Status function returns:
	//! -   gce_InvertRadius if MajorRadius is less than MinorRadius;
	//! -   gce_NegativeRadius if MinorRadius is less than 0.0;
	//! -   gce_NullAxis if the points S1 and Center are coincident; or
	//! -   gce_InvertAxis if:
	//! -   the major radius computed with Center and S1
	//! is less than the minor radius computed with Center, S1 and S2, or
	//! -   Center, S1 and S2 are collinear.
	xgce_MakeElips::xgce_MakeElips(xgp_Pnt^ S1, xgp_Pnt^ S2, xgp_Pnt^ Center) {
		NativeHandle = new gce_MakeElips(*S1->GetPnt(), *S2->GetPnt(), *Center->GetPnt());
		SetRoot(NativeHandle);
	};

	//! Returns theructed ellipse.
	//! Exceptions StdFail_NotDone if no ellipse isructed.
	xgp_Elips^ xgce_MakeElips::Value() {
		gp_Elips* temp = new gp_Elips(NativeHandle->Value());
		return gcnew xgp_Elips(temp);
	};

	xgp_Elips^ xgce_MakeElips::Operator() {
		gp_Elips* temp = new gp_Elips(NativeHandle->Operator());
		return gcnew xgp_Elips(temp);
	};
	xgce_MakeElips::operator xgp_Elips ^ () {
		gp_Elips* temp = new gp_Elips(NativeHandle->Operator());
		return gcnew xgp_Elips(temp);
	};

	//! Returns true if the construction is successful.
	Standard_Boolean xgce_MakeElips::IsDone() {
		return NativeHandle->IsDone();
	};

	//! Returns the status of the construction:
	//! -   gce_Done, if the construction is successful, or
	//! -   another value of the gce_ErrorType enumeration
	//! indicating why the construction failed.
	xgce_ErrorType xgce_MakeElips::Status() {
		return safe_cast<xgce_ErrorType>(NativeHandle->Status());
	};
}