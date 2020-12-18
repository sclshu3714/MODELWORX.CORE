#include <xgce_MakeParab.h>
namespace TKGeomBase {
	xgce_MakeParab::xgce_MakeParab() {
		/*NativeHandle = new gce_MakeParab();
		SetRoot(NativeHandle);*/
	};

	xgce_MakeParab::xgce_MakeParab(gce_MakeParab* pos) {
		NativeHandle = pos;
		SetRoot(NativeHandle);
	};

	void xgce_MakeParab::SetMakeParab(gce_MakeParab* pos) {
		NativeHandle = pos;
		SetRoot(NativeHandle);
	};

	gce_MakeParab* xgce_MakeParab::GetMakeParab() {
		return NativeHandle;
	};

	gce_Root* xgce_MakeParab::GetRoot() {
		return NativeHandle;
	};

	//! --- Purpose ;
	//! Creates a parabola with its local coordinate system "A2"
	//! and it's focal length "Focal".
	//! The XDirection of A2 defines the axis of symmetry of the
	//! parabola. The YDirection of A2 is parallel to the directrix
	//! of the parabola. The Location point of A2 is the vertex of
	//! the parabola
	//! The status is "NullFocusLength" if Focal < 0.0
	xgce_MakeParab::xgce_MakeParab(xgp_Ax2^ A2, Standard_Real Focal) {
		NativeHandle = new gce_MakeParab(*A2->GetAx2(), Focal);
		SetRoot(NativeHandle);
	};


	//! D is the directrix of the parabola and F the focus point.
	//! The symmetry axis (XAxis) of the parabola is normal to the
	//! directrix and pass through the focus point F, but its
	//! location point is the vertex of the parabola.
	//! The YAxis of the parabola is parallel to D and its location
	//! point is the vertex of the parabola. The normal to the plane
	//! of the parabola is the cross product between the XAxis and the
	//! YAxis.
	xgce_MakeParab::xgce_MakeParab(xgp_Ax1^ D, xgp_Pnt^ F) {
		NativeHandle = new gce_MakeParab(*D->GetAx1(), *F->GetPnt());
		SetRoot(NativeHandle);
	};

	//! Returns theructed parabola.
	//! Exceptions StdFail_NotDone if no parabola isructed.
	xgp_Parab^ xgce_MakeParab::Value() {
		gp_Parab* temp = new gp_Parab(NativeHandle->Value());
		return gcnew xgp_Parab(temp);
	};

	xgp_Parab^ xgce_MakeParab::Operator() {
		gp_Parab* temp = new gp_Parab(NativeHandle->Operator());
		return gcnew xgp_Parab(temp);
	};
	xgce_MakeParab::operator xgp_Parab^() {
		gp_Parab* temp = new gp_Parab(NativeHandle->Operator());
		return gcnew xgp_Parab(temp);
	};

	//! Returns true if the construction is successful.
	Standard_Boolean xgce_MakeParab::IsDone() {
		return NativeHandle->IsDone();
	};


	//! Returns the status of the construction:
	//! -   gce_Done, if the construction is successful, or
	//! -   another value of the gce_ErrorType enumeration
	//! indicating why the construction failed.
	xgce_ErrorType xgce_MakeParab::Status() {
		return safe_cast<xgce_ErrorType>(NativeHandle->Status());
	};
}