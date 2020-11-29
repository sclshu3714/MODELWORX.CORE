#include <XTopoDS_Face.h>

namespace TKBRep {


    //! Undefined Wire.
    XTopoDS_Face::XTopoDS_Face() : XTopoDS_Shape() {
        NativeHandle = new TopoDS_Face();
        SetShapeHandle(*NativeHandle);
    };

    //! Undefined Face.
    XTopoDS_Face::XTopoDS_Face(TopoDS_Face pos) {
        NativeHandle = &pos;
        SetShapeHandle(*NativeHandle);
    };

    //!
    TopoDS_Face XTopoDS_Face::GetFace() {
        return *NativeHandle;
    };
}
