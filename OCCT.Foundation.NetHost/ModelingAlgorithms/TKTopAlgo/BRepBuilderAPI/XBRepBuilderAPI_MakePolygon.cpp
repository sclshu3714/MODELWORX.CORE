#include <XBRepBuilderAPI_MakePolygon.h>
namespace TKTopAlgo {
	//! Initializes an empty polygonal wire, to which points or
	//! vertices are added using the Add function.
	//! As soon as the polygonal wire underruction
	//! contains vertices, it can be consulted using the Wire function.
	XBRepBuilderAPI_MakePolygon::XBRepBuilderAPI_MakePolygon() {
		NativeHandle = new BRepBuilderAPI_MakePolygon();
		SetMakeShapeHandle(NativeHandle);
	};

	XBRepBuilderAPI_MakePolygon::XBRepBuilderAPI_MakePolygon(BRepBuilderAPI_MakePolygon* handle) {
		NativeHandle = handle;
		SetMakeShapeHandle(NativeHandle);
	};

	void XBRepBuilderAPI_MakePolygon::SetMakePolygonHandle(BRepBuilderAPI_MakePolygon* handle) {
		NativeHandle = handle;
		SetMakeShapeHandle(NativeHandle);
	};

	BRepBuilderAPI_MakePolygon* XBRepBuilderAPI_MakePolygon::GetMakePolygon() {
		return NativeHandle;
	};

	BRepBuilderAPI_MakeShape* XBRepBuilderAPI_MakePolygon::GetMakeShape() {
		return NativeHandle;
	};

	XBRepBuilderAPI_MakePolygon::XBRepBuilderAPI_MakePolygon(xgp_Pnt^ P1, xgp_Pnt^ P2) {
		NativeHandle = new BRepBuilderAPI_MakePolygon(*P1->GetPnt(), *P2->GetPnt());
		SetMakeShapeHandle(NativeHandle);
	};

	//! Standard_Boolean Close = Standard_False
	XBRepBuilderAPI_MakePolygon::XBRepBuilderAPI_MakePolygon(xgp_Pnt^ P1, xgp_Pnt^ P2, xgp_Pnt^ P3, Standard_Boolean Close) {
		NativeHandle = new BRepBuilderAPI_MakePolygon(*P1->GetPnt(), *P2->GetPnt(), *P3->GetPnt(), Close);
		SetMakeShapeHandle(NativeHandle);
	};

	//! Constructs a polygonal wire from 2, 3 or 4 points. Vertices are
	//! automatically created on the given points. The polygonal wire is
	//! closed if Close is true; otherwise it is open. Further vertices can
	//! be added using the Add function. The polygonal wire under
	//!ruction can be consulted at any time by using the Wire function.
	//! Example
	//! //an open polygon from four points
	//! TopoDS_Wire W = BRepBuilderAPI_MakePolygon(P1,P2,P3,P4);
	//! Warning: The process is equivalent to:
	//! - initializing an empty polygonal wire,
	//! - and adding the given points in sequence.
	//! Consequently, be careful when using this function: if the
	//! sequence of points p1 - p2 - p1 is found among the arguments of the
	//!ructor, you will create a polygonal wire with two
	//! consecutive coincident edges.
	//! Standard_Boolean Close = Standard_False
	XBRepBuilderAPI_MakePolygon::XBRepBuilderAPI_MakePolygon(xgp_Pnt^ P1, xgp_Pnt^ P2, xgp_Pnt^ P3, xgp_Pnt^ P4, Standard_Boolean Close) {
		NativeHandle = new BRepBuilderAPI_MakePolygon(*P1->GetPnt(), *P2->GetPnt(), *P3->GetPnt(), *P4->GetPnt(), Close);
		SetMakeShapeHandle(NativeHandle);
	};

	XBRepBuilderAPI_MakePolygon::XBRepBuilderAPI_MakePolygon(XTopoDS_Vertex^ V1, XTopoDS_Vertex^ V2) {
		NativeHandle = new BRepBuilderAPI_MakePolygon(*V1->GetVertex(), *V2->GetVertex());
		SetMakeShapeHandle(NativeHandle);
	};

	//! Standard_Boolean Close = Standard_False
	XBRepBuilderAPI_MakePolygon::XBRepBuilderAPI_MakePolygon(XTopoDS_Vertex^ V1, XTopoDS_Vertex^ V2, XTopoDS_Vertex^ V3, Standard_Boolean Close) {
		NativeHandle = new BRepBuilderAPI_MakePolygon(*V1->GetVertex(), *V2->GetVertex(), *V3->GetVertex(), Close);
		SetMakeShapeHandle(NativeHandle);
	};

