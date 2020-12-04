#include "XBRepBuilderAPI_MakeEdge.h"

namespace TKTopAlgo {

	void XBRepBuilderAPI_MakeEdge::Initialize(BRepBuilderAPI_MakeEdge* pos) {
		SetMakeShapeHandle(pos);
	};

	XBRepBuilderAPI_MakeEdge::XBRepBuilderAPI_MakeEdge() {
		NativeHandle = new BRepBuilderAPI_MakeEdge();
		Initialize(NativeHandle);
	};

	BRepBuilderAPI_MakeEdge* XBRepBuilderAPI_MakeEdge::GetMakeEdge() {
		return NativeHandle;
	};

	BRepBuilderAPI_MakeShape* XBRepBuilderAPI_MakeEdge::GetMakeShape() {
		return NativeHandle;
	};

	XBRepBuilderAPI_MakeEdge::XBRepBuilderAPI_MakeEdge(BRepBuilderAPI_MakeEdge* pos) {
		NativeHandle = pos;
		Initialize(NativeHandle);
	};

	void XBRepBuilderAPI_MakeEdge::SetMakeEdgeHandle(BRepBuilderAPI_MakeEdge* pos) {
		NativeHandle = pos;
		Initialize(NativeHandle);
	};

	XBRepBuilderAPI_MakeEdge::XBRepBuilderAPI_MakeEdge(XTopoDS_Vertex^ V1, XTopoDS_Vertex^ V2) {
		NativeHandle = new BRepBuilderAPI_MakeEdge(*V1->GetVertex(), *V2->GetVertex());
		Initialize(NativeHandle);
	};

	XBRepBuilderAPI_MakeEdge::XBRepBuilderAPI_MakeEdge(xgp_Pnt^ P1, xgp_Pnt^ P2) {
		NativeHandle = new BRepBuilderAPI_MakeEdge(P1->GetPnt(), P2->GetPnt());
		Initialize(NativeHandle);
	};

	XBRepBuilderAPI_MakeEdge::XBRepBuilderAPI_MakeEdge(xgp_Lin^ L) {
		NativeHandle = new BRepBuilderAPI_MakeEdge(*L->GetLin());
		Initialize(NativeHandle);
	};

	XBRepBuilderAPI_MakeEdge::XBRepBuilderAPI_MakeEdge(xgp_Lin^ L, Standard_Real p1, Standard_Real p2) {
		NativeHandle = new BRepBuilderAPI_MakeEdge(*L->GetLin(), p1, p2);
		Initialize(NativeHandle);
	};

	XBRepBuilderAPI_MakeEdge::XBRepBuilderAPI_MakeEdge(xgp_Lin^ L, xgp_Pnt^ P1, xgp_Pnt^ P2) {
		NativeHandle = new BRepBuilderAPI_MakeEdge(*L->GetLin(), P1->GetPnt(), P2->GetPnt());
		Initialize(NativeHandle);
	};

	XBRepBuilderAPI_MakeEdge::XBRepBuilderAPI_MakeEdge(xgp_Lin^ L, XTopoDS_Vertex^ V1, XTopoDS_Vertex^ V2) {
		NativeHandle = new BRepBuilderAPI_MakeEdge(*L->GetLin(), *V1->GetVertex(), *V2->GetVertex());
		Initialize(NativeHandle);
	};

	XBRepBuilderAPI_MakeEdge::XBRepBuilderAPI_MakeEdge(xgp_Circ^ L) {
		NativeHandle = new BRepBuilderAPI_MakeEdge(*L->GetCirc());
		Initialize(NativeHandle);
	};

	XBRepBuilderAPI_MakeEdge::XBRepBuilderAPI_MakeEdge(xgp_Circ^ L, Standard_Real p1, Standard_Real p2) {
		NativeHandle = new BRepBuilderAPI_MakeEdge(*L->GetCirc(), p1, p2);
		Initialize(NativeHandle);
	};

