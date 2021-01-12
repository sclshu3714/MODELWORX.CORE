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

#ifndef _XGC_MakeTrimmedCylinder_HeaderFile
#define _XGC_MakeTrimmedCylinder_HeaderFile
#pragma once
#include <NCollection_Haft.h>
#include <XGC_Root.h>
#include <GC_MakeTrimmedCylinder.hxx>
#include <xgp_Pnt.h>
#include <xgp_Circ.h>
#include <xgp_Ax1.h>
#include <xgp_Cylinder.h>
#include <XGeom_RectangularTrimmedSurface.h>

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <GC_Root.hxx>
#include <Geom_RectangularTrimmedSurface.hxx>

class StdFail_NotDone;
class gp_Pnt;
class gp_Circ;
class gp_Ax1;
class gp_Cylinder;

using namespace TKMath;
using namespace TKG3d;
namespace TKGeomBase {
	ref class TKMath::xgp_Pnt;
	ref class TKMath::xgp_Circ;
	ref class TKMath::xgp_Ax1;
	ref class TKMath::xgp_Cylinder;
	ref class TKG3d::XGeom_RectangularTrimmedSurface;
	//! Implements construction algorithms for a trimmed
	//! cylinder limited by two planes orthogonal to its axis.
	//! The result is a Geom_RectangularTrimmedSurface surface.
	//! A MakeTrimmedCylinder provides a framework for:
	//! -   defining the construction of the trimmed cylinder,
	//! -   implementing the construction algorithm, and
	//! -   consulting the results. In particular, the Value
	//! function returns the constructed trimmed cylinder.
	public ref class XGC_MakeTrimmedCylinder : public XGC_Root
	{
	public:

		//DEFINE_STANDARD_ALLOC
		XGC_MakeTrimmedCylinder();

		XGC_MakeTrimmedCylinder(GC_MakeTrimmedCylinder* pos);

		void SetMakeTrimmedCylinder(GC_MakeTrimmedCylinder* pos);

		virtual GC_MakeTrimmedCylinder* GetMakeTrimmedCylinder();

		virtual GC_Root* GetRoot() Standard_OVERRIDE;

		//! Make a cylindricalSurface <Cyl> from Geom
		//! Its axis is is <P1P2> and its radius is the distance
		//! between <P3> and <P1P2>.
		//! The height is the distance between P1 and P2.
		XGC_MakeTrimmedCylinder(xgp_Pnt^ P1, xgp_Pnt^ P2, xgp_Pnt^ P3);

		//! Make a cylindricalSurface <Cyl> from gp by its base <Circ>.
		//! Its axis is the normal to the plane defined bi <Circ>.
		//! <Height> can be greater than zero or lower than zero.
		//! In the first case the V parametric direction of the
		//! result has the same orientation as the normal to <Circ>.
		//! In the other case it has the opposite orientation.
		XGC_MakeTrimmedCylinder(xgp_Circ^ Circ, Standard_Real Height);

		//! Make a cylindricalSurface <Cyl> from gp by its
		//! axis <A1> and its radius <Radius>.
		//! It returns NullObject if <Radius> is lower than zero.
		//! <Height> can be greater than zero or lower than zero.
		//! In the first case the V parametric direction of the
		//! result has the same orientation as <A1>.
		//! In the other case it has the opposite orientation.
		XGC_MakeTrimmedCylinder(xgp_Ax1^ A1, Standard_Real Radius, Standard_Real Height);

		//! Returns the constructed trimmed cylinder.
		//! Exceptions
		//! StdFail_NotDone if no trimmed cylinder is constructed.
		XGeom_RectangularTrimmedSurface^ Value();

		operator XGeom_RectangularTrimmedSurface^() { return Value(); }

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
		property  GC_MakeTrimmedCylinder* IHandle {
			GC_MakeTrimmedCylinder* get() {
				return 	NativeHandle;
			}
			void set(GC_MakeTrimmedCylinder* handle) {
				NativeHandle = handle;
			}
		}

	private:
		GC_MakeTrimmedCylinder* NativeHandle;
	};
}
#endif // _XGC_MakeTrimmedCylinder_HeaderFile
