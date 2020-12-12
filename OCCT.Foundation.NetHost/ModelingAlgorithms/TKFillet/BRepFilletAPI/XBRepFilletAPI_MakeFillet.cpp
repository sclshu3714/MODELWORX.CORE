#include <XBRepFilletAPI_MakeFillet.h>
namespace TKFillet {

	XBRepFilletAPI_MakeFillet::XBRepFilletAPI_MakeFillet() {
		//NativeHandle = new BRepFilletAPI_MakeFillet();
	};
	//! Initializes   the computation    of   the  fillets.
	//! <FShape> sets   the type   of fillet  surface. The
	//! default value is ChFi3d_Rational (classical  nurbs
	//! representation of  circles).   ChFi3d_QuasiAngular
	//! corresponds to  a  nurbs representation of circles
	//! which   parameterisation matches  the  circle one.
	//! ChFi3d_Polynomial  corresponds to  a    polynomial
	//! representation of circles.
	//! ChFi3d_FilletShape FShape = ChFi3d_Rational
	XBRepFilletAPI_MakeFillet::XBRepFilletAPI_MakeFillet(XTopoDS_Shape^ S, XChFi3d_FilletShape FShape) {
		NativeHandle = new BRepFilletAPI_MakeFillet(*S->GetShape(), safe_cast<ChFi3d_FilletShape>(FShape));
		SetMakeShapeHandle(NativeHandle);
	};


	XBRepFilletAPI_MakeFillet::XBRepFilletAPI_MakeFillet(BRepFilletAPI_MakeFillet* handle) {
		NativeHandle = handle;
		SetMakeShapeHandle(NativeHandle);
	};

	void XBRepFilletAPI_MakeFillet::SetMakeFilletHandle(BRepFilletAPI_MakeFillet* handle) {
		NativeHandle = handle;
		SetMakeShapeHandle(NativeHandle);
	};

	BRepFilletAPI_MakeFillet* XBRepFilletAPI_MakeFillet::GetMakeFillet() {
		return NativeHandle;
	};

	BRepFilletAPI_LocalOperation* XBRepFilletAPI_MakeFillet::GetLocalOperation() {
		return NativeHandle;
	};

	BRepBuilderAPI_MakeShape* XBRepFilletAPI_MakeFillet::GetMakeShape() {
		return NativeHandle;
	};

	//! Returns a shape built by the shape construction algorithm.
	//! Raises exception StdFail_NotDone if the shape was not built.
	XTopoDS_Shape^ XBRepFilletAPI_MakeFillet::Shape() {
		TopoDS_Shape* temp = new TopoDS_Shape(NativeHandle->Shape());
		return gcnew XTopoDS_Shape(temp);
	};

	void XBRepFilletAPI_MakeFillet::SetParams(Standard_Real Tang, Standard_Real Tesp, Standard_Real T2d, Standard_Real TApp3d, Standard_Real TolApp2d, Standard_Real Fleche) {
		NativeHandle->SetParams(Tang, Tesp, T2d, TApp3d, TolApp2d, Fleche);
	};

	//! Changes     the      parameters     of  continiuity
	//! InternalContinuity to produce fillet'surfaces with
	//! an continuity   Ci (i=0,1 or    2).
	//! By defaultInternalContinuity = GeomAbs_C1.
	//! AngularTolerance  is the G1 tolerance between fillet
	//! and support'faces.
	void XBRepFilletAPI_MakeFillet::SetContinuity(XGeomAbs_Shape InternalContinuity, Standard_Real AngularTolerance) {
		NativeHandle->SetContinuity(safe_cast<GeomAbs_Shape>(InternalContinuity), AngularTolerance);
	};

	//! Adds a  fillet contour in  the  builder  (builds a
	//! contour  of tangent edges).
	//! The Radius must be set after.
	void XBRepFilletAPI_MakeFillet::Add(XTopoDS_Edge^ E) {
		NativeHandle->Add(*E->GetEdge());
	};

