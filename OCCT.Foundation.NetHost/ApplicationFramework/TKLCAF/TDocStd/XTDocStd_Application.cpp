#include "XTDocStd_Application.h"

namespace TKLCAF {
    //! Constructs the new instance and registers it in CDM_Session
    XTDocStd_Application::XTDocStd_Application() {
        NativeHandle() = new TDocStd_Application();
    };

    //! Constructs the new instance and registers it in CDM_Session
    XTDocStd_Application::XTDocStd_Application(TDocStd_Application* pos) {
        NativeHandle() = new TDocStd_Application(*pos);
    };

    void XTDocStd_Application::SetNativeHandle(Handle(TDocStd_Application) pos) {
        NativeHandle() = pos;
    };
    //! Check if meta data driver was successfully loaded
    //! by the application constructor
    Standard_Boolean XTDocStd_Application::IsDriverLoaded() {
        return NativeHandle()->IsDriverLoaded();
    };

    //! Redefines message driver, by default outputs to std::cout.
    Handle(Message_Messenger) XTDocStd_Application::MessageDriver() {
        return NativeHandle()->MessageDriver();
    };

    //! Returns resource manager defining supported persistent formats.
    //!
    //! Default implementation loads resource file with name ResourcesName(),
    //! unless field myResources is already initialized (either by
    //! previous call or in any other way).
    //!
    //! The resource manager should define:
    //!
    //! * Format name for each file extension supported:
    //!   - [Extension].FileFormat: [Format]
    //!
    //! * For each format supported (as returned by Formats()),
    //!   its extension, description string, and (when applicable)
    //!   GUIDs of storage and retrieval plugins:
    //!   - [Format].Description: [Description]
    //!   - [Format].FileExtension: [Extension]
    //!   - [Format].RetrievalPlugin: [GUID] (optional)
    //!   - [Format].StoragePlugin: [GUID] (optional)
    Handle(Resource_Manager) XTDocStd_Application::Resources() {
        return NativeHandle()->Resources();
    };

    //! Returns the name of the file containing the
    //! resources of this application, for support of legacy
    //! method of loading formats data from resource files.
    //!
    //! Method DefineFormat() can be used to define all necessary
    //! parameters explicitly without actually using resource files.
    //!
    //! In a resource file, the application associates the 
    //! schema name of the document with the storage and
    //! retrieval plug-ins that are to be loaded for each
    //! document. On retrieval, the application reads the
    //! schema name in the heading of the CSF file and
    //! loads the plug-in indicated in the resource file.
    //! This plug-in instantiates the actual driver for
    //! transient-persistent conversion.
    //! Your application can bring this process into play
    //! by defining a class which inherits
    //! CDF_Application and redefines the function
    //! which returns the appropriate resources file. At
    //! this point, the function Retrieve and the class
    //! CDF_Store can be called. This allows you to
    //! deal with storage and retrieval of - as well as
    //! copying and pasting - documents.
    //! To implement a class like this, several virtual
    //! functions should be redefined. In particular, you
    //! must redefine the abstract function Resources
    //! inherited from the superclass CDM_Application.
    //!
    //! Default implementation returns empty string.
    Standard_CString XTDocStd_Application::ResourcesName() {
        return NativeHandle()->ResourcesName();
    };

    //! Sets up resources and registers read and storage drivers for
    //! the specified format.
    //! 
    //! @param theFormat - unique name for the format, used to identify it.
    //! @param theDescription - textual description of the format.
    //! @param theExtension - extension of the files in that format. 
    //!                       The same extension can be used by several formats.
    //! @param theReader - instance of the read driver for the format.
    //!                    Null value is allowed (no possibility to read).
    //! @param theWriter - instance of the write driver for the format.
    //!                    Null value is allowed (no possibility to write).
    void XTDocStd_Application::DefineFormat(const TCollection_AsciiString& theFormat, TCollection_AsciiString& theDescription, TCollection_AsciiString& theExtension, Handle(PCDM_RetrievalDriver)& theReader, Handle(PCDM_StorageDriver)& theWriter) {
        NativeHandle()->DefineFormat(theFormat, theDescription, theExtension, theReader, theWriter);
    };

