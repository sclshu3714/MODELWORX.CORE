#include "XTDF_Attribute.h"

namespace TKLCAF {

    XTDF_Attribute::XTDF_Attribute() {
        
    }
    //!
    XTDF_Attribute::XTDF_Attribute(Handle(TDF_Attribute) pos) {
        NativeHandle() = pos;
    };

    void XTDF_Attribute::SetNativeHandle(Handle(TDF_Attribute) pos) {
        NativeHandle() = pos;
    };
    //! Returns the ID of the attribute.
    Standard_GUID XTDF_Attribute::ID() {
       return NativeHandle()->ID();
    };

    //! Returns the ID of the attribute.
    XStandard_GUID^ XTDF_Attribute::GetIDEx() {
        return gcnew XStandard_GUID(NativeHandle()->ID());
    };

    //! Sets specific ID of the attribute (supports several attributes 
    //! of one type at the same label feature).
    void XTDF_Attribute::SetID(const Standard_GUID& theGuid) {
        NativeHandle()->SetID(theGuid);
    };

    //! Sets specific ID of the attribute (supports several attributes 
    //! of one type at the same label feature).
    void XTDF_Attribute::SetID(XStandard_GUID^ theGuid) {
        NativeHandle()->SetID(theGuid->GetGUID());
    };

    //! Sets default ID defined in nested class (to be used for attributes having User ID feature).
    void XTDF_Attribute::SetID() {
        NativeHandle()->SetID();
    };



    //! Returns   the   label to which  the   attribute is
    //! attached. If the  label is not  included in a  DF,
    //! the label is null. See Label.
    //! Warning
    //! If the label is not included in a data
    //! framework, it is null.
    //! This function should not be redefined inline.
    TDF_Label XTDF_Attribute::Label() {
        return NativeHandle()->Label();
    };

    XTDF_Label^ XTDF_Attribute::EditLabel() {
        return gcnew XTDF_Label(NativeHandle()->Label());
    };

    Handle(TDF_Attribute) XTDF_Attribute::GetAttribute() {
        return NativeHandle();
    };

    //! Returns the transaction index in which the
    //! attribute has been created or modified.
    Standard_Integer XTDF_Attribute::Transaction() {
        return NativeHandle()->Transaction();
    };

    //! Returns the upper transaction index until which
    //! the attribute is/was valid. This number may
    //! vary. A removed attribute validity range is
    //! reduced to its transaction index.
    Standard_Integer XTDF_Attribute::UntilTransaction() {
        return NativeHandle()->UntilTransaction();
    };

    //! Returns true if the attribute is valid; i.e. not a
    //! backuped or removed one.
    Standard_Boolean XTDF_Attribute::IsValid() {
        return NativeHandle()->IsValid();
    };

    //! Returns true if the attribute has no backup
    Standard_Boolean XTDF_Attribute::IsNew() {
        return NativeHandle()->IsNew();
    };

    //! Returns true if the attribute forgotten status is
    //! set.
    //!
    //! ShortCut Methods concerning associated attributes
    //! =================================================
    Standard_Boolean XTDF_Attribute::IsForgotten() {
        return NativeHandle()->IsForgotten();
    };

    //! Returns true if it  exists an associated attribute
    //! of <me> with <anID> as ID.
    Standard_Boolean XTDF_Attribute::IsAttribute(const Standard_GUID& anID) {
        return NativeHandle()->IsAttribute(anID);
    };

    //! Returns true if it  exists an associated attribute
    //! of <me> with <anID> as ID.
    Standard_Boolean XTDF_Attribute::IsAttribute(XStandard_GUID^ anID) {
        return NativeHandle()->IsAttribute(anID->GetGUID());
    };

