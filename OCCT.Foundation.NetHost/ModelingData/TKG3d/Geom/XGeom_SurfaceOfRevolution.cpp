#include <XGeom_SurfaceOfRevolution.h>
namespace TKG3d
{
	//!
	XGeom_SurfaceOfRevolution::XGeom_SurfaceOfRevolution(void) {
		/*NativeHandle() = new Geom_SurfaceOfRevolution();
		SetSurfaceHandle(NativeHandle());*/
	};

	//! 
	XGeom_SurfaceOfRevolution::XGeom_SurfaceOfRevolution(Handle(Geom_SurfaceOfRevolution) pos) {
		NativeHandle() = pos;
		SetSurfaceHandle(NativeHandle());
	};

	//!
	XGeom_SurfaceOfRevolution::~XGeom_SurfaceOfRevolution() {
		NativeHandle() = NULL;
		SetSurfaceHandle(NativeHandle());
	};

	void XGeom_SurfaceOfRevolution::SetSurfaceOfRevolutionHandle(Handle(Geom_SurfaceOfRevolution) handle) {
		NativeHandle() = handle;
		SetSurfaceHandle(NativeHandle());
	};

	//!
	Handle(Geom_SurfaceOfRevolution) XGeom_SurfaceOfRevolution::GetSurfaceOfRevolution() {
		return NativeHandle();
	};

	//!
	Handle(Geom_SweptSurface) XGeom_SurfaceOfRevolution::GetSweptSurface() {
		return NativeHandle();
	};

	//!
	Handle(Geom_Surface) XGeom_SurfaceOfRevolution::GetSurface() {
		return NativeHandle();
	};

	//!
	Handle(Geom_Geometry) XGeom_SurfaceOfRevolution::GetGeometry() {
		return NativeHandle();
	};

	//! C : is the meridian  or the referenced curve.
	//! A1 is the axis of revolution.
	//! The form of a SurfaceOfRevolution can be :
	//! . a general revolution surface (RevolutionForm),
	//! . a conical surface if the meridian is a line or a trimmed line
	//! (ConicalForm),
	//! . a cylindrical surface if the meridian is a line or a trimmed
	//! line parallel to the revolution axis (CylindricalForm),
	//! . a planar surface if the meridian is a line perpendicular to
	//! the revolution axis of the surface (PlanarForm).
	//! . a spherical surface,
	//! . a toroidal surface,
	//! . a quadric surface.
	//! Warnings :
	//! It is not checked that the curve C is planar and that the
	//! surface axis is in the plane of the curve.
	//! It is not checked that the revolved curve C doesn't
	//! self-intersects.
	XGeom_SurfaceOfRevolution::XGeom_SurfaceOfRevolution(XGeom_Curve^ C, xgp_Ax1^ A1) {
		NativeHandle() = new Geom_SurfaceOfRevolution(C->GetCurve(), *A1->GetAx1());
		SetSurfaceHandle(NativeHandle());
	};

	//! Changes the axis of revolution.
	//! Warnings :
	//! It is not checked that the axis is in the plane of the
	//! revolved curve.
	void XGeom_SurfaceOfRevolution::SetAxis(xgp_Ax1^ A1) {
		NativeHandle()->SetAxis(*A1->GetAx1());
	};

	//! Changes the direction of the revolution axis.
	//! Warnings :
	//! It is not checked that the axis is in the plane of the
	//! revolved curve.
	void XGeom_SurfaceOfRevolution::SetDirection(xgp_Dir^ V) {
		NativeHandle()->SetDirection(*V->GetDir());
	};

	//! Changes the revolved curve of the surface.
	//! Warnings :
	//! It is not checked that the curve C is planar and that the
	//! surface axis is in the plane of the curve.
	//! It is not checked that the revolved curve C doesn't
	//! self-intersects.
	void XGeom_SurfaceOfRevolution::SetBasisCurve(XGeom_Curve^ C) {
		NativeHandle()->SetBasisCurve(C->GetCurve());
	};

	//! Changes the location point of the revolution axis.
	//! Warnings :
	//! It is not checked that the axis is in the plane of the
	//! revolved curve.
	void XGeom_SurfaceOfRevolution::SetLocation(xgp_Pnt^ P) {
		NativeHandle()->SetLocation(*P->GetPnt());
	};

	//! Returns the revolution axis of the surface.
	xgp_Ax1^ XGeom_SurfaceOfRevolution::Axis() {
		gp_Ax1* temp = new gp_Ax1(NativeHandle()->Axis());
		return gcnew xgp_Ax1(temp);
	};


	//! Returns the location point of the axis of revolution.
	xgp_Pnt^ XGeom_SurfaceOfRevolution::Location() {
		gp_Pnt* temp = new gp_Pnt(NativeHandle()->Location());
		return gcnew xgp_Pnt(temp);
	};


