#include "XGeom_RectangularTrimmedSurface.h"
namespace TKG3d {
	//!
	XGeom_RectangularTrimmedSurface::XGeom_RectangularTrimmedSurface(void) {
		/*NativeHandle() = new Geom_RectangularTrimmedSurface();
		SetBoundedSurfaceHandle(NativeHandle());*/
	};

	//! 
	XGeom_RectangularTrimmedSurface::XGeom_RectangularTrimmedSurface(Handle(Geom_RectangularTrimmedSurface) pos) {
		NativeHandle() = pos;
		SetBoundedSurfaceHandle(NativeHandle());
	};

	//!
	XGeom_RectangularTrimmedSurface::~XGeom_RectangularTrimmedSurface() {
		NativeHandle() = NULL;
		SetBoundedSurfaceHandle(NativeHandle());
	};

	void XGeom_RectangularTrimmedSurface::SetRectangularTrimmedSurfaceHandle(Handle(Geom_RectangularTrimmedSurface) handle) {
		NativeHandle() = handle;
		SetBoundedSurfaceHandle(NativeHandle());
	};

	//!
	Handle(Geom_RectangularTrimmedSurface) XGeom_RectangularTrimmedSurface::GetRectangularTrimmedSurface() {
		return NativeHandle();
	};

	//!
	Handle(Geom_BoundedSurface) XGeom_RectangularTrimmedSurface::GetBoundedSurface() {
		return NativeHandle();
	};

	//!
	Handle(Geom_Surface) XGeom_RectangularTrimmedSurface::GetSurface() {
		return NativeHandle();
	};

	//!
	Handle(Geom_Geometry) XGeom_RectangularTrimmedSurface::GetGeometry() {
		return NativeHandle();
	};

	//! The U parametric direction of the surface is oriented from U1
	//! to U2. The V parametric direction of the surface is oriented
	//! from V1 to V2.
	//! These two directions define the orientation of the surface
	//! (normal). If the surface is not periodic USense and VSense are
	//! not used for the construction. If the surface S is periodic in
	//! one direction USense and VSense give the available part of the
	//! surface. By default in this case the surface has the same
	//! orientation as the basis surface S.
	//! The returned surface is not closed and not periodic.
	//! ConstructionError   Raised if
	//! S is not periodic in the UDirection and U1 or U2 are out of the
	//! bounds of S.
	//! S is not periodic in the VDirection and V1 or V2 are out of the
	//! bounds of S.
	//! U1 = U2 or V1 = V2
	//! Standard_Boolean USense = Standard_True, Standard_Boolean VSense = Standard_True
	XGeom_RectangularTrimmedSurface::XGeom_RectangularTrimmedSurface(XGeom_Surface^ S, Standard_Real U1, Standard_Real U2, Standard_Real V1, Standard_Real V2, Standard_Boolean USense, Standard_Boolean VSense) {
		NativeHandle() = new Geom_RectangularTrimmedSurface(S->GetSurface(), U1, U2, V1, V2, USense, VSense);
		SetBoundedSurfaceHandle(NativeHandle());
	};


	//! The basis surface S is only trim in one parametric direction.
	//! If UTrim = True the surface is trimmed in the U parametric
	//! direction else the surface is trimmed in the V parametric
	//! direction.
	//! In the considered parametric direction the resulting surface is
	//! oriented from Param1 to Param2. If S is periodic Sense gives the
	//! available part of the surface. By default the trimmed surface has
	//! the same orientation as the basis surface S in the considered
	//! parametric direction (Sense = True).
	//! If the basis surface S is closed or periodic in the parametric
	//! direction opposite to the trimming direction the trimmed surface
	//! has the same characteristics as the surface S in this direction.
	//! Warnings :
	//! In this package the entities are not shared.
	//! The RectangularTrimmedSurface is built with a copy of the
	//! surface S. So when S is modified the RectangularTrimmedSurface
	//! is not modified
	//! Raised if
	//! S is not periodic in the considered parametric direction and
	//! Param1 or Param2 are out of the bounds of S.
	//! Param1 = Param2
	//! Standard_Boolean Sense = Standard_True
	XGeom_RectangularTrimmedSurface::XGeom_RectangularTrimmedSurface(XGeom_Surface^ S, Standard_Real Param1, Standard_Real Param2, Standard_Boolean UTrim, Standard_Boolean Sense) {
		NativeHandle() = new Geom_RectangularTrimmedSurface(S->GetSurface(), Param1, Param2, UTrim, Sense);
		SetBoundedSurfaceHandle(NativeHandle());
	};

