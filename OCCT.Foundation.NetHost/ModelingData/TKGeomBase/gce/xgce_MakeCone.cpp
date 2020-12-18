#include <xgce_MakeCone.h>
namespace TKGeomBase {
	xgce_MakeCone::xgce_MakeCone() {

	};

	xgce_MakeCone::xgce_MakeCone(gce_MakeCone* pos) {
		NativeHandle = pos;
		SetRoot(NativeHandle);
	};

	void xgce_MakeCone::SetMakeCone(gce_MakeCone* pos) {
		NativeHandle = pos;
		SetRoot(NativeHandle);
	};

	gce_MakeCone* xgce_MakeCone::GetMakeCone() {
		return NativeHandle;
	};

	gce_Root* xgce_MakeCone::GetRoot() {
		return NativeHandle;
	};



	//! Creates an infinite conical surface. A2 locates the cone
	//! in the space and defines the reference plane of the surface.
	//! Ang is the conical surface semi-angle between 0 and PI/2 radians.
	//! Radius is the radius of the circle in the reference plane of
	//! the cone.
	//! If Radius is lower than 0.0 the status is "
	//! If Ang < Resolution from gp  or Ang >= (PI/2) - Resolution.
	xgce_MakeCone::xgce_MakeCone(xgp_Ax2^ A2, Standard_Real Ang, Standard_Real Radius) {
		NativeHandle = new gce_MakeCone(*A2->GetAx2(), Ang, Radius);
		SetRoot(NativeHandle);
	};

	//! Makes a Cone from gp <TheCone> coaxial to another
	//! Cone <Cone> and passing through a Pnt <Point>.
	xgce_MakeCone::xgce_MakeCone(xgp_Cone^ Cone, xgp_Pnt^ Point) {
		NativeHandle = new gce_MakeCone(*Cone->GetCone(), *Point->GetPnt());
		SetRoot(NativeHandle);
	};

	//! Makes a Cone from gp <TheCone> coaxial to another
	//! Cone <Cone> at the distance <Dist> which can
	//! be greater or lower than zero.
	xgce_MakeCone::xgce_MakeCone(xgp_Cone^ Cone, Standard_Real Dist) {
		NativeHandle = new gce_MakeCone(*Cone->GetCone(), Dist);
		SetRoot(NativeHandle);
	};

	//! Makes a Cone from gp <TheCone> by four points <P1>,
	//! <P2>,<P3> and <P4>.
	//! Its axis is <P1P2> and the radius of its base is
	//! the distance between <P3> and <P1P2>.
	//! The distance between <P4> and <P1P2> is the radius of
	//! the section passing through <P4>.
	//! If <P1> and <P2> are confused or <P3> and <P4> are
	//! confused we have the status "ConfusedPoints"
	//! if <P1>,<P2>,<P3>,<P4> are colinear we have the
	//! status "ColinearPoints"
	//! If <P3P4> is perpendicular to <P1P2> we have the
	//! status "NullAngle".
	//! <P3P4> is colinear to <P1P2> we have the status
	//! "NullAngle".
	xgce_MakeCone::xgce_MakeCone(xgp_Pnt^ P1, xgp_Pnt^ P2, xgp_Pnt^ P3, xgp_Pnt^ P4) {
		NativeHandle = new gce_MakeCone(*P1->GetPnt(), *P2->GetPnt(), *P3->GetPnt(), *P4->GetPnt());
		SetRoot(NativeHandle);
	};

	//! Makes a Cone by its axis <Axis> and and two points.
	//! The distance between <P1> and the axis is the radius
	//! of the section passing through <P1>.
	//! The distance between <P2> and the axis is the radius
	//! of the section passing through <P2>.
	//! If <P1P2> is colinear to <Axis> we have the status
	//! "NullAngle"
	//! If <P3P4> is perpendicular to <Axis> we have the status
	//! "NullAngle"
	//! If <P1> and <P2> are confused we have the status
	//! "ConfusedPoints"
	xgce_MakeCone::xgce_MakeCone(xgp_Ax1^ Axis, xgp_Pnt^ P1, xgp_Pnt^ P2) {
		NativeHandle = new gce_MakeCone(*Axis->GetAx1(), *P1->GetPnt(), *P2->GetPnt());
		SetRoot(NativeHandle);
	};

