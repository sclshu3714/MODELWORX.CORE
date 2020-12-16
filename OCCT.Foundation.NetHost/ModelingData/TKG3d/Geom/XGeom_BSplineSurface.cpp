#include "XGeom_BSplineSurface.h"
namespace TKG3d {
    //!
    XGeom_BSplineSurface::XGeom_BSplineSurface(void) {
        //NativeHandle() = new Geom_BSplineSurface();
    };

    //! 
    XGeom_BSplineSurface::XGeom_BSplineSurface(Handle(Geom_BSplineSurface) pos) {
        NativeHandle() = pos;
        SetBoundedSurfaceHandle(NativeHandle());
    };

    //!
    XGeom_BSplineSurface::~XGeom_BSplineSurface() {
        NativeHandle() = NULL;
        SetBoundedSurfaceHandle(NativeHandle());
    };

    void XGeom_BSplineSurface::SetBSplineSurfaceHandle(Handle(Geom_BSplineSurface) handle) {
        NativeHandle() = handle;
        SetBoundedSurfaceHandle(NativeHandle());
    };

    //!
    Handle(Geom_BSplineSurface) XGeom_BSplineSurface::GetBSplineSurface() {
        return NativeHandle();
    };

    //!
    Handle(Geom_BoundedSurface) XGeom_BSplineSurface::GetBoundedSurface() {
        return NativeHandle();
    };

    //!
    Handle(Geom_Surface) XGeom_BSplineSurface::GetSurface() {
        return NativeHandle();
    };

    //!
    Handle(Geom_Geometry) XGeom_BSplineSurface::GetGeometry() {
        return NativeHandle();
    };

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
    XGeom_BSplineSurface::XGeom_BSplineSurface(array<xgp_Pnt^, 2>^ Poles, array<Standard_Real>^ UKnots, array<Standard_Real>^ VKnots, array<Standard_Integer>^ UMults, array<Standard_Integer>^ VMults, Standard_Integer UDegree, Standard_Integer VDegree, Standard_Boolean UPeriodic, Standard_Boolean VPeriodic) {
        TColgp_Array2OfPnt XPoles; TColStd_Array1OfReal XUKnots; TColStd_Array1OfReal XVKnots; TColStd_Array1OfInteger XUMults; TColStd_Array1OfInteger XVMults;
        for (Standard_Integer i = 0; i < Poles->Length; i++) {
            for (Standard_Integer j = 0; j < Poles->GetLength(i); j++) {
                xgp_Pnt^ gpPnt = (xgp_Pnt^)Poles->GetValue(i, j);
                XPoles.SetValue(i, j, *gpPnt->GetPnt());
            }
        }
        for (Standard_Integer i = 0; i < UKnots->Length; i++) {
            Standard_Real XReal = (Standard_Real)UKnots->GetValue(i);
            XUKnots.SetValue(i, XReal);
        }
        for (Standard_Integer i = 0; i < VKnots->Length; i++) {
            Standard_Real XReal = (Standard_Real)VKnots->GetValue(i);
            XVKnots.SetValue(i, XReal);
        }
        for (Standard_Integer i = 0; i < UMults->Length; i++) {
            Standard_Integer XReal = (Standard_Integer)UMults->GetValue(i);
            XUMults.SetValue(i, XReal);
        }
        for (Standard_Integer i = 0; i < VMults->Length; i++) {
            Standard_Integer XReal = (Standard_Integer)VMults->GetValue(i);
            XVMults.SetValue(i, XReal);
        }
        NativeHandle() = new Geom_BSplineSurface(XPoles, XUKnots, XVKnots, XUMults, XVMults, UDegree, VDegree, UPeriodic, VPeriodic);
        SetBoundedSurfaceHandle(NativeHandle());
    };
    ;
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
    XGeom_BSplineSurface::XGeom_BSplineSurface(array<xgp_Pnt^, 2>^ Poles, array<Standard_Real, 2>^ Weights, array<Standard_Real>^ UKnots, array<Standard_Real>^ VKnots, array<Standard_Integer>^ UMults, array<Standard_Integer>^ VMults, Standard_Integer UDegree, Standard_Integer VDegree, Standard_Boolean UPeriodic, Standard_Boolean VPeriodic) {
        //const TColgp_Array2OfPnt& Poles, const TColStd_Array2OfReal& Weights, const TColStd_Array1OfReal& UKnots, const TColStd_Array1OfReal& VKnots, const TColStd_Array1OfInteger& UMults
        TColgp_Array2OfPnt XPoles; TColStd_Array2OfReal XWeights; TColStd_Array1OfReal XUKnots; TColStd_Array1OfReal XVKnots; TColStd_Array1OfInteger XUMults; TColStd_Array1OfInteger XVMults;
        for (Standard_Integer i = 0; i < Poles->Length; i++) {
            for (Standard_Integer j = 0; j < Poles->GetLength(i); j++) {
                xgp_Pnt^ gpPnt = (xgp_Pnt^)Poles->GetValue(i, j);
                XPoles.SetValue(i, j, *gpPnt->GetPnt());
            }
        }
        for (Standard_Integer i = 0; i < Weights->Length; i++) {
            for (Standard_Integer j = 0; j < Weights->GetLength(i); j++) {
                Standard_Real XReal = (Standard_Real)Weights->GetValue(i, j);
                XWeights.SetValue(i, j, XReal);
            }
        }
        for (Standard_Integer i = 0; i < UKnots->Length; i++) {
            Standard_Real XReal = (Standard_Real)UKnots->GetValue(i);
            XUKnots.SetValue(i, XReal);
        }
        for (Standard_Integer i = 0; i < VKnots->Length; i++) {
            Standard_Real XReal = (Standard_Real)VKnots->GetValue(i);
            XVKnots.SetValue(i, XReal);
        }
        for (Standard_Integer i = 0; i < UMults->Length; i++) {
            Standard_Integer XInteger = (Standard_Integer)UMults->GetValue(i);
            XUMults.SetValue(i, XInteger);
        }
        for (Standard_Integer i = 0; i < VMults->Length; i++) {
            Standard_Integer XInteger = (Standard_Integer)VMults->GetValue(i);
            XVMults.SetValue(i, XInteger);
        }
        NativeHandle() = new Geom_BSplineSurface(XPoles, XWeights, XUKnots, XVKnots, XUMults, XVMults, UDegree, VDegree, UPeriodic, VPeriodic);
        SetBoundedSurfaceHandle(NativeHandle());
    };

    //! Exchanges the u and v parametric directions on
    //! this BSpline surface.
    //! As a consequence:
    //! - the poles and weights tables are transposed,
    //! - the knots and multiplicities tables are exchanged,
    //! - degrees of continuity, and rational, periodic and
    //! uniform characteristics are exchanged, and
    //! - the orientation of the surface is inverted.
    void XGeom_BSplineSurface::ExchangeUV() {
        NativeHandle()->ExchangeUV();
    };

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
    void XGeom_BSplineSurface::SetUPeriodic() {
        NativeHandle()->SetUPeriodic();
    };

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
    void XGeom_BSplineSurface::SetVPeriodic() {
        NativeHandle()->SetVPeriodic();
    };

