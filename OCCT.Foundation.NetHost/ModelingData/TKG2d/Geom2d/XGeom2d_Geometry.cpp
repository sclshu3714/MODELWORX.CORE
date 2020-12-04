#include <XGeom2d_Geometry.h>
namespace TKG2d {
	XGeom2d_Geometry::XGeom2d_Geometry()
	{}
	XGeom2d_Geometry::XGeom2d_Geometry(Handle(Geom2d_Geometry) pos) {
		NativeHandle() = pos;
	};

	void XGeom2d_Geometry::SetGeometryHandle(Handle(Geom2d_Geometry) pos) {
		NativeHandle() = pos;
	};

	Handle(Geom2d_Geometry) XGeom2d_Geometry::GetGeometry() {
		return NativeHandle();
	};

	//! Performs the symmetrical transformation of a Geometry
	//! with respect to the point P which is the center of the
	//! symmetry and assigns the result to this geometric object.
	void XGeom2d_Geometry::Mirror(xgp_Pnt2d^ P) {
		NativeHandle()->Mirror(P->GetPnt2d());
	};

	//! Performs the symmetrical transformation of a Geometry
	//! with respect to an axis placement which is the axis of the symmetry.
	void XGeom2d_Geometry::Mirror(xgp_Ax2d^ A) {
		NativeHandle()->Mirror(*A->GetAx2d());
	};

	//! Rotates a Geometry. P is the center of the rotation.
	//! Ang is the angular value of the rotation in radians.
	void XGeom2d_Geometry::Rotate(xgp_Pnt2d^ P, Standard_Real Ang) {
		NativeHandle()->Rotate(P->GetPnt2d(), Ang);
	};

	//! Scales a Geometry. S is the scaling value.
	void XGeom2d_Geometry::Scale(xgp_Pnt2d^ P, Standard_Real S) {
		NativeHandle()->Scale(P->GetPnt2d(), S);
	};

	//! Translates a Geometry.  V is the vector of the tanslation.
	void XGeom2d_Geometry::Translate(xgp_Vec2d^ V) {
		NativeHandle()->Translate(V->GetVec2d());
	};

	//! Translates a Geometry from the point P1 to the point P2.
	void XGeom2d_Geometry::Translate(xgp_Pnt2d^ P1, xgp_Pnt2d^ P2) {
		NativeHandle()->Translate(P1->GetPnt2d(), P2->GetPnt2d());
	};

	//! Transformation of a geometric object. This tansformation
	//! can be a translation, a rotation, a symmetry, a scaling
	//! or a complex transformation obtained by combination of
	//! the previous elementaries transformations.
	//! (see class Transformation of the package Geom2d).
	//! The following transformations have the same properties
	//! as the previous ones but they don't modified the object
	//! itself. A copy of the object is returned.
	void XGeom2d_Geometry::Transform(xgp_Trsf2d^ T) {
		NativeHandle()->Transform(T->GetTrsf2d());
	};

	XGeom2d_Geometry^ XGeom2d_Geometry::Mirrored(xgp_Pnt2d^ P) {
		return gcnew XGeom2d_Geometry(NativeHandle()->Mirrored(P->GetPnt2d()));
	};

	XGeom2d_Geometry^ XGeom2d_Geometry::Mirrored(xgp_Ax2d^ A) {
		return gcnew XGeom2d_Geometry(NativeHandle()->Mirrored(*A->GetAx2d()));
	};

	XGeom2d_Geometry^ XGeom2d_Geometry::Rotated(xgp_Pnt2d^ P, Standard_Real Ang) {
		return gcnew XGeom2d_Geometry(NativeHandle()->Rotated(P->GetPnt2d(), Ang));
	};

	XGeom2d_Geometry^ XGeom2d_Geometry::Scaled(xgp_Pnt2d^ P, Standard_Real S) {
		return gcnew XGeom2d_Geometry(NativeHandle()->Scaled(P->GetPnt2d(), S));
	};

	XGeom2d_Geometry^ XGeom2d_Geometry::Transformed(xgp_Trsf2d^ T) {
		return gcnew XGeom2d_Geometry(NativeHandle()->Transformed(T->GetTrsf2d()));
	};

	XGeom2d_Geometry^ XGeom2d_Geometry::Translated(xgp_Vec2d^ V) {
		return gcnew XGeom2d_Geometry(NativeHandle()->Translated(V->GetVec2d()));
	};

	XGeom2d_Geometry^ XGeom2d_Geometry::Translated(xgp_Pnt2d^ P1, xgp_Pnt2d^ P2) {
		return gcnew XGeom2d_Geometry(NativeHandle()->Translated(P1->GetPnt2d(), P2->GetPnt2d()));
	};

	XGeom2d_Geometry^ XGeom2d_Geometry::Copy() {
		return gcnew XGeom2d_Geometry(NativeHandle()->Copy());
	};
}
