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

#ifndef _XGeom_Axis1Placement_HeaderFile
#define _XGeom_Axis1Placement_HeaderFile
#pragma once
#include <Geom_AxisPlacement.hxx>
#include <Geom_Axis1Placement.hxx>
#include <XGeom_AxisPlacement.h>
#include <xgp_Ax1.h>
#include <xgp_Pnt.h>
#include <xgp_Dir.h>
#include <xgp_Trsf.h>
#include <XGeom_Geometry.h>

#include <Standard.hxx>
#include <Standard_Type.hxx>


class gp_Ax1;
class gp_Pnt;
class gp_Dir;
class gp_Trsf;
class Geom_Geometry;
class Geom_Axis1Placement;
//DEFINE_STANDARD_HANDLE(Geom_Axis1Placement, Geom_AxisPlacement)

using namespace TKMath;
namespace TKG3d {
	ref class TKMath::xgp_Ax1;
	ref class TKMath::xgp_Dir;
	ref class TKMath::xgp_Pnt;
	ref class XGeom_Geometry;
	//! Describes an axis in 3D space.
	//! An axis is defined by:
	//! - its origin, also termed the "Location point" of the axis,
	//! - its unit vector, termed the "Direction" of the axis.
	//! Note: Geom_Axis1Placement axes provide the
	//! same kind of "geometric" services as gp_Ax1 axes
	//! but have more complex data structures. The
	//! geometric objects provided by the Geom package
	//! use gp_Ax1 objects to include axes in their data
	//! structures, or to define an axis of symmetry or axis of rotation.
	//! Geom_Axis1Placement axes are used in a context
	//! where they can be shared by several objects
	//! contained inside a common data structure.
	public ref class XGeom_Axis1Placement : public XGeom_AxisPlacement
	{

	public:
		//! 
		XGeom_Axis1Placement(void);

		//! 
		XGeom_Axis1Placement(Handle(Geom_Axis1Placement) pos);

		//!
		~XGeom_Axis1Placement();

		//! 
		void SetAxis1PlacementHandle(Handle(Geom_Axis1Placement) pos);

		//!
		virtual Handle(Geom_Axis1Placement) GetAxis1Placement();

		//!
		virtual Handle(Geom_AxisPlacement) GetAxisPlacement() Standard_OVERRIDE;

		//!
		virtual Handle(Geom_Geometry) GetGeometry() Standard_OVERRIDE;

		//! Returns a transient copy of A1.
		XGeom_Axis1Placement(xgp_Ax1^ A1);


		//! P is the origin of the axis placement and V is the direction
		//! of the axis placement.
		XGeom_Axis1Placement(xgp_Pnt^ P, xgp_Dir^ V);

		//! Returns a non transient copy of <me>.
		xgp_Ax1^ Ax1();

		//! Reverses the direction of the axis placement.
		void Reverse();

		//! Returns a copy of <me> reversed.
		XGeom_Axis1Placement^ Reversed();

		//! Assigns V to the unit vector of this axis.
		void SetDirection(xgp_Dir^ V) Standard_OVERRIDE;

		//! Applies the transformation T to this axis.
		void Transform(xgp_Trsf^ T) Standard_OVERRIDE;

		//! Creates a new object, which is a copy of this axis.
		XGeom_Geometry^ Copy() Standard_OVERRIDE;

		/// <summary>
		/// ±¾µØ¾ä±ú
		/// </summary>
		virtual property Handle(Standard_Transient) IHandle {
			Handle(Standard_Transient) get() Standard_OVERRIDE {
				return 	NativeHandle();
			}
			void set(Handle(Standard_Transient) handle) Standard_OVERRIDE {
				NativeHandle() = Handle(Geom_Axis1Placement)::DownCast(handle);
			}
		}

	private:
		NCollection_Haft<Handle(Geom_Axis1Placement)> NativeHandle;
	};
}
#endif // _XGeom_Axis1Placement_HeaderFile
