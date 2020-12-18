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

#ifndef _xgce_MakeElips2d_HeaderFile
#define _xgce_MakeElips2d_HeaderFile
#pragma once
#include <gce_MakeElips2d.hxx>
#include <xgce_Root.h>
#include <xgp_Ax2d.h>
#include <xgp_Ax22d.h>
#include <xgp_Pnt2d.h>
#include <xgp_Elips2d.h>

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <gp_Elips2d.hxx>
#include <gce_Root.hxx>
#include <Standard_Real.hxx>
#include <Standard_Boolean.hxx>
class StdFail_NotDone;
class gp_Ax2d;
class gp_Ax22d;
class gp_Pnt2d;
class gp_Elips2d;

using namespace TKMath;
namespace TKGeomBase {
	ref class TKMath::xgp_Ax2d;
	ref class TKMath::xgp_Ax22d;
	ref class TKMath::xgp_Pnt2d;
	ref class TKMath::xgp_Elips2d;
	//! This class implements the following algorithms used to
	//! create Elips2d from gp.
	//!
	//! * Create an ellipse from its center, and two points:
	//! one on the ciconference giving the major radius, the
	//! other giving the value of the small radius.
	//! * Create an ellipse from its major axis and its major
	//! radius and its minor radius.
	public ref class xgce_MakeElips2d : public xgce_Root
	{
	public:

		//DEFINE_STANDARD_ALLOC
		xgce_MakeElips2d();

		xgce_MakeElips2d(gce_MakeElips2d* pos);

		void SetMakeElips2d(gce_MakeElips2d* pos);

		virtual gce_MakeElips2d* GetMakeElips2d();

		virtual gce_Root* GetRoot() Standard_OVERRIDE;


		//! Creates an ellipse with the major axis, the major and the
		//! minor radius. The location of the MajorAxis is the center
		//! of the  ellipse.
		//! The sense of parametrization is given by Sense.
		//! It is possible to create an ellipse with MajorRadius = MinorRadius.
		//! the status is "InvertRadius" if MajorRadius < MinorRadius or
		//! "NegativeRadius" if MinorRadius < 0.0
		//! Standard_Boolean Sense = Standard_True
		xgce_MakeElips2d(xgp_Ax2d^ MajorAxis, Standard_Real MajorRadius, Standard_Real MinorRadius, Standard_Boolean Sense);


		//! Axis defines the Xaxis and Yaxis of the ellipse which defines
		//! the origin and the sense of parametrization.
		//! Creates an ellipse with the AxisPlacement the major and the
		//! minor radius. The location of Axis is the center
		//! of the  ellipse.
		//! It is possible to create an ellipse with MajorRadius = MinorRadius.
		//! the status is "InvertRadius" if MajorRadius < MinorRadius or
		//! "NegativeRadius" if MinorRadius < 0.0
		xgce_MakeElips2d(xgp_Ax22d^ A, Standard_Real MajorRadius, Standard_Real MinorRadius);

		//! Makes an Elips2d with its center and two points.
		//! The sense of parametrization is given by S1, S2,
		//! and Center.
		//! Depending on theructor, the  implicit orientation of the ellipse is:
		//! -   the sense defined by A,
		//! -   the sense defined by points Center, S1 and S2,
		//! -   the trigonometric sense if Sense is not given or is true, or
		//! -   the opposite if Sense is false.
		//! It is possible toruct an ellipse where the major
		//! and minor radii are equal.
		//! Warning
		//! If an error occurs (that is, when IsDone returns
		//! false), the Status function returns:
		//! -   gce_InvertRadius if MajorRadius is less than MinorRadius,
		//! -   gce_NegativeRadius if MajorRadius or
		//! MinorRadius is less than 0.0,
		//! -   gce_NullAxis if points S1, S2 and Center are collinear, or
		//! -   gce_InvertAxis if the major radius computed with
		//! Center and S1 is less than the minor radius
		//! computed with Center, S1 and S2.
		xgce_MakeElips2d(xgp_Pnt2d^ S1, xgp_Pnt2d^ S2, xgp_Pnt2d^ Center);

		//! Returns theructed ellipse.
		//! Exceptions StdFail_NotDone if no ellipse isructed.
		xgp_Elips2d^ Value();

		xgp_Elips2d^ Operator();
		operator xgp_Elips2d^();

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
		property gce_MakeElips2d* IHandle {
			gce_MakeElips2d* get() {
				return 	NativeHandle;
			}
			void set(gce_MakeElips2d* handle) {
				NativeHandle = handle;
			}
		}

	private:
		gce_MakeElips2d* NativeHandle;
	};
}
#endif // _xgce_MakeElips2d_HeaderFile
