// Created on: 1993-03-10
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


#include <XGeom_Curve.h>

namespace TKG3d {

	XGeom_Curve::XGeom_Curve() {
		//NativeHandle() = new Geom_Curve();
	};

	//! 
	XGeom_Curve::XGeom_Curve(Handle(Geom_Curve) pos) {
		NativeHandle() = pos;
		SetGeomHandle(NativeHandle());
	};

	//!
	XGeom_Curve::~XGeom_Curve() {
		NativeHandle() = NULL; 
		SetGeomHandle(NULL);
	};

	void XGeom_Curve::SetCurveHandle(Handle(Geom_Curve) pos) {
		NativeHandle() = pos;
		SetGeomHandle(NativeHandle());
	};

	Handle(Geom_Curve) XGeom_Curve::GetCurve() {
		return NativeHandle();
	};

	//! Changes the direction of parametrization of <me>.
	//! The "FirstParameter" and the "LastParameter" are not changed
	//! but the orientation  of the curve is modified. If the curve
	//! is bounded the StartPoint of the initial curve becomes the
	//! EndPoint of the reversed curve  and the EndPoint of the initial
	//! curve becomes the StartPoint of the reversed curve.
	void XGeom_Curve::Reverse() {
		NativeHandle()->Reverse();
	};

	//! Returns the  parameter on the  reversed  curve for
	//! the point of parameter U on <me>.
	//!
	//! me->Reversed()->Value(me->ReversedParameter(U))
	//!
	//! is the same point as
	//!
	//! me->Value(U)
	Standard_Real XGeom_Curve::ReversedParameter(Standard_Real U) {
		return NativeHandle()->ReversedParameter(U);
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
	//! This methods returns <U>
	//!
	//! It can be redefined. For example on the Line.
	Standard_Real XGeom_Curve::TransformedParameter(Standard_Real U, xgp_Trsf^ T) {
		return NativeHandle()->TransformedParameter(U, T->GetTrsf());
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
	//! This methods returns 1.
	//!
	//! It can be redefined. For example on the Line.
	Standard_Real XGeom_Curve::ParametricTransformation(xgp_Trsf^ T) {
		return NativeHandle()->ParametricTransformation(T->GetTrsf());
	};

	//! Returns a copy of <me> reversed.
	XGeom_Curve^ XGeom_Curve::Reversed() {
		return gcnew XGeom_Curve(NativeHandle()->Reversed());
	};

	//! Returns the value of the first parameter.
	//! Warnings :
	//! It can be RealFirst from package Standard
	//! if the curve is infinite
	Standard_Real XGeom_Curve::FirstParameter() {
		return NativeHandle()->FirstParameter();
	};

	//! Returns the value of the last parameter.
	//! Warnings :
	//! It can be RealLast from package Standard
	//! if the curve is infinite
	Standard_Real XGeom_Curve::LastParameter() {
		return NativeHandle()->LastParameter();
	};

	//! Returns true if the curve is closed.
	//! Some curves such as circle are always closed, others such as line
	//! are never closed (by definition).
	//! Some Curves such as OffsetCurve can be closed or not. These curves
	//! are considered as closed if the distance between the first point
	//! and the last point of the curve is lower or equal to the Resolution
	//! from package gp wich is a fixed criterion independant of the
	//! application.
	Standard_Boolean XGeom_Curve::IsClosed() {
		return NativeHandle()->IsClosed();
	};

	//! Is the parametrization of the curve periodic ?
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
	Standard_Boolean XGeom_Curve::IsPeriodic() {
		return NativeHandle()->IsPeriodic();
	};

	//! Returns the period of this curve.
	//! Exceptions Standard_NoSuchObject if this curve is not periodic.
	Standard_Real XGeom_Curve::Period() {
		return NativeHandle()->Period();
	};

	//! It is the global continuity of the curve
	//! C0 : only geometric continuity,
	//! C1 : continuity of the first derivative all along the Curve,
	//! C2 : continuity of the second derivative all along the Curve,
	//! C3 : continuity of the third derivative all along the Curve,
	//! G1 : tangency continuity all along the Curve,
	//! G2 : curvature continuity all along the Curve,
	//! CN : the order of continuity is infinite.
	XGeomAbs_Shape XGeom_Curve::Continuity() {
		return safe_cast<XGeomAbs_Shape>(NativeHandle()->Continuity());
	};

	//! Returns true if the degree of continuity of this curve is at least N.
	//! Exceptions -  Standard_RangeError if N is less than 0.
	Standard_Boolean XGeom_Curve::IsCN(Standard_Integer N) {
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
	void XGeom_Curve::D0(Standard_Real U, xgp_Pnt^ P) {
		NativeHandle()->D0(U, P->GetPnt());
	};


	//! Returns the point P of parameter U and the first derivative V1.
	//! Raised if the continuity of the curve is not C1.
	void XGeom_Curve::D1(Standard_Real U, xgp_Pnt^ P, xgp_Vec^ V1) {
		NativeHandle()->D1(U, P->GetPnt(), V1->GetVec());
	};


	//! Returns the point P of parameter U, the first and second
	//! derivatives V1 and V2.
	//! Raised if the continuity of the curve is not C2.
	void XGeom_Curve::D2(Standard_Real U, xgp_Pnt^ P, xgp_Vec^ V1, xgp_Vec^ V2) {
		NativeHandle()->D2(U, P->GetPnt(), V1->GetVec(), V2->GetVec());
	};


	//! Returns the point P of parameter U, the first, the second
	//! and the third derivative.
	//! Raised if the continuity of the curve is not C3.
	void XGeom_Curve::D3(Standard_Real U, xgp_Pnt^ P, xgp_Vec^ V1, xgp_Vec^ V2, xgp_Vec^ V3) {
		NativeHandle()->D3(U, P->GetPnt(), V1->GetVec(), V2->GetVec(), V3->GetVec());
	};


	//! The returned vector gives the value of the derivative for the
	//! order of derivation N.
	//! Raised if the continuity of the curve is not CN.
	//!
	//! Raised if the   derivative  cannot  be  computed
	//! easily. e.g. rational bspline and n > 3.
	//! Raised if N < 1.
	xgp_Vec^ XGeom_Curve::DN(Standard_Real U, Standard_Integer N) {
		  return gcnew xgp_Vec(NativeHandle()->DN(U, N));
	};

	//! Computes the point of parameter U on <me>.
	//! If the curve is periodic  then the returned point is P(U) with
	//! U = Ustart + (U - Uend)  where Ustart and Uend are the
	//! parametric bounds of the curve.
	//! it is implemented with D0.
	//!
	//! Raised only for the "OffsetCurve" if it is not possible to
	//! compute the current point. For example when the first
	//! derivative on the basis curve and the offset direction are parallel.
	xgp_Pnt^ XGeom_Curve::Value(Standard_Real U) {
		return gcnew xgp_Pnt(NativeHandle()->Value(U));
	};
}


