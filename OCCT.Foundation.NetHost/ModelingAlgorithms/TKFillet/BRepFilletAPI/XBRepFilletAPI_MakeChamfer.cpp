#include <XBRepFilletAPI_MakeChamfer.h>

namespace TKFillet {

	XBRepFilletAPI_MakeChamfer::XBRepFilletAPI_MakeChamfer() {
		//NativeHandle = new BRepFilletAPI_MakeChamfer();
	};

	//! Initializes an algorithm for computing chamfers on the shape S.
	//! The edges on which chamfers are built are defined using the Add function.
	XBRepFilletAPI_MakeChamfer::XBRepFilletAPI_MakeChamfer(XTopoDS_Shape^ S) {
		NativeHandle = new BRepFilletAPI_MakeChamfer(*S->GetShape());
		SetLocalOperationHandle(NativeHandle);
	};

	XBRepFilletAPI_MakeChamfer::XBRepFilletAPI_MakeChamfer(BRepFilletAPI_MakeChamfer* handle) {
		NativeHandle = handle;
		SetMakeShapeHandle(NativeHandle);
	};

	void XBRepFilletAPI_MakeChamfer::SetMakeChamferHandle(BRepFilletAPI_MakeChamfer* handle) {
		NativeHandle = handle;
		SetMakeShapeHandle(NativeHandle);
	};

	BRepFilletAPI_MakeChamfer* XBRepFilletAPI_MakeChamfer::GetMakeChamfer() {
		return NativeHandle;
	};

	BRepFilletAPI_LocalOperation* XBRepFilletAPI_MakeChamfer::GetLocalOperation() {
		return NativeHandle;
	};

	BRepBuilderAPI_MakeShape* XBRepFilletAPI_MakeChamfer::GetMakeShape() {
		return NativeHandle;
	};

	//! Returns a shape built by the shape construction algorithm.
	//! Raises exception StdFail_NotDone if the shape was not built.
	XTopoDS_Shape^ XBRepFilletAPI_MakeChamfer::Shape() {
		TopoDS_Shape* temp = new TopoDS_Shape(NativeHandle->Shape());
		return gcnew XTopoDS_Shape(temp);
	};

	//! Adds edge E to the table of edges used by this
	//! algorithm to build chamfers, where the parameters
	//! of the chamfer must be set after the
	void XBRepFilletAPI_MakeChamfer::Add(XTopoDS_Edge^ E) {
		NativeHandle->Add(*E->GetEdge());
	};

	//! Adds edge E to the table of edges used by this
	//! algorithm to build chamfers, where
	//! the parameters of the chamfer are given by
	//! the distance Dis (symmetric chamfer).
	//! The Add function results in a contour being built by
	//! propagation from the edge E (i.e. the contour contains at
	//! least this edge). This contour is composed of edges of
	//! the shape which are tangential to one another and
	//! which delimit two series of tangential faces, with one
	//! series of faces being located on either side of the contour.
	//! Warning
	//! Nothing is done if edge E or the face F does not belong to the initial shape.
	void XBRepFilletAPI_MakeChamfer::Add(Standard_Real Dis, XTopoDS_Edge^ E) {
		NativeHandle->Add(Dis, *E->GetEdge());
	};

	//! Sets the distances Dis1 and Dis2 which give the
	//! parameters of the chamfer along the contour of index
	//! IC generated using the Add function in the internal
	//! data structure of this algorithm. The face F identifies
	//! the side where Dis1 is measured.
	//! Warning
	//! Nothing is done if either the edge E or the face F
	//! does not belong to the initial shape.
	void XBRepFilletAPI_MakeChamfer::SetDist(Standard_Real Dis, Standard_Integer IC, XTopoDS_Face^ F) {
		NativeHandle->SetDist(Dis, IC, *F->GetFace());
	};

	void XBRepFilletAPI_MakeChamfer::GetDist(Standard_Integer IC, Standard_Real Dis) {
		NativeHandle->GetDist(IC, Dis);
	};

