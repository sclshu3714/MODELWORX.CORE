#include <XBRepPrim_Wedge.h>

namespace TKPrim {


	XBRepPrim_Wedge::XBRepPrim_Wedge(BRepPrim_Wedge* handle) {
		NativeHandle = handle;
		SetGWedgeHandle(handle);
	};


	void XBRepPrim_Wedge::SetBRepPrimWedgeHandle(BRepPrim_Wedge* handle) {
		NativeHandle = handle;
		SetGWedgeHandle(handle);
	};


	BRepPrim_Wedge* XBRepPrim_Wedge::GetBRepPrimWedge() {
		return NativeHandle;
	};

	BRepPrim_GWedge* XBRepPrim_Wedge::GetGWedge() {
		return NativeHandle;
	};

	//! Creates a  Wedge  algorithm.   <Axes> is  the axis
	//! system for the primitive.
	//!
	//! XMin, YMin, ZMin are set to 0
	//! XMax, YMax, ZMax are set to dx, dy, dz
	//! Z2Min = ZMin
	//! Z2Max = ZMax
	//! X2Min = XMin
	//! X2Max = XMax
	//! The result is a box
	//! dx,dy,dz should be positive
	XBRepPrim_Wedge::XBRepPrim_Wedge(xgp_Ax2^ Axes, Standard_Real dx, Standard_Real dy, Standard_Real dz) {
		NativeHandle = new BRepPrim_Wedge(Axes->GetAx2(), dx, dy, dz);
		SetGWedgeHandle(NativeHandle);
	};

	//! Creates  a Wedge  primitive. <Axes> is   the  axis
	//! system for the primitive.
	//!
	//! XMin, YMin, ZMin are set to 0
	//! XMax, YMax, ZMax are set to dx, dy, dz
	//! Z2Min = ZMin
	//! Z2Max = ZMax
	//! X2Min = ltx
	//! X2Max = ltx
	//! The result is a STEP right angular wedge
	//! dx,dy,dz should be positive
	//! ltx should not be negative
	XBRepPrim_Wedge::XBRepPrim_Wedge(xgp_Ax2^ Axes, Standard_Real dx, Standard_Real dy, Standard_Real dz, Standard_Real ltx) {
		NativeHandle = new BRepPrim_Wedge(Axes->GetAx2(), dx, dy, dz, ltx);
		SetGWedgeHandle(NativeHandle);
	};

	//! Create  a Wedge primitive.   <Axes>  is  the  axis
	//! system for the primitive.
	//!
	//! all the fields are set to the corresponding value
	//! XYZMax - XYZMin should be positive
	//! ZX2Max - ZX2Min should not be negative
	XBRepPrim_Wedge::XBRepPrim_Wedge(xgp_Ax2^ Axes, Standard_Real xmin, Standard_Real ymin, Standard_Real zmin, Standard_Real z2min, Standard_Real x2min, Standard_Real xmax, Standard_Real ymax, Standard_Real zmax, Standard_Real z2max, Standard_Real x2max) {
		NativeHandle = new BRepPrim_Wedge(Axes->GetAx2(), xmin, ymin, zmin, z2min, x2min, xmax, ymax, zmax, z2max, x2max);
		SetGWedgeHandle(NativeHandle);
	};
}

