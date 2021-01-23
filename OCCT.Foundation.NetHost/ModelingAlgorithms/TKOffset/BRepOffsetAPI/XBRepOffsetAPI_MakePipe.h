// Created on: 1994-07-12
// Created by: Bruno DUMORTIER
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

#ifndef _XBRepOffsetAPI_MakePipe_HeaderFile
#define _XBRepOffsetAPI_MakePipe_HeaderFile
#pragma once
#include <BRepOffsetAPI_MakePipe.hxx>
#include <XBRepPrimAPI_MakeSweep.h>
#include <XTopoDS_Wire.h>
#include <XTopoDS_Shape.h>
#include <XBRepFill_Pipe.h>
#include <XTopTools_ListOfShape.h>

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <BRepFill_Pipe.hxx>
#include <BRepPrimAPI_MakeSweep.hxx>
#include <GeomFill_Trihedron.hxx>
#include <Standard_Boolean.hxx>
#include <Standard_Real.hxx>
class TopoDS_Wire;
class TopoDS_Shape;
class BRepFill_Pipe;

using namespace TKPrim;
using namespace TKBRep;
using namespace TKBool;
namespace TKOffset {
	ref class TKBRep::XTopoDS_Wire;
	ref class TKBRep::XTopoDS_Shape;
	ref class TKBRep::XTopTools_ListOfShape;
	ref class TKBool::XBRepFill_Pipe;
	//! Describes functions to build pipes.
	//! A pipe is built a basis shape (called the profile) along
	//! a wire (called the spine) by sweeping.
	//! The profile must not contain solids.
	//! A MakePipe object provides a framework for:
	//! - defining the construction of a pipe,
	//! - implementing the construction algorithm, and
	//! - consulting the result.
	//! Warning
	//! The MakePipe class implements pipe constructions
	//! with G1 continuous spines only.
	public ref class XBRepOffsetAPI_MakePipe : public XBRepPrimAPI_MakeSweep
	{
	public:
		!XBRepOffsetAPI_MakePipe() { IHandle = NULL; };
		~XBRepOffsetAPI_MakePipe() { IHandle = NULL; };
		//DEFINE_STANDARD_ALLOC
		XBRepOffsetAPI_MakePipe();

		XBRepOffsetAPI_MakePipe(BRepOffsetAPI_MakePipe* pos);

		void SetMakePipeHandle(BRepOffsetAPI_MakePipe* pos);

		virtual BRepOffsetAPI_MakePipe* GetMakePipe();

		virtual BRepPrimAPI_MakeSweep* GetMakeSweep() Standard_OVERRIDE;

		virtual BRepBuilderAPI_MakeShape* GetMakeShape() Standard_OVERRIDE;

		virtual XTopoDS_Shape^ Shape() Standard_OVERRIDE;

		//! Constructs a pipe by sweeping the shape Profile along
		//! the wire Spine.The angle made by the spine with the profile is
		//! maintained along the length of the pipe.
		//! Warning
		//! Spine must be G1 continuous; that is, on the connection
		//! vertex of two edges of the wire, the tangent vectors on
		//! the left and on the right must have the same direction,
		//! though not necessarily the same magnitude.
		//! Exceptions
		//! Standard_DomainError if the profile is a solid or a
		//! composite solid.
		XBRepOffsetAPI_MakePipe(XTopoDS_Wire^ Spine, XTopoDS_Shape^ Profile);

		//! the same as previous but with setting of
		//! mode of sweep and the flag that indicates attempt
		//! to approximate a C1-continuous surface if a swept
		//! surface proved to be C0.
		//! const Standard_Boolean ForceApproxC1 = Standard_False
		XBRepOffsetAPI_MakePipe(XTopoDS_Wire^ Spine, XTopoDS_Shape^ Profile, XGeomFill_Trihedron aMode, Standard_Boolean ForceApproxC1);

		XBRepFill_Pipe^ Pipe();

		//! Builds the resulting shape (redefined from MakeShape).
		virtual void Build() Standard_OVERRIDE;

		//! Returns the  TopoDS  Shape of the bottom of the prism.
		XTopoDS_Shape^ FirstShape() Standard_OVERRIDE;

		//! Returns the TopoDS Shape of the top of the prism.
		XTopoDS_Shape^ LastShape() Standard_OVERRIDE;

		virtual XTopTools_ListOfShape^ Generated(XTopoDS_Shape^ S) Standard_OVERRIDE;

		XTopoDS_Shape^ Generated(XTopoDS_Shape^ SSpine, XTopoDS_Shape^ SProfile);

		Standard_Real ErrorOnSurface();

		/// <summary>
		/// ±¾µØ¾ä±ú
		/// </summary>
		virtual property BRepBuilderAPI_MakeShape* IHandle {
			BRepBuilderAPI_MakeShape* get() Standard_OVERRIDE {
				return NativeHandle;
			}
			void set(BRepBuilderAPI_MakeShape* handle) Standard_OVERRIDE {
				NativeHandle = static_cast<BRepOffsetAPI_MakePipe*>(handle);
			}
		}

	private:
		BRepOffsetAPI_MakePipe* NativeHandle;
	};
}
#endif // _XBRepOffsetAPI_MakePipe_HeaderFile
