#include <XStandard_GUID.h>

namespace TKernel {
	XStandard_GUID::XStandard_GUID() {
		NativeHandle = new Standard_GUID();
	};

	//! build a GUID from an ascii string with the
	//! following format:
	//! Length : 36 char
	//! "00000000-0000-0000-0000-000000000000"
	XStandard_GUID::XStandard_GUID(const Standard_CString aGuid) {
		NativeHandle = new Standard_GUID(aGuid);
	};

	//! build a GUID from an unicode string with the
	//! following format:
	//!
	//! "00000000-0000-0000-0000-000000000000"
	XStandard_GUID::XStandard_GUID(const Standard_ExtString aGuid) {
		NativeHandle = new Standard_GUID(aGuid);
	};

	XStandard_GUID::XStandard_GUID(const Standard_Integer a32b, Standard_ExtCharacter a16b1, Standard_ExtCharacter a16b2, Standard_ExtCharacter a16b3, Standard_Byte a8b1, Standard_Byte a8b2, Standard_Byte a8b3, Standard_Byte a8b4, Standard_Byte a8b5, Standard_Byte a8b6) {
		NativeHandle = new Standard_GUID(a32b, a16b1, a16b2, a16b3, a8b1, a8b2, a8b3, a8b4, a8b5, a8b6);
	};

	XStandard_GUID::XStandard_GUID(const Standard_UUID& aGuid) {
		NativeHandle = new Standard_GUID(aGuid);
	};

	XStandard_GUID::XStandard_GUID(const Standard_GUID& aGuid) {
		NativeHandle = new Standard_GUID(aGuid);
	};

	XStandard_GUID^ XStandard_GUID::ToUUID() {
		return gcnew XStandard_GUID(NativeHandle->ToUUID());
	};

	//!
	Standard_GUID XStandard_GUID::GetGUID() {
		return *NativeHandle;
	};

	//! translate the GUID into ascii string
	//! the aStrGuid is allocated by user.
	//! the guid have the following format:
	//!
	//! "00000000-0000-0000-0000-000000000000"
	void XStandard_GUID::ToCString(const Standard_PCharacter aStrGuid) {
		NativeHandle->ToCString(aStrGuid);
	};

	//! translate the GUID into unicode string
	//! the aStrGuid is allocated by user.
	//! the guid have the following format:
	//!
	//! "00000000-0000-0000-0000-000000000000"
	void XStandard_GUID::ToExtString(const Standard_PExtCharacter aStrGuid) {
		NativeHandle->ToExtString(aStrGuid);
	};

	Standard_Boolean XStandard_GUID::IsSame(const Standard_GUID& uid) {
		return NativeHandle->IsSame(uid);
	};


	Standard_Boolean XStandard_GUID::IsNotSame(const Standard_GUID& uid) {
		return NativeHandle->IsNotSame(uid);
	};


	void XStandard_GUID::Assign(const Standard_GUID& uid) {
		NativeHandle->Assign(uid);
	};


	void XStandard_GUID::Assign(const Standard_UUID& uid) {
		NativeHandle->Assign(uid);
	};

	//! Display the GUID with the following format:
	//!
	//! "00000000-0000-0000-0000-000000000000"
	void XStandard_GUID::ShallowDump(Standard_OStream& aStream) {
		NativeHandle->ShallowDump(aStream);
	};

	//! Check the format of a GUID string.
	//! It checks the size, the position of the '-' and the correct size of fields.
	Standard_Boolean XStandard_GUID::CheckGUIDFormat(const Standard_CString aGuid) {
		return Standard_GUID::CheckGUIDFormat(aGuid);
	};

	//! Hash function for GUID.
	Standard_Integer XStandard_GUID::Hash(const Standard_Integer Upper) {
		return NativeHandle->Hash(Upper);
	};

	//! Computes a hash code for the given GUID of the Standard_Integer type, in the range [1, theUpperBound]
	//! @param theGUID the GUID which hash code is to be computed
	//! @param theUpperBound the upper bound of the range a computing hash code must be within
	//! @return a computed hash code, in the range [1, theUpperBound]
	Standard_Integer XStandard_GUID::HashCode(const Standard_GUID& theGUID, Standard_Integer theUpperBound) {
		return Standard_GUID::HashCode(theGUID, theUpperBound);
	};

	//! Returns True  when the two GUID are the same.
	Standard_Boolean XStandard_GUID::IsEqual(const Standard_GUID& string1, Standard_GUID& string2) {
		return Standard_GUID::IsEqual(string1, string2);
	};
}