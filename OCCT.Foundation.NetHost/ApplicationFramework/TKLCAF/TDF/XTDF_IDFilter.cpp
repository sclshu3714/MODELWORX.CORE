#include "XTDF_IDFilter.h"

namespace TKLCAF {
    //! Creates an ID/attribute filter based on an ID
    //! list. The default mode is "ignore all but...".
    //!
    //! This filter has 2 working mode: keep and ignore.
    //!
    //! Ignore/Exclusive mode: all IDs are ignored except
    //! these set to be kept, using Keep(). Of course, it
    //! is possible set an kept ID to be ignored using
    //! Ignore().
    //!
    //! Keep/Inclusive mode: all IDs are kept except these
    //! set to be ignored, using Ignore(). Of course, it
    //! is possible set an ignored ID to be kept using
    //! Keep().
    //! ignoreMode = Standard_True
    XTDF_IDFilter::XTDF_IDFilter(const Standard_Boolean ignoreMode) {
        NativeHandle = new TDF_IDFilter(ignoreMode);
    };

    //! Creates an ID/attribute filter based on an ID
    XTDF_IDFilter::XTDF_IDFilter(TDF_IDFilter& pos) {
        NativeHandle = &pos;
    };

    TDF_IDFilter XTDF_IDFilter::GetIDFilter() {
        return &NativeHandle;
    };

    //! The list of ID is cleared and the filter mode is
    //! set to ignore mode if <keep> is true; false
    //! otherwise.
    void XTDF_IDFilter::IgnoreAll(const Standard_Boolean ignore) {
        NativeHandle->IgnoreAll(ignore);
    };

    //! Returns true is the mode is set to "ignore all
    //! but...".
    Standard_Boolean XTDF_IDFilter::IgnoreAll() {
        return NativeHandle->IgnoreAll();
    };

    //! An attribute with <anID> as ID is to be kept and
    //! the filter will answer true to the question
    //! IsKept(<anID>).
    void XTDF_IDFilter::Keep(XStandard_GUID^ anID) {
        NativeHandle->Keep(anID->GetGUID());
    };

    //! Attributes with ID owned by <anIDList> are to be kept and
    //! the filter will answer true to the question
    //! IsKept(<anID>) with ID from <anIDList>.
    void XTDF_IDFilter::Keep(const TDF_IDList& anIDList) {
        NativeHandle->Keep(anIDList);
    };

    //! Attributes with ID owned by <anIDList> are to be kept and
    //! the filter will answer true to the question
    //! IsKept(<anID>) with ID from <anIDList>.
    void XTDF_IDFilter::Keep(XTDF_IDList& anIDList) {
        //NativeHandle->Keep(anIDList->);
    };

    //! An attribute with <anID> as ID is to be ignored and
    //! the filter will answer false to the question
    //! IsKept(<anID>).
    void XTDF_IDFilter::Ignore(XStandard_GUID^ anID) {
        NativeHandle->Keep(anID->GetGUID());
    };

    //! Attributes with ID owned by <anIDList> are to be
    //! ignored and the filter will answer false to the
    //! question IsKept(<anID>) with ID from <anIDList>.
    void XTDF_IDFilter::Ignore(const TDF_IDList& anIDList) {
        NativeHandle->Ignore(anIDList);
    };

    

    //! Returns true if the ID is to be kept.
    Standard_Boolean XTDF_IDFilter::IsKept(XStandard_GUID^ anID) {
        return NativeHandle->IsKept(anID->GetGUID());
    };

    //! Returns true if the attribute is to be kept.
    Standard_Boolean XTDF_IDFilter::IsKept(const Handle(TDF_Attribute)& anAtt) {
        return NativeHandle->IsKept(anAtt);
    };

    //! Returns true if the attribute is to be kept.
    Standard_Boolean XTDF_IDFilter::IsKept(XTDF_Attribute^ anAtt) {
        return NativeHandle->IsKept(anAtt->GetAttribute());
    };

    //! Returns true if the ID is to be ignored.
    Standard_Boolean XTDF_IDFilter::IsIgnored(XStandard_GUID^ anID) {
        return NativeHandle->IsIgnored(anID->GetGUID());
    };

    //! Returns true if the attribute is to be ignored.
    Standard_Boolean XTDF_IDFilter::IsIgnored(const Handle(TDF_Attribute)& anAtt) {
        return NativeHandle->IsIgnored(anAtt);
    };

    //! Returns true if the attribute is to be ignored.
    Standard_Boolean XTDF_IDFilter::IsIgnored(XTDF_Attribute^ anAtt) {
        return NativeHandle->IsIgnored(anAtt->GetAttribute());
    };

    //! Copies the list of ID to be kept or ignored in
    //! <anIDList>. <anIDList> is cleared before use.
    void XTDF_IDFilter::IDList(TDF_IDList& anIDList) {
        NativeHandle->IDList(anIDList);
    };

    //! Copies into <me> the contents of
    //! <fromFilter>. <me> is cleared before copy.
    void XTDF_IDFilter::Copy(XTDF_IDFilter^ fromFilter) {
        NativeHandle->Copy(fromFilter->GetIDFilter());
    };

    //! Writes the contents of <me> to <OS>.
    void XTDF_IDFilter::Dump(Standard_OStream& anOS) {
        NativeHandle->Dump(anOS);
    };
}