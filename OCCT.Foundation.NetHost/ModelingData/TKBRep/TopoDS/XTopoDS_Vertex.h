// Created on: 1990-12-13
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

#ifndef _XTopoDS_Vertex_HeaderFile
#define _XTopoDS_Vertex_HeaderFile
#pragma once
#include <TopoDS_Vertex.hxx>
#include <XTopoDS_Shape.h>

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <TopoDS_Shape.hxx>


//! Describes a vertex which
//! - references an underlying vertex with the potential
//! to be given a location and an orientation
//! - has a location for the underlying vertex, giving its
//! placement in the local coordinate system
//! - has an orientation for the underlying vertex, in
//! terms of its geometry (as opposed to orientation in
//! relation to other shapes).
namespace TKBRep {
    public ref class XTopoDS_Vertex : public XTopoDS_Shape
    {
    public:

        //! DEFINE_STANDARD_ALLOC


        //! Undefined Vertex.
        XTopoDS_Vertex();


        //! Undefined Face.
        XTopoDS_Vertex(TopoDS_Vertex pos);

        //!
        virtual TopoDS_Vertex GetVertex();
        //!
        virtual TopoDS_Shape GetShape() Standard_OVERRIDE;

        /// <summary>
        /// ±¾µØ¾ä±ú
        /// </summary>
        virtual property TopoDS_Shape* IHandle {
            TopoDS_Shape* get() Standard_OVERRIDE {
                return NativeHandle;
            }
            void set(TopoDS_Shape* shape) Standard_OVERRIDE {
                NativeHandle = static_cast<TopoDS_Vertex*>(shape);
            }
        }
    private:
        TopoDS_Vertex* NativeHandle;
    };
}
#endif // _XTopoDS_Vertex_HeaderFile
