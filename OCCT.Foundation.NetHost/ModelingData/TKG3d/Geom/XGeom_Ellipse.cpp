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

#include <XGeom_Ellipse.h>

namespace TKG3d {
	//! Constructs an ellipse by conversion of the gp_Elips ellipse E.
	XGeom_Ellipse::XGeom_Ellipse(xgp_Elips^ E) {
		IHandle = new  Geom_Ellipse(E->GetElips());
	};

	//! Constructs an ellipse
	//! defined by its major and minor radii, MajorRadius
	//! and MinorRadius, where A2 locates the ellipse
	//! and defines its orientation in 3D space such that:
	//! - the center of the ellipse is the origin of A2,
	//! - the "X Direction" of A2 defines the major axis
	//! of the ellipse, i.e. the major radius
	//! MajorRadius is measured along this axis,
	//! - the "Y Direction" of A2 defines the minor axis
	//! of the ellipse, i.e. the minor radius
	//! MinorRadius is measured along this axis,
	//! - A2 is the local coordinate system of the ellipse.
	//! Exceptions
	//! Standard_ConstructionError if:
	//! - MajorRadius is less than MinorRadius, or
	//! - MinorRadius is less than 0.
	//! Warning The Geom package does not prevent the
	//! construction of an ellipse where MajorRadius and
	//! MinorRadius are equal.
	XGeom_Ellipse::XGeom_Ellipse(xgp_Ax2^ A2, Standard_Real MajorRadius, Standard_Real MinorRadius) {
		IHandle = new  Geom_Ellipse(A2->GetAx2(), MajorRadius, MinorRadius);
	};

	Handle(Geom_Conic) XGeom_Ellipse::GetConic() {
		return NativeHandle();
	};

	//!
	Handle(Geom_Curve) XGeom_Ellipse::GetCurve() {
		return NativeHandle();
	};

	//!
	Handle(Geom_Geometry) XGeom_Ellipse::GetGeometry() {
		return NativeHandle();
	};

	//! Converts the gp_Elips ellipse E into this ellipse.
	void XGeom_Ellipse::SetElips(xgp_Elips^ E) {
		NativeHandle()->SetElips(E->GetElips());
	};

	//! Assigns a value to the major radius of this ellipse.
	//! ConstructionError raised if MajorRadius < MinorRadius.
	void XGeom_Ellipse::SetMajorRadius(Standard_Real MajorRadius) {
		NativeHandle()->SetMajorRadius(MajorRadius);
	};

	//! Assigns a value to the minor radius of this ellipse.
	//! ConstructionError raised if MajorRadius < MinorRadius or if MinorRadius < 0.
	void XGeom_Ellipse::SetMinorRadius(Standard_Real MinorRadius) {
		NativeHandle()->SetMinorRadius(MinorRadius);
	};


	//! returns the non transient ellipse from gp with the same
	xgp_Elips^ XGeom_Ellipse::Elips() {
		return gcnew xgp_Elips(NativeHandle()->Elips());
	};

	//! Computes the parameter on the reversed ellipse for
	//! the point of parameter U on this ellipse.
	//! For an ellipse, the returned value is: 2.*Pi - U.
	Standard_Real XGeom_Ellipse::ReversedParameter(Standard_Real U) {
		return NativeHandle()->ReversedParameter(U);
	};


	//! This directrix is the line normal to the XAxis of the ellipse
	//! in the local plane (Z = 0) at a distance d = MajorRadius / e
	//! from the center of the ellipse, where e is the eccentricity of
	//! the ellipse.
	//! This line is parallel to the "YAxis". The intersection point
	//! between directrix1 and the "XAxis" is the "Location" point
	//! of the directrix1. This point is on the positive side of
	//! the "XAxis".
	//! Raised if Eccentricity = 0.0. (The ellipse degenerates
	//! into a circle)
	xgp_Ax1^ XGeom_Ellipse::Directrix1() {
		return gcnew xgp_Ax1(NativeHandle()->Directrix1());
	};


	//! This line is obtained by the symmetrical transformation
	//! of "Directrix1" with respect to the "YAxis" of the ellipse.
	//!
	//! Raised if Eccentricity = 0.0. (The ellipse degenerates into a
	//! circle).
	xgp_Ax1^ XGeom_Ellipse::Directrix2() {
		return gcnew xgp_Ax1(NativeHandle()->Directrix2());
	};


	//! Returns the eccentricity of the ellipse  between 0.0 and 1.0
	//! If f is the distance between the center of the ellipse and
	//! the Focus1 then the eccentricity e = f / MajorRadius.
	//! Returns 0 if MajorRadius = 0
	Standard_Real XGeom_Ellipse::Eccentricity() {
		return NativeHandle()->Eccentricity();
	};


