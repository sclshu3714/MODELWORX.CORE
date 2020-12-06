#include <XBRepAlgoAPI_BuilderAlgo.h>
namespace TKBO {
    //! Empty constructor
    XBRepAlgoAPI_BuilderAlgo::XBRepAlgoAPI_BuilderAlgo() {
        NativeHandle = new BRepAlgoAPI_BuilderAlgo();
    };
    XBRepAlgoAPI_BuilderAlgo::~XBRepAlgoAPI_BuilderAlgo() {
        NativeHandle->~BRepAlgoAPI_BuilderAlgo();
        NativeHandle = NULL;
    };

    //! Constructor with prepared Filler object
    XBRepAlgoAPI_BuilderAlgo::XBRepAlgoAPI_BuilderAlgo(XBOPAlgo_PaveFiller^ thePF) {
        NativeHandle = new BRepAlgoAPI_BuilderAlgo(*thePF->GetPaveFiller());
    };

    XBRepAlgoAPI_BuilderAlgo::XBRepAlgoAPI_BuilderAlgo(BRepAlgoAPI_BuilderAlgo* pos) {
        NativeHandle = pos;
    };

    void XBRepAlgoAPI_BuilderAlgo::SetBuilderAlgoHandle(BRepAlgoAPI_BuilderAlgo* pos) {
        NativeHandle = pos;
    };

    BRepAlgoAPI_BuilderAlgo* XBRepAlgoAPI_BuilderAlgo::GetBuilderAlgo() {
        return NativeHandle;
    };

    XTopoDS_Shape^ XBRepAlgoAPI_BuilderAlgo::Shape() {
        TopoDS_Shape* temp = new TopoDS_Shape(NativeHandle->Shape());
        return gcnew XTopoDS_Shape(temp);
    };

    //! @name Setting/Getting data for the algorithm

    //! Sets the arguments
    void XBRepAlgoAPI_BuilderAlgo::SetArguments(XTopTools_ListOfShape^ theLS) {
        NativeHandle->SetArguments(*theLS->GetListOfShapes());
    };

    //! Gets the arguments
    XTopTools_ListOfShape^ XBRepAlgoAPI_BuilderAlgo::Arguments() {
        TopTools_ListOfShape* temp = new TopTools_ListOfShape(NativeHandle->Arguments());
        return gcnew XTopTools_ListOfShape(temp);
    };


    //! @name Setting options

    //! Sets the flag that defines the mode of treatment.
    //! In non-destructive mode the argument shapes are not modified. Instead
    //! a copy of a sub-shape is created in the result if it is needed to be updated.
    void XBRepAlgoAPI_BuilderAlgo::SetNonDestructive(Standard_Boolean theFlag) {
        NativeHandle->SetNonDestructive(theFlag);
    };

    //! Returns the flag that defines the mode of treatment.
    //! In non-destructive mode the argument shapes are not modified. Instead
    //! a copy of a sub-shape is created in the result if it is needed to be updated.
    Standard_Boolean XBRepAlgoAPI_BuilderAlgo::NonDestructive() {
        return  NativeHandle->NonDestructive();
    };

    //! Sets the glue option for the algorithm,
    //! which allows increasing performance of the intersection
    //! of the input shapes.
    void XBRepAlgoAPI_BuilderAlgo::SetGlue(XBOPAlgo_GlueEnum theGlue) {
        NativeHandle->SetGlue(safe_cast<BOPAlgo_GlueEnum>(theGlue));
    };

    //! Returns the glue option of the algorithm
    XBOPAlgo_GlueEnum XBRepAlgoAPI_BuilderAlgo::Glue() {
        return safe_cast<XBOPAlgo_GlueEnum>(NativeHandle->Glue());
    };

    //! Enables/Disables the check of the input solids for inverted status
    void XBRepAlgoAPI_BuilderAlgo::SetCheckInverted(Standard_Boolean theCheck) {
        NativeHandle->SetCheckInverted(theCheck);
    };

    //! Returns the flag defining whether the check for input solids on inverted status
    //! should be performed or not.
    Standard_Boolean XBRepAlgoAPI_BuilderAlgo::CheckInverted() {
        return NativeHandle->CheckInverted();
    };


    //! @name Performing the operation

    //! Performs the algorithm
    void XBRepAlgoAPI_BuilderAlgo::Build() {
        NativeHandle->Build();
    };// Standard_OVERRIDE;


    //! @name Result simplification