	//! Adds a  fillet description in  the  builder
	//! - builds a contour  of tangent edges,
	//! - sets the radius.
	void XBRepFilletAPI_MakeFillet::Add(Standard_Real Radius, XTopoDS_Edge^ E) {
		NativeHandle->Add(Radius, *E->GetEdge());
	};

	//! Adds a  fillet description in  the  builder
	//! - builds a contour  of tangent edges,
	//! - sets a linear radius evolution law between
	//! the first and last vertex of the spine.
	void XBRepFilletAPI_MakeFillet::Add(Standard_Real R1, Standard_Real R2, XTopoDS_Edge^ E) {
		NativeHandle->Add(R1, R2, *E->GetEdge());
	};

	//! Adds a  fillet description in  the  builder
	//! - builds a contour  of tangent edges,
	//! - sest the radius evolution law.
	void XBRepFilletAPI_MakeFillet::Add(Handle(Law_Function)& L, XTopoDS_Edge^ E) {
		NativeHandle->Add(L, *E->GetEdge());
	};

	//! Adds a  fillet description in  the  builder
	//! - builds a contour  of tangent edges,
	//! - sets the radius evolution law interpolating the values
	//! given in the array UandR :
	//!
	//! p2d.X() = relative parameter on the spine [0,1]
	//! p2d.Y() = value of the radius.
	void XBRepFilletAPI_MakeFillet::Add(TColgp_Array1OfPnt2d& UandR, XTopoDS_Edge^ E) {
		NativeHandle->Add(UandR, *E->GetEdge());
	};

	//! Sets the parameters of the fillet
	//! along the contour of index IC generated using the Add function
	//! in the internal data structure of
	//! this algorithm, where Radius is the radius of the fillet.
	void XBRepFilletAPI_MakeFillet::SetRadius(Standard_Real Radius, Standard_Integer IC, Standard_Integer IinC) {
		NativeHandle->SetRadius(Radius, IC, IinC);
	};

	//! Sets the parameters of the fillet
	//! along the contour of index IC generated using the Add function
	//! in the internal data structure of this algorithm, where the radius of the
	//! fillet evolves according to a linear evolution law defined
	//! from R1 to R2, between the first and last vertices of the contour of index IC.
	void XBRepFilletAPI_MakeFillet::SetRadius(Standard_Real R1, Standard_Real R2, Standard_Integer IC, Standard_Integer IinC) {
		NativeHandle->SetRadius(R1, R2, IC, IinC);
	};

	//! Sets the parameters of the fillet
	//! along the contour of index IC generated using the Add function
	//! in the internal data structure of this algorithm, where the radius of the
	//! fillet evolves according to the evolution law L, between the
	//! first and last vertices of the contour of index IC.
	void XBRepFilletAPI_MakeFillet::SetRadius(Handle(Law_Function)& L, Standard_Integer IC, Standard_Integer IinC) {
		NativeHandle->SetRadius(L, IC, IinC);
	};

	//! Sets the parameters of the fillet
	//! along the contour of index IC generated using the Add function
	//! in the internal data structure of this algorithm,
	//! where the radius of the fillet evolves according to the evolution law
	//! which interpolates the set of parameter and radius pairs given
	//! in the array UandR as follows:
	//! -   the X coordinate of a point in UandR defines a
	//! relative parameter on the contour (i.e. a parameter between 0 and 1),
	//! -          the Y coordinate of a point in UandR gives the
	//! corresponding value of the radius, and the radius evolves
	//! between the first and last vertices of the contour of index IC.
	void XBRepFilletAPI_MakeFillet::SetRadius(TColgp_Array1OfPnt2d& UandR, Standard_Integer IC, Standard_Integer IinC) {
		NativeHandle->SetRadius(UandR, IC, IinC);
	};

