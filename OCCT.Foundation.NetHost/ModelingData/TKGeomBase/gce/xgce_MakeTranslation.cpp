#include <xgce_MakeTranslation.h>
namespace TKGeomBase {
	xgce_MakeTranslation::xgce_MakeTranslation() {
		//NativeHandle = new gce_MakeTranslation();
	};

	xgce_MakeTranslation::xgce_MakeTranslation(gce_MakeTranslation* pos) {
		NativeHandle = pos;
	};

	void xgce_MakeTranslation::SetMakeTranslation(gce_MakeTranslation* pos) {
		NativeHandle = pos;
	};

	gce_MakeTranslation* xgce_MakeTranslation::GetMakeTranslation() {
		return NativeHandle;
	};

	//! Constructs a translation along the vector " Vect"
	xgce_MakeTranslation::xgce_MakeTranslation(xgp_Vec^ Vect) {
		NativeHandle = new gce_MakeTranslation(*Vect->GetVec());
	};

	//! Constructs a translation along the vector
	//! (Point1,Point2) defined from the point Point1 to the point Point2.
	xgce_MakeTranslation::xgce_MakeTranslation(xgp_Pnt^ Point1, xgp_Pnt^ Point2) {
		NativeHandle = new gce_MakeTranslation(*Point1->GetPnt(), *Point2->GetPnt());
	};


	//! Returns theructed transformation.
	xgp_Trsf^ xgce_MakeTranslation::Value() {
		gp_Trsf* temp = new gp_Trsf(NativeHandle->Value());
		return gcnew xgp_Trsf(temp);
	};

	xgp_Trsf^ xgce_MakeTranslation::Operator() {
		gp_Trsf* temp = new gp_Trsf(NativeHandle->Operator());
		return gcnew xgp_Trsf(temp);
	};
	xgce_MakeTranslation::operator xgp_Trsf^() {
		gp_Trsf* temp = new gp_Trsf(NativeHandle->Operator());
		return gcnew xgp_Trsf(temp);
	};
}