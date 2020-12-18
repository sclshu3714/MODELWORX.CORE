#include <XGC_MakePlane.h>
namespace TKGeomBase {
	XGC_MakePlane::XGC_MakePlane() {
		//NativeHandle = new GC_MakePlane();
	};

	XGC_MakePlane::XGC_MakePlane(GC_MakePlane* pos) {
		NativeHandle = pos;
		SetRoot(NativeHandle);
	};

	void XGC_MakePlane::SetMakePlane(GC_MakePlane* pos) {
		NativeHandle = pos;
		SetRoot(NativeHandle);
	};

	GC_MakePlane* XGC_MakePlane::GetMakePlane() {
		return NativeHandle;
	};

	GC_Root* XGC_MakePlane::GetRoot() {
		return NativeHandle;
	};

	//! Creates a plane from a non persistent plane from package gp.
	XGC_MakePlane::XGC_MakePlane(xgp_Pln^ Pl) {
		NativeHandle = new GC_MakePlane(*Pl->GetPln());
		SetRoot(NativeHandle);
	};


	//! P is the "Location" point or origin of the plane.
	//! V is the direction normal to the plane.
	XGC_MakePlane::XGC_MakePlane(xgp_Pnt^ P, xgp_Dir^ V) {
		NativeHandle = new GC_MakePlane(*P->GetPnt(), *V->GetDir());
		SetRoot(NativeHandle);
	};


	//! Creates a plane from its cartesian equation :
	//! Ax + By + Cz + D = 0.0
	//! Status is "BadEquation" if Sqrt (A*A + B*B + C*C)
	//! <= Resolution from gp
	XGC_MakePlane::XGC_MakePlane(Standard_Real A, Standard_Real B, Standard_Real C, Standard_Real D) {
		NativeHandle = new GC_MakePlane(A, B, C, D);
		SetRoot(NativeHandle);
	};

	//! Make a Plane from Geom <ThePlane> parallel to another
	//! Pln <Pln> and passing through a Pnt <Point>.
	XGC_MakePlane::XGC_MakePlane(xgp_Pln^ Pln, xgp_Pnt^ Point) {
		NativeHandle = new GC_MakePlane(*Pln->GetPln(), *Point->GetPnt());
		SetRoot(NativeHandle);
	};

	//! Make a Plane from Geom <ThePlane> parallel to another
	//! Pln <Pln> at the distance <Dist> which can be greater
	//! or lower than zero.
	//! In the first case the result is at the distance
	//! <Dist> to the plane <Pln> in the direction of the
	//! normal to <Pln>.
	//! Otherwize it is in the oposite direction.
	XGC_MakePlane::XGC_MakePlane(xgp_Pln^ Pln, Standard_Real Dist) {
		NativeHandle = new GC_MakePlane(*Pln->GetPln(), Dist);
		SetRoot(NativeHandle);
	};

	//! Make a Plane from Geom <ThePlane> passing through 3
	//! Pnt <P1>,<P2>,<P3>.
	//! It returns false if <P1> <P2> <P3> are confused.
	XGC_MakePlane::XGC_MakePlane(xgp_Pnt^ P1, xgp_Pnt^ P2, xgp_Pnt^ P3) {
		NativeHandle = new GC_MakePlane(*P1->GetPnt(), *P2->GetPnt(), *P3->GetPnt());
		SetRoot(NativeHandle);
	};

	//! Make a Plane  passing through the location of <Axis>and
	//! normal to the Direction of <Axis>.
	XGC_MakePlane::XGC_MakePlane(xgp_Ax1^ Axis) {
		NativeHandle = new GC_MakePlane(*Axis->GetAx1());
		SetRoot(NativeHandle);
	};

	//! Returns the constructed plane.
	//! Exceptions StdFail_NotDone if no plane is constructed.
	XGeom_Plane^ XGC_MakePlane::Value() {
		return gcnew XGeom_Plane(NativeHandle->Value());
	};

	//! Returns true if the construction is successful.
	Standard_Boolean XGC_MakePlane::IsDone() {
		return NativeHandle->IsDone();
	};

	//! Returns the status of the construction:
	//! -   gce_Done, if the construction is successful, or
	//! -   another value of the gce_ErrorType enumeration
	//! indicating why the construction failed.
	xgce_ErrorType XGC_MakePlane::Status() {
		return safe_cast<xgce_ErrorType>(NativeHandle->Status());
	};
}