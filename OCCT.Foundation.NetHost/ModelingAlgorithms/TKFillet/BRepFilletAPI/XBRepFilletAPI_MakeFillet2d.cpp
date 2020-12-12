#include <XBRepFilletAPI_MakeFillet2d.h>

namespace TKFillet {
    //! Initializes an empty algorithm for computing fillets and
    //! chamfers. The face on which the fillets and
    //! chamfers are built is defined using the Init function.
    //! The vertices on which fillets or chamfers are built are
    //! defined using the AddFillet or AddChamfer function.
    //! Warning
    //! The status of the initialization, as given by the Status
    //! function, can be one of the following:
    //! -   ChFi2d_Ready if the initialization is correct,
    //! -   ChFi2d_NotPlanar if F is not planar,
    //! -   ChFi2d_NoFace if F is a null face.
    XBRepFilletAPI_MakeFillet2d::XBRepFilletAPI_MakeFillet2d() {
        NativeHandle = new BRepFilletAPI_MakeFillet2d();
        SetMakeShapeHandle(NativeHandle);
    };


    XBRepFilletAPI_MakeFillet2d::XBRepFilletAPI_MakeFillet2d(BRepFilletAPI_MakeFillet2d* handle) {
        NativeHandle = handle;
        SetMakeShapeHandle(NativeHandle);
    };

    void XBRepFilletAPI_MakeFillet2d::SetMakeFillet2dHandle(BRepFilletAPI_MakeFillet2d* handle) {
        NativeHandle = handle;
        SetMakeShapeHandle(NativeHandle);
    };

    BRepFilletAPI_MakeFillet2d* XBRepFilletAPI_MakeFillet2d::GetMakeFillet2d() {
        return NativeHandle;
    };

    BRepBuilderAPI_MakeShape* XBRepFilletAPI_MakeFillet2d::GetMakeShape() {
        return NativeHandle;
    };

    //! Returns a shape built by the shape construction algorithm.
    //! Raises exception StdFail_NotDone if the shape was not built.
    XTopoDS_Shape^ XBRepFilletAPI_MakeFillet2d::Shape() {
        TopoDS_Shape* temp = new TopoDS_Shape(NativeHandle->Shape());
        return gcnew XTopoDS_Shape(temp);
    };


    //! Initializes this algorithm for constructing fillets or
    //! chamfers with the face F.
    //! Warning
    //! The status of the initialization, as given by the Status
    //! function, can be one of the following:
    //! -   ChFi2d_Ready if the initialization is correct,
    //! -   ChFi2d_NotPlanar if F is not planar,
    //! -   ChFi2d_NoFace if F is a null face.
    void XBRepFilletAPI_MakeFillet2d::Init(XTopoDS_Face^ F) {
        NativeHandle->Init(*F->GetFace());
    };

    //! This initialize  method allow  to init the builder
    //! from a  face <RefFace> and  another face <ModFace>
    //! which derive from  <RefFace>.  This  is usefull to
    //! modify a fillet or   a chamfer already created  on
    //! <ModFace> .
    void XBRepFilletAPI_MakeFillet2d::Init(XTopoDS_Face^ RefFace, XTopoDS_Face^ ModFace) {
        NativeHandle->Init(*RefFace->GetFace(), *ModFace->GetFace());
    };

    //! Adds a fillet of radius Radius between the two edges
    //! adjacent to the vertex V on the face modified by this
    //! algorithm. The two edges do not need to be rectilinear.
    //! This function returns the fillet and builds the resulting face.
    //! Warning
    //! The status of the construction, as given by the Status
    //! function, can be one of the following:
    //! - ChFi2d_IsDone if the fillet is built,
    //! - ChFi2d_ConnexionError if V does not belong to the initial face,
    //! -   ChFi2d_ComputationError if Radius is too large
    //! to build a fillet between the two adjacent edges,
    //! -   ChFi2d_NotAuthorized
    //! -   if one of the two edges connected to V is a fillet or chamfer, or
    //! -   if a curve other than a straight line or an arc of a
    //! circle is used as E, E1 or E2.
    //! Do not use the returned fillet if the status of the construction is not ChFi2d_IsDone.
    //! Exceptions
    //! Standard_NegativeValue if Radius is less than or equal to zero.
    XTopoDS_Edge^ XBRepFilletAPI_MakeFillet2d::AddFillet(XTopoDS_Vertex^ V, Standard_Real Radius) {
        TopoDS_Edge* temp = new TopoDS_Edge(NativeHandle->AddFillet(*V->GetVertex(), Radius));
        return gcnew XTopoDS_Edge(temp);
    };

