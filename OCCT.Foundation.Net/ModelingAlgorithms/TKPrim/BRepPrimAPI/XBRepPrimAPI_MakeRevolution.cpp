#include <XBRepPrimAPI_MakeRevolution.h>

namespace TKPrim {

	XBRepPrimAPI_MakeRevolution::XBRepPrimAPI_MakeRevolution() {
		//NativeHandle = new BRepPrimAPI_MakeRevolution();
	};

	XBRepPrimAPI_MakeRevolution::XBRepPrimAPI_MakeRevolution(BRepPrimAPI_MakeRevolution* handle) {
		NativeHandle = handle;
		SetMakeOneAxisHandle(NativeHandle);
	};

	void XBRepPrimAPI_MakeRevolution::SetMakeRevolutionHandle(BRepPrimAPI_MakeRevolution* handle) {
		NativeHandle = handle;
		SetMakeOneAxisHandle(NativeHandle);
	};

	BRepPrimAPI_MakeRevolution* XBRepPrimAPI_MakeRevolution::GetMakeRevolution() {
		return NativeHandle;
	};

	BRepPrimAPI_MakeOneAxis* XBRepPrimAPI_MakeRevolution::GetMakeOneAxis() {
		return NativeHandle;
	};

	BRepBuilderAPI_MakeShape* XBRepPrimAPI_MakeRevolution::GetMakeShape() {
		return NativeHandle;
	};

	//! Make a revolution body by rotating a curve around Z.
	XBRepPrimAPI_MakeRevolution::XBRepPrimAPI_MakeRevolution(XGeom_Curve^ Meridian) {
		NativeHandle = new BRepPrimAPI_MakeRevolution(Meridian->GetCurve());
		SetMakeOneAxisHandle(NativeHandle);
	};

	//! Make a revolution body by rotating a curve around Z.
	XBRepPrimAPI_MakeRevolution::XBRepPrimAPI_MakeRevolution(XGeom_Curve^ Meridian, Standard_Real angle) {
		NativeHandle = new BRepPrimAPI_MakeRevolution(Meridian->GetCurve(), angle);
		SetMakeOneAxisHandle(NativeHandle);
	};

	//! Make a revolution body by rotating a curve around Z.
	XBRepPrimAPI_MakeRevolution::XBRepPrimAPI_MakeRevolution(XGeom_Curve^ Meridian, Standard_Real VMin, Standard_Real VMax) {
		NativeHandle = new BRepPrimAPI_MakeRevolution(Meridian->GetCurve(), VMin, VMax);
		SetMakeOneAxisHandle(NativeHandle);
	};

	//! Make a revolution body by rotating a curve around Z.
	XBRepPrimAPI_MakeRevolution::XBRepPrimAPI_MakeRevolution(XGeom_Curve^ Meridian, Standard_Real VMin, Standard_Real VMax, Standard_Real angle) {
		NativeHandle = new BRepPrimAPI_MakeRevolution(Meridian->GetCurve(), VMin, VMax, angle);
		SetMakeOneAxisHandle(NativeHandle);
	};

	//! Make a revolution body by rotating a curve around Z.
	XBRepPrimAPI_MakeRevolution::XBRepPrimAPI_MakeRevolution(xgp_Ax2^ Axes, XGeom_Curve^ Meridian) {
		NativeHandle = new BRepPrimAPI_MakeRevolution(*Axes->GetAx2(), Meridian->GetCurve());
		SetMakeOneAxisHandle(NativeHandle);
	};

	//! Make a revolution body by rotating a curve around Z.
	XBRepPrimAPI_MakeRevolution::XBRepPrimAPI_MakeRevolution(xgp_Ax2^ Axes, XGeom_Curve^ Meridian, Standard_Real angle) {
		NativeHandle = new BRepPrimAPI_MakeRevolution(*Axes->GetAx2(), Meridian->GetCurve(), angle);
		SetMakeOneAxisHandle(NativeHandle);
	};

	//! Make a revolution body by rotating a curve around Z.
	XBRepPrimAPI_MakeRevolution::XBRepPrimAPI_MakeRevolution(xgp_Ax2^ Axes, XGeom_Curve^ Meridian, Standard_Real VMin, Standard_Real VMax) {
		NativeHandle = new BRepPrimAPI_MakeRevolution(*Axes->GetAx2(), Meridian->GetCurve(), VMin, VMax);
		SetMakeOneAxisHandle(NativeHandle);
	};

	//! Make a revolution body by rotating a curve around Z.
	//! For all algorithms the resulting shape is composed of
	//! -   a lateral revolved face,
	//! -   two planar faces in planes parallel to the plane z =
	//! 0, and passing by the extremities of the revolved
	//! portion of Meridian, if these points are not on the Z
	//! axis (in case of a complete revolved shape, these faces are circles),
	//! -   and in the case of a portion of a revolved shape, two
	//! planar faces to close the shape (in the planes u = 0 and u = angle).
	XBRepPrimAPI_MakeRevolution::XBRepPrimAPI_MakeRevolution(xgp_Ax2^ Axes, XGeom_Curve^ Meridian, Standard_Real VMin, Standard_Real VMax, Standard_Real angle) {
		NativeHandle = new BRepPrimAPI_MakeRevolution(*Axes->GetAx2(), Meridian->GetCurve(), VMin, VMax, angle);
		SetMakeOneAxisHandle(NativeHandle);
	};

	//! Returns the algorithm.
	Object^ XBRepPrimAPI_MakeRevolution::OneAxis() {
		return XStandard_Helper::toObject(NativeHandle->OneAxis());
	};

	//! Returns the algorithm.
	XBRepPrim_Revolution^ XBRepPrimAPI_MakeRevolution::Revolution() {
		BRepPrim_Revolution* temp = new BRepPrim_Revolution(NativeHandle->Revolution());
		return gcnew XBRepPrim_Revolution(temp);
	};
}
