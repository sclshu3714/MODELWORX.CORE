#include "XTCollection_AsciiString.h"

namespace TKernel {

    //! Initializes a AsciiString to an empty AsciiString.
    XTCollection_AsciiString::XTCollection_AsciiString(){
        NativeHandle = new TCollection_AsciiString();
    };

    XTCollection_AsciiString::XTCollection_AsciiString(System::String^ message) {
        NativeHandle = new TCollection_AsciiString(XStandard_Helper::toAsciiString(message));
    };

    //! Initializes a AsciiString with a CString.
    XTCollection_AsciiString::XTCollection_AsciiString(Standard_CString message){
        NativeHandle = new TCollection_AsciiString(message);
    };

    //! Initializes a AsciiString with a CString.
    XTCollection_AsciiString::XTCollection_AsciiString(Standard_CString message, Standard_Integer aLen){
        NativeHandle = new TCollection_AsciiString(message, aLen);
    };

    //! Initializes a AsciiString with a single character.
    XTCollection_AsciiString::XTCollection_AsciiString(Standard_Character aChar){
        NativeHandle = new TCollection_AsciiString(aChar);
    };

    //! Initializes an AsciiString with <length> space allocated.
    //! and filled with <filler>. This is usefull for buffers.
    XTCollection_AsciiString::XTCollection_AsciiString(Standard_Integer length, Standard_Character filler){
        NativeHandle = new TCollection_AsciiString(length, filler);
    };

    //! Initializes an AsciiString with an integer value
    XTCollection_AsciiString::XTCollection_AsciiString(Standard_Integer value){
        NativeHandle = new TCollection_AsciiString(value);
    };

    //! Initializes an AsciiString with a real value
    XTCollection_AsciiString::XTCollection_AsciiString(Standard_Real value){
        NativeHandle = new TCollection_AsciiString(value);
    };

    //! Initializes a AsciiString with another AsciiString.
    XTCollection_AsciiString::XTCollection_AsciiString(TCollection_AsciiString* astring){
        NativeHandle = new TCollection_AsciiString(*astring);
    };

    //! Initializes a AsciiString with copy of another AsciiString
    //! concatenated with the message character.
    XTCollection_AsciiString::XTCollection_AsciiString(XTCollection_AsciiString^ astring, Standard_Character message){
        NativeHandle = new TCollection_AsciiString(*astring->GetAsciiString(), message);
    };

    //! Initializes a AsciiString with copy of another AsciiString
    //! concatenated with the message character.
    XTCollection_AsciiString::XTCollection_AsciiString(XTCollection_ExtendedString^ astring) {
        NativeHandle = new TCollection_AsciiString(*astring->GetExtendedString());
    };

    //! Initializes a AsciiString with copy of another AsciiString
    //! concatenated with the message string.
    XTCollection_AsciiString::XTCollection_AsciiString(XTCollection_AsciiString^  astring, Standard_CString message){
        NativeHandle = new TCollection_AsciiString(*astring->GetAsciiString(), message);
    };

    //! Initializes a AsciiString with copy of another AsciiString
    //! concatenated with the message string.
    XTCollection_AsciiString::XTCollection_AsciiString(XTCollection_AsciiString^  astring, XTCollection_AsciiString^  message){
        NativeHandle = new TCollection_AsciiString(*astring->GetAsciiString(), *message->GetAsciiString());
    };

    //!
    TCollection_AsciiString* XTCollection_AsciiString::GetAsciiString(){
        return NativeHandle;
    };

    //! Appends <other>  to me. This is an unary operator.
    void  XTCollection_AsciiString::AssignCat(Standard_Character other){   
        NativeHandle->AssignCat(other);
    };

    //! Appends <other>  to me. This is an unary operator.
    void  XTCollection_AsciiString::AssignCat(Standard_Integer other){
        NativeHandle->AssignCat(other);
    };

    //! Appends <other>  to me. This is an unary operator.
    void  XTCollection_AsciiString::AssignCat(Standard_Real other){
        NativeHandle->AssignCat(other);
    };