    //! returns the parameter normalized within
    //! the period if the surface is periodic : otherwise
    //! does not do anything
    void XGeom_BSplineSurface::PeriodicNormalization(Standard_Real% U, Standard_Real% V) {
        Standard_Real XU = Standard_Real(U); Standard_Real XV = Standard_Real(V);
        NativeHandle()->PeriodicNormalization(XU, XV);
        U = XU; V = XV;
    };

    //! Assigns the knot of index Index in the knots table in
    //! the corresponding parametric direction to be the
    //! origin of this periodic BSpline surface. As a
    //! consequence, the knots and poles tables are modified.
    //! Exceptions
    //! Standard_NoSuchObject if this BSpline surface is
    //! not periodic in the given parametric direction.
    //! Standard_DomainError if Index is outside the
    //! bounds of the knots table in the given parametric direction.
    void XGeom_BSplineSurface::SetUOrigin(Standard_Integer Index) {
        NativeHandle()->SetUOrigin(Index);
    };

    //! Assigns the knot of index Index in the knots table in
    //! the corresponding parametric direction to be the
    //! origin of this periodic BSpline surface. As a
    //! consequence, the knots and poles tables are modified.
    //! Exceptions
    //! Standard_NoSuchObject if this BSpline surface is
    //! not periodic in the given parametric direction.
    //! Standard_DomainError if Index is outside the
    //! bounds of the knots table in the given parametric direction.
    void XGeom_BSplineSurface::SetVOrigin(Standard_Integer Index) {
        NativeHandle()->SetVOrigin(Index);
    };

    //! Sets the surface U not periodic.
    //! Changes this BSpline surface into a non-periodic
    //! surface along U direction. 
    //! If this surface is already non-periodic, it is not modified.
    //! Note: the poles and knots tables are modified.
    void XGeom_BSplineSurface::SetUNotPeriodic() {
        NativeHandle()->SetUNotPeriodic();
    };

    //! Sets the surface V not periodic.
    //! Changes this BSpline surface into a non-periodic
    //! surface along V direction. 
    //! If this surface is already non-periodic, it is not modified.
    //! Note: the poles and knots tables are modified.
    void XGeom_BSplineSurface::SetVNotPeriodic() {
        NativeHandle()->SetVNotPeriodic();
    };

    //! Changes the orientation of this BSpline surface in the
    //! U parametric direction. The bounds of the
    //! surface are not changed but the given parametric
    //! direction is reversed. Hence the orientation of the
    //! surface is reversed.
    //! The knots and poles tables are modified.
    void XGeom_BSplineSurface::UReverse() {
        NativeHandle()->UReverse();
    };

    //! Changes the orientation of this BSpline surface in the
    //! V parametric direction. The bounds of the
    //! surface are not changed but the given parametric
    //! direction is reversed. Hence the orientation of the
    //! surface is reversed.
    //! The knots and poles tables are modified.
    void XGeom_BSplineSurface::VReverse() {
        NativeHandle()->VReverse();
    };

    //! Computes the u parameter on the modified
    //! surface, produced by reversing its U parametric
    //! direction, for the point of u parameter U,  on this BSpline surface.
    //! For a BSpline surface, these functions return respectively:
    //! - UFirst + ULast - U, 
    //! where UFirst, ULast are
    //! the values of the first and last parameters of this
    //! BSpline surface, in the u parametric directions.
    Standard_Real XGeom_BSplineSurface::UReversedParameter(Standard_Real U) {
       return NativeHandle()->UReversedParameter(U);
    };

    //! Computes the v parameter on the modified
    //! surface, produced by reversing its V parametric
    //! direction, for the point of v parameter V on this BSpline surface.
    //! For a BSpline surface, these functions return respectively:
    //! - VFirst + VLast - V,
    //! VFirst and VLast are
    //! the values of the first and last parameters of this
    //! BSpline surface, in the v pametric directions.
    Standard_Real XGeom_BSplineSurface::VReversedParameter(Standard_Real V) {
        return NativeHandle()->VReversedParameter(V);
    };

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
    void XGeom_BSplineSurface::IncreaseDegree(Standard_Integer UDegree, Standard_Integer VDegree) {
        NativeHandle()->IncreaseDegree(UDegree, VDegree);
    };

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
    void XGeom_BSplineSurface::InsertUKnots(array<Standard_Real>^ Knots, array<Standard_Integer>^ Mults, Standard_Real ParametricTolerance, Standard_Boolean Add) {
        TColStd_Array1OfReal XKnots; TColStd_Array1OfInteger XMults;
        for (Standard_Integer i = 0; i < Knots->Length; i++) {
            Standard_Real XReal = (Standard_Real)Knots->GetValue(i);
            XKnots.SetValue(i, XReal);
        }
        for (Standard_Integer i = 0; i < Mults->Length; i++) {
            Standard_Real XReal = (Standard_Real)Mults->GetValue(i);
            XMults.SetValue(i, XReal);
        }
        NativeHandle()->InsertUKnots(XKnots, XMults, ParametricTolerance, Add);
    };

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
    void XGeom_BSplineSurface::InsertVKnots(array<Standard_Real>^ Knots, array<Standard_Integer>^ Mults, Standard_Real ParametricTolerance, Standard_Boolean Add) {
        TColStd_Array1OfReal XKnots; TColStd_Array1OfInteger XMults;
        for (Standard_Integer i = 0; i < Knots->Length; i++) {
            Standard_Real XReal = (Standard_Real)Knots->GetValue(i);
            XKnots.SetValue(i, XReal);
        }
        for (Standard_Integer i = 0; i < Mults->Length; i++) {
            Standard_Real XReal = (Standard_Real)Mults->GetValue(i);
            XMults.SetValue(i, XReal);
        }
        NativeHandle()->InsertVKnots(XKnots, XMults, ParametricTolerance, Add);
    };

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
    Standard_Boolean XGeom_BSplineSurface::RemoveUKnot(Standard_Integer Index, Standard_Integer M, Standard_Real Tolerance) {
        return NativeHandle()->RemoveUKnot(Index, M, Tolerance);
    };

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
    Standard_Boolean XGeom_BSplineSurface::RemoveVKnot(Standard_Integer Index, Standard_Integer M, Standard_Real Tolerance) {
        return NativeHandle()->RemoveVKnot(Index, M, Tolerance);
    };


    //! Increases the multiplicity of the knot of range UIndex
    //! in the UKnots sequence.
    //! M is the new multiplicity. M must be greater than the
    //! previous multiplicity and lower or equal to the degree
    //! of the surface in the U parametric direction.
    //! Raised if M is not in the range [1, UDegree]
    //!
    //! Raised if UIndex is not in the range [FirstUKnotIndex,
    //! LastUKnotIndex] given by the methods with the same name.
    void XGeom_BSplineSurface::IncreaseUMultiplicity(Standard_Integer UIndex, Standard_Integer M) {
        NativeHandle()->IncreaseUMultiplicity(UIndex, M);
    };


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
    void XGeom_BSplineSurface::IncreaseUMultiplicity(Standard_Integer FromI1, Standard_Integer ToI2, Standard_Integer M) {
        NativeHandle()->IncreaseUMultiplicity(FromI1, ToI2, M);
    };