	XBRepBuilderAPI_MakeEdge::XBRepBuilderAPI_MakeEdge(xgp_Circ^ L, xgp_Pnt^ P1, xgp_Pnt^ P2) {
		NativeHandle = new BRepBuilderAPI_MakeEdge(*L->GetCirc(), P1->GetPnt(), P2->GetPnt());
		Initialize(NativeHandle);
	};

	XBRepBuilderAPI_MakeEdge::XBRepBuilderAPI_MakeEdge(xgp_Circ^ L, XTopoDS_Vertex^ V1, XTopoDS_Vertex^ V2) {
		NativeHandle = new BRepBuilderAPI_MakeEdge(*L->GetCirc(), *V1->GetVertex(), *V2->GetVertex());
		Initialize(NativeHandle);
	};

	XBRepBuilderAPI_MakeEdge::XBRepBuilderAPI_MakeEdge(xgp_Elips^ L) {
		NativeHandle = new BRepBuilderAPI_MakeEdge(*L->GetElips());
		Initialize(NativeHandle);
	};

	XBRepBuilderAPI_MakeEdge::XBRepBuilderAPI_MakeEdge(xgp_Elips^ L, Standard_Real p1, Standard_Real p2) {
		NativeHandle = new BRepBuilderAPI_MakeEdge(*L->GetElips(), p1, p2);
		Initialize(NativeHandle);
	};

	XBRepBuilderAPI_MakeEdge::XBRepBuilderAPI_MakeEdge(xgp_Elips^ L, xgp_Pnt^ P1, xgp_Pnt^ P2) {
		NativeHandle = new BRepBuilderAPI_MakeEdge(*L->GetElips(), P1->GetPnt(), P2->GetPnt());
		Initialize(NativeHandle);
	};

	XBRepBuilderAPI_MakeEdge::XBRepBuilderAPI_MakeEdge(xgp_Elips^ L, XTopoDS_Vertex^ V1, XTopoDS_Vertex^ V2) {
		NativeHandle = new BRepBuilderAPI_MakeEdge(*L->GetElips(), *V1->GetVertex(), *V2->GetVertex());
		Initialize(NativeHandle);
	};

	XBRepBuilderAPI_MakeEdge::XBRepBuilderAPI_MakeEdge(xgp_Hypr^ L) {
		NativeHandle = new BRepBuilderAPI_MakeEdge(*L->GetHypr());
		Initialize(NativeHandle);
	};

	XBRepBuilderAPI_MakeEdge::XBRepBuilderAPI_MakeEdge(xgp_Hypr^ L, Standard_Real p1, Standard_Real p2) {
		NativeHandle = new BRepBuilderAPI_MakeEdge(*L->GetHypr(), p1, p2);
		Initialize(NativeHandle);
	};

	XBRepBuilderAPI_MakeEdge::XBRepBuilderAPI_MakeEdge(xgp_Hypr^ L, xgp_Pnt^ P1, xgp_Pnt^ P2) {
		NativeHandle = new BRepBuilderAPI_MakeEdge(*L->GetHypr(), P1->GetPnt(), P2->GetPnt());
		Initialize(NativeHandle);
	};

	XBRepBuilderAPI_MakeEdge::XBRepBuilderAPI_MakeEdge(xgp_Hypr^ L, XTopoDS_Vertex^ V1, XTopoDS_Vertex^ V2) {
		NativeHandle = new BRepBuilderAPI_MakeEdge(*L->GetHypr(), *V1->GetVertex(), *V2->GetVertex());
		Initialize(NativeHandle);
	};

	XBRepBuilderAPI_MakeEdge::XBRepBuilderAPI_MakeEdge(xgp_Parab^ L) {
		NativeHandle = new BRepBuilderAPI_MakeEdge(L->GetParab());
		Initialize(NativeHandle);
	};

	XBRepBuilderAPI_MakeEdge::XBRepBuilderAPI_MakeEdge(xgp_Parab^ L, Standard_Real p1, Standard_Real p2) {
		NativeHandle = new BRepBuilderAPI_MakeEdge(L->GetParab(), p1, p2);
		Initialize(NativeHandle);
	};

