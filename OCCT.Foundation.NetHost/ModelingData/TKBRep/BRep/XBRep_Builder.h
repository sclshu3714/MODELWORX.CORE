// Created on: 1991-07-01
// Created by: Remi LEQUETTE
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

#ifndef _XBRep_Builder_HeaderFile
#define _XBRep_Builder_HeaderFile
#pragma once
#include <BRep_Builder.hxx>
#include <XStandard_Helper.h>
#include <XTopoDS_Builder.h>
#include <XTopoDS_Edge.h>
#include <XTopoDS_Vertex.h>
#include <XTopoDS_Face.h>
#include <XGeom_Surface.h>
#include <XGeom_Curve.h>
#include <xgp_Pnt2d.h>
#include <xgp_Pnt.h>

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <TopoDS_Builder.hxx>
#include <Geom2d_Curve.hxx>
#include <Geom_Curve.hxx>
#include <Geom_Surface.hxx>
#include <GeomAbs_Shape.hxx>
#include <Poly_Polygon3D.hxx>
#include <Poly_PolygonOnTriangulation.hxx>
#include <Poly_Triangulation.hxx>
#include <XGeom2d_Curve.h>
#include <gp_Dir2d.hxx>
class gp_Dir2d;
class Standard_NullObject;
class Standard_DomainError;
class TopoDS_Face;
class Geom_Surface;
class TopLoc_Location;
class Poly_Triangulation;
class TopoDS_Edge;
class Geom_Curve;
class Poly_Polygon3D;
class Poly_PolygonOnTriangulation;
class Geom2d_Curve;
class gp_Pnt2d;
class Poly_Polygon2D;
class TopoDS_Vertex;
class gp_Pnt;


//! A framework providing advanced tolerance control.
//! It is used to build Shapes.
//! If tolerance control is required, you are advised to:
//! 1. build a default precision for topology, using the
//! classes provided in the BRepAPI package
//! 2. update the tolerance of the resulting shape.
//! Note that only vertices, edges and faces have
//! meaningful tolerance control. The tolerance value
//! must always comply with the condition that face
//! tolerances are more restrictive than edge tolerances
//! which are more restrictive than vertex tolerances. In
//! other words: Tol(Vertex) >= Tol(Edge) >= Tol(Face).
//! Other rules in setting tolerance include:
//! - you can open up tolerance but should never restrict it
//! - an edge cannot be included within the fusion of the
//! tolerance spheres of two vertices


