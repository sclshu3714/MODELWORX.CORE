// Created on: 1997-06-19
// Created by: Christophe LEYNADIER
// Copyright (c) 1997-1999 Matra Datavision
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

#ifndef _XStandard_GUID_HeaderFile
#define _XStandard_GUID_HeaderFile
#pragma once
#include "Standard_GUID.hxx"
#include "XStandard_UUID.h"

#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <Standard_Integer.hxx>
#include <Standard_ExtCharacter.hxx>
#include <Standard_Byte.hxx>
#include <Standard_CString.hxx>
#include <Standard_ExtString.hxx>
#include <Standard_UUID.hxx>
#include <Standard_PCharacter.hxx>
#include <Standard_PExtCharacter.hxx>
#include <Standard_Boolean.hxx>
#include <Standard_OStream.hxx>

#define Standard_GUID_SIZE 36
#define Standard_GUID_SIZE_ALLOC Standard_GUID_SIZE+1

namespace TKernel {
	public ref class XStandard_GUID
	{
	public:

		!XStandard_GUID() { IHandle = NULL; };
		~XStandard_GUID() { IHandle = NULL; };

		XStandard_GUID();

		//! build a GUID from an ascii string with the
		//! following format:
		//! Length : 36 char
		//! "00000000-0000-0000-0000-000000000000"
		XStandard_GUID(Standard_CString aGuid);

		//! build a GUID from an unicode string with the
		//! following format:
		//!
		//! "00000000-0000-0000-0000-000000000000"
		XStandard_GUID(Standard_ExtString aGuid);

		XStandard_GUID(Standard_Integer a32b, Standard_ExtCharacter a16b1, Standard_ExtCharacter a16b2, Standard_ExtCharacter a16b3, Standard_Byte a8b1, Standard_Byte a8b2, Standard_Byte a8b3, Standard_Byte a8b4, Standard_Byte a8b5, Standard_Byte a8b6);

		XStandard_GUID(XStandard_UUID^ aGuid);

		XStandard_GUID(Standard_GUID aGuid);

		XStandard_GUID^ ToUUID();

		//!
		Standard_GUID GetGUID();

		//! translate the GUID into ascii string
		//! the aStrGuid is allocated by user.
		//! the guid have the following format:
		//!
		//! "00000000-0000-0000-0000-000000000000"
		void ToCString(Standard_PCharacter aStrGuid);

		//! translate the GUID into unicode string
		//! the aStrGuid is allocated by user.
		//! the guid have the following format:
		//!
		//! "00000000-0000-0000-0000-000000000000"
		void ToExtString(Standard_PExtCharacter aStrGuid);

		Standard_Boolean IsSame(XStandard_GUID^ uid);
		Standard_Boolean operator == (XStandard_GUID^ uid)
		{
			return IsSame(uid);
		}

		Standard_Boolean IsNotSame(XStandard_GUID^ uid);
		Standard_Boolean operator != (XStandard_GUID^ uid)
		{
			return IsNotSame(uid);
		}

		void Assign(XStandard_GUID^ uid);
		void operator = (XStandard_GUID^ uid)
		{
			Assign(uid);
		}

		void Assign(XStandard_UUID^ uid);
		void operator = (XStandard_UUID^ uid)
		{
			Assign(uid);
		}

		//! Display the GUID with the following format:
		//!
		//! "00000000-0000-0000-0000-000000000000"
		void ShallowDump(Standard_OStream& aStream);

		//! Check the format of a GUID string.
		//! It checks the size, the position of the '-' and the correct size of fields.
		static Standard_Boolean CheckGUIDFormat(const Standard_CString aGuid);

		//! Hash function for GUID.
		Standard_Integer Hash(const Standard_Integer Upper);

		//! Computes a hash code for the given GUID of the Standard_Integer type, in the range [1, theUpperBound]
		//! @param theGUID the GUID which hash code is to be computed
		//! @param theUpperBound the upper bound of the range a computing hash code must be within
		//! @return a computed hash code, in the range [1, theUpperBound]
		static Standard_Integer HashCode(XStandard_GUID^ theGUID, Standard_Integer theUpperBound);

		//! Returns True  when the two GUID are the same.
		static Standard_Boolean IsEqual(XStandard_GUID^ string1,XStandard_GUID^ string2);

		/// <summary>
		/// ±¾µØ¾ä±ú
		/// </summary>
		virtual property Standard_GUID* IHandle {
			Standard_GUID* get() {
				return NativeHandle;
			}
			void set(Standard_GUID* handle) {
				NativeHandle = handle;
			}
		}
	private:
		Standard_GUID* NativeHandle;
	};
}
#endif // _XStandard_GUID_HeaderFile