	XBRepBuilderAPI_MakeEdge::XBRepBuilderAPI_MakeEdge(xgp_Parab^ L, xgp_Pnt^ P1, xgp_Pnt^ P2) {
		NativeHandle = new BRepBuilderAPI_MakeEdge(L->GetParab(), P1->GetPnt(), P2->GetPnt());
		Initialize(NativeHandle);
	};

	XBRepBuilderAPI_MakeEdge::XBRepBuilderAPI_MakeEdge(xgp_Parab^ L, XTopoDS_Vertex^ V1, XTopoDS_Vertex^ V2) {
		NativeHandle = new BRepBuilderAPI_MakeEdge(L->GetParab(), *V1->GetVertex(), *V2->GetVertex());
		Initialize(NativeHandle);
	};

	XBRepBuilderAPI_MakeEdge::XBRepBuilderAPI_MakeEdge(XGeom_Curve^ L) {
		NativeHandle = new BRepBuilderAPI_MakeEdge(L->GetCurve());
		Initialize(NativeHandle);
	};

	XBRepBuilderAPI_MakeEdge::XBRepBuilderAPI_MakeEdge(XGeom_Curve^ L, Standard_Real p1, Standard_Real p2) {
		NativeHandle = new BRepBuilderAPI_MakeEdge(L->GetCurve(), p1, p2);
		Initialize(NativeHandle);
	};

	XBRepBuilderAPI_MakeEdge::XBRepBuilderAPI_MakeEdge(XGeom_Curve^ L, xgp_Pnt^ P1, xgp_Pnt^ P2) {
		NativeHandle = new BRepBuilderAPI_MakeEdge(L->GetCurve(), P1->GetPnt(), P2->GetPnt());
		Initialize(NativeHandle);
	};

	XBRepBuilderAPI_MakeEdge::XBRepBuilderAPI_MakeEdge(XGeom_Curve^ L, XTopoDS_Vertex^ V1, XTopoDS_Vertex^ V2) {
		NativeHandle = new BRepBuilderAPI_MakeEdge(L->GetCurve(), *V1->GetVertex(), *V2->GetVertex());
		Initialize(NativeHandle);
	};

	XBRepBuilderAPI_MakeEdge::XBRepBuilderAPI_MakeEdge(XGeom_Curve^ L, xgp_Pnt^ P1, xgp_Pnt^ P2, Standard_Real p1, Standard_Real p2) {
		NativeHandle = new BRepBuilderAPI_MakeEdge(L->GetCurve(), P1->GetPnt(), P2->GetPnt(), p1, p2);
		Initialize(NativeHandle);
	};

	XBRepBuilderAPI_MakeEdge::XBRepBuilderAPI_MakeEdge(XGeom_Curve^ L, XTopoDS_Vertex^ V1, XTopoDS_Vertex^ V2, Standard_Real p1, Standard_Real p2) {
		NativeHandle = new BRepBuilderAPI_MakeEdge(L->GetCurve(), *V1->GetVertex(), *V2->GetVertex(), p1, p2);
		Initialize(NativeHandle);
	};

	XBRepBuilderAPI_MakeEdge::XBRepBuilderAPI_MakeEdge(XGeom2d_Curve^ L, XGeom_Surface^ S) {
		NativeHandle = new BRepBuilderAPI_MakeEdge(L->GetCurve(), S->GetSurface());
		Initialize(NativeHandle);
	};

	XBRepBuilderAPI_MakeEdge::XBRepBuilderAPI_MakeEdge(XGeom2d_Curve^ L, XGeom_Surface^ S, Standard_Real p1, Standard_Real p2) {
		NativeHandle = new BRepBuilderAPI_MakeEdge(L->GetCurve(), S->GetSurface(), p1, p2);
		Initialize(NativeHandle);
	};

