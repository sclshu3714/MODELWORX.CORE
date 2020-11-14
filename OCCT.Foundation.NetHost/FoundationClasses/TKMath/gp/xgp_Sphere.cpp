#include <xgp_Sphere.h>

namespace TKMath
{
    //! Creates an indefinite sphere.
    xgp_Sphere::xgp_Sphere(void) {
        NativeHandle = new gp_Sphere();
    };

    /// <summary>
    /// 指针映射点
    /// </summary>
    /// <param name="pos"></param>
    xgp_Sphere::xgp_Sphere(gp_Sphere* pos) {
        NativeHandle = new gp_Sphere(*pos);
    };
    /// <summary>
    ///  映射点
    /// </summary>
    /// <param name="pos"></param>
    xgp_Sphere::xgp_Sphere(gp_Sphere pos) {
        NativeHandle = new gp_Sphere(pos);
    };

    //! Constructs a sphere with radius Radius, centered on the origin
    //! of A3.  A3 is the local coordinate system of the sphere.
    //! Warnings :
    //! It is not forbidden to create a sphere with null radius.
    //! Raises ConstructionError if Radius < 0.0
    xgp_Sphere::xgp_Sphere(xgp_Ax3^ A3, Standard_Real^ Radius) {
        NativeHandle = new gp_Sphere(A3->GetAx3(), *Radius);
    };

    //释放
    xgp_Sphere::~xgp_Sphere() {
        if (NativeHandle != NULL)
            delete NativeHandle;
        NativeHandle = NULL;
    };
    //释放
    xgp_Sphere::!xgp_Sphere() {
        if (NativeHandle != NULL)
            delete NativeHandle;
        NativeHandle = NULL;
    };


    //! gp_Sphere
    gp_Sphere xgp_Sphere::GetSphere() {
        return *NativeHandle;
    };

    //! Changes the center of the sphere.
    void xgp_Sphere::SetLocation(xgp_Pnt^ Loc) {
        NativeHandle->SetLocation(Loc->GetPnt());
    };

    //! Changes the local coordinate system of the sphere.
    void xgp_Sphere::SetPosition(xgp_Ax3^ A3) {
        NativeHandle->SetPosition(A3->GetAx3());
    };

    //! Assigns R the radius of the Sphere.
    //! Warnings :
    //! It is not forbidden to create a sphere with null radius.
    //! Raises ConstructionError if R < 0.0
    void xgp_Sphere::SetRadius(Standard_Real^ R) {
        NativeHandle->SetRadius(*R);
    };


    //! Computes the aera of the sphere.
    Standard_Real^ xgp_Sphere::Area() {
        return NativeHandle->Area();
    };


    //! Computes the coefficients of the implicit equation of the quadric
    //! in the absolute cartesian coordinates system :
    //! A1.X**2 + A2.Y**2 + A3.Z**2 + 2.(B1.X.Y + B2.X.Z + B3.Y.Z) +
    //! 2.(C1.X + C2.Y + C3.Z) + D = 0.0
    void xgp_Sphere::Coefficients(Standard_Real A1, Standard_Real A2, Standard_Real A3, Standard_Real B1, Standard_Real B2, Standard_Real B3, Standard_Real C1, Standard_Real C2, Standard_Real C3, Standard_Real D) {
        NativeHandle->Coefficients(A1, A2, A3, B1, B2, B3, C1, C2, C3, D);
    };

    //! Reverses the   U   parametrization of   the sphere
    //! reversing the YAxis.
    void xgp_Sphere::UReverse() {
        NativeHandle->UReverse();
    };

    //! Reverses the   V   parametrization of   the  sphere
    //! reversing the ZAxis.
    void xgp_Sphere::VReverse() {
        NativeHandle->VReverse();
    };

    //! Returns true if the local coordinate system of this sphere
    //! is right-handed.
    Standard_Boolean^ xgp_Sphere::Direct() {
        return NativeHandle->Direct();
    };

    //! --- Purpose ;
    //! Returns the center of the sphere.
    xgp_Pnt^ xgp_Sphere::Location() {
        return gcnew xgp_Pnt(NativeHandle->Location());
    };


    //! Returns the local coordinates system of the sphere.
    xgp_Ax3^ xgp_Sphere::Position() {
        return gcnew xgp_Ax3(NativeHandle->Position());
    };

    //! Returns the radius of the sphere.
    Standard_Real^ xgp_Sphere::Radius() {
        return  NativeHandle->Radius();
    };

