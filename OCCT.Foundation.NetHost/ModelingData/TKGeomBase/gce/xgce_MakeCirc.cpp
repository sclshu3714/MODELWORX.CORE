#include <xgce_MakeCirc.h>
namespace TKGeomBase {
	//DEFINE_STANDARD_ALLOC
	xgce_MakeCirc::xgce_MakeCirc() {
		/*NativeHandle = new gce_MakeCirc();
		SetRoot(NativeHandle);*/
	};

	xgce_MakeCirc::xgce_MakeCirc(gce_MakeCirc* pos) {
		NativeHandle = pos;
		SetRoot(NativeHandle);
	};

	void xgce_MakeCirc::SetMakeCirc(gce_MakeCirc* pos) {
		NativeHandle = pos;
		SetRoot(NativeHandle);
	};

	gce_MakeCirc* xgce_MakeCirc::GetMakeCirc() {
		return NativeHandle;
	};

	gce_Root* xgce_MakeCirc::GetRoot() {
		return NativeHandle;
	};


	//! A2 locates the circle and gives its orientation in 3D space.
	//! Warnings :
	//! It is not forbidden to create a circle with Radius = 0.0
	//! The status is "NegativeRadius" if Radius < 0.0
	xgce_MakeCirc::xgce_MakeCirc(xgp_Ax2^ A2, Standard_Real Radius) {
		NativeHandle = new gce_MakeCirc(*A2->GetAx2(), Radius);
		SetRoot(NativeHandle);
	};

	//! Makes a Circ from gp <TheCirc> coaxial to another
	//! Circ <Circ> at a distance <Dist>.
	//! If Dist is greater than zero the result is encloses
	//! the circle <Circ>, else the result is enclosed by the
	//! circle <Circ>.
	xgce_MakeCirc::xgce_MakeCirc(xgp_Circ^ Circ, Standard_Real Dist) {
		NativeHandle = new gce_MakeCirc(*Circ->GetCirc(), Dist);
		SetRoot(NativeHandle);
	};

	//! Makes a Circ from gp <TheCirc> coaxial to another
	//! Circ <Circ> and passing through a Pnt2d <Point>.
	xgce_MakeCirc::xgce_MakeCirc(xgp_Circ^ Circ, xgp_Pnt^ Point) {
		NativeHandle = new gce_MakeCirc(*Circ->GetCirc(), *Point->GetPnt());
		SetRoot(NativeHandle);
	};

	//! Makes a Circ from gp <TheCirc> passing through 3
	//! Pnt2d <P1>,<P2>,<P3>.
	xgce_MakeCirc::xgce_MakeCirc(xgp_Pnt^ P1, xgp_Pnt^ P2, xgp_Pnt^ P3) {
		NativeHandle = new gce_MakeCirc(*P1->GetPnt(), *P2->GetPnt(), *P3->GetPnt());
		SetRoot(NativeHandle);
	};

	//! Makes a Circ from gp <TheCirc> with its center
	//! <Center> and the normal of its plane <Norm> and
	//! its radius <Radius>.
	xgce_MakeCirc::xgce_MakeCirc(xgp_Pnt^ Center, xgp_Dir^ Norm, Standard_Real Radius) {
		NativeHandle = new gce_MakeCirc(*Center->GetPnt(), *Norm->GetDir(), Radius);
		SetRoot(NativeHandle);
	};

	//! Makes a Circ from gp <TheCirc> with its center
	//! <Center> and the normal of its plane <Plane> and
	//! its radius <Radius>.
	xgce_MakeCirc::xgce_MakeCirc(xgp_Pnt^ Center, xgp_Pln^ Plane, Standard_Real Radius) {
		NativeHandle = new gce_MakeCirc(*Center->GetPnt(), *Plane->GetPln(), Radius);
		SetRoot(NativeHandle);
	};

	//! Makes a Circ from gp <TheCirc> with its center
	//! <Center> and a point <Ptaxis> giving the normal
	//! of its plane <Plane> and its radius <Radius>.
	xgce_MakeCirc::xgce_MakeCirc(xgp_Pnt^ Center, xgp_Pnt^ Ptaxis, Standard_Real Radius) {
		NativeHandle = new gce_MakeCirc(*Center->GetPnt(), *Ptaxis->GetPnt(), Radius);
		SetRoot(NativeHandle);
	};

	//! Makes a Circ from gp <TheCirc> with its center
	//! <Center> and its radius <Radius>.
	//! Warning
	//! The MakeCirc class does not prevent the
	//! construction of a circle with a null radius.
	//! If an error occurs (that is, when IsDone returns
	//! false), the Status function returns:
	//! -   gce_Negative Radius if:
	//! -   Radius is less than 0.0, or
	//! -   Dist is less than 0.0 and the absolute value of
	//! Dist is greater than the radius of Circ;
	//! -   gce_IntersectionError if the points P1, P2 and
	//! P3 are collinear, and the three are not coincident;
	//! -   gce_ConfusedPoints if two of the three points
	//! P1, P2 and P3 are coincident; or
	//! -   gce_NullAxis if Center and Ptaxis are coincident.
	xgce_MakeCirc::xgce_MakeCirc(xgp_Ax1^ Axis, Standard_Real Radius) {
		NativeHandle = new gce_MakeCirc(*Axis->GetAx1(), Radius);
		SetRoot(NativeHandle);
	};

	//! Returns the constructed circle.
	//! Exceptions StdFail_NotDone if no circle is constructed.
	xgp_Circ^ xgce_MakeCirc::Value() {
		gp_Circ* temp = new gp_Circ(NativeHandle->Value());
		return gcnew xgp_Circ(temp);
	};

	xgp_Circ^ xgce_MakeCirc::Operator() {
		gp_Circ* temp = new gp_Circ(NativeHandle->Operator());
		return gcnew xgp_Circ(temp);
	};
	xgce_MakeCirc::operator xgp_Circ^() {
		gp_Circ* temp = new gp_Circ(NativeHandle->Operator());
		return gcnew xgp_Circ(temp);
	};


	//! Returns true if the construction is successful.
	Standard_Boolean xgce_MakeCirc::IsDone() {
		return NativeHandle->IsDone();
	};

	//! Returns the status of the construction:
	//! -   gce_Done, if the construction is successful, or
	//! -   another value of the gce_ErrorType enumeration
	//! indicating why the construction failed.
	xgce_ErrorType xgce_MakeCirc::Status() {
		return safe_cast<xgce_ErrorType>(NativeHandle->Status());
	};
}