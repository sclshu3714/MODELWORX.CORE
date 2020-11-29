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

#include <XTopoDS_HShape.h>

namespace TKBRep {

    //! Constructs an empty shape object
    XTopoDS_HShape::XTopoDS_HShape() {
        NativeHandle() = new TopoDS_HShape();
    };

    //! Constructs a shape object defined by the shape aShape.
    XTopoDS_HShape::XTopoDS_HShape(XTopoDS_Shape^ aShape) {
        NativeHandle() = new TopoDS_HShape(aShape->GetShape());
    };

    //! Loads this shape with the shape aShape
    void XTopoDS_HShape::Shape(XTopoDS_Shape^ aShape) {
        NativeHandle()->Shape(aShape->GetShape());
    };

    //! Returns a reference to a constant TopoDS_Shape based on this shape.
    XTopoDS_Shape^ XTopoDS_HShape::Shape() {
        return gcnew XTopoDS_Shape(NativeHandle()->Shape());
    };


    //! Exchanges the TopoDS_Shape object defining this
    //! shape for another one referencing the same underlying shape
    //! Accesses the list of shapes within the underlying
    //! shape referenced by the TopoDS_Shape object.
    //! Returns a reference to a TopoDS_Shape based on
    //! this shape. The TopoDS_Shape can be modified.
    XTopoDS_Shape^ XTopoDS_HShape::ChangeShape() {
        return gcnew XTopoDS_Shape(NativeHandle()->ChangeShape());
    };
}