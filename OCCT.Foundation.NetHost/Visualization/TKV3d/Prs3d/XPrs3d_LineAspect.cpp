#include <XPrs3d_LineAspect.h>
namespace TKV3d {
	//! Constructs a framework for line aspect defined by
	//! -   the color aColor
	//! -   the type of line aType and
	//! -   the line thickness aWidth.
	//! Type of line refers to whether the line is solid or dotted, for example.
	XPrs3d_LineAspect::XPrs3d_LineAspect(XQuantity_Color^ theColor, XAspect_TypeOfLine theType, const Standard_Real theWidth) {
		NativeHandle() = new Prs3d_LineAspect(theColor->GetColor(), safe_cast<Aspect_TypeOfLine>(theType), theWidth);
	};

	XPrs3d_LineAspect::XPrs3d_LineAspect(Handle(Prs3d_LineAspect) theAspect) {
		NativeHandle() = theAspect;
	};

	XPrs3d_LineAspect::XPrs3d_LineAspect(XGraphic3d_AspectLine3d^ theAspect) {
		NativeHandle() = new Prs3d_LineAspect(theAspect->GetAspectLine3d());
	};

	void XPrs3d_LineAspect::SetNativeHandle(Handle(Prs3d_LineAspect) theAspect) {
		NativeHandle() = theAspect;
	};

	Handle(Prs3d_LineAspect) XPrs3d_LineAspect::GetLineAspect() {
		return NativeHandle();
	};

	//! Sets the line color defined at the time of construction.
	//! Default value: Quantity_NOC_YELLOW
	void XPrs3d_LineAspect::SetColor(XQuantity_Color^ theColor) {
		NativeHandle()->SetColor(theColor->GetColor());
	};

	//! Sets the type of line defined at the time of construction.
	//! This could, for example, be solid, dotted or made up of dashes.
	//! Default value: Aspect_TOL_SOLID
	void XPrs3d_LineAspect::SetTypeOfLine(XAspect_TypeOfLine theType) {
		NativeHandle()->SetTypeOfLine(safe_cast<Aspect_TypeOfLine>(theType));
	};

	//! Sets the line width defined at the time of construction.
	//! Default value: 1.
	void XPrs3d_LineAspect::SetWidth(const Standard_Real theWidth) {
		NativeHandle()->SetWidth(theWidth);
	};

	//! Returns the line aspect. This is defined as the set of
	//! color, type and thickness attributes.
	XGraphic3d_AspectLine3d^ XPrs3d_LineAspect::Aspect() {
		return gcnew XGraphic3d_AspectLine3d(NativeHandle()->Aspect());
	};

	void XPrs3d_LineAspect::SetAspect(XGraphic3d_AspectLine3d^ theAspect) {
		NativeHandle()->SetAspect(theAspect->GetAspectLine3d());
	};

	//! Dumps the content of me into the stream
	//!  theDepth = -1
	void XPrs3d_LineAspect::DumpJson(Standard_OStream& theOStream, const Standard_Integer theDepth) {
		NativeHandle()->DumpJson(theOStream, theDepth);
	};
}

