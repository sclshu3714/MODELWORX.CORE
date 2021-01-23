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

#ifndef _XGC_MakeEllipse_HeaderFile
#define _XGC_MakeEllipse_HeaderFile
#pragma once
#include <XGC_Root.h>
#include <GC_MakeEllipse.hxx>
#include <xgp_Elips.h>
#include <xgp_Ax2.h >
#include <xgp_Pnt.h >
#include <XGeom_Ellipse.h>

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <GC_Root.hxx>
#include <Geom_Ellipse.hxx>

class StdFail_NotDone;
class gp_Elips;
class gp_Ax2;
class gp_Pnt;
class GC_MakeEllipse;

using namespace TKMath;
using namespace TKG3d;
namespace TKGeomBase {
	ref class TKMath::xgp_Elips;
	ref class TKMath::xgp_Ax2;
	ref class TKMath::xgp_Pnt;
	ref class TKG3d::XGeom_Ellipse;
	//! This class implements construction algorithms for an ellipse in
	//! 3D space. The result is a Geom_Ellipse ellipse.
	//! A MakeEllipse object provides a framework for:
	//! -   defining the construction of the ellipse,
	//! -   implementing the construction algorithm, and
	//! -   consulting the results. In particular, the Value
	//! function returns the constructed ellipse.
	public ref class XGC_MakeEllipse : public XGC_Root
	{
	public:

		!XGC_MakeEllipse() { IHandle = NULL; };
		~XGC_MakeEllipse() { IHandle = NULL; };
		//! DEFINE_STANDARD_ALLOC
		XGC_MakeEllipse(GC_MakeEllipse* pos);

		void SetMakeEllipseHandle(GC_MakeEllipse* pos);

		GC_MakeEllipse* GetMakeEllipse();

		//! Creates an ellipse from a non persistent ellipse E from package gp by its conversion.
		XGC_MakeEllipse(xgp_Elips^ E);

		//! Constructs an ellipse with major and minor radii MajorRadius and
		//! MinorRadius, and located in the plane defined by
		//! the "X Axis" and "Y Axis" of the coordinate system A2, where:
		//! -   its center is the origin of A2, and
		//! -   its major axis is the "X Axis" of A2;
		//! Warnings :
		//! The MakeEllipse class does not prevent the
		//! construction of an ellipse where MajorRadius is equal to MinorRadius.
		//! If an error occurs (that is, when IsDone returns
		//! false), the Status function returns:
		//! -   gce_InvertRadius if MajorRadius is less than MinorRadius;
		//! -   gce_NegativeRadius if MinorRadius is less than 0.0;
		//! -   gce_NullAxis if the points S1 and Center are coincident; or
		//! -   gce_InvertAxis if:
		//! -   the major radius computed with Center and S1
		//! is less than the minor radius computed with Center, S1 and S2, or
		//! -   Center, S1 and S2 are collinear.
		XGC_MakeEllipse(xgp_Ax2^ A2, Standard_Real MajorRadius, Standard_Real MinorRadius);

		//! Constructs an ellipse centered on the point Center, where
		//! -   the plane of the ellipse is defined by Center, S1 and S2,
		//! -   its major axis is defined by Center and S1,
		//! -   its major radius is the distance between Center and S1, and
		//! -   its minor radius is the distance between S2 and the major axis.
		XGC_MakeEllipse(xgp_Pnt^ S1, xgp_Pnt^ S2, xgp_Pnt^ Center);

		//! Returns the constructed ellipse.
		//! Exceptions StdFail_NotDone if no ellipse is constructed.
		XGeom_Ellipse^ Value();
		operator XGeom_Ellipse^() { return Value(); }

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
		virtual property  GC_MakeEllipse* IHandle {
			GC_MakeEllipse* get() {
				return 	NativeHandle;
			}
			void set(GC_MakeEllipse* handle) {
				NativeHandle = handle;
			}
		}

	private:
		GC_MakeEllipse* NativeHandle;
	};
}
#endif // _XGC_MakeEllipse_HeaderFile
