#include <XBRepBuilderAPI_Sewing.h>
namespace TKTopAlgo {
    XBRepBuilderAPI_Sewing::XBRepBuilderAPI_Sewing() {
        NativeHandle() = new BRepBuilderAPI_Sewing();
    };

    void XBRepBuilderAPI_Sewing::SetSewingHandle(Handle(BRepBuilderAPI_Sewing) handle) {
        NativeHandle() = handle;
    };

    Handle(BRepBuilderAPI_Sewing) XBRepBuilderAPI_Sewing::GetSewing() {
        return NativeHandle();
    };

    //! Creates an object with
    //! tolerance of connexity
    //! option for sewing (if false only control)
    //! option for analysis of degenerated shapes
    //! option for cutting of free edges.
    //! option for non manifold processing
    //! Standard_Real tolerance = 1.0e-06, Standard_Boolean option1 = Standard_True, Standard_Boolean option2 = Standard_True, Standard_Boolean option3 = Standard_True, Standard_Boolean option4 = Standard_False
    XBRepBuilderAPI_Sewing::XBRepBuilderAPI_Sewing(Standard_Real tolerance, Standard_Boolean option1, Standard_Boolean option2, Standard_Boolean option3, Standard_Boolean option4) {
        NativeHandle() = new BRepBuilderAPI_Sewing(tolerance, option1, option2, option3, option4);
    };

    //! initialize the parameters if necessary
    //! Standard_Real tolerance = 1.0e-06, Standard_Boolean option1 = Standard_True, Standard_Boolean option2 = Standard_True, Standard_Boolean option3 = Standard_True, Standard_Boolean option4 = Standard_False
    void XBRepBuilderAPI_Sewing::Init(Standard_Real tolerance, Standard_Boolean option1, Standard_Boolean option2, Standard_Boolean option3, Standard_Boolean option4) {
        NativeHandle()->Init(tolerance, option1, option2, option3, option4);
    };

    //! Loades the context shape.
    void XBRepBuilderAPI_Sewing::Load(XTopoDS_Shape^ shape) {
        NativeHandle()->Load(*shape->GetShape());
    };

    //! Defines the shapes to be sewed or controlled
    void XBRepBuilderAPI_Sewing::Add(XTopoDS_Shape^ shape) {
        NativeHandle()->Add(*shape->GetShape());
    };

    //! Computing
    //! thePI - progress indicator of algorithm
    //! thePI = 0
    void XBRepBuilderAPI_Sewing::Perform(const Message_ProgressRange& thePI) {
        NativeHandle()->Perform(thePI);
    };

    //! Gives the sewed shape
    //! a null shape if nothingructed
    //! may be a face, a shell, a solid or a compound
    XTopoDS_Shape^ XBRepBuilderAPI_Sewing::SewedShape() {
        TopoDS_Shape* temp = new TopoDS_Shape(NativeHandle()->SewedShape());
        return gcnew XTopoDS_Shape(temp);
    };

    //! set context
    void XBRepBuilderAPI_Sewing::SetContext(Handle(BRepTools_ReShape) theContext) {
        NativeHandle()->SetContext(theContext);
    };

    //! return context
    Handle(BRepTools_ReShape) XBRepBuilderAPI_Sewing::GetContext() {
        return NativeHandle()->GetContext();
    };

    //! Gives the number of free edges (edge shared by one face)
    Standard_Integer XBRepBuilderAPI_Sewing::NbFreeEdges() {
        return NativeHandle()->NbFreeEdges();
    };

    //! Gives each free edge
    XTopoDS_Edge^ XBRepBuilderAPI_Sewing::FreeEdge(Standard_Integer index) {
        TopoDS_Edge* temp = new TopoDS_Edge(NativeHandle()->FreeEdge(index));
        return gcnew XTopoDS_Edge(temp);
    };

    //! Gives the number of multiple edges
    //! (edge shared by more than two faces)
    Standard_Integer XBRepBuilderAPI_Sewing::NbMultipleEdges() {
        return NativeHandle()->NbMultipleEdges();
    };

    //! Gives each multiple edge
    XTopoDS_Edge^ XBRepBuilderAPI_Sewing::MultipleEdge(Standard_Integer index) {
        TopoDS_Edge* temp = new TopoDS_Edge(NativeHandle()->FreeEdge(index));
        return gcnew XTopoDS_Edge(temp);
    };

