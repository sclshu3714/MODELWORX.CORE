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

#ifndef _XBRepPrim_Cone_HeaderFile
#define _XBRepPrim_Cone_HeaderFile
#pragma once
#include <XStandard_Helper.h>
#include <BRepPrim_Cone.hxx>
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
	//! Implement the cone primitive.
	ref class TKBRep::XTopoDS_Face;
	ref class TKMath::xgp_Pnt;
	ref class TKMath::xgp_Ax2;
	ref class TKMath::xgp_Vec2d;
	public ref class XBRepPrim_Cone : public XBRepPrim_Revolution
	{
	public:

		//! DEFINE_STANDARD_ALLOC


		XBRepPrim_Cone();

		XBRepPrim_Cone(BRepPrim_Cone* handle);

		void SetPrimConeHandle(BRepPrim_Cone* handle);

		virtual BRepPrim_Cone* GetPrimCone();
		 
		virtual BRepPrim_Revolution* GetRevolution() Standard_OVERRIDE;

		virtual BRepPrim_OneAxis* GetOneAxis() Standard_OVERRIDE;

		//! the STEP definition
		//! Angle = semi-angle of the cone
		//! Position : the coordinate system
		//! Height : height of the cone.
		//! Radius : radius of truncated face at z = 0
		//!
		//! The apex is on z < 0
		//!
		//! Errors : Height < Resolution
		//! Angle < Resolution / Height
		//! Angle > PI/2 - Resolution / Height
		//! Radius = 0
		XBRepPrim_Cone(Standard_Real Angle, xgp_Ax2^ Position, Standard_Real Height, Standard_Real Radius);

		//! infinite cone at origin on Z negative
		XBRepPrim_Cone(Standard_Real Angle);

		//! infinite cone at Apex on Z negative
		XBRepPrim_Cone(Standard_Real Angle, xgp_Pnt^ Apex);

		//! infinite cone with Axes
		XBRepPrim_Cone(Standard_Real Angle, xgp_Ax2^ Axes);

		//! create a  Cone at origin  on Z axis, of height  H,
		//! radius R1 at Z = 0, R2 at  Z = H, X is  the origin
		//! of angles.  If R1 or  R2 is 0   there is  an apex.
		//! Otherwise, it is a truncated cone.
		//!
		//! Error  : R1 and R2  < Resolution
		//! R1 or R2 negative
		//! Abs(R1-R2) < Resolution
		//! H < Resolution
		//! H negative
		XBRepPrim_Cone(Standard_Real R1, Standard_Real R2, Standard_Real H);

		//! same as above but at a given point
		XBRepPrim_Cone(xgp_Pnt^ Center, Standard_Real R1, Standard_Real R2, Standard_Real H);

		//! same as above with given axes system.
		XBRepPrim_Cone(xgp_Ax2^ Axes, Standard_Real R1, Standard_Real R2, Standard_Real H);

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
				NativeHandle = static_cast<BRepPrim_Cone*>(handle);
			}
		}

	private:
		BRepPrim_Cone* NativeHandle;
	};
}
#endif // _XBRepPrim_Cone_HeaderFile
