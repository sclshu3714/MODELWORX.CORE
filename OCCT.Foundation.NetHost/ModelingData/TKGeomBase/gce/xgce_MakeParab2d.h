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

#ifndef _xgce_MakeParab2d_HeaderFile
#define _xgce_MakeParab2d_HeaderFile
#pragma once
#include <gce_MakeParab2d.hxx>
#include <xgce_Root.h>
#include <xgp_Ax2d.h>
#include <xgp_Ax22d.h>
#include <xgp_Pnt2d.h>
#include <xgp_Parab2d.h>

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <gp_Parab2d.hxx>
#include <gce_Root.hxx>
#include <Standard_Real.hxx>
#include <Standard_Boolean.hxx>
class StdFail_NotDone;
class gp_Ax2d;
class gp_Ax22d;
class gp_Pnt2d;
class gp_Parab2d;

using namespace TKMath;
namespace TKGeomBase {
	ref class TKMath::xgp_Ax2d;
	ref class TKMath::xgp_Ax22d;
	ref class TKMath::xgp_Pnt2d;
	ref class TKMath::xgp_Parab2d;
	//! This class implements the following algorithms used to
	//! create Parab2d from gp.
	//! Defines an infinite parabola.
	//! An axis placement one axis defines the local cartesian
	//! coordinate system ("XAxis") of the parabola.
	//! The vertex of the parabola is the "Location" point of the
	//! local coordinate system of the parabola.
	//! The "XAxis" of the parabola is its axis of symmetry.
	//! The "XAxis" is oriented from the vertex of the parabola to the
	//! Focus of the parabola.
	//! The "YAxis" is parallel to the directrix of the parabola and
	//! its "Location" point is the vertex of the parabola.
	//! The equation of the parabola in the local coordinate system is
	//! Y**2 = (2*P) * X
	//! P is the distance between the focus and the directrix of the
	//! parabola called Parameter).
	//! The focal length F = P/2 is the distance between the vertex
	//! and the focus of the parabola.
	//!
	//! * Create a Parab2d from one apex  and the center.
	//! * Create a Parab2d with the directrix and the focus point.
	//! * Create a Parab2d with its vertex point and its axis
	//! of symetry and its focus length.
	public ref class xgce_MakeParab2d : public xgce_Root
	{
	public:

		//DEFINE_STANDARD_ALLOC
		xgce_MakeParab2d();

		xgce_MakeParab2d(gce_MakeParab2d* pos);

		void SetMakeParab2d(gce_MakeParab2d* pos);

		virtual gce_MakeParab2d* GetMakeParab2d();

		virtual gce_Root* GetRoot() Standard_OVERRIDE;


		//! Creates a parabola with its axis of symmetry ("MirrorAxis")
		//! and its focal length.
		//! Warnings : It is possible to have Focal = 0.
		//! The status is "NullFocalLength" Raised if Focal < 0.0
		//! Standard_Boolean Sense = Standard_True
		xgce_MakeParab2d(xgp_Ax2d^ MirrorAxis, Standard_Real Focal, Standard_Boolean Sense);


		//! Creates a parabola with its local coordinate system <A>
		//! and its focal length.
		//! Warnings : It is possible to have Focal = 0.
		//! The status is "NullFocalLength" Raised if Focal < 0.0
		xgce_MakeParab2d(xgp_Ax22d^ A, Standard_Real Focal);


		//! Creates a parabola with the directrix and the focus point.
		//! The sense of parametrization is given by Sense.
		//! Standard_Boolean Sense = Standard_True
		xgce_MakeParab2d(xgp_Ax2d^ D, xgp_Pnt2d^ F, Standard_Boolean Sense);


		//! Make an Parab2d with S1 as the Focal point and Center
		//! as the apex of the parabola
		//! Warning
		//! The MakeParab2d class does not prevent the
		//!ruction of a parabola with a null focal distance.
		//! If an error occurs (that is, when IsDone returns
		//! false), the Status function returns:
		//! -   gce_NullFocusLength if Focal is less than 0.0, or
		//! -   gce_NullAxis if S1 and Center are coincident.
		//! Standard_Boolean Sense = Standard_True
		xgce_MakeParab2d(xgp_Pnt2d^ S1, xgp_Pnt2d^ Center, Standard_Boolean Sense);

		//! Returns theructed parabola.
		//! Exceptions StdFail_NotDone if no parabola isructed.
		xgp_Parab2d^ Value();

		xgp_Parab2d^ Operator();
		operator xgp_Parab2d^();

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
		property gce_MakeParab2d* IHandle {
			gce_MakeParab2d* get() {
				return 	NativeHandle;
			}
			void set(gce_MakeParab2d* handle) {
				NativeHandle = handle;
			}
		}

	private:
		gce_MakeParab2d* NativeHandle;
	};
}
#endif // _xgce_MakeParab2d_HeaderFile