	//! Computes the position of the reference plane of the surface
	//! defined by the basis curve and the symmetry axis.
	//! The location point is the location point of the revolution's
	//! axis, the XDirection of the plane is given by the revolution's
	//! axis and the orientation of the normal to the plane is given
	//! by the sense of revolution.
	//!
	//! Raised if the revolved curve is not planar or if the revolved
	//! curve and the symmetry axis are not in the same plane or if
	//! the maximum of distance between the axis and the revolved
	//! curve is lower or equal to Resolution from gp.
	xgp_Ax2^ XGeom_SurfaceOfRevolution::ReferencePlane() {
		gp_Ax2* temp = new gp_Ax2(NativeHandle()->ReferencePlane());
		return gcnew xgp_Ax2(temp);
	};

	//! Changes the orientation of this surface of revolution
	//! in the u  parametric direction. The bounds of the
	//! surface are not changed but the given parametric
	//! direction is reversed. Hence the orientation of the
	//! surface is reversed.
	//! As a consequence:
	//! - UReverse reverses the direction of the axis of
	//! revolution of this surface,
	void XGeom_SurfaceOfRevolution::UReverse() {
		NativeHandle()->UReverse();
	};

	//! Computes the u  parameter on the modified
	//! surface, when reversing its u  parametric
	//! direction, for any point of u parameter U  on this surface of revolution.
	//! In the case of a revolved surface:
	//! - UReversedParameter returns 2.*Pi - U
	Standard_Real XGeom_SurfaceOfRevolution::UReversedParameter(Standard_Real U) {
		return NativeHandle()->UReversedParameter(U);
	};

	//! Changes the orientation of this surface of revolution
	//! in the v parametric direction. The bounds of the
	//! surface are not changed but the given parametric
	//! direction is reversed. Hence the orientation of the
	//! surface is reversed.
	//! As a consequence:
	//! - VReverse reverses the meridian of this surface of revolution.
	void XGeom_SurfaceOfRevolution::VReverse() {
		NativeHandle()->VReverse();
	};

