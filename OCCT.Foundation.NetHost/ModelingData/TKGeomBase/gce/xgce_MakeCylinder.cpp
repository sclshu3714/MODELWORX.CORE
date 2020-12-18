#include <xgce_MakeCylinder.h>
namespace TKGeomBase {
	//DEFINE_STANDARD_ALLOC
	xgce_MakeCylinder::xgce_MakeCylinder() {
		/*NativeHandle = new gce_MakeCylinder();
		SetRoot(NativeHandle);*/
	};

	xgce_MakeCylinder::xgce_MakeCylinder(gce_MakeCylinder* pos) {
		NativeHandle = pos;
		SetRoot(NativeHandle);
	};

	void xgce_MakeCylinder::SetMakeCylinder(gce_MakeCylinder* pos) {
		NativeHandle = pos;
		SetRoot(NativeHandle);
	};

	gce_MakeCylinder* xgce_MakeCylinder::GetMakeCylinder() {
		return NativeHandle;
	};

	gce_Root* xgce_MakeCylinder::GetRoot() {
		return NativeHandle;
	};


	//! <A2> is the local cartesian coordinate system of <me>.
	//! The status is "NegativeRadius" if R < 0.0
	xgce_MakeCylinder::xgce_MakeCylinder(xgp_Ax2^ A2, Standard_Real Radius) {
		NativeHandle = new gce_MakeCylinder(*A2->GetAx2(), Radius);
		SetRoot(NativeHandle);
	};

	//! Makes a Cylinder from gp <TheCylinder> coaxial to another
	//! Cylinder <Cylinder> and passing through a Pnt <Point>.
	xgce_MakeCylinder::xgce_MakeCylinder(xgp_Cylinder^ Cyl, xgp_Pnt^ Point) {
		NativeHandle = new gce_MakeCylinder(*Cyl->GetCylinder(), *Point->GetPnt());
		SetRoot(NativeHandle);
	};

	//! Makes a Cylinder from gp <TheCylinder> coaxial to another
	//! Cylinder <Cylinder> at the distance <Dist> which can
	//! be greater or lower than zero.
	//! The radius of the result is the absolute value of the
	//! radius of <Cyl> plus <Dist>
	xgce_MakeCylinder::xgce_MakeCylinder(xgp_Cylinder^ Cyl, Standard_Real Dist) {
		NativeHandle = new gce_MakeCylinder(*Cyl->GetCylinder(), Dist);
		SetRoot(NativeHandle);
	};

	//! Makes a Cylinder from gp <TheCylinder> with 3 points
	//! <P1>,<P2>,<P3>.
	//! Its axis is <P1P2> and its radius is the distance
	//! between <P3> and <P1P2>
	xgce_MakeCylinder::xgce_MakeCylinder(xgp_Pnt^ P1, xgp_Pnt^ P2, xgp_Pnt^ P3) {
		NativeHandle = new gce_MakeCylinder(*P1->GetPnt(), *P2->GetPnt(), *P3->GetPnt());
		SetRoot(NativeHandle);
	};

	//! Makes a Cylinder by its axis <Axis> and radius <Radius>.
	xgce_MakeCylinder::xgce_MakeCylinder(xgp_Ax1^ Axis, Standard_Real Radius) {
		NativeHandle = new gce_MakeCylinder(*Axis->GetAx1(), Radius);
		SetRoot(NativeHandle);
	};

	//! Makes a Cylinder by its circular base.
	//! Warning
	//! If an error occurs (that is, when IsDone returns
	//! false), the Status function returns:
	//! -   gce_NegativeRadius if:
	//! -   Radius is less than 0.0, or
	//! -   Dist is negative and has an absolute value
	//! which is greater than the radius of Cyl; or
	//! -   gce_ConfusedPoints if points P1 and P2 are coincident.
	xgce_MakeCylinder::xgce_MakeCylinder(xgp_Circ^ Circ) {
		NativeHandle = new gce_MakeCylinder(*Circ->GetCirc());
		SetRoot(NativeHandle);
	};

	//! Returns theructed cylinder.
	//! Exceptions StdFail_NotDone if no cylinder isructed.
	xgp_Cylinder^ xgce_MakeCylinder::Value() {
		gp_Cylinder* temp = new gp_Cylinder(NativeHandle->Value());
		return gcnew xgp_Cylinder(temp);
	};

	xgp_Cylinder^ xgce_MakeCylinder::Operator() {
		gp_Cylinder* temp = new gp_Cylinder(NativeHandle->Operator());
		return gcnew xgp_Cylinder(temp);
	};
	xgce_MakeCylinder::operator xgp_Cylinder^() {
		gp_Cylinder* temp = new gp_Cylinder(NativeHandle->Operator());
		return gcnew xgp_Cylinder(temp);
	};

	//! Returns true if the construction is successful.
	Standard_Boolean xgce_MakeCylinder::IsDone() {
		return NativeHandle->IsDone();
	};

	//! Returns the status of the construction:
	//! -   gce_Done, if the construction is successful, or
	//! -   another value of the gce_ErrorType enumeration
	//! indicating why the construction failed.
	xgce_ErrorType xgce_MakeCylinder::Status() {
		return safe_cast<xgce_ErrorType>(NativeHandle->Status());
	};
}