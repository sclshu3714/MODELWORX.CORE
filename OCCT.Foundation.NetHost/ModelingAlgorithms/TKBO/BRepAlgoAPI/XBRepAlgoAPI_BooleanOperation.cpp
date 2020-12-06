#include <XBRepAlgoAPI_BooleanOperation.h>

namespace TKBO {

    //! Empty constructor
    XBRepAlgoAPI_BooleanOperation::XBRepAlgoAPI_BooleanOperation() {
        NativeHandle = new BRepAlgoAPI_BooleanOperation();
        SetBuilderAlgoHandle(NativeHandle);
    };

    //! Constructor with precomputed intersections of arguments.
    XBRepAlgoAPI_BooleanOperation::XBRepAlgoAPI_BooleanOperation(XBOPAlgo_PaveFiller^ thePF) {
        NativeHandle = new BRepAlgoAPI_BooleanOperation(*thePF->GetPaveFiller());
        SetBuilderAlgoHandle(NativeHandle);
    };

    XBRepAlgoAPI_BooleanOperation::XBRepAlgoAPI_BooleanOperation(BRepAlgoAPI_BooleanOperation* pos) {
        NativeHandle = pos;
        SetBuilderAlgoHandle(NativeHandle);
    };

    void XBRepAlgoAPI_BooleanOperation::SetBooleanOperationHandle(BRepAlgoAPI_BooleanOperation* pos) {
        NativeHandle = pos;
        SetBuilderAlgoHandle(NativeHandle);
    };

    BRepAlgoAPI_BooleanOperation* XBRepAlgoAPI_BooleanOperation::GetBooleanOperation() {
        return NativeHandle;
    };

    BRepAlgoAPI_BuilderAlgo* XBRepAlgoAPI_BooleanOperation::GetBuilderAlgo() {
        return NativeHandle;
    };

    //! @name Setting/getting arguments
    XTopoDS_Shape^ XBRepAlgoAPI_BooleanOperation::Shape() {
        TopoDS_Shape* temp = new TopoDS_Shape(NativeHandle->Shape());
        return gcnew XTopoDS_Shape(temp);
    };

    //! Returns the first argument involved in this Boolean operation.
    //! Obsolete
    XTopoDS_Shape^ XBRepAlgoAPI_BooleanOperation::Shape1() {
        TopoDS_Shape* temp = new TopoDS_Shape(NativeHandle->Shape1());
        return gcnew XTopoDS_Shape(temp);
    };

    //! Returns the second argument involved in this Boolean operation.
    //! Obsolete
    XTopoDS_Shape^ XBRepAlgoAPI_BooleanOperation::Shape2() {
        TopoDS_Shape* temp = new TopoDS_Shape(NativeHandle->Shape2());
        return gcnew XTopoDS_Shape(temp);
    };

    //! Sets the Tool arguments
    void XBRepAlgoAPI_BooleanOperation::SetTools(XTopTools_ListOfShape^ theLS) {
        NativeHandle->SetTools(*theLS->GetListOfShapes());
    };

    //! Returns the Tools arguments
    XTopTools_ListOfShape^ XBRepAlgoAPI_BooleanOperation::Tools() {
        TopTools_ListOfShape* temp = new TopTools_ListOfShape(NativeHandle->Tools());
        return gcnew XTopTools_ListOfShape(temp);
    };


    //! @name Setting/Getting the type of Boolean operation

     //! Sets the type of Boolean operation
    void XBRepAlgoAPI_BooleanOperation::SetOperation(XBOPAlgo_Operation theBOP) {
        NativeHandle->SetOperation(safe_cast<BOPAlgo_Operation>(theBOP));
    };

    //! Returns the type of Boolean Operation
    XBOPAlgo_Operation XBRepAlgoAPI_BooleanOperation::Operation() {
        return safe_cast<XBOPAlgo_Operation>(NativeHandle->Operation());
    };


    //! @name Performing the operation

    //! Performs the Boolean operation.
    void XBRepAlgoAPI_BooleanOperation::Build() {
        NativeHandle->Build();
    };
}