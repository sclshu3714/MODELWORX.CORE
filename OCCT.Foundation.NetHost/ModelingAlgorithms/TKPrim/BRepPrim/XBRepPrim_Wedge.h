// Created on: 1995-01-09
// Created by: Modelistation
// Copyright (c) 1995-1999 Matra Datavision
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

#ifndef _XBRepPrim_Wedge_HeaderFile
#define _XBRepPrim_Wedge_HeaderFile
#pragma once
#include <BRepPrim_Wedge.hxx>
#include <XBRepPrim_GWedge.h>
#include <XStandard_Helper.h>
#include <xgp_Ax2.h>
#include <xgp_Vec2d.h>

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <Standard_Real.hxx>
class Standard_DomainError;

using namespace TKMath;
namespace TKPrim {
	ref class TKMath::xgp_Ax2;
	ref class TKMath::xgp_Vec2d;
	//! Provides constructors without Builders.
	public ref class XBRepPrim_Wedge : public XBRepPrim_GWedge
	{
	public:

		//! DEFINE_STANDARD_ALLOC
		!XBRepPrim_Wedge() { IHandle = NULL; };
		~XBRepPrim_Wedge() { IHandle = NULL; };

		XBRepPrim_Wedge(BRepPrim_Wedge* handle);


		void SetBRepPrimWedgeHandle(BRepPrim_Wedge* handle);


		virtual BRepPrim_Wedge* GetBRepPrimWedge();

		virtual BRepPrim_GWedge* GetGWedge() Standard_OVERRIDE;

		//! Creates a  Wedge  algorithm.   <Axes> is  the axis
		//! system for the primitive.
		//!
		//! XMin, YMin, ZMin are set to 0
		//! XMax, YMax, ZMax are set to dx, dy, dz
		//! Z2Min = ZMin
		//! Z2Max = ZMax
		//! X2Min = XMin
		//! X2Max = XMax
		//! The result is a box
		//! dx,dy,dz should be positive
		XBRepPrim_Wedge(xgp_Ax2^ Axes, Standard_Real dx, Standard_Real dy, Standard_Real dz);

		//! Creates  a Wedge  primitive. <Axes> is   the  axis
		//! system for the primitive.
		//!
		//! XMin, YMin, ZMin are set to 0
		//! XMax, YMax, ZMax are set to dx, dy, dz
		//! Z2Min = ZMin
		//! Z2Max = ZMax
		//! X2Min = ltx
		//! X2Max = ltx
		//! The result is a STEP right angular wedge
		//! dx,dy,dz should be positive
		//! ltx should not be negative
		XBRepPrim_Wedge(xgp_Ax2^ Axes, Standard_Real dx, Standard_Real dy, Standard_Real dz, Standard_Real ltx);

		//! Create  a Wedge primitive.   <Axes>  is  the  axis
		//! system for the primitive.
		//!
		//! all the fields are set to the corresponding value
		//! XYZMax - XYZMin should be positive
		//! ZX2Max - ZX2Min should not be negative
		XBRepPrim_Wedge(xgp_Ax2^ Axes, Standard_Real xmin, Standard_Real ymin, Standard_Real zmin, Standard_Real z2min, Standard_Real x2min, Standard_Real xmax, Standard_Real ymax, Standard_Real zmax, Standard_Real z2max, Standard_Real x2max);

		/// <summary>
		/// ±¾µØ¾ä±ú
		/// </summary>
		virtual property BRepPrim_GWedge* IHandle {
			BRepPrim_GWedge* get() Standard_OVERRIDE {
				return NativeHandle;
			}
			void set(BRepPrim_GWedge* handle) Standard_OVERRIDE {
				//NativeHandle = static_cast<BRepPrim_Wedge*>(handle);
				if (handle == NULL)
					NativeHandle = static_cast<BRepPrim_Wedge*>(handle);
				else
					NativeHandle = NULL;
			}
		}

	private:
		BRepPrim_Wedge* NativeHandle;
	};
}
#endif // _XBRepPrim_Wedge_HeaderFile
