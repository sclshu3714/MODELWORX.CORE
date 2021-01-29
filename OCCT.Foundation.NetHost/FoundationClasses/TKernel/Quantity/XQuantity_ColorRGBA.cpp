#include <XQuantity_ColorRGBA.h>

namespace TKernel {
    //! Creates a color with the default value.
    XQuantity_ColorRGBA::XQuantity_ColorRGBA() {
        NativeHandle = new Quantity_ColorRGBA();
    };

    XQuantity_ColorRGBA::XQuantity_ColorRGBA(Quantity_ColorRGBA* pos) {
        NativeHandle = pos;
    };

    //! Creates the color with specified RGB value.
    XQuantity_ColorRGBA::XQuantity_ColorRGBA(XQuantity_Color^ theRgb) {
        NativeHandle = new Quantity_ColorRGBA(*theRgb->GetColor());
    };

    //! Creates the color with specified RGBA values.
    XQuantity_ColorRGBA::XQuantity_ColorRGBA(XQuantity_Color^ theRgb, float theAlpha) {
        NativeHandle = new Quantity_ColorRGBA(*theRgb->GetColor(), theAlpha);
    };

    //! Creates the color from RGBA vector.
    /*XQuantity_ColorRGBA::XQuantity_ColorRGBA(array<float, 1>^ theRgba) {

    };*/

    //! Creates the color from RGBA values.
    XQuantity_ColorRGBA::XQuantity_ColorRGBA(float theRed, float theGreen, float theBlue, float theAlpha) {
        NativeHandle = new Quantity_ColorRGBA(theRed, theGreen, theBlue, theAlpha);
    };

    //! Assign new values to the color.
    void XQuantity_ColorRGBA::SetValues(float theRed, float theGreen, float theBlue, float theAlpha) {
        NativeHandle->SetValues(theRed, theGreen, theBlue, theAlpha);
    };

    Quantity_ColorRGBA* XQuantity_ColorRGBA::GetColorRGBA() {
        return NativeHandle;
    };

    //! Return RGB color value.
    XQuantity_Color^ XQuantity_ColorRGBA::GetRGB() {
        Quantity_Color temp = NativeHandle->GetRGB();
        return gcnew XQuantity_Color(temp);
    };

    //! Modify RGB color components without affecting alpha value.
    XQuantity_Color^ XQuantity_ColorRGBA::ChangeRGB() {
        Quantity_Color temp = NativeHandle->ChangeRGB();
        return gcnew XQuantity_Color(temp);
    };

    //! Assign RGB color components without affecting alpha value.
    void XQuantity_ColorRGBA::SetRGB(XQuantity_Color^ theRgb) {
        NativeHandle->SetRGB(*theRgb->GetColor());
    };

    //! Return alpha value (1.0 means opaque, 0.0 means fully transparent).
    Standard_ShortReal XQuantity_ColorRGBA::Alpha() {
        return NativeHandle->Alpha();
    };

    //! Assign the alpha value.
    void XQuantity_ColorRGBA::SetAlpha(Standard_ShortReal theAlpha) {
        NativeHandle->SetAlpha(theAlpha);
    };

    //! Returns true if the distance between colors is greater than Epsilon().
    bool XQuantity_ColorRGBA::IsDifferent(XQuantity_ColorRGBA^ theOther) {
        return NativeHandle->IsDifferent(*theOther->GetColorRGBA());
    };

    //! Two colors are considered to be equal if their distance is no greater than Epsilon().
    bool XQuantity_ColorRGBA::IsEqual(XQuantity_ColorRGBA^ theOther) {
        return NativeHandle->IsEqual(*theOther->GetColorRGBA());
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
        return Quantity_ColorRGBA::ColorFromName(theColorNameString, *theColor->GetColorRGBA());
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
        return Quantity_ColorRGBA::ColorFromHex(theHexColorString, *theColor->GetColorRGBA(), theAlphaComponentIsOff);
    };

    //! Returns hex sRGBA string in format "#RRGGBBAA".
    //! bool theToPrefixHash = true
    //! static
    TCollection_AsciiString XQuantity_ColorRGBA::ColorToHex(XQuantity_ColorRGBA^ theColor, bool theToPrefixHash) {
        return Quantity_ColorRGBA::ColorToHex(*theColor->GetColorRGBA(), theToPrefixHash);
    };

    //! Dumps the content of me into the stream
    //! const Standard_Integer theDepth = -1
    void XQuantity_ColorRGBA::DumpJson(Standard_OStream& theOStream, Standard_Integer theDepth) {
        NativeHandle->DumpJson(theOStream, theDepth);
    };
}
