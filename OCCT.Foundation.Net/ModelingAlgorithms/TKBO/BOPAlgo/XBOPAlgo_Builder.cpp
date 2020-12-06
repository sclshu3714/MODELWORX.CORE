#include <XBOPAlgo_Builder.h>
namespace TKBO {
    //! Empty constructor.
    XBOPAlgo_Builder::XBOPAlgo_Builder() {
        NativeHandle = new BOPAlgo_Builder();
    };
    XBOPAlgo_Builder::~XBOPAlgo_Builder() {
        NativeHandle->~BOPAlgo_Builder();
        NativeHandle = NULL;
    };

    XBOPAlgo_Builder::XBOPAlgo_Builder(Handle(NCollection_BaseAllocator)& theAllocator) {
        NativeHandle = new BOPAlgo_Builder(theAllocator);
    };

    XBOPAlgo_Builder::XBOPAlgo_Builder(BOPAlgo_Builder* pos) {
        NativeHandle = pos;
    };

    void XBOPAlgo_Builder::SetAlgoBuilderHandle(BOPAlgo_Builder* pos) {
        NativeHandle = pos;
    };

    BOPAlgo_Builder* XBOPAlgo_Builder::GetAlgoBuilder() {
        return NativeHandle;
    };

    //! Clears the content of the algorithm.
    void XBOPAlgo_Builder::Clear() {
        NativeHandle->Clear();
    };// Standard_OVERRIDE;

    ////! Returns the PaveFiller, algorithm for sub-shapes intersection.
    //XBOPAlgo_PaveFiller^ XBOPAlgo_Builder::PPaveFiller() {
    //    BOPAlgo_PaveFiller* temp = new BOPAlgo_PaveFiller(*NativeHandle->PPaveFiller());
    //    return gcnew XBOPAlgo_PaveFiller(temp);
    //};

    //! Returns the Data Structure, holder of intersection information.
    BOPDS_PDS XBOPAlgo_Builder::PDS() {
        return NativeHandle->PDS();
    };

    //! Returns the Context, tool for cashing heavy algorithms.
    Handle(IntTools_Context) XBOPAlgo_Builder::Context() {
        return NativeHandle->Context();
    };

    //! @name Arguments

    //! Adds the argument to the operation.
    void XBOPAlgo_Builder::AddArgument(XTopoDS_Shape^ theShape) {
        return NativeHandle->AddArgument(*theShape->GetShape());
    };

    //! Sets the list of arguments for the operation.
    void XBOPAlgo_Builder::SetArguments(XTopTools_ListOfShape^ theLS) {
        NativeHandle->SetArguments(*theLS->GetListOfShapes());
    };

    //! Returns the list of arguments.
    XTopTools_ListOfShape^ XBOPAlgo_Builder::Arguments() {
        TopTools_ListOfShape* temp = new TopTools_ListOfShape(NativeHandle->Arguments());
        return gcnew XTopTools_ListOfShape(temp);
    };
    //! @name Options

    //! Sets the flag that defines the mode of treatment.
    //! In non-destructive mode the argument shapes are not modified. Instead
    //! a copy of a sub-shape is created in the result if it is needed to be updated.
    //! This flag is taken into account if internal PaveFiller is used only.
    //! In the case of calling PerformWithFiller the corresponding flag of that PaveFiller
    //! is in force.
    void XBOPAlgo_Builder::SetNonDestructive(Standard_Boolean theFlag) {
        NativeHandle->SetNonDestructive(theFlag);
    };

    //! Returns the flag that defines the mode of treatment.
    //! In non-destructive mode the argument shapes are not modified. Instead
    //! a copy of a sub-shape is created in the result if it is needed to be updated.
    Standard_Boolean XBOPAlgo_Builder::NonDestructive() {
        return NativeHandle->NonDestructive();
    };

    //! Sets the glue option for the algorithm
    void XBOPAlgo_Builder::SetGlue(XBOPAlgo_GlueEnum theGlue) {
        return NativeHandle->SetGlue(safe_cast<BOPAlgo_GlueEnum>(theGlue));
    };

    //! Returns the glue option of the algorithm
    XBOPAlgo_GlueEnum XBOPAlgo_Builder::Glue() {
        return safe_cast<XBOPAlgo_GlueEnum>(NativeHandle->Glue());
    };

    //! Enables/Disables the check of the input solids for inverted status
    void XBOPAlgo_Builder::SetCheckInverted(Standard_Boolean theCheck) {
        NativeHandle->SetCheckInverted(theCheck);
    };

