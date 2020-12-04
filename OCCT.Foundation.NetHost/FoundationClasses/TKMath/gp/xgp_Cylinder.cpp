#include <xgp_Cylinder.h>

namespace TKMath
{
    //! Creates a indefinite cylinder.
    xgp_Cylinder::xgp_Cylinder(void) {
        NativeHandle = new gp_Cylinder();
    };

    /// <summary>
    /// 指针映射点
    /// </summary>
    /// <param name="pos"></param>
    xgp_Cylinder::xgp_Cylinder(gp_Cylinder* pos) {
        NativeHandle = new gp_Cylinder(*pos);
    };


    //! Creates a cylinder of radius Radius, whose axis is the "main
    //! Axis" of A3. A3 is the local coordinate system of the cylinder.   Raises ConstructionErrord if R < 0.0
    xgp_Cylinder::xgp_Cylinder(xgp_Ax3^ A3, Standard_Real Radius) {
        NativeHandle = new gp_Cylinder(*A3->GetAx3(), Radius);
    };

    //释放
    xgp_Cylinder::~xgp_Cylinder() {
        if (NativeHandle != NULL)
            delete NativeHandle;
        NativeHandle = NULL;
    };
    //释放
    xgp_Cylinder::!xgp_Cylinder() {
        if (NativeHandle != NULL)
            delete NativeHandle;
        NativeHandle = NULL;
    };


    //! gp_Cylinder
    gp_Cylinder* xgp_Cylinder::GetCylinder() {
        return NativeHandle;
    };

    //! Changes the symmetry axis of the cylinder. Raises ConstructionError if the direction of A1 is parallel to the "XDirection"
    //! of the coordinate system of the cylinder.
    void xgp_Cylinder::SetAxis(xgp_Ax1^ A1) {
        NativeHandle->SetAxis(*A1->GetAx1());
    };

    //! Changes the location of the surface.
    void xgp_Cylinder::SetLocation(xgp_Pnt^ Loc) {
        NativeHandle->SetLocation(*Loc->GetPnt());
    };

    //! Change the local coordinate system of the surface.
    void xgp_Cylinder::SetPosition(xgp_Ax3^ A3) {
        NativeHandle->SetPosition(*A3->GetAx3());
    };

    //! Modifies the radius of this cylinder.
    //! Exceptions
    //! Standard_ConstructionError if R is negative.
    void xgp_Cylinder::SetRadius(Standard_Real R) {
        NativeHandle->SetRadius(R);
    };

    //! Reverses the   U   parametrization of   the cylinder
    //! reversing the YAxis.
    void xgp_Cylinder::UReverse() {
        NativeHandle->UReverse();
    };

    //! Reverses the   V   parametrization of   the  plane
    //! reversing the Axis.
    void xgp_Cylinder::VReverse() {
        NativeHandle->VReverse();
    };

    //! Returns true if the local coordinate system of this cylinder is right-handed.
    Standard_Boolean xgp_Cylinder::Direct() {
        return NativeHandle->Direct();
    };

    //! Returns the symmetry axis of the cylinder.
    xgp_Ax1^ xgp_Cylinder::Axis() {
        gp_Ax1* temp = new gp_Ax1(NativeHandle->Axis());
        return gcnew xgp_Ax1(temp);
    };


    //! Computes the coefficients of the implicit equation of the quadric
    //! in the absolute cartesian coordinate system :
    //! A1.X**2 + A2.Y**2 + A3.Z**2 + 2.(B1.X.Y + B2.X.Z + B3.Y.Z) +
    //! 2.(C1.X + C2.Y + C3.Z) + D = 0.0
    void xgp_Cylinder::Coefficients(Standard_Real A1, Standard_Real A2, Standard_Real A3, Standard_Real B1, Standard_Real B2, Standard_Real B3, Standard_Real C1, Standard_Real C2, Standard_Real C3, Standard_Real D) {
        NativeHandle->Coefficients(A1, A2, A3, B1, B2, B3, C1, C2, C3, D);
    };

    //! Returns the "Location" point of the cylinder.
    xgp_Pnt^ xgp_Cylinder::Location() {
        gp_Pnt* temp = new gp_Pnt(NativeHandle->Location());
        return gcnew xgp_Pnt(temp);
    };


    //! Returns the local coordinate system of the cylinder.
    xgp_Ax3^ xgp_Cylinder::Position() {
        gp_Ax3* temp = new gp_Ax3(NativeHandle->Position());
        return gcnew xgp_Ax3(temp);
    };

    //! Returns the radius of the cylinder.
    Standard_Real xgp_Cylinder::Radius() {
        return NativeHandle->Radius();
    };

    //! Returns the axis X of the cylinder.
    xgp_Ax1^ xgp_Cylinder::XAxis() {
        gp_Ax1* temp = new gp_Ax1(NativeHandle->XAxis());
        return gcnew xgp_Ax1(temp);
    };

