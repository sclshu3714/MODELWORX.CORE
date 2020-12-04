#include <xgp_Lin2d.h>

namespace TKMath
{
    //! Creates a Line corresponding to X axis of the
        //! reference coordinate system.
    xgp_Lin2d::xgp_Lin2d() {
        NativeHandle = new gp_Lin2d();
    };

    /// <summary>
    /// 指针映射点
    /// </summary>
    /// <param name="pos"></param>
    xgp_Lin2d::xgp_Lin2d(gp_Lin2d* pos) {
        NativeHandle = new gp_Lin2d(*pos);
    };
    /// <summary>
    ///  映射点
    /// </summary>
    /// <param name="pos"></param>
    xgp_Lin2d::xgp_Lin2d(gp_Lin2d pos) {
        NativeHandle = new gp_Lin2d(pos);
    };

    //! Creates a line located with A.
    xgp_Lin2d::xgp_Lin2d(xgp_Ax2d^ A) {
        NativeHandle = new gp_Lin2d(*A->GetAx2d());
    };


    //! <P> is the location point (origin) of the line and
    //! <V> is the direction of the line.
    xgp_Lin2d::xgp_Lin2d(xgp_Pnt2d^ P, xgp_Dir2d^ V) {
        NativeHandle = new gp_Lin2d(P->GetPnt2d(), *V->GetDir2d());
    };


    //! Creates the line from the equation A*X + B*Y + C = 0.0 Raises ConstructionError if Sqrt(A*A + B*B) <= Resolution from gp.
    //! Raised if Sqrt(A*A + B*B) <= Resolution from gp.
    xgp_Lin2d::xgp_Lin2d(Standard_Real A, Standard_Real B, Standard_Real C) {
        NativeHandle = new gp_Lin2d(A, B, C);
    };


    //释放
    xgp_Lin2d::~xgp_Lin2d() {
        if (NativeHandle != NULL)
            delete NativeHandle;
        NativeHandle = NULL;
    };
    //释放
    xgp_Lin2d::!xgp_Lin2d() {
        if (NativeHandle != NULL)
            delete NativeHandle;
        NativeHandle = NULL;
    };

    //! gp_Lin2d
    gp_Lin2d xgp_Lin2d::GetLin2d() {
        return *NativeHandle;
    };

    void xgp_Lin2d::Reverse() {
        return NativeHandle->Reverse();
    };


    //! Reverses the positioning axis of this line.
    //! Note:
    //! -   Reverse assigns the result to this line, while
    //! -   Reversed creates a new one.
    xgp_Lin2d^ xgp_Lin2d::Reversed() {
        return gcnew xgp_Lin2d(NativeHandle->Reversed());
    };

    //! Changes the direction of the line.
    void xgp_Lin2d::SetDirection(xgp_Dir2d^ V) {
        return NativeHandle->SetDirection(*V->GetDir2d());
    };

    //! Changes the origin of the line.
    void xgp_Lin2d::SetLocation(xgp_Pnt2d^ P) {
        return NativeHandle->SetLocation(P->GetPnt2d());
    };


    //! Complete redefinition of the line.
    //! The "Location" point of <A> is the origin of the line.
    //! The "Direction" of <A> is  the direction of the line.
    void xgp_Lin2d::SetPosition(xgp_Ax2d^ A) {
        return NativeHandle->SetPosition(*A->GetAx2d());
    };


    //! Returns the normalized coefficients of the line :
    //! A * X + B * Y + C = 0.
    void xgp_Lin2d::Coefficients(Standard_Real A, Standard_Real B, Standard_Real C) {
        NativeHandle->Coefficients(A, B, C);
    };

    //! Returns the direction of the line.
    xgp_Dir2d^ xgp_Lin2d::Direction() {
        gp_Dir2d* temp = new gp_Dir2d(NativeHandle->Direction());
        return gcnew xgp_Dir2d(temp);
    };

    //! Returns the location point (origin) of the line.
    xgp_Pnt2d^ xgp_Lin2d::Location() {
        return gcnew xgp_Pnt2d(NativeHandle->Location());
    };


    //! Returns the axis placement one axis whith the same
    //! location and direction as <me>.
    xgp_Ax2d^ xgp_Lin2d::Position() {
        gp_Ax2d* temp = new gp_Ax2d(NativeHandle->Position());
        return gcnew xgp_Ax2d(temp);
    };

    //! Computes the angle between two lines in radians.
    Standard_Real xgp_Lin2d::Angle(xgp_Lin2d^ Other) {
        return NativeHandle->Angle(Other->GetLin2d());
    };

    //! Returns true if this line contains the point P, that is, if the
    //! distance between point P and this line is less than or
    //! equal to LinearTolerance.
    Standard_Boolean xgp_Lin2d::Contains(xgp_Pnt2d^ P, Standard_Real LinearTolerance) {
        return NativeHandle->Contains(P->GetPnt2d(), LinearTolerance);
    };


