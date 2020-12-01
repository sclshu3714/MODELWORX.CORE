#include <XTopoDS_Wire.h>

namespace TKBRep {


    //! Undefined Wire.
    XTopoDS_Wire::XTopoDS_Wire() : XTopoDS_Shape() {
        NativeHandle = new TopoDS_Wire();
        SetShapeHandle(NativeHandle);
    };

    //! Undefined Wire.
    XTopoDS_Wire::XTopoDS_Wire(TopoDS_Wire* pos) : XTopoDS_Shape() {
        NativeHandle = new TopoDS_Wire(*pos);
        SetShapeHandle(NativeHandle);
    };

    TopoDS_Wire XTopoDS_Wire::GetWire() {
        return *NativeHandle;
    };

    TopoDS_Shape* XTopoDS_Wire::GetShape() {
        return NativeHandle;
    };
}
