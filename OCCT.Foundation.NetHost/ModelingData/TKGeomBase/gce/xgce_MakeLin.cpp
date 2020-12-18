#include <xgce_MakeLin.h>
namespace TKGeomBase {
	//DEFINE_STANDARD_ALLOC
	xgce_MakeLin::xgce_MakeLin() {
		//NativeHandle = new gce_MakeLin();
	};

	xgce_MakeLin::xgce_MakeLin(gce_MakeLin* pos) {
		NativeHandle = pos;
	};

	void xgce_MakeLin::SetMakeLin(gce_MakeLin* pos) {
		NativeHandle = pos;
	};

	gce_MakeLin* xgce_MakeLin::GetMakeLin() {
		return NativeHandle;
	};

	gce_Root* xgce_MakeLin::GetRoot() {
		return NativeHandle;
	};

	//! Creates a line located along the axis A1.
	xgce_MakeLin::xgce_MakeLin(xgp_Ax1^ A1) {
		NativeHandle = new gce_MakeLin(*A1->GetAx1());
		SetRoot(NativeHandle);
	};


	//! <P> is the location point (origin) of the line and
	//! <V> is the direction of the line.
	xgce_MakeLin::xgce_MakeLin(xgp_Pnt^ P, xgp_Dir^ V) {
		NativeHandle = new gce_MakeLin(*P->GetPnt(), *V->GetDir());
		SetRoot(NativeHandle);
	};

	//! Make a Lin from gp <TheLin> parallel to another
	//! Lin <Lin> and passing through a Pnt <Point>.
	xgce_MakeLin::xgce_MakeLin(xgp_Lin^ Lin, xgp_Pnt^ Point) {
		NativeHandle = new gce_MakeLin(*Lin->GetLin(), *Point->GetPnt());
		SetRoot(NativeHandle);
	};

	//! Make a Lin from gp <TheLin> passing through 2
	//! Pnt <P1>,<P2>.
	//! It returns false if <p1> and <P2> are confused.
	xgce_MakeLin::xgce_MakeLin(xgp_Pnt^ P1, xgp_Pnt^ P2) {
		NativeHandle = new gce_MakeLin(*P1->GetPnt(), *P2->GetPnt());
		SetRoot(NativeHandle);
	};

	//! Returns theructed line.
	//! Exceptions StdFail_NotDone is raised if no line isructed.
	xgp_Lin^ xgce_MakeLin::Value() {
		gp_Lin* temp = new gp_Lin(NativeHandle->Value());
		return gcnew xgp_Lin(temp);
	};

	xgp_Lin^ xgce_MakeLin::Operator() {
		gp_Lin* temp = new gp_Lin(NativeHandle->Operator());
		return gcnew xgp_Lin(temp);
	};
	xgce_MakeLin::operator xgp_Lin^() {
		gp_Lin* temp = new gp_Lin(NativeHandle->Operator());
		return gcnew xgp_Lin(temp);
	};

	//! Returns true if the construction is successful.
	Standard_Boolean xgce_MakeLin::IsDone() {
		return NativeHandle->IsDone();
	};

	//! Returns the status of the construction:
	//! -   gce_Done, if the construction is successful, or
	//! -   another value of the gce_ErrorType enumeration
	//! indicating why the construction failed.
	xgce_ErrorType xgce_MakeLin::Status() {
		return safe_cast<xgce_ErrorType>(NativeHandle->Status());
	};
}
