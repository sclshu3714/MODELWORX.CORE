#include <xgp_Cone.h>

namespace TKMath
{
    //! Creates an indefinite Cone.
    xgp_Cone::xgp_Cone(void) {
        NativeHandle = new gp_Cone();
    };

    /// <summary>
    /// 指针映射点
    /// </summary>
    /// <param name="pos"></param>
    xgp_Cone::xgp_Cone(gp_Cone* pos) {
        NativeHandle = new gp_Cone(*pos);
    };
    /// <summary>
    ///  映射点
    /// </summary>
    /// <param name="pos"></param>
    xgp_Cone::xgp_Cone(gp_Cone pos) {
        NativeHandle = new gp_Cone(pos);
    };

    //! Creates an infinite conical surface. A3 locates the cone
    //! in the space and defines the reference plane of the surface.
    //! Ang is the conical surface semi-angle. Its absolute value is in range
    //! ]0, PI/2[.
    //! Radius is the radius of the circle in the reference plane of
    //! the cone.
    //! Raises ConstructionError
    //! * if Radius is lower than 0.0
    //! * Abs(Ang) < Resolution from gp  or Abs(Ang) >= (PI/2) - Resolution.
    xgp_Cone::xgp_Cone(xgp_Ax3^ A3, Standard_Real Ang, Standard_Real Radius) {
        NativeHandle = new gp_Cone(*A3->GetAx3(), Ang, Radius);
    };


    //释放
    xgp_Cone::~xgp_Cone() {
        if (NativeHandle != NULL)
            delete NativeHandle;
        NativeHandle = NULL;
    };
    //释放
    xgp_Cone::!xgp_Cone() {
        if (NativeHandle != NULL)
            delete NativeHandle;
        NativeHandle = NULL;
    };

    //! gp_Cone
    gp_Cone xgp_Cone::GetCone() {
        return *NativeHandle;
    };

    //! Changes the symmetry axis of the cone.  Raises ConstructionError
    //! the direction of A1 is parallel to the "XDirection"
    //! of the coordinate system of the cone.
    void xgp_Cone::SetAxis(xgp_Ax1^ A1) {
        NativeHandle->SetAxis(*A1->GetAx1());
    };

    //! Changes the location of the cone.
    void xgp_Cone::SetLocation(xgp_Pnt^ Loc) {
        NativeHandle->SetLocation(Loc->GetPnt());
    };


    //! Changes the local coordinate system of the cone.
    //! This coordinate system defines the reference plane of the cone.
    void xgp_Cone::SetPosition(xgp_Ax3^ A3) {
        NativeHandle->SetPosition(*A3->GetAx3());
    };


    //! Changes the radius of the cone in the reference plane of
    //! the cone.
    //! Raised if R < 0.0
    void xgp_Cone::SetRadius(Standard_Real R) {
        NativeHandle->SetRadius(R);
    };


    //! Changes the semi-angle of the cone.
    //! Semi-angle can be negative. Its absolute value
    //! Abs(Ang) is in range ]0,PI/2[.
    //! Raises ConstructionError if Abs(Ang) < Resolution from gp or Abs(Ang) >= PI/2 - Resolution
    void xgp_Cone::SetSemiAngle(Standard_Real Ang) {
        NativeHandle->SetSemiAngle(Ang);
    };


    //! Computes the cone's top. The Apex of the cone is on the
    //! negative side of the symmetry axis of the cone.
    xgp_Pnt^ xgp_Cone::Apex() {
        return gcnew xgp_Pnt(NativeHandle->Apex());
    };

    //! Reverses the   U   parametrization of   the  cone
    //! reversing the YAxis.
    void xgp_Cone::UReverse() {
        NativeHandle->UReverse();
    };

    //! Reverses the   V   parametrization of   the  cone  reversing the ZAxis.
    void xgp_Cone::VReverse() {
        NativeHandle->VReverse();
    };

    //! Returns true if the local coordinate system of this cone is right-handed.
    Standard_Boolean xgp_Cone::Direct() {
        return NativeHandle->Direct();
    };

    //! returns the symmetry axis of the cone.
    xgp_Ax1^ xgp_Cone::Axis() {
        gp_Ax1* temp = new gp_Ax1(NativeHandle->Axis());
        return gcnew xgp_Ax1(temp);
    };


    //! Computes the coefficients of the implicit equation of the quadric
    //! in the absolute cartesian coordinates system :
    //! A1.X**2 + A2.Y**2 + A3.Z**2 + 2.(B1.X.Y + B2.X.Z + B3.Y.Z) +
    //! 2.(C1.X + C2.Y + C3.Z) + D = 0.0
    void xgp_Cone::Coefficients(Standard_Real A1, Standard_Real A2, Standard_Real A3, Standard_Real B1, Standard_Real B2, Standard_Real B3, Standard_Real C1, Standard_Real C2, Standard_Real C3, Standard_Real D) {
        NativeHandle->Coefficients(A1, A2, A3, B1, B2, B3, C1, C2, C3, D);
    };

