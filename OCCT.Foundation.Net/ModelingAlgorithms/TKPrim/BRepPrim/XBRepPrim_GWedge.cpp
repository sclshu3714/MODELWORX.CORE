#include <XBRepPrim_GWedge.h>
namespace TKPrim {
	//! DEFINE_STANDARD_ALLOC

	XBRepPrim_GWedge::XBRepPrim_GWedge() {};

	XBRepPrim_GWedge::XBRepPrim_GWedge(BRepPrim_GWedge* handle) {
		NativeHandle = handle;
	};


	void XBRepPrim_GWedge::SetGWedgeHandle(BRepPrim_GWedge* handle) {
		NativeHandle = handle;
	};


	BRepPrim_GWedge* XBRepPrim_GWedge::GetGWedge() {
		return NativeHandle;
	};

	//! Creates a  GWedge  algorithm.   <Axes> is  the axis
	//! system for the primitive.
	//!
	//! XMin, YMin, ZMin are set to 0
	//! XMax, YMax, ZMax are set to dx, dy, dz
	//! Z2Min = ZMin
	//! Z2Max = ZMax
	//! X2Min = XMin
	//! X2Max = XMax
	//! The result is a box
	//! dx,dy,dz should be positive
	XBRepPrim_GWedge::XBRepPrim_GWedge(XBRepPrim_Builder^ B, xgp_Ax2^ Axes, Standard_Real dx, Standard_Real dy, Standard_Real dz) {
		NativeHandle = new BRepPrim_GWedge(*B->GetBRepPrimBuilder(), *Axes->GetAx2(), dx, dy, dz);
	};

	//! Creates  a GWedge  primitive. <Axes> is   the  axis
	//! system for the primitive.
	//!
	//! XMin, YMin, ZMin are set to 0
	//! XMax, YMax, ZMax are set to dx, dy, dz
	//! Z2Min = ZMin
	//! Z2Max = ZMax
	//! X2Min = ltx
	//! X2Max = ltx
	//! The result is a STEP right angular wedge
	//! dx,dy,dz should be positive
	//! ltx should not be negative
	XBRepPrim_GWedge::XBRepPrim_GWedge(XBRepPrim_Builder^ B, xgp_Ax2^ Axes, Standard_Real dx, Standard_Real dy, Standard_Real dz, Standard_Real ltx) {
		NativeHandle = new BRepPrim_GWedge(*B->GetBRepPrimBuilder(), *Axes->GetAx2(), dx, dy, dz, ltx);
	};

	//! Create  a GWedge primitive.   <Axes>  is  the  axis
	//! system for the primitive.
	//!
	//! all the fields are set to the corresponding value
	//! XYZMax - XYZMin should be positive
	//! ZX2Max - ZX2Min should not be negative
	XBRepPrim_GWedge::XBRepPrim_GWedge(XBRepPrim_Builder^ B, xgp_Ax2^ Axes, Standard_Real xmin, Standard_Real ymin, Standard_Real zmin, Standard_Real z2min, Standard_Real x2min, Standard_Real xmax, Standard_Real ymax, Standard_Real zmax, Standard_Real z2max, Standard_Real x2max) {
		NativeHandle = new BRepPrim_GWedge(*B->GetBRepPrimBuilder(), *Axes->GetAx2(), xmin, ymin, zmin, z2min, x2min, xmax, ymax, zmax, z2max, x2max);
	};

	//! Returns the coordinates system from <me>.
	xgp_Ax2^ XBRepPrim_GWedge::Axes() {
		gp_Ax2* temp = new gp_Ax2(NativeHandle->Axes());
		return gcnew xgp_Ax2(temp);
	};

	//! Returns Xmin value from <me>.
	Standard_Real XBRepPrim_GWedge::GetXMin() {
		return NativeHandle->GetXMin();
	};

	//! Returns YMin value from <me>.
	Standard_Real XBRepPrim_GWedge::GetYMin() {
		return NativeHandle->GetYMin();
	};

	//! Returns ZMin value from <me>.
	Standard_Real XBRepPrim_GWedge::GetZMin() {
		return NativeHandle->GetZMin();
	};

	//! Returns Z2Min value from <me>.
	Standard_Real XBRepPrim_GWedge::GetZ2Min() {
		return NativeHandle->GetZ2Min();
	};

	//! Returns X2Min value from <me>.
	Standard_Real XBRepPrim_GWedge::GetX2Min() {
		return NativeHandle->GetX2Min();
	};

	//! Returns XMax value from <me>.
	Standard_Real XBRepPrim_GWedge::GetXMax() {
		return NativeHandle->GetXMax();
	};

	//! Returns YMax value from <me>.
	Standard_Real XBRepPrim_GWedge::GetYMax() {
		return NativeHandle->GetYMax();
	};

	//! Returns ZMax value from <me>.
	Standard_Real XBRepPrim_GWedge::GetZMax() {
		return NativeHandle->GetZMax();
	};

	//! Returns Z2Max value from <me>.
	Standard_Real XBRepPrim_GWedge::GetZ2Max() {
		return NativeHandle->GetZ2Max();
	};

	//! Returns X2Max value from <me>.
	Standard_Real XBRepPrim_GWedge::GetX2Max() {
		return NativeHandle->GetX2Max();
	};

	//! Opens <me> in <d1> direction. A face and its edges
	//! or vertices are said nonexistant.
	void XBRepPrim_GWedge::Open(XBRepPrim_Direction d1) {
		NativeHandle->Open(safe_cast<BRepPrim_Direction>(d1));
	};

