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
//! Describes a plane.
//! A plane is positioned in space with a coordinate system
//! (a xgp_Ax3 object), such that the plane is defined by the
//! origin, "X Direction" and "Y Direction" of this coordinate
//! system, which is the "local coordinate system" of the
//! plane. The "main Direction" of the coordinate system is a
//! vector normal to the plane. It gives the plane an implicit
//! orientation such that the plane is said to be "direct", if the
//! coordinate system is right-handed, or "indirect" in the other case.
//! Note: when a xgp_Pln plane is converted into a
//! Geom_Plane plane, some implicit properties of its local
//! coordinate system are used explicitly:
//! -   its origin defines the origin of the two parameters of
//! the planar surface,
//! -   its implicit orientation is also that of the Geom_Plane.
//! See Also
//! gce_MakePln which provides functions for more complex
//! plane constructions
//! Geom_Plane which provides additional functions for
//! constructing planes and works, in particular, with the
//! parametric equations of planes

#ifndef _xgp_Pln_HeaderFile
#define _xgp_Pln_HeaderFile
#pragma once
#include <gp_Pln.hxx>
#include "xgp_Ax1.h"
#include "xgp_Ax2.h"
#include "xgp_Ax3.h"
#include "xgp_Pnt.h"
#include "xgp_Dir.h"
#include "xgp_Lin.h"
#include "xgp_Trsf.h"
#include "xgp_Vec.h"