	//! Erases the radius information on the contour of index
	//! IC in the internal data structure of this algorithm.
	//! Use the SetRadius function to reset this data.
	//! Warning
	//! Nothing is done if IC is outside the bounds of the table of contours.
	void XBRepFilletAPI_MakeFillet::ResetContour(Standard_Integer IC) {
		NativeHandle->ResetContour(IC);
	};

	//! Returns true if the radius of the fillet along the contour of index IC
	//! in the internal data structure of this algorithm is constant,
	//! Warning
	//! False is returned if IC is outside the bounds of the table
	//! of contours or if E does not belong to the contour of index IC.
	Standard_Boolean XBRepFilletAPI_MakeFillet::IsConstant(Standard_Integer IC) {
		return NativeHandle->IsConstant(IC);
	};

	//! Returns the radius of the fillet along the contour of index IC in the
	//! internal data structure of this algorithm
	//! Warning
	//! -   Use this function only if the radius is constant.
	//! -   -1. is returned if IC is outside the bounds of the
	//! table of contours or if E does not belong to the contour of index IC.
	Standard_Real XBRepFilletAPI_MakeFillet::Radius(Standard_Integer IC) {
		return NativeHandle->Radius(IC);
	};

	//! Returns true if the radius of the fillet along the edge E of the
	//! contour of index IC in the internal data structure of
	//! this algorithm is constant.
	//! Warning
	//! False is returned if IC is outside the bounds of the table
	//! of contours or if E does not belong to the contour of index IC.
	Standard_Boolean XBRepFilletAPI_MakeFillet::IsConstant(Standard_Integer IC, XTopoDS_Edge^ E) {
		return NativeHandle->IsConstant(IC, *E->GetEdge());
	};

	//! Returns the radius of the fillet along the edge E of the contour of index
	//! IC in the internal data structure of this algorithm.
	//! Warning
	//! -   Use this function only if the radius is constant.
	//! -   -1 is returned if IC is outside the bounds of the
	//! table of contours or if E does not belong to the contour of index IC.
	Standard_Real XBRepFilletAPI_MakeFillet::Radius(Standard_Integer IC, XTopoDS_Edge^ E) {
		return NativeHandle->Radius(IC, *E->GetEdge());
	};

	//! Assigns Radius as the radius of the fillet on the edge E
	void XBRepFilletAPI_MakeFillet::SetRadius(Standard_Real Radius, Standard_Integer IC, XTopoDS_Edge^ E) {
		NativeHandle->SetRadius(Radius, IC, *E->GetEdge());
	};

	void XBRepFilletAPI_MakeFillet::SetRadius(Standard_Real Radius, Standard_Integer IC, XTopoDS_Vertex^ V) {
		NativeHandle->SetRadius(Radius, IC, *V->GetVertex());
	};

	Standard_Boolean XBRepFilletAPI_MakeFillet::GetBounds(Standard_Integer IC, XTopoDS_Edge^ E, Standard_Real F, Standard_Real L) {
		return NativeHandle->GetBounds(IC,*E->GetEdge(), F, L);
	};

	Handle(Law_Function) XBRepFilletAPI_MakeFillet::GetLaw(Standard_Integer IC, XTopoDS_Edge^ E) {
		return NativeHandle->GetLaw(IC, *E->GetEdge());
	};

	void XBRepFilletAPI_MakeFillet::SetLaw(Standard_Integer IC, XTopoDS_Edge^ E, Handle(Law_Function)& L) {
		NativeHandle->SetLaw(IC, *E->GetEdge(), L);
	};

	//! Assigns FShape as the type of fillet shape built by this algorithm.
	void XBRepFilletAPI_MakeFillet::SetFilletShape(XChFi3d_FilletShape FShape) {
		NativeHandle->SetFilletShape(safe_cast<ChFi3d_FilletShape>(FShape));
	};

