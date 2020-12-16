#include <XGeom_OffsetCurve.h>
namespace TKG3d {
	XGeom_OffsetCurve::XGeom_OffsetCurve() {
		//NativeHandle() = new Geom_OffsetCurve();
	};

	//! 
	XGeom_OffsetCurve::XGeom_OffsetCurve(Handle(Geom_OffsetCurve) pos) {
		NativeHandle() = pos;
		SetCurveHandle(NativeHandle());
	};

	//!
	XGeom_OffsetCurve::~XGeom_OffsetCurve() {
		NativeHandle() = NULL;
		SetCurveHandle(NativeHandle());
	};

	void XGeom_OffsetCurve::SetOffsetCurveHandle(Handle(Geom_OffsetCurve) pos) {
		NativeHandle() = pos;
		SetCurveHandle(NativeHandle());
	};

	Handle(Geom_OffsetCurve) XGeom_OffsetCurve::GetOffsetCurve() {
		return NativeHandle();
	};

	//!
	Handle(Geom_Curve) XGeom_OffsetCurve::GetCurve() {
		return NativeHandle();
	};

	//!
	Handle(Geom_Geometry) XGeom_OffsetCurve::GetGeometry() {
		return NativeHandle();
	};

	//! C is the basis curve, Offset is the distance between <me> and
	//! the basis curve at any point. V defines the fixed reference
	//! direction (offset direction). If P is a point on the basis
	//! curve and T the first derivative with non zero length
	//! at this point, the corresponding point on the offset curve is
	//! in the direction of the vector-product N = V ^ T   where
	//! N is a unitary vector.
	//! If isNotCheckC0 = TRUE checking if basis curve has C0-continuity
	//! is not made.
	//! Warnings :
	//! In this package the entities are not shared. The OffsetCurve is
	//! built with a copy of the curve C. So when C is modified the
	//! OffsetCurve is not modified
	//!
	//! Raised if the basis curve C is not at least C1.
	//! Warnings :
	//! No check is done to know if ||V^T|| != 0.0 at any point.
	//!  Standard_Boolean isNotCheckC0 = Standard_False
	XGeom_OffsetCurve::XGeom_OffsetCurve(XGeom_Curve^ C, Standard_Real Offset, xgp_Dir^ V, Standard_Boolean isNotCheckC0) {
		NativeHandle() = new Geom_OffsetCurve(C->GetCurve(), Offset, *V->GetDir(), isNotCheckC0);
		SetCurveHandle(NativeHandle());
	};

	//! Changes the orientation of this offset curve.
	//! As a result:
	//! - the basis curve is reversed,
	//! - the start point of the initial curve becomes the
	//! end point of the reversed curve,
	//! - the end point of the initial curve becomes the
	//! start point of the reversed curve, and
	//! - the first and last parameters are recomputed.
	void XGeom_OffsetCurve::Reverse() {
		NativeHandle()->Reverse();
	};

	//! Computes the parameter on the reversed curve for
	//! the point of parameter U on this offset curve.
	Standard_Real XGeom_OffsetCurve::ReversedParameter(Standard_Real U) {
		return NativeHandle()->ReversedParameter(U);
	};

	//! Changes this offset curve by assigning C
	//! as the basis curve from which it is built.
	//! If isNotCheckC0 = TRUE checking if basis curve
	//! has C0-continuity is not made.
	//! Exceptions
	//! Standard_ConstructionError if the curve C is not at least "C1" continuous.
	//! Standard_Boolean isNotCheckC0 = Standard_False
	void XGeom_OffsetCurve::SetBasisCurve(XGeom_Curve^ C, Standard_Boolean isNotCheckC0) {
		NativeHandle()->SetBasisCurve(C->GetCurve(), isNotCheckC0);
	};

	//! Changes this offset curve by assigning V as the
	//! reference vector used to compute the offset direction.
	void XGeom_OffsetCurve::SetDirection(xgp_Dir^ V) {
		NativeHandle()->SetDirection(*V->GetDir());
	};

