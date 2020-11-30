// Created on: 1993-03-24
// Created by: JCV
// Copyright (c) 1993-1999 Matra Datavision
// Copyright (c) 1999-2014 OPEN CASCADE SAS
//
// This file is part of Open CASCADE Technology software library.
//
// This library is free software; you can redistribute it and/or modify it under
// the terms of the GNU Lesser General Public License version 2.1 as published
// by the Free Software Foundation, with special exception defined in the file
// OCCT_LGPL_EXCEPTION.txt. Consult the file LICENSE_LGPL_21.txt included in OCCT
// distribution for complete text of the license and disclaimer of any warranty.
//
// Alternatively, this file may be used under the terms of Open CASCADE
// commercial license or contractual agreement.


#include <XGeom2d_Curve.h>

namespace TKG2d {

	XGeom2d_Curve::XGeom2d_Curve(Handle(Geom2d_Curve) pos) {
		NativeHandle() = pos;
		SetGeometryHandle(pos);
	};

	void XGeom2d_Curve::SetCurveHandle(Handle(Geom2d_Curve) pos) {
		NativeHandle() = pos;
		SetGeometryHandle(pos);
	};

	Handle(Geom2d_Geometry) XGeom2d_Curve::GetGeometry() {
		return NativeHandle();
	};

	Handle(Geom2d_Curve) XGeom2d_Curve::GetCurve() {
		return NativeHandle();
	};

	//! Changes the direction of parametrization of <me>.
	//! The "FirstParameter" and the "LastParameter" are not changed
	//! but the orientation  of the curve is modified. If the curve
	//! is bounded the StartPoint of the initial curve becomes the
	//! EndPoint of the reversed curve  and the EndPoint of the initial
	//! curve becomes the StartPoint of the reversed curve.
	void XGeom2d_Curve::Reverse() {
		NativeHandle()->Reverse();
	};

	//! Computes the parameter on the reversed curve for
	//! the point of parameter U on this curve.
	//! Note: The point of parameter U on this curve is
	//! identical to the point of parameter
	//! ReversedParameter(U) on the reversed curve.
	Standard_Real XGeom2d_Curve::ReversedParameter(Standard_Real U) {
		return NativeHandle()->ReversedParameter(U);
	};

	//! Computes the parameter on the curve transformed by
	//! T for the point of parameter U on this curve.
	//! Note: this function generally returns U but it can be
	//! redefined (for example, on a line).
	Standard_Real XGeom2d_Curve::TransformedParameter(Standard_Real U, xgp_Trsf2d^ T) {
		return NativeHandle()->TransformedParameter(U, T->GetTrsf2d());
	};

	//! Returns the coefficient required to compute the
	//! parametric transformation of this curve when
	//! transformation T is applied. This coefficient is the
	//! ratio between the parameter of a point on this curve
	//! and the parameter of the transformed point on the
	//! new curve transformed by T.
	//! Note: this function generally returns 1. but it can be
	//! redefined (for example, on a line).
	Standard_Real XGeom2d_Curve::ParametricTransformation(xgp_Trsf2d^ T) {
		return NativeHandle()->ParametricTransformation(T->GetTrsf2d());
	};

	//! Creates a reversed duplicate Changes the orientation of this curve. The first and
	//! last parameters are not changed, but the parametric
	//! direction of the curve is reversed.
	//! If the curve is bounded:
	//! - the start point of the initial curve becomes the end
	//! point of the reversed curve, and
	//! - the end point of the initial curve becomes the start
	//! point of the reversed curve.
	//! - Reversed creates a new curve.
	XGeom2d_Curve^ XGeom2d_Curve::Reversed() {
		return gcnew XGeom2d_Curve(NativeHandle()->Reversed());
	};

	//! Returns the value of the first parameter.
	//! Warnings :
	//! It can be RealFirst or RealLast from package Standard
	//! if the curve is infinite
	Standard_Real XGeom2d_Curve::FirstParameter() {
		return NativeHandle()->FirstParameter();
	};

	//! Value of the last parameter.
	//! Warnings :
	//! It can be RealFirst or RealLast from package Standard
	//! if the curve is infinite
	Standard_Real XGeom2d_Curve::LastParameter() {
		return NativeHandle()->LastParameter();
	};

	//! Returns true if the curve is closed.
	//! Examples :
	//! Some curves such as circle are always closed, others such as line
	//! are never closed (by definition).
	//! Some Curves such as OffsetCurve can be closed or not. These curves
	//! are considered as closed if the distance between the first point
	//! and the last point of the curve is lower or equal to the Resolution
	//! from package gp wich is a fixed criterion independant of the
	//! application.
	Standard_Boolean XGeom2d_Curve::IsClosed() {
		return NativeHandle()->IsClosed();
	};


