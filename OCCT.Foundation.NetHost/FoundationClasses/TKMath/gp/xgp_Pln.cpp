#include <xgp_Pln.h>

namespace TKMath
{
    //! Creates a plane coincident with OXY plane of the
      //! reference coordinate system.
    xgp_Pln::xgp_Pln(void) {
        NativeHandle = new gp_Pln();
    };

    /// <summary>
    /// 指针映射点
    /// </summary>
    /// <param name="pos"></param>
    xgp_Pln::xgp_Pln(gp_Pln* pos) {
        NativeHandle = new gp_Pln(*pos);
    };
    /// <summary>
    ///  映射点
    /// </summary>
    /// <param name="pos"></param>
    xgp_Pln::xgp_Pln(gp_Pln pos) {
        NativeHandle = new gp_Pln(pos);
    };
    //! The coordinate system of the plane is defined with the axis
    //! placement A3.
    //! The "Direction" of A3 defines the normal to the plane.
    //! The "Location" of A3 defines the location (origin) of the plane.
    //! The "XDirection" and "YDirection" of A3 define the "XAxis" and
    //! the "YAxis" of the plane used to parametrize the plane.
    xgp_Pln::xgp_Pln(xgp_Ax3^ A3) {
        NativeHandle = new gp_Pln(A3->GetAx3());
    };


    //! Creates a plane with the  "Location" point <P>
    //! and the normal direction <V>.
    xgp_Pln::xgp_Pln(xgp_Pnt^ P, xgp_Dir^ V) {
        NativeHandle = new gp_Pln(P->GetPnt(), V->GetDir());
    };


    //! Creates a plane from its cartesian equation :
    //! A * X + B * Y + C * Z + D = 0.0
    //! Raises ConstructionError if Sqrt (A*A + B*B + C*C) <= Resolution from gp.
    xgp_Pln::xgp_Pln(Standard_Real A, Standard_Real B, Standard_Real C, Standard_Real D) {
        NativeHandle = new gp_Pln(A, B, C, D);
    };

    //! 释放
    xgp_Pln::~xgp_Pln() {
        if (NativeHandle != NULL)
            delete NativeHandle;
        NativeHandle = NULL;
    };

    //! 释放
    xgp_Pln::!xgp_Pln() {
        if (NativeHandle != NULL)
            delete NativeHandle;
        NativeHandle = NULL;
    };

    //! gp_Pln
    gp_Pln xgp_Pln::GetPln() {
        return *NativeHandle;
    };

    //! Returns the coefficients of the plane's cartesian equation :
    //! A * X + B * Y + C * Z + D = 0.
    void xgp_Pln::Coefficients(Standard_Real A, Standard_Real B, Standard_Real C, Standard_Real D) {
        NativeHandle->Coefficients(A, B, C, D);
    };

    //! Modifies this plane, by redefining its local coordinate system so that
    //! -   its origin and "main Direction" become those of the
    //! axis A1 (the "X Direction" and "Y Direction" are then recomputed).
    //! Raises ConstructionError if the A1 is parallel to the "XAxis" of the plane.
    void xgp_Pln::SetAxis(xgp_Ax1^ A1) {
        NativeHandle->SetAxis(*A1->GetAx1());
    };

    //! Changes the origin of the plane.
    void xgp_Pln::SetLocation(xgp_Pnt^ Loc) {
        NativeHandle->SetLocation(Loc->GetPnt());
    };

    //! Changes the local coordinate system of the plane.
    void xgp_Pln::SetPosition(xgp_Ax3^ A3) {
        NativeHandle->SetPosition(A3->GetAx3());
    };

    //! Reverses the   U   parametrization of   the  plane
    //! reversing the XAxis.
    void xgp_Pln::UReverse() {
        NativeHandle->UReverse();
    };

    //! Reverses the   V   parametrization of   the  plane
    //! reversing the YAxis.
    void xgp_Pln::VReverse() {
        NativeHandle->VReverse();
    };

    //! returns true if the Ax3 is right handed.
    Standard_Boolean xgp_Pln::Direct() {
        return NativeHandle->Direct();
    };