	XBRepBuilderAPI_MakeEdge::XBRepBuilderAPI_MakeEdge(XGeom2d_Curve^ L, XGeom_Surface^ S, xgp_Pnt^ P1, xgp_Pnt^ P2) {
		NativeHandle = new BRepBuilderAPI_MakeEdge(L->GetCurve(), S->GetSurface(), P1->GetPnt(), P2->GetPnt());
		Initialize(NativeHandle);
	};

	XBRepBuilderAPI_MakeEdge::XBRepBuilderAPI_MakeEdge(XGeom2d_Curve^ L, XGeom_Surface^ S, XTopoDS_Vertex^ V1, XTopoDS_Vertex^ V2) {
		NativeHandle = new BRepBuilderAPI_MakeEdge(L->GetCurve(), S->GetSurface(), *V1->GetVertex(), *V2->GetVertex());
		Initialize(NativeHandle);
	};

	XBRepBuilderAPI_MakeEdge::XBRepBuilderAPI_MakeEdge(XGeom2d_Curve^ L, XGeom_Surface^ S, xgp_Pnt^ P1, xgp_Pnt^ P2, Standard_Real p1, Standard_Real p2) {
		NativeHandle = new BRepBuilderAPI_MakeEdge(L->GetCurve(), S->GetSurface(), P1->GetPnt(), P2->GetPnt(), p1, p2);
		Initialize(NativeHandle);
	};

	//! Auxiliary methods
	XBRepBuilderAPI_MakeEdge::XBRepBuilderAPI_MakeEdge(XGeom2d_Curve^ L, XGeom_Surface^ S, XTopoDS_Vertex^ V1, XTopoDS_Vertex^ V2, Standard_Real p1, Standard_Real p2) {
		NativeHandle = new BRepBuilderAPI_MakeEdge(L->GetCurve(), S->GetSurface(), *V1->GetVertex(), *V2->GetVertex(), p1, p2);
		Initialize(NativeHandle);
	};

	void XBRepBuilderAPI_MakeEdge::Init(XGeom_Curve^ C) {
		NativeHandle->Init(C->GetCurve());
	};

	void XBRepBuilderAPI_MakeEdge::Init(XGeom_Curve^ C, Standard_Real p1, Standard_Real p2) {
		NativeHandle->Init(C->GetCurve(), p1, p2);
	};

	void XBRepBuilderAPI_MakeEdge::Init(XGeom_Curve^ C, xgp_Pnt^ P1, xgp_Pnt^ P2) {
		NativeHandle->Init(C->GetCurve(), P1->GetPnt(), P2->GetPnt());
	};

	void XBRepBuilderAPI_MakeEdge::Init(XGeom_Curve^ C, XTopoDS_Vertex^ V1, XTopoDS_Vertex^ V2) {
		NativeHandle->Init(C->GetCurve(), *V1->GetVertex(), *V2->GetVertex());
	};

	void XBRepBuilderAPI_MakeEdge::Init(XGeom_Curve^ C, xgp_Pnt^ P1, xgp_Pnt^ P2, Standard_Real p1, Standard_Real p2) {
		NativeHandle->Init(C->GetCurve(), P1->GetPnt(), P2->GetPnt(), p1, p2);
	};

	void XBRepBuilderAPI_MakeEdge::Init(XGeom_Curve^ C, XTopoDS_Vertex^ V1, XTopoDS_Vertex^ V2, Standard_Real p1, Standard_Real p2) {
		NativeHandle->Init(C->GetCurve(), *V1->GetVertex(), *V2->GetVertex(), p1, p2);
	};

	void XBRepBuilderAPI_MakeEdge::Init(XGeom2d_Curve^ C, XGeom_Surface^ S) {
		NativeHandle->Init(C->GetCurve(), S->GetSurface());
	};

	void XBRepBuilderAPI_MakeEdge::Init(XGeom2d_Curve^ C, XGeom_Surface^ S, Standard_Real p1, Standard_Real p2) {
		NativeHandle->Init(C->GetCurve(), S->GetSurface(), p1, p2);
	};

