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

#ifndef _xgce_MakeElips_HeaderFile
#define _xgce_MakeElips_HeaderFile
#pragma once
#include <gce_MakeElips.hxx>
#include <xgce_Root.h>
#include <xgp_Ax2.h>
#include <xgp_Pnt.h>
#include <xgp_Elips.h>

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <gp_Elips.hxx>
#include <gce_Root.hxx>
#include <Standard_Real.hxx>
class StdFail_NotDone;
class gp_Ax2;
class gp_Pnt;
class gp_Elips;

using namespace TKMath;
namespace TKGeomBase {
	ref class TKMath::xgp_Ax2;
	ref class TKMath::xgp_Pnt;
	ref class TKMath::xgp_Elips;
	//! This class implements the following algorithms used to
	//! create an ellipse from gp.
	//!
	//! * Create an ellipse from its center, and two points:
	//! one on the ciconference giving the major radius, the
	//! other giving the value of the small radius.
	public ref class xgce_MakeElips : public xgce_Root
	{
	public:

		//DEFINE_STANDARD_ALLOC
		xgce_MakeElips();
		!xgce_MakeElips() { IHandle = NULL; };
		~xgce_MakeElips() { IHandle = NULL; };
		xgce_MakeElips(gce_MakeElips* pos);

		void SetMakeElips(gce_MakeElips* pos);

		virtual gce_MakeElips* GetMakeElips();

		virtual gce_Root* GetRoot() Standard_OVERRIDE;


		//! The major radius of the ellipse is on the "XAxis" and the
		//! minor radius is on the "YAxis" of the ellipse. The "XAxis"
		//! is defined with the "XDirection" of A2 and the "YAxis" is
		//! defined with the "YDirection" of A2.
		//! Warnings :
		//! It is not forbidden to create an ellipse with
		//! MajorRadius = MinorRadius.
		xgce_MakeElips(xgp_Ax2^ A2, Standard_Real MajorRadius, Standard_Real MinorRadius);

		//! Make an ellipse with its center and two points.
		//! Warning
		//! The MakeElips class does not prevent the
		//!ruction of an ellipse where the MajorRadius is
		//! equal to the MinorRadius.
		//! If an error occurs (that is, when IsDone returns
		//! false), the Status function returns:
		//! -   gce_InvertRadius if MajorRadius is less than MinorRadius;
		//! -   gce_NegativeRadius if MinorRadius is less than 0.0;
		//! -   gce_NullAxis if the points S1 and Center are coincident; or
		//! -   gce_InvertAxis if:
		//! -   the major radius computed with Center and S1
		//! is less than the minor radius computed with Center, S1 and S2, or
		//! -   Center, S1 and S2 are collinear.
		xgce_MakeElips(xgp_Pnt^ S1, xgp_Pnt^ S2, xgp_Pnt^ Center);

		//! Returns theructed ellipse.
		//! Exceptions StdFail_NotDone if no ellipse isructed.
		xgp_Elips^ Value();

		xgp_Elips^ Operator();
		operator xgp_Elips^();

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
		property gce_MakeElips* IHandle {
			gce_MakeElips* get() {
				return 	NativeHandle;
			}
			void set(gce_MakeElips* handle) {
				NativeHandle = handle;
			}
		}

	private:
		gce_MakeElips* NativeHandle;
	};
}
#endif // _xgce_MakeElips_HeaderFile
