#include <XBnd_Box2d.h>
namespace TKMath {
    //! DEFINE_STANDARD_ALLOC

    //! Creates an empty 2D bounding box.
    //! The constructed box is qualified Void. Its gap is null.
    XBnd_Box2d::XBnd_Box2d() {
        NativeHandle = new Bnd_Box2d();
    };

    XBnd_Box2d::XBnd_Box2d(Bnd_Box2d* pos) {
        NativeHandle = pos;
    };

    void XBnd_Box2d::SetBndBox2dHandle(Bnd_Box2d* pos) {
        NativeHandle = pos;
    };

    Bnd_Box2d* XBnd_Box2d::GetBndBox2d() {
        return NativeHandle;
    };

    //! Sets this bounding box so that it covers the whole 2D
    //! space, i.e. it is infinite in all directions.
    void XBnd_Box2d::SetWhole() {
        NativeHandle->SetWhole();
    };

    //! Sets this 2D bounding box so that it is empty. All points are outside a void box.
    void XBnd_Box2d::SetVoid() {
        NativeHandle->SetVoid();
    };

    //! Sets this 2D bounding box so that it bounds
    //! the point P. This involves first setting this bounding box
    //! to be void and then adding the point PThe rectangle bounds   the  point <P>.
    void XBnd_Box2d::Set(xgp_Pnt2d^ thePnt) {
        NativeHandle->Set(*thePnt->GetPnt2d());
    };

    //! Sets this 2D bounding box so that it bounds
    //! the half-line defined by point P and direction D, i.e. all
    //! points M defined by M=P+u*D, where u is greater than
    //! or equal to 0, are inside the bounding area. This involves
    //! first setting this 2D box to be void and then adding the   half-line.
    void XBnd_Box2d::Set(xgp_Pnt2d^ thePnt, xgp_Dir2d^ theDir) {
        NativeHandle->Set(*thePnt->GetPnt2d(), *theDir->GetDir2d());
    };

    //! Enlarges this 2D bounding box, if required, so that it
    //! contains at least:
    //! -   interval [ aXmin,aXmax ] in the "X Direction",
    //! -   interval [ aYmin,aYmax ] in the "Y Direction"
    void XBnd_Box2d::Update(Standard_Real aXmin, Standard_Real aYmin, Standard_Real aXmax, Standard_Real aYmax) {
        NativeHandle->Update(aXmin, aYmin, aXmax, aYmax);
    };

    //! Adds a point of coordinates (X,Y) to this bounding box.
    void XBnd_Box2d::Update(Standard_Real X, Standard_Real Y) {
        NativeHandle->Update(X, Y);
    };

    //! Returns the gap of this 2D bounding box.
    Standard_Real XBnd_Box2d::GetGap() {
        return  NativeHandle->GetGap();
    };

    //! Set the gap of this 2D bounding box to abs(Tol).
    void XBnd_Box2d::SetGap(Standard_Real Tol) {
        NativeHandle->SetGap(Tol);
    };

    //! Enlarges     the  box  with    a  tolerance  value.
    //! This means that the minimum values of its X and Y
    //! intervals of definition, when they are finite, are reduced by
    //! the absolute value of Tol, while the maximum values are
    //! increased by the same amount.
    void XBnd_Box2d::Enlarge(Standard_Real theTol) {
        NativeHandle->Enlarge(theTol);
    };

    //! Returns the bounds of this 2D bounding box.
    //! The gap is included. If this bounding box is infinite (i.e. "open"), returned values
    //! may be equal to +/- Precision::Infinite().
    //! if IsVoid()
    void XBnd_Box2d::Get(Standard_Real% aXmin, Standard_Real% aYmin, Standard_Real% aXmax, Standard_Real% aYmax) {
        Standard_Real aXminX(aXmin); Standard_Real aYminX(aXmin); Standard_Real aXmaxX(aXmax); Standard_Real aYmaxX(aYmax);
        NativeHandle->Get(aXminX, aYminX, aXmaxX, aYmaxX);
        aXmin = aXminX; aYmin = aYminX; aXmax = aXmaxX; aYmax =aYmaxX;
    };

    //! The Box will be infinitely long in the Xmin direction.
    void XBnd_Box2d::OpenXmin() {
        NativeHandle->OpenXmin();
    };

    //! The Box will be infinitely long in the Xmax direction.
    void XBnd_Box2d::OpenXmax() {
        NativeHandle->OpenXmax();
    };