    //! Assigns the radius Radius to the fillet Fillet already
    //! built on the face modified by this algorithm.
    //! This function returns the new fillet and modifies the existing face.
    //! Warning
    //! The status of the construction, as given by the Status
    //! function, can be one of the following:
    //! -   ChFi2d_IsDone if the new fillet is built,
    //! -   ChFi2d_ConnexionError if Fillet does not
    //! belong to the existing face,
    //! -   ChFi2d_ComputationError if Radius is too
    //! large to build a fillet between the two adjacent edges.
    //! Do not use the returned fillet if the status of the
    //! construction is not ChFi2d_IsDone.
    //! Exceptions
    //! Standard_NegativeValue if Radius is less than or equal to zero.
    XTopoDS_Edge^ XBRepFilletAPI_MakeFillet2d::ModifyFillet(XTopoDS_Edge^ Fillet, Standard_Real Radius) {
        TopoDS_Edge* temp = new TopoDS_Edge(NativeHandle->ModifyFillet(*Fillet->GetEdge(), Radius));
        return gcnew XTopoDS_Edge(temp);
    };

    //! Removes the fillet Fillet already built on the face
    //! modified by this algorithm.
    //! This function returns the vertex connecting the two
    //! adjacent edges of Fillet and modifies the existing face.
    //! Warning
    //! -   The returned vertex is only valid if the Status
    //! function returns ChFi2d_IsDone.
    //! -   A null vertex is returned if the edge Fillet does not
    //! belong to the initial face.
    XTopoDS_Vertex^ XBRepFilletAPI_MakeFillet2d::RemoveFillet(XTopoDS_Edge^ Fillet) {
        TopoDS_Vertex* temp = new TopoDS_Vertex(NativeHandle->RemoveFillet(*Fillet->GetEdge()));
        return gcnew XTopoDS_Vertex(temp);
    };

    //! Adds a chamfer on the face modified by this algorithm
    //! between the two adjacent edges E1 and E2, where
    //! the extremities of the chamfer are on E1 and E2 at
    //! distances D1 and D2 respectively
    //! In cases where the edges are not rectilinear, distances
    //! are measured using the curvilinear abscissa of the
    //! edges and the angle is measured with respect to the
    //! tangent at the corresponding point.
    //! The angle Ang is given in radians.
    //! This function returns the chamfer and builds the resulting face.
    XTopoDS_Edge^ XBRepFilletAPI_MakeFillet2d::AddChamfer(XTopoDS_Edge^ E1, XTopoDS_Edge^ E2, Standard_Real D1, Standard_Real D2) {
        TopoDS_Edge* temp = new TopoDS_Edge(NativeHandle->AddChamfer(*E1->GetEdge(), *E2->GetEdge(), D1, D2));
        return gcnew XTopoDS_Edge(temp);
    };

