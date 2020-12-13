#include "XGeom_TrimmedCurve.h"

namespace TKG3d {
	XGeom_TrimmedCurve::XGeom_TrimmedCurve() {
		//NativeHandle() = new Geom_TrimmedCurve();
	};

	//!
	XGeom_TrimmedCurve::~XGeom_TrimmedCurve() {
		NativeHandle() = NULL;
		SetBoundedCurveHandle(NativeHandle());
	};

	//! 
	XGeom_TrimmedCurve::XGeom_TrimmedCurve(Handle(Geom_TrimmedCurve) pos) {
		NativeHandle() = pos;
		SetBoundedCurveHandle(NativeHandle());
	};


	//
	void XGeom_TrimmedCurve::SetTrimmedCurveHandle(Handle(Geom_TrimmedCurve) pos) {
		NativeHandle() = pos;
		SetBoundedCurveHandle(NativeHandle());
	};

	//!
	Handle(Geom_TrimmedCurve) XGeom_TrimmedCurve::GetTrimmedCurve() {
		return NativeHandle();
	};

	//!
	Handle(Geom_BoundedCurve) XGeom_TrimmedCurve::GetBoundedCurve() {
		return NativeHandle();
	};

	//!
	Handle(Geom_Curve) XGeom_TrimmedCurve::GetCurve() {
		return NativeHandle();
	};

	//!
	Handle(Geom_Geometry) XGeom_TrimmedCurve::GetGeometry() {
		return NativeHandle();
	};

	//! Constructs a trimmed curve from the basis curve C
	//! which is limited between parameter values U1 and U2.
	//! Note: - U1 can be greater or less than U2; in both cases,
	//! the returned curve is oriented from U1 to U2.
	//! - If the basis curve C is periodic, there is an
	//! ambiguity because two parts are available. In this
	//! case, the trimmed curve has the same orientation
	//! as the basis curve if Sense is true (default value)
	//! or the opposite orientation if Sense is false.
	//! - If the curve is closed but not periodic, it is not
	//! possible to keep the part of the curve which
	//! includes the junction point (except if the junction
	//! point is at the beginning or at the end of the
	//! trimmed curve). If you tried to do this, you could
	//! alter the fundamental characteristics of the basis
	//! curve, which are used, for example, to compute
	//! the derivatives of the trimmed curve. The rules
	//! for a closed curve are therefore the same as
	//! those for an open curve.
	//! Warning: The trimmed curve is built from a copy of curve C.
	//! Therefore, when C is modified, the trimmed curve
	//! is not modified.
	//! - If the basis curve is periodic and theAdjustPeriodic is True,
	//! the bounds of the trimmed curve may be different from U1 and U2
	//! if the parametric origin of the basis curve is within
	//! the arc of the trimmed curve. In this case, the
	//! modified parameter will be equal to U1 or U2
	//! plus or minus the period.
	//! When theAdjustPeriodic is False, parameters U1 and U2 will be
	//! the same, without adjustment into the first period.
	//! Exceptions
	//! Standard_ConstructionError if:
	//! - C is not periodic and U1 or U2 is outside the
	//! bounds of C, or
	//! - U1 is equal to U2.
	//! Standard_Boolean Sense = Standard_True, Standard_Boolean theAdjustPeriodic = Standard_True
	XGeom_TrimmedCurve::XGeom_TrimmedCurve(XGeom_Curve^ C, Standard_Real U1, Standard_Real U2, Standard_Boolean Sense, Standard_Boolean theAdjustPeriodic) {
		NativeHandle() = new Geom_TrimmedCurve(C->GetCurve(), U1, U2, Sense, theAdjustPeriodic);
		SetBoundedCurveHandle(NativeHandle());
	};

	//! Changes the orientation of this trimmed curve.
	//! As a result:
	//! - the basis curve is reversed,
	//! - the start point of the initial curve becomes the
	//! end point of the reversed curve,
	//! - the end point of the initial curve becomes the
	//! start point of the reversed curve,
	//! - the first and last parameters are recomputed.
	//! If the trimmed curve was defined by:
	//! - a basis curve whose parameter range is [ 0., 1. ],
	//! - the two trim values U1 (first parameter) and U2 (last parameter),
	//! the reversed trimmed curve is defined by:
	//! - the reversed basis curve, whose parameter range is still [ 0., 1. ],
	//! - the two trim values 1. - U2 (first parameter) and 1. - U1 (last parameter).
	void XGeom_TrimmedCurve::Reverse() {
		NativeHandle()->Reverse();
	};