    //! Returns the sequence of reading formats supported by the application.
    //!
    //! @param theFormats - sequence of reading formats. Output parameter.
    void XTDocStd_Application::ReadingFormats(TColStd_SequenceOfAsciiString& theFormats) {
        NativeHandle()->ReadingFormats(theFormats);
    };

    //! Returns the sequence of writing formats supported by the application.
    //!
    //! @param theFormats - sequence of writing formats. Output parameter.
    void XTDocStd_Application::WritingFormats(TColStd_SequenceOfAsciiString& theFormats) {

    };

    //! returns the number of documents handled by the current applicative session.
    Standard_Integer XTDocStd_Application::NbDocuments() {
        return NativeHandle()->NbDocuments();
    };

    //! Constructs the new document aDoc.
    //! aDoc is identified by the index index which is
    //! any integer between 1 and n where n is the
    //! number of documents returned by NbDocument.
    //! Example
    //! Handle(TDocStd_Application)
    //! anApp;
    //! if (!CafTest::Find(A)) return 1;
    //! Handle(TDocStd) aDoc;
    //! Standard_Integer nbdoc = anApp->NbDocuments();
    //! for (Standard_Integer i = 1; i <= nbdoc; i++) {
    //! aApp->GetDocument(i,aDoc);
    void XTDocStd_Application::GetDocument(const Standard_Integer index, Handle(TDocStd_Document)& aDoc) {
        NativeHandle()->GetDocument(index, aDoc);
    };

    //! Constructs the new document aDoc.
    //! aDoc is identified by the index index which is
    //! any integer between 1 and n where n is the
    //! number of documents returned by NbDocument.
    //! Example
    //! Handle(TDocStd_Application)
    //! anApp;
    //! if (!CafTest::Find(A)) return 1;
    //! Handle(TDocStd) aDoc;
    //! Standard_Integer nbdoc = anApp->NbDocuments();
    //! for (Standard_Integer i = 1; i <= nbdoc; i++) {
    //! aApp->GetDocument(i,aDoc);
    void XTDocStd_Application::GetDocument(const Standard_Integer index, XTDocStd_Document^ aDoc) {
        NativeHandle()->GetDocument(index, aDoc->GetDocument());
    };

    //! Constructs the empty new document aDoc.
    //! This document will have the format format.
    //! If InitDocument is redefined for a specific
    //! application, the new document is handled by the
    //! applicative session.
    void XTDocStd_Application::NewDocument(const TCollection_ExtendedString& format, Handle(TDocStd_Document)& aDoc) {
        NativeHandle()->NewDocument(format, aDoc);
    };

    //! Constructs the empty new document aDoc.
    //! This document will have the format format.
    //! If InitDocument is redefined for a specific
    //! application, the new document is handled by the
    //! applicative session.
    void XTDocStd_Application::NewDocument(XTCollection_ExtendedString^ format, XTDocStd_Document^ aDoc) {
        NativeHandle()->NewDocument(format->GetExtendedString(), aDoc->GetDocument());
    };
    //! Constructs the empty new document aDoc.
   //! This document will have the format format.
   //! If InitDocument is redefined for a specific
   //! application, the new document is handled by the
   //! applicative session.
    void XTDocStd_Application::NewDocument(System::String^ format, XTDocStd_Document^ aDoc) {
        XTCollection_ExtendedString^ pos = gcnew XTCollection_ExtendedString(format, Standard_False);
        NativeHandle()->NewDocument(pos->GetExtendedString(), aDoc->GetDocument());
    };

    //! Initialize the document aDoc for the applicative session.
    //! This virtual function is called by NewDocument
    //! and is to be redefined for each specific application.
    //! Modified flag (different of disk version)
    //! =============
    //! to open/save a document
    //! =======================
    void XTDocStd_Application::InitDocument(const Handle(TDocStd_Document)& aDoc) {
        NativeHandle()->InitDocument(aDoc);
    };

    //! Initialize the document aDoc for the applicative session.
    //! This virtual function is called by NewDocument
    //! and is to be redefined for each specific application.
    //! Modified flag (different of disk version)
    //! =============
    //! to open/save a document
    //! =======================
    void XTDocStd_Application::InitDocument(XTDocStd_Document^ aDoc) {
        NativeHandle()->InitDocument(aDoc->GetDocument());
    };

    //! Close the given document. the document is not any more
    //! handled by the applicative session.
    void XTDocStd_Application::Close(const Handle(TDocStd_Document)& aDoc) {
        NativeHandle()->Close(aDoc);
    };

