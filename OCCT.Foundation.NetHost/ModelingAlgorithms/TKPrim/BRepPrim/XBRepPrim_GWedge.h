// Created on: 1991-09-18
// Created by: Christophe MARION
// Copyright (c) 1991-1999 Matra Datavision
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

#ifndef _XBRepPrim_GWedge_HeaderFile
#define _XBRepPrim_GWedge_HeaderFile
#pragma once
#include <BRepPrim_GWedge.hxx>
#include <XBRepPrim_Direction.h>
#include "XBRepPrim_Builder.h"
#include <XStandard_Helper.h>
#include <XTopoDS_Shell.h>
#include <XTopoDS_Vertex.h>
#include <XTopoDS_Edge.h>
#include <XTopoDS_Wire.h>
#include <XTopoDS_Face.h>
#include <xgp_Ax2.h>
#include <xgp_Pln.h>
#include <xgp_Lin.h>

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <Standard_Real.hxx>
#include <Standard_Boolean.hxx>
class Standard_DomainError;
class Standard_OutOfRange;



//! A wedge is defined by  :
//!
//! Axes : an Axis2 (coordinate system)
//!
//! YMin, YMax the  coordinates of the  ymin and ymax
//! rectangular faces parallel to the ZX plane (of the
//! coordinate systems)
//!
//! ZMin,ZMax,XMin,XMax the rectangular
//! left (YMin) face parallel to the Z and X axes.
//!
//! Z2Min,Z2Max,X2Min,X2Max the rectangular
//! right (YMax) face parallel to the Z and X axes.
//!
//! For a box Z2Min = ZMin, Z2Max = ZMax,
//! X2Min = XMin, X2Max = XMax
//!
//! The wedge can be open in the corresponding direction
//! of its Boolean myInfinite