    //! returns the "Location" point of the cone.
    xgp_Pnt^ xgp_Cone::Location() {
        return gcnew xgp_Pnt(NativeHandle->Location());
    };


    //! Returns the local coordinates system of the cone.
    xgp_Ax3^ xgp_Cone::Position() {
        gp_Ax3* temp = new gp_Ax3(NativeHandle->Position());
        return gcnew xgp_Ax3(temp);
    };


    //! Returns the radius of the cone in the reference plane.
    Standard_Real xgp_Cone::RefRadius() {
        return NativeHandle->RefRadius();
    };

    //! Returns the half-angle at the apex of this cone.
    //! Attention! Semi-angle can be negative.
    Standard_Real xgp_Cone::SemiAngle() {
        return NativeHandle->SemiAngle();
    };

    //! Returns the XAxis of the reference plane.
    xgp_Ax1^ xgp_Cone::XAxis() {
        gp_Ax1* temp = new gp_Ax1(NativeHandle->XAxis());
        return gcnew xgp_Ax1(temp);
    };

    //! Returns the YAxis of the reference plane.
    xgp_Ax1^ xgp_Cone::YAxis() {
        gp_Ax1* temp = new gp_Ax1(NativeHandle->YAxis());
        return gcnew xgp_Ax1(temp);
    };

    void xgp_Cone::Mirror(xgp_Pnt^ P) {
        NativeHandle->Mirror(P->GetPnt());
    };


    //! Performs the symmetrical transformation of a cone
    //! with respect to the point P which is the center of the
    //! symmetry.
    xgp_Cone^ xgp_Cone::Mirrored(xgp_Pnt^ P) {
        return gcnew xgp_Cone(NativeHandle->Mirrored(P->GetPnt()));
    };

    void xgp_Cone::Mirror(xgp_Ax1^ A1) {
        NativeHandle->Mirror(*A1->GetAx1());
    };


    //! Performs the symmetrical transformation of a cone with
    //! respect to an axis placement which is the axis of the
    //! symmetry.
    xgp_Cone^ xgp_Cone::Mirrored(xgp_Ax1^ A1) {
        return gcnew xgp_Cone(NativeHandle->Mirrored(*A1->GetAx1()));
    };

    void xgp_Cone::Mirror(xgp_Ax2^ A2) {
        NativeHandle->Mirror(*A2->GetAx2());
    };


    //! Performs the symmetrical transformation of a cone with respect
    //! to a plane. The axis placement A2 locates the plane of the
    //! of the symmetry : (Location, XDirection, YDirection).
    xgp_Cone^ xgp_Cone::Mirrored(xgp_Ax2^ A2) {
        return gcnew xgp_Cone(NativeHandle->Mirrored(*A2->GetAx2()));
    };

    void xgp_Cone::Rotate(xgp_Ax1^ A1, Standard_Real Ang) {
        NativeHandle->Rotate(*A1->GetAx1(), Ang);
    };


    //! Rotates a cone. A1 is the axis of the rotation.
    //! Ang is the angular value of the rotation in radians.
    xgp_Cone^ xgp_Cone::Rotated(xgp_Ax1^ A1, Standard_Real Ang) {
        return gcnew xgp_Cone(NativeHandle->Rotated(*A1->GetAx1(), Ang));
    };

    void xgp_Cone::Scale(xgp_Pnt^ P, Standard_Real S) {
        NativeHandle->Scale(P->GetPnt(), S);
    };


    //! Scales a cone. S is the scaling value.
    //! The absolute value of S is used to scale the cone
    xgp_Cone^ xgp_Cone::Scaled(xgp_Pnt^ P, Standard_Real S) {
        return gcnew xgp_Cone(NativeHandle->Scaled(P->GetPnt(), S));
    };

    void xgp_Cone::Transform(xgp_Trsf^ T) {
        NativeHandle->Transform(T->GetTrsf());
    };


    //! Transforms a cone with the transformation T fromnamespace TKMath  {  public ref class Trsf.
    xgp_Cone^ xgp_Cone::Transformed(xgp_Trsf^ T) {
        return gcnew xgp_Cone(NativeHandle->Transformed(T->GetTrsf()));
    };

    void xgp_Cone::Translate(xgp_Vec^ V) {
        NativeHandle->Translate(V->GetVec());
    };


    //! Translates a cone in the direction of the vector V.
    //! The magnitude of the translation is the vector's magnitude.
    xgp_Cone^ xgp_Cone::Translated(xgp_Vec^ V) {
        return gcnew xgp_Cone(NativeHandle->Translated(V->GetVec()));
    };

    void xgp_Cone::Translate(xgp_Pnt^ P1, xgp_Pnt^ P2) {
        NativeHandle->Translate(P1->GetPnt(), P2->GetPnt());
    };


    //! Translates a cone from the point P1 to the point P2.
    xgp_Cone^ xgp_Cone::Translated(xgp_Pnt^ P1, xgp_Pnt^ P2) {
        return gcnew xgp_Cone(NativeHandle->Translated(P1->GetPnt(), P2->GetPnt()));
    };
};

