#include <XGeom_BezierSurface.h>
namespace TKG3d {
    //!
    XGeom_BezierSurface::XGeom_BezierSurface(void) {
        //NativeHandle() = new Geom_BezierSurface();
    };

    //! 
    XGeom_BezierSurface::XGeom_BezierSurface(Handle(Geom_BezierSurface) pos) {
        NativeHandle() = pos;
        SetBoundedSurfaceHandle(NativeHandle());
    };

    //!
    XGeom_BezierSurface::~XGeom_BezierSurface() {
        NativeHandle() = NULL;
        SetBoundedSurfaceHandle(NativeHandle());
    };

    void XGeom_BezierSurface::SetBezierSurfaceHandle(Handle(Geom_BezierSurface) handle) {
        NativeHandle() = handle;
        SetBoundedSurfaceHandle(NativeHandle());
    };

    //!
    Handle(Geom_BezierSurface) XGeom_BezierSurface::GetBezierSurface() {
        return NativeHandle();
    };

    //!
    Handle(Geom_BoundedSurface) XGeom_BezierSurface::GetBoundedSurface() {
        return NativeHandle();
    };

    //!
    Handle(Geom_Surface) XGeom_BezierSurface::GetSurface() {
        return NativeHandle();
    };

    //!
    Handle(Geom_Geometry) XGeom_BezierSurface::GetGeometry() {
        return NativeHandle();
    };

    //! Creates a non-rational Bezier surface with a set of poles.
    //! Control points representation :
    //! SPoles(Uorigin,Vorigin) ...................SPoles(Uorigin,Vend)
    //! .                                     .
    //! .                                     .
    //! SPoles(Uend, Vorigin) .....................SPoles(Uend, Vend)
    //! For the double array the row indice corresponds to the parametric
    //! U direction and the columns indice corresponds to the parametric
    //! V direction.
    //! The weights are defaulted to all being 1.
    //!
    //! Raised if the number of poles of the surface is lower than 2
    //! or greater than MaxDegree + 1 in one of the two directions
    //! U or V.
    XGeom_BezierSurface::XGeom_BezierSurface(array<xgp_Pnt^,2>^ SurfacePoles) {
        TColgp_Array2OfPnt TSurfacePoles;
        for (Standard_Integer i = 0; i < SurfacePoles->Length; i++)
            for (Standard_Integer j = 0; j < SurfacePoles->GetLength(i); j++) {
                xgp_Pnt^ gpPnt = (xgp_Pnt^)SurfacePoles->GetValue(i, j);
                TSurfacePoles.SetValue(i, j, *gpPnt->GetPnt());
            }
        NativeHandle() = new Geom_BezierSurface(TSurfacePoles);
        SetBoundedSurfaceHandle(NativeHandle());
    };

    //! ---Purpose
    //! Creates a rational Bezier surface with a set of poles and a
    //! set of weights.
    //! For the double array the row indice corresponds to the parametric
    //! U direction and the columns indice corresponds to the parametric
    //! V direction.
    //! If all the weights are identical the surface is considered as
    //! non-rational (the tolerance criterion is Resolution from package
    //! gp).
    //!
    //! Raised if SurfacePoles and PoleWeights have not the same
    //! Rowlength or have not the same ColLength.
    //! Raised if PoleWeights (i, j) <= Resolution from gp;
    //! Raised if the number of poles of the surface is lower than 2
    //! or greater than MaxDegree + 1 in one of the two directions U or V.
    XGeom_BezierSurface::XGeom_BezierSurface(array<xgp_Pnt^,2>^ SurfacePoles, array<Standard_Real,2>^ PoleWeights) {
        TColgp_Array2OfPnt TSurfacePoles;
        TColStd_Array2OfReal TPoleWeights;
        for (Standard_Integer i = 0; i < SurfacePoles->Length; i++)
            for (Standard_Integer j = 0; j < SurfacePoles->GetLength(i); j++) {
                xgp_Pnt^ gpPnt = (xgp_Pnt^)SurfacePoles->GetValue(i, j);
                TSurfacePoles.SetValue(i, j, *gpPnt->GetPnt());
            }
        for (Standard_Integer i = 0; i < PoleWeights->Length; i++)
            for (Standard_Integer j = 0; j < PoleWeights->GetLength(i); j++) {
                Standard_Real XReal = (Standard_Real)PoleWeights->GetValue(i, j);
                TPoleWeights.SetValue(i, j, XReal);
            }
        NativeHandle() = new Geom_BezierSurface(TSurfacePoles, TPoleWeights);
        SetBoundedSurfaceHandle(NativeHandle());
    };