    //! Close the given document. the document is not any more
    //! handled by the applicative session.
    void XTDocStd_Application::Close(XTDocStd_Document^ aDoc) {
        NativeHandle()->Close(aDoc->GetDocument());
    };
    //! Returns an index for the document found in the
    //! path path in this applicative session.
    //! If the returned value is 0, the document is not
    //! present in the applicative session.
    //! This method can be used for the interactive part
    //! of an application. For instance, on a call to
    //! Open, the document to be opened may already
    //! be in memory. IsInSession checks to see if this
    //! is the case. Open can be made to depend on
    //! the value of the index returned: if IsInSession
    //! returns 0, the document is opened; if it returns
    //! another value, a message is displayed asking the
    //! user if he wants to override the version of the
    //! document in memory.
    //! Example:
    //! Standard_Integer insession = A->IsInSession(aDoc);
    //! if (insession > 0) {
    //! std::cout << "document " << insession << " is already in session" << std::endl;
    //! return 0;
    //! }
    Standard_Integer XTDocStd_Application::IsInSession(const TCollection_ExtendedString& path) {
        return NativeHandle()->IsInSession(path);
    };
    Standard_Integer XTDocStd_Application::IsInSession(XTCollection_ExtendedString^ path) {
        return NativeHandle()->IsInSession(path->GetExtendedString());
    };

    //! Retrieves the document aDoc stored under the
    //! name aName in the directory directory.
    //! In order not to override a version of aDoc which
    //! is already in memory, this method can be made
    //! to depend on the value returned by IsInSession.
    PCDM_ReaderStatus XTDocStd_Application::Open(const TCollection_ExtendedString& path, Handle(TDocStd_Document)& aDoc) {
        return NativeHandle()->Open(path, aDoc);
    };
    PCDM_ReaderStatus XTDocStd_Application::Open(XTCollection_ExtendedString^ path, XTDocStd_Document^ aDoc) {
        return NativeHandle()->Open(path->GetExtendedString(), aDoc->GetDocument());
    };
    //! Retrieves aDoc from standard SEEKABLE stream theIStream.
    //! the stream should support SEEK fuctionality
    PCDM_ReaderStatus XTDocStd_Application::Open(Standard_IStream& theIStream, Handle(TDocStd_Document)& theDoc) {
        return NativeHandle()->Open(theIStream, theDoc);
    };
    PCDM_ReaderStatus XTDocStd_Application::Open(Standard_IStream& theIStream, XTDocStd_Document^ theDoc) {
        return NativeHandle()->Open(theIStream, theDoc->GetDocument());
    };

    //! Save the  active document  in the file  <name> in the
    //! path <path> ; o verwrites  the file  if  it already exists.
    PCDM_StoreStatus XTDocStd_Application::SaveAs(const Handle(TDocStd_Document)& aDoc, TCollection_ExtendedString& path) {
        return NativeHandle()->SaveAs(aDoc, path);
    };
    //! Save the  active document  in the file  <name> in the
    //! path <path> ; o verwrites  the file  if  it already exists.
    PCDM_StoreStatus XTDocStd_Application::SaveAs(XTDocStd_Document^ aDoc, XTCollection_ExtendedString^ path) {
        return NativeHandle()->SaveAs(aDoc->GetDocument(), path->GetExtendedString());
    };

    //! Save theDoc to standard SEEKABLE stream theOStream.
    //! the stream should support SEEK fuctionality
    PCDM_StoreStatus XTDocStd_Application::SaveAs(const Handle(TDocStd_Document)& theDoc, Standard_OStream& theOStream) {
        return NativeHandle()->SaveAs(theDoc, theOStream);
    };

    //! Save theDoc to standard SEEKABLE stream theOStream.
    //! the stream should support SEEK fuctionality
    PCDM_StoreStatus XTDocStd_Application::SaveAs(XTDocStd_Document^ theDoc, Standard_OStream& theOStream) {
        return NativeHandle()->SaveAs(theDoc->GetDocument(), theOStream);
    };

    //! Save aDoc active document.
    //! Exceptions:
    //! Standard_NotImplemented if the document
    //! was not retrieved in the applicative session by using Open.
    PCDM_StoreStatus XTDocStd_Application::Save(const Handle(TDocStd_Document)& aDoc) {
        return NativeHandle()->Save(aDoc);
    };

