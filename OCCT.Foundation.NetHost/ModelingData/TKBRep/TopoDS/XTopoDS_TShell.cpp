#include <XTopoDS_TShell.h>
namespace TKBRep {
    //! Creates an empty TSolid.
    XTopoDS_TShell::XTopoDS_TShell() {
        NativeHandle() = new TopoDS_TShell();
        SetTShapeHandle(NativeHandle());
    };


    XTopoDS_TShell::XTopoDS_TShell(Handle(TopoDS_TShell) pos) {
        NativeHandle() = pos;
        SetTShapeHandle(NativeHandle());
    };

    void XTopoDS_TShell::SetTShellHandle(Handle(TopoDS_TShell) pos) {
        NativeHandle() = pos;
        SetTShapeHandle(NativeHandle());
    };

    Handle(TopoDS_TShell) XTopoDS_TShell::GetTShell() {
        return NativeHandle();
    };

    Handle(TopoDS_TShape) XTopoDS_TShell::GetTShape() {
        return NativeHandle();
    };

    //! returns SOLID.
    XTopAbs_ShapeEnum XTopoDS_TShell::ShapeType() {
        return safe_cast<XTopAbs_ShapeEnum>(NativeHandle()->ShapeType());
    };

    //! Returns an empty TSolid.
    XTopoDS_TShape^ XTopoDS_TShell::EmptyCopy() {
        return gcnew XTopoDS_TShape(NativeHandle()->EmptyCopy());
    };
}