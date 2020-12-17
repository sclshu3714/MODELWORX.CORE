#include <XGeom_SurfaceOfLinearExtrusion.h>
namespace TKG3d
{
	//!
	XGeom_SurfaceOfLinearExtrusion::XGeom_SurfaceOfLinearExtrusion(void) {
		/*NativeHandle() = new Geom_SurfaceOfLinearExtrusion();
		SetSurfaceHandle(NativeHandle());*/
	};

	//! 
	XGeom_SurfaceOfLinearExtrusion::XGeom_SurfaceOfLinearExtrusion(Handle(Geom_SurfaceOfLinearExtrusion) pos) {
		NativeHandle() = pos;
		SetSurfaceHandle(NativeHandle());
	};

	//!
	XGeom_SurfaceOfLinearExtrusion::~XGeom_SurfaceOfLinearExtrusion() {
		NativeHandle() = NULL;
		SetSurfaceHandle(NativeHandle());
	};

	void XGeom_SurfaceOfLinearExtrusion::SetSurfaceOfLinearExtrusionHandle(Handle(Geom_SurfaceOfLinearExtrusion) handle) {
		NativeHandle() = handle;
		SetSurfaceHandle(NativeHandle());
	};

	//!
	Handle(Geom_SurfaceOfLinearExtrusion) XGeom_SurfaceOfLinearExtrusion::GetSurfaceOfLinearExtrusion() {
		return NativeHandle();
	};

	//!
	Handle(Geom_SweptSurface) XGeom_SurfaceOfLinearExtrusion::GetSweptSurface() {
		return NativeHandle();
	};

	//!
	Handle(Geom_Surface) XGeom_SurfaceOfLinearExtrusion::GetSurface() {
		return NativeHandle();
	};

	//!
	Handle(Geom_Geometry) XGeom_SurfaceOfLinearExtrusion::GetGeometry() {
		return NativeHandle();
	};

	//! V is the direction of extrusion.
	//! C is the extruded curve.
	//! The form of a SurfaceOfLinearExtrusion can be :
	//! . ruled surface (RuledForm),
	//! . a cylindrical surface if the extruded curve is a circle or
	//! a trimmed circle (CylindricalForm),
	//! . a plane surface if the extruded curve is a Line (PlanarForm).
	//! Warnings :
	//! Degenerated surface cases are not detected. For example if the
	//! curve C is a line and V is parallel to the direction of this
	//! line.
	XGeom_SurfaceOfLinearExtrusion::XGeom_SurfaceOfLinearExtrusion(XGeom_Curve^ C, xgp_Dir^ V) {
		NativeHandle() = new Geom_SurfaceOfLinearExtrusion(C->GetCurve(), *V->GetDir());
		SetSurfaceHandle(NativeHandle());
	};

	//! Assigns V as the "direction of extrusion" for this
	//! surface of linear extrusion.
	void XGeom_SurfaceOfLinearExtrusion::SetDirection(xgp_Dir^ V) {
		NativeHandle()->SetDirection(*V->GetDir());
	};

	//! Modifies this surface of linear extrusion by redefining
	//! its "basis curve" (the "extruded curve").
	void XGeom_SurfaceOfLinearExtrusion::SetBasisCurve(XGeom_Curve^ C) {
		NativeHandle()->SetBasisCurve(C->GetCurve());
	};

	//! Changes the orientation of this surface of linear
	//! extrusion in the u  parametric direction. The
	//! bounds of the surface are not changed, but the given
	//! parametric direction is reversed. Hence the
	//! orientation of the surface is reversed.
	//! In the case of a surface of linear extrusion:
	//! - UReverse reverses the basis curve, and
	//! - VReverse reverses the direction of linear extrusion.
	void XGeom_SurfaceOfLinearExtrusion::UReverse() {
		NativeHandle()->UReverse();
	};

	//! Computes the u parameter on the modified
	//! surface, produced by reversing its u  parametric
	//! direction, for any point of u parameter U  on this surface of linear extrusion.
	//! In the case of an extruded surface:
	//! - UReverseParameter returns the reversed
	//! parameter given by the function
	//! ReversedParameter called with U on the basis   curve,
	Standard_Real XGeom_SurfaceOfLinearExtrusion::UReversedParameter(Standard_Real U) {
		return NativeHandle()->UReversedParameter(U);
	};

