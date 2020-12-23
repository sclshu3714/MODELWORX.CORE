#include <XBRepBuilderAPI.h>
namespace TKTopAlgo {
	//DEFINE_STANDARD_ALLOC
	//! Sets    the current plane.
	//! static 
	void XBRepBuilderAPI::Plane(XGeom_Plane^ P) {
		BRepBuilderAPI::Plane(P->GetPlane());
	};

	//! Returns the current plane.
	//! static 
	XGeom_Plane^ XBRepBuilderAPI::Plane() {
		return gcnew XGeom_Plane(BRepBuilderAPI::Plane());
	};

	//! Sets the default precision.  The current Precision
	//! is returned.
	//! static 
	void XBRepBuilderAPI::Precision(Standard_Real P) {
		BRepBuilderAPI::Precision(P);
	};

	//! Returns the default precision.
	//! static 
	Standard_Real XBRepBuilderAPI::Precision() {
		return BRepBuilderAPI::Precision();
	};
}