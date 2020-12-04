#include <xgp_Ax22d.h>

namespace TKMath
{
    //! Creates an object representing the reference
        //! co-ordinate system (OXY).
    xgp_Ax22d::xgp_Ax22d(void) {
        NativeHandle = new gp_Ax22d();
    };

    /// <summary>
    /// 指针映射点
    /// </summary>
    /// <param name="pos"></param>
    xgp_Ax22d::xgp_Ax22d(gp_Ax22d* pos) {
        NativeHandle = new gp_Ax22d(*pos);
    };


    //! Creates a coordinate system with origin P and where:
    //! -   Vx is the "X Direction", and
    //! -   the "Y Direction" is orthogonal to Vx and
    //! oriented so that the cross products Vx^"Y
    //! Direction" and Vx^Vy have the same sign.
    //! Raises ConstructionError if Vx and Vy are parallel (same or opposite orientation).
    xgp_Ax22d::xgp_Ax22d(xgp_Pnt2d^ P, xgp_Dir2d^ Vx, xgp_Dir2d^ Vy) {
        NativeHandle = new gp_Ax22d(*P->GetPnt2d(), *Vx->GetDir2d(), *Vx->GetDir2d());
    };


    //! Creates -   a coordinate system with origin P and "X Direction"
    //! V, which is:
    //! -   right-handed if Sense is true (default value), or
    //! -   left-handed if Sense is false
    xgp_Ax22d::xgp_Ax22d(xgp_Pnt2d^ P, xgp_Dir2d^ V, Standard_Boolean Sense) {
        NativeHandle = new gp_Ax22d(*P->GetPnt2d(), *V->GetDir2d(), Sense);
    };


    //! Creates -   a coordinate system where its origin is the origin of
    //! A and its "X Direction" is the unit vector of A, which   is:
    //! -   right-handed if Sense is true (default value), or
    //! -   left-handed if Sense is false.
    xgp_Ax22d::xgp_Ax22d(xgp_Ax2d^ A, Standard_Boolean Sense) {
        NativeHandle = new gp_Ax22d(*A->GetAx2d(), Sense);
    };

    //! 释放
    xgp_Ax22d::~xgp_Ax22d() {
        if (NativeHandle != NULL)
            delete NativeHandle;
        NativeHandle = NULL;
    };

    //! 释放
    xgp_Ax22d::!xgp_Ax22d() {
        if (NativeHandle != NULL)
            delete NativeHandle;
        NativeHandle = NULL;
    };

    //!  gp_Ax22d
    gp_Ax22d* xgp_Ax22d::GetAx22d() {
      return NativeHandle;
    };

    //! Assigns the origin and the two unit vectors of the
    //! coordinate system A1 to this coordinate system.
    void xgp_Ax22d::SetAxis(xgp_Ax22d^ A1) {
        NativeHandle->SetAxis(*A1->GetAx22d());
    };


    //! Changes the XAxis and YAxis ("Location" point and "Direction")
    //! of <me>.
    //! The "YDirection" is recomputed in the same sense as before.
    void xgp_Ax22d::SetXAxis(xgp_Ax2d^ A1) {
        NativeHandle->SetXAxis(*A1->GetAx2d());
    };

    //! Changes the XAxis and YAxis ("Location" point and "Direction") of <me>.
    //! The "XDirection" is recomputed in the same sense as before.
    void xgp_Ax22d::SetYAxis(xgp_Ax2d^ A1) {
        NativeHandle->SetYAxis(*A1->GetAx2d());
    };


    //! Changes the "Location" point (origin) of <me>.
    void xgp_Ax22d::SetLocation(xgp_Pnt2d^ P) {
        NativeHandle->SetLocation(*P->GetPnt2d());
    };


    //! Assigns Vx to the "X Direction"  of
    //! this coordinate system. The other unit vector of this
    //! coordinate system is recomputed, normal to Vx ,
    //! without modifying the orientation (right-handed or
    //! left-handed) of this coordinate system.
    void xgp_Ax22d::SetXDirection(xgp_Dir2d^ Vx) {
        NativeHandle->SetXDirection(*Vx->GetDir2d());
    };

    //! Assignsr Vy to the  "Y Direction" of
    //! this coordinate system. The other unit vector of this
    //! coordinate system is recomputed, normal to Vy,
    //! without modifying the orientation (right-handed or
    //! left-handed) of this coordinate system.
    void xgp_Ax22d::SetYDirection(xgp_Dir2d^ Vy) {
        NativeHandle->SetYDirection(*Vy->GetDir2d());
    };

    //! Returns an axis, for which
    //! -   the origin is that of this coordinate system, and
    //! -   the unit vector is either the "X Direction"  of this coordinate system.
    //! Note: the result is the "X Axis" of this coordinate system.
    xgp_Ax2d^ xgp_Ax22d::XAxis() {
       gp_Ax2d* temp = new gp_Ax2d(NativeHandle->XAxis());
       return gcnew xgp_Ax2d(temp);
    };

    //! Returns an axis, for which
    //! -   the origin is that of this coordinate system, and
    //! - the unit vector is either the  "Y Direction" of this coordinate system.
    //! Note: the result is the "Y Axis" of this coordinate system.
    xgp_Ax2d^ xgp_Ax22d::YAxis() {
        gp_Ax2d* temp = new gp_Ax2d(NativeHandle->YAxis());
        return gcnew xgp_Ax2d(temp);
    };


