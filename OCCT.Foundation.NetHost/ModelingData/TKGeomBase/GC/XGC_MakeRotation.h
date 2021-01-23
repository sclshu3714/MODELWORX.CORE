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

#ifndef _XGC_MakeRotation_HeaderFile
#define _XGC_MakeRotation_HeaderFile
#pragma once
#include <NCollection_Haft.h>
#include <GC_MakeRotation.hxx>
#include <xgp_Ax1.h>
#include <xgp_Lin.h>
#include <xgp_Pnt.h>
#include <xgp_Dir.h>
#include <XGeom_Transformation.h>

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <Standard_Real.hxx>
class Geom_Transformation;
class gp_Lin;
class gp_Ax1;
class gp_Pnt;
class gp_Dir;

using namespace TKMath;
using namespace TKG3d;
namespace TKGeomBase {
	ref class TKMath::xgp_Ax1;
	ref class TKMath::xgp_Lin;
	ref class TKMath::xgp_Pnt;
	ref class TKMath::xgp_Dir;
	ref class TKG3d::XGeom_Transformation;
	//! This class implements elementary construction algorithms for a
	//! rotation in 3D space. The result is a
	//! Geom_Transformation transformation.
	//! A MakeRotation object provides a framework for:
	//! -   defining the construction of the transformation,
	//! -   implementing the construction algorithm, and
	//! -   consulting the result.
	public ref class XGC_MakeRotation
	{
	public:

		!XGC_MakeRotation() { IHandle = NULL; };
		~XGC_MakeRotation() { IHandle = NULL; };
		//! DEFINE_STANDARD_ALLOC
		XGC_MakeRotation();

		XGC_MakeRotation(GC_MakeRotation* pos);

		void SetMakeRotation(GC_MakeRotation* pos);

		virtual GC_MakeRotation* GetMakeRotation();

		//! Constructs a rotation through angle Angle about the axis defined by the line Line.
		XGC_MakeRotation(xgp_Lin^ Line, Standard_Real Angle);

		//! Constructs a rotation through angle Angle about the axis defined by the axis Axis.
		XGC_MakeRotation(xgp_Ax1^ Axis, Standard_Real Angle);

		//! Constructs a rotation through angle Angle about the axis
		//! defined by the point Point and the unit vector Direc.
		XGC_MakeRotation(xgp_Pnt^ Point, xgp_Dir^ Direc, Standard_Real Angle);

		//! Returns the constructed transformation.
		XGeom_Transformation^ Value();
		operator const XGeom_Transformation^() { return Value(); }

		/// <summary>
		/// ±¾µØ¾ä±ú
		/// </summary>
		property  GC_MakeRotation* IHandle {
			GC_MakeRotation* get() {
				return 	NativeHandle;
			}
			void set(GC_MakeRotation* handle) {
				NativeHandle = handle;
			}
		}

	private:
		GC_MakeRotation* NativeHandle;
	};
}
#endif // _XGC_MakeRotation_HeaderFile
