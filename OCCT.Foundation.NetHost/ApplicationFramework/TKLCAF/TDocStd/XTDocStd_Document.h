// Created on: 1999-04-07
// Created by: Denis PASCAL
// Copyright (c) 1999 Matra Datavision
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

#ifndef _XTDocStd_Document_HeaderFile
#define _XTDocStd_Document_HeaderFile
#pragma once
#include "XTDF_Label.h"
#include "XTDocStd_Document.h"
#include "XTCollection_ExtendedString.h"
#include <TDocStd_Document.hxx>
#include <NCollection_Haft.h>
#include "XStandard_Helper.h"


#include <Standard.hxx>
#include <Standard_Type.hxx>

#include <TCollection_ExtendedString.hxx>
#include <Standard_Integer.hxx>
#include <TDF_Transaction.hxx>
#include <TDF_DeltaList.hxx>
#include <Standard_Boolean.hxx>
#include <CDM_Document.hxx>
#include <TDF_LabelMap.hxx>
#include <Standard_Address.hxx>
class TDF_Data;
class TDF_Delta;
class TDF_Label;
class TCollection_ExtendedString;
class TCollection_AsciiString;
class CDM_Document;
class TDocStd_CompoundDelta;

//class XTDocStd_Document;
//DEFINE_STANDARD_HANDLE(XTDocStd_Document, CDM_Document)

//! The contents of a TDocStd_Application, a
//! document is a container for a data framework
//! composed of labels and attributes. As such,
//! TDocStd_Document is the entry point into the data framework.
//! To gain access to the data, you create a document as follows:
//! Handle(TDocStd_Document) MyDF = new TDocStd_Document
//! The document also allows you to manage:
//! -   modifications, providing Undo and Redo functions.
//! -   command transactions.
//! Warning: The only data saved is the framework (TDF_Data)
using namespace TKernel;
namespace TKLCAF {

