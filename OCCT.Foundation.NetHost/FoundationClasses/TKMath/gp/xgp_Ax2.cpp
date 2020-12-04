#include <xgp_Ax2.h>

namespace TKMath
{
    //! Creates an object corresponding to the reference
       //! coordinate system (OXYZ).
    xgp_Ax2::xgp_Ax2() {
        NativeHandle = new gp_Ax2();
    };

    /// <summary>
    /// 指针映射点
    /// </summary>
    /// <param name="pos"></param>
    xgp_Ax2::xgp_Ax2(gp_Ax2* pos) {
        NativeHandle = new gp_Ax2(*pos);
    };

    //! Creates an axis placement with an origin P such that:
    //! -   N is the Direction, and
    //! -   the "X Direction" is normal to N, in the plane
    //! defined by the vectors (N, Vx): "X
    //! Direction" = (N ^ Vx) ^ N,
    //! Exception: raises ConstructionError if N and Vx are parallel (same or opposite orientation).
    xgp_Ax2::xgp_Ax2(xgp_Pnt^ P, xgp_Dir^ N, xgp_Dir^ Vx) {
        NativeHandle = new gp_Ax2(*P->GetPnt(),*N->GetDir(), *Vx->GetDir());
    };

    //! Creates an axis placement with an origin P such that:
    //! -   N is the Direction, and
    //! -   the "X Direction" is normal to N, in the plane
    //! defined by the vectors (N, Vx): "X
    //! Direction" = (N ^ Vx) ^ N,
    //! Exception: raises ConstructionError if N and Vx are parallel (same or opposite orientation).
    xgp_Ax2::xgp_Ax2(gp_Pnt P, gp_Dir N, gp_Dir Vx) {
        NativeHandle = new gp_Ax2(P, N, Vx);
    };

    //! Creates -   a coordinate system with an origin P, where V
    //! gives the "main Direction" (here, "X Direction" and "Y
    //! Direction" are defined automatically).
    xgp_Ax2::xgp_Ax2(xgp_Pnt^ P, xgp_Dir^ V) {
        NativeHandle = new gp_Ax2(*P->GetPnt(), *V->GetDir());
    };

    //! Creates -   a coordinate system with an origin P, where V
   //! gives the "main Direction" (here, "X Direction" and "Y
   //! Direction" are defined automatically).
    xgp_Ax2::xgp_Ax2(gp_Pnt P, gp_Dir V) {
        NativeHandle = new gp_Ax2(P, V);
    };

    //释放
    xgp_Ax2::~xgp_Ax2() {
        if (NativeHandle != NULL) {
            delete NativeHandle;
            NativeHandle = NULL;
        }
    };
    //释放
    xgp_Ax2::!xgp_Ax2() {
        if (NativeHandle != NULL) {
            delete NativeHandle;
            NativeHandle = NULL;
        }
    };

    //! Assigns the origin and "main Direction" of the axis A1 to
    //! this coordinate system, then recomputes its "X Direction" and "Y Direction".
    //! Note: The new "X Direction" is computed as follows:
    //! new "X Direction" = V1 ^(previous "X Direction" ^ V)
    //! where V is the "Direction" of A1.
    //! Exceptions
    //! Standard_ConstructionError if A1 is parallel to the "X
    //! Direction" of this coordinate system.
    void xgp_Ax2::SetAxis(xgp_Ax1^ A1) {
        NativeHandle->SetAxis(*A1->GetAx1());
    };


    //! Changes the "main Direction" of this coordinate system,
    //! then recomputes its "X Direction" and "Y Direction".
    //! Note: the new "X Direction" is computed as follows:
    //! new "X Direction" = V ^ (previous "X Direction" ^ V)
    //! Exceptions
    //! Standard_ConstructionError if V is parallel to the "X
    //! Direction" of this coordinate system.
    void xgp_Ax2::SetDirection(xgp_Dir^ V) {
        NativeHandle->SetDirection(*V->GetDir());
    };


    //! Changes the "Location" point (origin) of <me>.
    void xgp_Ax2::SetLocation(xgp_Pnt^ P) {
        NativeHandle->SetLocation(*P->GetPnt());
    };


