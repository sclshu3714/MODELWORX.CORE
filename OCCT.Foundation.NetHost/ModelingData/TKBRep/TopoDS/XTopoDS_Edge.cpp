#include <XTopoDS_Edge.h>

namespace TKBRep {


    //! Undefined Wire.
    XTopoDS_Edge::XTopoDS_Edge() : XTopoDS_Shape() {
        NativeHandle = new TopoDS_Edge();
        SetShapeHandle(NativeHandle);
    };

    XTopoDS_Edge::XTopoDS_Edge(TopoDS_Edge* pos) {
        NativeHandle = new TopoDS_Edge(*pos);
        SetShapeHandle(NativeHandle);
    };

    //!
    TopoDS_Edge XTopoDS_Edge::GetEdge() {
        return *NativeHandle;
    };

    //!
    TopoDS_Shape XTopoDS_Edge::GetShape() {
        return *NativeHandle;
    };
}
