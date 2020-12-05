#include "XStandard_CString.h"

namespace TKernel {
    XStandard_CString::XStandard_CString() {
        NativeHandle = new  Standard_CString();
    };

    XStandard_CString::XStandard_CString(Standard_CString* pos) {
        NativeHandle = pos;
    };

    Standard_CString XStandard_CString::GetCString() {
        return *NativeHandle;
    };

    //! Returns bounded hash code for the null-terminated string, in the range [1, theUpperBound]
    //! @param theString the null-terminated string which hash code is to be computed
    //! @param theUpperBound the upper bound of the range a computing hash code must be within
    //! @return a computed hash code, in the range [1, theUpperBound]
    Standard_Integer XStandard_CString::HashCode(XStandard_CString^ theString, Standard_Integer theUpperBound) {
              
    };

    //! Returns 32-bit hash code for the first theLen characters in the string theStr.
    //! The result is unbound (may be not only positive, but also negative)
    //! @param theString the string which hash code is to be computed
    //! @param theLength the length of the given string
    //! @return a computed hash code of the given string
    Standard_Integer XStandard_CString::HashCodes(XStandard_CString^ theString, Standard_Integer theLength) {

    };

    //! Returns bounded hash code for the first theLength characters in the string theString, in the range [1, theUpperBound]
    //! @param theString the string which hash code is to be computed
    //! @param theLength the length of the initial substring of the given string which hash code is to be computed
    //! @param theUpperBound the upper bound of the range a computing hash code must be within
    //! @return a computed hash code of the given string
    Standard_Integer XStandard_CString::HashCode(XStandard_CString^ theString, Standard_Integer theLength, Standard_Integer theUpperBound) {

    };


    //! Returns Standard_True if two strings are equal
    Standard_Boolean XStandard_CString::IsEqual(XStandard_CString^ theOne, XStandard_CString^ theTwo) {
    
    };
}