// Created on: 1992-11-05
// Created by: Remi LEQUETTE
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

#ifndef _XBRepPrim_Sphere_HeaderFile
#define _XBRepPrim_Sphere_HeaderFile
#pragma once
#include <XStandard_Helper.h>
#include <BRepPrim_Sphere.hxx>
#include <XBRepPrim_Revolution.h>
#include <XTopoDS_Face.h>
#include <xgp_Pnt.h>
#include <xgp_Ax2.h>
#include <xgp_Vec2d.h>

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <Standard_Real.hxx>
#include <BRepPrim_Revolution.hxx>
class Standard_DomainError;
class gp_Pnt;
class gp_Ax2;
class TopoDS_Face;

using namespace TKMath;
using namespace TKBRep;
namespace TKPrim {
	ref class TKMath::xgp_Pnt;
	ref class TKMath::xgp_Ax2;
	ref class TKBRep::XTopoDS_Face;
	ref class TKMath::xgp_Vec2d;
	//! Implements the sphere primitive
	public ref class XBRepPrim_Sphere : public XBRepPrim_Revolution
	{
	public:

		//! DEFINE_STANDARD_ALLOC
		!XBRepPrim_Sphere() { IHandle = NULL; };
		~XBRepPrim_Sphere() { IHandle = NULL; };
		//! 
		XBRepPrim_Sphere();

		XBRepPrim_Sphere(BRepPrim_Sphere* handle);

		void SetPrimSphereHandle(BRepPrim_Sphere* handle);

		virtual BRepPrim_Sphere* GetPrimSphere();

		virtual BRepPrim_Revolution* GetRevolution() Standard_OVERRIDE;

		virtual BRepPrim_OneAxis* GetOneAxis() Standard_OVERRIDE;

		//! Creates a Sphere at  origin with  Radius. The axes
		//! of the sphere are the  reference axes. An error is
		//! raised if the radius is < Resolution.
		XBRepPrim_Sphere(Standard_Real Radius);

		//! Creates a Sphere with Center and Radius.  Axes are
		//! the   referrence    axes.   This    is the    STEP
		//! constructor.
		XBRepPrim_Sphere(xgp_Pnt^ Center, Standard_Real Radius);

		//! Creates a sphere with given axes system.
		XBRepPrim_Sphere(xgp_Ax2^ Axes, Standard_Real Radius);

		//! The surface normal should be directed  towards the
		//! outside.
		virtual XTopoDS_Face^ MakeEmptyLateralFace() Standard_OVERRIDE;

		/// <summary>
		/// ±¾µØ¾ä±ú
		/// </summary>
		virtual property BRepPrim_OneAxis* IHandle {
			BRepPrim_OneAxis* get() Standard_OVERRIDE {
				return NativeHandle;
			}
			void set(BRepPrim_OneAxis* handle) Standard_OVERRIDE {
				NativeHandle = static_cast<BRepPrim_Sphere*>(handle);
			}
		}

	private:
		BRepPrim_Sphere* NativeHandle;
	};
}
#endif // _XBRepPrim_Sphere_HeaderFile
