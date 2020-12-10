#include <XTopoDS_TCompound.h>

namespace TKBRep {
    //! Creates an empty TCompound.
    XTopoDS_TCompound::XTopoDS_TCompound() {
        NativeHandle() = new TopoDS_TCompound();
        SetTShapeHandle(NativeHandle());
    };

    XTopoDS_TCompound::XTopoDS_TCompound(Handle(TopoDS_TCompound) pos) {
        NativeHandle() = pos;
        SetTShapeHandle(NativeHandle());
    };

    void XTopoDS_TCompound::SetTCompoundHandle(Handle(TopoDS_TCompound) pos) {
        NativeHandle() = pos;
        SetTShapeHandle(NativeHandle());
    };

    Handle(TopoDS_TCompound) XTopoDS_TCompound::GetTCompound() {
        return NativeHandle();
    };

    Handle(TopoDS_TShape) XTopoDS_TCompound::GetTShape() {
        return NativeHandle();
    };

    //! Returns COMPOUND.
    XTopAbs_ShapeEnum XTopoDS_TCompound::ShapeType() {
        return safe_cast<XTopAbs_ShapeEnum>(NativeHandle()->ShapeType());
    };

    //! Returns an empty TCompound.
    XTopoDS_TShape^ XTopoDS_TCompound::EmptyCopy() {
       return gcnew XTopoDS_TShape(NativeHandle()->EmptyCopy());
    };
}