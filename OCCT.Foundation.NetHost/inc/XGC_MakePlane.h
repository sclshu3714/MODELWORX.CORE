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

#ifndef _XGC_MakePlane_HeaderFile
#define _XGC_MakePlane_HeaderFile
#pragma once
#include <NCollection_Haft.h>
#include <XGC_Root.h>
#include <GC_MakePlane.hxx>
#include <xgp_Ax1.h>
#include <xgp_Lin.h>
#include <xgp_Pnt.h>
#include <xgp_Dir.h>
#include <XGeom_Plane.h>

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <GC_Root.hxx>
#include <Geom_Plane.hxx>

class StdFail_NotDone;
class gp_Ax2;
class gp_Pln;
class gp_Pnt;
class gp_Dir;
class gp_Ax1;

using namespace TKMath;
using namespace TKG3d;
namespace TKGeomBase {
	ref class TKMath::xgp_Ax1;
	ref class TKMath::xgp_Lin;
	ref class TKMath::xgp_Pnt;
	ref class TKMath::xgp_Dir;
	ref class TKG3d::XGeom_Plane;
	//! This class implements the following algorithms used
	//! to create a Plane from gp.
	//! * Create a Plane parallel to another and passing
	//! through a point.
	//! * Create a Plane passing through 3 points.
	//! * Create a Plane by its normal
	//! A MakePlane object provides a framework for:
	//! -   defining the construction of the plane,
	//! -   implementing the construction algorithm, and
	//! -   consulting the results. In particular, the Value
	//! function returns the constructed plane.
	public ref class XGC_MakePlane : public XGC_Root
	{
	public:

		//! DEFINE_STANDARD_ALLOC


		XGC_MakePlane();

		XGC_MakePlane(GC_MakePlane* pos);

		void SetMakePlane(GC_MakePlane* pos);

		virtual GC_MakePlane* GetMakePlane();

		virtual GC_Root* GetRoot() Standard_OVERRIDE;

		//! Creates a plane from a non persistent plane from package gp.
		XGC_MakePlane(xgp_Pln^ Pl);


		//! P is the "Location" point or origin of the plane.
		//! V is the direction normal to the plane.
		XGC_MakePlane(xgp_Pnt^ P, xgp_Dir^ V);


		//! Creates a plane from its cartesian equation :
		//! Ax + By + Cz + D = 0.0
		//! Status is "BadEquation" if Sqrt (A*A + B*B + C*C)
		//! <= Resolution from gp
		XGC_MakePlane(Standard_Real A, Standard_Real B, Standard_Real C, Standard_Real D);

		//! Make a Plane from Geom <ThePlane> parallel to another
		//! Pln <Pln> and passing through a Pnt <Point>.
		XGC_MakePlane(xgp_Pln^ Pln, xgp_Pnt^ Point);

		//! Make a Plane from Geom <ThePlane> parallel to another
		//! Pln <Pln> at the distance <Dist> which can be greater
		//! or lower than zero.
		//! In the first case the result is at the distance
		//! <Dist> to the plane <Pln> in the direction of the
		//! normal to <Pln>.
		//! Otherwize it is in the oposite direction.
		XGC_MakePlane(xgp_Pln^ Pln, Standard_Real Dist);

		//! Make a Plane from Geom <ThePlane> passing through 3
		//! Pnt <P1>,<P2>,<P3>.
		//! It returns false if <P1> <P2> <P3> are confused.
		XGC_MakePlane(xgp_Pnt^ P1, xgp_Pnt^ P2, xgp_Pnt^ P3);

		//! Make a Plane  passing through the location of <Axis>and
		//! normal to the Direction of <Axis>.
		XGC_MakePlane(xgp_Ax1^ Axis);

		//! Returns the constructed plane.
		//! Exceptions StdFail_NotDone if no plane is constructed.
		XGeom_Plane^ Value();

		operator XGeom_Plane ^() { return Value(); }

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
		property  GC_MakePlane* IHandle {
			GC_MakePlane* get() {
				return 	NativeHandle;
			}
			void set(GC_MakePlane* handle) {
				NativeHandle = handle;
			}
		}

	private:
		GC_MakePlane* NativeHandle;
	};
}
#endif // _XGC_MakePlane_HeaderFile
