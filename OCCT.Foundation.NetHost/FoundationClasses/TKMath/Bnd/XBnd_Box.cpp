#include <XBnd_Box.h>

namespace TKMath {

    //! Creates an empty Box.
    //! The constructed box is qualified Void. Its gap is null.
    XBnd_Box::XBnd_Box() {
        NativeHandle = new Bnd_Box();
    };

    XBnd_Box::XBnd_Box(Bnd_Box* pos) {
        NativeHandle = pos;
    };

    void XBnd_Box::SetBndBoxHandle(Bnd_Box* pos) {
        NativeHandle = pos;
    };

    Bnd_Box* XBnd_Box::GetBndBox() {
        return NativeHandle;
    };

    //! Creates a bounding box, it contains:
    //! -   minimum/maximum point of bouning box,
    //! The constructed box is qualified Void. Its gap is null.
    XBnd_Box::XBnd_Box(xgp_Pnt^ theMin, xgp_Pnt^ theMax) {
        NativeHandle = new Bnd_Box(*theMin->GetPnt(), *theMax->GetPnt());
    };

    //! Sets this bounding box so that it  covers the whole of 3D space.
    //! It is infinitely  long in all directions.
    void XBnd_Box::SetWhole() {
        NativeHandle->SetWhole();
    };

    //! Sets this bounding box so that it is empty. All points are outside a void box.
    void XBnd_Box::SetVoid() {
        NativeHandle->SetVoid();
    };

    //! Sets this bounding box so that it bounds
    //! -   the point P. This involves first setting this bounding box
    //! to be void and then adding the point P.
    void XBnd_Box::Set(xgp_Pnt^ P) {
        NativeHandle->Set(*P->GetPnt());
    };

    //! Sets this bounding box so that it bounds
    //! the half-line defined by point P and direction D, i.e. all
    //! points M defined by M=P+u*D, where u is greater than
    //! or equal to 0, are inside the bounding volume. This
    //! involves first setting this box to be void and then adding   the half-line.
    void XBnd_Box::Set(xgp_Pnt^ P, xgp_Dir^ D) {
        NativeHandle->Set(*P->GetPnt(), *D->GetDir());
    };

    //! Enlarges this bounding box, if required, so that it
    //! contains at least:
    //! -   interval [ aXmin,aXmax ] in the "X Direction",
    //! -   interval [ aYmin,aYmax ] in the "Y Direction",
    //! -   interval [ aZmin,aZmax ] in the "Z Direction";
    void XBnd_Box::Update(Standard_Real aXmin, Standard_Real aYmin, Standard_Real aZmin, Standard_Real aXmax, Standard_Real aYmax, Standard_Real aZmax) {
        NativeHandle->Update(aXmin, aYmin, aZmin, aXmax, aYmax, aZmax);
    };

    //! Adds a point of coordinates (X,Y,Z) to this bounding box.
    void XBnd_Box::Update(Standard_Real X, Standard_Real Y, Standard_Real Z) {
        NativeHandle->Update(X, Y, Z);
    };

    //! Returns the gap of this bounding box.
    Standard_Real XBnd_Box::GetGap() {
        return NativeHandle->GetGap();
    };

    //! Set the gap of this bounding box to abs(Tol).
    void XBnd_Box::SetGap(Standard_Real Tol) {
        NativeHandle->SetGap(Tol);
    };

    //! Enlarges the      box    with    a   tolerance   value.
    //! (minvalues-Abs(<tol>) and maxvalues+Abs(<tol>))
    //! This means that the minimum values of its X, Y and Z
    //! intervals of definition, when they are finite, are reduced by
    //! the absolute value of Tol, while the maximum values are
    //! increased by the same amount.
    void XBnd_Box::Enlarge(Standard_Real Tol) {
        NativeHandle->Enlarge(Tol);
    };

    //! Returns the bounds of this bounding box. The gap is included.
    //! If this bounding box is infinite (i.e. "open"), returned values
    //! may be equal to +/- Precision::Infinite().
    //! Standard_ConstructionError exception will be thrown if the box is void.
    //! if IsVoid()
    void XBnd_Box::Get(Standard_Real% theXmin, Standard_Real% theYmin, Standard_Real% theZmin, Standard_Real% theXmax, Standard_Real% theYmax, Standard_Real% theZmax) {
        Standard_Real theXminX(theXmin); Standard_Real theYminX(theYmin);  Standard_Real theZminX(theZmin); Standard_Real theXmaxX(theXmax); Standard_Real theYmaxX(theYmax); Standard_Real theZmaxX(theZmax);
        NativeHandle->Get(theXminX, theYminX, theZminX, theXmaxX, theYmaxX, theZmaxX);
        theXmin = theXminX; theYmin = theYminX; theZmin = theZminX; theXmax = theXmaxX; theYmax = theYmaxX; theZmax = theZmaxX;
    };

