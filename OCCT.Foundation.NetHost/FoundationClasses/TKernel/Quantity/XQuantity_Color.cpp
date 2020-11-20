#include "XQuantity_Color.h"

namespace TKernel {
    //! Creates Quantity_NOC_YELLOW color.
    XQuantity_Color::XQuantity_Color() {
        NativeHandle = new Quantity_Color();
    };

    //! Creates the color from enumeration value.
    XQuantity_Color::XQuantity_Color(const XQuantity_NameOfColor AName) {
        NativeHandle = new Quantity_Color(safe_cast<Quantity_NameOfColor>(AName));
    };

    //! Creates the color from enumeration value.
    XQuantity_Color::XQuantity_Color(const Quantity_Color AName) {
        NativeHandle = new Quantity_Color(AName);
    };

    //! Creates the color from enumeration value.
    XQuantity_Color::XQuantity_Color(XQuantity_Color^ AName) {
        NativeHandle = new Quantity_Color(AName->GetColor());
    };

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
    XQuantity_Color::XQuantity_Color(const Standard_Real theR1, Standard_Real theR2, Standard_Real theR3, XQuantity_TypeOfColor theType) {
        NativeHandle = new Quantity_Color(theR1, theR2, theR3, safe_cast<Quantity_TypeOfColor>(theType));
    };

    //! Quantity_Color
    Quantity_Color XQuantity_Color::GetColor() {
        return *NativeHandle;
    };

    //! Define color from RGB values.
    XQuantity_Color::XQuantity_Color(const NCollection_Vec3<float>& theRgb) {
        NativeHandle = new Quantity_Color(theRgb);
    };

    //! Increases or decreases the contrast by <ADelta>.
    //! <ADelta> is a percentage. Any value greater than zero
    //! will increase the contrast.
    //! The variation is expressed as a percentage of the
    //! current value.
    //! It is a variation of the saturation.
    void XQuantity_Color::ChangeContrast(const Standard_Real ADelta) {
        NativeHandle->ChangeContrast(ADelta);
    };

    //! Increases or decreases the intensity by <ADelta>.
    //! <ADelta> is a percentage. Any value greater than zero
    //! will increase the intensity.
    //! The variation is expressed as a percentage of the
    //! current value.
    //! It is a variation of the lightness.
    void XQuantity_Color::ChangeIntensity(const Standard_Real ADelta) {
        NativeHandle->ChangeIntensity(ADelta);
    };

    //! Updates the colour <me> from the definition of the
    //! colour <AName>.
    void XQuantity_Color::SetValues(const XQuantity_NameOfColor AName) {
        NativeHandle->SetValues(safe_cast<Quantity_NameOfColor>(AName));
    };

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
    void XQuantity_Color::SetValues(const Standard_Real theR1, Standard_Real theR2, Standard_Real theR3, XQuantity_TypeOfColor theType) {
        NativeHandle->SetValues(theR1, theR2, theR3, safe_cast<Quantity_TypeOfColor>(theType));
    };

    //! Returns the percentage change of contrast and intensity
    //! between <me> and <AColor>.
    //! <DC> and <DI> are percentages, either positive or negative.
    //! The calculation is with respect to the current value of <me>
    //! If <DC> is positive then <me> is more contrasty.
    //! If <DI> is positive then <me> is more intense.
    void XQuantity_Color::Delta(XQuantity_Color^ AColor, Standard_Real& DC, Standard_Real& DI) {
        NativeHandle->Delta(AColor->GetColor(), DC, DI);
    };

    //! Returns the distance between two colours. It's a
    //! value between 0 and the square root of 3
    //! (the black/white distance)
    Standard_Real XQuantity_Color::Distance(XQuantity_Color^ AColor) {
        return NativeHandle->Distance(AColor->GetColor());
    };

    //! Returns the square of distance between two colours.
    Standard_Real XQuantity_Color::SquareDistance(XQuantity_Color^ AColor) {
        return NativeHandle->SquareDistance(AColor->GetColor());
    };

    //! Returns the Blue component (quantity of blue) of the color within range [0.0; 1.0].
    Standard_Real XQuantity_Color::Blue() {
        return NativeHandle->Blue();
    };

    //! Returns the Green component (quantity of green) of the color within range [0.0; 1.0].
    Standard_Real XQuantity_Color::Green() {
        return NativeHandle->Green();
    };

    //! Returns the Hue component (hue angle) of the color
    //! in degrees within range [0.0; 360.0], 0.0 being Red.
    //! -1.0 is a special value reserved for grayscale color (S should be 0.0)
    Standard_Real XQuantity_Color::Hue() {
        return NativeHandle->Hue();
    };

    //! Returns Standard_True if the distance between <me> and
    //! <Other> is greater than Epsilon ().
    Standard_Boolean^ XQuantity_Color::IsDifferent(XQuantity_Color^ Other) {
        return NativeHandle->IsDifferent(Other->GetColor());
    };

    //! Returns true if the Other color is
    //! -   different from, or
    //! -   equal to this color.
    //! Two colors are considered to be equal if their
    //! distance is no greater than Epsilon().
    //! These methods are aliases of operator != and operator ==.
    Standard_Boolean^ XQuantity_Color::IsEqual(XQuantity_Color^ Other) {
        return NativeHandle->IsEqual(Other->GetColor());
    };

    //! Returns the Light component (value of the lightness) of the color within range [0.0; 1.0].
    Standard_Real XQuantity_Color::Light() {
        return NativeHandle->Light();
    };