    //! Finds an associated  attribute of  <me>, according
    //! to <anID>.  the returned <anAttribute> is a  valid
    //! one. The  method  returns  True if   found,  False
    //! otherwise.   A removed attribute  cannot be found using
    //! this  method.
    Standard_Boolean XTDF_Attribute::FindAttribute(const Standard_GUID& anID, Handle(TDF_Attribute)& anAttribute) {
        return NativeHandle()->FindAttribute(anID, anAttribute);
    };

    //! Finds an associated  attribute of  <me>, according
    //! to <anID>.  the returned <anAttribute> is a  valid
    //! one. The  method  returns  True if   found,  False
    //! otherwise.   A removed attribute  cannot be found using
    //! this  method.
    Standard_Boolean XTDF_Attribute::FindAttribute(XStandard_GUID^ anID, XTDF_Attribute^ anAttribute) {
        return NativeHandle()->FindAttribute(anID->GetGUID(), anAttribute->GetAttribute());
    };

    //! Adds   an   Attribute <other>  to  the   label  of
    //! <me>.Raises if there is  already  one of the same
    //! GUID fhan <other>.
    void XTDF_Attribute::AddAttribute(const Handle(TDF_Attribute)& other) {
        NativeHandle()->AddAttribute(other);
    };

    //! Adds   an   Attribute <other>  to  the   label  of
    //! <me>.Raises if there is  already  one of the same
    //! GUID fhan <other>.
    void XTDF_Attribute::AddAttribute(XTDF_Attribute^ other) {
        NativeHandle()->AddAttribute(other->GetAttribute());
    };

    //! Forgets  the Attribute of  GUID <aguid> associated
    //! to the label of <me>. Be  carefull that if <me> is
    //! the attribute of <guid>, <me> will have a null label
    //! after this call.  If  the attribute doesn't  exist
    //! returns False. Otherwise returns True.
    Standard_Boolean XTDF_Attribute::ForgetAttribute(const Standard_GUID& aguid) {
        return NativeHandle()->ForgetAttribute(aguid);
    };
    Standard_Boolean XTDF_Attribute::ForgetAttribute(XStandard_GUID^ aguid) {
        return NativeHandle()->ForgetAttribute(aguid->GetGUID());
    };

    //! Forgets all the  attributes attached to  the label
    //! of <me>.    Does   it   on  the  sub-labels   if
    //! <clearChildren> is set  to true.  Of  course, this
    //! method  is  compatible with Transaction  &  Delta
    //! mecanisms. Be carefull  that  if <me> will have a
    //! null label after this call
    //! default Standard_True
    void XTDF_Attribute::ForgetAllAttributes(const Standard_Boolean clearChildren) {
        NativeHandle()->ForgetAllAttributes(clearChildren);
    };

    //! Something to do after adding an Attribute to a label.
    void XTDF_Attribute::AfterAddition() {
        NativeHandle()->AfterAddition();
    };

    //! Something to do before removing an Attribute from
    //! a label.
    void XTDF_Attribute::BeforeRemoval() {
        NativeHandle()->BeforeRemoval();
    };

    //! Something to do before forgetting an Attribute to a
    //! label.
    void XTDF_Attribute::BeforeForget() {
        NativeHandle()->BeforeForget();
    };

    //! Something to do after resuming an Attribute from
    //! a label.
    void XTDF_Attribute::AfterResume() {
        NativeHandle()->AfterResume();
    };

    //! Something to do AFTER creation of an attribute by
    //! persistent-transient translation. The returned
    //! status says if AfterUndo has been performed (true)
    //! or if this callback must be called once again
    //! further (false). If <forceIt> is set to true, the
    //! method MUST perform and return true. Does nothing
    //! by default and returns true.
    //! default Standard_False
    Standard_Boolean XTDF_Attribute::AfterRetrieval(const Standard_Boolean forceIt) {
        return NativeHandle()->AfterRetrieval(forceIt);
    };

