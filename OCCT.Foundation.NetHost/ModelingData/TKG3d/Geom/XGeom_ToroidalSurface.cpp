#include <XGeom_ToroidalSurface.h>
namespace TKG3d {
	//!
	XGeom_ToroidalSurface::XGeom_ToroidalSurface(void) {
		/*NativeHandle() = new Geom_ToroidalSurface();
		SetElementarySurfaceHandle(NativeHandle());*/
	};

	//! 
	XGeom_ToroidalSurface::XGeom_ToroidalSurface(Handle(Geom_ToroidalSurface) pos) {
		NativeHandle() = pos;
		SetElementarySurfaceHandle(NativeHandle());
	};

	//!
	XGeom_ToroidalSurface::~XGeom_ToroidalSurface() {
		NativeHandle() = NULL;
		SetElementarySurfaceHandle(NativeHandle());
	};

	void XGeom_ToroidalSurface::SetToroidalSurfaceHandle(Handle(Geom_ToroidalSurface) handle) {
		NativeHandle() = handle;
		SetElementarySurfaceHandle(NativeHandle());
	};

	//! 
	Handle(Geom_ToroidalSurface) XGeom_ToroidalSurface::GetToroidalSurface() {
		return NativeHandle();
	};

	//! 
	Handle(Geom_ElementarySurface) XGeom_ToroidalSurface::GetElementarySurface() {
		return NativeHandle();
	};

	//!
	Handle(Geom_Surface) XGeom_ToroidalSurface::GetSurface() {
		return NativeHandle();
	};

	//!
	Handle(Geom_Geometry) XGeom_ToroidalSurface::GetGeometry() {
		return NativeHandle();
	};

	//! A3 is the local coordinate system of the surface.
	//! The orientation of increasing V parametric value is defined
	//! by the rotation around the main axis (ZAxis) in the
	//! trigonometric sense. The parametrization of the surface in the
	//! U direction is defined such as the normal Vector (N = D1U ^ D1V)
	//! is oriented towards the "outside region" of the surface.
	//! Warnings :
	//! It is not forbidden to create a toroidal surface with
	//! MajorRadius = MinorRadius = 0.0
	//!
	//! Raised if MinorRadius < 0.0 or if MajorRadius < 0.0
	XGeom_ToroidalSurface::XGeom_ToroidalSurface(xgp_Ax3^ A3, Standard_Real MajorRadius, Standard_Real MinorRadius) {
		NativeHandle() = new Geom_ToroidalSurface(*A3->GetAx3(), MajorRadius, MinorRadius);
		SetElementarySurfaceHandle(NativeHandle());
	};


	//! Creates a ToroidalSurface from a non transient Torus from
	//! package gp.
	XGeom_ToroidalSurface::XGeom_ToroidalSurface(xgp_Torus^ T) {
		NativeHandle() = new Geom_ToroidalSurface(*T->GetTorus());
		SetElementarySurfaceHandle(NativeHandle());
	};

	//! Modifies this torus by changing its major radius.
	//! Exceptions
	//! Standard_ConstructionError if:
	//! - MajorRadius is negative, or
	//! - MajorRadius - r is less than or equal to
	//! gp::Resolution(), where r is the minor radius of this torus.
	void XGeom_ToroidalSurface::SetMajorRadius(Standard_Real MajorRadius) {
		NativeHandle()->SetMajorRadius(MajorRadius);
	};

	//! Modifies this torus by changing its minor radius.
	//! Exceptions
	//! Standard_ConstructionError if:
	//! - MinorRadius is negative, or
	//! - R - MinorRadius is less than or equal to
	//! gp::Resolution(), where R is the major radius of this torus.
	void XGeom_ToroidalSurface::SetMinorRadius(Standard_Real MinorRadius) {
		NativeHandle()->SetMinorRadius(MinorRadius);
	};

	//! Converts the gp_Torus torus T into this torus.
	void XGeom_ToroidalSurface::SetTorus(xgp_Torus^ T) {
		NativeHandle()->SetTorus(*T->GetTorus());
	};


	//! Returns the non transient torus with the same geometric
	//! properties as <me>.
	xgp_Torus^ XGeom_ToroidalSurface::Torus() {
		gp_Torus* temp = new gp_Torus(NativeHandle()->Torus());
		return gcnew xgp_Torus(temp);
	};