	//! Constructs a polygonal wire from
	//! 2, 3 or 4 vertices. The polygonal wire is closed if Close is true;
	//! otherwise it is open (default value). Further vertices can be
	//! added using the Add function. The polygonal wire under
	//!ruction can be consulted at any time by using the Wire function.
	//! Example
	//! //a closed triangle from three vertices
	//! TopoDS_Wire W = BRepBuilderAPI_MakePolygon(V1,V2,V3,Standard_True);
	//! Warning
	//! The process is equivalent to:
	//! -      initializing an empty polygonal wire,
	//! -      then adding the given points in sequence.
	//! So be careful, as when using this function, you could create a
	//! polygonal wire with two consecutive coincident edges if
	//! the sequence of vertices v1 - v2 - v1 is found among the
	//!ructor's arguments.
	//! Standard_Boolean Close = Standard_False
	XBRepBuilderAPI_MakePolygon::XBRepBuilderAPI_MakePolygon(XTopoDS_Vertex^ V1, XTopoDS_Vertex^ V2, XTopoDS_Vertex^ V3, XTopoDS_Vertex^ V4, Standard_Boolean Close) {
		NativeHandle = new BRepBuilderAPI_MakePolygon(*V1->GetVertex(), *V2->GetVertex(), *V3->GetVertex(), *V4->GetVertex(), Close);
		SetMakeShapeHandle(NativeHandle);
	};

	void XBRepBuilderAPI_MakePolygon::Add(xgp_Pnt^ P) {
		NativeHandle->Add(*P->GetPnt());
	};


	//! Adds the point P or the vertex V at the end of the
	//! polygonal wire underruction. A vertex is
	//! automatically created on the point P.
	//! Warning
	//! -   When P or V is coincident to the previous vertex,
	//! no edge is built. The method Added can be used to
	//! test for this. Neither P nor V is checked to verify
	//! that it is coincident with another vertex than the last
	//! one, of the polygonal wire underruction. It is
	//! also possible to add vertices on a closed polygon
	//! (built for example by using aructor which
	//! declares the polygon closed, or after the use of the Close function).
	//! Consequently, be careful using this function: you might create:
	//! -      a polygonal wire with two consecutive coincident edges, or
	//! -      a non manifold polygonal wire.
	//! -      P or V is not checked to verify if it is
	//! coincident with another vertex but the last one, of
	//! the polygonal wire underruction. It is also
	//! possible to add vertices on a closed polygon (built
	//! for example by using aructor which declares
	//! the polygon closed, or after the use of the Close function).
	//! Consequently, be careful when using this function: you might create:
	//! -   a polygonal wire with two consecutive coincident edges, or
	//! -   a non-manifold polygonal wire.
	void XBRepBuilderAPI_MakePolygon::Add(XTopoDS_Vertex^ V) {
		NativeHandle->Add(*V->GetVertex());
	};

	//! Returns true if the last vertex added to theructed
	//! polygonal wire is not coincident with the previous one.
	Standard_Boolean XBRepBuilderAPI_MakePolygon::Added() {
		return NativeHandle->Added();
	};

	//! Closes the polygonal wire underruction. Note - this
	//! is equivalent to adding the first vertex to the polygonal
	//! wire underruction.
	void XBRepBuilderAPI_MakePolygon::Close() {
		NativeHandle->Close();
	};

	XTopoDS_Vertex^ XBRepBuilderAPI_MakePolygon::FirstVertex() {
		TopoDS_Vertex* temp = new TopoDS_Vertex(NativeHandle->FirstVertex());
		return gcnew XTopoDS_Vertex(temp);
	};

	//! Returns the first or the last vertex of the polygonal wire underruction.
	//! If theructed polygonal wire is closed, the first and the last vertices are identical.
	XTopoDS_Vertex^ XBRepBuilderAPI_MakePolygon::LastVertex() {
		TopoDS_Vertex* temp = new TopoDS_Vertex(NativeHandle->LastVertex());
		return gcnew XTopoDS_Vertex(temp);
	};


	//! Returns true if this algorithm contains a valid polygonal
	//! wire (i.e. if there is at least one edge).
	//! IsDone returns false if fewer than two vertices have
	//! been chained together by thisruction algorithm.
	Standard_Boolean XBRepBuilderAPI_MakePolygon::IsDone() {
		return NativeHandle->IsDone();
	};

	//! Returns the edge built between the last two points or
	//! vertices added to theructed polygonal wire underruction.
	//! Warning
	//! If there is only one vertex in the polygonal wire, the result is a null edge.
	XTopoDS_Edge^ XBRepBuilderAPI_MakePolygon::Edge() {
		TopoDS_Edge* temp = new TopoDS_Edge(NativeHandle->Edge());
		return gcnew XTopoDS_Edge(temp);
	};
	XBRepBuilderAPI_MakePolygon::operator XTopoDS_Edge^() {
		TopoDS_Edge* temp = new TopoDS_Edge(NativeHandle->Edge());
		return gcnew XTopoDS_Edge(temp);
	};


	//! Returns theructed polygonal wire, or the already
	//! built part of the polygonal wire underruction.
	//! Exceptions
	//! StdFail_NotDone if the wire is not built, i.e. if fewer than
	//! two vertices have been chained together by thisruction algorithm.
	XTopoDS_Wire^ XBRepBuilderAPI_MakePolygon::Wire() {
		TopoDS_Wire* temp = new TopoDS_Wire(NativeHandle->Wire());
		return gcnew XTopoDS_Wire(temp);
	};
	XBRepBuilderAPI_MakePolygon::operator XTopoDS_Wire^() {
		TopoDS_Wire* temp = new TopoDS_Wire(NativeHandle->Wire());
		return gcnew XTopoDS_Wire(temp);
	};
}