	//! Computes the parameter on the reversed curve for
	//! the point of parameter U on this trimmed curve.
	Standard_Real XGeom_TrimmedCurve::ReversedParameter(Standard_Real U) {
		return NativeHandle()->ReversedParameter(U);
	};

	//! Changes this trimmed curve, by redefining the
	//! parameter values U1 and U2 which limit its basis curve.
	//! Note: If the basis curve is periodic, the trimmed curve
	//! has the same orientation as the basis curve if Sense
	//! is true (default value) or the opposite orientation if Sense is false.
	//! Warning
	//! If the basis curve is periodic and theAdjustPeriodic is True,
	//! the bounds of the trimmed curve may be different from U1 and U2 if the
	//! parametric origin of the basis curve is within the arc of
	//! the trimmed curve. In this case, the modified
	//! parameter will be equal to U1 or U2 plus or minus the period.
	//! When theAdjustPeriodic is False, parameters U1 and U2 will be
	//! the same, without adjustment into the first period.
	//! Exceptions
	//! Standard_ConstructionError if:
	//! - the basis curve is not periodic, and either U1 or U2
	//! are outside the bounds of the basis curve, or
	//! - U1 is equal to U2.
	//! Standard_Boolean Sense = Standard_True, Standard_Boolean theAdjustPeriodic = Standard_True
	void XGeom_TrimmedCurve::SetTrim(Standard_Real U1, Standard_Real U2, Standard_Boolean Sense, Standard_Boolean theAdjustPeriodic) {
		return NativeHandle()->SetTrim(U1, U2, Sense, theAdjustPeriodic);
	};

	//! Returns the basis curve.
	//! Warning
	//! This function does not return a constant reference.
	//! Consequently, any modification of the returned value
	//! directly modifies the trimmed curve.
	XGeom_Curve^ XGeom_TrimmedCurve::BasisCurve() {
		return gcnew XGeom_Curve(NativeHandle()->BasisCurve());
	};


	//! Returns the continuity of the curve :
	//! C0 : only geometric continuity,
	//! C1 : continuity of the first derivative all along the Curve,
	//! C2 : continuity of the second derivative all along the Curve,
	//! C3 : continuity of the third derivative all along the Curve,
	//! CN : the order of continuity is infinite.
	XGeomAbs_Shape XGeom_TrimmedCurve::Continuity() {
		return safe_cast<XGeomAbs_Shape>(NativeHandle()->Continuity());
	};

	//! Returns true if the degree of continuity of the basis
	//! curve of this trimmed curve is at least N. A trimmed
	//! curve is at least "C0" continuous.
	//! Warnings :
	//! The continuity of the trimmed curve can be greater than
	//! the continuity of the basis curve because you consider
	//! only a part of the basis curve.
	//! Raised if N < 0.
	Standard_Boolean XGeom_TrimmedCurve::IsCN(Standard_Integer N) {
		return NativeHandle()->IsCN(N);
	};


	//! Returns the end point of <me>. This point is the
	//! evaluation of the curve for the "LastParameter".
	xgp_Pnt^ XGeom_TrimmedCurve::EndPoint() {
		gp_Pnt* temp = new gp_Pnt(NativeHandle()->EndPoint());
		return gcnew xgp_Pnt(temp);
	};


	//! Returns the value of the first parameter of <me>.
	//! The first parameter is the parameter of the "StartPoint"
	//! of the trimmed curve.
	Standard_Real XGeom_TrimmedCurve::FirstParameter() {
		return NativeHandle()->FirstParameter();
	};


	//! Returns True if the distance between the StartPoint and
	//! the EndPoint is lower or equal to Resolution from package gp.
	Standard_Boolean XGeom_TrimmedCurve::IsClosed() {
		return NativeHandle()->IsClosed();
	};

	//! Always returns FALSE (independently of the type of basis curve).
	Standard_Boolean XGeom_TrimmedCurve::IsPeriodic() {
		return NativeHandle()->IsPeriodic();
	};

