#include <XGC_MakeRotation.h>
namespace TKGeomBase {
	//! DEFINE_STANDARD_ALLOC
	XGC_MakeRotation::XGC_MakeRotation() {
		//NativeHandle = new GC_MakeRotation();
	};

	XGC_MakeRotation::XGC_MakeRotation(GC_MakeRotation* pos) {
		NativeHandle = pos;
	};

	void XGC_MakeRotation::SetMakeRotation(GC_MakeRotation* pos) {
		NativeHandle = pos;
	};

	GC_MakeRotation* XGC_MakeRotation::GetMakeRotation() {
		return NativeHandle;
	};

	//! Constructs a rotation through angle Angle about the axis defined by the line Line.
	XGC_MakeRotation::XGC_MakeRotation(xgp_Lin^ Line, Standard_Real Angle) {
		NativeHandle = new GC_MakeRotation(*Line->GetLin(), Angle);
	};

	//! Constructs a rotation through angle Angle about the axis defined by the axis Axis.
	XGC_MakeRotation::XGC_MakeRotation(xgp_Ax1^ Axis, Standard_Real Angle) {
		NativeHandle = new GC_MakeRotation(*Axis->GetAx1(), Angle);
	};

	//! Constructs a rotation through angle Angle about the axis
	//! defined by the point Point and the unit vector Direc.
	XGC_MakeRotation::XGC_MakeRotation(xgp_Pnt^ Point, xgp_Dir^ Direc, Standard_Real Angle) {
		NativeHandle = new GC_MakeRotation(*Point->GetPnt(), *Direc->GetDir(), Angle);
	};

	//! Returns the constructed transformation.
	XGeom_Transformation^ XGC_MakeRotation::Value() {
		return gcnew XGeom_Transformation(NativeHandle->Value());
	};
}
