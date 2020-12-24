// Created on: 1993-07-08
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

#ifndef _XBRepBuilderAPI_MakeWire_HeaderFile
#define _XBRepBuilderAPI_MakeWire_HeaderFile
#pragma once
#include <XBRepBuilderAPI_MakeShape.h>
#include <BRepBuilderAPI_MakeWire.hxx>
#include <XTopTools_ListOfShape.h>
#include <XTopoDS_Edge.h>
#include <XTopoDS_Wire.h>
#include <XTopoDS_Vertex.h>


#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <BRepLib_MakeWire.hxx>
#include <BRepBuilderAPI_MakeShape.hxx>
#include <TopTools_ListOfShape.hxx>
#include <Standard_Boolean.hxx>
#include <BRepBuilderAPI_WireError.hxx>
#include <gp_Dir2d.hxx>
class gp_Dir2d;
class StdFail_NotDone;
class TopoDS_Edge;
class TopoDS_Wire;
class TopoDS_Vertex;


//! Describes functions to build wires from edges. A wire can
//! be built from any number of edges.
//! To build a wire you first initialize the construction, then
//! add edges in sequence. An unlimited number of edges
//! can be added. The initialization of construction is done with:
//! -   no edge (an empty wire), or
//! -   edges of an existing wire, or
//! -   up to four connectable edges.
//! In order to be added to a wire under construction, an
//! edge (unless it is the first one) must satisfy the following
//! condition: one of its vertices must be geometrically
//! coincident with one of the vertices of the wire (provided
//! that the highest tolerance factor is assigned to the two
//! vertices). It could also be the same vertex.
//! -   The given edge is shared by the wire if it contains:
//! -   two vertices, identical to two vertices of the wire
//! under construction (a general case of the wire closure), or
//! -   one vertex, identical to a vertex of the wire under
//! construction; the other vertex not being
//! geometrically coincident with another vertex of the wire.
//! -   In other cases, when one of the vertices of the edge
//! is simply geometrically coincident with a vertex of the
//! wire under construction (provided that the highest
//! tolerance factor is assigned to the two vertices), the
//! given edge is first copied and the coincident vertex is
//! replaced in this new edge, by the coincident vertex of the wire.
//! Note: it is possible to build non manifold wires using this construction tool.
//! A MakeWire object provides a framework for:
//! -   initializing the construction of a wire,
//! -   adding edges to the wire under construction, and
//! -   consulting the result.
//! 
using namespace TKBRep;
namespace TKTopAlgo {
	ref class TKBRep::XTopTools_ListOfShape;
	public ref class XBRepBuilderAPI_MakeWire : public XBRepBuilderAPI_MakeShape
	{
	public:

		//!DEFINE_STANDARD_ALLOC

		
		//! Constructs an empty wire framework, to which edges
		//! are added using the Add function.
		//! As soon as the wire contains one edge, it can return
		//! with the use of the function Wire.
		//! Warning
		//! The function Error will return
		//! BRepBuilderAPI_EmptyWire if it is called before at
		//! least one edge is added to the wire under construction.
		XBRepBuilderAPI_MakeWire();

		XBRepBuilderAPI_MakeWire(BRepBuilderAPI_MakeWire* pos);

		//! Make a Wire from an edge.
		XBRepBuilderAPI_MakeWire(XTopoDS_Edge^ E);

		//! Make a Wire from two edges.
		XBRepBuilderAPI_MakeWire(XTopoDS_Edge^ E1, XTopoDS_Edge^ E2);

		//! Make a Wire from three edges.
		XBRepBuilderAPI_MakeWire(XTopoDS_Edge^ E1, XTopoDS_Edge^ E2, XTopoDS_Edge^ E3);

		//! Make a Wire from four edges.
		//! Constructs a wire
		//! -   from the TopoDS_Wire W composed of the edge E, or
		//! -   from edge E, or
		//! -   from two edges E1 and E2, or
		//! -   from three edges E1, E2 and E3, or
		//! -   from four edges E1, E2, E3 and E4.
		//! Further edges can be added using the function Add.
		//! Given edges are added in a sequence. Each of them
		//! must be connectable to the wire under construction,
		//! and so must satisfy the following condition (unless it is
		//! the first edge of the wire): one of its vertices must be
		//! geometrically coincident with one of the vertices of the
		//! wire (provided that the highest tolerance factor is
		//! assigned to the two vertices). It could also be the same vertex.
		//! Warning
		//! If an edge is not connectable to the wire under
		//! construction it is not added. The function Error will
		//! return BRepBuilderAPI_DisconnectedWire, the
		//! function IsDone will return false and the function Wire
		//! will raise an error, until a new connectable edge is added.
		XBRepBuilderAPI_MakeWire(XTopoDS_Edge^ E1, XTopoDS_Edge^ E2, XTopoDS_Edge^ E3, XTopoDS_Edge^ E4);

		//! Make a Wire from a Wire. Usefull for adding later.
		XBRepBuilderAPI_MakeWire(XTopoDS_Wire^ W);

		//! Add an edge to a wire.
		XBRepBuilderAPI_MakeWire(XTopoDS_Wire^ W, XTopoDS_Edge^ E);

		//! Adds the edge E to the wire under construction.
		//! E must be connectable to the wire under construction, and, unless it
		//! is the first edge of the wire, must satisfy the following
		//! condition: one of its vertices must be geometrically coincident
		//! with one of the vertices of the wire (provided that the highest
		//! tolerance factor is assigned to the two vertices). It could also
		//! be the same vertex.
		//! Warning
		//! If E is not connectable to the wire under construction it is not
		//! added. The function Error will return
		//! BRepBuilderAPI_DisconnectedWire, the function IsDone will return
		//! false and the function Wire will raise an error, until a new
		//! connectable edge is added.
		void Add(XTopoDS_Edge^ E);

		//! Add the edges of <W> to the current wire.
		void Add(XTopoDS_Wire^ W);

		//! Adds  the edges of <L>   to the current  wire.  The
		//! edges are not to be consecutive.   But they are to
		//! be  all  connected geometrically or topologically.
		//! If some of them are  not connected the Status give
		//! DisconnectedWire but the "Maker" is Done() and you
		//! can get the  partial result. (ie connected to  the
		//! first edgeof the list <L>)
		void Add(XTopTools_ListOfShape^ L);

		//! Returns true if this algorithm contains a valid wire.
		//! IsDone returns false if:
		//! -   there are no edges in the wire, or
		//! -   the last edge which you tried to add was not connectable.
		virtual Standard_Boolean IsDone() Standard_OVERRIDE;

		//! Returns the construction status
		//! -   BRepBuilderAPI_WireDone if the wire is built, or
		//! -   another value of the BRepBuilderAPI_WireError
		//! enumeration indicating why the construction failed.
		BRepBuilderAPI_WireError Error();

		//! Returns the constructed wire; or the part of the wire
		//! under construction already built.
		//! Exceptions StdFail_NotDone if a wire is not built.
		XTopoDS_Wire^ Wire();
		operator XTopoDS_Wire^();

		//! Returns the last edge added to the wire under construction.
		//! Warning
		//! -   This edge can be different from the original one (the
		//! argument of the function Add, for instance,)
		//! -   A null edge is returned if there are no edges in the
		//! wire under construction, or if the last edge which you
		//! tried to add was not connectable..
		XTopoDS_Edge^ Edge();


		virtual XTopoDS_Shape^ Shape() Standard_OVERRIDE;
		//! Returns the last vertex of the last edge added to the
		//! wire under construction.
		//! Warning
		//! A null vertex is returned if there are no edges in the wire
		//! under construction, or if the last edge which you tried to
		//! add was not connectableR
		XTopoDS_Vertex^ Vertex();

		virtual BRepBuilderAPI_MakeWire* GetMakeWire();

		virtual BRepBuilderAPI_MakeShape* GetMakeShape() Standard_OVERRIDE;

		/// <summary>
		/// ���ؾ��
		/// </summary>
		virtual property BRepBuilderAPI_MakeShape* IHandle {
			BRepBuilderAPI_MakeShape* get() Standard_OVERRIDE {
				return NativeHandle;
			}
			void set(BRepBuilderAPI_MakeShape* handle) Standard_OVERRIDE {
				NativeHandle = static_cast<BRepBuilderAPI_MakeWire*>(handle);
			}
		}

	private:
		BRepBuilderAPI_MakeWire* NativeHandle;
	};
}
#endif // _XBRepBuilderAPI_MakeWire_HeaderFile
