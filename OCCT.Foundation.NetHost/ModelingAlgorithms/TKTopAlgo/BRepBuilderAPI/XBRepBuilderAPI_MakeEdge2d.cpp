#include <XBRepBuilderAPI_MakeEdge2d.h>
namespace TKTopAlgo {
	//! DEFINE_STANDARD_ALLOC
	XBRepBuilderAPI_MakeEdge2d::XBRepBuilderAPI_MakeEdge2d() {
		//NativeHandle = new BRepBuilderAPI_MakeEdge2d();
	};

	void XBRepBuilderAPI_MakeEdge2d::SetMakeEdge2dHandle(BRepBuilderAPI_MakeEdge2d* handle) {
		NativeHandle = handle;
		SetMakeShapeHandle(NativeHandle);
	};

	BRepBuilderAPI_MakeEdge2d* XBRepBuilderAPI_MakeEdge2d::GetMakeEdge2d() {
		return NativeHandle;
	};

	BRepBuilderAPI_MakeShape* XBRepBuilderAPI_MakeEdge2d::GetMakeShape() {
		return NativeHandle;
	};

	XBRepBuilderAPI_MakeEdge2d::XBRepBuilderAPI_MakeEdge2d(XTopoDS_Vertex^ V1, XTopoDS_Vertex^ V2) {
		NativeHandle = new BRepBuilderAPI_MakeEdge2d(*V1->GetVertex(), *V2->GetVertex());
		SetMakeShapeHandle(NativeHandle);
	};

	XBRepBuilderAPI_MakeEdge2d::XBRepBuilderAPI_MakeEdge2d(xgp_Pnt2d^ P1, xgp_Pnt2d^ P2) {
		NativeHandle = new BRepBuilderAPI_MakeEdge2d(*P1->GetPnt2d(), *P2->GetPnt2d());
		SetMakeShapeHandle(NativeHandle);
	};

	XBRepBuilderAPI_MakeEdge2d::XBRepBuilderAPI_MakeEdge2d(xgp_Lin2d^ L) {
		NativeHandle = new BRepBuilderAPI_MakeEdge2d(*L->GetLin2d());
		SetMakeShapeHandle(NativeHandle);
	};

	XBRepBuilderAPI_MakeEdge2d::XBRepBuilderAPI_MakeEdge2d(xgp_Lin2d^ L, Standard_Real p1, Standard_Real p2) {
		NativeHandle = new BRepBuilderAPI_MakeEdge2d(*L->GetLin2d(), p1, p2);
		SetMakeShapeHandle(NativeHandle);
	};

	XBRepBuilderAPI_MakeEdge2d::XBRepBuilderAPI_MakeEdge2d(xgp_Lin2d^ L, xgp_Pnt2d^ P1, xgp_Pnt2d^ P2) {
		NativeHandle = new BRepBuilderAPI_MakeEdge2d(*L->GetLin2d(), *P1->GetPnt2d(), *P2->GetPnt2d());
		SetMakeShapeHandle(NativeHandle);
	};

	XBRepBuilderAPI_MakeEdge2d::XBRepBuilderAPI_MakeEdge2d(xgp_Lin2d^ L, XTopoDS_Vertex^ V1, XTopoDS_Vertex^ V2) {
		NativeHandle = new BRepBuilderAPI_MakeEdge2d(*L->GetLin2d(), *V1->GetVertex(), *V2->GetVertex());
		SetMakeShapeHandle(NativeHandle);
	};

	XBRepBuilderAPI_MakeEdge2d::XBRepBuilderAPI_MakeEdge2d(xgp_Circ2d^ L) {
		NativeHandle = new BRepBuilderAPI_MakeEdge2d(*L->GetCirc2d());
		SetMakeShapeHandle(NativeHandle);
	};

