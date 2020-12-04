#include <xgp_Trsf.h>

namespace TKMath
{
    //! Returns the identity transformation.
    xgp_Trsf::xgp_Trsf(void) {
        NativeHandle = new gp_Trsf();
    };

    /// <summary>
    /// 指针映射点
    /// </summary>
    /// <param name="pos"></param>
    xgp_Trsf::xgp_Trsf(gp_Trsf* pos) {
        NativeHandle = new gp_Trsf(*pos);
    };

    /// <summary>
    ///  映射点
    /// </summary>
    /// <param name="pos"></param>
    xgp_Trsf::xgp_Trsf(gp_Trsf pos) {
        NativeHandle = new gp_Trsf(pos);
    };

    //! Creates  a 3D transformation from the 2D transformation T.
    //! The resulting transformation has a homogeneous
    //! vectorial part, V3, and a translation part, T3, built from T:
    //! a11    a12
    //! 0             a13
    //! V3 =    a21    a22    0       T3
    //! =   a23
    //! 0    0    1.
    //! 0
    //! It also has the same scale factor as T. This
    //! guarantees (by projection) that the transformation
    //! which would be performed by T in a plane (2D space)
    //! is performed by the resulting transformation in the xOy
    //! plane of the 3D space, (i.e. in the plane defined by the
    //! origin (0., 0., 0.) and the vectors DX (1., 0., 0.), and DY
    //! (0., 1., 0.)). The scale factor is applied to the entire space.
    xgp_Trsf::xgp_Trsf(xgp_Trsf2d^ T) {
        NativeHandle = new gp_Trsf(T->GetTrsf2d());
    };


    //释放
    xgp_Trsf::~xgp_Trsf() {
        if (NativeHandle != NULL) {
            delete NativeHandle;
            NativeHandle = NULL;
        }
    };
    //释放
    xgp_Trsf::!xgp_Trsf() {
        if (NativeHandle != NULL) {
            delete NativeHandle;
            NativeHandle = NULL;
        }
    };

    //! Makes the transformation into a symmetrical transformation.
    //! P is the center of the symmetry.
    void xgp_Trsf::SetMirror(xgp_Pnt^ P) {
        NativeHandle->SetMirror(P->GetPnt());
    };


    //! Makes the transformation into a symmetrical transformation.
    //! A1 is the center of the axial symmetry.
    void xgp_Trsf::SetMirror(xgp_Ax1^ A1) {
        NativeHandle->SetMirror(A1->GetAx1());
    };


    //! Makes the transformation into a symmetrical transformation.
    //! A2 is the center of the planar symmetry
    //! and defines the plane of symmetry by its origin, "X
    //! Direction" and "Y Direction".
    void xgp_Trsf::SetMirror(xgp_Ax2^ A2) {
        NativeHandle->SetMirror(A2->GetAx2());
    };


    //! Changes the transformation into a rotation.
    //! A1 is the rotation axis and Ang is the angular value of the
    //! rotation in radians.
    void xgp_Trsf::SetRotation(xgp_Ax1^ A1, Standard_Real Ang) {
        NativeHandle->SetRotation(A1->GetAx1(), Ang);
    };


    //! Changes the transformation into a rotation defined by quaternion.
    //! Note that rotation is performed around origin, i.e.
    //! no translation is involved.
    void xgp_Trsf::SetRotation(xgp_Quaternion^ R) {
        NativeHandle->SetRotation(R->GetQuaternion());
    };


    //! Changes the transformation into a scale.
    //! P is the center of the scale and S is the scaling value.
    //! Raises ConstructionError  If <S> is null.
    void xgp_Trsf::SetScale(xgp_Pnt^ P, Standard_Real S) {
        NativeHandle->SetScale(P->GetPnt(), S);
    };


