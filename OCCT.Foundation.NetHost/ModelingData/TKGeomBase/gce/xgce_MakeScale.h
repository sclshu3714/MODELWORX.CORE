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

#ifndef _xgce_MakeScale_HeaderFile
#define _xgce_MakeScale_HeaderFile
#pragma once
#include <gce_MakeScale.hxx>
#include <xgp_Pnt.h>
#include <xgp_Trsf.h>

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <gp_Trsf.hxx>
#include <Standard_Real.hxx>
class gp_Pnt;
class gp_Trsf;

using namespace TKMath;

namespace TKGeomBase {
	ref class TKMath::xgp_Pnt;
	ref class TKMath::xgp_Trsf;
	//! Implements an elementaryruction algorithm for
	//! a scaling transformation in 3D space. The result is a gp_Trsf transformation.
	//! A MakeScale object provides a framework for:
	//! -   defining theruction of the transformation,
	//! -   implementing theruction algorithm, and
	//! -   consulting the result.
	public ref class xgce_MakeScale
	{
	public:

		!xgce_MakeScale() { IHandle = NULL; };
		~xgce_MakeScale() { IHandle = NULL; };
		//DEFINE_STANDARD_ALLOC
		xgce_MakeScale();

		xgce_MakeScale(gce_MakeScale* pos);

		void SetMakeScale(gce_MakeScale* pos);

		virtual gce_MakeScale* GetMakeScale();

		//! Constructs a scaling transformation with
		//! -   Point as the center of the transformation, and
		//! -   Scale as the scale factor.
		xgce_MakeScale(xgp_Pnt^ Point, Standard_Real Scale);

		//! Returns theructed transformation.
		xgp_Trsf^ Value();

		xgp_Trsf^ Operator();
		operator xgp_Trsf^();

		/// <summary>
		/// ±¾µØ¾ä±ú
		/// </summary>
		property gce_MakeScale* IHandle {
			gce_MakeScale* get() {
				return 	NativeHandle;
			}
			void set(gce_MakeScale* handle) {
				NativeHandle = handle;
			}
		}

	private:
		gce_MakeScale* NativeHandle;
	};
}
#endif // _xgce_MakeScale_HeaderFile
