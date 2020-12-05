#include <XBRepPrim_FaceBuilder.h>

namespace TKPrim {

	XBRepPrim_FaceBuilder::XBRepPrim_FaceBuilder() {
		NativeHandle = new BRepPrim_FaceBuilder();
	};

	XBRepPrim_FaceBuilder::XBRepPrim_FaceBuilder(BRepPrim_FaceBuilder* pos) {
		NativeHandle = pos;
	};

	XBRepPrim_FaceBuilder::XBRepPrim_FaceBuilder(XBRep_Builder^ B, XGeom_Surface^ S) {
		NativeHandle = new BRepPrim_FaceBuilder(*B->GetBRepBuilder(), S->GetSurface());
	};

	XBRepPrim_FaceBuilder::XBRepPrim_FaceBuilder(XBRep_Builder^ B, XGeom_Surface^ S, Standard_Real UMin, Standard_Real UMax, Standard_Real VMin, Standard_Real VMax) {
		NativeHandle = new BRepPrim_FaceBuilder(*B->GetBRepBuilder(), S->GetSurface(), UMin, UMax, VMin, VMax);
	};

	void XBRepPrim_FaceBuilder::SetPrimFaceBuilder(BRepPrim_FaceBuilder* pos) {
		NativeHandle = pos;
	};

	BRepPrim_FaceBuilder* XBRepPrim_FaceBuilder::GetPrimFaceBuilder() {
		return NativeHandle;
	};

	void XBRepPrim_FaceBuilder::Init(XBRep_Builder^ B, XGeom_Surface^ S) {
		NativeHandle->Init(*B->GetBRepBuilder(), S->GetSurface());
	};

	void XBRepPrim_FaceBuilder::Init(XBRep_Builder^ B, XGeom_Surface^ S, Standard_Real UMin, Standard_Real UMax, Standard_Real VMin, Standard_Real VMax) {
		NativeHandle->Init(*B->GetBRepBuilder(), S->GetSurface(), UMin, UMax, VMin, VMax);
	};

	XTopoDS_Face^ XBRepPrim_FaceBuilder::Face() {
		TopoDS_Face* aFace = new TopoDS_Face(NativeHandle->Face());
		return gcnew XTopoDS_Face(aFace);
	};
	XBRepPrim_FaceBuilder::operator XTopoDS_Face^() {
		TopoDS_Face* aFace = new TopoDS_Face(NativeHandle->Face());
		return gcnew XTopoDS_Face(aFace);
	};

	//! Returns the edge of index <I>
	//! 1 - Edge VMin
	//! 2 - Edge UMax
	//! 3 - Edge VMax
	//! 4 - Edge UMin
	XTopoDS_Edge^ XBRepPrim_FaceBuilder::Edge(Standard_Integer I) {
		TopoDS_Edge* aEdge = new TopoDS_Edge(NativeHandle->Edge(I));
		return gcnew XTopoDS_Edge(aEdge);
	};

	//! Returns the vertex of index <I>
	//! 1 - Vertex UMin,VMin
	//! 2 - Vertex UMax,VMin
	//! 3 - Vertex UMax,VMax
	//! 4 - Vertex UMin,VMax
	XTopoDS_Vertex^ XBRepPrim_FaceBuilder::Vertex(Standard_Integer I) {
		TopoDS_Vertex* aVertex = new TopoDS_Vertex(NativeHandle->Vertex(I));
		return gcnew XTopoDS_Vertex(aVertex);
	};
}