using namespace TKBRep;
using namespace TKernel;
using namespace TKMath;
namespace TKPrim {
	ref class XBRepPrim_Builder;
	ref class TKBRep::XTopoDS_Shell;
	ref class TKBRep::XTopoDS_Face;
	ref class TKBRep::XTopoDS_Wire;
	ref class TKBRep::XTopoDS_Edge;
	ref class TKBRep::XTopoDS_Vertex;
	ref class TKMath::xgp_Ax2;
	ref class TKMath::xgp_Pln;
	ref class TKMath::xgp_Lin;
	ref class TKMath::xgp_Pnt;
	public ref class XBRepPrim_GWedge
	{
	public:

		//! DEFINE_STANDARD_ALLOC

		XBRepPrim_GWedge(BRepPrim_GWedge* handle);


		void SetGWedgeHandle(BRepPrim_GWedge* handle);


		virtual BRepPrim_GWedge* GetGWedge();

		//! Creates a  GWedge  algorithm.   <Axes> is  the axis
		//! system for the primitive.
		//!
		//! XMin, YMin, ZMin are set to 0
		//! XMax, YMax, ZMax are set to dx, dy, dz
		//! Z2Min = ZMin
		//! Z2Max = ZMax
		//! X2Min = XMin
		//! X2Max = XMax
		//! The result is a box
		//! dx,dy,dz should be positive
		XBRepPrim_GWedge(XBRepPrim_Builder^ B, xgp_Ax2^ Axes, Standard_Real dx, Standard_Real dy, Standard_Real dz);

		//! Creates  a GWedge  primitive. <Axes> is   the  axis
		//! system for the primitive.
		//!
		//! XMin, YMin, ZMin are set to 0
		//! XMax, YMax, ZMax are set to dx, dy, dz
		//! Z2Min = ZMin
		//! Z2Max = ZMax
		//! X2Min = ltx
		//! X2Max = ltx
		//! The result is a STEP right angular wedge
		//! dx,dy,dz should be positive
		//! ltx should not be negative
		XBRepPrim_GWedge(XBRepPrim_Builder^ B, xgp_Ax2^ Axes, Standard_Real dx, Standard_Real dy, Standard_Real dz, Standard_Real ltx);

		//! Create  a GWedge primitive.   <Axes>  is  the  axis
		//! system for the primitive.
		//!
		//! all the fields are set to the corresponding value
		//! XYZMax - XYZMin should be positive
		//! ZX2Max - ZX2Min should not be negative
		XBRepPrim_GWedge(XBRepPrim_Builder^ B, xgp_Ax2^ Axes, Standard_Real xmin, Standard_Real ymin, Standard_Real zmin, Standard_Real z2min, Standard_Real x2min, Standard_Real xmax, Standard_Real ymax, Standard_Real zmax, Standard_Real z2max, Standard_Real x2max);

		//! Returns the coordinates system from <me>.
		xgp_Ax2^ Axes();

		//! Returns Xmin value from <me>.
		Standard_Real GetXMin();

		//! Returns YMin value from <me>.
		Standard_Real GetYMin();

		//! Returns ZMin value from <me>.
		Standard_Real GetZMin();

		//! Returns Z2Min value from <me>.
		Standard_Real GetZ2Min();

		//! Returns X2Min value from <me>.
		Standard_Real GetX2Min();

		//! Returns XMax value from <me>.
		Standard_Real GetXMax();

		//! Returns YMax value from <me>.
		Standard_Real GetYMax();

		//! Returns ZMax value from <me>.
		Standard_Real GetZMax();

		//! Returns Z2Max value from <me>.
		Standard_Real GetZ2Max();

		//! Returns X2Max value from <me>.
		Standard_Real GetX2Max();

		//! Opens <me> in <d1> direction. A face and its edges
		//! or vertices are said nonexistant.
		void Open(XBRepPrim_Direction d1);

		//! Closes   <me>  in <d1>  direction.  A face and its
		//! edges or vertices are said existant.
		void Close(XBRepPrim_Direction d1);

		//! Returns True if <me> is open in <d1> direction.
		Standard_Boolean IsInfinite(XBRepPrim_Direction d1);

		//! Returns the Shell containing the Faces of <me>.
		XTopoDS_Shell^ Shell();

		//! Returns True if <me> has a Face in <d1> direction.
		Standard_Boolean HasFace(XBRepPrim_Direction d1);

		//! Returns the Face of <me> located in <d1> direction.
		XTopoDS_Face^ Face(XBRepPrim_Direction d1);

		//! Returns the plane  of the Face  of <me> located in
		//! <d1> direction.
		xgp_Pln^ Plane(XBRepPrim_Direction d1);

		//! Returns True if <me> has a Wire in <d1> direction.
		Standard_Boolean HasWire(XBRepPrim_Direction d1);

		//! Returns the Wire of <me> located in <d1> direction.
		XTopoDS_Wire^ Wire(XBRepPrim_Direction d1);

		//! Returns True if <me> has an Edge in <d1><d2> direction.
		Standard_Boolean HasEdge(XBRepPrim_Direction d1, XBRepPrim_Direction d2);

		//! Returns the Edge of <me> located in <d1><d2> direction.
		XTopoDS_Edge^ Edge(XBRepPrim_Direction d1, XBRepPrim_Direction d2);

		//! Returns the line of  the Edge of <me>  located  in
		//! <d1><d2> direction.
		xgp_Lin^ Line(XBRepPrim_Direction d1, XBRepPrim_Direction d2);

		//! Returns True if <me> has a  Vertex in <d1><d2><d3>
		//! direction.
		Standard_Boolean HasVertex(XBRepPrim_Direction d1, XBRepPrim_Direction d2, XBRepPrim_Direction d3);

		//! Returns the Vertex of <me> located in <d1><d2><d3>
		//! direction.
		XTopoDS_Vertex^ Vertex(XBRepPrim_Direction d1, XBRepPrim_Direction d2, XBRepPrim_Direction d3);

		//! Returns the point of the Vertex of <me> located in
		//! <d1><d2><d3> direction.
		xgp_Pnt^ Point(XBRepPrim_Direction d1, XBRepPrim_Direction d2, XBRepPrim_Direction d3);

		/// <summary>
		/// ±¾µØ¾ä±ú
		/// </summary>
		virtual property BRepPrim_GWedge* IHandle {
			BRepPrim_GWedge* get() Standard_OVERRIDE {
				return NativeHandle;
			}
			void set(BRepPrim_GWedge* handle) Standard_OVERRIDE {
				NativeHandle = static_cast<BRepPrim_GWedge*>(handle);
			}
		}

	private:
		BRepPrim_GWedge* NativeHandle;
	};
}
#endif // _XBRepPrim_GWedge_HeaderFile
