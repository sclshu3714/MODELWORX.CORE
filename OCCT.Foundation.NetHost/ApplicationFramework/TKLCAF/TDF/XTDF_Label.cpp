#include <XTDF_Label.h>
#include <XTDataStd_Name.h>
#include <XTPrsStd_AISPresentation.h>        
#include <TDataStd_Name.hxx>
using namespace TKVCAF;

namespace TKLCAF {
    //! Constructs an empty label object.
    XTDF_Label::XTDF_Label() {
        NativeHandle = new TDF_Label();
    };

    //! Constructs an empty label object.
    XTDF_Label::XTDF_Label(TDF_Label* pos) {
        NativeHandle = new TDF_Label(*pos);
    };

    //! Constructs an empty label object.
    XTDF_Label::XTDF_Label(TDF_Label pos) {
        NativeHandle = new TDF_Label(pos);
    };

    //!  Returns the TDF_Label
    TDF_Label XTDF_Label::GetLabel() {
        return *NativeHandle;
    };

    //! Nullifies the label.
    void XTDF_Label::Nullify() {
        NativeHandle->Nullify();
    };

    //! Returns the Data owning <me>.
    Handle(TDF_Data) XTDF_Label::Data() {
        return NativeHandle->Data();
    };

    //! Returns the tag of the label.
    //! This is the integer assigned randomly to a label
    //! in a data framework. This integer is used to
    //! identify this label in an entry.
    Standard_Integer XTDF_Label::Tag() {
        return NativeHandle->Tag();
    };

    //! Returns the label father. This label may be null
    //! if the label is root.
    XTDF_Label^ XTDF_Label::Father() {
        return gcnew XTDF_Label(NativeHandle->Father());
    };

    //! Returns True if the <aLabel> is null, i.e. it has
    //! not been included in the data framework.
    Standard_Boolean XTDF_Label::IsNull() {
        return NativeHandle->IsNull();
    };

    //! Sets or unsets <me> and all its descendants as
    //! imported label, according to <aStatus>.
    void XTDF_Label::Imported(const Standard_Boolean aStatus) {
        NativeHandle->Imported(aStatus);
    };

    //! Returns True if the <aLabel> is imported.
    Standard_Boolean XTDF_Label::IsImported() {
        return NativeHandle->IsImported();
    };

    //! Returns True if the <aLabel> is equal to me (same
    //! LabelNode*).
    Standard_Boolean XTDF_Label::IsEqual(XTDF_Label^ aLabel) {
        return NativeHandle->IsEqual(aLabel->GetLabel());
    };

    Standard_Boolean XTDF_Label::IsDifferent(XTDF_Label^ aLabel) {
        return NativeHandle->IsDescendant(aLabel->GetLabel());
    };

    Standard_Boolean XTDF_Label::IsRoot() {
        return NativeHandle->IsRoot();
    };

    //! Returns true if <me> owns an attribute with <anID> as ID.
    Standard_Boolean XTDF_Label::IsAttribute(const Standard_GUID& anID) {
        return NativeHandle->IsAttribute(anID);
    };

    //! Adds an Attribute  to the current label. Raises if
    //! there is already one.
    void XTDF_Label::AddAttribute(const Handle(TDF_Attribute)& anAttribute, Standard_Boolean append) {
        NativeHandle->AddAttribute(anAttribute, append);
    };

    //! Forgets an  Attribute   from the  current  label,
    //! setting its   forgotten status true and  its valid
    //! status false. Raises if   the attribute is not in
    //! the structure.
    void XTDF_Label::ForgetAttribute(const Handle(TDF_Attribute)& anAttribute) {
        NativeHandle->ForgetAttribute(anAttribute);
    };

    //! Forgets the  Attribute of  GUID <aguid> from   the
    //! current label   . If the   attribute doesn't exist
    //! returns False. Otherwise returns True.
    Standard_Boolean XTDF_Label::ForgetAttribute(const Standard_GUID& aguid) {
        return NativeHandle->ForgetAttribute(aguid);
    };