    //! Appends <other>  to me. This is an unary operator.
    //! ex: aString += "Dummy"
    //! To catenate more than one CString, you must put a
    //! AsciiString before.
    //! Example: aString += "Hello " + "Dolly"  IS NOT VALID !
    //! But astring += anotherString + "Hello " + "Dolly" is valid.
    void  XTCollection_AsciiString::AssignCat(Standard_CString other){
        NativeHandle->AssignCat(other);
    };

    //! Appends <other> to me. This is an unary operator.
    //! Example: aString += anotherString
    void  XTCollection_AsciiString::AssignCat(XTCollection_AsciiString^  other){
        NativeHandle->AssignCat(*other->GetAsciiString());
    };

    //! Converts the first character into its corresponding
    //! upper-case character and the other characters into lowercase
    //! Example: before
    //! me = "hellO "
    //! after
    //! me = "Hello "
    void  XTCollection_AsciiString::Capitalize(){
        NativeHandle->Capitalize();
    };

    //! Appends <other>  to me.
    //! Syntax:
    //! aString = aString + "Dummy"
    //! Example: aString contains "I say "
    //! aString = aString + "Hello " + "Dolly"
    //! gives "I say Hello Dolly"
    //! To catenate more than one CString, you must put a String before.
    //! So the following example is WRONG !
    //! aString = "Hello " + "Dolly"  THIS IS NOT ALLOWED
    //! This rule is applicable to AssignCat (operator +=) too.
    XTCollection_AsciiString^ XTCollection_AsciiString::Cat(Standard_Character other){
        TCollection_AsciiString* temp = new TCollection_AsciiString(NativeHandle->Cat(other));
        return gcnew XTCollection_AsciiString(temp);
    };

    //! Appends <other>  to me.
    //! Syntax:
    //! aString = aString + 15;
    //! Example: aString contains "I say "
    //! gives "I say 15"
    //! To catenate more than one CString, you must put a String before.
    //! So the following example is WRONG !
    //! aString = "Hello " + "Dolly"  THIS IS NOT ALLOWED
    //! This rule is applicable to AssignCat (operator +=) too.
    XTCollection_AsciiString^ XTCollection_AsciiString::Cat(Standard_Integer other){
        TCollection_AsciiString* temp = new TCollection_AsciiString(NativeHandle->Cat(other));
        return gcnew XTCollection_AsciiString(temp);
    };

    //! Appends <other>  to me.
    //! Syntax:
    //! aString = aString + 15.15;
    //! Example: aString contains "I say "
    //! gives "I say 15.15"
    //! To catenate more than one CString, you must put a String before.
    //! So the following example is WRONG !
    //! aString = "Hello " + "Dolly"  THIS IS NOT ALLOWED
    //! This rule is applicable to AssignCat (operator +=) too.
    XTCollection_AsciiString^ XTCollection_AsciiString::Cat(Standard_Real other){
        TCollection_AsciiString* temp = new TCollection_AsciiString(NativeHandle->Cat(other));
        return  gcnew XTCollection_AsciiString(temp);
    };

    //! Appends <other>  to me.
    //! Syntax:
    //! aString = aString + "Dummy"
    //! Example: aString contains "I say "
    //! aString = aString + "Hello " + "Dolly"
    //! gives "I say Hello Dolly"
    //! To catenate more than one CString, you must put a String before.
    //! So the following example is WRONG !
    //! aString = "Hello " + "Dolly"  THIS IS NOT ALLOWED
    //! This rule is applicable to AssignCat (operator +=) too.
    XTCollection_AsciiString^ XTCollection_AsciiString::Cat(Standard_CString other){
        TCollection_AsciiString* temp = new TCollection_AsciiString(NativeHandle->Cat(other));
        return  gcnew XTCollection_AsciiString(temp);
    };

