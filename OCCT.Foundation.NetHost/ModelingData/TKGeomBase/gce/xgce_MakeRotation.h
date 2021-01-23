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

#ifndef _xgce_MakeRotation_HeaderFile
#define _xgce_MakeRotation_HeaderFile
#pragma once
#include <gce_MakeRotation.hxx>
#include <xgp_Lin.h>
#include <xgp_Ax1.h>
#include <xgp_Pnt.h>
#include <xgp_Dir.h>
#include <xgp_Trsf.h>

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <gp_Trsf.hxx>
#include <Standard_Real.hxx>
class gp_Lin;
class gp_Ax1;
class gp_Pnt;
class gp_Dir;
class gp_Trsf;

using namespace TKMath;

namespace TKGeomBase {
	ref class TKMath::xgp_Lin;
	ref class TKMath::xgp_Ax1;
	ref class TKMath::xgp_Pnt;
	ref class TKMath::xgp_Dir;
	ref class TKMath::xgp_Trsf;
	//! This class implements elementaryruction algorithms for a
	//! rotation in 3D space. The result is a gp_Trsf transformation.
	//! A MakeRotation object provides a framework for:
	//! -   defining theruction of the transformation,
	//! -   implementing theruction algorithm, and
	//! -   consulting the result.
	public ref class xgce_MakeRotation
	{
	public:

		//DEFINE_STANDARD_ALLOC
		xgce_MakeRotation();
		!xgce_MakeRotation() { IHandle = NULL; };
		~xgce_MakeRotation() { IHandle = NULL; };
		xgce_MakeRotation(gce_MakeRotation* pos);

		void SetMakeRotation(gce_MakeRotation* pos);

		virtual gce_MakeRotation* GetMakeRotation();

		//! Constructs a rotation through angle Angle about the axis defined by the line Line.
		xgce_MakeRotation(xgp_Lin^ Line, Standard_Real Angle);

		//! Constructs a rotation through angle Angle about the axis defined by the axis Axis.
		xgce_MakeRotation(xgp_Ax1^ Axis, Standard_Real Angle);


		//! Constructs a rotation through angle Angle about the axis defined by:
		//! the point Point and the unit vector Direc.
		xgce_MakeRotation(xgp_Pnt^ Point, xgp_Dir^ Direc, Standard_Real Angle);

		//! Returns theructed transformation.
		xgp_Trsf^ Value();

		xgp_Trsf^ Operator();
		operator xgp_Trsf^();
		/// <summary>
		/// ±¾µØ¾ä±ú
		/// </summary>
		property gce_MakeRotation* IHandle {
			gce_MakeRotation* get() {
				return 	NativeHandle;
			}
			void set(gce_MakeRotation* handle) {
				NativeHandle = handle;
			}
		}

	private:
		gce_MakeRotation* NativeHandle;
	};
}
#endif // _xgce_MakeRotation_HeaderFile
