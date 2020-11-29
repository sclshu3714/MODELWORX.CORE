#include <XTopoDS_Wire.h>

namespace TKBRep {


    //! Undefined Wire.
    XTopoDS_Wire::XTopoDS_Wire() : XTopoDS_Shape() {
        NativeHandle = new TopoDS_Wire();
        SetShapeHandle(*NativeHandle);
    };

    TopoDS_Wire XTopoDS_Wire::GetWire() {
        return *NativeHandle;
    };
}