    //! Appends <other> to me.
    //! Example: aString = aString + anotherString
    XTCollection_AsciiString^ XTCollection_AsciiString::Cat(XTCollection_AsciiString^  other){
        TCollection_AsciiString* temp = new TCollection_AsciiString(NativeHandle->Cat(*other->GetAsciiString()));
        return  gcnew XTCollection_AsciiString(temp);
    };

    //! Modifies this ASCII string so that its length
    //! becomes equal to Width and the new characters
    //! are equal to Filler. New characters are added
    //! both at the beginning and at the end of this string.
    //! If Width is less than the length of this ASCII string, nothing happens.
    //! Example
    //! XTCollection_AsciiString
    //! myAlphabet("abcdef"){       };
    //! myAlphabet.Center(9,' '){       };
    //! assert ( myAlphabet == "
    //! abcdef " ){       };
    void  XTCollection_AsciiString::Center(Standard_Integer Width, Standard_Character Filler){
        NativeHandle->Center(Width, Filler);
    };

    //! Substitutes all the characters equal to aChar by NewChar
    //! in the AsciiString <me>.
    //! The substitution can be case sensitive.
    //! If you don't use default case sensitive, no matter wether aChar
    //! is uppercase or not.
    //! Example: me = "Histake" -> ChangeAll('H','M',Standard_True)
    //! gives me = "Mistake"
    //! Standard_Boolean CaseSensitive = Standard_True
    void  XTCollection_AsciiString::ChangeAll(Standard_Character aChar, Standard_Character NewChar, Standard_Boolean CaseSensitive){
        NativeHandle->ChangeAll(aChar, NewChar, CaseSensitive);
    };

    //! Removes all characters contained in <me>.
    //! This produces an empty AsciiString.
    void  XTCollection_AsciiString::Clear(){
        NativeHandle->Clear();
    };

    //! Copy <fromwhere> to <me>.
    //! Used as operator =
    //! Example: aString = anotherCString;
    void  XTCollection_AsciiString::Copy(Standard_CString fromwhere){
        NativeHandle->Copy(fromwhere);
    };

    //! Copy <fromwhere> to <me>.
    //! Used as operator =
    //! Example: aString = anotherString;
    void  XTCollection_AsciiString::Copy(XTCollection_AsciiString^  fromwhere){
        NativeHandle->Copy(*fromwhere->GetAsciiString());
    };

    //! Exchange the data of two strings (without reallocating memory).
    void  XTCollection_AsciiString::Swap(XTCollection_AsciiString^  theOther){
        NativeHandle->Swap(*theOther->GetAsciiString());
    };

    //! Frees memory allocated by AsciiString.
    XTCollection_AsciiString::~XTCollection_AsciiString(){
        NativeHandle->~TCollection_AsciiString();
        delete NativeHandle;
        NativeHandle = NULL;
    };

    //! Returns the index of the first character of <me> that is
    //! present in <Set>.
    //! The search begins to the index FromIndex and ends to the
    //! the index ToIndex.
    //! Returns zero if failure.
    //! Raises an exception if FromIndex or ToIndex is out of range.
    //! Example: before
    //! me = "aabAcAa", S = "Aa", FromIndex = 1, Toindex = 7
    //! after
    //! me = "aabAcAa"
    //! returns
    //! 1
    Standard_Integer XTCollection_AsciiString::FirstLocationInSet(XTCollection_AsciiString^ Set, Standard_Integer FromIndex, Standard_Integer ToIndex){
        return NativeHandle->FirstLocationInSet(*Set->GetAsciiString(), FromIndex, ToIndex);
    };

    //! Returns the index of the first character of <me>
    //! that is not present in the set <Set>.
    //! The search begins to the index FromIndex and ends to the
    //! the index ToIndex in <me>.
    //! Returns zero if failure.
    //! Raises an exception if FromIndex or ToIndex is out of range.
    //! Example: before
    //! me = "aabAcAa", S = "Aa", FromIndex = 1, Toindex = 7
    //! after
    //! me = "aabAcAa"
    //! returns
    //! 3
    Standard_Integer XTCollection_AsciiString::FirstLocationNotInSet(XTCollection_AsciiString^  Set, Standard_Integer FromIndex, Standard_Integer ToIndex){
        return NativeHandle->FirstLocationNotInSet(*Set->GetAsciiString(), FromIndex, ToIndex);
    };

