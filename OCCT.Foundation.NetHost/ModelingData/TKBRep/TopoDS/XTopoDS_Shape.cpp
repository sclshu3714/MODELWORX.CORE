#include "XTopoDS_Shape.h"

namespace TKBRep {
    //! Creates a NULL Shape referring to nothing.
    XTopoDS_Shape::XTopoDS_Shape(void) {
        NativeHandle = new TopoDS_Shape();
    };

    //! Creates a NULL Shape referring to nothing.
    XTopoDS_Shape::XTopoDS_Shape(TopoDS_Shape pos) {
        NativeHandle = &pos;
    };

    //! Creates a NULL Shape referring to nothing.
    XTopoDS_Shape::XTopoDS_Shape(TopoDS_Shape* pos) {
        NativeHandle = pos;
    };

    XTopoDS_Shape::~XTopoDS_Shape() {
        NativeHandle = NULL;
    };

    void XTopoDS_Shape::SetShapeHandle(TopoDS_Shape pos) {
        NativeHandle = &pos;
    };

    void XTopoDS_Shape::SetShapeHandle(TopoDS_Shape* pos) {
        NativeHandle = pos;
    };

#ifndef OCCT_NO_RVALUE_REFERENCE

    //! Generalized moveructor, accepting also sub-classes
    //! (TopoDS_Shape hierarchy declares only fake sub-classes with no extra fields).
    template<class T2>
    XTopoDS_Shape::XTopoDS_Shape(T2 theOther, typename std::enable_if<opencascade::std::is_base_of<TopoDS_Shape, T2>::value>::type*) {
        NativeHandle = new TopoDS_Shape(theOther, std::forward<T2>(theOther));
    };
#endif

    //!
    TopoDS_Shape* XTopoDS_Shape::GetShape() {
        return NativeHandle;
    };

    //! Returns true if this shape is null. In other words, it
    //! references no underlying shape with the potential to
    //! be given a location and an orientation.
    Standard_Boolean XTopoDS_Shape::IsNull() {
        return NativeHandle->IsNull();
    };

    //! Destroys the reference to the underlying shape
    //! stored in this shape. As a result, this shape becomes null.
    void XTopoDS_Shape::Nullify() {
        NativeHandle->Nullify();
    };

    //! Returns the shape local coordinate system.
    XTopLoc_Location^ XTopoDS_Shape::Location() {
        return gcnew XTopLoc_Location(NativeHandle->Location());
    };

    //! Sets the shape local coordinate system.
    void XTopoDS_Shape::Location(XTopLoc_Location^ theLoc) {
        NativeHandle->Location(theLoc->GetLocation());
    };

    //! Returns a  shape  similar to <me> with   the local
    //! coordinate system set to <Loc>.
    XTopoDS_Shape^ XTopoDS_Shape::Located(XTopLoc_Location^ theLoc) {
        return gcnew XTopoDS_Shape(NativeHandle->Located(theLoc->GetLocation()));
    };

    //! Returns the shape orientation.
    XTopAbs_Orientation XTopoDS_Shape::Orientation() {
        return safe_cast<XTopAbs_Orientation>(NativeHandle->Orientation());
    };

    //! Sets the shape orientation.
    void XTopoDS_Shape::Orientation(XTopAbs_Orientation theOrient) {
        NativeHandle->Orientation(safe_cast<TopAbs_Orientation>(theOrient));
    };

    //! Returns  a    shape  similar  to  <me>   with  the
    //! orientation set to <Or>.
    XTopoDS_Shape^ XTopoDS_Shape::Oriented(XTopAbs_Orientation theOrient) {
        return gcnew XTopoDS_Shape(NativeHandle->Oriented(safe_cast<TopAbs_Orientation>(theOrient)));
    };

    //! Returns a handle to the actual shape implementation.
    XTopoDS_TShape^ XTopoDS_Shape::TShape() {
        return gcnew XTopoDS_TShape(NativeHandle->TShape());
    };

