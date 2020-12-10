#include <XTopExp_Explorer.h>
namespace TKBRep {

    //! Creates an empty explorer, becomes usefull after Init.
    XTopExp_Explorer::XTopExp_Explorer() {
        NativeHandle = new TopExp_Explorer();
    };

    XTopExp_Explorer::XTopExp_Explorer(TopExp_Explorer* pos) {
        NativeHandle = pos;
    };

    void XTopExp_Explorer::SetExplorerHandle(TopExp_Explorer* pos) {
        NativeHandle = pos;
    };

    TopExp_Explorer* XTopExp_Explorer::GetExplorer() {
        return NativeHandle;
    };

    //! Creates an Explorer on the Shape <S>.
    //!
    //! <ToFind> is the type of shapes to search.
    //! TopAbs_VERTEX, TopAbs_EDGE, ...
    //!
    //! <ToAvoid>   is the type   of shape to  skip in the
    //! exploration.   If   <ToAvoid>  is  equal  or  less
    //! complex than <ToFind> or if  <ToAVoid> is SHAPE it
    //! has no effect on the exploration.
    //! TopAbs_ShapeEnum ToAvoid = TopAbs_SHAPE
    XTopExp_Explorer::XTopExp_Explorer(XTopoDS_Shape^ S, XTopAbs_ShapeEnum ToFind, XTopAbs_ShapeEnum ToAvoid) {
        NativeHandle = new TopExp_Explorer(*S->GetShape(), safe_cast<TopAbs_ShapeEnum>(ToFind), safe_cast<TopAbs_ShapeEnum>(ToAvoid));
    };

    //! Resets this explorer on the shape S. It is initialized to
    //! search the shape S, for shapes of type ToFind, that
    //! are not part of a shape ToAvoid.
    //! If the shape ToAvoid is equal to TopAbs_SHAPE, or
    //! if it is the same as, or less complex than, the shape
    //! ToFind it has no effect on the search.
    //! TopAbs_ShapeEnum ToAvoid = TopAbs_SHAPE
    void XTopExp_Explorer::Init(XTopoDS_Shape^ S, XTopAbs_ShapeEnum ToFind, XTopAbs_ShapeEnum ToAvoid) {
        NativeHandle->Init(*S->GetShape(), safe_cast<TopAbs_ShapeEnum>(ToFind), safe_cast<TopAbs_ShapeEnum>(ToAvoid));
    };

    //! Returns  True if  there are   more  shapes in  the
    //! exploration.
    Standard_Boolean XTopExp_Explorer::More() {
        return NativeHandle->More();
    };

    //! Moves to the next Shape in the exploration.
    //! Exceptions
    //! Standard_NoMoreObject if there are no more shapes to explore.
    void XTopExp_Explorer::Next() {
        NativeHandle->Next();
    };

    //! Returns the current shape in the exploration.
    //! Exceptions
    //! Standard_NoSuchObject if this explorer has no more shapes to explore.
    XTopoDS_Shape^ XTopExp_Explorer::Value() { return Current(); }

    //! Returns the current shape in the exploration.
    //! Exceptions
    //! Standard_NoSuchObject if this explorer has no more shapes to explore.
    XTopoDS_Shape^ XTopExp_Explorer::Current() {
        TopoDS_Shape* temp = new TopoDS_Shape(NativeHandle->Current());
        return gcnew XTopoDS_Shape(temp);
    };

    //! Reinitialize  the    exploration with the original
    //! arguments.
    void XTopExp_Explorer::ReInit() {
        NativeHandle->ReInit();
    };

    //! Returns the current depth of the exploration. 0 is
    //! the shape to explore itself.
    Standard_Integer XTopExp_Explorer::Depth() {
        return NativeHandle->Depth();
    };

    //! Clears the content of the explorer. It will return
    //! False on More().
    void XTopExp_Explorer::Clear() {
        NativeHandle->Clear();
    };

    void XTopExp_Explorer::Destroy() {
        NativeHandle->Destroy();
    };
    XTopExp_Explorer::~XTopExp_Explorer() {  Destroy(); }
    XTopExp_Explorer::!XTopExp_Explorer() {  Destroy(); }
}