    //! Save aDoc active document.
    //! Exceptions:
    //! Standard_NotImplemented if the document
    //! was not retrieved in the applicative session by using Open.
    PCDM_StoreStatus XTDocStd_Application::Save(XTDocStd_Document^ aDoc) {
        return NativeHandle()->Save(aDoc->GetDocument());
    };

    //! Save the  active document  in the file  <name> in the
    //! path <path>  .  overwrite  the file  if  it
    //! already exist.
    PCDM_StoreStatus XTDocStd_Application::SaveAs(const Handle(TDocStd_Document)& aDoc, TCollection_ExtendedString& path, TCollection_ExtendedString& theStatusMessage) {
        return NativeHandle()->SaveAs(aDoc, path, theStatusMessage);
    };

    //! Save the  active document  in the file  <name> in the
    //! path <path>  .  overwrite  the file  if  it
    //! already exist.
    PCDM_StoreStatus XTDocStd_Application::SaveAs(XTDocStd_Document^ aDoc, XTCollection_ExtendedString^ path, XTCollection_ExtendedString^ theStatusMessage) {
        return NativeHandle()->SaveAs(aDoc->GetDocument(), path->GetExtendedString(), theStatusMessage->GetExtendedString());
    };

    //! Save theDoc TO standard SEEKABLE stream theOStream.
    //! the stream should support SEEK fuctionality
    PCDM_StoreStatus XTDocStd_Application::SaveAs(const Handle(TDocStd_Document)& theDoc, Standard_OStream& theOStream, TCollection_ExtendedString& theStatusMessage) {
        return NativeHandle()->SaveAs(theDoc, theOStream, theStatusMessage);
    };

    //! Save theDoc TO standard SEEKABLE stream theOStream.
    //! the stream should support SEEK fuctionality
    PCDM_StoreStatus XTDocStd_Application::SaveAs(XTDocStd_Document^ theDoc, Standard_OStream& theOStream, XTCollection_ExtendedString^ theStatusMessage) {
        return NativeHandle()->SaveAs(theDoc->GetDocument(), theOStream, theStatusMessage->GetExtendedString());
    };

    //! Save the document overwriting the previous file
    PCDM_StoreStatus XTDocStd_Application::Save(const Handle(TDocStd_Document)& aDoc, TCollection_ExtendedString& theStatusMessage) {
        return NativeHandle()->Save(aDoc, theStatusMessage);
    };

    //! Save the document overwriting the previous file
    PCDM_StoreStatus XTDocStd_Application::Save(XTDocStd_Document^ aDoc, XTCollection_ExtendedString^ theStatusMessage) {
        return NativeHandle()->Save(aDoc->GetDocument(), theStatusMessage->GetExtendedString());
    };

    //! Notification that is fired at each OpenTransaction event.
    void XTDocStd_Application::OnOpenTransaction(const Handle(TDocStd_Document)& theDoc) {
        NativeHandle()->OnOpenTransaction(theDoc);
    };

    //! Notification that is fired at each OpenTransaction event.
    void XTDocStd_Application::OnOpenTransaction(XTDocStd_Document^ theDoc) {
        NativeHandle()->OnOpenTransaction(theDoc->GetDocument());
    };

    //! Notification that is fired at each CommitTransaction event.
    void XTDocStd_Application::OnCommitTransaction(const Handle(TDocStd_Document)& theDoc) {
        NativeHandle()->OnCommitTransaction(theDoc);
    };

    //! Notification that is fired at each CommitTransaction event.
    void XTDocStd_Application::OnCommitTransaction(XTDocStd_Document^ theDoc) {
        NativeHandle()->OnCommitTransaction(theDoc->GetDocument());
    };

    //! Notification that is fired at each AbortTransaction event.
    void XTDocStd_Application::OnAbortTransaction(const Handle(TDocStd_Document)& theDoc) {
        NativeHandle()->OnAbortTransaction(theDoc);
    };

    //! Notification that is fired at each AbortTransaction event.
    void XTDocStd_Application::OnAbortTransaction(XTDocStd_Document^ theDoc) {
        NativeHandle()->OnAbortTransaction(theDoc->GetDocument());
    };
}