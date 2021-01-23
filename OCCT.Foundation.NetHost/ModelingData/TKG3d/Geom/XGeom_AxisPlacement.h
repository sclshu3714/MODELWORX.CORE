// Created on: 1993-03-09
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

#ifndef _XGeom_AxisPlacement_HeaderFile
#define _XGeom_AxisPlacement_HeaderFile
#pragma once
#include "NCollection_Haft.h"
#include "Geom_AxisPlacement.hxx"
#include "XGeom_Geometry.h"
#include <xgp_Ax1.h>
#include <xgp_Dir.h>
#include <xgp_Pnt.h>
#include <Standard.hxx>
#include <Standard_Type.hxx>

#include <gp_Ax1.hxx>
#include <Geom_Geometry.hxx>
#include <Standard_Real.hxx>
class Standard_ConstructionError;
class gp_Ax1;
class gp_Dir;
class gp_Pnt;
class Geom_AxisPlacement;
//DEFINE_STANDARD_HANDLE(Geom_AxisPlacement, Geom_Geometry)

using namespace TKMath;
namespace TKG3d {
	ref class TKMath::xgp_Ax1;
	ref class TKMath::xgp_Dir;
	ref class TKMath::xgp_Pnt;
	ref class XGeom_Geometry;
	//! The abstract class AxisPlacement describes the
	//! common behavior of positioning systems in 3D space,
	//! such as axis or coordinate systems.
	//! The Geom package provides two implementations of
	//! 3D positioning systems:
	//! - the axis (Geom_Axis1Placement class), which is defined by:
	//! - its origin, also termed the "Location point" of the  axis,
	//! - its unit vector, termed the "Direction" or "main
	//! Direction" of the axis;
	//! - the right-handed coordinate system
	//! (Geom_Axis2Placement class), which is defined by:
	//! - its origin, also termed the "Location point" of the coordinate system,
	//! - three orthogonal unit vectors, termed
	//! respectively the "X Direction", the "Y Direction"
	//! and the "Direction" of the coordinate system. As
	//! the coordinate system is right-handed, these
	//! unit vectors have the following relation:
	//! "Direction" = "X Direction" ^
	//! "Y Direction". The "Direction" is also
	//! called the "main Direction" because, when the
	//! unit vector is modified, the "X Direction" and "Y
	//! Direction" are recomputed, whereas when the "X
	//! Direction" or "Y Direction" is modified, the "main Direction" does not change.
	//! The axis whose origin is the origin of the positioning
	//! system and whose unit vector is its "main Direction" is
	//! also called the "Axis" or "main Axis" of the positioning system.
	public ref class XGeom_AxisPlacement : public XGeom_Geometry
	{

	public:

		//! 
		XGeom_AxisPlacement(void);

		//! 
		XGeom_AxisPlacement(Handle(Geom_AxisPlacement) pos);

		//!
		~XGeom_AxisPlacement();

		!XGeom_AxisPlacement() { IHandle = NULL; };
		//! 
		void SetAxisPlacementHandle(Handle(Geom_AxisPlacement) pos);

		//!
		virtual Handle(Geom_AxisPlacement) GetAxisPlacement();

		//!
		virtual Handle(Geom_Geometry) GetGeometry() Standard_OVERRIDE;

		//! Assigns A1 as the "main Axis" of this positioning system. This modifies
		//! - its origin, and
		//! - its "main Direction".
		//! If this positioning system is a
		//! Geom_Axis2Placement, then its "X Direction" and
		//! "Y Direction" are recomputed.
		//! Exceptions
		//! For a Geom_Axis2Placement:
		//! Standard_ConstructionError if A1 and the
		//! previous "X Direction" of the coordinate system are parallel.
		void SetAxis(xgp_Ax1^ A1);


		//! Changes the direction of the axis placement.
		//! If <me> is an axis placement two axis the main "Direction"
		//! is modified and the "XDirection" and "YDirection" are
		//! recomputed.
		//! Raises ConstructionError only for an axis placement two axis if V and the
		//! previous "XDirection" are parallel because it is not possible
		//! to calculate the new "XDirection" and the new "YDirection".
		virtual void SetDirection(xgp_Dir^ V);


		//! Assigns the point P as the origin of this positioning  system.
		void SetLocation(xgp_Pnt^ P);

		//! Computes the angular value, in radians, between the
		//! "main Direction" of this positioning system and that
		//! of positioning system Other. The result is a value between 0 and Pi.
		Standard_Real Angle(XGeom_AxisPlacement^ Other);

		//! Returns the main axis of the axis placement.
		//! For an "Axis2placement" it is the main axis (Location, Direction ).
		//! For an "Axis1Placement" this method returns a copy of <me>.
		xgp_Ax1^ Axis();


		//! Returns the main "Direction" of an axis placement.
		xgp_Dir^ Direction();


		//! Returns the Location point (origin) of the axis placement.
		xgp_Pnt^ Location();


		/// <summary>
		/// ±¾µØ¾ä±ú
		/// </summary>
		virtual property Handle(Standard_Transient) IHandle {
			Handle(Standard_Transient) get() Standard_OVERRIDE {
				return 	NativeHandle();
			}
			void set(Handle(Standard_Transient) handle) Standard_OVERRIDE {
				NativeHandle() = Handle(Geom_AxisPlacement)::DownCast(handle);
			}
		}

	private:
		NCollection_Haft<Handle(Geom_AxisPlacement)> NativeHandle;
	};
}
#endif // _XGeom_AxisPlacement_HeaderFile
