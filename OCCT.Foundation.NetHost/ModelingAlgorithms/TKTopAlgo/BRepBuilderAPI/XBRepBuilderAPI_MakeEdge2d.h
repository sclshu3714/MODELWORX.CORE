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

#ifndef _XBRepBuilderAPI_MakeEdge2d_HeaderFile
#define _XBRepBuilderAPI_MakeEdge2d_HeaderFile
#pragma once
#include <BRepBuilderAPI_MakeEdge2d.hxx>
#include <XBRepBuilderAPI_MakeShape.h>
#include <xgp_Pnt2d.h>
#include <xgp_Lin2d.h>
#include <xgp_Circ2d.h>
#include <xgp_Elips2d.h>
#include <xgp_Hypr2d.h>
#include <xgp_Parab2d.h>
#include <XTopoDS_Edge.h>
#include <XTopoDS_Vertex.h>
#include <XGeom2d_Curve.h>

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <BRepLib_MakeEdge2d.hxx>
#include <BRepBuilderAPI_MakeShape.hxx>
#include <Standard_Real.hxx>
#include <Standard_Boolean.hxx>
#include <BRepBuilderAPI_EdgeError.hxx>
#include <XBRepBuilderAPI_EdgeError.h>
class StdFail_NotDone;
class gp_Pnt2d;
class gp_Lin2d;
class gp_Circ2d;
class gp_Elips2d;
class gp_Hypr2d;
class gp_Parab2d;
class TopoDS_Edge;
class TopoDS_Vertex;
class Geom2d_Curve;