    //! Forgets all the attributes. Does it on also on the
    //! sub-labels if <clearChildren> is set to true. Of
    //! course, this method is compatible with Transaction
    //! & Delta mecanisms.
    void XTDF_Label::ForgetAllAttributes(const Standard_Boolean clearChildren) {
        return NativeHandle->ForgetAllAttributes(clearChildren);
    };

    //! Undo Forget action, setting its forgotten status
    //! false and its valid status true. Raises if the
    //! attribute is not in the structure.
    void XTDF_Label::ResumeAttribute(const Handle(TDF_Attribute)& anAttribute) {
        return NativeHandle->ResumeAttribute(anAttribute);
    };

    //! Finds an attribute of the current label, according
    //! to <anID>.
    //! If anAttribute is not a valid one, false is returned.
    //!
    //! The method returns True if found, False otherwise.
    //!
    //! A removed attribute cannot be found.
    Standard_Boolean XTDF_Label::FindAttribute(Standard_GUID anID, Handle(TDF_Attribute) anAttribute) {
        return NativeHandle->FindAttribute(anID, anAttribute);
    };

    Standard_Boolean XTDF_Label::FindAttribute(XStandard_GUID^ anID, XTDF_Attribute^% theAttribute) {
        System::String^ typeName = theAttribute->GetType()->Name;
        Standard_Boolean result = false;
        if (typeName == "XTDataStd_Name") {
            //XTDataStd_Name^ XName = dynamic_cast<XTDataStd_Name^>(theAttribute);
            Handle(TDataStd_Name) TName;
            result = NativeHandle->FindAttribute(anID->GetGUID(), TName);
            //std::cout << "  Name: " << TName->Get() << std::endl;
            theAttribute = gcnew XTDataStd_Name(TName);
            //XTDataStd_Name^ XName = dynamic_cast<XTDataStd_Name^>(theAttribute);
            //std::cout << "  Name: " << XName->GetName()->Get() << std::endl;
        }
        else if (typeName == "XTPrsStd_AISPresentation") {
            //XTPrsStd_AISPresentation^ XAISPresentation = dynamic_cast<XTPrsStd_AISPresentation^>(theAttribute);
            Handle(TPrsStd_AISPresentation) TAISPresentation;
            result = NativeHandle->FindAttribute(anID->GetGUID(), TAISPresentation);
            theAttribute = gcnew XTPrsStd_AISPresentation(TAISPresentation);
        }
        return  result;
    };

    //! Finds an attribute of the current label, according
    //! to <anID> and <aTransaction>. This attribute
    //! has/had to be a valid one for the given
    //! transaction index . So, this attribute is not
    //! necessary a valid one.
    //!
    //! The method returns True if found, False otherwise.
    //!
    //! A removed attribute cannot be found nor a backuped
    //! attribute of a removed one.
    Standard_Boolean XTDF_Label::FindAttribute(const Standard_GUID& anID, Standard_Integer aTransaction, Handle(TDF_Attribute)& anAttribute) {
        return NativeHandle->FindAttribute(anID, aTransaction, anAttribute);
    };

    Standard_Boolean XTDF_Label::FindAttribute(XStandard_GUID^ anID, Standard_Integer aTransaction, XTDF_Attribute^ anAttribute) {
        return NativeHandle->FindAttribute(anID->GetGUID(), aTransaction, anAttribute->GetAttribute());
    };

    //! Returns true if <me> or a DESCENDANT of <me> owns
    //! attributes not yet available in transaction 0. It
    //! means at least one of their attributes is new,
    //! modified or deleted.
    Standard_Boolean XTDF_Label::MayBeModified() {
        return NativeHandle->MayBeModified();
    };

    //! Returns true if <me> owns attributes not yet
    //! available in transaction 0. It means at least one
    //! attribute is new, modified or deleted.
    Standard_Boolean XTDF_Label::AttributesModified() {
        return NativeHandle->AttributesModified();
    };

    //! Returns true if this label has at least one attribute.
    Standard_Boolean XTDF_Label::HasAttribute() {
        return NativeHandle->HasAttribute();
    };

