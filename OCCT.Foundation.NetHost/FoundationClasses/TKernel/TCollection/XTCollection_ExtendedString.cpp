// Copyright (c) 1993-1999 Matra Datavision
// Copyright (c) 1999-2014 OPEN CASCADE SAS
//
// This file is part of Open CASCADE Technology software library.
//
// This library is free software; you can redistribute it and/or modify it under
// the terms of the GNU Lesser General Public License version 2.1 as published
// by the Free Software Foundation, with special exception defined in the file
// OCCT_LGPL_EXCEPTION.txt. Consult the file LICENSE_LGPL_21.txt included in OCCT
// distribution for complete text of the license and disclaimer of any warranty.
//
// Alternatively, this file may be used under the terms of Open CASCADE
// commercial license or contractual agreement.

#include <XTCollection_ExtendedString.h>

#include <NCollection_UtfIterator.hxx>
#include <Standard.hxx>
#include <Standard_ExtString.hxx>
#include <Standard_NegativeValue.hxx>
#include <Standard_NullObject.hxx>
#include <Standard_NumericError.hxx>
#include <Standard_OutOfRange.hxx>
#include <TCollection_AsciiString.hxx>

#include <algorithm>
#include <cctype>
#include <cstdio>

namespace TKernel
{
    //! Allocate string buffer (automatically adding extra symbol for NULL-termination).
    static Standard_ExtCharacter* allocateExtChars(const Standard_Size theLength)
    {
        return (Standard_ExtCharacter*)Standard::Allocate((theLength + 1) * sizeof(Standard_ExtCharacter));
    }

    //! Re-allocate string buffer (automatically adding extra symbol for NULL-termination).
    static Standard_ExtCharacter* reallocateExtChars(Standard_Address theAddr,  const Standard_Size theLength)
    {
        return (Standard_ExtCharacter*)Standard::Reallocate(theAddr, (theLength + 1) * sizeof(Standard_ExtCharacter));
    }

    static const Standard_ExtCharacter NULL_EXTSTRING[1] = { 0 };

    //! Returns the number of 16-bit code units in Unicode string
    template<typename T>
    static Standard_Integer nbSymbols(const T* theUtfString)
    {
        Standard_Integer aNbCodeUnits = 0;
        for (NCollection_UtfIterator<T> anIter(theUtfString); *anIter != 0; ++anIter)
        {
            aNbCodeUnits += anIter.AdvanceCodeUnitsUtf16();
        }
        return aNbCodeUnits;
    }

    //! Convert from wchar_t* to extended string.
    //! Default implementation when size of wchar_t and extended char is different (e.g. Linux / UNIX).
    template<size_t CharSize>
    inline Standard_ExtCharacter* Standard_UNUSED fromWideString(const Standard_WideChar* theUtfString,
        Standard_Integer& theLength)
    {
        theLength = nbSymbols(theUtfString);
        Standard_ExtCharacter* aString = allocateExtChars(theLength);
        NCollection_UtfWideIter anIterRead(theUtfString);
        for (Standard_ExtCharacter* anIterWrite = aString; *anIterRead != 0; ++anIterRead)
        {
            anIterWrite = anIterRead.GetUtf(anIterWrite);
        }
        aString[theLength] = 0;
        return aString;
    }

    //! Use memcpy() conversion when size is the same (e.g. on Windows).
    template<>
    inline Standard_ExtCharacter* Standard_UNUSED fromWideString<sizeof(Standard_ExtCharacter)>(const Standard_WideChar* theUtfString,
        Standard_Integer& theLength)
    {
        for (theLength = 0; theUtfString[theLength] != 0; ++theLength) {}
        Standard_ExtCharacter* aString = allocateExtChars(theLength);
        const Standard_Integer aSize = theLength * sizeof(Standard_ExtCharacter);
        memcpy(aString, theUtfString, aSize);
        aString[theLength] = 0;
        return aString;
    }


