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

#ifndef _XTDF_Tool_HeaderFile
#define _XTDF_Tool_HeaderFile
#pragma once
#include <TDF_Tool.hxx>
#include <XTDF_Label.h>
#include <XTDF_IDFilter.h>
#include <XTCollection_AsciiString.h>

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <Standard_Integer.hxx>
#include <Standard_Boolean.hxx>
#include <TDF_AttributeMap.hxx>
#include <TColStd_ListOfInteger.hxx>
#include <Standard_CString.hxx>
#include <TDF_LabelList.hxx>
#include <TDF_LabelIntegerMap.hxx>
#include <Standard_OStream.hxx>
class TDF_Label;
class TDF_IDFilter;
class TCollection_AsciiString;
class TDF_Data;

using namespace TKernel;
namespace TKLCAF {
	ref class XTDF_Label;
	ref class XTDF_IDFilter;
	ref class TKernel::XTCollection_AsciiString;
	//! This class provides general services for a data framework.
	public ref class XTDF_Tool
	{
	public:

		//! Returns the number of labels of the tree,
		//! including <aLabel>. aLabel is also included in this figure.
		//! This information is useful in setting the size of an array.
		static Standard_Integer NbLabels(XTDF_Label^ aLabel);

		//! Returns the total number of attributes attached
		//! to the labels dependent on the label aLabel.
		//! The attributes of aLabel are also included in this figure.
		//! This information is useful in setting the size of an array.
		static Standard_Integer NbAttributes(XTDF_Label^ aLabel);

		//! Returns the number of attributes of the tree,
		//! selected by a<Filter>, including those of
		//! <aLabel>.
		static Standard_Integer NbAttributes(XTDF_Label^ aLabel, XTDF_IDFilter^% aFilter);

		//! Returns true if <aLabel> and its descendants
		//! reference only attributes or labels attached to
		//! themselves.
		static Standard_Boolean IsSelfContained(XTDF_Label^ aLabel);

		//! Returns true if <aLabel> and its descendants
		//! reference only attributes or labels attached to
		//! themselves and kept by <aFilter>.
		static Standard_Boolean IsSelfContained(XTDF_Label^ aLabel, XTDF_IDFilter^% aFilter);

		//! Returns in <theAtts> the attributes having out
		//! references.
		//!
		//! Caution: <theAtts> is not cleared before use!
		static void OutReferers(XTDF_Label^ theLabel, TDF_AttributeMap& theAtts);

		//! Returns in <atts> the attributes having out
		//! references and kept by <aFilterForReferers>.
		//! It considers only the references kept by <aFilterForReferences>.
		//! Caution: <atts> is not cleared before use!
		static void OutReferers(XTDF_Label^ aLabel, XTDF_IDFilter^% aFilterForReferers, XTDF_IDFilter^% aFilterForReferences, TDF_AttributeMap& atts);

		//! Returns in <atts> the referenced attributes.
		//! Caution: <atts> is not cleared before use!
		static void OutReferences(XTDF_Label^ aLabel, TDF_AttributeMap& atts);

		//! Returns in <atts> the referenced attributes and kept by <aFilterForReferences>.
		//! It considers only the referers kept by <aFilterForReferers>.
		//! Caution: <atts> is not cleared before use!
		static void OutReferences(XTDF_Label^ aLabel, XTDF_IDFilter^% aFilterForReferers,XTDF_IDFilter^% aFilterForReferences, TDF_AttributeMap& atts);

		//! Returns the label having the same sub-entry as
		//! <aLabel> but located as descendant as <toRoot>
		//! instead of <fromRoot>.
		//!
		//! Exemple :
		//!
		//! aLabel = 0:3:24:7:2:7
		//! fromRoot = 0:3:24
		//! toRoot = 0:5
		//! returned label = 0:5:7:2:7
		//! Standard_Boolean create = Standard_False
		static void RelocateLabel(XTDF_Label^ aSourceLabel, XTDF_Label^ fromRoot, XTDF_Label^ toRoot, XTDF_Label^% aTargetLabel, Standard_Boolean create);

		//! Returns the entry for the label aLabel in the form
		//! of the ASCII character string anEntry containing
		//! the tag list for aLabel.
		static void Entry(XTDF_Label^ aLabel, XTCollection_AsciiString^ anEntry);

		//! Returns the entry of <aLabel> as list of integers
		//! in <aTagList>.
		//! TColStd_ListOfInteger& aTagList
		static void TagList(XTDF_Label^ aLabel, array<Standard_Integer>^% aTagList);

		//! Returns the entry expressed by <anEntry> as list
		//! of integers in <aTagList>.
		//! TColStd_ListOfInteger& aTagList
		static void TagList(XTCollection_AsciiString^ anEntry, array<Standard_Integer>^% aTagList);

		//! Returns the label expressed by <anEntry>; creates
		//! the label if it does not exist and if <create> is
		//! true.
		//! Standard_Boolean create = Standard_False
		static void Label(Handle(TDF_Data) aDF, XTCollection_AsciiString^ anEntry, XTDF_Label^% aLabel, Standard_Boolean create);

		//! Returns the label expressed by <anEntry>; creates
		//! the label if it does not exist and if <create> is
		//! true.
		//! Standard_Boolean create = Standard_False
		static void Label(Handle(TDF_Data) aDF, Standard_CString anEntry, XTDF_Label^% aLabel, Standard_Boolean create);

		//! Returns the label expressed by <anEntry>; creates
		//! the label if it does not exist and if <create> is
		//! true.
		//! Standard_Boolean create = Standard_False
		static void Label(Handle(TDF_Data) aDF, array<Standard_Integer>^% aTagList, XTDF_Label^% aLabel, Standard_Boolean create);

		//! Adds the labels of <aLabelList> to <aLabelMap> if
		//! they are unbound, or increases their reference
		//! counters. At the end of the process, <aLabelList>
		//! contains only the ADDED labels.
		static void CountLabels(TDF_LabelList aLabelList, TDF_LabelIntegerMap& aLabelMap);

		//! Decreases the reference counters of the labels of
		//! <aLabelList> to <aLabelMap>, and removes labels
		//! with null counter. At the end of the process,
		//! <aLabelList> contains only the SUPPRESSED labels.
		static void DeductLabels(TDF_LabelList& aLabelList, TDF_LabelIntegerMap& aLabelMap);

		//! Dumps <aDF> and its labels and their attributes.
		static void DeepDump(Standard_OStream& anOS, Handle(TDF_Data)& aDF);

		//! Dumps <aDF> and its labels and their attributes,
		//! if their IDs are kept by <aFilter>. Dumps also the
		//! attributes content.
		static void ExtendedDeepDump(Standard_OStream& anOS, Handle(TDF_Data)& aDF, TDF_IDFilter& aFilter);

		//! Dumps <aLabel>, its chilren and their attributes.
		static void DeepDump(Standard_OStream& anOS, TDF_Label& aLabel);

		//! Dumps <aLabel>, its chilren and their attributes,
		//! if their IDs are kept by <aFilter>. Dumps also the
		//! attributes content.
		static void ExtendedDeepDump(Standard_OStream& anOS, TDF_Label& aLabel, TDF_IDFilter& aFilter);
	};
}
#endif // _XTDF_Tool_HeaderFile
