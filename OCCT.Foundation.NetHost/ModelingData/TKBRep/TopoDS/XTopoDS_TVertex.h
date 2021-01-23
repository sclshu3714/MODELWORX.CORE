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

#ifndef _XTopoDS_TVertex_HeaderFile
#define _XTopoDS_TVertex_HeaderFile
#pragma once
#include <TopoDS_Vertex.hxx>
#include <XTopoDS_TShape.h>
#include <XTopAbs_ShapeEnum.h>
#include <NCollection_Haft.h>

#include <Standard.hxx>
#include <Standard_Type.hxx>
#include <TopoDS_TShape.hxx>
#include <TopoDS_TVertex.hxx>

class TopoDS_TShape;
class TopoDS_TVertex;
//!DEFINE_STANDARD_HANDLE(TopoDS_TVertex, TopoDS_TShape)

namespace TKBRep {
    //! A  Vertex is a topological  point in  two or three
    //! dimensions.
    public ref class XTopoDS_TVertex : public XTopoDS_TShape
    {

    public:
        !XTopoDS_TVertex() { IHandle = NULL; };
        ~XTopoDS_TVertex() { IHandle = NULL; };

        XTopoDS_TVertex();

        XTopoDS_TVertex(Handle(TopoDS_TVertex) pos);

        void SetTVertexHandle(Handle(TopoDS_TVertex) pos);

        virtual Handle(TopoDS_TVertex) GetTVertex();

        virtual Handle(TopoDS_TShape) GetTShape() Standard_OVERRIDE;

        //! Returns VERTEX.
        virtual XTopAbs_ShapeEnum ShapeType() Standard_OVERRIDE;
        /// <summary>
        /// ±¾µØ¾ä±ú
        /// </summary>
        virtual property Handle(TopoDS_TShape) IHandle {
            Handle(TopoDS_TShape) get() Standard_OVERRIDE {
                return NativeHandle();
            }
            void set(Handle(TopoDS_TShape) shape)  Standard_OVERRIDE {
                NativeHandle() = Handle(TopoDS_TVertex)::DownCast(shape);
            }
        }
    private:
        NCollection_Haft<Handle(TopoDS_TVertex)> NativeHandle;
    };
}
#endif // _XTopoDS_TVertex_HeaderFile