    //! Inserts a Character at position <where>.
    //! Example:
    //! aString contains "hy not ?"
    //! aString.Insert(1,'W'){       }; gives "Why not ?"
    //! aString contains "Wh"
    //! aString.Insert(3,'y'){       }; gives "Why"
    //! aString contains "Way"
    //! aString.Insert(2,'h'){       }; gives "Why"
    void  XTCollection_AsciiString::Insert(Standard_Integer where, Standard_Character what){
        NativeHandle->Insert(where, what);
    };

    //! Inserts a CString at position <where>.
    //! Example:
    //! aString contains "O more"
    //! aString.Insert(2,"nce"){       };  gives "Once more"
    void  XTCollection_AsciiString::Insert(Standard_Integer where, Standard_CString what){
        NativeHandle->Insert(where, what);
    };

    //! Inserts a AsciiString at position <where>.
    void  XTCollection_AsciiString::Insert(Standard_Integer where, XTCollection_AsciiString^  what){
        NativeHandle->Insert(where, *what->GetAsciiString());
    };

    //! Pushing a string after a specific index in the string <me>.
    //! Raises an exception if Index is out of bounds.
    //! -   less than 0 (InsertAfter), or less than 1 (InsertBefore), or
    //! -   greater than the number of characters in this ASCII string.
    //! Example:
    //! before
    //! me = "cde" , Index = 0 , other = "ab"
    //! after
    //! me = "abcde" , other = "ab"
    void  XTCollection_AsciiString::InsertAfter(Standard_Integer Index, XTCollection_AsciiString^  other){
        NativeHandle->InsertAfter(Index, *other->GetAsciiString());
    };

    //! Pushing a string before a specific index in the string <me>.
    //! Raises an exception if Index is out of bounds.
    //! -   less than 0 (InsertAfter), or less than 1 (InsertBefore), or
    //! -   greater than the number of characters in this ASCII string.
    //! Example:
    //! before
    //! me = "cde" , Index = 1 , other = "ab"
    //! after
    //! me = "abcde" , other = "ab"
    void  XTCollection_AsciiString::InsertBefore(Standard_Integer Index, XTCollection_AsciiString^  other){
        NativeHandle->InsertBefore(Index, *other->GetAsciiString());
    };

    //! Returns True if the string <me> contains zero character.
    Standard_Boolean XTCollection_AsciiString::IsEmpty(){
        return NativeHandle->IsEmpty();
    };

    //! Returns true if the characters in this ASCII string
    //! are identical to the characters in ASCII string other.
    //! Note that this method is an alias of operator ==.
    Standard_Boolean XTCollection_AsciiString::IsEqual(Standard_CString other){
        return NativeHandle->IsEqual(other);
    };

    //! Returns true if the characters in this ASCII string
    //! are identical to the characters in ASCII string other.
    //! Note that this method is an alias of operator ==.
    Standard_Boolean XTCollection_AsciiString::IsEqual(XTCollection_AsciiString^  other){
        return NativeHandle->IsEqual(*other->GetAsciiString());
    };

    //! Returns true if there are differences between the
    //! characters in this ASCII string and ASCII string other.
    //! Note that this method is an alias of operator !=
    Standard_Boolean XTCollection_AsciiString::IsDifferent(Standard_CString other){
        return NativeHandle->IsDifferent(other);
    };

    //! Returns true if there are differences between the
    //! characters in this ASCII string and ASCII string other.
    //! Note that this method is an alias of operator !=
    Standard_Boolean XTCollection_AsciiString::IsDifferent(XTCollection_AsciiString^  other){
        return NativeHandle->IsDifferent(*other->GetAsciiString());
    };

    //! Returns TRUE if <me> is 'ASCII' less than <other>.
    Standard_Boolean XTCollection_AsciiString::IsLess(Standard_CString other){
        return NativeHandle->IsLess(other);
    };

