#include <XBRepPrimAPI_MakeSweep.h>

namespace TKPrim {
	//! DEFINE_STANDARD_ALLOC
	void XBRepPrimAPI_MakeSweep::SetMakeSweepHandle(BRepPrimAPI_MakeSweep* pos) {
		NativeHandle = pos;
		SetMakeShapeHandle(*NativeHandle);
	};

	//! Returns the  TopoDS  Shape of the bottom of the sweep.
	XTopoDS_Shape^ XBRepPrimAPI_MakeSweep::FirstShape() {
		return gcnew XTopoDS_Shape(NativeHandle->FirstShape());
	};

	//! Returns the TopoDS Shape of the top of the sweep.
	XTopoDS_Shape^ XBRepPrimAPI_MakeSweep::LastShape() {
		return gcnew XTopoDS_Shape(NativeHandle->LastShape());
	};
}