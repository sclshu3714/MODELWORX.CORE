#include <XBRepAlgoAPI_Algo.h>

namespace TKBO {
    //! Empty constructor
    XBRepAlgoAPI_Algo::XBRepAlgoAPI_Algo() {
        //NativeHandle = new BRepAlgoAPI_Algo();
    };

    //! Destructor
    XBRepAlgoAPI_Algo::~XBRepAlgoAPI_Algo() {
        NativeHandle = NULL;
        SetMakeShapeHandle(NativeHandle);
    };

    void XBRepAlgoAPI_Algo::SetAlgoHandle(BRepAlgoAPI_Algo* pos) {
        NativeHandle = pos;
        SetMakeShapeHandle(NativeHandle);
    };

    BRepAlgoAPI_Algo* XBRepAlgoAPI_Algo::GetAlgo() {
        return NativeHandle;
    };

    //! DEFINE_STANDARD_ALLOC

    XTopoDS_Shape^ XBRepAlgoAPI_Algo::Shape() {

    };

    BRepBuilderAPI_MakeShape* XBRepAlgoAPI_Algo::GetMakeShape() {
        return NativeHandle;
    };

    //! Clears all warnings and errors, and any data cached by the algorithm.
    //! User defined options are not cleared.
    void XBRepAlgoAPI_Algo::Clear() {
        NativeHandle->Clear();
    };

    //!@name Error reporting mechanism

    //! Adds the alert as error (fail)
    void XBRepAlgoAPI_Algo::AddError(Handle(Message_Alert)& theAlert) {
        NativeHandle->AddError(theAlert);
    };

    //! Adds the alert as warning
    void XBRepAlgoAPI_Algo::AddWarning(Handle(Message_Alert)& theAlert) {
        NativeHandle->AddWarning(theAlert);
    };

    //! Returns true if algorithm has failed
    Standard_Boolean XBRepAlgoAPI_Algo::HasErrors() {
        return NativeHandle->HasErrors();
    };

    //! Returns true if algorithm has generated error of specified type
    Standard_Boolean XBRepAlgoAPI_Algo::HasError(Handle(Standard_Type)& theType) {
        return NativeHandle->HasError(theType);
    };

    //! Returns true if algorithm has generated some warning alerts
    Standard_Boolean XBRepAlgoAPI_Algo::HasWarnings() {
        return NativeHandle->HasWarnings();
    };

    //! Returns true if algorithm has generated warning of specified type
    Standard_Boolean XBRepAlgoAPI_Algo::HasWarning(Handle(Standard_Type)& theType) {
        return NativeHandle->HasWarning(theType);
    };

    //! Returns report collecting all errors and warnings
    const Handle(Message_Report)& XBRepAlgoAPI_Algo::GetReport() {
        return NativeHandle->GetReport();
    };

    //! Dumps the error status into the given stream
    void XBRepAlgoAPI_Algo::DumpErrors(Standard_OStream& theOS) {
        NativeHandle->DumpErrors(theOS);
    };

    //! Dumps the warning statuses into the given stream
    void XBRepAlgoAPI_Algo::DumpWarnings(Standard_OStream& theOS) {
        NativeHandle->DumpWarnings(theOS);
    };

    //! Clears the warnings of the algorithm
    void XBRepAlgoAPI_Algo::ClearWarnings() {
        NativeHandle->ClearWarnings();
    };

    //!@name Parallel processing mode

    //! Gets the global parallel mode
    //!static 
    Standard_Boolean XBRepAlgoAPI_Algo::GetParallelMode() {
        return BOPAlgo_Options::GetParallelMode();
    };

    //! Sets the global parallel mode
    //! static 
    void XBRepAlgoAPI_Algo::SetParallelMode(Standard_Boolean theNewMode) {
        BOPAlgo_Options::SetParallelMode(theNewMode);
    };

    //! Set the flag of parallel processing
    //! if <theFlag> is true  the parallel processing is switched on
    //! if <theFlag> is false the parallel processing is switched off
    void XBRepAlgoAPI_Algo::SetRunParallel(Standard_Boolean theFlag) {
        NativeHandle->SetRunParallel(theFlag);
    };

    //! Returns the flag of parallel processing
    Standard_Boolean XBRepAlgoAPI_Algo::RunParallel() {
        return  NativeHandle->RunParallel();
    };

    //!@name Fuzzy tolerance

    //! Sets the additional tolerance
    void XBRepAlgoAPI_Algo::SetFuzzyValue(Standard_Real theFuzz) {
        NativeHandle->SetFuzzyValue(theFuzz);
    };

    //! Returns the additional tolerance
    Standard_Real XBRepAlgoAPI_Algo::FuzzyValue() {
        return  NativeHandle->FuzzyValue();
    };
    //!@name Progress indicator

    //! Set the Progress Indicator object.
    void XBRepAlgoAPI_Algo::SetProgressIndicator(Handle(Message_ProgressIndicator)& theObj) {
        NativeHandle->SetProgressIndicator(theObj);
    };

    //!@name Usage of Oriented Bounding boxes

    //! Enables/Disables the usage of OBB
    void XBRepAlgoAPI_Algo::SetUseOBB(Standard_Boolean theUseOBB) {
        NativeHandle->SetUseOBB(theUseOBB);
    };

    //! Returns the flag defining usage of OBB
    Standard_Boolean XBRepAlgoAPI_Algo::UseOBB() {
        return  NativeHandle->UseOBB();
    };
}