    //! Exchanges the direction U and V on a Bezier surface
    //! As a consequence:
    //! - the poles and weights tables are transposed,
    //! - degrees, rational characteristics and so on are
    //! exchanged between the two parametric directions, and
    //! - the orientation of the surface is reversed.
    void XGeom_BezierSurface::ExchangeUV() {
        NativeHandle()->ExchangeUV();
    };

    //! Increases the degree of this Bezier surface in the two parametric directions.
    //!
    //! Raised if UDegree < UDegree <me>  or VDegree < VDegree <me>
    //! Raised if the degree of the surface is greater than MaxDegree
    //! in one of the two directions U or V.
    void XGeom_BezierSurface::Increase(Standard_Integer UDeg, Standard_Integer VDeg) {
        NativeHandle()->Increase(UDeg, VDeg);
    };


    //! Inserts a column of poles. If the surface is rational the weights
    //! values associated with CPoles are equal defaulted to 1.
    //!
    //! Raised if Vindex < 1 or VIndex > NbVPoles.
    //!
    //! raises if VDegree is greater than MaxDegree.
    //! raises if the Length of CPoles is not equal to NbUPoles
    void XGeom_BezierSurface::InsertPoleColAfter(Standard_Integer VIndex, array<xgp_Pnt^>^ CPoles) {
        TColgp_Array1OfPnt TCPoles;
        for (Standard_Integer i = 0; i < CPoles->Length; i++) {
            xgp_Pnt^ gpPnt = (xgp_Pnt^)CPoles->GetValue(i);
            TCPoles.SetValue(i,*gpPnt->GetPnt());
        }
        NativeHandle()->InsertPoleColAfter(VIndex, TCPoles);
    };


    //! Inserts a column of poles and weights.
    //! If the surface was non-rational it can become rational.
    //!
    //! Raised if Vindex < 1 or VIndex > NbVPoles.
    //! Raised if
    //! . VDegree is greater than MaxDegree.
    //! . the Length of CPoles is not equal to NbUPoles
    //! . a weight value is lower or equal to Resolution from
    //! package gp
    void XGeom_BezierSurface::InsertPoleColAfter(Standard_Integer VIndex, array<xgp_Pnt^>^ CPoles, array<Standard_Real>^ CPoleWeights) {
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
        NativeHandle()->InsertPoleColAfter(VIndex, TCPoles, TCPoleWeights);
    };


    //! Inserts a column of poles. If the surface is rational the weights
    //! values associated with CPoles are equal defaulted to 1.
    //!
    //! Raised if Vindex < 1 or VIndex > NbVPoles.
    //!
    //! Raised if VDegree is greater than MaxDegree.
    //! Raised if the Length of CPoles is not equal to NbUPoles
    void XGeom_BezierSurface::InsertPoleColBefore(Standard_Integer VIndex, array<xgp_Pnt^>^ CPoles) {
        TColgp_Array1OfPnt TCPoles;
        for (Standard_Integer i = 0; i < CPoles->Length; i++) {
            xgp_Pnt^ gpPnt = (xgp_Pnt^)CPoles->GetValue(i);
            TCPoles.SetValue(i, *gpPnt->GetPnt());
        }
        NativeHandle()->InsertPoleColBefore(VIndex, TCPoles);
    };


    //! Inserts a column of poles and weights.
    //! If the surface was non-rational it can become rational.
    //!
    //! Raised if Vindex < 1 or VIndex > NbVPoles.
    //! Raised if :
    //! . VDegree is greater than MaxDegree.
    //! . the Length of CPoles is not equal to NbUPoles
    //! . a weight value is lower or equal to Resolution from
    //! package gp
    void XGeom_BezierSurface::InsertPoleColBefore(Standard_Integer VIndex, array<xgp_Pnt^>^ CPoles, array<Standard_Real>^ CPoleWeights) {
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
        NativeHandle()->InsertPoleColBefore(VIndex, TCPoles, TCPoleWeights);
    };


