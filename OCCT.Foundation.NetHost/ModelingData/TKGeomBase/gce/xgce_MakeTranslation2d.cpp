#include <xgce_MakeTranslation2d.h>
namespace TKGeomBase {
	//DEFINE_STANDARD_ALLOC
	xgce_MakeTranslation2d::xgce_MakeTranslation2d() {
		///NativeHandle = new gce_MakeTranslation2d();
	};

	xgce_MakeTranslation2d::xgce_MakeTranslation2d(gce_MakeTranslation2d* pos) {
		NativeHandle = pos;
	};

	void xgce_MakeTranslation2d::SetMakeTranslation2d(gce_MakeTranslation2d* pos) {
		NativeHandle = pos;
	};

	gce_MakeTranslation2d* xgce_MakeTranslation2d::GetMakeTranslation2d() {
		return NativeHandle;
	};

	//! Constructs a translation along the vector Vect.
	xgce_MakeTranslation2d::xgce_MakeTranslation2d(xgp_Vec2d^ Vect) {
		NativeHandle = new gce_MakeTranslation2d(*Vect->GetVec2d());
	};

	//! Constructs a translation along the vector
	//! (Point1,Point2) defined from the point Point1 to the point Point2.
	xgce_MakeTranslation2d::xgce_MakeTranslation2d(xgp_Pnt2d^ Point1, xgp_Pnt2d^ Point2) {
		NativeHandle = new gce_MakeTranslation2d(*Point1->GetPnt2d(), *Point2->GetPnt2d());
	};

	//! Returns theructed transformation.
	xgp_Trsf2d^ xgce_MakeTranslation2d::Value() {
		gp_Trsf2d* temp = new gp_Trsf2d(NativeHandle->Value());
		return gcnew xgp_Trsf2d(temp);
	};

	xgp_Trsf2d^ xgce_MakeTranslation2d::Operator() {
		gp_Trsf2d* temp = new gp_Trsf2d(NativeHandle->Operator());
		return gcnew xgp_Trsf2d(temp);
	};
	xgce_MakeTranslation2d::operator xgp_Trsf2d^() {
		gp_Trsf2d* temp = new gp_Trsf2d(NativeHandle->Operator());
		return gcnew xgp_Trsf2d(temp);
	};
}