    //! Returns the number of attributes.
    Standard_Integer XTDF_Label::NbAttributes() {
        return NativeHandle->NbAttributes();
    };

    //! Returns the depth of the label in the data framework.
    //! This corresponds to the number of fathers which
    //! this label has, and is used in determining
    //! whether a label is root, null or equivalent to another label.
    //! Exceptions:
    //! Standard_NullObject if this label is null. This is
    //! because a null object can have no depth.
    Standard_Integer XTDF_Label::Depth() {
        return NativeHandle->Depth();
    };

    //! Returns True if <me> is a descendant of
    //! <aLabel>. Attention: every label is its own
    //! descendant.
    Standard_Boolean XTDF_Label::IsDescendant(XTDF_Label^ aLabel) {
        return NativeHandle->IsDescendant(aLabel->GetLabel());
    };

    //! Returns the root label Root of the data structure.
    //! This has a depth of 0.
    //! Exceptions:
    //! Standard_NullObject if this label is null. This is
    //! because a null object can have no depth.
    XTDF_Label^ XTDF_Label::Root() {
        return gcnew XTDF_Label(NativeHandle->Root());
    };

    //! Returns true if this label has at least one child.
    Standard_Boolean XTDF_Label::HasChild() {
        return NativeHandle->HasChild();
    };

    //! Returns the number of children.
    Standard_Integer XTDF_Label::NbChildren() {
        return NativeHandle->NbChildren();
    };

    //! Finds a child label having <aTag> as tag. Creates
    //! The tag aTag identifies the label which will be the parent.
    //! If create is true and no child label is found, a new one is created.
    //! Example:
    //! //creating a label with tag 10 at Root
    //! TDF_Label lab1 = aDF->Root().FindChild(10);
    //! //creating labels 7 and 2 on label 10
    //! TDF_Label lab2 = lab1.FindChild(7);
    //! TDF_Label lab3 = lab1.FindChild(2);
    XTDF_Label^ XTDF_Label::FindChild(const Standard_Integer aTag, Standard_Boolean create) {
        return gcnew XTDF_Label(NativeHandle->FindChild(aTag, create));
    };

    //! Create  a new child   label of me  using autoamtic
    //! delivery tags provided by TagSource.
    XTDF_Label^ XTDF_Label::NewChild() {
        return gcnew XTDF_Label(NativeHandle->NewChild());
    };

    //! Returns the current transaction index.
    Standard_Integer XTDF_Label::Transaction() {
        return NativeHandle->Transaction();
    };

    //! Returns true if node address of <me> is lower than
    //! <otherLabel> one. Used to quickly sort labels (not
    //! on entry criterion).
    //!
    //! -C++: inline
    Standard_Boolean XTDF_Label::HasLowerNode(XTDF_Label^ otherLabel) {
        return NativeHandle->HasLowerNode(otherLabel->GetLabel());
    };

    //! Returns true if node address of <me> is greater
    //! than <otherLabel> one. Used to quickly sort labels
    //! (not on entry criterion).
    //!
    //! -C++: inline
    Standard_Boolean XTDF_Label::HasGreaterNode(XTDF_Label^ otherLabel) {
        return NativeHandle->HasGreaterNode(otherLabel->GetLabel());
    };

    //! Dumps the minimum information about <me> on
    //! <aStream>.
    Standard_OStream& XTDF_Label::Dump(Standard_OStream& anOS) {
        return NativeHandle->Dump(anOS);
    };

    //! Dumps the label on <aStream> and its attributes
    //! rank in <aMap> if their IDs are kept by <IDFilter>.
    void XTDF_Label::ExtendedDump(Standard_OStream& anOS, TDF_IDFilter& aFilter, TDF_AttributeIndexedMap& aMap) {
        NativeHandle->ExtendedDump(anOS, aFilter, aMap);
    };

    //! Dumps the label entry.
    void XTDF_Label::EntryDump(Standard_OStream& anOS) {
        NativeHandle->EntryDump(anOS);
    };
}
