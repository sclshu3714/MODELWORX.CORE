#include <XGC_MakeTranslation.h>
namespace TKGeomBase {
	//! DEFINE_STANDARD_ALLOC
	XGC_MakeTranslation::XGC_MakeTranslation() {
		//NativeHandle = new GC_MakeTranslation();
	};

	XGC_MakeTranslation::XGC_MakeTranslation(GC_MakeTranslation* pos) {
		NativeHandle = pos;
	};

	void XGC_MakeTranslation::SetMakeTranslation(GC_MakeTranslation* pos) {
		NativeHandle = pos;
	};

	GC_MakeTranslation* XGC_MakeTranslation::GetMakeTranslation() {
		return NativeHandle;
	};

	//! Constructs a translation along the vector " Vect "
	XGC_MakeTranslation::XGC_MakeTranslation(xgp_Vec^ Vect) {
		NativeHandle = new GC_MakeTranslation(*Vect->GetVec());
	};

	//! Constructs a translation along the vector (Point1,Point2)
	//! defined from the point Point1 to the point Point2.
	XGC_MakeTranslation::XGC_MakeTranslation(xgp_Pnt^ Point1, xgp_Pnt^ Point2) {
		NativeHandle = new GC_MakeTranslation(*Point1->GetPnt(), *Point2->GetPnt());
	};

	//! Returns the constructed transformation.
	XGeom_Transformation^ XGC_MakeTranslation::Value() {
		return gcnew XGeom_Transformation(NativeHandle->Value());
	};
}