    //! Returns TRUE if <me> is 'ASCII' less than <other>.
    Standard_Boolean XTCollection_AsciiString::IsLess(XTCollection_AsciiString^  other){
        return NativeHandle->IsLess(*other->GetAsciiString());
    };

    //! Returns TRUE if <me> is 'ASCII' greater than <other>.
    Standard_Boolean XTCollection_AsciiString::IsGreater(Standard_CString other){
        return NativeHandle->IsGreater(other);
    };

    //! Returns TRUE if <me> is 'ASCII' greater than <other>.
    Standard_Boolean XTCollection_AsciiString::IsGreater(XTCollection_AsciiString^  other){
        return NativeHandle->IsGreater(*other->GetAsciiString());
    };

    //! Determines whether the beginning of this string instance matches the specified string.
    Standard_Boolean XTCollection_AsciiString::StartsWith(XTCollection_AsciiString^  theStartString){
        return NativeHandle->StartsWith(*theStartString->GetAsciiString());
    };

    //! Determines whether the end of this string instance matches the specified string.
    Standard_Boolean XTCollection_AsciiString::EndsWith(XTCollection_AsciiString^  theEndString){
        return NativeHandle->EndsWith(*theEndString->GetAsciiString());
    };

    //! Converts a AsciiString containing a numeric expression to
    //! an Integer.
    //! Example: "215" returns 215.
    Standard_Integer XTCollection_AsciiString::IntegerValue(){
        return NativeHandle->IntegerValue();
    };

    //! Returns True if the AsciiString contains an integer value.
    //! Note: an integer value is considered to be a real value as well.
    Standard_Boolean XTCollection_AsciiString::IsIntegerValue(){
        return NativeHandle->IsIntegerValue();
    };

    //! Returns True if the AsciiString contains a real value.
    //! Note: an integer value is considered to be a real value as well.
    Standard_Boolean XTCollection_AsciiString::IsRealValue(){
        return NativeHandle->IsRealValue();
    };

    //! Returns True if the AsciiString contains only ASCII characters
    //! between ' ' and '~'.
    //! This means no control character and no extended ASCII code.
    Standard_Boolean XTCollection_AsciiString::IsAscii(){
        return NativeHandle->IsAscii();
    };

    //! Removes all space characters in the begining of the string.
    void  XTCollection_AsciiString::LeftAdjust(){
        NativeHandle->LeftAdjust();
    };

    //! left justify
    //! Length becomes equal to Width and the new characters are
    //! equal to Filler.
    //! If Width < Length nothing happens.
    //! Raises an exception if Width is less than zero.
    //! Example:
    //! before
    //! me = "abcdef" , Width = 9 , Filler = ' '
    //! after
    //! me = "abcdef   "
    void  XTCollection_AsciiString::LeftJustify(Standard_Integer Width, Standard_Character Filler){
        NativeHandle->LeftJustify(Width, Filler);
    };

    //! Returns number of characters in <me>.
    //! This is the same functionality as 'strlen' in C.
    //! Example
    //! XTCollection_AsciiString myAlphabet("abcdef"){       };
    //! assert ( myAlphabet.Length() == 6 ){       };
    //! -   1 is the position of the first character in this string.
    //! -   The length of this string gives the position of its last character.
    //! -   Positions less than or equal to zero, or
    //! greater than the length of this string are
    //! invalid in functions which identify a character
    //! of this string by its position.
    Standard_Integer XTCollection_AsciiString::Length(){
        return NativeHandle->Length();
    };

    //! Returns an index in the string <me> of the first occurence
    //! of the string S in the string <me> from the starting index
    //! FromIndex to the ending index ToIndex
    //! returns zero if failure
    //! Raises an exception if FromIndex or ToIndex is out of range.
    //! Example:
    //! before
    //! me = "aabAaAa", S = "Aa", FromIndex = 1, ToIndex = 7
    //! after
    //! me = "aabAaAa"
    //! returns
    //! 4
    Standard_Integer XTCollection_AsciiString::Location(XTCollection_AsciiString^  other, Standard_Integer FromIndex, Standard_Integer ToIndex){
        return NativeHandle->Location(*other->GetAsciiString(), FromIndex, ToIndex);
    };

