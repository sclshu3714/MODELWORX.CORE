// Created on: 1993-07-12
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

#ifndef _XBRepBuilderAPI_MakeFace_HeaderFile
#define _XBRepBuilderAPI_MakeFace_HeaderFile
#pragma once
#include <BRepBuilderAPI_MakeFace.hxx>	 
#include <XBRepBuilderAPI_MakeShape.h>
#include <XTopoDS_Shape.h>

#include <XGeom_Surface.h>
#include <XTopoDS_Face.h>
#include <XTopoDS_Wire.h>
#include <xgp_Pln.h>
#include <xgp_Cylinder.h>
#include <xgp_Cone.h>
#include <xgp_Sphere.h>
#include <xgp_Torus.h>


#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <BRepLib_MakeFace.hxx>
#include <BRepBuilderAPI_MakeShape.hxx>
#include <Standard_Real.hxx>
#include <Standard_Boolean.hxx>
#include <BRepBuilderAPI_FaceError.hxx>
#include <XBRepBuilderAPI_FaceError.h>
#include <gp_Dir2d.hxx>
class gp_Dir2d;
class StdFail_NotDone;
//class TopoDS_Face;
//class gp_Pln;
//class gp_Cylinder;
//class gp_Cone;
//class gp_Sphere;
//class gp_Torus;
//class Geom_Surface;
//class TopoDS_Wire;