    //! Initializes a ExtendedString to an empty ExtendedString.
    XTCollection_ExtendedString::XTCollection_ExtendedString() {
        NativeHandle = new TCollection_ExtendedString();
    };

    //! Creation by converting a CString to an extended
    //! string.  If <isMultiByte> is true then the string is
    //! treated as having UTF-8 coding.  If it is not a UTF-8
    //! then <isMultiByte> is ignored and each character is
    //! copied to ExtCharacter.
    XTCollection_ExtendedString::XTCollection_ExtendedString(System::String^ astring, const Standard_Boolean isMultiByte) {
        TCollection_AsciiString aFilename = XStandard_Helper::toAsciiString(astring);
        NativeHandle = new TCollection_ExtendedString(aFilename.ToCString(), isMultiByte);
    };

    //! Creation by converting a CString to an extended
    //! string.  If <isMultiByte> is true then the string is
    //! treated as having UTF-8 coding.  If it is not a UTF-8
    //! then <isMultiByte> is ignored and each character is
    //! copied to ExtCharacter.
    XTCollection_ExtendedString::XTCollection_ExtendedString(const Standard_CString astring, const Standard_Boolean isMultiByte) {
        NativeHandle = new TCollection_ExtendedString(astring, isMultiByte);
    };

    //! Creation by converting an ExtString to an extended string.
    XTCollection_ExtendedString::XTCollection_ExtendedString(const Standard_ExtString astring) {
        NativeHandle = new TCollection_ExtendedString(astring);
    };

#if !defined(_MSC_VER) || defined(_NATIVE_WCHAR_T_DEFINED)
    //! Initialize from wide-char string considering it as Unicode string
    //! (the size of wide char is a platform-dependent - e.g. on Windows wchar_t is UTF-16).
    //!
    //! This constructor is unavailable if application is built with deprecated msvc option "-Zc:wchar_t-",
    //! since OCCT itself is never built with this option.
    XTCollection_ExtendedString::XTCollection_ExtendedString(const Standard_WideChar* theStringUtf) {
        NativeHandle = new TCollection_ExtendedString(theStringUtf);
    };
#endif

    //! Initializes a AsciiString with a single character.
    XTCollection_ExtendedString::XTCollection_ExtendedString(const Standard_Character aChar) {
        NativeHandle = new TCollection_ExtendedString(aChar);
    };

    //! Initializes a ExtendedString with a single character.
    XTCollection_ExtendedString::XTCollection_ExtendedString(const Standard_ExtCharacter aChar) {
        NativeHandle = new TCollection_ExtendedString(aChar);
    };

    //! Initializes a ExtendedString with <length> space allocated.
    //! and filled with <filler>.This is useful for buffers.
    XTCollection_ExtendedString::XTCollection_ExtendedString(const Standard_Integer length, const Standard_ExtCharacter filler) {
        NativeHandle = new TCollection_ExtendedString(length, filler);
    };

    //! Initializes an ExtendedString with an integer value
    XTCollection_ExtendedString::XTCollection_ExtendedString(const Standard_Integer value) {
        NativeHandle = new TCollection_ExtendedString(value);
    };

    //! Initializes an ExtendedString with a real value
    XTCollection_ExtendedString::XTCollection_ExtendedString(const Standard_Real value) {
        NativeHandle = new TCollection_ExtendedString(value);
    };

    //! Initializes a ExtendedString with another ExtendedString.
    XTCollection_ExtendedString::XTCollection_ExtendedString(XTCollection_ExtendedString^ astring) {
        NativeHandle = new TCollection_ExtendedString(*astring->GetExtendedString());
    };

#ifndef OCCT_NO_RVALUE_REFERENCE
    //! Move constructor
    XTCollection_ExtendedString::XTCollection_ExtendedString(XTCollection_ExtendedString^& theOther) {
        NativeHandle = new TCollection_ExtendedString(*theOther->GetExtendedString());
    };
#endif

