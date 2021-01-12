// Created on: 1995-11-02
// Created by: Jing Cheng MEI
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

#ifndef _XBRepBuilderAPI_FindPlane_HeaderFile
#define _XBRepBuilderAPI_FindPlane_HeaderFile
#pragma once
#include <BRepBuilderAPI_FindPlane.hxx>
#include <XGeom_Plane.h>
#include <XTopoDS_Shape.h>

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <Standard_Real.hxx>
#include <Standard_Boolean.hxx>

class Standard_NoSuchObject;
class Geom_Plane;
class TopoDS_Shape;

using namespace TKG3d;
using namespace TKBRep;
namespace TKTopAlgo {
	ref class TKG3d::XGeom_Plane;
	ref class TKBRep::XTopoDS_Shape;
	//! Describes functions to find the plane in which the edges
	//! of a given shape are located.
	//! A FindPlane object provides a framework for:
	//! -   extracting the edges of a given shape,
	//! -   implementing the construction algorithm, and
	//! -   consulting the result.
	public ref class XBRepBuilderAPI_FindPlane
	{
	public:

		//! DEFINE_STANDARD_ALLOC


		//! Initializes an empty algorithm. The function Init is then used to define the shape.
		XBRepBuilderAPI_FindPlane();

		XBRepBuilderAPI_FindPlane(BRepBuilderAPI_FindPlane* pos);

		void SetFindPlaneHandle(BRepBuilderAPI_FindPlane* pos);

		virtual BRepBuilderAPI_FindPlane* GetFindPlane();

		//! Constructs the plane containing the edges of the shape S.
		//! A plane is built only if all the edges are within a distance
		//! of less than or equal to tolerance from a planar surface.
		//! This tolerance value is equal to the larger of the following two values:
		//! -   Tol, where the default value is negative, or
		//! -   the largest of the tolerance values assigned to the individual edges of S.
		//! Use the function Found to verify that a plane is built.
		//! The resulting plane is then retrieved using the function Plane.
		//! Standard_Real Tol = -1
		XBRepBuilderAPI_FindPlane(XTopoDS_Shape^ S, Standard_Real Tol);

		//! Constructs the plane containing the edges of the shape S.
		//! A plane is built only if all the edges are within a distance
		//! of less than or equal to tolerance from a planar surface.
		//! This tolerance value is equal to the larger of the following two values:
		//! -   Tol, where the default value is negative, or
		//! -   the largest of the tolerance values assigned to the individual edges of S.
		//! Use the function Found to verify that a plane is built.
		//! The resulting plane is then retrieved using the function Plane.
		void Init(XTopoDS_Shape^ S, Standard_Real Tol);

		//! Returns true if a plane containing the edges of the
		//! shape is found and built. Use the function Plane to consult the result.
		Standard_Boolean Found();

		//! Returns the plane containing the edges of the shape.
		//! Warning
		//! Use the function Found to verify that the plane is built. If
		//! a plane is not found, Plane returns a null handle.
		XGeom_Plane^ Plane();
		/// <summary>
		/// ±¾µØ¾ä±ú
		/// </summary>
		virtual property BRepBuilderAPI_FindPlane* IHandle {
			BRepBuilderAPI_FindPlane* get() { //Standard_OVERRIDE {
				return NativeHandle;
			}
			void set(BRepBuilderAPI_FindPlane* handle)  { //Standard_OVERRIDE {
				NativeHandle = handle;
			}
		}

	private:
		BRepBuilderAPI_FindPlane* NativeHandle;
	};
}
#endif // _XBRepBuilderAPI_FindPlane_HeaderFile
