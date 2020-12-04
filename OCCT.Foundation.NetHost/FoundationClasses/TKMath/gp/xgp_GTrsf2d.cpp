#include <xgp_GTrsf2d.h>

namespace TKMath
{
    //! returns identity transformation.
    xgp_GTrsf2d::xgp_GTrsf2d(void) {
        NativeHandle = new  gp_GTrsf2d();
    };

    /// <summary>
    /// 指针映射点
    /// </summary>
    /// <param name="pos"></param>
    xgp_GTrsf2d::xgp_GTrsf2d(gp_GTrsf2d* pos) {
        NativeHandle = new  gp_GTrsf2d(*pos);
    };

    //! Converts the xgp_Trsf2d transformation T into a
    //! general transformation.
    xgp_GTrsf2d::xgp_GTrsf2d(xgp_Trsf2d^ T) {
        NativeHandle = new  gp_GTrsf2d(T->GetTrsf2d());
    };

    //! Creates   a transformation based on the matrix M and the
    //! vector V where M defines the vectorial part of the
    //! transformation, and V the translation part.
    xgp_GTrsf2d::xgp_GTrsf2d(xgp_Mat2d^ M, xgp_XY^ V) {
        NativeHandle = new gp_GTrsf2d(M->GetMat2d(), V->GetXY());
    };



    //释放
    xgp_GTrsf2d::~xgp_GTrsf2d() {
        if (NativeHandle != NULL)
            delete NativeHandle;
        NativeHandle = NULL;
    };
    //释放
    xgp_GTrsf2d::!xgp_GTrsf2d() {
        if (NativeHandle != NULL)
            delete NativeHandle;
        NativeHandle = NULL;
    };

    //! gp_GTrsf2d
    gp_GTrsf2d* xgp_GTrsf2d::GetGTrsf2d() {
        return NativeHandle;
    };

    //! Changes this transformation into an affinity of ratio Ratio
    //! with respect to the axis A.
    //! Note: An affinity is a point-by-point transformation that
    //! transforms any point P into a point P' such that if H is
    //! the orthogonal projection of P on the axis A, the vectors
    //! HP and HP' satisfy: HP' = Ratio * HP.
    void xgp_GTrsf2d::SetAffinity(xgp_Ax2d^ A, Standard_Real Ratio) {
        NativeHandle->SetAffinity(*A->GetAx2d(), Ratio);
    };


    //! Replaces   the coefficient (Row, Col) of the matrix representing
    //! this transformation by Value,
    //! Raises OutOfRange if Row < 1 or Row > 2 or Col < 1 or Col > 3
    void xgp_GTrsf2d::SetValue(Standard_Integer Row, Standard_Integer Col, Standard_Real Value) {
        NativeHandle->SetValue(Row, Col, Value);
    };

    //! Replacesthe translation part of this
    //! transformation by the coordinates of the number pair Coord.
    void xgp_GTrsf2d::SetTranslationPart(xgp_XY^ Coord) {
        NativeHandle->SetTranslationPart(Coord->GetXY());
    };


    //! Assigns the vectorial and translation parts of T to this transformation.
    void xgp_GTrsf2d::SetTrsf2d(xgp_Trsf2d^ T) {
        NativeHandle->SetTrsf2d(T->GetTrsf2d());
    };


    //! Replaces the vectorial part of this transformation by Matrix.
    void xgp_GTrsf2d::SetVectorialPart(xgp_Mat2d^ Matrix) {
        NativeHandle->SetVectorialPart(Matrix->GetMat2d());
    };


    //! Returns true if the determinant of the vectorial part of
    //! this transformation is negative.
    Standard_Boolean xgp_GTrsf2d::IsNegative() {
        return NativeHandle->IsNegative();
    };

    //! Returns true if this transformation is singular (and
    //! therefore, cannot be inverted).
    //! Note: The Gauss LU decomposition is used to invert the
    //! transformation matrix. Consequently, the transformation
    //! is considered as singular if the largest pivot found is less
    //! than or equal to gp::Resolution().
    //! Warning
    //! If this transformation is singular, it cannot be inverted.
    Standard_Boolean xgp_GTrsf2d::IsSingular() {
        return NativeHandle->IsSingular();
    };


    //! Returns the nature of the transformation.  It can be
    //! an identity transformation, a rotation, a translation, a mirror
    //! transformation (relative to a point or axis), a scaling
    //! transformation, a compound transformation or some
    //! other type of transformation.
    //! gp_TrsfForm
    int^ xgp_GTrsf2d::Form() {
        int tf = NativeHandle->Form();
        return (tf);
    };

