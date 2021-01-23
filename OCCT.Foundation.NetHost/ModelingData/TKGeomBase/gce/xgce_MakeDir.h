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

#ifndef _xgce_MakeDir_HeaderFile
#define _xgce_MakeDir_HeaderFile
#pragma once
#include <gce_MakeDir.hxx>
#include <xgce_Root.h>
#include <xgp_Vec.h>
#include <xgp_XYZ.h>
#include <xgp_Pnt.h>
#include <xgp_Dir.h>

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <gp_Dir.hxx>
#include <gce_Root.hxx>
#include <Standard_Real.hxx>
class StdFail_NotDone;
class gp_Vec;
class gp_XYZ;
class gp_Pnt;
class gp_Dir;

using namespace TKMath;
namespace TKGeomBase {
	ref class TKMath::xgp_Vec;
	ref class TKMath::xgp_XYZ;
	ref class TKMath::xgp_Pnt;
	ref class TKMath::xgp_Dir;
	//! This class implements the following algorithms used
	//! to create a Dir from gp.
	//! * Create a Dir parallel to another and passing
	//! through a point.
	//! * Create a Dir passing through 2 points.
	//! * Create a Dir from its axis (Ax1 from gp).
	//! * Create a Dir from a point and a direction.
	public ref class xgce_MakeDir : public xgce_Root
	{
	public:

		//DEFINE_STANDARD_ALLOC
		xgce_MakeDir();
		!xgce_MakeDir() { IHandle = NULL; };
		~xgce_MakeDir() { IHandle = NULL; };
		xgce_MakeDir(gce_MakeDir* pos);

		void SetMakeDir(gce_MakeDir* pos);

		virtual gce_MakeDir* GetMakeDir();

		virtual gce_Root* GetRoot() Standard_OVERRIDE;


		//! Normalizes the vector V and creates a direction.
		//! Status is "NullVector" if V.Magnitude() <= Resolution.
		xgce_MakeDir(xgp_Vec^ V);

		//! Creates a direction from a triplet of coordinates.
		//! Status is "NullVector" if Coord.Modulus() <=
		//! Resolution from gp.
		xgce_MakeDir(xgp_XYZ^ Coord);

		//! Creates a direction with its 3 cartesian coordinates.
		//! Status is "NullVector" if Sqrt(Xv*Xv + Yv*Yv + Zv*Zv)
		//! <= Resolution
		xgce_MakeDir(Standard_Real Xv, Standard_Real Yv, Standard_Real Zv);

		//! Make a Dir from gp <TheDir> passing through 2
		//! Pnt <P1>,<P2>.
		//! Status is "ConfusedPoints" if <p1> and <P2> are confused.
		//! Warning
		//! If an error occurs (that is, when IsDone returns
		//! false), the Status function returns:
		//! -   gce_ConfusedPoints if points P1 and P2 are coincident, or
		//! -   gce_NullVector if one of the following is less
		//! than or equal to gp::Resolution():
		//! -   the magnitude of vector V,
		//! -   the modulus of Coord,
		//! -   Sqrt(Xv*Xv + Yv*Yv + Zv*Zv).
		xgce_MakeDir(xgp_Pnt^ P1, xgp_Pnt^ P2);

		//! Returns theructed unit vector.
		//! Exceptions StdFail_NotDone if no unit vector isructed.
		xgp_Dir^ Value();

		xgp_Dir^ Operator();
		operator xgp_Dir^();

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
		property gce_MakeDir* IHandle {
			gce_MakeDir* get() {
				return 	NativeHandle;
			}
			void set(gce_MakeDir* handle) {
				NativeHandle = handle;
			}
		}

	private:
		gce_MakeDir* NativeHandle;
	};
}
#endif // _xgce_MakeDir_HeaderFile
