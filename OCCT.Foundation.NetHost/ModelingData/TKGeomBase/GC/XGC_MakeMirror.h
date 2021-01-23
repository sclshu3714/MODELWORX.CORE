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

#ifndef _XGC_MakeMirror_HeaderFile
#define _XGC_MakeMirror_HeaderFile
#pragma once
#include <NCollection_Haft.h>
#include <GC_MakeMirror.hxx>
#include <xgp_Pnt.h>
#include <xgp_Ax1.h>
#include <xgp_Lin.h>
#include <xgp_Dir.h>
#include <xgp_Pln.h>
#include <xgp_Ax2.h>
#include <XGeom_Transformation.h>

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

class Geom_Transformation;
class gp_Pnt;
class gp_Ax1;
class gp_Lin;
class gp_Dir;
class gp_Pln;
class gp_Ax2;

using namespace TKMath;
using namespace TKG3d;
namespace TKGeomBase {
	ref class TKMath::xgp_Pnt;
	ref class TKMath::xgp_Ax1;
	ref class TKMath::xgp_Lin;
	ref class TKMath::xgp_Dir;
	ref class TKMath::xgp_Pln;
	ref class TKMath::xgp_Ax2;
	ref class TKG3d::XGeom_Transformation;
	//! This class implements elementary construction algorithms for a
	//! symmetrical transformation in 3D space about a point,
	//! axis or plane. The result is a Geom_Transformation transformation.
	//! A MakeMirror object provides a framework for:
	//! -   defining the construction of the transformation,
	//! -   implementing the construction algorithm, and
	//! -   consulting the result.
	public ref class XGC_MakeMirror
	{
	public:

		!XGC_MakeMirror() { IHandle = NULL; };
		~XGC_MakeMirror() { IHandle = NULL; };
		//! DEFINE_STANDARD_ALLOC
		XGC_MakeMirror();

		XGC_MakeMirror(GC_MakeMirror* pos);

		void SetMakeMirror(GC_MakeMirror* pos);

		virtual GC_MakeMirror* GetMakeMirror();

		XGC_MakeMirror(xgp_Pnt^ Point);

		XGC_MakeMirror(xgp_Ax1^ Axis);

		XGC_MakeMirror(xgp_Lin^ Line);

		//! Make a symetry transformation af axis defined by
		//! <Point> and <Direc>.
		XGC_MakeMirror(xgp_Pnt^ Point, xgp_Dir^ Direc);

		//! Make a symetry transformation of plane <Plane>.
		XGC_MakeMirror(xgp_Pln^ Plane);

		//! Make a symetry transformation of plane <Plane>.
		XGC_MakeMirror(xgp_Ax2^ Plane);

		//! Returns the constructed transformation.
		XGeom_Transformation^ Value();
		operator XGeom_Transformation^() { return Value(); }

		/// <summary>
		/// ±¾µØ¾ä±ú
		/// </summary>
		property  GC_MakeMirror* IHandle {
			GC_MakeMirror* get() {
				return 	NativeHandle;
			}
			void set(GC_MakeMirror* handle) {
				NativeHandle = handle;
			}
		}

	private:
		GC_MakeMirror* NativeHandle;
	};
}
#endif // _XGC_MakeMirror_HeaderFile
