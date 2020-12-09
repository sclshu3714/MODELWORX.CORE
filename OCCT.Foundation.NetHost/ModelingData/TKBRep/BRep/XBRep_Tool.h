// Created on: 1993-07-07
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

#ifndef _XBRep_Tool_HeaderFile
#define _XBRep_Tool_HeaderFile
#pragma once
#include <BRep_Tool.hxx>
#include <XTopoDS_Shape.h>
#include <XTopoDS_Face.h>
#include <XTopoDS_Edge.h>
#include <XTopoDS_Vertex.h>
#include <XTopLoc_Location.h>
#include <XGeomAbs_Shape.h>
#include <XGeom_Surface.h>
#include <XGeom_Curve.h>
#include <XGeom2d_Curve.h>
#include <xgp_Pnt2d.h>
#include <xgp_Pnt.h>


#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <GeomAbs_Shape.hxx>
#include <Geom_Surface.hxx>
#include <Geom_Curve.hxx>
#include <Geom2d_Curve.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Pnt.hxx>
#include <Poly_Triangulation.hxx>
#include <Poly_Polygon3D.hxx>
#include <Poly_Polygon2D.hxx>
#include <Poly_PolygonOnTriangulation.hxx>
#include <TopAbs_ShapeEnum.hxx>

class TopoDS_Shape;
class TopoDS_Face;
class TopLoc_Location;
class TopoDS_Edge;
class TopoDS_Vertex;

