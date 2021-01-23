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

#ifndef _XGC_MakeHyperbola_HeaderFile
#define _XGC_MakeHyperbola_HeaderFile
#pragma once
#include <NCollection_Haft.h>
#include <XGC_Root.h>
#include <GC_MakeHyperbola.hxx>
#include <xgp_Hypr.h>
#include <xgp_Ax2.h>
#include <xgp_Pnt.h>
#include <XGeom_Hyperbola.h>

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <GC_Root.hxx>
#include <Geom_Hyperbola.hxx>

class StdFail_NotDone;
class gp_Hypr;
class gp_Ax2;
class gp_Pnt;

using namespace TKMath;
using namespace TKG3d;
namespace TKGeomBase {
	ref class TKMath::xgp_Hypr;
	ref class TKMath::xgp_Ax2;
	ref class TKMath::xgp_Pnt;
	ref class TKG3d::XGeom_Hyperbola;
	//! This class implements construction algorithms for a hyperbola in
	//! 3D space. The result is a Geom_Hyperbola hyperbola.
	//! A MakeHyperbola object provides a framework for:
	//! -   defining the construction of the hyperbola,
	//! -   implementing the construction algorithm, and
	//! -   consulting the results. In particular, the Value
	//! function returns the constructed hyperbola.
	//! To define the main branch of an hyperbola.
	//! The parameterization range is ]-infinite,+infinite[
	//! It is possible to get the other branch and the two conjugate
	//! branches of the main branch.
	//!
	//! ^YAxis
	//! |
	//! FirstConjugateBranch
	//! |
	//! Other            |                Main
	//! --------------------- C ------------------------------>XAxis
	//! Branch           |                Branch
	//! |
	//! SecondConjugateBranch
	//! |
	//!
	//! The major radius is the distance between the Location point
	//! of the hyperbola C and the apex of the Main Branch (or the
	//! Other branch). The major axis is the XAxis.
	//! The minor radius is the distance between the Location point
	//! of the hyperbola C and the apex of the First (or Second)
	//! Conjugate branch. The minor axis is the YAxis.
	//! The major radius can be lower than the minor radius.
	public ref class XGC_MakeHyperbola : public XGC_Root
	{
	public:

		//! DEFINE_STANDARD_ALLOC
		!XGC_MakeHyperbola() { IHandle = NULL; };
		~XGC_MakeHyperbola() { IHandle = NULL; };
		XGC_MakeHyperbola();

		XGC_MakeHyperbola(GC_MakeHyperbola* pos);

		void SetMakeHyperbola(GC_MakeHyperbola* pos);

		virtual GC_MakeHyperbola* GetMakeHyperbola();

		virtual GC_Root* GetRoot() Standard_OVERRIDE;

		//! Creates  an Hyperbola from a non persistent hyperbola  from package gp by conversion.
		XGC_MakeHyperbola(xgp_Hypr^ H);

		//! Constructs a hyperbola centered on the origin of the coordinate system
		//! A2, with major and minor radii MajorRadius and MinorRadius, where:
		//! the plane of the hyperbola is defined by the "X Axis" and "Y Axis" of A2,
		//! -   its major axis is the "X Axis" of A2.
		XGC_MakeHyperbola(xgp_Ax2^ A2, Standard_Real MajorRadius, Standard_Real MinorRadius);

		//! Constructs a hyperbola centered on the point Center, where
		//! -   the plane of the hyperbola is defined by Center, S1 and S2,
		//! -   its major axis is defined by Center and S1,
		//! -   its major radius is the distance between Center and S1, and
		//! -   its minor radius is the distance between S2 and the major axis;
		XGC_MakeHyperbola(xgp_Pnt^ S1, xgp_Pnt^ S2, xgp_Pnt^ Center);

		//! Returns the constructed hyperbola.
		//! Exceptions StdFail_NotDone if no hyperbola is constructed.
		XGeom_Hyperbola^ Value();

		operator XGeom_Hyperbola^() { return Value(); }

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
		property  GC_MakeHyperbola* IHandle {
			GC_MakeHyperbola* get() {
				return 	NativeHandle;
			}
			void set(GC_MakeHyperbola* handle) {
				NativeHandle =  handle;
			}
		}

	private:
		GC_MakeHyperbola* NativeHandle;
	};
}
#endif // _XGC_MakeHyperbola_HeaderFile
