#include <XBRepPrimAPI_MakeSweep.h>

namespace TKPrim {
	//! DEFINE_STANDARD_ALLOC
	//! 
	//! 
	XBRepPrimAPI_MakeSweep::XBRepPrimAPI_MakeSweep() {
		
	};

	XBRepPrimAPI_MakeSweep::XBRepPrimAPI_MakeSweep(BRepPrimAPI_MakeSweep* pos) {
		NativeHandle = pos;
		SetMakeShapeHandle(NativeHandle);
	};


	void XBRepPrimAPI_MakeSweep::SetMakeSweepHandle(BRepPrimAPI_MakeSweep* pos) {
		NativeHandle = pos;
		SetMakeShapeHandle(NativeHandle);
	};

	BRepPrimAPI_MakeSweep* XBRepPrimAPI_MakeSweep::GetMakeSweep() {
		return NativeHandle;
	};

	BRepBuilderAPI_MakeShape* XBRepPrimAPI_MakeSweep::GetMakeShape() {
		return NativeHandle;
	};

	//! Returns the  TopoDS  Shape of the bottom of the sweep.
	XTopoDS_Shape^ XBRepPrimAPI_MakeSweep::FirstShape() {
		TopoDS_Shape* aShape = new TopoDS_Shape(NativeHandle->FirstShape());
		return gcnew XTopoDS_Shape(aShape);
	};

	//! Returns the TopoDS Shape of the top of the sweep.
	XTopoDS_Shape^ XBRepPrimAPI_MakeSweep::LastShape() {
		TopoDS_Shape* aShape = new TopoDS_Shape(NativeHandle->LastShape());
		return gcnew XTopoDS_Shape(aShape);
	};

	XTopoDS_Shape^ XBRepPrimAPI_MakeSweep::Shape() {
		TopoDS_Shape* Shape = new TopoDS_Shape(NativeHandle->Shape());
		return gcnew XTopoDS_Shape(Shape);
	};
}