using namespace TKG3d;
using namespace TKG2d;
using namespace TKMath;
namespace TKBRep {
    ref class XTopoDS_Shape;
    ref class XTopoDS_Face;
    ref class XTopoDS_Edge;
    ref class XTopoDS_Vertex;
    ref class TKMath::XTopLoc_Location;
    ref class TKG3d::XGeom_Surface;
    ref class TKG3d::XGeom_Curve;
    ref class TKG2d::XGeom2d_Curve;
    ref class TKMath::xgp_Pnt2d;
    ref class TKMath::xgp_Pnt;
    //! Provides class methods  to  access to the geometry
    //! of BRep shapes.
    public ref class XBRep_Tool
    {
    public:

       //! DEFINE_STANDARD_ALLOC


        //! If S is Shell, returns True if it has no free boundaries (edges).
        //! If S is Wire, returns True if it has no free ends (vertices).
        //! (Internal and External sub-shepes are ignored in these checks)
        //! If S is Edge, returns True if its vertices are the same.
        //! For other shape types returns S.Closed().
        static Standard_Boolean IsClosed(XTopoDS_Shape^ S);

        //! Returns the geometric surface of the face. Returns
        //! in <L> the location for the surface.
        static XGeom_Surface^ Surface(XTopoDS_Face^ F, XTopLoc_Location^ L);

        //! Returns the geometric  surface of the face. It can
        //! be a copy if there is a Location.
        static XGeom_Surface^ Surface(XTopoDS_Face^ F);

        //! Returns  the Triangulation of  the  face. It  is a
        //! null handle if there is no triangulation.
        static Handle(Poly_Triangulation) Triangulation(XTopoDS_Face^ F, XTopLoc_Location^ L);

        //! Returns the tolerance of the face.
        static Standard_Real Tolerance(XTopoDS_Face^ F);

        //! Returns the  NaturalRestriction  flag of the  face.
        static Standard_Boolean NaturalRestriction(XTopoDS_Face^ F);

        //! Returns True if <E> is a 3d curve or a curve on
        //! surface.
        static Standard_Boolean IsGeometric(XTopoDS_Edge^ E);

        //! Returns the 3D curve  of the edge.  May be  a Null
        //! handle. Returns in <L> the location for the curve.
        //! In <First> and <Last> the parameter range.
        static XGeom_Curve^ Curve(XTopoDS_Edge^ E, XTopLoc_Location^ L, Standard_Real First, Standard_Real Last);

        //! Returns the 3D curve  of the edge. May be a Null handle.
        //! In <First> and <Last> the parameter range.
        //! It can be a copy if there is a Location.
        static XGeom_Curve^ Curve(XTopoDS_Edge^ E, Standard_Real First, Standard_Real Last);

        //! Returns the 3D polygon of the edge. May be   a Null
        //! handle. Returns in <L> the location for the polygon.
        static Handle(Poly_Polygon3D) Polygon3D(XTopoDS_Edge^ E, XTopLoc_Location^ L);

        //! Returns the curve  associated to the  edge in  the
        //! parametric  space of  the  face.  Returns   a NULL
        //! handle  if this curve  does not exist.  Returns in
        //! <First> and <Last> the parameter range.
        //! If the surface is a plane the curve can be not stored but created a new
        //! each time. The flag pointed by <theIsStored> serves to indicate storage status. 
        //! It is valued if the pointer is non-null.
        //! Standard_Boolean* theIsStored = NULL
        static XGeom2d_Curve^ CurveOnSurface(XTopoDS_Edge^ E, XTopoDS_Face^ F,  Standard_Real First, Standard_Real Last, Standard_Boolean theIsStored);

        //! Returns the  curve associated to   the edge in the
        //! parametric  space of the   surface. Returns a NULL
        //! handle  if this curve does  not exist.  Returns in
        //! <First> and <Last> the parameter range.
        //! If the surface is a plane the curve can be not stored but created a new
        //! each time. The flag pointed by <theIsStored> serves to indicate storage status. 
        //! It is valued if the pointer is non-null.
        //! Standard_Boolean* theIsStored = NULL
        static XGeom2d_Curve^ CurveOnSurface(XTopoDS_Edge^ E, XGeom_Surface^ S, XTopLoc_Location^ L, Standard_Real First, Standard_Real Last, Standard_Boolean theIsStored);

        //! For the planar surface builds the 2d curve for the edge
        //! by projection of the edge on plane.
        //! Returns a NULL handle if the surface is not planar or
        //! the projection failed.
        static XGeom2d_Curve^ CurveOnPlane(XTopoDS_Edge^ E, XGeom_Surface^ S, XTopLoc_Location^ L, Standard_Real First, Standard_Real Last);

        //! Returns in <C>, <S>, <L> a 2d curve, a surface and
        //! a location for the edge <E>. <C> and <S>  are null
        //! if the  edge has no curve on  surface.  Returns in
        //! <First> and <Last> the parameter range.
        static void CurveOnSurface(XTopoDS_Edge^ E, XGeom2d_Curve^ C, XGeom_Surface^ S, XTopLoc_Location^ L, Standard_Real First, Standard_Real Last);

        //! Returns in <C>, <S>, <L> the 2d curve, the surface
        //! and the location for the edge <E> of rank <Index>.
        //! <C> and <S> are null if the index is out of range.
        //! Returns in <First> and <Last> the parameter range.
        static void CurveOnSurface(XTopoDS_Edge^ E, XGeom2d_Curve^ C, XGeom_Surface^ S, XTopLoc_Location^ L, Standard_Real First, Standard_Real Last, Standard_Integer Index);

        //! Returns the polygon associated to the  edge in  the
        //! parametric  space of  the  face.  Returns   a NULL
        //! handle  if this polygon  does not exist.
        static Handle(Poly_Polygon2D) PolygonOnSurface(XTopoDS_Edge^ E, XTopoDS_Face^ F);

        //! Returns the polygon associated to the  edge in  the
        //! parametric  space of  the surface. Returns   a NULL
        //! handle  if this polygon  does not exist.
        static Handle(Poly_Polygon2D) PolygonOnSurface(XTopoDS_Edge^ E, XGeom_Surface^ S, XTopLoc_Location^ L);

        //! Returns in <C>, <S>, <L> a 2d curve, a surface and
        //! a location for the edge <E>. <C> and <S>  are null
        //! if the  edge has no polygon on  surface.
        static void PolygonOnSurface(XTopoDS_Edge^ E, Handle(Poly_Polygon2D)& C, XGeom_Surface^ S, XTopLoc_Location^ L);

        //! Returns in <C>, <S>, <L> the 2d curve, the surface
        //! and the location for the edge <E> of rank <Index>.
        //! <C> and <S> are null if the index is out of range.
        static void PolygonOnSurface(XTopoDS_Edge^ E, Handle(Poly_Polygon2D)& C, XGeom_Surface^ S, XTopLoc_Location^ L, Standard_Integer Index);

        //! Returns the polygon associated to the  edge in  the
        //! parametric  space of  the  face.  Returns   a NULL
        //! handle  if this polygon  does not exist.
        static Handle(Poly_PolygonOnTriangulation) PolygonOnTriangulation(XTopoDS_Edge^ E, Handle(Poly_Triangulation)& T, XTopLoc_Location^ L);

        //! Returns in <P>, <T>, <L> a polygon on triangulation, a
        //! triangulation and a location for the edge <E>.
        //! <P>  and  <T>  are null  if  the  edge has no
        //! polygon on  triangulation.
        static void PolygonOnTriangulation(XTopoDS_Edge^ E, Handle(Poly_PolygonOnTriangulation)& P, Handle(Poly_Triangulation)& T, XTopLoc_Location^ L);

        //! Returns   in   <P>,  <T>,    <L> a     polygon  on
        //! triangulation,   a triangulation  and a  location for
        //! the edge <E> for the range index.  <C> and <S> are
        //! null if the edge has no polygon on triangulation.
        static void PolygonOnTriangulation(XTopoDS_Edge^ E, Handle(Poly_PolygonOnTriangulation)& P, Handle(Poly_Triangulation)& T, XTopLoc_Location^ L, Standard_Integer Index);

        //! Returns  True  if  <E>  has  two  PCurves  in  the
        //! parametric space of <F>. i.e.  <F>  is on a closed
        //! surface and <E> is on the closing curve.
        static Standard_Boolean IsClosed(XTopoDS_Edge^ E, XTopoDS_Face^ F);

        //! Returns  True  if  <E>  has  two  PCurves  in  the
        //! parametric space  of <S>.  i.e.   <S>  is a closed
        //! surface and <E> is on the closing curve.
        static Standard_Boolean IsClosed(XTopoDS_Edge^ E, XGeom_Surface^ S, XTopLoc_Location^ L);

        //! Returns  True  if <E> has two arrays of indices in
        //! the triangulation <T>.
        static Standard_Boolean IsClosed(XTopoDS_Edge^ E, Handle(Poly_Triangulation)& T, XTopLoc_Location^ L);

        //! Returns the tolerance for <E>.
        static Standard_Real Tolerance(XTopoDS_Edge^ E);

        //! Returns the SameParameter flag for the edge.
        static Standard_Boolean SameParameter(XTopoDS_Edge^ E);

        //! Returns the SameRange flag for the edge.
        static Standard_Boolean SameRange(XTopoDS_Edge^ E);

        //! Returns True  if the edge is degenerated.
        static Standard_Boolean Degenerated(XTopoDS_Edge^ E);

        //! Gets the range of the 3d curve.
        static void Range(XTopoDS_Edge^ E, Standard_Real First, Standard_Real Last);

        //! Gets the range  of the edge  on the pcurve on  the
        //! surface.
        static void Range(XTopoDS_Edge^ E, XGeom_Surface^ S, XTopLoc_Location^ L, Standard_Real First, Standard_Real Last);

        //! Gets the range of the edge on the pcurve on the face.
        static void Range(XTopoDS_Edge^ E, XTopoDS_Face^ F, Standard_Real First, Standard_Real Last);

        //! Gets the UV locations of the extremities of the edge.
        static void UVPoints(XTopoDS_Edge^ E, XGeom_Surface^ S, XTopLoc_Location^ L, xgp_Pnt2d^ PFirst, xgp_Pnt2d^ PLast);

        //! Gets the UV locations of the extremities of the edge.
        static void UVPoints(XTopoDS_Edge^ E, XTopoDS_Face^ F, xgp_Pnt2d^ PFirst, xgp_Pnt2d^ PLast);

        //! Sets the UV locations of the extremities of the edge.
        static void SetUVPoints(XTopoDS_Edge^ E, XGeom_Surface^ S, XTopLoc_Location^ L, xgp_Pnt2d^ PFirst, xgp_Pnt2d^ PLast);

        //! Sets the UV locations of the extremities of the edge.
        static void SetUVPoints(XTopoDS_Edge^ E, XTopoDS_Face^ F, xgp_Pnt2d^ PFirst, xgp_Pnt2d^ PLast);

        //! Returns True if the edge is on the surfaces of the
        //! two faces.
        static Standard_Boolean HasContinuity(XTopoDS_Edge^ E, XTopoDS_Face^ F1, XTopoDS_Face^ F2);

        //! Returns the continuity.
        static XGeomAbs_Shape Continuity(XTopoDS_Edge^ E, XTopoDS_Face^ F1, XTopoDS_Face^ F2);

        //! Returns True if the edge is on the surfaces.
        static Standard_Boolean HasContinuity(XTopoDS_Edge^ E, XGeom_Surface^ S1, XGeom_Surface^ S2, XTopLoc_Location^ L1, XTopLoc_Location^ L2);

        //! Returns the continuity.
        static XGeomAbs_Shape Continuity(XTopoDS_Edge^ E, XGeom_Surface^ S1, XGeom_Surface^ S2, XTopLoc_Location^ L1, XTopLoc_Location^ L2);

        //! Returns True if the edge has regularity on some
        //! two surfaces
        static Standard_Boolean HasContinuity(XTopoDS_Edge^ E);

        //! Returns the max continuity of edge between some surfaces or GeomAbs_C0 if there no such surfaces.
        static XGeomAbs_Shape MaxContinuity(XTopoDS_Edge^ theEdge);

        //! Returns the 3d point.
        static xgp_Pnt^ Pnt(XTopoDS_Vertex^ V);

        //! Returns the tolerance.
        static Standard_Real Tolerance(XTopoDS_Vertex^ V);

        //! Returns the parameter of <V> on <E>.
        static Standard_Real Parameter(XTopoDS_Vertex^ V, XTopoDS_Edge^ E);

        //! Returns the  parameters  of   the  vertex   on the
        //! pcurve of the edge on the face.
        static Standard_Real Parameter(XTopoDS_Vertex^ V, XTopoDS_Edge^ E, XTopoDS_Face^ F);

        //! Returns the  parameters  of   the  vertex   on the
        //! pcurve of the edge on the surface.
        static Standard_Real Parameter(XTopoDS_Vertex^ V, XTopoDS_Edge^ E, XGeom_Surface^ S, XTopLoc_Location^ L);

        //! Returns the parameters of the vertex on the face.
        static xgp_Pnt2d^ Parameters(XTopoDS_Vertex^ V, XTopoDS_Face^ F);

        //! Returns the maximum tolerance of input shape subshapes.
        //@param theShape    - Shape to search tolerance.
        //@param theSubShape - Search subshape, only Face, Edge or Vertex are supported.
        static Standard_Real MaxTolerance(XTopoDS_Shape^ theShape, XTopAbs_ShapeEnum theSubShape);

    };
}
#endif // _XBRep_Tool_HeaderFile
