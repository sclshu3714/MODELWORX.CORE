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

#ifndef _xgce_MakeCirc2d_HeaderFile
#define _xgce_MakeCirc2d_HeaderFile
#pragma once
#include <NCollection_Haft.h>
#include <xgce_Root.h>
#include <gce_MakeCirc2d.hxx>
#include <xgp_Ax2d.h>
#include <xgp_Ax22d.h>
#include <xgp_Circ2d.h>
#include <xgp_Pnt2d.h>

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <gp_Circ2d.hxx>
#include <gce_Root.hxx>
#include <Standard_Real.hxx>
#include <Standard_Boolean.hxx>
class StdFail_NotDone;
class gp_Ax2d;
class gp_Ax22d;
class gp_Circ2d;
class gp_Pnt2d;

using namespace TKMath;
namespace TKGeomBase {
	ref class TKMath::xgp_Ax2d;
	ref class TKMath::xgp_Ax22d;
	ref class TKMath::xgp_Circ2d;
	ref class TKMath::xgp_Pnt2d;
	//! This class implements the following algorithms used
	//! to create Circ2d from gp.
	//!
	//! * Create a Circ2d concentric with another and passing
	//! though a point.
	//! * Create a Circ2d concentric with another at the distance
	//! Dist.
	//! * Create a Circ2d passing through 3 points.
	//! * Create a Circ2d with its center and radius.
	//! * Create a Circ2d with its center and a point given
	//! the radius.
	//! * Create a Circ2d with its axis and its radius.
	public ref class xgce_MakeCirc2d : public xgce_Root
	{
	public:

		//! DEFINE_STANDARD_ALLOC

		xgce_MakeCirc2d();
		!xgce_MakeCirc2d() { IHandle = NULL; };
		~xgce_MakeCirc2d() { IHandle = NULL; };
		xgce_MakeCirc2d(gce_MakeCirc2d* pos);

		void SetMakeCirc2d(gce_MakeCirc2d* pos);

		virtual gce_MakeCirc2d* GetMakeCirc2d();

		virtual gce_Root* GetRoot() Standard_OVERRIDE;

		//! The location point of XAxis is the center of the circle.
		//! Warnings :
		//! It is not forbidden to create a circle with Radius = 0.0
		//! If Sense is true the local coordinate system of the solution
		//! is direct and non direct in the other case.
		//! The status is "NegativeRadius" if Radius < 0.0.
		//! Standard_Boolean Sense = Standard_True
		xgce_MakeCirc2d(xgp_Ax2d^ XAxis, Standard_Real Radius, Standard_Boolean Sense);


		//! The location point of Axis is the center of the circle.
		//! Warnings :
		//! It is not forbidden to create a circle with Radius = 0.0
		xgce_MakeCirc2d(xgp_Ax22d^ Axis, Standard_Real Radius);

		//! Makes a Circ2d from gp <TheCirc> concentric with another
		//! circ2d <Circ> with a distance <Dist>.
		//! If Dist is greater than zero the result encloses
		//! the circle <Circ>, else the result is enclosed by the
		//! circle <Circ>.
		//! The local coordinate system of the solution is the
		//! same as Circ.
		xgce_MakeCirc2d(xgp_Circ2d^ Circ, Standard_Real Dist);

		//! Makes a Circ2d from gp <TheCirc> concentric with another
		//! circ2d <Circ> and passing through a Pnt2d <Point>.
		//! The local coordinate system of the solution is the
		//! same as Circ.
		xgce_MakeCirc2d(xgp_Circ2d^ Circ, xgp_Pnt2d^ Point);

		//! Makes a Circ2d from gp <TheCirc> passing through 3
		//! Pnt2d <P1>,<P2>,<P3>.
		//! The local coordinate system of the solution is given
		//! by the three points P1, P2, P3.
		xgce_MakeCirc2d(xgp_Pnt2d^ P1, xgp_Pnt2d^ P2, xgp_Pnt2d^ P3);

		//! Makes a Circ2d from gp <TheCirc> with its center
		//! <Center> and its radius <Radius>.
		//! If Sense is true the local coordinate system of
		//! the solution is direct and non direct in the other case.
		//! Standard_Boolean Sense = Standard_True
		xgce_MakeCirc2d(xgp_Pnt2d^ Center, Standard_Real Radius, Standard_Boolean Sense);

		//! Makes a Circ2d from gp <TheCirc> with its center
		//! <Center> and a point giving the radius.
		//! If Sense is true the local coordinate system of
		//! the solution is direct and non direct in the other case.
		//! Standard_Boolean Sense = Standard_True
		xgce_MakeCirc2d(xgp_Pnt2d^ Center, xgp_Pnt2d^ Point, Standard_Boolean Sense);

		//! Returns the constructed circle.
		//! Exceptions StdFail_NotDone if no circle is constructed.
		xgp_Circ2d^ Value();

		xgp_Circ2d^ Operator();
		operator xgp_Circ2d^();


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
		property gce_MakeCirc2d* IHandle {
			gce_MakeCirc2d* get() {
				return 	NativeHandle;
			}
			void set(gce_MakeCirc2d* handle) {
				NativeHandle = handle;
			}
		}

	private:
		gce_MakeCirc2d* NativeHandle;
	};
}
#endif // _xgce_MakeCirc2d_HeaderFile
