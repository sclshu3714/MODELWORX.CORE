#include <XBRepBuilderAPI_MakeWire.h>
#include <TopTools_ListOfShape.hxx>

namespace TKTopAlgo {
	//! Constructs an empty wire framework, to which edges
		//! are added using the Add function.
		//! As soon as the wire contains one edge, it can return
		//! with the use of the function Wire.
		//! Warning
		//! The function Error will return
		//! BRepBuilderAPI_EmptyWire if it is called before at
		//! least one edge is added to the wire under construction.
	XBRepBuilderAPI_MakeWire::XBRepBuilderAPI_MakeWire() {
		NativeHandle = new BRepBuilderAPI_MakeWire();
		SetMakeShapeHandle(*NativeHandle);
	};

	XBRepBuilderAPI_MakeWire::XBRepBuilderAPI_MakeWire(BRepBuilderAPI_MakeWire* pos) {
		NativeHandle = pos;
		SetMakeShapeHandle(*NativeHandle);
	};

	//! Make a Wire from an edge.
	XBRepBuilderAPI_MakeWire::XBRepBuilderAPI_MakeWire(XTopoDS_Edge^ E) {
		NativeHandle = new BRepBuilderAPI_MakeWire(E->GetEdge());
		SetMakeShapeHandle(*NativeHandle);
	};

	//! Make a Wire from two edges.
	XBRepBuilderAPI_MakeWire::XBRepBuilderAPI_MakeWire(XTopoDS_Edge^ E1, XTopoDS_Edge^ E2) {
		NativeHandle = new BRepBuilderAPI_MakeWire(E1->GetEdge(), E2->GetEdge());
		SetMakeShapeHandle(*NativeHandle);
	};

	//! Make a Wire from three edges.
	XBRepBuilderAPI_MakeWire::XBRepBuilderAPI_MakeWire(XTopoDS_Edge^ E1, XTopoDS_Edge^ E2, XTopoDS_Edge^ E3) {
		NativeHandle = new BRepBuilderAPI_MakeWire(E1->GetEdge(), E2->GetEdge(), E3->GetEdge());
		SetMakeShapeHandle(*NativeHandle);
	};

	//! Make a Wire from four edges.
	//! Constructs a wire
	//! -   from the TopoDS_Wire W composed of the edge E, or
	//! -   from edge E, or
	//! -   from two edges E1 and E2, or
	//! -   from three edges E1, E2 and E3, or
	//! -   from four edges E1, E2, E3 and E4.
	//! Further edges can be added using the function Add.
	//! Given edges are added in a sequence. Each of them
	//! must be connectable to the wire under construction,
	//! and so must satisfy the following condition (unless it is
	//! the first edge of the wire): one of its vertices must be
	//! geometrically coincident with one of the vertices of the
	//! wire (provided that the highest tolerance factor is
	//! assigned to the two vertices). It could also be the same vertex.
	//! Warning
	//! If an edge is not connectable to the wire under
	//! construction it is not added. The function Error will
	//! return BRepBuilderAPI_DisconnectedWire, the
	//! function IsDone will return false and the function Wire
	//! will raise an error, until a new connectable edge is added.
	XBRepBuilderAPI_MakeWire::XBRepBuilderAPI_MakeWire(XTopoDS_Edge^ E1, XTopoDS_Edge^ E2, XTopoDS_Edge^ E3, XTopoDS_Edge^ E4) {
		NativeHandle = new BRepBuilderAPI_MakeWire(E1->GetEdge(), E2->GetEdge(), E3->GetEdge(),E4->GetEdge());
		SetMakeShapeHandle(*NativeHandle);
	};

	//! Make a Wire from a Wire. Usefull for adding later.
	XBRepBuilderAPI_MakeWire::XBRepBuilderAPI_MakeWire(XTopoDS_Wire^ W) {
		NativeHandle = new BRepBuilderAPI_MakeWire(W->GetWire());
		SetMakeShapeHandle(*NativeHandle);
	};

