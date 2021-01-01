#include "XSTEPCAFControl_Reader.h"

namespace TKXDESTEP {


    //! Creates a reader with an empty
    //! STEP model and sets ColorMode, LayerMode, NameMode and
    //! PropsMode to Standard_True.
    XSTEPCAFControl_Reader::XSTEPCAFControl_Reader() {
        NativeHandle = new STEPCAFControl_Reader();
    };

    //! Creates a reader with an empty
   //! STEP model and sets ColorMode, LayerMode, NameMode and
   //! PropsMode to Standard_True.
    XSTEPCAFControl_Reader::XSTEPCAFControl_Reader(STEPCAFControl_Reader* pos) {
        NativeHandle = new STEPCAFControl_Reader(*pos);
    };
    //! Creates a reader tool and attaches it to an already existing Session
    //! Clears the session if it was not yet set for STEP
    XSTEPCAFControl_Reader::XSTEPCAFControl_Reader(const Handle(XSControl_WorkSession)& WS, const Standard_Boolean scratch) {
        NativeHandle = new STEPCAFControl_Reader(WS, scratch);
    };

    //! Clears the internal data structures and attaches to a new session
    //! Clears the session if it was not yet set for STEP
    void XSTEPCAFControl_Reader::Init(const Handle(XSControl_WorkSession)& WS, const Standard_Boolean scratch) {
        NativeHandle->Init(WS, scratch);
    };

    //! Loads a file and returns the read status
    //! Provided for use like single-file reader
    XIFSelect_ReturnStatus XSTEPCAFControl_Reader::ReadFile(const Standard_CString filename) {
        return safe_cast<XIFSelect_ReturnStatus>(NativeHandle->ReadFile(filename));
    };

    //! Loads a file and returns the read status
    //! Provided for use like single-file reader
    //! IFSelect_ReturnStatus
    XIFSelect_ReturnStatus XSTEPCAFControl_Reader::ReadFile(System::String^ theFileName) {
        const TCollection_AsciiString aFilename = toAsciiString(theFileName);
        return ReadFile(aFilename.ToCString());
    };

    //! Returns number of roots recognized for transfer
    //! Shortcut for Reader().NbRootsForTransfer()
    Standard_Integer XSTEPCAFControl_Reader::NbRootsForTransfer() {
        return NativeHandle->NbRootsForTransfer();
    };

    //! Translates currently loaded STEP file into the document
    //! Returns True if succeeded, and False in case of fail
    //! Provided for use like single-file reader
    Standard_Boolean XSTEPCAFControl_Reader::TransferOneRoot(const Standard_Integer num, Handle(TDocStd_Document)& doc) {
        return NativeHandle->TransferOneRoot(num, doc);
    };

    //! Translates currently loaded STEP file into the document
    //! Returns True if succeeded, and False in case of fail
    //! Provided for use like single-file reader
    Standard_Boolean XSTEPCAFControl_Reader::Transfer(Handle(TDocStd_Document)& doc) {
        return NativeHandle->Transfer(doc);
    };

    //! Translates currently loaded STEP file into the document
    //! Returns True if succeeded, and False in case of fail
    //! Provided for use like single-file reader
    Standard_Boolean XSTEPCAFControl_Reader::Transfer(XTDocStd_Document^ doc) {
        return NativeHandle->Transfer(doc->GetDocument());
    };

    Standard_Boolean XSTEPCAFControl_Reader::Perform(const TCollection_AsciiString& filename, Handle(TDocStd_Document)& doc) {
        return NativeHandle->Perform(filename, doc);
    };

    //! Translate STEP file given by filename into the document
    //! Return True if succeeded, and False in case of fail
    Standard_Boolean XSTEPCAFControl_Reader::Perform(const Standard_CString filename, Handle(TDocStd_Document)& doc) {
        return NativeHandle->Perform(filename, doc);
    };

    //! Returns data on external files
    //! Returns Null handle if no external files are read
    NCollection_DataMap<TCollection_AsciiString, Handle(STEPCAFControl_ExternFile)> XSTEPCAFControl_Reader::ExternFiles() {
        return NativeHandle->ExternFiles();
    };

    //! Returns data on external file by its name
    //! Returns False if no external file with given name is read
    Standard_Boolean XSTEPCAFControl_Reader::ExternFile(const Standard_CString name, Handle(STEPCAFControl_ExternFile)& ef) {
        return NativeHandle->ExternFile(name, ef);
    };

