#include <XGeom_SphericalSurface.h>
namespace TKG3d {
	//!
	XGeom_SphericalSurface::XGeom_SphericalSurface(void) {
		/*NativeHandle() = new Geom_SphericalSurface();
		SetElementarySurfaceHandle(NativeHandle());*/
	};

	//! 
	XGeom_SphericalSurface::XGeom_SphericalSurface(Handle(Geom_SphericalSurface) pos) {
		NativeHandle() = pos;
		SetElementarySurfaceHandle(NativeHandle());
	};

	//!
	XGeom_SphericalSurface::~XGeom_SphericalSurface() {
		NativeHandle() = NULL;
		SetElementarySurfaceHandle(NativeHandle());
	};

	void XGeom_SphericalSurface::SetSphericalSurfaceHandle(Handle(Geom_SphericalSurface) handle) {
		NativeHandle() = handle;
		SetElementarySurfaceHandle(NativeHandle());
	};

	//! 
	Handle(Geom_SphericalSurface) XGeom_SphericalSurface::GetSphericalSurface() {
		return NativeHandle();
	};

	//! 
	Handle(Geom_ElementarySurface) XGeom_SphericalSurface::GetElementarySurface() {
		return NativeHandle();
	};

	//!
	Handle(Geom_Surface) XGeom_SphericalSurface::GetSurface() {
		return NativeHandle();
	};

	//!
	Handle(Geom_Geometry) XGeom_SphericalSurface::GetGeometry() {
		return NativeHandle();
	};

	//! A3 is the local coordinate system of the surface.
	//! At the creation the parametrization of the surface is defined
	//! such as the normal Vector (N = D1U ^ D1V) is directed away from
	//! the center of the sphere.
	//! The direction of increasing parametric value V is defined by the
	//! rotation around the "YDirection" of A2 in the trigonometric sense
	//! and the orientation of increasing parametric value U is defined
	//! by the rotation around the main direction of A2 in the
	//! trigonometric sense.
	//! Warnings :
	//! It is not forbidden to create a spherical surface with
	//! Radius = 0.0
	//! Raised if Radius < 0.0.
	XGeom_SphericalSurface::XGeom_SphericalSurface(xgp_Ax3^ A3, Standard_Real Radius) {
		NativeHandle() = new Geom_SphericalSurface(*A3->GetAx3(), Radius);
		SetElementarySurfaceHandle(NativeHandle());
	};


	//! Creates a SphericalSurface from a non persistent Sphere from
	//! package gp.
	XGeom_SphericalSurface::XGeom_SphericalSurface(xgp_Sphere^ S) {
		NativeHandle() = new Geom_SphericalSurface(*S->GetSphere());
		SetElementarySurfaceHandle(NativeHandle());
	};

	//! Assigns the value R to the radius of this sphere.
	//! Exceptions Standard_ConstructionError if R is less than 0.0.
	void XGeom_SphericalSurface::SetRadius(Standard_Real R) {
		NativeHandle()->SetRadius(R);
	};

	//! Converts the gp_Sphere S into this sphere.
	void XGeom_SphericalSurface::SetSphere(xgp_Sphere^ S) {
		NativeHandle()->SetSphere(*S->GetSphere());
	};

	//! Returns a non persistent sphere with the same geometric
	//! properties as <me>.
	xgp_Sphere^ XGeom_SphericalSurface::Sphere() {
		gp_Sphere* temp = new gp_Sphere(NativeHandle()->Sphere());
		return gcnew xgp_Sphere(temp);
	};

	//! Computes the u parameter on the modified
	//! surface, when reversing its u  parametric
	//! direction, for any point of u parameter U on this sphere.
	//! In the case of a sphere, these functions returns 2.PI - U.
	Standard_Real XGeom_SphericalSurface::UReversedParameter(Standard_Real U) {
		return NativeHandle()->UReversedParameter(U);
	};

	//! Computes the v parameter on the modified
	//! surface, when reversing its v parametric
	//! direction, for any point of v parameter V on this sphere.
	//! In the case of a sphere, these functions returns   -U.
	Standard_Real XGeom_SphericalSurface::VReversedParameter(Standard_Real V) {
		return NativeHandle()->VReversedParameter(V);
	};