	//! Changes this offset curve by assigning D as the offset value.
	void XGeom_OffsetCurve::SetOffsetValue(Standard_Real D) {
		NativeHandle()->SetOffsetValue(D);
	};

	//! Returns the basis curve of this offset curve.
	//! Note: The basis curve can be an offset curve.
	XGeom_Curve^ XGeom_OffsetCurve::BasisCurve() {
		return gcnew XGeom_Curve(NativeHandle()->BasisCurve());
	};

	//! Returns the global continuity of this offset curve as a
	//! value of the GeomAbs_Shape enumeration.
	//! The degree of continuity of this offset curve is equal
	//! to the degree of continuity of the basis curve minus 1.
	//! Continuity of the Offset curve :
	//! C0 : only geometric continuity,
	//! C1 : continuity of the first derivative all along the Curve,
	//! C2 : continuity of the second derivative all along the Curve,
	//! C3 : continuity of the third derivative all along the Curve,
	//! G1 : tangency continuity all along the Curve,
	//! G2 : curvature continuity all along the Curve,
	//! CN : the order of continuity is infinite.
	//! Warnings :
	//! Returns the continuity of the basis curve - 1.
	//! The offset curve must have a unique offset direction defined
	//! at any point.
	XGeomAbs_Shape XGeom_OffsetCurve::Continuity() {
		return safe_cast<XGeomAbs_Shape>(NativeHandle()->Continuity());
	};

	//! Returns the reference vector of this offset curve.
	//! Value and derivatives
	//! Warnings :
	//! The exception UndefinedValue or UndefinedDerivative is
	//! raised if it is not possible to compute a unique offset
	//! direction.
	//! If T is the first derivative with not null length and
	//! V the offset direction the relation ||T(U) ^ V|| != 0
	//! must be satisfied to evaluate the offset curve.
	//! No check is done at the creation time and we suppose
	//! in this package that the offset curve is well defined.
	xgp_Dir^ XGeom_OffsetCurve::Direction() {
		gp_Dir* temp = new gp_Dir(NativeHandle()->Direction());
		return gcnew xgp_Dir(temp);
	};

	//! Warning! this should not be called
	//! if the basis curve is not at least C1. Nevertheless
	//! if used on portion where the curve is C1, it is OK
	void XGeom_OffsetCurve::D0(Standard_Real U, xgp_Pnt^ P) {
		NativeHandle()->D0(U, *P->GetPnt());
	};

	//! Warning! this should not be called
	//! if the continuity of the basis curve is not C2.
	//! Nevertheless, it's OK to use it  on portion
	//! where the curve is C2
	void XGeom_OffsetCurve::D1(Standard_Real U, xgp_Pnt^ P, xgp_Vec^ V1) {
		NativeHandle()->D1(U, *P->GetPnt(), *V1->GetVec());
	};

	//! Warning! this should not be called
	//! if the continuity of the basis curve is not C3.
	//! Nevertheless, it's OK to use it  on portion
	//! where the curve is C3
	void XGeom_OffsetCurve::D2(Standard_Real U, xgp_Pnt^ P, xgp_Vec^ V1, xgp_Vec^ V2) {
		NativeHandle()->D2(U, *P->GetPnt(), *V1->GetVec(), *V2->GetVec());
	};

	void XGeom_OffsetCurve::D3(Standard_Real U, xgp_Pnt^ P, xgp_Vec^ V1, xgp_Vec^ V2, xgp_Vec^ V3) {
		NativeHandle()->D3(U, *P->GetPnt(), *V1->GetVec(), *V2->GetVec(), *V3->GetVec());
	};


	//! The returned vector gives the value of the derivative
	//! for the order of derivation N.
	//!
	//! The following functions compute the value and derivatives
	//! on the offset curve and returns the derivatives on the
	//! basis curve too.
	//! The computation of the value and derivatives on the basis
	//! curve are used to evaluate the offset curve
	//!
	//! Warning:
	//! The exception UndefinedValue or UndefinedDerivative is
	//! raised if it is not possible to compute a unique offset
	//! direction.
	//! Raised if N < 1.
	xgp_Vec^ XGeom_OffsetCurve::DN(Standard_Real U, Standard_Integer N) {
		gp_Vec* temp = new gp_Vec(NativeHandle()->DN(U, N));
		return gcnew xgp_Vec(temp);
	};