	XBRepBuilderAPI_MakeEdge2d::XBRepBuilderAPI_MakeEdge2d(xgp_Circ2d^ L, Standard_Real p1, Standard_Real p2) {
		NativeHandle = new BRepBuilderAPI_MakeEdge2d(*L->GetCirc2d(), p1, p2);
		SetMakeShapeHandle(NativeHandle);
	};

	XBRepBuilderAPI_MakeEdge2d::XBRepBuilderAPI_MakeEdge2d(xgp_Circ2d^ L, xgp_Pnt2d^ P1, xgp_Pnt2d^ P2) {
		NativeHandle = new BRepBuilderAPI_MakeEdge2d(*L->GetCirc2d(), *P1->GetPnt2d(), *P2->GetPnt2d());
		SetMakeShapeHandle(NativeHandle);
	};

	XBRepBuilderAPI_MakeEdge2d::XBRepBuilderAPI_MakeEdge2d(xgp_Circ2d^ L, XTopoDS_Vertex^ V1, XTopoDS_Vertex^ V2) {
		NativeHandle = new BRepBuilderAPI_MakeEdge2d(*L->GetCirc2d(), *V1->GetVertex(), *V2->GetVertex());
		SetMakeShapeHandle(NativeHandle);
	};

	XBRepBuilderAPI_MakeEdge2d::XBRepBuilderAPI_MakeEdge2d(xgp_Elips2d^ L) {
		NativeHandle = new BRepBuilderAPI_MakeEdge2d(*L->GetElips2d());
		SetMakeShapeHandle(NativeHandle);
	};

	XBRepBuilderAPI_MakeEdge2d::XBRepBuilderAPI_MakeEdge2d(xgp_Elips2d^ L, Standard_Real p1, Standard_Real p2) {
		NativeHandle = new BRepBuilderAPI_MakeEdge2d(*L->GetElips2d(), p1, p2);
		SetMakeShapeHandle(NativeHandle);
	};

	XBRepBuilderAPI_MakeEdge2d::XBRepBuilderAPI_MakeEdge2d(xgp_Elips2d^ L, xgp_Pnt2d^ P1, xgp_Pnt2d^ P2) {
		NativeHandle = new BRepBuilderAPI_MakeEdge2d(*L->GetElips2d(), *P1->GetPnt2d(), *P2->GetPnt2d());
		SetMakeShapeHandle(NativeHandle);
	};

	XBRepBuilderAPI_MakeEdge2d::XBRepBuilderAPI_MakeEdge2d(xgp_Elips2d^ L, XTopoDS_Vertex^ V1, XTopoDS_Vertex^ V2) {
		NativeHandle = new BRepBuilderAPI_MakeEdge2d(*L->GetElips2d(), *V1->GetVertex(), *V2->GetVertex());
		SetMakeShapeHandle(NativeHandle);
	};

	XBRepBuilderAPI_MakeEdge2d::XBRepBuilderAPI_MakeEdge2d(xgp_Hypr2d^ L) {
		NativeHandle = new BRepBuilderAPI_MakeEdge2d(*L->GetHypr2d());
		SetMakeShapeHandle(NativeHandle);
	};

	XBRepBuilderAPI_MakeEdge2d::XBRepBuilderAPI_MakeEdge2d(xgp_Hypr2d^ L, Standard_Real p1, Standard_Real p2) {
		NativeHandle = new BRepBuilderAPI_MakeEdge2d(*L->GetHypr2d(), p1, p2);
		SetMakeShapeHandle(NativeHandle);
	};

	XBRepBuilderAPI_MakeEdge2d::XBRepBuilderAPI_MakeEdge2d(xgp_Hypr2d^ L, xgp_Pnt2d^ P1, xgp_Pnt2d^ P2) {
		NativeHandle = new BRepBuilderAPI_MakeEdge2d(*L->GetHypr2d(), *P1->GetPnt2d(), *P2->GetPnt2d());
		SetMakeShapeHandle(NativeHandle);
	};

