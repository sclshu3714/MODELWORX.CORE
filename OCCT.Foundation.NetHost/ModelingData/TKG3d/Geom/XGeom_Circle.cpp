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

#include <XGeom_Circle.h>

namespace TKG3d {
	//! Constructs a circle by conversion of the gp_Circ circle C.
	XGeom_Circle::XGeom_Circle(xgp_Circ^ C) {
		NativeHandle() = new Geom_Circle(*C->GetCirc());
		SetConicHandle(NativeHandle());
	};

	//! Constructs a circle of radius Radius, where A2 locates the circle and
	//! defines its orientation in 3D space such that:
	//! - the center of the circle is the origin of A2,
	//! - the origin, "X Direction" and "Y Direction" of A2
	//! define the plane of the circle,
	//! - A2 is the local coordinate system of the circle.
	//! Note: It is possible to create a circle where Radius is equal to 0.0.
	//! raised if Radius < 0.
	XGeom_Circle::XGeom_Circle(xgp_Ax2^ A2, Standard_Real Radius) {
		NativeHandle() = new Geom_Circle(*A2->GetAx2(), Radius);
		SetConicHandle(NativeHandle());
	};


	Handle(Geom_Circle) XGeom_Circle::GetCircle() {
		return NativeHandle();
	};



	Handle(Geom_Conic) XGeom_Circle::GetConic() {
		return NativeHandle();
	};

	//!
	Handle(Geom_Curve) XGeom_Circle::GetCurve() {
		return NativeHandle();
	};

	//!
	Handle(Geom_Geometry) XGeom_Circle::GetGeometry() {
		return NativeHandle();
	};

	void XGeom_Circle::SetCircleHandle(Handle(Geom_Circle) pos) {
		NativeHandle() = pos;
		SetConicHandle(NativeHandle());
	};

	//! Set <me> so that <me> has the same geometric properties as C.
	void XGeom_Circle::SetCirc(xgp_Circ^ C) {
		NativeHandle()->SetCirc(*C->GetCirc());
	};

	//! Assigns the value R to the radius of this circle.
	//! Note: it is possible to have a circle with a radius equal to 0.0.
	//! Exceptions - Standard_ConstructionError if R is negative.
	void XGeom_Circle::SetRadius(Standard_Real R) {
		NativeHandle()->SetRadius(R);
	};


	//! returns the non transient circle from gp with the same
	//! geometric properties as <me>.
	xgp_Circ^ XGeom_Circle::Circ() {
		gp_Circ* temp = new gp_Circ(NativeHandle()->Circ());
		return gcnew xgp_Circ(temp);
	};

	//! Returns the radius of this circle.
	Standard_Real XGeom_Circle::Radius() {
		return NativeHandle()->Radius();
	};

	//! Computes the parameter on the reversed circle for
	//! the point of parameter U on this circle.
	//! For a circle, the returned value is: 2.*Pi - U.
	Standard_Real XGeom_Circle::ReversedParameter(Standard_Real U) {
		return NativeHandle()->ReversedParameter(U);
	};

	//! Returns the eccentricity  e = 0 for a circle.
	Standard_Real XGeom_Circle::Eccentricity() {
		return NativeHandle()->Eccentricity();
	};

	//! Returns the value of the first parameter of this
	//! circle. This is  0.0, which gives the start point of this circle, or
	//! The start point and end point of a circle are coincident.
	Standard_Real XGeom_Circle::FirstParameter() {
		return NativeHandle()->FirstParameter();
	};

	//! Returns the value of the last parameter of this
	//! circle. This is 2.*Pi, which gives the end point of this circle.
	//! The start point and end point of a circle are coincident.
	Standard_Real XGeom_Circle::LastParameter() {
		return NativeHandle()->LastParameter();
	};

	//! returns True.
	Standard_Boolean XGeom_Circle::IsClosed() {
		return NativeHandle()->IsClosed();
	};

	//! returns True.
	Standard_Boolean XGeom_Circle::IsPeriodic() {
		return NativeHandle()->IsPeriodic();
	};

	//! Returns in P the point of parameter U.
	//! P = C + R * Cos (U) * XDir + R * Sin (U) * YDir
	//! where C is the center of the circle , XDir the XDirection and
	//! YDir the YDirection of the circle's local coordinate system.
	void XGeom_Circle::D0(Standard_Real U, xgp_Pnt^ P) {
		return NativeHandle()->D0(U, *P->GetPnt());
	};


	//! Returns the point P of parameter U and the first derivative V1.
	void XGeom_Circle::D1(Standard_Real U, xgp_Pnt^ P, xgp_Vec^ V1) {
		return NativeHandle()->D1(U, *P->GetPnt(), *V1->GetVec());
	};


	//! Returns the point P of parameter U, the first and second
	//! derivatives V1 and V2.
	void XGeom_Circle::D2(Standard_Real U, xgp_Pnt^ P, xgp_Vec^ V1, xgp_Vec^ V2) {
		return NativeHandle()->D2(U, *P->GetPnt(), *V1->GetVec(), *V2->GetVec());
	};


	//! Returns the point P of parameter u, the first second and third
	//! derivatives V1 V2 and V3.
	void XGeom_Circle::D3(Standard_Real U, xgp_Pnt^ P, xgp_Vec^ V1, xgp_Vec^ V2, xgp_Vec^ V3) {
		return NativeHandle()->D3(U, *P->GetPnt(), *V1->GetVec(), *V2->GetVec(), *V3->GetVec());
	};


	//! The returned vector gives the value of the derivative for the
	//! order of derivation N.
	//! Raised if N < 1.
	xgp_Vec^ XGeom_Circle::DN(Standard_Real U, Standard_Integer N) {
		gp_Vec* temp = new gp_Vec(NativeHandle()->DN(U, N));
		return gcnew xgp_Vec(temp);
	};

	//! Applies the transformation T to this circle.
	void XGeom_Circle::Transform(xgp_Trsf^ T) {
		NativeHandle()->Transform(*T->GetTrsf());
	};

	//! Creates a new object which is a copy of this circle.
	XGeom_Geometry^ XGeom_Circle::Copy() {
		return gcnew XGeom_Geometry(NativeHandle()->Copy());
	};
}
