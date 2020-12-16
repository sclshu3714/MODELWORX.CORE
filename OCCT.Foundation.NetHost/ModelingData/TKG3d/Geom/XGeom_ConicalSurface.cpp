#include <XGeom_ConicalSurface.h>
namespace TKG3d {
	/// <summary>
	/// X
	/// </summary>
	/// <param name=""></param>
	XGeom_ConicalSurface::XGeom_ConicalSurface(void) {
		//NativeHandle() = new Geom_ConicalSurface();
	};

	/// <summary>
	/// X
	/// </summary>
	/// <param name="pos"></param>
	XGeom_ConicalSurface::XGeom_ConicalSurface(Handle(Geom_ConicalSurface) pos) {
		NativeHandle() = pos;
		SetElementarySurfaceHandle(NativeHandle());
	};


	XGeom_ConicalSurface::~XGeom_ConicalSurface() {
		NativeHandle() = NULL;
		SetElementarySurfaceHandle(NativeHandle());
	};

	/// <summary>
	/// 
	/// </summary>
	/// <param name="handle"></param>
	void XGeom_ConicalSurface::SetConicalSurfaceHandle(Handle(Geom_ConicalSurface) handle) {
		NativeHandle() = handle;
		SetElementarySurfaceHandle(NativeHandle());
	};

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	Handle(Geom_ConicalSurface) XGeom_ConicalSurface::GetConicalSurface() {
		return NativeHandle();
	};

	//! 
	Handle(Geom_ElementarySurface) XGeom_ConicalSurface::GetElementarySurface() {
		return NativeHandle();
	};

	//!
	Handle(Geom_Surface) XGeom_ConicalSurface::GetSurface() {
		return NativeHandle();
	};

	//!
	Handle(Geom_Geometry) XGeom_ConicalSurface::GetGeometry() {
		return NativeHandle();
	};

	//! A3 defines the local coordinate system of the conical surface.
	//! Ang is the conical surface semi-angle. Its absolute value is in range
	//! ]0, PI/2[.
	//! Radius is the radius of the circle Viso in the placement plane
	//! of the conical surface defined with "XAxis" and "YAxis".
	//! The "ZDirection" of A3 defines the direction of the surface's
	//! axis of symmetry.
	//! If the location point of A3 is the apex of the surface
	//! Radius = 0 .
	//! At the creation the parametrization of the surface is defined
	//! such that the normal Vector (N = D1U ^ D1V) is oriented towards
	//! the "outside region" of the surface.
	//!
	//! Raised if Radius < 0.0 or Abs(Ang) < Resolution from gp or
	//! Abs(Ang) >= PI/2 - Resolution
	XGeom_ConicalSurface::XGeom_ConicalSurface(xgp_Ax3^ A3, Standard_Real Ang, Standard_Real Radius) {
		NativeHandle() = new Geom_ConicalSurface(*A3->GetAx3(), Ang, Radius);
		SetElementarySurfaceHandle(NativeHandle());
	};


	//! Creates a ConicalSurface from a non transient Cone from
	//! package gp.
	XGeom_ConicalSurface::XGeom_ConicalSurface(xgp_Cone^ C) {
		NativeHandle() = new Geom_ConicalSurface(*C->GetCone());
		SetElementarySurfaceHandle(NativeHandle());
	};


	//! Set <me> so that <me> has the same geometric properties as C.
	void XGeom_ConicalSurface::SetCone(xgp_Cone^ C) {
		NativeHandle()->SetCone(*C->GetCone());
	};


	//! Changes the radius of the conical surface in the placement
	//! plane (Z = 0, V = 0).  The local coordinate system is not
	//! modified.
	//! Raised if R < 0.0
	void XGeom_ConicalSurface::SetRadius(Standard_Real R) {
		NativeHandle()->SetRadius(R);
	};


	//! Changes the semi angle of the conical surface.
	//! Semi-angle can be negative. Its absolute value
	//! Abs(Ang) is in range ]0,PI/2[.
	//! Raises ConstructionError if Abs(Ang) < Resolution from gp or
	//! Abs(Ang) >= PI/2 - Resolution
	void XGeom_ConicalSurface::SetSemiAngle(Standard_Real Ang) {
		NativeHandle()->SetSemiAngle(Ang);
	};


	//! returns a non transient cone with the same geometric properties
	//! as <me>.
	xgp_Cone^ XGeom_ConicalSurface::Cone() {
		gp_Cone* temp = new gp_Cone(NativeHandle()->Cone());
		return gcnew xgp_Cone(temp);
	};

	//! return 2.PI - U.
	Standard_Real XGeom_ConicalSurface::UReversedParameter(Standard_Real U) {
		return NativeHandle()->UReversedParameter(U);
	};

	//! Computes the u (or v) parameter on the modified
	//! surface, when reversing its u (or v) parametric
	//! direction, for any point of u parameter U (or of v
	//! parameter V) on this cone.
	//! In the case of a cone, these functions return respectively:
	//! - 2.*Pi - U, -V.
	Standard_Real XGeom_ConicalSurface::VReversedParameter(Standard_Real V) {
		return NativeHandle()->VReversedParameter(V);
	};

