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


#include <XGeom_Point.h>

namespace TKG3d {
	XGeom_Point::XGeom_Point() {
		//NativeHandle() = new Geom_Point();
	};

	XGeom_Point::XGeom_Point(Handle(Geom_Point) pos) {
		NativeHandle() = pos;
		SetGeometryHandle(NativeHandle());
	};

	void XGeom_Point::SetPointHandle(Handle(Geom_Point) pos) {
		NativeHandle() = pos; 
		SetGeometryHandle(NativeHandle());
	};

	Handle(Geom_Point) XGeom_Point::GetPoint() {
		return NativeHandle();
	};

	//!
	Handle(Geom_Geometry) XGeom_Point::GetGeometry() {
		return NativeHandle();
	};

	//! returns the Coordinates of <me>.
	void XGeom_Point::Coord(Standard_Real% X, Standard_Real% Y, Standard_Real% Z) {
		Standard_Real XX(X); Standard_Real XY(Y); Standard_Real XZ(Z);
		NativeHandle()->Coord(XX, XY, XZ);
		X = XX; XY = Y; Z = XZ;
	};

	//! returns a non transient copy of <me>
	xgp_Pnt^ XGeom_Point::Pnt() {
		gp_Pnt* temp = new gp_Pnt(NativeHandle()->Pnt());
		return gcnew xgp_Pnt(temp);
	};

	//! returns the X coordinate of <me>.
	Standard_Real XGeom_Point::X() {
		return NativeHandle()->X();
	};

	//! returns  the Y coordinate of <me>.
	Standard_Real XGeom_Point::Y() {
		return NativeHandle()->Y();
	};

	//! returns the Z coordinate of <me>.
	Standard_Real XGeom_Point::Z() {
		return NativeHandle()->Z();
	};

	//! Computes the distance between <me> and <Other>.
	Standard_Real XGeom_Point::Distance(XGeom_Point^ Other) {
		return NativeHandle()->Distance(Other->GetPoint());
	};

	//! Computes the square distance between <me> and <Other>.
	Standard_Real XGeom_Point::SquareDistance(XGeom_Point^ Other) {
		return NativeHandle()->SquareDistance(Other->GetPoint());
	};
}
