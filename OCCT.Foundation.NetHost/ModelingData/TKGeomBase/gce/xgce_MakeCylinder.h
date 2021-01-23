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

#ifndef _xgce_MakeCylinder_HeaderFile
#define _xgce_MakeCylinder_HeaderFile
#pragma once
#include <gce_MakeCylinder.hxx>
#include <xgce_Root.h>
#include <xgp_Ax2.h>
#include <xgp_Cylinder.h>
#include <xgp_Pnt.h>
#include <xgp_Ax1.h>
#include <xgp_Circ.h>

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <gp_Cylinder.hxx>
#include <gce_Root.hxx>
#include <Standard_Real.hxx>
class StdFail_NotDone;
class gp_Ax2;
class gp_Cylinder;
class gp_Pnt;
class gp_Ax1;
class gp_Circ;

using namespace TKMath;
namespace TKGeomBase {
	ref class TKMath::xgp_Vec;
	ref class TKMath::xgp_XYZ;
	ref class TKMath::xgp_Pnt;
	ref class TKMath::xgp_Dir;
	//! This class implements the following algorithms used
	//! to create a Cylinder from gp.
	//! * Create a Cylinder coaxial to another and passing
	//! through a point.
	//! * Create a Cylinder coaxial to another at a distance
	//! <Dist>.
	//! * Create a Cylinder with 3 points.
	//! * Create a Cylinder by its axis and radius.
	//! * Create a cylinder by its circular base.
	public ref class xgce_MakeCylinder : public xgce_Root
	{
	public:

		//DEFINE_STANDARD_ALLOC
		xgce_MakeCylinder();
		!xgce_MakeCylinder() { IHandle = NULL; };
		~xgce_MakeCylinder() { IHandle = NULL; };
		xgce_MakeCylinder(gce_MakeCylinder* pos);

		void SetMakeCylinder(gce_MakeCylinder* pos);

		virtual gce_MakeCylinder* GetMakeCylinder();

		virtual gce_Root* GetRoot() Standard_OVERRIDE;


		//! <A2> is the local cartesian coordinate system of <me>.
		//! The status is "NegativeRadius" if R < 0.0
		xgce_MakeCylinder(xgp_Ax2^ A2, Standard_Real Radius);

		//! Makes a Cylinder from gp <TheCylinder> coaxial to another
		//! Cylinder <Cylinder> and passing through a Pnt <Point>.
		xgce_MakeCylinder(xgp_Cylinder^ Cyl, xgp_Pnt^ Point);

		//! Makes a Cylinder from gp <TheCylinder> coaxial to another
		//! Cylinder <Cylinder> at the distance <Dist> which can
		//! be greater or lower than zero.
		//! The radius of the result is the absolute value of the
		//! radius of <Cyl> plus <Dist>
		xgce_MakeCylinder(xgp_Cylinder^ Cyl, Standard_Real Dist);

		//! Makes a Cylinder from gp <TheCylinder> with 3 points
		//! <P1>,<P2>,<P3>.
		//! Its axis is <P1P2> and its radius is the distance
		//! between <P3> and <P1P2>
		xgce_MakeCylinder(xgp_Pnt^ P1, xgp_Pnt^ P2, xgp_Pnt^ P3);

		//! Makes a Cylinder by its axis <Axis> and radius <Radius>.
		xgce_MakeCylinder(xgp_Ax1^ Axis, Standard_Real Radius);

		//! Makes a Cylinder by its circular base.
		//! Warning
		//! If an error occurs (that is, when IsDone returns
		//! false), the Status function returns:
		//! -   gce_NegativeRadius if:
		//! -   Radius is less than 0.0, or
		//! -   Dist is negative and has an absolute value
		//! which is greater than the radius of Cyl; or
		//! -   gce_ConfusedPoints if points P1 and P2 are coincident.
		xgce_MakeCylinder(xgp_Circ^ Circ);

		//! Returns theructed cylinder.
		//! Exceptions StdFail_NotDone if no cylinder isructed.
		xgp_Cylinder^ Value();

		xgp_Cylinder^ Operator();
		operator xgp_Cylinder^();

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
		property gce_MakeCylinder* IHandle {
			gce_MakeCylinder* get() {
				return 	NativeHandle;
			}
			void set(gce_MakeCylinder* handle) {
				NativeHandle = handle;
			}
		}

	private:
		gce_MakeCylinder* NativeHandle;
	};
}
#endif // _xgce_MakeCylinder_HeaderFile
