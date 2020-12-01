#include <XTopoDS_Shell.h>

namespace TKBRep {


    //! Undefined Wire.
    XTopoDS_Shell::XTopoDS_Shell() : XTopoDS_Shape() {
        NativeHandle = new TopoDS_Shell();
        SetShapeHandle(*NativeHandle);
    };
    TopoDS_Shell* XTopoDS_Shell::GetShell() {
        return NativeHandle;
    };
    //!
    TopoDS_Shape* XTopoDS_Shell::GetShape() {
        return NativeHandle;
    };
}
