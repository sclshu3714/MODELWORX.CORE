// Created by: NW,JPB,CAL
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

#ifndef _XQuantity_Color_HeaderFile
#define _XQuantity_Color_HeaderFile
#pragma once
#include "XStandard_Helper.h"
#include "Quantity_Color.hxx"
#include "XQuantity_TypeOfColor.h"
#include "XQuantity_NameOfColor.h"

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>
#include <Standard_ShortReal.hxx>

#include <Quantity_NameOfColor.hxx>
#include <Quantity_TypeOfColor.hxx>
#include <TCollection_AsciiString.hxx>
#include <NCollection_Vec4.hxx>
class Quantity_ColorDefinitionError;


//! This class allows the definition of a colour.
//! The names of the colours are from the X11 specification.
//! color object may be used for numerous applicative purposes.
//! A color is defined by:
//! -   its respective quantities of red, green and blue (R-G-B values), or
//! -   its hue angle and its values of lightness and  saturation (H-L-S values).
//! These two color definition systems are equivalent.
//! Use this class in conjunction with:
//! -   the Quantity_TypeOfColor enumeration
//! which identifies the color definition system you are using,
//! -   the Quantity_NameOfColor enumeration
//! which lists numerous predefined colors and
//! identifies them by their name.
using namespace System;
namespace TKernel {
    //ref class XStandard_Helper;
    public ref class XQuantity_Color
    {
    public:

        //£¡ DEFINE_STANDARD_ALLOC

        //! Creates Quantity_NOC_YELLOW color.
        XQuantity_Color();

        //! Creates the color from enumeration value.
        XQuantity_Color(XQuantity_NameOfColor AName);

        //! Creates the color from enumeration value.
        XQuantity_Color(Quantity_Color* pos);

        //! Creates the color from enumeration value.
        XQuantity_Color(XQuantity_Color^ AName);

        //! Creates a color according to the definition system theType.
        //! Quantity_TOC_RGB:
        //!  - theR1 the value of Red   within range [0.0; 1.0]
        //!  - theR2 the value of Green within range [0.0; 1.0]
        //!  - theR3 the value of Blue  within range [0.0; 1.0]
        //!
        //! Quantity_TOC_HLS:
        //!  - theR1 is the Hue (H) angle in degrees within range [0.0; 360.0], 0.0 being Red.
        //!    Value -1.0 is a special value reserved for grayscale color (S should be 0.0).
        //!  - theR2 is the Lightness  (L) within range [0.0; 1.0]
        //!  - theR3 is the Saturation (S) within range [0.0; 1.0]
        XQuantity_Color(const Standard_Real theR1, Standard_Real theR2,  Standard_Real theR3, XQuantity_TypeOfColor theType);

        //! Quantity_Color
        Quantity_Color* GetColor();

        //! Define color from RGB values.
        explicit XQuantity_Color(const NCollection_Vec3<float>& theRgb);

        //! Increases or decreases the contrast by <ADelta>.
        //! <ADelta> is a percentage. Any value greater than zero
        //! will increase the contrast.
        //! The variation is expressed as a percentage of the
        //! current value.
        //! It is a variation of the saturation.
        void ChangeContrast(const Standard_Real ADelta);

        //! Increases or decreases the intensity by <ADelta>.
        //! <ADelta> is a percentage. Any value greater than zero
        //! will increase the intensity.
        //! The variation is expressed as a percentage of the
        //! current value.
        //! It is a variation of the lightness.
        void ChangeIntensity(const Standard_Real ADelta);

        //! Updates the colour <me> from the definition of the
        //! colour <AName>.
        void SetValues(const XQuantity_NameOfColor AName);

        //! Updates a color according to the mode specified by theType.
        //! Quantity_TOC_RGB:
        //!  - theR1 the value of Red   within range [0.0; 1.0]
        //!  - theR2 the value of Green within range [0.0; 1.0]
        //!  - theR3 the value of Blue  within range [0.0; 1.0]
        //!
        //! Quantity_TOC_HLS:
        //!  - theR1 is the Hue (H) angle in degrees within range [0.0; 360.0], 0.0 being Red.
        //!    -1.0 is a special value reserved for grayscale color (S should be 0.0).
        //!  - theR2 is the Lightness  (L) within range [0.0; 1.0]
        //!  - theR3 is the Saturation (S) within range [0.0; 1.0]
        void SetValues(const Standard_Real theR1, Standard_Real theR2, Standard_Real theR3, XQuantity_TypeOfColor theType);

        //! Returns the percentage change of contrast and intensity
        //! between <me> and <AColor>.
        //! <DC> and <DI> are percentages, either positive or negative.
        //! The calculation is with respect to the current value of <me>
        //! If <DC> is positive then <me> is more contrasty.
        //! If <DI> is positive then <me> is more intense.
        void Delta(XQuantity_Color^ AColor, Standard_Real% DC, Standard_Real% DI);

        //! Returns the distance between two colours. It's a
        //! value between 0 and the square root of 3
        //! (the black/white distance)
        Standard_Real Distance(XQuantity_Color^ AColor);

        //! Returns the square of distance between two colours.
        Standard_Real SquareDistance(XQuantity_Color^ AColor);

        //! Returns the Blue component (quantity of blue) of the color within range [0.0; 1.0].
        Standard_Real Blue();

        //! Returns the Green component (quantity of green) of the color within range [0.0; 1.0].
        Standard_Real Green();

        //! Returns the Hue component (hue angle) of the color
        //! in degrees within range [0.0; 360.0], 0.0 being Red.
        //! -1.0 is a special value reserved for grayscale color (S should be 0.0)
        Standard_Real Hue();

        //! Returns Standard_True if the distance between <me> and
        //! <Other> is greater than Epsilon ().
        Standard_Boolean IsDifferent(XQuantity_Color^ Other);
        Standard_Boolean operator != (XQuantity_Color^ Other)
        {
            return IsDifferent(Other);
        }

        //! Returns true if the Other color is
        //! -   different from, or
        //! -   equal to this color.
        //! Two colors are considered to be equal if their
        //! distance is no greater than Epsilon().
        //! These methods are aliases of operator != and operator ==.
        Standard_Boolean IsEqual(XQuantity_Color^ Other);
        Standard_Boolean operator == (XQuantity_Color^ Other)
        {
            return IsEqual(Other);
        }

        //! Returns the Light component (value of the lightness) of the color within range [0.0; 1.0].
        Standard_Real Light();

        //! Returns the name of the color defined by its
        //! quantities of red R, green G and blue B; more
        //! precisely this is the nearest color from the
        //! Quantity_NameOfColor enumeration.
        //! Exceptions
        //! Standard_OutOfRange if R, G or B is less than 0. or greater than 1.
        XQuantity_NameOfColor Name();

        //! Returns the Red component (quantity of red) of the color within range [0.0; 1.0].
        Standard_Real Red();

        //! Returns the Saturation component (value of the saturation) of the color within range [0.0; 1.0].
        Standard_Real Saturation();

        //! Return the color as vector of 3 float elements.
        //operator NCollection_Vec3<float>& () { return NCollection_Vec3<float>(this->GetColor().Red(), this->GetColor().Green(), this->GetColor().Blue()); }

        //! Returns in theR1, theR2 and theR3 the components of this color according to the color system definition theType.
        //! If theType is Quantity_TOC_RGB:
        //!  - theR1 the value of Red   between 0.0 and 1.0
        //!  - theR2 the value of Green between 0.0 and 1.0
        //!  - theR3 the value of Blue  between 0.0 and 1.0
        //! If theType is Quantity_TOC_HLS:
        //!  - theR1 is the Hue (H) angle in degrees within range [0.0; 360.0], 0.0 being Red.
        //!    -1.0 is a special value reserved for grayscale color (S should be 0.0).
        //!  - theR2 is the Lightness  (L) within range [0.0; 1.0]
        //!  - theR3 is the Saturation (S) within range [0.0; 1.0]
        void Values(Standard_Real% theR1, Standard_Real% theR2, Standard_Real% theR3, XQuantity_TypeOfColor theType);

        //! Sets the specified value used to compare <me> and
        //! an other color in IsDifferent and in IsEqual methods.
        //! Warning: The default value is 0.0001
        static void SetEpsilon(Standard_Real AnEpsilon);

        //! Returns the specified value used to compare <me> and
        //! an other color in IsDifferent and in IsEqual methods.
        static Standard_Real Epsilon();

        //! Returns the name of the colour for which the RGB components
        //! are nearest to <R>, <G> and <B>.
        static XQuantity_NameOfColor Name(Standard_Real R, Standard_Real G, Standard_Real B);

        //! Returns the name of the color identified by
        //! AName in the Quantity_NameOfColor enumeration.
        //! For example, the name of the color which
        //! corresponds to Quantity_NOC_BLACK is "BLACK".
        //! Exceptions
        //! Standard_OutOfRange if AName in not known
        //! in the Quantity_NameOfColor enumeration.
        static System::String^ StringName(XQuantity_NameOfColor AColor);

        //! Finds color from predefined names.
        //! For example, the name of the color which
        //! corresponds to "BLACK" is Quantity_NOC_BLACK.
        //! Returns false if name is unknown.
        static Standard_Boolean ColorFromName(System::String^ theName, XQuantity_NameOfColor% theColor);

        //! Finds color from predefined names.
        //! For example, the name of the color which
        //! corresponds to "BLACK" is Quantity_NOC_BLACK.
        //! Returns false if name is unknown.
        //! @param theColorNameString the color name
        //! @param theColor a found color
        //! @return false if the color name is unknown, or true if the search by color name was successful
        static Standard_Boolean ColorFromName(System::String^ theColorNameString, XQuantity_Color^ theColor)
        {
            XQuantity_NameOfColor aColorName = XQuantity_NameOfColor(Quantity_NOC_BLACK);
            if (!ColorFromName(theColorNameString, aColorName))
            {
                return false;
            }
            theColor = gcnew XQuantity_Color(aColorName);
            return true;
        }

        //! Parses the string as a hex color (like "#FF0" for short RGB color, or "#FFFF00" for RGB color)
        //! @param theHexColorString the string to be parsed
        //! @param theColor a color that is a result of parsing
        //! @return true if parsing was successful, or false otherwise
        static bool ColorFromHex(System::String^ theHexColorString, XQuantity_Color^ theColor);

        //! Returns hex sRGB string in format "#FFAAFF".
        //! theToPrefixHash = true
        static TCollection_AsciiString ColorToHex(XQuantity_Color^ theColor, bool theToPrefixHash)
        {
            NCollection_Vec3<Standard_ShortReal> anSRgb = (NCollection_Vec3<Standard_ShortReal>)*theColor->GetColor();
            NCollection_Vec3<Standard_Integer> anSRgbInt(anSRgb * 255.0f + NCollection_Vec3<Standard_ShortReal>(0.5f));
            char aBuff[10];
            Sprintf(aBuff, theToPrefixHash ? "#%02X%02X%02X" : "%02X%02X%02X",
                anSRgbInt.r(), anSRgbInt.g(), anSRgbInt.b());
            return aBuff;
        }

        //! Converts HLS components into RGB ones.
        static void HlsRgb(const Standard_Real H, Standard_Real L, Standard_Real S, Standard_Real% R, Standard_Real% G, Standard_Real% B);

        //! Converts RGB components into HLS ones.
        static void RgbHls(const Standard_Real R, Standard_Real G, Standard_Real B, Standard_Real% H, Standard_Real% L, Standard_Real% S);

        //! Convert the Color value to ARGB integer value.
        //! theARGB has Alpha equal to zero, so the output is
        //! formatted as 0x00RRGGBB
        static void Color2argb(XQuantity_Color^ theColor, Standard_Integer% theARGB);

        //! Convert integer ARGB value to Color. Alpha bits are ignored
        static void Argb2color(const Standard_Integer theARGB, XQuantity_Color^ theColor);

        //! Dumps the content of me into the stream
        //! theDepth = -1
        void DumpJson(Standard_OStream& theOStream, Standard_Integer theDepth);

        /// <summary>
        /// ±¾µØ¾ä±ú
        /// </summary>
        property Quantity_Color* Handle
        {
            Quantity_Color* get() {
                return NativeHandle;
            }
        };
    private:
        Quantity_Color* NativeHandle;

    };
}
#endif // _XQuantity_Color_HeaderFile