    //! Returns basic reader
    STEPControl_Reader& XSTEPCAFControl_Reader::ChangeReader() {
        return NativeHandle->ChangeReader();
    };

    //! Returns basic reader as const
    const STEPControl_Reader& XSTEPCAFControl_Reader::Reader() {
        return NativeHandle->Reader();
    };

    //! Returns label of instance of an assembly component
    //! corresponding to a given NAUO
    XTDF_Label^ XSTEPCAFControl_Reader::FindInstance(const Handle(StepRepr_NextAssemblyUsageOccurrence)& NAUO, const Handle(XCAFDoc_ShapeTool)& STool, const STEPConstruct_Tool& Tool, const XCAFDoc_DataMapOfShapeLabel& ShapeLabelMap) {
        return gcnew XTDF_Label(STEPCAFControl_Reader::FindInstance(NAUO, STool, Tool, ShapeLabelMap));
    };

    //! Set ColorMode for indicate read Colors or not.
    void XSTEPCAFControl_Reader::SetColorMode(const Standard_Boolean colormode) {
        NativeHandle->SetColorMode(colormode);
    };

    Standard_Boolean XSTEPCAFControl_Reader::GetColorMode() {
        return NativeHandle->GetColorMode();
    };

    //! Set NameMode for indicate read Name or not.
    void XSTEPCAFControl_Reader::SetNameMode(const Standard_Boolean namemode) {
        NativeHandle->SetNameMode(namemode);
    };

    Standard_Boolean XSTEPCAFControl_Reader::GetNameMode() {
        return NativeHandle->GetNameMode();
    };

    ////! Return the encoding of STEP file for converting names into UNICODE.
    ////! Initialized from "read.stepcaf.codepage" variable by constructor, which is Resource_UTF8 by default.
    //Resource_FormatType XSTEPCAFControl_Reader::SourceCodePage() {
    //    return NativeHandle->SourceCodePage();
    //};

    ////! Return the encoding of STEP file for converting names into UNICODE.
    //void XSTEPCAFControl_Reader::SetSourceCodePage(Resource_FormatType theCode) {
    //    NativeHandle->SetSourceCodePage(theCode);
    //};

    //! Set LayerMode for indicate read Layers or not.
    void XSTEPCAFControl_Reader::SetLayerMode(const Standard_Boolean layermode) {
        NativeHandle->SetLayerMode(layermode);
    };

    Standard_Boolean XSTEPCAFControl_Reader::GetLayerMode() {
        return NativeHandle->GetLayerMode();
    };

    //! PropsMode for indicate read Validation properties or not.
    void XSTEPCAFControl_Reader::SetPropsMode(const Standard_Boolean propsmode) {
        NativeHandle->SetPropsMode(propsmode);
    };

    Standard_Boolean XSTEPCAFControl_Reader::GetPropsMode() {
        return NativeHandle->GetPropsMode();
    };

    //! Set SHUO mode for indicate write SHUO or not.
    void XSTEPCAFControl_Reader::SetSHUOMode(const Standard_Boolean shuomode) {
        NativeHandle->SetSHUOMode(shuomode);
    };

    Standard_Boolean XSTEPCAFControl_Reader::GetSHUOMode() {
        return NativeHandle->GetSHUOMode();
    };

    //! Set GDT mode for indicate write GDT or not.
    void XSTEPCAFControl_Reader::SetGDTMode(const Standard_Boolean gdtmode) {
        NativeHandle->SetGDTMode(gdtmode);
    };

    Standard_Boolean XSTEPCAFControl_Reader::GetGDTMode() {
        return NativeHandle->GetGDTMode();
    };

    //! Set Material mode
    void XSTEPCAFControl_Reader::SetMatMode(const Standard_Boolean matmode) {
        NativeHandle->SetMatMode(matmode);
    };

    Standard_Boolean XSTEPCAFControl_Reader::GetMatMode() {
        return NativeHandle->GetMatMode();
    };

    //! Set View mode
    void XSTEPCAFControl_Reader::SetViewMode(const Standard_Boolean viewmode) {
        NativeHandle->SetViewMode(viewmode);
    };

    //! Get View mode
    Standard_Boolean XSTEPCAFControl_Reader::GetViewMode() {
        return NativeHandle->GetViewMode();
    };
}