    //! Adds a chamfer on the face modified by this algorithm
    //! between the two edges connected by the vertex V,
    //! where E is one of the two edges. The chamfer makes
    //! an angle Ang with E and one of its extremities is on
    //! E at distance D from V.
    //! In cases where the edges are not rectilinear, distances
    //! are measured using the curvilinear abscissa of the
    //! edges and the angle is measured with respect to the
    //! tangent at the corresponding point.
    //! The angle Ang is given in radians.
    //! This function returns the chamfer and builds the resulting face.
    //! Warning
    //! The status of the construction, as given by the Status function, can
    //! be one of the following:
    //! -          ChFi2d_IsDone if the chamfer is built,
    //! -  ChFi2d_ParametersError if D1, D2, D or Ang is less than or equal to zero,
    //! -          ChFi2d_ConnexionError if:
    //! - the edge E, E1 or E2 does not belong to the initial face, or
    //! -  the edges E1 and E2 are not adjacent, or
    //! -  the vertex V is not one of the limit points of the edge E,
    //! -          ChFi2d_ComputationError if the parameters of the chamfer
    //! are too large to build a chamfer between the two adjacent edges,
    //! -          ChFi2d_NotAuthorized if:
    //! - the edge E1, E2 or one of the two edges connected to V is a fillet or chamfer, or
    //! - a curve other than a straight line or an arc of a circle is used as E, E1 or E2.
    //! Do not use the returned chamfer if
    //! the status of the construction is not ChFi2d_IsDone.
    XTopoDS_Edge^ XBRepFilletAPI_MakeFillet2d::AddChamfer(XTopoDS_Edge^ E, XTopoDS_Vertex^ V, Standard_Real D, Standard_Real Ang) {
        TopoDS_Edge* temp = new TopoDS_Edge(NativeHandle->AddChamfer(*E->GetEdge(),*V->GetVertex(), D, Ang));
        return gcnew XTopoDS_Edge(temp);
    };

    //! Modifies the chamfer Chamfer on the face modified
    //! by this algorithm, where:
    //! E1 and E2 are the two adjacent edges on which
    //! Chamfer is already built; the extremities of the new
    //! chamfer are on E1 and E2 at distances D1 and D2 respectively.
    XTopoDS_Edge^ XBRepFilletAPI_MakeFillet2d::ModifyChamfer(XTopoDS_Edge^ Chamfer, XTopoDS_Edge^ E1, XTopoDS_Edge^ E2, Standard_Real D1, Standard_Real D2) {
        TopoDS_Edge* temp = new TopoDS_Edge(NativeHandle->ModifyChamfer(*Chamfer->GetEdge(), *E1->GetEdge(), *E2->GetEdge(), D1, D2));
        return gcnew XTopoDS_Edge(temp);
    };

    //! Modifies the chamfer Chamfer on the face modified
    //! by this algorithm, where:
    //! E is one of the two adjacent edges on which
    //! Chamfer is already built; the new chamfer makes
    //! an angle Ang with E and one of its extremities is
    //! on E at distance D from the vertex on which the chamfer is built.
    //! In cases where the edges are not rectilinear, the
    //! distances are measured using the curvilinear abscissa
    //! of the edges and the angle is measured with respect
    //! to the tangent at the corresponding point.
    //! The angle Ang is given in radians.
    //! This function returns the new chamfer and modifies the existing face.
    //! Warning
    //! The status of the construction, as given by the Status
    //! function, can be one of the following:
    //! -   ChFi2d_IsDone if the chamfer is built,
    //! -   ChFi2d_ParametersError if D1, D2, D or Ang is less than or equal to zero,
    //! -   ChFi2d_ConnexionError if:
    //! -   the edge E, E1, E2 or Chamfer does not belong
    //! to the existing face, or
    //! -   the edges E1 and E2 are not adjacent,
    //! -   ChFi2d_ComputationError if the parameters of
    //! the chamfer are too large to build a chamfer
    //! between the two adjacent edges,
    //! -   ChFi2d_NotAuthorized if E1 or E2 is a fillet or chamfer.
    //! Do not use the returned chamfer if the status of the
    //! construction is not ChFi2d_IsDone.
    XTopoDS_Edge^ XBRepFilletAPI_MakeFillet2d::ModifyChamfer(XTopoDS_Edge^ Chamfer, XTopoDS_Edge^ E, Standard_Real D, Standard_Real Ang) {
        TopoDS_Edge* temp = new TopoDS_Edge(NativeHandle->ModifyChamfer(*Chamfer->GetEdge(), *E->GetEdge(), D, Ang));
        return gcnew XTopoDS_Edge(temp);
    };

    //! Removes the chamfer Chamfer already built on the face
    //! modified by this algorithm.
    //! This function returns the vertex connecting the two
    //! adjacent edges of Chamfer and modifies the existing face.
    //! Warning
    //! -   The returned vertex is only valid if the Status
    //! function returns ChFi2d_IsDone.
    //! -   A null vertex is returned if the edge Chamfer does
    //! not belong to the initial face.
    XTopoDS_Vertex^ XBRepFilletAPI_MakeFillet2d::RemoveChamfer(XTopoDS_Edge^ Chamfer) {
        TopoDS_Vertex* temp = new TopoDS_Vertex(NativeHandle->RemoveChamfer(*Chamfer->GetEdge()));
        return gcnew XTopoDS_Vertex(temp);
    };

