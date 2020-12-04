// Created on: 1993-06-23
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

#ifndef _XBRepPrim_FaceBuilder_HeaderFile
#define _XBRepPrim_FaceBuilder_HeaderFile
#pragma once
#include <XStandard_Helper.h>
#include <BRepPrim_FaceBuilder.hxx>
#include <XBRep_Builder.h>
#include <XGeom_Surface.h>
#include <XTopoDS_Face.h>
#include <XTopoDS_Edge.h>
#include <XTopoDS_Vertex.h>
#include <xgp_Vec2d.h>


#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <TopoDS_Vertex.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Face.hxx>
#include <Standard_Real.hxx>
#include <Standard_Integer.hxx>
class Standard_ConstructionError;
class Standard_OutOfRange;
class BRep_Builder;
class Geom_Surface;
class TopoDS_Face;
class TopoDS_Edge;
class TopoDS_Vertex;


//! The  FaceBuilder is an algorithm   to build a BRep
//! Face from a Geom Surface.
//!
//! The  face covers  the  whole surface or  the  area
//! delimited by UMin, UMax, VMin, VMax
using namespace TKBRep;
using namespace TKG3d;
using namespace TKBRep;
using namespace TKMath;
namespace TKPrim {

	ref class TKBRep::XBRep_Builder;
	ref class TKG3d::XGeom_Surface;
	ref class TKBRep::XTopoDS_Face;
	ref class TKBRep::XTopoDS_Edge;
	ref class TKBRep::XTopoDS_Vertex;
	ref class TKMath::xgp_Vec2d;
	public ref class XBRepPrim_FaceBuilder
	{
	public:

		//! DEFINE_STANDARD_ALLOC


		XBRepPrim_FaceBuilder();

		XBRepPrim_FaceBuilder(BRepPrim_FaceBuilder* pos);

		XBRepPrim_FaceBuilder(XBRep_Builder^ B, XGeom_Surface^ S);

		XBRepPrim_FaceBuilder(XBRep_Builder^ B, XGeom_Surface^ S, Standard_Real UMin, Standard_Real UMax, Standard_Real VMin, Standard_Real VMax);

		void SetPrimFaceBuilder(BRepPrim_FaceBuilder* pos);

		virtual BRepPrim_FaceBuilder* GetPrimFaceBuilder();

		void Init(XBRep_Builder^ B, XGeom_Surface^ S);

		void Init(XBRep_Builder^ B, XGeom_Surface^ S, Standard_Real UMin, Standard_Real UMax, Standard_Real VMin, Standard_Real VMax);

		XTopoDS_Face^ Face();
		operator XTopoDS_Face^();

		//! Returns the edge of index <I>
		//! 1 - Edge VMin
		//! 2 - Edge UMax
		//! 3 - Edge VMax
		//! 4 - Edge UMin
		XTopoDS_Edge^ Edge(Standard_Integer I);

		//! Returns the vertex of index <I>
		//! 1 - Vertex UMin,VMin
		//! 2 - Vertex UMax,VMin
		//! 3 - Vertex UMax,VMax
		//! 4 - Vertex UMin,VMax
		XTopoDS_Vertex^ Vertex(Standard_Integer I);

		/// <summary>
		/// ±¾µØ¾ä±ú
		/// </summary>
		virtual property BRepPrim_FaceBuilder* IHandle {
			BRepPrim_FaceBuilder* get() { // Standard_OVERRIDE {
				return NativeHandle;
			}
			void set(BRepPrim_FaceBuilder* handle) { //s Standard_OVERRIDE {
				NativeHandle = static_cast<BRepPrim_FaceBuilder*>(handle);
			}
		}

	private:
		BRepPrim_FaceBuilder* NativeHandle;
	};
}
#endif // _XBRepPrim_FaceBuilder_HeaderFile
