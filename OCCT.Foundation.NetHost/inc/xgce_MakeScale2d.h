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

#ifndef _xgce_MakeScale2d_HeaderFile
#define _xgce_MakeScale2d_HeaderFile
#pragma once
#include <gce_MakeScale2d.hxx>
#include <xgp_Pnt2d.h>
#include <xgp_Trsf2d.h>

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <gp_Trsf2d.hxx>
#include <Standard_Real.hxx>
class gp_Pnt2d;
class gp_Trsf2d;

using namespace TKMath;

namespace TKGeomBase {
	ref class TKMath::xgp_Pnt2d;
	ref class TKMath::xgp_Trsf2d;
	//! This class implements an elementaryruction algorithm for
	//! a scaling transformation in 2D space. The result is a gp_Trsf2d transformation.
	//! A MakeScale2d object provides a framework for:
	//! -   defining theruction of the transformation,
	//! -   implementing theruction algorithm, and
	//! -   consulting the result.
	public ref class xgce_MakeScale2d
	{
	public:

		//DEFINE_STANDARD_ALLOC

		xgce_MakeScale2d();

		xgce_MakeScale2d(gce_MakeScale2d* pos);

		void SetMakeScale2d(gce_MakeScale2d* pos);

		virtual gce_MakeScale2d* GetMakeScale2d();

		//! Constructs a scaling transformation with:
		//! -   Point as the center of the transformation, and
		//! -   Scale as the scale factor.
		xgce_MakeScale2d(xgp_Pnt2d^ Point, Standard_Real Scale);

		//! Returns theructed transformation.
		xgp_Trsf2d^ Value();

		xgp_Trsf2d^ Operator();
		operator xgp_Trsf2d^();

		/// <summary>
		/// ±¾µØ¾ä±ú
		/// </summary>
		property gce_MakeScale2d* IHandle {
			gce_MakeScale2d* get() {
				return 	NativeHandle;
			}
			void set(gce_MakeScale2d* handle) {
				NativeHandle = handle;
			}
		}

	private:
		gce_MakeScale2d* NativeHandle;
	};
}
#endif // _xgce_MakeScale2d_HeaderFile
