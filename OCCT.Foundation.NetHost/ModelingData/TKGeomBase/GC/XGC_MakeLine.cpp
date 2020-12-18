#include <XGC_MakeLine.h>
namespace TKGeomBase {

	XGC_MakeLine::XGC_MakeLine() {
		/*NativeHandle = new GC_MakeLine();
		SetRoot(NativeHandle);*/
	};

	XGC_MakeLine::XGC_MakeLine(GC_MakeLine* pos) {
		NativeHandle = pos;
		SetRoot(NativeHandle);
	};

	void XGC_MakeLine::SetMakeLine(GC_MakeLine* pos) {
		NativeHandle = pos;
		SetRoot(NativeHandle);
	};

	GC_MakeLine* XGC_MakeLine::GetMakeLine() {
		return NativeHandle;
	};

	GC_Root* XGC_MakeLine::GetRoot() {
		return NativeHandle;
	};

	//! Creates a line located in 3D space with the axis placement A1.
	//! The Location of A1 is the origin of the line.
	XGC_MakeLine::XGC_MakeLine(xgp_Ax1^ A1) {
		NativeHandle = new GC_MakeLine(*A1->GetAx1());
		SetRoot(NativeHandle);
	};


	//! Creates a line from a non persistent line from package gp.
	XGC_MakeLine::XGC_MakeLine(xgp_Lin^ L) {
		NativeHandle = new GC_MakeLine(*L->GetLin());
		SetRoot(NativeHandle);
	};


	//! P is the origin and V is the direction of the line.
	XGC_MakeLine::XGC_MakeLine(xgp_Pnt^ P, xgp_Dir^ V) {
		NativeHandle = new GC_MakeLine(*P->GetPnt(), *V->GetDir());
		SetRoot(NativeHandle);
	};

	//! Make a Line from Geom <TheLin> parallel to another
	//! Lin <Lin> and passing through a Pnt <Point>.
	XGC_MakeLine::XGC_MakeLine(xgp_Lin^ Lin, xgp_Pnt^ Point) {
		NativeHandle = new GC_MakeLine(*Lin->GetLin(), *Point->GetPnt());
		SetRoot(NativeHandle);
	};

	//! Make a Line from Geom <TheLin> passing through 2
	//! Pnt <P1>,<P2>.
	//! It returns false if <p1> and <P2> are confused.
	//! Warning
	//! If the points P1 and P2 are coincident (that is, when
	//! IsDone returns false), the Status function returns gce_ConfusedPoints.
	XGC_MakeLine::XGC_MakeLine(xgp_Pnt^ P1, xgp_Pnt^ P2) {
		NativeHandle = new GC_MakeLine(*P1->GetPnt(), *P2->GetPnt());
		SetRoot(NativeHandle);
	};

	//! Returns the constructed line.
	//! Exceptions StdFail_NotDone if no line is constructed.
	XGeom_Line^ XGC_MakeLine::Value() {
		return gcnew XGeom_Line(NativeHandle->Value());
	};

	//! Returns true if the construction is successful.
	Standard_Boolean XGC_MakeLine::IsDone() {
		return NativeHandle->IsDone();
	};

	//! Returns the status of the construction:
	//! -   gce_Done, if the construction is successful, or
	//! -   another value of the gce_ErrorType enumeration
	//! indicating why the construction failed.
	xgce_ErrorType XGC_MakeLine::Status() {
		return safe_cast<xgce_ErrorType>(NativeHandle->Status());
	};
}