    //! Changes the "Xdirection" of <me>. The main direction
    //! "Direction" is not modified, the "Ydirection" is modified.
    //! If <Vx> is not normal to the main direction then <XDirection>
    //! is computed as follows XDirection = Direction ^ (Vx ^ Direction).
    //! Exceptions
    //! Standard_ConstructionError if Vx or Vy is parallel to
    //! the "main Direction" of this coordinate system.
    void xgp_Ax2::SetXDirection(xgp_Dir^ Vx) {
        NativeHandle->SetXDirection(*Vx->GetDir());
    };


    //! Changes the "Ydirection" of <me>. The main direction is not
    //! modified but the "Xdirection" is changed.
    //! If <Vy> is not normal to the main direction then "YDirection"
    //! is computed as  follows
    //! YDirection = Direction ^ (<Vy> ^ Direction).
    //! Exceptions
    //! Standard_ConstructionError if Vx or Vy is parallel to
    //! the "main Direction" of this coordinate system.
    void xgp_Ax2::SetYDirection(xgp_Dir^ Vy) {
        NativeHandle->SetYDirection(*Vy->GetDir());
    };


    //! Computes the angular value, in radians, between the main direction of
    //! <me> and the main direction of <Other>. Returns the angle
    //! between 0 and PI in radians.
    Standard_Real xgp_Ax2::Angle(xgp_Ax2^ Other) {
       return NativeHandle->Angle(*Other->GetAx2());
    };

    //获取gp_Ax2
    gp_Ax2* xgp_Ax2::GetAx2() {
        return NativeHandle;
    };

    //! Returns the main axis of <me>. It is the "Location" point
    //! and the main "Direction".
    xgp_Ax1^ xgp_Ax2::Axis() {
        gp_Ax1* temp = new gp_Ax1(NativeHandle->Axis());
        return gcnew  xgp_Ax1(temp);
    };


    //! Returns the main direction of <me>.
    xgp_Dir^ xgp_Ax2::Direction() {
        gp_Dir* temp = new gp_Dir(NativeHandle->Direction());
        return gcnew xgp_Dir(temp);
    };


    //! Returns the "Location" point (origin) of <me>.
    xgp_Pnt^ xgp_Ax2::Location() {
        gp_Pnt* temp = new gp_Pnt(NativeHandle->Location());
        return gcnew  xgp_Pnt(temp);
    };


    //! Returns the "XDirection" of <me>.
    xgp_Dir^ xgp_Ax2::XDirection() {
        gp_Dir* temp = new gp_Dir(NativeHandle->XDirection());
        return gcnew  xgp_Dir(temp);
    };


    //! Returns the "YDirection" of <me>.
    xgp_Dir^ xgp_Ax2::YDirection() {
        gp_Dir* temp = new gp_Dir(NativeHandle->YDirection());
        return gcnew  xgp_Dir(temp);
    };

    Standard_Boolean xgp_Ax2::IsCoplanar(xgp_Ax2^ Other, Standard_Real LinearTolerance, Standard_Real AngularTolerance) {
        return NativeHandle->IsCoplanar(*Other->GetAx2(), LinearTolerance, AngularTolerance);
    };


    //! Returns True if
    //! . the distance between <me> and the "Location" point of A1
    //! is lower of equal to LinearTolerance and
    //! . the main direction of <me> and the direction of A1 are normal.
    //! Note: the tolerance criterion for angular equality is given by AngularTolerance.
    Standard_Boolean xgp_Ax2::IsCoplanar(xgp_Ax1^ A1, Standard_Real LinearTolerance, Standard_Real AngularTolerance) {
        return NativeHandle->IsCoplanar(*A1->GetAx1(), LinearTolerance, AngularTolerance);
    };


    //! Performs a symmetrical transformation of this coordinate
    //! system with respect to:
    //! -   the point P, and assigns the result to this coordinate system.
    //! Warning
    //! This transformation is always performed on the origin.
    //! In case of a reflection with respect to a point:
    //! - the main direction of the coordinate system is not changed, and
    //! - the "X Direction" and the "Y Direction" are simply reversed
    //! In case of a reflection with respect to an axis or a plane:
    //! -   the transformation is applied to the "X Direction"
    //! and the "Y Direction", then
    //! -   the "main Direction" is recomputed as the cross
    //! product "X Direction" ^ "Y   Direction".
    //! This maintains the right-handed property of the
    //! coordinate system.
    void xgp_Ax2::Mirror(xgp_Pnt^ P) {
        NativeHandle->Mirror(*P->GetPnt());
    };


