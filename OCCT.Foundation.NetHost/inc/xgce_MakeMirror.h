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

#ifndef _xgce_MakeMirror_HeaderFile
#define _xgce_MakeMirror_HeaderFile
#pragma once
#include <gce_MakeMirror.hxx>
#include <xgp_Pnt.h>
#include <xgp_Ax1.h>
#include <xgp_Lin.h>
#include <xgp_Dir.h>
#include <xgp_Pln.h>
#include <xgp_Ax2.h>
#include <xgp_Trsf.h>

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <gp_Trsf.hxx>
class gp_Pnt;
class gp_Ax1;
class gp_Lin;
class gp_Dir;
class gp_Pln;
class gp_Ax2;
class gp_Trsf;

using namespace TKMath;
namespace TKGeomBase {
	ref class TKMath::xgp_Pnt;
	ref class TKMath::xgp_Ax1;
	ref class TKMath::xgp_Lin;
	ref class TKMath::xgp_Dir;
	ref class TKMath::xgp_Pln;
	ref class TKMath::xgp_Ax2;
	ref class TKMath::xgp_Trsf;
	//! This class mplements elementaryruction algorithms for a
	//! symmetrical transformation in 3D space about a point,
	//! axis or plane. The result is a gp_Trsf transformation.
	//! A MakeMirror object provides a framework for:
	//! -   defining theruction of the transformation,
	//! -   implementing theruction algorithm, and
	//! -   consulting the result.
	public ref class xgce_MakeMirror
	{
	public:

		//DEFINE_STANDARD_ALLOC
		xgce_MakeMirror();

		xgce_MakeMirror(gce_MakeMirror* pos);

		void SetMakeMirror(gce_MakeMirror* pos);

		virtual gce_MakeMirror* GetMakeMirror();

		xgce_MakeMirror(xgp_Pnt^ Point);

		xgce_MakeMirror(xgp_Ax1^ Axis);

		xgce_MakeMirror(xgp_Lin^ Line);

		//! Makes a symmetry transformation af axis defined by
		//! <Point> and <Direc>.
		xgce_MakeMirror(xgp_Pnt^ Point, xgp_Dir^ Direc);

		//! Makes a symmetry transformation of plane <Plane>.
		xgce_MakeMirror(xgp_Pln^ Plane);

		//! Makes a symmetry transformation of plane <Plane>.
		xgce_MakeMirror(xgp_Ax2^ Plane);

		//! Returns theructed transformation.
		xgp_Trsf^ Value();

		xgp_Trsf^ Operator();
		operator xgp_Trsf^();

		/// <summary>
		/// ±¾µØ¾ä±ú
		/// </summary>
		property gce_MakeMirror* IHandle {
			gce_MakeMirror* get() {
				return 	NativeHandle;
			}
			void set(gce_MakeMirror* handle) {
				NativeHandle = handle;
			}
		}

	private:
		gce_MakeMirror* NativeHandle;
	};
}
#endif // _xgce_MakeMirror_HeaderFile