    //! Simplification of the result shape is performed by the means of
    //! *ShapeUpgrade_UnifySameDomain* algorithm. The result of the operation will
    //! be overwritten with the simplified result.
    //!
    //! The simplification is performed without creation of the Internal shapes,
    //! i.e. shapes connections will never be broken.
    //!
    //! Simplification is performed on the whole result shape. Thus, if the input
    //! shapes contained connected tangent edges or faces unmodified during the operation
    //! they will also be unified.
    //!
    //! After simplification, the History of result simplification is merged into the main
    //! history of operation. So, it is taken into account when asking for Modified,
    //! Generated and Deleted shapes.
    //!
    //! Some options of the main operation are passed into the Unifier:
    //! - Fuzzy tolerance of the operation is given to the Unifier as the linear tolerance.
    //! - Non destructive mode here controls the safe input mode in Unifier.
    //!
    //! @param theUnifyEdges Controls the edges unification. TRUE by default.
    //! @param theUnifyFaces Controls the faces unification. TRUE by default.
    //! @param theAngularTol Angular criteria for tangency of edges and faces.
    //!                      Precision::Angular() by default.
    //!Standard_Boolean theUnifyEdges = Standard_True,Standard_Boolean theUnifyFaces = Standard_True,Standard_Real    theAngularTol = Precision::Angular()
    void XBRepAlgoAPI_BuilderAlgo::SimplifyResult(Standard_Boolean theUnifyEdges, Standard_Boolean theUnifyFaces, Standard_Real theAngularTol) {
        NativeHandle->SimplifyResult(theUnifyEdges, theUnifyFaces, theAngularTol);
    };


    //! @name History support

    //! Returns the shapes modified from the shape <theS>.
    //! If any, the list will contain only those splits of the
    //! given shape, contained in the result.
    XTopTools_ListOfShape^ XBRepAlgoAPI_BuilderAlgo::Modified(XTopoDS_Shape^ theS) {
        TopTools_ListOfShape* temp = new TopTools_ListOfShape(NativeHandle->Modified(*theS->GetShape()));
        return gcnew XTopTools_ListOfShape(temp);
    };// Standard_OVERRIDE;

    //! Returns the list  of shapes generated from the shape <theS>.
    //! In frames of Boolean Operations algorithms only Edges and Faces
    //! could have Generated elements, as only they produce new elements
    //! during intersection:
    //! - Edges can generate new vertices;
    //! - Faces can generate new edges and vertices.
    XTopTools_ListOfShape^ XBRepAlgoAPI_BuilderAlgo::Generated(XTopoDS_Shape^ theS) {
        TopTools_ListOfShape* temp = new TopTools_ListOfShape(NativeHandle->Generated(*theS->GetShape()));
        return gcnew XTopTools_ListOfShape(temp);
    };// Standard_OVERRIDE;

    //! Checks if the shape <theS> has been completely removed from the result,
    //! i.e. the result does not contain the shape itself and any of its splits.
    //! Returns TRUE if the shape has been deleted.
    Standard_Boolean XBRepAlgoAPI_BuilderAlgo::IsDeleted(XTopoDS_Shape^ aS) {
        return NativeHandle->IsDeleted(*aS->GetShape());
    };//Standard_OVERRIDE;

    //! Returns true if any of the input shapes has been modified during operation.
    Standard_Boolean XBRepAlgoAPI_BuilderAlgo::HasModified() {
        return NativeHandle->HasModified();
    };

    //! Returns true if any of the input shapes has generated shapes during operation.
    Standard_Boolean XBRepAlgoAPI_BuilderAlgo::HasGenerated() {
        return NativeHandle->HasGenerated();
    };

    //! Returns true if any of the input shapes has been deleted during operation.
    //! Normally, General Fuse operation should not have Deleted elements,
    //! but all derived operation can have.
    Standard_Boolean XBRepAlgoAPI_BuilderAlgo::HasDeleted() {
        return NativeHandle->HasDeleted();
    };


    //! @name Enabling/Disabling the history collection.

    //! Allows disabling the history collection
    void XBRepAlgoAPI_BuilderAlgo::SetToFillHistory(Standard_Boolean theHistFlag) {
        NativeHandle->SetToFillHistory(theHistFlag);
    };

    //! Returns flag of history availability
    Standard_Boolean XBRepAlgoAPI_BuilderAlgo::HasHistory() {
        return NativeHandle->HasHistory();
    };


    //! @name Getting the section edges

    //! Returns a list of section edges.
    //! The edges represent the result of intersection between arguments of operation.
    XTopTools_ListOfShape^ XBRepAlgoAPI_BuilderAlgo::SectionEdges() {
        TopTools_ListOfShape* temp = new TopTools_ListOfShape(NativeHandle->SectionEdges());
        return gcnew XTopTools_ListOfShape(temp);
    };


    //! @name Getting tools performing the job

    //! Returns the Intersection tool
    XBOPAlgo_PaveFiller^ XBRepAlgoAPI_BuilderAlgo::DSFiller() {
        BOPAlgo_PaveFiller* temp = new BOPAlgo_PaveFiller(*NativeHandle->DSFiller());
        return gcnew XBOPAlgo_PaveFiller(temp);
    };

    //! Returns the Building tool
    XBOPAlgo_Builder^ XBRepAlgoAPI_BuilderAlgo::Builder() {
        BOPAlgo_Builder* temp = new BOPAlgo_Builder(*NativeHandle->Builder());
        return gcnew XBOPAlgo_Builder(temp);
    };

    //! History tool
    Handle(BRepTools_History) XBRepAlgoAPI_BuilderAlgo::History() {
        NativeHandle->History();
    };
}