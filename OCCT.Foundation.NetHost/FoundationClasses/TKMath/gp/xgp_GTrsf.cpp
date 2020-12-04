#include <xgp_GTrsf.h>

namespace TKMath
{
    //! Returns the Identity transformation.
    xgp_GTrsf::xgp_GTrsf(void) {
        NativeHandle = new  gp_GTrsf();
    };

    /// <summary>
    /// 指针映射点
    /// </summary>
    /// <param name="pos"></param>
    xgp_GTrsf::xgp_GTrsf(gp_GTrsf* pos) {
        NativeHandle = new  gp_GTrsf(*pos);
    };
    /// <summary>
    ///  映射点
    /// </summary>
    /// <param name="pos"></param>
    xgp_GTrsf::xgp_GTrsf(gp_GTrsf pos) {
        NativeHandle = new  gp_GTrsf(pos);
    };

    //! Converts the xgp_Trsf transformation T into a
    //! general transformation, i.e. Returns a GTrsf with
    //! the same matrix of coefficients as the Trsf T.
    xgp_GTrsf::xgp_GTrsf(xgp_Trsf^ T) {
        NativeHandle = new  gp_GTrsf(T->GetTrsf());
    };


    //! Creates a transformation based on the matrix M and the
    //! vector V where M defines the vectorial part of
    //! the transformation, and V the translation part, or
    xgp_GTrsf::xgp_GTrsf(xgp_Mat^ M, xgp_XYZ^ V) {
        NativeHandle = new gp_GTrsf(M->GetMat(), *V->GetXYZ());
    };


    //释放
    xgp_GTrsf::~xgp_GTrsf() {
        if (NativeHandle != NULL)
            delete NativeHandle;
        NativeHandle = NULL;
    };
    //释放
    xgp_GTrsf::!xgp_GTrsf() {
        if (NativeHandle != NULL)
            delete NativeHandle;
        NativeHandle = NULL;
    };

    //! gp_GTrsf
    gp_GTrsf xgp_GTrsf::GetGTrsf() {
        return *NativeHandle;
    };

    //! Changes this transformation into an affinity of ratio Ratio
    //! with respect to the axis A1.
    //! Note: an affinity is a point-by-point transformation that
    //! transforms any point P into a point P' such that if H is
    //! the orthogonal projection of P on the axis A1 or the
    //! plane A2, the vectors HP and HP' satisfy:
    //! HP' = Ratio * HP.
    void xgp_GTrsf::SetAffinity(xgp_Ax1^ A1, Standard_Real Ratio) {
        NativeHandle->SetAffinity(*A1->GetAx1(), Ratio);
    };

    //! Changes this transformation into an affinity of ratio Ratio
    //! with respect to  the plane defined by the origin, the "X Direction" and
    //! the "Y Direction" of coordinate system A2.
    //! Note: an affinity is a point-by-point transformation that
    //! transforms any point P into a point P' such that if H is
    //! the orthogonal projection of P on the axis A1 or the
    //! plane A2, the vectors HP and HP' satisfy:
    //! HP' = Ratio * HP.
    void xgp_GTrsf::SetAffinity(xgp_Ax2^ A2, Standard_Real Ratio) {
        NativeHandle->SetAffinity(A2->GetAx2(), Ratio);
    };


    //! Replaces  the coefficient (Row, Col) of the matrix representing
    //! this transformation by Value.  Raises OutOfRange
    //! if  Row < 1 or Row > 3 or Col < 1 or Col > 4
    void xgp_GTrsf::SetValue(Standard_Integer Row, Standard_Integer Col, Standard_Real Value) {
        NativeHandle->SetValue(Row, Col, Value);
    };

    //! Replaces the vectorial part of this transformation by Matrix.
    void xgp_GTrsf::SetVectorialPart(xgp_Mat^ Matrix) {
        NativeHandle->SetVectorialPart(Matrix->GetMat());
    };

    //! Replaces the translation part of
    //! this transformation by the coordinates of the number triple Coord.
    void xgp_GTrsf::SetTranslationPart(xgp_XYZ^ Coord) {
        NativeHandle->SetTranslationPart(*Coord->GetXYZ());
    };

    //! Assigns the vectorial and translation parts of T to this transformation.
    void xgp_GTrsf::SetTrsf(xgp_Trsf^ T) {
        NativeHandle->SetTrsf(T->GetTrsf());
    };


