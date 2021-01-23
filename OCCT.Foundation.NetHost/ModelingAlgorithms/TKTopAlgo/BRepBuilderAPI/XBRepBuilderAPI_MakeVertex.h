// Created on: 1993-07-06
// Created by: Remi LEQUETTE
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

#ifndef _XBRepBuilderAPI_MakeVertex_HeaderFile
#define _XBRepBuilderAPI_MakeVertex_HeaderFile
#pragma once
#include <BRepBuilderAPI_MakeVertex.hxx>
#include <XBRepBuilderAPI_MakeShape.h>
#include <XTopoDS_Vertex.h>
#include <xgp_Pnt.h>


#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <BRepLib_MakeVertex.hxx>
#include <BRepBuilderAPI_MakeShape.hxx>
class gp_Pnt;
class TopoDS_Vertex;


//! Describes functions to build BRepBuilder vertices directly
//! from 3D geometric points. A vertex built using a
//! MakeVertex object is only composed of a 3D point and
//! a default precision value (Precision::Confusion()).
//! Later on, 2D representations can be added, for example,
//! when inserting a vertex in an edge.
//! A MakeVertex object provides a framework for:
//! -   defining and implementing the construction of a vertex, and
//! -   consulting the result.
//! 
namespace TKTopAlgo {
	public ref class XBRepBuilderAPI_MakeVertex : public XBRepBuilderAPI_MakeShape
	{
	public:

		//!
		//!  DEFINE_STANDARD_ALLOC
		!XBRepBuilderAPI_MakeVertex() { IHandle = NULL; };
		~XBRepBuilderAPI_MakeVertex() { IHandle = NULL; };

		//! Constructs a vertex from point P.
		//! Example create a vertex from a 3D point.
		//! gp_Pnt P(0,0,10);
		//! TopoDS_Vertex V = BRepBuilderAPI_MakeVertex(P);
		XBRepBuilderAPI_MakeVertex(xgp_Pnt^ P);

		//! Returns the constructed vertex.
		virtual XTopoDS_Vertex^ Vertex();
		virtual operator XTopoDS_Vertex^();

		/// <summary>
		/// ���ؾ��
		/// </summary>
		virtual property BRepBuilderAPI_MakeShape* IHandle {
			BRepBuilderAPI_MakeShape* get() Standard_OVERRIDE {
				return NativeHandle;
			}
			void set(BRepBuilderAPI_MakeShape* handle) Standard_OVERRIDE {
				NativeHandle = static_cast<BRepBuilderAPI_MakeVertex*>(handle);
			}
		}

	private:
		BRepBuilderAPI_MakeVertex* NativeHandle;
	};
}
#endif // _XBRepBuilderAPI_MakeVertex_HeaderFile