namespace TKMath
{
    ref class xgp_Ax1;
    ref class xgp_Ax2;
    ref class xgp_Ax3;
    ref class xgp_Pnt;
    ref class xgp_Dir;
    ref class xgp_Lin;
    ref class xgp_Trsf;
    ref class xgp_Vec;
    public ref class xgp_Pln
    {
    public:
        //! Creates a plane coincident with OXY plane of the
        //! reference coordinate system.
        xgp_Pln(void);
       
        /// <summary>
        /// 指针映射点
        /// </summary>
        /// <param name="pos"></param>
        xgp_Pln(gp_Pln* pos);
        /// <summary>
        ///  映射点
        /// </summary>
        /// <param name="pos"></param>
        xgp_Pln(gp_Pln pos);
        //! The coordinate system of the plane is defined with the axis
        //! placement A3.
        //! The "Direction" of A3 defines the normal to the plane.
        //! The "Location" of A3 defines the location (origin) of the plane.
        //! The "XDirection" and "YDirection" of A3 define the "XAxis" and
        //! the "YAxis" of the plane used to parametrize the plane.
        xgp_Pln(xgp_Ax3^ A3);


        //! Creates a plane with the  "Location" point <P>
        //! and the normal direction <V>.
        xgp_Pln(xgp_Pnt^ P, xgp_Dir^ V);


        //! Creates a plane from its cartesian equation :
        //! A * X + B * Y + C * Z + D = 0.0
        //! Raises ConstructionError if Sqrt (A*A + B*B + C*C) <= Resolution from gp.
        xgp_Pln(Standard_Real^ A, Standard_Real^ B, Standard_Real^ C, Standard_Real^ D);

        //! 释放
        ~xgp_Pln();

        //! 释放
        !xgp_Pln();

        //! gp_Pln
        gp_Pln GetPln();

        //! Returns the coefficients of the plane's cartesian equation :
        //! A * X + B * Y + C * Z + D = 0.
        void Coefficients(Standard_Real A, Standard_Real B, Standard_Real C, Standard_Real D);

        //! Modifies this plane, by redefining its local coordinate system so that
        //! -   its origin and "main Direction" become those of the
        //! axis A1 (the "X Direction" and "Y Direction" are then recomputed).
        //! Raises ConstructionError if the A1 is parallel to the "XAxis" of the plane.
        void SetAxis(xgp_Ax1^ A1);

        //! Changes the origin of the plane.
        void SetLocation(xgp_Pnt^ Loc);

        //! Changes the local coordinate system of the plane.
        void SetPosition(xgp_Ax3^ A3);

        //! Reverses the   U   parametrization of   the  plane
        //! reversing the XAxis.
        void UReverse();

        //! Reverses the   V   parametrization of   the  plane
        //! reversing the YAxis.
        void VReverse();

        //! returns true if the Ax3 is right handed.
        Standard_Boolean^ Direct();

        //! Returns the plane's normal Axis.
        xgp_Ax1^ Axis();

        //! Returns the plane's location (origin).
        xgp_Pnt^ Location();

        //! Returns the local coordinate system of the plane .
        xgp_Ax3^ Position();

        //! Computes the distance between <me> and the point <P>.
        Standard_Real^ Distance(xgp_Pnt^ P);

        //! Computes the distance between <me> and the line <L>.
        Standard_Real^ Distance(xgp_Lin^ L);

        //! Computes the distance between two planes.
        Standard_Real^ Distance(xgp_Pln^ Other);


        //! Computes the square distance between <me> and the point <P>.
        Standard_Real^ SquareDistance(xgp_Pnt^ P);


        //! Computes the square distance between <me> and the line <L>.
        Standard_Real^ SquareDistance(xgp_Lin^ L);


        //! Computes the square distance between two planes.
        Standard_Real^ SquareDistance(xgp_Pln^ Other);

        //! Returns the X axis of the plane.
        xgp_Ax1^ XAxis();

        //! Returns the Y axis  of the plane.
        xgp_Ax1^ YAxis();

        //! Returns true if this plane contains the point P. This means that
        //! -   the distance between point P and this plane is less
        //! than or equal to LinearTolerance, or
        //! -   line L is normal to the "main Axis" of the local
        //! coordinate system of this plane, within the tolerance
        //! AngularTolerance, and the distance between the origin
        //! of line L and this plane is less than or equal to
        //! LinearTolerance.
        Standard_Boolean^ Contains(xgp_Pnt^ P, Standard_Real^ LinearTolerance);

        //! Returns true if this plane contains the line L. This means that
        //! -   the distance between point P and this plane is less
        //! than or equal to LinearTolerance, or
        //! -   line L is normal to the "main Axis" of the local
        //! coordinate system of this plane, within the tolerance
        //! AngularTolerance, and the distance between the origin
        //! of line L and this plane is less than or equal to
        //! LinearTolerance.
        Standard_Boolean^ Contains(xgp_Lin^ L, Standard_Real^ LinearTolerance, Standard_Real^ AngularTolerance);

        void Mirror(xgp_Pnt^ P);


        //! Performs the symmetrical transformation of a plane with respect
        //! to the point <P> which is the center of the symmetry
        //! Warnings :
        //! The normal direction to the plane is not changed.
        //! The "XAxis" and the "YAxis" are reversed.
        xgp_Pln^ Mirrored(xgp_Pnt^ P);

        void Mirror(xgp_Ax1^ A1);

        //! Performs   the symmetrical transformation  of a
        //! plane with respect to an axis placement  which is the axis
        //! of  the symmetry.  The  transformation is performed on the
        //! "Location" point, on  the "XAxis"  and the "YAxis".    The
        //! resulting normal  direction  is  the cross product between
        //! the "XDirection" and the "YDirection" after transformation
        //! if  the  initial plane was right  handed,  else  it is the
        //! opposite.
        xgp_Pln^ Mirrored(xgp_Ax1^ A1);

        void Mirror(xgp_Ax2^ A2);

        //! Performs the  symmetrical transformation  of  a
        //! plane    with respect to    an axis  placement.   The axis
        //! placement  <A2> locates the plane  of  the symmetry.   The
        //! transformation is performed  on  the  "Location" point, on
        //! the  "XAxis" and  the    "YAxis".  The resulting    normal
        //! direction is the cross  product between   the "XDirection"
        //! and the "YDirection"  after  transformation if the initial
        //! plane was right handed, else it is the opposite.
        xgp_Pln^ Mirrored(xgp_Ax2^ A2);

        void Rotate(xgp_Ax1^ A1, Standard_Real^ Ang);


        //! rotates a plane. A1 is the axis of the rotation.
        //! Ang is the angular value of the rotation in radians.
        xgp_Pln^ Rotated(xgp_Ax1^ A1, Standard_Real^ Ang);

        void Scale(xgp_Pnt^ P, Standard_Real^ S);


        //! Scales a plane. S is the scaling value.
        xgp_Pln^ Scaled(xgp_Pnt^ P, Standard_Real^ S);

        void Transform(xgp_Trsf^ T);


        //! Transforms a plane with the transformation T fromnamespace TKMath  {  public ref class Trsf.
        //! The transformation is performed on the "Location"
        //! point, on the "XAxis" and the "YAxis".
        //! The resulting normal direction is the cross product between
        //! the "XDirection" and the "YDirection" after transformation.
        xgp_Pln^ Transformed(xgp_Trsf^ T);

        void Translate(xgp_Vec^ V);


        //! Translates a plane in the direction of the vector V.
        //! The magnitude of the translation is the vector's magnitude.
        xgp_Pln^ Translated(xgp_Vec^ V);

        void Translate(xgp_Pnt^ P1, xgp_Pnt^ P2);


        //! Translates a plane from the point P1 to the point P2.
        xgp_Pln^ Translated(xgp_Pnt^ P1, xgp_Pnt^ P2);

        /// <summary>
        /// 本地句柄
        /// </summary>
        property gp_Pln* Handle
        {
            gp_Pln* get() {
                return NativeHandle;
            }
        };

    private:
        gp_Pln* NativeHandle;
    };
}
#endif // _xgp_Pln_HeaderFile