	//! Returns the value of the first parameter of this
	//! offset curve. The first parameter corresponds to the
	//! start point of the curve.
	//! Note: the first and last parameters of this offset curve
	//! are also the ones of its basis curve.
	Standard_Real XGeom_OffsetCurve::FirstParameter() {
		return NativeHandle()->FirstParameter();
	};

	//! Returns the value of the last parameter of this
	//! offset curve. The last parameter
	//! corresponds to the end point.
	//! Note: the first and last parameters of this offset curve
	//! are also the ones of its basis curve.
	Standard_Real XGeom_OffsetCurve::LastParameter() {
		return NativeHandle()->LastParameter();
	};

	//! Returns the offset value of this offset curve.
	Standard_Real XGeom_OffsetCurve::Offset() {
		return NativeHandle()->Offset();
	};

	//! Returns True if the distance between the start point
	//! and the end point of the curve is lower or equal to
	//! Resolution from package gp.
	Standard_Boolean XGeom_OffsetCurve::IsClosed() {
		return NativeHandle()->IsClosed();
	};

	//! Returns true if the degree of continuity of the basis
	//! curve of this offset curve is at least N + 1.
	//! This method answer True if the continuity of the basis curve
	//! is N + 1.  We suppose in this class that a normal direction
	//! to the basis curve (used to compute the offset curve) is
	//! defined at any point on the basis curve.
	//! Raised if N < 0.
	Standard_Boolean XGeom_OffsetCurve::IsCN(Standard_Integer N) {
		return NativeHandle()->IsCN(N);
	};

	//! Returns true if this offset curve is periodic, i.e. if the
	//! basis curve of this offset curve is periodic.
	Standard_Boolean XGeom_OffsetCurve::IsPeriodic() {
		return NativeHandle()->IsPeriodic();
	};

	//! Returns the period of this offset curve, i.e. the period
	//! of the basis curve of this offset curve.
	//! Exceptions
	//! Standard_NoSuchObject if the basis curve is not periodic.
	Standard_Real XGeom_OffsetCurve::Period() {
		return NativeHandle()->Period();
	};

	//! Applies the transformation T to this offset curve.
	//! Note: the basis curve is also modified.
	void XGeom_OffsetCurve::Transform(xgp_Trsf^ T) {
		NativeHandle()->Transform(*T->GetTrsf());
	};

	//! Returns the  parameter on the  transformed  curve for
	//! the transform of the point of parameter U on <me>.
	//! me->Transformed(T)->Value(me->TransformedParameter(U,T))
	//! is the same point as
	//! me->Value(U).Transformed(T)
	//! This methods calls the basis curve method.
	Standard_Real XGeom_OffsetCurve::TransformedParameter(Standard_Real U, xgp_Trsf^ T) {
		return NativeHandle()->TransformedParameter(U, *T->GetTrsf());
	};

	//! Returns a  coefficient to compute the parameter on
	//! the transformed  curve  for  the transform  of the
	//! point on <me>.
	//!
	//! Transformed(T)->Value(U * ParametricTransformation(T))
	//! is the same point as
	//! Value(U).Transformed(T)
	//! This methods calls the basis curve method.
	Standard_Real XGeom_OffsetCurve::ParametricTransformation(xgp_Trsf^ T) {
		return NativeHandle()->ParametricTransformation(*T->GetTrsf());
	};

	//! Creates a new object which is a copy of this offset curve.
	XGeom_Geometry^ XGeom_OffsetCurve::Copy() {
		return gcnew XGeom_Geometry(NativeHandle()->Copy());
	};

	//! Returns continuity of the basis curve.
	XGeomAbs_Shape XGeom_OffsetCurve::GetBasisCurveContinuity() {
		return safe_cast<XGeomAbs_Shape>(NativeHandle()->GetBasisCurveContinuity());
	};
}