    //! Returns the axis Y of the cylinder.
    xgp_Ax1^ xgp_Cylinder::YAxis() {
        gp_Ax1* temp = new gp_Ax1(NativeHandle->YAxis());
        return gcnew xgp_Ax1(temp);
    };

    void xgp_Cylinder::Mirror(xgp_Pnt^ P) {
        NativeHandle->Mirror(*P->GetPnt());
    };


    //! Performs the symmetrical transformation of a cylinder
    //! with respect to the point P which is the center of the
    //! symmetry.
    xgp_Cylinder^ xgp_Cylinder::Mirrored(xgp_Pnt^ P) {
        gp_Cylinder* temp = new gp_Cylinder(NativeHandle->Mirrored(*P->GetPnt()));
        return gcnew xgp_Cylinder(temp);
    };

    void xgp_Cylinder::Mirror(xgp_Ax1^ A1) {
        NativeHandle->Mirror(*A1->GetAx1());
    };


    //! Performs the symmetrical transformation of a cylinder with
    //! respect to an axis placement which is the axis of the
    //! symmetry.
    xgp_Cylinder^ xgp_Cylinder::Mirrored(xgp_Ax1^ A1) {
        gp_Cylinder* temp = new gp_Cylinder(NativeHandle->Mirrored(*A1->GetAx1()));
        return gcnew xgp_Cylinder(temp);
    };

    void xgp_Cylinder::Mirror(xgp_Ax2^ A2) {
        NativeHandle->Mirror(*A2->GetAx2());
    };


    //! Performs the symmetrical transformation of a cylinder with respect
    //! to a plane. The axis placement A2 locates the plane of the
    //! of the symmetry : (Location, XDirection, YDirection).
    xgp_Cylinder^ xgp_Cylinder::Mirrored(xgp_Ax2^ A2) {
        gp_Cylinder* temp = new gp_Cylinder(NativeHandle->Mirrored(*A2->GetAx2()));
        return gcnew xgp_Cylinder(temp);
    };

    void xgp_Cylinder::Rotate(xgp_Ax1^ A1, Standard_Real Ang) {
        NativeHandle->Rotate(*A1->GetAx1(), Ang);
    };


    //! Rotates a cylinder. A1 is the axis of the rotation.
    //! Ang is the angular value of the rotation in radians.
    xgp_Cylinder^ xgp_Cylinder::Rotated(xgp_Ax1^ A1, Standard_Real Ang) {
        gp_Cylinder* temp = new gp_Cylinder(NativeHandle->Rotated(*A1->GetAx1(), Ang));
        return gcnew xgp_Cylinder(temp);
    };

    void xgp_Cylinder::Scale(xgp_Pnt^ P, Standard_Real S) {
        NativeHandle->Scale(*P->GetPnt(), S);
    };


    //! Scales a cylinder. S is the scaling value.
    //! The absolute value of S is used to scale the cylinder
    xgp_Cylinder^ xgp_Cylinder::Scaled(xgp_Pnt^ P, Standard_Real S) {
        gp_Cylinder* temp = new gp_Cylinder(NativeHandle->Scaled(*P->GetPnt(), S));
        return gcnew xgp_Cylinder(temp);
    };

    void xgp_Cylinder::Transform(xgp_Trsf^ T) {
        NativeHandle->Transform(*T->GetTrsf());
    };


    //! Transforms a cylinder with the transformation T fromnamespace TKMath  {  public ref class Trsf.
    xgp_Cylinder^ xgp_Cylinder::Transformed(xgp_Trsf^ T) {
        gp_Cylinder* temp = new gp_Cylinder(NativeHandle->Transformed(*T->GetTrsf()));
        return gcnew xgp_Cylinder(temp);
    };

    void xgp_Cylinder::Translate(xgp_Vec^ V) {
        NativeHandle->Translate(*V->GetVec());
    };


    //! Translates a cylinder in the direction of the vector V.
    //! The magnitude of the translation is the vector's magnitude.
    xgp_Cylinder^ xgp_Cylinder::Translated(xgp_Vec^ V) {
        gp_Cylinder* temp = new gp_Cylinder(NativeHandle->Translated(*V->GetVec()));
        return gcnew xgp_Cylinder(temp);
    };

    void xgp_Cylinder::Translate(xgp_Pnt^ P1, xgp_Pnt^ P2) {
        NativeHandle->Translate(*P1->GetPnt(), *P2->GetPnt());
    };


    //! Translates a cylinder from the point P1 to the point P2.
    xgp_Cylinder^ xgp_Cylinder::Translated(xgp_Pnt^ P1, xgp_Pnt^ P2) {
        gp_Cylinder* temp = new gp_Cylinder(NativeHandle->Translated(*P1->GetPnt(), *P2->GetPnt()));
        return gcnew xgp_Cylinder(temp);
    };
};

