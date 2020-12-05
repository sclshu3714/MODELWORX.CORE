#include <XBRepPrimAPI_MakeCylinder.h>

namespace TKPrim {

	XBRepPrimAPI_MakeCylinder::XBRepPrimAPI_MakeCylinder() {
		//NativeHandle = new BRepPrimAPI_MakeCylinder();
	};

	XBRepPrimAPI_MakeCylinder::XBRepPrimAPI_MakeCylinder(BRepPrimAPI_MakeCylinder* handle) {
		NativeHandle = handle;
		SetMakeOneAxisHandle(NativeHandle);
	};

	void XBRepPrimAPI_MakeCylinder::SetMakeCylinderHandle(BRepPrimAPI_MakeCylinder* handle) {
		NativeHandle = handle;
		SetMakeOneAxisHandle(NativeHandle);
	};

	BRepPrimAPI_MakeCylinder* XBRepPrimAPI_MakeCylinder::GetMakeCylinder() {
		return NativeHandle;
	};

	BRepPrimAPI_MakeOneAxis* XBRepPrimAPI_MakeCylinder::GetMakeOneAxis() {
		return NativeHandle;
	};

	BRepBuilderAPI_MakeShape* XBRepPrimAPI_MakeCylinder::GetMakeShape() {
		return NativeHandle;
	};

	//! Make a cylinder of radius R and length H.
	XBRepPrimAPI_MakeCylinder::XBRepPrimAPI_MakeCylinder(Standard_Real R, Standard_Real H) {
		NativeHandle = new BRepPrimAPI_MakeCylinder(R, H);
		SetMakeOneAxisHandle(NativeHandle);
	};

	//! Make a cylinder   of  radius R  and  length H with
	//! angle  H.
	XBRepPrimAPI_MakeCylinder::XBRepPrimAPI_MakeCylinder(Standard_Real R, Standard_Real H, Standard_Real Angle) {
		NativeHandle = new BRepPrimAPI_MakeCylinder(R, H, Angle);
		SetMakeOneAxisHandle(NativeHandle);
	};

	//! Make a cylinder of radius R and length H.
	XBRepPrimAPI_MakeCylinder::XBRepPrimAPI_MakeCylinder(xgp_Ax2^ Axes, Standard_Real R, Standard_Real H) {
		NativeHandle = new BRepPrimAPI_MakeCylinder(*Axes->GetAx2(), R, H);
		SetMakeOneAxisHandle(NativeHandle);
	};

	//! Make a cylinder   of  radius R  and  length H with
	//! angle  H.
	//! Constructs
	//! -   a cylinder of radius R and height H, or
	//! -   a portion of cylinder of radius R and height H, and of
	//! the angle Angle defining the missing portion of the cylinder.
	//! The cylinder is constructed about the "Z Axis" of either:
	//! -   the global coordinate system, or
	//! -   the local coordinate system Axes.
	//! It is limited in this coordinate system as follows:
	//! -   in the v parametric direction (the Z axis), by the two
	//! parameter values 0 and H,
	//! -   and in the u parametric direction (the rotation angle
	//! around the Z Axis), in the case of a portion of a
	//! cylinder, by the two parameter values 0 and Angle.
	//! Angle is given in radians.
	//! The resulting shape is composed of:
	//! -   a lateral cylindrical face,
	//! -   two planar faces in the planes z = 0 and z = H
	//! (in the case of a complete cylinder, these faces are circles), and
	//! -   in case of a portion of a cylinder, two additional
	//! planar faces to close the shape.(two rectangles in the
	//! planes u = 0 and u = Angle).
	//! Exceptions Standard_DomainError if:
	//! -   R is less than or equal to Precision::Confusion(), or
	//! -   H is less than or equal to Precision::Confusion().
	XBRepPrimAPI_MakeCylinder::XBRepPrimAPI_MakeCylinder(xgp_Ax2^ Axes, Standard_Real R, Standard_Real H, Standard_Real Angle) {
		NativeHandle = new BRepPrimAPI_MakeCylinder(*Axes->GetAx2(), R, H, Angle);
		SetMakeOneAxisHandle(NativeHandle);
	};

	//! Returns the algorithm.
	Object^ XBRepPrimAPI_MakeCylinder::OneAxis() {
		return XStandard_Helper::toObject(NativeHandle->OneAxis());
	};

	//! Returns the algorithm.
	XBRepPrim_Cylinder^ XBRepPrimAPI_MakeCylinder::Cylinder() {
		BRepPrim_Cylinder* aCylinder = new BRepPrim_Cylinder(NativeHandle->Cylinder());
		return gcnew XBRepPrim_Cylinder(aCylinder);
	};
}



