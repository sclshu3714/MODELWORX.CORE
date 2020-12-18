#include <xgce_MakeLin2d.h>
namespace TKGeomBase {
	//DEFINE_STANDARD_ALLOC
	xgce_MakeLin2d::xgce_MakeLin2d() {
		//NativeHandle = new gce_MakeLin2d();
	};

	xgce_MakeLin2d::xgce_MakeLin2d(gce_MakeLin2d* pos) {
		NativeHandle = pos;
	};

	void xgce_MakeLin2d::SetMakeLin2d(gce_MakeLin2d* pos) {
		NativeHandle = pos;
	};

	gce_MakeLin2d* xgce_MakeLin2d::GetMakeLin2d() {
		return NativeHandle;
	};

	gce_Root* xgce_MakeLin2d::GetRoot() {
		return NativeHandle;
	};

	//! Creates a line located with A.
	xgce_MakeLin2d::xgce_MakeLin2d(xgp_Ax2d^ A) {
		NativeHandle = new gce_MakeLin2d(*A->GetAx2d());
		SetRoot(NativeHandle);
	};


	//! <P> is the location point (origin) of the line and
	//! <V> is the direction of the line.
	xgce_MakeLin2d::xgce_MakeLin2d(xgp_Pnt2d^ P, xgp_Dir2d^ V) {
		NativeHandle = new gce_MakeLin2d(*P->GetPnt2d(), *V->GetDir2d());
		SetRoot(NativeHandle);
	};


	//! Creates the line from the equation A*X + B*Y + C = 0.0
	//! the status is "NullAxis"if Sqrt(A*A + B*B) <= Resolution from gp.
	xgce_MakeLin2d::xgce_MakeLin2d(Standard_Real A, Standard_Real B, Standard_Real C) {
		NativeHandle = new gce_MakeLin2d(A, B, C);
		SetRoot(NativeHandle);
	};

	//! Make a Lin2d from gp <TheLin> parallel to another
	//! Lin2d <Lin> at a distance <Dist>.
	//! If Dist is greater than zero the result is on the
	//! right of the Line <Lin>, else the result is on the
	//! left of the Line <Lin>.
	xgce_MakeLin2d::xgce_MakeLin2d(xgp_Lin2d^ Lin, Standard_Real Dist) {
		NativeHandle = new gce_MakeLin2d(*Lin->GetLin2d(), Dist);
		SetRoot(NativeHandle);
	};

	//! Make a Lin2d from gp <TheLin> parallel to another
	//! Lin2d <Lin> and passing through a Pnt2d <Point>.
	xgce_MakeLin2d::xgce_MakeLin2d(xgp_Lin2d^ Lin, xgp_Pnt2d^ Point) {
		NativeHandle = new gce_MakeLin2d(*Lin->GetLin2d(), *Point->GetPnt2d());
		SetRoot(NativeHandle);
	};

	//! Make a Lin2d from gp <TheLin> passing through 2
	//! Pnt2d <P1>,<P2>.
	//! It returns false if <P1> and <P2> are confused.
	//! Warning
	//! If an error occurs (that is, when IsDone returns
	//! false), the Status function returns:
	//! -   gce_NullAxis if Sqrt(A*A + B*B) is less
	//! than or equal to gp::Resolution(), or
	//! -   gce_ConfusedPoints if points P1 and P2 are coincident.
	xgce_MakeLin2d::xgce_MakeLin2d(xgp_Pnt2d^ P1, xgp_Pnt2d^ P2) {
		NativeHandle = new gce_MakeLin2d(*P1->GetPnt2d(), *P2->GetPnt2d());
		SetRoot(NativeHandle);
	};

	//! Returns theructed line.
	//! Exceptions StdFail_NotDone if no line isructed.
	xgp_Lin2d^ xgce_MakeLin2d::Value() {
		gp_Lin2d* temp = new gp_Lin2d(NativeHandle->Value());
		return gcnew xgp_Lin2d(temp);
	};

	xgp_Lin2d^ xgce_MakeLin2d::Operator() {
		gp_Lin2d* temp = new gp_Lin2d(NativeHandle->Operator());
		return gcnew xgp_Lin2d(temp);
	};
	xgce_MakeLin2d::operator xgp_Lin2d^() {
		gp_Lin2d* temp = new gp_Lin2d(NativeHandle->Operator());
		return gcnew xgp_Lin2d(temp);
	};

	//! Returns true if the construction is successful.
	Standard_Boolean xgce_MakeLin2d::IsDone() {
		return NativeHandle->IsDone();
	};

	//! Returns the status of the construction:
	//! -   gce_Done, if the construction is successful, or
	//! -   another value of the gce_ErrorType enumeration
	//! indicating why the construction failed.
	xgce_ErrorType xgce_MakeLin2d::Status() {
		return safe_cast<xgce_ErrorType>(NativeHandle->Status());
	};
}