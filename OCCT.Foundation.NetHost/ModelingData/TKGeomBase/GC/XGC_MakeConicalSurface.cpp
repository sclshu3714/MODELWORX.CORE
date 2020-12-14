#include <XGC_MakeConicalSurface.h>
namespace TKGeomBase {
	//! DEFINE_STANDARD_ALLOC

	XGC_MakeConicalSurface::XGC_MakeConicalSurface(GC_MakeConicalSurface* pos) {
		NativeHandle = pos;
		SetRoot(NativeHandle);
	};

	void XGC_MakeConicalSurface::SetMakeConicalSurfaceHandle(GC_MakeConicalSurface* pos) {
		NativeHandle = pos;
		SetRoot(NativeHandle);
	};

	GC_MakeConicalSurface* XGC_MakeConicalSurface::GetMakeConicalSurface() {
		return NativeHandle;
	};

	//! A2 defines the local coordinate system of the conical surface.
	//! Ang is the conical surface semi-angle ]0, PI/2[.
	//! Radius is the radius of the circle Viso in the placement plane
	//! of the conical surface defined with "XAxis" and "YAxis".
	//! The "ZDirection" of A2 defines the direction of the surface's
	//! axis of symmetry.
	//! If the location point of A2 is the apex of the surface
	//! Radius = 0 .
	//! At the creation the parametrization of the surface is defined
	//! such that the normal Vector (N = D1U ^ D1V) is oriented towards
	//! the "outside region" of the surface.
	//! Status is "NegativeRadius" if Radius < 0.0 or "BadAngle" if
	//! Ang < Resolution from gp or Ang >= PI/ - Resolution
	XGC_MakeConicalSurface::XGC_MakeConicalSurface(xgp_Ax2^ A2, Standard_Real Ang, Standard_Real Radius) {
		NativeHandle = new GC_MakeConicalSurface(*A2->GetAx2(), Ang, Radius);
		SetRoot(NativeHandle);
	};

	//! Creates a ConicalSurface from a non persistent Cone from package gp.
	XGC_MakeConicalSurface::XGC_MakeConicalSurface(xgp_Cone^ C) {
		NativeHandle = new GC_MakeConicalSurface(*C->GetCone());
		SetRoot(NativeHandle);
	};

	//! Make a ConicalSurface from Geom <TheCone> passing through 3
	//! Pnt <P1>,<P2>,<P3>.
	//! Its axis is <P1P2> and the radius of its base is
	//! the distance between <P3> and <P1P2>.
	//! The distance between <P4> and <P1P2> is the radius of
	//! the section passing through <P4>.
	//! An error iss raised if <P1>,<P2>,<P3>,<P4> are
	//! colinear or if <P3P4> is perpendicular to <P1P2> or
	//! <P3P4> is colinear to <P1P2>.
	XGC_MakeConicalSurface::XGC_MakeConicalSurface(xgp_Pnt^ P1, xgp_Pnt^ P2, xgp_Pnt^ P3, xgp_Pnt^ P4) {
		NativeHandle = new GC_MakeConicalSurface(*P1->GetPnt(), *P2->GetPnt(), *P3->GetPnt(), *P4->GetPnt());
		SetRoot(NativeHandle);
	};

	//! Make a ConicalSurface with two points and two radius.
	//! The axis of the solution is the line passing through
	//! <P1> and <P2>.
	//! <R1> is the radius of the section passing through <P1>
	//! and <R2> the radius of the section passing through <P2>.
	XGC_MakeConicalSurface::XGC_MakeConicalSurface(xgp_Pnt^ P1, xgp_Pnt^ P2, Standard_Real R1, Standard_Real R2) {
		NativeHandle = new GC_MakeConicalSurface(*P1->GetPnt(), *P2->GetPnt(), R1, R2);
		SetRoot(NativeHandle);
	};

	//! Returns the constructed cone.
	//! Exceptions
	//! StdFail_NotDone if no cone is constructed.
	XGeom_ConicalSurface^ XGC_MakeConicalSurface::Value() {
		return gcnew XGeom_ConicalSurface(NativeHandle->Value());
	};

	//! Returns true if the construction is successful.
	Standard_Boolean XGC_MakeConicalSurface::IsDone() {
		return NativeHandle->IsDone();
	};

	//! Returns the status of the construction:
	//! -   gce_Done, if the construction is successful, or
	//! -   another value of the gce_ErrorType enumeration
	//! indicating why the construction failed.
	xgce_ErrorType XGC_MakeConicalSurface::Status() {
		return safe_cast<xgce_ErrorType>(NativeHandle->Status());
	};
}
