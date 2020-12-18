#include <XGC_MakeTrimmedCylinder.h>
namespace TKGeomBase {
	//DEFINE_STANDARD_ALLOC
	XGC_MakeTrimmedCylinder::XGC_MakeTrimmedCylinder() {

	};

	XGC_MakeTrimmedCylinder::XGC_MakeTrimmedCylinder(GC_MakeTrimmedCylinder* pos) {
		NativeHandle = pos;
		SetRoot(NativeHandle);
	};

	void XGC_MakeTrimmedCylinder::SetMakeTrimmedCylinder(GC_MakeTrimmedCylinder* pos) {
		NativeHandle = pos;
		SetRoot(NativeHandle);
	};

	GC_MakeTrimmedCylinder* XGC_MakeTrimmedCylinder::GetMakeTrimmedCylinder() {
		return NativeHandle;
	};

	GC_Root* XGC_MakeTrimmedCylinder::GetRoot() {
		return NativeHandle;
	};

	//! Make a cylindricalSurface <Cyl> from Geom
	//! Its axis is is <P1P2> and its radius is the distance
	//! between <P3> and <P1P2>.
	//! The height is the distance between P1 and P2.
	XGC_MakeTrimmedCylinder::XGC_MakeTrimmedCylinder(xgp_Pnt^ P1, xgp_Pnt^ P2, xgp_Pnt^ P3) {
		NativeHandle = new GC_MakeTrimmedCylinder(*P1->GetPnt(), *P2->GetPnt(), *P3->GetPnt());
		SetRoot(NativeHandle);
	};

	//! Make a cylindricalSurface <Cyl> from gp by its base <Circ>.
	//! Its axis is the normal to the plane defined bi <Circ>.
	//! <Height> can be greater than zero or lower than zero.
	//! In the first case the V parametric direction of the
	//! result has the same orientation as the normal to <Circ>.
	//! In the other case it has the opposite orientation.
	XGC_MakeTrimmedCylinder::XGC_MakeTrimmedCylinder(xgp_Circ^ Circ, Standard_Real Height) {
		NativeHandle = new GC_MakeTrimmedCylinder(*Circ->GetCirc(), Height);
		SetRoot(NativeHandle);
	};

	//! Make a cylindricalSurface <Cyl> from gp by its
	//! axis <A1> and its radius <Radius>.
	//! It returns NullObject if <Radius> is lower than zero.
	//! <Height> can be greater than zero or lower than zero.
	//! In the first case the V parametric direction of the
	//! result has the same orientation as <A1>.
	//! In the other case it has the opposite orientation.
	XGC_MakeTrimmedCylinder::XGC_MakeTrimmedCylinder(xgp_Ax1^ A1, Standard_Real Radius, Standard_Real Height) {
		NativeHandle = new GC_MakeTrimmedCylinder(*A1->GetAx1(), Radius, Height);
		SetRoot(NativeHandle);
	};

	//! Returns the constructed trimmed cylinder.
	//! Exceptions
	//! StdFail_NotDone if no trimmed cylinder is constructed.
	XGeom_RectangularTrimmedSurface^ XGC_MakeTrimmedCylinder::Value() {
		return gcnew XGeom_RectangularTrimmedSurface(NativeHandle->Value());
	};

	//! Returns true if the construction is successful.
	Standard_Boolean XGC_MakeTrimmedCylinder::IsDone() {
		return NativeHandle->IsDone();
	};

	//! Returns the status of the construction:
	//! -   gce_Done, if the construction is successful, or
	//! -   another value of the gce_ErrorType enumeration
	//! indicating why the construction failed.
	xgce_ErrorType XGC_MakeTrimmedCylinder::Status() {
		return safe_cast<xgce_ErrorType>(NativeHandle->Status());
	};
}