    //! Modifies this transformation so that it transforms the
    //! coordinate system defined by FromSystem1 into the
    //! one defined by ToSystem2. After this modification, this
    //! transformation transforms:
    //! -   the origin of FromSystem1 into the origin of ToSystem2,
    //! -   the "X Direction" of FromSystem1 into the "X
    //! Direction" of ToSystem2,
    //! -   the "Y Direction" of FromSystem1 into the "Y
    //! Direction" of ToSystem2, and
    //! -   the "main Direction" of FromSystem1 into the "main
    //! Direction" of ToSystem2.
    //! Warning
    //! When you know the coordinates of a point in one
    //! coordinate system and you want to express these
    //! coordinates in another one, do not use the
    //! transformation resulting from this function. Use the
    //! transformation that results from SetTransformation instead.
    //! SetDisplacement and SetTransformation create
    //! related transformations: the vectorial part of one is the
    //! inverse of the vectorial part of the other.
    void xgp_Trsf::SetDisplacement(xgp_Ax3^ FromSystem1, xgp_Ax3^ ToSystem2) {
        NativeHandle->SetDisplacement(FromSystem1->GetAx3(), ToSystem2->GetAx3());
    };

    //! Modifies this transformation so that it transforms the
    //! coordinates of any point, (x, y, z), relative to a source
    //! coordinate system into the coordinates (x', y', z') which
    //! are relative to a target coordinate system, but which
    //! represent the same point
    //! The transformation is from the coordinate
    //! system "FromSystem1" to the coordinate system "ToSystem2".
    //! Example :
    //! In a C++ implementation :
    //! Real x1, y1, z1;  // are the coordinates of a point in the
    //! // local system FromSystem1
    //! Real x2, y2, z2;  // are the coordinates of a point in the
    //! // local system ToSystem2
    //! xgp_Pnt P1 (x1, y1, z1)
    //! Trsf T;
    //! T.SetTransformation (FromSystem1, ToSystem2);
    //! xgp_Pnt P2 = P1.Transformed (T);
    //! P2.Coord (x2, y2, z2);
    void xgp_Trsf::SetTransformation(xgp_Ax3^ FromSystem1, xgp_Ax3^ ToSystem2) {
        NativeHandle->SetTransformation(FromSystem1->GetAx3(), ToSystem2->GetAx3());
    };

    //! Modifies this transformation so that it transforms the
    //! coordinates of any point, (x, y, z), relative to a source
    //! coordinate system into the coordinates (x', y', z') which
    //! are relative to a target coordinate system, but which
    //! represent the same point
    //! The transformation is from the default coordinate system
    //! {P(0.,0.,0.), VX (1.,0.,0.), VY (0.,1.,0.), VZ (0., 0. ,1.) }
    //! to the local coordinate system defined with the Ax3 ToSystem.
    //! Use in the same way  as the previous method. FromSystem1 is
    //! defaulted to the absolute coordinate system.
    void xgp_Trsf::SetTransformation(xgp_Ax3^ ToSystem) {
        NativeHandle->SetTransformation(ToSystem->GetAx3());
    };


    //! Sets transformation by directly specified rotation and translation.
    void xgp_Trsf::SetTransformation(xgp_Quaternion^ R, xgp_Vec^ T) {
        NativeHandle->SetTransformation(R->GetQuaternion(), T->GetVec());
    };


    //! Changes the transformation into a translation.
    //! V is the vector of the translation.
    void xgp_Trsf::SetTranslation(xgp_Vec^ V) {
        NativeHandle->SetTranslation(V->GetVec());
    };


    //! Makes the transformation into a translation where the translation vector
    //! is the vector (P1, P2) defined from point P1 to point P2.
    void xgp_Trsf::SetTranslation(xgp_Pnt^ P1, xgp_Pnt^ P2) {
        NativeHandle->SetTranslation(P1->GetPnt(),P2->GetPnt());
    };

    //! Replaces the translation vector with the vector V.
    void xgp_Trsf::SetTranslationPart(xgp_Vec^ V) {
        NativeHandle->SetTranslationPart(V->GetVec());
    };

    //! Modifies the scale factor.
    //! Raises ConstructionError  If S is null.
    void xgp_Trsf::SetScaleFactor(Standard_Real S) {
        NativeHandle->SetScaleFactor(S);
    };

    void xgp_Trsf::SetTrsfForm(xgp_TrsfForm trsfForm) {
        gp_TrsfForm tf =  safe_cast<gp_TrsfForm>(trsfForm);
        NativeHandle->SetForm(tf);
    };

