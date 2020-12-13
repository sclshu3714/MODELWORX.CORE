#include "XGeom_BoundedSurface.h"
namespace TKG3d {
	//!
	XGeom_BoundedSurface::XGeom_BoundedSurface(void) {

	};

	//! 
	XGeom_BoundedSurface::XGeom_BoundedSurface(Handle(Geom_BoundedSurface) pos) {
		NativeHandle() = pos;
		SetSurfaceHandle(NativeHandle());
	};

	//!
	XGeom_BoundedSurface::~XGeom_BoundedSurface() {
		NativeHandle() = NULL;
		SetSurfaceHandle(NativeHandle());
	};

	void XGeom_BoundedSurface::SetBoundedSurfaceHandle(Handle(Geom_BoundedSurface) handle) {
		NativeHandle() = handle;
		SetSurfaceHandle(NativeHandle());
	};

	//!
	Handle(Geom_BoundedSurface) XGeom_BoundedSurface::GetBoundedSurface() {
		return NativeHandle();
	};

	//!
	Handle(Geom_Surface) XGeom_BoundedSurface::GetSurface() {
		return NativeHandle();
	};

	//!
	Handle(Geom_Geometry) XGeom_BoundedSurface::GetGeometry() {
		return NativeHandle();
	};
}
