#include <XAspect_Background.h>
namespace TKService {
	//! Creates a window background.
	//! Default color : NOC_MATRAGRAY.
	XAspect_Background::XAspect_Background() {
		NativeHandle = new Aspect_Background();
	};

	XAspect_Background::XAspect_Background(Aspect_Background* pos) {
		NativeHandle = pos;
	};

	void XAspect_Background::SetBackgroundHandle(Aspect_Background* pos) {
		NativeHandle = pos;
	};

	Aspect_Background* XAspect_Background::GetBackground() {
		return NativeHandle;
	};

	//! Creates a window background with the colour <AColor>.
	XAspect_Background::XAspect_Background(XQuantity_Color^ AColor) {
		NativeHandle = new Aspect_Background(*AColor->GetColor());
	};

	//! Modifies the colour of the window background <me>.
	void XAspect_Background::SetColor(XQuantity_Color^ AColor) {
		NativeHandle->SetColor(*AColor->GetColor());
	};

	//! Returns the colour of the window background <me>.
	XQuantity_Color^ XAspect_Background::Color() {
		Quantity_Color* temp = new Quantity_Color(NativeHandle->Color());
		return gcnew XQuantity_Color(temp);
	};
}