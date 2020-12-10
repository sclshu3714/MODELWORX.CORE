#include <XTopoDS_TWire.h>

namespace TKBRep {

    //! Creates an empty TWire.
    XTopoDS_TWire::XTopoDS_TWire() {
        NativeHandle() = new TopoDS_TWire();
        SetTShapeHandle(NativeHandle());
    };

    XTopoDS_TWire::XTopoDS_TWire(Handle(TopoDS_TWire) pos) {
        NativeHandle() = pos;
        SetTShapeHandle(NativeHandle());
    };

    void XTopoDS_TWire::SetTWireHandle(Handle(TopoDS_TWire) pos) {
        NativeHandle() = pos;
        SetTShapeHandle(NativeHandle());
    };

    Handle(TopoDS_TWire) XTopoDS_TWire::GetTWire() {
        return NativeHandle();
    };

    Handle(TopoDS_TShape) XTopoDS_TWire::GetTShape() {
        return NativeHandle();
    };

    //! Returns WIRE.
    XTopAbs_ShapeEnum XTopoDS_TWire::ShapeType() {
        return safe_cast<XTopAbs_ShapeEnum>(NativeHandle()->ShapeType());
    };

    //! Returns an empty TWire.
    XTopoDS_TShape^ XTopoDS_TWire::EmptyCopy() {
        return gcnew XTopoDS_TShape(NativeHandle()->EmptyCopy());
    };
}