    //! Something to do before applying <anAttDelta>. The
    //! returned status says if AfterUndo has been
    //! performed (true) or if this callback must be
    //! called once again further (false). If <forceIt> is
    //! set to true, the method MUST perform and return
    //! true. Does nothing by default and returns true.
    //! default Standard_False
    Standard_Boolean XTDF_Attribute::BeforeUndo(const Handle(TDF_AttributeDelta)& anAttDelta, Standard_Boolean forceIt) {
        return NativeHandle()->BeforeUndo(anAttDelta, forceIt);
    };


    //! Something to do after applying <anAttDelta>. The
    //! returned status says if AfterUndo has been
    //! performed (true) or if this callback must be
    //! called once again further (false). If <forceIt> is
    //! set to true, the method MUST perform and return
    //! true. Does nothing by default and returns true.
    //! default Standard_False
    Standard_Boolean XTDF_Attribute::AfterUndo(const Handle(TDF_AttributeDelta)& anAttDelta, Standard_Boolean forceIt) {
        return NativeHandle()->AfterUndo(anAttDelta, forceIt);
    };

    //! A callback.
    //! By default does nothing.
    //! It is called by TDF_Data::CommitTransaction() method.
    void XTDF_Attribute::BeforeCommitTransaction() {
        NativeHandle()->BeforeCommitTransaction();
    };

    //! Backups the attribute. The backuped attribute is
    //! flagged "Backuped" and not "Valid".
    //!
    //! The method does nothing:
    //!
    //! 1) If the attribute transaction number is equal to
    //! the current transaction number (the attribute has
    //! already been backuped).
    //!
    //! 2) If the attribute is not attached to a label.
    void XTDF_Attribute::Backup() {
        NativeHandle()->Backup();
    };

    //! Returns true if the attribute backup status is
    //! set. This status is set/unset by the
    //! Backup() method.
    Standard_Boolean XTDF_Attribute::IsBackuped() {
        return NativeHandle()->IsBackuped();
    };

    //! Copies  the attribute  contents into  a  new other
    //! attribute. It is used by Backup().
    Handle(TDF_Attribute) XTDF_Attribute::BackupCopy() {
        return NativeHandle()->BackupCopy();
    };

    //! Copies  the attribute  contents into  a  new other
    //! attribute. It is used by Backup().
    XTDF_Attribute^ XTDF_Attribute::BackupCopyx() {
        return gcnew XTDF_Attribute(NativeHandle()->BackupCopy());
    };

    //! Restores the backuped contents from <anAttribute>
    //! into this one. It is used when aborting a
    //! transaction.
    void XTDF_Attribute::Restore(const Handle(TDF_Attribute)& anAttribute) {
        return NativeHandle()->Restore(anAttribute);
    };

    //! Restores the backuped contents from <anAttribute>
    //! into this one. It is used when aborting a
    //! transaction.
    void XTDF_Attribute::Restore(XTDF_Attribute^ anAttribute) {
        NativeHandle()->Restore(anAttribute->GetAttribute());
    };

    //! Makes an AttributeDelta because <me>
    //! appeared. The only known use of a redefinition of
    //! this method is to return a null handle (no delta).
    Handle(TDF_DeltaOnAddition) XTDF_Attribute::DeltaOnAddition() {
        return NativeHandle()->DeltaOnAddition();
    };

    //! Makes an AttributeDelta because <me> has been
    //! forgotten.
    Handle(TDF_DeltaOnForget) XTDF_Attribute::DeltaOnForget() {
        return NativeHandle()->DeltaOnForget();
    };

    //! Makes an AttributeDelta because <me> has been
    //! resumed.
    Handle(TDF_DeltaOnResume) XTDF_Attribute::DeltaOnResume() {
        return NativeHandle()->DeltaOnResume();
    };

    //! Makes a DeltaOnModification between <me> and
    //! <anOldAttribute.
    Handle(TDF_DeltaOnModification) XTDF_Attribute::DeltaOnModification(const Handle(TDF_Attribute)& anOldAttribute) {
        return NativeHandle()->DeltaOnModification(anOldAttribute);
    };

