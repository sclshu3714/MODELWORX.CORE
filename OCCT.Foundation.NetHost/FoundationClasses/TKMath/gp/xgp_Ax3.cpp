#include <xgp_Ax3.h>

namespace TKMath
{
    //! Creates an object corresponding to the reference
        //! coordinate system (OXYZ).
    xgp_Ax3::xgp_Ax3(void) {
        NativeHandle = new gp_Ax3();
    };

    /// <summary>
    /// 指针映射点
    /// </summary>
    /// <param name="pos"></param>
    xgp_Ax3::xgp_Ax3(gp_Ax3* pos) {
        NativeHandle = new gp_Ax3(*pos);
    };
    /// <summary>
    ///  映射点
    /// </summary>
    /// <param name="pos"></param>
    xgp_Ax3::xgp_Ax3(gp_Ax3 pos) {
        NativeHandle = new gp_Ax3(pos);
    };

    //! Creates  a  coordinate  system from a right-handed
    //! coordinate system.
    xgp_Ax3::xgp_Ax3(xgp_Ax2^ A) {
        NativeHandle = new gp_Ax3(*A->GetAx2());
    };

    //! Creates a  right handed axis placement with the
    //! "Location"  point  P  and  two  directions, N    gives the
    //! "Direction" and Vx gives the "XDirection".
    //! Raises ConstructionError if N and Vx are parallel (same or opposite orientation).
    xgp_Ax3::xgp_Ax3(xgp_Pnt^ P, xgp_Dir^ N, xgp_Dir^ Vx) {
        NativeHandle = new gp_Ax3(P->GetPnt(), N->GetDir(), Vx->GetDir());
    };


    //! Creates an axis placement with the  "Location" point <P>
    //! and the normal direction <V>.
    xgp_Ax3::xgp_Ax3(xgp_Pnt^ P, xgp_Dir^ V) {
        NativeHandle = new gp_Ax3(P->GetPnt(), V->GetDir());
    };

    //释放
    xgp_Ax3::~xgp_Ax3() {
        if (NativeHandle != NULL) {
            delete NativeHandle;
            NativeHandle = NULL;
        }
    };
    //释放
    xgp_Ax3::!xgp_Ax3() {
        if (NativeHandle != NULL) {
            delete NativeHandle;
            NativeHandle = NULL;
        }
    };
    //! Return the gp_Ax3
    gp_Ax3 xgp_Ax3::GetAx3() {
        return *NativeHandle;
    };

    //! Reverses the X direction of <me>.
    void xgp_Ax3::XReverse() {
        NativeHandle->XReverse();
    };

    //! Reverses the Y direction of <me>.
    void xgp_Ax3::YReverse() {
        NativeHandle->YReverse();
    };

    //! Reverses the Z direction of <me>.
    void xgp_Ax3::ZReverse() {
        NativeHandle->ZReverse();
    };

    //! Assigns the origin and "main Direction" of the axis A1 to
    //! this coordinate system, then recomputes its "X Direction" and "Y Direction".
    //! Note:
    //! -   The new "X Direction" is computed as follows:
    //! new "X Direction" = V1 ^(previous "X Direction" ^ V)
    //! where V is the "Direction" of A1.
    //! -   The orientation of this coordinate system
    //! (right-handed or left-handed) is not modified.
    //! Raises ConstructionError  if the "Direction" of <A1> and the "XDirection" of <me>
    //! are parallel (same or opposite orientation) because it is
    //! impossible to calculate the new "XDirection" and the new
    //! "YDirection".
    void xgp_Ax3::SetAxis(xgp_Ax1^ A1) {
        NativeHandle->SetAxis(*A1->GetAx1());
    };


    //! Changes the main direction of this coordinate system,
    //! then recomputes its "X Direction" and "Y Direction".
    //! Note:
    //! -   The new "X Direction" is computed as follows:
    //! new "X Direction" = V ^ (previous "X Direction" ^ V).
    //! -   The orientation of this coordinate system (left- or right-handed) is not modified.
    //! Raises ConstructionError if <V< and the previous "XDirection" are parallel
    //! because it is impossible to calculate the new "XDirection"
    //! and the new "YDirection".
    void xgp_Ax3::SetDirection(xgp_Dir^ V) {
        NativeHandle->SetDirection(V->GetDir());
    };


    //! Changes the "Location" point (origin) of <me>.
    void xgp_Ax3::SetLocation(xgp_Pnt^ P) {
        NativeHandle->SetLocation(P->GetPnt());
    };


