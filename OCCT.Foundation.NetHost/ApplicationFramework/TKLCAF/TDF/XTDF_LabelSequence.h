// Created by: DAUTRY Philippe
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

#ifndef XTDF_LabelSequence_HeaderFile
#define XTDF_LabelSequence_HeaderFile

#pragma once
#include <TDF_LabelSequence.hxx>
#include <XTDF_Label.h>
#include <NCollection_Sequence.hxx>
#include "XTDF_XIterator.h"
namespace TKLCAF {
	typedef NCollection_Sequence<TDF_Label> TDF_LabelSequence;
	public ref class XTDF_LabelSequence
	{
	public:
		XTDF_LabelSequence() {};
		XTDF_LabelSequence(TDF_LabelSequence Labels) {
			NativeHandle = new TDF_LabelSequence(Labels);
		};
		~XTDF_LabelSequence() {
			NativeHandle->Clear();
			NativeHandle = NULL;
		};
		!XTDF_LabelSequence() { 
			NativeHandle->Clear(); 
			NativeHandle = NULL;
		};

		void Initialize(TDF_LabelSequence Labels) {
			NativeHandle = new TDF_LabelSequence(Labels);
		};								  

		TDF_LabelSequence GetLabelSequence() {
			return *NativeHandle;
		};

		XTDF_XIterator^ Iterator() {
			NativeIterator = gcnew XTDF_XIterator(NativeHandle, Standard_True);
			return NativeIterator;
		};

		//! Returns true if a current label is found in the
		//! iteration process.
		Standard_Boolean More() {
			return NativeIterator->More();
		};

		//! Move the  current  iteration  to the next Item.
		void Next() {
			NativeIterator->Next();
		};

		//! Returns the current label; or, if there is
		//! none, a null label.
		XTDF_Label^ Value() {
			return NativeIterator->Value();
		};

	private:
		TDF_LabelSequence* NativeHandle;
		XTDF_XIterator^ NativeIterator;
	};
}
#endif // XTDF_LabelSequence_HeaderFile
