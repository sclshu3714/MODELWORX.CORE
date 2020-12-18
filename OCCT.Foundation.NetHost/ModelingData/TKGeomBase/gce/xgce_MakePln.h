// Created on: 1992-08-26
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

#ifndef _xgce_MakePln_HeaderFile
#define _xgce_MakePln_HeaderFile
#pragma once
#include <gce_MakePln.hxx>
#include <xgce_Root.h>
#include <xgp_Ax2.h>
#include <xgp_Pnt.h>
#include <xgp_Dir.h>
#include <xgp_Pln.h>
#include <xgp_Ax1.h>

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <gp_Pln.hxx>
#include <gce_Root.hxx>
#include <Standard_Real.hxx>
class StdFail_NotDone;
class gp_Ax2;
class gp_Pnt;
class gp_Dir;
class gp_Pln;
class gp_Ax1;

using namespace TKMath;
namespace TKGeomBase {
	ref class TKMath::xgp_Ax2;
	ref class TKMath::xgp_Pnt;
	ref class TKMath::xgp_Dir;
	ref class TKMath::xgp_Pln;
	ref class TKMath::xgp_Ax1;
	//! This class implements the following algorithms used
	//! to create a Plane from gp.
	//! * Create a Pln parallel to another and passing
	//! through a point.
	//! * Create a Pln passing through 3 points.
	//! * Create a Pln by its normal.
	//! Defines a non-persistent plane.
	//! The plane is located in 3D space with an axis placement
	//! two axis. It is the local coordinate system of the plane.
	//!
	//! The "Location" point and the main direction of this axis
	//! placement define the "Axis" of the plane. It is the axis
	//! normal to the plane which gives the orientation of the
	//! plane.
	//!
	//! The "XDirection" and the "YDirection" of the axis
	//! placement define the plane ("XAxis" and "YAxis") .
	public ref class xgce_MakePln : public xgce_Root
	{
	public:

		//DEFINE_STANDARD_ALLOC

		xgce_MakePln();

		xgce_MakePln(gce_MakePln* pos);

		void SetMakePln(gce_MakePln* pos);

		virtual gce_MakePln* GetMakePln();

		virtual gce_Root* GetRoot() Standard_OVERRIDE;

		//! The coordinate system of the plane is defined with the axis
		//! placement A2.
		//! The "Direction" of A2 defines the normal to the plane.
		//! The "Location" of A2 defines the location (origin) of the plane.
		//! The "XDirection" and "YDirection" of A2 define the "XAxis" and
		//! the "YAxis" of the plane used to parametrize the plane.
		xgce_MakePln(xgp_Ax2^ A2);


		//! Creates a plane with the  "Location" point <P>
		//! and the normal direction <V>.
		xgce_MakePln(xgp_Pnt^ P, xgp_Dir^ V);


		//! Creates a plane from its cartesian equation :
		//! A * X + B * Y + C * Z + D = 0.0
		//!
		//! the status is "BadEquation" if Sqrt (A*A + B*B + C*C) <=
		//! Resolution from gp.
		xgce_MakePln(Standard_Real A, Standard_Real B, Standard_Real C, Standard_Real D);

		//! Make a Pln from gp <ThePln> parallel to another
		//! Pln <Pln> and passing through a Pnt <Point>.
		xgce_MakePln(xgp_Pln^ Pln, xgp_Pnt^ Point);

		//! Make a Pln from gp <ThePln> parallel to another
		//! Pln <Pln> at the distance <Dist> which can be greater
		//! or less than zero.
		//! In the first case the result is at the distance
		//! <Dist> to the plane <Pln> in the direction of the
		//! normal to <Pln>.
		//! Otherwize it is in the opposite direction.
		xgce_MakePln(xgp_Pln^ Pln, Standard_Real Dist);

		//! Make a Pln from gp <ThePln> passing through 3
		//! Pnt <P1>,<P2>,<P3>.
		//! It returns false if <P1> <P2> <P3> are confused.
		xgce_MakePln(xgp_Pnt^ P1, xgp_Pnt^ P2, xgp_Pnt^ P3);

		//! Make a Pln from gp <ThePln> perpendicular to the line
		//! passing through <P1>,<P2>.
		//! The status is "ConfusedPoints" if <P1> <P2> are confused.
		xgce_MakePln(xgp_Pnt^ P1, xgp_Pnt^ P2);

		//! Make a pln  passing through the location of <Axis>and
		//! normal to the Direction of <Axis>.
		//! Warning -  If an error occurs (that is, when IsDone returns
		//! false), the Status function returns:
		//! -   gce_BadEquation if Sqrt(A*A + B*B +
		//! C*C) is less than or equal to gp::Resolution(),
		//! -   gce_ConfusedPoints if P1 and P2 are coincident, or
		//! -   gce_ColinearPoints if P1, P2 and P3 are collinear.
		xgce_MakePln(xgp_Ax1^ Axis);

		//! Returns theructed plane.
		//! Exceptions StdFail_NotDone if no plane isructed.
		xgp_Pln^ Value();

		xgp_Pln^ Operator();
		operator xgp_Pln^();

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
		property gce_MakePln* IHandle {
			gce_MakePln* get() {
				return 	NativeHandle;
			}
			void set(gce_MakePln* handle) {
				NativeHandle = handle;
			}
		}

	private:
		gce_MakePln* NativeHandle;
	};
}
#endif // _xgce_MakePln_HeaderFile