	//! Returns the type of fillet shape built by this algorithm.
	XChFi3d_FilletShape XBRepFilletAPI_MakeFillet::GetFilletShape() {
		return safe_cast<XChFi3d_FilletShape>(NativeHandle->GetFilletShape());
	};

	//! Returns the number of contours generated using the
	//! Add function in the internal data structure of this algorithm.
	Standard_Integer XBRepFilletAPI_MakeFillet::NbContours() {
		return NativeHandle->NbContours();
	};

	//! Returns the index of the contour in the internal data
	//! structure of this algorithm which contains the edge E of the shape.
	//! This function returns 0 if the edge E does not belong to any contour.
	//! Warning
	//! This index can change if a contour is removed from the
	//! internal data structure of this algorithm using the function Remove.
	Standard_Integer XBRepFilletAPI_MakeFillet::Contour(XTopoDS_Edge^ E) {
		return NativeHandle->Contour(*E->GetEdge());
	};

	//! Returns the number of edges in the contour of index I in
	//! the internal data structure of this algorithm.
	//! Warning
	//! Returns 0 if I is outside the bounds of the table of contours.
	Standard_Integer XBRepFilletAPI_MakeFillet::NbEdges(Standard_Integer I) {
		return NativeHandle->NbEdges(I);
	};

	//! Returns the edge of index J in the contour of index I in
	//! the internal data structure of this algorithm.
	//! Warning
	//! Returns a null shape if:
	//! -   I is outside the bounds of the table of contours, or
	//! -   J is outside the bounds of the table of edges of the index I contour.
	XTopoDS_Edge^ XBRepFilletAPI_MakeFillet::Edge(Standard_Integer I, Standard_Integer J) {
		TopoDS_Edge* temp = new TopoDS_Edge(NativeHandle->Edge(I, J));
		return gcnew XTopoDS_Edge(temp);
	};

	//! Removes the contour in the internal data structure of
	//! this algorithm which contains the edge E of the shape.
	//! Warning
	//! Nothing is done if the edge E does not belong to the
	//! contour in the internal data structure of this algorithm.
	void XBRepFilletAPI_MakeFillet::Remove(XTopoDS_Edge^ E) {
		NativeHandle->Remove(*E->GetEdge());
	};

	//! Returns the length of the contour of index IC in the
	//! internal data structure of this algorithm.
	//! Warning
	//! Returns -1. if IC is outside the bounds of the table of contours.
	Standard_Real XBRepFilletAPI_MakeFillet::Length(Standard_Integer IC) {
		return NativeHandle->Length(IC);
	};

	//! Returns the first vertex of the contour of index IC
	//! in the internal data structure of this algorithm.
	//! Warning
	//! Returns a null shape if IC is outside the bounds of the table of contours.
	XTopoDS_Vertex^ XBRepFilletAPI_MakeFillet::FirstVertex(Standard_Integer IC) {
		TopoDS_Vertex* temp = new TopoDS_Vertex(NativeHandle->FirstVertex(IC));
		return gcnew XTopoDS_Vertex(temp);
	};

	//! Returns the  last vertex of the contour of index IC
	//! in the internal data structure of this algorithm.
	//! Warning
	//! Returns a null shape if IC is outside the bounds of the table of contours.
	XTopoDS_Vertex^ XBRepFilletAPI_MakeFillet::LastVertex(Standard_Integer IC) {
		TopoDS_Vertex* temp = new TopoDS_Vertex(NativeHandle->LastVertex(IC));
		return gcnew XTopoDS_Vertex(temp);
	};

	//! Returns the curvilinear abscissa of the vertex V on the
	//! contour of index IC in the internal data structure of this algorithm.
	//! Warning
	//! Returns -1. if:
	//! -   IC is outside the bounds of the table of contours, or
	//! -   V is not on the contour of index IC.
	Standard_Real XBRepFilletAPI_MakeFillet::Abscissa(Standard_Integer IC, XTopoDS_Vertex^ V) {
		return NativeHandle->Abscissa(IC, *V->GetVertex());
	};

