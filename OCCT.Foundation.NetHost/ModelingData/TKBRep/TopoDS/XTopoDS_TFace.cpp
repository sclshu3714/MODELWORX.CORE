#include <XTopoDS_TFace.h>
namespace TKBRep {
    //! Creates an empty TFace.
    XTopoDS_TFace::XTopoDS_TFace() {
        NativeHandle() = new TopoDS_TFace();
        SetTShapeHandle(NativeHandle());
    };

    XTopoDS_TFace::XTopoDS_TFace(Handle(TopoDS_TFace) pos) {
        NativeHandle() = pos;
        SetTShapeHandle(NativeHandle());
    };

    void XTopoDS_TFace::SetTFaceHandle(Handle(TopoDS_TFace) pos) {
        NativeHandle() = pos;
        SetTShapeHandle(NativeHandle());
    };

    Handle(TopoDS_TFace) XTopoDS_TFace::GetTFace() {
        return NativeHandle();
    };

    Handle(TopoDS_TShape) XTopoDS_TFace::GetTShape() {
        return NativeHandle();
    };

    //! returns FACE.
    XTopAbs_ShapeEnum XTopoDS_TFace::ShapeType() {
        return safe_cast<XTopAbs_ShapeEnum>(NativeHandle()->ShapeType());
    };

    //! Returns an empty TFace.
    XTopoDS_TShape^ XTopoDS_TFace::EmptyCopy() {
        return gcnew XTopoDS_TShape(NativeHandle()->EmptyCopy());
    };
}