	//! Modifies this patch by changing the trim values
	//! applied to the original surface
	//! The u parametric direction of
	//! this patch is oriented from U1 to U2. The v
	//! parametric direction of this patch is oriented
	//! from V1 to V2. USense and VSense are used
	//! for the construction only if the surface is periodic
	//! in the corresponding parametric direction, and
	//! define the available part of the surface; by default
	//! in this case, this patch has the same orientation
	//! as the basis surface.
	//! Raised if
	//! The BasisSurface is not periodic in the UDirection and U1 or U2
	//! are out of the bounds of the BasisSurface.
	//! The BasisSurface is not periodic in the VDirection and V1 or V2
	//! are out of the bounds of the BasisSurface.
	//! U1 = U2 or V1 = V2
	//! Standard_Boolean USense = Standard_True, Standard_Boolean VSense = Standard_True
	void XGeom_RectangularTrimmedSurface::SetTrim(Standard_Real U1, Standard_Real U2, Standard_Real V1, Standard_Real V2, Standard_Boolean USense, Standard_Boolean VSense) {
		NativeHandle()->SetTrim(U1, U2, V1, V2, USense, VSense);
	};

	//! Modifies this patch by changing the trim values
	//! applied to the original surface
	//! The basis surface is trimmed only in one parametric direction: if UTrim
	//! is true, the surface is trimmed in the u parametric
	//! direction; if it is false, it is trimmed in the v
	//! parametric direction. In the "trimmed" direction,
	//! this patch is oriented from Param1 to Param2. If
	//! the basis surface is periodic in the "trimmed"
	//! direction, Sense defines its available part. By
	//! default in this case, this patch has the same
	//! orientation as the basis surface in this parametric
	//! direction. If the basis surface is closed or periodic
	//! in the other parametric direction (i.e. not the
	//! "trimmed" direction), this patch has the same
	//! characteristics as the basis surface in that parametric direction.
	//! Raised if
	//! The BasisSurface is not periodic in the considered direction and
	//! Param1 or Param2 are out of the bounds of the BasisSurface.
	//! Param1 = Param2
	//!  Standard_Boolean Sense = Standard_True
	void XGeom_RectangularTrimmedSurface::SetTrim(Standard_Real Param1, Standard_Real Param2, Standard_Boolean UTrim, Standard_Boolean Sense) {
		NativeHandle()->SetTrim(Param1, Param2, UTrim, Sense);
	};

	//! Returns the Basis surface of <me>.
	XGeom_Surface^ XGeom_RectangularTrimmedSurface::BasisSurface() {
		return gcnew XGeom_Surface(NativeHandle()->BasisSurface());
	};

	//! Changes the orientation of this patch in the u
	//! parametric direction. The bounds of the surface are
	//! not changed, but the given parametric direction is
	//! reversed. Hence the orientation of the surface is reversed.
	void XGeom_RectangularTrimmedSurface::UReverse() {
		NativeHandle()->UReverse();
	};

	//! Computes the u  parameter on the modified
	//! surface, produced by when reversing its u
	//! parametric direction, for any point of u parameter U on this patch.
	Standard_Real XGeom_RectangularTrimmedSurface::UReversedParameter(Standard_Real U) {
		return NativeHandle()->UReversedParameter(U);
	};

	//! Changes the orientation of this patch in the v
	//! parametric direction. The bounds of the surface are
	//! not changed, but the given parametric direction is
	//! reversed. Hence the orientation of the surface is reversed.
	void XGeom_RectangularTrimmedSurface::VReverse() {
		NativeHandle()->VReverse();
	};