	//! Adds edge E to the table of edges used by this
	//! algorithm to build chamfers, where
	//! the parameters of the chamfer are given by the two
	//! distances Dis1 and Dis2; the face F identifies the side
	//! where Dis1 is measured.
	//! The Add function results in a contour being built by
	//! propagation from the edge E (i.e. the contour contains at
	//! least this edge). This contour is composed of edges of
	//! the shape which are tangential to one another and
	//! which delimit two series of tangential faces, with one
	//! series of faces being located on either side of the contour.
	//! Warning
	//! Nothing is done if edge E or the face F does not belong to the initial shape.
	void XBRepFilletAPI_MakeChamfer::Add(Standard_Real Dis1, Standard_Real Dis2, XTopoDS_Edge^ E, XTopoDS_Face^ F) {
		NativeHandle->Add(Dis1, Dis2, *E->GetEdge(), *F->GetFace());
	};

	//! Sets the distances Dis1 and Dis2 which give the
	//! parameters of the chamfer along the contour of index
	//! IC generated using the Add function in the internal
	//! data structure of this algorithm. The face F identifies
	//! the side where Dis1 is measured.
	//! Warning
	//! Nothing is done if either the edge E or the face F
	//! does not belong to the initial shape.
	void XBRepFilletAPI_MakeChamfer::SetDists(Standard_Real Dis1, Standard_Real Dis2, Standard_Integer IC, XTopoDS_Face^ F) {
		NativeHandle->SetDists(Dis1, Dis2, IC, *F->GetFace());
	};

	//! Returns the distances Dis1 and Dis2 which give the
	//! parameters of the chamfer along the contour of index IC
	//! in the internal data structure of this algorithm.
	//! Warning
	//! -1. is returned if IC is outside the bounds of the table of contours.
	void XBRepFilletAPI_MakeChamfer::Dists(Standard_Integer IC, Standard_Real% Dis1, Standard_Real% Dis2) {
		Standard_Real XDis1(Dis1); Standard_Real XDis2(Dis2);
		NativeHandle->Dists(IC, XDis1, XDis2);
		Dis1 = XDis1; Dis2 = XDis2;
	};

	//! Adds a  fillet contour in  the  builder  (builds a
	//! contour  of tangent edges to <E> and sets the
	//! distance <Dis1> and angle <Angle> ( parameters of the chamfer ) ).
	void XBRepFilletAPI_MakeChamfer::AddDA(Standard_Real Dis, Standard_Real Angle, XTopoDS_Edge^ E, XTopoDS_Face^ F) {
		NativeHandle->AddDA(Dis, Angle, *E->GetEdge(), *F->GetFace());
	};

	//! set the distance <Dis> and <Angle> of the fillet
	//! contour of index <IC> in the DS with <Dis> on <F>.
	//! if the face <F> is not one of common faces
	//! of an edge of the contour <IC>
	void XBRepFilletAPI_MakeChamfer::SetDistAngle(Standard_Real Dis, Standard_Real Angle, Standard_Integer IC, XTopoDS_Face^ F) {
		NativeHandle->SetDistAngle(Dis, Angle, IC, *F->GetFace());
	};

	//! gives the distances <Dis> and <Angle> of the fillet
	//! contour of index <IC> in the DS
	void XBRepFilletAPI_MakeChamfer::GetDistAngle(Standard_Integer IC, Standard_Real% Dis, Standard_Real% Angle) {
		Standard_Real XDis(Dis); Standard_Real XAngle(Angle);
		NativeHandle->GetDistAngle(IC, XDis, XAngle);
		Dis = XDis; Angle = XAngle;
	};

	//! Sets the mode of chamfer
	void XBRepFilletAPI_MakeChamfer::SetMode(XChFiDS_ChamfMode theMode) {
		NativeHandle->SetMode(safe_cast<ChFiDS_ChamfMode>(theMode));
	};

	//! return True if chamfer symetric false else.
	Standard_Boolean XBRepFilletAPI_MakeChamfer::IsSymetric(Standard_Integer IC) {
		return NativeHandle->IsSymetric(IC);
	};

	//! return True if chamfer is made with two distances false else.
	Standard_Boolean XBRepFilletAPI_MakeChamfer::IsTwoDistances(Standard_Integer IC) {
		return NativeHandle->IsTwoDistances(IC);
	};

	//! return True if chamfer is made with distance and angle false else.
	Standard_Boolean XBRepFilletAPI_MakeChamfer::IsDistanceAngle(Standard_Integer IC) {
		return NativeHandle->IsDistanceAngle(IC);
	};

