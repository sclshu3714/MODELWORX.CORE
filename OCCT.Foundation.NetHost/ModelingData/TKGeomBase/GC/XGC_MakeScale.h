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

#ifndef _XGC_MakeScale_HeaderFile
#define _XGC_MakeScale_HeaderFile
#pragma once
#include <NCollection_Haft.h>
#include <GC_MakeScale.hxx>
#include <xgp_Pnt.h>
#include <XGeom_Transformation.h>

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <Standard_Real.hxx>
class Geom_Transformation;
class gp_Pnt;

using namespace TKMath;
using namespace TKG3d;
namespace TKGeomBase {
	ref class TKMath::xgp_Pnt;
	ref class TKG3d::XGeom_Transformation;
	//! This class implements an elementary construction algorithm for
	//! a scaling transformation in 3D space. The result is a
	//! Geom_Transformation transformation (a scaling transformation with
	//! the center point <Point> and the scaling value <Scale>).
	//! A MakeScale object provides a framework for:
	//! -   defining the construction of the transformation,
	//! -   implementing the construction algorithm, and
	//! -   consulting the result.
	public ref class XGC_MakeScale
	{
	public:

		//! DEFINE_STANDARD_ALLOC
		XGC_MakeScale();

		XGC_MakeScale(GC_MakeScale* pos);

		void SetMakeScale(GC_MakeScale* pos);

		virtual GC_MakeScale* GetMakeScale();

		//! Constructs a scaling transformation with
		//! -   Point as the center of the transformation, and
		//! -   Scale as the scale factor.
		XGC_MakeScale(xgp_Pnt^ Point, Standard_Real Scale);

		//! Returns the constructed transformation.
		XGeom_Transformation^ Value();
		operator XGeom_Transformation^() { return Value(); }
		/// <summary>
		/// ±¾µØ¾ä±ú
		/// </summary>
		property  GC_MakeScale* IHandle {
			GC_MakeScale* get() {
				return 	NativeHandle;
			}
			void set(GC_MakeScale* handle) {
				NativeHandle = handle;
			}
		}

	private:
		GC_MakeScale* NativeHandle;
	};
}
#endif // _XGC_MakeScale_HeaderFile