	//! Computes the v  parameter on the modified
	//! surface, produced by when reversing its v
	//! parametric direction, for any point of v parameter V on this patch.
	Standard_Real XGeom_RectangularTrimmedSurface::VReversedParameter(Standard_Real V) {
		return NativeHandle()->VReversedParameter(V);
	};

	//! Returns the parametric bounds U1, U2, V1 and V2 of this patch.
	void XGeom_RectangularTrimmedSurface::Bounds(Standard_Real% U1, Standard_Real% U2, Standard_Real% V1, Standard_Real% V2) {
		Standard_Real XU1 = Standard_Real(U1); Standard_Real XU2 = Standard_Real(U2); Standard_Real XV1 = Standard_Real(V1); Standard_Real XV2 = Standard_Real(V2);
		NativeHandle()->Bounds(XU1, XU2, XV1, XV2);
		U1 = XU1; U2 = XU2; V1 = XV1; V2 = XV2;
	};


	//! Returns  the continuity of the surface :
	//! C0 : only geometric continuity,
	//! C1 : continuity of the first derivative all along the Surface,
	//! C2 : continuity of the second derivative all along the Surface,
	//! C3 : continuity of the third derivative all along the Surface,
	//! CN : the order of continuity is infinite.
	XGeomAbs_Shape XGeom_RectangularTrimmedSurface::Continuity() {
		return safe_cast<XGeomAbs_Shape>(NativeHandle()->Continuity());
	};

	//! Returns true if this patch is closed in the given parametric direction.
	Standard_Boolean XGeom_RectangularTrimmedSurface::IsUClosed() {
		return NativeHandle()->IsUClosed();
	};

	//! Returns true if this patch is closed in the given parametric direction.
	Standard_Boolean XGeom_RectangularTrimmedSurface::IsVClosed() {
		return NativeHandle()->IsVClosed();
	};


	//! Returns true if the order of derivation in the U parametric
	//! direction is N.
	//! Raised if N < 0.
	Standard_Boolean XGeom_RectangularTrimmedSurface::IsCNu(Standard_Integer N) {
		return NativeHandle()->IsCNu(N);
	};


	//! Returns true if the order of derivation in the V parametric
	//! direction is N.
	//! Raised if N < 0.
	Standard_Boolean XGeom_RectangularTrimmedSurface::IsCNv(Standard_Integer N) {
		return NativeHandle()->IsCNv(N);
	};

	//! Returns true if this patch is periodic and not trimmed in the given
	//! parametric direction.
	Standard_Boolean XGeom_RectangularTrimmedSurface::IsUPeriodic() {
		return NativeHandle()->IsUPeriodic();
	};

	//! Returns the period of this patch in the u
	//! parametric direction.
	//! raises if the surface is not uperiodic.
	Standard_Real XGeom_RectangularTrimmedSurface::UPeriod() {
		return NativeHandle()->UPeriod();
	};


	//! Returns true if this patch is periodic and not trimmed in the given
	//! parametric direction.
	Standard_Boolean XGeom_RectangularTrimmedSurface::IsVPeriodic() {
		return NativeHandle()->IsVPeriodic();
	};

	//! Returns the period of this patch in the v
	//! parametric direction.
	//! raises if the surface is not vperiodic.
	//! value and derivatives
	Standard_Real XGeom_RectangularTrimmedSurface::VPeriod() {
		return NativeHandle()->VPeriod();
	};

	//! computes the U isoparametric curve.
	XGeom_Curve^ XGeom_RectangularTrimmedSurface::UIso(Standard_Real U) {
		return gcnew XGeom_Curve(NativeHandle()->UIso(U));
	};

	//! Computes the V isoparametric curve.
	XGeom_Curve^ XGeom_RectangularTrimmedSurface::VIso(Standard_Real V) {
		return gcnew XGeom_Curve(NativeHandle()->VIso(V));
	};


	//! Can be raised if the basis surface is an OffsetSurface.
	void XGeom_RectangularTrimmedSurface::D0(Standard_Real U, Standard_Real V, xgp_Pnt^ P) {
		NativeHandle()->D0(U, V, *P->GetPnt());
	};