    //! Increments the multiplicity of the consecutives uknots FromI1..ToI2
    //! by step.   The multiplicity of each knot FromI1,.....,ToI2 must be
    //! lower or equal to the UDegree of the B_spline.
    //!
    //! Raised if FromI1 or ToI2 is not in the range
    //! [FirstUKnotIndex, LastUKnotIndex]
    //!
    //! Raised if one knot has a multiplicity greater than UDegree.
    void XGeom_BSplineSurface::IncrementUMultiplicity(Standard_Integer FromI1, Standard_Integer ToI2, Standard_Integer Step) {
        NativeHandle()->IncrementUMultiplicity(FromI1, ToI2, Step);
    };


    //! Increases the multiplicity of a knot in the V direction.
    //! M is the new multiplicity.
    //!
    //! M should be greater than the previous multiplicity and lower
    //! than the degree of the surface in the V parametric direction.
    //!
    //! Raised if VIndex is not in the range [FirstVKnotIndex,
    //! LastVKnotIndex] given by the methods with the same name.
    void XGeom_BSplineSurface::IncreaseVMultiplicity(Standard_Integer VIndex, Standard_Integer M) {
        NativeHandle()->IncreaseVMultiplicity(VIndex, M);
    };


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
    void XGeom_BSplineSurface::IncreaseVMultiplicity(Standard_Integer FromI1, Standard_Integer ToI2, Standard_Integer M) {
        NativeHandle()->IncreaseVMultiplicity(FromI1, ToI2, M);
    };


