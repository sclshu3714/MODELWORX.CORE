#include <xgce_MakeMirror2d.h>
namespace TKGeomBase {
	xgce_MakeMirror2d::xgce_MakeMirror2d() {
		//NativeHandle = new gce_MakeMirror2d();
	};

	xgce_MakeMirror2d::xgce_MakeMirror2d(gce_MakeMirror2d* pos) {
		NativeHandle = pos;
	};

	void xgce_MakeMirror2d::SetMakeMirror2d(gce_MakeMirror2d* pos) {
		NativeHandle = pos;
	};

	gce_MakeMirror2d* xgce_MakeMirror2d::GetMakeMirror2d() {
		return NativeHandle;
	};

	xgce_MakeMirror2d::xgce_MakeMirror2d(xgp_Pnt2d^ Point) {
		NativeHandle = new gce_MakeMirror2d(*Point->GetPnt2d());
	};

	xgce_MakeMirror2d::xgce_MakeMirror2d(xgp_Ax2d^ Axis) {
		NativeHandle = new gce_MakeMirror2d(*Axis->GetAx2d());
	};

	xgce_MakeMirror2d::xgce_MakeMirror2d(xgp_Lin2d^ Line) {
		NativeHandle = new gce_MakeMirror2d(*Line->GetLin2d());
	};

	//! Makes a symmetry transformation af axis defined by
	//! <Point> and <Direc>.
	xgce_MakeMirror2d::xgce_MakeMirror2d(xgp_Pnt2d^ Point, xgp_Dir2d^ Direc) {
		NativeHandle = new gce_MakeMirror2d(*Point->GetPnt2d(), *Direc->GetDir2d());
	};

	//! Returns theructed transformation.
	xgp_Trsf2d^ xgce_MakeMirror2d::Value() {
		gp_Trsf2d* temp = new gp_Trsf2d(NativeHandle->Value());
		return gcnew xgp_Trsf2d(temp);
	};

	xgp_Trsf2d^ xgce_MakeMirror2d::Operator() {
		gp_Trsf2d* temp = new gp_Trsf2d(NativeHandle->Operator());
		return gcnew xgp_Trsf2d(temp);
	};
	xgce_MakeMirror2d::operator xgp_Trsf2d^() {
		gp_Trsf2d* temp = new gp_Trsf2d(NativeHandle->Operator());
		return gcnew xgp_Trsf2d(temp);
	};
}