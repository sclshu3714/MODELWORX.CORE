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
//! Describes an infinite cylindrical surface.
//! A cylinder is defined by its radius and positioned in space
//! with a coordinate system (a xgp_Ax3 object), the "main
//! Axis" of which is the axis of the cylinder. This coordinate
//! system is the "local coordinate system" of the cylinder.
//! Note: when a xgp_Cylinder cylinder is converted into a
//! Geom_CylindricalSurface cylinder, some implicit
//! properties of its local coordinate system are used explicitly:
//! -   its origin, "X Direction", "Y Direction" and "main
//! Direction" are used directly to define the parametric
//! directions on the cylinder and the origin of the parameters,
//! -   its implicit orientation (right-handed or left-handed)
//! gives an orientation (direct or indirect) to the
//! Geom_CylindricalSurface cylinder.
//! See Also
//! gce_MakeCylinder which provides functions for more
//! complex cylinder constructions
//! Geom_CylindricalSurface which provides additional
//! functions for constructing cylinders and works, in
//! particular, with the parametric equations of cylinders xgp_Ax3

#ifndef _xgp_Cylinder_HeaderFile
#define _xgp_Cylinder_HeaderFile
#pragma once
#include <gp_Cylinder.hxx>
#include "xgp_Ax1.h"
#include "xgp_Ax2.h"
#include "xgp_Ax3.h"
#include "xgp_Pnt.h"
#include "xgp_Trsf.h"
#include "xgp_Vec.h"

namespace TKMath
{
    ref class xgp_Ax1;
    ref class xgp_Ax2;
    ref class xgp_Ax3;
    ref class xgp_Pnt;
    ref class xgp_Trsf;
    ref class xgp_Vec;
    public ref class xgp_Cylinder
    {
    public:

        //! Creates a indefinite cylinder.
        xgp_Cylinder(void);

        /// <summary>
        /// 指针映射点
        /// </summary>
        /// <param name="pos"></param>
        xgp_Cylinder(gp_Cylinder* pos);
        /// <summary>
        ///  映射点
        /// </summary>
        /// <param name="pos"></param>
        xgp_Cylinder(gp_Cylinder pos);

        //! Creates a cylinder of radius Radius, whose axis is the "main
        //! Axis" of A3. A3 is the local coordinate system of the cylinder.   Raises ConstructionErrord if R < 0.0
        xgp_Cylinder(xgp_Ax3^ A3, Standard_Real^ Radius);

        //释放
        ~xgp_Cylinder();
        //释放
        !xgp_Cylinder();


        //! gp_Cylinder
        gp_Cylinder GetCylinder();

        //! Changes the symmetry axis of the cylinder. Raises ConstructionError if the direction of A1 is parallel to the "XDirection"
        //! of the coordinate system of the cylinder.
        void SetAxis(xgp_Ax1^ A1);

        //! Changes the location of the surface.
        void SetLocation(xgp_Pnt^ Loc);

        //! Change the local coordinate system of the surface.
        void SetPosition(xgp_Ax3^ A3);

        //! Modifies the radius of this cylinder.
        //! Exceptions
        //! Standard_ConstructionError if R is negative.
        void SetRadius(Standard_Real^ R);

        //! Reverses the   U   parametrization of   the cylinder
        //! reversing the YAxis.
        void UReverse();

        //! Reverses the   V   parametrization of   the  plane
        //! reversing the Axis.
        void VReverse();

        //! Returns true if the local coordinate system of this cylinder is right-handed.
        Standard_Boolean^ Direct();

        //! Returns the symmetry axis of the cylinder.
        xgp_Ax1^ Axis();


        //! Computes the coefficients of the implicit equation of the quadric
        //! in the absolute cartesian coordinate system :
        //! A1.X**2 + A2.Y**2 + A3.Z**2 + 2.(B1.X.Y + B2.X.Z + B3.Y.Z) +
        //! 2.(C1.X + C2.Y + C3.Z) + D = 0.0
        void Coefficients(Standard_Real A1, Standard_Real A2, Standard_Real A3, Standard_Real B1, Standard_Real B2, Standard_Real B3, Standard_Real C1, Standard_Real C2, Standard_Real C3, Standard_Real D);

        //! Returns the "Location" point of the cylinder.
        xgp_Pnt^ Location();


        //! Returns the local coordinate system of the cylinder.
        xgp_Ax3^ Position();

        //! Returns the radius of the cylinder.
        Standard_Real^ Radius();

        //! Returns the axis X of the cylinder.
        xgp_Ax1^ XAxis();

        //! Returns the axis Y of the cylinder.
        xgp_Ax1^ YAxis();

        void Mirror(xgp_Pnt^ P);


        //! Performs the symmetrical transformation of a cylinder
        //! with respect to the point P which is the center of the
        //! symmetry.
        xgp_Cylinder^ Mirrored(xgp_Pnt^ P);

        void Mirror(xgp_Ax1^ A1);


        //! Performs the symmetrical transformation of a cylinder with
        //! respect to an axis placement which is the axis of the
        //! symmetry.
        xgp_Cylinder^ Mirrored(xgp_Ax1^ A1);

        void Mirror(xgp_Ax2^ A2);


        //! Performs the symmetrical transformation of a cylinder with respect
        //! to a plane. The axis placement A2 locates the plane of the
        //! of the symmetry : (Location, XDirection, YDirection).
        xgp_Cylinder^ Mirrored(xgp_Ax2^ A2);

        void Rotate(xgp_Ax1^ A1, Standard_Real^ Ang);


        //! Rotates a cylinder. A1 is the axis of the rotation.
        //! Ang is the angular value of the rotation in radians.
        xgp_Cylinder^ Rotated(xgp_Ax1^ A1, Standard_Real^ Ang);

        void Scale(xgp_Pnt^ P, Standard_Real^ S);


        //! Scales a cylinder. S is the scaling value.
        //! The absolute value of S is used to scale the cylinder
        xgp_Cylinder^ Scaled(xgp_Pnt^ P, Standard_Real^ S);

        void Transform(xgp_Trsf^ T);


        //! Transforms a cylinder with the transformation T fromnamespace TKMath  {  public ref class Trsf.
        xgp_Cylinder^ Transformed(xgp_Trsf^ T);

        void Translate(xgp_Vec^ V);


        //! Translates a cylinder in the direction of the vector V.
        //! The magnitude of the translation is the vector's magnitude.
        xgp_Cylinder^ Translated(xgp_Vec^ V);

        void Translate(xgp_Pnt^ P1, xgp_Pnt^ P2);


        //! Translates a cylinder from the point P1 to the point P2.
        xgp_Cylinder^ Translated(xgp_Pnt^ P1, xgp_Pnt^ P2);

        /// <summary>
        /// 本地句柄
        /// </summary>
        property gp_Cylinder* Handle
        {
            gp_Cylinder* get() {
                return NativeHandle;
            }
        }

    private:
        gp_Cylinder* NativeHandle;
    };
}
#endif // _xgp_Cylinder_HeaderFile