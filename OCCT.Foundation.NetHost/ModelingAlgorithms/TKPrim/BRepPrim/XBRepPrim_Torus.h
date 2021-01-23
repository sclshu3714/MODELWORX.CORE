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

#ifndef _XBRepPrim_Torus_HeaderFile
#define _XBRepPrim_Torus_HeaderFile
#pragma once
#include <XStandard_Helper.h>
#include <BRepPrim_Torus.hxx>
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
class gp_Ax2;
class gp_Pnt;
class TopoDS_Face;

using namespace TKMath;
using namespace TKBRep;
namespace TKPrim {
	ref class TKMath::xgp_Pnt;
	ref class TKMath::xgp_Ax2;
	ref class TKMath::xgp_Vec2d;
	ref class TKBRep::XTopoDS_Face;
	//! Implements the torus primitive
	public ref class XBRepPrim_Torus : public XBRepPrim_Revolution
	{
	public:

		//! DEFINE_STANDARD_ALLOC
		!XBRepPrim_Torus() { IHandle = NULL; };
		~XBRepPrim_Torus() { IHandle = NULL; };
		//! 
		XBRepPrim_Torus();

		XBRepPrim_Torus(BRepPrim_Torus* handle);

		void SetPrimTorusHandle(BRepPrim_Torus* handle);

		virtual BRepPrim_Torus* GetPrimTorus();

		virtual BRepPrim_Revolution* GetRevolution() Standard_OVERRIDE;

		virtual BRepPrim_OneAxis* GetOneAxis() Standard_OVERRIDE;

		//! the STEP definition
		//! Position : center and axes
		//! Major, Minor : Radii
		//!
		//! Errors : Major < Resolution
		//! Minor < Resolution
		XBRepPrim_Torus(xgp_Ax2^ Position, Standard_Real Major, Standard_Real Minor);

		//! Torus centered at origin
		XBRepPrim_Torus(Standard_Real Major, Standard_Real Minor);

		//! Torus at Center
		XBRepPrim_Torus(xgp_Pnt^ Center, Standard_Real Major, Standard_Real Minor);

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
				NativeHandle = static_cast<BRepPrim_Torus*>(handle);
			}
		}

	private:
		BRepPrim_Torus* NativeHandle;
	};
}
#endif // _XBRepPrim_Torus_HeaderFile
