#include "XGeom_Surface.h"

namespace TKG3d {

	//!XGeom_Surface(void)
	XGeom_Surface::XGeom_Surface(void) : XGeom_Geometry(){
		
	}
	//! 
	XGeom_Surface::XGeom_Surface(Handle(Geom_Surface) pos) : XGeom_Geometry(pos) {
		NativeHandle() = pos;
		SetGeomHandle(NativeHandle());
	};

	//!
	XGeom_Surface::~XGeom_Surface() {
		SetGeomHandle(NULL);
		NativeHandle() = NULL;
	};
	void XGeom_Surface::SetSurfaceHandle(Handle(Geom_Surface) handle) {
		NativeHandle() = handle;
		SetGeomHandle(NativeHandle());
	};

	//!
	Handle(Geom_Surface) XGeom_Surface::GetSurface() {
		return NativeHandle();// Handle(Geom_Geometry)(NativeHandle);
	};

	//!
	Handle(Geom_Geometry) XGeom_Surface::GetGeometry() {
		return NativeHandle();// Handle(Geom_Geometry)(NativeHandle);
	};

	//! Reverses the U direction of parametrization of <me>.
	//! The bounds of the surface are not modified.
	void XGeom_Surface::UReverse() {
		NativeHandle()->UReverse();
	};


	//! Reverses the U direction of parametrization of <me>.
	//! The bounds of the surface are not modified.
	//! A copy of <me> is returned.
	Handle(Geom_Surface) XGeom_Surface::UReversed() {
		return NativeHandle()->UReversed();
	};

	//! Returns the  parameter on the  Ureversed surface for
	//! the point of parameter U on <me>.
	//!
	//! me->UReversed()->Value(me->UReversedParameter(U),V)
	//!
	//! is the same point as
	//!
	//! me->Value(U,V)
	Standard_Real XGeom_Surface::UReversedParameter(Standard_Real U) {
		return NativeHandle()->UReversedParameter(U);
	};


	//! Reverses the V direction of parametrization of <me>.
	//! The bounds of the surface are not modified.
	void XGeom_Surface::VReverse() {
		NativeHandle()->VReverse();
	};


	//! Reverses the V direction of parametrization of <me>.
	//! The bounds of the surface are not modified.
	//! A copy of <me> is returned.
	Handle(Geom_Surface) XGeom_Surface::VReversed() {
		return NativeHandle()->VReversed();
	};

