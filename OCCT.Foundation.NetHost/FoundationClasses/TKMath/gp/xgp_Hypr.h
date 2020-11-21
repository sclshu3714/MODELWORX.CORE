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
//! Describes a branch of a hyperbola in 3D space.
//! A hyperbola is defined by its major and minor radii and
//! positioned in space with a coordinate system (a xgp_Ax2
//! object) of which:
//! -   the origin is the center of the hyperbola,
//! -   the "X Direction" defines the major axis of the
//! hyperbola, and
//! - the "Y Direction" defines the minor axis of the hyperbola.
//! The origin, "X Direction" and "Y Direction" of this
//! coordinate system together define the plane of the
//! hyperbola. This coordinate system is the "local
//! coordinate system" of the hyperbola. In this coordinate
//! system, the equation of the hyperbola is:
//! X*X/(MajorRadius**2)-Y*Y/(MinorRadius**2) = 1.0
//! The branch of the hyperbola described is the one located
//! on the positive side of the major axis.
//! The "main Direction" of the local coordinate system is a
//! normal vector to the plane of the hyperbola. This vector
//! gives an implicit orientation to the hyperbola. We refer to
//! the "main Axis" of the local coordinate system as the
//! "Axis" of the hyperbola.
//! The following schema shows the plane of the hyperbola,
//! and in it, the respective positions of the three branches of
//! hyperbolas constructed with the functions OtherBranch,
//! ConjugateBranch1, and ConjugateBranch2:
//!
//! ^YAxis
//! |
//! FirstConjugateBranch
//! |
//! Other            |                Main
//! --------------------- C ------------------------------>XAxis
//! Branch           |                Branch
//! |
//! |
//! SecondConjugateBranch
//! |                  ^YAxis
//! Warning
//! The major radius can be less than the minor radius.
//! See Also
//! gce_MakeHypr which provides functions for more
//! complex hyperbola constructions
//! Geom_Hyperbola which provides additional functions for
//! constructing hyperbolas and works, in particular, with the
//! parametric equations of hyperbolas


#ifndef _xgp_Hypr_HeaderFile
#define _xgp_Hypr_HeaderFile
#pragma once
#include <gp_Hypr.hxx>
#include "xgp_Ax1.h"
#include "xgp_Ax2.h"
#include "xgp_Pnt.h"
#include "xgp_Trsf.h"
#include "xgp_Vec.h"

namespace TKMath
{
    ref class xgp_Ax1;
    ref class xgp_Ax2;
    ref class xgp_Pnt;
    ref class xgp_Trsf;
    ref class xgp_Vec;