	//! Makes a Cone by its axis <Axis> and and two points.
	//! The distance between <P1> and the axis is the radius
	//! of the section passing through <P1>
	//! The distance between <P2> and the axis is the radius
	//! of the section passing through <P2>
	//! If <P1P2> is colinear to <Axis> we have the status
	//! "NullAngle"
	//! If <P3P4> is perpendicular to <Axis> we have the status
	//! "NullAngle"
	//! If <P1> and <P2> are confused we have the status
	//! "ConfusedPoints"
	xgce_MakeCone::xgce_MakeCone(xgp_Lin^ Axis, xgp_Pnt^ P1, xgp_Pnt^ P2) {
		NativeHandle = new gce_MakeCone(*Axis->GetLin(), *P1->GetPnt(), *P2->GetPnt());
		SetRoot(NativeHandle);
	};

	//! Makes a Cone with two points and two radius.
	//! The axis of the solution is the line passing through
	//! <P1> and <P2>.
	//! <R1> is the radius of the section passing through <P1>
	//! and <R2> the radius of the section passing through <P2>.
	//! If <P1> and <P2> are confused we have the status "NullAxis".
	//! Warning
	//! If an error occurs (that is, when IsDone returns
	//! false), the Status function returns:
	//! -   gce_NegativeRadius if Radius, R1 or R2 is less than 0.0;
	//! -   gce_BadAngle if Ang is less than
	//! gp::Resolution() or greater than Pi/2.- gp::Resolution();
	//! -   gce_ConfusedPoints if P1 and P2 or P3 and P4 are coincident;
	//! -   gce_NullAxis if the points P1 and P2, are coincident (5th syntax only);
	//! -   gce_NullAngle if:
	//! -   the vector joining P1 to P2 is parallel to either
	//! Axis or the line joining P3 to P4, or
	//! -   R1 and R2 are equal, (that is, their difference is
	//! less than gp::Resolution()); or
	//! -   gce_NullRadius if:
	//! -   the vector joining P1 to P2 is perpendicular to the line joining P3 to P4,
	//! -   the vector joining P1 to P2 is perpendicular to Axis, or
	//! -   P1, P2, P3, and P4 are collinear.
	xgce_MakeCone::xgce_MakeCone(xgp_Pnt^ P1, xgp_Pnt^ P2, Standard_Real R1, Standard_Real R2) {
		NativeHandle = new gce_MakeCone(*P1->GetPnt(), *P2->GetPnt(), R1, R2);
		SetRoot(NativeHandle);
	};

	//! Returns theructed cone.
	//! Exceptions StdFail_NotDone if no cone isructed.
	xgp_Cone^ xgce_MakeCone::Value() {
		gp_Cone* temp = new gp_Cone(NativeHandle->Value());
		return gcnew xgp_Cone(temp);
	};

	xgp_Cone^ xgce_MakeCone::Operator() {
		gp_Cone* temp = new gp_Cone(NativeHandle->Operator());
		return gcnew xgp_Cone(temp);
	};
	xgce_MakeCone::operator xgp_Cone^() {
		gp_Cone* temp = new gp_Cone(NativeHandle->Operator());
		return gcnew xgp_Cone(temp);
	};

	//! Returns true if the construction is successful.
	Standard_Boolean xgce_MakeCone::IsDone() {
		return NativeHandle->IsDone();
	};

	//! Returns the status of the construction:
	//! -   gce_Done, if the construction is successful, or
	//! -   another value of the gce_ErrorType enumeration
	//! indicating why the construction failed.
	xgce_ErrorType xgce_MakeCone::Status() {
		return safe_cast<xgce_ErrorType>(NativeHandle->Status());
	};
}