    //! Computes the volume of the sphere
    Standard_Real^ xgp_Sphere::Volume() {
        return NativeHandle->Volume();
    };

    //! Returns the axis X of the sphere.
    xgp_Ax1^ xgp_Sphere::XAxis() {
        return gcnew xgp_Ax1(NativeHandle->XAxis());
    };

    //! Returns the axis Y of the sphere.
    xgp_Ax1^ xgp_Sphere::YAxis() {
        return gcnew xgp_Ax1(NativeHandle->YAxis());
    };

    void xgp_Sphere::Mirror(xgp_Pnt^ P) {
        NativeHandle->Mirror(P->GetPnt());
    };


    //! Performs the symmetrical transformation of a sphere
    //! with respect to the point P which is the center of the
    //! symmetry.
    xgp_Sphere^ xgp_Sphere::Mirrored(xgp_Pnt^ P) {
        return gcnew xgp_Sphere(NativeHandle->Mirrored(P->GetPnt()));
    };

    void xgp_Sphere::Mirror(xgp_Ax1^ A1) {
        NativeHandle->Mirror(A1->GetAx1());
    };


    //! Performs the symmetrical transformation of a sphere with
    //! respect to an axis placement which is the axis of the
    //! symmetry.
    xgp_Sphere^ xgp_Sphere::Mirrored(xgp_Ax1^ A1) {
        return gcnew xgp_Sphere(NativeHandle->Mirrored(A1->GetAx1()));
    };

    void xgp_Sphere::Mirror(xgp_Ax2^ A2) {
        NativeHandle->Mirror(A2->GetAx2());
    };


    //! Performs the symmetrical transformation of a sphere with respect
    //! to a plane. The axis placement A2 locates the plane of the
    //! of the symmetry : (Location, XDirection, YDirection).
    xgp_Sphere^ xgp_Sphere::Mirrored(xgp_Ax2^ A2) {
        return gcnew xgp_Sphere(NativeHandle->Mirrored(A2->GetAx2()));
    };

    void xgp_Sphere::Rotate(xgp_Ax1^ A1, Standard_Real^ Ang) {
        NativeHandle->Rotate(A1->GetAx1(), *Ang);
    };


    //! Rotates a sphere. A1 is the axis of the rotation.
    //! Ang is the angular value of the rotation in radians.
    xgp_Sphere^ xgp_Sphere::Rotated(xgp_Ax1^ A1, Standard_Real^ Ang) {
        return gcnew xgp_Sphere(NativeHandle->Rotated(A1->GetAx1(), *Ang));
    };

    void xgp_Sphere::Scale(xgp_Pnt^ P, Standard_Real^ S) {
        NativeHandle->Scale(P->GetPnt(), *S);
    };


    //! Scales a sphere. S is the scaling value.
    //! The absolute value of S is used to scale the sphere
    xgp_Sphere^ xgp_Sphere::Scaled(xgp_Pnt^ P, Standard_Real^ S) {
        return gcnew xgp_Sphere(NativeHandle->Scaled(P->GetPnt(), *S));
    };

    void xgp_Sphere::Transform(xgp_Trsf^ T) {
        NativeHandle->Transform(T->GetTrsf());
    };


    //! Transforms a sphere with the transformation T fromnamespace TKMath  {  public ref class Trsf.
    xgp_Sphere^ xgp_Sphere::Transformed(xgp_Trsf^ T) {
        return gcnew xgp_Sphere(NativeHandle->Transformed(T->GetTrsf()));
    };

    void xgp_Sphere::Translate(xgp_Vec^ V) {
        NativeHandle->Translate(V->GetVec());
    };


    //! Translates a sphere in the direction of the vector V.
    //! The magnitude of the translation is the vector's magnitude.
    xgp_Sphere^ xgp_Sphere::Translated(xgp_Vec^ V) {
        return gcnew xgp_Sphere(NativeHandle->Translated(V->GetVec()));
    };

    void xgp_Sphere::Translate(xgp_Pnt^ P1, xgp_Pnt^ P2) {
       NativeHandle->Translate(P1->GetPnt(), P2->GetPnt());
    };


    //! Translates a sphere from the point P1 to the point P2.
    xgp_Sphere^ xgp_Sphere::Translated(xgp_Pnt^ P1, xgp_Pnt^ P2) {
        return gcnew xgp_Sphere(NativeHandle->Translated(P1->GetPnt(), P2->GetPnt()));
    };
};
