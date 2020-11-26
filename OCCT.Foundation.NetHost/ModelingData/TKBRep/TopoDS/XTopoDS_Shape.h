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

#ifndef _XTopoDS_Shape_HeaderFile
#define _XTopoDS_Shape_HeaderFile
#pragma once
#include <TopoDS_Shape.hxx>
#include "XTopLoc_Location.h"
#include "NCollection_Haft.h"
#include <XTopAbs_Orientation.h>
#include <XTopAbs_ShapeEnum.h>
//! Describes a shape which
//! - references an underlying shape with the potential
//! to be given a location and an orientation
//! - has a location for the underlying shape, giving its
//! placement in the local coordinate system
//! - has an orientation for the underlying shape, in
//! terms of its geometry (as opposed to orientation in
//! relation to other shapes).
//! Note: A Shape is empty if it references an underlying
//! shape which has an empty list of shapes.   
using namespace TKMath;
namespace TKBRep {
    ref class TKMath::XTopLoc_Location;
    public ref class XTopoDS_Shape
    {
    public:

        
        //! Creates a NULL Shape referring to nothing.
        XTopoDS_Shape(void);

        //! Creates a NULL Shape referring to nothing.
        XTopoDS_Shape(TopoDS_Shape pos);

        //! Creates a NULL Shape referring to nothing.
        XTopoDS_Shape(TopoDS_Shape* pos);

        ~XTopoDS_Shape();

        #ifndef OCCT_NO_RVALUE_REFERENCE

        //! Generalized moveructor, accepting also sub-classes
        //! (TopoDS_Shape hierarchy declares only fake sub-classes with no extra fields).
        template<class T2>
        XTopoDS_Shape(T2 theOther, typename std::enable_if<opencascade::std::is_base_of<TopoDS_Shape, T2>::value>::type*);

        //! Generalized move assignment operator.
        template<class T2>
        typename std::enable_if<opencascade::std::is_base_of<TopoDS_Shape, T2>::value, TopoDS_Shape>::type^
            operator= (T2 theOther) {
            return *this;
        };
        #endif

        //!
        TopoDS_Shape GetShape();

        //! Returns true if this shape is null. In other words, it
        //! references no underlying shape with the potential to
        //! be given a location and an orientation.
        Standard_Boolean^ IsNull();

        //! Destroys the reference to the underlying shape
        //! stored in this shape. As a result, this shape becomes null.
        void Nullify();

        //! Returns the shape local coordinate system.
        XTopLoc_Location^ Location();

        //! Sets the shape local coordinate system.
        void Location(XTopLoc_Location^ theLoc);

        //! Returns a  shape  similar to <me> with   the local
        //! coordinate system set to <Loc>.
        XTopoDS_Shape^ Located(XTopLoc_Location^ theLoc);

        //! Returns the shape orientation.
        XTopAbs_Orientation Orientation();

        //! Sets the shape orientation.
        void Orientation(XTopAbs_Orientation theOrient);

        //! Returns  a    shape  similar  to  <me>   with  the
        //! orientation set to <Or>.
        XTopoDS_Shape^ Oriented(XTopAbs_Orientation theOrient);

        //! Returns a handle to the actual shape implementation.
        Handle(TopoDS_TShape) TShape();

        //! Returns the value of the TopAbs_ShapeEnum
        //! enumeration that corresponds to this shape, for
        //! example VERTEX, EDGE, and so on.
        //! Exceptions
        //! Standard_NullObject if this shape is null.
        XTopAbs_ShapeEnum ShapeType();

        //! Returns the free flag.
        Standard_Boolean^ Free();

        //! Sets the free flag.
        void Free(Standard_Boolean theIsFree);

        //! Returns the locked flag.
        Standard_Boolean^ Locked();

        //! Sets the locked flag.
        void Locked(Standard_Boolean theIsLocked);

        //! Returns the modification flag.
        Standard_Boolean^ Modified();

        //! Sets the modification flag.
        void Modified(Standard_Boolean theIsModified);

        //! Returns the checked flag.
        Standard_Boolean^ Checked();

        //! Sets the checked flag.
        void Checked(Standard_Boolean theIsChecked);

        //! Returns the orientability flag.
        Standard_Boolean^ Orientable();

        //! Sets the orientability flag.
        void Orientable(Standard_Boolean theIsOrientable);

        //! Returns the closedness flag.
        Standard_Boolean^ Closed();

        //! Sets the closedness flag.
        void Closed(Standard_Boolean theIsClosed);

        //! Returns the infinity flag.
        Standard_Boolean^ Infinite();

        //! Sets the infinity flag.
        void Infinite(Standard_Boolean theIsInfinite);

        //! Returns the convexness flag.
        Standard_Boolean^ Convex();

        //! Sets the convexness flag.
        void Convex(Standard_Boolean theIsConvex);

        //! Multiplies the Shape location by thePosition.
        void Move(XTopLoc_Location^ thePosition);

        //! Returns a shape similar to <me> with a location multiplied by thePosition.
        XTopoDS_Shape^ Moved(XTopLoc_Location^ thePosition);

        //! Reverses the orientation, using the Reverse method
        //! from the TopAbs package.
        void Reverse();

        //! Returns    a shape  similar    to  <me>  with  the
        //! orientation  reversed, using  the   Reverse method
        //! from the TopAbs package.
        XTopoDS_Shape^ Reversed();

        //! Complements the orientation, using the  Complement
        //! method from the TopAbs package.
        void Complement();

        //! Returns  a   shape  similar  to   <me>   with  the
        //! orientation complemented,  using   the  Complement
        //! method from the TopAbs package.
        XTopoDS_Shape^ Complemented();

        //! Updates the Shape Orientation by composition with theOrient,
        //! using the Compose method from the TopAbs package.
        void Compose(XTopAbs_Orientation theOrient);

        //! Returns  a  shape   similar   to  <me>   with  the
        //! orientation composed with theOrient, using the
        //! Compose method from the TopAbs package.
        XTopoDS_Shape^ Composed(XTopAbs_Orientation theOrient);

        //! Returns the number of direct sub-shapes (children).
        //! @sa TopoDS_Iterator for accessing sub-shapes
        Standard_Integer^ NbChildren();

        //! Returns True if two shapes  are partners, i.e.  if
        //! they   share   the   same  TShape.  Locations  and
        //! Orientations may differ.
        Standard_Boolean^ IsPartner(XTopoDS_Shape^ theOther);

        //! Returns True if two shapes are same, i.e.  if they
        //! share  the  same TShape  with the same  Locations.
        //! Orientations may differ.
        Standard_Boolean^ IsSame(XTopoDS_Shape^ theOther);

        //! Returns True if two shapes are equal, i.e. if they
        //! share the same TShape with  the same Locations and
        //! Orientations.
        Standard_Boolean^ IsEqual(XTopoDS_Shape^ theOther);

        Standard_Boolean^ operator == (XTopoDS_Shape^ theOther) { return IsEqual(theOther); }

        //! Negation of the IsEqual method.
        Standard_Boolean^ IsNotEqual(XTopoDS_Shape^ theOther) { return !IsEqual(theOther); }
        Standard_Boolean^ operator != (XTopoDS_Shape^ theOther) { return IsNotEqual(theOther); }

        //! Returns a hashed value denoting <me>. This value is in the range [1, theUpperBound]. It is computed from the
        //! TShape and the Location. The Orientation is not used.
        //! @param theUpperBound the upper bound of the range a computing hash code must be within
        //! @return a computed hash code, in the range [1, theUpperBound]
        Standard_Integer^ HashCode(Standard_Integer theUpperBound);

        //! Replace   <me> by  a  new   Shape with the    same
        //! Orientation and Location and a new TShape with the
        //! same geometry and no sub-shapes.
        void EmptyCopy();

        //! Returns a new Shape with the  same Orientation and
        //! Location and  a new TShape  with the same geometry
        //! and no sub-shapes.
        XTopoDS_Shape^ EmptyCopied();

        void TShape(Handle(TopoDS_TShape) theTShape);

        void TShape(XTopoDS_Shape^ theTShape);

        //! Dumps the content of me into the stream
        void DumpJson(Standard_OStream theOStream, Standard_Integer theDepth);


        /// <summary>
        /// ±¾µØ¾ä±ú
        /// </summary>
        property TopoDS_Shape* Handle
        {
            TopoDS_Shape* get() {
                return NativeHandle;
            }
        }
    private:
        TopoDS_Shape* NativeHandle;

    };
}

#endif // _XTopoDS_Shape_HeaderFile