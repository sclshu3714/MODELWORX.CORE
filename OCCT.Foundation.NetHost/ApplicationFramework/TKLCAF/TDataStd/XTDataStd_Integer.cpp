#include "XTDataStd_Integer.h"

namespace TKLCAF {
	//IMPLEMENT_STANDARD_RTTIEXT(TDataStd_Integer, TDF_Attribute)
	//! class methods
	//! =============
	//! Returns the GUID for integers.
	//! static 
	XStandard_GUID^ XTDataStd_Integer::GetID() {
		return gcnew XStandard_GUID(TDataStd_Integer::GetID());
	};

	//! Finds, or creates, an Integer attribute and sets <value>
	//! the Integer  attribute is returned.
	//! static 
	XTDataStd_Integer^ XTDataStd_Integer::Set(XTDF_Label^ label, Standard_Integer value) {
		return gcnew XTDataStd_Integer(TDataStd_Integer::Set(label->GetLabel(), value));
	};

	//! Finds, or creates, an Integer attribute with explicit user defined <guid> and sets <value>.
	//! The Integer attribute  is  returned. 
	//! static 
	XTDataStd_Integer^ XTDataStd_Integer::Set(XTDF_Label^ label, XStandard_GUID^ guid, const Standard_Integer value) {
		return gcnew XTDataStd_Integer(TDataStd_Integer::Set(label->GetLabel(), guid->GetGUID(), value));
	};

	//! Integer methods
	//! ===============
	void XTDataStd_Integer::Set(const Standard_Integer V) {
		NativeHandle()->Set(V);
	};

	//! Sets the explicit GUID (user defined) for the attribute.
	void XTDataStd_Integer::SetID(XStandard_GUID^ guid) {
		NativeHandle()->SetID(guid->GetGUID());
	};

	//! Sets default GUID for the attribute.
	void XTDataStd_Integer::SetID() {
		NativeHandle()->SetID();
	};

	//! Returns the integer value contained in the attribute.
	Standard_Integer XTDataStd_Integer::Get() {
		return NativeHandle()->Get();
	};

	//! Returns True if there is a reference on the same label
	Standard_Boolean XTDataStd_Integer::IsCaptured() {
		return NativeHandle()->IsCaptured();
	};

	XStandard_GUID^ XTDataStd_Integer::ID() {
		return gcnew XStandard_GUID(NativeHandle()->ID());
	};

	void XTDataStd_Integer::Restore(XTDF_Attribute^ With) {
		NativeHandle()->Restore(With->GetAttribute());
	};

	XTDF_Attribute^ XTDataStd_Integer::NewEmpty() {
		return gcnew XTDF_Attribute(NativeHandle()->NewEmpty());
	};

	void XTDataStd_Integer::Paste(XTDF_Attribute^ Into, Handle(TDF_RelocationTable)& RT) {
		NativeHandle()->Paste(Into->GetAttribute(),RT);
	};

	Standard_OStream& XTDataStd_Integer::Dump(Standard_OStream& anOS) {
		return NativeHandle()->Dump(anOS);
	};

	XTDataStd_Integer::XTDataStd_Integer() {
		NativeHandle() = new TDataStd_Integer();
		SetNativeHandle(NativeHandle());
	};

	XTDataStd_Integer::XTDataStd_Integer(Handle(TDataStd_Integer) pos) {
		NativeHandle() = pos;
		SetNativeHandle(NativeHandle());
	};

	Handle(TDataStd_Integer) XTDataStd_Integer::GetInteger() {
		return NativeHandle();
	};
}