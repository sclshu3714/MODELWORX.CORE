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

#ifndef _XGeom_SweptSurface_HeaderFile
#define _XGeom_SweptSurface_HeaderFile
#pragma once
#include "NCollection_Haft.h"
#include <Geom_SweptSurface.hxx>
#include <xgp_Dir.h>
#include <XGeomAbs_Shape.h>
#include <XGeom_Surface.h>

#include <Standard.hxx>
#include <Standard_Type.hxx>

#include <gp_Dir.hxx>
#include <GeomAbs_Shape.hxx>
#include <Geom_Surface.hxx>
class Geom_Curve;
class gp_Dir;
class Geom_SweptSurface;
//DEFINE_STANDARD_HANDLE(Geom_SweptSurface, Geom_Surface)
using namespace TKMath;
namespace TKG3d
{
	ref class TKMath::xgp_Dir;
	ref class TKMath::xgp_Ax1;
	ref class XGeom_Curve;
	//! Describes the common behavior for surfaces
	//! constructed by sweeping a curve with another curve.
	//! The Geom package provides two concrete derived
	//! surfaces: surface of revolution (a revolved surface),
	//! and surface of linear extrusion (an extruded surface).
	public ref class XGeom_SweptSurface : public XGeom_Surface
	{

	public:

		//!
		XGeom_SweptSurface(void);

		//! 
		XGeom_SweptSurface(Handle(Geom_SweptSurface) pos);

		//!
		~XGeom_SweptSurface();

		void SetSweptSurfaceHandle(Handle(Geom_SweptSurface) handle);

		//!
		virtual Handle(Geom_SweptSurface) GetSweptSurface();

		//!
		virtual Handle(Geom_Surface) GetSurface() Standard_OVERRIDE;

		//!
		virtual Handle(Geom_Geometry) GetGeometry() Standard_OVERRIDE;

		//! returns the continuity of the surface :
		//! C0 : only geometric continuity,
		//! C1 : continuity of the first derivative all along the surface,
		//! C2 : continuity of the second derivative all along the surface,
		//! C3 : continuity of the third derivative all along the surface,
		//! G1 : tangency continuity all along the surface,
		//! G2 : curvature continuity all along the surface,
		//! CN : the order of continuity is infinite.
		XGeomAbs_Shape Continuity() Standard_OVERRIDE;

		//! Returns the reference direction of the swept surface.
		//! For a surface of revolution it is the direction of the
		//! revolution axis, for a surface of linear extrusion it is
		//! the direction of extrusion.
		xgp_Dir^ Direction();

		//! Returns the referenced curve of the surface.
		//! For a surface of revolution it is the revolution curve,
		//! for a surface of linear extrusion it is the extruded curve.
		XGeom_Curve^ BasisCurve();

		//DEFINE_STANDARD_RTTIEXT(Geom_SweptSurface, Geom_Surface)
		virtual property Handle(Standard_Transient) IHandle {
			Handle(Standard_Transient) get() Standard_OVERRIDE {
				return NativeHandle();
			}
			void set(Handle(Standard_Transient) handle) Standard_OVERRIDE {
				NativeHandle() = Handle(Geom_SweptSurface)::DownCast(handle);
			}
		};

	private:
		NCollection_Haft<Handle(Geom_SweptSurface)> NativeHandle;
	};
}
#endif // _XGeom_SweptSurface_HeaderFile
