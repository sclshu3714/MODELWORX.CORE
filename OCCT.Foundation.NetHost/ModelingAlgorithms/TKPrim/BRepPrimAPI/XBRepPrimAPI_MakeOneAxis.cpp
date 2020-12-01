#include <XBRepPrimAPI_MakeOneAxis.h>

namespace TKPrim {

	void XBRepPrimAPI_MakeOneAxis::SetMakeOneAxisHandle(BRepPrimAPI_MakeOneAxis* handle) {
		NativeHandle = handle;
		SetMakeShapeHandle(NativeHandle);
	};

	BRepPrimAPI_MakeOneAxis* XBRepPrimAPI_MakeOneAxis::GetMakeOneAxis() {
		return NativeHandle;
	};

	BRepBuilderAPI_MakeShape* XBRepPrimAPI_MakeOneAxis::GetMakeShape() {
		return NativeHandle;
	};

	//! The inherited commands should provide the algorithm.
	//! Returned as a pointer.
	Object^ XBRepPrimAPI_MakeOneAxis::OneAxis() {
		return XStandard_Helper::toObject(NativeHandle->OneAxis());
	};

	//! Stores the solid in myShape.
	void XBRepPrimAPI_MakeOneAxis::Build() {
		NativeHandle->Build();
	};

	//! Returns the lateral face of the rotational primitive.
	XTopoDS_Face^ XBRepPrimAPI_MakeOneAxis::Face() {
		TopoDS_Face* aFace = new TopoDS_Face(NativeHandle->Face());
		return gcnew XTopoDS_Face(aFace);
	};
	XBRepPrimAPI_MakeOneAxis::operator XTopoDS_Face^() {
		TopoDS_Face* aFace = new TopoDS_Face(NativeHandle->Face());
		return gcnew XTopoDS_Face(aFace);
	};

	//! Returns the constructed rotational primitive as a shell.
	XTopoDS_Shell^ XBRepPrimAPI_MakeOneAxis::Shell() {
		TopoDS_Shell* aShell = new TopoDS_Shell(NativeHandle->Shell());
		return gcnew XTopoDS_Shell(aShell);
	};
	XBRepPrimAPI_MakeOneAxis::operator XTopoDS_Shell^() {
		TopoDS_Shell* aShell = new TopoDS_Shell(NativeHandle->Shell());
		return gcnew XTopoDS_Shell(aShell);
	};

	//! Returns the constructed rotational primitive as a solid.
	XTopoDS_Solid^ XBRepPrimAPI_MakeOneAxis::Solid() {
		TopoDS_Solid* aSolid = new TopoDS_Solid(NativeHandle->Solid());
		return gcnew XTopoDS_Solid(aSolid);
	};
	XBRepPrimAPI_MakeOneAxis::operator XTopoDS_Solid^() {
		TopoDS_Solid* aSolid = new TopoDS_Solid(NativeHandle->Solid());
		return gcnew XTopoDS_Solid(aSolid);
	};
}

