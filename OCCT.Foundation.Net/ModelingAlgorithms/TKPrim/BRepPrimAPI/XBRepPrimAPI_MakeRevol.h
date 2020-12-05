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

#ifndef _XBRepPrimAPI_MakeRevol_HeaderFile
#define _XBRepPrimAPI_MakeRevol_HeaderFile

#pragma once
#include <XTopoDS_Shape.h>
#include <BRepPrimAPI_MakeRevol.hxx>
#include <TopoDS_Shape.hxx>
#include <XBRepPrimAPI_MakeSweep.h>
#include <XBRepSweep_Revol.h>
#include <xgp_Vec2d.h>

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <BRepSweep_Revol.hxx>
#include <TopTools_ListOfShape.hxx>
#include <BRepPrimAPI_MakeSweep.hxx>
#include <BRepTools_History.hxx>
#include <Standard_Real.hxx>
#include <Standard_Boolean.hxx>
class TopoDS_Shape;



//! Class to make revolved sweep topologies.
//!
//! a revolved sweep is defined by :
//!
//! * A basis topology which is swept.
//!
//! The   basis topology  must   not  contain solids
//! (neither composite solids.).
//!
//! The basis topology  may be copied  or  shared in
//! the result.
//!
//! * A rotation axis and angle :
//!
//! - The axis is an Ax1 from gp.
//!
//! - The angle is in [0, 2*Pi].
//!
//! - The angle default value is 2*Pi.
//!
//! The result is a topology with a higher dimension :
//!
//! - Vertex -> Edge.
//! - Edge   -> Face.
//! - Wire   -> Shell.
//! - Face   -> Solid.
//! - Shell  -> CompSolid.
//!
//! Sweeping a Compound sweeps  the elements  of the
//! compound  and creates    a  compound with    the
//! results.
//! 
using namespace TKMath;
namespace TKPrim {
	ref class XBRepSweep_Revol;
	ref class TKMath::xgp_Ax1;
	ref class TKMath::xgp_Vec2d;
	public ref class XBRepPrimAPI_MakeRevol : public XBRepPrimAPI_MakeSweep
	{
	public:

		//! DEFINE_STANDARD_ALLOC

		XBRepPrimAPI_MakeRevol();

		XBRepPrimAPI_MakeRevol(BRepPrimAPI_MakeRevol* pos);

		void SetMakeRevolHandle(BRepPrimAPI_MakeRevol* pos);

		virtual BRepPrimAPI_MakeRevol* GetMakeRevol();

		virtual BRepPrimAPI_MakeSweep* GetMakeSweep() Standard_OVERRIDE;

		virtual BRepBuilderAPI_MakeShape* GetMakeShape() Standard_OVERRIDE;

		virtual XTopoDS_Shape^ Shape() Standard_OVERRIDE;

		//! Builds the Revol of base S, axis  A and angle  D. If C
		//! is true, S is copied.
		//! Standard_Boolean Copy = Standard_False
		XBRepPrimAPI_MakeRevol(XTopoDS_Shape^ S, xgp_Ax1^ A, Standard_Real D, Standard_Boolean );

		//! Builds the Revol of base S, axis  A and angle 2*Pi. If
		//! C is true, S is copied.
		//! Standard_Boolean Copy = Standard_False
		XBRepPrimAPI_MakeRevol(XTopoDS_Shape^ S, xgp_Ax1^ A, Standard_Boolean Copy);

		//! Returns the internal sweeping algorithm.
		XBRepSweep_Revol^ Revol();

		//! Builds the resulting shape (redefined from MakeShape).
		virtual void Build() Standard_OVERRIDE;

		//! Returns the first shape of the revol  (coinciding with
		//! the generating shape).
		XTopoDS_Shape^ FirstShape() Standard_OVERRIDE;

		//! Returns the TopoDS Shape of the end of the revol.
		XTopoDS_Shape^ LastShape() Standard_OVERRIDE;

		//! Returns list of shape generated from shape S
		//! Warning: shape S must be shape of type VERTEX, EDGE, FACE, SOLID.
		//! For shapes of other types method always returns empty list
		virtual XTopTools_ListOfShape^ Generated(XTopoDS_Shape^ S) Standard_OVERRIDE;

		//! Returns true if the shape S has been deleted.
		virtual Standard_Boolean IsDeleted(XTopoDS_Shape^ S) Standard_OVERRIDE;


		//! Returns the TopoDS Shape of the beginning of the revolution,
		//! generated with theShape  (subShape of the generating shape).
		XTopoDS_Shape^ FirstShape(XTopoDS_Shape^ theShape);

		//! Returns the TopoDS Shape of the end of the revolution,
		//! generated with  theShape (subShape of the  generating shape).
		XTopoDS_Shape^ LastShape(XTopoDS_Shape^ theShape);

		//! Check if there are degenerated edges in the result.
		Standard_Boolean HasDegenerated();

		//! Returns the list of degenerated edges
		XTopTools_ListOfShape^ Degenerated();

		/// <summary>
		/// ±¾µØ¾ä±ú
		/// </summary>
		virtual property BRepBuilderAPI_MakeShape* IHandle {
			BRepBuilderAPI_MakeShape* get() Standard_OVERRIDE {
				return NativeHandle;
			}
			void set(BRepBuilderAPI_MakeShape* handle) Standard_OVERRIDE {
				NativeHandle = static_cast<BRepPrimAPI_MakeRevol*>(handle);
			}
		}

	private:
		BRepPrimAPI_MakeRevol* NativeHandle;
	};
}
#endif // _XBRepPrimAPI_MakeRevol_HeaderFile
