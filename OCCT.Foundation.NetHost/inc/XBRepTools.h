// Created on: 1992-08-28
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

#ifndef _XBRepTools_HeaderFile
#define _XBRepTools_HeaderFile
#pragma once
#include <BRepTools.hxx>
#include <XStandard_Helper.h>

#include <XTopoDS_Face.h>
#include <XTopoDS_Wire.h>
#include <XTopoDS_Edge.h>
#include <XTopoDS_Vertex.h>
#include <XTopoDS_Shell.h>
#include <XTopoDS_Solid.h>
#include <XTopoDS_CompSolid.h>
#include <XTopoDS_Compound.h>
#include <XTopoDS_Shape.h>
#include <XBRep_Builder.h>
#include <XGeom_Curve.h>
#include <XGeom2d_Curve.h>
#include <XGeom_Surface.h>

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <Standard_Real.hxx>
#include <Standard_Boolean.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <Standard_OStream.hxx>
#include <Standard_IStream.hxx>
#include <Standard_CString.hxx>

#include <Message_ProgressIndicator.hxx>

class TopoDS_Face;
class TopoDS_Wire;
class TopoDS_Edge;
class Bnd_Box2d;
class TopoDS_Vertex;
class TopoDS_Shell;
class TopoDS_Solid;
class TopoDS_CompSolid;
class TopoDS_Compound;
class TopoDS_Shape;
class Message_ProgressIndicator;
class BRep_Builder;
class BRepTools_WireExplorer;
class BRepTools_Modification;
class BRepTools_Modifier;
class BRepTools_TrsfModification;
class BRepTools_NurbsConvertModification;
class BRepTools_GTrsfModification;
class BRepTools_Substitution;
class BRepTools_Quilt;
class BRepTools_ShapeSet;
class BRepTools_ReShape;
class Geom_Curve;
class Geom2d_Curve;
class Geom_Surface;


