#include <xgce_MakeDir2d.h>
namespace TKGeomBase {
	xgce_MakeDir2d::xgce_MakeDir2d() {

	};

	xgce_MakeDir2d::xgce_MakeDir2d(gce_MakeDir2d* pos) {
		NativeHandle = pos;
		SetRoot(NativeHandle);
	};

	void xgce_MakeDir2d::SetMakeDir2d(gce_MakeDir2d* pos) {
		NativeHandle = pos;
		SetRoot(NativeHandle);
	};

	gce_MakeDir2d* xgce_MakeDir2d::GetMakeDir2d() {
		return NativeHandle;
	};

	gce_Root* xgce_MakeDir2d::GetRoot() {
		return NativeHandle;
	};

	//! Normalizes the vector V and creates a direction.
	//! Status is "NullVector" if V.Magnitude() <= Resolution.
	xgce_MakeDir2d::xgce_MakeDir2d(xgp_Vec2d^ V) {
		NativeHandle = new gce_MakeDir2d(*V->GetVec2d());
		SetRoot(NativeHandle);
	};

	//! Creates a direction from a triplet of coordinates.
	//! Status is "NullVector" if Coord.Modulus() <=
	//! Resolution from gp.
	xgce_MakeDir2d::xgce_MakeDir2d(xgp_XY^ Coord) {
		NativeHandle = new gce_MakeDir2d(*Coord->GetXY());
		SetRoot(NativeHandle);
	};

	//! Creates a direction with its 3 cartesian coordinates.
	//! Status is "NullVector" if Sqrt(Xv*Xv + Yv*Yv )
	//! <= Resolution
	xgce_MakeDir2d::xgce_MakeDir2d(Standard_Real Xv, Standard_Real Yv) {
		NativeHandle = new gce_MakeDir2d(Xv, Yv);
		SetRoot(NativeHandle);
	};

	//! Make a Dir2d from gp <TheDir> passing through 2
	//! Pnt <P1>,<P2>.
	//! Status is "ConfusedPoints" if <P1> and <P2> are confused.
	//! Warning
	//! If an error occurs (that is, when IsDone returns
	//! false), the Status function returns:
	//! -   gce_ConfusedPoints if points P1 and P2 are coincident, or
	//! -   gce_NullVector if one of the following is less
	//! than or equal to gp::Resolution():
	//! -   the magnitude of vector V,
	//! -   the modulus of Coord,
	//! -   Sqrt(Xv*Xv + Yv*Yv).
	xgce_MakeDir2d::xgce_MakeDir2d(xgp_Pnt2d^ P1, xgp_Pnt2d^ P2) {
		NativeHandle = new gce_MakeDir2d(*P1->GetPnt2d(), *P2->GetPnt2d());
		SetRoot(NativeHandle);
	};

	//! Returns theructed unit vector.
	//! Exceptions StdFail_NotDone if no unit vector isructed.
	xgp_Dir2d^ xgce_MakeDir2d::Value() {
		gp_Dir2d* temp = new gp_Dir2d(NativeHandle->Value());
		return gcnew xgp_Dir2d(temp);
	};

	xgp_Dir2d^ xgce_MakeDir2d::Operator() {
		gp_Dir2d* temp = new gp_Dir2d(NativeHandle->Operator());
		return gcnew xgp_Dir2d(temp);
	};
	xgce_MakeDir2d::operator xgp_Dir2d^() {
		gp_Dir2d* temp = new gp_Dir2d(NativeHandle->Operator());
		return gcnew xgp_Dir2d(temp);
	};

	//! Returns true if the construction is successful.
	Standard_Boolean xgce_MakeDir2d::IsDone() {
		return NativeHandle->IsDone();
	};

	//! Returns the status of the construction:
	//! -   gce_Done, if the construction is successful, or
	//! -   another value of the gce_ErrorType enumeration
	//! indicating why the construction failed.
	xgce_ErrorType xgce_MakeDir2d::Status() {
		return safe_cast<xgce_ErrorType>(NativeHandle->Status());
	};
}