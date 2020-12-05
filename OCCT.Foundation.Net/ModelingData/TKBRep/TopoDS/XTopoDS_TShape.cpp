// Created on: 1991-03-20
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

#include <XTopoDS_TShape.h>
#include <XTopoDS_Shape.h>
#include <Standard_Dump.hxx>

namespace TKBRep {

    XTopoDS_TShape::XTopoDS_TShape(Handle(TopoDS_TShape) pos) {
        NativeHandle() = pos;
    };


    Handle(TopoDS_TShape) XTopoDS_TShape::GetTShape() {
        return NativeHandle();
    };

    void XTopoDS_TShape::SetTShapeHandle(Handle(TopoDS_TShape) pos) {
        NativeHandle() = pos;
    };

    //! Returns the free flag.
    Standard_Boolean XTopoDS_TShape::Free() {
        return NativeHandle()->Free();
    };

    //! Sets the free flag.
    void XTopoDS_TShape::Free(Standard_Boolean theIsFree) {
        NativeHandle()->Free(theIsFree);
    };

    //! Returns the locked flag.
    Standard_Boolean XTopoDS_TShape::Locked() {
        return NativeHandle()->Locked();
    };

    //! Sets the locked flag.
    void XTopoDS_TShape::Locked(Standard_Boolean theIsLocked) {
        NativeHandle()->Locked(theIsLocked);
    };

    //! Returns the modification flag.
    Standard_Boolean XTopoDS_TShape::Modified() {
        return NativeHandle()->Modified();
    };

    //! Sets the modification flag.
    void XTopoDS_TShape::Modified(Standard_Boolean theIsModified) {
        NativeHandle()->Modified(theIsModified);
    };

    //! Returns the checked flag.
    Standard_Boolean XTopoDS_TShape::Checked() {
        return NativeHandle()->Checked();
    };

    //! Sets the checked flag.
    void XTopoDS_TShape::Checked(Standard_Boolean theIsChecked) {
        NativeHandle()->Checked(theIsChecked);
    };

    //! Returns the orientability flag.
    Standard_Boolean XTopoDS_TShape::Orientable() {
        return NativeHandle()->Orientable();
    };

    //! Sets the orientability flag.
    void XTopoDS_TShape::Orientable(Standard_Boolean theIsOrientable) {
        NativeHandle()->Orientable(theIsOrientable);
    };

    //! Returns the closedness flag.
    Standard_Boolean XTopoDS_TShape::Closed() {
        return NativeHandle()->Closed();
    };

    //! Sets the closedness flag.
    void XTopoDS_TShape::Closed(Standard_Boolean theIsClosed) {
        NativeHandle()->Closed(theIsClosed);
    };

    //! Returns the infinity flag.
    Standard_Boolean XTopoDS_TShape::Infinite() {
        return NativeHandle()->Infinite();
    };

    //! Sets the infinity flag.
    void XTopoDS_TShape::Infinite(Standard_Boolean theIsInfinite) {
        NativeHandle()->Infinite(theIsInfinite);
    };

    //! Returns the convexness flag.
    Standard_Boolean XTopoDS_TShape::Convex() {
        return NativeHandle()->Convex();
    };

    //! Sets the convexness flag.
    void XTopoDS_TShape::Convex(Standard_Boolean theIsConvex) {
        NativeHandle()->Convex(theIsConvex);
    };

    //! Returns the type as a term of the ShapeEnum enum :
    //! VERTEX, EDGE, WIRE, FACE, ....
    XTopAbs_ShapeEnum XTopoDS_TShape::ShapeType() {
        return safe_cast<XTopAbs_ShapeEnum>(NativeHandle()->ShapeType());
    };

    //! Returns a copy  of the  TShape  with no sub-shapes.
    XTopoDS_TShape^ XTopoDS_TShape::EmptyCopy() {
        return gcnew XTopoDS_TShape(NativeHandle()->EmptyCopy());
    };

    //! Returns the number of direct sub-shapes (children).
    //! @sa TopoDS_Iterator for accessing sub-shapes
    Standard_Integer XTopoDS_TShape::NbChildren() {
        return NativeHandle()->NbChildren();
    };

    //! Dumps the content of me into the stream
    //! Standard_Integer theDepth = -1
    void XTopoDS_TShape::DumpJson(Standard_OStream theOStream, Standard_Integer theDepth) {
        return NativeHandle()->DumpJson(theOStream, theDepth);
    };
}
