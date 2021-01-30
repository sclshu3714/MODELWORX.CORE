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

//      	------------
// Version:	0.0
//Version	Date		Purpose
//		0.0	Mar 13 1997	Creation
#include <XTDF_Tool.h>
namespace TKLCAF {

	//! Returns the number of labels of the tree,
	//! including <aLabel>. aLabel is also included in this figure.
	//! This information is useful in setting the size of an array.
	//! static 
	Standard_Integer XTDF_Tool::NbLabels(XTDF_Label^ aLabel) {
		return TDF_Tool::NbLabels(*aLabel->GetLabel());
	};

	//! Returns the total number of attributes attached
	//! to the labels dependent on the label aLabel.
	//! The attributes of aLabel are also included in this figure.
	//! This information is useful in setting the size of an array.
	//! static 
	Standard_Integer XTDF_Tool::NbAttributes(XTDF_Label^ aLabel) {
		return TDF_Tool::NbAttributes(*aLabel->GetLabel());
	};

	//! Returns the number of attributes of the tree,
	//! selected by a<Filter>, including those of
	//! <aLabel>.
	//! static 
	Standard_Integer XTDF_Tool::NbAttributes(XTDF_Label^ aLabel, XTDF_IDFilter^% aFilter) {
		TDF_IDFilter* temp = aFilter->GetIDFilter();
		Standard_Integer Result = TDF_Tool::NbAttributes(*aLabel->GetLabel(), *temp);
		aFilter = gcnew XTDF_IDFilter(temp);
		return Result;
	};

	//! Returns true if <aLabel> and its descendants
	//! reference only attributes or labels attached to
	//! themselves.
	//! static 
	Standard_Boolean XTDF_Tool::IsSelfContained(XTDF_Label^ aLabel) {
		return TDF_Tool::IsSelfContained(*aLabel->GetLabel());
	};

	//! Returns true if <aLabel> and its descendants
	//! reference only attributes or labels attached to
	//! themselves and kept by <aFilter>.
	//! static 
	Standard_Boolean XTDF_Tool::IsSelfContained(XTDF_Label^ aLabel, XTDF_IDFilter^% aFilter) {
		TDF_IDFilter* temp = aFilter->GetIDFilter();
		Standard_Integer Result = TDF_Tool::IsSelfContained(*aLabel->GetLabel(), *temp);
		aFilter = gcnew XTDF_IDFilter(temp);
		return Result;
	};

	//! Returns in <theAtts> the attributes having out
	//! references.
	//!
	//! Caution: <theAtts> is not cleared before use!
	//! static 
	void XTDF_Tool::OutReferers(XTDF_Label^ theLabel, TDF_AttributeMap& theAtts) {
		TDF_Tool::OutReferers(*theLabel->GetLabel(), theAtts);
	};

	//! Returns in <atts> the attributes having out
	//! references and kept by <aFilterForReferers>.
	//! It considers only the references kept by <aFilterForReferences>.
	//! Caution: <atts> is not cleared before use!
	//! static 
	void XTDF_Tool::OutReferers(XTDF_Label^ aLabel, XTDF_IDFilter^% aFilterForReferers, XTDF_IDFilter^% aFilterForReferences, TDF_AttributeMap& atts) {
		TDF_IDFilter* aFilterForReferersx = aFilterForReferers->GetIDFilter();
	    TDF_IDFilter* aFilterForReferencesx = aFilterForReferences->GetIDFilter();
		TDF_Tool::OutReferers(*aLabel->GetLabel(), aFilterForReferersx, aFilterForReferencesx, atts);
		aFilterForReferers = gcnew XTDF_IDFilter(aFilterForReferersx);
		aFilterForReferences = gcnew XTDF_IDFilter(aFilterForReferencesx);
	};

	//! Returns in <atts> the referenced attributes.
	//! Caution: <atts> is not cleared before use!
	//! static 
	void XTDF_Tool::OutReferences(XTDF_Label^ aLabel, TDF_AttributeMap& atts) {
		TDF_Tool::OutReferences(*aLabel->GetLabel(), atts);
	};