    //! Inserts a row of poles. If the surface is rational the weights
    //! values associated with CPoles are equal defaulted to 1.
    //!
    //! Raised if Uindex < 1 or UIndex > NbUPoles.
    //!
    //! Raised if UDegree is greater than MaxDegree.
    //! Raised if the Length of CPoles is not equal to NbVPoles
    void XGeom_BezierSurface::InsertPoleRowAfter(Standard_Integer UIndex, array<xgp_Pnt^>^ CPoles) {
        TColgp_Array1OfPnt TCPoles;
        for (Standard_Integer i = 0; i < CPoles->Length; i++) {
            xgp_Pnt^ gpPnt = (xgp_Pnt^)CPoles->GetValue(i);
            TCPoles.SetValue(i, *gpPnt->GetPnt());
        }
        NativeHandle()->InsertPoleRowAfter(UIndex, TCPoles);
    };


    //! Inserts a row of poles and weights.
    //! If the surface was non-rational it can become rational.
    //!
    //! Raised if Uindex < 1 or UIndex > NbUPoles.
    //! Raised if :
    //! . UDegree is greater than MaxDegree.
    //! . the Length of CPoles is not equal to NbVPoles
    //! . a weight value is lower or equal to Resolution from
    //! package gp
    void XGeom_BezierSurface::InsertPoleRowAfter(Standard_Integer UIndex, array<xgp_Pnt^>^ CPoles, array<Standard_Real>^ CPoleWeights) {
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
        NativeHandle()->InsertPoleRowAfter(UIndex, TCPoles, TCPoleWeights);
    };


    //! Inserts a row of poles. If the surface is rational the weights
    //! values associated with CPoles are equal defaulted to 1.
    //!
    //! Raised if Uindex < 1 or UIndex > NbUPoles.
    //!
    //! Raised if UDegree is greater than MaxDegree.
    //! Raised if the Length of CPoles is not equal to NbVPoles
    void XGeom_BezierSurface::InsertPoleRowBefore(Standard_Integer UIndex, array<xgp_Pnt^>^ CPoles) {
        TColgp_Array1OfPnt TCPoles;
        for (Standard_Integer i = 0; i < CPoles->Length; i++) {
            xgp_Pnt^ gpPnt = (xgp_Pnt^)CPoles->GetValue(i);
            TCPoles.SetValue(i, *gpPnt->GetPnt());
        }
        NativeHandle()->InsertPoleRowBefore(UIndex, TCPoles);
    };


    //! Inserts a row of poles and weights.
    //! If the surface was non-rational it can become rational.
    //!
    //! Raised if Uindex < 1 or UIndex > NbUPoles.
    //! Raised if :
    //! . UDegree is greater than MaxDegree.
    //! . the Length of CPoles is not equal to NbVPoles
    //! . a weight value is lower or equal to Resolution from
    //! pacakage gp
    void XGeom_BezierSurface::InsertPoleRowBefore(Standard_Integer UIndex, array<xgp_Pnt^>^ CPoles, array<Standard_Real>^ CPoleWeights) {
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
        NativeHandle()->InsertPoleRowBefore(UIndex, TCPoles, TCPoleWeights);
    };

    //! Removes a column of poles.
    //! If the surface was rational it can become non-rational.
    //!
    //! Raised if NbVPoles <= 2 after removing, a Bezier surface
    //! must have at least two columns of poles.
    //! Raised if Vindex < 1 or VIndex > NbVPoles
    void XGeom_BezierSurface::RemovePoleCol(Standard_Integer VIndex) {
        NativeHandle()->RemovePoleCol(VIndex);
    };

    //! Removes a row of poles.
    //! If the surface was rational it can become non-rational.
    //!
    //! Raised if NbUPoles <= 2 after removing, a Bezier surface
    //! must have at least two rows of poles.
    //! Raised if Uindex < 1 or UIndex > NbUPoles
    void XGeom_BezierSurface::RemovePoleRow(Standard_Integer UIndex) {
        NativeHandle()->RemovePoleRow(UIndex);
    };