	//! Changes the orientation of this cone in the v
	//! parametric direction. The bounds of the surface are
	//! not changed but the v parametric direction is reversed.
	//! As a consequence, for a cone:
	//! - the "main Direction" of the local coordinate system
	//! is reversed, and
	//! - the half-angle at the apex is inverted.
	void XGeom_ConicalSurface::VReverse() {
		NativeHandle()->VReverse();
	};

	//! Computes the  parameters on the  transformed  surface for
	//! the transform of the point of parameters U,V on <me>.
	//!
	//! me->Transformed(T)->Value(U',V')
	//!
	//! is the same point as
	//!
	//! me->Value(U,V).Transformed(T)
	//!
	//! Where U',V' are the new values of U,V after calling
	//!
	//! me->TranformParameters(U,V,T)
	//!
	//! This methods multiplies V by T.ScaleFactor()
	void XGeom_ConicalSurface::TransformParameters(Standard_Real U, Standard_Real V, xgp_Trsf^ T) {
		NativeHandle()->TransformParameters(U, V, *T->GetTrsf());
	};

	//! Returns a 2d transformation  used to find the  new
	//! parameters of a point on the transformed surface.
	//!
	//! me->Transformed(T)->Value(U',V')
	//!
	//! is the same point as
	//!
	//! me->Value(U,V).Transformed(T)
	//!
	//! Where U',V' are  obtained by transforming U,V with
	//! th 2d transformation returned by
	//!
	//! me->ParametricTransformation(T)
	//!
	//! This  methods  returns  a scale  centered  on  the
	//! U axis with T.ScaleFactor
	xgp_GTrsf2d^ XGeom_ConicalSurface::ParametricTransformation(xgp_Trsf^ T) {
		gp_GTrsf2d* temp = new gp_GTrsf2d(NativeHandle()->ParametricTransformation(*T->GetTrsf()));
		return gcnew xgp_GTrsf2d(temp);
	};

	//! Computes the apex of this cone. It is on the negative
	//! side of the axis of revolution of this cone if the
	//! half-angle at the apex is positive, and on the positive
	//! side of the "main Axis" if the half-angle is negative.
	xgp_Pnt^ XGeom_ConicalSurface::Apex() {
		gp_Pnt* temp = new gp_Pnt(NativeHandle()->Apex());
		return gcnew xgp_Pnt(temp);
	};


	//! The conical surface is infinite in the V direction so
	//! V1 = Realfirst from Standard and V2 = RealLast.
	//! U1 = 0 and U2 = 2*PI.
	void XGeom_ConicalSurface::Bounds(Standard_Real% U1, Standard_Real% U2, Standard_Real% V1, Standard_Real% V2) {
		Standard_Real XU1 = Standard_Real(U1); Standard_Real XU2 = Standard_Real(U2); Standard_Real XV1 = Standard_Real(V1); Standard_Real XV2 = Standard_Real(V2);
		NativeHandle()->Bounds(XU1, XU2, XV1, XV2);
		U1 = XU1; U2 = XU2; V1 = XV1; V2 = XV2;
	};


	//! Returns the coefficients of the implicit equation of the
	//! quadric in the absolute cartesian coordinate system :
	//! These coefficients are normalized.
	//! A1.X**2 + A2.Y**2 + A3.Z**2 + 2.(B1.X.Y + B2.X.Z + B3.Y.Z) +
	//! 2.(C1.X + C2.Y + C3.Z) + D = 0.0
	void XGeom_ConicalSurface::Coefficients(Standard_Real A1, Standard_Real A2, Standard_Real A3, Standard_Real B1, Standard_Real B2, Standard_Real B3, Standard_Real C1, Standard_Real C2, Standard_Real C3, Standard_Real D) {
		NativeHandle()->Coefficients(A1, A2, A3, B1, B2, B3, C1, C2, C3, D);
	};

	//! Returns the reference radius of this cone.
	//! The reference radius is the radius of the circle formed
	//! by the intersection of this cone and its reference
	//! plane (i.e. the plane defined by the origin, "X
	//! Direction" and "Y Direction" of the local coordinate
	//! system of this cone).
	//! If the apex of this cone is on the origin of the local
	//! coordinate system of this cone, the returned value is 0.
	Standard_Real XGeom_ConicalSurface::RefRadius() {
		return NativeHandle()->RefRadius();
	};


	//! Returns the semi-angle at the apex of this cone.
	//! Attention! Semi-angle can be negative.
	Standard_Real XGeom_ConicalSurface::SemiAngle() {
		return NativeHandle()->SemiAngle();
	};

	//! returns True.
	Standard_Boolean XGeom_ConicalSurface::IsUClosed() {
		return NativeHandle()->IsUClosed();
	};