using namespace TKernel;
using namespace TKMath;
using namespace TKG3d;
using namespace TKG2d;
namespace TKBRep {
    ref class XTopoDS_Face;
    ref class XTopoDS_Edge;
    ref class XTopoDS_Vertex;
    ref class TKG3d::XGeom_Surface;
    ref class TKG3d::XGeom_Curve;
    ref class TKG2d::XGeom2d_Curve;
    ref class TKMath::xgp_Pnt2d;
    ref class TKMath::xgp_Pnt;
    public ref class XBRep_Builder : public XTopoDS_Builder
    {
    public:

        //! DEFINE_STANDARD_ALLOC

        //! Creates from a Builder.
        XBRep_Builder(BRep_Builder* pos);

        void SetBRepBuilderHandle(BRep_Builder* pos);

        virtual BRep_Builder* GetBRepBuilder();

        virtual TopoDS_Builder* GetTopoDSBuilder() Standard_OVERRIDE;

        //! Makes an undefined Face.
        void MakeFace(XTopoDS_Face^ F);

        //! Makes a Face with a surface.
        void MakeFace(XTopoDS_Face^ F, XGeom_Surface^ S, Standard_Real Tol);

        //! Makes a Face with a surface and a location.
        void MakeFace(XTopoDS_Face^ F, XGeom_Surface^ S, XTopLoc_Location^ L, Standard_Real Tol);

        //! Makes a Face with a triangulation. The triangulation
        //! is in the same reference system than the TFace.
        void MakeFace(XTopoDS_Face^ F, Handle(Poly_Triangulation)& T);

        //! Updates the face F using the tolerance value Tol,
        //! surface S and location Location.
        void UpdateFace(XTopoDS_Face^ F, XGeom_Surface^ S, XTopLoc_Location^ L, Standard_Real Tol);

        //! Changes a  face triangulation.
        //!
        //! A null Triangulation removes the triangulation.
        void UpdateFace(XTopoDS_Face^ F, Handle(Poly_Triangulation)& T);

        //! Updates the face Tolerance.
        void UpdateFace(XTopoDS_Face^ F, Standard_Real Tol);

        //! Sets the  NaturalRestriction flag of  the face.
        void NaturalRestriction(XTopoDS_Face^ F, Standard_Boolean N);

        //! Makes an undefined Edge (no geometry).
        void MakeEdge(XTopoDS_Edge^ E);

        //! Makes an Edge with a curve.
        void MakeEdge(XTopoDS_Edge^ E, XGeom_Curve^ C, Standard_Real Tol);

        //! Makes an Edge with a curve and a location.
        void MakeEdge(XTopoDS_Edge^ E, XGeom_Curve^ C, XTopLoc_Location^ L, Standard_Real Tol);

        //! Makes an Edge with a polygon 3d.
        void MakeEdge(XTopoDS_Edge^ E, Handle(Poly_Polygon3D)& P);

        //! makes an Edge polygon on Triangulation.
        void MakeEdge(XTopoDS_Edge^ E, Handle(Poly_PolygonOnTriangulation)& N, Handle(Poly_Triangulation)& T);

        //! makes an Edge polygon on Triangulation.
        void MakeEdge(XTopoDS_Edge^ E, Handle(Poly_PolygonOnTriangulation)& N, Handle(Poly_Triangulation)& T, XTopLoc_Location^ L);

        //! Sets a 3D curve for the edge.
        //! If <C> is a null handle, remove any existing 3d curve.
        void UpdateEdge(XTopoDS_Edge^ E, XGeom_Curve^ C, Standard_Real Tol);

        //! Sets a 3D curve for the edge.
        //! If <C> is a null handle, remove any existing 3d curve.
        void UpdateEdge(XTopoDS_Edge^ E, XGeom_Curve^ C, XTopLoc_Location^ L, Standard_Real Tol);

        //! Sets a pcurve for the edge on the face.
        //! If <C> is a null handle, remove any existing pcurve.
        void UpdateEdge(XTopoDS_Edge^ E, XGeom2d_Curve^ C, XTopoDS_Face^ F, Standard_Real Tol);

        //! Sets pcurves for the edge on the  closed face.  If
        //! <C1> or <C2> is a null handle, remove any existing
        //! pcurve.
        void UpdateEdge(XTopoDS_Edge^ E, XGeom2d_Curve^ C1,XGeom2d_Curve^ C2, XTopoDS_Face^ F, Standard_Real Tol);

        //! Sets a pcurve for the edge on the face.
        //! If <C> is a null handle, remove any existing pcurve.
        void UpdateEdge(XTopoDS_Edge^ E,  XGeom2d_Curve^ C, XGeom_Surface^ S, XTopLoc_Location^ L, Standard_Real Tol);

        //! Sets a pcurve for the edge on the face.
        //! If <C> is a null handle, remove any existing pcurve.
        //! Sets UV bounds for curve repsentation
        void UpdateEdge(XTopoDS_Edge^ E, XGeom2d_Curve^ C, XGeom_Surface^ S, XTopLoc_Location^ L, Standard_Real Tol, xgp_Pnt2d^ Pf, xgp_Pnt2d^ Pl);

        //! Sets pcurves for the edge on the closed surface.
        //! <C1> or <C2> is a null handle, remove any existing
        //! pcurve.
        void UpdateEdge(XTopoDS_Edge^ E, XGeom2d_Curve^ C1, XGeom2d_Curve^ C2, XGeom_Surface^ S, XTopLoc_Location^ L, Standard_Real Tol);

        //! Sets pcurves for the edge on the closed surface.
        //! <C1> or <C2> is a null handle, remove any existing
        //! pcurve.
        //! Sets UV bounds for curve repsentation
        void UpdateEdge(XTopoDS_Edge^ E, XGeom2d_Curve^ C1, XGeom2d_Curve^ C2, XGeom_Surface^ S, XTopLoc_Location^ L, Standard_Real Tol, xgp_Pnt2d^ Pf, xgp_Pnt2d^ Pl);

        //! Changes an Edge 3D polygon.
        //! A null Polygon removes the 3d Polygon.
        void UpdateEdge(XTopoDS_Edge^ E, Handle(Poly_Polygon3D)& P);

        //! Changes an Edge 3D polygon.
        //! A null Polygon removes the 3d Polygon.
        void UpdateEdge(XTopoDS_Edge^ E, Handle(Poly_Polygon3D)& P, XTopLoc_Location^ L);

        //! Changes an Edge polygon on Triangulation.
        void UpdateEdge(XTopoDS_Edge^ E, Handle(Poly_PolygonOnTriangulation)& N, Handle(Poly_Triangulation)& T);

        //! Changes an Edge polygon on Triangulation.
        void UpdateEdge(XTopoDS_Edge^ E, Handle(Poly_PolygonOnTriangulation)& N, Handle(Poly_Triangulation)& T, XTopLoc_Location^ L);

        //! Changes an Edge polygon on Triangulation.
        void UpdateEdge(XTopoDS_Edge^ E, Handle(Poly_PolygonOnTriangulation)& N1, Handle(Poly_PolygonOnTriangulation)& N2, Handle(Poly_Triangulation)& T);

        //! Changes an Edge polygon on Triangulation.
        void UpdateEdge(XTopoDS_Edge^ E, Handle(Poly_PolygonOnTriangulation)& N1, Handle(Poly_PolygonOnTriangulation)& N2, Handle(Poly_Triangulation)& T, XTopLoc_Location^ L);

        //! Changes Edge polygon on a face.
        void UpdateEdge(XTopoDS_Edge^ E, Handle(Poly_Polygon2D)& P, XTopoDS_Face^ S);

        //! Changes Edge polygon on a face.
        void UpdateEdge(XTopoDS_Edge^ E, Handle(Poly_Polygon2D)& P, XGeom_Surface^ S, XTopLoc_Location^ T);

        //! Changes Edge polygons on a face.
        //!
        //! A null Polygon removes the 2d Polygon.
        void UpdateEdge(XTopoDS_Edge^ E, Handle(Poly_Polygon2D)& P1, Handle(Poly_Polygon2D)& P2, XTopoDS_Face^ S);

        //! Changes Edge polygons on a face.
        //!
        //! A null Polygon removes the 2d Polygon.
        void UpdateEdge(XTopoDS_Edge^ E, Handle(Poly_Polygon2D)& P1, Handle(Poly_Polygon2D)& P2, XGeom_Surface^ S, XTopLoc_Location^ L);

        //! Updates the edge tolerance.
        void UpdateEdge(XTopoDS_Edge^ E, Standard_Real Tol);

        //! Sets the geometric continuity on the edge.
        void Continuity(XTopoDS_Edge^ E, XTopoDS_Face^ F1, XTopoDS_Face^ F2, XGeomAbs_Shape C);

        //! Sets the geometric continuity on the edge.
        void Continuity(XTopoDS_Edge^ E, XGeom_Surface^ S1, XGeom_Surface^ S2, XTopLoc_Location^ L1, XTopLoc_Location^ L2, XGeomAbs_Shape C);

        //! Sets the same parameter flag for the edge <E>.
        void SameParameter(XTopoDS_Edge^ E, Standard_Boolean S);

        //! Sets the same range flag for the edge <E>.
        void SameRange(XTopoDS_Edge^ E, Standard_Boolean S);

        //! Sets the degenerated flag for the edge <E>.
        void Degenerated(XTopoDS_Edge^ E, Standard_Boolean D);

        //! Sets the range of the 3d curve if Only3d=TRUE,
        //! otherwise sets the range to all the representations
        //!  Standard_Boolean Only3d = Standard_False
        void Range(XTopoDS_Edge^ E, Standard_Real First, Standard_Real Last, Standard_Boolean Only3d);

        //! Sets the range  of the edge  on the pcurve on  the
        //! surface.
        void Range(XTopoDS_Edge^ E, XGeom_Surface^ S, XTopLoc_Location^ L, Standard_Real First, Standard_Real Last);

        //! Sets the range of the edge on the pcurve on the face.
        void Range(XTopoDS_Edge^ E, XTopoDS_Face^ F, Standard_Real First, Standard_Real Last);

        //! Add  to <Eout>  the  geometric representations  of
        //! <Ein>.
        void Transfert(XTopoDS_Edge^ Ein, XTopoDS_Edge^ Eout);

        //! Makes an udefined vertex without geometry.
        void MakeVertex(XTopoDS_Vertex^ V);

        //! Makes a vertex from a 3D point.
        void MakeVertex(XTopoDS_Vertex^ V, xgp_Pnt^ P, Standard_Real Tol);

        //! Sets a 3D point on the vertex.
        void UpdateVertex(XTopoDS_Vertex^ V, xgp_Pnt^ P, Standard_Real Tol);

        //! Sets  the parameter  for the   vertex on the  edge
        //! curves.
        void UpdateVertex(XTopoDS_Vertex^ V, Standard_Real P, XTopoDS_Edge^ E, Standard_Real Tol);

        //! Sets  the parameter  for the  vertex  on the  edge
        //! pcurve  on the face.
        void UpdateVertex(XTopoDS_Vertex^ V, Standard_Real P, XTopoDS_Edge^ E, XTopoDS_Face^ F, Standard_Real Tol);

        //! Sets  the parameter  for the  vertex  on the  edge
        //! pcurve  on the surface.
        void UpdateVertex(XTopoDS_Vertex^ V, Standard_Real P, XTopoDS_Edge^ E, XGeom_Surface^ S, XTopLoc_Location^ L, Standard_Real Tol);

        //! Sets the parameters for the vertex on the face.
        void UpdateVertex(XTopoDS_Vertex^ Ve, Standard_Real U, Standard_Real V, XTopoDS_Face^ F, Standard_Real Tol);

        //! Updates the vertex tolerance.
        void UpdateVertex(XTopoDS_Vertex^ V, Standard_Real Tol);

        //! Transfert the parameters  of   Vin on  Ein as  the
        //! parameter of Vout on Eout.
        void Transfert(XTopoDS_Edge^ Ein, XTopoDS_Edge^ Eout, XTopoDS_Vertex^ Vin, XTopoDS_Vertex^ Vout);

        /// <summary>
        /// ±¾µØ¾ä±ú
        /// </summary>
        virtual property TopoDS_Builder* IHandle {
            TopoDS_Builder* get() Standard_OVERRIDE {
                return NativeHandle;
            }
            void set(TopoDS_Builder* handle) Standard_OVERRIDE {
                NativeHandle = static_cast<BRep_Builder*>(handle);
            }
        }

    private:
        BRep_Builder* NativeHandle;
    };
}
#endif // _XBRep_Builder_HeaderFile
