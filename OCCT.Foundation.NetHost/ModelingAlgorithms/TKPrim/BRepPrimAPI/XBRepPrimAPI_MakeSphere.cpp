#include <XBRepPrimAPI_MakeSphere.h>

namespace TKPrim {

	XBRepPrimAPI_MakeSphere::XBRepPrimAPI_MakeSphere() {
		//NativeHandle = new BRepPrimAPI_MakeSphere();
	};

	XBRepPrimAPI_MakeSphere::XBRepPrimAPI_MakeSphere(BRepPrimAPI_MakeSphere* handle) {
		NativeHandle = handle;
		SetMakeOneAxisHandle(NativeHandle);
	};

	void XBRepPrimAPI_MakeSphere::SetMakeSphereHandle(BRepPrimAPI_MakeSphere* handle) {
		NativeHandle = handle;
		SetMakeOneAxisHandle(NativeHandle);
	};

	BRepPrimAPI_MakeSphere* XBRepPrimAPI_MakeSphere::GetMakeSphere() {
		return NativeHandle;
	};

	BRepPrimAPI_MakeOneAxis* XBRepPrimAPI_MakeSphere::GetMakeOneAxis() {
		return NativeHandle;
	};

	BRepBuilderAPI_MakeShape* XBRepPrimAPI_MakeSphere::GetMakeShape() {
		return NativeHandle;
	};

	//! Make a sphere of radius R.
	XBRepPrimAPI_MakeSphere::XBRepPrimAPI_MakeSphere(Standard_Real R) {
		NativeHandle = new BRepPrimAPI_MakeSphere(R);
		SetMakeOneAxisHandle(NativeHandle);
	};

	//! Make a sphere of radius R.
	XBRepPrimAPI_MakeSphere::XBRepPrimAPI_MakeSphere(Standard_Real R, Standard_Real angle) {
		NativeHandle = new BRepPrimAPI_MakeSphere(R, angle);
		SetMakeOneAxisHandle(NativeHandle);
	};

	//! Make a sphere of radius R.
	XBRepPrimAPI_MakeSphere::XBRepPrimAPI_MakeSphere(Standard_Real R, Standard_Real angle1, Standard_Real angle2) {
		NativeHandle = new BRepPrimAPI_MakeSphere(R, angle1, angle2);
		SetMakeOneAxisHandle(NativeHandle);
	};

	//! Make a sphere of radius R.
	XBRepPrimAPI_MakeSphere::XBRepPrimAPI_MakeSphere(Standard_Real R, Standard_Real angle1, Standard_Real angle2, Standard_Real angle3) {
		NativeHandle = new BRepPrimAPI_MakeSphere(R, angle1, angle2, angle3);
		SetMakeOneAxisHandle(NativeHandle);
	};

	//! Make a sphere of radius R.
	XBRepPrimAPI_MakeSphere::XBRepPrimAPI_MakeSphere(xgp_Pnt^ Center, Standard_Real R) {
		NativeHandle = new BRepPrimAPI_MakeSphere(*Center->GetPnt(), R);
		SetMakeOneAxisHandle(NativeHandle);
	};

	//! Make a sphere of radius R.
	XBRepPrimAPI_MakeSphere::XBRepPrimAPI_MakeSphere(xgp_Pnt^ Center, Standard_Real R, Standard_Real angle) {
		NativeHandle = new BRepPrimAPI_MakeSphere(*Center->GetPnt(), R, angle);
		SetMakeOneAxisHandle(NativeHandle);
	};

	//! Make a sphere of radius R.
	XBRepPrimAPI_MakeSphere::XBRepPrimAPI_MakeSphere(xgp_Pnt^ Center, Standard_Real R, Standard_Real angle1, Standard_Real angle2) {
		NativeHandle = new BRepPrimAPI_MakeSphere(*Center->GetPnt(), R, angle1, angle2);
		SetMakeOneAxisHandle(NativeHandle);
	};

	//! Make a sphere of radius R.
	XBRepPrimAPI_MakeSphere::XBRepPrimAPI_MakeSphere(xgp_Pnt^ Center, Standard_Real R, Standard_Real angle1, Standard_Real angle2, Standard_Real angle3) {
		NativeHandle = new BRepPrimAPI_MakeSphere(*Center->GetPnt(), R, angle1, angle2, angle3);
		SetMakeOneAxisHandle(NativeHandle);
	};

	//! Make a sphere of radius R.
	XBRepPrimAPI_MakeSphere::XBRepPrimAPI_MakeSphere(xgp_Ax2^ Axis, Standard_Real R) {
		NativeHandle = new BRepPrimAPI_MakeSphere(*Axis->GetAx2(), R);
		SetMakeOneAxisHandle(NativeHandle);
	};

	//! Make a sphere of radius R.
	XBRepPrimAPI_MakeSphere::XBRepPrimAPI_MakeSphere(xgp_Ax2^ Axis, Standard_Real R, Standard_Real angle) {
		NativeHandle = new BRepPrimAPI_MakeSphere(*Axis->GetAx2(), R, angle);
		SetMakeOneAxisHandle(NativeHandle);
	};

	//! Make a sphere of radius R.
	XBRepPrimAPI_MakeSphere::XBRepPrimAPI_MakeSphere(xgp_Ax2^ Axis, Standard_Real R, Standard_Real angle1, Standard_Real angle2) {
		NativeHandle = new BRepPrimAPI_MakeSphere(*Axis->GetAx2(), R, angle1, angle2);
		SetMakeOneAxisHandle(NativeHandle);
	};

	//! Make a sphere of radius R.
	//! For all algorithms The resulting shape is composed of
	//! -   a lateral spherical face,
	//! -   two planar faces parallel to the plane z = 0 if the
	//! sphere is truncated in the v parametric direction, or
	//! only one planar face if angle1 is equal to -p/2 or if
	//! angle2 is equal to p/2 (these faces are circles in
	//! case of a complete truncated sphere),
	//! -   and in case of a portion of sphere, two planar faces
	//! to shut the shape.(in the planes u = 0 and u = angle).
	XBRepPrimAPI_MakeSphere::XBRepPrimAPI_MakeSphere(xgp_Ax2^ Axis, Standard_Real R, Standard_Real angle1, Standard_Real angle2, Standard_Real angle3) {
		NativeHandle = new BRepPrimAPI_MakeSphere(*Axis->GetAx2(), R, angle1, angle2, angle3);
		SetMakeOneAxisHandle(NativeHandle);
	};

	//! Returns the algorithm.
	Object^ XBRepPrimAPI_MakeSphere::OneAxis() {
		return XStandard_Helper::toObject(NativeHandle->OneAxis());
	};

	//! Returns the algorithm.
	XBRepPrim_Sphere^ XBRepPrimAPI_MakeSphere::Sphere() {
		BRepPrim_Sphere* temp = new BRepPrim_Sphere(NativeHandle->Sphere());
		return gcnew XBRepPrim_Sphere(temp);
	};
}