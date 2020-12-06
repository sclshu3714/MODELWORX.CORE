#include <XBRepBuilderAPI_MakeVertex.h>

namespace TKTopAlgo {
	//! Constructs a vertex from point P.
		//! Example create a vertex from a 3D point.
		//! gp_Pnt P(0,0,10);
		//! TopoDS_Vertex V = BRepBuilderAPI_MakeVertex(P);
	XBRepBuilderAPI_MakeVertex::XBRepBuilderAPI_MakeVertex(xgp_Pnt^ P) {
		NativeHandle = new BRepBuilderAPI_MakeVertex(*P->GetPnt());
		SetMakeShapeHandle(NativeHandle);
	};

	//! Returns the constructed vertex.
	XTopoDS_Vertex^ XBRepBuilderAPI_MakeVertex::Vertex() {
		TopoDS_Vertex* temp = new TopoDS_Vertex(NativeHandle->Vertex());
		return gcnew XTopoDS_Vertex(temp);
	};
	XBRepBuilderAPI_MakeVertex::operator XTopoDS_Vertex^() {
		TopoDS_Vertex* temp = new TopoDS_Vertex(NativeHandle->Vertex());
		return gcnew XTopoDS_Vertex(temp);
	};
}

