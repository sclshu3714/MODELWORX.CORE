#include "XGeom_OffsetSurface.h"
namespace TKG3d
{

	//!
	XGeom_OffsetSurface::XGeom_OffsetSurface(void) {
		//NativeHandle() = new Geom_OffsetSurface();
	};

	//! 
	XGeom_OffsetSurface::XGeom_OffsetSurface(Handle(Geom_OffsetSurface) pos) {
		NativeHandle() = pos;
		SetSurfaceHandle(NativeHandle());
	};

	//!
	XGeom_OffsetSurface::~XGeom_OffsetSurface() {
		NativeHandle() = NULL;
		SetSurfaceHandle(NativeHandle());
	};

	void XGeom_OffsetSurface::SetOffsetSurfaceHandle(Handle(Geom_OffsetSurface) handle) {
		NativeHandle() = handle;
		SetSurfaceHandle(NativeHandle());
	};

	//!
	Handle(Geom_OffsetSurface) XGeom_OffsetSurface::GetOffsetSurface() {
		return NativeHandle();
	};

	//!
	Handle(Geom_Surface) XGeom_OffsetSurface::GetSurface() {
		return NativeHandle();
	};

	//!
	Handle(Geom_Geometry) XGeom_OffsetSurface::GetGeometry() {
		return NativeHandle();
	};

	//! Constructs a surface offset from the basis surface
	//! S, where Offset is the distance between the offset
	//! surface and the basis surface at any point.
	//! A point on the offset surface is built by measuring
	//! the offset value along a normal vector at a point on
	//! S. This normal vector is given by the cross product
	//! D1u^D1v, where D1u and D1v are the vectors
	//! tangential to the basis surface in the u and v
	//! parametric directions at this point. The side of S on
	//! which the offset value is measured is indicated by
	//! this normal vector if Offset is positive, or is the
	//! inverse sense if Offset is negative.
	//! If isNotCheckC0 = TRUE checking if basis surface has C0-continuity
	//! is not made.
	//! Warnings :
	//! - The offset surface is built with a copy of the
	//! surface S. Therefore, when S is modified the
	//! offset surface is not modified.
	//! - No check is made at the time of construction to
	//! detect points on S with multiple possible normal directions.
	//! Raised if S is not at least C1.
	//! Warnings :
	//! No check is done to verify that a unique normal direction is
	//! defined at any point of the basis surface S.
	//! Standard_Boolean isNotCheckC0 = Standard_False
	XGeom_OffsetSurface::XGeom_OffsetSurface(XGeom_Surface^ S, Standard_Real Offset, Standard_Boolean isNotCheckC0) {
		NativeHandle() = new Geom_OffsetSurface(S->GetSurface(), Offset, isNotCheckC0);
		SetSurfaceHandle(NativeHandle());
	};

	//! Raised if S is not at least C1.
	//! Warnings :
	//! No check is done to verify that a unique normal direction is
	//! defined at any point of the basis surface S.
	//! If isNotCheckC0 = TRUE checking if basis surface has C0-continuity
	//! is not made.
	//! Exceptions
	//! Standard_ConstructionError if the surface S is not
	//! at least "C1" continuous.
	//! Standard_Boolean isNotCheckC0 = Standard_False
	void XGeom_OffsetSurface::SetBasisSurface(XGeom_Surface^ S, Standard_Boolean isNotCheckC0) {
		NativeHandle()->SetBasisSurface(S->GetSurface(), isNotCheckC0);
	};

	//! Changes this offset surface by assigning D as the offset value.
	void XGeom_OffsetSurface::SetOffsetValue(Standard_Real D) {
		NativeHandle()->SetOffsetValue(D);
	};

	//! Returns the offset value of this offset surface.
	Standard_Real XGeom_OffsetSurface::Offset() {
		return NativeHandle()->Offset();
	};

	//! Returns the basis surface of this offset surface.
	//! Note: The basis surface can be an offset surface.
	XGeom_Surface^ XGeom_OffsetSurface::BasisSurface() {
		return gcnew XGeom_Surface(NativeHandle()->BasisSurface());
	};

	//! Returns osculating surface if base surface is B-spline or Bezier
	XGeom_OsculatingSurface^ XGeom_OffsetSurface::OsculatingSurface() {
		return gcnew XGeom_OsculatingSurface(NativeHandle()->OsculatingSurface());
	};

	//! Changes the orientation of this offset surface in the u
	//! parametric direction. The bounds of the surface
	//! are not changed but the given parametric direction is reversed.
	void XGeom_OffsetSurface::UReverse() {
		NativeHandle()->UReverse();
	};