	void XBRepBuilderAPI_MakeEdge::Init(XGeom2d_Curve^ C, XGeom_Surface^ S, xgp_Pnt^ P1, xgp_Pnt^ P2) {
		NativeHandle->Init(C->GetCurve(), S->GetSurface(), P1->GetPnt(), P2->GetPnt());
	};

	void XBRepBuilderAPI_MakeEdge::Init(XGeom2d_Curve^ C, XGeom_Surface^ S, XTopoDS_Vertex^ V1, XTopoDS_Vertex^ V2) {
		NativeHandle->Init(C->GetCurve(), S->GetSurface(), *V1->GetVertex(), *V2->GetVertex());
	};

	void XBRepBuilderAPI_MakeEdge::Init(XGeom2d_Curve^ C, XGeom_Surface^ S, xgp_Pnt^ P1, xgp_Pnt^ P2, Standard_Real p1, Standard_Real p2) {
		NativeHandle->Init(C->GetCurve(), S->GetSurface(), P1->GetPnt(), P2->GetPnt(), p1, p2);
	};

	//! Defines or redefines the arguments for the construction of an edge.
	//! This function is currently used after the empty constructor BRepAPI_MakeEdge().
	void XBRepBuilderAPI_MakeEdge::Init(XGeom2d_Curve^ C, XGeom_Surface^ S, XTopoDS_Vertex^ V1, XTopoDS_Vertex^ V2, Standard_Real p1, Standard_Real p2) {
		NativeHandle->Init(C->GetCurve(),S->GetSurface(), *V1->GetVertex(), *V2->GetVertex(), p1, p2);
	};

	//! Returns true if the edge is built.
    Standard_Boolean XBRepBuilderAPI_MakeEdge::IsDone() {
		return NativeHandle->IsDone();
	};

	//! Returns the construction status
	//! -   BRepBuilderAPI_EdgeDone if the edge is built, or
	//! -   another value of the BRepBuilderAPI_EdgeError
	//! enumeration indicating the reason of construction failure.
	XBRepBuilderAPI_EdgeError XBRepBuilderAPI_MakeEdge::Error() {
		 return safe_cast<XBRepBuilderAPI_EdgeError>(NativeHandle->Error());
	};


	//! Returns the constructed edge.
	//! Exceptions StdFail_NotDone if the edge is not built.
	XTopoDS_Edge^ XBRepBuilderAPI_MakeEdge::Edge() {
		TopoDS_Edge* edge = new TopoDS_Edge(NativeHandle->Edge());
		return gcnew XTopoDS_Edge(edge);
	};
	XBRepBuilderAPI_MakeEdge::operator XTopoDS_Edge^() {
		TopoDS_Edge* edge = new TopoDS_Edge(NativeHandle->Edge());
		return gcnew XTopoDS_Edge(edge);
	};

	XTopoDS_Shape^ XBRepBuilderAPI_MakeEdge::Shape() {
		TopoDS_Shape* Shape = new TopoDS_Shape(NativeHandle->Shape());
		return gcnew XTopoDS_Shape(Shape);
	};

	//! Returns the first vertex of the edge. May be Null.
	XTopoDS_Vertex^ XBRepBuilderAPI_MakeEdge::Vertex1() {
		TopoDS_Vertex* vertex = new TopoDS_Vertex(NativeHandle->Vertex1());
		return gcnew XTopoDS_Vertex(vertex);
	};

	//! Returns the second vertex of the edge. May be Null.
	//!
	//! Warning
	//! The returned vertex in each function corresponds respectively to
	//! -   the lowest, or
	//! -   the highest parameter on the curve along which the edge is built.
	//! It does not correspond to the first or second vertex
	//! given at the time of the construction, if the edge is oriented reversed.
	//! Exceptions
	//! StdFail_NotDone if the edge is not built.
	XTopoDS_Vertex^ XBRepBuilderAPI_MakeEdge::Vertex2() {
		TopoDS_Vertex* vertex = new TopoDS_Vertex(NativeHandle->Vertex2());
		return gcnew XTopoDS_Vertex(vertex);
	};
}