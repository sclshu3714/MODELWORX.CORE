#include <XGC_MakeCircle.h>
namespace TKGeomBase {
	//! DEFINE_STANDARD_ALLOC
	XGC_MakeCircle::XGC_MakeCircle(GC_MakeCircle* pos) {
		NativeHandle = pos;
		SetRoot(NativeHandle);
	};

	void XGC_MakeCircle::SetMakeCircleHandle(GC_MakeCircle* pos) {
		NativeHandle = pos;
		SetRoot(NativeHandle);
	};

	GC_MakeCircle* XGC_MakeCircle::GetMakeCircle() {
		return NativeHandle;
	};

	//! creates a circle from a non persistent circle C by its conversion.
	XGC_MakeCircle::XGC_MakeCircle(xgp_Circ^ C) {
		NativeHandle = new GC_MakeCircle(*C->GetCirc());
		SetRoot(NativeHandle);
	};


	//! A2 is the local coordinates system of the circle.
	//! It is not forbidden to create a circle with Radius = 0.0
	//! Status is "NegativeRadius" if Radius < 0.
	XGC_MakeCircle::XGC_MakeCircle(xgp_Ax2^ A2, Standard_Real Radius) {
		NativeHandle = new GC_MakeCircle(*A2->GetAx2(), Radius);
		SetRoot(NativeHandle);
	};

	//! Make a Circle from Geom <TheCirc> parallel to another
	//! Circ <Circ> with a distance <Dist>.
	//! If Dist is greater than zero the result is enclosing
	//! the circle <Circ>, else the result is enclosed by the
	//! circle <Circ>.
	XGC_MakeCircle::XGC_MakeCircle(xgp_Circ^ Circ, Standard_Real Dist) {
		NativeHandle = new GC_MakeCircle(*Circ->GetCirc(), Dist);
		SetRoot(NativeHandle);
	};

	//! Make a Circle from Geom <TheCirc> parallel to another
	//! Circ <Circ> and passing through a Pnt <Point>.
	XGC_MakeCircle::XGC_MakeCircle(xgp_Circ^ Circ, xgp_Pnt^ Point) {
		NativeHandle = new GC_MakeCircle(*Circ->GetCirc(), *Point->GetPnt());
		SetRoot(NativeHandle);
	};

	//! Make a Circ from gp <TheCirc> passing through 3
	//! Pnt2d <P1>,<P2>,<P3>.
	XGC_MakeCircle::XGC_MakeCircle(xgp_Pnt^ P1, xgp_Pnt^ P2, xgp_Pnt^ P3) {
		NativeHandle = new GC_MakeCircle(*P1->GetPnt(), *P2->GetPnt(), *P3->GetPnt());
		SetRoot(NativeHandle);
	};

	//! Make a Circle from Geom <TheCirc> with its center
	//! <Center> and the normal of its plane <Norm> and
	//! its radius <Radius>.
	XGC_MakeCircle::XGC_MakeCircle(xgp_Pnt^ Center, xgp_Dir^ Norm, Standard_Real Radius) {
		NativeHandle = new GC_MakeCircle(*Center->GetPnt(), *Norm->GetDir(), Radius);
		SetRoot(NativeHandle);
	};

	//! Make a Circle from Geom <TheCirc> with its center
	//! <Center> and the normal of its plane defined by the
	//! two points <Center> and <PtAxis> and its radius <Radius>.
	XGC_MakeCircle::XGC_MakeCircle(xgp_Pnt^ Center, xgp_Pnt^ PtAxis, Standard_Real Radius) {
		NativeHandle = new GC_MakeCircle(*Center->GetPnt(), *PtAxis->GetPnt(), Radius);
		SetRoot(NativeHandle);
	};

	//! Make a Circle from Geom <TheCirc> with its center
	//! <Center> and its radius <Radius>.
	XGC_MakeCircle::XGC_MakeCircle(xgp_Ax1^ Axis, Standard_Real Radius) {
		NativeHandle = new GC_MakeCircle(*Axis->GetAx1(), Radius);
		SetRoot(NativeHandle);
	};


	//! Returns the constructed circle.
	//! Exceptions
	//! StdFail_NotDone if no circle is constructed.
	XGeom_Circle^ XGC_MakeCircle::Value() {
		return gcnew XGeom_Circle(NativeHandle->Value());
	};

	//! Returns true if the construction is successful.
	Standard_Boolean XGC_MakeCircle::IsDone() {
		return NativeHandle->IsDone();
	};

	//! Returns the status of the construction:
	//! -   gce_Done, if the construction is successful, or
	//! -   another value of the gce_ErrorType enumeration
	//! indicating why the construction failed.
	xgce_ErrorType XGC_MakeCircle::Status() {
		return safe_cast<xgce_ErrorType>(NativeHandle->Status());
	};
}