    //! Returns the value of the TopAbs_ShapeEnum
    //! enumeration that corresponds to this shape, for
    //! example VERTEX, EDGE, and so on.
    //! Exceptions
    //! Standard_NullObject if this shape is null.
    XTopAbs_ShapeEnum XTopoDS_Shape::ShapeType() {
        return safe_cast<XTopAbs_ShapeEnum>(NativeHandle->ShapeType());
    };

    //! Returns the free flag.
    Standard_Boolean XTopoDS_Shape::Free() {
        return NativeHandle->Free();
    };

    //! Sets the free flag.
    void XTopoDS_Shape::Free(Standard_Boolean theIsFree) {
        NativeHandle->Free(theIsFree);
    };

    //! Returns the locked flag.
    Standard_Boolean XTopoDS_Shape::Locked() {
        return NativeHandle->Locked();
    };

    //! Sets the locked flag.
    void XTopoDS_Shape::Locked(Standard_Boolean theIsLocked) {
        NativeHandle->Locked(theIsLocked);
    };

    //! Returns the modification flag.
    Standard_Boolean XTopoDS_Shape::Modified() {
        return NativeHandle->Modified();
    };

    //! Sets the modification flag.
    void XTopoDS_Shape::Modified(Standard_Boolean theIsModified) {
        NativeHandle->Modified(theIsModified);
    };

    //! Returns the checked flag.
    Standard_Boolean XTopoDS_Shape::Checked() {
        return NativeHandle->Checked();
    };

    //! Sets the checked flag.
    void XTopoDS_Shape::Checked(Standard_Boolean theIsChecked) {
        NativeHandle->Checked(theIsChecked);
    };

    //! Returns the orientability flag.
    Standard_Boolean XTopoDS_Shape::Orientable() {
        return NativeHandle->Orientable();
    };

    //! Sets the orientability flag.
    void XTopoDS_Shape::Orientable(const Standard_Boolean theIsOrientable) {
        NativeHandle->Orientable(theIsOrientable);
    };

    //! Returns the closedness flag.
    Standard_Boolean XTopoDS_Shape::Closed() {
        return NativeHandle->Closed();
    };

    //! Sets the closedness flag.
    void XTopoDS_Shape::Closed(Standard_Boolean theIsClosed) {
        NativeHandle->Closed(theIsClosed);
    };

    //! Returns the infinity flag.
    Standard_Boolean XTopoDS_Shape::Infinite() {
        return NativeHandle->Infinite();
    };

    //! Sets the infinity flag.
    void XTopoDS_Shape::Infinite(Standard_Boolean theIsInfinite) {
        NativeHandle->Infinite(theIsInfinite);
    };

    //! Returns the convexness flag.
    Standard_Boolean XTopoDS_Shape::Convex() {
        return NativeHandle->Convex();
    };

    //! Sets the convexness flag.
    void XTopoDS_Shape::Convex(Standard_Boolean theIsConvex) {
        NativeHandle->Convex(theIsConvex);
    };

    //! Multiplies the Shape location by thePosition.
    void XTopoDS_Shape::Move(XTopLoc_Location^ thePosition) {
        NativeHandle->Move(thePosition->GetLocation());
    };

    //! Returns a shape similar to <me> with a location multiplied by thePosition.
    XTopoDS_Shape^ XTopoDS_Shape::Moved(XTopLoc_Location^ thePosition) {
        return gcnew XTopoDS_Shape(NativeHandle->Moved(thePosition->GetLocation()));
    };

    //! Reverses the orientation, using the Reverse method
    //! from the TopAbs package.
    void XTopoDS_Shape::Reverse() {
        NativeHandle->Reverse();
    };

    //! Returns    a shape  similar    to  <me>  with  the
    //! orientation  reversed, using  the   Reverse method
    //! from the TopAbs package.
    XTopoDS_Shape^ XTopoDS_Shape::Reversed() {
        return gcnew XTopoDS_Shape(NativeHandle->Reversed());
    };