    //! Returns the index of the nth occurence of the character C
    //! in the string <me> from the starting index FromIndex to the
    //! ending index ToIndex.
    //! Returns zero if failure.
    //! Raises an exception if FromIndex or ToIndex is out of range.
    //! Example:
    //! before
    //! me = "aabAa", N = 3, C = 'a', FromIndex = 1, ToIndex = 5
    //! after
    //! me = "aabAa"
    //! returns
    //! 5
    Standard_Integer XTCollection_AsciiString::Location(Standard_Integer N, Standard_Character C, Standard_Integer FromIndex, Standard_Integer ToIndex){
        return NativeHandle->Location(N, C, FromIndex, ToIndex);
    };

    //! Converts <me> to its lower-case equivalent.
    //! Example
    //! XTCollection_AsciiString myString("Hello Dolly"){       };
    //! myString.UpperCase(){       };
    //! assert ( myString == "HELLO DOLLY" ){       };
    //! myString.LowerCase(){       };
    //! assert ( myString == "hello dolly" ){       };
    void  XTCollection_AsciiString::LowerCase(){
        NativeHandle->LowerCase();
    };

    //! Inserts the string other at the beginning of this ASCII string.
    //! Example
    //! XTCollection_AsciiString myAlphabet("cde"){       };
    //! XTCollection_AsciiString myBegin("ab"){       };
    //! myAlphabet.Prepend(myBegin){       };
    //! assert ( myAlphabet == "abcde" ){       };
    void  XTCollection_AsciiString::Prepend(XTCollection_AsciiString^  other){
        NativeHandle->Prepend(*other->GetAsciiString());
    };

    //! Displays <me> on a stream.
    void  XTCollection_AsciiString::Print(Standard_OStream& astream){
        NativeHandle->Print(astream);
    };
    //! friend Standard_OStream& operator << (Standard_OStream& astream, XTCollection_AsciiString^  astring){       };

    //! Read <me> from a stream.
    void  XTCollection_AsciiString::Read(Standard_IStream& astream){
        NativeHandle->Read(astream);
    };
    //! friend Standard_IStream& operator >> (Standard_IStream& astream, XTCollection_AsciiString^  astring){       };

    //! Converts an AsciiString containing a numeric expression.
    //! to a Real.
    //! Example: ex: "215" returns 215.0.
    //! ex: "3.14159267" returns 3.14159267.
    Standard_Real XTCollection_AsciiString::RealValue(){
        return NativeHandle->RealValue();
    };

    //! Remove all the occurences of the character C in the string.
    //! Example:
    //! before
    //! me = "HellLLo", C = 'L' , CaseSensitive = True
    //! after
    //! me = "Hello"
    void  XTCollection_AsciiString::RemoveAll(Standard_Character C, Standard_Boolean CaseSensitive){
        NativeHandle->RemoveAll(C, CaseSensitive);
    };

    //! Removes every <what> characters from <me>.
    void  XTCollection_AsciiString::RemoveAll(Standard_Character what){
        NativeHandle->RemoveAll(what);
    };

    //! Erases <ahowmany> characters from position <where>,
    //! <where> included.
    //! Example:
    //! aString contains "Hello"
    //! aString.Remove(2,2) erases 2 characters from position 2
    //! This gives "Hlo".
    //! Standard_Integer ahowmany = 1
    void  XTCollection_AsciiString::Remove(Standard_Integer where, Standard_Integer ahowmany){
        NativeHandle->Remove(where, ahowmany);
    };

    //! Removes all space characters at the end of the string.
    void  XTCollection_AsciiString::RightAdjust(){
        NativeHandle->RightAdjust();
    };

