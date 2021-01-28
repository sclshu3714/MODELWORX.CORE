// Copyright (c) 2016 OPEN CASCADE SAS
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

#ifndef _XQuantity_ColorRGBA_HeaderFile
#define _XQuantity_ColorRGBA_HeaderFile
#pragma once
#include "Quantity_ColorRGBA.hxx"
#include "XQuantity_Color.h"
#include "XQuantity_TypeOfColor.h"
#include "XQuantity_NameOfColor.h"
#include <Standard_Assert.hxx>
//#include "XStandard_Helper.h"

//! The pair of Quantity_Color and Alpha component (1.0 opaque, 0.0 transparent).
using namespace System;
namespace TKernel {
    //ref class XStandard_Helper;
    //ref class XQuantity_Color;
    public ref class XQuantity_ColorRGBA
    {
    public:

        //! Creates a color with the default value.
        XQuantity_ColorRGBA();

        //! Creates the color with specified RGB value.
        XQuantity_ColorRGBA(XQuantity_Color^ theRgb);

        //! Creates the color with specified RGBA values.
        XQuantity_ColorRGBA(XQuantity_Color^ theRgb, float theAlpha);

        //! Creates the color from RGBA vector.
        XQuantity_ColorRGBA(array<float,1> theRgba);

        //! Creates the color from RGBA values.
        XQuantity_ColorRGBA(float theRed, float theGreen, float theBlue, float theAlpha);

        //! Assign new values to the color.
        void SetValues(float theRed, float theGreen, float theBlue, float theAlpha);

        //! Return RGB color value.
        XQuantity_Color^ GetRGB();

        //! Modify RGB color components without affecting alpha value.
        XQuantity_Color^ ChangeRGB();

        //! Assign RGB color components without affecting alpha value.
        void SetRGB(XQuantity_Color^ theRgb);

        //! Return alpha value (1.0 means opaque, 0.0 means fully transparent).
        Standard_ShortReal Alpha();

        //! Assign the alpha value.
        void SetAlpha(Standard_ShortReal theAlpha);

        //! Return the color as vector of 4 float elements.
        operator array<Standard_Real, 1>& () {
           NCollection_Vec4<float> NVec4 = *(NCollection_Vec4<float>*)this->NativeHandle;
           //array<Standard_Real, 1> P = array<Standard_Real,1>();
        };

        //! Returns true if the distance between colors is greater than Epsilon().
        bool IsDifferent(XQuantity_ColorRGBA^ theOther);

        //! Returns true if the distance between colors is greater than Epsilon().
        bool operator!= (XQuantity_ColorRGBA^ theOther) { return IsDifferent(theOther); };

        //! Two colors are considered to be equal if their distance is no greater than Epsilon().
        bool IsEqual(XQuantity_ColorRGBA^ theOther);

        //! Two colors are considered to be equal if their distance is no greater than Epsilon().
        bool operator== (XQuantity_ColorRGBA^ theOther) { return IsEqual(theOther); };

        //! Finds color from predefined names.
        //! For example, the name of the color which
        //! corresponds to "BLACK" is Quantity_NOC_BLACK.
        //! Returns false if name is unknown.
        //! An alpha component is set to 1.0.
        //! @param theColorNameString the color name
        //! @param theColor a found color
        //! @return false if the color name is unknown, or true if the search by color name was successful
        static Standard_Boolean ColorFromName(Standard_CString theColorNameString, XQuantity_ColorRGBA^ theColor);

        //! Parses the string as a hex color (like "#FF0" for short RGB color, "#FF0F" for short RGBA color,
        //! "#FFFF00" for RGB color, or "#FFFF00FF" for RGBA color)
        //! @param theHexColorString the string to be parsed
        //! @param theColor a color that is a result of parsing
        //! @param theAlphaComponentIsOff the flag that indicates if a color alpha component is presented
        //! in the input string (false) or not (true)
        //! @return true if parsing was successful, or false otherwise
        //! bool          theAlphaComponentIsOff = false
        static bool ColorFromHex(char* theHexColorString, XQuantity_ColorRGBA^ theColor,bool theAlphaComponentIsOff);

        //! Returns hex sRGBA string in format "#RRGGBBAA".
        //! bool theToPrefixHash = true
        static TCollection_AsciiString ColorToHex(XQuantity_ColorRGBA^ theColor, bool theToPrefixHash);

        //! Dumps the content of me into the stream
        //! const Standard_Integer theDepth = -1
        void DumpJson(Standard_OStream& theOStream, Standard_Integer theDepth);

        /// <summary>
        /// ±¾µØ¾ä±ú
        /// </summary>
        virtual property Quantity_ColorRGBA* IHandle {
            Quantity_ColorRGBA* get() {
                return NativeHandle;
            }
            void set(Quantity_ColorRGBA* handle) {
                NativeHandle = handle;
            }
        };
    private:
        Quantity_ColorRGBA* NativeHandle;
    };
}
#endif // _XQuantity_ColorRGBA_HeaderFile
