#include <XGeom_SweptSurface.h>
namespace TKG3d
{
	//!
	XGeom_SweptSurface::XGeom_SweptSurface(void) {
		/*NativeHandle() = new Geom_SweptSurface();*/
	};

	//! 
	XGeom_SweptSurface::XGeom_SweptSurface(Handle(Geom_SweptSurface) pos) {
		NativeHandle() = pos;
		SetSurfaceHandle(NativeHandle());
	};

	//!
	XGeom_SweptSurface::~XGeom_SweptSurface() {
		NativeHandle() = NULL;
		SetSurfaceHandle(NativeHandle());
	};

	void XGeom_SweptSurface::SetSweptSurfaceHandle(Handle(Geom_SweptSurface) handle) {
		NativeHandle() = handle;
		SetSurfaceHandle(NativeHandle());
	};

	//!
	Handle(Geom_SweptSurface) XGeom_SweptSurface::GetSweptSurface() {
		return NativeHandle();
	};

	//!
	Handle(Geom_Surface) XGeom_SweptSurface::GetSurface() {
		return NativeHandle();
	};

	//!
	Handle(Geom_Geometry) XGeom_SweptSurface::GetGeometry() {
		return NativeHandle();
	};

	//! returns the continuity of the surface :
	//! C0 : only geometric continuity,
	//! C1 : continuity of the first derivative all along the surface,
	//! C2 : continuity of the second derivative all along the surface,
	//! C3 : continuity of the third derivative all along the surface,
	//! G1 : tangency continuity all along the surface,
	//! G2 : curvature continuity all along the surface,
	//! CN : the order of continuity is infinite.
	XGeomAbs_Shape XGeom_SweptSurface::Continuity() {
		return safe_cast<XGeomAbs_Shape>(NativeHandle()->Continuity());
	};

	//! Returns the reference direction of the swept surface.
	//! For a surface of revolution it is the direction of the
	//! revolution axis, for a surface of linear extrusion it is
	//! the direction of extrusion.
	xgp_Dir^ XGeom_SweptSurface::Direction() {
		gp_Dir* temp = new gp_Dir(NativeHandle()->Direction());
		return gcnew xgp_Dir(temp);
	};

	//! Returns the referenced curve of the surface.
	//! For a surface of revolution it is the revolution curve,
	//! for a surface of linear extrusion it is the extruded curve.
	XGeom_Curve^ XGeom_SweptSurface::BasisCurve() {
		return gcnew XGeom_Curve(NativeHandle()->BasisCurve());
	};
}