	//! Return the  parameter on the  Ureversed surface for
	//! the point of parameter U on <me>.
	//! Return 2.PI - U.
	Standard_Real XGeom_ToroidalSurface::UReversedParameter(Standard_Real U) {
		return NativeHandle()->UReversedParameter(U);
	};

	//! Return the  parameter on the  Ureversed surface for
	//! the point of parameter U on <me>.
	//! Return 2.PI - U.
	Standard_Real XGeom_ToroidalSurface::VReversedParameter(Standard_Real U) {
		return NativeHandle()->VReversedParameter(U);
	};

	//! Computes the aera of the surface.
	Standard_Real XGeom_ToroidalSurface::Area() {
		return NativeHandle()->Area();
	};

	//! Returns the parametric bounds U1, U2, V1 and V2 of this torus.
	//! For a torus: U1 = V1 = 0 and U2 = V2 = 2*PI .
	void XGeom_ToroidalSurface::Bounds(Standard_Real% U1, Standard_Real% U2, Standard_Real% V1, Standard_Real% V2) {
		Standard_Real XU1 = Standard_Real(U1); Standard_Real XU2 = Standard_Real(U2); Standard_Real XV1 = Standard_Real(V1); Standard_Real XV2 = Standard_Real(V2);
		NativeHandle()->Bounds(XU1, XU2, XV1, XV2);
		U1 = XU1; U2 = XU2; V1 = XV1; V2 = XV2;
	};


	//! Returns the coefficients of the implicit equation of the surface
	//! in the absolute cartesian coordinate system :
	//! Coef(1) * X**4 + Coef(2) * Y**4 + Coef(3) * Z**4 +
	//! Coef(4) * X**3 * Y + Coef(5) * X**3 * Z + Coef(6) * Y**3 * X +
	//! Coef(7) * Y**3 * Z + Coef(8) * Z**3 * X + Coef(9) * Z**3 * Y +
	//! Coef(10) * X**2 * Y**2 + Coef(11) * X**2 * Z**2 +
	//! Coef(12) * Y**2 * Z**2 + Coef(13) * X**3 + Coef(14) * Y**3 +
	//! Coef(15) * Z**3 + Coef(16) * X**2 * Y + Coef(17) * X**2 * Z +
	//! Coef(18) * Y**2 * X + Coef(19) * Y**2 * Z + Coef(20) * Z**2 * X +
	//! Coef(21) * Z**2 * Y + Coef(22) * X**2 + Coef(23) * Y**2 +
	//! Coef(24) * Z**2 + Coef(25) * X * Y + Coef(26) * X * Z +
	//! Coef(27) * Y * Z + Coef(28) * X + Coef(29) * Y + Coef(30) *  Z +
	//! Coef(31) = 0.0
	//! Raised if the length of Coef is lower than 31.
	void XGeom_ToroidalSurface::Coefficients(array<Standard_Real>^ Coef) {
		TColStd_Array1OfReal XCoef;
		for (Standard_Integer i = 0; i < Coef->Length; i++) {
			const Standard_Real XReal = (Standard_Real)Coef->GetValue(i);
			XCoef.SetValue(i, XReal);
		}
		NativeHandle()->Coefficients(XCoef);
	};

	//! Returns the major radius, or the minor radius, of this torus.
	Standard_Real XGeom_ToroidalSurface::MajorRadius() {
		return NativeHandle()->MajorRadius();
	};

	//! Returns the major radius, or the minor radius, of this torus.
	Standard_Real XGeom_ToroidalSurface::MinorRadius() {
		return NativeHandle()->MinorRadius();
	};

	//! Computes the volume.
	Standard_Real XGeom_ToroidalSurface::Volume() {
		return NativeHandle()->Volume();
	};

	//! Returns True.
	Standard_Boolean XGeom_ToroidalSurface::IsUClosed() {
		return NativeHandle()->IsUClosed();
	};

	//! Returns True.
	Standard_Boolean XGeom_ToroidalSurface::IsVClosed() {
		return NativeHandle()->IsVClosed();
	};

	//! Returns True.
	Standard_Boolean XGeom_ToroidalSurface::IsUPeriodic() {
		return NativeHandle()->IsUPeriodic();
	};

	//! Returns True.
	Standard_Boolean XGeom_ToroidalSurface::IsVPeriodic() {
		return NativeHandle()->IsVPeriodic();
	};

