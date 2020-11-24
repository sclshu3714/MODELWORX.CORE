// Created on: 1997-07-31
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

#ifndef _XTDataStd_Name_HeaderFile
#define _XTDataStd_Name_HeaderFile
#pragma once
#include "TDataStd_Name.hxx"
#include "XTDF_Attribute.h"
#include "NCollection_Haft.h"
#include "XTDF_Label.h"
#include "XTCollection_ExtendedString.h"
#include "XStandard_GUID.h"

#include <Standard.hxx>
#include <Standard_Type.hxx>

#include <TCollection_ExtendedString.hxx>
#include <TDF_Attribute.hxx>
#include <Standard_OStream.hxx>
#include <Standard_GUID.hxx>

class Standard_DomainError;
class TDF_Label;
class TCollection_ExtendedString;
class TDF_Attribute;
class TDF_RelocationTable;

//ref class XTDF_Attribute;
//DEFINE_STANDARD_HANDLE(XTDataStd_Name, XTDF_Attribute)

using namespace TKernel;
namespace TKLCAF {
	ref class XTDF_Label;
	ref class TKernel::XTCollection_ExtendedString;
	ref class TKernel::XStandard_GUID;
	//! Used to define a name attribute containing a string which specifies the name.
	public ref class XTDataStd_Name : public XTDF_Attribute
	{

	public:

		XTDataStd_Name();

		XTDataStd_Name(Handle(TDataStd_Name) pos);

		//XTDataStd_Name(XTDF_Attribute^ pos);

		Handle(TDataStd_Name) GetName();

		//! class methods working on the name itself
		//! ========================================
		//! Returns the GUID for name attributes.
		static XStandard_GUID^ GetID();

		//! Creates (if does not exist) and sets the name in the name attribute.
		//! from any label <L>  search in father  labels (L is not
		//! concerned) the first name attribute.if found set it in
		//! <father>.
		//! class methods working on the name tree
		//! ======================================
		//! Search in the  whole TDF_Data the Name attribute which
		//! fit with <fullPath>. Returns True if found.
		//! Search  under <currentLabel>  a  label which fit with
		//! <name>. Returns True if  found. Shortcut which  avoids
		//! building a ListOfExtendedStrin.
		//! Search in the whole TDF_Data the label which fit with name
		//! Returns True if found.
		//! tools methods to translate path <-> pathlist
		//! ===========================================
		//! move to draw For Draw test we may provide this tool method which convert a path in a
		//! sequence of string to call after the FindLabel methods.
		//! Example: if it's given "Assembly:Part_1:Sketch_5" it will return in <pathlist>
		//! the list of 3 strings: "Assembly","Part_1","Sketch_5".
		//! move to draw from <pathlist> build the string path
		//! Name methods
		//! ============
		static XTDataStd_Name^ Set(XTDF_Label^ label, XTCollection_ExtendedString^ string);

		//! Finds, or creates, a Name attribute with explicit user defined <guid> and sets <string>.
		//! The Name attribute  is  returned. 
		static XTDataStd_Name^ Set(XTDF_Label^ label, XStandard_GUID^ guid, XTCollection_ExtendedString^ string);

		//! Sets <S> as name. Raises if <S> is not a valid name.
		void Set(XTCollection_ExtendedString^ S);

		//! Sets the explicit user defined GUID  to the attribute.
		void SetID(const Standard_GUID& theGuid) Standard_OVERRIDE;

		//! Sets the explicit user defined GUID  to the attribute.
		void SetID(XStandard_GUID^ guid) Standard_OVERRIDE;

		//! Sets default GUID for the attribute.
		void SetID() Standard_OVERRIDE;

		//! Returns the name contained in this name attribute.
		const XTCollection_ExtendedString^ Get();

		XStandard_GUID^ ID() Standard_OVERRIDE;

		void Restore(XTDF_Attribute^ with) Standard_OVERRIDE;

		XTDF_Attribute^ NewEmpty() Standard_OVERRIDE;

		void Paste(XTDF_Attribute^ intoAttribute, Handle(TDF_RelocationTable)& aRelocationTable) Standard_OVERRIDE;

		virtual Standard_OStream& Dump(Standard_OStream& anOS) Standard_OVERRIDE;

		/// <summary>
		/// ±¾µØ¾ä±ú
		/// </summary>
		property Handle(TDataStd_Name) Handle
		{
			Handle(TDataStd_Name) get() {
				return NativeHandle();
			}
		}
		//! DEFINE_STANDARD_RTTIEXT(XTDataStd_Name, XTDF_Attribute)
	private:
		NCollection_Haft<Handle(TDataStd_Name)> NativeHandle;

	};
}
#endif // _XTDataStd_Name_HeaderFile
