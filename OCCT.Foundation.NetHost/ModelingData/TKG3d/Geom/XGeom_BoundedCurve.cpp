#include <XGeom_BoundedCurve.h> 
namespace TKG3d {

	XGeom_BoundedCurve::XGeom_BoundedCurve() {
		//NativeHandle() = new Geom_BoundedCurve();
	};

	//! 
	XGeom_BoundedCurve::XGeom_BoundedCurve(Handle(Geom_BoundedCurve) pos) {
		NativeHandle() = pos;
		SetCurveHandle(NativeHandle());
	};

	//!
	XGeom_BoundedCurve::~XGeom_BoundedCurve() {
		NativeHandle() = NULL;
		SetCurveHandle(NativeHandle());
	};

	void XGeom_BoundedCurve::SetBoundedCurveHandle(Handle(Geom_BoundedCurve) pos) {
		NativeHandle() = pos;
		SetCurveHandle(NativeHandle());
	};

	//!
	Handle(Geom_BoundedCurve) XGeom_BoundedCurve::GetBoundedCurve() {
		return NativeHandle();
	};

	//!
	Handle(Geom_Curve) XGeom_BoundedCurve::GetCurve() {
		return NativeHandle();
	};

	//!
	Handle(Geom_Geometry) XGeom_BoundedCurve::GetGeometry() {
		return NativeHandle();
	};

	//! Returns the end point of the curve.
	xgp_Pnt^ XGeom_BoundedCurve::EndPoint() {
		gp_Pnt* temp = new gp_Pnt(NativeHandle()->EndPoint());
		return gcnew xgp_Pnt(temp);
	};

	//! Returns the start point of the curve.
	xgp_Pnt^ XGeom_BoundedCurve::StartPoint() {
		gp_Pnt* temp = new gp_Pnt(NativeHandle()->StartPoint());
		return gcnew xgp_Pnt(temp);
	};
}