    //! Returns the "Location" point (origin) of <me>.
    xgp_Pnt2d^ xgp_Ax22d::Location() {
        gp_Pnt2d* temp = new gp_Pnt2d(NativeHandle->Location());
        return gcnew xgp_Pnt2d(temp);
    };


    //! Returns the "XDirection" of <me>.
    xgp_Dir2d^ xgp_Ax22d::XDirection() {
        gp_Dir2d* temp = new gp_Dir2d(NativeHandle->XDirection());
        return gcnew xgp_Dir2d(temp);
    };


    //! Returns the "YDirection" of <me>.
    xgp_Dir2d^ xgp_Ax22d::YDirection() {
        gp_Dir2d* temp = new gp_Dir2d(NativeHandle->YDirection());
        return gcnew xgp_Dir2d(temp);
    };

    void xgp_Ax22d::Mirror(xgp_Pnt2d^ P) {
        NativeHandle->Mirror(*P->GetPnt2d());
    };


    //! Performs the symmetrical transformation of an axis
    //! placement with respect to the point P which is the
    //! center of the symmetry.
    //! Warnings :
    //! The main direction of the axis placement is not changed.
    //! The "XDirection" and the "YDirection" are reversed.
    //! So the axis placement stay right handed.
    xgp_Ax22d^ xgp_Ax22d::Mirrored(xgp_Pnt2d^ P) {
        gp_Ax22d* temp = new gp_Ax22d(NativeHandle->Mirrored(*P->GetPnt2d()));
        return gcnew xgp_Ax22d(temp);
    };

    void xgp_Ax22d::Mirror(xgp_Ax2d^ A) {
        NativeHandle->Mirrored(*A->GetAx2d());
    };


    //! Performs the symmetrical transformation of an axis
    //! placement with respect to an axis placement which
    //! is the axis of the symmetry.
    //! The transformation is performed on the "Location"
    //! point, on the "XDirection" and "YDirection".
    //! The resulting main "Direction" is the cross product between
    //! the "XDirection" and the "YDirection" after transformation.
    xgp_Ax22d^ xgp_Ax22d::Mirrored(xgp_Ax2d^ A) {
        gp_Ax22d* temp = new gp_Ax22d(NativeHandle->Mirrored(*A->GetAx2d()));
        return gcnew xgp_Ax22d(temp);
    };

    void xgp_Ax22d::Rotate(xgp_Pnt2d^ P, Standard_Real Ang) {
        NativeHandle->Rotate(*P->GetPnt2d(), Ang);
    };


    //! Rotates an axis placement. <A1> is the axis of the
    //! rotation . Ang is the angular value of the rotation
    //! in radians.
    xgp_Ax22d^ xgp_Ax22d::Rotated(xgp_Pnt2d^ P, Standard_Real Ang) {
        gp_Ax22d* temp = new gp_Ax22d(NativeHandle->Rotated(*P->GetPnt2d(), Ang));
        return gcnew xgp_Ax22d(temp);
    };

    void xgp_Ax22d::Scale(xgp_Pnt2d^ P, Standard_Real S) {
        NativeHandle->Scale(*P->GetPnt2d(), S);
    };


    //! Applies a scaling transformation on the axis placement.
    //! The "Location" point of the axisplacement is modified.
    //! Warnings :
    //! If the scale <S> is negative :
    //! . the main direction of the axis placement is not changed.
    //! . The "XDirection" and the "YDirection" are reversed.
    //! So the axis placement stay right handed.
    xgp_Ax22d^ xgp_Ax22d::Scaled(xgp_Pnt2d^ P, Standard_Real S) {
        gp_Ax22d* temp = new gp_Ax22d(NativeHandle->Scaled(*P->GetPnt2d(), S));
        return gcnew xgp_Ax22d(temp);
    };

    void xgp_Ax22d::Transform(xgp_Trsf2d^ T) {
        NativeHandle->Transform(*T->GetTrsf2d());
    };


    //! Transforms an axis placement with a Trsf.
    //! The "Location" point, the "XDirection" and the
    //! "YDirection" are transformed with T.  The resulting
    //! main "Direction" of <me> is the cross product between
    //! the "XDirection" and the "YDirection" after transformation.
    xgp_Ax22d^ xgp_Ax22d::Transformed(xgp_Trsf2d^ T) {
        gp_Ax22d* temp = new gp_Ax22d(NativeHandle->Transformed(*T->GetTrsf2d()));
        return gcnew xgp_Ax22d(temp);
    };

    void xgp_Ax22d::Translate(xgp_Vec2d^ V) {
        NativeHandle->Translate(*V->GetVec2d());
    };


    //! Translates an axis plaxement in the direction of the vector
    //! <V>. The magnitude of the translation is the vector's magnitude.
    xgp_Ax22d^ xgp_Ax22d::Translated(xgp_Vec2d^ V) {
        gp_Ax22d* temp = new gp_Ax22d(NativeHandle->Translated(*V->GetVec2d()));
        return gcnew xgp_Ax22d(temp);
    };

    void xgp_Ax22d::Translate(xgp_Pnt2d^ P1, xgp_Pnt2d^ P2) {
        NativeHandle->Translate(*P1->GetPnt2d(), *P2->GetPnt2d());
    };


    //! Translates an axis placement from the point <P1> to the
    //! point <P2>.
    xgp_Ax22d^ xgp_Ax22d::Translated(xgp_Pnt2d^ P1, xgp_Pnt2d^ P2) {
        gp_Ax22d* temp = new gp_Ax22d(NativeHandle->Translated(*P1->GetPnt2d(), *P2->GetPnt2d()));
        return gcnew xgp_Ax22d(temp);
    };
};
