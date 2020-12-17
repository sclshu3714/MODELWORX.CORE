#include "XGeom_OsculatingSurface.h"
namespace TKG3d
{

	//! DEFINE_STANDARD_ALLOC
	XGeom_OsculatingSurface::XGeom_OsculatingSurface() {
		NativeHandle() = new Geom_OsculatingSurface();
	};

	XGeom_OsculatingSurface::XGeom_OsculatingSurface(Handle(Geom_OsculatingSurface) pos) {
		NativeHandle() = pos;
	};

	void XGeom_OsculatingSurface::SetOsculatingSurfaceHandle(Handle(Geom_OsculatingSurface) pos) {
		NativeHandle() = pos;
	};

	Handle(Geom_OsculatingSurface) XGeom_OsculatingSurface::GetOsculatingSurface() {
		return NativeHandle();
	};


	//! detects if the  surface has punctual U  or  V
	//! isoparametric  curve along on  the bounds of the surface
	//! relativly to the tolerance Tol and Builds the corresponding
	//! osculating surfaces.
	XGeom_OsculatingSurface::XGeom_OsculatingSurface(XGeom_Surface^ BS, Standard_Real Tol) {
		NativeHandle() = new Geom_OsculatingSurface(BS->GetSurface(), Tol);
	};

	void XGeom_OsculatingSurface::Init(XGeom_Surface^ BS, Standard_Real Tol) {
		NativeHandle()->Init(BS->GetSurface(), Tol);
	};

	XGeom_Surface^ XGeom_OsculatingSurface::BasisSurface() {
		return gcnew XGeom_Surface(NativeHandle()->BasisSurface());
	};

	Standard_Real XGeom_OsculatingSurface::Tolerance() {
		return NativeHandle()->Tolerance();
	};

	//! if Standard_True, L is the local osculating surface
	//! along U at the point U,V.
	Standard_Boolean XGeom_OsculatingSurface::UOscSurf(Standard_Real U, Standard_Real V, Standard_Boolean% t, XGeom_BSplineSurface^% L) {
		Standard_Boolean Xt = t; Handle(Geom_BSplineSurface) XL = L->GetBSplineSurface();
		return NativeHandle()->UOscSurf(U, V, Xt, XL);
		t = Xt; L = gcnew XGeom_BSplineSurface(XL);
	};

	//! if Standard_True, L is the local osculating surface
	//! along V at the point U,V.
	Standard_Boolean XGeom_OsculatingSurface::VOscSurf(Standard_Real U, Standard_Real V, Standard_Boolean% t, XGeom_BSplineSurface^% L) {
		Standard_Boolean Xt = t; Handle(Geom_BSplineSurface) XL = L->GetBSplineSurface();
		return NativeHandle()->VOscSurf(U, V, Xt, XL);
		t = Xt; L = gcnew XGeom_BSplineSurface(XL);
	};
}
