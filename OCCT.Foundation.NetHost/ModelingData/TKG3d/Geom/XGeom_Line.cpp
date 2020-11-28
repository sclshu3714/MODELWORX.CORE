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
#include "XGeom_Line.h"

namespace TKG3d {


	//! Creates a line located in 3D space with the axis placement A1.
	//! The Location of A1 is the origin of the line.
	XGeom_Line::XGeom_Line(xgp_Ax1^ A1) {
		NativeHandle() = new Geom_Line(A1->GetAx1());
		SetCurveHandle(NativeHandle());
	};


	//! Creates a line from a non transient line from package gp.
	XGeom_Line::XGeom_Line(xgp_Lin^ L) {
		NativeHandle() = new Geom_Line(L->GetLin());
		SetCurveHandle(NativeHandle());
	};

	XGeom_Line::XGeom_Line(Handle(Geom_Line) pos) {
		NativeHandle() = pos;
		SetCurveHandle(NativeHandle());
	};
	//! Constructs a line passing through point P and parallel to vector V
	//! (P and V are, respectively, the origin and the unit
	//! vector of the positioning axis of the line).
	XGeom_Line::XGeom_Line(xgp_Pnt^ P, xgp_Dir^ V) {
		NativeHandle() = new Geom_Line(P->GetPnt(), V->GetDir());
		SetCurveHandle(NativeHandle());
	};

	void XGeom_Line::SetLineHandle(Handle(Geom_Line) pos) {
		NativeHandle() = pos;
		SetCurveHandle(NativeHandle());
	};

	Handle(Geom_Line) XGeom_Line::GetHLine() {
		return NativeHandle();
	};

	//! Set <me> so that <me> has the same geometric properties as L.
	void XGeom_Line::SetLin(xgp_Lin^ L) {
		NativeHandle()->SetLin(L->GetLin());
	};

	//! changes the direction of the line.
	void XGeom_Line::SetDirection(xgp_Dir^ V) {
		NativeHandle()->SetDirection(V->GetDir());
	};


	//! changes the "Location" point (origin) of the line.
	void XGeom_Line::SetLocation(xgp_Pnt^ P) {
		NativeHandle()->SetLocation(P->GetPnt());
	};


	//! changes the "Location" and a the "Direction" of <me>.
	void XGeom_Line::SetPosition(xgp_Ax1^ A1) {
		NativeHandle()->SetPosition(A1->GetAx1());
	};


	//! Returns non transient line from gp with the same geometric
	//! properties as <me>
	xgp_Lin^ XGeom_Line::Lin() {
		return gcnew xgp_Lin(NativeHandle()->Lin());
	};

	//! Returns the positioning axis of this line; this is also its local coordinate system.
	xgp_Ax1^ XGeom_Line::Position() {
		return gcnew xgp_Ax1(NativeHandle()->Position());
	};

	//! Changes the orientation of this line. As a result, the
	//! unit vector of the positioning axis of this line is reversed.
	void XGeom_Line::Reverse() {
		NativeHandle()->Reverse();
	};

	//! Computes the parameter on the reversed line for the
	//! point of parameter U on this line.
	//! For a line, the returned value is -U.
	Standard_Real XGeom_Line::ReversedParameter(Standard_Real U) {
		return NativeHandle()->ReversedParameter(U);
	};

	//! Returns the value of the first parameter of this
	//! line. This is Standard_Real::RealFirst().
	Standard_Real XGeom_Line::FirstParameter() {
		return NativeHandle()->FirstParameter();
	};

	//! Returns the value of the last parameter of this
	//! line. This is  Standard_Real::RealLast().
	Standard_Real XGeom_Line::LastParameter() {
		return NativeHandle()->LastParameter();
	};

	//! returns False
	Standard_Boolean XGeom_Line::IsClosed() {
		return NativeHandle()->IsClosed();
	};

	//! returns False
	Standard_Boolean XGeom_Line::IsPeriodic() {
		return NativeHandle()->IsPeriodic();
	};

	//! Returns GeomAbs_CN, which is the global continuity of any line.
	XGeomAbs_Shape XGeom_Line::Continuity() {
		return safe_cast<XGeomAbs_Shape>(NativeHandle()->Continuity());
	};

	//! returns True.
	//! Raised if N < 0.
	Standard_Boolean XGeom_Line::IsCN(Standard_Integer N) {
		return NativeHandle()->IsCN(N);
	};

	//! Returns in P the point of parameter U.
	//! P (U) = O + U * Dir where O is the "Location" point of the
	//! line and Dir the direction of the line.
	void XGeom_Line::D0(Standard_Real U, xgp_Pnt^ P) {
		NativeHandle()->D0(U, P->GetPnt());
	};


	//! Returns the point P of parameter u and the first derivative V1.
	void XGeom_Line::D1(Standard_Real U, xgp_Pnt^ P, xgp_Vec^ V1) {
		NativeHandle()->D1(U, P->GetPnt(), V1->GetVec());
	};


	//! Returns the point P of parameter U, the first and second
	//! derivatives V1 and V2. V2 is a vector with null magnitude
	//! for a line.
	void XGeom_Line::D2(Standard_Real U, xgp_Pnt^ P, xgp_Vec^ V1, xgp_Vec^ V2) {
		NativeHandle()->D2(U, P->GetPnt(), V1->GetVec(), V2->GetVec());
	};


	//! V2 and V3 are vectors with null magnitude for a line.
	void XGeom_Line::D3(Standard_Real U, xgp_Pnt^ P, xgp_Vec^ V1, xgp_Vec^ V2, xgp_Vec^ V3) {
		NativeHandle()->D3(U, P->GetPnt(), V1->GetVec(), V2->GetVec(), V3->GetVec());
	};


	//! The returned vector gives the value of the derivative for the
	//! order of derivation N.
	//! Raised if N < 1.
	xgp_Vec^ XGeom_Line::DN(Standard_Real U, Standard_Integer N) {
		return gcnew xgp_Vec(NativeHandle()->DN(U, N));
	};

	//! Applies the transformation T to this line.
	void XGeom_Line::Transform(xgp_Trsf^ T) {
		NativeHandle()->Transform(T->GetTrsf());
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
	//! This methods returns <U> * T.ScaleFactor()
	Standard_Real XGeom_Line::TransformedParameter(Standard_Real U, xgp_Trsf^ T) {
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
	//! This methods returns T.ScaleFactor()
	Standard_Real XGeom_Line::ParametricTransformation(xgp_Trsf^ T) {
		return NativeHandle()->ParametricTransformation(T->GetTrsf());
	};

	//! Creates a new object which is a copy of this line.
	XGeom_Geometry^ XGeom_Line::Copy() {
		return gcnew XGeom_Geometry(NativeHandle()->Copy());
	};
}