    //! Modifies this Bezier surface by segmenting it
    //! between U1 and U2 in the u parametric direction,
    //! and between V1 and V2 in the v parametric
    //! direction. U1, U2, V1, and V2 can be outside the
    //! bounds of this surface.
    //! - U1 and U2 isoparametric Bezier curves,
    //! segmented between V1 and V2, become the two
    //! bounds of the surface in the v parametric
    //! direction (0. and 1. u isoparametric curves).
    //! - V1 and V2 isoparametric Bezier curves,
    //! segmented between U1 and U2, become the two
    //! bounds of the surface in the u parametric
    //! direction (0. and 1. v isoparametric curves).
    //! The poles and weights tables are modified, but the
    //! degree of this surface in the u and v parametric
    //! directions does not change.
    //! U1 can be greater than U2, and V1 can be greater
    //! than V2. In these cases, the corresponding
    //! parametric direction is inverted. The orientation of
    //! the surface is inverted if one (and only one)
    //! parametric direction is inverted.
    void XGeom_BezierSurface::Segment(Standard_Real U1, Standard_Real U2, Standard_Real V1, Standard_Real V2) {
        NativeHandle()->Segment(U1, U2, V1, V2);
    };

    //! Modifies a pole value.
    //! If the surface is rational the weight of range (UIndex, VIndex)
    //! is not modified.
    //!
    //! Raised if  UIndex < 1 or UIndex > NbUPoles  or  VIndex < 1
    //! or VIndex > NbVPoles.
    void XGeom_BezierSurface::SetPole(Standard_Integer UIndex, Standard_Integer VIndex, xgp_Pnt^ P) {
        NativeHandle()->SetPole(UIndex, VIndex, *P->GetPnt());
    };


    //! Substitutes the pole and the weight of range UIndex, VIndex.
    //! If the surface <me> is not rational it can become rational.
    //! if the surface was rational it can become non-rational.
    //!
    //! raises if  UIndex < 1 or UIndex > NbUPoles  or  VIndex < 1
    //! or VIndex > NbVPoles.
    //! Raised if Weight <= Resolution from package gp.
    void XGeom_BezierSurface::SetPole(Standard_Integer UIndex, Standard_Integer VIndex, xgp_Pnt^ P, Standard_Real Weight) {
        NativeHandle()->SetPole(UIndex, VIndex, *P->GetPnt(), Weight);
    };

    //! Modifies a column of poles.
    //! The length of CPoles can be lower but not greater than NbUPoles
    //! so you can modify just a part of the column.
    //! Raised if VIndex < 1 or  VIndex > NbVPoles
    //!
    //! Raised if CPoles.Lower() < 1 or CPoles.Upper() > NbUPoles
    void XGeom_BezierSurface::SetPoleCol(Standard_Integer VIndex, array<xgp_Pnt^>^ CPoles) {
        TColgp_Array1OfPnt TCPoles;
        for (Standard_Integer i = 0; i < CPoles->Length; i++) {
            xgp_Pnt^ gpPnt = (xgp_Pnt^)CPoles->GetValue(i);
            TCPoles.SetValue(i, *gpPnt->GetPnt());
        }
        NativeHandle()->SetPoleCol(VIndex, TCPoles);
    };

