// Created on: 1995-03-08
// Created by: Bruno DUMORTIER
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

#ifndef _XBRepPrimAPI_MakeHalfSpace_HeaderFile
#define _XBRepPrimAPI_MakeHalfSpace_HeaderFile
#pragma once
#include <XStandard_Helper.h>
#include <BRepPrimAPI_MakeHalfSpace.hxx>
#include <XBRepBuilderAPI_MakeShape.h>
#include <XTopoDS_Face.h>
#include <XTopoDS_Shell.h>
#include <XTopoDS_Solid.h>
#include <XTopoDS_Shape.h>
#include <xgp_Pnt.h>

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <TopoDS_Solid.hxx>
#include <BRepBuilderAPI_MakeShape.hxx>
class StdFail_NotDone;
class TopoDS_Face;
class TopoDS_Shell;
class TopoDS_Solid;
class gp_Pnt;


//! Describes functions to build half-spaces.
//! A half-space is an infinite solid, limited by a surface. It
//! is built from a face or a shell, which bounds it, and with
//! a reference point, which specifies the side of the
//! surface where the matter of the half-space is located.
//! A half-space is a tool commonly used in topological
//! operations to cut another shape.
//! A MakeHalfSpace object provides a framework for:
//! -   defining and implementing the construction of a half-space, and
//! -   consulting the result.
//! 
using namespace TKBRep;
using namespace TKMath;
using namespace TKTopAlgo;
namespace TKPrim {
	ref class TKBRep::XTopoDS_Face;
	ref class TKBRep::XTopoDS_Shell;
	ref class TKBRep::XTopoDS_Solid;
	ref class TKMath::xgp_Pnt;
	public ref class XBRepPrimAPI_MakeHalfSpace : public XBRepBuilderAPI_MakeShape
	{
	public:

		//! DEFINE_STANDARD_ALLOC

		XBRepPrimAPI_MakeHalfSpace();

		XBRepPrimAPI_MakeHalfSpace(BRepPrimAPI_MakeHalfSpace* handle);

		void SetMakeHalfSpaceHandle(BRepPrimAPI_MakeHalfSpace* handle);

		virtual BRepPrimAPI_MakeHalfSpace* GetMakeHalfSpace();

		virtual BRepBuilderAPI_MakeShape* GetMakeShape() Standard_OVERRIDE;

		//! Make a HalfSpace defined with a Face and a Point.
		XBRepPrimAPI_MakeHalfSpace(XTopoDS_Face^ Face, xgp_Pnt^ RefPnt);

		//! Make a HalfSpace defined with a Shell and a Point.
		XBRepPrimAPI_MakeHalfSpace(XTopoDS_Shell^ Shell, xgp_Pnt^ RefPnt);

		//! Returns the constructed half-space as a solid.
		XTopoDS_Solid^ Solid();
		operator XTopoDS_Solid^();

		/// <summary>
		/// ±¾µØ¾ä±ú
		/// </summary>
		virtual property BRepBuilderAPI_MakeShape* IHandle {
			BRepBuilderAPI_MakeShape* get() Standard_OVERRIDE {
				return NativeHandle;
			}
			void set(BRepBuilderAPI_MakeShape* handle) Standard_OVERRIDE {
				NativeHandle = static_cast<BRepPrimAPI_MakeHalfSpace*>(handle);
			}
		}

	private:
		BRepPrimAPI_MakeHalfSpace* NativeHandle;
	};
}
#endif // _XBRepPrimAPI_MakeHalfSpace_HeaderFile