    //! Returns the lower corner of this bounding box. The gap is included.
    //! If this bounding box is infinite (i.e. "open"), returned values
    //! may be equal to +/- Precision::Infinite().
    //! Standard_ConstructionError exception will be thrown if the box is void.
    //! if IsVoid()
    xgp_Pnt^ XBnd_Box::CornerMin() {
        gp_Pnt* temp = new gp_Pnt(NativeHandle->CornerMin());
        return gcnew xgp_Pnt(temp);
    };

    //! Returns the upper corner of this bounding box. The gap is included.
    //! If this bounding box is infinite (i.e. "open"), returned values
    //! may be equal to +/- Precision::Infinite().
    //! Standard_ConstructionError exception will be thrown if the box is void.
    //! if IsVoid()
    xgp_Pnt^ XBnd_Box::CornerMax() {
        gp_Pnt* temp = new gp_Pnt(NativeHandle->CornerMax());
        return gcnew xgp_Pnt(temp);
    };

    //! The   Box will be   infinitely   long  in the Xmin
    //! direction.
    void XBnd_Box::OpenXmin() {
        NativeHandle->OpenXmin();
    };

    //! The   Box will be   infinitely   long  in the Xmax
    //! direction.
    void XBnd_Box::OpenXmax() {
        NativeHandle->OpenXmax();
    };

    //! The   Box will be   infinitely   long  in the Ymin
    //! direction.
    void XBnd_Box::OpenYmin() {
        NativeHandle->OpenYmin();
    };

    //! The   Box will be   infinitely   long  in the Ymax
    //! direction.
    void XBnd_Box::OpenYmax() {
        NativeHandle->OpenYmax();
    };

    //! The   Box will be   infinitely   long  in the Zmin
    //! direction.
    void XBnd_Box::OpenZmin() {
        NativeHandle->OpenZmin();
    };

    //! The   Box will be   infinitely   long  in the Zmax
    //! direction.
    void XBnd_Box::OpenZmax() {
        NativeHandle->OpenZmax();
    };

    //! Returns true if this bounding box has at least one open direction.
    Standard_Boolean XBnd_Box::IsOpen() {
        return  NativeHandle->IsOpen();
    };

    //! Returns true if this bounding box is open in the  Xmin direction.
    Standard_Boolean XBnd_Box::IsOpenXmin() {
        return  NativeHandle->IsOpenXmin();
    };

    //! Returns true if this bounding box is open in the  Xmax direction.
    Standard_Boolean XBnd_Box::IsOpenXmax() {
        return  NativeHandle->IsOpenXmax();
    };

    //! Returns true if this bounding box is open in the  Ymix direction.
    Standard_Boolean XBnd_Box::IsOpenYmin() {
        return  NativeHandle->IsOpenYmin();
    };

    //! Returns true if this bounding box is open in the  Ymax direction.
    Standard_Boolean XBnd_Box::IsOpenYmax() {
        return  NativeHandle->IsOpenYmax();
    };

    //! Returns true if this bounding box is open in the  Zmin direction.
    Standard_Boolean XBnd_Box::IsOpenZmin() {
        return  NativeHandle->IsOpenZmin();
    };

    //! Returns true if this bounding box is open in the  Zmax  direction.
    Standard_Boolean XBnd_Box::IsOpenZmax() {
        return  NativeHandle->IsOpenZmax();
    };

    //! Returns true if this bounding box is infinite in all 6 directions (WholeSpace flag).
    Standard_Boolean XBnd_Box::IsWhole() {
        return  NativeHandle->IsWhole();
    };

    //! Returns true if this bounding box is empty (Void flag).
    Standard_Boolean XBnd_Box::IsVoid() {
        return  NativeHandle->IsVoid();
    };

    //! true if xmax-xmin < tol.
    Standard_Boolean XBnd_Box::IsXThin(Standard_Real tol) {
        return  NativeHandle->IsXThin(tol);
    };

    //! true if ymax-ymin < tol.
    Standard_Boolean XBnd_Box::IsYThin(Standard_Real tol) {
        return  NativeHandle->IsYThin(tol);
    };

    //! true if zmax-zmin < tol.
    Standard_Boolean XBnd_Box::IsZThin(Standard_Real tol) {
        return  NativeHandle->IsZThin(tol);
    };

    //! Returns true if IsXThin, IsYThin and IsZThin are all true,
    //! i.e. if the box is thin in all three dimensions.
    Standard_Boolean XBnd_Box::IsThin(Standard_Real tol) {
        return  NativeHandle->IsThin(tol);
    };