	//! Computes the aera of the spherical surface.
	Standard_Real XGeom_SphericalSurface::Area() {
		return NativeHandle()->Area();
	};

	//! Returns the parametric bounds U1, U2, V1 and V2 of this sphere.
	//! For a sphere: U1 = 0, U2 = 2*PI, V1 = -PI/2, V2 = PI/2.
	void XGeom_SphericalSurface::Bounds(Standard_Real% U1, Standard_Real% U2, Standard_Real% V1, Standard_Real% V2) {
		Standard_Real XU1 = Standard_Real(U1); Standard_Real XU2 = Standard_Real(U2); Standard_Real XV1 = Standard_Real(V1); Standard_Real XV2 = Standard_Real(V2);
		NativeHandle()->Bounds(XU1, XU2, XV1, XV2);
		U1 = XU1; U2 = XU2; V1 = XV1; V2 = XV2;
	};

	//! Returns the coefficients of the implicit equation of the
	//! quadric in the absolute cartesian coordinates system :
	//! These coefficients are normalized.
	//! A1.X**2 + A2.Y**2 + A3.Z**2 + 2.(B1.X.Y + B2.X.Z + B3.Y.Z) +
	//! 2.(C1.X + C2.Y + C3.Z) + D = 0.0
	void XGeom_SphericalSurface::Coefficients(Standard_Real% A1, Standard_Real% A2, Standard_Real% A3, Standard_Real% B1, Standard_Real% B2, Standard_Real% B3, Standard_Real% C1, Standard_Real% C2, Standard_Real% C3, Standard_Real% D) {
		Standard_Real XA1(A1); Standard_Real XA2(A2); Standard_Real XA3(A3);
		Standard_Real XB1(B1); Standard_Real XB2(B2); Standard_Real XB3(B3);
		Standard_Real XC1(C1); Standard_Real XC2(C2); Standard_Real XC3(C3);
		Standard_Real XD(D);
		NativeHandle()->Coefficients(XA1, XA2, XA3, XB1, XB2, XB3, XC1, XC2,XC3, XD);
		A1 = XA1; A2 = XA2; A3 = XA3; B1 = XB1; B2 = XB2; B3 = XB3; C1 = XC1; C2 = XC2; C3 = XC3; D = XD;
	};

	//! Computes the coefficients of the implicit equation of
	//! this quadric in the absolute Cartesian coordinate system:
	//! A1.X**2 + A2.Y**2 + A3.Z**2 + 2.(B1.X.Y + B2.X.Z + B3.Y.Z) +
	//! 2.(C1.X + C2.Y + C3.Z) + D = 0.0
	//! An implicit normalization is applied (i.e. A1 = A2 = 1.
	//! in the local coordinate system of this sphere).
	Standard_Real XGeom_SphericalSurface::Radius() {
		return NativeHandle()->Radius();
	};

	//! Computes the volume of the spherical surface.
	Standard_Real XGeom_SphericalSurface::Volume() {
		return NativeHandle()->Volume();
	};

	//! Returns True.
	Standard_Boolean XGeom_SphericalSurface::IsUClosed() {
		return NativeHandle()->IsUClosed();
	};

	//! Returns False.
	Standard_Boolean XGeom_SphericalSurface::IsVClosed() {
		return NativeHandle()->IsVClosed();
	};

	//! Returns True.
	Standard_Boolean XGeom_SphericalSurface::IsUPeriodic() {
		return NativeHandle()->IsUPeriodic();
	};

	//! Returns False.
	Standard_Boolean XGeom_SphericalSurface::IsVPeriodic() {
		return NativeHandle()->IsVPeriodic();
	};

	//! Computes the U isoparametric curve.
	//! The U isoparametric curves of the surface are defined by the
	//! section of the spherical surface with plane obtained by rotation
	//! of the plane (Location, XAxis, ZAxis) around ZAxis. This plane
	//! defines the origin of parametrization u.
	//! For a SphericalSurface the UIso curve is a Circle.
	//! Warnings : The radius of this circle can be zero.
	XGeom_Curve^ XGeom_SphericalSurface::UIso(Standard_Real U) {
		return gcnew XGeom_Curve(NativeHandle()->UIso(U));
	};