    //! Complements the orientation, using the  Complement
    //! method from the TopAbs package.
    void XTopoDS_Shape::Complement() {
        NativeHandle->Complement();
    };

    //! Returns  a   shape  similar  to   <me>   with  the
    //! orientation complemented,  using   the  Complement
    //! method from the TopAbs package.
    XTopoDS_Shape^ XTopoDS_Shape::Complemented() {
        return gcnew XTopoDS_Shape(NativeHandle->Complemented());
    };

    //! Updates the Shape Orientation by composition with theOrient,
    //! using the Compose method from the TopAbs package.
    void XTopoDS_Shape::Compose(XTopAbs_Orientation theOrient) {
        NativeHandle->Compose(safe_cast<TopAbs_Orientation>(theOrient));
    };

    //! Returns  a  shape   similar   to  <me>   with  the
    //! orientation composed with theOrient, using the
    //! Compose method from the TopAbs package.
    XTopoDS_Shape^ XTopoDS_Shape::Composed(XTopAbs_Orientation theOrient) {
        return gcnew XTopoDS_Shape(NativeHandle->Composed(safe_cast<TopAbs_Orientation>(theOrient)));
    };

    //! Returns the number of direct sub-shapes (children).
    //! @sa TopoDS_Iterator for accessing sub-shapes
    Standard_Integer XTopoDS_Shape::NbChildren() {
        return NativeHandle->NbChildren();
    };

    //! Returns True if two shapes  are partners, i.e.  if
    //! they   share   the   same  TShape.  Locations  and
    //! Orientations may differ.
    Standard_Boolean XTopoDS_Shape::IsPartner(XTopoDS_Shape^ theOther) {
        return NativeHandle->IsPartner(*theOther->GetShape());
    };

    //! Returns True if two shapes are same, i.e.  if they
    //! share  the  same TShape  with the same  Locations.
    //! Orientations may differ.
    Standard_Boolean XTopoDS_Shape::IsSame(XTopoDS_Shape^ theOther) {
        return NativeHandle->IsSame(*theOther->GetShape());
    };

    //! Returns True if two shapes are equal, i.e. if they
    //! share the same TShape with  the same Locations and
    //! Orientations.
    Standard_Boolean XTopoDS_Shape::IsEqual(XTopoDS_Shape^ theOther) {
        return NativeHandle->IsEqual(*theOther->GetShape());
    };


    //! Returns a hashed value denoting <me>. This value is in the range [1, theUpperBound]. It is computed from the
    //! TShape and the Location. The Orientation is not used.
    //! @param theUpperBound the upper bound of the range a computing hash code must be within
    //! @return a computed hash code, in the range [1, theUpperBound]
    Standard_Integer XTopoDS_Shape::HashCode(Standard_Integer theUpperBound) {
        return NativeHandle->HashCode(theUpperBound);
    };

    //! Replace   <me> by  a  new   Shape with the    same
    //! Orientation and Location and a new TShape with the
    //! same geometry and no sub-shapes.
    void XTopoDS_Shape::EmptyCopy() {
        NativeHandle->EmptyCopy();
    };

    //! Returns a new Shape with the  same Orientation and
    //! Location and  a new TShape  with the same geometry
    //! and no sub-shapes.
    XTopoDS_Shape^ XTopoDS_Shape::EmptyCopied() {
        return gcnew XTopoDS_Shape(NativeHandle->EmptyCopied());
    };

    void XTopoDS_Shape::TShape(XTopoDS_TShape^ theTShape) {
        NativeHandle->TShape(theTShape->GetTShape());
    };

    void XTopoDS_Shape::TShape(XTopoDS_Shape^ theTShape) {
        NativeHandle->TShape(theTShape->TShape()->GetTShape());
    };

    //! Dumps the content of me into the stream
    void XTopoDS_Shape::DumpJson(Standard_OStream theOStream, Standard_Integer theDepth) {
        return NativeHandle->DumpJson(theOStream, theDepth);
    };
}