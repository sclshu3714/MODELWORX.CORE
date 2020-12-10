#include <XTopoDS_TSolid.h>
namespace TKBRep {
    //! Creates an empty TSolid.
    XTopoDS_TSolid::XTopoDS_TSolid() {
        NativeHandle() = new TopoDS_TSolid();
        SetTShapeHandle(NativeHandle());
    };


    XTopoDS_TSolid::XTopoDS_TSolid(Handle(TopoDS_TSolid) pos) {
        NativeHandle() = pos;
        SetTShapeHandle(NativeHandle());
    };

    void XTopoDS_TSolid::SetTSolidHandle(Handle(TopoDS_TSolid) pos) {
        NativeHandle() = pos;
        SetTShapeHandle(NativeHandle());
    };

    Handle(TopoDS_TSolid) XTopoDS_TSolid::GetTSolid() {
        return NativeHandle();
    };

    Handle(TopoDS_TShape) XTopoDS_TSolid::GetTShape() {
        return NativeHandle();
    };

    //! returns SOLID.
    XTopAbs_ShapeEnum XTopoDS_TSolid::ShapeType() {
        return safe_cast<XTopAbs_ShapeEnum>(NativeHandle()->ShapeType());
    };

    //! Returns an empty TSolid.
    XTopoDS_TShape^ XTopoDS_TSolid::EmptyCopy() {
        return gcnew XTopoDS_TShape(NativeHandle()->EmptyCopy());
    };
}