	//! Returns the  parameter on the  Vreversed surface for
	//! the point of parameter V on <me>.
	//!
	//! me->VReversed()->Value(U,me->VReversedParameter(V))
	//!
	//! is the same point as
	//!
	//! me->Value(U,V)
	Standard_Real XGeom_Surface::VReversedParameter(Standard_Real V) {
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
	//! This methods does not change <U> and <V>
	//!
	//! It  can be redefined.  For  example on  the Plane,
	//! Cylinder, Cone, Revolved and Extruded surfaces.
	void XGeom_Surface::TransformParameters(Standard_Real U, Standard_Real V, xgp_Trsf^ T) {
		NativeHandle()->TransformParameters(U, V, T->GetTrsf());
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
	//! This methods returns an identity transformation
	//!
	//! It  can be redefined.  For  example on  the Plane,
	//! Cylinder, Cone, Revolved and Extruded surfaces.
	xgp_GTrsf2d^ XGeom_Surface::ParametricTransformation(xgp_Trsf^ T) {
		gp_GTrsf2d* temp = new gp_GTrsf2d(NativeHandle()->ParametricTransformation(T->GetTrsf()));
		return gcnew xgp_GTrsf2d(temp);
	};

	//! Returns the parametric bounds U1, U2, V1 and V2 of this surface.
	//! If the surface is infinite, this function can return a value
	//! equal to Precision::Infinite: instead of Standard_Real::LastReal.
	void XGeom_Surface::Bounds(Standard_Real U1, Standard_Real U2, Standard_Real V1, Standard_Real V2) {
		NativeHandle()->Bounds(U1, U2, V1, V2);
	};

	//! Checks whether this surface is closed in the u
	//! parametric direction.
	//! Returns true if, in the u parametric direction: taking
	//! uFirst and uLast as the parametric bounds in
	//! the u parametric direction, for each parameter v, the
	//! distance between the points P(uFirst, v) and
	//! P(uLast, v) is less than or equal to gp::Resolution().
	Standard_Boolean XGeom_Surface::IsUClosed() {
		return NativeHandle()->IsUClosed();
	};

	//! Checks whether this surface is closed in the u
	//! parametric direction.
	//! Returns true if, in the v parametric
	//! direction: taking vFirst and vLast as the
	//! parametric bounds in the v parametric direction, for
	//! each parameter u, the distance between the points
	//! P(u, vFirst) and P(u, vLast) is less than
	//! or equal to gp::Resolution().
	Standard_Boolean XGeom_Surface::IsVClosed() {
		return NativeHandle()->IsVClosed();
	};

	//! Checks if this surface is periodic in the u
	//! parametric direction. Returns true if:
	//! - this surface is closed in the u parametric direction, and
	//! - there is a constant T such that the distance
	//! between the points P (u, v) and P (u + T,
	//! v) (or the points P (u, v) and P (u, v +
	//! T)) is less than or equal to gp::Resolution().
	//! Note: T is the parametric period in the u parametric direction.
	Standard_Boolean XGeom_Surface::IsUPeriodic() {
		return NativeHandle()->IsUPeriodic();
	};

	//! Returns the period of this surface in the u
	//! parametric direction.
	//! raises if the surface is not uperiodic.
	Standard_Real XGeom_Surface::UPeriod() {
		return NativeHandle()->UPeriod();
	};

	//! Checks if this surface is periodic in the v
	//! parametric direction. Returns true if:
	//! - this surface is closed in the v parametric direction, and
	//! - there is a constant T such that the distance
	//! between the points P (u, v) and P (u + T,
	//! v) (or the points P (u, v) and P (u, v +
	//! T)) is less than or equal to gp::Resolution().
	//! Note: T is the parametric period in the v parametric direction.
	Standard_Boolean XGeom_Surface::IsVPeriodic() {
		return NativeHandle()->IsVPeriodic();
	};

	//! Returns the period of this surface in the v parametric direction.
	//! raises if the surface is not vperiodic.
	Standard_Real XGeom_Surface::VPeriod() {
		return NativeHandle()->VPeriod();
	};

	//! Computes the U isoparametric curve.
	Handle(Geom_Curve) XGeom_Surface::UIso(Standard_Real U) {
		return NativeHandle()->UIso(U);
	};

	//! Computes the V isoparametric curve.
	Handle(Geom_Curve) XGeom_Surface::VIso(Standard_Real V) {
		return NativeHandle()->VIso(V);
	};


	//! Returns the Global Continuity of the surface in direction U and V :
	//! C0 : only geometric continuity,
	//! C1 : continuity of the first derivative all along the surface,
	//! C2 : continuity of the second derivative all along the surface,
	//! C3 : continuity of the third derivative all along the surface,
	//! G1 : tangency continuity all along the surface,
	//! G2 : curvature continuity all along the surface,
	//! CN : the order of continuity is infinite.
	//! Example :
	//! If the surface is C1 in the V parametric direction and C2
	//! in the U parametric direction Shape = C1.
	GeomAbs_Shape XGeom_Surface::Continuity() {
		return NativeHandle()->Continuity();
	};

	//! Returns the order of continuity of the surface in the
	//! U parametric direction.
	//! Raised if N < 0.
	Standard_Boolean XGeom_Surface::IsCNu(Standard_Integer N) {
		return NativeHandle()->IsCNu(N);
	};

	//! Returns the order of continuity of the surface in the
	//! V parametric direction.
	//! Raised if N < 0.
	Standard_Boolean XGeom_Surface::IsCNv(Standard_Integer N) {
		return NativeHandle()->IsCNv(N);
	};

	//! Computes the point of parameter U,V on the surface.
	//!
	//! Raised only for an "OffsetSurface" if it is not possible to
	//! compute the current point.
	void XGeom_Surface::D0(Standard_Real U, Standard_Real V, xgp_Pnt^ P) {
		return NativeHandle()->D0(U, V, P->GetPnt());
	};


	//! Computes the point P and the first derivatives in the
	//! directions U and V at this point.
	//! Raised if the continuity of the surface is not C1.
	void XGeom_Surface::D1(Standard_Real U, Standard_Real V, xgp_Pnt^ P, xgp_Vec^ D1U, xgp_Vec^ D1V) {
		return NativeHandle()->D1(U, V, P->GetPnt(), D1U->GetVec(), D1V->GetVec());
	};


	//! Computes the point P, the first and the second derivatives in
	//! the directions U and V at this point.
	//! Raised if the continuity of the surface is not C2.
	void XGeom_Surface::D2(Standard_Real U, Standard_Real V, xgp_Pnt^ P, xgp_Vec^ D1U, xgp_Vec^ D1V, xgp_Vec^ D2U, xgp_Vec^ D2V, xgp_Vec^ D2UV) {
		return NativeHandle()->D2(U, V, P->GetPnt(), D1U->GetVec(), D1V->GetVec(), D2U->GetVec(), D2V->GetVec(), D2UV->GetVec());
	};


	//! Computes the point P, the first,the second and the third
	//! derivatives in the directions U and V at this point.
	//! Raised if the continuity of the surface is not C2.
	void XGeom_Surface::D3(Standard_Real U, Standard_Real V, xgp_Pnt^ P, xgp_Vec^ D1U, xgp_Vec^ D1V, xgp_Vec^ D2U, xgp_Vec^ D2V, xgp_Vec^ D2UV, xgp_Vec^ D3U, xgp_Vec^ D3V, xgp_Vec^ D3UUV, xgp_Vec^ D3UVV) {
		NativeHandle()->D3(U, V, P->GetPnt(), D1U->GetVec(), D1V->GetVec(), D2U->GetVec(), D2V->GetVec(), D2UV->GetVec(), D3U->GetVec(), D3V->GetVec(), D3UUV->GetVec(), D3UVV->GetVec());
	};

	//! ---Purpose ;
	//! Computes the derivative of order Nu in the direction U and Nv
	//! in the direction V at the point P(U, V).
	//!
	//! Raised if the continuity of the surface is not CNu in the U
	//! direction or not CNv in the V direction.
	//! Raised if Nu + Nv < 1 or Nu < 0 or Nv < 0.
	xgp_Vec^ XGeom_Surface::DN(Standard_Real U, Standard_Real V, Standard_Integer Nu, Standard_Integer Nv) {
		return gcnew xgp_Vec(NativeHandle()->DN(U, V, Nu, Nv));
	};


	//! Computes the point of parameter U on the surface.
	//!
	//! It is implemented with D0
	//!
	//! Raised only for an "OffsetSurface" if it is not possible to
	//! compute the current point.
	xgp_Pnt^ XGeom_Surface::Value(Standard_Real U, Standard_Real V) {
		return gcnew xgp_Pnt(NativeHandle()->Value(U, V));
	};
}