    //! Computes the distance between <me> and the point <P>.
    Standard_Real xgp_Lin2d::Distance(xgp_Pnt2d^ P) {
        return NativeHandle->Distance(P->GetPnt2d());
    };

    //! Computes the distance between two lines.
    Standard_Real xgp_Lin2d::Distance(xgp_Lin2d^ Other) {
        return NativeHandle->Distance(Other->GetLin2d());
    };


    //! Computes the square distance between <me> and the point
    //! <P>.
    Standard_Real xgp_Lin2d::SquareDistance(xgp_Pnt2d^ P) {
        return NativeHandle->SquareDistance(P->GetPnt2d());
    };

    //! Computes the square distance between two lines.
    Standard_Real xgp_Lin2d::SquareDistance(xgp_Lin2d^ Other) {
        return NativeHandle->SquareDistance(Other->GetLin2d());
    };


    //! Computes the line normal to the direction of <me>,
    //! passing through the point <P>.
    xgp_Lin2d^ xgp_Lin2d::Normal(xgp_Pnt2d^ P) {
        return gcnew xgp_Lin2d(NativeHandle->Normal(P->GetPnt2d()));
    };

    void xgp_Lin2d::Mirror(xgp_Pnt2d^ P) {
        NativeHandle->Mirror(P->GetPnt2d());
    };


    //! Performs the symmetrical transformation of a line
    //! with respect to the point <P> which is the center
    //! of the symmetry
    xgp_Lin2d^ xgp_Lin2d::Mirrored(xgp_Pnt2d^ P) {
        return gcnew xgp_Lin2d(NativeHandle->Mirrored(P->GetPnt2d()));
    };

    void xgp_Lin2d::Mirror(xgp_Ax2d^ A) {
        NativeHandle->Mirror(*A->GetAx2d());
    };


    //! Performs the symmetrical transformation of a line
    //! with respect to an axis placement which is the axis
    //! of the symmetry.
    xgp_Lin2d^ xgp_Lin2d::Mirrored(xgp_Ax2d^ A) {
        return gcnew xgp_Lin2d(NativeHandle->Mirrored(*A->GetAx2d()));
    };

    void xgp_Lin2d::Rotate(xgp_Pnt2d^ P, Standard_Real Ang) {
        NativeHandle->Rotate(P->GetPnt2d(), Ang);
    };


    //! Rotates a line. P is the center of the rotation.
    //! Ang is the angular value of the rotation in radians.
    xgp_Lin2d^ xgp_Lin2d::Rotated(xgp_Pnt2d^ P, Standard_Real Ang) {
        return gcnew xgp_Lin2d(NativeHandle->Rotated(P->GetPnt2d(), Ang));
    };

    void xgp_Lin2d::Scale(xgp_Pnt2d^ P, Standard_Real S) {
        NativeHandle->Scale(P->GetPnt2d(), S);
    };


    //! Scales a line. S is the scaling value. Only the
    //! origin of the line is modified.
    xgp_Lin2d^ xgp_Lin2d::Scaled(xgp_Pnt2d^ P, Standard_Real S) {
        return gcnew xgp_Lin2d(NativeHandle->Scaled(P->GetPnt2d(), S));
    };

    void xgp_Lin2d::Transform(xgp_Trsf2d^ T) {
        NativeHandle->Transform(T->GetTrsf2d());
    };


    //! Transforms a line with the transformation T fromnamespace TKMath  {  public ref class Trsf2d.
    xgp_Lin2d^ xgp_Lin2d::Transformed(xgp_Trsf2d^ T) {
        return gcnew xgp_Lin2d(NativeHandle->Transformed(T->GetTrsf2d()));
    };

    void xgp_Lin2d::Translate(xgp_Vec2d^ V) {
        NativeHandle->Translate(V->GetVec2d());
    };


    //! Translates a line in the direction of the vector V.
    //! The magnitude of the translation is the vector's magnitude.
    xgp_Lin2d^ xgp_Lin2d::Translated(xgp_Vec2d^ V) {
        return gcnew xgp_Lin2d(NativeHandle->Translated(V->GetVec2d()));
    };

    void xgp_Lin2d::Translate(xgp_Pnt2d^ P1, xgp_Pnt2d^ P2) {
        NativeHandle->Translate(P1->GetPnt2d(), P2->GetPnt2d());
    };


    //! Translates a line from the point P1 to the point P2.
    xgp_Lin2d^ xgp_Lin2d::Translated(xgp_Pnt2d^ P1, xgp_Pnt2d^ P2) {
        return gcnew xgp_Lin2d(NativeHandle->Translated(P1->GetPnt2d(), P2->GetPnt2d()));
    };
};