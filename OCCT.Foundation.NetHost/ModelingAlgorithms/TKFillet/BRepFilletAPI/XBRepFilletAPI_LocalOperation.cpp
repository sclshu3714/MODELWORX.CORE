#include <XBRepFilletAPI_LocalOperation.h>

namespace TKFillet {
	//! DEFINE_STANDARD_ALLOC

	XBRepFilletAPI_LocalOperation::XBRepFilletAPI_LocalOperation() {
		//NativeHandle = new BRepFilletAPI_LocalOperation();
	};

	XBRepFilletAPI_LocalOperation::XBRepFilletAPI_LocalOperation(BRepFilletAPI_LocalOperation* handle) {
		NativeHandle = handle;
		SetMakeShapeHandle(NativeHandle);
	};

	void XBRepFilletAPI_LocalOperation::SetLocalOperationHandle(BRepFilletAPI_LocalOperation* handle) {
		NativeHandle = handle;
		SetMakeShapeHandle(NativeHandle);
	};

	BRepFilletAPI_LocalOperation* XBRepFilletAPI_LocalOperation::GetLocalOperation() {
		return NativeHandle;
	};

	BRepBuilderAPI_MakeShape* XBRepFilletAPI_LocalOperation::GetMakeShape() {
		return NativeHandle;
	};

	//! Returns a shape built by the shape construction algorithm.
	//! Raises exception StdFail_NotDone if the shape was not built.
	XTopoDS_Shape^ XBRepFilletAPI_LocalOperation::Shape() {
		TopoDS_Shape* temp = new TopoDS_Shape(NativeHandle->Shape());
		return gcnew XTopoDS_Shape(temp);
	};
	//! Adds a  contour in  the  builder  (builds a
	//! contour  of tangent edges).
	void XBRepFilletAPI_LocalOperation::Add(XTopoDS_Edge^ E) {
		NativeHandle->Add(*E->GetEdge());
	};

	//! Reset the contour of index IC, there is nomore
	//! information in the contour.
	void XBRepFilletAPI_LocalOperation::ResetContour(Standard_Integer IC) {
		NativeHandle->ResetContour(IC);
	};

	//! Number of contours.
	Standard_Integer XBRepFilletAPI_LocalOperation::NbContours() {
		return NativeHandle->NbContours();
	};

	//! Returns the index of  the  contour containing the edge
	//! E, returns 0 if E doesn't belong to any contour.
	Standard_Integer XBRepFilletAPI_LocalOperation::Contour(XTopoDS_Edge^ E) {
		return NativeHandle->Contour(*E->GetEdge());
	};

	//! Number of Edges in the contour I.
	Standard_Integer XBRepFilletAPI_LocalOperation::NbEdges(Standard_Integer I) {
		return NativeHandle->NbEdges(I);
	};

	//! Returns the Edge J in the contour I.
	XTopoDS_Edge^ XBRepFilletAPI_LocalOperation::Edge(Standard_Integer I, Standard_Integer J) {
		TopoDS_Edge* temp = new TopoDS_Edge(NativeHandle->Edge(I, J));
		return gcnew XTopoDS_Edge(temp);
	};

	//! remove the contour containing the Edge E.
	void XBRepFilletAPI_LocalOperation::Remove(XTopoDS_Edge^ E) {
		NativeHandle->Remove(*E->GetEdge());
	};

	//! returns the length the contour of index IC.
	Standard_Real XBRepFilletAPI_LocalOperation::Length(Standard_Integer IC) {
		return NativeHandle->Length(IC);
	};

	//! Returns the first Vertex of the contour of index IC.
	XTopoDS_Vertex^ XBRepFilletAPI_LocalOperation::FirstVertex(Standard_Integer IC) {
		TopoDS_Vertex* temp = new TopoDS_Vertex(NativeHandle->FirstVertex(IC));
		return gcnew XTopoDS_Vertex(temp);
	};

	//! Returns the last Vertex of the contour of index IC.
	XTopoDS_Vertex^ XBRepFilletAPI_LocalOperation::LastVertex(Standard_Integer IC) {
		TopoDS_Vertex* temp = new TopoDS_Vertex(NativeHandle->LastVertex(IC));
		return gcnew XTopoDS_Vertex(temp);
	};

	//! returns the abscissa of the vertex V on
	//! the contour of index IC.
	Standard_Real XBRepFilletAPI_LocalOperation::Abscissa(Standard_Integer IC, XTopoDS_Vertex^ V) {
		return NativeHandle->Abscissa(IC, *V->GetVertex());
	};

	//! returns the relative abscissa([0.,1.]) of the
	//! vertex V on the contour of index IC.
	Standard_Real XBRepFilletAPI_LocalOperation::RelativeAbscissa(Standard_Integer IC, XTopoDS_Vertex^ V) {
		return NativeHandle->RelativeAbscissa(IC, *V->GetVertex());
	};

	//! returns true if the contour of index IC is closed
	//! an tangent.
	Standard_Boolean XBRepFilletAPI_LocalOperation::ClosedAndTangent(Standard_Integer IC) {
		return NativeHandle->ClosedAndTangent(IC);
	};

	//! returns true if the contour of index IC is closed
	Standard_Boolean XBRepFilletAPI_LocalOperation::Closed(Standard_Integer IC) {
		return NativeHandle->Closed(IC);
	};

	//! Reset all the fields updated   by Build operation  and
	//! leave the  algorithm in  the  same state  than  before
	//! build    call.  It   allows   contours    and   radius
	//! modifications  to build the result another time.
	void XBRepFilletAPI_LocalOperation::Reset() {
		NativeHandle->Reset();
	};

	void XBRepFilletAPI_LocalOperation::Simulate(Standard_Integer IC) {
		NativeHandle->Simulate(IC);
	};

	Standard_Integer XBRepFilletAPI_LocalOperation::NbSurf(Standard_Integer IC) {
		return NativeHandle->NbSurf(IC);
	};

	Handle(ChFiDS_SecHArray1) XBRepFilletAPI_LocalOperation::Sect(Standard_Integer IC, Standard_Integer IS) {
		return NativeHandle->Sect(IC, IS);
	};
}
