// Created on: 1992-11-05
// Created by: Remi LEQUETTE
// Copyright (c) 1992-1999 Matra Datavision
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

#ifndef _XBRepPrim_Revolution_HeaderFile
#define _XBRepPrim_Revolution_HeaderFile
#pragma once
#include <XStandard_Helper.h>
#include <BRepPrim_Revolution.hxx>
#include <XBRepPrim_OneAxis.h>
#include <XGeom_Curve.h>
#include <XGeom2d_Curve.h>
#include <XTopoDS_Face.h>
#include <XTopoDS_Edge.h>
#include <xgp_Pnt2d.h>
#include <xgp_Ax2.h>


#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Real.hxx>
class Geom_Curve;
class Geom2d_Curve;
class gp_Ax2;
class TopoDS_Face;
class TopoDS_Edge;
class gp_Pnt2d;

using namespace TKG2d;
using namespace TKG3d;
using namespace TKMath;
using namespace TKBRep;
namespace TKPrim {
	//! Implement  the OneAxis algoritm   for a revolution
	//! surface.
	ref class TKG3d::XGeom_Curve;
	ref class TKG2d::XGeom2d_Curve;
	ref class TKBRep::XTopoDS_Face;
	ref class TKBRep::XTopoDS_Edge;
	ref class TKMath::xgp_Pnt2d;
	ref class TKMath::xgp_Ax2;
	public ref class XBRepPrim_Revolution : public XBRepPrim_OneAxis
	{
	public:

		//! DEFINE_STANDARD_ALLOC
		//! 
		XBRepPrim_Revolution();

		XBRepPrim_Revolution(BRepPrim_Revolution* handle);

		void SetRevolutionHandle(BRepPrim_Revolution* handle);

		virtual BRepPrim_Revolution* GetRevolution();

		virtual BRepPrim_OneAxis* GetOneAxis() Standard_OVERRIDE;

		//! Create a  revolution body <M>  is the  meridian nd
		//! must   be in the XZ  plane   of <A>. <PM>  is  the
		//! meridian in the XZ plane.
		XBRepPrim_Revolution(xgp_Ax2^ A, Standard_Real VMin, Standard_Real VMax, XGeom_Curve^ M, XGeom2d_Curve^ PM);

		//! The surface normal should be directed  towards the
		//! outside.
		virtual XTopoDS_Face^ MakeEmptyLateralFace() Standard_OVERRIDE;

		//! Returns  an  edge with  a 3D curve   made from the
		//! meridian  in the XZ  plane rotated by <Ang> around
		//! the Z-axis. Ang may be 0 or myAngle.
		virtual XTopoDS_Edge^ MakeEmptyMeridianEdge(Standard_Real Ang) Standard_OVERRIDE;

		//! Returns the meridian point at parameter <V> in the
		//! plane XZ.
		virtual xgp_Pnt2d^ MeridianValue(Standard_Real V) Standard_OVERRIDE;

		//! Sets the  parametric urve of  the edge <E>  in the
		//! face <F>   to be  the  2d  representation  of  the
		//! meridian.
		virtual void SetMeridianPCurve(XTopoDS_Edge^ E, XTopoDS_Face^ F) Standard_OVERRIDE;

		/// <summary>
		/// ±¾µØ¾ä±ú
		/// </summary>
		virtual property BRepPrim_OneAxis* IHandle {
			BRepPrim_OneAxis* get() Standard_OVERRIDE {
				return NativeHandle;
			}
			void set(BRepPrim_OneAxis* handle) Standard_OVERRIDE {
				NativeHandle = static_cast<BRepPrim_Revolution*>(handle);
			}
		}

	private:
		BRepPrim_Revolution* NativeHandle;
	};
}
#endif // _BRepPrim_Revolution_HeaderFile