    //! Returns true if the determinant of the vectorial part of
    //! this transformation is negative.
    Standard_Boolean xgp_GTrsf::IsNegative() {
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
    Standard_Boolean xgp_GTrsf::IsSingular() {
        return NativeHandle->IsSingular();
    };


    //! Returns the nature of the transformation.  It can be an
    //! identity transformation, a rotation, a translation, a mirror
    //! transformation (relative to a point, an axis or a plane), a
    //! scaling transformation, a compound transformation or
    //! some other type of transformation.
    //! gp_TrsfForm
    int^ xgp_GTrsf::Form() {
        int tf = NativeHandle->Form();
        return (tf);
    };


    //! verify and set the shape of the GTrsf Other or CompoundTrsf
    //! Ex :
    //! myGTrsf.SetValue(row1,col1,val1);
    //! myGTrsf.SetValue(row2,col2,val2);
    //! ...
    //! myGTrsf.SetForm();
    void xgp_GTrsf::SetForm() {
        NativeHandle->SetForm();
    };

    //! Returns the translation part of the GTrsf.
    xgp_XYZ^ xgp_GTrsf::TranslationPart() {
        gp_XYZ* aXYZ = new gp_XYZ(NativeHandle->TranslationPart());
        return gcnew xgp_XYZ(aXYZ);
    };


    //! Computes the vectorial part of the GTrsf. The returned Matrix
    //! is a  3*3 matrix.
    xgp_Mat^ xgp_GTrsf::VectorialPart() {
        return gcnew xgp_Mat(NativeHandle->VectorialPart());
    };


    //! Returns the coefficients of the global matrix of transformation.
    //! Raises OutOfRange if Row < 1 or Row > 3 or Col < 1 or Col > 4
    Standard_Real xgp_GTrsf::Value(Standard_Integer Row, Standard_Integer Col) {
        return  NativeHandle->Value(Row, Col);
    };

    void xgp_GTrsf::Invert() {
        NativeHandle->Invert();
    };


    //! Computes the reverse transformation.
    //! Raises an exception if the matrix of the transformation
    //! is not inversible.
    xgp_GTrsf^ xgp_GTrsf::Inverted() {
        return gcnew xgp_GTrsf(NativeHandle->Inverted());
    };


    //! Computes the transformation composed from T and <me>.
    //! In a C++ implementation you can also write Tcomposed = <me> * T.
    //! Example :
    //! GTrsf T1, T2, Tcomp; ...............
    //! //composition :
    //! Tcomp = T2.Multiplied(T1);         // or   (Tcomp = T2 * T1)
    //! // transformation of a point
    //! XYZ P(10.,3.,4.);
    //! XYZ P1(P);
    //! Tcomp.Transforms(P1);               //using Tcomp
    //! XYZ P2(P);
    //! T1.Transforms(P2);                  //using T1 then T2
    //! T2.Transforms(P2);                  // P1 = P2 !!!
    xgp_GTrsf^ xgp_GTrsf::Multiplied(xgp_GTrsf^ T) {
        return gcnew xgp_GTrsf(NativeHandle->Multiplied(T->GetGTrsf()));
    };


    //! Computes the transformation composed with <me> and T.
    //! <me> = <me> * T
    void xgp_GTrsf::Multiply(xgp_GTrsf^ T) {
        NativeHandle->Multiply(T->GetGTrsf());
    };


    //! Computes the product of the transformation T and this
    //! transformation and assigns the result to this transformation.
    //! this = T * this
    void xgp_GTrsf::PreMultiply(xgp_GTrsf^ T) {
        NativeHandle->PreMultiply(T->GetGTrsf());
    };

    void xgp_GTrsf::Power(Standard_Integer N) {
        NativeHandle->Power(N);
    };


    //! Computes:
    //! -   the product of this transformation multiplied by itself
    //! N times, if N is positive, or
    //! -   the product of the inverse of this transformation
    //! multiplied by itself |N| times, if N is negative.
    //! If N equals zero, the result is equal to the Identity
    //! transformation.
    //! I.e.:  <me> * <me> * .......* <me>, N time.
    //! if N =0 <me> = Identity
    //! if N < 0 <me> = <me>.Inverse() *...........* <me>.Inverse().
    //!
    //! Raises an exception if N < 0 and if the matrix of the
    //! transformation not inversible.
    xgp_GTrsf^ xgp_GTrsf::Powered(Standard_Integer N) {
        return gcnew xgp_GTrsf(NativeHandle->Powered(N));
    };

    void xgp_GTrsf::Transforms(xgp_XYZ^ Coord) {
        NativeHandle->Transforms(*Coord->GetXYZ());
    };

    //! Transforms a triplet XYZ with a GTrsf.
    void xgp_GTrsf::Transforms(Standard_Real X, Standard_Real Y, Standard_Real Z) {
        NativeHandle->Transforms(X, Y, Z);
    };

    xgp_Trsf^ xgp_GTrsf::Trsf() {
        return gcnew xgp_Trsf(NativeHandle->Trsf());
    };
};