    //! Returns the name of the color defined by its
    //! quantities of red R, green G and blue B; more
    //! precisely this is the nearest color from the
    //! Quantity_NameOfColor enumeration.
    //! Exceptions
    //! Standard_OutOfRange if R, G or B is less than 0. or greater than 1.
    XQuantity_NameOfColor XQuantity_Color::Name() {
        return safe_cast<XQuantity_NameOfColor>(NativeHandle->Name());
    };

    //! Returns the Red component (quantity of red) of the color within range [0.0; 1.0].
    Standard_Real XQuantity_Color::Red() {
        return NativeHandle->Red();
    };

    //! Returns the Saturation component (value of the saturation) of the color within range [0.0; 1.0].
    Standard_Real XQuantity_Color::Saturation() {
        return NativeHandle->Saturation();
    };

    ////! Return the color as vector of 3 float elements.
    //operator NCollection_Vec3<float>& () { return *(const NCollection_Vec3<float>*)this->GetColor(); }

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
    void XQuantity_Color::Values(Standard_Real& theR1, Standard_Real& theR2, Standard_Real& theR3, XQuantity_TypeOfColor theType) {
        NativeHandle->Values(theR1, theR2, theR3, safe_cast<Quantity_TypeOfColor>(theType));
    };

    //! Sets the specified value used to compare <me> and
    //! an other color in IsDifferent and in IsEqual methods.
    //! Warning: The default value is 0.0001
    //! static 
    void XQuantity_Color::SetEpsilon(const Standard_Real AnEpsilon) {
        Quantity_Color::SetEpsilon(AnEpsilon);
    };

    //! Returns the specified value used to compare <me> and
    //! an other color in IsDifferent and in IsEqual methods.
    //! static 
    Standard_Real XQuantity_Color::Epsilon() {
        return Quantity_Color::Epsilon();
    };

    //! Returns the name of the colour for which the RGB components
    //! are nearest to <R>, <G> and <B>.
    //! static 
    XQuantity_NameOfColor XQuantity_Color::Name(const Standard_Real R, Standard_Real G, Standard_Real B) {
        return safe_cast<XQuantity_NameOfColor>(Quantity_Color::Name(R, G, B));
    };

    //! Returns the name of the color identified by
    //! AName in the Quantity_NameOfColor enumeration.
    //! For example, the name of the color which
    //! corresponds to Quantity_NOC_BLACK is "BLACK".
    //! Exceptions
    //! Standard_OutOfRange if AName in not known
    //! in the Quantity_NameOfColor enumeration.
    //! static 
    System::String^ XQuantity_Color::StringName(XQuantity_NameOfColor AColor) {
        Standard_CString cString = Quantity_Color::StringName(safe_cast<Quantity_NameOfColor>(AColor));
        std::string tstring = std::string(cString);
        System::String^ sString = gcnew System::String(tstring.c_str());
        return sString;
    };

    //! Finds color from predefined names.
    //! For example, the name of the color which
    //! corresponds to "BLACK" is Quantity_NOC_BLACK.
    //! Returns false if name is unknown.
    //! static 
    Standard_Boolean XQuantity_Color::ColorFromName(System::String^ theName, XQuantity_NameOfColor& theColor) {
        TCollection_AsciiString asc = XStandard_Helper::toAsciiString(theName);
        const Standard_CString theColorNameString = asc.ToCString();
        Quantity_Color theQColor = safe_cast<Quantity_NameOfColor>(theColor);
        return Quantity_Color::ColorFromName(theColorNameString, theQColor);
    };

    //! Parses the string as a hex color (like "#FF0" for short RGB color, or "#FFFF00" for RGB color)
    //! @param theHexColorString the string to be parsed
    //! @param theColor a color that is a result of parsing
    //! @return true if parsing was successful, or false otherwise
    //! static
    bool XQuantity_Color::ColorFromHex(System::String^ theHexColorString, XQuantity_Color^ theColor) {
        TCollection_AsciiString asc = XStandard_Helper::toAsciiString(theHexColorString);
        const Standard_CString theColorNameString = asc.ToCString();
        Quantity_Color theQColor = safe_cast<Quantity_Color>(theColor->GetColor());
       return Quantity_Color::ColorFromHex(theColorNameString, theQColor);
    };


    //! Converts HLS components into RGB ones.
    //! static 
    void XQuantity_Color::HlsRgb(const Standard_Real H, Standard_Real L, Standard_Real S, Standard_Real& R, Standard_Real& G, Standard_Real& B) {
        Quantity_Color::HlsRgb(H, L, S, R, G, B);
    };

    //! Converts RGB components into HLS ones.
    //! static 
    void XQuantity_Color::RgbHls(const Standard_Real R, Standard_Real G, Standard_Real B, Standard_Real& H, Standard_Real& L, Standard_Real& S) {
        Quantity_Color::RgbHls(R, G, B, H, L, S);
    };

    //! Convert the Color value to ARGB integer value.
    //! theARGB has Alpha equal to zero, so the output is
    //! formatted as 0x00RRGGBB
    //! static 
    void XQuantity_Color::Color2argb(XQuantity_Color^ theColor, Standard_Integer& theARGB) {
        Quantity_Color::Color2argb(theColor->GetColor(), theARGB);
    };

    //! Convert integer ARGB value to Color. Alpha bits are ignored
    //! static 
    void XQuantity_Color::Argb2color(const Standard_Integer theARGB, XQuantity_Color^ theColor) {
        Quantity_Color::Argb2color(theARGB, theColor->GetColor());
    };

    //! Internal test
    //! static 
    void XQuantity_Color::Test() {
        Quantity_Color::Test();
    };

    //! Dumps the content of me into the stream
    //! theDepth = -1
    void XQuantity_Color::DumpJson(Standard_OStream& theOStream, Standard_Integer theDepth) {
        NativeHandle->DumpJson(theOStream, theDepth);
    };
}