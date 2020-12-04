#include <xgp_Circ.h>

namespace TKMath
{
    //! Creates an indefinite circle.
    xgp_Circ::xgp_Circ(void) {
        NativeHandle = new gp_Circ();
    };

    /// <summary>
    /// 指针映射点
    /// </summary>
    /// <param name="pos"></param>
    xgp_Circ::xgp_Circ(gp_Circ* pos) {
        NativeHandle = new gp_Circ(*pos);
    };
    /// <summary>
    ///  映射点
    /// </summary>
    /// <param name="pos"></param>
    xgp_Circ::xgp_Circ(gp_Circ pos) {
        NativeHandle = new gp_Circ(pos);
    };

    //! A2 locates the circle and gives its orientation in 3D space.
    //! Warnings :
    //! It is not forbidden to create a circle with Radius = 0.0  Raises ConstructionError if Radius < 0.0
    xgp_Circ::xgp_Circ(xgp_Ax2^ A2, Standard_Real Radius) {
        NativeHandle = new gp_Circ(A2->GetAx2(), Radius);
    };

    //! 释放
    xgp_Circ::~xgp_Circ() {
        if (NativeHandle == NULL)
            delete NativeHandle;
        NativeHandle = NULL;
    };

    //! 释放
    xgp_Circ::!xgp_Circ() {
        if (NativeHandle == NULL)
            delete NativeHandle;
        NativeHandle = NULL;
    };

    //! gp_Circ
    gp_Circ xgp_Circ::GetCirc() {
        return *NativeHandle;
    };

    //! Changes the main axis of the circle. It is the axis
    //! perpendicular to the plane of the circle.
    //! Raises ConstructionError if the direction of A1
    //! is parallel to the "XAxis" of the circle.
    void xgp_Circ::SetAxis(xgp_Ax1^ A1) {
        NativeHandle->SetAxis(*A1->GetAx1());
    };


    //! Changes the "Location" point (center) of the circle.
    void xgp_Circ::SetLocation(xgp_Pnt^ P) {
        NativeHandle->SetLocation(P->GetPnt());
    };

    //! Changes the position of the circle.
    void xgp_Circ::SetPosition(xgp_Ax2^ A2) {
        NativeHandle->SetPosition(A2->GetAx2());
    };

    //! Modifies the radius of this circle.
    //! Warning. Thisnamespace TKMath  {  public ref class does not prevent the creation of a circle where Radius is null.
    //! Exceptions
    //! Standard_ConstructionError if Radius is negative.
    void xgp_Circ::SetRadius(Standard_Real Radius) {
        NativeHandle->SetRadius(Radius);
    };

    //! Computes the area of the circle.
    Standard_Real xgp_Circ::Area() {
        return  NativeHandle->Area();
    };


    //! Returns the main axis of the circle.
    //! It is the axis perpendicular to the plane of the circle,
    //! passing through the "Location" point (center) of the circle.
    xgp_Ax1^ xgp_Circ::Axis() {
        gp_Ax1* temp = new gp_Ax1(NativeHandle->Axis());
        return gcnew xgp_Ax1(temp);
    };

    //! Computes the circumference of the circle.
    Standard_Real xgp_Circ::Length() {
        return NativeHandle->Length();
    };


    //! Returns the center of the circle. It is the
    //! "Location" point of the local coordinate system
    //! of the circle
    xgp_Pnt^ xgp_Circ::Location() {
        return gcnew xgp_Pnt(NativeHandle->Location());
    };


    //! Returns the position of the circle.
    //! It is the local coordinate system of the circle.
    xgp_Ax2^ xgp_Circ::Position() {
        return gcnew xgp_Ax2(NativeHandle->Position());
    };

    //! Returns the radius of this circle.
    Standard_Real xgp_Circ::Radius() {
        return NativeHandle->Radius();
    };


    //! Returns the "XAxis" of the circle.
    //! This axis is perpendicular to the axis of the conic.
    //! This axis and the "Yaxis" define the plane of the conic.
    xgp_Ax1^ xgp_Circ::XAxis() {
        gp_Ax1* temp = new gp_Ax1(NativeHandle->XAxis());
        return gcnew xgp_Ax1(temp);
    };


    //! Returns the "YAxis" of the circle.
    //! This axis and the "Xaxis" define the plane of the conic.
    //! The "YAxis" is perpendicular to the "Xaxis".
    xgp_Ax1^ xgp_Circ::YAxis() {
        gp_Ax1* temp = new gp_Ax1(NativeHandle->YAxis());
        return gcnew xgp_Ax1(temp);
    };


