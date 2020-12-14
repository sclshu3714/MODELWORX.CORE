#include <XGC_MakeCylindricalSurface.h>
namespace TKGeomBase {

	//! DEFINE_STANDARD_ALLOC

	//!
	XGC_MakeCylindricalSurface::XGC_MakeCylindricalSurface(GC_MakeCylindricalSurface* pos) {
		NativeHandle = pos;
		SetRoot(NativeHandle);
	};

	//!
	void XGC_MakeCylindricalSurface::SetMakeCylindricalSurfaceHandle(GC_MakeCylindricalSurface* pos) {
		NativeHandle = pos;
		SetRoot(NativeHandle);
	};

	//!
	GC_MakeCylindricalSurface* XGC_MakeCylindricalSurface::GetMakeCylindricalSurface() {
		return NativeHandle;
	};

	//! A2 defines the local coordinate system of the cylindrical surface.
	//! The "ZDirection" of A2 defines the direction of the surface's
	//! axis of symmetry.
	//! At the creation the parametrization of the surface is defined
	//! such that the normal Vector (N = D1U ^ D1V) is oriented towards
	//! the "outside region" of the surface.
	//! Warnings :
	//! It is not forbidden to create a cylindrical surface with
	//! Radius = 0.0
	//! Status is "NegativeRadius" if Radius < 0.0
	XGC_MakeCylindricalSurface::XGC_MakeCylindricalSurface(xgp_Ax2^ A2, Standard_Real Radius) {
		NativeHandle = new GC_MakeCylindricalSurface(*A2->GetAx2(), Radius);
		SetRoot(NativeHandle);
	};


	//! Creates a CylindricalSurface from a non persistent Cylinder
	//! from package gp.
	XGC_MakeCylindricalSurface::XGC_MakeCylindricalSurface(xgp_Cylinder^ C) {
		NativeHandle = new GC_MakeCylindricalSurface(*C->GetCylinder());
		SetRoot(NativeHandle);
	};

	//! Make a CylindricalSurface from Geom <TheCylinder>
	//! parallel to another
	//! CylindricalSurface <Cylinder> and passing through a
	//! Pnt <Point>.
	XGC_MakeCylindricalSurface::XGC_MakeCylindricalSurface(xgp_Cylinder^ Cyl, xgp_Pnt^ Point) {
		NativeHandle = new GC_MakeCylindricalSurface(*Cyl->GetCylinder(), *Point->GetPnt());
		SetRoot(NativeHandle);
	};

	//! Make a CylindricalSurface from Geom <TheCylinder>
	//! parallel to another
	//! CylindricalSurface <Cylinder> at the distance <Dist>
	//! which can be greater or lower than zero.
	//! The radius of the result is the absolute value of the
	//! radius of <Cyl> plus <Dist>
	XGC_MakeCylindricalSurface::XGC_MakeCylindricalSurface(xgp_Cylinder^ Cyl, Standard_Real Dist) {
		NativeHandle = new GC_MakeCylindricalSurface(*Cyl->GetCylinder(), Dist);
		SetRoot(NativeHandle);
	};

	//! Make a CylindricalSurface from Geom <TheCylinder>
	//! passing through 3 Pnt <P1>,<P2>,<P3>.
	//! Its axis is <P1P2> and its radius is the distance
	//! between <P3> and <P1P2>
	XGC_MakeCylindricalSurface::XGC_MakeCylindricalSurface(xgp_Pnt^ P1, xgp_Pnt^ P2, xgp_Pnt^ P3) {
		NativeHandle = new GC_MakeCylindricalSurface(*P1->GetPnt(), *P2->GetPnt(),*P3->GetPnt());
		SetRoot(NativeHandle);
	};

	//! Make a CylindricalSurface by its axis <Axis> and radius
	//! <Radius>.
	XGC_MakeCylindricalSurface::XGC_MakeCylindricalSurface(xgp_Ax1^ Axis, Standard_Real Radius) {
		NativeHandle = new GC_MakeCylindricalSurface(*Axis->GetAx1(), Radius);
		SetRoot(NativeHandle);
	};

	//! Make a CylindricalSurface by its circular base.
	XGC_MakeCylindricalSurface::XGC_MakeCylindricalSurface(xgp_Circ^ Circ) {
		NativeHandle = new GC_MakeCylindricalSurface(*Circ->GetCirc());
		SetRoot(NativeHandle);
	};

	//! Returns the constructed cylinder.
	//! Exceptions StdFail_NotDone if no cylinder is constructed.
	XGeom_CylindricalSurface^ XGC_MakeCylindricalSurface::Value() {
		return gcnew XGeom_CylindricalSurface(NativeHandle->Value());
	};

	//! Returns true if the construction is successful.
	Standard_Boolean XGC_MakeCylindricalSurface::IsDone() {
		return NativeHandle->IsDone();
	};

	//! Returns the status of the construction:
	//! -   gce_Done, if the construction is successful, or
	//! -   another value of the gce_ErrorType enumeration
	//! indicating why the construction failed.
	xgce_ErrorType XGC_MakeCylindricalSurface::Status() {
		return safe_cast<xgce_ErrorType>(NativeHandle->Status());
	};
}
