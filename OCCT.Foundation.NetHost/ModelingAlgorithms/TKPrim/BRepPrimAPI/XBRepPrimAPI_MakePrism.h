// Created on: 1993-10-12
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

#ifndef _XBRepPrimAPI_MakePrism_HeaderFile
#define _XBRepPrimAPI_MakePrism_HeaderFile
#pragma once
#include <BRepPrimAPI_MakePrism.hxx>
#include <XBRepPrimAPI_MakeSweep.h>
#include <XTopoDS_Shape.h>
#include <xgp_Vec.h>
#include <xgp_Dir.h>
#include <xgp_Vec2d.h>

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <BRepSweep_Prism.hxx>
#include <BRepPrimAPI_MakeSweep.hxx>
#include <Standard_Boolean.hxx>
#include <TopTools_ListOfShape.hxx>
class BRepSweep_Prism;


//! Describes functions to build linear swept topologies, called prisms.
//! A prism is defined by:
//! -   a basis shape, which is swept, and
//! -   a sweeping direction, which is:
//! -   a vector for finite prisms, or
//! -   a direction for infinite or semi-infinite prisms.
//! The basis shape must not contain any solids.
//! The profile generates objects according to the following rules:
//! -   Vertices generate Edges
//! -   Edges generate Faces.
//! -   Wires generate Shells.
//! -   Faces generate Solids.
//! -   Shells generate Composite Solids
//! A MakePrism object provides a framework for:
//! -   defining the construction of a prism,
//! -   implementing the construction algorithm, and
//! -   consulting the result.
//! 
using namespace TKMath;
using namespace TKBRep;
namespace TKPrim {
	ref class TKBRep::XTopoDS_Shape;
	ref class TKMath::xgp_Vec;
	ref class TKMath::xgp_Dir;
	ref class TKMath::xgp_Vec2d;
	ref class XBRepPrimAPI_MakeSweep;
	public ref class XBRepPrimAPI_MakePrism : public XBRepPrimAPI_MakeSweep
	{
	public:

		//!	DEFINE_STANDARD_ALLOC

		!XBRepPrimAPI_MakePrism() { IHandle = NULL; };
		~XBRepPrimAPI_MakePrism() { IHandle = NULL; };

		void SetMakePrismHandle(BRepPrimAPI_MakePrism* pos);

		virtual BRepPrimAPI_MakePrism* GetMakePrism();

		virtual BRepPrimAPI_MakeSweep* GetMakeSweep() Standard_OVERRIDE;

		virtual BRepBuilderAPI_MakeShape* GetMakeShape() Standard_OVERRIDE;

		virtual XTopoDS_Shape^ Shape() Standard_OVERRIDE;

		//! Builds the prism of base S and vector V. If C is true,
		//! S is copied. If Canonize is true then generated surfaces
		//! are attempted to be canonized in simple types
		//! const Standard_Boolean Copy = Standard_False, const Standard_Boolean Canonize = Standard_True
		XBRepPrimAPI_MakePrism(XTopoDS_Shape^ S, xgp_Vec^ V, Standard_Boolean Copy, Standard_Boolean Canonize);

		//! Builds a semi-infinite or an infinite prism of base S.
		//! If Inf is true the prism  is infinite, if Inf is false
		//! the prism is semi-infinite (in the direction D).  If C
		//! is true S is copied (for semi-infinite prisms).
		//! If Canonize is true then generated surfaces
		//! are attempted to be canonized in simple types
		//!  const Standard_Boolean Inf = Standard_True, const Standard_Boolean Copy = Standard_False, const Standard_Boolean Canonize = Standard_True
		XBRepPrimAPI_MakePrism(XTopoDS_Shape^ S, xgp_Dir^ D, Standard_Boolean Inf, Standard_Boolean Copy, Standard_Boolean Canonize);

		//! Returns the internal sweeping algorithm.
		BRepSweep_Prism Prism();

		//! Builds the resulting shape (redefined from MakeShape).
		virtual void Build() Standard_OVERRIDE;

		//! Returns the  TopoDS  Shape of the bottom of the prism.
		XTopoDS_Shape^ FirstShape() Standard_OVERRIDE;

		//! Returns the TopoDS Shape of the top of the prism.
		//! In the case of a finite prism, FirstShape returns the
		//! basis of the prism, in other words, S if Copy is false;
		//! otherwise, the copy of S belonging to the prism.
		//! LastShape returns the copy of S translated by V at the
		//! time of construction.
		XTopoDS_Shape^ LastShape() Standard_OVERRIDE;

		//! Returns ListOfShape from TopTools.
		virtual XTopTools_ListOfShape^ Generated(XTopoDS_Shape^ S) Standard_OVERRIDE;

		//! Returns true if the shape S has been deleted.
		virtual Standard_Boolean IsDeleted(XTopoDS_Shape^ S) Standard_OVERRIDE;

		//! Returns the TopoDS Shape of the bottom  of the  prism.
		//! generated  with  theShape (subShape of the  generating shape).
		XTopoDS_Shape^ FirstShape(XTopoDS_Shape^ theShape);

		//! Returns the  TopoDS  Shape of the top  of  the  prism.
		//! generated  with  theShape (subShape of the  generating shape).
		XTopoDS_Shape^ LastShape(XTopoDS_Shape^ theShape);

		/// <summary>
		/// ±¾µØ¾ä±ú
		/// </summary>
		virtual property BRepBuilderAPI_MakeShape* IHandle {
			BRepBuilderAPI_MakeShape* get() Standard_OVERRIDE {
				return NativeHandle;
			}
			void set(BRepBuilderAPI_MakeShape* handle) Standard_OVERRIDE {
				NativeHandle = static_cast<BRepPrimAPI_MakePrism*>(handle);
			}
		}

	private:
		BRepPrimAPI_MakePrism* NativeHandle;
	};
}
#endif // _XBRepPrimAPI_MakePrism_HeaderFile
