// Created on: 2002-04-17
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

#ifndef XNCollection_List_HeaderFile
#define XNCollection_List_HeaderFile
#pragma once
#include "NCollection_List.hxx"
#include "XNCollection_ListNode.h"
#include "NCollection_Haft.h"

#include <NCollection_TListIterator.hxx>
#include <NCollection_StlIterator.hxx>

#include <Standard_NoSuchObject.hxx>
namespace TKernel {
    /**
     * Purpose:      Simple list to link  items together keeping the first
     *               and the last one.
     *               Inherits BaseList, adding the data item to each node.
     */
    template<class  TheItemType>
    public ref class XNCollection_List : public NCollection_BaseList
    {
    public:
        //! STL-compliant typedef for value type
        typedef TheItemType value_type;

    public:
        typedef NCollection_TListNode<TheItemType>     ListNode;
        typedef NCollection_TListIterator<TheItemType> Iterator;

        //! Shorthand for a regular iterator type.
        typedef NCollection_StlIterator<std::forward_iterator_tag, Iterator, TheItemType, false> iterator;

        //! Shorthand for a constant iterator type.
        typedef NCollection_StlIterator<std::forward_iterator_tag, Iterator, TheItemType, true> const_iterator;

        //! Returns an iterator pointing to the first element in the list.
        iterator begin() const { return Iterator(*this->GetList()); }

        //! Returns an iterator referring to the past-the-end element in the list.
        iterator end() const { return Iterator(); }

        //! Returns a const iterator pointing to the first element in the list.
        const_iterator cbegin() const { return Iterator(*this->GetList()); }

        //! Returns a const iterator referring to the past-the-end element in the list.
        const_iterator cend() const { return Iterator(); }

    public:
        // ---------- PUBLIC METHODS ------------

        //! Empty constructor.
        XNCollection_List() : NCollection_BaseList(Handle(NCollection_BaseAllocator)()) {}

        NCollection_List& GetList() {
            return NativeHandle;
        };

        //! Constructor
        explicit XNCollection_List(const Handle(NCollection_BaseAllocator)& theAllocator) : NCollection_BaseList(theAllocator) {}

        //! Copy constructor
        XNCollection_List(XNCollection_List^ theOther) :
            NCollection_BaseList(theOther.myAllocator)
        {
            Assign(theOther);
        }

        //! Size - Number of items
        Standard_Integer Size(void) const
        {
            return Extent();
        }

        //! Replace this list by the items of another list (theOther parameter).
        //! This method does not change the internal allocator.
        XNCollection_List^ Assign(XNCollection_List^ theOther)
        {
            if (this != &theOther) {
                Clear();
                appendList(theOther.PFirst());
            }
            return *this;
        }

        //! Replacement operator
        XNCollection_List^ operator= (XNCollection_List^ theOther)
        {
            return Assign(theOther);
        }

        //! Clear this list
        //! theAllocator = 0L
        void Clear(const Handle(NCollection_BaseAllocator)& theAllocator)
        {
            PClear(ListNode::delNode);
            if (!theAllocator.IsNull())
                this->myAllocator = theAllocator;
        }

        //! First item
        TheItemType^ First(void)
        {
            Standard_NoSuchObject_Raise_if(IsEmpty(), "XNCollection_List::First");
            return ((const ListNode*)PFirst())->Value();
        }

        //! First item (non-const)
        TheItemType^ First(void)
        {
            Standard_NoSuchObject_Raise_if(IsEmpty(), "XNCollection_List::First");
            return ((ListNode*)PFirst())->ChangeValue();
        }

        //! Last item
        const TheItemType^ Last(void)
        {
            Standard_NoSuchObject_Raise_if(IsEmpty(), "XNCollection_List::Last");
            return ((const ListNode*)PLast())->Value();
        }

        //! Last item (non-const)
        TheItemType^ Last(void)
        {
            Standard_NoSuchObject_Raise_if(IsEmpty(), "XNCollection_List::Last");
            return ((ListNode*)PLast())->ChangeValue();
        }

        //! Append one item at the end
        TheItemType^ Append(TheItemType^ theItem)
        {
            ListNode* pNew = new (this->myAllocator) ListNode(theItem);
            PAppend(pNew);
            return ((ListNode*)PLast())->ChangeValue();
        }

        //! Append one item at the end and output iterator
        //!   pointing at the appended item
        void Append(TheItemType^ theItem, Iterator theIter)
        {
            ListNode* pNew = new (this->myAllocator) ListNode(theItem);
            PAppend(pNew, theIter);
        }

        //! Append another list at the end.
        //! After this operation, theOther list will be cleared.
        void Append(XNCollection_List^ theOther)
        {
            if (this == &theOther || theOther.Extent() < 1)
                return;
            if (this->myAllocator == theOther.myAllocator)
            {
                // Then we take the list and glue it to our end - 
                // deallocation will bring no problem
                PAppend(theOther);
            }
            else
            {
                // No - this list has different memory scope
                appendList(theOther.myFirst);
                theOther.Clear();
            }
        }

        //! Prepend one item at the beginning
        TheItemType^ Prepend(TheItemType^ theItem)
        {
            ListNode* pNew = new (this->myAllocator) ListNode(theItem);
            PPrepend(pNew);
            return ((ListNode*)PFirst())->ChangeValue();
        }

        //! Prepend another list at the beginning
        void Prepend(XNCollection_List^ theOther)
        {
            if (this == &theOther || theOther.Extent() < 1)
                return;
            if (this->myAllocator == theOther.myAllocator)
            {
                // Then we take the list and glue it to our head - 
                // deallocation will bring no problem
                PPrepend(theOther);
            }
            else
            {
                // No - this list has different memory scope
                Iterator it(*this);
                prependList(theOther.PFirst(), it);
                theOther.Clear();
            }
        }

        //! RemoveFirst item
        void RemoveFirst(void)
        {
            PRemoveFirst(ListNode::delNode);
        }

        //! Remove item pointed by iterator theIter; 
        //! theIter is then set to the next item
        void Remove(Iterator theIter)
        {
            PRemove(theIter, ListNode::delNode);
        }

        //! Remove the first occurrence of the object.
        template<typename TheValueType> // instantiate this method on first call only for types defining equality operator
        Standard_Boolean Remove(TheValueType^ theObject)
        {
            for (Iterator anIter(*this); anIter.More(); anIter.Next())
            {
                if (anIter.Value() == theObject)
                {
                    Remove(anIter);
                    return Standard_True;
                }
            }
            return Standard_False;
        }

        //! InsertBefore
        TheItemType^ InsertBefore(TheItemType^ theItem, Iterator theIter)
        {
            ListNode* pNew = new (this->myAllocator) ListNode(theItem);
            PInsertBefore(pNew, theIter);
            return pNew->ChangeValue();
        }

        //! InsertBefore
        void InsertBefore(XNCollection_List^ theOther, Iterator theIter)
        {
            if (this == &theOther)
                return;

            if (this->myAllocator == theOther.myAllocator)
            {
                // Then we take the list and glue it to our head - 
                // deallocation will bring no problem
                PInsertBefore(theOther, theIter);
            }
            else
            {
                // No - this list has different memory scope
                prependList(theOther.myFirst, theIter);
                theOther.Clear();
            }
        }

        //! InsertAfter
        TheItemType^ InsertAfter(const TheItemType^ theItem, Iterator theIter)
        {
            ListNode* pNew = new (this->myAllocator) ListNode(theItem);
            PInsertAfter(pNew, theIter);
            return pNew->ChangeValue();
        }

        //! InsertAfter
        void InsertAfter(XNCollection_List^ theOther, Iterator theIter)
        {
            if (!theIter.More())
            {
                Append(theOther);
                return;
            }
            if (this->myAllocator == theOther.myAllocator)
            {
                // Then we take the list and glue it to our head - 
                // deallocation will bring no problem
                PInsertAfter(theOther, theIter);
            }
            else
            {
                // No - this list has different memory scope
                Iterator anIter;
                anIter.myPrevious = theIter.myCurrent;
                anIter.myCurrent = theIter.myCurrent->Next();
                prependList(theOther.PFirst(), anIter);
                theOther.Clear();
            }
        }

        //! Reverse the list
        void Reverse()
        {
            PReverse();
        }

        //! Return true if object is stored in the list.
        template<typename TheValueType> // instantiate this method on first call only for types defining equality operator
        Standard_Boolean Contains(TheValueType^ theObject) const
        {
            for (Iterator anIter(*this); anIter.More(); anIter.Next())
            {
                if (anIter.Value() == theObject)
                {
                    return Standard_True;
                }
            }
            return Standard_False;
        }

        //! Destructor - clears the List
        virtual ~XNCollection_List(void)
        {
            Clear();
        }

    private:
        NCollection_List* NativeHandle;
    };
}
#endif
