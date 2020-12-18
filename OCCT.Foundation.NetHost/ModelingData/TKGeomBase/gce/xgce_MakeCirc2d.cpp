#include <xgce_MakeCirc2d.h>
namespace TKGeomBase {
	//! DEFINE_STANDARD_ALLOC

	xgce_MakeCirc2d::xgce_MakeCirc2d() {

	};

	xgce_MakeCirc2d::xgce_MakeCirc2d(gce_MakeCirc2d* pos) {
		NativeHandle = pos;
		SetRoot(NativeHandle);
	};

	void xgce_MakeCirc2d::SetMakeCirc2d(gce_MakeCirc2d* pos) {
		NativeHandle = pos;
		SetRoot(NativeHandle);
	};

	gce_MakeCirc2d* xgce_MakeCirc2d::GetMakeCirc2d() {
		return NativeHandle;
	};

	gce_Root* xgce_MakeCirc2d::GetRoot() {
		return NativeHandle;
	};

	//! The location point of XAxis is the center of the circle.
	//! Warnings :
	//! It is not forbidden to create a circle with Radius = 0.0
	//! If Sense is true the local coordinate system of the solution
	//! is direct and non direct in the other case.
	//! The status is "NegativeRadius" if Radius < 0.0.
	//! Standard_Boolean Sense = Standard_True
	xgce_MakeCirc2d::xgce_MakeCirc2d(xgp_Ax2d^ XAxis, Standard_Real Radius, Standard_Boolean Sense) {
		NativeHandle = new gce_MakeCirc2d(*XAxis->GetAx2d(), Radius, Sense);
		SetRoot(NativeHandle);
	};


	//! The location point of Axis is the center of the circle.
	//! Warnings :
	//! It is not forbidden to create a circle with Radius = 0.0
	xgce_MakeCirc2d::xgce_MakeCirc2d(xgp_Ax22d^ Axis, Standard_Real Radius) {
		NativeHandle = new gce_MakeCirc2d(*Axis->GetAx22d(), Radius);
		SetRoot(NativeHandle);
	};

	//! Makes a Circ2d from gp <TheCirc> concentric with another
	//! circ2d <Circ> with a distance <Dist>.
	//! If Dist is greater than zero the result encloses
	//! the circle <Circ>, else the result is enclosed by the
	//! circle <Circ>.
	//! The local coordinate system of the solution is the
	//! same as Circ.
	xgce_MakeCirc2d::xgce_MakeCirc2d(xgp_Circ2d^ Circ, Standard_Real Dist) {
		NativeHandle = new gce_MakeCirc2d(*Circ->GetCirc2d(), Dist);
		SetRoot(NativeHandle);
	};

	//! Makes a Circ2d from gp <TheCirc> concentric with another
	//! circ2d <Circ> and passing through a Pnt2d <Point>.
	//! The local coordinate system of the solution is the
	//! same as Circ.
	xgce_MakeCirc2d::xgce_MakeCirc2d(xgp_Circ2d^ Circ, xgp_Pnt2d^ Point) {
		NativeHandle = new gce_MakeCirc2d(*Circ->GetCirc2d(), *Point->GetPnt2d());
		SetRoot(NativeHandle);
	};

	//! Makes a Circ2d from gp <TheCirc> passing through 3
	//! Pnt2d <P1>,<P2>,<P3>.
	//! The local coordinate system of the solution is given
	//! by the three points P1, P2, P3.
	xgce_MakeCirc2d::xgce_MakeCirc2d(xgp_Pnt2d^ P1, xgp_Pnt2d^ P2, xgp_Pnt2d^ P3) {
		NativeHandle = new gce_MakeCirc2d(*P1->GetPnt2d(), *P2->GetPnt2d(), *P3->GetPnt2d());
		SetRoot(NativeHandle);
	};

	//! Makes a Circ2d from gp <TheCirc> with its center
	//! <Center> and its radius <Radius>.
	//! If Sense is true the local coordinate system of
	//! the solution is direct and non direct in the other case.
	//! Standard_Boolean Sense = Standard_True
	xgce_MakeCirc2d::xgce_MakeCirc2d(xgp_Pnt2d^ Center, Standard_Real Radius, Standard_Boolean Sense) {
		NativeHandle = new gce_MakeCirc2d(*Center->GetPnt2d(), Radius, Sense);
		SetRoot(NativeHandle);
	};

	//! Makes a Circ2d from gp <TheCirc> with its center
	//! <Center> and a point giving the radius.
	//! If Sense is true the local coordinate system of
	//! the solution is direct and non direct in the other case.
	//! Standard_Boolean Sense = Standard_True
	xgce_MakeCirc2d::xgce_MakeCirc2d(xgp_Pnt2d^ Center, xgp_Pnt2d^ Point, Standard_Boolean Sense) {
		NativeHandle = new gce_MakeCirc2d(*Center->GetPnt2d(), *Point->GetPnt2d(), Sense);
		SetRoot(NativeHandle);
	};

	//! Returns the constructed circle.
	//! Exceptions StdFail_NotDone if no circle is constructed.
	xgp_Circ2d^ xgce_MakeCirc2d::Value() {
		gp_Circ2d* temp = new gp_Circ2d(NativeHandle->Value());
		return gcnew xgp_Circ2d(temp);
	};

	xgp_Circ2d^ xgce_MakeCirc2d::Operator() {
		gp_Circ2d* temp = new gp_Circ2d(NativeHandle->Operator());
		return gcnew xgp_Circ2d(temp);
	};

	xgce_MakeCirc2d::operator xgp_Circ2d^() {
		gp_Circ2d* temp = new gp_Circ2d(NativeHandle->Operator());
		return gcnew xgp_Circ2d(temp);
	};


	//! Returns true if the construction is successful.
	Standard_Boolean xgce_MakeCirc2d::IsDone() {
		return NativeHandle->IsDone();
	};

	//! Returns the status of the construction:
	//! -   gce_Done, if the construction is successful, or
	//! -   another value of the gce_ErrorType enumeration
	//! indicating why the construction failed.
	xgce_ErrorType xgce_MakeCirc2d::Status() {
		return safe_cast<xgce_ErrorType>(NativeHandle->Status());
	};
}