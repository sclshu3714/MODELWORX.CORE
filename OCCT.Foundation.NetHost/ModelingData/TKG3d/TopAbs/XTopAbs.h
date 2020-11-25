// Created on: 1992-01-24
// Created by: Remi LEQUETTE
// Copyright (c) 1992-1999 Matra Datavision
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

#ifndef _XTopAbs_HeaderFile
#define _XTopAbs_HeaderFile
#pragma once
#include <TopAbs.hxx>

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>
#include "XStandard_Helper.h"

#include <TCollection_AsciiString.hxx>
#include <TopAbs_Orientation.hxx>
#include <Standard_OStream.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <TopAbs_State.hxx>
#include "XTopAbs_Orientation.h"
#include "XTopAbs_ShapeEnum.h"
#include "XTopAbs_State.h"


//! This package gives resources for Topology oriented
//! applications such as : Topological Data Structure,
//! Topological Algorithms.
//!
//! It contains :
//!
//! * The ShapeEnum   enumeration  to  describe  the
//! differents topological shapes.
//!
//! * The  Orientation  enumeration to  describe the
//! orientation of a topological shape.
//!
//! * The  State    enumeration  to  describes  the
//! position of a point relative to a Shape.
//!
//! * Methods to manage the enumerations.
using namespace TKernel;
namespace TKG3d {
    ref class TKernel::XStandard_Helper;
    public ref class XTopAbs
    {
    public:

        //! DEFINE_STANDARD_ALLOC


        //! Compose  the Orientation    <Or1>  and  <Or2>.    This
        //! composition is not symmetric (if  you switch <Or1> and
        //! <Or2> the result  is different). It assumes that <Or1>
        //! is the Orientation of a Shape S1 containing a Shape S2
        //! of Orientation   Or2.  The result    is the  cumulated
        //! orientation of S2 in S1.  The composition law is :
        //!
        //! \ Or2     FORWARD  REVERSED INTERNAL EXTERNAL
        //! Or1       -------------------------------------
        //! FORWARD   | FORWARD  REVERSED INTERNAL EXTERNAL
        //! |
        //! REVERSED  | REVERSED FORWARD  INTERNAL EXTERNAL
        //! |
        //! INTERNAL  | INTERNAL INTERNAL INTERNAL INTERNAL
        //! |
        //! EXTERNAL  | EXTERNAL EXTERNAL EXTERNAL EXTERNAL
        //! Note: The top corner in the table is the most important
        //! for the purposes of Open CASCADE topology and shape sharing.
        static XTopAbs_Orientation Compose(XTopAbs_Orientation Or1, XTopAbs_Orientation Or2);

        //! xchanges the interior/exterior status of the two
        //! sides. This is what happens when the sense of
        //! direction is reversed. The following rules apply:
        //!
        //! FORWARD          REVERSED
        //! REVERSED         FORWARD
        //! INTERNAL         INTERNAL
        //! EXTERNAL         EXTERNAL
        //!
        //! Reverse exchange the material sides.
        static XTopAbs_Orientation Reverse(XTopAbs_Orientation Or);

        //! Reverses the interior/exterior status of each side of
        //! the object. So, to take the complement of an object
        //! means to reverse the interior/exterior status of its
        //! boundary, i.e. inside becomes outside.
        //! The method returns the complementary orientation,
        //! following the rules in the table below:
        //! FORWARD          REVERSED
        //! REVERSED         FORWARD
        //! INTERNAL         EXTERNAL
        //! EXTERNAL         INTERNAL
        //!
        //! Complement  complements   the  material  side.  Inside
        //! becomes outside.
        static XTopAbs_Orientation Complement(XTopAbs_Orientation Or);

        //! Prints the name of Shape type as a String on the Stream.
        static Standard_OStream& Print(XTopAbs_ShapeEnum theShapeType, Standard_OStream& theStream)
        {
            System::String^ SString = ShapeTypeToString(theShapeType);
            TCollection_AsciiString TAsciiString = XStandard_Helper::toAsciiString(SString);
            return (theStream << TAsciiString.ToCString());
        }

        //! Prints the name of the Orientation as a String on the Stream.
        static Standard_OStream& Print(XTopAbs_Orientation theOrientation, Standard_OStream& theStream)
        {
            System::String^ SString = ShapeOrientationToString(theOrientation);
            TCollection_AsciiString TAsciiString = XStandard_Helper::toAsciiString(SString);
            return (theStream << TAsciiString.ToCString());
        }

        //! Prints the name of the State <St> as a String on
        //! the Stream <S> and returns <S>.
        static Standard_OStream& Print(XTopAbs_State St, Standard_OStream& S);

        //! Returns the string name for a given shape type.
        //! @param theType shape type
        //! @return string identifier from the list COMPOUND, COMPSOLID, SOLID, SHELL, FACE, WIRE, EDGE, VERTEX, SHAPE
        static System::String^ ShapeTypeToString(XTopAbs_ShapeEnum theType);

        //! Returns the shape type from the given string identifier (using case-insensitive comparison).
        //! @param theTypeString string identifier
        //! @return shape type or TopAbs_SHAPE if string identifier is invalid
        static XTopAbs_ShapeEnum ShapeTypeFromString(System::String^ theTypeString)
        {
            XTopAbs_ShapeEnum aType = XTopAbs_ShapeEnum(TopAbs_SHAPE);
            ShapeTypeFromString(theTypeString, aType);
            return aType;
        }

        //! Determines the shape type from the given string identifier (using case-insensitive comparison).
        //! @param theTypeString string identifier
        //! @param theType detected shape type
        //! @return TRUE if string identifier is known
        static Standard_Boolean ShapeTypeFromString(System::String^ theTypeString, XTopAbs_ShapeEnum theType);

        //! Returns the string name for a given shape orientation.
        //! @param theOrientation shape orientation
        //! @return string identifier from the list FORWARD, REVERSED, INTERNAL, EXTERNAL
        static System::String^ ShapeOrientationToString(XTopAbs_Orientation theOrientation);

        //! Returns the shape orientation from the given string identifier (using case-insensitive comparison).
        //! @param theOrientationString string identifier
        //! @return shape orientation or TopAbs_FORWARD if string identifier is invalid
        static XTopAbs_Orientation ShapeOrientationFromString(System::String^ theOrientationString)
        {
            XTopAbs_Orientation aType = XTopAbs_Orientation(TopAbs_FORWARD);
            ShapeOrientationFromString(theOrientationString, aType);
            return aType;
        }

        //! Determines the shape orientation from the given string identifier (using case-insensitive comparison).
        //! @param theOrientationString string identifier
        //! @param theOrientation detected shape orientation
        //! @return TRUE if string identifier is known
        static Standard_Boolean ShapeOrientationFromString(System::String^ theOrientationString, XTopAbs_Orientation theOrientation);
    };
}
#endif // _TopAbs_HeaderFile