    //! Right justify.
    //! Length becomes equal to Width and the new characters are
    //! equal to Filler.
    //! if Width < Length nothing happens.
    //! Raises an exception if Width is less than zero.
    //! Example:
    //! before
    //! me = "abcdef" , Width = 9 , Filler = ' '
    //! after
    //! me = "   abcdef"
    void  XTCollection_AsciiString::RightJustify(Standard_Integer Width, Standard_Character Filler){
        NativeHandle->RightJustify(Width, Filler);
    };

    //! Searches a CString in <me> from the beginning
    //! and returns position of first item <what> matching.
    //! it returns -1 if not found.
    //! Example:
    //! aString contains "Sample single test"
    //! aString.Search("le") returns 5
    Standard_Integer XTCollection_AsciiString::Search(Standard_CString what){
        return NativeHandle->Search(what);
    };

    //! Searches an AsciiString in <me> from the beginning
    //! and returns position of first item <what> matching.
    //! It returns -1 if not found.
    Standard_Integer XTCollection_AsciiString::Search(XTCollection_AsciiString^  what){
        return NativeHandle->Search(*what->GetAsciiString());
    };

    //! Searches a CString in a AsciiString from the end
    //! and returns position of first item <what> matching.
    //! It returns -1 if not found.
    //! Example:
    //! aString contains "Sample single test"
    //! aString.SearchFromEnd("le") returns 12
    Standard_Integer XTCollection_AsciiString::SearchFromEnd(Standard_CString what){
        return NativeHandle->SearchFromEnd(what);
    };

    //! Searches a AsciiString in another AsciiString from the end
    //! and returns position of first item <what> matching.
    //! It returns -1 if not found.
    Standard_Integer XTCollection_AsciiString::SearchFromEnd(XTCollection_AsciiString^  what){
        return NativeHandle->SearchFromEnd(*what->GetAsciiString());
    };

    //! Replaces one character in the AsciiString at position <where>.
    //! If <where> is less than zero or greater than the length of <me>
    //! an exception is raised.
    //! Example:
    //! aString contains "Garbake"
    //! astring.Replace(6,'g')  gives <me> = "Garbage"
    void  XTCollection_AsciiString::SetValue(Standard_Integer where, Standard_Character what){
        NativeHandle->SetValue(where, what);
    };

    //! Replaces a part of <me> by a CString.
    //! If <where> is less than zero or greater than the length of <me>
    //! an exception is raised.
    //! Example:
    //! aString contains "abcde"
    //! aString.SetValue(4,"1234567") gives <me> = "abc1234567"
    void  XTCollection_AsciiString::SetValue(Standard_Integer where, Standard_CString what){
        NativeHandle->SetValue(where, what);
    };

    //! Replaces a part of <me> by another AsciiString.
    void  XTCollection_AsciiString::SetValue(Standard_Integer where, XTCollection_AsciiString^  what){
        NativeHandle->SetValue(where, *what->GetAsciiString());
    };

    //! Splits a AsciiString into two sub-strings.
    //! Example:
    //! aString contains "abcdefg"
    //! aString.Split(3) gives <me> = "abc" and returns "defg"
    XTCollection_AsciiString^ XTCollection_AsciiString::Split(Standard_Integer where){
        TCollection_AsciiString* temp = new TCollection_AsciiString(NativeHandle->Split(where));
        return gcnew XTCollection_AsciiString(temp);
    };

    //! Creation of a sub-string of the string <me>.
    //! The sub-string starts to the index Fromindex and ends
    //! to the index ToIndex.
    //! Raises an exception if ToIndex or FromIndex is out of bounds
    //! Example:
    //! before
    //! me = "abcdefg", ToIndex=3, FromIndex=6
    //! after
    //! me = "abcdefg"
    //! returns
    //! "cdef"
    XTCollection_AsciiString^ XTCollection_AsciiString::SubString(Standard_Integer FromIndex, Standard_Integer ToIndex){
        TCollection_AsciiString* temp = new TCollection_AsciiString(NativeHandle->SubString(FromIndex, ToIndex));
        return gcnew XTCollection_AsciiString(temp);
    };