//! The BRepTools package provides  utilities for BRep
//! data structures.
//!
//! * WireExplorer : A tool to explore the topology of
//! a wire in the order of the edges.
//!
//! * ShapeSet :  Tools used for  dumping, writing and
//! reading.
//!
//! * UVBounds : Methods to compute the  limits of the
//! boundary  of a  face,  a wire or   an edge in  the
//! parametric space of a face.
//!
//! *  Update : Methods  to call when   a topology has
//! been created to compute all missing data.
//!
//! * UpdateFaceUVPoints: Method to update the UV points
//! stored with the edges on a face.
//!
//! * Compare : Method to compare two vertices.
//!
//! * Compare : Method to compare two edges.
//!
//! * OuterWire : A method to find the outer wire of a
//! face.
//!
//! * Map3DEdges : A method to map all the 3D Edges of
//! a Shape.
//!
//! * Dump : A method to dump a BRep object.
using namespace TKG3d;
using namespace TKG2d;
namespace TKBRep {
    ref class XTopoDS_Face;
    ref class XTopoDS_Wire;
    ref class XTopoDS_Edge;
    ref class XTopoDS_Vertex;
    ref class XTopoDS_Shell;
    ref class XTopoDS_Solid;
    ref class XTopoDS_CompSolid;
    ref class XTopoDS_Compound;
    ref class XTopoDS_Shape;
    ref class TKG3d::XGeom_Curve;
    ref class TKG2d::XGeom2d_Curve;
    ref class TKG3d::XGeom_Surface;
    public ref class XBRepTools
    {
    public:

        //! DEFINE_STANDARD_ALLOC

        //! Returns in UMin,  UMax, VMin,  VMax  the  bounding
        //! values in the parametric space of F.
        static void UVBounds(XTopoDS_Face^ F, Standard_Real UMin, Standard_Real UMax, Standard_Real VMin, Standard_Real VMax);

        //! Returns in UMin,  UMax, VMin,  VMax  the  bounding
        //! values of the wire in the parametric space of F.
        static void UVBounds(XTopoDS_Face^ F, XTopoDS_Wire^ W, Standard_Real UMin, Standard_Real UMax, Standard_Real VMin, Standard_Real VMax);

        //! Returns in UMin,  UMax, VMin,  VMax  the  bounding
        //! values of the edge in the parametric space of F.
        static void UVBounds(XTopoDS_Face^ F, XTopoDS_Edge^ E, Standard_Real UMin, Standard_Real UMax, Standard_Real VMin, Standard_Real VMax);

        //! Adds  to  the box <B>  the bounding values in  the
        //! parametric space of F.
        static void AddUVBounds(XTopoDS_Face^ F, Bnd_Box2d& B);

        //! Adds  to the box  <B>  the bounding  values of the
        //! wire in the parametric space of F.
        static void AddUVBounds(XTopoDS_Face^ F, XTopoDS_Wire^ W, Bnd_Box2d& B);

        //! Adds to  the box <B>  the  bounding values  of the
        //! edge in the parametric space of F.
        static void AddUVBounds(XTopoDS_Face^ F, XTopoDS_Edge^ E, Bnd_Box2d& B);

        //! Update a vertex (nothing is done)
        static void Update(XTopoDS_Vertex^ V);

        //! Update an edge, compute 2d bounding boxes.
        static void Update(XTopoDS_Edge^ E);

        //! Update a wire (nothing is done)
        static void Update(XTopoDS_Wire^ W);

        //! Update a Face, update UV points.
        static void Update(XTopoDS_Face^ F);

        //! Update a shell (nothing is done)
        static void Update(XTopoDS_Shell^ S);

        //! Update a solid (nothing is done)
        static void Update(XTopoDS_Solid^ S);

        //! Update a composite solid (nothing is done)
        static void Update(XTopoDS_CompSolid^ C);

        //! Update a compound (nothing is done)
        static void Update(XTopoDS_Compound^ C);

        //! Update a shape, call the corect update.
        static void Update(XTopoDS_Shape^ S);

        //! For each edge of the face <F> reset the UV points
        //! to the bounding points of the parametric curve of the
        //! edge on the face.
        static void UpdateFaceUVPoints(XTopoDS_Face^ theF);

        //! Removes all the triangulations of the faces of <S>
        //! and removes all polygons on triangulations of the
        //! edges.
        static void Clean(XTopoDS_Shape^ S);

        //! Removes geometry (curves and surfaces) from all edges and faces of the shape
        static void CleanGeometry(XTopoDS_Shape^ theShape);

        //! Removes all the pcurves of the edges of <S> that
        //! refer to surfaces not belonging to any face of <S>
        static void RemoveUnusedPCurves(XTopoDS_Shape^ S);

        //! verifies that each face from the shape <S> has got
        //! a triangulation  with a  deflection <= deflec  and
        //! the edges a discretisation on  this triangulation.
        static Standard_Boolean Triangulation(XTopoDS_Shape^ S, Standard_Real deflec);

        //! Returns  True if  the    distance between the  two
        //! vertices is lower than their tolerance.
        static Standard_Boolean Compare(XTopoDS_Vertex^ V1, XTopoDS_Vertex^ V2);

        //! Returns  True if  the    distance between the  two
        //! edges is lower than their tolerance.
        static Standard_Boolean Compare(XTopoDS_Edge^ E1, XTopoDS_Edge^ E2);

        //! Returns the outer most wire of <F>. Returns a Null
        //! wire if <F> has no wires.
        static XTopoDS_Wire^ OuterWire(XTopoDS_Face^ F);

        //! Stores in the map  <M> all the 3D topology edges
        //! of <S>.
        static void Map3DEdges(XTopoDS_Shape^ S, TopTools_IndexedMapOfShape& M);

        //! Verifies that the edge  <E> is found two  times on
        //! the face <F> before calling BRep_Tool::IsClosed.
        static Standard_Boolean IsReallyClosed(XTopoDS_Edge^ E, XTopoDS_Face^ F);

        //! Detect closedness of face in U and V directions
        static void DetectClosedness(XTopoDS_Face^ theFace, Standard_Boolean theUclosed, Standard_Boolean theVclosed);

        //! Dumps the topological structure and the geometry
        //! of <Sh> on the stream <S>.
        static void Dump(XTopoDS_Shape^ Sh, Standard_OStream S);

        //! Writes <Sh> on <S> in an ASCII format.
        //! PR = NULL
        static void Write(XTopoDS_Shape^ Sh, Standard_OStream S, const Message_ProgressRange& PR);

        //! Reads a Shape  from <S> in  returns it in  <Sh>.
        //! <B> is used to build the shape.
        //! PR = NULL
        static void Read(XTopoDS_Shape^ Sh, Standard_IStream S, XBRep_Builder^ B, const Message_ProgressRange& PR);

        //! Writes <Sh> in <File>.
        //! PR = NULL
        static Standard_Boolean Write(XTopoDS_Shape^ Sh, Standard_CString File, const Message_ProgressRange& PR);

        //! Reads a Shape  from <File>,  returns it in  <Sh>.
        //! <B> is used to build the shape.
        //! PR = NULL
        static Standard_Boolean Read(XTopoDS_Shape^ Sh, Standard_CString File, XBRep_Builder^ B, const Message_ProgressRange& PR);

        //! Evals real tolerance of edge  <theE>.
        //! <theC3d>, <theC2d>, <theS>, <theF>, <theL> are
        //! correspondently 3d curve of edge, 2d curve on surface <theS> and
        //! rang of edge
        //! If calculated tolerance is more then current edge tolerance, edge is updated.
        //! Method returns actual tolerance of edge
        static Standard_Real EvalAndUpdateTol(XTopoDS_Edge^ theE, XGeom_Curve^ theC3d, XGeom2d_Curve^ theC2d, XGeom_Surface^ theS,Standard_Real theF,Standard_Real theL);
    };
}
#endif // _XBRepTools_HeaderFile
