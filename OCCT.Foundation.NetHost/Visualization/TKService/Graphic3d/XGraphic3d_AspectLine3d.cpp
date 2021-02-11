#include <XGraphic3d_AspectLine3d.h>
namespace TKService {
    //! Creates a context table for line primitives
    //! defined with the following default values:
    //!
    //! Color = Quantity_NOC_YELLOW;
    //! Type  = Aspect_TOL_SOLID;
    //! Width = 1.0;
    XGraphic3d_AspectLine3d::XGraphic3d_AspectLine3d() {
        NativeHandle() = new Graphic3d_AspectLine3d();
    };

    XGraphic3d_AspectLine3d::XGraphic3d_AspectLine3d(Handle(Graphic3d_AspectLine3d) posAspectLine) {
        NativeHandle() = posAspectLine;
    };

    //! Creates a context table for line primitives defined with the specified values.
    //! Warning: theWidth is the "line width scale factor".
    //! The nominal line width is 1 pixel.
    //! The width of the line is determined by applying the line width scale factor to this nominal line width.
    //! The supported line widths vary by 1-pixel units.
    XGraphic3d_AspectLine3d::XGraphic3d_AspectLine3d(XQuantity_Color^ theColor, XAspect_TypeOfLine theType, Standard_Real theWidth) {
        NativeHandle() = new Graphic3d_AspectLine3d(*theColor->GetColor(), safe_cast<Aspect_TypeOfLine>(theType), theWidth);
    };

    Handle(Graphic3d_AspectLine3d) XGraphic3d_AspectLine3d::GetAspectLine3d() {
        return NativeHandle();
    };

    //! 
    void XGraphic3d_AspectLine3d::SetNativeHandle(Handle(Graphic3d_AspectLine3d) theAspect) {
        NativeHandle() = theAspect;
    };

    //! Return line type.
    XAspect_TypeOfLine XGraphic3d_AspectLine3d::Type() {
        return safe_cast<XAspect_TypeOfLine>(NativeHandle()->Type());
    };

    //! Modifies the type of line.
    void XGraphic3d_AspectLine3d::SetType(XAspect_TypeOfLine theType) {
        NativeHandle()->SetType(safe_cast<Aspect_TypeOfLine>(theType));
    };

    //! Return line width.
    Standard_ShortReal XGraphic3d_AspectLine3d::Width() {
        return NativeHandle()->Width();
    };
}