	//! Computes the  v parameter on the modified
	//! surface, when reversing its  v parametric
	//! direction, for any point of v parameter V on this surface of revolution.
	//! In the case of a revolved surface:
	//! - VReversedParameter returns the reversed
	//! parameter given by the function
	//! ReversedParameter called with V on the meridian.
	Standard_Real XGeom_SurfaceOfRevolution::VReversedParameter(Standard_Real V) {
		return NativeHandle()->VReversedParameter(V);
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
	//! This methods multiplies V by
	//! BasisCurve()->ParametricTransformation(T)
	void XGeom_SurfaceOfRevolution::TransformParameters(Standard_Real% U, Standard_Real% V, xgp_Trsf^ T) {
		Standard_Real XU(U); Standard_Real  XV(V);
		NativeHandle()->TransformParameters(XU, XV, *T->GetTrsf());
		U = XU; V = XV;
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
	//! U axis with BasisCurve()->ParametricTransformation(T)
	xgp_GTrsf2d^ XGeom_SurfaceOfRevolution::ParametricTransformation(xgp_Trsf^ T) {
		gp_GTrsf2d* temp = new gp_GTrsf2d(NativeHandle()->ParametricTransformation(*T->GetTrsf()));
		return gcnew xgp_GTrsf2d(temp);
	};

	//! Returns the parametric bounds U1, U2 , V1 and V2 of this surface.
	//! A surface of revolution is always complete, so U1 = 0, U2 = 2*PI.
	void XGeom_SurfaceOfRevolution::Bounds(Standard_Real% U1, Standard_Real% U2, Standard_Real% V1, Standard_Real% V2) {
		Standard_Real XU1 = Standard_Real(U1); Standard_Real XU2 = Standard_Real(U2); Standard_Real XV1 = Standard_Real(V1); Standard_Real XV2 = Standard_Real(V2);
		NativeHandle()->Bounds(XU1, XU2, XV1, XV2);
		U1 = XU1; U2 = XU2; V1 = XV1; V2 = XV2;
	};

	//! IsUClosed always returns true.
	Standard_Boolean XGeom_SurfaceOfRevolution::IsUClosed() {
		return NativeHandle()->IsUClosed();
	};

	//! IsVClosed returns true if the meridian of this
	//! surface of revolution is closed.
	Standard_Boolean XGeom_SurfaceOfRevolution::IsVClosed() {
		return NativeHandle()->IsVClosed();
	};

	//! IsCNu always returns true.
	Standard_Boolean XGeom_SurfaceOfRevolution::IsCNu(Standard_Integer N) {
		return NativeHandle()->IsCNu(N);
	};

	//! IsCNv returns true if the degree of continuity of the
	//! meridian of this surface of revolution is at least N.
	//! Raised if N < 0.
	Standard_Boolean XGeom_SurfaceOfRevolution::IsCNv(Standard_Integer N) {
		return NativeHandle()->IsCNv(N);
	};

	//! Returns True.
	Standard_Boolean XGeom_SurfaceOfRevolution::IsUPeriodic() {
		return NativeHandle()->IsUPeriodic();
	};

	//! IsVPeriodic returns true if the meridian of this
	//! surface of revolution is periodic.
	Standard_Boolean XGeom_SurfaceOfRevolution::IsVPeriodic() {
		return NativeHandle()->IsVPeriodic();
	};

	//! Computes the U isoparametric curve of this surface
	//! of revolution. It is the curve obtained by rotating the
	//! meridian through an angle U about the axis of revolution.
	XGeom_Curve^ XGeom_SurfaceOfRevolution::UIso(Standard_Real U) {
		return gcnew XGeom_Curve(NativeHandle()->UIso(U));
	};

	//! Computes the U isoparametric curve of this surface
	//! of revolution. It is the curve obtained by rotating the
	//! meridian through an angle U about the axis of revolution.
	XGeom_Curve^ XGeom_SurfaceOfRevolution::VIso(Standard_Real V) {
		return gcnew XGeom_Curve(NativeHandle()->VIso(V));
	};

	//! Computes the  point P (U, V) on the surface.
	//! U is the angle of the rotation around the revolution axis.
	//! The direction of this axis gives the sense of rotation.
	//! V is the parameter of the revolved curve.
	void XGeom_SurfaceOfRevolution::D0(Standard_Real U, Standard_Real V, xgp_Pnt^ P) {
		NativeHandle()->D0(U, V, *P->GetPnt());
	};

	//! Computes the current point and the first derivatives
	//! in the directions U and V.
	//! Raised if the continuity of the surface is not C1.
	void XGeom_SurfaceOfRevolution::D1(Standard_Real U, Standard_Real V, xgp_Pnt^ P, xgp_Vec^ D1U, xgp_Vec^ D1V) {
		NativeHandle()->D1(U, V, *P->GetPnt(), *D1U->GetVec(), *D1V->GetVec());
	};

	//! Computes the current point, the first and the second derivatives
	//! in the directions U and V.
	//! Raised if the continuity of the surface is not C2.
	void XGeom_SurfaceOfRevolution::D2(Standard_Real U, Standard_Real V, xgp_Pnt^ P, xgp_Vec^ D1U, xgp_Vec^ D1V, xgp_Vec^ D2U, xgp_Vec^ D2V, xgp_Vec^ D2UV) {
		NativeHandle()->D2(U, V, *P->GetPnt(), *D1U->GetVec(), *D1V->GetVec(), *D2U->GetVec(), *D2V->GetVec(), *D2UV->GetVec());
	};

	//! Computes the current point, the first,the second and the third
	//! derivatives in the directions U and V.
	//! Raised if the continuity of the surface is not C3.
	void XGeom_SurfaceOfRevolution::D3(Standard_Real U, Standard_Real V, xgp_Pnt^ P, xgp_Vec^ D1U, xgp_Vec^ D1V, xgp_Vec^ D2U, xgp_Vec^ D2V, xgp_Vec^ D2UV, xgp_Vec^ D3U, xgp_Vec^ D3V, xgp_Vec^ D3UUV, xgp_Vec^ D3UVV) {
		NativeHandle()->D3(U, V, *P->GetPnt(), *D1U->GetVec(), *D1V->GetVec(), *D2U->GetVec(), *D2V->GetVec(), *D2UV->GetVec(), *D3U->GetVec(), *D3V->GetVec(), *D3UUV->GetVec(), *D3UVV->GetVec());
	};

	//! Computes the derivative of order Nu in the direction u and
	//! Nv in the direction v.
	//!
	//! Raised if the continuity of the surface is not CNu in the u
	//! direction and CNv in the v direction.
	//! Raised if Nu + Nv < 1 or Nu < 0 or Nv < 0.
	//! The following  functions  evaluates the  local
	//! derivatives on surface. Useful to manage discontinuities
	//! on the surface.
	//! if    Side  =  1  ->  P  =  S( U+,V )
	//! if    Side  = -1  ->  P  =  S( U-,V )
	//! else  P  is betveen discontinuities
	//! can be evaluated using methods  of
	//! global evaluations    P  =  S( U ,V )
	xgp_Vec^ XGeom_SurfaceOfRevolution::DN(Standard_Real U, Standard_Real V, Standard_Integer Nu, Standard_Integer Nv) {
		gp_Vec* temp = new gp_Vec(NativeHandle()->DN(U, V, Nu, Nv));
		return gcnew xgp_Vec(temp);
	};

	//! Applies the transformation T to this surface of revolution.
	void XGeom_SurfaceOfRevolution::Transform(xgp_Trsf^ T) {
		NativeHandle()->Transform(*T->GetTrsf());
	};

	//! Creates a new object which is a copy of this surface of revolution.
	XGeom_Geometry^ XGeom_SurfaceOfRevolution::Copy() {
		return gcnew XGeom_Geometry(NativeHandle()->Copy());
	};
}
