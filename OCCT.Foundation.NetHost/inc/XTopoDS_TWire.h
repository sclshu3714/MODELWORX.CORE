// Created on: 1990-12-17
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

#ifndef _XTopoDS_TWire_HeaderFile
#define _XTopoDS_TWire_HeaderFile
#pragma once
#include <TopoDS_TWire.hxx>
#include <XTopoDS_TShape.h>
#include <XTopAbs_ShapeEnum.h>
#include <NCollection_Haft.h>

#include <Standard.hxx>
#include <Standard_Type.hxx>

#include <TopoDS_TShape.hxx>
#include <TopAbs_ShapeEnum.hxx>
class TopoDS_TShape;
class TopoDS_TWire;
//DEFINE_STANDARD_HANDLE(TopoDS_TWire, TopoDS_TShape)
namespace TKBRep {
    //! A set of edges connected by their vertices.
    public ref class XTopoDS_TWire : public XTopoDS_TShape
    {

    public:


        //! Creates an empty TWire.
        XTopoDS_TWire();

        XTopoDS_TWire(Handle(TopoDS_TWire) pos);

        void SetTWireHandle(Handle(TopoDS_TWire) pos);

        virtual Handle(TopoDS_TWire) GetTWire();

        virtual Handle(TopoDS_TShape) GetTShape() Standard_OVERRIDE;

        //! Returns WIRE.
        virtual XTopAbs_ShapeEnum ShapeType() Standard_OVERRIDE;

        //! Returns an empty TWire.
        virtual XTopoDS_TShape^ EmptyCopy() Standard_OVERRIDE;


        //! DEFINE_STANDARD_RTTIEXT(TopoDS_TWire, TopoDS_TShape)

        /// <summary>
        /// ±¾µØ¾ä±ú
        /// </summary>
        virtual property Handle(TopoDS_TShape) IHandle {
            Handle(TopoDS_TShape) get() Standard_OVERRIDE {
                return NativeHandle();
            }
            void set(Handle(TopoDS_TShape) shape)  Standard_OVERRIDE {
                NativeHandle() = Handle(TopoDS_TWire)::DownCast(shape);
            }
        }
    private:
        NCollection_Haft<Handle(TopoDS_TWire)> NativeHandle;
    };
}
#endif // _XTopoDS_TWire_HeaderFile
