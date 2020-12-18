#include <xgce_MakeScale2d.h>
namespace TKGeomBase {
	xgce_MakeScale2d::xgce_MakeScale2d() {
		//NativeHandle = new gce_MakeScale2d();
	};

	xgce_MakeScale2d::xgce_MakeScale2d(gce_MakeScale2d* pos) {
		NativeHandle = pos;
	};

	void xgce_MakeScale2d::SetMakeScale2d(gce_MakeScale2d* pos) {
		NativeHandle = pos;
	};

	gce_MakeScale2d* xgce_MakeScale2d::GetMakeScale2d() {
		return NativeHandle;
	};

	//! Constructs a scaling transformation with:
	//! -   Point as the center of the transformation, and
	//! -   Scale as the scale factor.
	xgce_MakeScale2d::xgce_MakeScale2d(xgp_Pnt2d^ Point, Standard_Real Scale) {
		NativeHandle = new gce_MakeScale2d(*Point->GetPnt2d(), Scale);
	};

	//! Returns theructed transformation.
	xgp_Trsf2d^ xgce_MakeScale2d::Value() {
		gp_Trsf2d* temp = new gp_Trsf2d(NativeHandle->Value());
		return gcnew xgp_Trsf2d(temp);
	};

	xgp_Trsf2d^ xgce_MakeScale2d::Operator() {
		gp_Trsf2d* temp = new gp_Trsf2d(NativeHandle->Operator());
		return gcnew xgp_Trsf2d(temp);
	};
	xgce_MakeScale2d::operator xgp_Trsf2d^() {
		gp_Trsf2d* temp = new gp_Trsf2d(NativeHandle->Operator());
		return gcnew xgp_Trsf2d(temp);
	};
}