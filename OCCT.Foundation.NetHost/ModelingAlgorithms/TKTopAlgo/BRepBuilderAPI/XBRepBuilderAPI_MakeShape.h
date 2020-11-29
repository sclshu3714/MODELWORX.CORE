// Created on: 1993-07-21
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

#ifndef _XBRepBuilderAPI_MakeShape_HeaderFile
#define _XBRepBuilderAPI_MakeShape_HeaderFile
#pragma once
#include <BRepBuilderAPI_MakeShape.hxx>
#include <XTopoDS_Shape.h>

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <TopoDS_Shape.hxx>
#include <TopTools_ListOfShape.hxx>
#include <BRepBuilderAPI_Command.hxx>
#include <Standard_Boolean.hxx>
#include <XTopTools_ListOfShape.h>
class StdFail_NotDone;
class TopoDS_Shape;

using namespace TKBRep;
namespace TKTopAlgo {
	//! This    is  the  root     class for     all  shape
	//! constructions.  It stores the result.
	//!
	//! It  provides deferred methods to trace the history
	//! of sub-shapes.
	ref class TKBRep::XTopoDS_Shape;
	ref class TKBRep::XTopTools_ListOfShape;
	public ref class XBRepBuilderAPI_MakeShape  //: public BRepBuilderAPI_Command
	{
	public:

	//!	DEFINE_STANDARD_ALLOC

		XBRepBuilderAPI_MakeShape();

		void SetMakeShapeHandle(BRepBuilderAPI_MakeShape handle);

		//! This is  called by  Shape().  It does  nothing but
		//! may be redefined.
		virtual void Build();

		//! Returns a shape built by the shape construction algorithm.
		//! Raises exception StdFail_NotDone if the shape was not built.
		virtual XTopoDS_Shape^ Shape();
		
		operator XTopoDS_Shape^();

		//! Returns the  list   of shapes generated   from the
		//! shape <S>.
		virtual XTopTools_ListOfShape^ Generated(XTopoDS_Shape^ S);

		//! Returns the list  of shapes modified from the shape
		//! <S>.
		virtual XTopTools_ListOfShape^ Modified(XTopoDS_Shape^ S);

		//! Returns true if the shape S has been deleted.
		virtual Standard_Boolean IsDeleted(XTopoDS_Shape^ S);

		/// <summary>
		/// ���ؾ��
		/// </summary>
		virtual property BRepBuilderAPI_MakeShape* IHandle {
			BRepBuilderAPI_MakeShape* get() Standard_OVERRIDE {
				return NativeHandle;
			}
			void set(BRepBuilderAPI_MakeShape* handle) Standard_OVERRIDE {
				NativeHandle = static_cast<BRepBuilderAPI_MakeShape*>(handle);
			}
		}

	private:
		BRepBuilderAPI_MakeShape* NativeHandle;
		//NCollection_Haft<Handle(BRepBuilderAPI_MakeShape)> NativeHandle;
	};
}
#endif // _XBRepBuilderAPI_MakeShape_HeaderFile
