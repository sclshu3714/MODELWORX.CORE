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


#include <XGeom_Direction.h>

namespace TKG3d {
	//! Creates a unit vector with it 3 cartesian coordinates.
		//!
		//! Raised if Sqrt( X*X + Y*Y + Z*Z) <= Resolution from gp.
	XGeom_Direction::XGeom_Direction(Standard_Real X, Standard_Real Y, Standard_Real Z) {
		NativeHandle() = new Geom_Direction(X, Y, Z);
		SetVectorHandle(NativeHandle());
	};

	//! Creates a transient copy of <me>.
	XGeom_Direction::XGeom_Direction(xgp_Dir^ V) {
		NativeHandle() = new Geom_Direction(*V->GetDir());
		SetVectorHandle(NativeHandle());
	};

	//!
	Handle(Geom_Geometry) XGeom_Direction::GetGeometry() {
		return NativeHandle();
	};

	//!
	Handle(Geom_Vector) XGeom_Direction::GetVector() {
		return NativeHandle();
	};

	//! Sets <me> to X,Y,Z coordinates.
	//!
	//! Raised if Sqrt( X*X + Y*Y + Z*Z) <= Resolution from gp.
	void XGeom_Direction::SetCoord(Standard_Real X, Standard_Real Y, Standard_Real Z) {
		NativeHandle()->SetCoord(X, Y, Z);
	};

	//! Converts the gp_Dir unit vector V into this unit vector.
	void XGeom_Direction::SetDir(xgp_Dir^ V) {
		NativeHandle()->SetDir(*V->GetDir());
	};

	//! Changes the X coordinate of <me>.
	//!
	//! Raised if Sqrt( X*X + Y*Y + Z*Z) <= Resolution from gp.
	void XGeom_Direction::SetX(Standard_Real X) {
		NativeHandle()->SetX(X);
	};

	//! Changes the Y coordinate of <me>.
	//!
	//! Raised if Sqrt( X*X + Y*Y + Z*Z) <= Resolution from gp.
	void XGeom_Direction::SetY(Standard_Real Y) {
		NativeHandle()->SetY(Y);
	};

	//! Changes the Z coordinate of <me>.
	//!
	//! Raised if Sqrt( X*X + Y*Y + Z*Z) <= Resolution from gp.
	void XGeom_Direction::SetZ(Standard_Real Z) {
		NativeHandle()->SetZ(Z);
	};


	//! Returns the non transient direction with the same
	//! coordinates as <me>.
	xgp_Dir^ XGeom_Direction::Dir() {
		gp_Dir* temp = new gp_Dir(NativeHandle()->Dir());
		return gcnew xgp_Dir(temp);
	};

	//! returns 1.0 which is the magnitude of any unit vector.
	Standard_Real XGeom_Direction::Magnitude() {
		return NativeHandle()->Magnitude();
	};

	//! returns 1.0 which is the square magnitude of any unit vector.
	Standard_Real XGeom_Direction::SquareMagnitude() {
		return NativeHandle()->SquareMagnitude();
	};


	//! Computes the cross product between <me> and <Other>.
	//!
	//! Raised if the two vectors are parallel because it is
	//! not possible to have a direction with null length.
	void XGeom_Direction::Cross(XGeom_Vector^ Other) {
		return NativeHandle()->Cross(Other->GetVector());
	};


	//! Computes the triple vector product  <me> ^(V1 ^ V2).
	//!
	//! Raised if V1 and V2 are parallel or <me> and (V1 ^ V2) are
	//! parallel
	void XGeom_Direction::CrossCross(XGeom_Vector^ V1, XGeom_Vector^ V2) {
		NativeHandle()->CrossCross(V1->GetVector(), V2->GetVector());
	};


	//! Computes the cross product between <me> and <Other>.
	//! A new direction is returned.
	//!
	//! Raised if the two vectors are parallel because it is
	//! not possible to have a direction with null length.
	XGeom_Vector^ XGeom_Direction::Crossed(XGeom_Vector^ Other) {
		return gcnew XGeom_Vector(NativeHandle()->Crossed(Other->GetVector()));
	};


	//! Computes the triple vector product <me> ^(V1 ^ V2).
	//!
	//! Raised if V1 and V2 are parallel or <me> and (V1 ^ V2) are
	//! parallel
	XGeom_Vector^ XGeom_Direction::CrossCrossed(XGeom_Vector^ V1, XGeom_Vector^ V2) {
		return gcnew XGeom_Vector(NativeHandle()->CrossCrossed(V1->GetVector(), V2->GetVector()));
	};

	//! Applies the transformation T to this unit vector, then normalizes it.
	void XGeom_Direction::Transform(xgp_Trsf^ T) {
		NativeHandle()->Transform(T->GetTrsf());
	};

	//! Creates a new object which is a copy of this unit vector.
	XGeom_Geometry^ XGeom_Direction::Copy() {
		return gcnew XGeom_Geometry(NativeHandle()->Copy());
	};
}