    //! Returns true if the edge E on the face modified by this
    //! algorithm is chamfered or filleted.
    //! Warning
    //! Returns false if E does not belong to the face modified by this algorithm.
    Standard_Boolean XBRepFilletAPI_MakeFillet2d::IsModified(XTopoDS_Edge^ E) {
        return NativeHandle->IsModified(*E->GetEdge());
    };

    //! Returns the table of fillets on the face modified by this algorithm.
    TopTools_SequenceOfShape XBRepFilletAPI_MakeFillet2d::FilletEdges() {
        return NativeHandle->FilletEdges();
    };

    //! Returns the number of fillets on the face modified by this algorithm.
    Standard_Integer XBRepFilletAPI_MakeFillet2d::NbFillet() {
        return NativeHandle->NbFillet();
    };

    //! Returns the table of chamfers on the face modified by this algorithm.
    TopTools_SequenceOfShape XBRepFilletAPI_MakeFillet2d::ChamferEdges() {
        return NativeHandle->ChamferEdges();
    };

    //! Returns the number of chamfers on the face modified by this algorithm.
    Standard_Integer XBRepFilletAPI_MakeFillet2d::NbChamfer() {
        return NativeHandle->NbChamfer();
    };

    //! Returns the list  of shapes modified from the shape
    //! <S>.
    XTopTools_ListOfShape^ XBRepFilletAPI_MakeFillet2d::Modified(XTopoDS_Shape^ S) {
        TopTools_ListOfShape* temp = new TopTools_ListOfShape(NativeHandle->Modified(*S->GetShape()));
        return gcnew XTopTools_ListOfShape(temp);
    };

    //! returns the number of new curves
    //! after the shape creation.
    Standard_Integer XBRepFilletAPI_MakeFillet2d::NbCurves() {
        return NativeHandle->NbCurves();
    };

    //! Return the Edges created for curve I.
    XTopTools_ListOfShape^ XBRepFilletAPI_MakeFillet2d::NewEdges(Standard_Integer I) {
        TopTools_ListOfShape* temp = new TopTools_ListOfShape(NativeHandle->NewEdges(I));
        return gcnew XTopTools_ListOfShape(temp);
    };

    Standard_Boolean XBRepFilletAPI_MakeFillet2d::HasDescendant(XTopoDS_Edge^ E) {
        return NativeHandle->HasDescendant(*E->GetEdge());
    };

    //! Returns the chamfered or filleted edge built from the
    //! edge E on the face modified by this algorithm. If E has
    //! not been modified, this function returns E.
    //! Exceptions
    //! Standard_NoSuchObject if the edge E does not
    //! belong to the initial face.
    XTopoDS_Edge^ XBRepFilletAPI_MakeFillet2d::DescendantEdge(XTopoDS_Edge^ E) {
        TopoDS_Edge* temp = new TopoDS_Edge(NativeHandle->DescendantEdge(*E->GetEdge()));
        return gcnew XTopoDS_Edge(temp);
    };

    //! Returns the basis edge on the face modified by this
    //! algorithm from which the chamfered or filleted edge E is
    //! built. If E has not been modified, this function returns E.
    //! Warning
    //! E is returned if it does not belong to the initial face.
    XTopoDS_Edge^ XBRepFilletAPI_MakeFillet2d::BasisEdge(XTopoDS_Edge^ E) {
        TopoDS_Edge* temp = new TopoDS_Edge(NativeHandle->BasisEdge(*E->GetEdge()));
        return gcnew XTopoDS_Edge(temp);
    };

    XChFi2d_ConstructionError XBRepFilletAPI_MakeFillet2d::Status() {
        return safe_cast<XChFi2d_ConstructionError>(NativeHandle->Status());
    };

    //! Update the result and set the Done flag
    void XBRepFilletAPI_MakeFillet2d::Build() {
        NativeHandle->Build();
    };
}

