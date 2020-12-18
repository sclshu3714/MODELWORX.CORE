#include <xgce_MakeRotation2d.h>
namespace TKGeomBase {
	xgce_MakeRotation2d::xgce_MakeRotation2d() {
		//NativeHandle = new gce_MakeRotation2d();
	};

	xgce_MakeRotation2d::xgce_MakeRotation2d(gce_MakeRotation2d* pos) {
		NativeHandle = pos;
	};

	void xgce_MakeRotation2d::SetMakeRotation2d(gce_MakeRotation2d* pos) {
		NativeHandle = pos;
	};

	gce_MakeRotation2d* xgce_MakeRotation2d::GetMakeRotation2d() {
		return NativeHandle;
	};

	//! Constructs a rotation through angle Angle about the center Point.
	xgce_MakeRotation2d::xgce_MakeRotation2d(xgp_Pnt2d^ Point, Standard_Real Angle) {
		NativeHandle = new gce_MakeRotation2d(*Point->GetPnt2d(), Angle);
	};

	//! Returns theructed transformation.
	xgp_Trsf2d^ xgce_MakeRotation2d::Value() {
		gp_Trsf2d* temp = new gp_Trsf2d(NativeHandle->Value());
		return gcnew xgp_Trsf2d(temp);
	};

	xgp_Trsf2d^ xgce_MakeRotation2d::Operator() {
		gp_Trsf2d* temp = new gp_Trsf2d(NativeHandle->Operator());
		return gcnew xgp_Trsf2d(temp);
	};
	xgce_MakeRotation2d::operator xgp_Trsf2d^() {
		gp_Trsf2d* temp = new gp_Trsf2d(NativeHandle->Operator());
		return gcnew xgp_Trsf2d(temp);
	};
}