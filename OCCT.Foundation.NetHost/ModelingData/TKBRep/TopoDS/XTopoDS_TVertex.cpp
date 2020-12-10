#include <XTopoDS_TVertex.h>
namespace TKBRep {
    XTopoDS_TVertex::XTopoDS_TVertex() {
        //NativeHandle() = new TopoDS_TVertex();
    };

    XTopoDS_TVertex::XTopoDS_TVertex(Handle(TopoDS_TVertex) pos) {
        NativeHandle() = pos;
        SetTShapeHandle(NativeHandle());
    };

    void XTopoDS_TVertex::SetTVertexHandle(Handle(TopoDS_TVertex) pos) {
        NativeHandle() = pos;
        SetTShapeHandle(NativeHandle());
    };

    Handle(TopoDS_TVertex) XTopoDS_TVertex::GetTVertex() {
        return NativeHandle();
    };

    Handle(TopoDS_TShape) XTopoDS_TVertex::GetTShape() {
        return NativeHandle();
    };

    //! Returns VERTEX.
    XTopAbs_ShapeEnum XTopoDS_TVertex::ShapeType() {
        return safe_cast<XTopAbs_ShapeEnum>(NativeHandle()->ShapeType());
    };
}
