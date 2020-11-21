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
//! Describes an ellipse in the plane (2D space).
//! An ellipse is defined by its major and minor radii and
//! positioned in the plane with a coordinate system (a
//! xgp_Ax22d object) as follows:
//! -   the origin of the coordinate system is the center of the ellipse,
//! -   its "X Direction" defines the major axis of the ellipse, and
//! -   its "Y Direction" defines the minor axis of the ellipse.
//! This coordinate system is the "local coordinate system"
//! of the ellipse. Its orientation (direct or indirect) gives an
//! implicit orientation to the ellipse. In this coordinate
//! system, the equation of the ellipse is:
//! X*X / (MajorRadius**2) + Y*Y / (MinorRadius**2) = 1.0
//! See Also
//! gce_MakeElips2d which provides functions for more
//! complex ellipse constructions
//! Geom2d_Ellipse which provides additional functions for
//! constructing ellipses and works, in particular, with the
//! parametric equations of ellipses

#ifndef _xgp_Elips2d_HeaderFile
#define _xgp_Elips2d_HeaderFile
#pragma once
#include <gp_Elips2d.hxx>
#include "xgp_Ax2d.h"
#include "xgp_Ax22d.h"
#include "xgp_Pnt2d.h"
#include "xgp_Trsf2d.h"
#include "xgp_Vec2d.h"