    //! Returns the plane's normal Axis.
    xgp_Ax1^ xgp_Pln::Axis() {
        gp_Ax1* temp = new gp_Ax1(NativeHandle->Axis());
        return gcnew xgp_Ax1(temp);
    };

    //! Returns the plane's location (origin).
    xgp_Pnt^ xgp_Pln::Location() {
        return gcnew xgp_Pnt(NativeHandle->Location());
    };

    //! Returns the local coordinate system of the plane .
    xgp_Ax3^ xgp_Pln::Position() {
        return gcnew xgp_Ax3(NativeHandle->Position());
    };

    //! Computes the distance between <me> and the point <P>.
    Standard_Real xgp_Pln::Distance(xgp_Pnt^ P) {
        return NativeHandle->Distance(P->GetPnt());
    };

    //! Computes the distance between <me> and the line <L>.
    Standard_Real xgp_Pln::Distance(xgp_Lin^ L) {
        return NativeHandle->Distance(L->GetLin());
    };

    //! Computes the distance between two planes.
    Standard_Real xgp_Pln::Distance(xgp_Pln^ Other) {
        return NativeHandle->Distance(Other->GetPln());
    };


    //! Computes the square distance between <me> and the point <P>.
    Standard_Real xgp_Pln::SquareDistance(xgp_Pnt^ P) {
        return NativeHandle->SquareDistance(P->GetPnt());
    };


    //! Computes the square distance between <me> and the line <L>.
    Standard_Real xgp_Pln::SquareDistance(xgp_Lin^ L) {
        return NativeHandle->SquareDistance(L->GetLin());
    };


    //! Computes the square distance between two planes.
    Standard_Real xgp_Pln::SquareDistance(xgp_Pln^ Other) {
        return NativeHandle->SquareDistance(Other->GetPln());
    };

    //! Returns the X axis of the plane.
    xgp_Ax1^ xgp_Pln::XAxis() {
        gp_Ax1* temp = new gp_Ax1(NativeHandle->XAxis());
        return gcnew xgp_Ax1(temp);
    };

    //! Returns the Y axis  of the plane.
    xgp_Ax1^ xgp_Pln::YAxis() {
        gp_Ax1* temp = new gp_Ax1(NativeHandle->YAxis());
        return gcnew xgp_Ax1(temp);
    };

    //! Returns true if this plane contains the point P. This means that
    //! -   the distance between point P and this plane is less
    //! than or equal to LinearTolerance, or
    //! -   line L is normal to the "main Axis" of the local
    //! coordinate system of this plane, within the tolerance
    //! AngularTolerance, and the distance between the origin
    //! of line L and this plane is less than or equal to
    //! LinearTolerance.
    Standard_Boolean xgp_Pln::Contains(xgp_Pnt^ P, Standard_Real LinearTolerance) {
        return NativeHandle->Contains(P->GetPnt(), LinearTolerance);
    };

    //! Returns true if this plane contains the line L. This means that
    //! -   the distance between point P and this plane is less
    //! than or equal to LinearTolerance, or
    //! -   line L is normal to the "main Axis" of the local
    //! coordinate system of this plane, within the tolerance
    //! AngularTolerance, and the distance between the origin
    //! of line L and this plane is less than or equal to
    //! LinearTolerance.
    Standard_Boolean xgp_Pln::Contains(xgp_Lin^ L, Standard_Real LinearTolerance, Standard_Real AngularTolerance) {
        return NativeHandle->Contains(L->GetLin(), LinearTolerance, AngularTolerance);
    };

    void xgp_Pln::Mirror(xgp_Pnt^ P) {
        NativeHandle->Mirror(P->GetPnt());
    };


    //! Performs the symmetrical transformation of a plane with respect
    //! to the point <P> which is the center of the symmetry
    //! Warnings :
    //! The normal direction to the plane is not changed.
    //! The "XAxis" and the "YAxis" are reversed.
    xgp_Pln^ xgp_Pln::Mirrored(xgp_Pnt^ P) {
        return gcnew xgp_Pln(NativeHandle->Mirrored(P->GetPnt()));
    };