	//! The returned derivatives have the same orientation as the
	//! derivatives of the basis surface even if the trimmed surface
	//! has not the same parametric orientation.
	//! Warning!  UndefinedDerivative  raised if the continuity of the surface is not C1.
	void XGeom_RectangularTrimmedSurface::D1(Standard_Real U, Standard_Real V, xgp_Pnt^ P, xgp_Vec^ D1U, xgp_Vec^ D1V) {
		NativeHandle()->D1(U, V, *P->GetPnt(), *D1U->GetVec(), *D1V->GetVec());
	};


	//! The returned derivatives have the same orientation as the
	//! derivatives of the basis surface even if the trimmed surface
	//! has not the same parametric orientation.
	//! Warning! UndefinedDerivative raised if the continuity of the surface is not C2.
	void XGeom_RectangularTrimmedSurface::D2(Standard_Real U, Standard_Real V, xgp_Pnt^ P, xgp_Vec^ D1U, xgp_Vec^ D1V, xgp_Vec^ D2U, xgp_Vec^ D2V, xgp_Vec^ D2UV) {
		NativeHandle()->D2(U, V, *P->GetPnt(), *D1U->GetVec(), *D1V->GetVec(), *D2U->GetVec(), *D2V->GetVec(), *D2UV->GetVec());
	};

	//! The returned derivatives have the same orientation as the
	//! derivatives of the basis surface even if the trimmed surface
	//! has not the same parametric orientation.
	//! Warning UndefinedDerivative raised if the continuity of the surface is not C3.
	void XGeom_RectangularTrimmedSurface::D3(Standard_Real U, Standard_Real V, xgp_Pnt^ P, xgp_Vec^ D1U, xgp_Vec^ D1V, xgp_Vec^ D2U, xgp_Vec^ D2V, xgp_Vec^ D2UV, xgp_Vec^ D3U, xgp_Vec^ D3V, xgp_Vec^ D3UUV, xgp_Vec^ D3UVV) {
		NativeHandle()->D3(U, V, *P->GetPnt(), *D1U->GetVec(), *D1V->GetVec(), *D2U->GetVec(), *D2V->GetVec(), *D2UV->GetVec(), *D3U->GetVec(), *D3V->GetVec(), *D3UUV->GetVec(), *D3UVV->GetVec());
	};

	//! The returned derivative has the same orientation as the
	//! derivative of the basis surface even if the trimmed surface
	//! has not the same parametric orientation.
	//! Warning!  UndefinedDerivative raised if the continuity of the surface is not CNu in the U
	//! parametric direction and CNv in the V parametric direction.
	//! RangeError Raised if Nu + Nv < 1 or Nu < 0 or Nv < 0.
	xgp_Vec^ XGeom_RectangularTrimmedSurface::DN(Standard_Real U, Standard_Real V, Standard_Integer Nu, Standard_Integer Nv) {
		gp_Vec* temp = new gp_Vec(NativeHandle()->DN(U, V, Nu, Nv));
		return gcnew xgp_Vec(temp);
	};

	//! Applies the transformation T to this patch.
	//! Warning
	//! As a consequence, the basis surface included in the
	//! data structure of this patch is also modified.
	void XGeom_RectangularTrimmedSurface::Transform(xgp_Trsf^ T) {
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
	//! This methods calls the basis surface method.
	void XGeom_RectangularTrimmedSurface::TransformParameters(Standard_Real% U, Standard_Real% V, xgp_Trsf^ T) {
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
	//! This methods calls the basis surface method.
	xgp_GTrsf2d^ XGeom_RectangularTrimmedSurface::ParametricTransformation(xgp_Trsf^ T) {
		gp_GTrsf2d* temp = new gp_GTrsf2d(NativeHandle()->ParametricTransformation(*T->GetTrsf()));
		return gcnew xgp_GTrsf2d(temp);
	};

	//! Creates a new object which is a copy of this patch.
	XGeom_Geometry^ XGeom_RectangularTrimmedSurface::Copy() {
		return gcnew XGeom_Geometry(NativeHandle()->Copy());
	};
}