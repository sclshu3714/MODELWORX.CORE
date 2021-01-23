// Created on: 1994-12-12
// Created by: Jacques GOUSSARD
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

#ifndef _XBRepBuilderAPI_Copy_HeaderFile
#define _XBRepBuilderAPI_Copy_HeaderFile
#pragma once
#include <BRepBuilderAPI_Copy.hxx>
#include <XBRepBuilderAPI_ModifyShape.h>
#include <XTopoDS_Shape.h>


#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <BRepBuilderAPI_ModifyShape.hxx>

class TopoDS_Shape;

using namespace TKBRep;
namespace TKTopAlgo {
	ref class TKBRep::XTopoDS_Shape;
	//! Duplication of a shape.
	//! A Copy object provides a framework for:
	//! -   defining the construction of a duplicate shape,
	//! -   implementing the construction algorithm, and
	//! -   consulting the result.
	public ref class XBRepBuilderAPI_Copy : public XBRepBuilderAPI_ModifyShape
	{
	public:

		!XBRepBuilderAPI_Copy() { IHandle = NULL; };
		~XBRepBuilderAPI_Copy() { IHandle = NULL; };
		//! DEFINE_STANDARD_ALLOC
		//! Constructs an empty copy framework. Use the function
		//! Perform to copy shapes.
		XBRepBuilderAPI_Copy();

		void SetCopyHandle(BRepBuilderAPI_Copy* handle);

		virtual BRepBuilderAPI_Copy* GetCopy();

		virtual BRepBuilderAPI_ModifyShape* GetModifyShape() Standard_OVERRIDE;

		virtual BRepBuilderAPI_MakeShape* GetMakeShape() Standard_OVERRIDE;

		//! Constructs a copy framework and copies the shape S.
		//! Use the function Shape to access the result.
		//! If copyMesh is True, triangulation contained in original shape will be 
		//! copied along with geometry (by default, triangulation gets lost).
		//! If copyGeom is False, only topological objects will be copied, while 
		//! geometry and triangulation will be shared with original shape.
		//! Note: the constructed framework can be reused to copy
		//! other shapes: just specify them with the function Perform.
		//! const Standard_Boolean copyGeom = Standard_True, const Standard_Boolean copyMesh = Standard_False
		XBRepBuilderAPI_Copy(XTopoDS_Shape^ S, Standard_Boolean copyGeom, Standard_Boolean copyMesh);

		//! Copies the shape S.
		//! Use the function Shape to access the result.
		//! If copyMesh is True, triangulation contained in original shape will be 
		//! copied along with geometry (by default, triangulation gets lost).
		//! If copyGeom is False, only topological objects will be copied, while 
		//! geometry and triangulation will be shared with original shape.
		//! const Standard_Boolean copyGeom = Standard_True, const Standard_Boolean copyMesh = Standard_False
		void Perform(XTopoDS_Shape^ S, Standard_Boolean copyGeom, Standard_Boolean copyMesh);

		/// <summary>
		/// ���ؾ��
		/// </summary>
		virtual property BRepBuilderAPI_MakeShape* IHandle {
			BRepBuilderAPI_MakeShape* get() Standard_OVERRIDE {
				return NativeHandle;
			}
			void set(BRepBuilderAPI_MakeShape* handle) Standard_OVERRIDE {
				NativeHandle = static_cast<BRepBuilderAPI_Copy*>(handle);
			}
		}

	private:
		BRepBuilderAPI_Copy* NativeHandle;
	};
}
#endif // _XBRepBuilderAPI_Copy_HeaderFile