	//! Changes the orientation of this surface of linear
	//! extrusion in the v parametric direction. The
	//! bounds of the surface are not changed, but the given
	//! parametric direction is reversed. Hence the
	//! orientation of the surface is reversed.
	//! In the case of a surface of linear extrusion:
	//! - UReverse reverses the basis curve, and
	//! - VReverse reverses the direction of linear extrusion.
	void XGeom_SurfaceOfLinearExtrusion::VReverse() {
		NativeHandle()->VReverse();
	};

	//! Computes the v parameter on the modified
	//! surface, produced by reversing its u v parametric
	//! direction, for any point of v parameter V on this surface of linear extrusion.
	//! In the case of an extruded surface VReverse returns -V.
	Standard_Real XGeom_SurfaceOfLinearExtrusion::VReversedParameter(Standard_Real V) {
		return NativeHandle()->VReversedParameter(V);
	};

	//! Returns the parametric bounds U1, U2, V1 and V2 of
	//! this surface of linear extrusion.
	//! A surface of linear extrusion is infinite in the v
	//! parametric direction, so:
	//! - V1 = Standard_Real::RealFirst()
	//! - V2 = Standard_Real::RealLast().
	void XGeom_SurfaceOfLinearExtrusion::Bounds(Standard_Real% U1, Standard_Real% U2, Standard_Real% V1, Standard_Real% V2) {
		Standard_Real XU1 = Standard_Real(U1); Standard_Real XU2 = Standard_Real(U2); Standard_Real XV1 = Standard_Real(V1); Standard_Real XV2 = Standard_Real(V2);
		NativeHandle()->Bounds(XU1, XU2, XV1, XV2);
		U1 = XU1; U2 = XU2; V1 = XV1; V2 = XV2;
	};

	//! IsUClosed returns true if the "basis curve" of this
	//! surface of linear extrusion is closed.
	Standard_Boolean XGeom_SurfaceOfLinearExtrusion::IsUClosed() {
		return NativeHandle()->IsUClosed();
	};

	//! IsVClosed always returns false.
	Standard_Boolean XGeom_SurfaceOfLinearExtrusion::IsVClosed() {
		return NativeHandle()->IsVClosed();
	};

	//! IsCNu returns true if the degree of continuity for the
	//! "basis curve" of this surface of linear extrusion is at least N.
	//! Raises RangeError if N < 0.
	Standard_Boolean XGeom_SurfaceOfLinearExtrusion::IsCNu(Standard_Integer N) {
		return NativeHandle()->IsCNu(N);
	};

	//! IsCNv always returns true.
	Standard_Boolean XGeom_SurfaceOfLinearExtrusion::IsCNv(Standard_Integer N) {
		return NativeHandle()->IsCNv(N);
	};

	//! IsUPeriodic returns true if the "basis curve" of this
	//! surface of linear extrusion is periodic.
	Standard_Boolean XGeom_SurfaceOfLinearExtrusion::IsUPeriodic() {
		return NativeHandle()->IsUPeriodic();
	};

	//! IsVPeriodic always returns false.
	Standard_Boolean XGeom_SurfaceOfLinearExtrusion::IsVPeriodic() {
		return NativeHandle()->IsVPeriodic();
	};

	//! Computes the U isoparametric curve of this surface
	//! of linear extrusion. This is the line parallel to the
	//! direction of extrusion, passing through the point of
	//! parameter U of the basis curve.
	XGeom_Curve^ XGeom_SurfaceOfLinearExtrusion::UIso(Standard_Real U) {
		return gcnew XGeom_Curve(NativeHandle()->UIso(U));
	};

	//! Computes the V isoparametric curve of this surface
	//! of linear extrusion. This curve is obtained by
	//! translating the extruded curve in the direction of
	//! extrusion, with the magnitude V.
	XGeom_Curve^ XGeom_SurfaceOfLinearExtrusion::VIso(Standard_Real V) {
		return gcnew XGeom_Curve(NativeHandle()->VIso(V));
	};


	//! Computes the  point P (U, V) on the surface.
	//! The parameter U is the parameter on the extruded curve.
	//! The parametrization V is a linear parametrization, and
	//! the direction of parametrization is the direction of
	//! extrusion. If the point is on the extruded curve, V = 0.0
	void XGeom_SurfaceOfLinearExtrusion::D0(Standard_Real U, Standard_Real V, xgp_Pnt^ P) {
		NativeHandle()->D0(U, V, *P->GetPnt());
	};


