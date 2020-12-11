// Created on: 1998-01-29
// Created by: Laurent BOURESCHE
// Copyright (c) 1998-1999 Matra Datavision
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

#ifndef _XBRepFilletAPI_LocalOperation_HeaderFile
#define _XBRepFilletAPI_LocalOperation_HeaderFile
#pragma once
#include <BRepFilletAPI_LocalOperation.hxx>
#include <XBRepBuilderAPI_MakeShape.h>
#include <XTopoDS_Edge.h>
#include <XTopoDS_Vertex.h>

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <BRepBuilderAPI_MakeShape.hxx>
#include <Standard_Integer.hxx>
#include <Standard_Real.hxx>
#include <Standard_Boolean.hxx>
#include <ChFiDS_SecHArray1.hxx>
class TopoDS_Edge;
class TopoDS_Vertex;
class BRepFilletAPI_LocalOperation;

using namespace TKBRep;
using namespace TKTopAlgo;
namespace TKFillet {
	ref class TKBRep::XTopoDS_Edge;
	ref class TKBRep::XTopoDS_Vertex;
	//! Construction of fillets on the edges of a Shell.
	public ref class XBRepFilletAPI_LocalOperation : public XBRepBuilderAPI_MakeShape
	{
	public:

		//! DEFINE_STANDARD_ALLOC

		XBRepFilletAPI_LocalOperation();

		XBRepFilletAPI_LocalOperation(BRepFilletAPI_LocalOperation* handle);

		void SetLocalOperationHandle(BRepFilletAPI_LocalOperation* handle);

		virtual BRepFilletAPI_LocalOperation* GetLocalOperation();

		virtual BRepBuilderAPI_MakeShape* GetMakeShape() Standard_OVERRIDE;

		//! Returns a shape built by the shape construction algorithm.
		//! Raises exception StdFail_NotDone if the shape was not built.
		virtual XTopoDS_Shape^ Shape() Standard_OVERRIDE;
		//! Adds a  contour in  the  builder  (builds a
		//! contour  of tangent edges).
		virtual void Add(XTopoDS_Edge^ E);

		//! Reset the contour of index IC, there is nomore
		//! information in the contour.
		virtual void ResetContour(Standard_Integer IC);

		//! Number of contours.
		virtual Standard_Integer NbContours();

		//! Returns the index of  the  contour containing the edge
		//! E, returns 0 if E doesn't belong to any contour.
		virtual Standard_Integer Contour(XTopoDS_Edge^ E);

		//! Number of Edges in the contour I.
		virtual Standard_Integer NbEdges(Standard_Integer I);

		//! Returns the Edge J in the contour I.
		virtual XTopoDS_Edge^ Edge(Standard_Integer I, Standard_Integer J);

		//! remove the contour containing the Edge E.
		virtual void Remove(XTopoDS_Edge^ E);

		//! returns the length the contour of index IC.
		virtual Standard_Real Length(Standard_Integer IC);

		//! Returns the first Vertex of the contour of index IC.
		virtual XTopoDS_Vertex^ FirstVertex(Standard_Integer IC);

		//! Returns the last Vertex of the contour of index IC.
		virtual XTopoDS_Vertex^ LastVertex(Standard_Integer IC);

		//! returns the abscissa of the vertex V on
		//! the contour of index IC.
		virtual Standard_Real Abscissa(Standard_Integer IC, XTopoDS_Vertex^ V);

		//! returns the relative abscissa([0.,1.]) of the
		//! vertex V on the contour of index IC.
		virtual Standard_Real RelativeAbscissa(Standard_Integer IC, XTopoDS_Vertex^ V);

		//! returns true if the contour of index IC is closed
		//! an tangent.
		virtual Standard_Boolean ClosedAndTangent(Standard_Integer IC);

		//! returns true if the contour of index IC is closed
		virtual Standard_Boolean Closed(Standard_Integer IC);

		//! Reset all the fields updated   by Build operation  and
		//! leave the  algorithm in  the  same state  than  before
		//! build    call.  It   allows   contours    and   radius
		//! modifications  to build the result another time.
		virtual void Reset();

		virtual void Simulate(Standard_Integer IC);

		virtual Standard_Integer NbSurf(Standard_Integer IC);

		virtual Handle(ChFiDS_SecHArray1) Sect(Standard_Integer IC, Standard_Integer IS);

		/// <summary>
		/// ±¾µØ¾ä±ú
		/// </summary>
		virtual property BRepBuilderAPI_MakeShape* IHandle {
			BRepBuilderAPI_MakeShape* get() Standard_OVERRIDE {
				return NativeHandle;
			}
			void set(BRepBuilderAPI_MakeShape* handle) Standard_OVERRIDE {
				NativeHandle = static_cast<BRepFilletAPI_LocalOperation*>(handle);
			}
		}

	private:
		BRepFilletAPI_LocalOperation* NativeHandle;
	};
}
#endif // _XBRepFilletAPI_LocalOperation_HeaderFile