	//! Add an edge to a wire.
	XBRepBuilderAPI_MakeWire::XBRepBuilderAPI_MakeWire(XTopoDS_Wire^ W, XTopoDS_Edge^ E) {
		NativeHandle = new BRepBuilderAPI_MakeWire(W->GetWire(), E->GetEdge());
		SetMakeShapeHandle(*NativeHandle);
	};

	//! Adds the edge E to the wire under construction.
	//! E must be connectable to the wire under construction, and, unless it
	//! is the first edge of the wire, must satisfy the following
	//! condition: one of its vertices must be geometrically coincident
	//! with one of the vertices of the wire (provided that the highest
	//! tolerance factor is assigned to the two vertices). It could also
	//! be the same vertex.
	//! Warning
	//! If E is not connectable to the wire under construction it is not
	//! added. The function Error will return
	//! BRepBuilderAPI_DisconnectedWire, the function IsDone will return
	//! false and the function Wire will raise an error, until a new
	//! connectable edge is added.
	void XBRepBuilderAPI_MakeWire::Add(XTopoDS_Edge^ E) {
		NativeHandle = new BRepBuilderAPI_MakeWire(E->GetEdge());
		SetMakeShapeHandle(*NativeHandle);
	};

	//! Add the edges of <W> to the current wire.
	void XBRepBuilderAPI_MakeWire::Add(XTopoDS_Wire^ W) {
		NativeHandle = new BRepBuilderAPI_MakeWire(W->GetWire());
		SetMakeShapeHandle(*NativeHandle);
	};

	//! Adds  the edges of <L>   to the current  wire.  The
	//! edges are not to be consecutive.   But they are to
	//! be  all  connected geometrically or topologically.
	//! If some of them are  not connected the Status give
	//! DisconnectedWire but the "Maker" is Done() and you
	//! can get the  partial result. (ie connected to  the
	//! first edgeof the list <L>)
	void XBRepBuilderAPI_MakeWire::Add(XTopTools_ListOfShape^ XL) {
		NativeHandle->Add(XL->TListOfShapes());
	};

	//! Returns true if this algorithm contains a valid wire.
	//! IsDone returns false if:
	//! -   there are no edges in the wire, or
	//! -   the last edge which you tried to add was not connectable.
	Standard_Boolean XBRepBuilderAPI_MakeWire::IsDone() {
		return NativeHandle->IsDone();
	};

	//! Returns the construction status
	//! -   BRepBuilderAPI_WireDone if the wire is built, or
	//! -   another value of the BRepBuilderAPI_WireError
	//! enumeration indicating why the construction failed.
	BRepBuilderAPI_WireError XBRepBuilderAPI_MakeWire::Error() {
		return NativeHandle->Error();
	};

	//! Returns the constructed wire; or the part of the wire
	//! under construction already built.
	//! Exceptions StdFail_NotDone if a wire is not built.
	XTopoDS_Wire^ XBRepBuilderAPI_MakeWire::Wire() {
		return gcnew XTopoDS_Wire(NativeHandle->Wire());
	};

	XBRepBuilderAPI_MakeWire::operator XTopoDS_Wire^() {
		return gcnew XTopoDS_Wire(NativeHandle->Wire());
	};

	//! Returns the last edge added to the wire under construction.
	//! Warning
	//! -   This edge can be different from the original one (the
	//! argument of the function Add, for instance,)
	//! -   A null edge is returned if there are no edges in the
	//! wire under construction, or if the last edge which you
	//! tried to add was not connectable..
	XTopoDS_Edge^ XBRepBuilderAPI_MakeWire::Edge() {
		return gcnew XTopoDS_Edge(NativeHandle->Edge());
	};

	//! Returns the last vertex of the last edge added to the
	//! wire under construction.
	//! Warning
	//! A null vertex is returned if there are no edges in the wire
	//! under construction, or if the last edge which you tried to
	//! add was not connectableR
	XTopoDS_Vertex^ XBRepBuilderAPI_MakeWire::Vertex() {
		return gcnew XTopoDS_Vertex(NativeHandle->Vertex());
	};
}