    //! Returns pointer to AsciiString (char *).
    //! This is useful for some casual manipulations.
    //! Warning: Because this "char *" is 'const', you can't modify its contents.
    Standard_CString XTCollection_AsciiString::ToCString(){
        return NativeHandle->ToCString();
    };

    String^ XTCollection_AsciiString::ValueToCString() {
        Standard_CString CString = NativeHandle->ToCString();
        return XStandard_Helper::toString(CString);
    };

    //! Extracts <whichone> token from <me>.
    //! By default, the <separators> is set to space and tabulation.
    //! By default, the token extracted is the first one (whichone = 1).
    //! <separators> contains all separators you need.
    //! If no token indexed by <whichone> is found, it returns empty AsciiString.
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
    //! Standard_CString separators = " \t", Standard_Integer whichone = 1
    XTCollection_AsciiString^ XTCollection_AsciiString::Token(Standard_CString separators, Standard_Integer whichone){
        TCollection_AsciiString* temp = new TCollection_AsciiString(NativeHandle->Token(separators, whichone));
        return gcnew XTCollection_AsciiString(temp);
    };

    //! Truncates <me> to <ahowmany> characters.
    //! Example:  me = "Hello Dolly" -> Trunc(3) -> me = "Hel"
    void  XTCollection_AsciiString::Trunc(Standard_Integer ahowmany){
        NativeHandle->Trunc(ahowmany);
    };

    //! Converts <me> to its upper-case equivalent.
    void  XTCollection_AsciiString::UpperCase(){
        NativeHandle->UpperCase();
    };

    //! Length of the string ignoring all spaces (' ') and the
    //! control character at the end.
    Standard_Integer XTCollection_AsciiString::UsefullLength(){
        return NativeHandle->UsefullLength();
    };

    //! Returns character at position <where> in <me>.
    //! If <where> is less than zero or greater than the lenght of <me>,
    //! an exception is raised.
    //! Example:
    //! aString contains "Hello"
    //! aString.Value(2) returns 'e'
    Standard_Character XTCollection_AsciiString::Value(Standard_Integer where){
        return NativeHandle->Value(where);
    };

    //! Computes a hash code for the given ASCII string, in the range [1, theUpperBound].
    //! Returns the same integer value as the hash function for TCollection_ExtendedString
    //! @param theAsciiString the ASCII string which hash code is to be computed
    //! @param theUpperBound the upper bound of the range a computing hash code must be within
    //! @return a computed hash code, in the range [1, theUpperBound]
    //!static 
    Standard_Integer XTCollection_AsciiString::HashCode(XTCollection_AsciiString^  theAsciiString, Standard_Integer theUpperBound){
        return TCollection_AsciiString::HashCode(*theAsciiString->GetAsciiString(), theUpperBound);
    };

    //! Returns True  when the two  strings are the same.
    //! (Just for HashCode for AsciiString)
    //!static 
    Standard_Boolean XTCollection_AsciiString::IsEqual(XTCollection_AsciiString^  string1, XTCollection_AsciiString^  string2){
        return TCollection_AsciiString::IsEqual(*string1->GetAsciiString(), *string2->GetAsciiString());
    };

    //! Returns True  when the two  strings are the same.
    //! (Just for HashCode for AsciiString)
    //!static 
    Standard_Boolean XTCollection_AsciiString::IsEqual(XTCollection_AsciiString^  string1, Standard_CString string2){
       return TCollection_AsciiString::IsEqual(*string1->GetAsciiString(), string2);
    };

    //! Returns True if the strings contain same characters.
    //!static 
    Standard_Boolean XTCollection_AsciiString::IsSameString(XTCollection_AsciiString^  theString1, XTCollection_AsciiString^  theString2, Standard_Boolean theIsCaseSensitive){
       return TCollection_AsciiString::IsSameString(*theString1->GetAsciiString(), *theString2->GetAsciiString(), theIsCaseSensitive);
    };
}