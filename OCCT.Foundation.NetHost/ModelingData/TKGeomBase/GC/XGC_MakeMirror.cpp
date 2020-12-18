#include <XGC_MakeMirror.h>
namespace TKGeomBase {
	//! DEFINE_STANDARD_ALLOC
	XGC_MakeMirror::XGC_MakeMirror() {
		//NativeHandle = new GC_MakeMirror();
	};

	XGC_MakeMirror::XGC_MakeMirror(GC_MakeMirror* pos) {
		NativeHandle = pos;
	};

	void XGC_MakeMirror::SetMakeMirror(GC_MakeMirror* pos) {
		NativeHandle = pos;
	};

	GC_MakeMirror* XGC_MakeMirror::GetMakeMirror() {
		return NativeHandle;
	};

	XGC_MakeMirror::XGC_MakeMirror(xgp_Pnt^ Point) {
		NativeHandle = new GC_MakeMirror(*Point->GetPnt());
	};

	XGC_MakeMirror::XGC_MakeMirror(xgp_Ax1^ Axis) {
		NativeHandle = new GC_MakeMirror(*Axis->GetAx1());
	};

	XGC_MakeMirror::XGC_MakeMirror(xgp_Lin^ Line) {
		NativeHandle = new GC_MakeMirror(*Line->GetLin());
	};

	//! Make a symetry transformation af axis defined by
	//! <Point> and <Direc>.
	XGC_MakeMirror::XGC_MakeMirror(xgp_Pnt^ Point, xgp_Dir^ Direc) {
		NativeHandle = new GC_MakeMirror(*Point->GetPnt(), *Direc->GetDir());
	};

	//! Make a symetry transformation of plane <Plane>.
	XGC_MakeMirror::XGC_MakeMirror(xgp_Pln^ Plane) {
		NativeHandle = new GC_MakeMirror(*Plane->GetPln());
	};

	//! Make a symetry transformation of plane <Plane>.
	XGC_MakeMirror::XGC_MakeMirror(xgp_Ax2^ Plane) {
		NativeHandle = new GC_MakeMirror(*Plane->GetAx2());
	};

	//! Returns the constructed transformation.
	XGeom_Transformation^ XGC_MakeMirror::Value() {
		return gcnew XGeom_Transformation(NativeHandle->Value());
	};
}
