#include <xgce_MakeParab2d.h>
namespace TKGeomBase {
	//DEFINE_STANDARD_ALLOC
	xgce_MakeParab2d::xgce_MakeParab2d() {
		/*NativeHandle = new gce_MakeParab2d();
		SetRoot(NativeHandle);*/
	};

	xgce_MakeParab2d::xgce_MakeParab2d(gce_MakeParab2d* pos) {
		NativeHandle = pos;
		SetRoot(NativeHandle);
	};

	void xgce_MakeParab2d::SetMakeParab2d(gce_MakeParab2d* pos) {
		NativeHandle = pos;
		SetRoot(NativeHandle);
	};

	gce_MakeParab2d* xgce_MakeParab2d::GetMakeParab2d() {
		return NativeHandle;
	};

	gce_Root* xgce_MakeParab2d::GetRoot() {
		return NativeHandle;
	};


	//! Creates a parabola with its axis of symmetry ("MirrorAxis")
	//! and its focal length.
	//! Warnings : It is possible to have Focal = 0.
	//! The status is "NullFocalLength" Raised if Focal < 0.0
	//! Standard_Boolean Sense = Standard_True
	xgce_MakeParab2d::xgce_MakeParab2d(xgp_Ax2d^ MirrorAxis, Standard_Real Focal, Standard_Boolean Sense) {
		NativeHandle = new gce_MakeParab2d(*MirrorAxis->GetAx2d(), Focal, Sense);
		SetRoot(NativeHandle);
	};


	//! Creates a parabola with its local coordinate system <A>
	//! and its focal length.
	//! Warnings : It is possible to have Focal = 0.
	//! The status is "NullFocalLength" Raised if Focal < 0.0
	xgce_MakeParab2d::xgce_MakeParab2d(xgp_Ax22d^ A, Standard_Real Focal) {
		NativeHandle = new gce_MakeParab2d(*A->GetAx22d(), Focal);
		SetRoot(NativeHandle);
	};


	//! Creates a parabola with the directrix and the focus point.
	//! The sense of parametrization is given by Sense.
	//! Standard_Boolean Sense = Standard_True
	xgce_MakeParab2d::xgce_MakeParab2d(xgp_Ax2d^ D, xgp_Pnt2d^ F, Standard_Boolean Sense) {
		NativeHandle = new gce_MakeParab2d(*D->GetAx2d(), *F->GetPnt2d(), Sense);
		SetRoot(NativeHandle);
	};


	//! Make an Parab2d with S1 as the Focal point and Center
	//! as the apex of the parabola
	//! Warning
	//! The MakeParab2d class does not prevent the
	//!ruction of a parabola with a null focal distance.
	//! If an error occurs (that is, when IsDone returns
	//! false), the Status function returns:
	//! -   gce_NullFocusLength if Focal is less than 0.0, or
	//! -   gce_NullAxis if S1 and Center are coincident.
	//! Standard_Boolean Sense = Standard_True
	xgce_MakeParab2d::xgce_MakeParab2d(xgp_Pnt2d^ S1, xgp_Pnt2d^ Center, Standard_Boolean Sense) {
		NativeHandle = new gce_MakeParab2d(*S1->GetPnt2d(), *Center->GetPnt2d(), Sense);
		SetRoot(NativeHandle);
	};

	//! Returns theructed parabola.
	//! Exceptions StdFail_NotDone if no parabola isructed.
	xgp_Parab2d^ xgce_MakeParab2d::Value() {
		gp_Parab2d* temp = new gp_Parab2d(NativeHandle->Value());
		return gcnew xgp_Parab2d(temp);
	};

	xgp_Parab2d^ xgce_MakeParab2d::Operator() {
		gp_Parab2d* temp = new gp_Parab2d(NativeHandle->Operator());
		return gcnew xgp_Parab2d(temp);
	};
	xgce_MakeParab2d::operator xgp_Parab2d^() {
		gp_Parab2d* temp = new gp_Parab2d(NativeHandle->Operator());
		return gcnew xgp_Parab2d(temp);
	};

	//! Returns true if the construction is successful.
	Standard_Boolean xgce_MakeParab2d::IsDone() {
		return NativeHandle->IsDone();
	};


	//! Returns the status of the construction:
	//! -   gce_Done, if the construction is successful, or
	//! -   another value of the gce_ErrorType enumeration
	//! indicating why the construction failed.
	xgce_ErrorType xgce_MakeParab2d::Status() {
		return safe_cast<xgce_ErrorType>(NativeHandle->Status());
	};
}