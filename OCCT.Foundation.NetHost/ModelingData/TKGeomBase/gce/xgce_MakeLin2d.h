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

#ifndef _xgce_MakeLin2d_HeaderFile
#define _xgce_MakeLin2d_HeaderFile
#pragma once
#include <gce_MakeLin2d.hxx>
#include <xgce_Root.h>
#include <xgp_Ax2d.h>
#include <xgp_Pnt2d.h>
#include <xgp_Dir2d.h>
#include <xgp_Lin2d.h>

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <gp_Lin2d.hxx>
#include <gce_Root.hxx>
#include <Standard_Real.hxx>
class StdFail_NotDone;
class gp_Ax2d;
class gp_Pnt2d;
class gp_Dir2d;
class gp_Lin2d;

using namespace TKMath;
namespace TKGeomBase {
	ref class TKMath::xgp_Ax2d;
	ref class TKMath::xgp_Pnt2d;
	ref class TKMath::xgp_Dir2d;
	ref class TKMath::xgp_Lin2d;
	//! This class implements the following algorithms used
	//! to create Lin2d from gp.
	//!
	//! * Create a Lin2d parallel to another and passing
	//! through a point.
	//! * Create a Lin2d parallel to another at the distance
	//! Dist.
	//! * Create a Lin2d passing through 2 points.
	//! * Create a Lin2d from its axis (Ax1 from gp).
	//! * Create a Lin2d from a point and a direction.
	//! * Create a Lin2d from its equation.
	public ref class xgce_MakeLin2d : public xgce_Root
	{
	public:

		//DEFINE_STANDARD_ALLOC
		xgce_MakeLin2d();
		!xgce_MakeLin2d() { IHandle = NULL; };
		~xgce_MakeLin2d() { IHandle = NULL; };
		xgce_MakeLin2d(gce_MakeLin2d* pos);

		void SetMakeLin2d(gce_MakeLin2d* pos);

		virtual gce_MakeLin2d* GetMakeLin2d();

		virtual gce_Root* GetRoot() Standard_OVERRIDE;

		//! Creates a line located with A.
		xgce_MakeLin2d(xgp_Ax2d^ A);


		//! <P> is the location point (origin) of the line and
		//! <V> is the direction of the line.
		xgce_MakeLin2d(xgp_Pnt2d^ P, xgp_Dir2d^ V);


		//! Creates the line from the equation A*X + B*Y + C = 0.0
		//! the status is "NullAxis"if Sqrt(A*A + B*B) <= Resolution from gp.
		xgce_MakeLin2d(Standard_Real A, Standard_Real B, Standard_Real C);

		//! Make a Lin2d from gp <TheLin> parallel to another
		//! Lin2d <Lin> at a distance <Dist>.
		//! If Dist is greater than zero the result is on the
		//! right of the Line <Lin>, else the result is on the
		//! left of the Line <Lin>.
		xgce_MakeLin2d(xgp_Lin2d^ Lin, Standard_Real Dist);

		//! Make a Lin2d from gp <TheLin> parallel to another
		//! Lin2d <Lin> and passing through a Pnt2d <Point>.
		xgce_MakeLin2d(xgp_Lin2d^ Lin, xgp_Pnt2d^ Point);

		//! Make a Lin2d from gp <TheLin> passing through 2
		//! Pnt2d <P1>,<P2>.
		//! It returns false if <P1> and <P2> are confused.
		//! Warning
		//! If an error occurs (that is, when IsDone returns
		//! false), the Status function returns:
		//! -   gce_NullAxis if Sqrt(A*A + B*B) is less
		//! than or equal to gp::Resolution(), or
		//! -   gce_ConfusedPoints if points P1 and P2 are coincident.
		xgce_MakeLin2d(xgp_Pnt2d^ P1, xgp_Pnt2d^ P2);

		//! Returns theructed line.
		//! Exceptions StdFail_NotDone if no line isructed.
		xgp_Lin2d^ Value();

		xgp_Lin2d^ Operator();
		operator xgp_Lin2d^();

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
		property gce_MakeLin2d* IHandle {
			gce_MakeLin2d* get() {
				return 	NativeHandle;
			}
			void set(gce_MakeLin2d* handle) {
				NativeHandle = handle;
			}
		}

	private:
		gce_MakeLin2d* NativeHandle;
	};
}
#endif // _xgce_MakeLin2d_HeaderFile
