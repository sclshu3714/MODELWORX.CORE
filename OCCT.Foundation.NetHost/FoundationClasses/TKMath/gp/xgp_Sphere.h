// Copyright (c) 1991-1999 Matra Datavision
// Copyright (c) 1999-2014 OPEN CASCADE SAS
//
// This file is part of Open CASCADE Technology software library.
//
// This library is free software; you can redistribute it and/or modify it under
// the terms of the GNU Lesser General Public License version 2.1 as published
// by the Free Software Foundation, with special exception defined in the file
// OCCT_LGPL_EXCEPTION.txt. Consult the file LICENSE_LGPL_21.txt included in OCCT
// distribution for complete text of the license and disclaimer of any warranty.
//
// Alternatively, this file may be used under the terms of Open CASCADE
// commercial license or contractual agreement.
//! Describes a sphere.
//! A sphere is defined by its radius and positioned in space
//! with a coordinate system (a xgp_Ax3 object). The origin of
//! the coordinate system is the center of the sphere. This
//! coordinate system is the "local coordinate system" of the sphere.
//! Note: when a xgp_Sphere sphere is converted into a
//! Geom_SphericalSurface sphere, some implicit
//! properties of its local coordinate system are used explicitly:
//! -   its origin, "X Direction", "Y Direction" and "main
//! Direction" are used directly to define the parametric
//! directions on the sphere and the origin of the parameters,
//! -   its implicit orientation (right-handed or left-handed)
//! gives the orientation (direct, indirect) to the
//! Geom_SphericalSurface sphere.
//! See Also
//! gce_MakeSphere which provides functions for more
//! complex sphere constructions
//! Geom_SphericalSurface which provides additional
//! functions for constructing spheres and works, in
//! particular, with the parametric equations of spheres.
#pragma once
#include <gp_Sphere.hxx>
#include "xgp_Pnt.h"
#include "xgp_Ax1.h"
#include "xgp_Ax2.h"
#include "xgp_Ax3.h"
#include "xgp_Dir.h"
#include "xgp_Trsf.h"
#include "xgp_Vec.h"

namespace TKMath
{
    ref class xgp_Pnt;
    ref class xgp_Dir;
    ref class xgp_Ax1;
    ref class xgp_Ax2;
    ref class xgp_Ax3;
    ref class xgp_Vec;
    ref class xgp_Trsf;
    public ref class xgp_Sphere
    {
    public:
        //! Creates an indefinite sphere.
        xgp_Sphere(void);

        /// <summary>
        /// 指针映射点
        /// </summary>
        /// <param name="pos"></param>
        xgp_Sphere(gp_Sphere* pos);
        /// <summary>
        ///  映射点
        /// </summary>
        /// <param name="pos"></param>
        xgp_Sphere(gp_Sphere pos);

        //! Constructs a sphere with radius Radius, centered on the origin
        //! of A3.  A3 is the local coordinate system of the sphere.
        //! Warnings :
        //! It is not forbidden to create a sphere with null radius.
        //! Raises ConstructionError if Radius < 0.0
        xgp_Sphere(xgp_Ax3^ A3, Standard_Real^ Radius);

        //释放
        ~xgp_Sphere();
        //释放
        !xgp_Sphere();


        //! gp_Sphere
        gp_Sphere GetSphere();

        //! Changes the center of the sphere.
        void SetLocation(xgp_Pnt^ Loc);

        //! Changes the local coordinate system of the sphere.
        void SetPosition(xgp_Ax3^ A3);

        //! Assigns R the radius of the Sphere.
        //! Warnings :
        //! It is not forbidden to create a sphere with null radius.
        //! Raises ConstructionError if R < 0.0
        void SetRadius(Standard_Real^ R);


        //! Computes the aera of the sphere.
        Standard_Real^ Area();


        //! Computes the coefficients of the implicit equation of the quadric
        //! in the absolute cartesian coordinates system :
        //! A1.X**2 + A2.Y**2 + A3.Z**2 + 2.(B1.X.Y + B2.X.Z + B3.Y.Z) +
        //! 2.(C1.X + C2.Y + C3.Z) + D = 0.0
        void Coefficients(Standard_Real A1, Standard_Real A2, Standard_Real A3, Standard_Real B1, Standard_Real B2, Standard_Real B3, Standard_Real C1, Standard_Real C2, Standard_Real C3, Standard_Real D);

        //! Reverses the   U   parametrization of   the sphere
        //! reversing the YAxis.
        void UReverse();

        //! Reverses the   V   parametrization of   the  sphere
        //! reversing the ZAxis.
        void VReverse();

        //! Returns true if the local coordinate system of this sphere
        //! is right-handed.
        Standard_Boolean^ Direct();

        //! --- Purpose ;
        //! Returns the center of the sphere.
        xgp_Pnt^ Location();


        //! Returns the local coordinates system of the sphere.
        xgp_Ax3^ Position();

        //! Returns the radius of the sphere.
        Standard_Real^ Radius();

        //! Computes the volume of the sphere
        Standard_Real^ Volume();

        //! Returns the axis X of the sphere.
        xgp_Ax1^ XAxis();

        //! Returns the axis Y of the sphere.
        xgp_Ax1^ YAxis();

        void Mirror(xgp_Pnt^ P);


        //! Performs the symmetrical transformation of a sphere
        //! with respect to the point P which is the center of the
        //! symmetry.
        xgp_Sphere^ Mirrored(xgp_Pnt^ P);

        void Mirror(xgp_Ax1^ A1);


        //! Performs the symmetrical transformation of a sphere with
        //! respect to an axis placement which is the axis of the
        //! symmetry.
        xgp_Sphere^ Mirrored(xgp_Ax1^ A1);

        void Mirror(xgp_Ax2^ A2);


        //! Performs the symmetrical transformation of a sphere with respect
        //! to a plane. The axis placement A2 locates the plane of the
        //! of the symmetry : (Location, XDirection, YDirection).
        xgp_Sphere^ Mirrored(xgp_Ax2^ A2);

        void Rotate(xgp_Ax1^ A1, Standard_Real^ Ang);


        //! Rotates a sphere. A1 is the axis of the rotation.
        //! Ang is the angular value of the rotation in radians.
        xgp_Sphere^ Rotated(xgp_Ax1^ A1, Standard_Real^ Ang);

        void Scale(xgp_Pnt^ P, Standard_Real^ S);


        //! Scales a sphere. S is the scaling value.
        //! The absolute value of S is used to scale the sphere
        xgp_Sphere^ Scaled(xgp_Pnt^ P, Standard_Real^ S);

        void Transform(xgp_Trsf^ T);


        //! Transforms a sphere with the transformation T fromnamespace TKMath  {  public ref class Trsf.
        xgp_Sphere^ Transformed(xgp_Trsf^ T);

        void Translate(xgp_Vec^ V);


        //! Translates a sphere in the direction of the vector V.
        //! The magnitude of the translation is the vector's magnitude.
        xgp_Sphere^ Translated(xgp_Vec^ V);

        void Translate(xgp_Pnt^ P1, xgp_Pnt^ P2);


        //! Translates a sphere from the point P1 to the point P2.
        xgp_Sphere^ Translated(xgp_Pnt^ P1, xgp_Pnt^ P2);

        /// <summary>
        /// 本地句柄
        /// </summary>
        property gp_Sphere* Handle
        {
            gp_Sphere* get() {
                return NativeHandle;
            }
        }

    private:
        gp_Sphere* NativeHandle;
    };
};
