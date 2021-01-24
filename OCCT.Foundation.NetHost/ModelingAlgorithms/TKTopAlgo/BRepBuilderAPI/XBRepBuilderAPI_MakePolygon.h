// Created on: 1993-07-29
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

#ifndef _XBRepBuilderAPI_MakePolygon_HeaderFile
#define _XBRepBuilderAPI_MakePolygon_HeaderFile
#pragma once
#include <BRepBuilderAPI_MakePolygon.hxx>
#include <XBRepBuilderAPI_MakeShape.h>
#include <XTopoDS_Vertex.h>
#include <XTopoDS_Edge.h>
#include <XTopoDS_Wire.h>
#include <xgp_Pnt.h>

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <BRepLib_MakePolygon.hxx>
#include <BRepBuilderAPI_MakeShape.hxx>
#include <Standard_Boolean.hxx>
class StdFail_NotDone;
class gp_Pnt;
class TopoDS_Vertex;
class TopoDS_Edge;
class TopoDS_Wire;

using namespace TKMath;
using namespace TKBRep;
namespace TKTopAlgo {
	ref class TKMath::xgp_Pnt;
	ref class TKBRep::XTopoDS_Vertex;
	ref class TKBRep::XTopoDS_Edge;
	ref class TKBRep::XTopoDS_Wire;
	//! Describes functions to build polygonal wires. A
	//! polygonal wire can be built from any number of points
	//! or vertices, and consists of a sequence of connected
	//! rectilinear edges.
	//! When a point or vertex is added to the  polygon if
	//! it is identic  to the previous  point no  edge  is
	//! built. The method added can be used to test it.
	//! Construction of a Polygonal Wire
	//! You canruct:
	//! -   a complete polygonal wire by defining all its points
	//! or vertices (limited to four), or
	//! -   an empty polygonal wire and add its points or
	//! vertices in sequence (unlimited number).
	//! A MakePolygon object provides a framework for:
	//! -   initializing theruction of a polygonal wire,
	//! -   adding points or vertices to the polygonal wire underruction, and
	//! -   consulting the result.
	public ref class XBRepBuilderAPI_MakePolygon : public XBRepBuilderAPI_MakeShape
	{
	public:

		//! DEFINE_STANDARD_ALLOC
		!XBRepBuilderAPI_MakePolygon() { IHandle = NULL; };
		~XBRepBuilderAPI_MakePolygon() { IHandle = NULL; };

		//! Initializes an empty polygonal wire, to which points or
		//! vertices are added using the Add function.
		//! As soon as the polygonal wire underruction
		//! contains vertices, it can be consulted using the Wire function.
		XBRepBuilderAPI_MakePolygon();

		XBRepBuilderAPI_MakePolygon(BRepBuilderAPI_MakePolygon* handle);

		void SetMakePolygonHandle(BRepBuilderAPI_MakePolygon* handle);

		virtual BRepBuilderAPI_MakePolygon* GetMakePolygon();

		virtual BRepBuilderAPI_MakeShape* GetMakeShape() Standard_OVERRIDE;

		XBRepBuilderAPI_MakePolygon(xgp_Pnt^ P1, xgp_Pnt^ P2);

		//! Standard_Boolean Close = Standard_False
		XBRepBuilderAPI_MakePolygon(xgp_Pnt^ P1, xgp_Pnt^ P2, xgp_Pnt^ P3, Standard_Boolean Close);

		//! Constructs a polygonal wire from 2, 3 or 4 points. Vertices are
		//! automatically created on the given points. The polygonal wire is
		//! closed if Close is true; otherwise it is open. Further vertices can
		//! be added using the Add function. The polygonal wire under
		//!ruction can be consulted at any time by using the Wire function.
		//! Example
		//! //an open polygon from four points
		//! TopoDS_Wire W = BRepBuilderAPI_MakePolygon(P1,P2,P3,P4);
		//! Warning: The process is equivalent to:
		//! - initializing an empty polygonal wire,
		//! - and adding the given points in sequence.
		//! Consequently, be careful when using this function: if the
		//! sequence of points p1 - p2 - p1 is found among the arguments of the
		//!ructor, you will create a polygonal wire with two
		//! consecutive coincident edges.
		//! Standard_Boolean Close = Standard_False
		XBRepBuilderAPI_MakePolygon(xgp_Pnt^ P1, xgp_Pnt^ P2, xgp_Pnt^ P3, xgp_Pnt^ P4, Standard_Boolean Close);

		XBRepBuilderAPI_MakePolygon(XTopoDS_Vertex^ V1, XTopoDS_Vertex^ V2);

		//! Standard_Boolean Close = Standard_False
		XBRepBuilderAPI_MakePolygon(XTopoDS_Vertex^ V1, XTopoDS_Vertex^ V2, XTopoDS_Vertex^ V3, Standard_Boolean Close);

		//! Constructs a polygonal wire from
		//! 2, 3 or 4 vertices. The polygonal wire is closed if Close is true;
		//! otherwise it is open (default value). Further vertices can be
		//! added using the Add function. The polygonal wire under
		//!ruction can be consulted at any time by using the Wire function.
		//! Example
		//! //a closed triangle from three vertices
		//! TopoDS_Wire W = BRepBuilderAPI_MakePolygon(V1,V2,V3,Standard_True);
		//! Warning
		//! The process is equivalent to:
		//! -      initializing an empty polygonal wire,
		//! -      then adding the given points in sequence.
		//! So be careful, as when using this function, you could create a
		//! polygonal wire with two consecutive coincident edges if
		//! the sequence of vertices v1 - v2 - v1 is found among the
		//!ructor's arguments.
		//! Standard_Boolean Close = Standard_False
		XBRepBuilderAPI_MakePolygon(XTopoDS_Vertex^ V1, XTopoDS_Vertex^ V2, XTopoDS_Vertex^ V3, XTopoDS_Vertex^ V4, Standard_Boolean Close);

		void Add(xgp_Pnt^ P);


		//! Adds the point P or the vertex V at the end of the
		//! polygonal wire underruction. A vertex is
		//! automatically created on the point P.
		//! Warning
		//! -   When P or V is coincident to the previous vertex,
		//! no edge is built. The method Added can be used to
		//! test for this. Neither P nor V is checked to verify
		//! that it is coincident with another vertex than the last
		//! one, of the polygonal wire underruction. It is
		//! also possible to add vertices on a closed polygon
		//! (built for example by using aructor which
		//! declares the polygon closed, or after the use of the Close function).
		//! Consequently, be careful using this function: you might create:
		//! -      a polygonal wire with two consecutive coincident edges, or
		//! -      a non manifold polygonal wire.
		//! -      P or V is not checked to verify if it is
		//! coincident with another vertex but the last one, of
		//! the polygonal wire underruction. It is also
		//! possible to add vertices on a closed polygon (built
		//! for example by using aructor which declares
		//! the polygon closed, or after the use of the Close function).
		//! Consequently, be careful when using this function: you might create:
		//! -   a polygonal wire with two consecutive coincident edges, or
		//! -   a non-manifold polygonal wire.
		void Add(XTopoDS_Vertex^ V);

		//! Returns true if the last vertex added to theructed
		//! polygonal wire is not coincident with the previous one.
		Standard_Boolean Added();

		//! Closes the polygonal wire underruction. Note - this
		//! is equivalent to adding the first vertex to the polygonal
		//! wire underruction.
		void Close();

		XTopoDS_Vertex^ FirstVertex();

		//! Returns the first or the last vertex of the polygonal wire underruction.
		//! If theructed polygonal wire is closed, the first and the last vertices are identical.
		XTopoDS_Vertex^ LastVertex();


		//! Returns true if this algorithm contains a valid polygonal
		//! wire (i.e. if there is at least one edge).
		//! IsDone returns false if fewer than two vertices have
		//! been chained together by thisruction algorithm.
		virtual Standard_Boolean IsDone() Standard_OVERRIDE;

		//! Returns the edge built between the last two points or
		//! vertices added to theructed polygonal wire underruction.
		//! Warning
		//! If there is only one vertex in the polygonal wire, the result is a null edge.
		XTopoDS_Edge^ Edge();
		operator XTopoDS_Edge^();


		//! Returns theructed polygonal wire, or the already
		//! built part of the polygonal wire underruction.
		//! Exceptions
		//! StdFail_NotDone if the wire is not built, i.e. if fewer than
		//! two vertices have been chained together by thisruction algorithm.
		XTopoDS_Wire^ Wire();
		operator XTopoDS_Wire^();

		/// <summary>
		/// ±¾µØ¾ä±ú
		/// </summary>
		virtual property BRepBuilderAPI_MakeShape* IHandle {
			BRepBuilderAPI_MakeShape* get() Standard_OVERRIDE {
				return NativeHandle;
			}
			void set(BRepBuilderAPI_MakeShape* handle) Standard_OVERRIDE {
				//NativeHandle = static_cast<BRepBuilderAPI_MakePolygon*>(handle);
				if (handle == NULL)
					NativeHandle = static_cast<BRepBuilderAPI_MakePolygon*>(handle);
				else
					NativeHandle = NULL;
			}
		}

	private:
		BRepBuilderAPI_MakePolygon* NativeHandle;
	};
}
#endif // _XBRepBuilderAPI_MakePolygon_HeaderFile