	//! Computes the u  parameter on the modified
	//! surface, produced by reversing the u
	//! parametric direction of this offset surface, for any
	//! point of u parameter U  on this offset surface.
	Standard_Real XGeom_OffsetSurface::UReversedParameter(Standard_Real U) {
		return NativeHandle()->UReversedParameter(U);
	};

	//! Changes the orientation of this offset surface in the v parametric direction. The bounds of the surface
	//! are not changed but the given parametric direction is reversed.
	void XGeom_OffsetSurface::VReverse() {
		NativeHandle()->VReverse();
	};

	//! Computes the  v parameter on the modified
	//! surface, produced by reversing the or v
	//! parametric direction of this offset surface, for any
	//! point of  v parameter V on this offset surface.
	Standard_Real XGeom_OffsetSurface::VReversedParameter(Standard_Real V) {
		return NativeHandle()->VReversedParameter(V);
	};

	//! Returns the parametric bounds U1, U2, V1 and V2 of
	//! this offset surface.
	//! If the surface is infinite, this function can return:
	//! - Standard_Real::RealFirst(), or
	//! - Standard_Real::RealLast().
	void XGeom_OffsetSurface::Bounds(Standard_Real% U1, Standard_Real% U2, Standard_Real% V1, Standard_Real% V2) {
		Standard_Real XU1 = Standard_Real(U1); Standard_Real XU2 = Standard_Real(U2); Standard_Real XV1 = Standard_Real(V1); Standard_Real XV2 = Standard_Real(V2);
		NativeHandle()->Bounds(XU1, XU2, XV1, XV2);
		U1 = XU1; U2 = XU2; V1 = XV1; V2 = XV2;
	};


	//! This method returns the continuity of the basis surface - 1.
	//! Continuity of the Offset surface :
	//! C0 : only geometric continuity,
	//! C1 : continuity of the first derivative all along the Surface,
	//! C2 : continuity of the second derivative all along the Surface,
	//! C3 : continuity of the third derivative all along the Surface,
	//! CN : the order of continuity is infinite.
	//! Example :
	//! If the basis surface is C2 in the V direction and C3 in the U
	//! direction Shape = C1.
	//! Warnings :
	//! If the basis surface has a unique normal direction defined at
	//! any point this method gives the continuity of the offset
	//! surface otherwise the effective continuity can be lower than
	//! the continuity of the basis surface - 1.
	XGeomAbs_Shape XGeom_OffsetSurface::Continuity() {
		return safe_cast<XGeomAbs_Shape>(NativeHandle()->Continuity());
	};


	//! This method answer True if the continuity of the basis surface
	//! is N + 1 in the U parametric direction. We suppose in this
	//! class that a unique normal is defined at any point on the basis
	//! surface.
	//! Raised if N <0.
	Standard_Boolean XGeom_OffsetSurface::IsCNu(Standard_Integer N) {
		return NativeHandle()->IsCNu(N);
	};


	//! This method answer True if the continuity of the basis surface
	//! is N + 1 in the V parametric direction. We suppose in this
	//! class that a unique normal is defined at any point on the basis
	//! surface.
	//! Raised if N <0.
	Standard_Boolean XGeom_OffsetSurface::IsCNv(Standard_Integer N) {
		return NativeHandle()->IsCNv(N);
	};

	//! Checks whether this offset surface is closed in the u
	//! parametric direction.
	//! Returns true if, taking uFirst and uLast as
	//! the parametric bounds in the u parametric direction,
	//! the distance between the points P(uFirst,v)
	//! and P(uLast,v) is less than or equal to
	//! gp::Resolution() for each value of the   parameter v.
	Standard_Boolean XGeom_OffsetSurface::IsUClosed() {
		return NativeHandle()->IsUClosed();
	};

	//! Checks whether this offset surface is closed in the u
	//! or v parametric direction. Returns true if taking vFirst and vLast as the
	//! parametric bounds in the v parametric direction, the
	//! distance between the points P(u,vFirst) and
	//! P(u,vLast) is less than or equal to
	//! gp::Resolution() for each value of the parameter u.
	Standard_Boolean XGeom_OffsetSurface::IsVClosed() {
		return NativeHandle()->IsVClosed();
	};


	//! Returns true if this offset surface is periodic in the u
	//! parametric direction, i.e. if the basis
	//! surface of this offset surface is periodic in this direction.
	Standard_Boolean XGeom_OffsetSurface::IsUPeriodic() {
		return NativeHandle()->IsUPeriodic();
	};