    //! Gives the number of contigous edges (edge shared by two faces)
    Standard_Integer XBRepBuilderAPI_Sewing::NbContigousEdges() {
        return NativeHandle()->NbContigousEdges();
    };

    //! Gives each contigous edge
    XTopoDS_Edge^ XBRepBuilderAPI_Sewing::ContigousEdge(Standard_Integer index) {
        TopoDS_Edge* temp = new TopoDS_Edge(NativeHandle()->ContigousEdge(index));
        return gcnew XTopoDS_Edge(temp);
    };

    //! Gives the sections (edge) belonging to a contigous edge
    XTopTools_ListOfShape^ XBRepBuilderAPI_Sewing::ContigousEdgeCouple(Standard_Integer index) {
        TopTools_ListOfShape* temp = new TopTools_ListOfShape(NativeHandle()->ContigousEdgeCouple(index));
        return gcnew XTopTools_ListOfShape(temp);
    };

    //! Indicates if a section is bound (before use SectionToBoundary)
    Standard_Boolean XBRepBuilderAPI_Sewing::IsSectionBound(XTopoDS_Edge^ section) {
        return NativeHandle()->IsSectionBound(*section->GetEdge());
    };

    //! Gives the original edge (free boundary) which becomes the
    //! the section. Remember that sectionsitute  common edges.
    //! This imformation is important for control because with
    //! original edge we can find the surface to which the section
    //! is attached.
    XTopoDS_Edge^ XBRepBuilderAPI_Sewing::SectionToBoundary(XTopoDS_Edge^ section) {
        TopoDS_Edge* temp = new TopoDS_Edge(NativeHandle()->SectionToBoundary(*section->GetEdge()));
        return gcnew XTopoDS_Edge(temp);
    };

    //! Gives the number of degenerated shapes
    Standard_Integer XBRepBuilderAPI_Sewing::NbDegeneratedShapes() {
        return NativeHandle()->NbDegeneratedShapes();
    };

    //! Gives each degenerated shape
    XTopoDS_Shape^ XBRepBuilderAPI_Sewing::DegeneratedShape(Standard_Integer index) {
        TopoDS_Shape* temp = new TopoDS_Shape(NativeHandle()->DegeneratedShape(index));
        return gcnew XTopoDS_Shape(temp);
    };

    //! Indicates if a input shape is degenerated
    Standard_Boolean XBRepBuilderAPI_Sewing::IsDegenerated(XTopoDS_Shape^ shape) {
        return NativeHandle()->IsDegenerated(*shape->GetShape());
    };

    //! Indicates if a input shape has been modified
    Standard_Boolean XBRepBuilderAPI_Sewing::IsModified(XTopoDS_Shape^ shape) {
        return NativeHandle()->IsModified(*shape->GetShape());
    };

    //! Gives a modifieded shape
    XTopoDS_Shape^ XBRepBuilderAPI_Sewing::Modified(XTopoDS_Shape^ shape) {
        TopoDS_Shape* temp = new TopoDS_Shape(NativeHandle()->Modified(*shape->GetShape()));
        return gcnew XTopoDS_Shape(temp);
    };

    //! Indicates if a input subshape has been modified
    Standard_Boolean XBRepBuilderAPI_Sewing::IsModifiedSubShape(XTopoDS_Shape^ shape) {
        return NativeHandle()->IsModifiedSubShape(*shape->GetShape());
    };

    //! Gives a modifieded subshape
    XTopoDS_Shape^ XBRepBuilderAPI_Sewing::ModifiedSubShape(XTopoDS_Shape^ shape) {
        TopoDS_Shape* temp = new TopoDS_Shape(NativeHandle()->ModifiedSubShape(*shape->GetShape()));
        return gcnew XTopoDS_Shape(temp);
    };

    //! print the informations
    void XBRepBuilderAPI_Sewing::Dump() {
        NativeHandle()->Dump();
    };

    //! Gives the number of deleted faces (faces smallest than tolerance)
    Standard_Integer XBRepBuilderAPI_Sewing::NbDeletedFaces() {
        return NativeHandle()->NbDeletedFaces();
    };

