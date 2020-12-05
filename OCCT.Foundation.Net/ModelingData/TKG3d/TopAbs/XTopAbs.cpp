// Created on: 1991-04-23
// Created by: Remi LEQUETTE
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

#include <XTopAbs.h>
namespace TKG3d {
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
        //! static
    XTopAbs_Orientation XTopAbs::Compose(XTopAbs_Orientation Or1, XTopAbs_Orientation Or2) {
        return safe_cast<XTopAbs_Orientation>(TopAbs::Compose(safe_cast<TopAbs_Orientation>(Or1),safe_cast<TopAbs_Orientation>(Or2)));
    };

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
     //! static
    XTopAbs_Orientation XTopAbs::Reverse(XTopAbs_Orientation Or) {
        return safe_cast<XTopAbs_Orientation>(TopAbs::Reverse(safe_cast<TopAbs_Orientation>(Or)));
    };

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
     //! static
    XTopAbs_Orientation XTopAbs::Complement(XTopAbs_Orientation Or) {
        return safe_cast<XTopAbs_Orientation>(TopAbs::Complement(safe_cast<TopAbs_Orientation>(Or)));
    };


    //! Prints the name of the State <St> as a String on
    //! the Stream <S> and returns <S>.
     //! static
    Standard_OStream& XTopAbs::Print(XTopAbs_State St, Standard_OStream& S) {
        return TopAbs::Print(safe_cast<TopAbs_State>(St), S);
    };

    //! Returns the string name for a given shape type.
    //! @param theType shape type
    //! @return string identifier from the list COMPOUND, COMPSOLID, SOLID, SHELL, FACE, WIRE, EDGE, VERTEX, SHAPE
     //! static
    System::String^ XTopAbs::ShapeTypeToString(XTopAbs_ShapeEnum theType) {
        Standard_CString SCString = TopAbs::ShapeTypeToString(safe_cast<TopAbs_ShapeEnum>(theType));
        return XStandard_Helper::toString(SCString);
    };


    //! Determines the shape type from the given string identifier (using case-insensitive comparison).
    //! @param theTypeString string identifier
    //! @param theType detected shape type
    //! @return TRUE if string identifier is known
     //! static
    Standard_Boolean XTopAbs::ShapeTypeFromString(System::String^ theTypeString, XTopAbs_ShapeEnum theType) {
        TCollection_AsciiString TAsciiString = XStandard_Helper::toAsciiString(theTypeString);
        Standard_CString theString = TAsciiString.ToCString();
        TopAbs_ShapeEnum theShapeType = safe_cast<TopAbs_ShapeEnum>(theType);
        return TopAbs::ShapeTypeFromString(theString, theShapeType);
    };

    //! Returns the string name for a given shape orientation.
    //! @param theOrientation shape orientation
    //! @return string identifier from the list FORWARD, REVERSED, INTERNAL, EXTERNAL
     //! static
    System::String^ XTopAbs::ShapeOrientationToString(XTopAbs_Orientation theOrientation) {
        Standard_CString SCString = TopAbs::ShapeOrientationToString(safe_cast<TopAbs_Orientation>(theOrientation));
        return XStandard_Helper::toString(SCString);
    };

    //! Determines the shape orientation from the given string identifier (using case-insensitive comparison).
    //! @param theOrientationString string identifier
    //! @param theOrientation detected shape orientation
    //! @return TRUE if string identifier is known
     //! static
    Standard_Boolean XTopAbs::ShapeOrientationFromString(System::String^ theOrientationString, XTopAbs_Orientation theOrientation) {
        TCollection_AsciiString TAsciiString = XStandard_Helper::toAsciiString(theOrientationString);
        Standard_CString theTypeString = TAsciiString.ToCString();
        TopAbs_Orientation theType = safe_cast<TopAbs_Orientation>(theOrientation);
        return TopAbs::ShapeOrientationFromString(theTypeString, theType);
    };
}