    //! Computes the minimum of distance between the point P and
    //! any point on the circumference of the circle.
    Standard_Real xgp_Circ::Distance(xgp_Pnt^ P) {
        return NativeHandle->Distance(P->GetPnt());
    };


    //! Computes the square distance between <me> and the point P.
    Standard_Real xgp_Circ::SquareDistance(xgp_Pnt^ P) {
        return NativeHandle->SquareDistance(P->GetPnt());
    };


    //! Returns True if the point P is on the circumference.
    //! The distance between <me> and <P> must be lower or
    //! equal to LinearTolerance.
    Standard_Boolean xgp_Circ::Contains(xgp_Pnt^ P, Standard_Real LinearTolerance) {
        return NativeHandle->Contains(P->GetPnt(), LinearTolerance);
    };

    void xgp_Circ::Mirror(xgp_Pnt^ P) {
        NativeHandle->Mirror(P->GetPnt());
    };


    //! Performs the symmetrical transformation of a circle
    //! with respect to the point P which is the center of the
    //! symmetry.
    xgp_Circ^ xgp_Circ::Mirrored(xgp_Pnt^ P) {
        return gcnew xgp_Circ(NativeHandle->Mirrored(P->GetPnt()));
    };

    void xgp_Circ::Mirror(xgp_Ax1^ A1) {
        NativeHandle->Mirror(*A1->GetAx1());
    };


    //! Performs the symmetrical transformation of a circle with
    //! respect to an axis placement which is the axis of the
    //! symmetry.
    xgp_Circ^ xgp_Circ::Mirrored(xgp_Ax1^ A1) {
        return gcnew xgp_Circ(NativeHandle->Mirrored(*A1->GetAx1()));
    };

    void xgp_Circ::Mirror(xgp_Ax2^ A2) {
        NativeHandle->Mirror(A2->GetAx2());
    };


    //! Performs the symmetrical transformation of a circle with respect
    //! to a plane. The axis placement A2 locates the plane of the
    //! of the symmetry : (Location, XDirection, YDirection).
    xgp_Circ^ xgp_Circ::Mirrored(xgp_Ax2^ A2) {
        return gcnew xgp_Circ(NativeHandle->Mirrored(A2->GetAx2()));
    };

    void xgp_Circ::Rotate(xgp_Ax1^ A1, Standard_Real Ang) {
        NativeHandle->Rotate(*A1->GetAx1(), Ang);
    };


    //! Rotates a circle. A1 is the axis of the rotation.
    //! Ang is the angular value of the rotation in radians.
    xgp_Circ^ xgp_Circ::Rotated(xgp_Ax1^ A1, Standard_Real Ang) {
        return gcnew xgp_Circ(NativeHandle->Rotated(*A1->GetAx1(), Ang));
    };

    void xgp_Circ::Scale(xgp_Pnt^ P, Standard_Real S) {
        NativeHandle->Scale(P->GetPnt(), S);
    };


    //! Scales a circle. S is the scaling value.
    //! Warnings :
    //! If S is negative the radius stay positive but
    //! the "XAxis" and the "YAxis" are  reversed as for
    //! an ellipse.
    xgp_Circ^ xgp_Circ::Scaled(xgp_Pnt^ P, Standard_Real S) {
        return gcnew xgp_Circ(NativeHandle->Scaled(P->GetPnt(), S));
    };

    void xgp_Circ::Transform(xgp_Trsf^ T) {
        NativeHandle->Transform(T->GetTrsf());
    };


    //! Transforms a circle with the transformation T fromnamespace TKMath  {  public ref class Trsf.
    xgp_Circ^ xgp_Circ::Transformed(xgp_Trsf^ T) {
        return gcnew xgp_Circ(NativeHandle->Transformed(T->GetTrsf()));
    };

    void xgp_Circ::Translate(xgp_Vec^ V) {
        NativeHandle->Translate(V->GetVec());
    };


    //! Translates a circle in the direction of the vector V.
    //! The magnitude of the translation is the vector's magnitude.
    xgp_Circ^ xgp_Circ::Translated(xgp_Vec^ V) {
        return gcnew xgp_Circ(NativeHandle->Translated(V->GetVec()));
    };

    void xgp_Circ::Translate(xgp_Pnt^ P1, xgp_Pnt^ P2) {
        NativeHandle->Translate(P1->GetPnt(), P2->GetPnt());
    };


    //! Translates a circle from the point P1 to the point P2.
    xgp_Circ^ xgp_Circ::Translated(xgp_Pnt^ P1, xgp_Pnt^ P2) {
        return gcnew xgp_Circ(NativeHandle->Translated(P1->GetPnt(), P2->GetPnt()));
    };
};
