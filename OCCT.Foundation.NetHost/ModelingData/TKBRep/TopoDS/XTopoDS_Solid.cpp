#include <XTopoDS_Solid.h>

namespace TKBRep {


    //! Undefined Wire.
    XTopoDS_Solid::XTopoDS_Solid() : XTopoDS_Shape() {
        NativeHandle = new TopoDS_Solid();
        SetShapeHandle(*NativeHandle);
    };
}