    //! Returns the translation part of the GTrsf2d.
    xgp_XY^ xgp_GTrsf2d::TranslationPart() {
        return gcnew xgp_XY(NativeHandle->TranslationPart());
    };


    //! Computes the vectorial part of the GTrsf2d. The returned
    //! Matrix is a 2*2 matrix.
    xgp_Mat2d^ xgp_GTrsf2d::VectorialPart() {
        return gcnew xgp_Mat2d(NativeHandle->VectorialPart());
    };


    //! Returns the coefficients of the global matrix of transformation.
    //! Raised OutOfRange if Row < 1 or Row > 2 or Col < 1 or Col > 3
    Standard_Real xgp_GTrsf2d::Value(Standard_Integer Row, Standard_Integer Col) {
        return  NativeHandle->Value(Row, Col);
    };


    void xgp_GTrsf2d::Invert() {
        NativeHandle->Invert();
    };


    //! Computes the reverse transformation.
    //! Raised an exception if the matrix of the transformation
    //! is not inversible.
    xgp_GTrsf2d^ xgp_GTrsf2d::Inverted() {
        gp_GTrsf2d* temp = new gp_GTrsf2d(NativeHandle->Inverted());
        return gcnew xgp_GTrsf2d(temp);
    };


    //! Computes the transformation composed with T and <me>.
    //! In a C++ implementation you can also write Tcomposed = <me> * T.
    //! Example :
    //! GTrsf2d T1, T2, Tcomp; ...............
    //! //composition :
    //! Tcomp = T2.Multiplied(T1);         // or   (Tcomp = T2 * T1)
    //! // transformation of a point
    //! XY P(10.,3.);
    //! XY P1(P);
    //! Tcomp.Transforms(P1);               //using Tcomp
    //! XY P2(P);
    //! T1.Transforms(P2);                  //using T1 then T2
    //! T2.Transforms(P2);                  // P1 = P2 !!!
    xgp_GTrsf2d^ xgp_GTrsf2d::Multiplied(xgp_GTrsf2d^ T) {
        gp_GTrsf2d* temp = new gp_GTrsf2d(NativeHandle->Multiplied(*T->GetGTrsf2d()));
        return gcnew xgp_GTrsf2d(temp);
    };

    void xgp_GTrsf2d::Multiply(xgp_GTrsf2d^ T) {
        NativeHandle->Multiply(*T->GetGTrsf2d());
    };


    //! Computes the product of the transformation T and this
    //! transformation, and assigns the result to this transformation:
    //! this = T * this
    void xgp_GTrsf2d::PreMultiply(xgp_GTrsf2d^ T) {
        NativeHandle->PreMultiply(*T->GetGTrsf2d());
    };

    void xgp_GTrsf2d::Power(Standard_Integer N) {
        NativeHandle->Power(N);
    };


    //! Computes the following composition of transformations
    //! <me> * <me> * .......* <me>, N time.
    //! if N = 0 <me> = Identity
    //! if N < 0 <me> = <me>.Inverse() *...........* <me>.Inverse().
    //!
    //! Raises an exception if N < 0 and if the matrix of the
    //! transformation is not inversible.
    xgp_GTrsf2d^ xgp_GTrsf2d::Powered(Standard_Integer N) {
        gp_GTrsf2d* temp = new gp_GTrsf2d(NativeHandle->Powered(N));
        return gcnew xgp_GTrsf2d(temp);
    };

    void xgp_GTrsf2d::Transforms(xgp_XY^ Coord) {
        NativeHandle->Transforms(Coord->GetXY());
    };

    xgp_XY^ xgp_GTrsf2d::Transformed(xgp_XY^ Coord) {
        return gcnew xgp_XY(NativeHandle->Transformed(Coord->GetXY()));
    };


    //! Applies this transformation to the coordinates:
    //! -   of the number pair Coord, or
    //! -   X and Y.
    //!
    //! Note:
    //! -   Transforms modifies X, Y, or the coordinate pair Coord, while
    //! -   Transformed creates a new coordinate pair.
    void xgp_GTrsf2d::Transforms(Standard_Real X, Standard_Real Y) {
        NativeHandle->Transforms(X, Y);
    };


    //! Converts this transformation into a xgp_Trsf2d transformation.
    //! Exceptions
    //! Standard_ConstructionError if this transformation
    //! cannot be converted, i.e. if its form is gp_Other.
    xgp_Trsf2d^ xgp_GTrsf2d::Trsf2d() {
        return gcnew xgp_Trsf2d(NativeHandle->Trsf2d());
    };
};

