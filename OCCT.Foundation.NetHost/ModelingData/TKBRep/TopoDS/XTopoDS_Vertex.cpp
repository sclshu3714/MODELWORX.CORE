#include <XTopoDS_Vertex.h>

namespace TKBRep {


    //! Undefined Wire.
    XTopoDS_Vertex::XTopoDS_Vertex() : XTopoDS_Shape() {
        NativeHandle = new TopoDS_Vertex();
        SetShapeHandle(*NativeHandle);
    };

    //! Undefined Face.
    XTopoDS_Vertex::XTopoDS_Vertex(TopoDS_Vertex* pos) {
        NativeHandle = new TopoDS_Vertex(*pos);
        SetShapeHandle(*NativeHandle);
    };


    //!
    TopoDS_Vertex XTopoDS_Vertex::GetVertex() {
        return *NativeHandle;
    };

    //!
    TopoDS_Shape XTopoDS_Vertex::GetShape() {
        return *NativeHandle;
    };
}