	//! Computes the focal distance. It is the distance between the
	//! the two focus of the ellipse.
	Standard_Real XGeom_Ellipse::Focal() {
		return NativeHandle()->Focal();
	};


	//! Returns the first focus of the ellipse. This focus is on the
	//! positive side of the "XAxis" of the ellipse.
	xgp_Pnt^ XGeom_Ellipse::Focus1() {
		return gcnew xgp_Pnt(NativeHandle()->Focus1());
	};


	//! Returns the second focus of the ellipse. This focus is on
	//! the negative side of the "XAxis" of the ellipse.
	xgp_Pnt^ XGeom_Ellipse::Focus2() {
		return gcnew xgp_Pnt(NativeHandle()->Focus2());
	};

	//! Returns the major  radius of this ellipse.
	Standard_Real XGeom_Ellipse::MajorRadius() {
		return NativeHandle()->MajorRadius();
	};

	//! Returns the minor radius of this ellipse.
	Standard_Real XGeom_Ellipse::MinorRadius() {
		return NativeHandle()->MinorRadius();
	};


	//! Returns p = (1 - e * e) * MajorRadius where e is the eccentricity
	//! of the ellipse.
	//! Returns 0 if MajorRadius = 0
	Standard_Real XGeom_Ellipse::Parameter() {
		return NativeHandle()->Parameter();
	};

	//! Returns the value of the first parameter of this
	//! ellipse. This is respectively:
	//! - 0.0, which gives the start point of this ellipse, or
	//! The start point and end point of an ellipse are coincident.
	Standard_Real XGeom_Ellipse::FirstParameter() {
		return NativeHandle()->FirstParameter();
	};

	//! Returns the value of the  last parameter of this
	//! ellipse. This is respectively:
	//! - 2.*Pi, which gives the end point of this ellipse.
	//! The start point and end point of an ellipse are coincident.
	Standard_Real XGeom_Ellipse::LastParameter() {
		return NativeHandle()->LastParameter();
	};

	//! return True.
	Standard_Boolean XGeom_Ellipse::IsClosed() {
		return NativeHandle()->IsClosed();
	};

	//! return True.
	Standard_Boolean XGeom_Ellipse::IsPeriodic() {
		return NativeHandle()->IsPeriodic();
	};

	//! Returns in P the point of parameter U.
	//! P = C + MajorRadius * Cos (U) * XDir + MinorRadius * Sin (U) * YDir
	//! where C is the center of the ellipse , XDir the direction of
	//! the "XAxis" and "YDir" the "YAxis" of the ellipse.
	void XGeom_Ellipse::D0(Standard_Real U, xgp_Pnt^ P) {
		return NativeHandle()->D0(U, P->GetPnt());
	};

	void XGeom_Ellipse::D1(Standard_Real U, xgp_Pnt^ P, xgp_Vec^ V1) {
		return NativeHandle()->D1(U, P->GetPnt(), V1->GetVec());
	};


	//! Returns the point P of parameter U. The vectors V1 and V2
	//! are the first and second derivatives at this point.
	void XGeom_Ellipse::D2(Standard_Real U, xgp_Pnt^ P, xgp_Vec^ V1, xgp_Vec^ V2) {
		return NativeHandle()->D2(U, P->GetPnt(), V1->GetVec(), V2->GetVec());
	};


	//! Returns the point P of parameter U, the first second and
	//! third derivatives V1 V2 and V3.
	void XGeom_Ellipse::D3(Standard_Real U, xgp_Pnt^ P, xgp_Vec^ V1, xgp_Vec^ V2, xgp_Vec^ V3) {
		return NativeHandle()->D3(U, P->GetPnt(), V1->GetVec(), V2->GetVec(), V3->GetVec());
	};

	//! For the point of parameter U of this ellipse, computes
	//! the vector corresponding to the Nth derivative.
	//! Exceptions Standard_RangeError if N is less than 1.
	xgp_Vec^ XGeom_Ellipse::DN(Standard_Real U, Standard_Integer N) {
		return gcnew xgp_Vec(NativeHandle()->DN(U, N));
	};

	//! Applies the transformation T to this ellipse.
	void XGeom_Ellipse::Transform(xgp_Trsf^ T) {
		NativeHandle()->Transform(T->GetTrsf());
	};

	//! Creates a new object which is a copy of this ellipse.
	XGeom_Geometry^ XGeom_Ellipse::Copy() {
		return gcnew XGeom_Geometry(NativeHandle()->Copy());
	};
}