    //! Creation by converting an Ascii string to an extended
    //! string. The string is treated as having UTF-8 coding.
    //! If it is not a UTF-8 then each character is copied to ExtCharacter.
    XTCollection_ExtendedString::XTCollection_ExtendedString(TCollection_AsciiString astring) {
        NativeHandle = new TCollection_ExtendedString(astring);
    };

    //! Returns the TCollection_ExtendedString
    TCollection_ExtendedString* XTCollection_ExtendedString::GetExtendedString() {
      return NativeHandle;
    };

    //! Appends the other extended string to this extended string.
    //! Note that this method is an alias of operator +=.
    //! Example: aString += anotherString
    void XTCollection_ExtendedString::AssignCat(XTCollection_ExtendedString^ other) {
        NativeHandle->AssignCat(*other->GetExtendedString());
    };

    //! Appends <other> to me.
    XTCollection_ExtendedString^ XTCollection_ExtendedString::Cat(XTCollection_ExtendedString^ other) {
        return gcnew XTCollection_ExtendedString(NativeHandle->Cat(*other->GetExtendedString()));
    };


    //! Substitutes all the characters equal to aChar by NewChar
    //! in the ExtendedString <me>.
    //! The substitution can be case sensitive.
    //! If you don't use default case sensitive, no matter wether aChar
    //! is uppercase or not.
    void XTCollection_ExtendedString::ChangeAll(const Standard_ExtCharacter aChar, const Standard_ExtCharacter NewChar) {
        NativeHandle->ChangeAll(aChar, NewChar);
    };

    //! Removes all characters contained in <me>.
    //! This produces an empty ExtendedString.
    void XTCollection_ExtendedString::Clear() {
        NativeHandle->Clear();
    };

    //! Copy <fromwhere> to <me>.
    //! Used as operator =
    void XTCollection_ExtendedString::Copy(XTCollection_ExtendedString^ fromwhere) {
        NativeHandle->Copy(*fromwhere->GetExtendedString());
    };

    //! Exchange the data of two strings (without reallocating memory).
    void XTCollection_ExtendedString::Swap(XTCollection_ExtendedString^ theOther) {
        NativeHandle->Swap(*theOther->GetExtendedString());
    };


    //! Frees memory allocated by ExtendedString.
    XTCollection_ExtendedString::~XTCollection_ExtendedString() {
        NativeHandle->~TCollection_ExtendedString();
    };

    //! Insert a Character at position <where>.
    void XTCollection_ExtendedString::Insert(const Standard_Integer where, const Standard_ExtCharacter what) {
        NativeHandle->Insert(where, what);
    };

    //! Insert a ExtendedString at position <where>.
    void XTCollection_ExtendedString::Insert(const Standard_Integer where, XTCollection_ExtendedString^ what) {
        NativeHandle->Insert(where, *what->GetExtendedString());
    };

    //! Returns True if this string contains no characters.
    Standard_Boolean XTCollection_ExtendedString::IsEmpty() {
        return NativeHandle->IsEmpty();
    };

    //! Returns true if the characters in this extended
    //! string are identical to the characters in the other extended string.
    //! Note that this method is an alias of operator ==
    Standard_Boolean XTCollection_ExtendedString::IsEqual(const Standard_ExtString other) {
        return NativeHandle->IsEqual(other);
    };

    //! Returns true if the characters in this extended
    //! string are identical to the characters in the other extended string.
    //! Note that this method is an alias of operator ==
    Standard_Boolean XTCollection_ExtendedString::IsEqual(XTCollection_ExtendedString^ other) {
        return NativeHandle->IsEqual(*other->GetExtendedString());
    };

    //! Returns true if there are differences between the
    //! characters in this extended string and the other extended string.
    //! Note that this method is an alias of operator !=.
    Standard_Boolean XTCollection_ExtendedString::IsDifferent(const Standard_ExtString other) {
        return NativeHandle->IsDifferent(other);
    };