	//! Returns the period of this offset surface in the u
	//! parametric direction respectively, i.e. the period of the
	//! basis surface of this offset surface in this parametric direction.
	//! raises if the surface is not uperiodic.
	Standard_Real XGeom_OffsetSurface::UPeriod() {
		return NativeHandle()->UPeriod();
	};


	//! Returns true if this offset surface is periodic in the v
	//! parametric direction, i.e. if the basis
	//! surface of this offset surface is periodic in this direction.
	Standard_Boolean XGeom_OffsetSurface::IsVPeriodic() {
		return NativeHandle()->IsVPeriodic();
	};

	//! Returns the period of this offset surface in the v
	//! parametric direction respectively, i.e. the period of the
	//! basis surface of this offset surface in this parametric direction.
	//! raises if the surface is not vperiodic.
	Standard_Real XGeom_OffsetSurface::VPeriod() {
		return NativeHandle()->VPeriod();
	};

	//! Computes the U isoparametric curve.
	XGeom_Curve^ XGeom_OffsetSurface::UIso(Standard_Real U) {
		return gcnew XGeom_Curve(NativeHandle()->UIso(U));
	};

	//! Computes the V isoparametric curve.
	//!
	//! Te followings methods compute value and derivatives.
	//!
	//! Warnings
	//! An exception is raised if a unique normal vector is
	//! not defined on the basis surface for the parametric
	//! value (U,V).
	//! No check is done at the creation time and we suppose
	//! in this package that the offset surface can be defined
	//! at any point.
	XGeom_Curve^ XGeom_OffsetSurface::VIso(Standard_Real V) {
		return gcnew XGeom_Curve(NativeHandle()->VIso(V));
	};


	//! P (U, V) = Pbasis + Offset * Ndir   where
	//! Ndir = D1Ubasis ^ D1Vbasis / ||D1Ubasis ^ D1Vbasis|| is the
	//! normal direction of the basis surface. Pbasis, D1Ubasis,
	//! D1Vbasis are the point and the first derivatives on the basis
	//! surface.
	//! If Ndir is undefined this method computes an approched normal
	//! direction using the following limited development :
	//! Ndir = N0 + DNdir/DU + DNdir/DV + Eps with Eps->0 which
	//! requires to compute the second derivatives on the basis surface.
	//! If the normal direction cannot be approximate for this order
	//! of derivation the exception UndefinedValue is raised.
	//!
	//! Raised if the continuity of the basis surface is not C1.
	//! Raised if the order of derivation required to compute the
	//! normal direction is greater than the second order.
	void XGeom_OffsetSurface::D0(Standard_Real U, Standard_Real V, xgp_Pnt^ P) {
		NativeHandle()->D0(U, V, *P->GetPnt());
	};


	//! Raised if the continuity of the basis surface is not C2.
	void XGeom_OffsetSurface::D1(Standard_Real U, Standard_Real V, xgp_Pnt^ P, xgp_Vec^ D1U, xgp_Vec^ D1V) {
		NativeHandle()->D1(U, V, *P->GetPnt(), *D1U->GetVec(), *D1V->GetVec());
	};

	//! ---Purpose ;
	//! Raised if the continuity of the basis surface is not C3.
	void XGeom_OffsetSurface::D2(Standard_Real U, Standard_Real V, xgp_Pnt^ P, xgp_Vec^ D1U, xgp_Vec^ D1V, xgp_Vec^ D2U, xgp_Vec^ D2V, xgp_Vec^ D2UV) {
		NativeHandle()->D2(U, V, *P->GetPnt(), *D1U->GetVec(), *D1V->GetVec(), *D2U->GetVec(), *D2V->GetVec(), *D2UV->GetVec());
	};


	//! Raised if the continuity of the basis surface is not C4.
	void XGeom_OffsetSurface::D3(Standard_Real U, Standard_Real V, xgp_Pnt^ P, xgp_Vec^ D1U, xgp_Vec^ D1V, xgp_Vec^ D2U, xgp_Vec^ D2V, xgp_Vec^ D2UV, xgp_Vec^ D3U, xgp_Vec^ D3V, xgp_Vec^ D3UUV, xgp_Vec^ D3UVV) {
		NativeHandle()->D3(U, V, *P->GetPnt(), *D1U->GetVec(), *D1V->GetVec(), *D2U->GetVec(), *D2V->GetVec(), *D2UV->GetVec(), *D3U->GetVec(), *D3V->GetVec(), *D3UUV->GetVec(), *D3UVV->GetVec());
	};


