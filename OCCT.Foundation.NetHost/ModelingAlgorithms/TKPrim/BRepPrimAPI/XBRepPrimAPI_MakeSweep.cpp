#include <XBRepPrimAPI_MakeSweep.h>

namespace TKPrim {
	//! DEFINE_STANDARD_ALLOC
	void XBRepPrimAPI_MakeSweep::SetMakeSweepHandle(BRepPrimAPI_MakeSweep* pos) {
		NativeHandle = pos;
		SetMakeShapeHandle(NativeHandle);
	};

	BRepPrimAPI_MakeSweep* XBRepPrimAPI_MakeSweep::GetMakeSweep() {
		return NativeHandle;
	};

	BRepBuilderAPI_MakeShape XBRepPrimAPI_MakeSweep::GetMakeShape() {
		return *NativeHandle;
	};

	//! Returns the  TopoDS  Shape of the bottom of the sweep.
	XTopoDS_Shape^ XBRepPrimAPI_MakeSweep::FirstShape() {
		return gcnew XTopoDS_Shape(NativeHandle->FirstShape());
	};

	//! Returns the TopoDS Shape of the top of the sweep.
	XTopoDS_Shape^ XBRepPrimAPI_MakeSweep::LastShape() {
		return gcnew XTopoDS_Shape(NativeHandle->LastShape());
	};

	XTopoDS_Shape^ XBRepPrimAPI_MakeSweep::Shape() {
		TopoDS_Shape* Shape = new TopoDS_Shape(NativeHandle->Shape());
		return gcnew XTopoDS_Shape(*Shape);
	};
}
