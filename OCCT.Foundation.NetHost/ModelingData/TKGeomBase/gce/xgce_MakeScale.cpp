#include <xgce_MakeScale.h>
namespace TKGeomBase {
	//DEFINE_STANDARD_ALLOC
	xgce_MakeScale::xgce_MakeScale() {
		//NativeHandle = new gce_MakeScale();
	};

	xgce_MakeScale::xgce_MakeScale(gce_MakeScale* pos) {
		NativeHandle = pos;
	};

	void xgce_MakeScale::SetMakeScale(gce_MakeScale* pos) {
		NativeHandle = pos;
	};

	gce_MakeScale* xgce_MakeScale::GetMakeScale() {
		return NativeHandle;
	};

	//! Constructs a scaling transformation with
	//! -   Point as the center of the transformation, and
	//! -   Scale as the scale factor.
	xgce_MakeScale::xgce_MakeScale(xgp_Pnt^ Point, Standard_Real Scale) {
		NativeHandle = new gce_MakeScale(*Point->GetPnt(), Scale);
	};

	//! Returns theructed transformation.
	xgp_Trsf^ xgce_MakeScale::Value() {
		gp_Trsf* temp = new gp_Trsf(NativeHandle->Value());
		return gcnew xgp_Trsf(temp);
	};

	xgp_Trsf^ xgce_MakeScale::Operator() {
		gp_Trsf* temp = new gp_Trsf(NativeHandle->Operator());
		return gcnew xgp_Trsf(temp);
	};
	xgce_MakeScale::operator xgp_Trsf^() {
		gp_Trsf* temp = new gp_Trsf(NativeHandle->Operator());
		return gcnew xgp_Trsf(temp);
	};
}