    //! Sets the coefficients  of the transformation.  The
    //! transformation  of the  point  x,y,z is  the point
    //! x',y',z' with :
    //!
    //! x' = a11 x + a12 y + a13 z + a14
    //! y' = a21 x + a22 y + a23 z + a24
    //! z' = a31 x + a32 y + a33 z + a34
    //!
    //! The method Value(i,j) will return aij.
    //! Raises ConstructionError if the determinant of  the aij is null.
    //! The matrix is orthogonalized before future using.
    void xgp_Trsf::SetValues(Standard_Real a11, Standard_Real a12, Standard_Real a13, Standard_Real a14, Standard_Real a21, Standard_Real a22, Standard_Real a23, Standard_Real a24, Standard_Real a31, Standard_Real a32, Standard_Real a33, Standard_Real a34) {
        NativeHandle->SetValues(a11, a12, a13, a14, a21, a22, a23, a24, a31, a32, a33, a34);
    };

    //! Returns the gp_Trsf
    gp_Trsf xgp_Trsf::GetTrsf() {
        return *NativeHandle;
    };

    //! Returns true if the determinant of the vectorial part of
    //! this transformation is negative.
    Standard_Boolean xgp_Trsf::IsNegative() {
        return NativeHandle->IsNegative();
    };


    //! Returns the nature of the transformation. It can be: an
    //! identity transformation, a rotation, a translation, a mirror
    //! transformation (relative to a point, an axis or a plane), a
    //! scaling transformation, or a compound transformation.
    //! gp_TrsfForm
    int^ xgp_Trsf::Form() {
        int tf = NativeHandle->Form();
        return (tf);
    };

    //! Returns the scale factor.
    Standard_Real xgp_Trsf::ScaleFactor() {
        return NativeHandle->ScaleFactor();
    };


    //! Returns the translation part of the transformation's matrix
    xgp_XYZ^ xgp_Trsf::TranslationPart() {
        gp_XYZ* aXYZ = new gp_XYZ(NativeHandle->TranslationPart());
        return gcnew xgp_XYZ(aXYZ);
    };


    //! Returns the boolean True if there is non-zero rotation.
    //! In the presence of rotation, the output parameters store the axis
    //! and the angle of rotation. The method always returns positive
    //! value "theAngle", i.e., 0. < theAngle <= PI.
    //! Note that this rotation is defined only by the vectorial part of
    //! the transformation; generally you would need to check also the
    //! translational part to obtain the axis (xgp_Ax1) of rotation.
    Standard_Boolean xgp_Trsf::GetRotation(xgp_XYZ^ theAxis, Standard_Real theAngle) {
        return NativeHandle->GetRotation(*theAxis->GetXYZ(), theAngle);
    };


    //! Returns quaternion representing rotational part of the transformation.
    xgp_Quaternion^ xgp_Trsf::GetRotation() {
        return gcnew xgp_Quaternion(NativeHandle->GetRotation());
    };


    //! Returns the vectorial part of the transformation. It is
    //! a 3*3 matrix which includes the scale factor.
    xgp_Mat^ xgp_Trsf::VectorialPart() {
        return gcnew xgp_Mat(NativeHandle->VectorialPart());
    };


    //! Computes the homogeneous vectorial part of the transformation.
    //! It is a 3*3 matrix which doesn't include the scale factor.
    //! In other words, the vectorial part of this transformation is equal
    //! to its homogeneous vectorial part, multiplied by the scale factor.
    //! The coefficients of this matrix must be multiplied by the
    //! scale factor to obtain the coefficients of the transformation.
    xgp_Mat^ xgp_Trsf::HVectorialPart() {
        return gcnew xgp_Mat(NativeHandle->HVectorialPart());
    };


    //! Returns the coefficients of the transformation's matrix.
    //! It is a 3 rows * 4 columns matrix.
    //! This coefficient includes the scale factor.
    //! Raises OutOfRanged if Row < 1 or Row > 3 or Col < 1 or Col > 4
    Standard_Real xgp_Trsf::Value(Standard_Integer Row, Standard_Integer Col) {
        return NativeHandle->Value(Row, Col);
    };

    void xgp_Trsf::Invert() {
        NativeHandle->Invert();
    };


