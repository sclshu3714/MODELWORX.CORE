// Created on: 1990-12-11
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
#pragma once
#ifndef _XTopoDS_HeaderFile
#define _XTopoDS_HeaderFile
#include <TopoDS.hxx>
#include <XTopoDS_Vertex.h>;
#include <XTopoDS_Shape.h>;
#include <XTopoDS_Edge.h>;
#include <XTopoDS_Wire.h>;
#include <XTopoDS_Face.h>;
#include <XTopoDS_Shell.h>;
#include <XTopoDS_Solid.h>;
#include <XTopoDS_CompSolid.h>;
#include <XTopoDS_Compound.h>;
#include <XTopoDS_Shape.h>;
#include <XTopoDS_HShape.h>;
#include <XTopoDS_TShape.h>;
#include <XTopoDS_TVertex.h>;
#include <XTopoDS_Vertex.h>;
#include <XTopoDS_TEdge.h>;
#include <XTopoDS_Edge.h>;
#include <XTopoDS_TWire.h>;
#include <XTopoDS_Wire.h>;
#include <XTopoDS_TFace.h>;
#include <XTopoDS_Face.h>;
#include <XTopoDS_TShell.h>;
#include <XTopoDS_Shell.h>;
#include <XTopoDS_TSolid.h>;
#include <XTopoDS_Solid.h>;
#include <XTopoDS_TCompSolid.h>;
#include <XTopoDS_CompSolid.h>;
#include <XTopoDS_TCompound.h>;
#include <XTopoDS_Compound.h>;
#include <XTopoDS_Builder.h>;
#include <XTopoDS_Iterator.h>;



#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

class TopoDS_Vertex;
class TopoDS_Shape;
class TopoDS_Edge;
class TopoDS_Wire;
class TopoDS_Face;
class TopoDS_Shell;
class TopoDS_Solid;
class TopoDS_CompSolid;
class TopoDS_Compound;
class TopoDS_Shape;
class TopoDS_HShape;
class TopoDS_TShape;
class TopoDS_TVertex;
class TopoDS_Vertex;
class TopoDS_TEdge;
class TopoDS_Edge;
class TopoDS_TWire;
class TopoDS_Wire;
class TopoDS_TFace;
class TopoDS_Face;
class TopoDS_TShell;
class TopoDS_Shell;
class TopoDS_TSolid;
class TopoDS_Solid;
class TopoDS_TCompSolid;
class TopoDS_CompSolid;
class TopoDS_TCompound;
class TopoDS_Compound;
class TopoDS_Builder;
class TopoDS_Iterator;


//! Provides methods to cast objects of class
//! TopoDS_Shape to be onjects of more specialized
//! sub-classes. Types are verified, thus in the example
//! below, the first two blocks are correct but the third is
//! rejected by the compiler.
namespace TKBRep {
    ref class XTopoDS_Vertex;
    ref class XTopoDS_Shape;
    ref class XTopoDS_Edge;
    ref class XTopoDS_Wire;
    ref class XTopoDS_Face;
    ref class XTopoDS_Shell;
    ref class XTopoDS_Solid;
    ref class XTopoDS_CompSolid;
    ref class XTopoDS_Compound;
    ref class XTopoDS_Shape;
    ref class XTopoDS_HShape;
    ref class XTopoDS_TShape;
    ref class XTopoDS_TVertex;
    ref class XTopoDS_Vertex;
    ref class XTopoDS_TEdge;
    ref class XTopoDS_Edge;
    ref class XTopoDS_TWire;
    ref class XTopoDS_Wire;
    ref class XTopoDS_TFace;
    ref class XTopoDS_Face;
    ref class XTopoDS_TShell;
    ref class XTopoDS_Shell;
    ref class XTopoDS_TSolid;
    ref class XTopoDS_Solid;
    ref class XTopoDS_TCompSolid;
    ref class XTopoDS_CompSolid;
    ref class XTopoDS_TCompound;
    ref class XTopoDS_Compound;
    ref class XTopoDS_Builder;
    ref class XTopoDS_Iterator;
    public ref class XTopoDS
    {
    public:

        //! DEFINE_STANDARD_ALLOC

        //! Basic tool to access the data structure.
        //! Casts shape S to the more specialized return type, Vertex.
        //! Exceptions
        //! Standard_TypeMismatch if S cannot be cast to this return type.
        static XTopoDS_Vertex^ Vertex(XTopoDS_Shape^ S);

        //! Casts shape S to the more specialized return type, Edge
        //! Exceptions
        //! Standard_TypeMismatch if S cannot be cast to this return type.
        static XTopoDS_Edge^ Edge(XTopoDS_Shape^ S);

        //! Casts shape S to the more specialized return type, Wire.
        //! Exceptions
        //! Standard_TypeMismatch if S cannot be cast to this return type.
        static XTopoDS_Wire^ Wire(XTopoDS_Shape^ S);

        //! Casts shape S to the more specialized return type, Face.
        //! Exceptions
        //! Standard_TypeMismatch if S cannot be cast to this return type.
        static XTopoDS_Face^ Face(XTopoDS_Shape^ S);

        //! Casts shape S to the more specialized return type, Shell.
        //! Exceptions
        //! Standard_TypeMismatch if S cannot be cast to this return type.
        static XTopoDS_Shell^ Shell(XTopoDS_Shape^ S);

        //! Casts shape S to the more specialized return type, Solid.
        //! Exceptions
        //! Standard_TypeMismatch if S cannot be cast to this return type.
        static XTopoDS_Solid^ Solid(XTopoDS_Shape^ S);

        //! Casts shape S to the more specialized return type, CompSolid.
        //! Exceptions
        //! Standard_TypeMismatch if S cannot be cast to this return type.
        static XTopoDS_CompSolid^ CompSolid(XTopoDS_Shape^ S);

        //! Casts shape S to the more specialized return type, Compound.
        //! Exceptions
        //! Standard_TypeMismatch if S cannot be cast to this return type.
        static XTopoDS_Compound^ Compound(XTopoDS_Shape^ S);
    };
}
#endif // _XTopoDS_HeaderFile