    public ref class xgp_Hypr
    {
    public:

        //! Creates of an indefinite hyperbola.
        xgp_Hypr();

        /// <summary>
        /// 指针映射点
        /// </summary>
        /// <param name="pos"></param>
        xgp_Hypr(gp_Hypr* pos);
        /// <summary>
        ///  映射点
        /// </summary>
        /// <param name="pos"></param>
        xgp_Hypr(gp_Hypr pos);

        //! Creates a hyperbola with radii MajorRadius and
        //! MinorRadius, positioned in the space by the
        //! coordinate system A2 such that:
        //! -   the origin of A2 is the center of the hyperbola,
        //! -   the "X Direction" of A2 defines the major axis of
        //! the hyperbola, that is, the major radius
        //! MajorRadius is measured along this axis, and
        //! -   the "Y Direction" of A2 defines the minor axis of
        //! the hyperbola, that is, the minor radius
        //! MinorRadius is measured along this axis.
        //! Note: Thisnamespace TKMath  {  public ref class does not prevent the creation of a
        //! hyperbola where:
        //! -   MajorAxis is equal to MinorAxis, or
        //! -   MajorAxis is less than MinorAxis.
        //! Exceptions
        //! Standard_ConstructionError if MajorAxis or MinorAxis is negative.
        //! Raises ConstructionError if MajorRadius < 0.0 or MinorRadius < 0.0
        //! Raised if MajorRadius < 0.0 or MinorRadius < 0.0
        xgp_Hypr(xgp_Ax2^ A2, Standard_Real^ MajorRadius, Standard_Real^ MinorRadius);


        //释放
        ~xgp_Hypr();
        //释放
        !xgp_Hypr();

        //! gp_Hypr
        gp_Hypr GetHypr();

        //! Modifies this hyperbola, by redefining its local coordinate
        //! system so that:
        //! -   its origin and "main Direction" become those of the
        //! axis A1 (the "X Direction" and "Y Direction" are then
        //! recomputed in the same way as for any xgp_Ax2).
        //! Raises ConstructionError if the direction of A1 is parallel to the direction of
        //! the "XAxis" of the hyperbola.
        void SetAxis(xgp_Ax1^ A1);

        //! Modifies this hyperbola, by redefining its local coordinate
        //! system so that its origin becomes P.
        void SetLocation(xgp_Pnt^ P);


        //! Modifies the major  radius of this hyperbola.
        //! Exceptions
        //! Standard_ConstructionError if MajorRadius is negative.
        void SetMajorRadius(Standard_Real^ MajorRadius);


        //! Modifies the minor  radius of this hyperbola.
        //! Exceptions
        //! Standard_ConstructionError if MinorRadius is negative.
        void SetMinorRadius(Standard_Real^ MinorRadius);

        //! Modifies this hyperbola, by redefining its local coordinate
        //! system so that it becomes A2.
        void SetPosition(xgp_Ax2^ A2);


        //! In the local coordinate system of the hyperbola the equation of
        //! the hyperbola is (X*X)/(A*A) - (Y*Y)/(B*B) = 1.0 and the
        //! equation of the first asymptote is Y = (B/A)*X
        //! where A is the major radius and B is the minor radius. Raises ConstructionError if MajorRadius = 0.0
        xgp_Ax1^ Asymptote1();


        //! In the local coordinate system of the hyperbola the equation of
        //! the hyperbola is (X*X)/(A*A) - (Y*Y)/(B*B) = 1.0 and the
        //! equation of the first asymptote is Y = -(B/A)*X.
        //! where A is the major radius and B is the minor radius. Raises ConstructionError if MajorRadius = 0.0
        xgp_Ax1^ Asymptote2();

        //! Returns the axis passing through the center,
        //! and normal to the plane of this hyperbola.
        xgp_Ax1^ Axis();


        //! Computes the branch of hyperbola which is on the positive side of the
        //! "YAxis" of <me>.
        xgp_Hypr^ ConjugateBranch1();


        //! Computes the branch of hyperbola which is on the negative side of the
        //! "YAxis" of <me>.
        xgp_Hypr^ ConjugateBranch2();


        //! This directrix is the line normal to the XAxis of the hyperbola
        //! in the local plane (Z = 0) at a distance d = MajorRadius / e
        //! from the center of the hyperbola, where e is the eccentricity of
        //! the hyperbola.
        //! This line is parallel to the "YAxis". The intersection point
        //! between the directrix1 and the "XAxis" is the "Location" point
        //! of the directrix1. This point is on the positive side of the
        //! "XAxis".
        xgp_Ax1^ Directrix1();


        //! This line is obtained by the symmetrical transformation
        //! of "Directrix1" with respect to the "YAxis" of the hyperbola.
        xgp_Ax1^ Directrix2();


        //! Returns the excentricity of the hyperbola (e > 1).
        //! If f is the distance between the location of the hyperbola
        //! and the Focus1 then the eccentricity e = f / MajorRadius. Raises DomainError if MajorRadius = 0.0
        Standard_Real^ Eccentricity();


        //! Computes the focal distance. It is the distance between the
        //! the two focus of the hyperbola.
        Standard_Real^ Focal();


        //! Returns the first focus of the hyperbola. This focus is on the
        //! positive side of the "XAxis" of the hyperbola.
        xgp_Pnt^ Focus1();


        //! Returns the second focus of the hyperbola. This focus is on the
        //! negative side of the "XAxis" of the hyperbola.
        xgp_Pnt^ Focus2();


        //! Returns  the location point of the hyperbola. It is the
        //! intersection point between the "XAxis" and the "YAxis".
        xgp_Pnt^ Location();


        //! Returns the major radius of the hyperbola. It is the radius
        //! on the "XAxis" of the hyperbola.
        Standard_Real^ MajorRadius();


        //! Returns the minor radius of the hyperbola. It is the radius
        //! on the "YAxis" of the hyperbola.
        Standard_Real^ MinorRadius();


        //! Returns the branch of hyperbola obtained by doing the
        //! symmetrical transformation of <me> with respect to the
        //! "YAxis"  of <me>.
        xgp_Hypr^ OtherBranch();


        //! Returns p = (e * e - 1) * MajorRadius where e is the
        //! eccentricity of the hyperbola.
        //! Raises DomainError if MajorRadius = 0.0
        Standard_Real^ Parameter();

        //! Returns the coordinate system of the hyperbola.
        xgp_Ax2^ Position();

        //! Computes an axis, whose
        //! -   the origin is the center of this hyperbola, and
        //! -   the unit vector is the "X Direction"
        //! of the local coordinate system of this hyperbola.
        //! These axes are, the major axis (the "X
        //! Axis") and  of this hyperboReturns the "XAxis" of the hyperbola.
        xgp_Ax1^ XAxis();

        //! Computes an axis, whose
        //! -   the origin is the center of this hyperbola, and
        //! -   the unit vector is the "Y Direction"
        //! of the local coordinate system of this hyperbola.
        //! These axes are the minor axis (the "Y Axis") of this hyperbola
        xgp_Ax1^ YAxis();

        void Mirror(xgp_Pnt^ P);


        //! Performs the symmetrical transformation of an hyperbola with
        //! respect  to the point P which is the center of the symmetry.
        xgp_Hypr^ Mirrored(xgp_Pnt^ P);

        void Mirror(xgp_Ax1^ A1);


        //! Performs the symmetrical transformation of an hyperbola with
        //! respect to an axis placement which is the axis of the symmetry.
        xgp_Hypr^ Mirrored(xgp_Ax1^ A1);

        void Mirror(xgp_Ax2^ A2);


        //! Performs the symmetrical transformation of an hyperbola with
        //! respect to a plane. The axis placement A2 locates the plane
        //! of the symmetry (Location, XDirection, YDirection).
        xgp_Hypr^ Mirrored(xgp_Ax2^ A2);

        void Rotate(xgp_Ax1^ A1, Standard_Real^ Ang);


        //! Rotates an hyperbola. A1 is the axis of the rotation.
        //! Ang is the angular value of the rotation in radians.
        xgp_Hypr^ Rotated(xgp_Ax1^ A1, Standard_Real^ Ang);

        void Scale(xgp_Pnt^ P, Standard_Real^ S);


        //! Scales an hyperbola. S is the scaling value.
        xgp_Hypr^ Scaled(xgp_Pnt^ P, Standard_Real^ S);

        void Transform(xgp_Trsf^ T);


        //! Transforms an hyperbola with the transformation T from
        //!namespace TKMath  {  public ref class Trsf.
        xgp_Hypr^ Transformed(xgp_Trsf^ T);

        void Translate(xgp_Vec^ V);


        //! Translates an hyperbola in the direction of the vector V.
        //! The magnitude of the translation is the vector's magnitude.
        xgp_Hypr^ Translated(xgp_Vec^ V);

        void Translate(xgp_Pnt^ P1, xgp_Pnt^ P2);


        //! Translates an hyperbola from the point P1 to the point P2.
        xgp_Hypr^ Translated(xgp_Pnt^ P1, xgp_Pnt^ P2);

        /// <summary>
        /// 本地句柄
        /// </summary>
        property gp_Hypr* Handle
        {
            gp_Hypr* get() {
                return NativeHandle;
            }
        }

    private:
        gp_Hypr* NativeHandle;
        Standard_Real majorRadius;
        Standard_Real minorRadius;
    };
} 
#endif // _xgp_Hypr_HeaderFile