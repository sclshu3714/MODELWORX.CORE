// Created on: 1997-02-06
// Created by: Denis PASCAL
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

#ifndef _XTDataStd_Integer_HeaderFile
#define _XTDataStd_Integer_HeaderFile
#pragma once
#include <TDataStd_Integer.hxx>
#include <NCollection_Haft.h>
#include "XTDF_Attribute.h"
#include "XStandard_GUID.h"
#include "XTDF_Label.h"
#include <xgp_Vec2d.h>

#include <Standard.hxx>
#include <Standard_Type.hxx>

#include <Standard_Integer.hxx>
#include <Standard_Boolean.hxx>
#include <Standard_OStream.hxx>


class TDF_Attribute;
class TDF_RelocationTable;


//class TDataStd_Integer;
//DEFINE_STANDARD_HANDLE(TDataStd_Integer, TDF_Attribute)
using namespace TKernel;
using namespace TKMath;
namespace TKLCAF {
	ref class TKernel::XStandard_GUID;
	ref class XTDF_Label;
	ref class TKMath::xgp_Vec2d;
	/// <summary>
	/// The basis to define an integer attribute.
	/// </summary>
	public ref class XTDataStd_Integer : public XTDF_Attribute
	{

	public:

		/// <summary>
		///  class methods 
		///  Returns the GUID for integers.
		/// </summary>
		/// <returns></returns>
		static XStandard_GUID^ GetID();

		/// <summary>
		/// Finds, or creates, an Integer attribute and sets the Integer  attribute is returned.
		/// </summary>
		/// <param name="label"></param>
		/// <param name="value"></param>
		/// <returns></returns>
		static XTDataStd_Integer^ Set(XTDF_Label^ label, Standard_Integer value);

		
		/// <summary>
		/// Finds, or creates, an Integer attribute with explicit user defined guid and sets value.
		/// The Integer attribute  is  returned.
		/// </summary>
		/// <param name="label"></param>
		/// <param name="guid"></param>
		/// <param name="value"></param>
		/// <returns></returns>
		static XTDataStd_Integer^ Set(XTDF_Label^ label, XStandard_GUID^ guid, const Standard_Integer value);

		/// <summary>
		/// Integer methods
		/// </summary>
		/// <param name="V"></param>
		void Set(const Standard_Integer V);

		/// <summary>
		/// Sets the explicit GUID (user defined) for the attribute.
		/// </summary>
		void SetID(XStandard_GUID^ guid) Standard_OVERRIDE;

		/// <summary>
		/// Sets default GUID for the attribute.
		/// </summary>
		void SetID() Standard_OVERRIDE;

		/// <summary>
		/// Returns the integer value contained in the attribute.
		/// </summary>
		/// <returns></returns>
		Standard_Integer Get();

		//! Returns True if there is a reference on the same label
		Standard_Boolean IsCaptured();

		XStandard_GUID^ ID() Standard_OVERRIDE;

		void Restore(XTDF_Attribute^ With) Standard_OVERRIDE;

		XTDF_Attribute^ NewEmpty() Standard_OVERRIDE;

		void Paste(XTDF_Attribute^ Into, Handle(TDF_RelocationTable)& RT) Standard_OVERRIDE;

		virtual Standard_OStream& Dump(Standard_OStream& anOS) Standard_OVERRIDE;

		XTDataStd_Integer();

		XTDataStd_Integer(Handle(TDataStd_Integer) pos);

		virtual Handle(TDataStd_Integer) GetInteger();

		//£¡
		virtual Handle(TDF_Attribute) GetAttribute() Standard_OVERRIDE;

		/// <summary>
		/// ±¾µØ¾ä±ú
		/// </summary>
		virtual property Handle(Standard_Transient) IHandle  {
			Handle(Standard_Transient) get() Standard_OVERRIDE {
				return NativeHandle();
			}
			void set(Handle(Standard_Transient) handle) Standard_OVERRIDE {
				NativeHandle() = Handle(TDataStd_Integer)::DownCast(handle);
			}
		}
	private:
		NCollection_Haft<Handle(TDataStd_Integer)> NativeHandle;
	};
}
#endif // _XTDataStd_Integer_HeaderFile