//! Provides methods to build faces.
//!
//! A face may be built :
//!
//! * From a surface.
//!
//! - Elementary surface from gp.
//!
//! - Surface from Geom.
//!
//! * From a surface and U,V values.
//!
//! * From a wire.
//!
//! - Find the surface automatically if possible.
//!
//! * From a surface and a wire.
//!
//! - A flag Inside is given, when this flag is True
//! the  wire is  oriented to bound a finite area on
//! the surface.
//!
//! * From a face and a wire.
//!
//! - The new wire is a perforation.
//! 
using namespace TKMath;
using namespace TKBRep;
using namespace TKG3d;
namespace TKTopAlgo {
	ref class TKMath::xgp_Pln;
	ref class TKMath::xgp_Cylinder;
	ref class TKMath::xgp_Cone;
	ref class TKMath::xgp_Sphere;
	ref class TKMath::xgp_Torus;
	ref class TKG3d::XGeom_Surface;
	ref class TKBRep::XTopoDS_Wire;
	ref class TKBRep::XTopoDS_Face;
	public ref class XBRepBuilderAPI_MakeFace : public XBRepBuilderAPI_MakeShape
	{
	public:

		//! DEFINE_STANDARD_ALLOC
		void Initialize(BRepBuilderAPI_MakeFace* pos);

		//! Not done.
		XBRepBuilderAPI_MakeFace();

		//! Load a face. Usefull to add wires.
		XBRepBuilderAPI_MakeFace(XTopoDS_Face^ F);

		//! Make a face from a plane.
		XBRepBuilderAPI_MakeFace(xgp_Pln^ P);

		//! Make a face from a cylinder.
		XBRepBuilderAPI_MakeFace(xgp_Cylinder^ C);

		//! Make a face from a cone.
		XBRepBuilderAPI_MakeFace(xgp_Cone^ C);

		//! Make a face from a sphere.
		XBRepBuilderAPI_MakeFace(xgp_Sphere^ S);

		//! Make a face from a torus.
		XBRepBuilderAPI_MakeFace(xgp_Torus^ C);

		//! Make a face from a Surface. Accepts tolerance value (TolDegen)
		//! for resolution of degenerated edges.
		XBRepBuilderAPI_MakeFace(XGeom_Surface^ S, Standard_Real TolDegen);

		//! Make a face from a plane.
		XBRepBuilderAPI_MakeFace(xgp_Pln^ P, Standard_Real UMin, Standard_Real UMax, Standard_Real VMin, Standard_Real VMax);

		//! Make a face from a cylinder.
		XBRepBuilderAPI_MakeFace(xgp_Cylinder^ C, Standard_Real UMin, Standard_Real UMax, Standard_Real VMin, Standard_Real VMax);

		//! Make a face from a cone.
		XBRepBuilderAPI_MakeFace(xgp_Cone^ C, Standard_Real UMin, Standard_Real UMax, Standard_Real VMin, Standard_Real VMax);

		//! Make a face from a sphere.
		XBRepBuilderAPI_MakeFace(xgp_Sphere^ S, Standard_Real UMin, Standard_Real UMax, Standard_Real VMin, Standard_Real VMax);

		//! Make a face from a torus.
		XBRepBuilderAPI_MakeFace(xgp_Torus^ C, Standard_Real UMin, Standard_Real UMax, Standard_Real VMin, Standard_Real VMax);

		//! Make a face from a Surface. Accepts tolerance value (TolDegen)
		//! for resolution of degenerated edges.
		XBRepBuilderAPI_MakeFace(XGeom_Surface^ S, Standard_Real UMin, Standard_Real UMax, Standard_Real VMin, Standard_Real VMax, Standard_Real TolDegen);

		//! Find a surface from the wire and make a face.
		//! if <OnlyPlane> is true, the computed surface will be
		//! a plane. If it is not possible to find a plane, the
		//! flag NotDone will be set.
		//! Standard_Boolean OnlyPlane = Standard_False
		XBRepBuilderAPI_MakeFace(XTopoDS_Wire^ W, Standard_Boolean OnlyPlane);

		//! Make a face from a plane and a wire.
		//! Standard_Boolean Inside = Standard_True
		XBRepBuilderAPI_MakeFace(xgp_Pln^ P, XTopoDS_Wire^ W, Standard_Boolean Inside);

		//! Make a face from a cylinder and a wire.
		//! Standard_Boolean Inside = Standard_True
		XBRepBuilderAPI_MakeFace(xgp_Cylinder^ C, XTopoDS_Wire^ W, Standard_Boolean Inside);

		//! Make a face from a cone and a wire.
		//! Standard_Boolean Inside = Standard_True
		XBRepBuilderAPI_MakeFace(xgp_Cone^ C, XTopoDS_Wire^ W, Standard_Boolean Inside);

		//! Make a face from a sphere and a wire.
		//! Standard_Boolean Inside = Standard_True
		XBRepBuilderAPI_MakeFace(xgp_Sphere^ S, XTopoDS_Wire^ W, Standard_Boolean Inside);

		//! Make a face from a torus and a wire.
		//! Standard_Boolean Inside = Standard_True
		XBRepBuilderAPI_MakeFace(xgp_Torus^ C, XTopoDS_Wire^ W, Standard_Boolean Inside);

		//! Make a face from a Surface and a wire.
		//! Standard_Boolean Inside = Standard_True
		XBRepBuilderAPI_MakeFace(XGeom_Surface^ S, XTopoDS_Wire^ W, Standard_Boolean Inside);

		//! Adds the wire <W> in the face <F>
		//! A general method to create a face is to give
		//! -      a surface S as the support (the geometric domain) of the face,
		//! -      and a wire W to bound it.
		//! The bounds of the face can also be defined by four parameter values
		//! umin, umax, vmin, vmax which determine isoparametric limitations on
		//! the parametric space of the surface. In this way, a patch is
		//! defined. The parameter values are optional. If they are omitted, the
		//! natural bounds of the surface are used. A wire is automatically
		//! built using the defined bounds. Up to four edges and four vertices
		//! are created with this wire (no edge is created when the
		//! corresponding parameter value is infinite).
		//! Wires can then be added using the function Add to define other
		//! restrictions on the face. These restrictions represent holes. More
		//! than one wire may be added by this way, provided that the wires do
		//! not cross each other and that they define only one area on the
		//! surface. (Be careful, however, as this is not checked).
		//! Forbidden addition of wires
		//! Note that in this schema, the third case is valid if edges of the
		//! wire W are declared internal to the face. As a result, these edges
		//! are no longer bounds of the face.
		//! A default tolerance (Precision::Confusion()) is given to the face,
		//! this tolerance may be increased during construction of the face
		//! using various algorithms.
		//! Rules applied to the arguments
		//! For the surface:
		//! -      The surface must not be a 'null handle'.
		//! -      If the surface is a trimmed surface, the basis surface is used.
		//! -      For the wire: the wire is composed of connected edges, each
		//! edge having a parametric curve description in the parametric
		//! domain of the surface; in other words, as a pcurve.
		//! For the parameters:
		//! -      The parameter values must be in the parametric range of the
		//! surface (or the basis surface, if the surface is trimmed). If this
		//! condition is not satisfied, the face is not built, and the Error
		//! function will return BRepBuilderAPI_ParametersOutOfRange.
		//! -      The bounding parameters p1 and p2 are adjusted on a periodic
		//! surface in a given parametric direction by adding or subtracting
		//! the period to obtain p1 in the parametric range of the surface and
		//! such p2, that p2 - p1 <= Period, where Period is the period of the
		//! surface in this parametric direction.
		//! -      A parameter value may be infinite. There will be no edge and
		//! no vertex in the corresponding direction.
		XBRepBuilderAPI_MakeFace(XTopoDS_Face^ F, XTopoDS_Wire^ W);

		//! Initializes (or reinitializes) the
		//! construction of a face by creating a new object which is a copy of
		//! the face F, in order to add wires to it, using the function Add.
		//! Note: this complete copy of the geometry is only required if you
		//! want to work on the geometries of the two faces independently.
		void Init(XTopoDS_Face^ F);

		//! Initializes (or reinitializes) the construction of a face on
		//! the surface S. If Bound is true, a wire is
		//! automatically created from the natural bounds of the
		//! surface S and added to the face in order to bound it. If
		//! Bound is false, no wire is added. This option is used
		//! when real bounds are known. These will be added to
		//! the face after this initialization, using the function Add.
		//! TolDegen parameter is used for resolution of degenerated edges
		//! if calculation of natural bounds is turned on.
		void Init(XGeom_Surface^ S, Standard_Boolean Bound, Standard_Real TolDegen);

		//! Initializes (or reinitializes) the construction of a face on
		//! the surface S, limited in the u parametric direction by
		//! the two parameter values UMin and UMax and in the
		//! v parametric direction by the two parameter values VMin and VMax.
		//! Warning
		//! Error returns:
		//! -      BRepBuilderAPI_ParametersOutOfRange
		//! when the parameters given are outside the bounds of the
		//! surface or the basis surface of a trimmed surface.
		//! TolDegen parameter is used for resolution of degenerated edges.
		void Init(XGeom_Surface^ S, Standard_Real UMin, Standard_Real UMax, Standard_Real VMin, Standard_Real VMax, Standard_Real TolDegen);

		//! Adds the wire W to the constructed face as a hole.
		//! Warning
		//! W must not cross the other bounds of the face, and all
		//! the bounds must define only one area on the surface.
		//! (Be careful, however, as this is not checked.)
		//! Example
		//! // a cylinder
		//! gp_Cylinder C = ..;
		//! // a wire
		//! TopoDS_Wire W = ...;
		//! BRepBuilderAPI_MakeFace MF(C);
		//! MF.Add(W);
		//! TopoDS_Face F = MF;
		void Add(XTopoDS_Wire^ W);

		//! Returns true if this algorithm has a valid face.
		virtual Standard_Boolean IsDone();// Standard_OVERRIDE;

		//! Returns the construction status
		//! BRepBuilderAPI_FaceDone if the face is built, or
		//! -   another value of the BRepBuilderAPI_FaceError
		//! enumeration indicating why the construction failed, in
		//! particular when the given parameters are outside the
		//! bounds of the surface.
		XBRepBuilderAPI_FaceError Error();

		//! Returns the constructed face.
		//! Exceptions
		//! StdFail_NotDone if no face is built.
		XTopoDS_Face^ Face();
		operator XTopoDS_Face^();

		void SetMakeFaceHandle(BRepBuilderAPI_MakeFace* pos);

		virtual BRepBuilderAPI_MakeFace* GetMakeFace();

		virtual BRepBuilderAPI_MakeShape* GetMakeShape() Standard_OVERRIDE;

		virtual XTopoDS_Shape^ Shape() Standard_OVERRIDE;

		/// <summary>
		/// ±¾µØ¾ä±ú
		/// </summary>
		virtual property BRepBuilderAPI_MakeShape* IHandle {
			BRepBuilderAPI_MakeShape* get() Standard_OVERRIDE {
				return NativeHandle;
			}
			void set(BRepBuilderAPI_MakeShape* handle) Standard_OVERRIDE {
				NativeHandle = static_cast<BRepBuilderAPI_MakeFace*>(handle);
			}
		}

	private:
		BRepBuilderAPI_MakeFace* NativeHandle;
	};
}
#endif // _XBRepBuilderAPI_MakeFace_HeaderFile
