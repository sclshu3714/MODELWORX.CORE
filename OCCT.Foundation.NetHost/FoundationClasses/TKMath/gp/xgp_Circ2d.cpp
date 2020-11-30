#include <xgp_Circ2d.h>

namespace TKMath
{
    //! creates an indefinite circle.
    xgp_Circ2d::xgp_Circ2d(void) {
        NativeHandle = new gp_Circ2d();
    };

    /// <summary>
    /// 指针映射点
    /// </summary>
    /// <param name="pos"></param>
    xgp_Circ2d::xgp_Circ2d(gp_Circ2d* pos) {
        NativeHandle = new gp_Circ2d(*pos);
    };
    /// <summary>
    ///  映射点
    /// </summary>
    /// <param name="pos"></param>
    xgp_Circ2d::xgp_Circ2d(gp_Circ2d pos) {
        NativeHandle = new gp_Circ2d(pos);
    };

    //! The location point of XAxis is the center of the circle.
    //! Warnings :
    //! It is not forbidden to create a circle with Radius = 0.0   Raises ConstructionError if Radius < 0.0.
    //! Raised if Radius < 0.0.
    xgp_Circ2d::xgp_Circ2d(xgp_Ax2d^ XAxis, Standard_Real Radius, Standard_Boolean Sense) {
        NativeHandle = new gp_Circ2d(XAxis->GetAx2d(), Radius, Sense);
    };


    //! Axis defines the Xaxis and Yaxis of the circle which defines
    //! the origin and the sense of parametrization.
    //! The location point of Axis is the center of the circle.
    //! Warnings :
    //! It is not forbidden to create a circle with Radius = 0.0 Raises ConstructionError if Radius < 0.0.
    //! Raised if Radius < 0.0.
    xgp_Circ2d::xgp_Circ2d(xgp_Ax22d^ Axis, Standard_Real Radius) {
        NativeHandle = new gp_Circ2d(Axis->GetAx22d(), Radius);
    };

    //释放
    xgp_Circ2d::~xgp_Circ2d() {
        if (NativeHandle == NULL)
            delete NativeHandle;
        NativeHandle = NULL;
    };
    //释放
    xgp_Circ2d::!xgp_Circ2d() {
        if (NativeHandle == NULL)
            delete NativeHandle;
        NativeHandle = NULL;
    };

    //! gp_Circ2d
    gp_Circ2d xgp_Circ2d::GetCirc2d() {
        return *NativeHandle;
    };

    //! Changes the location point (center) of the circle.
    void xgp_Circ2d::SetLocation(xgp_Pnt2d^ P) {
        NativeHandle->SetLocation(P->GetPnt2d());
    };

    //! Changes the X axis of the circle.
    void xgp_Circ2d::SetXAxis(xgp_Ax2d^ A) {
        NativeHandle->SetXAxis(A->GetAx2d());
    };

    //! Changes the X axis of the circle.
    void xgp_Circ2d::SetAxis(xgp_Ax22d^ A) {
        NativeHandle->SetAxis(A->GetAx22d());
    };

    //! Changes the Y axis of the circle.
    void xgp_Circ2d::SetYAxis(xgp_Ax2d^ A) {
        NativeHandle->SetYAxis(A->GetAx2d());
    };

    //! Modifies the radius of this circle.
    //! Thisnamespace TKMath  {  public ref class does not prevent the creation of a circle where
    //! Radius is null.
    //! Exceptions
    //! Standard_ConstructionError if Radius is negative.
    void xgp_Circ2d::SetRadius(Standard_Real Radius) {
        NativeHandle->SetRadius(Radius);
    };

    //! Computes the area of the circle.
    Standard_Real xgp_Circ2d::Area() {
        return  NativeHandle->Area();
    };


    //! Returns the normalized coefficients from the implicit equation
    //! of the circle :
    //! A * (X**2) + B * (Y**2) + 2*C*(X*Y) + 2*D*X + 2*E*Y + F = 0.0
    void xgp_Circ2d::Coefficients(Standard_Real A, Standard_Real B, Standard_Real C, Standard_Real D, Standard_Real E, Standard_Real F) {
        NativeHandle->Coefficients(A, B, C, D, E, F);
    };

    //! Does <me> contain P ?
    //! Returns True if the distance between P and any point on
    //! the circumference of the circle is lower of equal to
    //! <LinearTolerance>.
    Standard_Boolean xgp_Circ2d::Contains(xgp_Pnt2d^ P, Standard_Real LinearTolerance) {
        return NativeHandle->Contains(P->GetPnt2d(), LinearTolerance);
    };


    //! Computes the minimum of distance between the point P and any
    //! point on the circumference of the circle.
    Standard_Real xgp_Circ2d::Distance(xgp_Pnt2d^ P) {
        return NativeHandle->Distance(P->GetPnt2d());
    };


    //! Computes the square distance between <me> and the point P.
    Standard_Real xgp_Circ2d::SquareDistance(xgp_Pnt2d^ P) {
        return NativeHandle->SquareDistance(P->GetPnt2d());
    };

    //! computes the circumference of the circle.
    Standard_Real xgp_Circ2d::Length() {
        return NativeHandle->Length();
    };

    //! Returns the location point (center) of the circle.
    xgp_Pnt2d^ xgp_Circ2d::Location() {
        return gcnew xgp_Pnt2d(NativeHandle->Location());
    };

