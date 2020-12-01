#include <XTopoDS_Solid.h>

namespace TKBRep {


    //! Undefined Wire.
    XTopoDS_Solid::XTopoDS_Solid() : XTopoDS_Shape() {
        NativeHandle = new TopoDS_Solid();
        SetShapeHandle(*NativeHandle);
    };

    TopoDS_Solid* XTopoDS_Solid::GetSolid() {
        return NativeHandle;
    };

    //!
    TopoDS_Shape* XTopoDS_Solid::GetShape() {
        return NativeHandle;
    };
}
