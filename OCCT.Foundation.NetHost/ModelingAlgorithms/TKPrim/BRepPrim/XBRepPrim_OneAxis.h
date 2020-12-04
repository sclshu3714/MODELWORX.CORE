// Created on: 1991-07-23
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

#ifndef _XBRepPrim_OneAxis_HeaderFile
#define _XBRepPrim_OneAxis_HeaderFile
#pragma once
#include <BRepPrim_OneAxis.hxx>
#include <XStandard_Helper.h>
#include <XBRepPrim_Builder.h>
#include <XTopoDS_Shell.h>
#include <XTopoDS_Vertex.h>
#include <XTopoDS_Edge.h>
#include <XTopoDS_Wire.h>
#include <XTopoDS_Face.h>
#include <xgp_Ax2.h>
#include <xgp_Vec2d.h>

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Real.hxx>
#include <Standard_Boolean.hxx>

class Standard_DomainError;
class Standard_OutOfRange;


//! Algorithm to  build  primitives with  one  axis of
//! revolution.
//!
//! The revolution  body is described by :
//!
//! A coordinate  system (Ax2 from  gp). The Z axis is
//! the rotational axis.
//!
//! An Angle around the Axis, When  the Angle  is 2*PI
//! the primitive is not limited  by planar faces. The
//! U parameter range from 0 to Angle.
//!
//! A parameter range VMin, VMax on the meridian.
//!
//! A meridian : The  meridian is a curve described by
//! a set of deferred methods.
//!
//! The  topology consists of  A shell,  Faces,  Wires,
//! Edges and Vertices.  Methods  are provided to build
//! all the elements.  Building an element  implies the
//! automatic building  of  all its  sub-elements.
//!
//! So building the shell builds everything.
//!
//! There are at most 5 faces :
//!
//! - The LateralFace.
//!
//! - The TopFace and the BottomFace.
//!
//! - The StartFace and the EndFace.
//! 
using namespace TKMath;
using namespace TKBRep;
namespace TKPrim {
	ref class XBRepPrim_Builder;
	ref class TKBRep::XTopoDS_Face;
	ref class TKBRep::XTopoDS_Edge;
	ref class TKBRep::XTopoDS_Shell;
	ref class TKBRep::XTopoDS_Wire;
	ref class TKBRep::XTopoDS_Vertex;
	ref class TKMath::xgp_Ax2;
	ref class TKMath::xgp_Pnt2d;
	ref class TKMath::xgp_Vec2d;
	public ref class XBRepPrim_OneAxis
	{
	public:

		//! DEFINE_STANDARD_ALLOC
		XBRepPrim_OneAxis();

		XBRepPrim_OneAxis(BRepPrim_OneAxis* handle);

		void SetOneAxisHandle(BRepPrim_OneAxis* handle);

		virtual BRepPrim_OneAxis* GetOneAxis();

		//! The MeridianOffset is added  to the  parameters on
		//! the meridian curve and  to  the  V values  of  the
		//! pcurves. This is  used for the sphere for example,
		//! to give a range on the meridian  edge which is not
		//! VMin, VMax.
		//! Standard_Real MeridianOffset
		void SetMeridianOffset(Standard_Real MeridianOffset);

		//! Returns the Ax2 from <me>.
		xgp_Ax2^ Axes();

		void Axes(xgp_Ax2^ A);

		Standard_Real Angle();

		void Angle(Standard_Real A);

		Standard_Real VMin();

		void VMin(Standard_Real V);

		Standard_Real VMax();

		void VMax(Standard_Real V);

		//! Returns a face with  no edges.  The surface is the
		//! lateral surface with normals pointing outward. The
		//! U parameter is the angle with the  origin on the X
		//! axis. The  V parameter is   the  parameter of  the
		//! meridian.
		virtual XTopoDS_Face^ MakeEmptyLateralFace();

		//! Returns  an  edge with  a 3D curve   made from the
		//! meridian  in the XZ  plane rotated by <Ang> around
		//! the Z-axis. Ang may be 0 or myAngle.
		virtual XTopoDS_Edge^ MakeEmptyMeridianEdge(Standard_Real Ang);

		//! Sets the  parametric curve of the  edge <E> in the
		//! face  <F> to be  the   2d representation  of   the
		//! meridian.
		virtual void SetMeridianPCurve(XTopoDS_Edge^ E, XTopoDS_Face^ F);

		//! Returns the meridian point at parameter <V> in the
		//! plane XZ.
		virtual xgp_Pnt2d^ MeridianValue(Standard_Real V);

		//! Returns True if the point of  parameter <V> on the
		//! meridian is on the Axis. Default implementation is
		//! Abs(MeridianValue(V).X()) < Precision::Confusion()
		virtual Standard_Boolean MeridianOnAxis(Standard_Real V);

		//! Returns True  if the  meridian is  closed. Default
		//! implementation                                  is
		//! MeridianValue(VMin).IsEqual(MeridianValue(VMax),
		//! Precision::Confusion())
		virtual Standard_Boolean MeridianClosed();

		//! Returns  True   if  VMax    is  infinite.  Default
		//! Precision::IsPositiveInfinite(VMax);
		virtual Standard_Boolean VMaxInfinite();

		//! Returns  True   if  VMin    is  infinite.  Default
		//! Precision::IsNegativeInfinite(VMax);
		virtual Standard_Boolean VMinInfinite();

		//! Returns True if  there is  a top  face.
		//!
		//! That is neither : VMaxInfinite()
		//! MeridianClosed()
		//! MeridianOnAxis(VMax)
		virtual Standard_Boolean HasTop();

		//! Returns   True if there is   a bottom  face.
		//!
		//! That is neither : VMinInfinite()
		//! MeridianClosed()
		//! MeridianOnAxis(VMin)
		virtual Standard_Boolean HasBottom();

		//! Returns True if  there are Start   and  End faces.
		//!
		//! That is : 2*PI  - Angle > Precision::Angular()
		virtual Standard_Boolean HasSides();

		//! Returns the Shell containing all the  Faces of the
		//! primitive.
		XTopoDS_Shell^ Shell();

		//! Returns  the lateral Face.   It is oriented toward
		//! the outside of the primitive.
		XTopoDS_Face^ LateralFace();

		//! Returns the   top planar  Face.    It  is Oriented
		//! toward the +Z axis (outside).
		XTopoDS_Face^ TopFace();

		//! Returns  the Bottom planar Face.   It is  Oriented
		//! toward the -Z axis (outside).
		XTopoDS_Face^ BottomFace();

		//! Returns  the  Face   starting   the slice, it   is
		//! oriented toward the exterior of the primitive.
		XTopoDS_Face^ StartFace();

		//! Returns the Face ending the slice, it  is oriented
		//! toward the exterior of the primitive.
		XTopoDS_Face^ EndFace();

		//! Returns  the wire in the lateral face.
		XTopoDS_Wire^ LateralWire();

		//! Returns the   wire in the   lateral  face with the
		//! start edge.
		XTopoDS_Wire^ LateralStartWire();

		//! Returns the wire with in lateral face with the end
		//! edge.
		XTopoDS_Wire^ LateralEndWire();

		//! Returns the wire in the top face.
		XTopoDS_Wire^ TopWire();

		//! Returns the wire in the bottom face.
		XTopoDS_Wire^ BottomWire();

		//! Returns the wire  in the  start face.
		XTopoDS_Wire^ StartWire();

		//! Returns  the wire   in the  start   face  with the
		//! AxisEdge.
		XTopoDS_Wire^ AxisStartWire();

		//! Returns the Wire in   the end face.
		XTopoDS_Wire^ EndWire();

		//! Returns  the Wire  in  the   end   face  with  the
		//! AxisEdge.
		XTopoDS_Wire^ AxisEndWire();

		//! Returns the Edge built along the Axis and oriented
		//! on +Z of the Axis.
		XTopoDS_Edge^ AxisEdge();

		//! Returns the   Edge at angle 0.
		XTopoDS_Edge^ StartEdge();

		//! Returns the  Edge at  angle Angle.  If !HasSides()
		//! the StartEdge and the EndEdge are the same edge.
		XTopoDS_Edge^ EndEdge();

		//! Returns the linear Edge between start Face and top
		//! Face.
		XTopoDS_Edge^ StartTopEdge();

		//! Returns the linear  Edge between  start  Face  and
		//! bottom Face.
		XTopoDS_Edge^ StartBottomEdge();

		//! Returns the linear Edge  between end Face and  top
		//! Face.
		XTopoDS_Edge^ EndTopEdge();

		//! Returns  the  linear  Edge  between end  Face  and
		//! bottom Face.
		XTopoDS_Edge^ EndBottomEdge();

		//! Returns the edge at VMax. If  MeridianClosed() the
		//! TopEdge and the BottomEdge are the same edge.
		XTopoDS_Edge^ TopEdge();

		//! Returns the edge  at VMin. If MeridianClosed() the
		//! TopEdge and the BottomEdge are the same edge.
		XTopoDS_Edge^ BottomEdge();

		//! Returns the Vertex at the Top altitude on the axis.
		XTopoDS_Vertex^ AxisTopVertex();

		//! Returns the Vertex  at the Bottom  altitude on the
		//! axis.
		XTopoDS_Vertex^ AxisBottomVertex();

		//! Returns the vertex (0,VMax)
		XTopoDS_Vertex^ TopStartVertex();

		//! Returns the vertex (angle,VMax)
		XTopoDS_Vertex^ TopEndVertex();

		//! Returns the vertex (0,VMin)
		XTopoDS_Vertex^ BottomStartVertex();

		//! Returns the vertex (angle,VMax)
		XTopoDS_Vertex^ BottomEndVertex();
		virtual ~XBRepPrim_OneAxis();

		/// <summary>
		/// ±¾µØ¾ä±ú
		/// </summary>
		virtual property BRepPrim_OneAxis* IHandle {
			BRepPrim_OneAxis* get() { //Standard_OVERRIDE {
				return NativeHandle;
			}
			void set(BRepPrim_OneAxis* handle) { //Standard_OVERRIDE {
				NativeHandle = static_cast<BRepPrim_OneAxis*>(handle);
			}
		}

	private:
		BRepPrim_OneAxis* NativeHandle;
	};
}
#endif // _XBRepPrim_OneAxis_HeaderFile
