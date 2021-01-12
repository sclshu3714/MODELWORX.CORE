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

#ifndef _XGC_MakeSegment_HeaderFile
#define _XGC_MakeSegment_HeaderFile
#pragma once
#include <NCollection_Haft.h>
#include <XGC_Root.h>
#include <GC_MakeSegment.hxx>
#include <xgp_Pnt.h>
#include <xgp_Lin.h>
#include <XGeom_TrimmedCurve.h>

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <GC_Root.hxx>
#include <Geom_TrimmedCurve.hxx>

class StdFail_NotDone;
class gp_Pnt;
class gp_Lin;

using namespace TKMath;
using namespace TKG3d;
namespace TKGeomBase {
	ref class TKMath::xgp_Lin;
	ref class TKMath::xgp_Pnt;
	ref class TKG3d::XGeom_TrimmedCurve;
	//! Implements construction algorithms for a line
	//! segment in 3D space.
	//! Makes a segment of Line from the 2 points <P1> and <P2>.
	//! The result is a Geom_TrimmedCurve curve.
	//! A MakeSegment object provides a framework for:
	//! -   defining the construction of the line segment,
	//! -   implementing the construction algorithm, and
	//! -   consulting the results. In particular, the Value
	//! function returns the constructed line segment.
	public ref class XGC_MakeSegment : public XGC_Root
	{
	public:

		//! DEFINE_STANDARD_ALLOC
		XGC_MakeSegment();

		XGC_MakeSegment(GC_MakeSegment* pos);

		void SetMakeSegment(GC_MakeSegment* pos);

		virtual GC_MakeSegment* GetMakeSegment();

		virtual GC_Root* GetRoot() Standard_OVERRIDE;

		//! Make a segment of Line from the 2 points <P1> and <P2>.
		//! It returns NullObject if <P1> and <P2> are confused.
		XGC_MakeSegment(xgp_Pnt^ P1, xgp_Pnt^ P2);

		//! Make a segment of Line from the line <Line1>
		//! between the two parameters U1 and U2.
		//! It returns NullObject if <U1> is equal <U2>.
		XGC_MakeSegment(xgp_Lin^ Line, Standard_Real U1, Standard_Real U2);

		//! Make a segment of Line from the line <Line1>
		//! between the point <Point> and the parameter Ulast.
		//! It returns NullObject if <U1> is equal <U2>.
		XGC_MakeSegment(xgp_Lin^ Line, xgp_Pnt^ Point, Standard_Real Ulast);

		//! Make a segment of Line from the line <Line1>
		//! between the two points <P1> and <P2>.
		//! It returns NullObject if <U1> is equal <U2>.
		XGC_MakeSegment(xgp_Lin^ Line, xgp_Pnt^ P1, xgp_Pnt^ P2);

		//! Returns the constructed line segment.
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
		property  GC_MakeSegment* IHandle {
			GC_MakeSegment* get() {
				return 	NativeHandle;
			}
			void set(GC_MakeSegment* handle) {
				NativeHandle = handle;
			}
		}

	private:
		GC_MakeSegment* NativeHandle;
	};
}
#endif // _XGC_MakeSegment_HeaderFile
