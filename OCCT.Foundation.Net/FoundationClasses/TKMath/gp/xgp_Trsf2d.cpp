#include <xgp_Trsf2d.h>

namespace TKMath
{
    //! Returns identity transformation.
    xgp_Trsf2d::xgp_Trsf2d(void) {
        NativeHandle = new gp_Trsf2d();
    };

    /// <summary>
    /// 指针映射点
    /// </summary>
    /// <param name="pos"></param>
    xgp_Trsf2d::xgp_Trsf2d(gp_Trsf2d* pos) {
        NativeHandle = new gp_Trsf2d(*pos);
    };

    //! Creates a 2d transformation in the XY plane from a
    //! 3d transformation .
    xgp_Trsf2d::xgp_Trsf2d(xgp_Trsf^ T) {
        NativeHandle = new gp_Trsf2d(*T->GetTrsf());
    };

    //释放
    xgp_Trsf2d::~xgp_Trsf2d() {
        if (NativeHandle != NULL) {
            delete NativeHandle;
            NativeHandle = NULL;
        }
    };
    //释放
    xgp_Trsf2d::!xgp_Trsf2d() {
        if (NativeHandle != NULL) {
            delete NativeHandle;
            NativeHandle = NULL;
        }
    };


    //! Changes the transformation into a symmetrical transformation.
    //! P is the center of the symmetry.
    void xgp_Trsf2d::SetMirror(xgp_Pnt2d^ P) {
        NativeHandle->SetMirror(*P->GetPnt2d());
    };


    //! Changes the transformation into a symmetrical transformation.
    //! A is the center of the axial symmetry.
    void xgp_Trsf2d::SetMirror(xgp_Ax2d^ A) {
        NativeHandle->SetMirror(*A->GetAx2d());
    };


    //! Changes the transformation into a rotation.
    //! P is the rotation's center and Ang is the angular value of the
    //! rotation in radian.
    void xgp_Trsf2d::SetRotation(xgp_Pnt2d^ P, Standard_Real Ang) {
        NativeHandle->SetRotation(*P->GetPnt2d(), Ang);
    };


    //! Changes the transformation into a scale.
    //! P is the center of the scale and S is the scaling value.
    void xgp_Trsf2d::SetScale(xgp_Pnt2d^ P, Standard_Real S) {
        NativeHandle->SetScale(*P->GetPnt2d(), S);
    };


    //! Changes a transformation allowing passage from the coordinate
    //! system "FromSystem1" to the coordinate system "ToSystem2".
    void xgp_Trsf2d::SetTransformation(xgp_Ax2d^ FromSystem1, xgp_Ax2d^ ToSystem2) {
        NativeHandle->SetTransformation(*FromSystem1->GetAx2d(), *ToSystem2->GetAx2d());
    };


    //! Changes the transformation allowing passage from the basic
    //! coordinate system
    //! {P(0.,0.,0.), VX (1.,0.,0.), VY (0.,1.,0.)}
    //! to the local coordinate system defined with the Ax2d ToSystem.
    void xgp_Trsf2d::SetTransformation(xgp_Ax2d^ ToSystem) {
        NativeHandle->SetTransformation(*ToSystem->GetAx2d());
    };


    //! Changes the transformation into a translation.
    //! V is the vector of the translation.
    void xgp_Trsf2d::SetTranslation(xgp_Vec2d^ V) {
        NativeHandle->SetTranslation(*V->GetVec2d());
    };


    //! Makes the transformation into a translation from
    //! the point P1 to the point P2.
    void xgp_Trsf2d::SetTranslation(xgp_Pnt2d^ P1, xgp_Pnt2d^ P2) {
        NativeHandle->SetTranslation(*P1->GetPnt2d(), *P2->GetPnt2d());
    };

    //! Replaces the translation vector with V.
    void xgp_Trsf2d::SetTranslationPart(xgp_Vec2d^ V) {
        NativeHandle->SetTranslationPart(*V->GetVec2d());
    };

    //! Modifies the scale factor.
    void xgp_Trsf2d::SetScaleFactor(Standard_Real S) {
        NativeHandle->SetScaleFactor(S);
    };

    //! Returns the gp_Trsf2d
    gp_Trsf2d* xgp_Trsf2d::GetTrsf2d() {
        return NativeHandle;
    };

    //! Returns true if the determinant of the vectorial part of
    //! this transformation is negative..
    Standard_Boolean xgp_Trsf2d::IsNegative() {
        return NativeHandle->IsNegative();
    };


    //! Returns the nature of the transformation. It can be  an
    //! identity transformation, a rotation, a translation, a mirror
    //! (relative to a point or an axis), a scaling transformation,
    //! or a compound transformation.
    int^ xgp_Trsf2d::Form() {
        int f = NativeHandle->Form();
        return (f);
    };