	XBRepBuilderAPI_MakeEdge2d::XBRepBuilderAPI_MakeEdge2d(xgp_Hypr2d^ L, XTopoDS_Vertex^ V1, XTopoDS_Vertex^ V2) {
		NativeHandle = new BRepBuilderAPI_MakeEdge2d(*L->GetHypr2d(), *V1->GetVertex(), *V2->GetVertex());
		SetMakeShapeHandle(NativeHandle);
	};

	XBRepBuilderAPI_MakeEdge2d::XBRepBuilderAPI_MakeEdge2d(xgp_Parab2d^ L) {
		NativeHandle = new BRepBuilderAPI_MakeEdge2d(*L->GetParab2d());
		SetMakeShapeHandle(NativeHandle);
	};

	XBRepBuilderAPI_MakeEdge2d::XBRepBuilderAPI_MakeEdge2d(xgp_Parab2d^ L, Standard_Real p1, Standard_Real p2) {
		NativeHandle = new BRepBuilderAPI_MakeEdge2d(*L->GetParab2d(), p1, p2);
		SetMakeShapeHandle(NativeHandle);
	};

	XBRepBuilderAPI_MakeEdge2d::XBRepBuilderAPI_MakeEdge2d(xgp_Parab2d^ L, xgp_Pnt2d^ P1, xgp_Pnt2d^ P2) {
		NativeHandle = new BRepBuilderAPI_MakeEdge2d(*L->GetParab2d(), *P1->GetPnt2d(), *P2->GetPnt2d());
		SetMakeShapeHandle(NativeHandle);
	};

	XBRepBuilderAPI_MakeEdge2d::XBRepBuilderAPI_MakeEdge2d(xgp_Parab2d^ L, XTopoDS_Vertex^ V1, XTopoDS_Vertex^ V2) {
		NativeHandle = new BRepBuilderAPI_MakeEdge2d(*L->GetParab2d(), *V1->GetVertex(), *V2->GetVertex());
		SetMakeShapeHandle(NativeHandle);
	};

	XBRepBuilderAPI_MakeEdge2d::XBRepBuilderAPI_MakeEdge2d(XGeom2d_Curve^ L) {
		NativeHandle = new BRepBuilderAPI_MakeEdge2d(L->GetCurve());
		SetMakeShapeHandle(NativeHandle);
	};

	XBRepBuilderAPI_MakeEdge2d::XBRepBuilderAPI_MakeEdge2d(XGeom2d_Curve^ L, Standard_Real p1, Standard_Real p2) {
		NativeHandle = new BRepBuilderAPI_MakeEdge2d(L->GetCurve(), p1, p2);
		SetMakeShapeHandle(NativeHandle);
	};

	XBRepBuilderAPI_MakeEdge2d::XBRepBuilderAPI_MakeEdge2d(XGeom2d_Curve^ L, xgp_Pnt2d^ P1, xgp_Pnt2d^ P2) {
		NativeHandle = new BRepBuilderAPI_MakeEdge2d(L->GetCurve(), *P1->GetPnt2d(), *P2->GetPnt2d());
		SetMakeShapeHandle(NativeHandle);
	};

	XBRepBuilderAPI_MakeEdge2d::XBRepBuilderAPI_MakeEdge2d(XGeom2d_Curve^ L, XTopoDS_Vertex^ V1, XTopoDS_Vertex^ V2) {
		NativeHandle = new BRepBuilderAPI_MakeEdge2d(L->GetCurve(), *V1->GetVertex(), *V2->GetVertex());
		SetMakeShapeHandle(NativeHandle);
	};

	XBRepBuilderAPI_MakeEdge2d::XBRepBuilderAPI_MakeEdge2d(XGeom2d_Curve^ L, xgp_Pnt2d^ P1, xgp_Pnt2d^ P2, Standard_Real p1, Standard_Real p2) {
		NativeHandle = new BRepBuilderAPI_MakeEdge2d(L->GetCurve(), *P1->GetPnt2d(), *P2->GetPnt2d(), p1, p2);
		SetMakeShapeHandle(NativeHandle);
	};

