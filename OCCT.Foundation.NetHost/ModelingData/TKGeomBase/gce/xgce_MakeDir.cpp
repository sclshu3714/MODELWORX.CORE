#include <xgce_MakeDir.h>
namespace TKGeomBase {
	xgce_MakeDir::xgce_MakeDir() {

	};

	xgce_MakeDir::xgce_MakeDir(gce_MakeDir* pos) {
		NativeHandle = pos;
		SetRoot(NativeHandle);
	};

	void xgce_MakeDir::SetMakeDir(gce_MakeDir* pos) {
		NativeHandle = pos;
		SetRoot(NativeHandle);
	};

	gce_MakeDir* xgce_MakeDir::GetMakeDir() {
		return NativeHandle;
	};

	gce_Root* xgce_MakeDir::GetRoot() {
		return NativeHandle;
	};


	//! Normalizes the vector V and creates a direction.
	//! Status is "NullVector" if V.Magnitude() <= Resolution.
	xgce_MakeDir::xgce_MakeDir(xgp_Vec^ V) {
		NativeHandle = new gce_MakeDir(*V->GetVec());
		SetRoot(NativeHandle);
	};

	//! Creates a direction from a triplet of coordinates.
	//! Status is "NullVector" if Coord.Modulus() <=
	//! Resolution from gp.
	xgce_MakeDir::xgce_MakeDir(xgp_XYZ^ Coord) {
		NativeHandle = new gce_MakeDir(*Coord->GetXYZ());
		SetRoot(NativeHandle);
	};

	//! Creates a direction with its 3 cartesian coordinates.
	//! Status is "NullVector" if Sqrt(Xv*Xv + Yv*Yv + Zv*Zv)
	//! <= Resolution
	xgce_MakeDir::xgce_MakeDir(Standard_Real Xv, Standard_Real Yv, Standard_Real Zv) {
		NativeHandle = new gce_MakeDir(Xv, Yv, Zv);
		SetRoot(NativeHandle);
	};

	//! Make a Dir from gp <TheDir> passing through 2
	//! Pnt <P1>,<P2>.
	//! Status is "ConfusedPoints" if <p1> and <P2> are confused.
	//! Warning
	//! If an error occurs (that is, when IsDone returns
	//! false), the Status function returns:
	//! -   gce_ConfusedPoints if points P1 and P2 are coincident, or
	//! -   gce_NullVector if one of the following is less
	//! than or equal to gp::Resolution():
	//! -   the magnitude of vector V,
	//! -   the modulus of Coord,
	//! -   Sqrt(Xv*Xv + Yv*Yv + Zv*Zv).
	xgce_MakeDir::xgce_MakeDir(xgp_Pnt^ P1, xgp_Pnt^ P2) {
		NativeHandle = new gce_MakeDir(*P1->GetPnt(), *P2->GetPnt());
		SetRoot(NativeHandle);
	};

	//! Returns theructed unit vector.
	//! Exceptions StdFail_NotDone if no unit vector isructed.
	xgp_Dir^ xgce_MakeDir::Value() {
		gp_Dir* temp = new gp_Dir(NativeHandle->Value());
		return gcnew xgp_Dir(temp);
	};

	xgp_Dir^ xgce_MakeDir::Operator() {
		gp_Dir* temp = new gp_Dir(NativeHandle->Operator());
		return gcnew xgp_Dir(temp);
	};
	xgce_MakeDir::operator xgp_Dir^() {
		gp_Dir* temp = new gp_Dir(NativeHandle->Operator());
		return gcnew xgp_Dir(temp);
	};

	//! Returns true if the construction is successful.
	Standard_Boolean xgce_MakeDir::IsDone() {
		return NativeHandle->IsDone();
	};

	//! Returns the status of the construction:
	//! -   gce_Done, if the construction is successful, or
	//! -   another value of the gce_ErrorType enumeration
	//! indicating why the construction failed.
	xgce_ErrorType xgce_MakeDir::Status() {
		return safe_cast<xgce_ErrorType>(NativeHandle->Status());
	};
}