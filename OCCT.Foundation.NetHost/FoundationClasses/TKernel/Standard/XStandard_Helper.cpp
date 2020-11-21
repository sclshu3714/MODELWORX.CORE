#include "XStandard_Helper.h"

namespace TKernel {
    XStandard_Helper::XStandard_Helper() {
        
    }
    //! Auxiliary tool for converting C# string into UTF-8 string.
    TCollection_AsciiString XStandard_Helper::toAsciiString(String^ theString) {
        if (theString == nullptr) {
            return TCollection_AsciiString();
        }

        pin_ptr<const wchar_t> aPinChars = PtrToStringChars(theString);
        const wchar_t* aWCharPtr = aPinChars;
        if (aWCharPtr == NULL
            || *aWCharPtr == L'\0') {
            return TCollection_AsciiString();
        }
        return TCollection_AsciiString(aWCharPtr);
    }

    Standard_CString XStandard_Helper::toCString(TCollection_AsciiString AString) {
        return AString.ToCString();
    };

    String^ XStandard_Helper::toString(Standard_CString CString) {
        System::String^ sString = gcnew System::String(CString);
        return sString;
    };

    String^ XStandard_Helper::toString(TCollection_AsciiString AString) {
        System::String^ sString = gcnew System::String(AString.ToCString());
        return sString;
    };
}