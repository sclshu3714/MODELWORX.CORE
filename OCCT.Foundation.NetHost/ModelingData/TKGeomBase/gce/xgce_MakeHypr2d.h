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

#ifndef _xgce_MakeHypr2d_HeaderFile
#define _xgce_MakeHypr2d_HeaderFile
#pragma once
#include <gce_MakeHypr2d.hxx>
#include <xgce_Root.h>
#include <xgp_Pnt2d.h>
#include <xgp_Ax2d.h>
#include <xgp_Ax22d.h>
#include <xgp_Hypr2d.h>

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <gp_Hypr2d.hxx>
#include <gce_Root.hxx>
#include <Standard_Real.hxx>
#include <Standard_Boolean.hxx>
class StdFail_NotDone;
class gp_Pnt2d;
class gp_Ax2d;
class gp_Ax22d;
class gp_Hypr2d;

using namespace TKMath;
namespace TKGeomBase {
	ref class TKMath::xgp_Pnt2d;
	ref class TKMath::xgp_Ax2d;
	ref class TKMath::xgp_Ax22d;
	ref class TKMath::xgp_Hypr2d;
	//! This class implements the following algorithms used to
	//! create a 2d Hyperbola from gp.
	//! * Create a 2d Hyperbola from its center and two points:
	//! one on its axis of symmetry giving the major radius, the
	//! other giving the value of the small radius.
	//! * Create a 2d Hyperbola from its major axis and its major
	//! radius and its minor radius.
	//!
	//! ^YAxis
	//! |
	//! FirstConjugateBranch
	//! |
	//! Other            |                Main
	//! --------------------- C ------------------------------>XAxis
	//! Branch           |                Branch
	//! |
	//! |
	//! SecondConjugateBranch
	//! |
	//!
	//! An axis placement (one axis) is associated with the hyperbola.
	//! This axis is the "XAxis" or major axis of the hyperbola. It is
	//! the symmetry axis of the main branch of hyperbola.
	//! The "YAxis" is normal to this axis and pass throught its location
	//! point. It is the minor axis.
	//!
	//! The major radius is the distance between the Location point
	//! of the hyperbola C and the vertex of the Main Branch (or the
	//! Other branch). The minor radius is the distance between the
	//! Location point of the hyperbola C and the vertex of the First
	//! (or Second) Conjugate branch.
	//! The major radius can be lower than the minor radius.
	public ref class xgce_MakeHypr2d : public xgce_Root
	{
	public:

		//DEFINE_STANDARD_ALLOC
		xgce_MakeHypr2d();
		!xgce_MakeHypr2d() { IHandle = NULL; };
		~xgce_MakeHypr2d() { IHandle = NULL; };
		xgce_MakeHypr2d(gce_MakeHypr2d* pos);

		void SetMakeHypr2d(gce_MakeHypr2d* pos);

		virtual gce_MakeHypr2d* GetMakeHypr2d();

		virtual gce_Root* GetRoot() Standard_OVERRIDE;


		//! Constructs a hyperbola
		//! centered on the point Center, where:
		//! -   the major axis of the hyperbola is defined by Center and point S1,
		//! -   the major radius is the distance between Center and S1, and
		//! -   the minor radius is the distance between point S2 and the major axis.
		xgce_MakeHypr2d(xgp_Pnt2d^ S1, xgp_Pnt2d^ S2, xgp_Pnt2d^ Center);

		//! Constructs a hyperbola with major and minor radii MajorRadius and
		//! MinorRadius, where:
		//! -   the center of the hyperbola is the origin of the axis MajorAxis, and
		//! -   the major axis is defined by MajorAxis if Sense
		//! is true, or the opposite axis to MajorAxis if Sense is false; or
		//! -   centered on the origin of the coordinate system
		//! A, with major and minor radii MajorRadius and
		//! MinorRadius, where its major axis is the "X Axis"
		//! of A (A is the local coordinate system of the hyperbola).
		xgce_MakeHypr2d(xgp_Ax2d^ MajorAxis, Standard_Real MajorRadius, Standard_Real MinorRadius, Standard_Boolean Sense);

		//! Creates a Hypr2d centered on the origin of the coordinate system
		//! A, with major and minor radii MajorRadius and
		//! MinorRadius, where its major axis is the "X Axis"
		//! of A (A is the local coordinate system of the hyperbola).
		xgce_MakeHypr2d(xgp_Ax22d^ A, Standard_Real MajorRadius, Standard_Real MinorRadius);

		//! Returns theructed hyperbola.
		//! Exceptions StdFail_NotDone if no hyperbola isructed.
		xgp_Hypr2d^ Value();

		xgp_Hypr2d^ Operator();
		operator xgp_Hypr2d^();
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
		property gce_MakeHypr2d* IHandle {
			gce_MakeHypr2d* get() {
				return 	NativeHandle;
			}
			void set(gce_MakeHypr2d* handle) {
				NativeHandle = handle;
			}
		}

	private:
		gce_MakeHypr2d* NativeHandle;
	};
}
#endif // _xgce_MakeHypr2d_HeaderFile
