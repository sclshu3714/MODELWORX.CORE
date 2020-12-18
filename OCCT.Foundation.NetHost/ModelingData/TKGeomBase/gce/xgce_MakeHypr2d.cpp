#include <xgce_MakeHypr2d.h>
namespace TKGeomBase {
	xgce_MakeHypr2d::xgce_MakeHypr2d() {
		/*NativeHandle = new gce_MakeHypr2d();
		SetRoot(NativeHandle);*/
	};

	xgce_MakeHypr2d::xgce_MakeHypr2d(gce_MakeHypr2d* pos) {
		NativeHandle = pos;
		SetRoot(NativeHandle);
	};

	void xgce_MakeHypr2d::SetMakeHypr2d(gce_MakeHypr2d* pos) {
		NativeHandle = pos;
		SetRoot(NativeHandle);
	};

	gce_MakeHypr2d* xgce_MakeHypr2d::GetMakeHypr2d() {
		return NativeHandle;
	};

	gce_Root* xgce_MakeHypr2d::GetRoot() {
		return NativeHandle;
	};


	//! Constructs a hyperbola
	//! centered on the point Center, where:
	//! -   the major axis of the hyperbola is defined by Center and point S1,
	//! -   the major radius is the distance between Center and S1, and
	//! -   the minor radius is the distance between point S2 and the major axis.
	xgce_MakeHypr2d::xgce_MakeHypr2d(xgp_Pnt2d^ S1, xgp_Pnt2d^ S2, xgp_Pnt2d^ Center) {
		NativeHandle = new gce_MakeHypr2d(*S1->GetPnt2d(), *S2->GetPnt2d(), *Center->GetPnt2d());
		SetRoot(NativeHandle);
	};

	//! Constructs a hyperbola with major and minor radii MajorRadius and
	//! MinorRadius, where:
	//! -   the center of the hyperbola is the origin of the axis MajorAxis, and
	//! -   the major axis is defined by MajorAxis if Sense
	//! is true, or the opposite axis to MajorAxis if Sense is false; or
	//! -   centered on the origin of the coordinate system
	//! A, with major and minor radii MajorRadius and
	//! MinorRadius, where its major axis is the "X Axis"
	//! of A (A is the local coordinate system of the hyperbola).
	xgce_MakeHypr2d::xgce_MakeHypr2d(xgp_Ax2d^ MajorAxis, Standard_Real MajorRadius, Standard_Real MinorRadius, Standard_Boolean Sense) {
		NativeHandle = new gce_MakeHypr2d(*MajorAxis->GetAx2d(), MajorRadius, MinorRadius, Sense);
		SetRoot(NativeHandle);
	};

	//! Creates a Hypr2d centered on the origin of the coordinate system
	//! A, with major and minor radii MajorRadius and
	//! MinorRadius, where its major axis is the "X Axis"
	//! of A (A is the local coordinate system of the hyperbola).
	xgce_MakeHypr2d::xgce_MakeHypr2d(xgp_Ax22d^ A, Standard_Real MajorRadius, Standard_Real MinorRadius) {
		NativeHandle = new gce_MakeHypr2d(*A->GetAx22d(), MajorRadius, MinorRadius);
		SetRoot(NativeHandle);
	};

	//! Returns theructed hyperbola.
	//! Exceptions StdFail_NotDone if no hyperbola isructed.
	xgp_Hypr2d^ xgce_MakeHypr2d::Value() {
		gp_Hypr2d* temp = new gp_Hypr2d(NativeHandle->Value());
		return gcnew xgp_Hypr2d(temp);
	};

	xgp_Hypr2d^ xgce_MakeHypr2d::Operator() {
		gp_Hypr2d* temp = new gp_Hypr2d(NativeHandle->Operator());
		return gcnew xgp_Hypr2d(temp);
	};
	xgce_MakeHypr2d::operator xgp_Hypr2d^() {
		gp_Hypr2d* temp = new gp_Hypr2d(NativeHandle->Operator());
		return gcnew xgp_Hypr2d(temp);
	};
	//! Returns true if the construction is successful.
	Standard_Boolean xgce_MakeHypr2d::IsDone() {
		return NativeHandle->IsDone();
	};

	//! Returns the status of the construction:
	//! -   gce_Done, if the construction is successful, or
	//! -   another value of the gce_ErrorType enumeration
	//! indicating why the construction failed.
	xgce_ErrorType xgce_MakeHypr2d::Status() {
		return safe_cast<xgce_ErrorType>(NativeHandle->Status());
	};
}