    //! Makes a DeltaOnModification between <me> and
    //! <anOldAttribute.
    Handle(TDF_DeltaOnModification) XTDF_Attribute::DeltaOnModification(XTDF_Attribute^ anOldAttribute) {
        return NativeHandle()->DeltaOnModification(anOldAttribute->GetAttribute());
    };

    //! Applies a DeltaOnModification to <me>.
    void XTDF_Attribute::DeltaOnModification(const Handle(TDF_DeltaOnModification)& aDelta) {
        NativeHandle()->DeltaOnModification(aDelta);
    };

    //! Makes a DeltaOnRemoval on <me> because <me> has
    //! disappeared from the DS.
    Handle(TDF_DeltaOnRemoval) XTDF_Attribute::DeltaOnRemoval() {
        return NativeHandle()->DeltaOnRemoval();
    };

    //! Returns an new empty attribute from the good end
    //! type. It is used by the copy algorithm.
    Handle(TDF_Attribute) XTDF_Attribute::NewEmpty() {
        return NativeHandle()->NewEmpty();
    };

    //! Returns an new empty attribute from the good end
    //! type. It is used by the copy algorithm.
    XTDF_Attribute^ XTDF_Attribute::NewEmptyx() {
        return gcnew XTDF_Attribute(NativeHandle()->NewEmpty());
    };

    //! This method is different from the "Copy" one,
    //! because it is used when copying an attribute from
    //! a source structure into a target structure. This
    //! method may paste the contents of <me> into
    //! <intoAttribute>.
    //!
    //! The given pasted attribute can be full or empty of
    //! its contents. But don't make a NEW! Just set the
    //! contents!
    //!
    //! It is possible to use <aRelocationTable> to
    //! get/set the relocation value of a source
    //! attribute.
    void XTDF_Attribute::Paste(const Handle(TDF_Attribute)& intoAttribute, Handle(TDF_RelocationTable)& aRelocationTable) {
        NativeHandle()->Paste(intoAttribute, aRelocationTable);
    };

    void XTDF_Attribute::Paste(XTDF_Attribute^ intoAttribute, Handle(TDF_RelocationTable)& aRelocationTable) {
        NativeHandle()->Paste(intoAttribute->GetAttribute(), aRelocationTable);
    };

    //! Adds the first level referenced attributes and labels
    //! to <aDataSet>.
    //!
    //! For this, use the AddLabel or AddAttribute of
    //! DataSet.
    //!
    //! If there is none, do not implement the method.
    void XTDF_Attribute::References(const Handle(TDF_DataSet)& aDataSet) {
        NativeHandle()->References(aDataSet);
    };

    //! Dumps the minimum information about <me> on
    //! <aStream>.
    Standard_OStream& XTDF_Attribute::Dump(Standard_OStream& anOS) {
        return NativeHandle()->Dump(anOS);
    };

    //! Dumps the attribute content on <aStream>, using
    //! <aMap> like this: if an attribute is not in the
    //! map, first put add it to the map and then dump it.
    //! Use the map rank instead of dumping each attribute
    //! field.
    void XTDF_Attribute::ExtendedDump(Standard_OStream& anOS, TDF_IDFilter& aFilter, TDF_AttributeIndexedMap& aMap) {
        NativeHandle()->ExtendedDump(anOS, aFilter, aMap);
    };

    //! Forgets the attribute. <aTransaction> is the
    //! current transaction in which the forget is done. A
    //! forgotten attribute is also flagged not "Valid".
    //!
    //! A forgotten attribute is invisible. Set also the
    //! "Valid" status to False. Obvioulsy, DF cannot
    //! empty an attribute (this has a semantic
    //! signification), but can remove it from the
    //! structure. So, a forgotten attribute is NOT an empty
    //! one, but a soon DEAD one.
    //!
    //! Should be private.
    void XTDF_Attribute::Forget(const Standard_Integer aTransaction) {
        NativeHandle()->Forget(aTransaction);
    };
}