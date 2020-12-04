
#ifndef _xgp_Ax1_HeaderFile
#define _xgp_Ax1_HeaderFile
#pragma once
#include "gp_Ax1.hxx"
#include "xgp_Pnt.h"
#include "xgp_Dir.h"
#include "xgp_Ax2.h"
#include "xgp_Vec.h"
#include "xgp_Trsf.h"

namespace TKMath
{
    ref class xgp_Pnt;
    ref class xgp_Dir;
    ref class xgp_Ax2;
    ref class xgp_Vec;
    ref class xgp_Trsf;
    public ref class xgp_Ax1
    {
    public:
        //! Creates an axis object representing Z axis of
        //! the reference co-ordinate system.
        xgp_Ax1(void);

        /// <summary>
        /// 指针映射点
        /// </summary>
        /// <param name="pos"></param>
        xgp_Ax1(gp_Ax1* pos);

        //! P is the location point and V is the direction of <me>.
        xgp_Ax1(gp_Pnt* P, gp_Dir* V);

        //! P is the location point and V is the direction of <me>.
        xgp_Ax1(xgp_Pnt^ P, xgp_Dir^ V);

        //释放
        ~xgp_Ax1();
        //释放
        !xgp_Ax1();

        //! 获取映射的gp_Ax1
        gp_Ax1* GetAx1();

        //! Assigns V as the "Direction"  of this axis.
        void SetDirection(xgp_Dir^ V);

        //! Assigns  P as the origin of this axis.
        void SetLocation(xgp_Pnt^ P);

        //! Returns the direction of <me>.
        xgp_Dir^ Direction();

        //! Returns the location point of <me>.
        xgp_Pnt^ Location();


        //! Returns True if  :
        //! . the angle between <me> and <Other> is lower or equal
        //! to <AngularTolerance> and
        //! . the distance between <me>.Location() and <Other> is lower
        //! or equal to <LinearTolerance> and
        //! . the distance between <Other>.Location() and <me> is lower
        //! or equal to LinearTolerance.
        Standard_Boolean IsCoaxial(xgp_Ax1^ Other, Standard_Real AngularTolerance, Standard_Real LinearTolerance);


        //! Returns True if the direction of the <me> and <Other>
        //! are normal to each other.
        //! That is, if the angle between the two axes is equal to Pi/2.
        //! Note: the tolerance criterion is given by AngularTolerance..
        Standard_Boolean IsNormal(xgp_Ax1^ Other, Standard_Real AngularTolerance);


        //! Returns True if the direction of <me> and <Other> are
        //! parallel with opposite orientation. That is, if the angle
        //! between the two axes is equal to Pi.
        //! Note: the tolerance criterion is given by AngularTolerance.
        Standard_Boolean IsOpposite(xgp_Ax1^ Other, Standard_Real AngularTolerance);


        //! Returns True if the direction of <me> and <Other> are
        //! parallel with same orientation or opposite orientation. That
        //! is, if the angle between the two axes is equal to 0 or Pi.
        //! Note: the tolerance criterion is given by
        //! AngularTolerance.
        Standard_Boolean IsParallel(xgp_Ax1^ Other, Standard_Real AngularTolerance);


        //! Computes the angular value, in radians, between <me>.Direction() and
        //! <Other>.Direction(). Returns the angle between 0 and 2*PI
        //! radians.
        Standard_Real Angle(xgp_Ax1^ Other);

        //! Reverses the unit vector of this axis.
        //! and  assigns the result to this axis.
        void Reverse();

        //! Reverses the unit vector of this axis and creates a new one.
        xgp_Ax1^ Reversed();


        //! Performs the symmetrical transformation of an axis
        //! placement with respect to the point P which is the
        //! center of the symmetry and assigns the result to this axis.
        void Mirror(xgp_Pnt^ P);

        //! Performs the symmetrical transformation of an axis
        //! placement with respect to the point P which is the
        //! center of the symmetry and creates a new axis.
        xgp_Ax1^ Mirrored(xgp_Pnt^ P);


        //! Performs the symmetrical transformation of an axis
        //! placement with respect to an axis placement which
        //! is the axis of the symmetry and assigns the result to this axis.
        void Mirror(xgp_Ax1^ A1);


        //! Performs the symmetrical transformation of an axis
        //! placement with respect to an axis placement which
        //! is the axis of the symmetry and creates a new axis.
        xgp_Ax1^ Mirrored(xgp_Ax1^ A1);


        //! Performs the symmetrical transformation of an axis
        //! placement with respect to a plane. The axis placement
        //! <A2> locates the plane of the symmetry :
        //! (Location, XDirection, YDirection) and assigns the result to this axis.
        void Mirror(xgp_Ax2^ A2);


        //! Performs the symmetrical transformation of an axis
        //! placement with respect to a plane. The axis placement
        //! <A2> locates the plane of the symmetry :
        //! (Location, XDirection, YDirection) and creates a new axis.
        xgp_Ax1^ Mirrored(xgp_Ax2^ A2);

        //! Rotates this axis at an angle Ang (in radians) about the axis A1
        //! and assigns the result to this axis.
        void Rotate(xgp_Ax1^ A1, Standard_Real Ang);

        //! Rotates this axis at an angle Ang (in radians) about the axis A1
        //! and creates a new one.
        xgp_Ax1^ Rotated(xgp_Ax1^ A1, Standard_Real Ang);


        //! Applies a scaling transformation to this axis with:
        //! -   scale factor S, and
        //! -   center P and assigns the result to this axis.
        void Scale(xgp_Pnt^ P, Standard_Real S);


        //! Applies a scaling transformation to this axis with:
        //! -   scale factor S, and
        //! -   center P and creates a new axis.
        xgp_Ax1^ Scaled(xgp_Pnt^ P, Standard_Real S);

        //! Applies the transformation T to this axis.
        //! and assigns the result to this axis.
        void Transform(xgp_Trsf^ T);


        //! Applies the transformation T to this axis and creates a new one.
        //!
        //! Translates an axis plaxement in the direction of the vector
        //! <V>. The magnitude of the translation is the vector's magnitude.
        xgp_Ax1^ Transformed(xgp_Trsf^ T);


        //! Translates this axis by the vector V,
        //! and assigns the result to this axis.
        void Translate(xgp_Vec^ V);


        //! Translates this axis by the vector V,
        //! and creates a new one.
        xgp_Ax1^ Translated(xgp_Vec^ V);


        //! Translates this axis by:
        //! the vector (P1, P2) defined from point P1 to point P2.
        //! and assigns the result to this axis.
        void Translate(xgp_Pnt^ P1, xgp_Pnt^ P2);


        //! Translates this axis by:
        //! the vector (P1, P2) defined from point P1 to point P2.
        //! and creates a new one.
        xgp_Ax1^ Translated(xgp_Pnt^ P1, xgp_Pnt^ P2);
        /// <summary>
        /// 本地句柄
        /// </summary>
        property gp_Ax1* Handle
        {
            gp_Ax1* get() {
                return NativeHandle;
            }
        }

    private:
        gp_Ax1* NativeHandle;
    };
}
#endif // _xgp_Ax1_HeaderFile