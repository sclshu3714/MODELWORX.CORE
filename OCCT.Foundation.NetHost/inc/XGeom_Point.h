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

#ifndef _XGeom_Point_HeaderFile
#define _XGeom_Point_HeaderFile
#pragma once
#include <Geom_Point.hxx>
#include <NCollection_Haft.h> 
#include <XGeom_Geometry.h>
#include <Geom_Curve.hxx>
#include <xgp_Pnt.h>

#include <Standard.hxx>
#include <Standard_Type.hxx>

#include <Geom_Geometry.hxx>
#include <Standard_Real.hxx>
class Geom_Curve;


//class Geom_Point;
//DEFINE_STANDARD_HANDLE(Geom_Point, Geom_Geometry)
using namespace TKMath;
//! The abstract class Point describes the common
//! behavior of geometric points in 3D space.
//! The Geom package also provides the concrete class
//! Geom_CartesianPoint.
namespace TKG3d {
	ref class TKMath::xgp_Pnt;
	public ref class XGeom_Point : public XGeom_Geometry
	{

	public:
		XGeom_Point();

		XGeom_Point(Handle(Geom_Point) pos);

		void SetPointHandle(Handle(Geom_Point) pos);

		virtual Handle(Geom_Point) GetPoint();

		//!
		virtual Handle(Geom_Geometry) GetGeometry() Standard_OVERRIDE;

		//! returns the Coordinates of <me>.
		virtual void Coord(Standard_Real% X, Standard_Real% Y, Standard_Real% Z);

		//! returns a non transient copy of <me>
		virtual xgp_Pnt^ Pnt();

		//! returns the X coordinate of <me>.
		virtual Standard_Real X();

		//! returns  the Y coordinate of <me>.
		virtual Standard_Real Y();

		//! returns the Z coordinate of <me>.
		virtual Standard_Real Z();

		//! Computes the distance between <me> and <Other>.
		Standard_Real Distance(XGeom_Point^ Other);

		//! Computes the square distance between <me> and <Other>.
		Standard_Real SquareDistance(XGeom_Point^ Other);

		//! DEFINE_STANDARD_RTTIEXT(Geom_Point, Geom_Geometry)
			/// <summary>
			/// ±¾µØ¾ä±ú
			/// </summary>
		virtual property Handle(Standard_Transient) IHandle {
			Handle(Standard_Transient) get() Standard_OVERRIDE {
				return 	NativeHandle();
			}
			void set(Handle(Standard_Transient) handle) Standard_OVERRIDE {
				NativeHandle() = Handle(Geom_Point)::DownCast(handle);
			}
		}

	private:
		NCollection_Haft<Handle(Geom_Point)> NativeHandle;
	};
}
#endif // _XGeom_Point_HeaderFile