namespace TKMath
{
    ref class xgp_Ax2d;
    ref class xgp_Ax22d;
    ref class xgp_Pnt2d;
    ref class xgp_Trsf2d;
    ref class xgp_Vec2d;
    public ref class xgp_Elips2d
    {
    public:

        //! Creates an indefinite ellipse.
        xgp_Elips2d(void);

        /// <summary>
        /// 指针映射点
        /// </summary>
        /// <param name="pos"></param>
        xgp_Elips2d(gp_Elips2d* pos);
        /// <summary>
        ///  映射点
        /// </summary>
        /// <param name="pos"></param>
        xgp_Elips2d(gp_Elips2d pos);

        //! Creates an ellipse with the major axis, the major and the
        //! minor radius. The location of the MajorAxis is the center
        //! of the  ellipse.
        //! The sense of parametrization is given by Sense.
        //! Warnings :
        //! It is possible to create an ellipse with
        //! MajorRadius = MinorRadius.
        //! Raises ConstructionError if MajorRadius < MinorRadius or MinorRadius < 0.0
        xgp_Elips2d(xgp_Ax2d^ MajorAxis, Standard_Real^ MajorRadius, Standard_Real^ MinorRadius, Standard_Boolean^ Sense);

        //! Creates an ellipse with radii MajorRadius and
        //! MinorRadius, positioned in the plane by coordinate system A where:
        //! -   the origin of A is the center of the ellipse,
        //! -   the "X Direction" of A defines the major axis of
        //! the ellipse, that is, the major radius MajorRadius
        //! is measured along this axis, and
        //! -   the "Y Direction" of A defines the minor axis of
        //! the ellipse, that is, the minor radius MinorRadius
        //! is measured along this axis, and
        //! -   the orientation (direct or indirect sense) of A
        //! gives the orientation of the ellipse.
        //! Warnings :
        //! It is possible to create an ellipse with
        //! MajorRadius = MinorRadius.
        //! Raises ConstructionError if MajorRadius < MinorRadius or MinorRadius < 0.0
        xgp_Elips2d(xgp_Ax22d^ A, Standard_Real^ MajorRadius, Standard_Real^ MinorRadius);


        //释放
        ~xgp_Elips2d();
        //释放
        !xgp_Elips2d();

        //! gp_Elips2d
        gp_Elips2d GetElips2d();

        //! Modifies this ellipse, by redefining its local coordinate system so that
        //! -   its origin becomes P.
        void SetLocation(xgp_Pnt2d^ P);

        //! Changes the value of the major radius.
        //! Raises ConstructionError if MajorRadius < MinorRadius.
        void SetMajorRadius(Standard_Real^ MajorRadius);

        //! Changes the value of the minor radius.
        //! Raises ConstructionError if MajorRadius < MinorRadius or MinorRadius < 0.0
        void SetMinorRadius(Standard_Real^ MinorRadius);

        //! Modifies this ellipse, by redefining its local coordinate system so that
        //! it becomes A.
        void SetAxis(xgp_Ax22d^ A);

        //! Modifies this ellipse, by redefining its local coordinate system so that
        //! its origin and its "X Direction"  become those
        //! of the axis A. The "Y  Direction"  is then
        //! recomputed. The orientation of the local coordinate
        //! system is not modified.
        void SetXAxis(xgp_Ax2d^ A);

        //! Modifies this ellipse, by redefining its local coordinate system so that
        //! its origin and its "Y Direction"  become those
        //! of the axis A. The "X  Direction"  is then
        //! recomputed. The orientation of the local coordinate
        //! system is not modified.
        void SetYAxis(xgp_Ax2d^ A);

        //! Computes the area of the ellipse.
        Standard_Real^ Area();


        //! Returns the coefficients of the implicit equation of the ellipse.
        //! A * (X**2) + B * (Y**2) + 2*C*(X*Y) + 2*D*X + 2*E*Y + F = 0.
        void Coefficients(Standard_Real A, Standard_Real B, Standard_Real C, Standard_Real D, Standard_Real E, Standard_Real F);


        //! This directrix is the line normal to the XAxis of the ellipse
        //! in the local plane (Z = 0) at a distance d = MajorRadius / e
        //! from the center of the ellipse, where e is the eccentricity of
        //! the ellipse.
        //! This line is parallel to the "YAxis". The intersection point
        //! between directrix1 and the "XAxis" is the location point of the
        //! directrix1. This point is on the positive side of the "XAxis".
        //!
        //! Raised if Eccentricity = 0.0. (The ellipse degenerates into a
        //! circle)
        xgp_Ax2d^ Directrix1();


        //! This line is obtained by the symmetrical transformation
        //! of "Directrix1" with respect to the minor axis of the ellipse.
        //!
        //! Raised if Eccentricity = 0.0. (The ellipse degenerates into a
        //! circle).
        xgp_Ax2d^ Directrix2();


        //! Returns the eccentricity of the ellipse  between 0.0 and 1.0
        //! If f is the distance between the center of the ellipse and
        //! the Focus1 then the eccentricity e = f / MajorRadius.
        //! Returns 0 if MajorRadius = 0.
        Standard_Real^ Eccentricity();


        //! Returns the distance between the center of the ellipse
        //! and focus1 or focus2.
        Standard_Real^ Focal();


        //! Returns the first focus of the ellipse. This focus is on the
        //! positive side of the major axis of the ellipse.
        xgp_Pnt2d^ Focus1();


        //! Returns the second focus of the ellipse. This focus is on the
        //! negative side of the major axis of the ellipse.
        xgp_Pnt2d^ Focus2();

        //! Returns the center of the ellipse.
        xgp_Pnt2d^ Location();

        //! Returns the major radius of the Ellipse.
        Standard_Real^ MajorRadius();

        //! Returns the minor radius of the Ellipse.
        Standard_Real^ MinorRadius();


        //! Returns p = (1 - e * e) * MajorRadius where e is the eccentricity
        //! of the ellipse.
        //! Returns 0 if MajorRadius = 0
        Standard_Real^ Parameter();

        //! Returns the major axis of the ellipse.
        xgp_Ax22d^ Axis();

        //! Returns the major axis of the ellipse.
        xgp_Ax2d^ XAxis();

        //! Returns the minor axis of the ellipse.
        //! Reverses the direction of the circle.
        xgp_Ax2d^ YAxis();

        void Reverse();

        xgp_Elips2d^ Reversed();

        //! Returns true if the local coordinate system is direct
        //! and false in the other case.
        Standard_Boolean^ IsDirect();

        void Mirror(xgp_Pnt2d^ P);


        //! Performs the symmetrical transformation of a ellipse with respect
        //! to the point P which is the center of the symmetry
        xgp_Elips2d^ Mirrored(xgp_Pnt2d^ P);

        void Mirror(xgp_Ax2d^ A);


        //! Performs the symmetrical transformation of a ellipse with respect
        //! to an axis placement which is the axis of the symmetry.
        xgp_Elips2d^ Mirrored(xgp_Ax2d^ A);

        void Rotate(xgp_Pnt2d^ P, Standard_Real^ Ang);

        xgp_Elips2d^ Rotated(xgp_Pnt2d^ P, Standard_Real^ Ang);

        void Scale(xgp_Pnt2d^ P, Standard_Real^ S);


        //! Scales a ellipse. S is the scaling value.
        xgp_Elips2d^ Scaled(xgp_Pnt2d^ P, Standard_Real^ S);

        void Transform(xgp_Trsf2d^ T);


        //! Transforms an ellipse with the transformation T fromnamespace TKMath  {  public ref class Trsf2d.
        xgp_Elips2d^ Transformed(xgp_Trsf2d^ T);

        void Translate(xgp_Vec2d^ V);


        //! Translates a ellipse in the direction of the vector V.
        //! The magnitude of the translation is the vector's magnitude.
        xgp_Elips2d^ Translated(xgp_Vec2d^ V);

        void Translate(xgp_Pnt2d^ P1, xgp_Pnt2d^ P2);


        //! Translates a ellipse from the point P1 to the point P2.
        xgp_Elips2d^ Translated(xgp_Pnt2d^ P1, xgp_Pnt2d^ P2);

        /// <summary>
        /// 本地句柄
        /// </summary>
        property gp_Elips2d* Handle
        {
            gp_Elips2d* get() {
                return NativeHandle;
            }
        }

    private:
        gp_Elips2d* NativeHandle;
    };
}
#endif // _xgp_Elips2d_HeaderFile