using namespace TKMath;
using namespace TKBRep;
using namespace TKG2d;
namespace TKTopAlgo {
	ref class TKMath::xgp_Pnt2d;
	ref class TKMath::xgp_Lin2d;
	ref class TKMath::xgp_Circ2d;
	ref class TKMath::xgp_Elips2d;
	ref class TKMath::xgp_Hypr2d;
	ref class TKMath::xgp_Parab2d;
	ref class TKBRep::XTopoDS_Edge;
	ref class TKBRep::XTopoDS_Vertex;
	ref class TKG2d::XGeom2d_Curve;
	//! Provides methods to build edges.
	//!
	//! The   methods have  the  following   syntax, where
	//! TheCurve is one of Lin2d, Circ2d, ...
	//!
	//! Create(C : TheCurve)
	//!
	//! Makes an edge on  the whole curve.  Add vertices
	//! on finite curves.
	//!
	//! Create(C : TheCurve; p1,p2 : Real)
	//!
	//! Make an edge  on the curve between parameters p1
	//! and p2. if p2 < p1 the edge will be REVERSED. If
	//! p1  or p2 is infinite the  curve will be open in
	//! that  direction. Vertices are created for finite
	//! values of p1 and p2.
	//!
	//! Create(C : TheCurve; P1, P2 : Pnt2d from gp)
	//!
	//! Make an edge on the curve  between the points P1
	//! and P2. The  points are projected on   the curve
	//! and the   previous method is  used. An  error is
	//! raised if the points are not on the curve.
	//!
	//! Create(C : TheCurve; V1, V2 : Vertex from TopoDS)
	//!
	//! Make an edge  on the curve  between the vertices
	//! V1 and V2. Same as the  previous but no vertices
	//! are created. If a vertex is  Null the curve will
	//! be open in this direction.
	public ref class XBRepBuilderAPI_MakeEdge2d : public XBRepBuilderAPI_MakeShape
	{
	public:

		!XBRepBuilderAPI_MakeEdge2d() { IHandle = NULL; };
		~XBRepBuilderAPI_MakeEdge2d() { IHandle = NULL; };
		//! DEFINE_STANDARD_ALLOC
		XBRepBuilderAPI_MakeEdge2d();

		void SetMakeEdge2dHandle(BRepBuilderAPI_MakeEdge2d* handle);

		virtual BRepBuilderAPI_MakeEdge2d* GetMakeEdge2d();

		virtual BRepBuilderAPI_MakeShape* GetMakeShape() Standard_OVERRIDE;

		XBRepBuilderAPI_MakeEdge2d(XTopoDS_Vertex^ V1, XTopoDS_Vertex^ V2);

		XBRepBuilderAPI_MakeEdge2d(xgp_Pnt2d^ P1, xgp_Pnt2d^ P2);

		XBRepBuilderAPI_MakeEdge2d(xgp_Lin2d^ L);

		XBRepBuilderAPI_MakeEdge2d(xgp_Lin2d^ L, Standard_Real p1, Standard_Real p2);

		XBRepBuilderAPI_MakeEdge2d(xgp_Lin2d^ L, xgp_Pnt2d^ P1, xgp_Pnt2d^ P2);

		XBRepBuilderAPI_MakeEdge2d(xgp_Lin2d^ L, XTopoDS_Vertex^ V1, XTopoDS_Vertex^ V2);

		XBRepBuilderAPI_MakeEdge2d(xgp_Circ2d^ L);

		XBRepBuilderAPI_MakeEdge2d(xgp_Circ2d^ L, Standard_Real p1, Standard_Real p2);

		XBRepBuilderAPI_MakeEdge2d(xgp_Circ2d^ L, xgp_Pnt2d^ P1, xgp_Pnt2d^ P2);

		XBRepBuilderAPI_MakeEdge2d(xgp_Circ2d^ L, XTopoDS_Vertex^ V1, XTopoDS_Vertex^ V2);

		XBRepBuilderAPI_MakeEdge2d(xgp_Elips2d^ L);

		XBRepBuilderAPI_MakeEdge2d(xgp_Elips2d^ L, Standard_Real p1, Standard_Real p2);

		XBRepBuilderAPI_MakeEdge2d(xgp_Elips2d^ L, xgp_Pnt2d^ P1, xgp_Pnt2d^ P2);

		XBRepBuilderAPI_MakeEdge2d(xgp_Elips2d^ L, XTopoDS_Vertex^ V1, XTopoDS_Vertex^ V2);

		XBRepBuilderAPI_MakeEdge2d(xgp_Hypr2d^ L);

		XBRepBuilderAPI_MakeEdge2d(xgp_Hypr2d^ L, Standard_Real p1, Standard_Real p2);

		XBRepBuilderAPI_MakeEdge2d(xgp_Hypr2d^ L, xgp_Pnt2d^ P1, xgp_Pnt2d^ P2);

		XBRepBuilderAPI_MakeEdge2d(xgp_Hypr2d^ L, XTopoDS_Vertex^ V1, XTopoDS_Vertex^ V2);

		XBRepBuilderAPI_MakeEdge2d(xgp_Parab2d^ L);

		XBRepBuilderAPI_MakeEdge2d(xgp_Parab2d^ L, Standard_Real p1, Standard_Real p2);

		XBRepBuilderAPI_MakeEdge2d(xgp_Parab2d^ L, xgp_Pnt2d^ P1, xgp_Pnt2d^ P2);

		XBRepBuilderAPI_MakeEdge2d(xgp_Parab2d^ L, XTopoDS_Vertex^ V1, XTopoDS_Vertex^ V2);

		XBRepBuilderAPI_MakeEdge2d(XGeom2d_Curve^ L);

		XBRepBuilderAPI_MakeEdge2d(XGeom2d_Curve^ L, Standard_Real p1, Standard_Real p2);

		XBRepBuilderAPI_MakeEdge2d(XGeom2d_Curve^ L, xgp_Pnt2d^ P1, xgp_Pnt2d^ P2);

		XBRepBuilderAPI_MakeEdge2d(XGeom2d_Curve^ L, XTopoDS_Vertex^ V1, XTopoDS_Vertex^ V2);

		XBRepBuilderAPI_MakeEdge2d(XGeom2d_Curve^ L, xgp_Pnt2d^ P1, xgp_Pnt2d^ P2, Standard_Real p1, Standard_Real p2);

		XBRepBuilderAPI_MakeEdge2d(XGeom2d_Curve^ L, XTopoDS_Vertex^ V1, XTopoDS_Vertex^ V2, Standard_Real p1, Standard_Real p2);

		void Init(XGeom2d_Curve^ C);

		void Init(XGeom2d_Curve^ C, Standard_Real p1, Standard_Real p2);

		void Init(XGeom2d_Curve^ C, xgp_Pnt2d^ P1, xgp_Pnt2d^ P2);

		void Init(XGeom2d_Curve^ C, XTopoDS_Vertex^ V1, XTopoDS_Vertex^ V2);

		void Init(XGeom2d_Curve^ C, xgp_Pnt2d^ P1, xgp_Pnt2d^ P2, Standard_Real p1, Standard_Real p2);

		void Init(XGeom2d_Curve^ C, XTopoDS_Vertex^ V1, XTopoDS_Vertex^ V2, Standard_Real p1, Standard_Real p2);

		virtual Standard_Boolean IsDone() Standard_OVERRIDE;

		//! Returns the error description when NotDone.
		XBRepBuilderAPI_EdgeError Error();

		XTopoDS_Edge^ Edge();
		operator XTopoDS_Edge^();

		//! Returns the first vertex of the edge. May be Null.
		XTopoDS_Vertex^ Vertex1();

		//! Returns the second vertex of the edge. May be Null.
		XTopoDS_Vertex^ Vertex2();
		/// <summary>
		/// ±¾µØ¾ä±ú
		/// </summary>
		virtual property BRepBuilderAPI_MakeShape* IHandle {
			BRepBuilderAPI_MakeShape* get() Standard_OVERRIDE {
				return NativeHandle;
			}
			void set(BRepBuilderAPI_MakeShape* handle) Standard_OVERRIDE {
				//NativeHandle = static_cast<BRepBuilderAPI_MakeEdge2d*>(handle);
				if (handle == NULL)
					NativeHandle = static_cast<BRepBuilderAPI_MakeEdge2d*>(handle);
				else
					NativeHandle = NULL;
			}
		}

	private:
		BRepBuilderAPI_MakeEdge2d* NativeHandle;
	};
}
#endif // _XBRepBuilderAPI_MakeEdge2d_HeaderFile
