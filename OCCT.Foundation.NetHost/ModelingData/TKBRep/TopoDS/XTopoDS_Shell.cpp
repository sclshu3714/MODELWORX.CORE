#include <XTopoDS_Shell.h>

namespace TKBRep {


    //! Undefined Wire.
    XTopoDS_Shell::XTopoDS_Shell() : XTopoDS_Shape() {
        NativeHandle = new TopoDS_Shell();
        SetShapeHandle(NativeHandle);
    };

    XTopoDS_Shell::XTopoDS_Shell(TopoDS_Shell* pos) {
        NativeHandle = pos;
        SetShapeHandle(NativeHandle);
    }

    TopoDS_Shell* XTopoDS_Shell::GetShell() {
        return NativeHandle;
    };
    //!
    TopoDS_Shape* XTopoDS_Shell::GetShape() {
        return NativeHandle;
    };
}
