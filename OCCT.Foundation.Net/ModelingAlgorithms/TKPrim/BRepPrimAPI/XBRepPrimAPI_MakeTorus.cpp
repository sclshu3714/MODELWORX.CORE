#include <XBRepPrimAPI_MakeTorus.h>

namespace TKPrim {

	XBRepPrimAPI_MakeTorus::XBRepPrimAPI_MakeTorus() {

	};

	XBRepPrimAPI_MakeTorus::XBRepPrimAPI_MakeTorus(BRepPrimAPI_MakeTorus* handle) {
		NativeHandle = handle;
		SetMakeOneAxisHandle(NativeHandle);
	};

	void XBRepPrimAPI_MakeTorus::SetMakeTorusHandle(BRepPrimAPI_MakeTorus* handle) {
		NativeHandle = handle;
		SetMakeOneAxisHandle(NativeHandle);
	};

	BRepPrimAPI_MakeTorus* XBRepPrimAPI_MakeTorus::GetMakeTorus() {
		return NativeHandle;
	};

	BRepPrimAPI_MakeOneAxis* XBRepPrimAPI_MakeTorus::GetMakeOneAxis() {
		return NativeHandle;
	};

	BRepBuilderAPI_MakeShape* XBRepPrimAPI_MakeTorus::GetMakeShape() {
		return NativeHandle;
	};

	//! Make a torus of radii R1 R2.
	XBRepPrimAPI_MakeTorus::XBRepPrimAPI_MakeTorus(Standard_Real R1, Standard_Real R2) {
		NativeHandle = new BRepPrimAPI_MakeTorus(R1, R2);
		SetMakeOneAxisHandle(NativeHandle);
	};

	//! Make a section of a torus of radii R1 R2.
	XBRepPrimAPI_MakeTorus::XBRepPrimAPI_MakeTorus(Standard_Real R1, Standard_Real R2, Standard_Real angle) {
		NativeHandle = new BRepPrimAPI_MakeTorus(R1, R2, angle);
		SetMakeOneAxisHandle(NativeHandle);
	};

	//! Make  a torus of  radii R2, R2  with angles on the
	//! small circle.
	XBRepPrimAPI_MakeTorus::XBRepPrimAPI_MakeTorus(Standard_Real R1, Standard_Real R2, Standard_Real angle1, Standard_Real angle2) {
		NativeHandle = new BRepPrimAPI_MakeTorus(R1, R2, angle1, angle2);
		SetMakeOneAxisHandle(NativeHandle);
	};

	//! Make  a torus of  radii R2, R2  with angles on the
	//! small circle.
	XBRepPrimAPI_MakeTorus::XBRepPrimAPI_MakeTorus(Standard_Real R1, Standard_Real R2, Standard_Real angle1, Standard_Real angle2, Standard_Real angle) {
		NativeHandle = new BRepPrimAPI_MakeTorus(R1, R2, angle1, angle2, angle);
		SetMakeOneAxisHandle(NativeHandle);
	};

	//! Make a torus of radii R1 R2.
	XBRepPrimAPI_MakeTorus::XBRepPrimAPI_MakeTorus(xgp_Ax2^ Axes, Standard_Real R1, Standard_Real R2) {
		NativeHandle = new BRepPrimAPI_MakeTorus(*Axes->GetAx2(), R1, R2);
		SetMakeOneAxisHandle(NativeHandle);
	};

	//! Make a section of a torus of radii R1 R2.
	XBRepPrimAPI_MakeTorus::XBRepPrimAPI_MakeTorus(xgp_Ax2^ Axes, Standard_Real R1, Standard_Real R2, Standard_Real angle) {
		NativeHandle = new BRepPrimAPI_MakeTorus(*Axes->GetAx2(), R1, R2, angle);
		SetMakeOneAxisHandle(NativeHandle);
	};

	//! Make a torus of radii R1 R2.
	XBRepPrimAPI_MakeTorus::XBRepPrimAPI_MakeTorus(xgp_Ax2^ Axes, Standard_Real R1, Standard_Real R2, Standard_Real angle1, Standard_Real angle2) {
		NativeHandle = new BRepPrimAPI_MakeTorus(*Axes->GetAx2(), R1, R2, angle1, angle2);
		SetMakeOneAxisHandle(NativeHandle);
	};

	//! Make a section of a torus of radii R1 R2.
	//! For all algorithms The resulting shape is composed of
	//! -      a lateral toroidal face,
	//! -      two conical faces (defined  by the equation v = angle1 and
	//! v = angle2) if the sphere is truncated in the v parametric
	//! direction (they may be cylindrical faces in some
	//! particular conditions), and in case of a portion
	//! of torus, two planar faces to close the shape.(in the planes
	//! u = 0 and u = angle).
	//! Notes:
	//! -      The u parameter corresponds to a rotation angle around the Z axis.
	//! -      The circle whose radius is equal to the minor radius,
	//! located in the plane defined by the X axis and the Z axis,
	//! centered on the X axis, on its positive side, and positioned
	//! at a distance from the origin equal to the major radius, is
	//! the reference circle of the torus. The rotation around an
	//! axis parallel to the Y axis and passing through the center
	//! of the reference circle gives the v parameter on the
	//! reference circle. The X axis gives the origin of the v
	//! parameter. Near 0, as v increases, the Z coordinate decreases.
	XBRepPrimAPI_MakeTorus::XBRepPrimAPI_MakeTorus(xgp_Ax2^ Axes, Standard_Real R1, Standard_Real R2, Standard_Real angle1, Standard_Real angle2, Standard_Real angle) {
		NativeHandle = new BRepPrimAPI_MakeTorus(*Axes->GetAx2(), R1, R2, angle1, angle2, angle1);
		SetMakeOneAxisHandle(NativeHandle);
	};

	//! Returns the algorithm.
	Object^ XBRepPrimAPI_MakeTorus::OneAxis() {
		return XStandard_Helper::toObject(NativeHandle->OneAxis());
	};

	//! Returns the algorithm.
	XBRepPrim_Torus^ XBRepPrimAPI_MakeTorus::Torus() {
		BRepPrim_Torus* temp = new BRepPrim_Torus(NativeHandle->Torus());
		return gcnew XBRepPrim_Torus(temp);
	};
}