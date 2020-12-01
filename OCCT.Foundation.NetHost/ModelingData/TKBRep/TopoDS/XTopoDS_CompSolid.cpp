#include <XTopoDS_CompSolid.h>

namespace TKBRep {


    //! Undefined Wire.
    XTopoDS_CompSolid::XTopoDS_CompSolid() : XTopoDS_Shape() {
        NativeHandle = new TopoDS_CompSolid();
        SetShapeHandle(*NativeHandle);
    };

    //!
    TopoDS_CompSolid* XTopoDS_CompSolid::GetCompSolid() {
        return NativeHandle;
    };

    TopoDS_Shape* XTopoDS_CompSolid::GetShape() {
        return NativeHandle;
    };
}
