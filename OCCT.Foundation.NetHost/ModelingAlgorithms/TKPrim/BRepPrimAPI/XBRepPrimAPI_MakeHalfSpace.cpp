#include <XBRepPrimAPI_MakeHalfSpace.h>

namespace TKPrim {

	XBRepPrimAPI_MakeHalfSpace::XBRepPrimAPI_MakeHalfSpace() {
		//NativeHandle = new BRepPrimAPI_MakeHalfSpace();
	};

	XBRepPrimAPI_MakeHalfSpace::XBRepPrimAPI_MakeHalfSpace(BRepPrimAPI_MakeHalfSpace* handle) {
		NativeHandle = handle;
		SetMakeShapeHandle(NativeHandle);
	};

	void XBRepPrimAPI_MakeHalfSpace::SetMakeHalfSpaceHandle(BRepPrimAPI_MakeHalfSpace* handle) {
		NativeHandle = handle;
		SetMakeShapeHandle(NativeHandle);
	};

	BRepPrimAPI_MakeHalfSpace* XBRepPrimAPI_MakeHalfSpace::GetMakeHalfSpace() {
		return NativeHandle;
	};

	BRepBuilderAPI_MakeShape* XBRepPrimAPI_MakeHalfSpace::GetMakeShape() {
		return NativeHandle;
	};

	//! Make a HalfSpace defined with a Face and a Point.
	XBRepPrimAPI_MakeHalfSpace::XBRepPrimAPI_MakeHalfSpace(XTopoDS_Face^ Face, xgp_Pnt^ RefPnt) {
		NativeHandle = new BRepPrimAPI_MakeHalfSpace(*Face->GetFace(), *RefPnt->GetPnt());
		SetMakeShapeHandle(NativeHandle);
	};

	//! Make a HalfSpace defined with a Shell and a Point.
	XBRepPrimAPI_MakeHalfSpace::XBRepPrimAPI_MakeHalfSpace(XTopoDS_Shell^ Shell, xgp_Pnt^ RefPnt) {
		NativeHandle = new BRepPrimAPI_MakeHalfSpace(*Shell->GetShell(), *RefPnt->GetPnt());
		SetMakeShapeHandle(NativeHandle);
	};

	//! Returns the constructed half-space as a solid.
	XTopoDS_Solid^ XBRepPrimAPI_MakeHalfSpace::Solid() {
		TopoDS_Solid* temp = new TopoDS_Solid(NativeHandle->Solid());
		return gcnew XTopoDS_Solid();
	};
	XBRepPrimAPI_MakeHalfSpace::operator XTopoDS_Solid ^ () {
		TopoDS_Solid* temp = new TopoDS_Solid(NativeHandle->Solid());
		return gcnew XTopoDS_Solid();
	};
}