	//! Computes the derivative of order Nu in the direction u and Nv
	//! in the direction v.
	//! ---Purpose ;
	//! Raised if the continuity of the basis surface is not CNu + 1
	//! in the U direction and CNv + 1 in the V direction.
	//! Raised if Nu + Nv < 1 or Nu < 0 or Nv < 0.
	//!
	//! The following methods compute the value and derivatives
	//! on the offset surface and returns the derivatives on the
	//! basis surface too.
	//! The computation of the value and derivatives on the basis
	//! surface are used to evaluate the offset surface.
	//!
	//! Warnings :
	//! The exception UndefinedValue or UndefinedDerivative is
	//! raised if it is not possible to compute a unique offset
	//! direction.
	xgp_Vec^ XGeom_OffsetSurface::DN(Standard_Real U, Standard_Real V, Standard_Integer Nu, Standard_Integer Nv) {
		gp_Vec* temp = new gp_Vec(NativeHandle()->DN(U, V, Nu, Nv));
		return gcnew xgp_Vec(temp);
	};

	//! Applies the transformation T to this offset surface.
	//! Note: the basis surface is also modified.
	void XGeom_OffsetSurface::Transform(xgp_Trsf^ T) {
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
	//! This methods calls the basis surface method.
	void XGeom_OffsetSurface::TransformParameters(Standard_Real% U, Standard_Real% V, xgp_Trsf^ T) {
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
	xgp_GTrsf2d^ XGeom_OffsetSurface::ParametricTransformation(xgp_Trsf^ T) {
		gp_GTrsf2d* temp = new gp_GTrsf2d(NativeHandle()->ParametricTransformation(*T->GetTrsf()));
		return gcnew xgp_GTrsf2d(temp);
	};

	//! Creates a new object which is a copy of this offset surface.
	XGeom_Geometry^ XGeom_OffsetSurface::Copy() {
		return gcnew XGeom_Geometry(NativeHandle()->Copy());
	};

	//! returns an  equivalent surface of the offset surface
	//! when  the basis surface   is a canonic  surface or a
	//! rectangular  limited surface on canonic surface or if
	//! the offset is null.
	XGeom_Surface^ XGeom_OffsetSurface::Surface() {
		return gcnew XGeom_Surface(NativeHandle()->Surface());
	};

	//! if Standard_True, L is  the local osculating surface
	//! along U at  the point U,V.   It means that  DL/DU is
	//! collinear to DS/DU .  If IsOpposite == Standard_True
	//! these vectors have opposite direction.
	Standard_Boolean XGeom_OffsetSurface::UOsculatingSurface(Standard_Real U, Standard_Real V, Standard_Boolean% IsOpposite, XGeom_BSplineSurface^% UOsculSurf) {
		Standard_Boolean XIsOpposite = IsOpposite; Handle(Geom_BSplineSurface) XUOsculSurf = UOsculSurf->GetBSplineSurface();
		Standard_Boolean IsUOsculatingSurface = NativeHandle()->UOsculatingSurface(U, V, XIsOpposite, XUOsculSurf);
		IsOpposite = XIsOpposite; UOsculSurf = gcnew XGeom_BSplineSurface(XUOsculSurf);
		return IsUOsculatingSurface;
	};

	//! if Standard_True, L is the local osculating surface
	//! along V at the point U,V.
	//! It means that  DL/DV is
	//! collinear to DS/DV .  If IsOpposite == Standard_True
	//! these vectors have opposite direction.
	Standard_Boolean XGeom_OffsetSurface::VOsculatingSurface(Standard_Real U, Standard_Real V, Standard_Boolean% IsOpposite, XGeom_BSplineSurface^% VOsculSurf) {
		Standard_Boolean XIsOpposite = IsOpposite; Handle(Geom_BSplineSurface) XVOsculSurf = VOsculSurf->GetBSplineSurface();
		Standard_Boolean IsVOsculatingSurface = NativeHandle()->UOsculatingSurface(U, V, XIsOpposite, XVOsculSurf);
		IsOpposite = XIsOpposite; VOsculSurf = gcnew XGeom_BSplineSurface(XVOsculSurf);
		return IsVOsculatingSurface;
	};

	//! Returns continuity of the basis surface.
	XGeomAbs_Shape XGeom_OffsetSurface::GetBasisSurfContinuity() {
		return safe_cast<XGeomAbs_Shape>(NativeHandle()->GetBasisSurfContinuity());
	};
}
