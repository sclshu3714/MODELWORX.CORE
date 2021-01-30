#include "XTDocStd_Document.h"

namespace TKLCAF {
    //! Will Abort any execution, clear fields
    //! returns the    document which contains <L>.  raises  an
    //! exception if the document is not found.
    Handle(TDocStd_Document) XTDocStd_Document::Get(XTDF_Label^ L) {
        return TDocStd_Document::Get(*L->GetLabel());
    };

    //! Constructs a document object defined by the
       //! string astorageformat.
    XTDocStd_Document::XTDocStd_Document(Handle(TDocStd_Document) pos) {
        NativeHandle() = pos;
    };

    //! Constructs a document object defined by the
        //! string astorageformat.
    XTDocStd_Document::XTDocStd_Document(System::String^ astorageformat) {
        XTCollection_ExtendedString^ pos = gcnew XTCollection_ExtendedString(astorageformat, Standard_False);
        NativeHandle() = new TDocStd_Document(*pos ->GetExtendedString());
    };

    //! Constructs a document object defined by the
    //! string astorageformat.
    XTDocStd_Document::XTDocStd_Document(const TCollection_ExtendedString& astorageformat) {
        NativeHandle() = new TDocStd_Document(astorageformat);
    };

    //! Constructs a document object defined by the
    //! string astorageformat.
    XTDocStd_Document::XTDocStd_Document(XTCollection_ExtendedString^ astorageformat) {
        NativeHandle() = new TDocStd_Document(*astorageformat->GetExtendedString());
    };

    Handle(TDocStd_Document) XTDocStd_Document::GetDocument() {
        return  NativeHandle();
    };

    //! the document is saved in a file.
    Standard_Boolean XTDocStd_Document::IsSaved() {
        return NativeHandle()->IsSaved();
    };

    //! returns True if document differs from the state of last saving.
    //! this method have to be called only wroking in the transaction mode
    Standard_Boolean XTDocStd_Document::IsChanged() {
        return NativeHandle()->IsChanged();
    };

    //! This method have to be called to show document that it has been saved
    void XTDocStd_Document::SetSaved() {
        NativeHandle()->SetSaved();
    };

    //! Say to document what it is not saved.
    //! Use value, returned earlier by GetSavedTime().
    void XTDocStd_Document::SetSavedTime(const Standard_Integer theTime) {
        NativeHandle()->SetSavedTime(theTime);
    };

    //! Returns value of <mySavedTime> to be used later in SetSavedTime()
    Standard_Integer XTDocStd_Document::GetSavedTime() {
        return NativeHandle()->GetSavedTime();
    };

    //! raise if <me> is not saved.
    TCollection_ExtendedString XTDocStd_Document::GetName() {
        return NativeHandle()->GetName();
    };

    //! returns the OS  path of the  file, in wich one <me> is
    //! saved. Raise an exception if <me> is not saved.
    TCollection_ExtendedString XTDocStd_Document::GetPath() {
        return NativeHandle()->GetPath();
    };

    void XTDocStd_Document::SetData(const Handle(TDF_Data)& data) {
        NativeHandle()->SetData(data);
    };

    Handle(TDF_Data) XTDocStd_Document::GetData() {
        return NativeHandle()->GetData();
    };

    //! Returns the main label in this data framework.
    //! By definition, this is the label with the entry 0:1.
    XTDF_Label^ XTDocStd_Document::Main() {
        return gcnew XTDF_Label(NativeHandle()->Main());
    };

    //! Returns True if the main label has no attributes
    Standard_Boolean XTDocStd_Document::IsEmpty() {
        return NativeHandle()->IsEmpty();
    };

    //! Returns False if the  document has been modified
    //! but not recomputed.
    Standard_Boolean XTDocStd_Document::IsValid() {
        return NativeHandle()->IsValid();
    };