    //! Performs a symmetrical transformation of this coordinate
    //! system with respect to:
    //! -   the point P, and creates a new one.
    //! Warning
    //! This transformation is always performed on the origin.
    //! In case of a reflection with respect to a point:
    //! - the main direction of the coordinate system is not changed, and
    //! - the "X Direction" and the "Y Direction" are simply reversed
    //! In case of a reflection with respect to an axis or a plane:
    //! -   the transformation is applied to the "X Direction"
    //! and the "Y Direction", then
    //! -   the "main Direction" is recomputed as the cross
    //! product "X Direction" ^ "Y   Direction".
    //! This maintains the right-handed property of the
    //! coordinate system.
    xgp_Ax2^ xgp_Ax2::Mirrored(xgp_Pnt^ P) {
        gp_Ax2* temp = new gp_Ax2(NativeHandle->Mirrored(*P->GetPnt()));
        return gcnew xgp_Ax2(temp);
    };


    //! Performs a symmetrical transformation of this coordinate
    //! system with respect to:
    //! -   the axis A1, and assigns the result to this coordinate systeme.
    //! Warning
    //! This transformation is always performed on the origin.
    //! In case of a reflection with respect to a point:
    //! - the main direction of the coordinate system is not changed, and
    //! - the "X Direction" and the "Y Direction" are simply reversed
    //! In case of a reflection with respect to an axis or a plane:
    //! -   the transformation is applied to the "X Direction"
    //! and the "Y Direction", then
    //! -   the "main Direction" is recomputed as the cross
    //! product "X Direction" ^ "Y   Direction".
    //! This maintains the right-handed property of the
    //! coordinate system.
    void xgp_Ax2::Mirror(xgp_Ax1^ A1) {
        NativeHandle->Mirror(*A1->GetAx1());
    };


    //! Performs a symmetrical transformation of this coordinate
    //! system with respect to:
    //! -   the axis A1, and  creates a new one.
    //! Warning
    //! This transformation is always performed on the origin.
    //! In case of a reflection with respect to a point:
    //! - the main direction of the coordinate system is not changed, and
    //! - the "X Direction" and the "Y Direction" are simply reversed
    //! In case of a reflection with respect to an axis or a plane:
    //! -   the transformation is applied to the "X Direction"
    //! and the "Y Direction", then
    //! -   the "main Direction" is recomputed as the cross
    //! product "X Direction" ^ "Y   Direction".
    //! This maintains the right-handed property of the
    //! coordinate system.
    xgp_Ax2^ xgp_Ax2::Mirrored(xgp_Ax1^ A1) {
        gp_Ax2* temp = new gp_Ax2(NativeHandle->Mirrored(*A1->GetAx1()));
        return gcnew xgp_Ax2(temp);
    };


    //! Performs a symmetrical transformation of this coordinate
    //! system with respect to:
    //! -   the plane defined by the origin, "X Direction" and "Y
    //! Direction" of coordinate system A2 and  assigns the result to this coordinate systeme.
    //! Warning
    //! This transformation is always performed on the origin.
    //! In case of a reflection with respect to a point:
    //! - the main direction of the coordinate system is not changed, and
    //! - the "X Direction" and the "Y Direction" are simply reversed
    //! In case of a reflection with respect to an axis or a plane:
    //! -   the transformation is applied to the "X Direction"
    //! and the "Y Direction", then
    //! -   the "main Direction" is recomputed as the cross
    //! product "X Direction" ^ "Y   Direction".
    //! This maintains the right-handed property of the
    //! coordinate system.
    void xgp_Ax2::Mirror(xgp_Ax2^ A2) {
        NativeHandle->Mirror(*A2->GetAx2());
    };


