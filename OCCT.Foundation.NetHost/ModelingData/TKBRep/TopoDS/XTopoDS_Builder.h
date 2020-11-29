// Created on: 1991-02-21
// Created by: Remi Lequette
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

#ifndef _XTopoDS_Builder_HeaderFile
#define _XTopoDS_Builder_HeaderFile
#pragma once
#include <TopoDS_Builder.hxx>
#include <XTopoDS_Shape.h>
#include <XTopoDS_TShape.h>
#include <XTopoDS_Wire.h>
#include <XTopoDS_Shell.h>
#include <XTopoDS_Solid.h>
#include <XTopoDS_CompSolid.h>
#include <XTopoDS_Compound.h>

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

class Standard_NullObject;
class TopoDS_FrozenShape;
class TopoDS_UnCompatibleShapes;



//! A  Builder is used   to  create  Topological  Data
//! Structures.It is the root of the Builder class hierarchy.
//!
//! There are three groups of methods in the Builder :
//!
//! The Make methods create Shapes.
//!
//! The Add method includes a Shape in another Shape.
//!
//! The Remove  method  removes a  Shape from an other
//! Shape.
//!
//! The methods in Builder are not static. They can be
//! redefined in inherited builders.
//!
//! This   Builder does not  provide   methods to Make
//! Vertices,  Edges, Faces,  Shells  or Solids. These
//! methods are  provided  in  the inherited  Builders
//! as they must provide the geometry.
//!
//! The Add method check for the following rules :
//!
//! - Any SHAPE can be added in a COMPOUND.
//!
//! - Only SOLID can be added in a COMPSOLID.
//!
//! - Only SHELL, EDGE and VERTEX can be added in a SOLID.
//! EDGE and VERTEX as to be INTERNAL or EXTERNAL.
//!
//! - Only FACE can be added in a SHELL.
//!
//! - Only WIRE and VERTEX can be added in a FACE.
//! VERTEX as to be INTERNAL or EXTERNAL.
//!
//! - Only EDGE can be added in a WIRE.
//!
//! - Only VERTEX can be added in an EDGE.
//!
//! - Nothing can be added in a VERTEX.
//! 
namespace TKBRep {
    ref class XTopoDS_Shape;
    ref class XTopoDS_TShape;
    ref class XTopoDS_Wire;
    ref class XTopoDS_Shell;
    ref class XTopoDS_Solid;
    ref class XTopoDS_CompSolid;
    ref class XTopoDS_Compound;
    public ref class XTopoDS_Builder
    {
    public:

        //! DEFINE_STANDARD_ALLOC
        void SetBuilderHandle(TopoDS_Builder* pos);

        //! Make an empty Wire.
        void XTopoDS_Builder::MakeWire(XTopoDS_Wire^ W);

        //! Make an empty Shell.
        void XTopoDS_Builder::MakeShell(XTopoDS_Shell^ S);

        //! Make a Solid covering the whole 3D space.
        void XTopoDS_Builder::MakeSolid(XTopoDS_Solid^ S);

        //! Make an empty Composite Solid.
        void XTopoDS_Builder::MakeCompSolid(XTopoDS_CompSolid^ C);

        //! Make an empty Compound.
        void XTopoDS_Builder::MakeCompound(XTopoDS_Compound^ C);

        //! Add the Shape C in the Shape S.
        //! Exceptions
        //! - TopoDS_FrozenShape if S is not free and cannot be modified.
        //! - TopoDS__UnCompatibleShapes if S and C are not compatible.
        void XTopoDS_Builder::Add(XTopoDS_Shape^ S, XTopoDS_Shape^ C);

        //! Remove the Shape C from the Shape S.
        //! Exceptions
        //! TopoDS_FrozenShape if S is frozen and cannot be modified.
        void XTopoDS_Builder::Remove(XTopoDS_Shape^ S, XTopoDS_Shape^ C);

        /// <summary>
        /// ±¾µØ¾ä±ú
        /// </summary>
        virtual property TopoDS_Builder* IHandle {
            TopoDS_Builder* get() {
                return NativeHandle;
            }
            void set(TopoDS_Builder* shape) {
                NativeHandle = shape;
            }
        }
    private:
        TopoDS_Builder* NativeHandle;
    };
}
#endif // _XTopoDS_Builder_HeaderFile