	//! Returns in <atts> the referenced attributes and kept by <aFilterForReferences>.
	//! It considers only the referers kept by <aFilterForReferers>.
	//! Caution: <atts> is not cleared before use!
	//! static 
	void XTDF_Tool::OutReferences(XTDF_Label^ aLabel, XTDF_IDFilter^% aFilterForReferers, XTDF_IDFilter^% aFilterForReferences, TDF_AttributeMap& atts) {
		TDF_IDFilter* aFilterForReferersx = aFilterForReferers->GetIDFilter();
		TDF_IDFilter* aFilterForReferencesx = aFilterForReferences->GetIDFilter();
		TDF_Tool::OutReferences(*aLabel->GetLabel(), aFilterForReferersx, aFilterForReferencesx, atts);
		aFilterForReferers = gcnew XTDF_IDFilter(aFilterForReferersx);
		aFilterForReferences = gcnew XTDF_IDFilter(aFilterForReferencesx);
	};

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
	//! static 
	void XTDF_Tool::RelocateLabel(XTDF_Label^ aSourceLabel, XTDF_Label^ fromRoot, XTDF_Label^ toRoot, XTDF_Label^% aTargetLabel, Standard_Boolean create) {
		TDF_Label* aTargetLabelx = aTargetLabel->GetLabel();
		TDF_Tool::RelocateLabel(*aSourceLabel->GetLabel(), *fromRoot->GetLabel(), *toRoot->GetLabel(), *aTargetLabelx, create);
		aTargetLabel = gcnew XTDF_Label(aTargetLabelx);
	};

	//! Returns the entry for the label aLabel in the form
	//! of the ASCII character string anEntry containing
	//! the tag list for aLabel.
	//! static 
	void XTDF_Tool::Entry(XTDF_Label^ aLabel, XTCollection_AsciiString^% anEntry) {
		TCollection_AsciiString* temp = anEntry->GetAsciiString();
		TDF_Tool::Entry(*aLabel->GetLabel(), *temp);
		anEntry = gcnew XTCollection_AsciiString(temp);
	};

	//! Returns the entry of <aLabel> as list of integers
	//! in <aTagList>.
	//! TColStd_ListOfInteger& aTagList
	//! static 
	void XTDF_Tool::TagList(XTDF_Label^ aLabel, array<Standard_Integer>^% aTagList) {
		TColStd_ListOfInteger aTagListx;
		TDF_Tool::TagList(*aLabel->GetLabel(), aTagListx);
		aTagList = gcnew array<Standard_Integer>(aTagListx.Size());
		TColStd_ListIteratorOfListOfInteger iter;
		Standard_Integer i = 0;
		for (iter.Initialize(aTagListx); iter.More(); iter.Next())
		{
			aTagList->SetValue(i++, iter.Value());
		}
	};

	//! Returns the entry expressed by <anEntry> as list
	//! of integers in <aTagList>.
	//! TColStd_ListOfInteger& aTagList
	//! static 
	void XTDF_Tool::TagList(XTCollection_AsciiString^ anEntry, array<Standard_Integer>^% aTagList) {
		TColStd_ListOfInteger aTagListx;
		TDF_Tool::TagList(*anEntry->GetAsciiString(), aTagListx);
		aTagList = gcnew array<Standard_Integer>(aTagListx.Size());
		TColStd_ListIteratorOfListOfInteger iter;
		Standard_Integer i = 0;
		for (iter.Initialize(aTagListx); iter.More(); iter.Next())
		{
			aTagList->SetValue(i++, iter.Value());
		}
	};

	//! Returns the label expressed by <anEntry>; creates
	//! the label if it does not exist and if <create> is
	//! true.
	//! Standard_Boolean create = Standard_False
	//! static 
	void XTDF_Tool::Label(Handle(TDF_Data) aDF, XTCollection_AsciiString^ anEntry, XTDF_Label^% aLabel, Standard_Boolean create) {
		TDF_Label* aLabelx = aLabel->GetLabel();
		TDF_Tool::Label(aDF, *anEntry->GetAsciiString(), *aLabelx, create);
		aLabel = gcnew XTDF_Label(aLabelx);
	};