	//! Returns the relative curvilinear abscissa (i.e. between 0
	//! and 1) of the vertex V on the contour of index IC in the
	//! internal data structure of this algorithm.
	//! Warning
	//! Returns -1. if:
	//! -   IC is outside the bounds of the table of contours, or
	//! -   V is not on the contour of index IC.
	Standard_Real XBRepFilletAPI_MakeFillet::RelativeAbscissa(Standard_Integer IC, XTopoDS_Vertex^ V) {
		return NativeHandle->RelativeAbscissa(IC, *V->GetVertex());
	};

	//! Returns true if the contour of index IC in the internal
	//! data structure of this algorithm is closed and tangential
	//! at the point of closure.
	//! Warning
	//! Returns false if IC is outside the bounds of the table of contours.
	Standard_Boolean XBRepFilletAPI_MakeFillet::ClosedAndTangent(Standard_Integer IC) {
		return NativeHandle->ClosedAndTangent(IC);
	};

	//! Returns true if the contour of index IC in the internal
	//! data structure of this algorithm is closed.
	//! Warning
	//! Returns false if IC is outside the bounds of the table of contours.
	Standard_Boolean XBRepFilletAPI_MakeFillet::Closed(Standard_Integer IC) {
		return NativeHandle->Closed(IC);
	};

	//! Builds the fillets on all the contours in the internal data
	//! structure of this algorithm and constructs the resulting shape.
	//! Use the function IsDone to verify that the filleted shape
	//! is built. Use the function Shape to retrieve the filleted shape.
	//! Warning
	//! The construction of fillets implements highly complex
	//! construction algorithms. Consequently, there may be
	//! instances where the algorithm fails, for example if the
	//! data defining the radius of the fillet is not compatible
	//! with the geometry of the initial shape. There is no initial
	//! analysis of errors and they only become evident at the
	//! construction stage.
	//! Additionally, in the current software release, the
	//! following cases are not handled:
	//! -   the end point of the contour is the point of
	//! intersection of 4 or more edges of the shape, or
	//! -   the intersection of the fillet with a face which limits
	//! the contour is not fully contained in this face.
	void XBRepFilletAPI_MakeFillet::Build() {
		NativeHandle->Build();
	};

	//! Reinitializes this algorithm, thus canceling the effects of the Build function.
	//! This function allows modifications to be made to the
	//! contours and fillet parameters in order to rebuild the shape.
	void XBRepFilletAPI_MakeFillet::Reset() {
		NativeHandle->Reset();
	};

	//! Returns the internal topology building algorithm.
	Handle(TopOpeBRepBuild_HBuilder) XBRepFilletAPI_MakeFillet::Builder() {
		return NativeHandle->Builder();
	};

	//! Returns the  list   of shapes generated   from the
	//! shape <EorV>.
	XTopTools_ListOfShape^ XBRepFilletAPI_MakeFillet::Generated(XTopoDS_Shape^ EorV) {
		TopTools_ListOfShape* temp = new TopTools_ListOfShape(NativeHandle->Generated(*EorV->GetShape()));
		return gcnew XTopTools_ListOfShape(temp);
	};

	//! Returns the list  of shapes modified from the shape
	//! <F>.
	XTopTools_ListOfShape^ XBRepFilletAPI_MakeFillet::Modified(XTopoDS_Shape^ F) {
		TopTools_ListOfShape* temp = new TopTools_ListOfShape(NativeHandle->Modified(*F->GetShape()));
		return gcnew XTopTools_ListOfShape(temp);
	};

	Standard_Boolean XBRepFilletAPI_MakeFillet::IsDeleted(XTopoDS_Shape^ F) {
		return NativeHandle->IsDeleted(*F->GetShape());
	};

	//! returns the number of surfaces
	//! after the shape creation.
	Standard_Integer XBRepFilletAPI_MakeFillet::NbSurfaces() {
		return NativeHandle->NbSurfaces();
	};

