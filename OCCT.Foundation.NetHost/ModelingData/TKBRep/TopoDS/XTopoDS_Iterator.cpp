#include <XTopoDS_Iterator.h> 

namespace TKBRep {

    //! Creates an empty Iterator.
    XTopoDS_Iterator::XTopoDS_Iterator() {
        NativeHandle = new TopoDS_Iterator();
    };

    //! Creates an Iterator on <S> sub-shapes.
    //! Note:
    //! - If cumOri is true, the function composes all
    //! sub-shapes with the orientation of S.
    //! - If cumLoc is true, the function multiplies all
    //! sub-shapes by the location of S, i.e. it applies to
    //! each sub-shape the transformation that is associated with S.
    //! Standard_Boolean cumOri = Standard_True, const Standard_Boolean cumLoc = Standard_True
    XTopoDS_Iterator::XTopoDS_Iterator(XTopoDS_Shape^ S, Standard_Boolean cumOri, Standard_Boolean cumLoc) {
        NativeHandle = new TopoDS_Iterator(*S->GetShape(), cumOri, cumLoc);
    };

    //! Initializes this iterator with shape S.
    //! Note:
    //! - If cumOri is true, the function composes all
    //! sub-shapes with the orientation of S.
    //! - If cumLoc is true, the function multiplies all
    //! sub-shapes by the location of S, i.e. it applies to
    //! each sub-shape the transformation that is associated with S.
    //! Standard_Boolean cumOri = Standard_True, const Standard_Boolean cumLoc = Standard_True
    void XTopoDS_Iterator::Initialize(XTopoDS_Shape^ S, Standard_Boolean cumOri, const Standard_Boolean cumLoc) {
        NativeHandle->Initialize(*S->GetShape(), cumOri, cumLoc);
    };

    TopoDS_Iterator XTopoDS_Iterator::GetIterator() {
        return *NativeHandle;
    };

    //! Returns true if there is another sub-shape in the
    //! shape which this iterator is scanning.
    Standard_Boolean XTopoDS_Iterator::More() {
        return NativeHandle->More();
    };

    //! Moves on to the next sub-shape in the shape which
    //! this iterator is scanning.
    //! Exceptions
    //! Standard_NoMoreObject if there are no more sub-shapes in the shape.
    void XTopoDS_Iterator::Next() {
        NativeHandle->Next();
    };

    //! Returns the current sub-shape in the shape which
    //! this iterator is scanning.
    //! Exceptions
    //! Standard_NoSuchObject if there is no current sub-shape.
    XTopoDS_Shape^ XTopoDS_Iterator::Value() {
        TopoDS_Shape* aShape = new TopoDS_Shape(NativeHandle->Value());
        return gcnew XTopoDS_Shape(aShape);
    };
}