    //! Notify the label as modified, the Document becomes UnValid.
    //! returns True if <L> has been notified as modified.
    void XTDocStd_Document::SetModified(XTDF_Label^ L) {
        NativeHandle()->SetModified(*L->GetLabel());
    };

    //! Remove all modifications. After this call The document
    //! becomesagain Valid.
    void XTDocStd_Document::PurgeModified() {
        NativeHandle()->PurgeModified();
    };

    //! Returns the labels which have been modified in
    //! this document.
    TDF_LabelMap XTDocStd_Document::GetModified() {
        return NativeHandle()->GetModified();
    };

    //! Launches a new command. This command may be undone.
    void XTDocStd_Document::NewCommand() {
        NativeHandle()->NewCommand();
    };

    //! returns True if a Command transaction is open in the curret .
    Standard_Boolean XTDocStd_Document::HasOpenCommand() {
        return NativeHandle()->HasOpenCommand();
    };

    //! Opens a new command transaction in this document.
    //! You can use HasOpenCommand to see whether a command is already open.
    //! Exceptions
    //! Standard_DomainError if a command is already open in this document.
    void XTDocStd_Document::OpenCommand() {
        NativeHandle()->OpenCommand();
    };

    //! Commits documents transactions and fills the
    //! transaction manager with documents that have
    //! been changed during the transaction.
    //! If no command transaction is open, nothing is done.
    //! Returns True if a new delta has been added to myUndos.
    Standard_Boolean XTDocStd_Document::CommitCommand() {
        return NativeHandle()->CommitCommand();
    };

    //! Abort the  Command  transaction. Does nothing If there is
    //! no Command transaction open.
    void XTDocStd_Document::AbortCommand() {
        NativeHandle()->AbortCommand();
    };

    //! The current limit on the number of undos
    Standard_Integer XTDocStd_Document::GetUndoLimit() {
        return NativeHandle()->GetUndoLimit();
    };

    //! Set the  limit on  the number of  Undo Delta  stored 0
    //! will disable  Undo  on the  document A negative  value
    //! means no limit. Note that by default Undo is disabled.
    //! Enabling  it will  take effect with  the next  call to
    //! NewCommand. Of course this limit is the same for Redo
    void XTDocStd_Document::SetUndoLimit(const Standard_Integer L) {
        NativeHandle()->SetUndoLimit(L);
    };

    //! Remove all stored Undos and Redos
    void XTDocStd_Document::ClearUndos() {
        NativeHandle()->ClearUndos();
    };

    //! Remove all stored Redos
    void XTDocStd_Document::ClearRedos() {
        NativeHandle()->ClearRedos();
    };

    //! Returns the number of undos stored in this
    //! document. If this figure is greater than 0, the method Undo
    //! can be used.
    Standard_Integer XTDocStd_Document::GetAvailableUndos() {
        return NativeHandle()->GetAvailableUndos();
    };

    //! Will UNDO  one step, returns  False if no undo was
    //! done (Undos == 0).
    //! Otherwise, true is returned and one step in the
    //! list of undoes is undone.
    Standard_Boolean XTDocStd_Document::Undo() {
        return NativeHandle()->Undo();
    };

    //! Returns the number of redos stored in this
    //! document. If this figure is greater than 0, the method Redo
    //! can be used.
    Standard_Integer XTDocStd_Document::GetAvailableRedos() {
        return NativeHandle()->GetAvailableRedos();
    };

    //! Will REDO  one step, returns  False if no redo was
    //! done (Redos == 0).
    //! Otherwise, true is returned, and one step in the list of redoes is done again.
    Standard_Boolean XTDocStd_Document::Redo() {
        return NativeHandle()->Redo();
    };

    TDF_DeltaList XTDocStd_Document::GetUndos() {
        return NativeHandle()->GetUndos();
    };

    TDF_DeltaList XTDocStd_Document::GetRedos() {
        return NativeHandle()->GetRedos();
    };

