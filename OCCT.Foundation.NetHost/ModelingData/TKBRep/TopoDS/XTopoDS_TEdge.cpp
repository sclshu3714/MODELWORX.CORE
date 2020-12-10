#include <XTopoDS_TEdge.h>
namespace TKBRep {
    XTopoDS_TEdge::XTopoDS_TEdge() {
        //NativeHandle() = new TopoDS_TVertex();
    };

    XTopoDS_TEdge::XTopoDS_TEdge(Handle(TopoDS_TEdge) pos) {
        NativeHandle() = pos;
        SetTShapeHandle(NativeHandle());
    };

    void XTopoDS_TEdge::SetTEdgeHandle(Handle(TopoDS_TEdge) pos) {
        NativeHandle() = pos;
        SetTShapeHandle(NativeHandle());
    };

    Handle(TopoDS_TEdge) XTopoDS_TEdge::GetTEdge() {
        return NativeHandle();
    };

    Handle(TopoDS_TShape) XTopoDS_TEdge::GetTShape() {
        return NativeHandle();
    };

    //! Returns VERTEX.
    XTopAbs_ShapeEnum XTopoDS_TEdge::ShapeType() {
        return safe_cast<XTopAbs_ShapeEnum>(NativeHandle()->ShapeType());
    };
}