    //! Returns a bounding box which is the result of applying the
    //! transformation T to this bounding box.
    //! Warning
    //! Applying a geometric transformation (for example, a
    //! rotation) to a bounding box generally increases its
    //! dimensions. This is not optimal for algorithms which use it.
    XBnd_Box^ XBnd_Box::Transformed(xgp_Trsf^ T) {
        Bnd_Box* temp = new Bnd_Box(NativeHandle->Transformed(*T->GetTrsf()));
        return gcnew XBnd_Box(temp);
    };

    //! Adds the box <Other> to <me>.
    void XBnd_Box::Add(XBnd_Box^ Other) {
        NativeHandle->Add(*Other->GetBndBox());
    };

    //! Adds a Pnt to the box.
    void XBnd_Box::Add(xgp_Pnt^ P) {
        NativeHandle->Add(*P->GetPnt());
    };

    //! Extends  <me> from the Pnt <P> in the direction <D>.
    void XBnd_Box::Add(xgp_Pnt^ P, xgp_Dir^ D) {
        NativeHandle->Add(*P->GetPnt(), *D->GetDir());
    };

    //! Extends the Box  in the given Direction, i.e. adds
    //! an  half-line. The   box  may become   infinite in
    //! 1,2 or 3 directions.
    void XBnd_Box::Add(xgp_Dir^ D) {
        NativeHandle->Add(*D->GetDir());
    };

    //! Returns True if the Pnt is out the box.
    Standard_Boolean XBnd_Box::IsOut(xgp_Pnt^ P) {
        return NativeHandle->IsOut(*P->GetPnt());
    };

    //! Returns False if the line intersects the box.
    Standard_Boolean XBnd_Box::IsOut(xgp_Lin^ L) {
        return NativeHandle->IsOut(*L->GetLin());
    };

    //! Returns False if the plane intersects the box.
    Standard_Boolean XBnd_Box::IsOut(xgp_Pln^ P) {
        return NativeHandle->IsOut(*P->GetPln());
    };

    //! Returns False if the <Box> intersects or is inside <me>.
    Standard_Boolean XBnd_Box::IsOut(XBnd_Box^ Other) {
        return NativeHandle->IsOut(*Other->GetBndBox());
    };

    //! Returns False if  the transformed <Box> intersects
    //! or  is inside <me>.
    Standard_Boolean XBnd_Box::IsOut(XBnd_Box^ Other, xgp_Trsf^ T) {
        return NativeHandle->IsOut(*Other->GetBndBox(), *T->GetTrsf());
    };

    //! Returns False  if the transformed <Box> intersects
    //! or  is inside the transformed box <me>.
    Standard_Boolean XBnd_Box::IsOut(xgp_Trsf^ T1, XBnd_Box^ Other, xgp_Trsf^ T2) {
        return NativeHandle->IsOut(*T1->GetTrsf(), *Other->GetBndBox(), *T2->GetTrsf());
    };

    //! Returns False  if the flat band lying between two parallel
    //! lines represented by their reference points <P1>, <P2> and
    //! direction <D> intersects the box.
    Standard_Boolean XBnd_Box::IsOut(xgp_Pnt^ P1, xgp_Pnt^ P2, xgp_Dir^ D) {
        return NativeHandle->IsOut(*P1->GetPnt(), *P2->GetPnt(), *D->GetDir());
    };

    //! Computes the minimum distance between two boxes.
    Standard_Real XBnd_Box::Distance(XBnd_Box^ Other) {
        return NativeHandle->Distance(*Other->GetBndBox());
    };

    void XBnd_Box::Dump() {
        NativeHandle->Dump();
    };

    //! Computes the squared diagonal of me.
    Standard_Real XBnd_Box::SquareExtent() {
        return NativeHandle->SquareExtent();
    };

    //! Returns a finite part of an infinite bounding box (returns self if this is already finite box).
    //! This can be a Void box in case if its sides has been defined as infinite (Open) without adding any finite points.
    //! WARNING! This method relies on Open flags, the infinite points added using Add() method will be returned as is.
    XBnd_Box^ XBnd_Box::FinitePart() {
        Bnd_Box* temp = new Bnd_Box(NativeHandle->FinitePart());
        return gcnew XBnd_Box(temp);
    };

    //! Returns TRUE if this box has finite part.
    Standard_Boolean XBnd_Box::HasFinitePart() {
        return NativeHandle->HasFinitePart();
    };

    //! Dumps the content of me into the stream
    //! Standard_Integer theDepth = -1
    void XBnd_Box::DumpJson(Standard_OStream& theOStream, Standard_Integer theDepth) {
        return NativeHandle->DumpJson(theOStream, theDepth);
    };
}