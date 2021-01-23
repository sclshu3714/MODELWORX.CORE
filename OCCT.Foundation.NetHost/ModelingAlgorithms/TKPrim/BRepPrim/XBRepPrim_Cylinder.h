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

#ifndef _XBRepPrim_Cylinder_HeaderFile
#define _XBRepPrim_Cylinder_HeaderFile
#pragma once
#include <XStandard_Helper.h>
#include <BRepPrim_Cylinder.hxx>
#include <XBRepPrim_Revolution.h>
#include <XTopoDS_Face.h>
#include <xgp_Pnt.h>
#include <xgp_Ax2.h>
#include <xgp_Vec2d.h>

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <Standard_Real.hxx>
class Standard_DomainError;
class gp_Ax2;
class gp_Pnt;
class TopoDS_Face;

using namespace TKMath;
using namespace TKBRep;
namespace TKPrim {
	//! Cylinder primitive.
	
	ref class TKBRep::XTopoDS_Face;
	ref class TKMath::xgp_Pnt;
	ref class TKMath::xgp_Ax2;
	ref class TKMath::xgp_Vec2d;
	public ref class XBRepPrim_Cylinder : public XBRepPrim_Revolution
	{
	public:

		//! DEFINE_STANDARD_ALLOC
		!XBRepPrim_Cylinder() { IHandle = NULL; };
		~XBRepPrim_Cylinder() { IHandle = NULL; };
		//! 
		XBRepPrim_Cylinder();

		XBRepPrim_Cylinder(BRepPrim_Cylinder* handle);

		void SetCylinderHandle(BRepPrim_Cylinder* handle);

		virtual BRepPrim_Cylinder* GetCylinder();

		virtual BRepPrim_Revolution* GetRevolution() Standard_OVERRIDE;

		virtual BRepPrim_OneAxis* GetOneAxis() Standard_OVERRIDE;

		//! the STEP definition
		//! Position : center of a Face and Axis
		//! Radius : radius of cylinder
		//! Height : distance between faces
		//! on positive side
		//!
		//! Errors : Height < Resolution
		//! Radius < Resolution
		XBRepPrim_Cylinder(xgp_Ax2^ Position, Standard_Real Radius, Standard_Real Height);

		//! infinite Cylinder at origin on Z negative
		XBRepPrim_Cylinder(Standard_Real Radius);

		//! infinite Cylinder at Center on Z negative
		XBRepPrim_Cylinder(xgp_Pnt^ Center, Standard_Real Radius);

		//! infinite Cylinder at Axes on Z negative
		XBRepPrim_Cylinder(xgp_Ax2^ Axes, Standard_Real Radius);

		//! create a Cylinder  at origin on Z  axis, of
		//! height H and radius R
		//! Error  : Radius  < Resolution
		//! H < Resolution
		//! H negative
		XBRepPrim_Cylinder(Standard_Real R, Standard_Real H);

		//! same as above but at a given point
		XBRepPrim_Cylinder(xgp_Pnt^ Center, Standard_Real R, Standard_Real H);

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
				NativeHandle = static_cast<BRepPrim_Cylinder*>(handle);
			}
		}

	private:
		BRepPrim_Cylinder* NativeHandle;
	};
}
#endif // _XBRepPrim_Cylinder_HeaderFile
