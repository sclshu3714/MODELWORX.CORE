#include <XBRepPrimAPI_MakeWedge.h>

namespace TKPrim {
	XBRepPrimAPI_MakeWedge::XBRepPrimAPI_MakeWedge() {

	};

	XBRepPrimAPI_MakeWedge::XBRepPrimAPI_MakeWedge(BRepPrimAPI_MakeWedge* handle) {
		NativeHandle = handle;
		SetMakeShapeHandle(NativeHandle);
	};

	void XBRepPrimAPI_MakeWedge::SetMakeWedgeHandle(BRepPrimAPI_MakeWedge* handle) {
		NativeHandle = handle;
		SetMakeShapeHandle(NativeHandle);
	};

	BRepPrimAPI_MakeWedge* XBRepPrimAPI_MakeWedge::GetMakeWedge() {
		return NativeHandle;
	};

	BRepBuilderAPI_MakeShape* XBRepPrimAPI_MakeWedge::GetMakeShape() {
		return NativeHandle;
	};

	//! Make a STEP right angular wedge. (ltx >= 0)
	XBRepPrimAPI_MakeWedge::XBRepPrimAPI_MakeWedge(Standard_Real dx, Standard_Real dy, Standard_Real dz, Standard_Real ltx) {
		NativeHandle = new BRepPrimAPI_MakeWedge(dx, dy, dz, ltx);
		SetMakeShapeHandle(NativeHandle);
	};

	//! Make a STEP right angular wedge. (ltx >= 0)
	XBRepPrimAPI_MakeWedge::XBRepPrimAPI_MakeWedge(xgp_Ax2^ Axes, Standard_Real dx, Standard_Real dy, Standard_Real dz, Standard_Real ltx) {
		NativeHandle = new BRepPrimAPI_MakeWedge(*Axes->GetAx2(), dx, dy, dz, ltx);
		SetMakeShapeHandle(NativeHandle);
	};

	//! Make a wedge. The face at dy is xmin,zmin xmax,zmax
	XBRepPrimAPI_MakeWedge::XBRepPrimAPI_MakeWedge(Standard_Real dx, Standard_Real dy, Standard_Real dz, Standard_Real xmin, Standard_Real zmin, Standard_Real xmax, Standard_Real zmax) {
		NativeHandle = new BRepPrimAPI_MakeWedge(dx, dy, dz, xmin, zmin, xmax, zmax);
		SetMakeShapeHandle(NativeHandle);
	};

	//! Make a wedge. The face at dy is xmin,zmin xmax,zmax
	XBRepPrimAPI_MakeWedge::XBRepPrimAPI_MakeWedge(xgp_Ax2^ Axes, Standard_Real dx, Standard_Real dy, Standard_Real dz, Standard_Real xmin, Standard_Real zmin, Standard_Real xmax, Standard_Real zmax) {
		NativeHandle = new BRepPrimAPI_MakeWedge(*Axes->GetAx2(), dx, dy, dz, xmin, zmin, xmax, zmax);
		SetMakeShapeHandle(NativeHandle);
	};

	//! Returns the internal algorithm.
	XBRepPrim_Wedge^ XBRepPrimAPI_MakeWedge::Wedge() {
		BRepPrim_Wedge* temp = new BRepPrim_Wedge(NativeHandle->Wedge());
		return gcnew XBRepPrim_Wedge(temp);
	};

	//! Stores the solid in myShape.
	void XBRepPrimAPI_MakeWedge::Build() {
		NativeHandle->Build();
	};

	//! Returns the constructed box in the form of a shell.
	XTopoDS_Shell^ XBRepPrimAPI_MakeWedge::Shell() {
		TopoDS_Shell* temp = new TopoDS_Shell(NativeHandle->Shell());
		return gcnew XTopoDS_Shell(temp);
	};
	XBRepPrimAPI_MakeWedge::operator XTopoDS_Shell^() {
		TopoDS_Shell* temp = new TopoDS_Shell(NativeHandle->Shell());
		return gcnew XTopoDS_Shell(temp);
	};

	//! Returns the constructed box in the form of a solid.
	XTopoDS_Solid^ XBRepPrimAPI_MakeWedge::Solid() {
		TopoDS_Solid* temp = new TopoDS_Solid(NativeHandle->Solid());
		return gcnew XTopoDS_Solid(temp);
	};
	XBRepPrimAPI_MakeWedge::operator XTopoDS_Solid^() {
		TopoDS_Solid* temp = new TopoDS_Solid(NativeHandle->Solid());
		return gcnew XTopoDS_Solid(temp);
	};
}