	//! returns False.
	Standard_Boolean XGeom_ConicalSurface::IsVClosed() {
		return NativeHandle()->IsVClosed();
	};

	//! Returns True.
	Standard_Boolean XGeom_ConicalSurface::IsUPeriodic() {
		return NativeHandle()->IsUPeriodic();
	};

	//! Returns False.
	Standard_Boolean XGeom_ConicalSurface::IsVPeriodic() {
		return NativeHandle()->IsVPeriodic();
	};

	//! Builds the U isoparametric line of this cone. The
	//! origin of this line is on the reference plane of this
	//! cone (i.e. the plane defined by the origin, "X Direction"
	//! and "Y Direction" of the local coordinate system of this cone).
	XGeom_Curve^ XGeom_ConicalSurface::UIso(Standard_Real U) {
		return gcnew XGeom_Curve(NativeHandle()->UIso(U));
	};

	//! Builds the V isoparametric circle of this cone. It is the
	//! circle on this cone, located in the plane of Z
	//! coordinate V*cos(Semi-Angle) in the local coordinate system of this
	//! cone. The "Axis" of this circle is the axis of revolution
	//! of this cone. Its starting point is defined by the "X
	//! Direction" of this cone.
	//! Warning
	//! If the V isoparametric circle is close to the apex of
	//! this cone, the radius of the circle becomes very small.
	//! It is possible to have a circle with radius equal to 0.0.
	XGeom_Curve^ XGeom_ConicalSurface::VIso(Standard_Real V) {
		return gcnew XGeom_Curve(NativeHandle()->VIso(V));
	};


	//! Computes the  point P (U, V) on the surface.
	//! P (U, V) = Loc +
	//! (RefRadius + V * sin (Semi-Angle)) * (cos (U) * XDir + sin (U) * YDir) +
	//! V * cos (Semi-Angle) * ZDir
	//! where Loc is the origin of the placement plane (XAxis, YAxis)
	//! XDir is the direction of the XAxis and YDir the direction of
	//! the YAxis.
	void XGeom_ConicalSurface::D0(Standard_Real U, Standard_Real V, xgp_Pnt^ P) {
		NativeHandle()->D0(U, V, *P->GetPnt());
	};


	//! Computes the current point and the first derivatives in the
	//! directions U and V.
	void XGeom_ConicalSurface::D1(Standard_Real U, Standard_Real V, xgp_Pnt^ P, xgp_Vec^ D1U, xgp_Vec^ D1V) {
		NativeHandle()->D1(U, V, *P->GetPnt(), *D1U->GetVec(), *D1V->GetVec());
	};


	//! Computes the current point, the first and the second derivatives
	//! in the directions U and V.
	void XGeom_ConicalSurface::D2(Standard_Real U, Standard_Real V, xgp_Pnt^ P, xgp_Vec^ D1U, xgp_Vec^ D1V, xgp_Vec^ D2U, xgp_Vec^ D2V, xgp_Vec^ D2UV) {
		NativeHandle()->D2(U, V, *P->GetPnt(), *D1U->GetVec(), *D1V->GetVec(), *D2U->GetVec(), *D2V->GetVec(), *D2UV->GetVec());
	};


	//! Computes the current point, the first,the second and the third
	//! derivatives in the directions U and V.
	void XGeom_ConicalSurface::D3(Standard_Real U, Standard_Real V, xgp_Pnt^ P, xgp_Vec^ D1U, xgp_Vec^ D1V, xgp_Vec^ D2U, xgp_Vec^ D2V, xgp_Vec^ D2UV, xgp_Vec^ D3U, xgp_Vec^ D3V, xgp_Vec^ D3UUV, xgp_Vec^ D3UVV) {
		NativeHandle()->D3(U, V, *P->GetPnt(), *D1U->GetVec(), *D1V->GetVec(), *D2U->GetVec(), *D2V->GetVec(), *D2UV->GetVec(), *D3U->GetVec(), *D3V->GetVec(), *D3UUV->GetVec(), *D3UVV->GetVec());
	};

	//! Computes the derivative of order Nu in the u
	//! parametric direction, and Nv in the v parametric
	//! direction at the point of parameters (U, V) of this cone.
	//! Exceptions
	//! Standard_RangeError if:
	//! - Nu + Nv is less than 1,
	//! - Nu or Nv is negative.
	xgp_Vec^ XGeom_ConicalSurface::DN(Standard_Real U, Standard_Real V, Standard_Integer Nu, Standard_Integer Nv) {
		gp_Vec* temp = new gp_Vec(NativeHandle()->DN(U, V, Nu, Nv));
		return gcnew xgp_Vec(temp);
	};

	//! Applies the transformation T to this cone.
	void XGeom_ConicalSurface::Transform(xgp_Trsf^ T) {
		NativeHandle()->Transform(*T->GetTrsf());
	};

	//! Creates a new object which is a copy of this cone.
	XGeom_Geometry^ XGeom_ConicalSurface::Copy() {
		return gcnew XGeom_Geometry(NativeHandle()->Copy());
	};
}