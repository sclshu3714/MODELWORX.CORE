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
}