    //! Changes the "Xdirection" of <me>. The main direction
    //! "Direction" is not modified, the "Ydirection" is modified.
    //! If <Vx> is not normal to the main direction then <XDirection>
    //! is computed as follows XDirection = Direction ^ (Vx ^ Direction).
    //! Raises ConstructionError if <Vx> is parallel (same or opposite
    //! orientation) to the main direction of <me>
    void xgp_Ax3::SetXDirection(xgp_Dir^ Vx) {
        NativeHandle->SetXDirection(Vx->GetDir());
    };


    //! Changes the "Ydirection" of <me>. The main direction is not
    //! modified but the "Xdirection" is changed.
    //! If <Vy> is not normal to the main direction then "YDirection"
    //! is computed as  follows
    //! YDirection = Direction ^ (<Vy> ^ Direction).
    //! Raises ConstructionError if <Vy> is parallel to the main direction of <me>
    void xgp_Ax3::SetYDirection(xgp_Dir^ Vy) {
        NativeHandle->SetYDirection(Vy->GetDir());
    };


    //! Computes the angular value between the main direction of
    //! <me> and the main direction of <Other>. Returns the angle
    //! between 0 and PI in radians.
    Standard_Real xgp_Ax3::Angle(xgp_Ax3^ Other) {
        return NativeHandle->Angle(Other->GetAx3());
    };


    //! Returns the main axis of <me>. It is the "Location" point
    //! and the main "Direction".
    xgp_Ax1^ xgp_Ax3::Axis() {
        gp_Ax1* temp = new gp_Ax1(NativeHandle->Axis());
        return gcnew xgp_Ax1(temp);
    };

    //! Computes a right-handed coordinate system with the
    //! same "X Direction" and "Y Direction" as those of this
    //! coordinate system, then recomputes the "main Direction".
    //! If this coordinate system is right-handed, the result
    //! returned is the same coordinate system. If this
    //! coordinate system is left-handed, the result is reversed.
    xgp_Ax2^ xgp_Ax3::Ax2() {
        gp_Ax2* temp = new gp_Ax2(NativeHandle->Ax2());
        return gcnew xgp_Ax2(temp);
    };


    //! Returns the main direction of <me>.
    xgp_Dir^ xgp_Ax3::Direction() {
        return gcnew xgp_Dir(NativeHandle->Direction());
    };


    //! Returns the "Location" point (origin) of <me>.
    xgp_Pnt^ xgp_Ax3::Location() {
        return gcnew xgp_Pnt(NativeHandle->Location());
    };


    //! Returns the "XDirection" of <me>.
    xgp_Dir^ xgp_Ax3::XDirection() {
        return gcnew xgp_Dir(NativeHandle->XDirection());
    };


    //! Returns the "YDirection" of <me>.
    xgp_Dir^ xgp_Ax3::YDirection() {
        return gcnew xgp_Dir(NativeHandle->YDirection());
    };

    //! Returns  True if  the  coordinate  system is right-handed. i.e.
    //! XDirection().Crossed(YDirection()).Dot(Direction()) > 0
    Standard_Boolean xgp_Ax3::Direct() {
        return NativeHandle->Direct();
    };


    //! Returns True if
    //! . the distance between the "Location" point of <me> and
    //! <Other> is lower or equal to LinearTolerance and
    //! . the distance between the "Location" point of <Other> and
    //! <me> is lower or equal to LinearTolerance and
    //! . the main direction of <me> and the main direction of
    //! <Other> are parallel (same or opposite orientation).
    Standard_Boolean xgp_Ax3::IsCoplanar(xgp_Ax3^ Other, Standard_Real LinearTolerance, Standard_Real AngularTolerance) {
        return NativeHandle->IsCoplanar(Other->GetAx3(), LinearTolerance, AngularTolerance);
    };

    //! Returns True if
    //! . the distance between <me> and the "Location" point of A1
    //! is lower of equal to LinearTolerance and
    //! . the distance between A1 and the "Location" point of <me>
    //! is lower or equal to LinearTolerance and
    //! . the main direction of <me> and the direction of A1 are normal.
    Standard_Boolean xgp_Ax3::IsCoplanar(xgp_Ax1^ A1, Standard_Real LinearTolerance, Standard_Real AngularTolerance) {
        return NativeHandle->IsCoplanar(*A1->GetAx1(), LinearTolerance, AngularTolerance);
    };

    void xgp_Ax3::Mirror(xgp_Pnt^ P) {
        NativeHandle->Mirror(P->GetPnt());
    };


