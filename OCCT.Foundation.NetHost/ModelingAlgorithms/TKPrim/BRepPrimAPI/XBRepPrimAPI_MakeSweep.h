// Created on: 1994-02-18
// Created by: Remi LEQUETTE
// Copyright (c) 1994-1999 Matra Datavision
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

#ifndef _XBRepPrimAPI_MakeSweep_HeaderFile
#define _XBRepPrimAPI_MakeSweep_HeaderFile
#pragma once
#include <BRepPrimAPI_MakeSweep.hxx>
#include <XBRepBuilderAPI_MakeShape.h>
#include <XTopoDS_Shape.h>

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>




//! The abstract class MakeSweep is
//! the root class of swept primitives.
//! Sweeps are objects you obtain by sweeping a profile along a path.
//! The profile can be any topology and the path is usually a curve or
//! a wire. The profile generates objects according to the following rules:
//! -      Vertices generate Edges
//! -      Edges generate Faces.
//! -      Wires generate Shells.
//! -      Faces generate Solids.
//! -      Shells generate Composite  Solids.
//! You are not allowed to sweep Solids and Composite Solids.
//! Two kinds of sweeps are implemented in the BRepPrimAPI package:
//! -      The linear sweep called a   Prism
//! -      The rotational sweep    called a Revol
//! Swept constructions along complex profiles such as BSpline curves
//! are also available in the BRepOffsetAPI package..
//! 
using namespace TKBRep;	
using namespace TKTopAlgo;
namespace TKPrim {
	ref class TKBRep::XTopoDS_Shape;
	public ref class XBRepPrimAPI_MakeSweep : public XBRepBuilderAPI_MakeShape
	{
	public:

		//! DEFINE_STANDARD_ALLOC
		void SetMakeSweepHandle(BRepPrimAPI_MakeSweep* pos);

		virtual BRepPrimAPI_MakeSweep* GetMakeSweep();

		virtual BRepBuilderAPI_MakeShape* GetMakeShape() Standard_OVERRIDE;

		virtual XTopoDS_Shape^ Shape() Standard_OVERRIDE;

		//! Returns the  TopoDS  Shape of the bottom of the sweep.
		virtual XTopoDS_Shape^ FirstShape();

		//! Returns the TopoDS Shape of the top of the sweep.
		virtual XTopoDS_Shape^ LastShape();

		/// <summary>
		/// ±¾µØ¾ä±ú
		/// </summary>
		virtual property BRepBuilderAPI_MakeShape* IHandle {
			BRepBuilderAPI_MakeShape* get() Standard_OVERRIDE {
				return NativeHandle;
			}
			void set(BRepBuilderAPI_MakeShape* handle) Standard_OVERRIDE {
				NativeHandle = static_cast<BRepPrimAPI_MakeSweep*>(handle);
			}
		}

	private:
		BRepPrimAPI_MakeSweep* NativeHandle;
	};
}
#endif // _XBRepPrimAPI_MakeSweep_HeaderFile
