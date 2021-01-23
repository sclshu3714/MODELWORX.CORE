// Created on: 1995-06-28
// Created by: Modelistation
// Copyright (c) 1995-1999 Matra Datavision
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

#ifndef _XTopoDS_HShape_HeaderFile
#define _XTopoDS_HShape_HeaderFile
#pragma once       
#include "NCollection_Haft.h"
#include <TopoDS_HShape.hxx>
#include <XTopoDS_Shape.h>

#include <Standard.hxx>
#include <Standard_Type.hxx>
#include <Standard_Transient.hxx>
#include <gp_Dir2d.hxx>
class gp_Dir2d;

//class TopoDS_HShape;
//DEFINE_STANDARD_HANDLE(TopoDS_HShape, Standard_Transient)

namespace TKBRep {
    ref class XTopoDS_Shape;
    //! Class to manipulate a Shape with  handle.
   public ref class XTopoDS_HShape //: public Standard_Transient
    {

    public:

        !XTopoDS_HShape() { IHandle = NULL; };
        ~XTopoDS_HShape() { IHandle = NULL; };
        //! Constructs an empty shape object
        XTopoDS_HShape();

        //! Constructs a shape object defined by the shape aShape.
        XTopoDS_HShape(XTopoDS_Shape^ aShape);

        //! Loads this shape with the shape aShape
        void Shape(XTopoDS_Shape^ aShape);

        //!
        virtual TopoDS_HShape GetHShape();

        //! Returns a reference to a constant TopoDS_Shape based on this shape.
        XTopoDS_Shape^ Shape();


        //! Exchanges the TopoDS_Shape object defining this
        //! shape for another one referencing the same underlying shape
        //! Accesses the list of shapes within the underlying
        //! shape referenced by the TopoDS_Shape object.
        //! Returns a reference to a TopoDS_Shape based on
        //! this shape. The TopoDS_Shape can be modified.
        XTopoDS_Shape^ ChangeShape();




       //! DEFINE_STANDARD_RTTIEXT(TopoDS_HShape, Standard_Transient)

            /// <summary>
            /// ±¾µØ¾ä±ú
            /// </summary>
        virtual property Handle(TopoDS_HShape) IHandle {
            Handle(TopoDS_HShape) get() {
                return NativeHandle();
            }
            void set(Handle(TopoDS_HShape) shape) {
                NativeHandle() = shape;
            }
        }
    private:
        NCollection_Haft<Handle(TopoDS_HShape)> NativeHandle;
    };
}
#endif // _XTopoDS_HShape_HeaderFile