    //! Returns the flag defining whether the check for input solids on inverted status
    //! should be performed or not.
    Standard_Boolean XBOPAlgo_Builder::CheckInverted() {
        return NativeHandle->CheckInverted();
    };


    //! @name Performing the operation

    //! Performs the operation.
    //! The intersection will be performed also.
    void XBOPAlgo_Builder::Perform() {
        NativeHandle->Perform();
    }; //Standard_OVERRIDE;

    //! Performs the operation with the prepared filler.
    //! The intersection will not be performed in this case.
    void XBOPAlgo_Builder::PerformWithFiller(XBOPAlgo_PaveFiller^ theFiller) {
        NativeHandle->PerformWithFiller(*theFiller->GetPaveFiller());
    };


    //! @name BOPs on open solids

    //! Builds the result shape according to the given states for the objects
    //! and tools. These states can be unambiguously converted into the Boolean operation type.
    //! Thus, it performs the Boolean operation on the given groups of shapes.
    //!
    //! The result is built basing on the result of Builder operation (GF or any other).
    //! The only condition for the Builder is that the splits of faces should be created
    //! and classified relatively solids.
    //!
      //! The method uses classification approach for choosing the faces which will
      //! participate in building the result shape:
      //! - All faces from each group having the given state for the opposite group
      //!   will be taken into result.
      //!
      //! Such approach shows better results (in comparison with BOPAlgo_BuilderSolid approach)
      //! when working with open solids. However, the result may not be always
      //! correct on such data (at least, not as expected) as the correct classification
      //! of the faces relatively open solids is not always possible and may vary
      //! depending on the chosen classification point on the face.
      //!
      //! History is not created for the solids in this method.
      //!
      //! To avoid pollution of the report of Builder algorithm, there is a possibility to pass
      //! the different report to collect the alerts of the method only. But, if the new report
      //! is not given, the Builder report will be used.
      //! So, even if Builder passed without any errors, but some error has been stored into its report
      //! in this method, for the following calls the Builder report must be cleared.
      //!
      //! The method may set the following errors:
      //! - BOPAlgo_AlertBuilderFailed - Building operation has not been performed yet or failed;
      //! - BOPAlgo_AlertBOPNotSet - invalid BOP type is given (COMMON/FUSE/CUT/CUT21 are supported);
      //! - BOPAlgo_AlertTooFewArguments - arguments are not given;
      //! - BOPAlgo_AlertUnknownShape - the shape is unknown for the operation.
      //!
      //! Parameters:
      //! @param theObjects   - The group of Objects for BOP;
      //! @param theObjState  - State for objects faces to pass into result;
      //! @param theTools     - The group of Tools for BOP;
      //! @param theObjState  - State for tools faces to pass into result;
      //! @param theReport    - The alternative report to avoid pollution of the main one.
      //! Handle(Message_Report)      theReport = NULL
    void XBOPAlgo_Builder::BuildBOP(XTopTools_ListOfShape^ theObjects, XTopAbs_State theObjState, XTopTools_ListOfShape^ theTools, XTopAbs_State theToolsState, Handle(Message_Report) theReport) {
        NativeHandle->BuildBOP(*theObjects->GetListOfShapes(), safe_cast<TopAbs_State>(theObjState), *theTools->GetListOfShapes(), safe_cast<TopAbs_State>(theToolsState), theReport);
    };

    //! Builds the result of Boolean operation of given type
    //! basing on the result of Builder operation (GF or any other).
    //!
    //! The method converts the given type of operation into the states
    //! for the objects and tools required for their face to pass into result
    //! and performs the call to the same method, but with states instead
    //! of operation type.
    //!
    //! The conversion looks as follows:
    //! - COMMON is built from the faces of objects located IN any of the tools
    //!          and vice versa.
    //! - FUSE   is built from the faces OUT of all given shapes;
    //! - CUT    is built from the faces of the objects OUT of the tools and
    //!          faces of the tools located IN solids of the objects.
    //!
    //! @param theObjects   - The group of Objects for BOP;
    //! @param theTools     - The group of Tools for BOP;
    //! @param theOperation - The BOP type;
    //! @param theReport    - The alternative report to avoid pollution of the global one.
    //! Handle(Message_Report)      theReport = NULL
    void XBOPAlgo_Builder::BuildBOP(XTopTools_ListOfShape^ theObjects, XTopTools_ListOfShape^ theTools, XBOPAlgo_Operation theOperation, Handle(Message_Report) theReport) {
        NativeHandle->BuildBOP(*theObjects->GetListOfShapes(), *theTools->GetListOfShapes(), safe_cast<BOPAlgo_Operation>(theOperation), theReport);
    };
}