    //! Performs a symmetrical transformation of this coordinate
    //! system with respect to:
    //! -   the plane defined by the origin, "X Direction" and "Y
    //! Direction" of coordinate system A2 and creates a new one.
    //! Warning
    //! This transformation is always performed on the origin.
    //! In case of a reflection with respect to a point:
    //! - the main direction of the coordinate system is not changed, and
    //! - the "X Direction" and the "Y Direction" are simply reversed
    //! In case of a reflection with respect to an axis or a plane:
    //! -   the transformation is applied to the "X Direction"
    //! and the "Y Direction", then
    //! -   the "main Direction" is recomputed as the cross
    //! product "X Direction" ^ "Y   Direction".
    //! This maintains the right-handed property of the
    //! coordinate system.
    xgp_Ax2^ xgp_Ax2::Mirrored(xgp_Ax2^ A2) {
        gp_Ax2* temp = new gp_Ax2(NativeHandle->Mirrored(*A2->GetAx2()));
        return gcnew xgp_Ax2(temp);
    };

    void xgp_Ax2::Rotate(xgp_Ax1^ A1, Standard_Real Ang) {
        NativeHandle->Rotate(*A1->GetAx1(), Ang);
    };


    //! Rotates an axis placement. <A1> is the axis of the
    //! rotation . Ang is the angular value of the rotation
    //! in radians.
    xgp_Ax2^ xgp_Ax2::Rotated(xgp_Ax1^ A1, Standard_Real Ang) {
        gp_Ax2* temp = new gp_Ax2(NativeHandle->Rotated(*A1->GetAx1(), Ang));
        return gcnew xgp_Ax2(temp);
    };

    void xgp_Ax2::Scale(xgp_Pnt^ P, Standard_Real S) {
        NativeHandle->Scale(*P->GetPnt(), S);
    };


    //! Applies a scaling transformation on the axis placement.
    //! The "Location" point of the axisplacement is modified.
    //! Warnings :
    //! If the scale <S> is negative :
    //! . the main direction of the axis placement is not changed.
    //! . The "XDirection" and the "YDirection" are reversed.
    //! So the axis placement stay right handed.
    xgp_Ax2^ xgp_Ax2::Scaled(xgp_Pnt^ P, Standard_Real S) {
        gp_Ax2* temp = new gp_Ax2(NativeHandle->Scaled(*P->GetPnt(), S));
        return gcnew xgp_Ax2(temp);
    };

    void xgp_Ax2::Transform(xgp_Trsf^ T) {
        NativeHandle->Transform(T->GetTrsf());
    };


    //! Transforms an axis placement with a Trsf.
    //! The "Location" point, the "XDirection" and the
    //! "YDirection" are transformed with T.  The resulting
    //! main "Direction" of <me> is the cross product between
    //! the "XDirection" and the "YDirection" after transformation.
    xgp_Ax2^ xgp_Ax2::Transformed(xgp_Trsf^ T) {
        gp_Ax2* temp = new gp_Ax2(NativeHandle->Transformed(T->GetTrsf()));
        return gcnew xgp_Ax2(temp);
    };

    void xgp_Ax2::Translate(xgp_Vec^ V) {
        NativeHandle->Translate(V->GetVec());
    };


    //! Translates an axis plaxement in the direction of the vector
    //! <V>. The magnitude of the translation is the vector's magnitude.
    xgp_Ax2^ xgp_Ax2::Translated(xgp_Vec^ V) {
        gp_Ax2* temp = new gp_Ax2(NativeHandle->Translated(V->GetVec()));
        return gcnew xgp_Ax2(temp);
    };

    void xgp_Ax2::Translate(xgp_Pnt^ P1, xgp_Pnt^ P2) {
        NativeHandle->Translate(*P1->GetPnt(), *P2->GetPnt());
    };


    //! Translates an axis placement from the point <P1> to the
    //! point <P2>.
    xgp_Ax2^ xgp_Ax2::Translated(xgp_Pnt^ P1, xgp_Pnt^ P2) {
        gp_Ax2* temp = new gp_Ax2(NativeHandle->Translated(*P1->GetPnt(), *P2->GetPnt()));
        return gcnew xgp_Ax2(temp);
    };
};