	//! Returns true if the parameter of the curve is periodic.
	//! It is possible only if the curve is closed and if the
	//! following relation is satisfied :
	//! for each parametric value U the distance between the point
	//! P(u) and the point P (u + T) is lower or equal to Resolution
	//! from package gp, T is the period and must be a constant.
	//! There are three possibilities :
	//! . the curve is never periodic by definition (SegmentLine)
	//! . the curve is always periodic by definition (Circle)
	//! . the curve can be defined as periodic (BSpline). In this case
	//! a function SetPeriodic allows you to give the shape of the
	//! curve.  The general rule for this case is : if a curve can be
	//! periodic or not the default periodicity set is non periodic
	//! and you have to turn (explicitly) the curve into a periodic
	//! curve  if you want the curve to be periodic.
	Standard_Boolean XGeom2d_Curve::IsPeriodic() {
		return NativeHandle()->IsPeriodic();
	};

	//! Returns thne period of this curve.
	//! raises if the curve is not periodic
	Standard_Real XGeom2d_Curve::Period() {
		return NativeHandle()->Period();
	};


	//! It is the global continuity of the curve :
	//! C0 : only geometric continuity,
	//! C1 : continuity of the first derivative all along the Curve,
	//! C2 : continuity of the second derivative all along the Curve,
	//! C3 : continuity of the third derivative all along the Curve,
	//! G1 : tangency continuity all along the Curve,
	//! G2 : curvature continuity all along the Curve,
	//! CN : the order of continuity is infinite.
	XGeomAbs_Shape XGeom2d_Curve::Continuity() {
		return safe_cast<XGeomAbs_Shape>(NativeHandle()->Continuity());
	};

	//! Returns true if the degree of continuity of this curve is at least N.
	//! Exceptions Standard_RangeError if N is less than 0.
	Standard_Boolean XGeom2d_Curve::IsCN(Standard_Integer N) {
		return NativeHandle()->IsCN(N);
	};

	//! Returns in P the point of parameter U.
	//! If the curve is periodic  then the returned point is P(U) with
	//! U = Ustart + (U - Uend)  where Ustart and Uend are the
	//! parametric bounds of the curve.
	//!
	//! Raised only for the "OffsetCurve" if it is not possible to
	//! compute the current point. For example when the first
	//! derivative on the basis curve and the offset direction
	//! are parallel.
	void XGeom2d_Curve::D0(Standard_Real U, xgp_Pnt2d^ P) {
		NativeHandle()->D0(U, P->GetPnt2d());
	};


	//! Returns the point P of parameter U and the first derivative V1.
	//! Raised if the continuity of the curve is not C1.
	void XGeom2d_Curve::D1(Standard_Real U, xgp_Pnt2d^ P, xgp_Vec2d^ V1) {
		NativeHandle()->D1(U, P->GetPnt2d(), V1->GetVec2d());
	};


	//! Returns the point P of parameter U, the first and second
	//! derivatives V1 and V2.
	//! Raised if the continuity of the curve is not C2.
	void XGeom2d_Curve::D2(Standard_Real U, xgp_Pnt2d^ P, xgp_Vec2d^ V1, xgp_Vec2d^ V2) {
		NativeHandle()->D2(U, P->GetPnt2d(), V1->GetVec2d(), V2->GetVec2d());
	};


	//! Returns the point P of parameter U, the first, the second
	//! and the third derivative.
	//! Raised if the continuity of the curve is not C3.
	void XGeom2d_Curve::D3(Standard_Real U, xgp_Pnt2d^ P, xgp_Vec2d^ V1, xgp_Vec2d^ V2, xgp_Vec2d^ V3) {
		NativeHandle()->D3(U, P->GetPnt2d(), V1->GetVec2d(), V2->GetVec2d(), V3->GetVec2d());
	};

	//! For the point of parameter U of this curve, computes
	//! the vector corresponding to the Nth derivative.
	//! Exceptions
	//! StdFail_UndefinedDerivative if:
	//! - the continuity of the curve is not "CN", or
	//! - the derivative vector cannot be computed easily;
	//! this is the case with specific types of curve (for
	//! example, a rational BSpline curve where N is greater than 3).
	//! Standard_RangeError if N is less than 1.
	xgp_Vec2d^ XGeom2d_Curve::DN(Standard_Real U, Standard_Integer N) {
		return gcnew xgp_Vec2d(NativeHandle()->DN(U, N));
	};

	//! Computes the point of parameter U on <me>.
	//! If the curve is periodic  then the returned point is P(U) with
	//! U = Ustart + (U - Uend)  where Ustart and Uend are the
	//! parametric bounds of the curve.
	//!
	//! it is implemented with D0.
	//!
	//! Raised only for the "OffsetCurve" if it is not possible to
	//! compute the current point. For example when the first
	//! derivative on the basis curve and the offset direction
	//! are parallel.
	xgp_Pnt2d^ XGeom2d_Curve::Value(Standard_Real U) {
		return gcnew xgp_Pnt2d(NativeHandle()->Value(U));
	};
}
