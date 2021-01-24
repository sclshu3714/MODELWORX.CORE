// Created on: 1993-06-22
// Created by: Laurent BOURESCHE
// Copyright (c) 1993-1999 Matra Datavision
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

#ifndef _XBRepSweep_Revol_HeaderFile
#define _XBRepSweep_Revol_HeaderFile
#pragma once
#include <XStandard_Helper.h>
#include <BRepSweep_Revol.hxx>
#include <XTopoDS_Shape.h>
#include <XTopLoc_Location.h>
#include <xgp_Ax1.h>
#include <TopoDS_Shape.hxx>

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <BRepSweep_Rotation.hxx>
#include <Standard_Boolean.hxx>
#include <Standard_Real.hxx>
class Standard_ConstructionError;
class Sweep_NumShape;
class TopoDS_Shape;

using namespace TKBRep;
using namespace TKMath;
namespace TKPrim {
	//! Provides natural constructors to build BRepSweep
	//! rotated swept Primitives.
	ref class TKBRep::XTopoDS_Shape;
	ref class TKMath::xgp_Ax1;
	ref class TKMath::XTopLoc_Location;
	public ref class XBRepSweep_Revol
	{
	public:

		//! DEFINE_STANDARD_ALLOC

		!XBRepSweep_Revol() { IHandle = NULL; };
		~XBRepSweep_Revol() { IHandle = NULL; };

		XBRepSweep_Revol();

		XBRepSweep_Revol(BRepSweep_Revol* pos);

		void SetSweepRevolHandle(BRepSweep_Revol* pos);

		virtual BRepSweep_Revol* GetSweepRevol();

		//! Builds the Revol of meridian S axis A  and angle D. If
		//! C is true S is copied.
		//! Standard_Boolean C = Standard_False
		XBRepSweep_Revol(XTopoDS_Shape^ S, xgp_Ax1^ A, Standard_Real D, Standard_Boolean C);

		//! Builds the Revol of meridian S  axis A and angle 2*Pi.
		//! If C is true S is copied.
		//! Standard_Boolean C = Standard_False
		XBRepSweep_Revol(XTopoDS_Shape^ S, xgp_Ax1^ A, Standard_Boolean C);

		//! Returns the TopoDS Shape attached to the Revol.
		XTopoDS_Shape^ Shape();

		//! Returns    the  TopoDS  Shape   generated  with  aGenS
		//! (subShape  of the generating shape).
		XTopoDS_Shape^ Shape(XTopoDS_Shape^ aGenS);

		//! Returns the first shape of the revol  (coinciding with
		//! the generating shape).
		XTopoDS_Shape^ FirstShape();

		//! Returns the first shape of the revol  (coinciding with
		//! the generating shape).
		XTopoDS_Shape^ FirstShape(XTopoDS_Shape^ aGenS);

		//! Returns the TopoDS Shape of the top of the prism.
		XTopoDS_Shape^ LastShape();

		//! Returns the  TopoDS  Shape of the top  of  the  prism.
		//! generated  with  aGenS  (subShape  of  the  generating
		//! shape).
		XTopoDS_Shape^ LastShape(XTopoDS_Shape^ aGenS);

		//! returns the axis
		xgp_Ax1^ Axe();

		//! returns the angle.
		Standard_Real Angle();

		//! Returns true if the aGenS is used in resulting Shape 
		Standard_Boolean IsUsed(XTopoDS_Shape^ aGenS);

		/// <summary>
		/// ±¾µØ¾ä±ú
		/// </summary>
		virtual property BRepSweep_Revol* IHandle {
			BRepSweep_Revol* get() { //Standard_OVERRIDE {
				return NativeHandle;
			}
			void set(BRepSweep_Revol* handle) { //Standard_OVERRIDE {
				//NativeHandle = static_cast<BRepSweep_Revol*>(handle);
				if (handle == NULL)
					NativeHandle = static_cast<BRepSweep_Revol*>(handle);
				else
					NativeHandle = NULL;
			}
		}

	private:
		BRepSweep_Revol* NativeHandle;
	};
}
#endif // _XBRepSweep_Revol_HeaderFile
