#include <XBRepPrim_Torus.h>
namespace TKPrim {
	//! 
	XBRepPrim_Torus::XBRepPrim_Torus() {
		//NativeHandle = new BRepPrim_Torus();
	};

	XBRepPrim_Torus::XBRepPrim_Torus(BRepPrim_Torus* handle) {
		NativeHandle = handle;
		SetRevolutionHandle(NativeHandle);
	};

	void XBRepPrim_Torus::SetPrimTorusHandle(BRepPrim_Torus* handle) {
		NativeHandle = handle;
		SetRevolutionHandle(NativeHandle);
	};

	BRepPrim_Torus* XBRepPrim_Torus::GetPrimTorus() {
		return NativeHandle;
	};

	BRepPrim_Revolution* XBRepPrim_Torus::GetRevolution() {
		return NativeHandle;
	};

	BRepPrim_OneAxis* XBRepPrim_Torus::GetOneAxis() {
		return NativeHandle;
	};

	//! the STEP definition
	//! Position : center and axes
	//! Major, Minor : Radii
	//!
	//! Errors : Major < Resolution
	//! Minor < Resolution
	XBRepPrim_Torus::XBRepPrim_Torus(xgp_Ax2^ Position, Standard_Real Major, Standard_Real Minor) {
		NativeHandle = new BRepPrim_Torus(*Position->GetAx2(), Major, Minor);
		SetRevolutionHandle(NativeHandle);
	};

	//! Torus centered at origin
	XBRepPrim_Torus::XBRepPrim_Torus(Standard_Real Major, Standard_Real Minor) {
		NativeHandle = new BRepPrim_Torus(Major, Minor);
		SetRevolutionHandle(NativeHandle);
	};

	//! Torus at Center
	XBRepPrim_Torus::XBRepPrim_Torus(xgp_Pnt^ Center, Standard_Real Major, Standard_Real Minor) {
		NativeHandle = new BRepPrim_Torus(*Center->GetPnt(), Major, Minor);
		SetRevolutionHandle(NativeHandle);
	};

	//! The surface normal should be directed  towards the
	//! outside.
	XTopoDS_Face^ XBRepPrim_Torus::MakeEmptyLateralFace() {
		TopoDS_Face* aFace = new TopoDS_Face(NativeHandle->MakeEmptyLateralFace());
		return gcnew XTopoDS_Face(aFace);
	};
}
