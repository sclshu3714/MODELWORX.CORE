#include <xgce_MakeRotation.h>
namespace TKGeomBase {
	//DEFINE_STANDARD_ALLOC
	xgce_MakeRotation::xgce_MakeRotation() {
		//NativeHandle = new gce_MakeRotation();
	};

	xgce_MakeRotation::xgce_MakeRotation(gce_MakeRotation* pos) {
		NativeHandle = pos;
	};

	void xgce_MakeRotation::SetMakeRotation(gce_MakeRotation* pos) {
		NativeHandle = pos;
	};

	gce_MakeRotation* xgce_MakeRotation::GetMakeRotation() {
		return NativeHandle;
	};

	//! Constructs a rotation through angle Angle about the axis defined by the line Line.
	xgce_MakeRotation::xgce_MakeRotation(xgp_Lin^ Line, Standard_Real Angle) {
		NativeHandle = new gce_MakeRotation(*Line->GetLin(), Angle);
	};

	//! Constructs a rotation through angle Angle about the axis defined by the axis Axis.
	xgce_MakeRotation::xgce_MakeRotation(xgp_Ax1^ Axis, Standard_Real Angle) {
		NativeHandle = new gce_MakeRotation(*Axis->GetAx1(), Angle);
	};


	//! Constructs a rotation through angle Angle about the axis defined by:
	//! the point Point and the unit vector Direc.
	xgce_MakeRotation::xgce_MakeRotation(xgp_Pnt^ Point, xgp_Dir^ Direc, Standard_Real Angle) {
		NativeHandle = new gce_MakeRotation(*Point->GetPnt(), *Direc->GetDir(), Angle);
	};

	//! Returns theructed transformation.
	xgp_Trsf^ xgce_MakeRotation::Value() {
		gp_Trsf* temp = new gp_Trsf(NativeHandle->Value());
		return gcnew xgp_Trsf(temp);
	};

	xgp_Trsf^ xgce_MakeRotation::Operator() {
		gp_Trsf* temp = new gp_Trsf(NativeHandle->Operator());
		return gcnew xgp_Trsf(temp);
	};
	xgce_MakeRotation::operator xgp_Trsf^() {
		gp_Trsf* temp = new gp_Trsf(NativeHandle->Operator());
		return gcnew xgp_Trsf(temp);
	};
}