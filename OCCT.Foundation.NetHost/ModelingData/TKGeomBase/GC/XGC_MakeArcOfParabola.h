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

#ifndef _XGC_MakeArcOfParabola_HeaderFile
#define _XGC_MakeArcOfParabola_HeaderFile
#pragma once
#include <XGC_Root.h>
#include <GC_MakeArcOfParabola.hxx>
#include <XGeom_TrimmedCurve.h>
#include <xgp_Parab.h>
#include <xgp_Pnt.h >

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <GC_Root.hxx>
#include <Geom_TrimmedCurve.hxx>

class StdFail_NotDone;
class gp_Parab;
class gp_Pnt;

using namespace TKMath;
using namespace TKG3d;
namespace TKGeomBase {
	ref class TKMath::xgp_Parab;
	ref class TKMath::xgp_Pnt;
	ref class TKG3d::XGeom_TrimmedCurve;
	//! Implements construction algorithms for an arc
	//! of parabola in 3D space. The result is a Geom_TrimmedCurve curve.
	//! A MakeArcOfParabola object provides a framework for:
	//! -   defining the construction of the arc of parabola,
	//! -   implementing the construction algorithm, and
	//! -   consulting the results. In particular, the
	//! Value function returns the constructed arc of parabola.
	public ref class XGC_MakeArcOfParabola : public XGC_Root
	{
	public:

		!XGC_MakeArcOfParabola() { IHandle = NULL; };
		~XGC_MakeArcOfParabola() { IHandle = NULL; };
		//! DEFINE_STANDARD_ALLOC
		XGC_MakeArcOfParabola(GC_MakeArcOfParabola* pos);

		void SetMakeArcOfParabolaHandle(GC_MakeArcOfParabola* pos);

		GC_MakeArcOfParabola* GetMakeArcOfParabola();

		//! Creates an arc of Parabola (TrimmedCurve from Geom) from
		//! a Parabola between two parameters Alpha1 and Alpha2
		//! (given in radians).
		XGC_MakeArcOfParabola(xgp_Parab^ Parab, Standard_Real Alpha1, Standard_Real Alpha2, Standard_Boolean Sense);

		//! Creates an arc of Parabola (TrimmedCurve from Geom) from
		//! a Parabola between point <P> and the parameter
		//! Alpha (given in radians).
		XGC_MakeArcOfParabola(xgp_Parab^ Parab, xgp_Pnt^ P, Standard_Real Alpha, Standard_Boolean Sense);

		//! Creates an arc of Parabola (TrimmedCurve from Geom) from
		//! a Parabola between two points P1 and P2.
		XGC_MakeArcOfParabola(xgp_Parab^ Parab, xgp_Pnt^ P1, xgp_Pnt^ P2, Standard_Boolean Sense);

		//! Returns the constructed arc of parabola.
		XGeom_TrimmedCurve^ Value();
		operator XGeom_TrimmedCurve^() { return Value(); }

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
		virtual property  GC_MakeArcOfParabola* IHandle {
			GC_MakeArcOfParabola* get() {
				return 	NativeHandle;
			}
			void set(GC_MakeArcOfParabola* handle) {
				NativeHandle = handle;
			}
		}

	private:
		GC_MakeArcOfParabola* NativeHandle;
	};
}
#endif // _GC_MakeArcOfParabola_HeaderFile
