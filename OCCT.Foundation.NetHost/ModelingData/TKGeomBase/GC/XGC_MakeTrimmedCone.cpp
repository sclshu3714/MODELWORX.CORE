#include <XGC_MakeTrimmedCone.h>
namespace TKGeomBase {
	//! DEFINE_STANDARD_ALLOC
	//! 

	XGC_MakeTrimmedCone::XGC_MakeTrimmedCone() {
		/*NativeHandle = new GC_MakeTrimmedCone();
		SetRoot(NativeHandle);*/
	};

	XGC_MakeTrimmedCone::XGC_MakeTrimmedCone(GC_MakeTrimmedCone* pos) {
		NativeHandle = pos;
		SetRoot(NativeHandle);
	};

	void XGC_MakeTrimmedCone::SetMakeTrimmedConeHandle(GC_MakeTrimmedCone* pos) {
		NativeHandle = pos;
		SetRoot(NativeHandle);
	};

	GC_MakeTrimmedCone* XGC_MakeTrimmedCone::GetMakeTrimmedCone() {
		return NativeHandle;
	};

	GC_Root* XGC_MakeTrimmedCone::GetRoot() {
		return NativeHandle;
	};

	//! Make a RectangularTrimmedSurface <TheCone> from Geom
	//! It is trimmed by P3 and P4.
	//! Its axis is <P1P2> and the radius of its base is
	//! the distance between <P3> and <P1P2>.
	//! The distance between <P4> and <P1P2> is the radius of
	//! the section passing through <P4>.
	//! An error iss raised if <P1>,<P2>,<P3>,<P4> are
	//! colinear or if <P3P4> is perpendicular to <P1P2> or
	//! <P3P4> is colinear to <P1P2>.
	XGC_MakeTrimmedCone::XGC_MakeTrimmedCone(xgp_Pnt^ P1, xgp_Pnt^ P2, xgp_Pnt^ P3, xgp_Pnt^ P4) {
		NativeHandle = new GC_MakeTrimmedCone(*P1->GetPnt(), *P2->GetPnt(), *P3->GetPnt(), *P4->GetPnt());
		SetRoot(NativeHandle);
	};

	//! Make a RectangularTrimmedSurface from Geom <TheCone>
	//! from a cone and trimmed by two points P1 and P2 and
	//! the two radius <R1> and <R2> of the sections passing
	//! through <P1> an <P2>.
	//! Warning
	//! If an error occurs (that is, when IsDone returns
	//! false), the Status function returns:
	//! -   gce_ConfusedPoints if points P1 and P2, or P3 and P4, are coincident;
	//! -   gce_NullAngle if:
	//! -   the lines joining P1 to P2 and P3 to P4 are parallel, or
	//! -   R1 and R2 are equal (i.e. their difference is less than gp::Resolution());
	//! -   gce_NullRadius if:
	//! -   the line joining P1 to P2 is perpendicular to the line joining P3 to P4, or
	//! -   the points P1, P2, P3 and P4 are collinear;
	//! -   gce_NegativeRadius if R1 or R2 is negative; or
	//! -   gce_NullAxis if points P1 and P2 are coincident (2nd syntax only).
	XGC_MakeTrimmedCone::XGC_MakeTrimmedCone(xgp_Pnt^ P1, xgp_Pnt^ P2, Standard_Real R1, Standard_Real R2) {
		NativeHandle = new GC_MakeTrimmedCone(*P1->GetPnt(), *P2->GetPnt(), R1, R2);
		SetRoot(NativeHandle);
	};

	//! Returns the constructed trimmed cone.
	//! StdFail_NotDone if no trimmed cone is constructed.
	XGeom_RectangularTrimmedSurface^ XGC_MakeTrimmedCone::Value() {
		return gcnew XGeom_RectangularTrimmedSurface(NativeHandle->Value());
	};

	//! Returns true if the construction is successful.
	Standard_Boolean XGC_MakeTrimmedCone::IsDone() {
		return NativeHandle->IsDone();
	};

	//! Returns the status of the construction:
	//! -   gce_Done, if the construction is successful, or
	//! -   another value of the gce_ErrorType enumeration
	//! indicating why the construction failed.
	xgce_ErrorType XGC_MakeTrimmedCone::Status() {
		return safe_cast<xgce_ErrorType>(NativeHandle->Status());
	};
}