    //! The Box will be infinitely long in the Ymin direction.
    void XBnd_Box2d::OpenYmin() {
        NativeHandle->OpenYmin();
    };

    //! The Box will be infinitely long in the Ymax direction.
    void XBnd_Box2d::OpenYmax() {
        NativeHandle->OpenYmax();
    };

    //! Returns true if this bounding box is open in the Xmin direction.
    Standard_Boolean XBnd_Box2d::IsOpenXmin() {
        return NativeHandle->IsOpenXmin();
    };

    //! Returns true if this bounding box is open in the Xmax direction.
    Standard_Boolean XBnd_Box2d::IsOpenXmax() {
        return NativeHandle->IsOpenXmax();
    };

    //! Returns true if this bounding box is open in the Ymin direction.
    Standard_Boolean XBnd_Box2d::IsOpenYmin() {
        return NativeHandle->IsOpenYmin();
    };

    //! Returns true if this bounding box is open in the Ymax direction.
    Standard_Boolean XBnd_Box2d::IsOpenYmax() {
        return NativeHandle->IsOpenYmax();
    };

    //! Returns true if this bounding box is infinite in all 4
    //! directions (Whole Space flag).
    Standard_Boolean XBnd_Box2d::IsWhole() {
        return NativeHandle->IsWhole();
    };

    //! Returns true if this 2D bounding box is empty (Void flag).
    Standard_Boolean XBnd_Box2d::IsVoid() {
        return NativeHandle->IsVoid();
    };

    //! Returns a bounding box which is the result of applying the
    //! transformation T to this bounding box.
    //! Warning
    //! Applying a geometric transformation (for example, a
    //! rotation) to a bounding box generally increases its
    //! dimensions. This is not optimal for algorithms which use it.
    XBnd_Box2d^ XBnd_Box2d::Transformed(xgp_Trsf2d^ T) {
        Bnd_Box2d* temp = new Bnd_Box2d(NativeHandle->Transformed(*T->GetTrsf2d()));
        return gcnew XBnd_Box2d(temp);
    };

    //! Adds the 2d box <Other> to <me>.
    void XBnd_Box2d::Add(XBnd_Box2d^ Other) {
        NativeHandle->Add(*Other->GetBndBox2d());
    };

    //! Adds the 2d point.
    void XBnd_Box2d::Add(xgp_Pnt2d^ thePnt) {
        NativeHandle->Add(*thePnt->GetPnt2d());
    }; 

    //! Extends bounding box from thePnt in the direction theDir.
    void XBnd_Box2d::Add(xgp_Pnt2d^ thePnt, xgp_Dir2d^ theDir) {
        NativeHandle->Add(*thePnt->GetPnt2d(), *theDir->GetDir2d());
    };

    //! Extends the Box  in the given Direction, i.e. adds
    //! a half-line. The box may become infinite in 1 or 2
    //! directions.
    void XBnd_Box2d::Add(xgp_Dir2d^ D) {
        NativeHandle->Add(*D->GetDir2d());
    };

    //! Returns True if the 2d pnt <P> is out <me>.
    Standard_Boolean XBnd_Box2d::IsOut(xgp_Pnt2d^ P) {
        return NativeHandle->IsOut(*P->GetPnt2d());
    };

    //! Returns True if <Box2d> is out <me>.
    Standard_Boolean XBnd_Box2d::IsOut(XBnd_Box2d^ Other) {
        return NativeHandle->IsOut(*Other->GetBndBox2d());
    };

    //! Returns True if transformed <Box2d> is out <me>.
    Standard_Boolean XBnd_Box2d::IsOut(XBnd_Box2d^ theOther, xgp_Trsf2d^ theTrsf) {
        return NativeHandle->IsOut(*theOther->GetBndBox2d(), *theTrsf->GetTrsf2d());
    };

    //! Compares  a transformed  bounding with  a    transformed
    //! bounding. The default implementation is  to make a copy
    //! of <me> and <Other>, to transform them and to test.
    Standard_Boolean XBnd_Box2d::IsOut(xgp_Trsf2d^ T1, XBnd_Box2d^ Other, xgp_Trsf2d^ T2) {
        return NativeHandle->IsOut(*T1->GetTrsf2d(), *Other->GetBndBox2d(), *T2->GetTrsf2d());
    };

    void XBnd_Box2d::Dump() {
        return NativeHandle->Dump();
    };

    //! Computes the squared diagonal of me.
    Standard_Real XBnd_Box2d::SquareExtent() {
        return NativeHandle->SquareExtent();
    };
}
