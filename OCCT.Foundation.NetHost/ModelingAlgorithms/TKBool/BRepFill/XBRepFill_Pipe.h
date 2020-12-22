// Created on: 1994-06-07
// Created by: Bruno DUMORTIER
// Copyright (c) 1994-1999 Matra Datavision
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

#ifndef _XBRepFill_Pipe_HeaderFile
#define _XBRepFill_Pipe_HeaderFile
#pragma once
#include <BRepFill_Pipe.hxx>
#include <XGeomFill_Trihedron.h>
#include <XTopoDS_Wire.h>
#include <XTopoDS_Shape.h>
#include <XTopoDS_Face.h>
#include <XTopoDS_Edge.h>
#include <XTopoDS_Vertex.h>
#include <xgp_Pnt.h>
#include <XTopTools_ListOfShape.h>


#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <TopoDS_Wire.hxx>
#include <TopoDS_Shape.hxx>
#include <gp_Trsf.hxx>
#include <TopTools_HArray2OfShape.hxx>
#include <TopTools_MapOfShape.hxx>
#include <BRepFill_DataMapOfShapeHArray2OfShape.hxx>
#include <TopTools_DataMapOfShapeListOfShape.hxx>
#include <Standard_Integer.hxx>
#include <GeomAbs_Shape.hxx>
#include <GeomFill_Trihedron.hxx>
#include <Standard_Boolean.hxx>
#include <Standard_Real.hxx>
class BRepFill_LocationLaw;
class Standard_DomainError;
class StdFail_NotDone;
class TopoDS_Wire;
class TopoDS_Shape;
class TopoDS_Face;
class TopoDS_Edge;
class TopoDS_Vertex;
class gp_Pnt;
class BRepFill_Sweep;

using namespace TKBRep;
using namespace TKMath;
namespace TKBool {
    ref class TKBRep::XTopoDS_Wire;
    ref class TKBRep::XTopoDS_Shape;
    ref class TKBRep::XTopoDS_Face;
    ref class TKBRep::XTopoDS_Edge;
    ref class TKBRep::XTopoDS_Vertex;
    ref class TKBRep::XTopTools_ListOfShape;
    ref class TKMath::xgp_Pnt;
    //! Create a  shape by sweeping a shape  (the profile)
    //! along a wire (the spine).
    //!
    //! For each edge  or vertex from the spine  the  user
    //! may ask for the shape generated from each subshape
    //! of the profile.
    public ref class XBRepFill_Pipe
    {
    public:

        //! DEFINE_STANDARD_ALLOC


        XBRepFill_Pipe();

        XBRepFill_Pipe(BRepFill_Pipe* pos);

        void SetPipeHandle(BRepFill_Pipe* pos);

        BRepFill_Pipe* GetPipeHandle();

        //GeomFill_Trihedron aMode = GeomFill_IsCorrectedFrenet, Standard_Boolean ForceApproxC1 = Standard_False, Standard_Boolean GeneratePartCase = Standard_False
        XBRepFill_Pipe(XTopoDS_Wire^ Spine, XTopoDS_Shape^ Profile,XGeomFill_Trihedron aMode, Standard_Boolean ForceApproxC1, Standard_Boolean GeneratePartCase);

        //Standard_Boolean GeneratePartCase = Standard_False
        void Perform(XTopoDS_Wire^ Spine, XTopoDS_Shape^ Profile, Standard_Boolean GeneratePartCase);

        XTopoDS_Shape^ Spine();

        XTopoDS_Shape^ Profile();

        XTopoDS_Shape^ Shape();

        Standard_Real ErrorOnSurface();

        XTopoDS_Shape^ FirstShape();

        XTopoDS_Shape^ LastShape();

        //! Returns the  list   of shapes generated   from the
        //! shape <S>.
        void Generated(XTopoDS_Shape^ S, XTopTools_ListOfShape^ L);

        //! Returns the face created from an edge of the spine
        //! and an edge of the profile.
        //! if the edges are not in the spine or the profile
        XTopoDS_Face^ Face(XTopoDS_Edge^ ESpine, XTopoDS_Edge^ EProfile);

        //! Returns the edge created from an edge of the spine
        //! and a vertex of the profile.
        //! if the edge or the vertex are not in  the spine or
        //! the profile.
        XTopoDS_Edge^ Edge(XTopoDS_Edge^ ESpine, XTopoDS_Vertex^ VProfile);

        //! Returns  the shape created from the profile at the
        //! position of the vertex VSpine.
        //! if the vertex is not in the Spine
        XTopoDS_Shape^ Section(XTopoDS_Vertex^ VSpine);

        //! Create a Wire by sweeping the Point along the <spine>
        //! if the <Spine> is undefined
        XTopoDS_Wire^ PipeLine(xgp_Pnt^ Point);

        /// <summary>
        /// ±¾µØ¾ä±ú
        /// </summary>
        virtual property BRepFill_Pipe* IHandle {
            BRepFill_Pipe* get() {
                return NativeHandle;
            }
            void set(BRepFill_Pipe* handle) {
                NativeHandle = handle;
            }
        }

    private:
        BRepFill_Pipe* NativeHandle;
    };
}
#endif // _XBRepFill_Pipe_HeaderFile