    //! Removes the first undo in the list of document undos.
    //! It is used in the application when the undo limit is exceed.
    void XTDocStd_Document::RemoveFirstUndo() {
        NativeHandle()->RemoveFirstUndo();
    };

    //! Initializes the procedure of delta compaction
    //! Returns false if there is no delta to compact
    //! Marks the last delta as a "from" delta
    Standard_Boolean XTDocStd_Document::InitDeltaCompaction() {
        return NativeHandle()->InitDeltaCompaction();
    };

    //! Performs the procedure of delta compaction
    //! Makes all deltas starting from "from" delta
    //! till the last one to be one delta.
    Standard_Boolean XTDocStd_Document::PerformDeltaCompaction() {
        return NativeHandle()->PerformDeltaCompaction();
    };

    //! Set   modifications on  labels  impacted  by  external
    //! references to the entry.  The document becomes invalid
    //! and must be recomputed.
    void XTDocStd_Document::UpdateReferences(const TCollection_AsciiString& aDocEntry) {
        NativeHandle()->UpdateReferences(aDocEntry);
    };

    //! Recompute if the document was  not valid and propagate
    //! the reccorded modification.
    void XTDocStd_Document::Recompute() {
        NativeHandle()->Recompute();
    };

    //! This method Update   will be called
    //! to signal the end   of the modified references list.
    //! The    document     should    be  recomputed     and
    //! UpdateFromDocuments  should be called.  Update should
    //! returns True in case  of success, false otherwise.  In
    //! case of Failure, additional information can be given in
    //! ErrorString.
    //! Update the document by propagation
    //! ==================================
    //! Update   the    document    from   internal   stored
    //! modifications.   If   you   want  to   undoing  this
    //! operation, please call NewCommand before.
    //! to change format (advanced programming)
    //! ================
    void XTDocStd_Document::Update(const Handle(CDM_Document)& aToDocument, Standard_Integer aReferenceIdentifier, Standard_Address aModifContext) {
        NativeHandle()->Update(aToDocument, aReferenceIdentifier, aModifContext);
    };

    TCollection_ExtendedString XTDocStd_Document::StorageFormat() {
        return NativeHandle()->StorageFormat();
    };

    //! Sets saving mode for empty labels. If Standard_True, empty labels will be saved.
    void XTDocStd_Document::SetEmptyLabelsSavingMode(const Standard_Boolean isAllowed) {
        NativeHandle()->SetEmptyLabelsSavingMode(isAllowed);
    };

    //! Returns saving mode for empty labels.
    Standard_Boolean XTDocStd_Document::EmptyLabelsSavingMode() {
        return NativeHandle()->EmptyLabelsSavingMode();
    };

    //! methods for the nested transaction mode
    void XTDocStd_Document::ChangeStorageFormat(const TCollection_ExtendedString& newStorageFormat) {
        NativeHandle()->ChangeStorageFormat(newStorageFormat);
    };

    //! Sets nested transaction mode if isAllowed == Standard_True
    void XTDocStd_Document::SetNestedTransactionMode(const Standard_Boolean isAllowed) {
        NativeHandle()->SetNestedTransactionMode(isAllowed);
    };

    //! Returns Standard_True if mode is set
    Standard_Boolean XTDocStd_Document::IsNestedTransactionMode() {
        return NativeHandle()->IsNestedTransactionMode();
    };

    //! if theTransactionOnly is True changes is denied outside transactions
    void XTDocStd_Document::SetModificationMode(const Standard_Boolean theTransactionOnly) {
        NativeHandle()->SetModificationMode(theTransactionOnly);
    };

    //! returns True if changes allowed only inside transactions
    Standard_Boolean XTDocStd_Document::ModificationMode() {
        return NativeHandle()->ModificationMode();
    };

    //! Prepares document for closing
    void XTDocStd_Document::BeforeClose() {
        NativeHandle()->BeforeClose();
    };
}