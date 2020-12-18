#include <xgce_MakeMirror.h>
namespace TKGeomBase {
	//DEFINE_STANDARD_ALLOC
	xgce_MakeMirror::xgce_MakeMirror() {
		//NativeHandle = new gce_MakeMirror();
	};

	xgce_MakeMirror::xgce_MakeMirror(gce_MakeMirror* pos) {
		NativeHandle = pos;
	};

	void xgce_MakeMirror::SetMakeMirror(gce_MakeMirror* pos) {
		NativeHandle = pos;
	};

	gce_MakeMirror* xgce_MakeMirror::GetMakeMirror() {
		return NativeHandle;
	};

	xgce_MakeMirror::xgce_MakeMirror(xgp_Pnt^ Point) {
		NativeHandle = new gce_MakeMirror(*Point->GetPnt());
	};

	xgce_MakeMirror::xgce_MakeMirror(xgp_Ax1^ Axis) {
		NativeHandle = new gce_MakeMirror(*Axis->GetAx1());
	};

	xgce_MakeMirror::xgce_MakeMirror(xgp_Lin^ Line) {
		NativeHandle = new gce_MakeMirror(*Line->GetLin());
	};

	//! Makes a symmetry transformation af axis defined by
	//! <Point> and <Direc>.
	xgce_MakeMirror::xgce_MakeMirror(xgp_Pnt^ Point, xgp_Dir^ Direc) {
		NativeHandle = new gce_MakeMirror(*Point->GetPnt(), *Direc->GetDir());
	};

	//! Makes a symmetry transformation of plane <Plane>.
	xgce_MakeMirror::xgce_MakeMirror(xgp_Pln^ Plane) {
		NativeHandle = new gce_MakeMirror(*Plane->GetPln());
	};

	//! Makes a symmetry transformation of plane <Plane>.
	xgce_MakeMirror::xgce_MakeMirror(xgp_Ax2^ Plane) {
		NativeHandle = new gce_MakeMirror(*Plane->GetAx2());
	};

	//! Returns theructed transformation.
	xgp_Trsf^ xgce_MakeMirror::Value() {
		gp_Trsf* temp = new gp_Trsf(NativeHandle->Value());
		return gcnew xgp_Trsf(temp);
	};

	xgp_Trsf^ xgce_MakeMirror::Operator() {
		gp_Trsf* temp = new gp_Trsf(NativeHandle->Operator());
		return gcnew xgp_Trsf(temp);
	};
	xgce_MakeMirror::operator xgp_Trsf^() {
		gp_Trsf* temp = new gp_Trsf(NativeHandle->Operator());
		return gcnew xgp_Trsf(temp);
	};
}