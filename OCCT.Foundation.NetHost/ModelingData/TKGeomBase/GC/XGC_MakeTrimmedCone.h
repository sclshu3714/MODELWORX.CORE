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

#ifndef _XGC_MakeTrimmedCone_HeaderFile
#define _XGC_MakeTrimmedCone_HeaderFile
#pragma once
#include <XGC_Root.h>
#include <XGeom_RectangularTrimmedSurface.h>
#include <GC_MakeTrimmedCone.hxx>
#include <XGeom_TrimmedCurve.h>
#include <xgp_Pnt.h >

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <GC_Root.hxx>
#include <Geom_RectangularTrimmedSurface.hxx>

class StdFail_NotDone;
class gp_Pnt;

using namespace TKMath;
using namespace TKG3d;
namespace TKGeomBase {
	ref class TKMath::xgp_Pnt;
	//! Implements construction algorithms for a trimmed
	//! cone limited by two planes orthogonal to its axis. The
	//! result is a Geom_RectangularTrimmedSurface surface.
	//! A MakeTrimmedCone provides a framework for:
	//! -   defining the construction of the trimmed cone,
	//! -   implementing the construction algorithm, and
	//! -   consulting the results. In particular, the Value
	//! function returns the constructed trimmed cone.
	public ref class XGC_MakeTrimmedCone : public XGC_Root
	{
	public:

		//! DEFINE_STANDARD_ALLOC
		XGC_MakeTrimmedCone(GC_MakeTrimmedCone* pos);

		void SetMakeTrimmedConeHandle(GC_MakeTrimmedCone* pos);

		GC_MakeTrimmedCone* GetMakeTrimmedCone();

		//! Make a RectangularTrimmedSurface <TheCone> from Geom
		//! It is trimmed by P3 and P4.
		//! Its axis is <P1P2> and the radius of its base is
		//! the distance between <P3> and <P1P2>.
		//! The distance between <P4> and <P1P2> is the radius of
		//! the section passing through <P4>.
		//! An error iss raised if <P1>,<P2>,<P3>,<P4> are
		//! colinear or if <P3P4> is perpendicular to <P1P2> or
		//! <P3P4> is colinear to <P1P2>.
		XGC_MakeTrimmedCone(xgp_Pnt^ P1, xgp_Pnt^ P2, xgp_Pnt^ P3, xgp_Pnt^ P4);

		//! Make a RectangularTrimmedSurface from Geom <TheCone>
		//! from a cone and trimmed by two points P1 and P2 and
		//! the two radius <R1> and <R2> of the sections passing
		//! through <P1> an <P2>.
		//! Warning
		//! If an error occurs (that is, when IsDone returns
		//! false), the Status function returns:
		//! -   gce_ConfusedPoints if points P1 and P2, or P3 and P4, are coincident;
		//! -   gce_NullAngle if:
		//! -   the lines joining P1 to P2 and P3 to P4 are parallel, or
		//! -   R1 and R2 are equal (i.e. their difference is less than gp::Resolution());
		//! -   gce_NullRadius if:
		//! -   the line joining P1 to P2 is perpendicular to the line joining P3 to P4, or
		//! -   the points P1, P2, P3 and P4 are collinear;
		//! -   gce_NegativeRadius if R1 or R2 is negative; or
		//! -   gce_NullAxis if points P1 and P2 are coincident (2nd syntax only).
		XGC_MakeTrimmedCone(xgp_Pnt^ P1, xgp_Pnt^ P2, Standard_Real R1, Standard_Real R2);

		//! Returns the constructed trimmed cone.
		//! StdFail_NotDone if no trimmed cone is constructed.
		XGeom_RectangularTrimmedSurface^ Value();

		operator XGeom_RectangularTrimmedSurface^() { return Value(); }

		/// <summary>
		/// ±¾µØ¾ä±ú
		/// </summary>
		virtual property  GC_MakeTrimmedCone* IHandle {
			GC_MakeTrimmedCone* get() {
				return 	NativeHandle;
			}
			void set(GC_MakeTrimmedCone* handle) {
				NativeHandle = handle;
			}
		}

	private:
		GC_MakeTrimmedCone* NativeHandle;
	};
}
#endif // _XGC_MakeTrimmedCone_HeaderFile
