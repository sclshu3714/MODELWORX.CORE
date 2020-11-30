#include <xgp_Ax2d.h>

namespace TKMath
{
    //! Creates an axis object representing X axis of
      //! the reference co-ordinate system.
    xgp_Ax2d::xgp_Ax2d(void) {
        NativeHandle = new gp_Ax2d();
    };

    /// <summary>
    /// 指针映射点
    /// </summary>
    /// <param name="pos"></param>
    xgp_Ax2d::xgp_Ax2d(gp_Ax2d* pos) {
        NativeHandle = new gp_Ax2d(*pos);
    };
    /// <summary>
    ///  映射点
    /// </summary>
    /// <param name="pos"></param>
    xgp_Ax2d::xgp_Ax2d(gp_Ax2d pos) {
        NativeHandle = new gp_Ax2d(pos);
    };

    //! Creates an Ax2d. <P> is the "Location" point of
    //! the axis placement and V is the "Direction" of
    //! the axis placement.
    xgp_Ax2d::xgp_Ax2d(xgp_Pnt2d^ P, xgp_Dir2d^ V) {
        NativeHandle = new gp_Ax2d(P->GetPnt2d(), V->GetDir2d());
    };

    //释放
    xgp_Ax2d::~xgp_Ax2d() {
        if (NativeHandle != NULL) {
            delete NativeHandle;
            NativeHandle = NULL;
        }
    };
    //释放
    xgp_Ax2d::!xgp_Ax2d() {
        if (NativeHandle != NULL) {
            delete NativeHandle;
            NativeHandle = NULL;
        }
    };

    //! Changes the "Location" point (origin) of <me>.
    void xgp_Ax2d::SetLocation(xgp_Pnt2d^ Locat) {
        NativeHandle->SetLocation(Locat->GetPnt2d());
    };

    //! Changes the direction of <me>.
    void xgp_Ax2d::SetDirection(xgp_Dir2d^ V) {
        NativeHandle->SetDirection(V->GetDir2d());
    };

    //Returns the gp_Ax2d
    gp_Ax2d xgp_Ax2d::GetAx2d() {
        return *NativeHandle;
    };

    //! Returns the origin of <me>.
    xgp_Pnt2d^ xgp_Ax2d::Location() {
        return gcnew xgp_Pnt2d(NativeHandle->Location());
    };

    //! Returns the direction of <me>.
    xgp_Dir2d^ xgp_Ax2d::Direction() {
        return gcnew xgp_Dir2d(NativeHandle->Direction());
    };


    //! Returns True if  :
    //! . the angle between <me> and <Other> is lower or equal
    //! to <AngularTolerance> and
    //! . the distance between <me>.Location() and <Other> is lower
    //! or equal to <LinearTolerance> and
    //! . the distance between <Other>.Location() and <me> is lower
    //! or equal to LinearTolerance.
    Standard_Boolean xgp_Ax2d::IsCoaxial(xgp_Ax2d^ Other, Standard_Real AngularTolerance, Standard_Real LinearTolerance) {
        return NativeHandle->IsCoaxial(Other->GetAx2d(), AngularTolerance, LinearTolerance);
    };

    //! Returns true if this axis and the axis Other are normal to
    //! each other. That is, if the angle between the two axes is equal to Pi/2 or -Pi/2.
    //! Note: the tolerance criterion is given by AngularTolerance.
    Standard_Boolean xgp_Ax2d::IsNormal(xgp_Ax2d^ Other, Standard_Real AngularTolerance) {
        return NativeHandle->IsNormal(Other->GetAx2d(), AngularTolerance);
    };

    //! Returns true if this axis and the axis Other are parallel,
    //! and have opposite orientations. That is, if the angle
    //! between the two axes is equal to Pi or -Pi.
    //! Note: the tolerance criterion is given by AngularTolerance.
    Standard_Boolean xgp_Ax2d::IsOpposite(xgp_Ax2d^ Other, Standard_Real AngularTolerance) {
        return NativeHandle->IsOpposite(Other->GetAx2d(), AngularTolerance);
    };

    //! Returns true if this axis and the axis Other are parallel,
    //! and have either the same or opposite orientations. That
    //! is, if the angle between the two axes is equal to 0, Pi or -Pi.
    //! Note: the tolerance criterion is given by AngularTolerance.
    Standard_Boolean xgp_Ax2d::IsParallel(xgp_Ax2d^ Other, Standard_Real AngularTolerance) {
        return NativeHandle->IsParallel(Other->GetAx2d(), AngularTolerance);
    };


