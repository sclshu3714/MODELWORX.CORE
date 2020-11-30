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


#include <XGeom_Vector.h>
namespace TKG3d {
	XGeom_Vector::XGeom_Vector() {
		//NativeHandle() = new Geom_Vector();
	};

	XGeom_Vector::XGeom_Vector(Handle(Geom_Vector) pos) {
		NativeHandle() = pos;
		SetGeomHandle(NativeHandle());
	};

	void XGeom_Vector::SetVectorHandle(Handle(Geom_Vector) handle) {
		NativeHandle() = handle;
		SetGeomHandle(NativeHandle());
	};

	Handle(Geom_Vector) XGeom_Vector::GetVector() {
		return NativeHandle();
	};

	//!
	Handle(Geom_Geometry) XGeom_Vector::GetGeometry() {
		return NativeHandle();
	};

	//! Reverses the vector <me>.
	void XGeom_Vector::Reverse() {
		NativeHandle()->Reverse();
	};

	//! Returns a copy of <me> reversed.
	XGeom_Vector^ XGeom_Vector::Reversed() {
		return gcnew XGeom_Vector(NativeHandle()->Reversed());
	};

	//! Computes the angular value, in radians, between this
	//! vector and vector Other. The result is a value between 0 and Pi.
	//! Exceptions
	//! gp_VectorWithNullMagnitude if:
	//! - the magnitude of this vector is less than or equal to
	//! gp::Resolution(), or
	//! - the magnitude of vector Other is less than or equal
	//! to gp::Resolution().
	Standard_Real XGeom_Vector::Angle(XGeom_Vector^ Other) {
		return NativeHandle()->Angle(Other->GetVector());
	};

	//! Computes the angular value, in radians, between this
	//! vector and vector Other. The result is a value
	//! between -Pi and Pi. The vector VRef defines the
	//! positive sense of rotation: the angular value is positive
	//! if the cross product this ^ Other has the same
	//! orientation as VRef (in relation to the plane defined
	//! by this vector and vector Other). Otherwise, it is negative.
	//! Exceptions
	//! Standard_DomainError if this vector, vector Other
	//! and vector VRef are coplanar, except if this vector
	//! and vector Other are parallel.
	//! gp_VectorWithNullMagnitude if the magnitude of
	//! this vector, vector Other or vector VRef is less than
	//! or equal to gp::Resolution().
	Standard_Real XGeom_Vector::AngleWithRef(XGeom_Vector^ Other, XGeom_Vector^ VRef) {
		return NativeHandle()->AngleWithRef(Other->GetVector(), VRef->GetVector());
	};

	//! Returns the coordinates X, Y and Z of this vector.
	void XGeom_Vector::Coord(Standard_Real X, Standard_Real Y, Standard_Real Z) {
		NativeHandle()->Coord(X, Y, Z);
	};

	//! Returns the  Magnitude of <me>.
	Standard_Real XGeom_Vector::Magnitude() {
		return NativeHandle()->Magnitude();
	};

	//! Returns the square magnitude of <me>.
	Standard_Real XGeom_Vector::SquareMagnitude() {
		return NativeHandle()->SquareMagnitude();
	};

	//! Returns the X coordinate of <me>.
	Standard_Real XGeom_Vector::X() {
		return NativeHandle()->X();
	};

	//! Returns the Y coordinate of <me>.
	Standard_Real XGeom_Vector::Y() {
		return NativeHandle()->Y();
	};

	//! Returns the Z coordinate of <me>.
	Standard_Real XGeom_Vector::Z() {
		return NativeHandle()->Z();
	};


	//! Computes the cross product between <me> and <Other>.
	//!
	//! Raised if <me> is a "Direction" and if <me> and <Other>
	//! are parallel because it is not possible to build a
	//! "Direction" with null length.
	void XGeom_Vector::Cross(XGeom_Vector^ Other) {
		NativeHandle()->Cross(Other->GetVector());
	};


	//! Computes the cross product between <me> and <Other>.
	//! A new direction is returned.
	//!
	//! Raised if <me> is a "Direction" and if the two vectors
	//! are parallel because it is not possible to create a
	//! "Direction" with null length.
	XGeom_Vector^ XGeom_Vector::Crossed(XGeom_Vector^ Other) {
		return gcnew XGeom_Vector(NativeHandle()->Crossed(Other->GetVector()));
	};


	//! Computes the triple vector product  <me> ^(V1 ^ V2).
	//!
	//! Raised if <me> is a "Direction" and if V1 and V2 are parallel
	//! or <me> and (V1 ^ V2) are  parallel
	void XGeom_Vector::CrossCross(XGeom_Vector^ V1, XGeom_Vector^ V2) {
		NativeHandle()->CrossCross(V1->GetVector(), V2->GetVector());
	};


	//! Computes the triple vector product <me> ^(V1 ^ V2).
	//!
	//! Raised if <me> is a direction and if V1 and V2 are
	//! parallel or <me> and (V1 ^ V2) are parallel
	XGeom_Vector^ XGeom_Vector::CrossCrossed(XGeom_Vector^ V1, XGeom_Vector^ V2) {
		return gcnew XGeom_Vector(NativeHandle()->CrossCrossed(V1->GetVector(), V2->GetVector()));
	};

	//! Computes the scalar product of this vector and vector Other.
	Standard_Real XGeom_Vector::Dot(XGeom_Vector^ Other) {
		return NativeHandle()->Dot(Other->GetVector());
	};


	//! Computes the triple scalar product. Returns me . (V1 ^ V2)
	Standard_Real XGeom_Vector::DotCross(XGeom_Vector^ V1, XGeom_Vector^ V2) {
		return NativeHandle()->DotCross(V1->GetVector(), V2->GetVector());
	};

	//! Converts this vector into a gp_Vec vector.
	xgp_Vec^ XGeom_Vector::Vec() {
		return gcnew xgp_Vec(NativeHandle()->Vec());
	};
}