	//! Return the faces created for surface <I>.
	XTopTools_ListOfShape^ XBRepFilletAPI_MakeFillet::NewFaces(Standard_Integer I) {
		TopTools_ListOfShape* temp = new TopTools_ListOfShape(NativeHandle->NewFaces(I));
		return gcnew XTopTools_ListOfShape(temp);
	};

	void XBRepFilletAPI_MakeFillet::Simulate(Standard_Integer IC) {
		NativeHandle->Simulate(IC);
	};

	Standard_Integer XBRepFilletAPI_MakeFillet::NbSurf(Standard_Integer IC) {
		return NativeHandle->NbSurf(IC);
	};

	Handle(ChFiDS_SecHArray1) XBRepFilletAPI_MakeFillet::Sect(Standard_Integer IC, Standard_Integer IS) {
		return NativeHandle->Sect(IC, IS);
	};

	//! Returns the number of contours where the computation
	//! of the fillet failed
	Standard_Integer XBRepFilletAPI_MakeFillet::NbFaultyContours() {
		return NativeHandle->NbFaultyContours();
	};

	//! for each I in [1.. NbFaultyContours] returns the index IC of
	//! the contour where the computation of the fillet failed.
	//! the method NbEdges(IC) gives the number of edges in the contour IC
	//! the method Edge(IC,ie) gives the edge number ie of the contour IC
	Standard_Integer XBRepFilletAPI_MakeFillet::FaultyContour(Standard_Integer I) {
		return NativeHandle->FaultyContour(I);
	};

	//! returns the number of surfaces which have been
	//! computed on the contour IC
	Standard_Integer XBRepFilletAPI_MakeFillet::NbComputedSurfaces(Standard_Integer IC) {
		return NativeHandle->NbComputedSurfaces(IC);
	};

	//! returns the surface number IS concerning the contour IC
	XGeom_Surface^ XBRepFilletAPI_MakeFillet::ComputedSurface(Standard_Integer IC, Standard_Integer IS) {
		return gcnew XGeom_Surface(NativeHandle->ComputedSurface(IC, IS));
	};

	//! returns the number of vertices where the computation failed
	Standard_Integer XBRepFilletAPI_MakeFillet::NbFaultyVertices() {
		return NativeHandle->NbFaultyVertices();
	};

	//! returns the vertex where the computation failed
	XTopoDS_Vertex^ XBRepFilletAPI_MakeFillet::FaultyVertex(Standard_Integer IV) {
		TopoDS_Vertex* temp = new TopoDS_Vertex(NativeHandle->FaultyVertex(IV));
		return gcnew XTopoDS_Vertex(temp);
	};

	//! returns true if a part of the result has been computed
	//! if the filling in a corner failed a shape with a hole is returned
	Standard_Boolean XBRepFilletAPI_MakeFillet::HasResult() {
		return NativeHandle->HasResult();
	};

	//! if (HasResult()) returns the partial result
	XTopoDS_Shape^ XBRepFilletAPI_MakeFillet::BadShape() {
		TopoDS_Shape* temp = new TopoDS_Shape(NativeHandle->BadShape());
		return gcnew XTopoDS_Shape(temp);
	};

	//! returns the status concerning the contour IC in case of error
	//! ChFiDS_Ok : the computation is Ok
	//! ChFiDS_StartsolFailure : the computation can't start, perhaps the
	//! the radius is too big
	//! ChFiDS_TwistedSurface : the computation failed because of a twisted
	//! surface
	//! ChFiDS_WalkingFailure : there is a problem in the walking
	//! ChFiDS_Error:  other error different from above
	XChFiDS_ErrorStatus XBRepFilletAPI_MakeFillet::StripeStatus(Standard_Integer IC) {
		return safe_cast<XChFiDS_ErrorStatus>(NativeHandle->StripeStatus(IC));
	};
}

