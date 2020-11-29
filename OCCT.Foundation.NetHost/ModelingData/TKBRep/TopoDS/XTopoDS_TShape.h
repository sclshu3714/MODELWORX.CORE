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

#ifndef _XTopoDS_TShape_HeaderFile
#define _XTopoDS_TShape_HeaderFile
#pragma once
#include <NCollection_Haft.h>
#include "TopoDS_TShape.hxx"   
#include <XTopAbs.h>
#include <XTopAbs_ShapeEnum.h>
#include "XTopoDS_Iterator.h"


#include <Standard_Type.hxx>
#include <TopoDS_ListOfShape.hxx>


class TopoDS_Builder;

//! A TShape  is a topological  structure describing a
//! set of points in a 2D or 3D space.
//!
//! A topological shape is a structure made from other
//! shapes.  This is a deferred class  used to support
//! topological objects.
//!
//! TShapes are   defined   by  their  optional domain
//! (geometry)  and  their  components  (other TShapes
//! with  Locations and Orientations).  The components
//! are stored in a List of Shapes.
//!
//! A   TShape contains  the   following boolean flags :
//!
//! - Free       : Free or Frozen.
//! - Modified   : Has been modified.
//! - Checked    : Has been checked.
//! - Orientable : Can be oriented.
//! - Closed     : Is closed (note that only Wires and Shells may be closed).
//! - Infinite   : Is infinite.
//! - Convex     : Is convex.
//!
//! Users have no direct access to the classes derived
//! from TShape.  They  handle them with   the classes
//! derived from Shape.

namespace TKBRep {
    ref class XTopoDS_Iterator;
    public ref class XTopoDS_TShape //: public Standard_Transient
    {

    public:

        XTopoDS_TShape(Handle(TopoDS_TShape) pos);


        Handle(TopoDS_TShape) GetTShape();

        void SetTShapeHandle(Handle(TopoDS_TShape) pos);

        //! Returns the free flag.
        Standard_Boolean Free();

        //! Sets the free flag.
        void Free(Standard_Boolean theIsFree);

        //! Returns the locked flag.
        Standard_Boolean Locked();

        //! Sets the locked flag.
        void Locked(Standard_Boolean theIsLocked);

        //! Returns the modification flag.
        Standard_Boolean Modified();

        //! Sets the modification flag.
        void Modified(Standard_Boolean theIsModified);

        //! Returns the checked flag.
        Standard_Boolean Checked();

        //! Sets the checked flag.
        void Checked(Standard_Boolean theIsChecked);

        //! Returns the orientability flag.
        Standard_Boolean Orientable();

        //! Sets the orientability flag.
        void Orientable(Standard_Boolean theIsOrientable);

        //! Returns the closedness flag.
        Standard_Boolean Closed();

        //! Sets the closedness flag.
        void Closed(Standard_Boolean theIsClosed);

        //! Returns the infinity flag.
        Standard_Boolean Infinite();

        //! Sets the infinity flag.
        void Infinite(Standard_Boolean theIsInfinite);

        //! Returns the convexness flag.
        Standard_Boolean Convex();

        //! Sets the convexness flag.
        void Convex(Standard_Boolean theIsConvex);

        //! Returns the type as a term of the ShapeEnum enum :
        //! VERTEX, EDGE, WIRE, FACE, ....
        virtual XTopAbs_ShapeEnum ShapeType();

        //! Returns a copy  of the  TShape  with no sub-shapes.
        virtual XTopoDS_TShape^ EmptyCopy();

        //! Returns the number of direct sub-shapes (children).
        //! @sa TopoDS_Iterator for accessing sub-shapes
        Standard_Integer NbChildren();

        //! Dumps the content of me into the stream
        //! Standard_Integer theDepth = -1
        void DumpJson(Standard_OStream theOStream, Standard_Integer theDepth);

        //friend class TopoDS_Iterator;
        //friend class TopoDS_Builder;


        //! DEFINE_STANDARD_RTTIEXT(TopoDS_TShape, Standard_Transient)

            /// <summary>
            /// ±¾µØ¾ä±ú
            /// </summary>
        virtual property Handle(TopoDS_TShape) IHandle {
            Handle(TopoDS_TShape) get() {
                return NativeHandle();
            }
            void set(Handle(TopoDS_TShape) shape) {
                NativeHandle() = shape;
            }
        }
    private:
        NCollection_Haft<Handle(TopoDS_TShape)> NativeHandle;
    };

    //! DEFINE_STANDARD_HANDLE(TopoDS_TShape, Standard_Transient)
}
#endif // _XTopoDS_TShape_HeaderFile
