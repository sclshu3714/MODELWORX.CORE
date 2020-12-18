#include <xgce_MakePln.h>
namespace TKGeomBase {
	xgce_MakePln::xgce_MakePln() {
		//NativeHandle = new gce_MakePln();
	};

	xgce_MakePln::xgce_MakePln(gce_MakePln* pos) {
		NativeHandle = pos;
	};

	void xgce_MakePln::SetMakePln(gce_MakePln* pos) {
		NativeHandle = pos;
	};

	gce_MakePln* xgce_MakePln::GetMakePln() {
		return NativeHandle;
	};

	gce_Root* xgce_MakePln::GetRoot() {
		return NativeHandle;
	};

	//! The coordinate system of the plane is defined with the axis
	//! placement A2.
	//! The "Direction" of A2 defines the normal to the plane.
	//! The "Location" of A2 defines the location (origin) of the plane.
	//! The "XDirection" and "YDirection" of A2 define the "XAxis" and
	//! the "YAxis" of the plane used to parametrize the plane.
	xgce_MakePln::xgce_MakePln(xgp_Ax2^ A2) {
		NativeHandle = new gce_MakePln(*A2->GetAx2());
		SetRoot(NativeHandle);
	};


	//! Creates a plane with the  "Location" point <P>
	//! and the normal direction <V>.
	xgce_MakePln::xgce_MakePln(xgp_Pnt^ P, xgp_Dir^ V) {
		NativeHandle = new gce_MakePln(*P->GetPnt(), *V->GetDir());
		SetRoot(NativeHandle);
	};


	//! Creates a plane from its cartesian equation :
	//! A * X + B * Y + C * Z + D = 0.0
	//!
	//! the status is "BadEquation" if Sqrt (A*A + B*B + C*C) <=
	//! Resolution from gp.
	xgce_MakePln::xgce_MakePln(Standard_Real A, Standard_Real B, Standard_Real C, Standard_Real D) {
		NativeHandle = new gce_MakePln(A, B, C, D);
		SetRoot(NativeHandle);
	};

	//! Make a Pln from gp <ThePln> parallel to another
	//! Pln <Pln> and passing through a Pnt <Point>.
	xgce_MakePln::xgce_MakePln(xgp_Pln^ Pln, xgp_Pnt^ Point) {
		NativeHandle = new gce_MakePln(*Pln->GetPln(), *Point->GetPnt());
		SetRoot(NativeHandle);
	};

	//! Make a Pln from gp <ThePln> parallel to another
	//! Pln <Pln> at the distance <Dist> which can be greater
	//! or less than zero.
	//! In the first case the result is at the distance
	//! <Dist> to the plane <Pln> in the direction of the
	//! normal to <Pln>.
	//! Otherwize it is in the opposite direction.
	xgce_MakePln::xgce_MakePln(xgp_Pln^ Pln, Standard_Real Dist) {
		NativeHandle = new gce_MakePln(*Pln->GetPln(), Dist);
		SetRoot(NativeHandle);
	};

	//! Make a Pln from gp <ThePln> passing through 3
	//! Pnt <P1>,<P2>,<P3>.
	//! It returns false if <P1> <P2> <P3> are confused.
	xgce_MakePln::xgce_MakePln(xgp_Pnt^ P1, xgp_Pnt^ P2, xgp_Pnt^ P3) {
		NativeHandle = new gce_MakePln(*P1->GetPnt(), *P2->GetPnt(), *P3->GetPnt());
		SetRoot(NativeHandle);
	};

	//! Make a Pln from gp <ThePln> perpendicular to the line
	//! passing through <P1>,<P2>.
	//! The status is "ConfusedPoints" if <P1> <P2> are confused.
	xgce_MakePln::xgce_MakePln(xgp_Pnt^ P1, xgp_Pnt^ P2) {
		NativeHandle = new gce_MakePln(*P1->GetPnt(), *P2->GetPnt());
		SetRoot(NativeHandle);
	};

	//! Make a pln  passing through the location of <Axis>and
	//! normal to the Direction of <Axis>.
	//! Warning -  If an error occurs (that is, when IsDone returns
	//! false), the Status function returns:
	//! -   gce_BadEquation if Sqrt(A*A + B*B +
	//! C*C) is less than or equal to gp::Resolution(),
	//! -   gce_ConfusedPoints if P1 and P2 are coincident, or
	//! -   gce_ColinearPoints if P1, P2 and P3 are collinear.
	xgce_MakePln::xgce_MakePln(xgp_Ax1^ Axis) {
		NativeHandle = new gce_MakePln(*Axis->GetAx1());
		SetRoot(NativeHandle);
	};

	//! Returns theructed plane.
	//! Exceptions StdFail_NotDone if no plane isructed.
	xgp_Pln^ xgce_MakePln::Value() {
		gp_Pln* temp = new gp_Pln(NativeHandle->Value());
		return gcnew xgp_Pln(temp);
	};

	xgp_Pln^ xgce_MakePln::Operator() {
		gp_Pln* temp = new gp_Pln(NativeHandle->Operator());
		return gcnew xgp_Pln(temp);
	};
	xgce_MakePln::operator xgp_Pln^() {
		gp_Pln* temp = new gp_Pln(NativeHandle->Operator());
		return gcnew xgp_Pln(temp);
	};

	//! Returns true if the construction is successful.
	Standard_Boolean xgce_MakePln::IsDone() {
		return NativeHandle->IsDone();
	};


	//! Returns the status of the construction:
	//! -   gce_Done, if the construction is successful, or
	//! -   another value of the gce_ErrorType enumeration
	//! indicating why the construction failed.
	xgce_ErrorType xgce_MakePln::Status() {
		return safe_cast<xgce_ErrorType>(NativeHandle->Status());
	};
}