    //! Computes the angle, in radians, between this axis and
    //! the axis Other. The value of the angle is between -Pi and Pi.
    Standard_Real xgp_Ax2d::Angle(xgp_Ax2d^ Other) {
        return NativeHandle->Angle(Other->GetAx2d());
    };

    //! Reverses the direction of <me> and assigns the result to this axis.
    void xgp_Ax2d::Reverse() {
        NativeHandle->Reverse();
    };


    //! Computes a new axis placement with a direction opposite to
    //! the direction of <me>.
    xgp_Ax2d^ xgp_Ax2d::Reversed() {
        return gcnew xgp_Ax2d(NativeHandle->Reversed());
    };

    void xgp_Ax2d::Mirror(xgp_Pnt2d^ P) {
        NativeHandle->Mirror(P->GetPnt2d());
    };


    //! Performs the symmetrical transformation of an axis
    //! placement with respect to the point P which is the
    //! center of the symmetry.
    xgp_Ax2d^ xgp_Ax2d::Mirrored(xgp_Pnt2d^ P) {
        return gcnew xgp_Ax2d(NativeHandle->Mirrored(P->GetPnt2d()));
    };

    void xgp_Ax2d::Mirror(xgp_Ax2d^ A) {
        NativeHandle->Mirror(A->GetAx2d());
    };


    //! Performs the symmetrical transformation of an axis
    //! placement with respect to an axis placement which
    //! is the axis of the symmetry.
    xgp_Ax2d^ xgp_Ax2d::Mirrored(xgp_Ax2d^ A) {
        return gcnew xgp_Ax2d(NativeHandle->Mirrored(A->GetAx2d()));
    };

    void xgp_Ax2d::Rotate(xgp_Pnt2d^ P, Standard_Real Ang) {
        NativeHandle->Rotate(P->GetPnt2d(), Ang);
    };


    //! Rotates an axis placement. <P> is the center of the
    //! rotation . Ang is the angular value of the rotation
    //! in radians.
    xgp_Ax2d^ xgp_Ax2d::Rotated(xgp_Pnt2d^ P, Standard_Real Ang) {
        return gcnew xgp_Ax2d(NativeHandle->Rotated(P->GetPnt2d(), Ang));
    };

    void xgp_Ax2d::Scale(xgp_Pnt2d^ P, Standard_Real S) {
        NativeHandle->Scale(P->GetPnt2d(), S);
    };


    //! Applies a scaling transformation on the axis placement.
    //! The "Location" point of the axisplacement is modified.
    //! The "Direction" is reversed if the scale is negative.
    xgp_Ax2d^ xgp_Ax2d::Scaled(xgp_Pnt2d^ P, Standard_Real S) {
        return gcnew xgp_Ax2d(NativeHandle->Scaled(P->GetPnt2d(), S));
    };

    void xgp_Ax2d::Transform(xgp_Trsf2d^ T) {
        NativeHandle->Transform(T->GetTrsf2d());
    };

    //! Transforms an axis placement with a Trsf.
    xgp_Ax2d^ xgp_Ax2d::Transformed(xgp_Trsf2d^ T) {
        return gcnew xgp_Ax2d(NativeHandle->Transformed(T->GetTrsf2d()));
    };

    void xgp_Ax2d::Translate(xgp_Vec2d^ V) {
        NativeHandle->Translate(V->GetVec2d());
    };


    //! Translates an axis placement in the direction of the vector
    //! <V>. The magnitude of the translation is the vector's magnitude.
    xgp_Ax2d^ xgp_Ax2d::Translated(xgp_Vec2d^ V) {
        return gcnew xgp_Ax2d(NativeHandle->Translated(V->GetVec2d()));
    };

    void xgp_Ax2d::Translate(xgp_Pnt2d^ P1, xgp_Pnt2d^ P2) {
        NativeHandle->Translate(P1->GetPnt2d(), P2->GetPnt2d());
    };


    //! Translates an axis placement from the point <P1> to the
    //! point <P2>.
    xgp_Ax2d^ xgp_Ax2d::Translated(xgp_Pnt2d^ P1, xgp_Pnt2d^ P2) {
        return gcnew xgp_Ax2d(NativeHandle->Translated(P1->GetPnt2d(), P2->GetPnt2d()));
    };
};