	//! Returns the period of the basis curve of this trimmed curve.
	//! Exceptions
	//! Standard_NoSuchObject if the basis curve is not periodic.
	Standard_Real XGeom_TrimmedCurve::Period() {
		return NativeHandle()->Period();
	};


	//! Returns the value of the last parameter of <me>.
	//! The last parameter is the parameter of the "EndPoint" of the
	//! trimmed curve.
	Standard_Real XGeom_TrimmedCurve::LastParameter() {
		return NativeHandle()->LastParameter();
	};


	//! Returns the start point of <me>.
	//! This point is the evaluation of the curve from the
	//! "FirstParameter".
	//! value and derivatives
	//! Warnings :
	//! The returned derivatives have the same orientation as the
	//! derivatives of the basis curve even if the trimmed curve
	//! has not the same orientation as the basis curve.
	xgp_Pnt^ XGeom_TrimmedCurve::StartPoint() {
		gp_Pnt* temp = new gp_Pnt(NativeHandle()->StartPoint());
		return gcnew xgp_Pnt(temp);
	};

	//! Returns in P the point of parameter U.
	//!
	//! If the basis curve is an OffsetCurve sometimes it is not
	//! possible to do the evaluation of the curve at the parameter
	//! U (see class OffsetCurve).
	void XGeom_TrimmedCurve::D0(Standard_Real U, xgp_Pnt^ P) {
		NativeHandle()->D0(U, *P->GetPnt());
	};

	//! Raised if the continuity of the curve is not C1.
	void XGeom_TrimmedCurve::D1(Standard_Real U, xgp_Pnt^ P, xgp_Vec^ V1) {
		NativeHandle()->D1(U, *P->GetPnt(), *V1->GetVec());
	};

	//! Raised if the continuity of the curve is not C2.
	void XGeom_TrimmedCurve::D2(Standard_Real U, xgp_Pnt^ P, xgp_Vec^ V1, xgp_Vec^ V2) {
		NativeHandle()->D2(U, *P->GetPnt(), *V1->GetVec(), *V2->GetVec());
	};

	//! Raised if the continuity of the curve is not C3.
	void XGeom_TrimmedCurve::D3(Standard_Real U, xgp_Pnt^ P, xgp_Vec^ V1, xgp_Vec^ V2, xgp_Vec^ V3) {
		NativeHandle()->D3(U, *P->GetPnt(), *V1->GetVec(), *V2->GetVec(), *V3->GetVec());
	};

	//! N is the order of derivation.
	//! Raised if the continuity of the curve is not CN.
	//! Raised if N < 1.
	//! geometric transformations
	xgp_Vec^ XGeom_TrimmedCurve::DN(Standard_Real U, Standard_Integer N) {
		gp_Vec* temp = new gp_Vec(NativeHandle()->DN(U, N));
		return gcnew xgp_Vec(temp);
	};

	//! Applies the transformation T to this trimmed curve.
	//! Warning The basis curve is also modified.
	void XGeom_TrimmedCurve::Transform(xgp_Trsf^ T) {
		NativeHandle()->Transform(*T->GetTrsf());
	};

	//! Returns the  parameter on the  transformed  curve for
	//! the transform of the point of parameter U on <me>.
	//!
	//! me->Transformed(T)->Value(me->TransformedParameter(U,T))
	//!
	//! is the same point as
	//!
	//! me->Value(U).Transformed(T)
	//!
	//! This methods calls the basis curve method.
	Standard_Real XGeom_TrimmedCurve::TransformedParameter(Standard_Real U, xgp_Trsf^ T) {
		return NativeHandle()->TransformedParameter(U, *T->GetTrsf());
	};

	//! Returns a  coefficient to compute the parameter on
	//! the transformed  curve  for  the transform  of the
	//! point on <me>.
	//!
	//! Transformed(T)->Value(U * ParametricTransformation(T))
	//!
	//! is the same point as
	//!
	//! Value(U).Transformed(T)
	//!
	//! This methods calls the basis curve method.
	Standard_Real XGeom_TrimmedCurve::ParametricTransformation(xgp_Trsf^ T) {
		return NativeHandle()->ParametricTransformation(*T->GetTrsf());
	};

	//! Creates a new object which is a copy of this trimmed curve.
	XGeom_Geometry^ XGeom_TrimmedCurve::Copy() {
		return gcnew XGeom_Geometry(NativeHandle()->Copy());
	};
}
