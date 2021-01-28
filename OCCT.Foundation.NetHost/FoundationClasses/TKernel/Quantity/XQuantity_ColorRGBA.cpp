#include <XQuantity_ColorRGBA.h>

namespace TKernel {
    //! Creates a color with the default value.
    XQuantity_ColorRGBA::XQuantity_ColorRGBA() {

    };

    //! Creates the color with specified RGB value.
    XQuantity_ColorRGBA::XQuantity_ColorRGBA(XQuantity_Color^ theRgb) {

    };

    //! Creates the color with specified RGBA values.
    XQuantity_ColorRGBA::XQuantity_ColorRGBA(XQuantity_Color^ theRgb, float theAlpha) {

    };

    //! Creates the color from RGBA vector.
    XQuantity_ColorRGBA::XQuantity_ColorRGBA(array<float, 1> theRgba) {

    };

    //! Creates the color from RGBA values.
    XQuantity_ColorRGBA::XQuantity_ColorRGBA(float theRed, float theGreen, float theBlue, float theAlpha) {

    };

    //! Assign new values to the color.
    void XQuantity_ColorRGBA::SetValues(float theRed, float theGreen, float theBlue, float theAlpha) {

    };

    //! Return RGB color value.
    XQuantity_Color^ XQuantity_ColorRGBA::GetRGB() {

    };

    //! Modify RGB color components without affecting alpha value.
    XQuantity_Color^ XQuantity_ColorRGBA::ChangeRGB() {

    };

    //! Assign RGB color components without affecting alpha value.
    void XQuantity_ColorRGBA::SetRGB(XQuantity_Color^ theRgb) {

    };

    //! Return alpha value (1.0 means opaque, 0.0 means fully transparent).
    Standard_ShortReal XQuantity_ColorRGBA::Alpha() {

    };

    //! Assign the alpha value.
    void XQuantity_ColorRGBA::SetAlpha(Standard_ShortReal theAlpha) {

    };

    //! Returns true if the distance between colors is greater than Epsilon().
    bool XQuantity_ColorRGBA::IsDifferent(XQuantity_ColorRGBA^ theOther) {

    };

    //! Two colors are considered to be equal if their distance is no greater than Epsilon().
    bool XQuantity_ColorRGBA::IsEqual(XQuantity_ColorRGBA^ theOther) {

    };

    //! Finds color from predefined names.
    //! For example, the name of the color which
    //! corresponds to "BLACK" is Quantity_NOC_BLACK.
    //! Returns false if name is unknown.
    //! An alpha component is set to 1.0.
    //! @param theColorNameString the color name
    //! @param theColor a found color
    //! @return false if the color name is unknown, or true if the search by color name was successful
    //! static
    Standard_Boolean XQuantity_ColorRGBA::ColorFromName(Standard_CString theColorNameString, XQuantity_ColorRGBA^ theColor) {

    };

    //! Parses the string as a hex color (like "#FF0" for short RGB color, "#FF0F" for short RGBA color,
    //! "#FFFF00" for RGB color, or "#FFFF00FF" for RGBA color)
    //! @param theHexColorString the string to be parsed
    //! @param theColor a color that is a result of parsing
    //! @param theAlphaComponentIsOff the flag that indicates if a color alpha component is presented
    //! in the input string (false) or not (true)
    //! @return true if parsing was successful, or false otherwise
    //! bool          theAlphaComponentIsOff = false
    //! static
    bool XQuantity_ColorRGBA::ColorFromHex(char* theHexColorString, XQuantity_ColorRGBA^ theColor, bool theAlphaComponentIsOff) {

    };

    //! Returns hex sRGBA string in format "#RRGGBBAA".
    //! bool theToPrefixHash = true
    //! static
    TCollection_AsciiString XQuantity_ColorRGBA::ColorToHex(XQuantity_ColorRGBA^ theColor, bool theToPrefixHash) {

    };

    //! Dumps the content of me into the stream
    //! const Standard_Integer theDepth = -1
    void XQuantity_ColorRGBA::DumpJson(Standard_OStream& theOStream, Standard_Integer theDepth) {

    };
}
