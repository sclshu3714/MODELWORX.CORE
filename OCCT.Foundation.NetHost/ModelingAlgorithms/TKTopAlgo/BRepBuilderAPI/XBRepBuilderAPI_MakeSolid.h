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

#ifndef _XBRepBuilderAPI_MakeSolid_HeaderFile
#define _XBRepBuilderAPI_MakeSolid_HeaderFile
#pragma once
#include <BRepBuilderAPI_MakeSolid.hxx>
#include <XBRepBuilderAPI_MakeShape.h>
#include <XTopoDS_CompSolid.h>
#include <XTopoDS_Shell.h>
#include <XTopoDS_Solid.h>
#include <XTopoDS_Shape.h>

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <BRepLib_MakeSolid.hxx>
#include <BRepBuilderAPI_MakeShape.hxx>
#include <Standard_Boolean.hxx>
class StdFail_NotDone;



//! Describes functions to build a solid from shells.
//! A solid is made of one shell, or a series of shells, which
//! do not intersect each other. One of these shells
//! constitutes the outside skin of the solid. It may be closed
//! (a finite solid) or open (an infinite solid). Other shells
//! form hollows (cavities) in these previous ones. Each
//! must bound a closed volume.
//! A MakeSolid object provides a framework for:
//! -   defining and implementing the construction of a solid, and
//! -   consulting the result.
//! 
using namespace TKBRep;
namespace TKTopAlgo {
	
	ref class TKBRep::XTopoDS_CompSolid;
	ref class TKBRep::XTopoDS_Shell;
	ref class TKBRep::XTopoDS_Solid;
	ref class TKBRep::XTopoDS_Shape;
	public ref class XBRepBuilderAPI_MakeSolid : public XBRepBuilderAPI_MakeShape
	{
	public:

		//! DEFINE_STANDARD_ALLOC


		//! Initializes the construction of a solid. An empty solid is
		//! considered to cover the whole space. The Add function
		//! is used to define shells to bound it.
		XBRepBuilderAPI_MakeSolid();

		XBRepBuilderAPI_MakeSolid(BRepBuilderAPI_MakeSolid* handle);

		void SetMakeSolidHandle(BRepBuilderAPI_MakeSolid* handle);

		virtual BRepBuilderAPI_MakeShape* GetMakeShape() Standard_OVERRIDE;

		//! Make a solid from a CompSolid.
		XBRepBuilderAPI_MakeSolid(XTopoDS_CompSolid^ S);

		//! Make a solid from a shell.
		XBRepBuilderAPI_MakeSolid(XTopoDS_Shell^ S);

		//! Make a solid from two shells.
		XBRepBuilderAPI_MakeSolid(XTopoDS_Shell^ S1, XTopoDS_Shell^ S2);

		//! Make a solid from three shells.
		//! Constructs a solid
		//! -   covering the whole space, or
		//! -   from shell S, or
		//! -   from two shells S1 and S2, or
		//! -   from three shells S1, S2 and S3, or
		//! Warning
		//! No check is done to verify the conditions of coherence
		//! of the resulting solid. In particular, S1, S2 (and S3) must
		//! not intersect each other.
		//! Besides, after all shells have been added using the Add
		//! function, one of these shells should constitute the outside
		//! skin of the solid; it may be closed (a finite solid) or open
		//! (an infinite solid). Other shells form hollows (cavities) in
		//! these previous ones. Each must bound a closed volume.
		XBRepBuilderAPI_MakeSolid(XTopoDS_Shell^ S1, XTopoDS_Shell^ S2, XTopoDS_Shell^ S3);

		//! Make a solid from a solid. Usefull for adding later.
		XBRepBuilderAPI_MakeSolid(XTopoDS_Solid^ So);

		//! Add a shell to a solid.
		//!
		//! Constructs a solid:
		//! -   from the solid So, to which shells can be added, or
		//! -   by adding the shell S to the solid So.
		//! Warning
		//! No check is done to verify the conditions of coherence
		//! of the resulting solid. In particular S must not intersect the solid S0.
		//! Besides, after all shells have been added using the Add
		//! function, one of these shells should constitute the outside
		//! skin of the solid. It may be closed (a finite solid) or open
		//! (an infinite solid). Other shells form hollows (cavities) in
		//! the previous ones. Each must bound a closed volume.
		XBRepBuilderAPI_MakeSolid(XTopoDS_Solid^ So, XTopoDS_Shell^ S);

		//! Adds the shell to the current solid.
		//! Warning
		//! No check is done to verify the conditions of coherence
		//! of the resulting solid. In particular, S must not intersect
		//! other shells of the solid under construction.
		//! Besides, after all shells have been added, one of
		//! these shells should constitute the outside skin of the
		//! solid. It may be closed (a finite solid) or open (an
		//! infinite solid). Other shells form hollows (cavities) in
		//! these previous ones. Each must bound a closed volume.
		void Add(XTopoDS_Shell^ S);

		//! Returns true if the solid is built.
		//! For this class, a solid under construction is always valid.
		//! If no shell has been added, it could be a whole-space
		//! solid. However, no check was done to verify the
		//! conditions of coherence of the resulting solid.
		virtual Standard_Boolean IsDone() Standard_OVERRIDE;

		//! Returns the new Solid.
		XTopoDS_Solid^ Solid();
		operator XTopoDS_Solid^();

		virtual Standard_Boolean IsDeleted(XTopoDS_Shape^ S) Standard_OVERRIDE;

		/// <summary>
		/// ±¾µØ¾ä±ú
		/// </summary>
		virtual property BRepBuilderAPI_MakeShape* IHandle {
			BRepBuilderAPI_MakeShape* get() Standard_OVERRIDE {
				return NativeHandle;
			}
			void set(BRepBuilderAPI_MakeShape* handle) Standard_OVERRIDE {
				NativeHandle = static_cast<BRepBuilderAPI_MakeSolid*>(handle);
			}
		}

	private:
		BRepBuilderAPI_MakeSolid* NativeHandle;
	};
}
#endif // _XBRepBuilderAPI_MakeSolid_HeaderFile