    //! Gives each deleted face
    XTopoDS_Face^ XBRepBuilderAPI_Sewing::DeletedFace(Standard_Integer index) {
        TopoDS_Face* temp = new TopoDS_Face(NativeHandle()->DeletedFace(index));
        return gcnew XTopoDS_Face(temp);
    };

    //! Gives a modified shape
    //! Standard_Integer index = 1
    XTopoDS_Face^ XBRepBuilderAPI_Sewing::WhichFace(XTopoDS_Edge^ theEdg, Standard_Integer index) {
        TopoDS_Face* temp = new TopoDS_Face(NativeHandle()->DeletedFace(index));
        return gcnew XTopoDS_Face(temp);
    };

    //! Gets same parameter mode.
    Standard_Boolean XBRepBuilderAPI_Sewing::SameParameterMode() {
        return NativeHandle()->SameParameterMode();
    };

    //! Sets same parameter mode.
    void XBRepBuilderAPI_Sewing::SetSameParameterMode(Standard_Boolean SameParameterMode) {
        NativeHandle()->SetSameParameterMode(SameParameterMode);
    };

    //! Gives set tolerance.
    Standard_Real XBRepBuilderAPI_Sewing::Tolerance() {
        return NativeHandle()->Tolerance();
    };

    //! Sets tolerance
    void XBRepBuilderAPI_Sewing::SetTolerance(Standard_Real theToler) {
        NativeHandle()->SetTolerance(theToler);
    };

    //! Gives set min tolerance.
    Standard_Real XBRepBuilderAPI_Sewing::MinTolerance() {
        return NativeHandle()->MinTolerance();
    };

    //! Sets min tolerance
    void XBRepBuilderAPI_Sewing::SetMinTolerance(Standard_Real theMinToler) {
        NativeHandle()->SetMinTolerance(theMinToler);
    };

    //! Gives set max tolerance
    Standard_Real XBRepBuilderAPI_Sewing::MaxTolerance() {
        return NativeHandle()->MaxTolerance();
    };

    //! Sets max tolerance.
    void XBRepBuilderAPI_Sewing::SetMaxTolerance(Standard_Real theMaxToler) {
        NativeHandle()->SetMaxTolerance(theMaxToler);
    };

    //! Returns mode for sewing faces By default - true.
    Standard_Boolean XBRepBuilderAPI_Sewing::FaceMode() {
        return NativeHandle()->FaceMode();
    };

    //! Sets mode for sewing faces By default - true.
    void XBRepBuilderAPI_Sewing::SetFaceMode(Standard_Boolean theFaceMode) {
        NativeHandle()->SetFaceMode(theFaceMode);
    };

    //! Returns mode for sewing floating edges By default - false.
    Standard_Boolean XBRepBuilderAPI_Sewing::FloatingEdgesMode() {
        return NativeHandle()->FloatingEdgesMode();
    };

    //! Sets mode for sewing floating edges By default - false.
    //! Returns mode for cutting floating edges By default - false.
    //! Sets mode for cutting floating edges By default - false.
    void XBRepBuilderAPI_Sewing::SetFloatingEdgesMode(Standard_Boolean theFloatingEdgesMode) {
        NativeHandle()->SetFloatingEdgesMode(theFloatingEdgesMode);
    };

    //! Returns mode for accounting of local tolerances
    //! of edges and vertices during of merging.
    Standard_Boolean XBRepBuilderAPI_Sewing::LocalTolerancesMode() {
        return NativeHandle()->LocalTolerancesMode();
    };

    //! Sets mode for accounting of local tolerances
    //! of edges and vertices during of merging
    //! in this case WorkTolerance = myTolerance + tolEdge1+ tolEdg2;
    void XBRepBuilderAPI_Sewing::SetLocalTolerancesMode(Standard_Boolean theLocalTolerancesMode) {
        NativeHandle()->SetLocalTolerancesMode(theLocalTolerancesMode);
    };

    //! Sets mode for non-manifold sewing.
    void XBRepBuilderAPI_Sewing::SetNonManifoldMode(Standard_Boolean theNonManifoldMode) {
        NativeHandle()->SetNonManifoldMode(theNonManifoldMode);
    };

    //! Gets mode for non-manifold sewing.
    //!
    //! INTERNAL FUCTIONS ---
    Standard_Boolean XBRepBuilderAPI_Sewing::NonManifoldMode() {
        return NativeHandle()->NonManifoldMode();
    };
}