    //! Performs the symmetrical transformation of an axis
    //! placement with respect to the point P which is the
    //! center of the symmetry.
    //! Warnings :
    //! The main direction of the axis placement is not changed.
    //! The "XDirection" and the "YDirection" are reversed.
    //! So the axis placement stay right handed.
    xgp_Ax3^ xgp_Ax3::Mirrored(xgp_Pnt^ P) {
        return gcnew xgp_Ax3(NativeHandle->Mirrored(P->GetPnt()));
    };

    void xgp_Ax3::Mirror(xgp_Ax1^ A1) {
        NativeHandle->Mirror(*A1->GetAx1());
    };


    //! Performs the symmetrical transformation of an axis
    //! placement with respect to an axis placement which
    //! is the axis of the symmetry.
    //! The transformation is performed on the "Location"
    //! point, on the "XDirection" and "YDirection".
    //! The resulting main "Direction" is the cross product between
    //! the "XDirection" and the "YDirection" after transformation.
    xgp_Ax3^ xgp_Ax3::Mirrored(xgp_Ax1^ A1) {
        return gcnew xgp_Ax3(NativeHandle->Mirrored(*A1->GetAx1()));
    };

    void xgp_Ax3::Mirror(xgp_Ax2^ A2) {
        NativeHandle->Mirror(*A2->GetAx2());
    };


    //! Performs the symmetrical transformation of an axis
    //! placement with respect to a plane.
    //! The axis placement  <A2> locates the plane of the symmetry :
    //! (Location, XDirection, YDirection).
    //! The transformation is performed on the "Location"
    //! point, on the "XDirection" and "YDirection".
    //! The resulting main "Direction" is the cross product between
    //! the "XDirection" and the "YDirection" after transformation.
    xgp_Ax3^ xgp_Ax3::Mirrored(xgp_Ax2^ A2) {
        return gcnew xgp_Ax3(NativeHandle->Mirrored(*A2->GetAx2()));
    };

    void xgp_Ax3::Rotate(xgp_Ax1^ A1, Standard_Real Ang) {
        NativeHandle->Rotate(*A1->GetAx1(), Ang);
    };


    //! Rotates an axis placement. <A1> is the axis of the
    //! rotation . Ang is the angular value of the rotation
    //! in radians.
    xgp_Ax3^ xgp_Ax3::Rotated(xgp_Ax1^ A1, Standard_Real Ang) {
        return gcnew xgp_Ax3(NativeHandle->Rotated(*A1->GetAx1(), Ang));
    };

    void xgp_Ax3::Scale(xgp_Pnt^ P, Standard_Real S) {
        NativeHandle->Scale(P->GetPnt(), S);
    };


    //! Applies a scaling transformation on the axis placement.
    //! The "Location" point of the axisplacement is modified.
    //! Warnings :
    //! If the scale <S> is negative :
    //! . the main direction of the axis placement is not changed.
    //! . The "XDirection" and the "YDirection" are reversed.
    //! So the axis placement stay right handed.
    xgp_Ax3^ xgp_Ax3::Scaled(xgp_Pnt^ P, Standard_Real S) {
        return gcnew xgp_Ax3(NativeHandle->Scaled(P->GetPnt(), S));
    };

    void xgp_Ax3::Transform(xgp_Trsf^ T) {
        NativeHandle->Transform(T->GetTrsf());
    };


    //! Transforms an axis placement with a Trsf.
    //! The "Location" point, the "XDirection" and the
    //! "YDirection" are transformed with T.  The resulting
    //! main "Direction" of <me> is the cross product between
    //! the "XDirection" and the "YDirection" after transformation.
    xgp_Ax3^ xgp_Ax3::Transformed(xgp_Trsf^ T) {
        return gcnew xgp_Ax3(NativeHandle->Transformed(T->GetTrsf()));
    };

    void xgp_Ax3::Translate(xgp_Vec^ V) {
        NativeHandle->Translate(V->GetVec());
    };


    //! Translates an axis plaxement in the direction of the vector
    //! <V>. The magnitude of the translation is the vector's magnitude.
    xgp_Ax3^ xgp_Ax3::Translated(xgp_Vec^ V) {
        return gcnew xgp_Ax3(NativeHandle->Translated(V->GetVec()));
    };

    void xgp_Ax3::Translate(xgp_Pnt^ P1, xgp_Pnt^ P2) {
        NativeHandle->Translate(P1->GetPnt(), P2->GetPnt());
    };


    //! Translates an axis placement from the point <P1> to the
    //! point <P2>.
    xgp_Ax3^ xgp_Ax3::Translated(xgp_Pnt^ P1, xgp_Pnt^ P2) {
        return gcnew xgp_Ax3(NativeHandle->Translated(P1->GetPnt(), P2->GetPnt()));
    };
};

