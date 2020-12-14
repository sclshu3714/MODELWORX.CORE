#include <XGeom_Axis1Placement.h>
namespace TKG3d {
	//! 
	XGeom_Axis1Placement::XGeom_Axis1Placement(void) {
		/*NativeHandle() = new Geom_Axis1Placement();*/
	};

	//! 
	XGeom_Axis1Placement::XGeom_Axis1Placement(Handle(Geom_Axis1Placement) pos) {
		NativeHandle() = pos;
		SetAxisPlacementHandle(NativeHandle());
	};

	//!
	XGeom_Axis1Placement::~XGeom_Axis1Placement() {
		NativeHandle() = NULL;
		SetAxisPlacementHandle(NativeHandle());
	};

	//! 
	void XGeom_Axis1Placement::SetAxis1PlacementHandle(Handle(Geom_Axis1Placement) pos) {
		NativeHandle() = pos;
		SetAxisPlacementHandle(NativeHandle());
	};

	//!
	Handle(Geom_Axis1Placement) XGeom_Axis1Placement::GetAxis1Placement() {
		return NativeHandle();
	};

	//!
	Handle(Geom_AxisPlacement) XGeom_Axis1Placement::GetAxisPlacement() {
		return NativeHandle();
	};

	//!
	Handle(Geom_Geometry) XGeom_Axis1Placement::XGeom_Axis1Placement::GetGeometry() {
		return NativeHandle();
	};

	//! Returns a transient copy of A1.
	XGeom_Axis1Placement::XGeom_Axis1Placement(xgp_Ax1^ A1) {
		NativeHandle() = new Geom_Axis1Placement(*A1->GetAx1());
		SetAxisPlacementHandle(NativeHandle());
	};


	//! P is the origin of the axis placement and V is the direction
	//! of the axis placement.
	XGeom_Axis1Placement::XGeom_Axis1Placement(xgp_Pnt^ P, xgp_Dir^ V) {
		NativeHandle() = new Geom_Axis1Placement(*P->GetPnt(), *V->GetDir());
		SetAxisPlacementHandle(NativeHandle());
	};

	//! Returns a non transient copy of <me>.
	xgp_Ax1^ XGeom_Axis1Placement::Ax1() {
		gp_Ax1* temp = new gp_Ax1(NativeHandle()->Ax1());
		return gcnew xgp_Ax1(temp);
	};

	//! Reverses the direction of the axis placement.
	void XGeom_Axis1Placement::Reverse() {
		NativeHandle()->Reverse();
	};

	//! Returns a copy of <me> reversed.
	XGeom_Axis1Placement^ XGeom_Axis1Placement::Reversed() {
		return gcnew XGeom_Axis1Placement(NativeHandle()->Reversed());
	};

	//! Assigns V to the unit vector of this axis.
	void XGeom_Axis1Placement::SetDirection(xgp_Dir^ V) {
		NativeHandle()->SetDirection(*V->GetDir());
	};

	//! Applies the transformation T to this axis.
	void XGeom_Axis1Placement::Transform(xgp_Trsf^ T) {
		NativeHandle()->Transform(*T->GetTrsf());
	};

	//! Creates a new object, which is a copy of this axis.
	XGeom_Geometry^ XGeom_Axis1Placement::Copy() {
		return gcnew XGeom_Geometry(NativeHandle()->Copy());
	};
}
