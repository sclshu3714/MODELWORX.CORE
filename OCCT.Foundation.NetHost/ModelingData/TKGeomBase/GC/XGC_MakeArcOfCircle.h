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

#ifndef _XGC_MakeArcOfCircle_HeaderFile
#define _XGC_MakeArcOfCircle_HeaderFile
#pragma once
#include <XGC_Root.h>
#include <GC_MakeArcOfCircle.hxx>
#include <XGeom_TrimmedCurve.h>
#include <xgp_Circ.h>
#include <xgp_Vec.h >
#include <xgp_Pnt.h >

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <GC_Root.hxx>
#include <Geom_TrimmedCurve.hxx>

class gp_Circ;
class gp_Pnt;
class gp_Vec;
class GC_MakeArcOfCircle;

using namespace TKMath;
using namespace TKG3d;
namespace TKGeomBase {
	ref class TKMath::xgp_Vec;
	ref class TKMath::xgp_Ax2;
	ref class TKMath::xgp_Pnt;
	ref class TKG3d::XGeom_TrimmedCurve;
	//! Implements construction algorithms for an
	//! arc of circle in 3D space. The result is a Geom_TrimmedCurve curve.
	//! A MakeArcOfCircle object provides a framework for:
	//! -   defining the construction of the arc of circle,
	//! -   implementing the construction algorithm, and
	//! -   consulting the results. In particular, the
	//! Value function returns the constructed arc of circle.
	public ref class XGC_MakeArcOfCircle : public XGC_Root
	{
	public:

		!XGC_MakeArcOfCircle() { IHandle = NULL; };
		~XGC_MakeArcOfCircle() { IHandle = NULL; };
		//! DEFINE_STANDARD_ALLOC
		XGC_MakeArcOfCircle(GC_MakeArcOfCircle* pos);

		void SetMakeArcOfCircleHandle(GC_MakeArcOfCircle* pos);

		GC_MakeArcOfCircle* GetMakeArcOfCircle();

		//! Make an arc of circle (TrimmedCurve from Geom) from
		//! a circle between two angles Alpha1 and Alpha2
		//! given in radiians.
		XGC_MakeArcOfCircle(xgp_Circ^ Circ, Standard_Real Alpha1, Standard_Real Alpha2, Standard_Boolean Sense);

		//! Make an arc of circle (TrimmedCurve from Geom) from
		//! a circle between point <P> and the angle Alpha
		//! given in radians.
		XGC_MakeArcOfCircle(xgp_Circ^ Circ, xgp_Pnt^ P, Standard_Real Alpha, Standard_Boolean Sense);

		//! Make an arc of circle (TrimmedCurve from Geom) from
		//! a circle between two points P1 and P2.
		XGC_MakeArcOfCircle(xgp_Circ^ Circ, xgp_Pnt^ P1, xgp_Pnt^ P2, Standard_Boolean Sense);

		//! Make an arc of circle (TrimmedCurve from Geom) from
		//! three points P1,P2,P3 between two points P1 and P2.
		XGC_MakeArcOfCircle(xgp_Pnt^ P1, xgp_Pnt^ P2, xgp_Pnt^ P3);

		//! Make an arc of circle (TrimmedCurve from Geom) from
		//! two points P1,P2 and the tangente to the solution at
		//! the point P1.
		//! The orientation of the arc is:
		//! -   the sense determined by the order of the points P1, P3 and P2;
		//! -   the sense defined by the vector V; or
		//! -   for other syntaxes:
		//! -   the sense of Circ if Sense is true, or
		//! -   the opposite sense if Sense is false.
		//! Note: Alpha1, Alpha2 and Alpha are angle values, given in radians.
		//! Warning
		//! If an error occurs (that is, when IsDone returns
		//! false), the Status function returns:
		//! -   gce_ConfusedPoints if:
		//! -   any 2 of the 3 points P1, P2 and P3 are coincident, or
		//! -   P1 and P2 are coincident; or
		//! -   gce_IntersectionError if:
		//! -   P1, P2 and P3 are collinear and not coincident, or
		//! -   the vector defined by the points P1 and
		//! P2 is collinear with the vector V.
		XGC_MakeArcOfCircle(xgp_Pnt^ P1, xgp_Vec^ V, xgp_Pnt^ P2);

		//! Returns the constructed arc of circle.
		//! Exceptions StdFail_NotDone if no arc of circle is constructed.
		XGeom_TrimmedCurve^ Value();

		operator XGeom_TrimmedCurve^ () { return Value(); }


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
		virtual property  GC_MakeArcOfCircle* IHandle {
			GC_MakeArcOfCircle* get() {
				return 	NativeHandle;
			}
			void set(GC_MakeArcOfCircle* handle) {
				NativeHandle = handle;
			}
		}

	private:
		GC_MakeArcOfCircle* NativeHandle;
	};
}
#endif // _XGC_MakeArcOfCircle_HeaderFile
