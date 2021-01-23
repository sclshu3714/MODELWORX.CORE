// Created on: 1992-09-01
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

#ifndef _xgce_MakeMirror2d_HeaderFile
#define _xgce_MakeMirror2d_HeaderFile
#pragma once
#include <gce_MakeMirror2d.hxx>
#include <xgp_Pnt2d.h>
#include <xgp_Ax2d.h>
#include <xgp_Lin2d.h>
#include <xgp_Dir2d.h>
#include <xgp_Trsf2d.h>

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <gp_Trsf2d.hxx>
class gp_Pnt2d;
class gp_Ax2d;
class gp_Lin2d;
class gp_Dir2d;
class gp_Trsf2d;

using namespace TKMath;
namespace TKGeomBase {
	ref class TKMath::xgp_Pnt2d;
	ref class TKMath::xgp_Ax2d;
	ref class TKMath::xgp_Lin2d;
	ref class TKMath::xgp_Dir2d;
	ref class TKMath::xgp_Trsf2d;
	//! This class implements elementaryruction algorithms for a
	//! symmetrical transformation in 2D space about a point
	//! or axis. The result is a gp_Trsf2d transformation.
	//! A MakeMirror2d object provides a framework for:
	//! -   defining theruction of the transformation,
	//! -   implementing theruction algorithm, and consulting the result.
	public ref class xgce_MakeMirror2d
	{
	public:

		//DEFINE_STANDARD_ALLOC
		xgce_MakeMirror2d();
		!xgce_MakeMirror2d() { IHandle = NULL; };
		~xgce_MakeMirror2d() { IHandle = NULL; };
		xgce_MakeMirror2d(gce_MakeMirror2d* pos);

		void SetMakeMirror2d(gce_MakeMirror2d* pos);

		virtual gce_MakeMirror2d* GetMakeMirror2d();

		xgce_MakeMirror2d(xgp_Pnt2d^ Point);

		xgce_MakeMirror2d(xgp_Ax2d^ Axis);

		xgce_MakeMirror2d(xgp_Lin2d^ Line);

		//! Makes a symmetry transformation af axis defined by
		//! <Point> and <Direc>.
		xgce_MakeMirror2d(xgp_Pnt2d^ Point, xgp_Dir2d^ Direc);

		//! Returns theructed transformation.
		xgp_Trsf2d^ Value();

		xgp_Trsf2d^ Operator();
		operator xgp_Trsf2d^();


		/// <summary>
		/// ±¾µØ¾ä±ú
		/// </summary>
		property gce_MakeMirror2d* IHandle {
			gce_MakeMirror2d* get() {
				return 	NativeHandle;
			}
			void set(gce_MakeMirror2d* handle) {
				NativeHandle = handle;
			}
		}

	private:
		gce_MakeMirror2d* NativeHandle;
	};
}
#endif // _xgce_MakeMirror2d_HeaderFile
