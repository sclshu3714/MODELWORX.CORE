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

#ifndef _XGC_MakeArcOfEllipse_HeaderFile
#define _XGC_MakeArcOfEllipse_HeaderFile
#pragma once
#include <GC_MakeArcOfEllipse.hxx>
#include <XGC_Root.h>
#include <XGeom_TrimmedCurve.h>
#include <xgp_Elips.h>
#include <xgp_Pnt.h >

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <GC_Root.hxx>
#include <Geom_TrimmedCurve.hxx>

class StdFail_NotDone;
class gp_Elips;
class gp_Pnt;

using namespace TKMath;
using namespace TKG3d;
namespace TKGeomBase {
	ref class TKMath::xgp_Elips;
	ref class TKMath::xgp_Pnt;
	ref class TKG3d::XGeom_TrimmedCurve;
	//! Implements construction algorithms for an arc
	//! of ellipse in 3D space. The result is a Geom_TrimmedCurve curve.
	//! A MakeArcOfEllipse object provides a framework for:
	//! -   defining the construction of the arc of ellipse,
	//! -   implementing the construction algorithm, and
	//! -   consulting the results. In particular, the
	//! Value function returns the constructed arc of ellipse.
	public ref class XGC_MakeArcOfEllipse : public XGC_Root
	{
	public:

		!XGC_MakeArcOfEllipse() { IHandle = NULL; };
		~XGC_MakeArcOfEllipse() { IHandle = NULL; };
		//! DEFINE_STANDARD_ALLOC
		XGC_MakeArcOfEllipse(GC_MakeArcOfEllipse* pos);

		void SetMakeArcOfEllipseHandle(GC_MakeArcOfEllipse* pos);

		GC_MakeArcOfEllipse* GetMakeArcOfEllipse();

		//! Constructs an arc of Ellipse (TrimmedCurve from Geom) from
		//! a Ellipse between two parameters Alpha1 and Alpha2.
		XGC_MakeArcOfEllipse(xgp_Elips^ Elips, Standard_Real Alpha1, Standard_Real Alpha2, Standard_Boolean Sense);

		//! Constructs an arc of Ellipse (TrimmedCurve from Geom) from
		//! a Ellipse between point <P> and the angle Alpha
		//! given in radians.
		XGC_MakeArcOfEllipse(xgp_Elips^ Elips, xgp_Pnt^ P, Standard_Real Alpha, Standard_Boolean Sense);

		//! Constructs an arc of Ellipse (TrimmedCurve from Geom) from
		//! a Ellipse between two points P1 and P2.
		//! The orientation of the arc of ellipse is:
		//! -   the sense of Elips if Sense is true, or
		//! -   the opposite sense if Sense is false.
		//! Notes:
		//! -   Alpha1, Alpha2 and Alpha are angle values, given in radians.
		//! -   IsDone always returns true.
		XGC_MakeArcOfEllipse(xgp_Elips^ Elips, xgp_Pnt^ P1, xgp_Pnt^ P2, Standard_Boolean Sense);

		//! Returns the constructed arc of ellipse.
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
		virtual property  GC_MakeArcOfEllipse* IHandle {
			GC_MakeArcOfEllipse* get() {
				return 	NativeHandle;
			}
			void set(GC_MakeArcOfEllipse* handle) {
				NativeHandle = handle;
			}
		}

	private:
		GC_MakeArcOfEllipse* NativeHandle;
	};
}
#endif // _XGC_MakeArcOfEllipse_HeaderFile
