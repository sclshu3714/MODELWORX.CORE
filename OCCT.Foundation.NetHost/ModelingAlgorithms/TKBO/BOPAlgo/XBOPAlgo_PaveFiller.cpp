#include <XBOPAlgo_PaveFiller.h>
namespace TKBO {

    XBOPAlgo_PaveFiller::XBOPAlgo_PaveFiller() {
        NativeHandle = new BOPAlgo_PaveFiller();
    };

    XBOPAlgo_PaveFiller::~XBOPAlgo_PaveFiller() {
        NativeHandle->~BOPAlgo_PaveFiller();
    };

    XBOPAlgo_PaveFiller::XBOPAlgo_PaveFiller(Handle(NCollection_BaseAllocator) theAllocator) {
        NativeHandle = new BOPAlgo_PaveFiller(theAllocator);
    };

    XBOPAlgo_PaveFiller::XBOPAlgo_PaveFiller(BOPAlgo_PaveFiller* pos) {
        NativeHandle = pos;
    };

    void XBOPAlgo_PaveFiller::SetPaveFillerHandle(BOPAlgo_PaveFiller* pos) {
        NativeHandle = pos;
    };

    BOPAlgo_PaveFiller* XBOPAlgo_PaveFiller::GetPaveFiller() {
        return NativeHandle;
    };

    const BOPDS_DS& XBOPAlgo_PaveFiller::DS() {
        return NativeHandle->DS();
    };

    BOPDS_PDS XBOPAlgo_PaveFiller::PDS() {
        return NativeHandle->PDS();
    };

   /* const BOPDS_PIterator& XBOPAlgo_PaveFiller::Iterator() {
        return NativeHandle->Iterator();
    };*/

    //! Sets the arguments for operation
    void XBOPAlgo_PaveFiller::SetArguments(XTopTools_ListOfShape^ theLS) {
        TopTools_ListOfShape temp(*theLS->GetListOfShapes());
        NativeHandle->SetArguments(temp);
    };

    //! Adds the argument for operation
    void XBOPAlgo_PaveFiller::AddArgument(XTopoDS_Shape^ theShape) {
        NativeHandle->AddArgument(*theShape->GetShape());
    };

    //! Returns the list of arguments
    XTopTools_ListOfShape^ XBOPAlgo_PaveFiller::Arguments() {
        TopTools_ListOfShape* temp = new TopTools_ListOfShape(NativeHandle->Arguments());
        return gcnew XTopTools_ListOfShape(temp);
    };

    Handle(IntTools_Context) XBOPAlgo_PaveFiller::Context() {
        return NativeHandle->Context();
    };

    void XBOPAlgo_PaveFiller::SetSectionAttribute(BOPAlgo_SectionAttribute theSecAttr) {
        NativeHandle->SetSectionAttribute(theSecAttr);
    };

    //! Sets the flag that defines the mode of treatment.
    //! In non-destructive mode the argument shapes are not modified. Instead
    //! a copy of a sub-shape is created in the result if it is needed to be updated.
    void XBOPAlgo_PaveFiller::SetNonDestructive(Standard_Boolean theFlag) {
        NativeHandle->SetNonDestructive(theFlag);
    };

    //! Returns the flag that defines the mode of treatment.
    //! In non-destructive mode the argument shapes are not modified. Instead
    //! a copy of a sub-shape is created in the result if it is needed to be updated.
    Standard_Boolean XBOPAlgo_PaveFiller::NonDestructive() {
        return NativeHandle->NonDestructive();
    };

    void XBOPAlgo_PaveFiller::Perform() {
        NativeHandle->Perform();
    };

    //! Sets the glue option for the algorithm
    void XBOPAlgo_PaveFiller::SetGlue(XBOPAlgo_GlueEnum theGlue) {
        NativeHandle->SetGlue(safe_cast<BOPAlgo_GlueEnum>(theGlue));
    };

    //! Returns the glue option of the algorithm
    XBOPAlgo_GlueEnum XBOPAlgo_PaveFiller::Glue() {
        return safe_cast<XBOPAlgo_GlueEnum>(NativeHandle->Glue());
    };

    //! Sets the flag to avoid building of p-curves of edges on faces
    void XBOPAlgo_PaveFiller::SetAvoidBuildPCurve(Standard_Boolean theValue) {
        NativeHandle->SetAvoidBuildPCurve(theValue);
    };

    //! Returns the flag to avoid building of p-curves of edges on faces
    Standard_Boolean XBOPAlgo_PaveFiller::IsAvoidBuildPCurve() {
        return NativeHandle->IsAvoidBuildPCurve();
    };
}