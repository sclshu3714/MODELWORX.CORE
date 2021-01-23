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

#ifndef _xgce_MakeRotation2d_HeaderFile
#define _xgce_MakeRotation2d_HeaderFile
#pragma once
#include <gce_MakeRotation2d.hxx>
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
	ref class TKMath::xgp_Pnt;
	ref class TKMath::xgp_Trsf;
	//! Implements an elementaryruction algorithm for
	//! a rotation in 2D space. The result is a gp_Trsf2d transformation.
	//! A MakeRotation2d object provides a framework for:
	//! -   defining theruction of the transformation,
	//! -   implementing theruction algorithm, and
	//! -   consulting the result.
	public ref class xgce_MakeRotation2d
	{
	public:

		!xgce_MakeRotation2d() { IHandle = NULL; };
		~xgce_MakeRotation2d() { IHandle = NULL; };
		//DEFINE_STANDARD_ALLOC
		xgce_MakeRotation2d();

		xgce_MakeRotation2d(gce_MakeRotation2d* pos);

		void SetMakeRotation2d(gce_MakeRotation2d* pos);

		virtual gce_MakeRotation2d* GetMakeRotation2d();

		//! Constructs a rotation through angle Angle about the center Point.
		xgce_MakeRotation2d(xgp_Pnt2d^ Point, Standard_Real Angle);

		//! Returns theructed transformation.
		xgp_Trsf2d^ Value();

		xgp_Trsf2d^ Operator();
		operator xgp_Trsf2d^();

		/// <summary>
		/// ±¾µØ¾ä±ú
		/// </summary>
		property gce_MakeRotation2d* IHandle {
			gce_MakeRotation2d* get() {
				return 	NativeHandle;
			}
			void set(gce_MakeRotation2d* handle) {
				NativeHandle = handle;
			}
		}

	private:
		gce_MakeRotation2d* NativeHandle;
	};
}
#endif // _xgce_MakeRotation2d_HeaderFile
