#include <XGC_MakeScale.h>
namespace TKGeomBase {
	//! DEFINE_STANDARD_ALLOC
	XGC_MakeScale::XGC_MakeScale() {
		//NativeHandle = new GC_MakeScale();
	};

	XGC_MakeScale::XGC_MakeScale(GC_MakeScale* pos) {
		NativeHandle = pos;
	};

	void XGC_MakeScale::SetMakeScale(GC_MakeScale* pos) {
		NativeHandle = pos;
	};

	GC_MakeScale* XGC_MakeScale::GetMakeScale() {
		return NativeHandle;
	};

	//! Constructs a scaling transformation with
	//! -   Point as the center of the transformation, and
	//! -   Scale as the scale factor.
	XGC_MakeScale::XGC_MakeScale(xgp_Pnt^ Point, Standard_Real Scale) {
		NativeHandle = new GC_MakeScale(*Point->GetPnt(), Scale);
	};

	//! Returns the constructed transformation.
	XGeom_Transformation^ XGC_MakeScale::Value() {
		return gcnew XGeom_Transformation(NativeHandle->Value());
	};
}
