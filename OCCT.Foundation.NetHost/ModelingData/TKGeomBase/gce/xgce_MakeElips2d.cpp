#include <xgce_MakeElips2d.h>
namespace TKGeomBase {
	//DEFINE_STANDARD_ALLOC
	xgce_MakeElips2d::xgce_MakeElips2d() {
		/*NativeHandle = new gce_MakeElips2d();
		SetRoot(NativeHandle);*/
	};

	xgce_MakeElips2d::xgce_MakeElips2d(gce_MakeElips2d* pos) {
		NativeHandle = pos;
		SetRoot(NativeHandle);
	};

	void xgce_MakeElips2d::SetMakeElips2d(gce_MakeElips2d* pos) {
		NativeHandle = pos;
		SetRoot(NativeHandle);
	};

	gce_MakeElips2d* xgce_MakeElips2d::GetMakeElips2d() {
		return NativeHandle;
	};

	gce_Root* xgce_MakeElips2d::GetRoot() {
		return NativeHandle;
	};


	//! Creates an ellipse with the major axis, the major and the
	//! minor radius. The location of the MajorAxis is the center
	//! of the  ellipse.
	//! The sense of parametrization is given by Sense.
	//! It is possible to create an ellipse with MajorRadius = MinorRadius.
	//! the status is "InvertRadius" if MajorRadius < MinorRadius or
	//! "NegativeRadius" if MinorRadius < 0.0
	//! Standard_Boolean Sense = Standard_True
	xgce_MakeElips2d::xgce_MakeElips2d(xgp_Ax2d^ MajorAxis, Standard_Real MajorRadius, Standard_Real MinorRadius, Standard_Boolean Sense) {
		NativeHandle = new gce_MakeElips2d(*MajorAxis->GetAx2d(), MajorRadius, MinorRadius, Sense);
		SetRoot(NativeHandle);
	};


	//! Axis defines the Xaxis and Yaxis of the ellipse which defines
	//! the origin and the sense of parametrization.
	//! Creates an ellipse with the AxisPlacement the major and the
	//! minor radius. The location of Axis is the center
	//! of the  ellipse.
	//! It is possible to create an ellipse with MajorRadius = MinorRadius.
	//! the status is "InvertRadius" if MajorRadius < MinorRadius or
	//! "NegativeRadius" if MinorRadius < 0.0
	xgce_MakeElips2d::xgce_MakeElips2d(xgp_Ax22d^ A, Standard_Real MajorRadius, Standard_Real MinorRadius) {
		NativeHandle = new gce_MakeElips2d(*A->GetAx22d(), MajorRadius, MinorRadius);
		SetRoot(NativeHandle);
	};

	//! Makes an Elips2d with its center and two points.
	//! The sense of parametrization is given by S1, S2,
	//! and Center.
	//! Depending on theructor, the  implicit orientation of the ellipse is:
	//! -   the sense defined by A,
	//! -   the sense defined by points Center, S1 and S2,
	//! -   the trigonometric sense if Sense is not given or is true, or
	//! -   the opposite if Sense is false.
	//! It is possible toruct an ellipse where the major
	//! and minor radii are equal.
	//! Warning
	//! If an error occurs (that is, when IsDone returns
	//! false), the Status function returns:
	//! -   gce_InvertRadius if MajorRadius is less than MinorRadius,
	//! -   gce_NegativeRadius if MajorRadius or
	//! MinorRadius is less than 0.0,
	//! -   gce_NullAxis if points S1, S2 and Center are collinear, or
	//! -   gce_InvertAxis if the major radius computed with
	//! Center and S1 is less than the minor radius
	//! computed with Center, S1 and S2.
	xgce_MakeElips2d::xgce_MakeElips2d(xgp_Pnt2d^ S1, xgp_Pnt2d^ S2, xgp_Pnt2d^ Center) {
		NativeHandle = new gce_MakeElips2d(*S1->GetPnt2d(), *S2->GetPnt2d(), *Center->GetPnt2d());
		SetRoot(NativeHandle);
	};

	//! Returns theructed ellipse.
	//! Exceptions StdFail_NotDone if no ellipse isructed.
	xgp_Elips2d^ xgce_MakeElips2d::Value() {
		gp_Elips2d* temp = new gp_Elips2d(NativeHandle->Value());
		return gcnew xgp_Elips2d(temp);
	};

	xgp_Elips2d^ xgce_MakeElips2d::Operator() {
		gp_Elips2d* temp = new gp_Elips2d(NativeHandle->Operator());
		return gcnew xgp_Elips2d(temp);
	};
	xgce_MakeElips2d::operator xgp_Elips2d^() {
		gp_Elips2d* temp = new gp_Elips2d(NativeHandle->Operator());
		return gcnew xgp_Elips2d(temp);
	};

	//! Returns true if the construction is successful.
	Standard_Boolean xgce_MakeElips2d::IsDone() {
		return NativeHandle->IsDone();
	};

	//! Returns the status of the construction:
	//! -   gce_Done, if the construction is successful, or
	//! -   another value of the gce_ErrorType enumeration
	//! indicating why the construction failed.
	xgce_ErrorType xgce_MakeElips2d::Status() {
		return safe_cast<xgce_ErrorType>(NativeHandle->Status());
	};
}