#include <XGeom_Axis2Placement.h>
namespace TKG3d {
	//! 
	XGeom_Axis2Placement::XGeom_Axis2Placement(void) {
		//NativeHandle() = new Geom_Axis2Placement();
	};

	//! 
	XGeom_Axis2Placement::XGeom_Axis2Placement(Handle(Geom_Axis2Placement) pos) {
		NativeHandle() = pos;
		SetAxisPlacementHandle(NativeHandle());
	};

	//!
	XGeom_Axis2Placement::~XGeom_Axis2Placement() {
		NativeHandle() = NULL;
		SetAxisPlacementHandle(NativeHandle());
	};

	//! 
	void XGeom_Axis2Placement::SetAxis2PlacementHandle(Handle(Geom_Axis2Placement) pos) {
		NativeHandle() = pos;
		SetAxisPlacementHandle(NativeHandle());
	};

	//!
	Handle(Geom_Axis2Placement) XGeom_Axis2Placement::GetAxis2Placement() {
		return NativeHandle();
	};

	//!
	Handle(Geom_AxisPlacement) XGeom_Axis2Placement::GetAxisPlacement() {
		return NativeHandle();
	};

	//!
	Handle(Geom_Geometry) XGeom_Axis2Placement::GetGeometry() {
		return NativeHandle();
	};

	//! Returns a transient copy of A2.
	XGeom_Axis2Placement::XGeom_Axis2Placement(xgp_Ax2^ A2) {
		NativeHandle() = new Geom_Axis2Placement(*A2->GetAx2());
		SetAxisPlacementHandle(NativeHandle());
	};


	//! P is the origin of the axis placement, N is the main
	//! direction of the axis placement and Vx is the "XDirection".
	//! If the two directions N and Vx are not orthogonal the
	//! "XDirection" is computed as follow :
	//! XDirection = N ^ (Vx ^ N).
	//! Raised if N and Vx are parallel.
	XGeom_Axis2Placement::XGeom_Axis2Placement(xgp_Pnt^ P, xgp_Dir^ N, xgp_Dir^ Vx) {
		NativeHandle() = new Geom_Axis2Placement(*P->GetPnt(), *N->GetDir(), *Vx->GetDir());
		SetAxisPlacementHandle(NativeHandle());
	};

	//! Assigns the origin and the three unit vectors of A2 to
	//! this coordinate system.
	void XGeom_Axis2Placement::SetAx2(xgp_Ax2^ A2) {
		NativeHandle()->SetAx2(*A2->GetAx2());
	};


	//! Changes the main direction of the axis placement.
	//! The "Xdirection" is modified :
	//! New XDirection = V ^ (Previous_Xdirection ^ V).
	//!
	//! Raised if V and the previous "XDirection" are parallel
	//! because it is impossible to calculate the new "XDirection"
	//! and the new "YDirection".
	void XGeom_Axis2Placement::SetDirection(xgp_Dir^ V) {
		NativeHandle()->SetDirection(*V->GetDir());
	};


	//! Changes the "XDirection" of the axis placement, Vx is the
	//! new "XDirection". If Vx is not normal to the main direction
	//! then "XDirection" is computed as follow :
	//! XDirection = Direction ^ ( Vx ^ Direction).
	//! The main direction is not modified.
	//! Raised if Vx and "Direction"  are parallel.
	void XGeom_Axis2Placement::SetXDirection(xgp_Dir^ Vx) {
		NativeHandle()->SetXDirection(*Vx->GetDir());
	};


	//! Changes the "YDirection" of the axis placement, Vy is the
	//! new "YDirection". If Vy is not normal to the main direction
	//! then "YDirection" is computed as follow :
	//! YDirection = Direction ^ ( Vy ^ Direction).
	//! The main direction is not modified. The "XDirection" is
	//! modified.
	//! Raised if Vy and the main direction are parallel.
	void XGeom_Axis2Placement::SetYDirection(xgp_Dir^ Vy) {
		NativeHandle()->SetYDirection(*Vy->GetDir());
	};

	//! Returns a non transient copy of <me>.
	xgp_Ax2^ XGeom_Axis2Placement::Ax2() {
		gp_Ax2* temp = new gp_Ax2(NativeHandle()->Ax2());
		return gcnew xgp_Ax2(temp);
	};

	//! Returns the "XDirection". This is a unit vector.
	xgp_Dir^ XGeom_Axis2Placement::XDirection() {
		gp_Dir* temp = new gp_Dir(NativeHandle()->XDirection());
		return gcnew xgp_Dir(temp);
	};

	//! Returns the "YDirection". This is a unit vector.
	xgp_Dir^ XGeom_Axis2Placement::YDirection() {
		gp_Dir* temp = new gp_Dir(NativeHandle()->YDirection());
		return gcnew xgp_Dir(temp);
	};


	//! Transforms an axis placement with a Trsf.
	//! The "Location" point, the "XDirection" and the
	//! "YDirection" are transformed with T.  The resulting
	//! main "Direction" of <me> is the cross product between
	//! the "XDirection" and the "YDirection" after transformation.
	void XGeom_Axis2Placement::Transform(xgp_Trsf^ T) {
		NativeHandle()->Transform(*T->GetTrsf());
	};

	//! Creates a new object which is a copy of this coordinate system.
	XGeom_Geometry^ XGeom_Axis2Placement::Copy() {
		return gcnew XGeom_Geometry(NativeHandle()->Copy());
	};
}