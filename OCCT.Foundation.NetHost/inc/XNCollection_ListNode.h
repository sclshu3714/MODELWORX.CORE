// Created on: 2002-04-17
// Created by: Alexander KARTOMIN (akm)
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

#ifndef XNCollection_ListNode_HeaderFile
#define XNCollection_ListNode_HeaderFile
#pragma once
#include <NCollection_ListNode.hxx>
#include <NCollection_Haft.h>

//#include <NCollection_BaseAllocator.hxx>
//#include <NCollection_DefineAlloc.hxx>

namespace TKernel {
	/**
	 * Purpose:     This class is used to  represent a node  in the BaseList and
	 *              BaseMap.
	 */
	public ref class XNCollection_ListNode
	{
	public:
		// define new operator for use with NCollection allocators
		// DEFINE_NCOLLECTION_ALLOC
	public:
		//! The only constructor
		XNCollection_ListNode(Handle(NCollection_ListNode) theNext)
			: NativeHandle(theNext) {}

		void SetListNode(Handle(NCollection_ListNode) pos) {
			NativeHandle() = pos;
		}

		Handle(NCollection_ListNode) GetListNode()
		{
			return NativeHandle();
		}

		//! Next pointer access
		XNCollection_ListNode^ Next(void)
		{
			return gcnew XNCollection_ListNode(NativeHandle()->Next());
		}

		//! Next pointer const access
		XNCollection_ListNode^ Next(void)
		{
			return gcnew XNCollection_ListNode(NativeHandle()->Next());
		}

	private:
		//! operator= - forbidden
		Handle(NCollection_ListNode)* operator= (Handle(NCollection_ListNode)*);

		//! copy constructor - forbidden
		XNCollection_ListNode(XNCollection_ListNode^ ListNode);

	private:
		NCollection_Haft<Handle(NCollection_ListNode)> NativeHandle; //!< Pointer to the next node
	};
}
#endif
