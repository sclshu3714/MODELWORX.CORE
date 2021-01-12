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

#ifndef _XGeom_ElementarySurface_HeaderFile
#define _XGeom_ElementarySurface_HeaderFile
#pragma once
#include <XGeom_Surface.h>
#include <Geom_ElementarySurface.hxx>
#include <XGeom_Surface.h>
#include <xgp_Ax3.h>
#include <xgp_Pnt.h>
#include <xgp_Ax1.h>

#include <Standard.hxx>
#include <Standard_Type.hxx>

#include <gp_Ax3.hxx>
#include <Geom_Surface.hxx>
#include <Standard_Real.hxx>
#include <GeomAbs_Shape.hxx>
#include <Standard_Boolean.hxx>
#include <Standard_Integer.hxx>
class Standard_ConstructionError;
class gp_Ax1;
class gp_Pnt;
class gp_Ax3;
class Geom_ElementarySurface;
//DEFINE_STANDARD_HANDLE(Geom_ElementarySurface, Geom_Surface)


using namespace TKMath;
namespace TKG3d {
	ref class TKMath::xgp_Ax3;
	ref class TKMath::xgp_Pnt;
	ref class TKMath::xgp_Ax1;
	//! Describes the common behavior of surfaces which
	//! have a simple parametric equation in a local
	//! coordinate system. The Geom package provides
	//! several implementations of concrete elementary surfaces:
	//! - the plane, and
	//! - four simple surfaces of revolution: the cylinder, the
	//! cone, the sphere and the torus.
	//! An elementary surface inherits the common behavior
	//! of Geom_Surface surfaces. Furthermore, it is located
	//! in 3D space by a coordinate system (a gp_Ax3
	//! object) which is also its local coordinate system.
	//! Any elementary surface is oriented, i.e. the normal
	//! vector is always defined, and gives the same
	//! orientation to the surface, at any point on the surface.
	//! In topology this property is referred to as the "outside
	//! region of the surface". This orientation is related to
	//! the two parametric directions of the surface.
	//! Rotation of a surface around the "main Axis" of its
	//! coordinate system, in the trigonometric sense given
	//! by the "X Direction" and the "Y Direction" of the
	//! coordinate system, defines the u parametric direction
	//! of that elementary surface of revolution. This is the
	//! default construction mode.
	//! It is also possible, however, to change the orientation
	//! of a surface by reversing one of the two parametric
	//! directions: use the UReverse or VReverse functions
	//! to change the orientation of the normal at any point on the surface.
	//! Warning
	//! The local coordinate system of an elementary surface
	//! is not necessarily direct:
	//! - if it is direct, the trigonometric sense defined by its
	//! "main Direction" is the same as the trigonometric
	//! sense defined by its two vectors "X Direction" and "Y Direction":
	//! "main Direction" = "X Direction" ^ "Y Direction"
	//! - if it is indirect, the two definitions of trigonometric
	//! sense are opposite:
	//! "main Direction" = - "X Direction" ^ "Y Direction"
	public ref class XGeom_ElementarySurface : public XGeom_Surface
	{
	public:

		//!
		XGeom_ElementarySurface(void);

		//! 
		XGeom_ElementarySurface(Handle(Geom_ElementarySurface) pos);

		//!
		~XGeom_ElementarySurface();

		void SetElementarySurfaceHandle(Handle(Geom_ElementarySurface) handle);

		//! 
		virtual Handle(Geom_ElementarySurface) GetElementarySurface();

		//!
		virtual Handle(Geom_Surface) GetSurface() Standard_OVERRIDE;

		//!
		virtual Handle(Geom_Geometry) GetGeometry() Standard_OVERRIDE;

		//! Changes the main axis (ZAxis) of the elementary surface.
		//!
		//! Raised if the direction of A1 is parallel to the XAxis of the
		//! coordinate system of the surface.
		void SetAxis(xgp_Ax1^ A1);


		//! Changes the location of the local coordinates system of the
		//! surface.
		void SetLocation(xgp_Pnt^ Loc);


		//! Changes the local coordinates system of the surface.
		void SetPosition(xgp_Ax3^ A3);


		//! Returns the main axis of the surface (ZAxis).
		xgp_Ax1^ Axis();


		//! Returns the location point of the local coordinate system of the
		//! surface.
		xgp_Pnt^ Location();

		//! Returns the local coordinates system of the surface.
		xgp_Ax3^ Position();


		//! Reverses the U parametric direction of the surface.
		virtual void UReverse() Standard_OVERRIDE;

		//! Return the  parameter on the  Ureversed surface for
		//! the point of parameter U on <me>.
		//!
		//! me->UReversed()->Value(me->UReversedParameter(U),V)
		//! is the same point as
		//! me->Value(U,V)
		virtual Standard_Real UReversedParameter(Standard_Real U) Standard_OVERRIDE;


		//! Reverses the V parametric direction of the surface.
		virtual void VReverse() Standard_OVERRIDE;

		//! Return the  parameter on the  Vreversed surface for
		//! the point of parameter V on <me>.
		//!
		//! me->VReversed()->Value(U,me->VReversedParameter(V))
		//! is the same point as
		//! me->Value(U,V)
		virtual Standard_Real VReversedParameter(Standard_Real V) Standard_OVERRIDE;

		//! Returns GeomAbs_CN, the global continuity of any elementary surface.
		XGeomAbs_Shape Continuity() Standard_OVERRIDE;

		//! Returns True.
		Standard_Boolean IsCNu(Standard_Integer N) Standard_OVERRIDE;

		//! Returns True.
		Standard_Boolean IsCNv(Standard_Integer N) Standard_OVERRIDE;


		//! DEFINE_STANDARD_RTTIEXT(Geom_ElementarySurface, Geom_Surface)
		virtual property Handle(Standard_Transient) IHandle {
			Handle(Standard_Transient) get() Standard_OVERRIDE {
				return NativeHandle();
			}
			void set(Handle(Standard_Transient) handle) Standard_OVERRIDE {
				NativeHandle() = Handle(Geom_ElementarySurface)::DownCast(handle);
			}
		};

	private:
		NCollection_Haft<Handle(Geom_ElementarySurface)> NativeHandle;
	};
}
#endif // _XGeom_ElementarySurface_HeaderFile
