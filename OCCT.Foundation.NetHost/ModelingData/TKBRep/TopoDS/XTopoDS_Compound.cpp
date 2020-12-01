#include <XTopoDS_Compound.h>

namespace TKBRep {


    //! Undefined Wire.
    XTopoDS_Compound::XTopoDS_Compound() : XTopoDS_Shape() {
        NativeHandle = new TopoDS_Compound();
        SetShapeHandle(*NativeHandle);
    };
    //!
    TopoDS_Compound* XTopoDS_Compound::GetCompound() {
        return NativeHandle;
    };

    //!
    TopoDS_Shape* XTopoDS_Compound::GetShape() {
        return NativeHandle;
    };
}
