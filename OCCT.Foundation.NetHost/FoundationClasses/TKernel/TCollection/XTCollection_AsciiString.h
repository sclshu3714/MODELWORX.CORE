// Created on: 1993-02-22
// Created by: Mireille MERCIEN
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

#ifndef _XTCollection_AsciiString_HeaderFile
#define _XTCollection_AsciiString_HeaderFile
#pragma once
#include <TCollection_AsciiString.hxx>
#include "NCollection_Haft.h"
#include "XStandard_Helper.h"
#include "XTCollection_ExtendedString.h"

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <Standard_PCharacter.hxx>
#include <Standard_Integer.hxx>
#include <Standard_CString.hxx>
#include <Standard_Character.hxx>
#include <Standard_Real.hxx>
#include <Standard_Boolean.hxx>
#include <Standard_OStream.hxx>
#include <Standard_IStream.hxx>
class Standard_NullObject;
class Standard_OutOfRange;
class Standard_NumericError;
class Standard_NegativeValue;
class TCollection_HAsciiString;
class TCollection_ExtendedString;
//! Class defines a variable-length sequence of 8-bit characters.
//! Despite class name (kept for historical reasons), it is intended to store UTF-8 string, not just ASCII characters.
//! However, multi-byte nature of UTF-8 is not considered by the following methods:
//! - Method ::Length() return the number of bytes, not the number of Unicode symbols.
//! - Methods taking/returning symbol index work with 8-bit code units, not true Unicode symbols,
//!   including ::Remove(), ::SetValue(), ::Value(), ::Search(), ::Trunc() and others.
//! If application needs to process multi-byte Unicode symbols explicitly, NCollection_Utf8Iter class can be used
//! for iterating through Unicode string (UTF-32 code unit will be returned for each position).
//!
//! Class provides editing operations with built-in memory management to make AsciiString objects easier to use than ordinary character arrays.
//! AsciiString objects follow value semantics; in other words, they are the actual strings,
//! not handles to strings, and are copied through assignment.
//! You may use HAsciiString objects to get handles to strings.
namespace TKernel {
    //ref class XStandard_Helper;
    public ref class XTCollection_AsciiString
    {
    public:

        //! DEFINE_STANDARD_ALLOC
        !XTCollection_AsciiString() { IHandle = NULL; };

        //! Initializes a AsciiString to an empty AsciiString.
        XTCollection_AsciiString();

        //! Initializes a AsciiString with a CString.
        XTCollection_AsciiString(System::String^ message);

        //! Initializes a AsciiString with a CString.
        XTCollection_AsciiString(Standard_CString message);

        //! Initializes a AsciiString with a CString.
        XTCollection_AsciiString(Standard_CString message, Standard_Integer aLen);

        //! Initializes a AsciiString with a single character.
        XTCollection_AsciiString(Standard_Character aChar);

        //! Initializes an AsciiString with <length> space allocated.
        //! and filled with <filler>. This is usefull for buffers.
        XTCollection_AsciiString(Standard_Integer length, Standard_Character filler);

        //! Initializes an AsciiString with an integer value
        XTCollection_AsciiString(Standard_Integer value);

        //! Initializes an AsciiString with a real value
        XTCollection_AsciiString(Standard_Real value);

        //! Initializes a AsciiString with another AsciiString.
        XTCollection_AsciiString(TCollection_AsciiString* astring);

        //! Initializes a AsciiString with copy of another AsciiString
        //! concatenated with the message character.
        XTCollection_AsciiString(XTCollection_AsciiString^ astring, Standard_Character message);

        //! Initializes a AsciiString with copy of another AsciiString
        //! concatenated with the message character.
        XTCollection_AsciiString(XTCollection_ExtendedString^ astring);
        //! Initializes a AsciiString with copy of another AsciiString
        //! concatenated with the message string.
        XTCollection_AsciiString(XTCollection_AsciiString^ astring, Standard_CString message);

        //! Initializes a AsciiString with copy of another AsciiString
        //! concatenated with the message string.
        XTCollection_AsciiString(XTCollection_AsciiString^ astring, XTCollection_AsciiString^ message);

        //!
        TCollection_AsciiString* GetAsciiString();

        //! Appends <other>  to me. This is an unary operator.
        void AssignCat(Standard_Character other);
        void operator += (Standard_Character other)
        {
            AssignCat(other);
        }

        //! Appends <other>  to me. This is an unary operator.
        void AssignCat(Standard_Integer other);
        void operator += (Standard_Integer other)
        {
            AssignCat(other);
        }

        //! Appends <other>  to me. This is an unary operator.
        void AssignCat(Standard_Real other);
        void operator += (Standard_Real other)
        {
            AssignCat(other);
        }

        //! Appends <other>  to me. This is an unary operator.
        //! ex: aString += "Dummy"
        //! To catenate more than one CString, you must put a
        //! AsciiString before.
        //! Example: aString += "Hello " + "Dolly"  IS NOT VALID !
        //! But astring += anotherString + "Hello " + "Dolly" is valid.
        void AssignCat(Standard_CString other);
        void operator += (Standard_CString other)
        {
            AssignCat(other);
        }

        //! Appends <other> to me. This is an unary operator.
        //! Example: aString += anotherString
        void AssignCat(XTCollection_AsciiString^ other);
        void operator += (XTCollection_AsciiString^ other)
        {
            AssignCat(other);
        }

        //! Converts the first character into its corresponding
        //! upper-case character and the other characters into lowercase
        //! Example: before
        //! me = "hellO "
        //! after
        //! me = "Hello "
        void Capitalize();

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
        XTCollection_AsciiString^ Cat(Standard_Character other);
        XTCollection_AsciiString^ operator + (Standard_Character other)
        {
            return Cat(other);
        }

        //! Appends <other>  to me.
        //! Syntax:
        //! aString = aString + 15;
        //! Example: aString contains "I say "
        //! gives "I say 15"
        //! To catenate more than one CString, you must put a String before.
        //! So the following example is WRONG !
        //! aString = "Hello " + "Dolly"  THIS IS NOT ALLOWED
        //! This rule is applicable to AssignCat (operator +=) too.
        XTCollection_AsciiString^ Cat(Standard_Integer other);
        XTCollection_AsciiString^ operator + (Standard_Integer other)
        {
            return Cat(other);
        }

        //! Appends <other>  to me.
        //! Syntax:
        //! aString = aString + 15.15;
        //! Example: aString contains "I say "
        //! gives "I say 15.15"
        //! To catenate more than one CString, you must put a String before.
        //! So the following example is WRONG !
        //! aString = "Hello " + "Dolly"  THIS IS NOT ALLOWED
        //! This rule is applicable to AssignCat (operator +=) too.
        XTCollection_AsciiString^ Cat(Standard_Real other);
        XTCollection_AsciiString^ operator + (Standard_Real other)
        {
            return Cat(other);
        }

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
        XTCollection_AsciiString^ Cat(Standard_CString other);
        XTCollection_AsciiString^ operator + (Standard_CString other)
        {
            return Cat(other);
        }

        //! Appends <other> to me.
        //! Example: aString = aString + anotherString
        XTCollection_AsciiString^ Cat(XTCollection_AsciiString^ other);
        XTCollection_AsciiString^ operator + (XTCollection_AsciiString^ other)
        {
            return Cat(other);
        }

        //! Modifies this ASCII string so that its length
        //! becomes equal to Width and the new characters
        //! are equal to Filler. New characters are added
        //! both at the beginning and at the end of this string.
        //! If Width is less than the length of this ASCII string, nothing happens.
        //! Example
        //! XTCollection_AsciiString
        //! myAlphabet("abcdef");
        //! myAlphabet.Center(9,' ');
        //! assert ( myAlphabet == "
        //! abcdef " );
        void Center(Standard_Integer Width, Standard_Character Filler);

        //! Substitutes all the characters equal to aChar by NewChar
        //! in the AsciiString <me>.
        //! The substitution can be case sensitive.
        //! If you don't use default case sensitive, no matter wether aChar
        //! is uppercase or not.
        //! Example: me = "Histake" -> ChangeAll('H','M',Standard_True)
        //! gives me = "Mistake"
        //! Standard_Boolean CaseSensitive = Standard_True
        void ChangeAll(Standard_Character aChar, Standard_Character NewChar, Standard_Boolean CaseSensitive);

        //! Removes all characters contained in <me>.
        //! This produces an empty AsciiString.
        void Clear();

        //! Copy <fromwhere> to <me>.
        //! Used as operator =
        //! Example: aString = anotherCString;
        void Copy(Standard_CString fromwhere);
        void operator = (Standard_CString fromwhere)
        {
            Copy(fromwhere);
        }

        //! Copy <fromwhere> to <me>.
        //! Used as operator =
        //! Example: aString = anotherString;
        void Copy(XTCollection_AsciiString^ fromwhere);
        void operator = (XTCollection_AsciiString^ fromwhere)
        {
            Copy(fromwhere);
        }

        //! Exchange the data of two strings (without reallocating memory).
        void Swap(XTCollection_AsciiString^ theOther);

#ifndef OCCT_NO_RVALUE_REFERENCE
        //! Move assignment operator
        XTCollection_AsciiString^ operator= (XTCollection_AsciiString^& theOther) { Swap(theOther); return this; }
#endif

        //! Frees memory allocated by AsciiString.
        ~XTCollection_AsciiString();

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
        Standard_Integer FirstLocationInSet(XTCollection_AsciiString^ Set, Standard_Integer FromIndex, Standard_Integer ToIndex);

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
        Standard_Integer FirstLocationNotInSet(XTCollection_AsciiString^ Set, Standard_Integer FromIndex, Standard_Integer ToIndex);

        //! Inserts a Character at position <where>.
        //! Example:
        //! aString contains "hy not ?"
        //! aString.Insert(1,'W'); gives "Why not ?"
        //! aString contains "Wh"
        //! aString.Insert(3,'y'); gives "Why"
        //! aString contains "Way"
        //! aString.Insert(2,'h'); gives "Why"
        void Insert(Standard_Integer where, Standard_Character what);

        //! Inserts a CString at position <where>.
        //! Example:
        //! aString contains "O more"
        //! aString.Insert(2,"nce");  gives "Once more"
        void Insert(Standard_Integer where, Standard_CString what);

        //! Inserts a AsciiString at position <where>.
        void Insert(Standard_Integer where, XTCollection_AsciiString^ what);

        //! Pushing a string after a specific index in the string <me>.
        //! Raises an exception if Index is out of bounds.
        //! -   less than 0 (InsertAfter), or less than 1 (InsertBefore), or
        //! -   greater than the number of characters in this ASCII string.
        //! Example:
        //! before
        //! me = "cde" , Index = 0 , other = "ab"
        //! after
        //! me = "abcde" , other = "ab"
        void InsertAfter(Standard_Integer Index, XTCollection_AsciiString^ other);

        //! Pushing a string before a specific index in the string <me>.
        //! Raises an exception if Index is out of bounds.
        //! -   less than 0 (InsertAfter), or less than 1 (InsertBefore), or
        //! -   greater than the number of characters in this ASCII string.
        //! Example:
        //! before
        //! me = "cde" , Index = 1 , other = "ab"
        //! after
        //! me = "abcde" , other = "ab"
        void InsertBefore(Standard_Integer Index, XTCollection_AsciiString^ other);

        //! Returns True if the string <me> contains zero character.
        Standard_Boolean IsEmpty();

        //! Returns true if the characters in this ASCII string
        //! are identical to the characters in ASCII string other.
        //! Note that this method is an alias of operator ==.
        Standard_Boolean IsEqual(Standard_CString other);
        Standard_Boolean operator == (Standard_CString other)
        {
            return IsEqual(other);
        }

        //! Returns true if the characters in this ASCII string
        //! are identical to the characters in ASCII string other.
        //! Note that this method is an alias of operator ==.
        Standard_Boolean IsEqual(XTCollection_AsciiString^ other);
        Standard_Boolean operator == (XTCollection_AsciiString^ other)
        {
            return IsEqual(other);
        }

        //! Returns true if there are differences between the
        //! characters in this ASCII string and ASCII string other.
        //! Note that this method is an alias of operator !=
        Standard_Boolean IsDifferent(Standard_CString other);
        Standard_Boolean operator != (Standard_CString other)
        {
            return IsDifferent(other);
        }

        //! Returns true if there are differences between the
        //! characters in this ASCII string and ASCII string other.
        //! Note that this method is an alias of operator !=
        Standard_Boolean IsDifferent(XTCollection_AsciiString^ other);
        Standard_Boolean operator != (XTCollection_AsciiString^ other)
        {
            return IsDifferent(other);
        }

        //! Returns TRUE if <me> is 'ASCII' less than <other>.
        Standard_Boolean IsLess(Standard_CString other);
        Standard_Boolean operator < (Standard_CString other)
        {
            return IsLess(other);
        }

        //! Returns TRUE if <me> is 'ASCII' less than <other>.
        Standard_Boolean IsLess(XTCollection_AsciiString^ other);
        Standard_Boolean operator < (XTCollection_AsciiString^ other)
        {
            return IsLess(other);
        }

        //! Returns TRUE if <me> is 'ASCII' greater than <other>.
        Standard_Boolean IsGreater(Standard_CString other);
        Standard_Boolean operator > (Standard_CString other)
        {
            return IsGreater(other);
        }

        //! Returns TRUE if <me> is 'ASCII' greater than <other>.
        Standard_Boolean IsGreater(XTCollection_AsciiString^ other);
        Standard_Boolean operator > (XTCollection_AsciiString^ other)
        {
            return IsGreater(other);
        }

        //! Determines whether the beginning of this string instance matches the specified string.
        Standard_Boolean StartsWith(XTCollection_AsciiString^ theStartString);

        //! Determines whether the end of this string instance matches the specified string.
        Standard_Boolean EndsWith(XTCollection_AsciiString^ theEndString);

        //! Converts a AsciiString containing a numeric expression to
        //! an Integer.
        //! Example: "215" returns 215.
        Standard_Integer IntegerValue();

        //! Returns True if the AsciiString contains an integer value.
        //! Note: an integer value is considered to be a real value as well.
        Standard_Boolean IsIntegerValue();

        //! Returns True if the AsciiString contains a real value.
        //! Note: an integer value is considered to be a real value as well.
        Standard_Boolean IsRealValue();

        //! Returns True if the AsciiString contains only ASCII characters
        //! between ' ' and '~'.
        //! This means no control character and no extended ASCII code.
        Standard_Boolean IsAscii();

        //! Removes all space characters in the begining of the string.
        void LeftAdjust();

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
        void LeftJustify(Standard_Integer Width, Standard_Character Filler);

        //! Returns number of characters in <me>.
        //! This is the same functionality as 'strlen' in C.
        //! Example
        //! XTCollection_AsciiString myAlphabet("abcdef");
        //! assert ( myAlphabet.Length() == 6 );
        //! -   1 is the position of the first character in this string.
        //! -   The length of this string gives the position of its last character.
        //! -   Positions less than or equal to zero, or
        //! greater than the length of this string are
        //! invalid in functions which identify a character
        //! of this string by its position.
        Standard_Integer Length();

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
        Standard_Integer Location(XTCollection_AsciiString^ other, Standard_Integer FromIndex, Standard_Integer ToIndex);

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
        Standard_Integer Location(Standard_Integer N, Standard_Character C, Standard_Integer FromIndex, Standard_Integer ToIndex);

        //! Converts <me> to its lower-case equivalent.
        //! Example
        //! XTCollection_AsciiString myString("Hello Dolly");
        //! myString.UpperCase();
        //! assert ( myString == "HELLO DOLLY" );
        //! myString.LowerCase();
        //! assert ( myString == "hello dolly" );
        void LowerCase();

        //! Inserts the string other at the beginning of this ASCII string.
        //! Example
        //! XTCollection_AsciiString myAlphabet("cde");
        //! XTCollection_AsciiString myBegin("ab");
        //! myAlphabet.Prepend(myBegin);
        //! assert ( myAlphabet == "abcde" );
        void Prepend(XTCollection_AsciiString^ other);

        //! Displays <me> on a stream.
        void Print(Standard_OStream& astream);
        //! friend Standard_OStream& operator << (Standard_OStream& astream, XTCollection_AsciiString^ astring);

        //! Read <me> from a stream.
        void Read(Standard_IStream& astream);
        //! friend Standard_IStream& operator >> (Standard_IStream& astream, XTCollection_AsciiString^ astring);

        //! Converts an AsciiString containing a numeric expression.
        //! to a Real.
        //! Example: ex: "215" returns 215.0.
        //! ex: "3.14159267" returns 3.14159267.
        Standard_Real RealValue();

        //! Remove all the occurences of the character C in the string.
        //! Example:
        //! before
        //! me = "HellLLo", C = 'L' , CaseSensitive = True
        //! after
        //! me = "Hello"
        void RemoveAll(Standard_Character C, Standard_Boolean CaseSensitive);

        //! Removes every <what> characters from <me>.
        void RemoveAll(Standard_Character what);

        //! Erases <ahowmany> characters from position <where>,
        //! <where> included.
        //! Example:
        //! aString contains "Hello"
        //! aString.Remove(2,2) erases 2 characters from position 2
        //! This gives "Hlo".
        //! Standard_Integer ahowmany = 1
        void Remove(Standard_Integer where, Standard_Integer ahowmany);

        //! Removes all space characters at the end of the string.
        void RightAdjust();

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
        void RightJustify(Standard_Integer Width, Standard_Character Filler);

        //! Searches a CString in <me> from the beginning
        //! and returns position of first item <what> matching.
        //! it returns -1 if not found.
        //! Example:
        //! aString contains "Sample single test"
        //! aString.Search("le") returns 5
        Standard_Integer Search(Standard_CString what);

        //! Searches an AsciiString in <me> from the beginning
        //! and returns position of first item <what> matching.
        //! It returns -1 if not found.
        Standard_Integer Search(XTCollection_AsciiString^ what);

        //! Searches a CString in a AsciiString from the end
        //! and returns position of first item <what> matching.
        //! It returns -1 if not found.
        //! Example:
        //! aString contains "Sample single test"
        //! aString.SearchFromEnd("le") returns 12
        Standard_Integer SearchFromEnd(Standard_CString what);

        //! Searches a AsciiString in another AsciiString from the end
        //! and returns position of first item <what> matching.
        //! It returns -1 if not found.
        Standard_Integer SearchFromEnd(XTCollection_AsciiString^ what);

        //! Replaces one character in the AsciiString at position <where>.
        //! If <where> is less than zero or greater than the length of <me>
        //! an exception is raised.
        //! Example:
        //! aString contains "Garbake"
        //! astring.Replace(6,'g')  gives <me> = "Garbage"
        void SetValue(Standard_Integer where, Standard_Character what);

        //! Replaces a part of <me> by a CString.
        //! If <where> is less than zero or greater than the length of <me>
        //! an exception is raised.
        //! Example:
        //! aString contains "abcde"
        //! aString.SetValue(4,"1234567") gives <me> = "abc1234567"
        void SetValue(Standard_Integer where, Standard_CString what);

        //! Replaces a part of <me> by another AsciiString.
        void SetValue(Standard_Integer where, XTCollection_AsciiString^ what);

        //! Splits a AsciiString into two sub-strings.
        //! Example:
        //! aString contains "abcdefg"
        //! aString.Split(3) gives <me> = "abc" and returns "defg"
        XTCollection_AsciiString^ Split(Standard_Integer where);

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
        XTCollection_AsciiString^ SubString(Standard_Integer FromIndex, Standard_Integer ToIndex);

        //! Returns pointer to AsciiString (char *).
        //! This is useful for some casual manipulations.
        //! Warning: Because this "char *" is 'const', you can't modify its contents.
        Standard_CString ToCString();

        //! Returns pointer to AsciiString (char *).
        String^ ValueToCString();

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
        XTCollection_AsciiString^ Token(Standard_CString separators, Standard_Integer whichone);

        //! Truncates <me> to <ahowmany> characters.
        //! Example:  me = "Hello Dolly" -> Trunc(3) -> me = "Hel"
        void Trunc(Standard_Integer ahowmany);

        //! Converts <me> to its upper-case equivalent.
        void UpperCase();

        //! Length of the string ignoring all spaces (' ') and the
        //! control character at the end.
        Standard_Integer UsefullLength();

        //! Returns character at position <where> in <me>.
        //! If <where> is less than zero or greater than the lenght of <me>,
        //! an exception is raised.
        //! Example:
        //! aString contains "Hello"
        //! aString.Value(2) returns 'e'
        Standard_Character Value(Standard_Integer where);


        //! Computes a hash code for the given ASCII string, in the range [1, theUpperBound].
        //! Returns the same integer value as the hash function for TCollection_ExtendedString
        //! @param theAsciiString the ASCII string which hash code is to be computed
        //! @param theUpperBound the upper bound of the range a computing hash code must be within
        //! @return a computed hash code, in the range [1, theUpperBound]
        static Standard_Integer HashCode(XTCollection_AsciiString^ theAsciiString, Standard_Integer theUpperBound);

        //! Returns True  when the two  strings are the same.
        //! (Just for HashCode for AsciiString)
        static Standard_Boolean IsEqual(XTCollection_AsciiString^ string1, XTCollection_AsciiString^ string2);

        //! Returns True  when the two  strings are the same.
        //! (Just for HashCode for AsciiString)
        static Standard_Boolean IsEqual(XTCollection_AsciiString^ string1, Standard_CString string2);

        //! Returns True if the strings contain same characters.
        static Standard_Boolean IsSameString(XTCollection_AsciiString^ theString1, XTCollection_AsciiString^ theString2, Standard_Boolean theIsCaseSensitive);
        
        /// <summary>
        /// ±¾µØ¾ä±ú
        /// </summary>
        virtual property TCollection_AsciiString* IHandle {
            TCollection_AsciiString* get() {
                return NativeHandle;
            }
            void set(TCollection_AsciiString* handle) {
                NativeHandle = handle;
            }
        }
    private:
        TCollection_AsciiString* NativeHandle;
        //NCollection_Haft<Handle(TCollection_AsciiString)> NativeHandle;

    };
}
#endif // _XTCollection_AsciiString_HeaderFile
