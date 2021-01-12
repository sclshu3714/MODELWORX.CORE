// Created on: 2002-04-15
// Created by: Alexander Kartomin (akm)
// Copyright (c) 2002-2014 OPEN CASCADE SAS
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

#ifndef XNCollection_Array1_HeaderFile
#define XNCollection_Array1_HeaderFile
#pragma once
#include <NCollection_Array1.hxx>
#include <NCollection_Haft.h>

#include <Standard_DimensionMismatch.hxx>
#include <Standard_OutOfMemory.hxx>
#include <Standard_OutOfRange.hxx>

#include <NCollection_DefineAlloc.hxx>
#include <NCollection_StlIterator.hxx>

// *********************************************** Template for Array1 class

namespace TKernel {
    /**
    * Purpose:     The class Array1 represents unidimensional arrays
    *              of fixed size known at run time.
    *              The range of the index is user defined.
    *              An array1 can be constructed with a "C array".
    *              This functionality is useful to call methods expecting
    *              an Array1. It allows to carry the bounds inside the arrays.
    *
    * Examples:    Item tab[100]; //  An example with a C array
    *              Array1OfItem ttab (tab[0],1,100);
    *
    *              Array1OfItem tttab (ttab(10),10,20); // a slice of ttab
    *
    *              If you want to reindex an array from 1 to Length do :
    *
    *              Array1 tab1(tab(tab.Lower()),1,tab.Length());
    *
    * Warning:     Programs client of such a class must be independant
    *              of the range of the first element. Then, a C++ for
    *              loop must be written like this
    *
    *              for (i = A.Lower(); i <= A.Upper(); i++)
    *
    * Changes:     In  comparison  to  TCollection  the  flag  isAllocated  was
    *              renamed into myDeletable (alike in  the Array2).  For naming
    *              compatibility the method IsAllocated remained in class along
    *              with IsDeletable.
    */
    template <class TheItemType>
    public ref class XNCollection_Array1
    {
    public:
        //! STL-compliant typedef for value type
        //typedef TheItemType^ value_type;

    public:
        //! Implementation of the Iterator interface.
        ref class XIterator
        {
        public:

            //! Empty constructor - for later Init
            XIterator(void);

            //! Constructor with initialization
            //! Standard_Boolean theToEnd = Standard_False
            XIterator(XNCollection_Array1^ theArray, Standard_Boolean theToEnd);

            //! Initialisation
            void Init(XNCollection_Array1^ theArray);

            //! Assignment
            XIterator^ operator= (XIterator^ theOther);

            //! Check end
            Standard_Boolean More(void);

            //! Increment operator
            void Next(void);

            //! Decrement operator
            void Previous();

            //! Offset operator.
            void Offset(ptrdiff_t theOffset);

            //! Difference operator.
            ptrdiff_t Differ(XIterator^ theOther);

            //! Constant value access
            TheItemType^ Value(void);

            //! Variable value access
            TheItemType^ ChangeValue(void);

            //! Performs comparison of two iterators
            Standard_Boolean IsEqual(XIterator^ theOther);

        private:
            NCollection_Array1::Iterator* NativeHandle;

        }; // End of the nested class Iterator

    public:
        // ---------- PUBLIC METHODS ------------

        //! Empty constructor; should be used with caution.
        //! @sa methods Resize() and Move().
        XNCollection_Array1();

        //! Constructor
        XNCollection_Array1(Standard_Integer theLower, Standard_Integer theUpper);

        //! Copy constructor 
        XNCollection_Array1(XNCollection_Array1^ theOther);

        //! C array-based constructor.
        //!
        //! Makes this array to use the buffer pointed by theBegin
        //! instead of allocating it dynamically.
        //! Argument theBegin should be a reference to the first element
        //! of the pre-allocated buffer (usually local C array buffer),
        //! with size at least theUpper - theLower + 1 items.
        //!
        //! Warning: returning array object created using this constructor
        //! from function by value will result in undefined behavior
        //! if compiler performs return value optimization (this is likely
        //! to be true for all modern compilers in release mode).
        //! The same happens if array is copied using Move() function
        //! or move constructor and target object's lifespan is longer
        //! than that of the buffer.
        XNCollection_Array1(TheItemType^ theBegin, Standard_Integer theLower, Standard_Integer theUpper);

        //! Initialise the items with theValue
        void Init(TheItemType^ theValue);

        //! Size query
        Standard_Integer Size(void);
        //! Length query (the same)
        Standard_Integer Length(void);

        //! Return TRUE if array has zero length.
        Standard_Boolean IsEmpty();

        //! Lower bound
        Standard_Integer Lower(void);
        //! Upper bound
        Standard_Integer Upper(void);

        //! myDeletable flag
        Standard_Boolean IsDeletable(void);

        //! IsAllocated flag - for naming compatibility
        Standard_Boolean IsAllocated(void);

        //! Copies data of theOther array to this.
        //! This array should be pre-allocated and have the same length as theOther;
        //! otherwise exception Standard_DimensionMismatch is thrown.
        XNCollection_Array1^ Assign(XNCollection_Array1^ theOther);

        //! Move assignment.
        //! This array will borrow all the data from theOther.
        //! The moved object will keep pointer to the memory buffer and
        //! range, but it will not free the buffer on destruction.
        XNCollection_Array1^ Move(XNCollection_Array1^ theOther);

        //! Assignment operator; @sa Assign()
        XNCollection_Array1^ operator= (XNCollection_Array1^ theOther);

        //! @return first element
        TheItemType^ First();

        //! @return first element
        TheItemType^ ChangeFirst();

        //! @return last element
        TheItemType^ Last();

        //! @return last element
        TheItemType^ ChangeLast();

        //! Constant value access
        TheItemType^ Value(Standard_Integer theIndex);

        //! operator() - alias to Value
        TheItemType^ operator() (Standard_Integer theIndex);

        //! operator[] - alias to Value
        TheItemType^ operator[] (Standard_Integer theIndex);

        //! Variable value access
        TheItemType^ ChangeValue(Standard_Integer theIndex);

        //! operator() - alias to ChangeValue
        TheItemType^ operator() (Standard_Integer theIndex);

        //! operator[] - alias to ChangeValue
        TheItemType^ operator[] (Standard_Integer theIndex);

        //! Set value 
        void SetValue(Standard_Integer theIndex, TheItemType^ theItem);

        //! Resizes the array to specified bounds.
        //! No re-allocation will be done if length of array does not change,
        //! but existing values will not be discarded if theToCopyData set to FALSE.
        //! @param theLower new lower bound of array
        //! @param theUpper new upper bound of array
        //! @param theToCopyData flag to copy existing data into new array
        void Resize(Standard_Integer theLower, Standard_Integer theUpper, Standard_Boolean theToCopyData);

        //! Destructor - releases the memory
        ~XNCollection_Array1(void);

    private:
        NCollection_Array1* NativeHandle;
    };
}
#endif //XNCollection_Array1
