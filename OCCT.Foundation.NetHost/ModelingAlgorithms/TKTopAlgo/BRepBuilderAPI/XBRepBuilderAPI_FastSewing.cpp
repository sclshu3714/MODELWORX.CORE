#include <XBRepBuilderAPI_FastSewing.h>
namespace TKTopAlgo {
    XBRepBuilderAPI_FastSewing::XBRepBuilderAPI_FastSewing() {
        NativeHandle() = new BRepBuilderAPI_FastSewing();
    };

    XBRepBuilderAPI_FastSewing::XBRepBuilderAPI_FastSewing(Handle(BRepBuilderAPI_FastSewing) handle) {
        NativeHandle() = handle;
    };

    void XBRepBuilderAPI_FastSewing::SetFastSewingHandle(Handle(BRepBuilderAPI_FastSewing) handle) {
        NativeHandle() = handle;
    };

    Handle(BRepBuilderAPI_FastSewing) XBRepBuilderAPI_FastSewing::GetFastSewing() {
        return NativeHandle();
    };

    //! Creates an object with tolerance of connexity
    //! const Standard_Real theTolerance = 1.0e-06
    XBRepBuilderAPI_FastSewing::XBRepBuilderAPI_FastSewing(Standard_Real theTolerance) {
        NativeHandle() = new BRepBuilderAPI_FastSewing(theTolerance);
    };

    //! Adds faces of a shape
    Standard_Boolean XBRepBuilderAPI_FastSewing::Add(XTopoDS_Shape^ theShape) {
        return NativeHandle()->Add(*theShape->GetShape());
    };

    //! Adds a surface
    Standard_Boolean XBRepBuilderAPI_FastSewing::Add(XGeom_Surface^ theSurface) {
        return NativeHandle()->Add(theSurface->GetSurface());
    };

    //! Compute resulted shape
    void XBRepBuilderAPI_FastSewing::Perform(void) {
        NativeHandle()->Perform();
    };

    //! Sets tolerance
    void XBRepBuilderAPI_FastSewing::SetTolerance(Standard_Real theToler) {
        NativeHandle()->SetTolerance(theToler);
    };

    //! Returns tolerance
    Standard_Real XBRepBuilderAPI_FastSewing::GetTolerance() {
        return NativeHandle()->GetTolerance();
    };

    //! Returns resulted shape
    XTopoDS_Shape^ XBRepBuilderAPI_FastSewing::GetResult() {
        TopoDS_Shape* temp = new TopoDS_Shape(NativeHandle()->GetResult());
        return gcnew XTopoDS_Shape(temp);
    };

    //! Returns list of statuses. Print message if theOS != 0
    //! Standard_OStream* const theOS = 0
    XFS_Statuses XBRepBuilderAPI_FastSewing::GetStatuses(Standard_OStream theOS) {
        return safe_cast<XFS_Statuses>(NativeHandle()->GetStatuses(&theOS));
    };
}