    //! Returns true if there are differences between the
    //! characters in this extended string and the other extended string.
    //! Note that this method is an alias of operator !=.
    Standard_Boolean XTCollection_ExtendedString::IsDifferent(XTCollection_ExtendedString^ other) {
        return NativeHandle->IsDifferent(*other->GetExtendedString());
    };

    //! Returns TRUE if <me> is less than <other>.
    Standard_Boolean XTCollection_ExtendedString::IsLess(const Standard_ExtString other) {
        return NativeHandle->IsLess(other);
    };

    //! Returns TRUE if <me> is less than <other>.
    Standard_Boolean XTCollection_ExtendedString::IsLess(XTCollection_ExtendedString^ other) {
        return NativeHandle->IsLess(*other->GetExtendedString());
    };

    //! Returns TRUE if <me> is greater than <other>.
    Standard_Boolean XTCollection_ExtendedString::IsGreater(const Standard_ExtString other) {
        return NativeHandle->IsGreater(other);
    };

    //! Returns TRUE if <me> is greater than <other>.
    Standard_Boolean XTCollection_ExtendedString::IsGreater(XTCollection_ExtendedString^ other) {
        return NativeHandle->IsGreater(*other->GetExtendedString());
    };

    //! Determines whether the beginning of this string instance matches the specified string.
    Standard_Boolean XTCollection_ExtendedString::StartsWith(XTCollection_ExtendedString^ theStartString) {
        return NativeHandle->StartsWith(*theStartString->GetExtendedString());
    };

    //! Determines whether the end of this string instance matches the specified string.
    Standard_Boolean XTCollection_ExtendedString::EndsWith(XTCollection_ExtendedString^ theEndString) {
        return NativeHandle->EndsWith(*theEndString->GetExtendedString());
    };

    //! Returns True if the ExtendedString contains only
    //! "Ascii Range" characters .
    Standard_Boolean XTCollection_ExtendedString::IsAscii() {
        return NativeHandle->IsAscii();
    };

    //! Returns the number of 16-bit code units
    //! (might be greater than number of Unicode symbols if string contains surrogate pairs).
    Standard_Integer XTCollection_ExtendedString::Length() {
        return NativeHandle->Length();
    };

    //! Displays <me> .
    void XTCollection_ExtendedString::Print(Standard_OStream& astream) {
        NativeHandle->Print(astream);
    };
    //friend Standard_OStream& operator << (Standard_OStream& astream, XTCollection_ExtendedString^ astring);

    //! Removes every <what> characters from <me>.
    void XTCollection_ExtendedString::RemoveAll(const Standard_ExtCharacter what) {
        NativeHandle->RemoveAll(what);
    };

    //! Erases <ahowmany> characters from position <where>,<where> included.
    void XTCollection_ExtendedString::Remove(const Standard_Integer where, const Standard_Integer ahowmany) {
        return NativeHandle->Remove(where,ahowmany);
    };

    //! Searches a ExtendedString in <me> from the beginning
    //! and returns position of first item <what> matching.
    //! it returns -1 if not found.
    Standard_Integer XTCollection_ExtendedString::Search(XTCollection_ExtendedString^ what) {
        return NativeHandle->Search(*what->GetExtendedString());
    };

    //! Searches a ExtendedString in another ExtendedString from the
    //! end and returns position of first item <what> matching.
    //! it returns -1 if not found.
    Standard_Integer XTCollection_ExtendedString::SearchFromEnd(XTCollection_ExtendedString^ what) {
        return NativeHandle->SearchFromEnd(*what->GetExtendedString());
    };

    //! Replaces one character in the ExtendedString at position <where>.
    //! If <where> is less than zero or greater than the length of <me>
    //! an exception is raised.
    void XTCollection_ExtendedString::SetValue(const Standard_Integer where, const Standard_ExtCharacter what) {
        NativeHandle->SetValue(where, what);
    };