	//! Erases the chamfer parameters on the contour of
	//! index IC in the internal data structure of this algorithm.
	//! Use the SetDists function to reset this data.
	//! Warning
	//! Nothing is done if IC is outside the bounds of the table of contours.
	void XBRepFilletAPI_MakeChamfer::ResetContour(Standard_Integer IC) {
		NativeHandle->ResetContour(IC);
	};

	//! Returns the number of contours generated using the
	//! Add function in the internal data structure of this algorithm.
	Standard_Integer XBRepFilletAPI_MakeChamfer::NbContours() {
		return NativeHandle->NbContours();
	};

	//! Returns the index of the contour in the internal data
	//! structure of this algorithm, which contains the edge E of the shape.
	//! This function returns 0 if the edge E does not belong to any contour.
	//! Warning
	//! This index can change if a contour is removed from the
	//! internal data structure of this algorithm using the function Remove.
	Standard_Integer XBRepFilletAPI_MakeChamfer::Contour(XTopoDS_Edge^ E) {
		return NativeHandle->Contour(*E->GetEdge());
	};

	//! Returns the number of edges in the contour of index I in
	//! the internal data structure of this algorithm.
	//! Warning
	//! Returns 0 if I is outside the bounds of the table of contours.
	Standard_Integer XBRepFilletAPI_MakeChamfer::NbEdges(Standard_Integer I) {
		return NativeHandle->NbEdges(I);
	};

	//! Returns the edge of index J in the contour of index I in
	//! the internal data structure of this algorithm.
	//! Warning
	//! Returns a null shape if:
	//! -   I is outside the bounds of the table of contours, or
	//! -   J is outside the bounds of the table of edges of the contour of index I.
	XTopoDS_Edge^ XBRepFilletAPI_MakeChamfer::Edge(Standard_Integer I, Standard_Integer J) {
		TopoDS_Edge* temp = new TopoDS_Edge(NativeHandle->Edge(I, J));
		return gcnew XTopoDS_Edge(temp);
	};

	//! Removes the contour in the internal data structure of
	//! this algorithm which contains the edge E of the shape.
	//! Warning
	//! Nothing is done if the edge E does not belong to the
	//! contour in the internal data structure of this algorithm.
	void XBRepFilletAPI_MakeChamfer::Remove(XTopoDS_Edge^ E) {
		NativeHandle->Remove(*E->GetEdge());
	};

	//! Returns the length of the contour of index IC in the
	//! internal data structure of this algorithm.
	//! Warning
	//! Returns -1. if IC is outside the bounds of the table of contours.
	Standard_Real XBRepFilletAPI_MakeChamfer::Length(Standard_Integer IC) {
		return NativeHandle->Length(IC);
	};

	//! Returns the first vertex of the contour of index IC
	//! in the internal data structure of this algorithm.
	//! Warning
	//! Returns a null shape if IC is outside the bounds of the table of contours.
	XTopoDS_Vertex^ XBRepFilletAPI_MakeChamfer::FirstVertex(Standard_Integer IC) {
		TopoDS_Vertex* temp = new TopoDS_Vertex(NativeHandle->FirstVertex(IC));
		return gcnew XTopoDS_Vertex(temp);
	};

	//! Returns the last vertex of the contour of index IC
	//! in the internal data structure of this algorithm.
	//! Warning
	//! Returns a null shape if IC is outside the bounds of the table of contours.
	XTopoDS_Vertex^ XBRepFilletAPI_MakeChamfer::LastVertex(Standard_Integer IC) {
		TopoDS_Vertex* temp = new TopoDS_Vertex(NativeHandle->LastVertex(IC));
		return gcnew XTopoDS_Vertex(temp);
	};

	//! Returns the curvilinear abscissa of the vertex V on the
	//! contour of index IC in the internal data structure of this algorithm.
	//! Warning
	//! Returns -1. if:
	//! -   IC is outside the bounds of the table of contours, or
	//! -   V is not on the contour of index IC.
	Standard_Real XBRepFilletAPI_MakeChamfer::Abscissa(Standard_Integer IC, XTopoDS_Vertex^% V) {
		TopoDS_Vertex* temp = V->GetVertex();
		return NativeHandle->Abscissa(IC, *temp);
		V = gcnew XTopoDS_Vertex(temp);
	};

