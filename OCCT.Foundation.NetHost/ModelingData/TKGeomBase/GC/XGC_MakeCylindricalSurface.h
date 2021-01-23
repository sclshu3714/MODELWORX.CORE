// Created on: 1992-09-28
// Created by: Remi GILET
// Copyright (c) 1992-1999 Matra Datavision
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

#ifndef _XGC_MakeCylindricalSurface_HeaderFile
#define _XGC_MakeCylindricalSurface_HeaderFile
#pragma once
#include <XGC_Root.h>
#include <GC_MakeCylindricalSurface.hxx>
#include <XGeom_CylindricalSurface.h>
#include <xgp_Cylinder.h>
#include <xgp_Ax2.h>
#include <xgp_Pnt.h>
#include <xgp_Ax1.h>
#include <xgp_Circ.h>


#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <GC_Root.hxx>
#include <Geom_CylindricalSurface.hxx>

class StdFail_NotDone;
class gp_Ax2;
class gp_Cylinder;
class gp_Pnt;
class gp_Ax1;
class gp_Circ;

using namespace TKMath;
using namespace TKG3d;
namespace TKGeomBase {
	ref class TKMath::xgp_Cylinder;
	ref class TKMath::xgp_Ax2;
	ref class TKMath::xgp_Pnt;
	ref class TKMath::xgp_Ax1;
	ref class TKMath::xgp_Circ;
	ref class TKG3d::XGeom_CylindricalSurface;
	//! This class implements the following algorithms used
	//! to create a CylindricalSurface from Geom.
	//! * Create a CylindricalSurface parallel to another and
	//! passing through a point.
	//! * Create a CylindricalSurface parallel to another at a
	//! distance
	//! <Dist>.
	//! * Create a CylindricalSurface passing through 3 points.
	//! * Create a CylindricalSurface by its axis and radius.
	//! * Create a cylindricalSurface by its circular base.
	//! The local coordinate system of the CylindricalSurface is defined
	//! with an axis placement (see class ElementarySurface).
	//!
	//! The "ZAxis" is the symmetry axis of the CylindricalSurface,
	//! it gives the direction of increasing parametric value V.
	//!
	//! The parametrization range is :
	//! U [0, 2*PI],  V ]- infinite, + infinite[
	//!
	//! The "XAxis" and the "YAxis" define the placement plane of the
	//! surface (Z = 0, and parametric value V = 0)  perpendicular to
	//! the symmetry axis. The "XAxis" defines the origin of the
	//! parameter U = 0.  The trigonometric sense gives the positive
	//! orientation for the parameter U.
	public ref class XGC_MakeCylindricalSurface : public XGC_Root
	{
	public:

		//! DEFINE_STANDARD_ALLOC
		!XGC_MakeCylindricalSurface() { IHandle = NULL; };
		~XGC_MakeCylindricalSurface() { IHandle = NULL; };
		//!
		XGC_MakeCylindricalSurface(GC_MakeCylindricalSurface* pos);

		//!
		void SetMakeCylindricalSurfaceHandle(GC_MakeCylindricalSurface* pos);

		//!
		GC_MakeCylindricalSurface* GetMakeCylindricalSurface();

		//! A2 defines the local coordinate system of the cylindrical surface.
		//! The "ZDirection" of A2 defines the direction of the surface's
		//! axis of symmetry.
		//! At the creation the parametrization of the surface is defined
		//! such that the normal Vector (N = D1U ^ D1V) is oriented towards
		//! the "outside region" of the surface.
		//! Warnings :
		//! It is not forbidden to create a cylindrical surface with
		//! Radius = 0.0
		//! Status is "NegativeRadius" if Radius < 0.0
		XGC_MakeCylindricalSurface(xgp_Ax2^ A2, Standard_Real Radius);


		//! Creates a CylindricalSurface from a non persistent Cylinder
		//! from package gp.
		XGC_MakeCylindricalSurface(xgp_Cylinder^ C);

		//! Make a CylindricalSurface from Geom <TheCylinder>
		//! parallel to another
		//! CylindricalSurface <Cylinder> and passing through a
		//! Pnt <Point>.
		XGC_MakeCylindricalSurface(xgp_Cylinder^ Cyl, xgp_Pnt^ Point);

		//! Make a CylindricalSurface from Geom <TheCylinder>
		//! parallel to another
		//! CylindricalSurface <Cylinder> at the distance <Dist>
		//! which can be greater or lower than zero.
		//! The radius of the result is the absolute value of the
		//! radius of <Cyl> plus <Dist>
		XGC_MakeCylindricalSurface(xgp_Cylinder^ Cyl, Standard_Real Dist);

		//! Make a CylindricalSurface from Geom <TheCylinder>
		//! passing through 3 Pnt <P1>,<P2>,<P3>.
		//! Its axis is <P1P2> and its radius is the distance
		//! between <P3> and <P1P2>
		XGC_MakeCylindricalSurface(xgp_Pnt^ P1, xgp_Pnt^ P2, xgp_Pnt^ P3);

		//! Make a CylindricalSurface by its axis <Axis> and radius
		//! <Radius>.
		XGC_MakeCylindricalSurface(xgp_Ax1^ Axis, Standard_Real Radius);

		//! Make a CylindricalSurface by its circular base.
		XGC_MakeCylindricalSurface(xgp_Circ^ Circ);

		//! Returns the constructed cylinder.
		//! Exceptions StdFail_NotDone if no cylinder is constructed.
		XGeom_CylindricalSurface^ Value();

		operator XGeom_CylindricalSurface^() { return Value(); }
		//! Returns true if the construction is successful.
		virtual Standard_Boolean IsDone() Standard_OVERRIDE;

		//! Returns the status of the construction:
		//! -   gce_Done, if the construction is successful, or
		//! -   another value of the gce_ErrorType enumeration
		//! indicating why the construction failed.
		virtual xgce_ErrorType Status() Standard_OVERRIDE;

		/// <summary>
		/// ±¾µØ¾ä±ú
		/// </summary>
		virtual property  GC_MakeCylindricalSurface* IHandle {
			GC_MakeCylindricalSurface* get() {
				return 	NativeHandle;
			}
			void set(GC_MakeCylindricalSurface* handle) {
				NativeHandle = handle;
			}
		}

	private:
		GC_MakeCylindricalSurface* NativeHandle;
	};
}
#endif // _XGC_MakeCylindricalSurface_HeaderFile