	//! Computes the U isoparametric curve.
	//!
	//! For a toroidal surface the UIso curve is a circle.
	//! The center of the Uiso circle is at the distance MajorRadius
	//! from the location point of the toroidal surface.
	//! Warnings :
	//! The radius of the circle can be zero if for the surface
	//! MinorRadius = 0.0
	XGeom_Curve^ XGeom_ToroidalSurface::UIso(Standard_Real U) {
		return gcnew XGeom_Curve(NativeHandle()->UIso(U));
	};

	//! Computes the V isoparametric curve.
	//!
	//! For a ToroidalSurface the VIso curve is a circle.
	//! The axis of the circle is the main axis (ZAxis) of the
	//! toroidal  surface.
	//! Warnings :
	//! The radius of the circle can be zero if for the surface
	//! MajorRadius = MinorRadius
	XGeom_Curve^ XGeom_ToroidalSurface::VIso(Standard_Real V) {
		return gcnew XGeom_Curve(NativeHandle()->VIso(V));
	};


	//! Computes the  point P (U, V) on the surface.
	//! P (U, V) = Loc + MinorRadius * Sin (V) * Zdir +
	//! (MajorRadius + MinorRadius * Cos(V)) *
	//! (cos (U) * XDir + sin (U) * YDir)
	//! where Loc is the origin of the placement plane (XAxis, YAxis)
	//! XDir is the direction of the XAxis and YDir the direction of
	//! the YAxis and ZDir the direction of the ZAxis.
	void XGeom_ToroidalSurface::D0(Standard_Real U, Standard_Real V, xgp_Pnt^ P) {
		NativeHandle()->D0(U, V, *P->GetPnt());
	};


	//! Computes the current point and the first derivatives in
	//! the directions U and V.
	void XGeom_ToroidalSurface::D1(Standard_Real U, Standard_Real V, xgp_Pnt^ P, xgp_Vec^ D1U, xgp_Vec^ D1V) {
		NativeHandle()->D1(U, V, *P->GetPnt(), *D1U->GetVec(), *D1V->GetVec());
	};


	//! Computes the current point, the first and the second derivatives
	//! in the directions U and V.
	void XGeom_ToroidalSurface::D2(Standard_Real U, Standard_Real V, xgp_Pnt^ P, xgp_Vec^ D1U, xgp_Vec^ D1V, xgp_Vec^ D2U, xgp_Vec^ D2V, xgp_Vec^ D2UV) {
		NativeHandle()->D2(U, V, *P->GetPnt(), *D1U->GetVec(), *D1V->GetVec(), *D2U->GetVec(), *D2V->GetVec(), *D2UV->GetVec());
	};


	//! Computes the current point, the first,the second and the
	//! third derivatives in the directions U and V.
	void XGeom_ToroidalSurface::D3(Standard_Real U, Standard_Real V, xgp_Pnt^ P, xgp_Vec^ D1U, xgp_Vec^ D1V, xgp_Vec^ D2U, xgp_Vec^ D2V, xgp_Vec^ D2UV, xgp_Vec^ D3U, xgp_Vec^ D3V, xgp_Vec^ D3UUV, xgp_Vec^ D3UVV) {
		NativeHandle()->D3(U, V, *P->GetPnt(), *D1U->GetVec(), *D1V->GetVec(), *D2U->GetVec(), *D2V->GetVec(), *D2UV->GetVec(), *D3U->GetVec(), *D3V->GetVec(), *D3UUV->GetVec(), *D3UVV->GetVec());
	};


	//! Computes the derivative of order Nu in the direction u and
	//! Nv in the direction v.
	//! Raised if Nu + Nv < 1 or Nu < 0 or Nv < 0.
	xgp_Vec^ XGeom_ToroidalSurface::DN(Standard_Real U, Standard_Real V, Standard_Integer Nu, Standard_Integer Nv) {
		gp_Vec* temp = new gp_Vec(NativeHandle()->DN(U, V, Nu, Nv));
		return gcnew xgp_Vec(temp);
	};

	//! Applies the transformation T to this torus.
	void XGeom_ToroidalSurface::Transform(xgp_Trsf^ T) {
		NativeHandle()->Transform(*T->GetTrsf());
	};

	//! Creates a new object which is a copy of this torus.
	XGeom_Geometry^ XGeom_ToroidalSurface::Copy() {
		return gcnew XGeom_Geometry(NativeHandle()->Copy());
	};
}