    ref class XTDF_Label;
    ref class TKernel::XTCollection_ExtendedString;
    ref class TKernel::XStandard_Helper;
    public ref class XTDocStd_Document
    {

    public:

        //! Will Abort any execution, clear fields
        //! returns the    document which contains <L>.  raises  an
        //! exception if the document is not found.
        static Handle(TDocStd_Document) Get(XTDF_Label^ L);

        //! Constructs a document object defined by the
        //! string astorageformat.
        XTDocStd_Document(Handle(TDocStd_Document) pos);

        //! Constructs a document object defined by the
        //! string astorageformat.
        XTDocStd_Document(System::String^ astorageformat);

        //! Constructs a document object defined by the
        //! string astorageformat.
        XTDocStd_Document(const TCollection_ExtendedString& astorageformat);

        //! Constructs a document object defined by the
        //! string astorageformat.
        XTDocStd_Document(XTCollection_ExtendedString^ astorageformat);

        //!
        Handle(TDocStd_Document) GetDocument();

        //! the document is saved in a file.
        Standard_Boolean IsSaved();

        //! returns True if document differs from the state of last saving.
        //! this method have to be called only wroking in the transaction mode
        Standard_Boolean IsChanged();

        //! This method have to be called to show document that it has been saved
        void SetSaved();

        //! Say to document what it is not saved.
        //! Use value, returned earlier by GetSavedTime().
        void SetSavedTime(const Standard_Integer theTime);

        //! Returns value of <mySavedTime> to be used later in SetSavedTime()
        Standard_Integer GetSavedTime();

        //! raise if <me> is not saved.
        TCollection_ExtendedString GetName();

        //! returns the OS  path of the  file, in wich one <me> is
        //! saved. Raise an exception if <me> is not saved.
        TCollection_ExtendedString GetPath();

        void SetData(const Handle(TDF_Data)& data);

        Handle(TDF_Data) GetData();

        //! Returns the main label in this data framework.
        //! By definition, this is the label with the entry 0:1.
        XTDF_Label^ Main();

        //! Returns True if the main label has no attributes
        Standard_Boolean IsEmpty();

        //! Returns False if the  document has been modified
        //! but not recomputed.
        Standard_Boolean IsValid();

        //! Notify the label as modified, the Document becomes UnValid.
        //! returns True if <L> has been notified as modified.
        void SetModified(XTDF_Label^ L);

        //! Remove all modifications. After this call The document
        //! becomesagain Valid.
        void PurgeModified();

        //! Returns the labels which have been modified in
        //! this document.
        TDF_LabelMap GetModified();

        //! Launches a new command. This command may be undone.
        void NewCommand();

        //! returns True if a Command transaction is open in the curret .
        Standard_Boolean HasOpenCommand();

        //! Opens a new command transaction in this document.
        //! You can use HasOpenCommand to see whether a command is already open.
        //! Exceptions
        //! Standard_DomainError if a command is already open in this document.
        void OpenCommand();

        //! Commits documents transactions and fills the
        //! transaction manager with documents that have
        //! been changed during the transaction.
        //! If no command transaction is open, nothing is done.
        //! Returns True if a new delta has been added to myUndos.
        Standard_Boolean CommitCommand();

        //! Abort the  Command  transaction. Does nothing If there is
        //! no Command transaction open.
        void AbortCommand();

        //! The current limit on the number of undos
        Standard_Integer GetUndoLimit();

        //! Set the  limit on  the number of  Undo Delta  stored 0
        //! will disable  Undo  on the  document A negative  value
        //! means no limit. Note that by default Undo is disabled.
        //! Enabling  it will  take effect with  the next  call to
        //! NewCommand. Of course this limit is the same for Redo
        void SetUndoLimit(const Standard_Integer L);

        //! Remove all stored Undos and Redos
        void ClearUndos();

        //! Remove all stored Redos
        void ClearRedos();

        //! Returns the number of undos stored in this
        //! document. If this figure is greater than 0, the method Undo
        //! can be used.
        Standard_Integer GetAvailableUndos();

        //! Will UNDO  one step, returns  False if no undo was
        //! done (Undos == 0).
        //! Otherwise, true is returned and one step in the
        //! list of undoes is undone.
        Standard_Boolean Undo();

        //! Returns the number of redos stored in this
        //! document. If this figure is greater than 0, the method Redo
        //! can be used.
        Standard_Integer GetAvailableRedos();

        //! Will REDO  one step, returns  False if no redo was
        //! done (Redos == 0).
        //! Otherwise, true is returned, and one step in the list of redoes is done again.
        Standard_Boolean Redo();

        TDF_DeltaList GetUndos();

        TDF_DeltaList GetRedos();

        //! Removes the first undo in the list of document undos.
        //! It is used in the application when the undo limit is exceed.
        void RemoveFirstUndo();

        //! Initializes the procedure of delta compaction
        //! Returns false if there is no delta to compact
        //! Marks the last delta as a "from" delta
        Standard_Boolean InitDeltaCompaction();

        //! Performs the procedure of delta compaction
        //! Makes all deltas starting from "from" delta
        //! till the last one to be one delta.
        Standard_Boolean PerformDeltaCompaction();

        //! Set   modifications on  labels  impacted  by  external
        //! references to the entry.  The document becomes invalid
        //! and must be recomputed.
        void UpdateReferences(const TCollection_AsciiString& aDocEntry);

        //! Recompute if the document was  not valid and propagate
        //! the reccorded modification.
        void Recompute();

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
        virtual void Update(const Handle(CDM_Document)& aToDocument, Standard_Integer aReferenceIdentifier, Standard_Address aModifContext);

        virtual TCollection_ExtendedString StorageFormat();

        //! Sets saving mode for empty labels. If Standard_True, empty labels will be saved.
        void SetEmptyLabelsSavingMode(const Standard_Boolean isAllowed);

        //! Returns saving mode for empty labels.
        Standard_Boolean EmptyLabelsSavingMode();

        //! methods for the nested transaction mode
        virtual void ChangeStorageFormat(const TCollection_ExtendedString& newStorageFormat);

        //! Sets nested transaction mode if isAllowed == Standard_True
        void SetNestedTransactionMode(const Standard_Boolean isAllowed);

        //! Returns Standard_True if mode is set
        Standard_Boolean IsNestedTransactionMode();

        //! if theTransactionOnly is True changes is denied outside transactions
        void SetModificationMode(const Standard_Boolean theTransactionOnly);

        //! returns True if changes allowed only inside transactions
        Standard_Boolean ModificationMode();

        //! Prepares document for closing
        virtual void BeforeClose();

        /// <summary>
        /// ���ؾ��
        /// </summary>
        property Handle(TDocStd_Document) Handle
        {
            Handle(TDocStd_Document) get() {
                return NativeHandle();
            }
        }
    private:
        NCollection_Haft<Handle(TDocStd_Document)> NativeHandle;
    };
}
#endif // _XTDocStd_Document_HeaderFile