	//! Computes the current point and the first derivatives in the
	//! directions U and V.
	//! Raises UndefinedDerivative if the continuity of the surface is not C1.
	void XGeom_SurfaceOfLinearExtrusion::D1(Standard_Real U, Standard_Real V, xgp_Pnt^ P, xgp_Vec^ D1U, xgp_Vec^ D1V) {
		NativeHandle()->D1(U, V, *P->GetPnt(), *D1U->GetVec(), *D1V->GetVec());
	};

	//! --- Purpose ;
	//! Computes the current point, the first and the second derivatives
	//! in the directions U and V.
	//! Raises UndefinedDerivative if the continuity of the surface is not C2.
	void XGeom_SurfaceOfLinearExtrusion::D2(Standard_Real U, Standard_Real V, xgp_Pnt^ P, xgp_Vec^ D1U, xgp_Vec^ D1V, xgp_Vec^ D2U, xgp_Vec^ D2V, xgp_Vec^ D2UV) {
		NativeHandle()->D2(U, V, *P->GetPnt(), *D1U->GetVec(), *D1V->GetVec(), *D2U->GetVec(), *D2V->GetVec(), *D2UV->GetVec());
	};


	//! Computes the current point, the first,the second and the third
	//! derivatives in the directions U and V.
	//! Raises UndefinedDerivative if the continuity of the surface is not C3.
	void XGeom_SurfaceOfLinearExtrusion::D3(Standard_Real U, Standard_Real V, xgp_Pnt^ P, xgp_Vec^ D1U, xgp_Vec^ D1V, xgp_Vec^ D2U, xgp_Vec^ D2V, xgp_Vec^ D2UV, xgp_Vec^ D3U, xgp_Vec^ D3V, xgp_Vec^ D3UUV, xgp_Vec^ D3UVV) {
		NativeHandle()->D3(U, V, *P->GetPnt(), *D1U->GetVec(), *D1V->GetVec(), *D2U->GetVec(), *D2V->GetVec(), *D2UV->GetVec(), *D3U->GetVec(), *D3V->GetVec(), *D3UUV->GetVec(), *D3UVV->GetVec());
	};


	//! Computes the derivative of order Nu in the direction u
	//! and Nv in the direction v.
	//! Raises UndefinedDerivative if the continuity of the surface is not CNu in the u
	//! direction and CNv in the v direction.
	//! Raises RangeError if Nu + Nv < 1 or Nu < 0 or Nv < 0.
	xgp_Vec^ XGeom_SurfaceOfLinearExtrusion::DN(Standard_Real U, Standard_Real V, Standard_Integer Nu, Standard_Integer Nv) {
		gp_Vec* temp = new gp_Vec(NativeHandle()->DN(U, V, Nu, Nv));
		return gcnew xgp_Vec(temp);
	};

	//! Applies the transformation T to this surface of linear extrusion.
	void XGeom_SurfaceOfLinearExtrusion::Transform(xgp_Trsf^ T) {
		NativeHandle()->Transform(*T->GetTrsf());
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
	//! This methods multiplies :
	//! U by BasisCurve()->ParametricTransformation(T)
	//! V by T.ScaleFactor()
	void XGeom_SurfaceOfLinearExtrusion::TransformParameters(Standard_Real% U, Standard_Real% V, xgp_Trsf^ T) {
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
	//! This  methods  returns  a scale
	//! U by BasisCurve()->ParametricTransformation(T)
	//! V by T.ScaleFactor()
	xgp_GTrsf2d^ XGeom_SurfaceOfLinearExtrusion::ParametricTransformation(xgp_Trsf^ T) {
		gp_GTrsf2d* temp = new gp_GTrsf2d(NativeHandle()->ParametricTransformation(*T->GetTrsf()));
		return gcnew xgp_GTrsf2d(temp);
	};

	//! Creates a new object which is a copy of this surface of linear extrusion.
	XGeom_Geometry^ XGeom_SurfaceOfLinearExtrusion::Copy() {
		return gcnew XGeom_Geometry(NativeHandle()->Copy());
	};
}