    //! Returns the radius value of the circle.
    Standard_Real xgp_Circ2d::Radius() {
        return NativeHandle->Radius();
    };

    //! returns the position of the circle.
    xgp_Ax22d^ xgp_Circ2d::Axis() {
        return gcnew xgp_Ax22d(NativeHandle->Axis());
    };

    //! returns the position of the circle. Idem Axis(me).
    xgp_Ax22d^ xgp_Circ2d::Position() {
        return gcnew xgp_Ax22d(NativeHandle->Position());
    };

    //! returns the X axis of the circle.
    xgp_Ax2d^ xgp_Circ2d::XAxis() {
        return gcnew xgp_Ax2d(NativeHandle->XAxis());
    };

    //! Returns the Y axis of the circle.
    //! Reverses the direction of the circle.
    xgp_Ax2d^ xgp_Circ2d::YAxis() {
        return gcnew xgp_Ax2d(NativeHandle->YAxis());
    };

    //! Reverses the orientation of the local coordinate system
    //! of this circle (the "Y Direction" is reversed) and therefore
    //! changes the implicit orientation of this circle.
    //! Reverse assigns the result to this circle,
    void xgp_Circ2d::Reverse() {
        NativeHandle->Reverse();
    };

    //! Reverses the orientation of the local coordinate system
    //! of this circle (the "Y Direction" is reversed) and therefore
    //! changes the implicit orientation of this circle.
    //! Reversed creates a new circle.
    xgp_Circ2d^ xgp_Circ2d::Reversed() {
        return gcnew xgp_Circ2d(NativeHandle->Reversed());
    };

    //! Returns true if the local coordinate system is direct
    //! and false in the other case.
    Standard_Boolean xgp_Circ2d::IsDirect() {
        return NativeHandle->IsDirect();
    };

    void xgp_Circ2d::Mirror(xgp_Pnt2d^ P) {
        NativeHandle->Mirror(P->GetPnt2d());
    };


    //! Performs the symmetrical transformation of a circle with respect
    //! to the point P which is the center of the symmetry
    xgp_Circ2d^ xgp_Circ2d::Mirrored(xgp_Pnt2d^ P) {
        return gcnew xgp_Circ2d(NativeHandle->Mirrored(P->GetPnt2d()));
    };

    void xgp_Circ2d::Mirror(xgp_Ax2d^ A) {
        NativeHandle->Mirror(A->GetAx2d());
    };


    //! Performs the symmetrical transformation of a circle with respect
    //! to an axis placement which is the axis of the symmetry.
    xgp_Circ2d^ xgp_Circ2d::Mirrored(xgp_Ax2d^ A) {
        return gcnew xgp_Circ2d(NativeHandle->Mirrored(A->GetAx2d()));
    };

    void xgp_Circ2d::Rotate(xgp_Pnt2d^ P, Standard_Real Ang) {
        NativeHandle->Rotate(P->GetPnt2d(), Ang);
    };


    //! Rotates a circle. P is the center of the rotation.
    //! Ang is the angular value of the rotation in radians.
    xgp_Circ2d^ xgp_Circ2d::Rotated(xgp_Pnt2d^ P, Standard_Real Ang) {
        return gcnew xgp_Circ2d(NativeHandle->Rotated(P->GetPnt2d(), Ang));
    };

    void xgp_Circ2d::Scale(xgp_Pnt2d^ P, Standard_Real S) {
        NativeHandle->Scale(P->GetPnt2d(), S);
    };


    //! Scales a circle. S is the scaling value.
    //! Warnings :
    //! If S is negative the radius stay positive but
    //! the "XAxis" and the "YAxis" are  reversed as for
    //! an ellipse.
    xgp_Circ2d^ xgp_Circ2d::Scaled(xgp_Pnt2d^ P, Standard_Real S) {
        return gcnew xgp_Circ2d(NativeHandle->Scaled(P->GetPnt2d(), S));
    };

    void xgp_Circ2d::Transform(xgp_Trsf2d^ T) {
        NativeHandle->Transform(T->GetTrsf2d());
    };


    //! Transforms a circle with the transformation T fromnamespace TKMath  {  public ref class Trsf2d.
    xgp_Circ2d^ xgp_Circ2d::Transformed(xgp_Trsf2d^ T) {
        return gcnew xgp_Circ2d(NativeHandle->Transformed(T->GetTrsf2d()));
    };

    void xgp_Circ2d::Translate(xgp_Vec2d^ V) {
        NativeHandle->Translate(V->GetVec2d());
    };


    //! Translates a circle in the direction of the vector V.
    //! The magnitude of the translation is the vector's magnitude.
    xgp_Circ2d^ xgp_Circ2d::Translated(xgp_Vec2d^ V) {
        return gcnew xgp_Circ2d(NativeHandle->Translated(V->GetVec2d()));
    };

    void xgp_Circ2d::Translate(xgp_Pnt2d^ P1, xgp_Pnt2d^ P2) {
        NativeHandle->Translate(P1->GetPnt2d(), P2->GetPnt2d());
    };


    //! Translates a circle from the point P1 to the point P2.
    xgp_Circ2d^ xgp_Circ2d::Translated(xgp_Pnt2d^ P1, xgp_Pnt2d^ P2) {
        return gcnew xgp_Circ2d(NativeHandle->Translated(P1->GetPnt2d(), P2->GetPnt2d()));
    };
};

