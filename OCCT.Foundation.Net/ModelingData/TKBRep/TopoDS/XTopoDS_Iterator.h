// Created on: 1993-01-21
// Created by: Remi LEQUETTE
// Copyright (c) 1993-1999 Matra Datavision
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

#ifndef _XTopoDS_Iterator_HeaderFile
#define _XTopoDS_Iterator_HeaderFile
#pragma once
#include <TopoDS_Iterator.hxx>
#include "XTopLoc_Location.h"
#include "NCollection_Haft.h"
#include <XTopoDS_Shape.h>

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <TopoDS_Shape.hxx>
#include <TopoDS_ListIteratorOfListOfShape.hxx>
#include <TopAbs_Orientation.hxx>
#include <TopLoc_Location.hxx>
#include <Standard_Boolean.hxx>
#include <gp_Dir2d.hxx>
class gp_Dir2d;
class Standard_NoMoreObject;
class Standard_NoSuchObject;


//! Iterates on the underlying shape underlying a given
//! TopoDS_Shape object, providing access to its
//! component sub-shapes. Each component shape is
//! returned as a TopoDS_Shape with an orientation,
//! and a compound of the original values and the relative values.
//! 
namespace TKBRep {
    ref class XTopoDS_Shape;
    public ref class XTopoDS_Iterator
    {
    public:

       //! DEFINE_STANDARD_ALLOC


        //! Creates an empty Iterator.
        XTopoDS_Iterator();

        //! Creates an Iterator on <S> sub-shapes.
        //! Note:
        //! - If cumOri is true, the function composes all
        //! sub-shapes with the orientation of S.
        //! - If cumLoc is true, the function multiplies all
        //! sub-shapes by the location of S, i.e. it applies to
        //! each sub-shape the transformation that is associated with S.
        //! Standard_Boolean cumOri = Standard_True, const Standard_Boolean cumLoc = Standard_True
        XTopoDS_Iterator(XTopoDS_Shape^ S, Standard_Boolean cumOri, Standard_Boolean cumLoc);

        //! Initializes this iterator with shape S.
        //! Note:
        //! - If cumOri is true, the function composes all
        //! sub-shapes with the orientation of S.
        //! - If cumLoc is true, the function multiplies all
        //! sub-shapes by the location of S, i.e. it applies to
        //! each sub-shape the transformation that is associated with S.
        //! Standard_Boolean cumOri = Standard_True, const Standard_Boolean cumLoc = Standard_True
        void Initialize(XTopoDS_Shape^ S, Standard_Boolean cumOri, const Standard_Boolean cumLoc);

        virtual TopoDS_Iterator  GetIterator();

        //! Returns true if there is another sub-shape in the
        //! shape which this iterator is scanning.
        Standard_Boolean More();

        //! Moves on to the next sub-shape in the shape which
        //! this iterator is scanning.
        //! Exceptions
        //! Standard_NoMoreObject if there are no more sub-shapes in the shape.
        void Next();

        //! Returns the current sub-shape in the shape which
        //! this iterator is scanning.
        //! Exceptions
        //! Standard_NoSuchObject if there is no current sub-shape.
        XTopoDS_Shape^ Value();

        /// <summary>
        /// ���ؾ��
        /// </summary>
        virtual property TopoDS_Iterator* IHandle {
            TopoDS_Iterator* get() {
                return NativeHandle;
            }
            void set(TopoDS_Iterator* shape) {
                NativeHandle = shape;
            }
        }
    private:
        TopoDS_Iterator* NativeHandle;
        //NCollection_Haft<Handle(TopoDS_Iterator)> NativeHandle;
    };
}
#endif // _XTopoDS_Iterator_HeaderFile