	//! Returns the label expressed by <anEntry>; creates
	//! the label if it does not exist and if <create> is
	//! true.
	//! Standard_Boolean create = Standard_False
	//! static 
	void XTDF_Tool::Label(Handle(TDF_Data) aDF, Standard_CString anEntry, XTDF_Label^% aLabel, Standard_Boolean create) {
		TDF_Label* aLabelx = aLabel->GetLabel();
		TDF_Tool::Label(aDF, anEntry, *aLabelx, create);
		aLabel = gcnew XTDF_Label(aLabelx);
	};

	//! Returns the label expressed by <anEntry>; creates
	//! the label if it does not exist and if <create> is
	//! true.
	//! Standard_Boolean create = Standard_False
	//! static 
	void XTDF_Tool::Label(Handle(TDF_Data) aDF, array<Standard_Integer>^% aTagList, XTDF_Label^% aLabel, Standard_Boolean create) {
		TColStd_ListOfInteger aTagListx;
		TDF_Label* aLabelx = aLabel->GetLabel();
		TDF_Tool::Label(aDF, aTagListx, *aLabelx, create);
		aLabel = gcnew XTDF_Label(aLabelx);
		aTagList = gcnew array<Standard_Integer>(aTagListx.Size());
		TColStd_ListIteratorOfListOfInteger iter;
		Standard_Integer i = 0;
		for (iter.Initialize(aTagListx); iter.More(); iter.Next())
		{
			aTagList->SetValue(i++, iter.Value());
		}
	};

	//! Adds the labels of <aLabelList> to <aLabelMap> if
	//! they are unbound, or increases their reference
	//! counters. At the end of the process, <aLabelList>
	//! contains only the ADDED labels.
	//! static 
	void XTDF_Tool::CountLabels(TDF_LabelList aLabelList, TDF_LabelIntegerMap& aLabelMap) {
		TDF_Tool::CountLabels(aLabelList, aLabelMap);
	};

	//! Decreases the reference counters of the labels of
	//! <aLabelList> to <aLabelMap>, and removes labels
	//! with null counter. At the end of the process,
	//! <aLabelList> contains only the SUPPRESSED labels.
	//! static 
	void XTDF_Tool::DeductLabels(TDF_LabelList& aLabelList, TDF_LabelIntegerMap& aLabelMap) {
		TDF_Tool::DeductLabels(aLabelList, aLabelMap);
	};

	//! Dumps <aDF> and its labels and their attributes.
	//! static 
	void XTDF_Tool::DeepDump(Standard_OStream& anOS, Handle(TDF_Data)& aDF) {
		TDF_Tool::DeepDump(anOS, aDF);
	};

	//! Dumps <aDF> and its labels and their attributes,
	//! if their IDs are kept by <aFilter>. Dumps also the
	//! attributes content.
	//! static 
	void XTDF_Tool::ExtendedDeepDump(Standard_OStream& anOS, Handle(TDF_Data)& aDF, TDF_IDFilter& aFilter) {
		TDF_Tool::ExtendedDeepDump(anOS, aDF, aFilter);
	};

	//! Dumps <aLabel>, its chilren and their attributes.
	//! static 
	void XTDF_Tool::DeepDump(Standard_OStream& anOS, TDF_Label& aLabel) {
		TDF_Tool::DeepDump(anOS, aLabel);
	};

	//! Dumps <aLabel>, its chilren and their attributes,
	//! if their IDs are kept by <aFilter>. Dumps also the
	//! attributes content.
	//! static 
	void XTDF_Tool::ExtendedDeepDump(Standard_OStream& anOS, TDF_Label& aLabel, TDF_IDFilter& aFilter) {
		TDF_Tool::ExtendedDeepDump(anOS, aLabel, aFilter);
	};
}