	//! Closes   <me>  in <d1>  direction.  A face and its
	//! edges or vertices are said existant.
	void XBRepPrim_GWedge::Close(XBRepPrim_Direction d1) {
		NativeHandle->Close(safe_cast<BRepPrim_Direction>(d1));
	};

	//! Returns True if <me> is open in <d1> direction.
	Standard_Boolean XBRepPrim_GWedge::IsInfinite(XBRepPrim_Direction d1) {
		return NativeHandle->IsInfinite(safe_cast<BRepPrim_Direction>(d1));
	};

	//! Returns the Shell containing the Faces of <me>.
	XTopoDS_Shell^ XBRepPrim_GWedge::Shell() {
		TopoDS_Shell* aShell = new TopoDS_Shell(NativeHandle->Shell());
		return gcnew XTopoDS_Shell(aShell);
	};

	//! Returns True if <me> has a Face in <d1> direction.
	Standard_Boolean XBRepPrim_GWedge::HasFace(XBRepPrim_Direction d1) {
		return NativeHandle->HasFace(safe_cast<BRepPrim_Direction>(d1));
	};

	//! Returns the Face of <me> located in <d1> direction.
	XTopoDS_Face^ XBRepPrim_GWedge::Face(XBRepPrim_Direction d1) {
		TopoDS_Face* aFace = new TopoDS_Face(NativeHandle->Face(safe_cast<BRepPrim_Direction>(d1)));
		return gcnew XTopoDS_Face(aFace);
	};

	//! Returns the plane  of the Face  of <me> located in
	//! <d1> direction.
	xgp_Pln^ XBRepPrim_GWedge::Plane(XBRepPrim_Direction d1) {
		gp_Pln* aPln = new gp_Pln(NativeHandle->Plane(safe_cast<BRepPrim_Direction>(d1)));
		return gcnew xgp_Pln(aPln);
	};

	//! Returns True if <me> has a Wire in <d1> direction.
	Standard_Boolean XBRepPrim_GWedge::HasWire(XBRepPrim_Direction d1) {
		return NativeHandle->HasWire(safe_cast<BRepPrim_Direction>(d1));
	};

	//! Returns the Wire of <me> located in <d1> direction.
	XTopoDS_Wire^ XBRepPrim_GWedge::Wire(XBRepPrim_Direction d1) {
		TopoDS_Wire* aWire = new TopoDS_Wire(NativeHandle->Wire(safe_cast<BRepPrim_Direction>(d1)));
		return gcnew XTopoDS_Wire(aWire);
	};

	//! Returns True if <me> has an Edge in <d1><d2> direction.
	Standard_Boolean XBRepPrim_GWedge::HasEdge(XBRepPrim_Direction d1, XBRepPrim_Direction d2) {
		return NativeHandle->HasEdge(safe_cast<BRepPrim_Direction>(d1), safe_cast<BRepPrim_Direction>(d2));
	};

	//! Returns the Edge of <me> located in <d1><d2> direction.
	XTopoDS_Edge^ XBRepPrim_GWedge::Edge(XBRepPrim_Direction d1, XBRepPrim_Direction d2) {
		TopoDS_Edge* aEdge = new TopoDS_Edge(NativeHandle->Edge(safe_cast<BRepPrim_Direction>(d1), safe_cast<BRepPrim_Direction>(d2)));
		return gcnew XTopoDS_Edge(aEdge);
	};

	//! Returns the line of  the Edge of <me>  located  in
	//! <d1><d2> direction.
	xgp_Lin^ XBRepPrim_GWedge::Line(XBRepPrim_Direction d1, XBRepPrim_Direction d2) {
		gp_Lin* aLin = new gp_Lin(NativeHandle->Line(safe_cast<BRepPrim_Direction>(d1), safe_cast<BRepPrim_Direction>(d2)));
		return gcnew xgp_Lin(aLin);
	};

	//! Returns True if <me> has a  Vertex in <d1><d2><d3>
	//! direction.
	Standard_Boolean XBRepPrim_GWedge::HasVertex(XBRepPrim_Direction d1, XBRepPrim_Direction d2, XBRepPrim_Direction d3) {
		return NativeHandle->HasVertex(safe_cast<BRepPrim_Direction>(d1), safe_cast<BRepPrim_Direction>(d2), safe_cast<BRepPrim_Direction>(d3));
	};

	//! Returns the Vertex of <me> located in <d1><d2><d3>
	//! direction.
	XTopoDS_Vertex^ XBRepPrim_GWedge::Vertex(XBRepPrim_Direction d1, XBRepPrim_Direction d2, XBRepPrim_Direction d3) {
		TopoDS_Vertex* aLin = new TopoDS_Vertex(NativeHandle->Vertex(safe_cast<BRepPrim_Direction>(d1), safe_cast<BRepPrim_Direction>(d2), safe_cast<BRepPrim_Direction>(d3)));
		return gcnew XTopoDS_Vertex(aLin);
	};

	//! Returns the point of the Vertex of <me> located in
	//! <d1><d2><d3> direction.
	xgp_Pnt^ XBRepPrim_GWedge::Point(XBRepPrim_Direction d1, XBRepPrim_Direction d2, XBRepPrim_Direction d3) {
		gp_Pnt* aPnt = new gp_Pnt(NativeHandle->Point(safe_cast<BRepPrim_Direction>(d1), safe_cast<BRepPrim_Direction>(d2), safe_cast<BRepPrim_Direction>(d3)));
		return gcnew xgp_Pnt(aPnt);
	};
}