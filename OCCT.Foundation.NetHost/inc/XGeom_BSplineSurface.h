// Created on: 1993-03-09
// Created by: JCV
// Copyright (c) 1993-1999 Matra Datavision
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

#ifndef _XGeom_BSplineSurface_HeaderFile
#define _XGeom_BSplineSurface_HeaderFile
#pragma once
#include "NCollection_Haft.h"
#include "Geom_BSplineSurface.hxx"
#include <XGeom_BoundedSurface.h>
#include <xgp_Pnt.h>
#include <xgp_Vec.h>
#include <xgp_Trsf.h>
#include <XGeom_Curve.h>
#include <XGeom_Geometry.h>

#include <Standard.hxx>
#include <Standard_Type.hxx>

#include <Precision.hxx>
#include <Standard_Boolean.hxx>
#include <GeomAbs_BSplKnotDistribution.hxx>
#include <GeomAbs_Shape.hxx>
#include <Standard_Integer.hxx>
#include <TColgp_HArray2OfPnt.hxx>
#include <TColStd_HArray2OfReal.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <Standard_Real.hxx>
#include <Geom_BoundedSurface.hxx>
#include <TColgp_Array2OfPnt.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <TColStd_Array2OfReal.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <XGeomAbs_BSplKnotDistribution.h>
class Standard_ConstructionError;
class Standard_DimensionError;
class Standard_DomainError;
class Standard_OutOfRange;
class Standard_NoSuchObject;
class Standard_RangeError;
class Geom_UndefinedDerivative;
class gp_Pnt;
class gp_Vec;
class Geom_Curve;
class gp_Trsf;
class Geom_Geometry;
class Geom_BSplineSurface;
//DEFINE_STANDARD_HANDLE(Geom_BSplineSurface, Geom_BoundedSurface)

