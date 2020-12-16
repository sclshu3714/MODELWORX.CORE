#include <XGeom_CartesianPoint.h>
namespace TKG3d {
	XGeom_CartesianPoint::XGeom_CartesianPoint() {
		//NativeHandle() = new Geom_CartesianPoint();
	};

	XGeom_CartesianPoint::XGeom_CartesianPoint(Handle(Geom_CartesianPoint) pos) {
		NativeHandle() = pos;
		SetPointHandle(NativeHandle());
	};

	void XGeom_CartesianPoint::SetCartesianPointHandle(Handle(Geom_CartesianPoint) pos) {
		NativeHandle() = pos;
		SetPointHandle(NativeHandle());
	};

	Handle(Geom_CartesianPoint) XGeom_CartesianPoint::GetCartesianPoint() {
		return NativeHandle();
	};

	Handle(Geom_Point) XGeom_CartesianPoint::GetPoint() {
		return NativeHandle();
	};

	//!
	Handle(Geom_Geometry) XGeom_CartesianPoint::GetGeometry() {
		return NativeHandle();
	};

	//! Returns a transient copy of P.
	XGeom_CartesianPoint::XGeom_CartesianPoint(xgp_Pnt^ P) {
		NativeHandle() = new Geom_CartesianPoint(*P->GetPnt());
		SetPointHandle(NativeHandle());
	};

	//! Constructs a point defined by its three Cartesian coordinates X, Y and Z.
	XGeom_CartesianPoint::XGeom_CartesianPoint(Standard_Real X, Standard_Real Y, Standard_Real Z) {
		NativeHandle() = new Geom_CartesianPoint(X, Y, Z);
		SetPointHandle(NativeHandle());
	};

	//! Assigns the coordinates X, Y and Z to this point.
	void XGeom_CartesianPoint::SetCoord(Standard_Real X, Standard_Real Y, Standard_Real Z) {
		NativeHandle()->SetCoord(X, Y, Z);
	};

	//! Set <me> to P.X(), P.Y(), P.Z() coordinates.
	void XGeom_CartesianPoint::SetPnt(xgp_Pnt^ P) {
		NativeHandle()->SetPnt(*P->GetPnt());
	};

	//! Changes the X coordinate of me.
	void XGeom_CartesianPoint::SetX(Standard_Real X) {
		NativeHandle()->SetX(X);
	};

	//! Changes the Y coordinate of me.
	void XGeom_CartesianPoint::SetY(Standard_Real Y) {
		NativeHandle()->SetY(Y);
	};

	//! Changes the Z coordinate of me.
	void XGeom_CartesianPoint::SetZ(Standard_Real Z) {
		NativeHandle()->SetZ(Z);
	};

	//! Returns the coordinates of <me>.
	void XGeom_CartesianPoint::Coord(Standard_Real% X, Standard_Real% Y, Standard_Real% Z) {
		Standard_Real XX(X); Standard_Real XY(Y); Standard_Real XZ(Z);
		NativeHandle()->Coord(XX, XY, XZ);
		X = XX; XY = Y; Z = XZ;
	};


	//! Returns a non transient cartesian point with
	//! the same coordinates as <me>.
	xgp_Pnt^ XGeom_CartesianPoint::Pnt() {
		gp_Pnt* temp = new gp_Pnt(NativeHandle()->Pnt());
		return gcnew xgp_Pnt(temp);
	};

	//! Returns the X coordinate of <me>.
	Standard_Real XGeom_CartesianPoint::X() {
		return NativeHandle()->X();
	};

	//! Returns the Y coordinate of <me>.
	Standard_Real XGeom_CartesianPoint::Y() {
		return NativeHandle()->Y();
	};

	//! Returns the Z coordinate of <me>.
	Standard_Real XGeom_CartesianPoint::Z() {
		return NativeHandle()->Z();
	};

	//! Applies the transformation T to this point.
	void XGeom_CartesianPoint::Transform(xgp_Trsf^ T) {
		NativeHandle()->Transform(*T->GetTrsf());
	};

	//! Creates a new object which is a copy of this point.
	XGeom_Geometry^ XGeom_CartesianPoint::Copy() {
		return gcnew XGeom_Geometry(NativeHandle()->Copy());
	};
}