    void xgp_Pln::Mirror(xgp_Ax1^ A1) {
        return NativeHandle->Mirror(*A1->GetAx1());
    };

    //! Performs   the symmetrical transformation  of a
    //! plane with respect to an axis placement  which is the axis
    //! of  the symmetry.  The  transformation is performed on the
    //! "Location" point, on  the "XAxis"  and the "YAxis".    The
    //! resulting normal  direction  is  the cross product between
    //! the "XDirection" and the "YDirection" after transformation
    //! if  the  initial plane was right  handed,  else  it is the
    //! opposite.
    xgp_Pln^ xgp_Pln::Mirrored(xgp_Ax1^ A1) {
        return gcnew xgp_Pln(NativeHandle->Mirrored(*A1->GetAx1()));
    };

    void xgp_Pln::Mirror(xgp_Ax2^ A2) {
        NativeHandle->Mirror(*A2->GetAx2());
    };

    //! Performs the  symmetrical transformation  of  a
    //! plane    with respect to    an axis  placement.   The axis
    //! placement  <A2> locates the plane  of  the symmetry.   The
    //! transformation is performed  on  the  "Location" point, on
    //! the  "XAxis" and  the    "YAxis".  The resulting    normal
    //! direction is the cross  product between   the "XDirection"
    //! and the "YDirection"  after  transformation if the initial
    //! plane was right handed, else it is the opposite.
    xgp_Pln^ xgp_Pln::Mirrored(xgp_Ax2^ A2) {
        return gcnew xgp_Pln(NativeHandle->Mirrored(*A2->GetAx2()));
    };

    void xgp_Pln::Rotate(xgp_Ax1^ A1, Standard_Real Ang) {
        NativeHandle->Rotate(*A1->GetAx1(), Ang);
    };


    //! rotates a plane. A1 is the axis of the rotation.
    //! Ang is the angular value of the rotation in radians.
    xgp_Pln^ xgp_Pln::Rotated(xgp_Ax1^ A1, Standard_Real Ang) {
        return gcnew xgp_Pln(NativeHandle->Rotated(*A1->GetAx1(), Ang));
    };

    void xgp_Pln::Scale(xgp_Pnt^ P, Standard_Real S) {
        NativeHandle->Scale(P->GetPnt(), S);
    };


    //! Scales a plane. S is the scaling value.
    xgp_Pln^ xgp_Pln::Scaled(xgp_Pnt^ P, Standard_Real S) {
        return gcnew xgp_Pln(NativeHandle->Scaled(P->GetPnt(), S));
    };

    void xgp_Pln::Transform(xgp_Trsf^ T) {
        NativeHandle->Transform(T->GetTrsf());
    };


    //! Transforms a plane with the transformation T fromnamespace TKMath  {  public ref class Trsf.
    //! The transformation is performed on the "Location"
    //! point, on the "XAxis" and the "YAxis".
    //! The resulting normal direction is the cross product between
    //! the "XDirection" and the "YDirection" after transformation.
    xgp_Pln^ xgp_Pln::Transformed(xgp_Trsf^ T) {
        return gcnew xgp_Pln(NativeHandle->Transformed(T->GetTrsf()));
    };

    void xgp_Pln::Translate(xgp_Vec^ V) {
        NativeHandle->Translate(V->GetVec());
    };


    //! Translates a plane in the direction of the vector V.
    //! The magnitude of the translation is the vector's magnitude.
    xgp_Pln^ xgp_Pln::Translated(xgp_Vec^ V) {
        return gcnew xgp_Pln(NativeHandle->Translated(V->GetVec()));
    };

    void xgp_Pln::Translate(xgp_Pnt^ P1, xgp_Pnt^ P2) {
        NativeHandle->Translate(P1->GetPnt(), P2->GetPnt());
    };


    //! Translates a plane from the point P1 to the point P2.
    xgp_Pln^ xgp_Pln::Translated(xgp_Pnt^ P1, xgp_Pnt^ P2) {
        return gcnew xgp_Pln(NativeHandle->Translated(P1->GetPnt(), P2->GetPnt()));
    };
};
