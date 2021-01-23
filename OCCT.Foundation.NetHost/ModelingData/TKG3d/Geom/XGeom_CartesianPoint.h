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

#ifndef _XGeom_CartesianPoint_HeaderFile
#define _XGeom_CartesianPoint_HeaderFile
#pragma once
#include <NCollection_Haft.h> 
#include <Geom_CartesianPoint.hxx>
#include <XGeom_Point.h>
#include <XGeom_Geometry.h>
#include <xgp_Trsf.h>
#include <xgp_Pnt.h>

#include <Standard.hxx>
#include <Standard_Type.hxx>

#include <gp_Pnt.hxx>
#include <Geom_Point.hxx>
#include <Standard_Real.hxx>
class gp_Pnt;
class gp_Trsf;
class Geom_Geometry;
class Geom_CartesianPoint;
//DEFINE_STANDARD_HANDLE(Geom_CartesianPoint, Geom_Point)

using namespace TKMath;
namespace TKG3d {
	ref class TKMath::xgp_Pnt;
	ref class TKMath::xgp_Trsf;
	ref class XGeom_Geometry;
	//! Describes a point in 3D space. A
	//! Geom_CartesianPoint is defined by a gp_Pnt point,
	//! with its three Cartesian coordinates X, Y and Z.
	public ref class XGeom_CartesianPoint : public XGeom_Point
	{

	public:
		!XGeom_CartesianPoint() { IHandle = NULL; };
		~XGeom_CartesianPoint() { IHandle = NULL; };

		XGeom_CartesianPoint();

		XGeom_CartesianPoint(Handle(Geom_CartesianPoint) pos);

		void SetCartesianPointHandle(Handle(Geom_CartesianPoint) pos);

		virtual Handle(Geom_CartesianPoint) GetCartesianPoint();

		virtual Handle(Geom_Point) GetPoint() Standard_OVERRIDE;

		//!
		virtual Handle(Geom_Geometry) GetGeometry() Standard_OVERRIDE;

		//! Returns a transient copy of P.
		XGeom_CartesianPoint(xgp_Pnt^ P);

		//! Constructs a point defined by its three Cartesian coordinates X, Y and Z.
		XGeom_CartesianPoint(Standard_Real X, Standard_Real Y, Standard_Real Z);

		//! Assigns the coordinates X, Y and Z to this point.
		void SetCoord(Standard_Real X, Standard_Real Y, Standard_Real Z);

		//! Set <me> to P.X(), P.Y(), P.Z() coordinates.
		void SetPnt(xgp_Pnt^ P);

		//! Changes the X coordinate of me.
		void SetX(Standard_Real X);

		//! Changes the Y coordinate of me.
		void SetY(Standard_Real Y);

		//! Changes the Z coordinate of me.
		void SetZ(Standard_Real Z);

		//! Returns the coordinates of <me>.
		void Coord(Standard_Real% X, Standard_Real% Y, Standard_Real% Z) Standard_OVERRIDE;


		//! Returns a non transient cartesian point with
		//! the same coordinates as <me>.
		xgp_Pnt^ Pnt() Standard_OVERRIDE;

		//! Returns the X coordinate of <me>.
		Standard_Real X() Standard_OVERRIDE;

		//! Returns the Y coordinate of <me>.
		Standard_Real Y() Standard_OVERRIDE;

		//! Returns the Z coordinate of <me>.
		Standard_Real Z() Standard_OVERRIDE;

		//! Applies the transformation T to this point.
		void Transform(xgp_Trsf^ T) Standard_OVERRIDE;

		//! Creates a new object which is a copy of this point.
		XGeom_Geometry^ Copy() Standard_OVERRIDE;

		/// <summary>
		/// ±¾µØ¾ä±ú
		/// </summary>
		virtual property Handle(Standard_Transient) IHandle {
			Handle(Standard_Transient) get() Standard_OVERRIDE {
				return 	NativeHandle();
			}
			void set(Handle(Standard_Transient) handle) Standard_OVERRIDE {
				NativeHandle() = Handle(Geom_CartesianPoint)::DownCast(handle);
			}
		}

	private:
		NCollection_Haft<Handle(Geom_CartesianPoint)> NativeHandle;
	};
}
#endif // _XGeom_CartesianPoint_HeaderFile
