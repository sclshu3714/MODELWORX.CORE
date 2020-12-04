#include <XBRepPrim_Cylinder.h>

namespace TKPrim {
	//! 
	XBRepPrim_Cylinder::XBRepPrim_Cylinder() {
		//NativeHandle = new BRepPrim_Cylinder();
	};

	XBRepPrim_Cylinder::XBRepPrim_Cylinder(BRepPrim_Cylinder* handle) {
		NativeHandle = handle;
		SetRevolutionHandle(NativeHandle);
	};

	void XBRepPrim_Cylinder::SetCylinderHandle(BRepPrim_Cylinder* handle) {
		NativeHandle = handle;
		SetRevolutionHandle(NativeHandle);
	};

	BRepPrim_Cylinder* XBRepPrim_Cylinder::GetCylinder() {
		return NativeHandle;
	};

	BRepPrim_Revolution* XBRepPrim_Cylinder::GetRevolution() {
		return NativeHandle;
	};

	BRepPrim_OneAxis* XBRepPrim_Cylinder::GetOneAxis() {
		return NativeHandle;
	};

	//! the STEP definition
	//! Position : center of a Face and Axis
	//! Radius : radius of cylinder
	//! Height : distance between faces
	//! on positive side
	//!
	//! Errors : Height < Resolution
	//! Radius < Resolution
	XBRepPrim_Cylinder::XBRepPrim_Cylinder(xgp_Ax2^ Position, Standard_Real Radius, Standard_Real Height) {
		NativeHandle = new BRepPrim_Cylinder(*Position->GetAx2(), Radius, Height);
		SetRevolutionHandle(NativeHandle);
	};

	//! infinite Cylinder at origin on Z negative
	XBRepPrim_Cylinder::XBRepPrim_Cylinder(Standard_Real Radius) {
		NativeHandle = new BRepPrim_Cylinder(Radius);
		SetRevolutionHandle(NativeHandle);
	};

	//! infinite Cylinder at Center on Z negative
	XBRepPrim_Cylinder::XBRepPrim_Cylinder(xgp_Pnt^ Center, Standard_Real Radius) {
		NativeHandle = new BRepPrim_Cylinder(Center->GetPnt(), Radius);
		SetRevolutionHandle(NativeHandle);
	};

	//! infinite Cylinder at Axes on Z negative
	XBRepPrim_Cylinder::XBRepPrim_Cylinder(xgp_Ax2^ Axes, Standard_Real Radius) {
		NativeHandle = new BRepPrim_Cylinder(*Axes->GetAx2(), Radius);
		SetRevolutionHandle(NativeHandle);
	};

	//! create a Cylinder  at origin on Z  axis, of
	//! height H and radius R
	//! Error  : Radius  < Resolution
	//! H < Resolution
	//! H negative
	XBRepPrim_Cylinder::XBRepPrim_Cylinder(Standard_Real R, Standard_Real H) {
		NativeHandle = new BRepPrim_Cylinder(R, H);
		SetRevolutionHandle(NativeHandle);
	};

	//! same as above but at a given point
	XBRepPrim_Cylinder::XBRepPrim_Cylinder(xgp_Pnt^ Center, Standard_Real R, Standard_Real H) {
		NativeHandle = new BRepPrim_Cylinder(Center->GetPnt(), R, H);
		SetRevolutionHandle(NativeHandle);
	};

	//! The surface normal should be directed  towards the
	//! outside.
	XTopoDS_Face^ XBRepPrim_Cylinder::MakeEmptyLateralFace() {
		TopoDS_Face* aFace = new TopoDS_Face(NativeHandle->MakeEmptyLateralFace());
		return gcnew XTopoDS_Face(aFace);
	};
}
