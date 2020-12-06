#include <XBOPAlgo_Options.h>

namespace TKBO {

    //! Empty constructor
    XBOPAlgo_Options::XBOPAlgo_Options() {
        NativeHandle = new BOPAlgo_Options();
    };

    //! Constructor with allocator
    XBOPAlgo_Options::XBOPAlgo_Options(const Handle(NCollection_BaseAllocator)& theAllocator) {
        NativeHandle = new BOPAlgo_Options(theAllocator);
    };

    void XBOPAlgo_Options::SetAlgoOptionsHandle(BOPAlgo_Options* pos) {
        NativeHandle = pos;
    };

    BOPAlgo_Options* XBOPAlgo_Options::GetOptions() {
        return NativeHandle;
    };

    //! Destructor
    XBOPAlgo_Options::~XBOPAlgo_Options() {
        if (NativeHandle != NULL)
            delete NativeHandle;
        NativeHandle = NULL;
    };

    //! Returns allocator
    const Handle(NCollection_BaseAllocator)& XBOPAlgo_Options::Allocator() {
        return NativeHandle->Allocator();
    };

    //! Clears all warnings and errors, and any data cached by the algorithm.
    //! User defined options are not cleared.
    void XBOPAlgo_Options::Clear() {
        NativeHandle->Clear();
    };

    //!@name Error reporting mechanism

    //! Adds the alert as error (fail)
    void XBOPAlgo_Options::AddError(const Handle(Message_Alert)& theAlert) {
        NativeHandle->AddError(theAlert);
    };

    //! Adds the alert as warning
    void XBOPAlgo_Options::AddWarning(const Handle(Message_Alert)& theAlert) {
        NativeHandle->AddWarning(theAlert);
    };

    //! Returns true if algorithm has failed
    Standard_Boolean XBOPAlgo_Options::HasErrors() {
        return NativeHandle->HasErrors();
    };

    //! Returns true if algorithm has generated error of specified type
    Standard_Boolean XBOPAlgo_Options::HasError(const Handle(Standard_Type)& theType) {
        return NativeHandle->HasError(theType);
    };

    //! Returns true if algorithm has generated some warning alerts
    Standard_Boolean XBOPAlgo_Options::HasWarnings() {
        return NativeHandle->HasWarnings();
    };

    //! Returns true if algorithm has generated warning of specified type
    Standard_Boolean XBOPAlgo_Options::HasWarning(const Handle(Standard_Type)& theType) {
        return NativeHandle->HasWarning(theType);
    };

    //! Returns report collecting all errors and warnings
    const Handle(Message_Report)& XBOPAlgo_Options::GetReport() {
        return NativeHandle->GetReport();
    };

    //! Dumps the error status into the given stream
    void XBOPAlgo_Options::DumpErrors(Standard_OStream& theOS) {
        NativeHandle->DumpErrors(theOS);
    };

    //! Dumps the warning statuses into the given stream
    void XBOPAlgo_Options::DumpWarnings(Standard_OStream& theOS) {
        NativeHandle->DumpWarnings(theOS);
    };

    //! Clears the warnings of the algorithm
    void XBOPAlgo_Options::ClearWarnings() {
        NativeHandle->ClearWarnings();
    };

    //!@name Parallel processing mode

    //! Gets the global parallel mode
    //!static 
    Standard_Boolean XBOPAlgo_Options::GetParallelMode() {
        return BOPAlgo_Options::GetParallelMode();
    };

    //! Sets the global parallel mode
    //! static 
    void XBOPAlgo_Options::SetParallelMode(Standard_Boolean theNewMode) {
        BOPAlgo_Options::SetParallelMode(theNewMode);
    };

    //! Set the flag of parallel processing
    //! if <theFlag> is true  the parallel processing is switched on
    //! if <theFlag> is false the parallel processing is switched off
    void XBOPAlgo_Options::SetRunParallel(Standard_Boolean theFlag) {
        NativeHandle->SetRunParallel(theFlag);
    };

    //! Returns the flag of parallel processing
    Standard_Boolean XBOPAlgo_Options::RunParallel() {
        return  NativeHandle->RunParallel();
    };

    //!@name Fuzzy tolerance

    //! Sets the additional tolerance
    void XBOPAlgo_Options::SetFuzzyValue(Standard_Real theFuzz) {
        NativeHandle->SetFuzzyValue(theFuzz);
    };

    //! Returns the additional tolerance
    Standard_Real XBOPAlgo_Options::FuzzyValue() {
        return  NativeHandle->FuzzyValue();
    };
    //!@name Progress indicator

    //! Set the Progress Indicator object.
    void XBOPAlgo_Options::SetProgressIndicator(const Handle(Message_ProgressIndicator)& theObj) {
        NativeHandle->SetProgressIndicator(theObj);
    };

    //!@name Usage of Oriented Bounding boxes

    //! Enables/Disables the usage of OBB
    void XBOPAlgo_Options::SetUseOBB(Standard_Boolean theUseOBB) {
        NativeHandle->SetUseOBB(theUseOBB);
    };

    //! Returns the flag defining usage of OBB
    Standard_Boolean XBOPAlgo_Options::UseOBB() {
        return  NativeHandle->UseOBB();
    };
}