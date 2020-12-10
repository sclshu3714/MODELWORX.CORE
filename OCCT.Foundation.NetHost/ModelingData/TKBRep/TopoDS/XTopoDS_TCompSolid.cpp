#include <XTopoDS_TCompSolid.h>
namespace TKBRep {
    //! Creates an empty TCompSolid.
    XTopoDS_TCompSolid::XTopoDS_TCompSolid() {
        NativeHandle() = new TopoDS_TCompSolid();
        SetTShapeHandle(NativeHandle());
    };

    XTopoDS_TCompSolid::XTopoDS_TCompSolid(Handle(TopoDS_TCompSolid) pos) {
        NativeHandle() = pos;
        SetTShapeHandle(NativeHandle());
    };

    void XTopoDS_TCompSolid::SetTCompSolidHandle(Handle(TopoDS_TCompSolid) pos) {
        NativeHandle() = pos;
        SetTShapeHandle(NativeHandle());
    };

    Handle(TopoDS_TCompSolid) XTopoDS_TCompSolid::GetTCompSolid() {
        return NativeHandle();
    };

    Handle(TopoDS_TShape) XTopoDS_TCompSolid::GetTShape() {
        return NativeHandle();
    };

    //! returns COMPSOLID
    XTopAbs_ShapeEnum XTopoDS_TCompSolid::ShapeType() {
        return safe_cast<XTopAbs_ShapeEnum>(NativeHandle()->ShapeType());
    };

    //! Returns an empty TCompSolid.
    XTopoDS_TShape^ XTopoDS_TCompSolid::EmptyCopy() {
        return gcnew XTopoDS_TShape(NativeHandle()->EmptyCopy());
    };
}
