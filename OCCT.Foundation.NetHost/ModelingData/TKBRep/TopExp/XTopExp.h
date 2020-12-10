// Created on: 1990-12-20
// Created by: Remi Lequette
// Copyright (c) 1990-1999 Matra Datavision
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

#ifndef _XTopExp_HeaderFile
#define _XTopExp_HeaderFile
#pragma once
#include <TopExp.hxx>
#include <XTopoDS_Shape.h>
#include <XTopoDS_Vertex.h>
#include <XTopoDS_Edge.h>
#include <XTopoDS_Wire.h>
#include <XTopExp_Explorer.h>

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <TopAbs_ShapeEnum.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <TopTools_IndexedDataMapOfShapeListOfShape.hxx>
#include <TopTools_MapOfShape.hxx>
#include <Standard_Boolean.hxx>
class TopoDS_Shape;
class TopoDS_Vertex;
class TopoDS_Edge;
class TopoDS_Wire;
class TopExp_Explorer;
namespace TKBRep {

    ref class XTopoDS_Shape;
    ref class XTopoDS_Vertex;
    ref class XTopoDS_Edge;
    ref class XTopoDS_Wire;
    ref class XTopExp_Explorer;
    //! This package   provides  basic tools  to   explore the
    //! topological data structures.
    //!
    //! * Explorer : A tool to find all sub-shapes of  a given
    //! type. e.g. all faces of a solid.
    //!
    //! * Package methods to map sub-shapes of a shape.
    //!
    //! Level : Public
    //! All methods of all  classes will be public.
    public ref class XTopExp
    {
    public:

        //! DEFINE_STANDARD_ALLOC


        //! Tool to explore a topological data structure.
        //! Stores in the map <M> all  the sub-shapes of <S>
        //! of type <T>.
        //!
        //! Warning: The map is not cleared at first.
        static void MapShapes(XTopoDS_Shape^ S, XTopAbs_ShapeEnum T, TopTools_IndexedMapOfShape& M);

        //! Stores in the map <M> all  the sub-shapes of <S>.
        static void MapShapes(XTopoDS_Shape^ S, TopTools_IndexedMapOfShape& M);

        //! Stores in the map <M> all  the sub-shapes of <S>.
        static void MapShapes(XTopoDS_Shape^ S, TopTools_MapOfShape& M);

        //! Stores in the map <M> all the subshape of <S> of
        //! type <TS>  for each one append  to  the list all
        //! the ancestors of type <TA>.  For example map all
        //! the edges and bind the list of faces.
        //! Warning: The map is not cleared at first.
        static void MapShapesAndAncestors(XTopoDS_Shape^ S, XTopAbs_ShapeEnum TS, XTopAbs_ShapeEnum TA, TopTools_IndexedDataMapOfShapeListOfShape& M);

        //! Stores in the map <M> all the subshape of <S> of
        //! type <TS> for each one append to the list all
        //! unique ancestors of type <TA>.  For example map all
        //! the edges and bind the list of faces.
        //! useOrientation = True : taking account the ancestor orientation
        //! Warning: The map is not cleared at first.
        //! Standard_Boolean useOrientation = Standard_False
        static void MapShapesAndUniqueAncestors(XTopoDS_Shape^ S, XTopAbs_ShapeEnum TS, XTopAbs_ShapeEnum TA, TopTools_IndexedDataMapOfShapeListOfShape& M, Standard_Boolean useOrientation);

        //! Returns the Vertex of orientation FORWARD in E. If
        //! there is none returns a Null Shape.
        //! CumOri = True : taking account the edge 
        //! Standard_Boolean CumOri = Standard_False
        static XTopoDS_Vertex^ FirstVertex(XTopoDS_Edge^ E, Standard_Boolean CumOri);

        //! Returns the Vertex of orientation REVERSED in E. If
        //! there is none returns a Null Shape.
        //! CumOri = True : taking account the edge orientation
        //! Standard_Boolean CumOri = Standard_False
        static XTopoDS_Vertex^ LastVertex(XTopoDS_Edge^ E, Standard_Boolean CumOri);

        //! Returns in Vfirst, Vlast the  FORWARD and REVERSED
        //! vertices of the edge <E>. May be null shapes.
        //! CumOri = True : taking account the edge orientation
        //! Standard_Boolean CumOri = Standard_False
        static void Vertices(XTopoDS_Edge^ E, XTopoDS_Vertex^ Vfirst, XTopoDS_Vertex^ Vlast, Standard_Boolean CumOri);

        //! Returns  in  Vfirst,  Vlast   the first   and last
        //! vertices of the open wire <W>. May be null shapes.
        //! if   <W>  is closed Vfirst and Vlast  are a same
        //! vertex on <W>.
        //! if <W> is no manifold. VFirst and VLast are null
        //! shapes.
        static void Vertices(XTopoDS_Wire^ W, XTopoDS_Vertex^ Vfirst, XTopoDS_Vertex^ Vlast);

        //! Finds   the  vertex <V> common   to  the two edges
        //! <E1,E2>, returns True if this vertex exists.
        //!
        //! Warning: <V> has sense only if the value <True> is returned
        static Standard_Boolean CommonVertex(XTopoDS_Edge^ E1, XTopoDS_Edge^ E2, XTopoDS_Vertex^ V);

    //    /// <summary>
    //   /// ±¾µØ¾ä±ú
    //   /// </summary>
    //    virtual property TopExp_Explorer* IHandle {
    //        TopExp_Explorer* get() { //Standard_OVERRIDE {
    //            return NativeHandle;
    //        }
    //        void set(TopExp_Explorer* shape) { // Standard_OVERRIDE {
    //            NativeHandle = shape;
    //        }
    //    }
    //private:
    //    TopExp_Explorer* NativeHandle;
    };
}
#endif // _XTopExp_HeaderFile
