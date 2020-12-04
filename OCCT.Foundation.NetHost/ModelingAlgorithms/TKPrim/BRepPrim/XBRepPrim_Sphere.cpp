#include <XBRepPrim_Sphere.h>

namespace TKPrim {
	//! 
	XBRepPrim_Sphere::XBRepPrim_Sphere() {
		NativeHandle = new BRepPrim_Sphere(1.0);
		SetRevolutionHandle(NativeHandle);
	};

	XBRepPrim_Sphere::XBRepPrim_Sphere(BRepPrim_Sphere* handle) {
		NativeHandle = handle;
		SetRevolutionHandle(NativeHandle);
	};

	void XBRepPrim_Sphere::SetPrimSphereHandle(BRepPrim_Sphere* handle) {
		NativeHandle = handle;
		SetRevolutionHandle(NativeHandle);
	};

	BRepPrim_Sphere* XBRepPrim_Sphere::GetPrimSphere() {
		return NativeHandle;
	};

	BRepPrim_Revolution* XBRepPrim_Sphere::GetRevolution() {
		return NativeHandle;
	};

	BRepPrim_OneAxis* XBRepPrim_Sphere::GetOneAxis() {
		return NativeHandle;
	};

	//! Creates a Sphere at  origin with  Radius. The axes
	//! of the sphere are the  reference axes. An error is
	//! raised if the radius is < Resolution.
	XBRepPrim_Sphere::XBRepPrim_Sphere(Standard_Real Radius) {
		NativeHandle = new BRepPrim_Sphere(Radius);
		SetRevolutionHandle(NativeHandle);
	};

	//! Creates a Sphere with Center and Radius.  Axes are
	//! the   referrence    axes.   This    is the    STEP
	//! constructor.
	XBRepPrim_Sphere::XBRepPrim_Sphere(xgp_Pnt^ Center, Standard_Real Radius) {
		NativeHandle = new BRepPrim_Sphere(Center->GetPnt() ,Radius);
		SetRevolutionHandle(NativeHandle);
	};

	//! Creates a sphere with given axes system.
	XBRepPrim_Sphere::XBRepPrim_Sphere(xgp_Ax2^ Axes, Standard_Real Radius) {
		NativeHandle = new BRepPrim_Sphere(Axes->GetAx2(), Radius);
		SetRevolutionHandle(NativeHandle);
	};

	//! The surface normal should be directed  towards the
	//! outside.
	XTopoDS_Face^ XBRepPrim_Sphere::MakeEmptyLateralFace() {
		TopoDS_Face* aFace = new TopoDS_Face(NativeHandle->MakeEmptyLateralFace());
		return gcnew XTopoDS_Face(aFace);
	};
}

