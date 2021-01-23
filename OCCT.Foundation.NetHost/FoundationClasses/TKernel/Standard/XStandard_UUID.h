// Copyright (c) 1998-1999 Matra Datavision
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

#ifndef _XStandard_UUID_HeaderFile
#define _XStandard_UUID_HeaderFile
#pragma once
#include <Standard_UUID.hxx>
#include <Standard_Type.hxx>
namespace TKernel {
	typedef GUID Standard_UUID;
	public ref class XStandard_UUID {
	public:

		!XStandard_UUID() { IHandle = NULL; };
		~XStandard_UUID() { IHandle = NULL; };
		XStandard_UUID() {
			NativeHandle = new Standard_UUID();
		};
		XStandard_UUID(Standard_UUID* UUID) {
			NativeHandle = UUID;
		};

		XStandard_UUID(unsigned long Data1, unsigned short Data2, unsigned short Data3, array<unsigned char, 1>^ Data4) {
			unsigned char* CData4 = new unsigned char(Data4->Length);
			for (int i = 0; i < Data4->Length; i++)
				CData4[i] = Data4[i];
			Standard_UUID UUID = { Data1, Data2, Data3, *CData4 };
			NativeHandle = new Standard_UUID(UUID);
		};

		Standard_UUID GetUUID() {
			return *NativeHandle;
		};
		/// <summary>
		/// ±¾µØ¾ä±ú
		/// </summary>
		virtual property Standard_UUID* IHandle {
			Standard_UUID* get() {
				return NativeHandle;
			}
			void set(Standard_UUID* handle) {
				NativeHandle = handle;
			}
		}
	private:
		Standard_UUID* NativeHandle;
	};
}
#endif // _XStandard_UUID_HeaderFile