	//! Returns the relative curvilinear abscissa (i.e. between 0
	//! and 1) of the vertex V on the contour of index IC in the
	//! internal data structure of this algorithm.
	//! Warning
	//! Returns -1. if:
	//! -   IC is outside the bounds of the table of contours, or
	//! -   V is not on the contour of index IC.
	Standard_Real XBRepFilletAPI_MakeChamfer::RelativeAbscissa(Standard_Integer IC, XTopoDS_Vertex^% V) {
		TopoDS_Vertex* temp = V->GetVertex();
		return NativeHandle->RelativeAbscissa(IC, *temp);
		V = gcnew XTopoDS_Vertex(temp);
	};

	//! eturns true if the contour of index IC in the internal
	//! data structure of this algorithm is closed and tangential at the point of closure.
	//! Warning
	//! Returns false if IC is outside the bounds of the table of contours.
	Standard_Boolean XBRepFilletAPI_MakeChamfer::ClosedAndTangent(Standard_Integer IC) {
		return NativeHandle->ClosedAndTangent(IC);
	};

	//! Returns true if the contour of index IC in the internal
	//! data structure of this algorithm is closed.
	//! Warning
	//! Returns false if IC is outside the bounds of the table of contours.
	Standard_Boolean XBRepFilletAPI_MakeChamfer::Closed(Standard_Integer IC) {
		return NativeHandle->Closed(IC);
	};

	//! Builds the chamfers on all the contours in the internal
	//! data structure of this algorithm and constructs the resulting shape.
	//! Use the function IsDone to verify that the chamfered
	//! shape is built. Use the function Shape to retrieve the chamfered shape.
	//! Warning
	//! The construction of chamfers implements highly complex
	//! construction algorithms. Consequently, there may be
	//! instances where the algorithm fails, for example if the
	//! data defining the parameters of the chamfer is not
	//! compatible with the geometry of the initial shape. There
	//! is no initial analysis of errors and these only become
	//! evident at the construction stage.
	//! Additionally, in the current software release, the following
	//! cases are not handled:
	//! -   the end point of the contour is the point of
	//! intersection of 4 or more edges of the shape, or
	//! -   the intersection of the chamfer with a face which
	//! limits the contour is not fully contained in this face.
	void XBRepFilletAPI_MakeChamfer::Build() {
		NativeHandle->Build();
	};

	//! Reinitializes this algorithm, thus canceling the effects of the Build function.
	//! This function allows modifications to be made to the
	//! contours and chamfer parameters in order to rebuild the shape.
	void XBRepFilletAPI_MakeChamfer::Reset() {
		NativeHandle->Reset();
	};

	//! Returns the internal filleting algorithm.
	Handle(TopOpeBRepBuild_HBuilder) XBRepFilletAPI_MakeChamfer::Builder() {
		return NativeHandle->Builder();
	};

	//! Returns the  list   of shapes generated   from the
	//! shape <EorV>.
	XTopTools_ListOfShape^ XBRepFilletAPI_MakeChamfer::Generated(XTopoDS_Shape^ EorV) {
		TopTools_ListOfShape* temp = new TopTools_ListOfShape(NativeHandle->Generated(*EorV->GetShape()));
		return gcnew XTopTools_ListOfShape(temp);
	};

	//! Returns the list  of shapes modified from the shape
	//! <F>.
	XTopTools_ListOfShape^ XBRepFilletAPI_MakeChamfer::Modified(XTopoDS_Shape^ F) {
		TopTools_ListOfShape* temp = new TopTools_ListOfShape(NativeHandle->Modified(*F->GetShape()));
		return gcnew XTopTools_ListOfShape(temp);
	};

	Standard_Boolean XBRepFilletAPI_MakeChamfer::IsDeleted(XTopoDS_Shape^ F) {
		return NativeHandle->IsDeleted(*F->GetShape());
	};

	void XBRepFilletAPI_MakeChamfer::Simulate(Standard_Integer IC) {
		NativeHandle->Simulate(IC);
	};

	Standard_Integer XBRepFilletAPI_MakeChamfer::NbSurf(Standard_Integer IC) {
		return NativeHandle->NbSurf(IC);
	};

	Handle(ChFiDS_SecHArray1) XBRepFilletAPI_MakeChamfer::Sect(Standard_Integer IC, Standard_Integer IS) {
		return NativeHandle->Sect(IC, IS);
	};
}