    //! Increments the multiplicity of the consecutives vknots FromI1..ToI2
    //! by step.  The multiplicity of each knot FromI1,.....,ToI2 must be
    //! lower or equal to the VDegree of the B_spline.
    //!
    //! Raised if FromI1 or ToI2 is not in the range
    //! [FirstVKnotIndex, LastVKnotIndex]
    //!
    //! Raised if one knot has a multiplicity greater than VDegree.
    void XGeom_BSplineSurface::IncrementVMultiplicity(Standard_Integer FromI1, Standard_Integer ToI2, Standard_Integer Step) {
        NativeHandle()->IncrementVMultiplicity(FromI1, ToI2, Step);
    };


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
    void XGeom_BSplineSurface::InsertUKnot(Standard_Real U, Standard_Integer M, Standard_Real ParametricTolerance, Standard_Boolean Add) {
        NativeHandle()->InsertUKnot(U, M, ParametricTolerance, Add);
    };


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
    void XGeom_BSplineSurface::InsertVKnot(Standard_Real V, Standard_Integer M, Standard_Real ParametricTolerance, Standard_Boolean Add) {
        NativeHandle()->InsertVKnot(V, M, ParametricTolerance, Add);
    };


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
    void XGeom_BSplineSurface::Segment(Standard_Real U1, Standard_Real U2, Standard_Real V1, Standard_Real V2, Standard_Real theUTolerance, Standard_Real theVTolerance) {
        NativeHandle()->Segment(U1, U2, V1, V2, theUTolerance, theVTolerance);
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
    void XGeom_BSplineSurface::CheckAndSegment(Standard_Real U1, Standard_Real U2, Standard_Real V1, Standard_Real V2, Standard_Real theUTolerance, Standard_Real theVTolerance) {
        NativeHandle()->CheckAndSegment(U1, U2, V1, V2, theUTolerance, theVTolerance);
    };


    //! Substitutes the UKnots of range UIndex with K.
    //!
    //! Raised if UIndex < 1 or UIndex > NbUKnots
    //!
    //! Raised if K >= UKnots(UIndex+1) or K <= UKnots(UIndex-1)
    void XGeom_BSplineSurface::SetUKnot(Standard_Integer UIndex, Standard_Real K) {
        NativeHandle()->SetUKnot(UIndex, K);
    };

    //! Changes all the U-knots of the surface.
    //! The multiplicity of the knots are not modified.
    //!
    //! Raised if there is an index such that UK (Index+1) <= UK (Index).
    //!
    //! Raised if  UK.Lower() < 1 or UK.Upper() > NbUKnots
    void XGeom_BSplineSurface::SetUKnots(array<Standard_Real>^ UK) {
        TColStd_Array1OfReal XUK;
        for (Standard_Integer i = 0; i < UK->Length; i++) {
            Standard_Real XReal = (Standard_Real)UK->GetValue(i);
            XUK.SetValue(i, XReal);
        }
        NativeHandle()->SetUKnots(XUK);
    };


    //! Changes the value of the UKnots of range UIndex and
    //! increases its multiplicity.
    //!
    //! Raised if UIndex is not in the range [FirstUKnotIndex,
    //! LastUKnotIndex] given by the methods with the same name.
    //!
    //! Raised if K >= UKnots(UIndex+1) or K <= UKnots(UIndex-1)
    //! M must be lower than UDegree and greater than the previous
    //! multiplicity of the knot of range UIndex.
    void XGeom_BSplineSurface::SetUKnot(Standard_Integer UIndex, Standard_Real K, Standard_Integer M) {
        NativeHandle()->SetUKnot(UIndex, K, M);
    };

    //! Substitutes the VKnots of range VIndex with K.
    //!
    //! Raised if VIndex < 1 or VIndex > NbVKnots
    //!
    //! Raised if K >= VKnots(VIndex+1) or K <= VKnots(VIndex-1)
    void XGeom_BSplineSurface::SetVKnot(Standard_Integer VIndex, Standard_Real K) {
        NativeHandle()->SetVKnot(VIndex, K);
    };

    //! Changes all the V-knots of the surface.
    //! The multiplicity of the knots are not modified.
    //!
    //! Raised if there is an index such that VK (Index+1) <= VK (Index).
    //!
    //! Raised if  VK.Lower() < 1 or VK.Upper() > NbVKnots
    void XGeom_BSplineSurface::SetVKnots(array<Standard_Real>^ VK) {
        TColStd_Array1OfReal XVK;
        for (Standard_Integer i = 0; i < VK->Length; i++) {
            Standard_Real XReal = (Standard_Real)VK->GetValue(i);
            XVK.SetValue(i, XReal);
        }
        NativeHandle()->SetVKnots(XVK);
    };


    //! Changes the value of the VKnots of range VIndex and increases
    //! its multiplicity.
    //!
    //! Raised if VIndex is not in the range [FirstVKnotIndex,
    //! LastVKnotIndex] given by the methods with the same name.
    //!
    //! Raised if K >= VKnots(VIndex+1) or K <= VKnots(VIndex-1)
    //! M must be lower than VDegree and greater than the previous
    //! multiplicity of the knot of range VIndex.
    void XGeom_BSplineSurface::SetVKnot(Standard_Integer VIndex, Standard_Real K, Standard_Integer M) {
        NativeHandle()->SetVKnot(VIndex, K, M);
    };


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
    void XGeom_BSplineSurface::LocateU(Standard_Real U, Standard_Real ParametricTolerance, Standard_Integer% I1, Standard_Integer% I2, Standard_Boolean WithKnotRepetition) {
        Standard_Integer XI1 = Standard_Integer(I1); Standard_Integer XI2 = Standard_Integer(I2);
        NativeHandle()->LocateU(U, ParametricTolerance, XI1, XI2, WithKnotRepetition);
        I1 = XI1; I2 = XI2;
    };


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
    void XGeom_BSplineSurface::LocateV(Standard_Real V, Standard_Real ParametricTolerance, Standard_Integer% I1, Standard_Integer% I2, Standard_Boolean WithKnotRepetition) {
        Standard_Integer XI1 = Standard_Integer(I1); Standard_Integer XI2 = Standard_Integer(I2);
        NativeHandle()->LocateV(V, ParametricTolerance, XI1, XI2, WithKnotRepetition);
        I1 = XI1; I2 = XI2;
    };


    //! Substitutes the pole of range (UIndex, VIndex) with P.
    //! If the surface is rational the weight of range (UIndex, VIndex)
    //! is not modified.
    //!
    //! Raised if UIndex < 1 or UIndex > NbUPoles or VIndex < 1 or
    //! VIndex > NbVPoles.
    void XGeom_BSplineSurface::SetPole(Standard_Integer UIndex, Standard_Integer VIndex, xgp_Pnt^ P) {
        NativeHandle()->SetPole(UIndex, VIndex, *P->GetPnt());
    };


    //! Substitutes the pole and the weight of range (UIndex, VIndex)
    //! with P and W.
    //!
    //! Raised if UIndex < 1 or UIndex > NbUPoles or VIndex < 1 or
    //! VIndex > NbVPoles.
    //! Raised if Weight <= Resolution from package gp.
    void XGeom_BSplineSurface::SetPole(Standard_Integer UIndex, Standard_Integer VIndex, xgp_Pnt^ P, Standard_Real Weight) {
        NativeHandle()->SetPole(UIndex, VIndex, *P->GetPnt(), Weight);
    };


    //! Changes a column of poles or a part of this column.
    //! Raised if Vindex < 1 or VIndex > NbVPoles.
    //!
    //! Raised if CPoles.Lower() < 1 or CPoles.Upper() > NbUPoles.
    void XGeom_BSplineSurface::SetPoleCol(Standard_Integer VIndex, array<xgp_Pnt^>^ CPoles) {
        TColgp_Array1OfPnt TCPoles;
        for (Standard_Integer i = 0; i < CPoles->Length; i++) {
            xgp_Pnt^ gpPnt = (xgp_Pnt^)CPoles->GetValue(i);
            TCPoles.SetValue(i, *gpPnt->GetPnt());
        }
        NativeHandle()->SetPoleCol(VIndex, TCPoles);
    };


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
    void XGeom_BSplineSurface::SetPoleCol(Standard_Integer VIndex, array<xgp_Pnt^>^ CPoles, array<Standard_Real>^ CPoleWeights) {
        TColgp_Array1OfPnt TCPoles;
        for (Standard_Integer i = 0; i < CPoles->Length; i++) {
            xgp_Pnt^ gpPnt = (xgp_Pnt^)CPoles->GetValue(i);
            TCPoles.SetValue(i, *gpPnt->GetPnt());
        }
        TColStd_Array1OfReal TCPoleWeights;
        for (Standard_Integer i = 0; i < CPoleWeights->Length; i++) {
            Standard_Real XReal = (Standard_Real)CPoleWeights->GetValue(i);
            TCPoleWeights.SetValue(i, XReal);
        }
        NativeHandle()->SetPoleCol(VIndex, TCPoles, TCPoleWeights);
    };


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
    void XGeom_BSplineSurface::SetPoleRow(Standard_Integer UIndex, array<xgp_Pnt^>^ CPoles, array<Standard_Real>^ CPoleWeights) {
        TColgp_Array1OfPnt TCPoles;
        for (Standard_Integer i = 0; i < CPoles->Length; i++) {
            xgp_Pnt^ gpPnt = (xgp_Pnt^)CPoles->GetValue(i);
            TCPoles.SetValue(i, *gpPnt->GetPnt());
        }
        TColStd_Array1OfReal TCPoleWeights;
        for (Standard_Integer i = 0; i < CPoleWeights->Length; i++) {
            Standard_Real XReal = (Standard_Real)CPoleWeights->GetValue(i);
            TCPoleWeights.SetValue(i, XReal);
        }
        NativeHandle()->SetPoleRow(UIndex, TCPoles, TCPoleWeights);
    };


    //! Changes a row of poles or a part of this row.
    //! Raised if Uindex < 1 or UIndex > NbUPoles.
    //!
    //! Raised if CPoles.Lower() < 1 or CPoles.Upper() > NbVPoles.
    void XGeom_BSplineSurface::SetPoleRow(Standard_Integer UIndex, array<xgp_Pnt^>^ CPoles) {
        TColgp_Array1OfPnt TCPoles;
        for (Standard_Integer i = 0; i < CPoles->Length; i++) {
            xgp_Pnt^ gpPnt = (xgp_Pnt^)CPoles->GetValue(i);
            TCPoles.SetValue(i, *gpPnt->GetPnt());
        }
        NativeHandle()->SetPoleRow(UIndex, TCPoles);
    };


    //! Changes the weight of the pole of range UIndex, VIndex.
    //! If the surface was non rational it can become rational.
    //! If the surface was rational it can become non rational.
    //!
    //! Raised if UIndex < 1 or UIndex > NbUPoles or VIndex < 1 or
    //! VIndex > NbVPoles
    //!
    //! Raised if weight is lower or equal to Resolution from
    //! package gp
    void XGeom_BSplineSurface::SetWeight(Standard_Integer UIndex, Standard_Integer VIndex, Standard_Real Weight) {
        NativeHandle()->SetWeight(UIndex, VIndex, Weight);
    };


    //! Changes a column of weights of a part of this column.
    //!
    //! Raised if VIndex < 1 or VIndex > NbVPoles
    //!
    //! Raised if CPoleWeights.Lower() < 1 or
    //! CPoleWeights.Upper() > NbUPoles.
    //! Raised if a weight value is lower or equal to Resolution
    //! from package gp.
    void XGeom_BSplineSurface::SetWeightCol(Standard_Integer VIndex, array<Standard_Real>^ CPoleWeights) {
        TColStd_Array1OfReal TCPoleWeights;
        for (Standard_Integer i = 0; i < CPoleWeights->Length; i++) {
            Standard_Real XReal = (Standard_Real)CPoleWeights->GetValue(i);
            TCPoleWeights.SetValue(i, XReal);
        }
        NativeHandle()->SetWeightCol(VIndex, TCPoleWeights);
    };


    //! Changes a row of weights or a part of this row.
    //!
    //! Raised if UIndex < 1 or UIndex > NbUPoles
    //!
    //! Raised if CPoleWeights.Lower() < 1 or
    //! CPoleWeights.Upper() > NbVPoles.
    //! Raised  if a weight value is lower or equal to Resolution
    //! from package gp.
    void XGeom_BSplineSurface::SetWeightRow(Standard_Integer UIndex, array<Standard_Real>^ CPoleWeights) {
        TColStd_Array1OfReal TCPoleWeights;
        for (Standard_Integer i = 0; i < CPoleWeights->Length; i++) {
            Standard_Real XReal = (Standard_Real)CPoleWeights->GetValue(i);
            TCPoleWeights.SetValue(i, XReal);
        }
        NativeHandle()->SetWeightRow(UIndex, TCPoleWeights);
    };

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
    void XGeom_BSplineSurface::MovePoint(Standard_Real U, Standard_Real V, xgp_Pnt^ P, Standard_Integer UIndex1, Standard_Integer UIndex2, Standard_Integer VIndex1, Standard_Integer VIndex2, Standard_Integer% UFirstIndex, Standard_Integer% ULastIndex, Standard_Integer% VFirstIndex, Standard_Integer% VLastIndex) {
        Standard_Integer XUFirstIndex = Standard_Integer(UFirstIndex); Standard_Integer XULastIndex = Standard_Integer(ULastIndex); Standard_Integer XVFirstIndex = Standard_Integer(VFirstIndex); Standard_Integer XVLastIndex = Standard_Integer(VLastIndex);
        NativeHandle()->MovePoint(U, V, *P->GetPnt(), UIndex1, UIndex2, VIndex1, VIndex2, XUFirstIndex, XULastIndex, XVFirstIndex, XVLastIndex);
        UFirstIndex = XUFirstIndex; ULastIndex = XULastIndex; VFirstIndex = XVFirstIndex; VLastIndex = XVLastIndex;
    };


    //! Returns true if the first control points row and the last
    //! control points row are identical. The tolerance criterion
    //! is Resolution from package gp.
    Standard_Boolean XGeom_BSplineSurface::IsUClosed() {
        return NativeHandle()->IsUClosed();
    };


    //! Returns true if the first control points column and the
    //! last last control points column are identical.
    //! The tolerance criterion is Resolution from package gp.
    Standard_Boolean XGeom_BSplineSurface::IsVClosed() {
        return NativeHandle()->IsVClosed();
    };


    //! Returns True if the order of continuity of the surface in the
    //! U direction  is N.
    //! Raised if N < 0.
    Standard_Boolean XGeom_BSplineSurface::IsCNu(Standard_Integer N) {
        return NativeHandle()->IsCNu(N);
    };


    //! Returns True if the order of continuity of the surface
    //! in the V direction  is N.
    //! Raised if N < 0.
    Standard_Boolean XGeom_BSplineSurface::IsCNv(Standard_Integer N) {
        return NativeHandle()->IsCNv(N);
    };


    //! Returns True if the surface is closed in the U direction
    //! and if the B-spline has been turned into a periodic surface
    //! using the function SetUPeriodic.
    Standard_Boolean XGeom_BSplineSurface::IsUPeriodic() {
        return NativeHandle()->IsUPeriodic();
    };


    //! Returns False if for each row of weights all the weights
    //! are identical.
    //! The tolerance criterion is resolution from package gp.
    //! Example :
    //! |1.0, 1.0, 1.0|
    //! if Weights =  |0.5, 0.5, 0.5|   returns False
    //! |2.0, 2.0, 2.0|
    Standard_Boolean XGeom_BSplineSurface::IsURational() {
        return NativeHandle()->IsURational();
    };


    //! Returns True if the surface is closed in the V direction
    //! and if the B-spline has been turned into a periodic
    //! surface using the function SetVPeriodic.
    Standard_Boolean XGeom_BSplineSurface::IsVPeriodic() {
        return NativeHandle()->IsVPeriodic();
    };


    //! Returns False if for each column of weights all the weights
    //! are identical.
    //! The tolerance criterion is resolution from package gp.
    //! Examples :
    //! |1.0, 2.0, 0.5|
    //! if Weights =  |1.0, 2.0, 0.5|   returns False
    //! |1.0, 2.0, 0.5|
    Standard_Boolean XGeom_BSplineSurface::IsVRational() {
        return NativeHandle()->IsVRational();
    };


    //! Returns the parametric bounds of the surface.
    //! Warnings :
    //! These parametric values are the bounds of the array of
    //! knots UKnots and VKnots only if the first knots and the
    //! last knots have a multiplicity equal to UDegree + 1 or
    //! VDegree + 1
    void XGeom_BSplineSurface::Bounds(Standard_Real% U1, Standard_Real% U2, Standard_Real% V1, Standard_Real% V2) {
        Standard_Real XU1 = Standard_Real(U1); Standard_Real XU2 = Standard_Real(U2); Standard_Real XV1 = Standard_Real(V1); Standard_Real XV2 = Standard_Real(V2);
        NativeHandle()->Bounds(XU1, XU2, XV1, XV2);
        U1 = XU1; U2 = XU2; V1 = XV1; V2 = XV2;
    };


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
    XGeomAbs_Shape XGeom_BSplineSurface::Continuity() {
        return safe_cast<XGeomAbs_Shape>(NativeHandle()->Continuity());
    };


    //! Computes the Index of the UKnots which gives the first
    //! parametric value of the surface in the U direction.
    //! The UIso curve corresponding to this value is a
    //! boundary curve of the surface.
    Standard_Integer XGeom_BSplineSurface::FirstUKnotIndex() {
        return NativeHandle()->FirstUKnotIndex();
    };


    //! Computes the Index of the VKnots which gives the
    //! first parametric value of the surface in the V direction.
    //! The VIso curve corresponding to this knot is a boundary
    //! curve of the surface.
    Standard_Integer XGeom_BSplineSurface::FirstVKnotIndex() {
        return NativeHandle()->FirstVKnotIndex();
    };


    //! Computes the Index of the UKnots which gives the
    //! last parametric value of the surface in the U direction.
    //! The UIso curve corresponding to this knot is a boundary
    //! curve of the surface.
    Standard_Integer XGeom_BSplineSurface::LastUKnotIndex() {
        return NativeHandle()->LastUKnotIndex();
    };


    //! Computes the Index of the VKnots which gives the
    //! last parametric value of the surface in the V direction.
    //! The VIso curve corresponding to this knot is a
    //! boundary curve of the surface.
    Standard_Integer XGeom_BSplineSurface::LastVKnotIndex() {
        return NativeHandle()->LastVKnotIndex();
    };

    //! Returns the number of knots in the U direction.
    Standard_Integer XGeom_BSplineSurface::NbUKnots() {
        return NativeHandle()->NbUKnots();
    };

    //! Returns number of poles in the U direction.
    Standard_Integer XGeom_BSplineSurface::NbUPoles() {
        return NativeHandle()->NbUPoles();
    };

    //! Returns the number of knots in the V direction.
    Standard_Integer XGeom_BSplineSurface::NbVKnots() {
        return NativeHandle()->NbVKnots();
    };

    //! Returns the number of poles in the V direction.
    Standard_Integer XGeom_BSplineSurface::NbVPoles() {
        return NativeHandle()->NbVPoles();
    };


    //! Returns the pole of range (UIndex, VIndex).
    //!
    //! Raised if UIndex < 1 or UIndex > NbUPoles or VIndex < 1 or
    //! VIndex > NbVPoles.
    xgp_Pnt^ XGeom_BSplineSurface::Pole(Standard_Integer UIndex, Standard_Integer VIndex) {
        gp_Pnt* temp = new gp_Pnt(NativeHandle()->Pole(UIndex, VIndex));
        return gcnew xgp_Pnt(temp);
    };

    //! Returns the poles of the B-spline surface.
    //!
    //! Raised if the length of P in the U and V direction
    //! is not equal to NbUpoles and NbVPoles.
    void XGeom_BSplineSurface::Poles(array<xgp_Pnt^, 2>^ P) {
        TColgp_Array2OfPnt XP;
        for (Standard_Integer i = 0; i < P->Length; i++) {
            for (Standard_Integer j = 0; j < P->GetLength(i); j++) {
                xgp_Pnt^ gpPnt = (xgp_Pnt^)P->GetValue(i, j);
                XP.SetValue(i, j, *gpPnt->GetPnt());
            }
        }
        NativeHandle()->Poles(XP);
    };

    //! Returns the poles of the B-spline surface.
    array<xgp_Pnt^, 2>^ XGeom_BSplineSurface::Poles() {
        TColgp_Array2OfPnt XP = NativeHandle()->Poles();
        array<xgp_Pnt^, 2>^ P = gcnew array<xgp_Pnt^, 2>(XP.ColLength(), XP.RowLength());
        for (Standard_Integer i = 0; i < XP.ColLength(); i++) {
            for (Standard_Integer j = 0; j < XP.RowLength(); j++) {
                gp_Pnt* gpPnt = new gp_Pnt(XP.Value(i, j));
                xgp_Pnt^ temp = gcnew xgp_Pnt(gpPnt);
                P->SetValue(temp, i, j);
            }
        }
        return P;
    };


    //! Returns the degree of the normalized B-splines Ni,n in the U
    //! direction.
    Standard_Integer XGeom_BSplineSurface::UDegree() {
        return NativeHandle()->UDegree();
    };


    //! Returns the Knot value of range UIndex.
    //! Raised if UIndex < 1 or UIndex > NbUKnots
    Standard_Real XGeom_BSplineSurface::UKnot(Standard_Integer UIndex) {
        return NativeHandle()->UKnot(UIndex);
    };


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
    XGeomAbs_BSplKnotDistribution XGeom_BSplineSurface::UKnotDistribution() {
        return safe_cast<XGeomAbs_BSplKnotDistribution>(NativeHandle()->UKnotDistribution());
    };

    //! Returns the knots in the U direction.
    //!
    //! Raised if the length of Ku is not equal to the number of knots
    //! in the U direction.
    void XGeom_BSplineSurface::UKnots(array<Standard_Real>^ Ku) {
        TColStd_Array1OfReal XKu;
        for (Standard_Integer i = 0; i < Ku->Length; i++) {
            Standard_Real XReal = (Standard_Real)Ku->GetValue(i);
            XKu.SetValue(i, XReal);
        }
        NativeHandle()->UKnots(XKu);
    };

    //! Returns the knots in the U direction.
    array<Standard_Real>^ XGeom_BSplineSurface::UKnots() {
        TColStd_Array1OfReal XKu = NativeHandle()->UKnots();
        array<Standard_Real>^ Ku = gcnew array<Standard_Real>(XKu.Length());
        for (Standard_Integer i = 0; i < XKu.Length(); i++) {
            Standard_Real XReal = (Standard_Real)XKu.Value(i);
            Ku->SetValue(XReal, i);
        }
        return Ku;
    };

    //! Returns the uknots sequence.
    //! In this sequence the knots with a multiplicity greater than 1
    //! are repeated.
    //! Example :
    //! Ku = {k1, k1, k1, k2, k3, k3, k4, k4, k4}
    //!
    //! Raised if the length of Ku is not equal to NbUPoles + UDegree + 1
    void XGeom_BSplineSurface::UKnotSequence(array<Standard_Real>^ Ku) {
        TColStd_Array1OfReal XKu;
        for (Standard_Integer i = 0; i < Ku->Length; i++) {
            Standard_Real XReal = (Standard_Real)Ku->GetValue(i);
            XKu.SetValue(i, XReal);
        }
        NativeHandle()->UKnotSequence(XKu);
    };

    //! Returns the uknots sequence.
    //! In this sequence the knots with a multiplicity greater than 1
    //! are repeated.
    //! Example :
    //! Ku = {k1, k1, k1, k2, k3, k3, k4, k4, k4}
    array<Standard_Real>^ XGeom_BSplineSurface::UKnotSequence() {
        TColStd_Array1OfReal XKu = NativeHandle()->UKnotSequence();
        array<Standard_Real>^ Ku = gcnew array<Standard_Real>(XKu.Length());
        for (Standard_Integer i = 0; i < XKu.Length(); i++) {
            Standard_Real XReal = (Standard_Real)XKu.Value(i);
            Ku->SetValue(XReal, i);
        }
        return Ku;
    };


    //! Returns the multiplicity value of knot of range UIndex in
    //! the u direction.
    //! Raised if UIndex < 1 or UIndex > NbUKnots.
    Standard_Integer XGeom_BSplineSurface::UMultiplicity(Standard_Integer UIndex) {
        return NativeHandle()->UMultiplicity(UIndex);
    };


    //! Returns the multiplicities of the knots in the U direction.
    //!
    //! Raised if the length of Mu is not equal to the number of
    //! knots in the U direction.
    void XGeom_BSplineSurface::UMultiplicities(array<Standard_Integer>^ Mu) {
        TColStd_Array1OfInteger XMu;
        for (Standard_Integer i = 0; i < Mu->Length; i++) {
            Standard_Integer XInteger = (Standard_Integer)Mu->GetValue(i);
            XMu.SetValue(i, XInteger);
        }
        NativeHandle()->UMultiplicities(XMu);
    };

    //! Returns the multiplicities of the knots in the U direction.
    array<Standard_Integer>^ XGeom_BSplineSurface::UMultiplicities() {
        TColStd_Array1OfInteger XMu = NativeHandle()->UMultiplicities();
        array<Standard_Integer>^ Mu = gcnew array<Standard_Integer>(XMu.Length());
        for (Standard_Integer i = 0; i < XMu.Length(); i++) {
            Standard_Integer XInteger = (Standard_Integer)XMu.Value(i);
            Mu->SetValue(XInteger, i);
        }
        return Mu;
    };


    //! Returns the degree of the normalized B-splines Ni,d in the
    //! V direction.
    Standard_Integer XGeom_BSplineSurface::VDegree() {
        return NativeHandle()->VDegree();
    };

    //! Returns the Knot value of range VIndex.
    //! Raised if VIndex < 1 or VIndex > NbVKnots
    Standard_Real XGeom_BSplineSurface::VKnot(Standard_Integer VIndex) {
        return NativeHandle()->VKnot(VIndex);
    };


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
    XGeomAbs_BSplKnotDistribution XGeom_BSplineSurface::VKnotDistribution() {
        return safe_cast<XGeomAbs_BSplKnotDistribution>(NativeHandle()->VKnotDistribution());
    };

    //! Returns the knots in the V direction.
    //!
    //! Raised if the length of Kv is not equal to the number of
    //! knots in the V direction.
    void XGeom_BSplineSurface::VKnots(array<Standard_Real>^ Kv) {
        TColStd_Array1OfReal XKv;
        for (Standard_Integer i = 0; i < Kv->Length; i++) {
            Standard_Real XInteger = (Standard_Real)Kv->GetValue(i);
            XKv.SetValue(i, XInteger);
        }
        NativeHandle()->VKnots(XKv);
    };

    //! Returns the knots in the V direction.
    array<Standard_Real>^ XGeom_BSplineSurface::VKnots() {
        TColStd_Array1OfReal XKv = NativeHandle()->VKnots();
        array<Standard_Real>^ Kv = gcnew array<Standard_Real>(XKv.Length());
        for (Standard_Integer i = 0; i < XKv.Length(); i++) {
            Standard_Real XReal = (Standard_Real)XKv.Value(i);
            Kv->SetValue(XReal, i);
        }
        return Kv;
    };

    //! Returns the vknots sequence.
    //! In this sequence the knots with a multiplicity greater than 1
    //! are repeated.
    //! Example :
    //! Kv = {k1, k1, k1, k2, k3, k3, k4, k4, k4}
    //!
    //! Raised if the length of Kv is not equal to NbVPoles + VDegree + 1
    void XGeom_BSplineSurface::VKnotSequence(array<Standard_Real>^ Kv) {
        TColStd_Array1OfReal XKv;
        for (Standard_Integer i = 0; i < Kv->Length; i++) {
            Standard_Real XInteger = (Standard_Real)Kv->GetValue(i);
            XKv.SetValue(i, XInteger);
        }
        NativeHandle()->VKnotSequence(XKv);
    };

    //! Returns the vknots sequence.
    //! In this sequence the knots with a multiplicity greater than 1
    //! are repeated.
    //! Example :
    //! Ku = {k1, k1, k1, k2, k3, k3, k4, k4, k4}
    array<Standard_Real>^ XGeom_BSplineSurface::VKnotSequence() {
        TColStd_Array1OfReal XKv = NativeHandle()->VKnotSequence();
        array<Standard_Real>^ Kv = gcnew array<Standard_Real>(XKv.Length());
        for (Standard_Integer i = 0; i < XKv.Length(); i++) {
            Standard_Real XReal = (Standard_Real)XKv.Value(i);
            Kv->SetValue(XReal, i);
        }
        return Kv;
    };


    //! Returns the multiplicity value of knot of range VIndex in
    //! the v direction.
    //! Raised if VIndex < 1 or VIndex > NbVKnots
    Standard_Integer XGeom_BSplineSurface::VMultiplicity(Standard_Integer VIndex) {
        return NativeHandle()->VMultiplicity(VIndex);
    };


    //! Returns the multiplicities of the knots in the V direction.
    //!
    //! Raised if the length of Mv is not equal to the number of
    //! knots in the V direction.
    void XGeom_BSplineSurface::VMultiplicities(array<Standard_Integer>^ Mv) {
        TColStd_Array1OfInteger XMv;
        for (Standard_Integer i = 0; i < Mv->Length; i++) {
            Standard_Integer XInteger = (Standard_Integer)Mv->GetValue(i);
            XMv.SetValue(i, XInteger);
        }
        NativeHandle()->VMultiplicities(XMv);
    };

    //! Returns the multiplicities of the knots in the V direction.
    array<Standard_Integer>^ XGeom_BSplineSurface::VMultiplicities() {
        TColStd_Array1OfInteger XMv = NativeHandle()->VMultiplicities();
        array<Standard_Integer>^ Mv = gcnew array<Standard_Integer>(XMv.Length());
        for (Standard_Integer i = 0; i < XMv.Length(); i++) {
            Standard_Integer XInteger = (Standard_Integer)XMv.Value(i);
            Mv->SetValue(XInteger, i);
        }
        return Mv;
    };

    //! Returns the weight value of range UIndex, VIndex.
    //!
    //! Raised if UIndex < 1 or UIndex > NbUPoles or VIndex < 1
    //! or VIndex > NbVPoles.
    Standard_Real XGeom_BSplineSurface::Weight(Standard_Integer UIndex, Standard_Integer VIndex) {
        return NativeHandle()->Weight(UIndex, VIndex);
    };

    //! Returns the weights of the B-spline surface.
    //!
    //! Raised if the length of W in the U and V direction is
    //! not equal to NbUPoles and NbVPoles.
    void XGeom_BSplineSurface::Weights(array<Standard_Real, 2>^ W) {
        TColStd_Array2OfReal XW;
        for (Standard_Integer i = 0; i < W->Length; i++) {
            for (Standard_Integer j = 0; j < W->GetLength(i); j++) {
                Standard_Real XReal = (Standard_Real)W->GetValue(i, j);
                XW.SetValue(i, j, XReal);
            }
        }
        NativeHandle()->Weights(XW);
    };

    //! Returns the weights of the B-spline surface.
    //! value and derivatives computation
    array<Standard_Real, 2>^ XGeom_BSplineSurface::Weights() {
        const TColStd_Array2OfReal* XW = NativeHandle()->Weights();
        array<Standard_Real, 2>^ W = gcnew array<Standard_Real, 2>(XW->ColLength(), XW->RowLength());
        for (Standard_Integer i = 0; i < XW->ColLength(); i++) {
            for (Standard_Integer j = 0; j < XW->RowLength(); j++) {
                Standard_Real XReal = (Standard_Real)XW->Value(i, j);
                W->SetValue(XReal, i, j);
            }
        }
        return W;
    };

    void XGeom_BSplineSurface::D0(Standard_Real U, Standard_Real V, xgp_Pnt^ P) {
        NativeHandle()->D0(U, V, *P->GetPnt());
    };

    //! Raised if the continuity of the surface is not C1.
    void XGeom_BSplineSurface::D1(Standard_Real U, Standard_Real V, xgp_Pnt^ P, xgp_Vec^ D1U, xgp_Vec^ D1V) {
        NativeHandle()->D1(U, V, *P->GetPnt(), *D1U->GetVec(), *D1V->GetVec());
    };

    //! Raised if the continuity of the surface is not C2.
    void XGeom_BSplineSurface::D2(Standard_Real U, Standard_Real V, xgp_Pnt^ P, xgp_Vec^ D1U, xgp_Vec^ D1V, xgp_Vec^ D2U, xgp_Vec^ D2V, xgp_Vec^ D2UV) {
        NativeHandle()->D2(U, V, *P->GetPnt(), *D1U->GetVec(), *D1V->GetVec(), *D2U->GetVec(), *D2V->GetVec(), *D2UV->GetVec());
    };

    //! Raised if the continuity of the surface is not C3.
    void XGeom_BSplineSurface::D3(Standard_Real U, Standard_Real V, xgp_Pnt^ P, xgp_Vec^ D1U, xgp_Vec^ D1V, xgp_Vec^ D2U, xgp_Vec^ D2V, xgp_Vec^ D2UV, xgp_Vec^ D3U, xgp_Vec^ D3V, xgp_Vec^ D3UUV, xgp_Vec^ D3UVV) {
        NativeHandle()->D3(U, V, *P->GetPnt(), *D1U->GetVec(), *D1V->GetVec(), *D2U->GetVec(), *D2V->GetVec(), *D2UV->GetVec(), *D3U->GetVec(), *D3V->GetVec(), *D3UUV->GetVec(), *D3UVV->GetVec());
    };


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
    xgp_Vec^ XGeom_BSplineSurface::DN(Standard_Real U, Standard_Real V, Standard_Integer Nu, Standard_Integer Nv) {
        gp_Vec* temp = new gp_Vec(NativeHandle()->DN(U, V, Nu, Nv));
        return gcnew xgp_Vec(temp);
    };

    //! Raised if FromUK1 = ToUK2 or FromVK1 = ToVK2.
    void XGeom_BSplineSurface::LocalD0(Standard_Real U, Standard_Real V, Standard_Integer FromUK1, Standard_Integer ToUK2, Standard_Integer FromVK1, Standard_Integer ToVK2, xgp_Pnt^ P) {
        NativeHandle()->LocalD0(U, V, FromUK1, ToUK2, FromVK1, ToVK2, *P->GetPnt());
    };


    //! Raised if the local continuity of the surface is not C1
    //! between the knots FromUK1, ToUK2 and FromVK1, ToVK2.
    //! Raised if FromUK1 = ToUK2 or FromVK1 = ToVK2.
    void XGeom_BSplineSurface::LocalD1(Standard_Real U, Standard_Real V, Standard_Integer FromUK1, Standard_Integer ToUK2, Standard_Integer FromVK1, Standard_Integer ToVK2, xgp_Pnt^ P, xgp_Vec^ D1U, xgp_Vec^ D1V) {
        NativeHandle()->LocalD1(U, V, FromUK1, ToUK2, FromVK1, ToVK2, *P->GetPnt(),*D1U->GetVec(),*D1V->GetVec());
    };


    //! Raised if the local continuity of the surface is not C2
    //! between the knots FromUK1, ToUK2 and FromVK1, ToVK2.
    //! Raised if FromUK1 = ToUK2 or FromVK1 = ToVK2.
    void XGeom_BSplineSurface::LocalD2(Standard_Real U, Standard_Real V, Standard_Integer FromUK1, Standard_Integer ToUK2, Standard_Integer FromVK1, Standard_Integer ToVK2, xgp_Pnt^ P, xgp_Vec^ D1U, xgp_Vec^ D1V, xgp_Vec^ D2U, xgp_Vec^ D2V, xgp_Vec^ D2UV) {
        NativeHandle()->LocalD2(U, V, FromUK1, ToUK2, FromVK1, ToVK2, *P->GetPnt(), *D1U->GetVec(), *D1V->GetVec(), *D2U->GetVec(), *D2V->GetVec(), *D2UV->GetVec());
    };


    //! Raised if the local continuity of the surface is not C3
    //! between the knots FromUK1, ToUK2 and FromVK1, ToVK2.
    //! Raised if FromUK1 = ToUK2 or FromVK1 = ToVK2.
    void XGeom_BSplineSurface::LocalD3(Standard_Real U, Standard_Real V, Standard_Integer FromUK1, Standard_Integer ToUK2, Standard_Integer FromVK1, Standard_Integer ToVK2, xgp_Pnt^ P, xgp_Vec^ D1U, xgp_Vec^ D1V, xgp_Vec^ D2U, xgp_Vec^ D2V, xgp_Vec^ D2UV, xgp_Vec^ D3U, xgp_Vec^ D3V, xgp_Vec^ D3UUV, xgp_Vec^ D3UVV) {
        NativeHandle()->LocalD3(U, V, FromUK1, ToUK2, FromVK1, ToVK2, *P->GetPnt(), *D1U->GetVec(), *D1V->GetVec(), *D2U->GetVec(), *D2V->GetVec(), *D2UV->GetVec(), *D3U->GetVec(), *D3V->GetVec(), *D3UUV->GetVec(), *D3UVV->GetVec());
    };


    //! Raised if the local continuity of the surface is not CNu
    //! between the knots FromUK1, ToUK2 and CNv between the knots
    //! FromVK1, ToVK2.
    //! Raised if FromUK1 = ToUK2 or FromVK1 = ToVK2.
    xgp_Vec^ XGeom_BSplineSurface::LocalDN(Standard_Real U, Standard_Real V, Standard_Integer FromUK1, Standard_Integer ToUK2, Standard_Integer FromVK1, Standard_Integer ToVK2, Standard_Integer Nu, Standard_Integer Nv) {
        gp_Vec* temp = new gp_Vec(NativeHandle()->LocalDN(U, V, FromUK1, ToUK2, FromVK1, ToVK2, Nu, Nv));
        return gcnew xgp_Vec(temp);
    };


    //! Computes the point of parameter U, V on the BSpline surface patch
    //! defines between the knots UK1 UK2, VK1, VK2. U can be out of the
    //! bounds [Knot UK1, Knot UK2] and V can be outof the bounds
    //! [Knot VK1, Knot VK2]  but for the computation we only use the
    //! definition of the surface between these knot values.
    //! Raises if FromUK1 = ToUK2 or FromVK1 = ToVK2.
    xgp_Pnt^ XGeom_BSplineSurface::LocalValue(Standard_Real U, Standard_Real V, Standard_Integer FromUK1, Standard_Integer ToUK2, Standard_Integer FromVK1, Standard_Integer ToVK2) {
        gp_Pnt* temp = new gp_Pnt(NativeHandle()->LocalValue(U, V, FromUK1, ToUK2, FromVK1, ToVK2));
        return gcnew xgp_Pnt(temp);
    };


    //! Computes the U isoparametric curve.
    //! A B-spline curve is returned.
    XGeom_Curve^ XGeom_BSplineSurface::UIso(Standard_Real U) {
        return gcnew XGeom_Curve(NativeHandle()->UIso(U));
    };


    //! Computes the V isoparametric curve.
    //! A B-spline curve is returned.
    XGeom_Curve^ XGeom_BSplineSurface::VIso(Standard_Real V) {
        return gcnew XGeom_Curve(NativeHandle()->VIso(V));
    };


    //! Computes the U isoparametric curve.
    //! If CheckRational=False, no try to make it non-rational.
    //! A B-spline curve is returned.
    XGeom_Curve^ XGeom_BSplineSurface::UIso(Standard_Real U, Standard_Boolean CheckRational) {
        return gcnew XGeom_Curve(NativeHandle()->UIso(U, CheckRational));
    };


    //! Computes the V isoparametric curve.
    //! If CheckRational=False, no try to make it non-rational.
    //! A B-spline curve is returned.
    //! transformations
    XGeom_Curve^ XGeom_BSplineSurface::VIso(Standard_Real V, Standard_Boolean CheckRational) {
        return gcnew XGeom_Curve(NativeHandle()->VIso(V, CheckRational));
    };

    //! Applies the transformation T to this BSpline surface.
    void XGeom_BSplineSurface::Transform(xgp_Trsf^ T) {
        NativeHandle()->Transform(*T->GetTrsf());
    };


    //! Returns the value of the maximum degree of the normalized
    //! B-spline basis functions in the u and v directions.
    //! static 
    Standard_Integer XGeom_BSplineSurface::MaxDegree() {
        return Geom_BSplineSurface::MaxDegree();
    };

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
    void XGeom_BSplineSurface::Resolution(Standard_Real Tolerance3D, Standard_Real% UTolerance, Standard_Real% VTolerance) {
        Standard_Real XUTolerance(UTolerance); Standard_Real XVTolerance(VTolerance);
        NativeHandle()->Resolution(Tolerance3D, XUTolerance, XVTolerance);
        UTolerance = XUTolerance; VTolerance = XVTolerance;
    };

    //! Creates a new object which is a copy of this BSpline surface.
    XGeom_Geometry^ XGeom_BSplineSurface::Copy() {
        return gcnew XGeom_Geometry(NativeHandle()->Copy());
    };
}