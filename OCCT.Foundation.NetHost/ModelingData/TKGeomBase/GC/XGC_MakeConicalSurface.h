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

#ifndef _XGC_MakeConicalSurface_HeaderFile
#define _XGC_MakeConicalSurface_HeaderFile
#pragma once
#include <XGC_Root.h>
#include <GC_MakeConicalSurface.hxx>
#include <XGeom_ConicalSurface.h>
#include <xgp_Cone.h>
#include <xgp_Ax2.h>
#include <xgp_Pnt.h>
#include <xgp_Ax1.h>
#include <xgp_Lin.h>

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <GC_Root.hxx>
#include <Geom_ConicalSurface.hxx>

class StdFail_NotDone;
class gp_Ax2;
class gp_Cone;
class gp_Pnt;
class gp_Ax1;
class gp_Lin;

using namespace TKMath;
using namespace TKG3d;
namespace TKGeomBase {
	ref class TKMath::xgp_Cone;
	ref class TKMath::xgp_Ax2;
	ref class TKMath::xgp_Pnt;
	ref class TKMath::xgp_Ax1;
	ref class TKMath::xgp_Lin;
	ref class TKG3d::XGeom_ConicalSurface;
	//! This class implements the following algorithms used
	//! to create a ConicalSurface from Geom.
	//! * Create a ConicalSurface parallel to another and passing
	//! through a point.
	//! * Create a ConicalSurface parallel to another at a distance
	//! <Dist>.
	//! * Create a ConicalSurface by 4 points.
	//! * Create a ConicalSurface by its axis and 2 points.
	//! * Create a ConicalSurface by 2 points and 2 radius.
	//! The local coordinate system of the ConicalSurface is defined
	//! with an axis placement (see class ElementarySurface).
	//!
	//! The "ZAxis" is the symmetry axis of the ConicalSurface,
	//! it gives the direction of increasing parametric value V.
	//! The apex of the surface is on the negative side of this axis.
	//!
	//! The parametrization range is  :
	//! U [0, 2*PI],  V ]-infinite, + infinite[
	//!
	//! The "XAxis" and the "YAxis" define the placement plane of the
	//! surface (Z = 0, and parametric value V = 0)  perpendicular to
	//! the symmetry axis. The "XAxis" defines the origin of the
	//! parameter U = 0.  The trigonometric sense gives the positive
	//! orientation for the parameter U.
	//!
	//! When you create a ConicalSurface the U and V directions of
	//! parametrization are such that at each point of the surface the
	//! normal is oriented towards the "outside region".
	public ref class XGC_MakeConicalSurface : public XGC_Root
	{
	public:

		//! DEFINE_STANDARD_ALLOC

		XGC_MakeConicalSurface(GC_MakeConicalSurface* pos);

		void SetMakeConicalSurfaceHandle(GC_MakeConicalSurface* pos);

		GC_MakeConicalSurface* GetMakeConicalSurface();

		//! A2 defines the local coordinate system of the conical surface.
		//! Ang is the conical surface semi-angle ]0, PI/2[.
		//! Radius is the radius of the circle Viso in the placement plane
		//! of the conical surface defined with "XAxis" and "YAxis".
		//! The "ZDirection" of A2 defines the direction of the surface's
		//! axis of symmetry.
		//! If the location point of A2 is the apex of the surface
		//! Radius = 0 .
		//! At the creation the parametrization of the surface is defined
		//! such that the normal Vector (N = D1U ^ D1V) is oriented towards
		//! the "outside region" of the surface.
		//! Status is "NegativeRadius" if Radius < 0.0 or "BadAngle" if
		//! Ang < Resolution from gp or Ang >= PI/ - Resolution
		XGC_MakeConicalSurface(xgp_Ax2^ A2, Standard_Real Ang, Standard_Real Radius);

		//! Creates a ConicalSurface from a non persistent Cone from package gp.
		XGC_MakeConicalSurface(xgp_Cone^ C);

		//! Make a ConicalSurface from Geom <TheCone> passing through 3
		//! Pnt <P1>,<P2>,<P3>.
		//! Its axis is <P1P2> and the radius of its base is
		//! the distance between <P3> and <P1P2>.
		//! The distance between <P4> and <P1P2> is the radius of
		//! the section passing through <P4>.
		//! An error iss raised if <P1>,<P2>,<P3>,<P4> are
		//! colinear or if <P3P4> is perpendicular to <P1P2> or
		//! <P3P4> is colinear to <P1P2>.
		XGC_MakeConicalSurface(xgp_Pnt^ P1, xgp_Pnt^ P2, xgp_Pnt^ P3, xgp_Pnt^ P4);

		//! Make a ConicalSurface with two points and two radius.
		//! The axis of the solution is the line passing through
		//! <P1> and <P2>.
		//! <R1> is the radius of the section passing through <P1>
		//! and <R2> the radius of the section passing through <P2>.
		XGC_MakeConicalSurface(xgp_Pnt^ P1, xgp_Pnt^ P2, Standard_Real R1, Standard_Real R2);

		//! Returns the constructed cone.
		//! Exceptions
		//! StdFail_NotDone if no cone is constructed.
		XGeom_ConicalSurface^ Value();

		operator XGeom_ConicalSurface^() { return Value(); }

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
		virtual property  GC_MakeConicalSurface* IHandle {
			GC_MakeConicalSurface* get() {
				return 	NativeHandle;
			}
			void set(GC_MakeConicalSurface* handle) {
				NativeHandle = handle;
			}
		}

	private:
		GC_MakeConicalSurface* NativeHandle;
	};
}
#endif // _XGC_MakeConicalSurface_HeaderFile