    //! Modifies a column of poles.
    //! If the surface was rational it can become non-rational
    //! If the surface was non-rational it can become rational.
    //! The length of CPoles can be lower but not greater than NbUPoles
    //! so you can modify just a part of the column.
    //! Raised if VIndex < 1 or  VIndex > NbVPoles
    //!
    //! Raised if CPoles.Lower() < 1 or CPoles.Upper() > NbUPoles
    //! Raised if CPoleWeights and CPoles have not the same bounds.
    //! Raised if one of the weight value CPoleWeights (i) is lower
    //! or equal to Resolution from package gp.
    void XGeom_BezierSurface::SetPoleCol(Standard_Integer VIndex, array<xgp_Pnt^>^ CPoles, array<Standard_Real>^ CPoleWeights) {
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

    //! Modifies a row of poles.
    //! The length of CPoles can be lower but not greater than NbVPoles
    //! so you can modify just a part of the row.
    //! Raised if UIndex < 1 or  UIndex > NbUPoles
    //!
    //! Raised if CPoles.Lower() < 1 or CPoles.Upper() > NbVPoles
    void XGeom_BezierSurface::SetPoleRow(Standard_Integer UIndex, array<xgp_Pnt^>^ CPoles) {
        TColgp_Array1OfPnt TCPoles;
        for (Standard_Integer i = 0; i < CPoles->Length; i++) {
            xgp_Pnt^ gpPnt = (xgp_Pnt^)CPoles->GetValue(i);
            TCPoles.SetValue(i, *gpPnt->GetPnt());
        }
        NativeHandle()->SetPoleRow(UIndex, TCPoles);
    };

    //! Modifies a row of poles and weights.
    //! If the surface was rational it can become non-rational.
    //! If the surface was non-rational it can become rational.
    //! The length of CPoles can be lower but not greater than NbVPoles
    //! so you can modify just a part of the row.
    //! Raised if UIndex < 1 or  UIndex > NbUPoles
    //!
    //! Raised if CPoles.Lower() < 1 or CPoles.Upper() > NbVPoles
    //! Raised if CPoleWeights and CPoles have not the same bounds.
    //! Raised if one of the weight value CPoleWeights (i) is lower
    //! or equal to Resolution from gp.
    void XGeom_BezierSurface::SetPoleRow(Standard_Integer UIndex, array<xgp_Pnt^>^ CPoles, array<Standard_Real>^ CPoleWeights) {
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


    //! Modifies the weight of the pole of range UIndex, VIndex.
    //! If the surface was non-rational it can become rational.
    //! If the surface was rational it can become non-rational.
    //!
    //! Raised if UIndex < 1  or  UIndex > NbUPoles or VIndex < 1 or
    //! VIndex > NbVPoles.
    //! Raised if Weight <= Resolution from package gp.
    void XGeom_BezierSurface::SetWeight(Standard_Integer UIndex, Standard_Integer VIndex, Standard_Real Weight) {
        NativeHandle()->SetWeight(UIndex, VIndex, Weight);
    };

    //! Modifies a column of weights.
    //! If the surface was rational it can become non-rational.
    //! If the surface was non-rational it can become rational.
    //! The length of CPoleWeights can be lower but not greater than
    //! NbUPoles.
    //! Raised if VIndex < 1 or  VIndex > NbVPoles
    //!
    //! Raised if CPoleWeights.Lower() < 1 or CPoleWeights.Upper() >
    //! NbUPoles
    //! Raised if one of the weight value CPoleWeights (i) is lower
    //! or equal to Resolution from package gp.
    void XGeom_BezierSurface::SetWeightCol(Standard_Integer VIndex, array<Standard_Real>^ CPoleWeights) {
        TColStd_Array1OfReal TCPoleWeights;
        for (Standard_Integer i = 0; i < CPoleWeights->Length; i++) {
            Standard_Real XReal = (Standard_Real)CPoleWeights->GetValue(i);
            TCPoleWeights.SetValue(i, XReal);
        }
        NativeHandle()->SetWeightCol(VIndex, TCPoleWeights);
    };

    //! Modifies a row of weights.
    //! If the surface was rational it can become non-rational.
    //! If the surface was non-rational it can become rational.
    //! The length of CPoleWeights can be lower but not greater than
    //! NbVPoles.
    //! Raised if UIndex < 1 or  UIndex > NbUPoles
    //!
    //! Raised if CPoleWeights.Lower() < 1 or CPoleWeights.Upper() >
    //! NbVPoles
    //! Raised if one of the weight value CPoleWeights (i) is lower
    //! or equal to Resolution from package gp.
    void XGeom_BezierSurface::SetWeightRow(Standard_Integer UIndex, array<Standard_Real>^ CPoleWeights) {
        TColStd_Array1OfReal TCPoleWeights;
        for (Standard_Integer i = 0; i < CPoleWeights->Length; i++) {
            Standard_Real XReal = (Standard_Real)CPoleWeights->GetValue(i);
            TCPoleWeights.SetValue(i, XReal);
        }
        NativeHandle()->SetWeightCol(UIndex, TCPoleWeights);
    };

    //! Changes the orientation of this Bezier surface in the
    //! u  parametric direction. The bounds of the
    //! surface are not changed, but the given parametric
    //! direction is reversed. Hence, the orientation of the surface is reversed.
    void XGeom_BezierSurface::UReverse() {
        NativeHandle()->UReverse();
    };

    //! Computes the u (or v) parameter on the modified
    //! surface, produced by reversing its u (or v) parametric
    //! direction, for any point of u parameter U (or of v
    //! parameter V) on this Bezier surface.
    //! In the case of a Bezier surface, these functions return respectively:
    //! - 1.-U, or 1.-V.
    Standard_Real XGeom_BezierSurface::UReversedParameter(Standard_Real U) {
        return NativeHandle()->UReversedParameter(U);
    };

    //! Changes the orientation of this Bezier surface in the
    //! v parametric direction. The bounds of the
    //! surface are not changed, but the given parametric
    //! direction is reversed. Hence, the orientation of the
    //! surface is reversed.
    void XGeom_BezierSurface::VReverse() {
        NativeHandle()->VReverse();
    };

    //! Computes the u (or v) parameter on the modified
    //! surface, produced by reversing its u (or v) parametric
    //! direction, for any point of u parameter U (or of v
    //! parameter V) on this Bezier surface.
    //! In the case of a Bezier surface, these functions return respectively:
    //! - 1.-U, or 1.-V.
    Standard_Real XGeom_BezierSurface::VReversedParameter(Standard_Real V) {
        return NativeHandle()->VReversedParameter(V);
    };

    //! Returns the parametric bounds U1, U2, V1 and V2 of
    //! this Bezier surface.
    //! In the case of a Bezier surface, this function returns
    //! U1 = 0, V1 = 0, U2 = 1, V2 = 1.
    void XGeom_BezierSurface::Bounds(Standard_Real% U1, Standard_Real% U2, Standard_Real% V1, Standard_Real% V2) {
        Standard_Real XU1(U1); Standard_Real XU2(U2); Standard_Real XV1(V1); Standard_Real XV2(V2);
        NativeHandle()->Bounds(XU1, XU2, XV1, XV2);
        U1 = XU1; U2 = XU2; V1 = XV1; V2 = XV2;
    };


    //! Returns the continuity of the surface CN : the order of
    //! continuity is infinite.
    XGeomAbs_Shape XGeom_BezierSurface::Continuity() {
        return safe_cast<XGeomAbs_Shape>(NativeHandle()->Continuity());
    };

    void XGeom_BezierSurface::D0(Standard_Real U, Standard_Real V, xgp_Pnt^ P) {
        NativeHandle()->D0(U, V, *P->GetPnt());
    };

    void XGeom_BezierSurface::D1(Standard_Real U, Standard_Real V, xgp_Pnt^ P, xgp_Vec^ D1U, xgp_Vec^ D1V) {
        NativeHandle()->D1(U, V, *P->GetPnt(), *D1U->GetVec(), *D1V->GetVec());
    };

    void XGeom_BezierSurface::D2(Standard_Real U, Standard_Real V, xgp_Pnt^ P, xgp_Vec^ D1U, xgp_Vec^ D1V, xgp_Vec^ D2U, xgp_Vec^ D2V, xgp_Vec^ D2UV) {
        NativeHandle()->D2(U, V, *P->GetPnt(), *D1U->GetVec(), *D1V->GetVec(), *D2U->GetVec(), *D2V->GetVec(), *D2UV->GetVec());
    };

    //! Computes P, the point of parameters (U, V) of this Bezier surface, and
    //! - one or more of the following sets of vectors:
    //! - D1U and D1V, the first derivative vectors at this point,
    //! - D2U, D2V and D2UV, the second derivative
    //! vectors at this point,
    //! - D3U, D3V, D3UUV and D3UVV, the third
    //! derivative vectors at this point.
    //! Note: The parameters U and V can be outside the bounds of the surface.
    void XGeom_BezierSurface::D3(Standard_Real U, Standard_Real V, xgp_Pnt^ P, xgp_Vec^ D1U, xgp_Vec^ D1V, xgp_Vec^ D2U, xgp_Vec^ D2V, xgp_Vec^ D2UV, xgp_Vec^ D3U, xgp_Vec^ D3V, xgp_Vec^ D3UUV, xgp_Vec^ D3UVV) {
        NativeHandle()->D3(U, V, *P->GetPnt(), *D1U->GetVec(), *D1V->GetVec(), *D2U->GetVec(), *D2V->GetVec(), *D2UV->GetVec(), *D3U->GetVec(), *D3V->GetVec(), *D3UUV->GetVec(), *D3UVV->GetVec());
    };

    //! Computes the derivative of order Nu in the u
    //! parametric direction, and Nv in the v parametric
    //! direction, at the point of parameters (U, V) of this Bezier surface.
    //! Note: The parameters U and V can be outside the bounds of the surface.
    //! Exceptions
    //! Standard_RangeError if:
    //! - Nu + Nv is less than 1, or Nu or Nv is negative.
    xgp_Vec^ XGeom_BezierSurface::DN(Standard_Real U, Standard_Real V, Standard_Integer Nu, Standard_Integer Nv) {
        gp_Vec* temp = new gp_Vec(NativeHandle()->DN(U, V, Nu, Nv));
        return gcnew xgp_Vec(temp);
    };

    //! Returns the number of poles in the U direction.
    Standard_Integer XGeom_BezierSurface::NbUPoles() {
        return NativeHandle()->NbUPoles();
    };

    //! Returns the number of poles in the V direction.
    Standard_Integer XGeom_BezierSurface::NbVPoles() {
        return NativeHandle()->NbVPoles();
    };

    //! Returns the pole of range UIndex, VIndex
    //! Raised if UIndex < 1 or UIndex > NbUPoles, or
    //! VIndex < 1 or VIndex > NbVPoles.
    xgp_Pnt^ XGeom_BezierSurface::Pole(Standard_Integer UIndex, Standard_Integer VIndex) {
        gp_Pnt* temp = new gp_Pnt(NativeHandle()->Pole(UIndex, VIndex));
        return gcnew xgp_Pnt(temp);
    };

    //! Returns the poles of the Bezier surface.
    //!
    //! Raised if the length of P in the U an V direction is not equal to
    //! NbUPoles and NbVPoles.
    void XGeom_BezierSurface::Poles(array<xgp_Pnt^,2>^ P) {
        TColgp_Array2OfPnt TP;
        for (Standard_Integer i = 0; i < P->Length; i++)
            for (Standard_Integer j = 0; j < P->GetLength(i); j++) {
                xgp_Pnt^ gpPnt = (xgp_Pnt^)P->GetValue(i, j);
                TP.SetValue(i, j, *gpPnt->GetPnt());
            }
        NativeHandle()->Poles(TP);
    };

    //! Returns the poles of the Bezier surface.
    array<xgp_Pnt^,2>^ XGeom_BezierSurface::Poles() {
        TColgp_Array2OfPnt TP = NativeHandle()->Poles();
        array<xgp_Pnt^, 2>^ P = gcnew array<xgp_Pnt^, 2>(TP.ColLength(), TP.RowLength());
        for (Standard_Integer i = 0; i < TP.ColLength(); i++)
            for (Standard_Integer j = 0; j < TP.RowLength(); j++) {
                gp_Pnt* temp = new gp_Pnt(TP.Value(i, j));
                xgp_Pnt^ gpPnt = gcnew xgp_Pnt(temp);
                P->SetValue(gpPnt, i, j);
            }
        return P;
    };

    //! Returns the degree of the surface in the U direction it is
    //! NbUPoles - 1
    Standard_Integer XGeom_BezierSurface::UDegree() {
        return NativeHandle()->UDegree();
    };


    //! Computes the U isoparametric curve. For a Bezier surface the
    //! UIso curve is a Bezier curve.
    XGeom_Curve^ XGeom_BezierSurface::UIso(Standard_Real U) {
       return gcnew XGeom_Curve( NativeHandle()->UIso(U));
    };


    //! Returns the degree of the surface in the V direction it is
    //! NbVPoles - 1
    Standard_Integer XGeom_BezierSurface::VDegree() {
        return NativeHandle()->VDegree();
    };


    //! Computes the V isoparametric curve. For a Bezier surface the
    //! VIso  curve is a Bezier curve.
    XGeom_Curve^ XGeom_BezierSurface::VIso(Standard_Real V) {
        return gcnew XGeom_Curve(NativeHandle()->VIso(V));
    };

    //! Returns the weight of range UIndex, VIndex
    //!
    //! Raised if UIndex < 1 or UIndex > NbUPoles, or
    //! VIndex < 1 or VIndex > NbVPoles.
    Standard_Real XGeom_BezierSurface::Weight(Standard_Integer UIndex, Standard_Integer VIndex) {
        return NativeHandle()->Weight(UIndex, VIndex);
    };

    //! Returns the weights of the Bezier surface.
    //!
    //! Raised if the length of W in the U an V direction is not
    //! equal to NbUPoles and NbVPoles.
    void XGeom_BezierSurface::Weights(array<Standard_Real,2>^ W) {
        TColStd_Array2OfReal TW;
        for (Standard_Integer i = 0; i < W->Length; i++)
            for (Standard_Integer j = 0; j < W->GetLength(i); j++) {
                Standard_Real XReal = (Standard_Real)W->GetValue(i, j);
                TW.SetValue(i, j, XReal);
            }
        NativeHandle()->Weights(TW);
    };

    //! Returns the weights of the Bezier surface.
    array<Standard_Real,2>^ XGeom_BezierSurface::Weights() {
        const TColStd_Array2OfReal* TW = NativeHandle()->Weights();
        array<Standard_Real, 2>^ W = gcnew array<Standard_Real, 2>(TW->ColLength(), TW->RowLength());
        for (Standard_Integer i = 0; i < TW->ColLength(); i++)
            for (Standard_Integer j = 0; j < TW->RowLength(); j++) {
                Standard_Real XReal = TW->Value(i, j);
                W->SetValue(XReal, i, j);
            }
        return W;
    };

    //! Returns True if the first control points row and the
    //! last control points row are identical. The tolerance
    //! criterion is Resolution from package gp.
    Standard_Boolean XGeom_BezierSurface::IsUClosed() {
        return NativeHandle()->IsUClosed();
    };


    //! Returns True if the first control points column
    //! and the last control points column are identical.
    //! The tolerance criterion is Resolution from package gp.
    Standard_Boolean XGeom_BezierSurface::IsVClosed() {
        return NativeHandle()->IsVClosed();
    };

    //! Returns True, a Bezier surface is always  CN
    Standard_Boolean XGeom_BezierSurface::IsCNu(Standard_Integer N) {
        return NativeHandle()->IsCNu(N);
    };

    //! Returns True, a BezierSurface is always  CN
    Standard_Boolean XGeom_BezierSurface::IsCNv(Standard_Integer N) {
        return NativeHandle()->IsCNv(N);
    };

    //! Returns False.
    Standard_Boolean XGeom_BezierSurface::IsUPeriodic() {
        return NativeHandle()->IsUPeriodic();
    };

    //! Returns False.
    Standard_Boolean XGeom_BezierSurface::IsVPeriodic() {
        return NativeHandle()->IsVPeriodic();
    };


    //! Returns False if the weights are identical in the U direction,
    //! The tolerance criterion is Resolution from package gp.
    //! Example :
    //! |1.0, 1.0, 1.0|
    //! if Weights =  |0.5, 0.5, 0.5|   returns False
    //! |2.0, 2.0, 2.0|
    Standard_Boolean XGeom_BezierSurface::IsURational() {
        return NativeHandle()->IsURational();
    };


    //! Returns False if the weights are identical in the V direction,
    //! The tolerance criterion is Resolution from package gp.
    //! Example :
    //! |1.0, 2.0, 0.5|
    //! if Weights =  |1.0, 2.0, 0.5|   returns False
    //! |1.0, 2.0, 0.5|
    Standard_Boolean XGeom_BezierSurface::IsVRational() {
        return NativeHandle()->IsVRational();
    };

    //! Applies the transformation T to this Bezier surface.
    void XGeom_BezierSurface::Transform(xgp_Trsf^ T) {
        return NativeHandle()->Transform(*T->GetTrsf());
    };


    //! Returns the value of the maximum polynomial degree of a
    //! Bezier surface. This value is 25.
    //! static 
    Standard_Integer XGeom_BezierSurface::MaxDegree() {
        return Geom_BezierSurface::MaxDegree();
    };

    //! Computes two tolerance values for this Bezier
    //! surface, based on the given tolerance in 3D space
    //! Tolerance3D. The tolerances computed are:
    //! - UTolerance in the u parametric direction, and
    //! - VTolerance in the v parametric direction.
    //! If f(u,v) is the equation of this Bezier surface,
    //! UTolerance and VTolerance guarantee that:
    //! | u1 - u0 | < UTolerance and
    //! | v1 - v0 | < VTolerance
    //! ====> |f (u1,v1) - f (u0,v0)| < Tolerance3D
    void XGeom_BezierSurface::Resolution(Standard_Real Tolerance3D, Standard_Real% UTolerance, Standard_Real% VTolerance) {
        Standard_Real XUTolerance(UTolerance); Standard_Real XVTolerance(VTolerance);
        NativeHandle()->Resolution(Tolerance3D, XUTolerance, XVTolerance);
        UTolerance = XUTolerance; VTolerance = XVTolerance;
    };

    //! Creates a new object which is a copy of this Bezier surface.
    XGeom_Geometry^ XGeom_BezierSurface::Copy() {
        return gcnew XGeom_Geometry(NativeHandle()->Copy());
    };
}