	XBRepBuilderAPI_MakeEdge2d::XBRepBuilderAPI_MakeEdge2d(XGeom2d_Curve^ L, XTopoDS_Vertex^ V1, XTopoDS_Vertex^ V2, Standard_Real p1, Standard_Real p2) {
		NativeHandle = new BRepBuilderAPI_MakeEdge2d(L->GetCurve(), *V1->GetVertex(), *V2->GetVertex(), p1, p2);
		SetMakeShapeHandle(NativeHandle);
	};

	void XBRepBuilderAPI_MakeEdge2d::Init(XGeom2d_Curve^ C) {
		NativeHandle->Init(C->GetCurve());
	};

	void XBRepBuilderAPI_MakeEdge2d::Init(XGeom2d_Curve^ C, Standard_Real p1, Standard_Real p2) {
		NativeHandle->Init(C->GetCurve(), p1, p2);
	};

	void XBRepBuilderAPI_MakeEdge2d::Init(XGeom2d_Curve^ C, xgp_Pnt2d^ P1, xgp_Pnt2d^ P2) {
		NativeHandle->Init(C->GetCurve(), *P1->GetPnt2d(), *P2->GetPnt2d());
	};

	void XBRepBuilderAPI_MakeEdge2d::Init(XGeom2d_Curve^ C, XTopoDS_Vertex^ V1, XTopoDS_Vertex^ V2) {
		NativeHandle->Init(C->GetCurve(), *V1->GetVertex(), *V2->GetVertex());
	};

	void XBRepBuilderAPI_MakeEdge2d::Init(XGeom2d_Curve^ C, xgp_Pnt2d^ P1, xgp_Pnt2d^ P2, Standard_Real p1, Standard_Real p2) {
		NativeHandle->Init(C->GetCurve(), *P1->GetPnt2d(), *P2->GetPnt2d(), p1, p2);
	};

	void XBRepBuilderAPI_MakeEdge2d::Init(XGeom2d_Curve^ C, XTopoDS_Vertex^ V1, XTopoDS_Vertex^ V2, Standard_Real p1, Standard_Real p2) {
		NativeHandle->Init(C->GetCurve(), *V1->GetVertex(), *V2->GetVertex(), p1, p2);
	};

	Standard_Boolean XBRepBuilderAPI_MakeEdge2d::IsDone() {
		return NativeHandle->IsDone();
	};

	//! Returns the error description when NotDone.
	XBRepBuilderAPI_EdgeError XBRepBuilderAPI_MakeEdge2d::Error() {
		return safe_cast<XBRepBuilderAPI_EdgeError>(NativeHandle->Error());
	};

	XTopoDS_Edge^ XBRepBuilderAPI_MakeEdge2d::Edge() {
		TopoDS_Edge* temp = new TopoDS_Edge(NativeHandle->Edge());
		return gcnew XTopoDS_Edge(temp);
	};
	XBRepBuilderAPI_MakeEdge2d::operator XTopoDS_Edge^() {
		TopoDS_Edge* temp = new TopoDS_Edge(NativeHandle->Edge());
		return gcnew XTopoDS_Edge(temp);
	};

	//! Returns the first vertex of the edge. May be Null.
	XTopoDS_Vertex^ XBRepBuilderAPI_MakeEdge2d::Vertex1() {
		TopoDS_Vertex* temp = new TopoDS_Vertex(NativeHandle->Vertex1());
		return gcnew XTopoDS_Vertex(temp);
	};

	//! Returns the second vertex of the edge. May be Null.
	XTopoDS_Vertex^ XBRepBuilderAPI_MakeEdge2d::Vertex2() {
		TopoDS_Vertex* temp = new TopoDS_Vertex(NativeHandle->Vertex2());
		return gcnew XTopoDS_Vertex(temp);
	};
}