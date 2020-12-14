#include "XGeom_AxisPlacement.h"

namespace TKG3d {
	//! 
	XGeom_AxisPlacement::XGeom_AxisPlacement(void) {
		//NativeHandle() = new Geom_AxisPlacement();
	};

	//! 
	XGeom_AxisPlacement::XGeom_AxisPlacement(Handle(Geom_AxisPlacement) pos) {
		NativeHandle() = pos;
		SetGeometryHandle(NativeHandle());
	};

	//!
	XGeom_AxisPlacement::~XGeom_AxisPlacement() {
		NativeHandle() = NULL;
		SetGeometryHandle(NativeHandle());
	};

	//! 
	void XGeom_AxisPlacement::SetAxisPlacementHandle(Handle(Geom_AxisPlacement) pos) {
		NativeHandle() = pos;
		SetGeometryHandle(NativeHandle());
	};

	//!
	Handle(Geom_AxisPlacement) XGeom_AxisPlacement::GetAxisPlacement() {
		return NativeHandle();
	};

	//!
	Handle(Geom_Geometry) XGeom_AxisPlacement::GetGeometry() {
		return NativeHandle();
	};

	//! Assigns A1 as the "main Axis" of this positioning system. This modifies
	//! - its origin, and
	//! - its "main Direction".
	//! If this positioning system is a
	//! Geom_Axis2Placement, then its "X Direction" and
	//! "Y Direction" are recomputed.
	//! Exceptions
	//! For a Geom_Axis2Placement:
	//! Standard_ConstructionError if A1 and the
	//! previous "X Direction" of the coordinate system are parallel.
	void XGeom_AxisPlacement::SetAxis(xgp_Ax1^ A1) {
		NativeHandle()->SetAxis(*A1->GetAx1());
	};


	//! Changes the direction of the axis placement.
	//! If <me> is an axis placement two axis the main "Direction"
	//! is modified and the "XDirection" and "YDirection" are
	//! recomputed.
	//! Raises ConstructionError only for an axis placement two axis if V and the
	//! previous "XDirection" are parallel because it is not possible
	//! to calculate the new "XDirection" and the new "YDirection".
	void XGeom_AxisPlacement::SetDirection(xgp_Dir^ V) {
		NativeHandle()->SetDirection(*V->GetDir());
	};


	//! Assigns the point P as the origin of this positioning  system.
	void XGeom_AxisPlacement::SetLocation(xgp_Pnt^ P) {
		NativeHandle()->SetLocation(*P->GetPnt());
	};

	//! Computes the angular value, in radians, between the
	//! "main Direction" of this positioning system and that
	//! of positioning system Other. The result is a value between 0 and Pi.
	Standard_Real XGeom_AxisPlacement::Angle(XGeom_AxisPlacement^ Other) {
		return NativeHandle()->Angle(Other->GetAxisPlacement());
	};

	//! Returns the main axis of the axis placement.
	//! For an "Axis2placement" it is the main axis (Location, Direction ).
	//! For an "Axis1Placement" this method returns a copy of <me>.
	xgp_Ax1^ XGeom_AxisPlacement::Axis() {
		gp_Ax1* temp = new gp_Ax1(NativeHandle()->Axis());
		return gcnew xgp_Ax1(temp);
	};


	//! Returns the main "Direction" of an axis placement.
	xgp_Dir^ XGeom_AxisPlacement::Direction() {
		gp_Dir* temp = new gp_Dir(NativeHandle()->Direction());
		return gcnew xgp_Dir(temp);
	};


	//! Returns the Location point (origin) of the axis placement.
	xgp_Pnt^ XGeom_AxisPlacement::Location() {
		gp_Pnt* temp = new gp_Pnt(NativeHandle()->Location());
		return gcnew xgp_Pnt(temp);
	};
}