    //! Returns the scale factor.
    Standard_Real xgp_Trsf2d::ScaleFactor() {
        return  NativeHandle->ScaleFactor();
    };


    //! Returns the translation part of the transformation's matrix
    xgp_XY^ xgp_Trsf2d::TranslationPart() {
        gp_XY* temp = new gp_XY(NativeHandle->TranslationPart());
        return gcnew xgp_XY(temp);
    };


    //! Returns the vectorial part of the transformation. It is a
    //! 2*2 matrix which includes the scale factor.
    xgp_Mat2d^ xgp_Trsf2d::VectorialPart() {
        gp_Mat2d* temp = new gp_Mat2d(NativeHandle->VectorialPart());
        return gcnew xgp_Mat2d(temp);
    };


    //! Returns the homogeneous vectorial part of the transformation.
    //! It is a 2*2 matrix which doesn't include the scale factor.
    //! The coefficients of this matrix must be multiplied by the
    //! scale factor to obtain the coefficients of the transformation.
    xgp_Mat2d^ xgp_Trsf2d::HVectorialPart() {
        gp_Mat2d* temp = new gp_Mat2d(NativeHandle->HVectorialPart());
        return gcnew xgp_Mat2d(temp);
    };


    //! Returns the angle corresponding to the rotational component
    //! of the transformation matrix (operation opposite to SetRotation()).
    Standard_Real xgp_Trsf2d::RotationPart() {
        return NativeHandle->RotationPart();
    };


    //! Returns the coefficients of the transformation's matrix.
    //! It is a 2 rows * 3 columns matrix.
    //! Raises OutOfRange if Row < 1 or Row > 2 or Col < 1 or Col > 3
    Standard_Real xgp_Trsf2d::Value(Standard_Integer Row, Standard_Integer Col) {
        return NativeHandle->Value(Row, Col);
    };

    void xgp_Trsf2d::Invert() {
        NativeHandle->Invert();
    };


    //! Computes the reverse transformation.
    //! Raises an exception if the matrix of the transformation
    //! is not inversible, it means that the scale factor is lower
    //! or equal to Resolution from package gp.
    xgp_Trsf2d^ xgp_Trsf2d::Inverted() {
        gp_Trsf2d* temp = new gp_Trsf2d(NativeHandle->Inverted());
        return gcnew xgp_Trsf2d(temp);
    };

    xgp_Trsf2d^ xgp_Trsf2d::Multiplied(xgp_Trsf2d^ T) {
        gp_Trsf2d* temp = new gp_Trsf2d(NativeHandle->Multiplied(*T->GetTrsf2d()));
        return gcnew xgp_Trsf2d(temp);
    };


    //! Computes the transformation composed from <me> and T.
    //! <me> = <me> * T
    void xgp_Trsf2d::Multiply(xgp_Trsf2d^ T) {
        NativeHandle->Multiply(*T->GetTrsf2d());
    };


    //! Computes the transformation composed from <me> and T.
    //! <me> = T * <me>
    void xgp_Trsf2d::PreMultiply(xgp_Trsf2d^ T) {
        NativeHandle->PreMultiply(*T->GetTrsf2d());
    };

    void xgp_Trsf2d::Power(Standard_Integer N) {
        NativeHandle->Power(N);
    };


    //! Computes the following composition of transformations
    //! <me> * <me> * .......* <me>,  N time.
    //! if N = 0 <me> = Identity
    //! if N < 0 <me> = <me>.Inverse() *...........* <me>.Inverse().
    //!
    //! Raises if N < 0 and if the matrix of the transformation not
    //! inversible.
    xgp_Trsf2d^ xgp_Trsf2d::Powered(Standard_Integer N) {
        gp_Trsf2d* temp = new gp_Trsf2d(NativeHandle->Powered(N));
        return gcnew xgp_Trsf2d(temp);
    };

    void xgp_Trsf2d::Transforms(Standard_Real X, Standard_Real Y) {
        NativeHandle->Transforms(gp_XY(X, Y));
    };

    //! Transforms  a doublet XY with a Trsf2d
    void xgp_Trsf2d::Transforms(xgp_XY^ Coord) {
        NativeHandle->Transforms(*Coord->GetXY());
    };

    //! Sets the coefficients  of the transformation. The
    //! transformation  of the  point  x,y is  the point
    //! x',y' with :
    //!
    //! x' = a11 x + a12 y + a13
    //! y' = a21 x + a22 y + a23
    //!
    //! The method Value(i,j) will return aij.
    //! Raises ConstructionError if the determinant of the aij is null.
    //! If the matrix as not a uniform scale it will be orthogonalized before future using.
    void xgp_Trsf2d::SetValues(Standard_Real a11, Standard_Real a12, Standard_Real a13, Standard_Real a21, Standard_Real a22, Standard_Real a23) {
        NativeHandle->SetValues(a11, a12, a13, a21, a22, a23);
    };
};