using namespace TKMath;
namespace TKG3d {
    ref class TKMath::xgp_Pnt;
    ref class TKMath::xgp_Vec;
    ref class TKMath::xgp_Trsf;
    ref class XGeom_Curve;
    ref class XGeom_Geometry;
    //! Describes a BSpline surface.
    //! In each parametric direction, a BSpline surface can be:
    //! - uniform or non-uniform,
    //! - rational or non-rational,
    //! - periodic or non-periodic.
    //! A BSpline surface is defined by:
    //! - its degrees, in the u and v parametric directions,
    //! - its periodic characteristic, in the u and v parametric directions,
    //! - a table of poles, also called control points (together
    //! with the associated weights if the surface is rational), and
    //! - a table of knots, together with the associated multiplicities.
    //! The degree of a Geom_BSplineSurface is limited to
    //! a value (25) which is defined and controlled by the
    //! system. This value is returned by the function MaxDegree.
    //! Poles and Weights
    //! Poles and Weights are manipulated using two associative double arrays:
    //! - the poles table, which is a double array of gp_Pnt points, and
    //! - the weights table, which is a double array of reals.
    //! The bounds of the poles and weights arrays are:
    //! - 1 and NbUPoles for the row bounds (provided
    //! that the BSpline surface is not periodic in the u
    //! parametric direction), where NbUPoles is the
    //! number of poles of the surface in the u parametric direction, and
    //! - 1 and NbVPoles for the column bounds (provided
    //! that the BSpline surface is not periodic in the v
    //! parametric direction), where NbVPoles is the
    //! number of poles of the surface in the v parametric direction.
    //! The poles of the surface are the points used to shape
    //! and reshape the surface. They comprise a rectangular network.
    //! If the surface is not periodic:
    //! - The points (1, 1), (NbUPoles, 1), (1,
    //! NbVPoles), and (NbUPoles, NbVPoles)
    //! are the four parametric "corners" of the surface.
    //! - The first column of poles and the last column of
    //! poles define two BSpline curves which delimit the
    //! surface in the v parametric direction. These are the
    //! v isoparametric curves corresponding to the two
    //! bounds of the v parameter.
    //! - The first row of poles and the last row of poles
    //! define two BSpline curves which delimit the surface
    //! in the u parametric direction. These are the u
    //! isoparametric curves corresponding to the two bounds of the u parameter.
    //! If the surface is periodic, these geometric properties are not verified.
    //! It is more difficult to define a geometrical significance
    //! for the weights. However they are useful for
    //! representing a quadric surface precisely. Moreover, if
    //! the weights of all the poles are equal, the surface has
    //! a polynomial equation, and hence is a "non-rational surface".
    //! The non-rational surface is a special, but frequently
    //! used, case, where all poles have identical weights.
    //! The weights are defined and used only in the case of
    //! a rational surface. The rational characteristic is
    //! defined in each parametric direction. A surface can be
    //! rational in the u parametric direction, and
    //! non-rational in the v parametric direction.
    //! Knots and Multiplicities
    //! For a Geom_BSplineSurface the table of knots is
    //! made up of two increasing sequences of reals, without
    //! repetition, one for each parametric direction. The
    //! multiplicities define the repetition of the knots.
    //! A BSpline surface comprises multiple contiguous
    //! patches, which are themselves polynomial or rational
    //! surfaces. The knots are the parameters of the
    //! isoparametric curves which limit these contiguous
    //! patches. The multiplicity of a knot on a BSpline
    //! surface (in a given parametric direction) is related to
    //! the degree of continuity of the surface at that knot in
    //! that parametric direction:
    //! Degree of continuity at knot(i) = Degree - Multi(i) where:
    //! - Degree is the degree of the BSpline surface in
    //! the given parametric direction, and
    //! - Multi(i) is the multiplicity of knot number i in
    //! the given parametric direction.
    //! There are some special cases, where the knots are
    //! regularly spaced in one parametric direction (i.e. the
    //! difference between two consecutive knots is a constant).
    //! - "Uniform": all the multiplicities are equal to 1.
    //! - "Quasi-uniform": all the multiplicities are equal to 1,
    //! except for the first and last knots in this parametric
    //! direction, and these are equal to Degree + 1.
    //! - "Piecewise Bezier": all the multiplicities are equal to
    //! Degree except for the first and last knots, which
    //! are equal to Degree + 1. This surface is a
    //! concatenation of Bezier patches in the given
    //! parametric direction.
    //! If the BSpline surface is not periodic in a given
    //! parametric direction, the bounds of the knots and
    //! multiplicities tables are 1 and NbKnots, where
    //! NbKnots is the number of knots of the BSpline
    //! surface in that parametric direction.
    //! If the BSpline surface is periodic in a given parametric
    //! direction, and there are k periodic knots and p
    //! periodic poles in that parametric direction:
    //! - the period is such that:
    //! period = Knot(k+1) - Knot(1), and
    //! - the poles and knots tables in that parametric
    //! direction can be considered as infinite tables, such that:
    //! Knot(i+k) = Knot(i) + period, and
    //! Pole(i+p) = Pole(i)
    //! Note: The data structure tables for a periodic BSpline
    //! surface are more complex than those of a non-periodic one.
    //! References :
    //! . A survey of curve and surface methods in CADG Wolfgang BOHM
    //! CAGD 1 (1984)
    //! . On de Boor-like algorithms and blossoming Wolfgang BOEHM
    //! cagd 5 (1988)
    //! . Blossoming and knot insertion algorithms for B-spline curves
    //! Ronald N. GOLDMAN
    //! . Modelisation des surfaces en CAO, Henri GIAUME Peugeot SA
    //! . Curves and Surfaces for Computer Aided Geometric Design,
    //! a practical guide Gerald Farin
    public ref class XGeom_BSplineSurface : public XGeom_BoundedSurface
    {

    public:

        //!
        XGeom_BSplineSurface(void);

        //! 
        XGeom_BSplineSurface(Handle(Geom_BSplineSurface) pos);

        //!
        ~XGeom_BSplineSurface();

        void SetBSplineSurfaceHandle(Handle(Geom_BSplineSurface) handle);

        //!
        virtual Handle(Geom_BSplineSurface) GetBSplineSurface();

        //!
        virtual Handle(Geom_BoundedSurface) GetBoundedSurface() Standard_OVERRIDE;

        //!
        virtual Handle(Geom_Surface) GetSurface() Standard_OVERRIDE;

        //!
        virtual Handle(Geom_Geometry) GetGeometry() Standard_OVERRIDE;

        //! Creates  a non-rational b-spline surface (weights
        //! default value is 1.).
        //! The following conditions must be verified.
        //! 0 < UDegree <= MaxDegree.
        //! UKnots.Length() == UMults.Length() >= 2
        //! UKnots(i) < UKnots(i+1) (Knots are increasing)
        //! 1 <= UMults(i) <= UDegree
        //! On a   non  uperiodic   surface    the  first and    last
        //! umultiplicities  may  be     UDegree+1  (this   is   even
        //! recommanded if you want the curve  to start and finish on
        //! the first and last pole).
        //! On a uperiodic     surface  the first    and   the   last
        //! umultiplicities must be the same.
        //! on non-uperiodic surfaces
        //! Poles.ColLength() == Sum(UMults(i)) - UDegree - 1 >= 2
        //! on uperiodic surfaces
        //! Poles.ColLength() == Sum(UMults(i)) except the first or last
        //! The previous conditions for U holds  also for V, with the
        //! RowLength of the poles.
        //! Standard_Boolean UPeriodic = Standard_False, Standard_Boolean VPeriodic = Standard_False
        XGeom_BSplineSurface(array<xgp_Pnt^, 2>^ Poles, array<Standard_Real>^ UKnots, array<Standard_Real>^ VKnots, array<Standard_Integer>^ UMults, array<Standard_Integer>^ VMults, Standard_Integer UDegree, Standard_Integer VDegree, Standard_Boolean UPeriodic, Standard_Boolean VPeriodic);

        XGeom_BSplineSurface(array<xgp_Pnt^, 2>^ Poles, array<Standard_Real>^ UKnots, array<Standard_Real>^ VKnots, array<Standard_Integer>^ UMults, array<Standard_Integer>^ VMults, Standard_Integer UDegree, Standard_Integer VDegree) {
            Standard_Boolean UPeriodic = Standard_False; Standard_Boolean VPeriodic = Standard_False;
            XGeom_BSplineSurface(Poles, UKnots, VKnots, UMults, VMults, UDegree, VDegree, UPeriodic, VPeriodic);
        };
        //! Creates  a non-rational b-spline surface (weights
        //! default value is 1.).
        //!
        //! The following conditions must be verified.
        //! 0 < UDegree <= MaxDegree.
        //!
        //! UKnots.Length() == UMults.Length() >= 2
        //!
        //! UKnots(i) < UKnots(i+1) (Knots are increasing)
        //! 1 <= UMults(i) <= UDegree
        //!
        //! On a   non  uperiodic   surface    the  first and    last
        //! umultiplicities  may  be     UDegree+1  (this   is   even
        //! recommanded if you want the curve  to start and finish on
        //! the first and last pole).
        //!
        //! On a uperiodic     surface  the first    and   the   last
        //! umultiplicities must be the same.
        //!
        //! on non-uperiodic surfaces
        //!
        //! Poles.ColLength() == Sum(UMults(i)) - UDegree - 1 >= 2
        //!
        //! on uperiodic surfaces
        //!
        //! Poles.ColLength() == Sum(UMults(i)) except the first or
        //! last
        //!
        //! The previous conditions for U holds  also for V, with the
        //! RowLength of the poles.
        //! Standard_Boolean UPeriodic = Standard_False, Standard_Boolean VPeriodic = Standard_False
        XGeom_BSplineSurface(array<xgp_Pnt^, 2>^ Poles, array<Standard_Real, 2>^ Weights, array<Standard_Real>^ UKnots, array<Standard_Real>^ VKnots, array<Standard_Integer>^ UMults, array<Standard_Integer>^ VMults, Standard_Integer UDegree, Standard_Integer VDegree, Standard_Boolean UPeriodic, Standard_Boolean VPeriodic);

        //! Exchanges the u and v parametric directions on
        //! this BSpline surface.
        //! As a consequence:
        //! - the poles and weights tables are transposed,
        //! - the knots and multiplicities tables are exchanged,
        //! - degrees of continuity, and rational, periodic and
        //! uniform characteristics are exchanged, and
        //! - the orientation of the surface is inverted.
        void ExchangeUV();

        //! Sets the surface U periodic.
        //! Modifies this surface to be periodic in the U 
        //! parametric direction.
        //! To become periodic in a given parametric direction a
        //! surface must be closed in that parametric direction,
        //! and the knot sequence relative to that direction must be periodic.
        //! To generate this periodic sequence of knots, the
        //! functions FirstUKnotIndex and LastUKnotIndex  are used to
        //! compute I1 and I2. These are the indexes, in the
        //! knot array associated with the given parametric
        //! direction, of the knots that correspond to the first and
        //! last parameters of this BSpline surface in the given
        //! parametric direction. Hence the period is:
        //! Knots(I1) - Knots(I2)
        //! As a result, the knots and poles tables are modified.
        //! Exceptions
        //! Standard_ConstructionError if the surface is not
        //! closed in the given parametric direction.
        void SetUPeriodic();

        //! Sets the surface V periodic.
        //! Modifies this surface to be periodic in the V
        //! parametric direction.
        //! To become periodic in a given parametric direction a
        //! surface must be closed in that parametric direction,
        //! and the knot sequence relative to that direction must be periodic.
        //! To generate this periodic sequence of knots, the
        //! functions FirstVKnotIndex and LastVKnotIndex are used to
        //! compute I1 and I2. These are the indexes, in the
        //! knot array associated with the given parametric
        //! direction, of the knots that correspond to the first and
        //! last parameters of this BSpline surface in the given
        //! parametric direction. Hence the period is:
        //! Knots(I1) - Knots(I2)
        //! As a result, the knots and poles tables are modified.
        //! Exceptions
        //! Standard_ConstructionError if the surface is not
        //! closed in the given parametric direction.
        void SetVPeriodic();

        //! returns the parameter normalized within
        //! the period if the surface is periodic : otherwise
        //! does not do anything
        void PeriodicNormalization(Standard_Real% U, Standard_Real% V);

        //! Assigns the knot of index Index in the knots table in
        //! the corresponding parametric direction to be the
        //! origin of this periodic BSpline surface. As a
        //! consequence, the knots and poles tables are modified.
        //! Exceptions
        //! Standard_NoSuchObject if this BSpline surface is
        //! not periodic in the given parametric direction.
        //! Standard_DomainError if Index is outside the
        //! bounds of the knots table in the given parametric direction.
        void SetUOrigin(Standard_Integer Index);

        //! Assigns the knot of index Index in the knots table in
        //! the corresponding parametric direction to be the
        //! origin of this periodic BSpline surface. As a
        //! consequence, the knots and poles tables are modified.
        //! Exceptions
        //! Standard_NoSuchObject if this BSpline surface is
        //! not periodic in the given parametric direction.
        //! Standard_DomainError if Index is outside the
        //! bounds of the knots table in the given parametric direction.
        void SetVOrigin(Standard_Integer Index);

        //! Sets the surface U not periodic.
        //! Changes this BSpline surface into a non-periodic
        //! surface along U direction. 
        //! If this surface is already non-periodic, it is not modified.
        //! Note: the poles and knots tables are modified.
        void SetUNotPeriodic();

        //! Sets the surface V not periodic.
        //! Changes this BSpline surface into a non-periodic
        //! surface along V direction. 
        //! If this surface is already non-periodic, it is not modified.
        //! Note: the poles and knots tables are modified.
        void SetVNotPeriodic();

        //! Changes the orientation of this BSpline surface in the
        //! U parametric direction. The bounds of the
        //! surface are not changed but the given parametric
        //! direction is reversed. Hence the orientation of the
        //! surface is reversed.
        //! The knots and poles tables are modified.
        void UReverse() Standard_OVERRIDE;

        //! Changes the orientation of this BSpline surface in the
        //! V parametric direction. The bounds of the
        //! surface are not changed but the given parametric
        //! direction is reversed. Hence the orientation of the
        //! surface is reversed.
        //! The knots and poles tables are modified.
        void VReverse() Standard_OVERRIDE;

        //! Computes the u parameter on the modified
        //! surface, produced by reversing its U parametric
        //! direction, for the point of u parameter U,  on this BSpline surface.
        //! For a BSpline surface, these functions return respectively:
        //! - UFirst + ULast - U, 
        //! where UFirst, ULast are
        //! the values of the first and last parameters of this
        //! BSpline surface, in the u parametric directions.
        Standard_Real UReversedParameter(Standard_Real U) Standard_OVERRIDE;

        //! Computes the v parameter on the modified
        //! surface, produced by reversing its V parametric
        //! direction, for the point of v parameter V on this BSpline surface.
        //! For a BSpline surface, these functions return respectively:
        //! - VFirst + VLast - V,
        //! VFirst and VLast are
        //! the values of the first and last parameters of this
        //! BSpline surface, in the v pametric directions.
        Standard_Real VReversedParameter(Standard_Real V) Standard_OVERRIDE;

        //! Increases the degrees of this BSpline surface to
        //! UDegree and VDegree in the u and v parametric
        //! directions respectively. As a result, the tables of poles,
        //! weights and multiplicities are modified. The tables of
        //! knots is not changed.
        //! Note: Nothing is done if the given degree is less than
        //! or equal to the current degree in the corresponding
        //! parametric direction.
        //! Exceptions
        //! Standard_ConstructionError if UDegree or
        //! VDegree is greater than
        //! Geom_BSplineSurface::MaxDegree().
        void IncreaseDegree(Standard_Integer UDegree, Standard_Integer VDegree);

        //! Inserts into the knots table for the U
        //! parametric direction of this BSpline surface:
        //! - the values of the array Knots, with their respective
        //! multiplicities, Mults.
        //! If the knot value to insert already exists in the table, its multiplicity is:
        //! - increased by M, if Add is true (the default), or
        //! - increased to M, if Add is false.
        //! The tolerance criterion used to check the equality of
        //! the knots is the larger of the values ParametricTolerance and
        //! Standard_Real::Epsilon(val), where val is the knot value to be inserted.
        //! Warning
        //! - If a given multiplicity coefficient is null, or negative, nothing is done.
        //! - The new multiplicity of a knot is limited to the degree of this BSpline surface in the
        //! corresponding parametric direction.
        //! Exceptions
        //! Standard_ConstructionError if a knot value to
        //! insert is outside the bounds of this BSpline surface in
        //! the specified parametric direction. The comparison
        //! uses the precision criterion ParametricTolerance.
        //! Standard_Real ParametricTolerance = 0.0, Standard_Boolean Add = Standard_True
        void InsertUKnots(array<Standard_Real>^ Knots, array<Standard_Integer>^ Mults, Standard_Real ParametricTolerance, Standard_Boolean Add);

        //! Inserts into the knots table for the V
        //! parametric direction of this BSpline surface:
        //! - the values of the array Knots, with their respective
        //! multiplicities, Mults.
        //! If the knot value to insert already exists in the table, its multiplicity is:
        //! - increased by M, if Add is true (the default), or
        //! - increased to M, if Add is false.
        //! The tolerance criterion used to check the equality of
        //! the knots is the larger of the values ParametricTolerance and
        //! Standard_Real::Epsilon(val), where val is the knot value to be inserted.
        //! Warning
        //! - If a given multiplicity coefficient is null, or negative, nothing is done.
        //! - The new multiplicity of a knot is limited to the degree of this BSpline surface in the
        //! corresponding parametric direction.
        //! Exceptions
        //! Standard_ConstructionError if a knot value to
        //! insert is outside the bounds of this BSpline surface in
        //! the specified parametric direction. The comparison
        //! uses the precision criterion ParametricTolerance.
        //! Standard_Real ParametricTolerance = 0.0, Standard_Boolean Add = Standard_True
        void InsertVKnots(array<Standard_Real>^ Knots, array<Standard_Integer>^ Mults, Standard_Real ParametricTolerance, Standard_Boolean Add);

        //! Reduces to M the multiplicity of the knot of index
        //! Index in the U parametric direction. If M is 0, the knot is removed.
        //! With a modification of this type, the table of poles is also modified.
        //! Two different algorithms are used systematically to
        //! compute the new poles of the surface. For each
        //! pole, the distance between the pole calculated
        //! using the first algorithm and the same pole
        //! calculated using the second algorithm, is checked. If
        //! this distance is less than Tolerance it ensures that
        //! the surface is not modified by more than Tolerance.
        //! Under these conditions, the function returns true;
        //! otherwise, it returns false.
        //! A low tolerance prevents modification of the
        //! surface. A high tolerance "smoothes" the surface.
        //! Exceptions
        //! Standard_OutOfRange if Index is outside the
        //! bounds of the knots table of this BSpline surface.
        Standard_Boolean RemoveUKnot(Standard_Integer Index, Standard_Integer M, Standard_Real Tolerance);

        //! Reduces to M the multiplicity of the knot of index
        //! Index in the V parametric direction. If M is 0, the knot is removed.
        //! With a modification of this type, the table of poles is also modified.
        //! Two different algorithms are used systematically to
        //! compute the new poles of the surface. For each
        //! pole, the distance between the pole calculated
        //! using the first algorithm and the same pole
        //! calculated using the second algorithm, is checked. If
        //! this distance is less than Tolerance it ensures that
        //! the surface is not modified by more than Tolerance.
        //! Under these conditions, the function returns true;
        //! otherwise, it returns false.
        //! A low tolerance prevents modification of the
        //! surface. A high tolerance "smoothes" the surface.
        //! Exceptions
        //! Standard_OutOfRange if Index is outside the
        //! bounds of the knots table of this BSpline surface.
        Standard_Boolean RemoveVKnot(Standard_Integer Index, Standard_Integer M, Standard_Real Tolerance);


        //! Increases the multiplicity of the knot of range UIndex
        //! in the UKnots sequence.
        //! M is the new multiplicity. M must be greater than the
        //! previous multiplicity and lower or equal to the degree
        //! of the surface in the U parametric direction.
        //! Raised if M is not in the range [1, UDegree]
        //!
        //! Raised if UIndex is not in the range [FirstUKnotIndex,
        //! LastUKnotIndex] given by the methods with the same name.
        void IncreaseUMultiplicity(Standard_Integer UIndex, Standard_Integer M);


        //! Increases until order M the multiplicity of the set of knots
        //! FromI1,...., ToI2 in the U direction. This method can be used
        //! to make a B_spline surface into a PiecewiseBezier B_spline
        //! surface.
        //! If <me> was uniform, it can become non uniform.
        //!
        //! Raised if FromI1 or ToI2 is out of the range [FirstUKnotIndex,
        //! LastUKnotIndex].
        //!
        //! M should be greater than the previous multiplicity of the
        //! all the knots FromI1,..., ToI2 and lower or equal to the
        //! Degree of the surface in the U parametric direction.
        void IncreaseUMultiplicity(Standard_Integer FromI1, Standard_Integer ToI2, Standard_Integer M);


        //! Increments the multiplicity of the consecutives uknots FromI1..ToI2
        //! by step.   The multiplicity of each knot FromI1,.....,ToI2 must be
        //! lower or equal to the UDegree of the B_spline.
        //!
        //! Raised if FromI1 or ToI2 is not in the range
        //! [FirstUKnotIndex, LastUKnotIndex]
        //!
        //! Raised if one knot has a multiplicity greater than UDegree.
        void IncrementUMultiplicity(Standard_Integer FromI1, Standard_Integer ToI2, Standard_Integer Step);


        //! Increases the multiplicity of a knot in the V direction.
        //! M is the new multiplicity.
        //!
        //! M should be greater than the previous multiplicity and lower
        //! than the degree of the surface in the V parametric direction.
        //!
        //! Raised if VIndex is not in the range [FirstVKnotIndex,
        //! LastVKnotIndex] given by the methods with the same name.
        void IncreaseVMultiplicity(Standard_Integer VIndex, Standard_Integer M);


        //! Increases until order M the multiplicity of the set of knots
        //! FromI1,...., ToI2 in the V direction. This method can be used to
        //! make a BSplineSurface into a PiecewiseBezier B_spline
        //! surface. If <me> was uniform, it can become non-uniform.
        //!
        //! Raised if FromI1 or ToI2 is out of the range [FirstVKnotIndex,
        //! LastVKnotIndex] given by the methods with the same name.
        //!
        //! M should be greater than the previous multiplicity of the
        //! all the knots FromI1,..., ToI2 and lower or equal to the
        //! Degree of the surface in the V parametric direction.
        void IncreaseVMultiplicity(Standard_Integer FromI1, Standard_Integer ToI2, Standard_Integer M);


        //! Increments the multiplicity of the consecutives vknots FromI1..ToI2
        //! by step.  The multiplicity of each knot FromI1,.....,ToI2 must be
        //! lower or equal to the VDegree of the B_spline.
        //!
        //! Raised if FromI1 or ToI2 is not in the range
        //! [FirstVKnotIndex, LastVKnotIndex]
        //!
        //! Raised if one knot has a multiplicity greater than VDegree.
        void IncrementVMultiplicity(Standard_Integer FromI1, Standard_Integer ToI2, Standard_Integer Step);


        //! Inserts a knot value in the sequence of UKnots. If U is a knot
        //! value this method increases the multiplicity of the knot if the
        //! previous multiplicity was lower than M else it does nothing. The
        //! tolerance criterion is ParametricTolerance. ParametricTolerance
        //! should be greater or equal than Resolution from package gp.
        //!
        //! Raised if U is out of the bounds [U1, U2] given by the methods
        //! Bounds, the criterion ParametricTolerance is used.
        //! Raised if M is not in the range [1, UDegree].
        //! Standard_Boolean Add = Standard_True
        void InsertUKnot(Standard_Real U, Standard_Integer M, Standard_Real ParametricTolerance, Standard_Boolean Add);


        //! Inserts a knot value in the sequence of VKnots. If V is a knot
        //! value this method increases the multiplicity of the knot if the
        //! previous multiplicity was lower than M otherwise it does nothing.
        //! The tolerance criterion is ParametricTolerance.
        //! ParametricTolerance should be greater or equal than Resolution
        //! from package gp.
        //!
        //! raises if V is out of the Bounds [V1, V2] given by the methods
        //! Bounds, the criterion ParametricTolerance is used.
        //! raises if M is not in the range [1, VDegree].
        //! Standard_Boolean Add = Standard_True
        void InsertVKnot(Standard_Real V, Standard_Integer M, Standard_Real ParametricTolerance, Standard_Boolean Add);


        //! Segments the surface between U1 and U2 in the U-Direction.
        //! between V1 and V2 in the V-Direction.
        //! The control points are modified, the first and the last point
        //! are not the same.
        //!
        //! Parameters theUTolerance, theVTolerance define the possible proximity along the correponding
        //! direction of the segment boundaries and B-spline knots to treat them as equal.
        //!
        //! Warnings :
        //! Even if <me> is not closed it can become closed after the
        //! segmentation for example if U1 or U2 are out of the bounds
        //! of the surface <me> or if the surface makes loop.
        //! raises if U2 < U1 or V2 < V1.
        //! Standard_DomainError if U2 - U1 exceeds the uperiod for uperiodic surfaces.
        //! i.e. ((U2 - U1) - UPeriod) > Precision::PConfusion().
        //! Standard_DomainError if V2 - V1 exceeds the vperiod for vperiodic surfaces.
        //! i.e. ((V2 - V1) - VPeriod) > Precision::PConfusion()).
        //! Standard_Real theUTolerance = Precision::PConfusion(), Standard_Real theVTolerance = Precision::PConfusion()
        void Segment(Standard_Real U1, Standard_Real U2, Standard_Real V1, Standard_Real V2, Standard_Real theUTolerance, Standard_Real theVTolerance);

        void Segment(Standard_Real U1, Standard_Real U2, Standard_Real V1, Standard_Real V2) {
            Standard_Real theUTolerance = Precision::PConfusion(); Standard_Real theVTolerance = Precision::PConfusion();
            Segment(U1, U2, V1, V2, theUTolerance, theVTolerance);
        };
        //! Segments the surface between U1 and U2 in the U-Direction.
        //! between V1 and V2 in the V-Direction.
        //!
        //! same as Segment but do nothing if U1 and U2 (resp. V1 and V2) are
        //! equal to the bounds in U (resp. in V) of <me>.
        //! For example, if <me> is periodic in V, it will be always periodic
        //! in V after the segmentation if the bounds in V are unchanged
        //!
        //! Parameters theUTolerance, theVTolerance define the possible proximity along the correponding
        //! direction of the segment boundaries and B-spline knots to treat them as equal.
        //!
        //! Warnings :
        //! Even if <me> is not closed it can become closed after the
        //! segmentation for example if U1 or U2 are out of the bounds
        //! of the surface <me> or if the surface makes loop.
        //! raises if U2 < U1 or V2 < V1.
        //! Standard_DomainError if U2 - U1 exceeds the uperiod for uperiodic surfaces.
        //! i.e. ((U2 - U1) - UPeriod) > Precision::PConfusion().
        //! Standard_DomainError if V2 - V1 exceeds the vperiod for vperiodic surfaces.
        //! i.e. ((V2 - V1) - VPeriod) > Precision::PConfusion()).
        //! Standard_Real theUTolerance = Precision::PConfusion(), Standard_Real theVTolerance = Precision::PConfusion()
        void CheckAndSegment(Standard_Real U1, Standard_Real U2, Standard_Real V1, Standard_Real V2, Standard_Real theUTolerance, Standard_Real theVTolerance);

        void CheckAndSegment(Standard_Real U1, Standard_Real U2, Standard_Real V1, Standard_Real V2) {
            Standard_Real theUTolerance = Precision::PConfusion();  Standard_Real theVTolerance = Precision::PConfusion();
            CheckAndSegment(U1, U2, V1, V2, theUTolerance, theVTolerance);
        };

        //! Substitutes the UKnots of range UIndex with K.
        //!
        //! Raised if UIndex < 1 or UIndex > NbUKnots
        //!
        //! Raised if K >= UKnots(UIndex+1) or K <= UKnots(UIndex-1)
        void SetUKnot(Standard_Integer UIndex, Standard_Real K);

        //! Changes all the U-knots of the surface.
        //! The multiplicity of the knots are not modified.
        //!
        //! Raised if there is an index such that UK (Index+1) <= UK (Index).
        //!
        //! Raised if  UK.Lower() < 1 or UK.Upper() > NbUKnots
        void SetUKnots(array<Standard_Real>^ UK);


        //! Changes the value of the UKnots of range UIndex and
        //! increases its multiplicity.
        //!
        //! Raised if UIndex is not in the range [FirstUKnotIndex,
        //! LastUKnotIndex] given by the methods with the same name.
        //!
        //! Raised if K >= UKnots(UIndex+1) or K <= UKnots(UIndex-1)
        //! M must be lower than UDegree and greater than the previous
        //! multiplicity of the knot of range UIndex.
        void SetUKnot(Standard_Integer UIndex, Standard_Real K, Standard_Integer M);

        //! Substitutes the VKnots of range VIndex with K.
        //!
        //! Raised if VIndex < 1 or VIndex > NbVKnots
        //!
        //! Raised if K >= VKnots(VIndex+1) or K <= VKnots(VIndex-1)
        void SetVKnot(Standard_Integer VIndex, Standard_Real K);

        //! Changes all the V-knots of the surface.
        //! The multiplicity of the knots are not modified.
        //!
        //! Raised if there is an index such that VK (Index+1) <= VK (Index).
        //!
        //! Raised if  VK.Lower() < 1 or VK.Upper() > NbVKnots
        void SetVKnots(array<Standard_Real>^ VK);


        //! Changes the value of the VKnots of range VIndex and increases
        //! its multiplicity.
        //!
        //! Raised if VIndex is not in the range [FirstVKnotIndex,
        //! LastVKnotIndex] given by the methods with the same name.
        //!
        //! Raised if K >= VKnots(VIndex+1) or K <= VKnots(VIndex-1)
        //! M must be lower than VDegree and greater than the previous
        //! multiplicity of the knot of range VIndex.
        void SetVKnot(Standard_Integer VIndex, Standard_Real K, Standard_Integer M);


        //! Locates the parametric value U in the sequence of UKnots.
        //! If "WithKnotRepetition" is True we consider the knot's
        //! representation with repetition of multiple knot value,
        //! otherwise  we consider the knot's representation with
        //! no repetition of multiple knot values.
        //! UKnots (I1) <= U <= UKnots (I2)
        //! . if I1 = I2  U is a knot value (the tolerance criterion
        //! ParametricTolerance is used).
        //! . if I1 < 1  => U < UKnots(1) - Abs(ParametricTolerance)
        //! . if I2 > NbUKnots => U > UKnots(NbUKnots)+Abs(ParametricTolerance)
        //! Standard_Boolean WithKnotRepetition = Standard_False
        void LocateU(Standard_Real U, Standard_Real ParametricTolerance, Standard_Integer% I1, Standard_Integer% I2, Standard_Boolean WithKnotRepetition);


        //! Locates the parametric value V in the sequence of knots.
        //! If "WithKnotRepetition" is True we consider the knot's
        //! representation with repetition of multiple knot value,
        //! otherwise  we consider the knot's representation with
        //! no repetition of multiple knot values.
        //! VKnots (I1) <= V <= VKnots (I2)
        //! . if I1 = I2  V is a knot value (the tolerance criterion
        //! ParametricTolerance is used).
        //! . if I1 < 1  => V < VKnots(1) - Abs(ParametricTolerance)
        //! . if I2 > NbVKnots => V > VKnots(NbVKnots)+Abs(ParametricTolerance)
        //! poles insertion and removing
        //! The following methods are available only if the surface
        //! is Uniform or QuasiUniform in the considered direction
        //! The knot repartition is modified.
        //! Standard_Boolean WithKnotRepetition = Standard_False
        void LocateV(Standard_Real V, Standard_Real ParametricTolerance, Standard_Integer% I1, Standard_Integer% I2, Standard_Boolean WithKnotRepetition);


        //! Substitutes the pole of range (UIndex, VIndex) with P.
        //! If the surface is rational the weight of range (UIndex, VIndex)
        //! is not modified.
        //!
        //! Raised if UIndex < 1 or UIndex > NbUPoles or VIndex < 1 or
        //! VIndex > NbVPoles.
        void SetPole(Standard_Integer UIndex, Standard_Integer VIndex, xgp_Pnt^ P);


        //! Substitutes the pole and the weight of range (UIndex, VIndex)
        //! with P and W.
        //!
        //! Raised if UIndex < 1 or UIndex > NbUPoles or VIndex < 1 or
        //! VIndex > NbVPoles.
        //! Raised if Weight <= Resolution from package gp.
        void SetPole(Standard_Integer UIndex, Standard_Integer VIndex, xgp_Pnt^ P, Standard_Real Weight);


        //! Changes a column of poles or a part of this column.
        //! Raised if Vindex < 1 or VIndex > NbVPoles.
        //!
        //! Raised if CPoles.Lower() < 1 or CPoles.Upper() > NbUPoles.
        void SetPoleCol(Standard_Integer VIndex, array<xgp_Pnt^>^ CPoles);


        //! Changes a column of poles or a part of this column with the
        //! corresponding weights. If the surface was rational it can
        //! become non rational. If the surface was non rational it can
        //! become rational.
        //! Raised if Vindex < 1 or VIndex > NbVPoles.
        //!
        //! Raised if CPoles.Lower() < 1 or CPoles.Upper() > NbUPoles
        //! Raised if the bounds of CPoleWeights are not the same as the
        //! bounds of CPoles.
        //! Raised if one of the weight value of CPoleWeights is lower or
        //! equal to Resolution from package gp.
        void SetPoleCol(Standard_Integer VIndex, array<xgp_Pnt^>^ CPoles, array<Standard_Real>^ CPoleWeights);


        //! Changes a row of poles or a part of this row with the
        //! corresponding weights. If the surface was rational it can
        //! become non rational. If the surface was non rational it can
        //! become rational.
        //! Raised if Uindex < 1 or UIndex > NbUPoles.
        //!
        //! Raised if CPoles.Lower() < 1 or CPoles.Upper() > NbVPoles
        //! raises if the bounds of CPoleWeights are not the same as the
        //! bounds of CPoles.
        //! Raised if one of the weight value of CPoleWeights is lower or
        //! equal to Resolution from package gp.
        void SetPoleRow(Standard_Integer UIndex, array<xgp_Pnt^>^ CPoles, array<Standard_Real>^ CPoleWeights);


        //! Changes a row of poles or a part of this row.
        //! Raised if Uindex < 1 or UIndex > NbUPoles.
        //!
        //! Raised if CPoles.Lower() < 1 or CPoles.Upper() > NbVPoles.
        void SetPoleRow(Standard_Integer UIndex, array<xgp_Pnt^>^ CPoles);


        //! Changes the weight of the pole of range UIndex, VIndex.
        //! If the surface was non rational it can become rational.
        //! If the surface was rational it can become non rational.
        //!
        //! Raised if UIndex < 1 or UIndex > NbUPoles or VIndex < 1 or
        //! VIndex > NbVPoles
        //!
        //! Raised if weight is lower or equal to Resolution from
        //! package gp
        void SetWeight(Standard_Integer UIndex, Standard_Integer VIndex, Standard_Real Weight);


        //! Changes a column of weights of a part of this column.
        //!
        //! Raised if VIndex < 1 or VIndex > NbVPoles
        //!
        //! Raised if CPoleWeights.Lower() < 1 or
        //! CPoleWeights.Upper() > NbUPoles.
        //! Raised if a weight value is lower or equal to Resolution
        //! from package gp.
        void SetWeightCol(Standard_Integer VIndex, array<Standard_Real>^ CPoleWeights);


        //! Changes a row of weights or a part of this row.
        //!
        //! Raised if UIndex < 1 or UIndex > NbUPoles
        //!
        //! Raised if CPoleWeights.Lower() < 1 or
        //! CPoleWeights.Upper() > NbVPoles.
        //! Raised  if a weight value is lower or equal to Resolution
        //! from package gp.
        void SetWeightRow(Standard_Integer UIndex, array<Standard_Real>^ CPoleWeights);

        //! Move a point with parameter U and V to P.
        //! given u,v  as parameters)  to  reach a  new position
        //! UIndex1, UIndex2, VIndex1, VIndex2:
        //! indicates the poles which can be moved
        //! if Problem in BSplineBasis calculation, no change
        //! for the curve and
        //! UFirstIndex, VLastIndex = 0
        //! VFirstIndex, VLastIndex = 0
        //!
        //! Raised if UIndex1 < UIndex2 or VIndex1 < VIndex2 or
        //! UIndex1 < 1 || UIndex1 > NbUPoles or
        //! UIndex2 < 1 || UIndex2 > NbUPoles
        //! VIndex1 < 1 || VIndex1 > NbVPoles or
        //! VIndex2 < 1 || VIndex2 > NbVPoles
        //! characteristics of the surface
        void MovePoint(Standard_Real U, Standard_Real V, xgp_Pnt^ P, Standard_Integer UIndex1, Standard_Integer UIndex2, Standard_Integer VIndex1, Standard_Integer VIndex2, Standard_Integer% UFirstIndex, Standard_Integer% ULastIndex, Standard_Integer% VFirstIndex, Standard_Integer% VLastIndex);


        //! Returns true if the first control points row and the last
        //! control points row are identical. The tolerance criterion
        //! is Resolution from package gp.
        Standard_Boolean IsUClosed() Standard_OVERRIDE;


        //! Returns true if the first control points column and the
        //! last last control points column are identical.
        //! The tolerance criterion is Resolution from package gp.
        Standard_Boolean IsVClosed() Standard_OVERRIDE;


        //! Returns True if the order of continuity of the surface in the
        //! U direction  is N.
        //! Raised if N < 0.
        Standard_Boolean IsCNu(Standard_Integer N) Standard_OVERRIDE;


        //! Returns True if the order of continuity of the surface
        //! in the V direction  is N.
        //! Raised if N < 0.
        Standard_Boolean IsCNv(Standard_Integer N) Standard_OVERRIDE;


        //! Returns True if the surface is closed in the U direction
        //! and if the B-spline has been turned into a periodic surface
        //! using the function SetUPeriodic.
        Standard_Boolean IsUPeriodic() Standard_OVERRIDE;


        //! Returns False if for each row of weights all the weights
        //! are identical.
        //! The tolerance criterion is resolution from package gp.
        //! Example :
        //! |1.0, 1.0, 1.0|
        //! if Weights =  |0.5, 0.5, 0.5|   returns False
        //! |2.0, 2.0, 2.0|
        Standard_Boolean IsURational();


        //! Returns True if the surface is closed in the V direction
        //! and if the B-spline has been turned into a periodic
        //! surface using the function SetVPeriodic.
        Standard_Boolean IsVPeriodic() Standard_OVERRIDE;


        //! Returns False if for each column of weights all the weights
        //! are identical.
        //! The tolerance criterion is resolution from package gp.
        //! Examples :
        //! |1.0, 2.0, 0.5|
        //! if Weights =  |1.0, 2.0, 0.5|   returns False
        //! |1.0, 2.0, 0.5|
        Standard_Boolean IsVRational();


        //! Returns the parametric bounds of the surface.
        //! Warnings :
        //! These parametric values are the bounds of the array of
        //! knots UKnots and VKnots only if the first knots and the
        //! last knots have a multiplicity equal to UDegree + 1 or
        //! VDegree + 1
        void Bounds(Standard_Real% U1, Standard_Real% U2, Standard_Real% V1, Standard_Real% V2) Standard_OVERRIDE;


        //! Returns the continuity of the surface :
        //! C0 : only geometric continuity,
        //! C1 : continuity of the first derivative all along the Surface,
        //! C2 : continuity of the second derivative all along the Surface,
        //! C3 : continuity of the third derivative all along the Surface,
        //! CN : the order of continuity is infinite.
        //! A B-spline surface is infinitely continuously differentiable
        //! for the couple of parameters U, V such thats U != UKnots(i)
        //! and V != VKnots(i). The continuity of the surface at a knot
        //! value depends on the multiplicity of this knot.
        //! Example :
        //! If the surface is C1 in the V direction and C2 in the U
        //! direction this function returns Shape = C1.
        XGeomAbs_Shape Continuity() Standard_OVERRIDE;


        //! Computes the Index of the UKnots which gives the first
        //! parametric value of the surface in the U direction.
        //! The UIso curve corresponding to this value is a
        //! boundary curve of the surface.
        Standard_Integer FirstUKnotIndex();


        //! Computes the Index of the VKnots which gives the
        //! first parametric value of the surface in the V direction.
        //! The VIso curve corresponding to this knot is a boundary
        //! curve of the surface.
        Standard_Integer FirstVKnotIndex();


        //! Computes the Index of the UKnots which gives the
        //! last parametric value of the surface in the U direction.
        //! The UIso curve corresponding to this knot is a boundary
        //! curve of the surface.
        Standard_Integer LastUKnotIndex();


        //! Computes the Index of the VKnots which gives the
        //! last parametric value of the surface in the V direction.
        //! The VIso curve corresponding to this knot is a
        //! boundary curve of the surface.
        Standard_Integer LastVKnotIndex();

        //! Returns the number of knots in the U direction.
        Standard_Integer NbUKnots();

        //! Returns number of poles in the U direction.
        Standard_Integer NbUPoles();

        //! Returns the number of knots in the V direction.
        Standard_Integer NbVKnots();

        //! Returns the number of poles in the V direction.
        Standard_Integer NbVPoles();


        //! Returns the pole of range (UIndex, VIndex).
        //!
        //! Raised if UIndex < 1 or UIndex > NbUPoles or VIndex < 1 or
        //! VIndex > NbVPoles.
        xgp_Pnt^ Pole(Standard_Integer UIndex, Standard_Integer VIndex);

        //! Returns the poles of the B-spline surface.
        //!
        //! Raised if the length of P in the U and V direction
        //! is not equal to NbUpoles and NbVPoles.
        void Poles(array<xgp_Pnt^, 2>^ P);

        //! Returns the poles of the B-spline surface.
        array<xgp_Pnt^, 2>^ Poles();


        //! Returns the degree of the normalized B-splines Ni,n in the U
        //! direction.
        Standard_Integer UDegree();


        //! Returns the Knot value of range UIndex.
        //! Raised if UIndex < 1 or UIndex > NbUKnots
        Standard_Real UKnot(Standard_Integer UIndex);


        //! Returns NonUniform or Uniform or QuasiUniform or
        //! PiecewiseBezier.  If all the knots differ by a
        //! positive constant from the preceding knot in the U
        //! direction the B-spline surface can be :
        //! - Uniform if all the knots are of multiplicity 1,
        //! - QuasiUniform if all the knots are of multiplicity 1
        //! except for the first and last knot which are of
        //! multiplicity Degree + 1,
        //! - PiecewiseBezier if the first and last knots have
        //! multiplicity Degree + 1 and if interior knots have
        //! multiplicity Degree
        //! otherwise the surface is non uniform in the U direction
        //! The tolerance criterion is Resolution from package gp.
        XGeomAbs_BSplKnotDistribution UKnotDistribution();

        //! Returns the knots in the U direction.
        //!
        //! Raised if the length of Ku is not equal to the number of knots
        //! in the U direction.
        void UKnots(array<Standard_Real>^ Ku);

        //! Returns the knots in the U direction.
        array<Standard_Real>^ UKnots();

        //! Returns the uknots sequence.
        //! In this sequence the knots with a multiplicity greater than 1
        //! are repeated.
        //! Example :
        //! Ku = {k1, k1, k1, k2, k3, k3, k4, k4, k4}
        //!
        //! Raised if the length of Ku is not equal to NbUPoles + UDegree + 1
        void UKnotSequence(array<Standard_Real>^ Ku);

        //! Returns the uknots sequence.
        //! In this sequence the knots with a multiplicity greater than 1
        //! are repeated.
        //! Example :
        //! Ku = {k1, k1, k1, k2, k3, k3, k4, k4, k4}
        array<Standard_Real>^ UKnotSequence();


        //! Returns the multiplicity value of knot of range UIndex in
        //! the u direction.
        //! Raised if UIndex < 1 or UIndex > NbUKnots.
        Standard_Integer UMultiplicity(Standard_Integer UIndex);


        //! Returns the multiplicities of the knots in the U direction.
        //!
        //! Raised if the length of Mu is not equal to the number of
        //! knots in the U direction.
        void UMultiplicities(array<Standard_Integer>^ Mu);

        //! Returns the multiplicities of the knots in the U direction.
        array<Standard_Integer>^ UMultiplicities();


        //! Returns the degree of the normalized B-splines Ni,d in the
        //! V direction.
        Standard_Integer VDegree();

        //! Returns the Knot value of range VIndex.
        //! Raised if VIndex < 1 or VIndex > NbVKnots
        Standard_Real VKnot(Standard_Integer VIndex);


        //! Returns NonUniform or Uniform or QuasiUniform or
        //! PiecewiseBezier. If all the knots differ by a positive
        //! constant from the preceding knot in the V direction the
        //! B-spline surface can be :
        //! - Uniform if all the knots are of multiplicity 1,
        //! - QuasiUniform if all the knots are of multiplicity 1
        //! except for the first and last knot which are of
        //! multiplicity Degree + 1,
        //! - PiecewiseBezier if the first and last knots have
        //! multiplicity  Degree + 1 and if interior knots have
        //! multiplicity Degree
        //! otherwise the surface is non uniform in the V direction.
        //! The tolerance criterion is Resolution from package gp.
        XGeomAbs_BSplKnotDistribution VKnotDistribution();

        //! Returns the knots in the V direction.
        //!
        //! Raised if the length of Kv is not equal to the number of
        //! knots in the V direction.
        void VKnots(array<Standard_Real>^ Kv);

        //! Returns the knots in the V direction.
        array<Standard_Real>^ VKnots();

        //! Returns the vknots sequence.
        //! In this sequence the knots with a multiplicity greater than 1
        //! are repeated.
        //! Example :
        //! Kv = {k1, k1, k1, k2, k3, k3, k4, k4, k4}
        //!
        //! Raised if the length of Kv is not equal to NbVPoles + VDegree + 1
        void VKnotSequence(array<Standard_Real>^ Kv);

        //! Returns the vknots sequence.
        //! In this sequence the knots with a multiplicity greater than 1
        //! are repeated.
        //! Example :
        //! Ku = {k1, k1, k1, k2, k3, k3, k4, k4, k4}
        array<Standard_Real>^ VKnotSequence();


        //! Returns the multiplicity value of knot of range VIndex in
        //! the v direction.
        //! Raised if VIndex < 1 or VIndex > NbVKnots
        Standard_Integer VMultiplicity(Standard_Integer VIndex);


        //! Returns the multiplicities of the knots in the V direction.
        //!
        //! Raised if the length of Mv is not equal to the number of
        //! knots in the V direction.
        void VMultiplicities(array<Standard_Integer>^ Mv);

        //! Returns the multiplicities of the knots in the V direction.
        array<Standard_Integer>^ VMultiplicities();

        //! Returns the weight value of range UIndex, VIndex.
        //!
        //! Raised if UIndex < 1 or UIndex > NbUPoles or VIndex < 1
        //! or VIndex > NbVPoles.
        Standard_Real Weight(Standard_Integer UIndex, Standard_Integer VIndex);

        //! Returns the weights of the B-spline surface.
        //!
        //! Raised if the length of W in the U and V direction is
        //! not equal to NbUPoles and NbVPoles.
        void Weights(array<Standard_Real, 2>^ W);

        //! Returns the weights of the B-spline surface.
        //! value and derivatives computation
        array<Standard_Real, 2>^ Weights();

        void D0(Standard_Real U, Standard_Real V, xgp_Pnt^ P) Standard_OVERRIDE;

        //! Raised if the continuity of the surface is not C1.
        void D1(Standard_Real U, Standard_Real V, xgp_Pnt^ P, xgp_Vec^ D1U, xgp_Vec^ D1V) Standard_OVERRIDE;

        //! Raised if the continuity of the surface is not C2.
        void D2(Standard_Real U, Standard_Real V, xgp_Pnt^ P, xgp_Vec^ D1U, xgp_Vec^ D1V, xgp_Vec^ D2U, xgp_Vec^ D2V, xgp_Vec^ D2UV) Standard_OVERRIDE;

        //! Raised if the continuity of the surface is not C3.
        void D3(Standard_Real U, Standard_Real V, xgp_Pnt^ P, xgp_Vec^ D1U, xgp_Vec^ D1V, xgp_Vec^ D2U, xgp_Vec^ D2V, xgp_Vec^ D2UV, xgp_Vec^ D3U, xgp_Vec^ D3V, xgp_Vec^ D3UUV, xgp_Vec^ D3UVV) Standard_OVERRIDE;


        //! Nu is the order of derivation in the U parametric direction and
        //! Nv is the order of derivation in the V parametric direction.
        //!
        //! Raised if the continuity of the surface is not CNu in the U
        //! direction and CNv in the V direction.
        //!
        //! Raised if Nu + Nv < 1 or Nu < 0 or Nv < 0.
        //!
        //! The following functions computes the point for the
        //! parametric values (U, V) and the derivatives at
        //! this point on the B-spline surface patch delimited
        //! with the knots FromUK1, FromVK1 and the knots ToUK2,
        //! ToVK2.  (U, V) can be out of these parametric bounds
        //! but for the computation we only use the definition
        //! of the surface between these knots. This method is
        //! useful to compute local derivative, if the order of
        //! continuity of the whole surface is not greater enough.
        //! Inside the parametric knot's domain previously defined
        //! the evaluations are the same as if we consider the whole
        //! definition of the surface. Of course the evaluations are
        //! different outside this parametric domain.
        xgp_Vec^ DN(Standard_Real U, Standard_Real V, Standard_Integer Nu, Standard_Integer Nv) Standard_OVERRIDE;

        //! Raised if FromUK1 = ToUK2 or FromVK1 = ToVK2.
        void LocalD0(Standard_Real U, Standard_Real V, Standard_Integer FromUK1, Standard_Integer ToUK2, Standard_Integer FromVK1, Standard_Integer ToVK2, xgp_Pnt^ P);


        //! Raised if the local continuity of the surface is not C1
        //! between the knots FromUK1, ToUK2 and FromVK1, ToVK2.
        //! Raised if FromUK1 = ToUK2 or FromVK1 = ToVK2.
        void LocalD1(Standard_Real U, Standard_Real V, Standard_Integer FromUK1, Standard_Integer ToUK2, Standard_Integer FromVK1, Standard_Integer ToVK2, xgp_Pnt^ P, xgp_Vec^ D1U, xgp_Vec^ D1V);


        //! Raised if the local continuity of the surface is not C2
        //! between the knots FromUK1, ToUK2 and FromVK1, ToVK2.
        //! Raised if FromUK1 = ToUK2 or FromVK1 = ToVK2.
        void LocalD2(Standard_Real U, Standard_Real V, Standard_Integer FromUK1, Standard_Integer ToUK2, Standard_Integer FromVK1, Standard_Integer ToVK2, xgp_Pnt^ P, xgp_Vec^ D1U, xgp_Vec^ D1V, xgp_Vec^ D2U, xgp_Vec^ D2V, xgp_Vec^ D2UV);


        //! Raised if the local continuity of the surface is not C3
        //! between the knots FromUK1, ToUK2 and FromVK1, ToVK2.
        //! Raised if FromUK1 = ToUK2 or FromVK1 = ToVK2.
        void LocalD3(Standard_Real U, Standard_Real V, Standard_Integer FromUK1, Standard_Integer ToUK2, Standard_Integer FromVK1, Standard_Integer ToVK2, xgp_Pnt^ P, xgp_Vec^ D1U, xgp_Vec^ D1V, xgp_Vec^ D2U, xgp_Vec^ D2V, xgp_Vec^ D2UV, xgp_Vec^ D3U, xgp_Vec^ D3V, xgp_Vec^ D3UUV, xgp_Vec^ D3UVV);


        //! Raised if the local continuity of the surface is not CNu
        //! between the knots FromUK1, ToUK2 and CNv between the knots
        //! FromVK1, ToVK2.
        //! Raised if FromUK1 = ToUK2 or FromVK1 = ToVK2.
        xgp_Vec^ LocalDN(Standard_Real U, Standard_Real V, Standard_Integer FromUK1, Standard_Integer ToUK2, Standard_Integer FromVK1, Standard_Integer ToVK2, Standard_Integer Nu, Standard_Integer Nv);


        //! Computes the point of parameter U, V on the BSpline surface patch
        //! defines between the knots UK1 UK2, VK1, VK2. U can be out of the
        //! bounds [Knot UK1, Knot UK2] and V can be outof the bounds
        //! [Knot VK1, Knot VK2]  but for the computation we only use the
        //! definition of the surface between these knot values.
        //! Raises if FromUK1 = ToUK2 or FromVK1 = ToVK2.
        xgp_Pnt^ LocalValue(Standard_Real U, Standard_Real V, Standard_Integer FromUK1, Standard_Integer ToUK2, Standard_Integer FromVK1, Standard_Integer ToVK2);


        //! Computes the U isoparametric curve.
        //! A B-spline curve is returned.
        XGeom_Curve^ UIso(Standard_Real U) Standard_OVERRIDE;


        //! Computes the V isoparametric curve.
        //! A B-spline curve is returned.
        XGeom_Curve^ VIso(Standard_Real V) Standard_OVERRIDE;


        //! Computes the U isoparametric curve.
        //! If CheckRational=False, no try to make it non-rational.
        //! A B-spline curve is returned.
        XGeom_Curve^ UIso(Standard_Real U, Standard_Boolean CheckRational);


        //! Computes the V isoparametric curve.
        //! If CheckRational=False, no try to make it non-rational.
        //! A B-spline curve is returned.
        //! transformations
        XGeom_Curve^ VIso(Standard_Real V, Standard_Boolean CheckRational);

        //! Applies the transformation T to this BSpline surface.
        void Transform(xgp_Trsf^ T) Standard_OVERRIDE;


        //! Returns the value of the maximum degree of the normalized
        //! B-spline basis functions in the u and v directions.
        static Standard_Integer MaxDegree();

        //! Computes two tolerance values for this BSpline
        //! surface, based on the given tolerance in 3D space
        //! Tolerance3D. The tolerances computed are:
        //! - UTolerance in the u parametric direction, and
        //! - VTolerance in the v parametric direction.
        //! If f(u,v) is the equation of this BSpline surface,
        //! UTolerance and VTolerance guarantee that :
        //! | u1 - u0 | < UTolerance and
        //! | v1 - v0 | < VTolerance
        //! ====> |f (u1,v1) - f (u0,v0)| < Tolerance3D
        void Resolution(Standard_Real Tolerance3D, Standard_Real% UTolerance, Standard_Real% VTolerance);

        //! Creates a new object which is a copy of this BSpline surface.
        XGeom_Geometry^ Copy() Standard_OVERRIDE;




        //DEFINE_STANDARD_RTTIEXT(Geom_BSplineSurface, Geom_BoundedSurface)
        virtual property Handle(Standard_Transient) IHandle {
            Handle(Standard_Transient) get() Standard_OVERRIDE {
                return NativeHandle();
            }
            void set(Handle(Standard_Transient) handle) Standard_OVERRIDE {
                NativeHandle() = Handle(Geom_BSplineSurface)::DownCast(handle);
            }
        };

    private:
        NCollection_Haft<Handle(Geom_BSplineSurface)> NativeHandle;
    };
}
#endif // _XGeom_BSplineSurface_HeaderFile