    //! Replaces a part of <me> by another ExtendedString see above.
    void XTCollection_ExtendedString::SetValue(const Standard_Integer where, XTCollection_ExtendedString^ what) {
        return NativeHandle->SetValue(where, *what->GetExtendedString());
    };

    //! Splits this extended string into two sub-strings at position where.
    //! -   The second sub-string (from position
    //! where + 1 of this string to the end) is
    //! returned in a new extended string.
    //! -   this extended string is modified: its last
    //! characters are removed, it becomes equal to
    //! the first sub-string (from the first character to position where).
    //! Example:
    //! aString contains "abcdefg"
    //! aString.Split(3) gives <me> = "abc" and returns "defg"
    XTCollection_ExtendedString^ XTCollection_ExtendedString::Split(const Standard_Integer where) {
        return gcnew XTCollection_ExtendedString(NativeHandle->Split(where));
    };

    //! Extracts <whichone> token from <me>.
    //! By default, the <separators> is set to space and tabulation.
    //! By default, the token extracted is the first one (whichone = 1).
    //! <separators> contains all separators you need.
    //! If no token indexed by <whichone> is found, it returns an empty AsciiString.
    //! Example:
    //! aString contains "This is a     message"
    //! aString.Token()  returns "This"
    //! aString.Token(" ",4) returns "message"
    //! aString.Token(" ",2) returns "is"
    //! aString.Token(" ",9) returns ""
    //! Other separators than space character and tabulation are allowed :
    //! aString contains "1234; test:message   , value"
    //! aString.Token("; :,",4) returns "value"
    //! aString.Token("; :,",2) returns "test"
    XTCollection_ExtendedString^ XTCollection_ExtendedString::Token(const Standard_ExtString separators, const Standard_Integer whichone) {
        return gcnew XTCollection_ExtendedString(NativeHandle->Token(separators, whichone));
    };

    //! Returns pointer to ExtString
    Standard_ExtString XTCollection_ExtendedString::ToExtString() {
        return NativeHandle->ToExtString();
    };

    //! Truncates <me> to <ahowmany> characters.
    //! Example:  me = "Hello Dolly" -> Trunc(3) -> me = "Hel"
    //! Exceptions
    //! Standard_OutOfRange if ahowmany is greater
    //! than the length of this string.
    void XTCollection_ExtendedString::Trunc(const Standard_Integer ahowmany) {
        NativeHandle->Trunc(ahowmany);
    };

    //! Returns character at position <where> in <me>.
    //! If <where> is less than zero or greater than the lenght of
    //! <me>, an exception is raised.
    //! Example:
    //! aString contains "Hello"
    //! aString.Value(2) returns 'e'
    //! Exceptions
    //! Standard_OutOfRange if where lies outside
    //! the bounds of this extended string.
    Standard_ExtCharacter XTCollection_ExtendedString::Value(const Standard_Integer where) {
        return NativeHandle->Value(where);
    };

    //! Returns the System::String
    System::String^ XTCollection_ExtendedString::GetValueString() {
        TCollection_AsciiString* tAsc = new TCollection_AsciiString(*NativeHandle);
        return XStandard_Helper::toString(*tAsc);
    };

    //! Converts the internal <mystring> to UTF8 coding and
    //! returns length of the out CString. A memory for the
    //! <theCString> should be allocated before call!
    Standard_Integer XTCollection_ExtendedString::ToUTF8CString(Standard_PCharacter& theCString) {
        return NativeHandle->ToUTF8CString(theCString);
    };

    //! Returns expected CString length in UTF8 coding.
    //! It can be used for  memory  calculation  before converting
    //! to CString containing symbols in UTF8 coding.
    Standard_Integer XTCollection_ExtendedString::LengthOfCString() {
        return NativeHandle->LengthOfCString();
    };
}