    //! Computes the reverse transformation
    //! Raises an exception if the matrix of the transformation
    //! is not inversible, it means that the scale factor is lower
    //! or equal to Resolution from package gp.
    //! Computes the transformation composed with T and  <me>.
    //! In a C++ implementation you can also write Tcomposed = <me> * T.
    //! Example :
    //! Trsf T1, T2, Tcomp; ...............
    //! Tcomp = T2.Multiplied(T1);         // or   (Tcomp = T2 * T1)
    //! Pnt P1(10.,3.,4.);
    //! Pnt P2 = P1.Transformed(Tcomp);    //using Tcomp
    //! Pnt P3 = P1.Transformed(T1);       //using T1 then T2
    //! P3.Transform(T2);                  // P3 = P2 !!!
    xgp_Trsf^ xgp_Trsf::Inverted() {
        return gcnew xgp_Trsf(NativeHandle->Inverted());
    };

    xgp_Trsf^ xgp_Trsf::Multiplied(xgp_Trsf^ T) {
        return gcnew xgp_Trsf(NativeHandle->Multiplied(T->GetTrsf()));
    };


    //! Computes the transformation composed with <me> and T.
    //! <me> = <me> * T
    void xgp_Trsf::Multiply(xgp_Trsf^ T) {
        NativeHandle->Multiply(T->GetTrsf());
    };


    //! Computes the transformation composed with <me> and T.
    //! <me> = T * <me>
    void xgp_Trsf::PreMultiply(xgp_Trsf^ T) {
        NativeHandle->PreMultiply(T->GetTrsf());
    };

    void xgp_Trsf::Power(Standard_Integer N) {
        NativeHandle->Power(N);
    };


    //! Computes the following composition of transformations
    //! <me> * <me> * .......* <me>, N time.
    //! if N = 0 <me> = Identity
    //! if N < 0 <me> = <me>.Inverse() *...........* <me>.Inverse().
    //!
    //! Raises if N < 0 and if the matrix of the transformation not
    //! inversible.
    xgp_Trsf^ xgp_Trsf::Powered(Standard_Integer N) {
        return gcnew xgp_Trsf(NativeHandle->Powered(N));
    };

    void xgp_Trsf::Transforms(Standard_Real X, Standard_Real Y, Standard_Real Z) {
        NativeHandle->Transforms(gp_XYZ (X, Y, Z));
    };

    //! Transformation of a triplet XYZ with a Trsf
    void xgp_Trsf::Transforms(xgp_XYZ^ Coord) {
        NativeHandle->Transforms(*Coord->GetXYZ());
    };

    ////! Convert transformation to 4x4 matrix.
    //template<class T>
    //void xgp_Trsf::GetMat4(NCollection_Mat4<T> theMat) {
    //    if (shape == gp_Identity) {
    //        theMat.InitIdentity();
    //        return;
    //    }

    //    theMat.SetValue(0, 0, static_cast<T> (Value(1, 1)));
    //    theMat.SetValue(0, 1, static_cast<T> (Value(1, 2)));
    //    theMat.SetValue(0, 2, static_cast<T> (Value(1, 3)));
    //    theMat.SetValue(0, 3, static_cast<T> (Value(1, 4)));
    //    theMat.SetValue(1, 0, static_cast<T> (Value(2, 1)));
    //    theMat.SetValue(1, 1, static_cast<T> (Value(2, 2)));
    //    theMat.SetValue(1, 2, static_cast<T> (Value(2, 3)));
    //    theMat.SetValue(1, 3, static_cast<T> (Value(2, 4)));
    //    theMat.SetValue(2, 0, static_cast<T> (Value(3, 1)));
    //    theMat.SetValue(2, 1, static_cast<T> (Value(3, 2)));
    //    theMat.SetValue(2, 2, static_cast<T> (Value(3, 3)));
    //    theMat.SetValue(2, 3, static_cast<T> (Value(3, 4)));
    //    theMat.SetValue(3, 0, static_cast<T> (0));
    //    theMat.SetValue(3, 1, static_cast<T> (0));
    //    theMat.SetValue(3, 2, static_cast<T> (0));
    //    theMat.SetValue(3, 3, static_cast<T> (1));
    //}

    //! Dumps the content of me into the stream
    void xgp_Trsf::DumpJson(Standard_OStream theOStream, Standard_Integer theDepth) {
        NativeHandle->DumpJson(theOStream, theDepth);
    };
};