	//! Computes the V isoparametric curve.
	//! The V isoparametric curves of the surface  are defined by
	//! the section of the spherical surface with plane parallel to the
	//! plane (Location, XAxis, YAxis). This plane defines the origin of
	//! parametrization V.
	//! Be careful if  V is close to PI/2 or 3*PI/2 the radius of the
	//! circle becomes tiny. It is not forbidden in this toolkit to
	//! create circle with radius = 0.0
	//! For a SphericalSurface the VIso curve is a Circle.
	//! Warnings : The radius of this circle can be zero.
	XGeom_Curve^ XGeom_SphericalSurface::VIso(Standard_Real V) {
		return gcnew XGeom_Curve(NativeHandle()->VIso(V));
	};


	//! Computes the  point P (U, V) on the surface.
	//! P (U, V) = Loc + Radius * Sin (V) * Zdir +
	//! Radius * Cos (V) * (cos (U) * XDir + sin (U) * YDir)
	//! where Loc is the origin of the placement plane (XAxis, YAxis)
	//! XDir is the direction of the XAxis and YDir the direction of
	//! the YAxis and ZDir the direction of the ZAxis.
	void XGeom_SphericalSurface::D0(Standard_Real U, Standard_Real V, xgp_Pnt^ P) {
		NativeHandle()->D0(U, V, *P->GetPnt());
	};


	//! Computes the current point and the first derivatives in the
	//! directions U and V.
	void XGeom_SphericalSurface::D1(Standard_Real U, Standard_Real V, xgp_Pnt^ P, xgp_Vec^ D1U, xgp_Vec^ D1V) {
		NativeHandle()->D1(U, V, *P->GetPnt(), *D1U->GetVec(), *D1V->GetVec());
	};


	//! Computes the current point, the first and the second derivatives
	//! in the directions U and V.
	void XGeom_SphericalSurface::D2(Standard_Real U, Standard_Real V, xgp_Pnt^ P, xgp_Vec^ D1U, xgp_Vec^ D1V, xgp_Vec^ D2U, xgp_Vec^ D2V, xgp_Vec^ D2UV) {
		NativeHandle()->D2(U, V, *P->GetPnt(), *D1U->GetVec(), *D1V->GetVec(), *D2U->GetVec(), *D2V->GetVec(), *D2UV->GetVec());
	};


	//! Computes the current point, the first,the second and the third
	//! derivatives in the directions U and V.
	void XGeom_SphericalSurface::D3(Standard_Real U, Standard_Real V, xgp_Pnt^ P, xgp_Vec^ D1U, xgp_Vec^ D1V, xgp_Vec^ D2U, xgp_Vec^ D2V, xgp_Vec^ D2UV, xgp_Vec^ D3U, xgp_Vec^ D3V, xgp_Vec^ D3UUV, xgp_Vec^ D3UVV) {
		NativeHandle()->D3(U, V, *P->GetPnt(), *D1U->GetVec(), *D1V->GetVec(), *D2U->GetVec(), *D2V->GetVec(), *D2UV->GetVec(), *D3U->GetVec(), *D3V->GetVec(), *D3UUV->GetVec(), *D3UVV->GetVec());
	};


	//! Computes the derivative of order Nu in the direction u
	//! and Nv in the direction v.
	//! Raised if Nu + Nv < 1 or Nu < 0 or Nv < 0.
	xgp_Vec^ XGeom_SphericalSurface::DN(Standard_Real U, Standard_Real V, Standard_Integer Nu, Standard_Integer Nv) {
		gp_Vec* temp = new gp_Vec(NativeHandle()->DN(U, V, Nu, Nv));
		return gcnew xgp_Vec(temp);
	};

	//! Applies the transformation T to this sphere.
	void XGeom_SphericalSurface::Transform(xgp_Trsf^ T) {
		NativeHandle()->Transform(*T->GetTrsf());
	};

	//! Creates a new object which is a copy of this sphere.
	XGeom_Geometry^ XGeom_SphericalSurface::Copy() {
		return gcnew XGeom_Geometry(NativeHandle()->Copy());
	};
}
