#include <XGeom_BSplineCurve.h>
namespace TKG3d {
    XGeom_BSplineCurve::XGeom_BSplineCurve() {
        //NativeHandle() = new Geom_BSplineCurve();
    };

    //! 
    XGeom_BSplineCurve::XGeom_BSplineCurve(Handle(Geom_BSplineCurve) pos) {
        NativeHandle() = pos;
        SetBoundedCurveHandle(NativeHandle());
    };

    //!
    XGeom_BSplineCurve::~XGeom_BSplineCurve() {
        NativeHandle() = NULL;
        SetBoundedCurveHandle(NativeHandle());
    };

    void XGeom_BSplineCurve::SetBSplineCurveHandle(Handle(Geom_BSplineCurve) pos) {
        NativeHandle() = pos;
        SetBoundedCurveHandle(NativeHandle());
    };

    //!
    Handle(Geom_BSplineCurve) XGeom_BSplineCurve::GetBSplineCurve() {
        return NativeHandle();
    };

    //!
    Handle(Geom_BoundedCurve) XGeom_BSplineCurve::GetBoundedCurve() {
        return NativeHandle();
    };

    //!
    Handle(Geom_Curve) XGeom_BSplineCurve::GetCurve() {
        return NativeHandle();
    };

    //!
    Handle(Geom_Geometry) XGeom_BSplineCurve::GetGeometry() {
        return NativeHandle();
    };

    //! Creates a  non-rational B_spline curve   on  the
    //! basis <Knots, Multiplicities> of degree <Degree>.
    //!  Standard_Boolean Periodic = Standard_False
    XGeom_BSplineCurve::XGeom_BSplineCurve(array<xgp_Pnt^>^ Poles, array<Standard_Real>^ Knots, array<Standard_Integer>^ Multiplicities, Standard_Integer Degree, Standard_Boolean Periodic) {
        TColgp_Array1OfPnt XPoles; TColStd_Array1OfReal XKnots; TColStd_Array1OfInteger XMultiplicities;
        Standard_Integer i = 0, j = 0, m = 0;
        for each (xgp_Pnt ^ xgpPnt in Poles)
            XPoles.SetValue(i++, *xgpPnt->GetPnt());
        for each (Standard_Real xReal in Knots)
            XKnots.SetValue(j++, xReal);
        for each (Standard_Integer xInteger in Multiplicities)
            XMultiplicities.SetValue(m++, xInteger);
        NativeHandle() = new Geom_BSplineCurve(XPoles, XKnots, XMultiplicities, Degree, Periodic);
        SetBoundedCurveHandle(NativeHandle());
    };

    //! Creates  a rational B_spline  curve  on the basis
    //! <Knots, Multiplicities> of degree <Degree>.
    //! Raises ConstructionError subject to the following conditions
    //! 0 < Degree <= MaxDegree.
    //!
    //! Weights.Length() == Poles.Length()
    //!
    //! Knots.Length() == Mults.Length() >= 2
    //!
    //! Knots(i) < Knots(i+1) (Knots are increasing)
    //!
    //! 1 <= Mults(i) <= Degree
    //!
    //! On a non periodic curve the first and last multiplicities
    //! may be Degree+1 (this is even recommanded if you want the
    //! curve to start and finish on the first and last pole).
    //!
    //! On a periodic  curve the first  and  the last multicities
    //! must be the same.
    //!
    //! on non-periodic curves
    //!
    //! Poles.Length() == Sum(Mults(i)) - Degree - 1 >= 2
    //!
    //! on periodic curves
    //!
    //! Poles.Length() == Sum(Mults(i)) except the first or last
    //! Standard_Boolean Periodic = Standard_False, Standard_Boolean CheckRational = Standard_True
    XGeom_BSplineCurve::XGeom_BSplineCurve(array<xgp_Pnt^>^ Poles, array<Standard_Real>^ Weights, array<Standard_Real>^ Knots, array<Standard_Integer>^ Multiplicities, Standard_Integer Degree, Standard_Boolean Periodic, Standard_Boolean CheckRational) {
        TColgp_Array1OfPnt XPoles; TColStd_Array1OfReal XWeights; TColStd_Array1OfReal XKnots; TColStd_Array1OfInteger XMultiplicities;
        Standard_Integer i = 0, j = 0, m = 0, n = 0;
        for each (xgp_Pnt ^ xgpPnt in Poles)
            XPoles.SetValue(i++, *xgpPnt->GetPnt());
        for each (Standard_Real xReal in Weights)
            XWeights.SetValue(j++, xReal);
        for each (Standard_Real xReal in Knots)
            XKnots.SetValue(m++, xReal);
        for each (Standard_Integer xInteger in Multiplicities)
            XMultiplicities.SetValue(n++, xInteger);
        NativeHandle() = new Geom_BSplineCurve(XPoles, XWeights, XKnots, XMultiplicities, Degree, Periodic);
        SetBoundedCurveHandle(NativeHandle());
    };

    //! Increases the degree of this BSpline curve to
    //! Degree. As a result, the poles, weights and
    //! multiplicities tables are modified; the knots table is
    //! not changed. Nothing is done if Degree is less than
    //! or equal to the current degree.
    //! Exceptions
    //! Standard_ConstructionError if Degree is greater than
    //! Geom_BSplineCurve::MaxDegree().
    void XGeom_BSplineCurve::IncreaseDegree(Standard_Integer Degree) {
        NativeHandle()->IncreaseDegree(Degree);
    };

    //! Increases the multiplicity  of the knot <Index> to
    //! <M>.
    //!
    //! If   <M>   is   lower   or  equal   to  the current
    //! multiplicity nothing is done. If <M> is higher than
    //! the degree the degree is used.
    //! If <Index> is not in [FirstUKnotIndex, LastUKnotIndex]
    void XGeom_BSplineCurve::IncreaseMultiplicity(Standard_Integer Index, Standard_Integer M) {
        NativeHandle()->IncreaseMultiplicity(Index, M);
    };

    //! Increases  the  multiplicities   of  the knots  in
    //! [I1,I2] to <M>.
    //!
    //! For each knot if  <M>  is  lower  or equal  to  the
    //! current multiplicity  nothing  is  done. If <M>  is
    //! higher than the degree the degree is used.
    //! If <I1,I2> are not in [FirstUKnotIndex, LastUKnotIndex]
    void XGeom_BSplineCurve::IncreaseMultiplicity(Standard_Integer I1, Standard_Integer I2, Standard_Integer M) {
        NativeHandle()->IncreaseMultiplicity(I1, I2, M);
    };

    //! Increment  the  multiplicities   of  the knots  in
    //! [I1,I2] by <M>.
    //!
    //! If <M> is not positive nithing is done.
    //!
    //! For   each  knot   the resulting   multiplicity  is
    //! limited to the Degree.
    //! If <I1,I2> are not in [FirstUKnotIndex, LastUKnotIndex]
    void XGeom_BSplineCurve::IncrementMultiplicity(Standard_Integer I1, Standard_Integer I2, Standard_Integer M) {
        NativeHandle()->IncrementMultiplicity(I1, I2, M);
    };

    //! Inserts a knot value in the sequence of knots.  If
    //! <U>  is an  existing knot     the multiplicity  is
    //! increased by <M>.
    //!
    //! If U  is  not  on the parameter  range  nothing is
    //! done.
    //!
    //! If the multiplicity is negative or null nothing is
    //! done. The  new   multiplicity  is limited  to  the
    //! degree.
    //!
    //! The  tolerance criterion  for  knots  equality  is
    //! the max of Epsilon(U) and ParametricTolerance.
    //! Standard_Integer M = 1, Standard_Real ParametricTolerance = 0.0, Standard_Boolean Add = Standard_True
    void XGeom_BSplineCurve::InsertKnot(Standard_Real U, Standard_Integer M, Standard_Real ParametricTolerance, Standard_Boolean Add) {
        NativeHandle()->InsertKnot(U, M, ParametricTolerance, Add);
    };

    //! Inserts a set of knots  values in  the sequence of
    //! knots.
    //!
    //! For each U = Knots(i), M = Mults(i)
    //!
    //! If <U>  is an existing  knot  the  multiplicity is
    //! increased by  <M> if  <Add>  is True, increased to
    //! <M> if <Add> is False.
    //!
    //! If U  is  not  on the parameter  range  nothing is
    //! done.
    //!
    //! If the multiplicity is negative or null nothing is
    //! done. The  new   multiplicity  is limited  to  the
    //! degree.
    //!
    //! The  tolerance criterion  for  knots  equality  is
    //! the max of Epsilon(U) and ParametricTolerance.
    //! Standard_Real ParametricTolerance = 0.0, Standard_Boolean Add = Standard_False
    void XGeom_BSplineCurve::InsertKnots(array<Standard_Real>^ Knots, array<Standard_Integer>^ Mults, Standard_Real ParametricTolerance, Standard_Boolean Add) {
        TColStd_Array1OfReal XKnots; TColStd_Array1OfInteger XMults;
        Standard_Integer i = 0, j = 0;
        for each (Standard_Real xReal in Knots)
            XKnots.SetValue(i++, xReal);
        for each (Standard_Integer xInteger in Mults)
            XMults.SetValue(j++, xInteger);
        NativeHandle()->InsertKnots(XKnots, XMults);
    };

    //! Reduces the multiplicity of the knot of index Index
    //! to M. If M is equal to 0, the knot is removed.
    //! With a modification of this type, the array of poles is also modified.
    //! Two different algorithms are systematically used to
    //! compute the new poles of the curve. If, for each
    //! pole, the distance between the pole calculated
    //! using the first algorithm and the same pole
    //! calculated using the second algorithm, is less than
    //! Tolerance, this ensures that the curve is not
    //! modified by more than Tolerance. Under these
    //! conditions, true is returned; otherwise, false is returned.
    //! A low tolerance is used to prevent modification of
    //! the curve. A high tolerance is used to "smooth" the curve.
    //! Exceptions
    //! Standard_OutOfRange if Index is outside the
    //! bounds of the knots table.
    //! pole insertion and pole removing
    //! this operation is limited to the Uniform or QuasiUniform
    //! BSplineCurve. The knot values are modified . If the BSpline is
    //! NonUniform or Piecewise Bezier an exception Construction error
    //! is raised.
    Standard_Boolean XGeom_BSplineCurve::RemoveKnot(Standard_Integer Index, Standard_Integer M, Standard_Real Tolerance) {
        return NativeHandle()->RemoveKnot(Index, M, Tolerance);
    };


    //! Changes the direction of parametrization of <me>. The Knot
    //! sequence is modified, the FirstParameter and the
    //! LastParameter are not modified. The StartPoint of the
    //! initial curve becomes the EndPoint of the reversed curve
    //! and the EndPoint of the initial curve becomes the StartPoint
    //! of the reversed curve.
    void XGeom_BSplineCurve::Reverse() {
        NativeHandle()->Reverse();
    };

    //! Returns the  parameter on the  reversed  curve for
    //! the point of parameter U on <me>.
    //!
    //! returns UFirst + ULast - U
    Standard_Real XGeom_BSplineCurve::ReversedParameter(Standard_Real U) {
        return NativeHandle()->ReversedParameter(U);
    };

    //! Modifies this BSpline curve by segmenting it between
    //! U1 and U2. Either of these values can be outside the
    //! bounds of the curve, but U2 must be greater than U1.
    //! All data structure tables of this BSpline curve are
    //! modified, but the knots located between U1 and U2
    //! are retained. The degree of the curve is not modified.
    //!
    //! Parameter theTolerance defines the possible proximity of the segment
    //! boundaries and B-spline knots to treat them as equal.
    //!
    //! Warnings :
    //! Even if <me> is not closed it can become closed after the
    //! segmentation for example if U1 or U2 are out of the bounds
    //! of the curve <me> or if the curve makes loop.
    //! After the segmentation the length of a curve can be null.
    //! raises if U2 < U1.
    //! Standard_DomainError if U2 - U1 exceeds the period for periodic curves.
    //! i.e. ((U2 - U1) - Period) > Precision::PConfusion().
    //! Standard_Real theTolerance = Precision::PConfusion()
    void XGeom_BSplineCurve::Segment(Standard_Real U1, Standard_Real U2, Standard_Real theTolerance) {
        NativeHandle()->Segment(U1, U2, theTolerance);
    };

    //! Modifies this BSpline curve by assigning the value K
    //! to the knot of index Index in the knots table. This is a
    //! relatively local modification because K must be such that:
    //! Knots(Index - 1) < K < Knots(Index + 1)
    //! The second syntax allows you also to increase the
    //! multiplicity of the knot to M (but it is not possible to
    //! decrease the multiplicity of the knot with this function).
    //! Standard_ConstructionError if:
    //! - K is not such that:
    //! Knots(Index - 1) < K < Knots(Index + 1)
    //! - M is greater than the degree of this BSpline curve
    //! or lower than the previous multiplicity of knot of
    //! index Index in the knots table.
    //! Standard_OutOfRange if Index is outside the bounds of the knots table.
    void XGeom_BSplineCurve::SetKnot(Standard_Integer Index, Standard_Real K) {
        NativeHandle()->SetKnot(Index, K);
    };

    //! Modifies this BSpline curve by assigning the array
    //! K to its knots table. The multiplicity of the knots is not modified.
    //! Exceptions
    //! Standard_ConstructionError if the values in the
    //! array K are not in ascending order.
    //! Standard_OutOfRange if the bounds of the array
    //! K are not respectively 1 and the number of knots of this BSpline curve.
    void XGeom_BSplineCurve::SetKnots(array<Standard_Real>^ K) {
        TColStd_Array1OfReal XK; Standard_Integer i = 0;
        for each (Standard_Real xReal in K)
            XK.SetValue(i++, xReal);
        NativeHandle()->SetKnots(XK);
    };


    //! Changes the knot of range Index with its multiplicity.
    //! You can increase the multiplicity of a knot but it is
    //! not allowed to decrease the multiplicity of an existing knot.
    //!
    //! Raised if K >= Knots(Index+1) or K <= Knots(Index-1).
    //! Raised if M is greater than Degree or lower than the previous
    //! multiplicity of knot of range Index.
    //! Raised if Index < 1 || Index > NbKnots
    void XGeom_BSplineCurve::SetKnot(Standard_Integer Index, Standard_Real K, Standard_Integer M) {
        NativeHandle()->SetKnot(Index, K, M);
    };

    //! returns the parameter normalized within
    //! the period if the curve is periodic : otherwise
    //! does not do anything
    void XGeom_BSplineCurve::PeriodicNormalization(Standard_Real^ U) {
        Standard_Real XU = Standard_Real(U);
        NativeHandle()->PeriodicNormalization(XU);
        U = XU;
    };

    //! Changes this BSpline curve into a periodic curve.
    //! To become periodic, the curve must first be closed.
    //! Next, the knot sequence must be periodic. For this,
    //! FirstUKnotIndex and LastUKnotIndex are used
    //! to compute I1 and I2, the indexes in the knots
    //! array of the knots corresponding to the first and
    //! last parameters of this BSpline curve.
    //! The period is therefore: Knots(I2) - Knots(I1).
    //! Consequently, the knots and poles tables are modified.
    //! Exceptions
    //! Standard_ConstructionError if this BSpline curve is not closed.
    void XGeom_BSplineCurve::SetPeriodic() {
        NativeHandle()->SetPeriodic();
    };

    //! Assigns the knot of index Index in the knots table as
    //! the origin of this periodic BSpline curve. As a
    //! consequence, the knots and poles tables are modified.
    //! Exceptions
    //! Standard_NoSuchObject if this curve is not periodic.
    //! Standard_DomainError if Index is outside the bounds of the knots table.
    void XGeom_BSplineCurve::SetOrigin(Standard_Integer Index) {
        NativeHandle()->SetOrigin(Index);
    };

    //! Set the origin of a periodic curve at Knot U. If U
    //! is  not a  knot  of  the  BSpline  a  new knot  is
    //! inseted. KnotVector and poles are modified.
    //! Raised if the curve is not periodic
    void XGeom_BSplineCurve::SetOrigin(Standard_Real U, Standard_Real Tol) {
        NativeHandle()->SetOrigin(U, Tol);
    };

    //! Changes this BSpline curve into a non-periodic
    //! curve. If this curve is already non-periodic, it is not modified.
    //! Note: the poles and knots tables are modified.
    //! Warning
    //! If this curve is periodic, as the multiplicity of the first
    //! and last knots is not modified, and is not equal to
    //! Degree + 1, where Degree is the degree of
    //! this BSpline curve, the start and end points of the
    //! curve are not its first and last poles.
    void XGeom_BSplineCurve::SetNotPeriodic() {
        NativeHandle()->SetNotPeriodic();
    };

    //! Modifies this BSpline curve by assigning P to the pole
    //! of index Index in the poles table.
    //! Exceptions
    //! Standard_OutOfRange if Index is outside the
    //! bounds of the poles table.
    //! Standard_ConstructionError if Weight is negative or null.
    void XGeom_BSplineCurve::SetPole(Standard_Integer Index, xgp_Pnt^ P) {
        NativeHandle()->SetPole(Index, *P->GetPnt());
    };

    //! Modifies this BSpline curve by assigning P to the pole
    //! of index Index in the poles table.
    //! This syntax also allows you to modify the
    //! weight of the modified pole, which becomes Weight.
    //! In this case, if this BSpline curve is non-rational, it
    //! can become rational and vice versa.
    //! Exceptions
    //! Standard_OutOfRange if Index is outside the
    //! bounds of the poles table.
    //! Standard_ConstructionError if Weight is negative or null.
    void XGeom_BSplineCurve::SetPole(Standard_Integer Index, xgp_Pnt^ P, Standard_Real Weight) {
        NativeHandle()->SetPole(Index, *P->GetPnt(), Weight);
    };


    //! Changes the weight for the pole of range Index.
    //! If the curve was non rational it can become rational.
    //! If the curve was rational it can become non rational.
    //!
    //! Raised if Index < 1 || Index > NbPoles
    //! Raised if Weight <= 0.0
    void XGeom_BSplineCurve::SetWeight(Standard_Integer Index, Standard_Real Weight) {
        NativeHandle()->SetWeight(Index, Weight);
    };

    //! Moves the point of parameter U of this BSpline curve
    //! to P. Index1 and Index2 are the indexes in the table
    //! of poles of this BSpline curve of the first and last
    //! poles designated to be moved.
    //! FirstModifiedPole and LastModifiedPole are the
    //! indexes of the first and last poles which are effectively modified.
    //! In the event of incompatibility between Index1, Index2 and the value U:
    //! - no change is made to this BSpline curve, and
    //! - the FirstModifiedPole and LastModifiedPole are returned null.
    //! Exceptions
    //! Standard_OutOfRange if:
    //! - Index1 is greater than or equal to Index2, or
    //! - Index1 or Index2 is less than 1 or greater than the
    //! number of poles of this BSpline curve.
    void XGeom_BSplineCurve::MovePoint(Standard_Real U, xgp_Pnt^ P, Standard_Integer Index1, Standard_Integer Index2, Standard_Integer% FirstModifiedPole, Standard_Integer% LastModifiedPole) {
        Standard_Integer XFirstModifiedPole(FirstModifiedPole); Standard_Integer XLastModifiedPole(LastModifiedPole);
        NativeHandle()->MovePoint(U, *P->GetPnt(), Index1, Index2, XFirstModifiedPole, XLastModifiedPole);
        FirstModifiedPole = XFirstModifiedPole; LastModifiedPole = XLastModifiedPole;
    };


    //! Move a point with parameter U to P.
    //! and makes it tangent at U be Tangent.
    //! StartingCondition = -1 means first can move
    //! EndingCondition   = -1 means last point can move
    //! StartingCondition = 0 means the first point cannot move
    //! EndingCondition   = 0 means the last point cannot move
    //! StartingCondition = 1 means the first point and tangent cannot move
    //! EndingCondition   = 1 means the last point and tangent cannot move
    //! and so forth
    //! ErrorStatus != 0 means that there are not enought degree of freedom
    //! with the constrain to deform the curve accordingly
    void XGeom_BSplineCurve::MovePointAndTangent(Standard_Real U, xgp_Pnt^ P, xgp_Vec^ Tangent, Standard_Real Tolerance, Standard_Integer StartingCondition, Standard_Integer EndingCondition, Standard_Integer% ErrorStatus) {
        Standard_Integer XErrorStatus(ErrorStatus); 
        NativeHandle()->MovePointAndTangent(U, *P->GetPnt(), *Tangent->GetVec(), Tolerance, StartingCondition, EndingCondition, XErrorStatus);
        ErrorStatus = XErrorStatus;
    };


    //! Returns the continuity of the curve, the curve is at least C0.
    //! Raised if N < 0.
    Standard_Boolean XGeom_BSplineCurve::IsCN(Standard_Integer N) {
        return NativeHandle()->IsCN(N);
    };


    //! Check if curve has at least G1 continuity in interval [theTf, theTl]
    //! Returns true if IsCN(1)
    //! or
    //! angle betweem "left" and "right" first derivatives at
    //! knots with C0 continuity is less then theAngTol
    //! only knots in interval [theTf, theTl] is checked
    Standard_Boolean XGeom_BSplineCurve::IsG1(Standard_Real theTf, Standard_Real theTl, Standard_Real theAngTol) {
        return NativeHandle()->IsG1(theTf, theTl, theAngTol);
    };


    //! Returns true if the distance between the first point and the
    //! last point of the curve is lower or equal to Resolution
    //! from package gp.
    //! Warnings :
    //! The first and the last point can be different from the first
    //! pole and the last pole of the curve.
    Standard_Boolean XGeom_BSplineCurve::IsClosed() {
        return NativeHandle()->IsClosed();
    };

    //! Returns True if the curve is periodic.
    Standard_Boolean XGeom_BSplineCurve::IsPeriodic() {
        return NativeHandle()->IsPeriodic();
    };


    //! Returns True if the weights are not identical.
    //! The tolerance criterion is Epsilon of the class Real.
    Standard_Boolean XGeom_BSplineCurve::IsRational() {
        return NativeHandle()->IsRational();
    };


    //! Returns the global continuity of the curve :
    //! C0 : only geometric continuity,
    //! C1 : continuity of the first derivative all along the Curve,
    //! C2 : continuity of the second derivative all along the Curve,
    //! C3 : continuity of the third derivative all along the Curve,
    //! CN : the order of continuity is infinite.
    //! For a B-spline curve of degree d if a knot Ui has a
    //! multiplicity p the B-spline curve is only Cd-p continuous
    //! at Ui. So the global continuity of the curve can't be greater
    //! than Cd-p where p is the maximum multiplicity of the interior
    //! Knots. In the interior of a knot span the curve is infinitely
    //! continuously differentiable.
    XGeomAbs_Shape XGeom_BSplineCurve::Continuity() {
        return safe_cast<XGeomAbs_Shape>(NativeHandle()->Continuity());
    };

    //! Returns the degree of this BSpline curve.
    //! The degree of a Geom_BSplineCurve curve cannot
    //! be greater than Geom_BSplineCurve::MaxDegree().
    //! Computation of value and derivatives
    Standard_Integer XGeom_BSplineCurve::Degree() {
        return NativeHandle()->Degree();
    };

    //! Returns in P the point of parameter U.
    void XGeom_BSplineCurve::D0(Standard_Real U, xgp_Pnt^ P) {
        NativeHandle()->D0(U, *P->GetPnt());
    };

    //! Raised if the continuity of the curve is not C1.
    void XGeom_BSplineCurve::D1(Standard_Real U, xgp_Pnt^ P, xgp_Vec^ V1) {
        NativeHandle()->D1(U, *P->GetPnt(), *V1->GetVec());
    };

    //! Raised if the continuity of the curve is not C2.
    void XGeom_BSplineCurve::D2(Standard_Real U, xgp_Pnt^ P, xgp_Vec^ V1, xgp_Vec^ V2) {
        NativeHandle()->D2(U, *P->GetPnt(), *V1->GetVec(), *V2->GetVec());
    };

    //! Raised if the continuity of the curve is not C3.
    void XGeom_BSplineCurve::D3(Standard_Real U, xgp_Pnt^ P, xgp_Vec^ V1, xgp_Vec^ V2, xgp_Vec^ V3) {
        NativeHandle()->D3(U, *P->GetPnt(), *V1->GetVec(), *V2->GetVec(), *V3->GetVec());
    };

    //! For the point of parameter U of this BSpline curve,
    //! computes the vector corresponding to the Nth derivative.
    //! Warning
    //! On a point where the continuity of the curve is not the
    //! one requested, this function impacts the part defined
    //! by the parameter with a value greater than U, i.e. the
    //! part of the curve to the "right" of the singularity.
    //! Exceptions
    //! Standard_RangeError if N is less than 1.
    //!
    //! The following functions compute the point of parameter U
    //! and the derivatives at this point on the B-spline curve
    //! arc defined between the knot FromK1 and the knot ToK2.
    //! U can be out of bounds [Knot (FromK1),  Knot (ToK2)] but
    //! for the computation we only use the definition of the curve
    //! between these two knots. This method is useful to compute
    //! local derivative, if the order of continuity of the whole
    //! curve is not greater enough.    Inside the parametric
    //! domain Knot (FromK1), Knot (ToK2) the evaluations are
    //! the same as if we consider the whole definition of the
    //! curve. Of course the evaluations are different outside
    //! this parametric domain.
    xgp_Vec^ XGeom_BSplineCurve::DN(Standard_Real U, Standard_Integer N) {
        gp_Vec* temp = new gp_Vec(NativeHandle()->DN(U, N));
        return gcnew xgp_Vec(temp);
    };

    //! Raised if FromK1 = ToK2.
    xgp_Pnt^ XGeom_BSplineCurve::LocalValue(Standard_Real U, Standard_Integer FromK1, Standard_Integer ToK2) {
        gp_Pnt* temp = new gp_Pnt(NativeHandle()->LocalValue(U, FromK1, ToK2));
        return gcnew xgp_Pnt(temp);
    };

    //! Raised if FromK1 = ToK2.
    void XGeom_BSplineCurve::LocalD0(Standard_Real U, Standard_Integer FromK1, Standard_Integer ToK2, xgp_Pnt^ P) {
        NativeHandle()->LocalD0(U, FromK1, ToK2, *P->GetPnt());
    };


    //! Raised if the local continuity of the curve is not C1
    //! between the knot K1 and the knot K2.
    //! Raised if FromK1 = ToK2.
    void XGeom_BSplineCurve::LocalD1(Standard_Real U, Standard_Integer FromK1, Standard_Integer ToK2, xgp_Pnt^ P, xgp_Vec^ V1) {
        NativeHandle()->LocalD1(U, FromK1, ToK2, *P->GetPnt(), *V1->GetVec());
    };


    //! Raised if the local continuity of the curve is not C2
    //! between the knot K1 and the knot K2.
    //! Raised if FromK1 = ToK2.
    void XGeom_BSplineCurve::LocalD2(Standard_Real U, Standard_Integer FromK1, Standard_Integer ToK2, xgp_Pnt^ P, xgp_Vec^ V1, xgp_Vec^ V2) {
        NativeHandle()->LocalD2(U, FromK1, ToK2, *P->GetPnt(), *V1->GetVec(),*V2->GetVec());
    };


    //! Raised if the local continuity of the curve is not C3
    //! between the knot K1 and the knot K2.
    //! Raised if FromK1 = ToK2.
    void XGeom_BSplineCurve::LocalD3(Standard_Real U, Standard_Integer FromK1, Standard_Integer ToK2, xgp_Pnt^ P, xgp_Vec^ V1, xgp_Vec^ V2, xgp_Vec^ V3) {
        NativeHandle()->LocalD3(U, FromK1, ToK2, *P->GetPnt(), *V1->GetVec(), *V2->GetVec(),*V3->GetVec());
    };


    //! Raised if the local continuity of the curve is not CN
    //! between the knot K1 and the knot K2.
    //! Raised if FromK1 = ToK2.
    //! Raised if N < 1.
    xgp_Vec^ XGeom_BSplineCurve::LocalDN(Standard_Real U, Standard_Integer FromK1, Standard_Integer ToK2, Standard_Integer N) {
        gp_Vec* temp = new gp_Vec(NativeHandle()->LocalDN(U, FromK1, ToK2, N));
        return gcnew xgp_Vec(temp);
    };


    //! Returns the last point of the curve.
    //! Warnings :
    //! The last point of the curve is different from the last
    //! pole of the curve if the multiplicity of the last knot
    //! is lower than Degree.
    xgp_Pnt^ XGeom_BSplineCurve::EndPoint() {
        gp_Pnt* temp = new gp_Pnt(NativeHandle()->EndPoint());
        return gcnew xgp_Pnt(temp);
    };

    //! Returns the index in the knot array of the knot
    //! corresponding to the first or last parameter of this BSpline curve.
    //! For a BSpline curve, the first (or last) parameter
    //! (which gives the start (or end) point of the curve) is a
    //! knot value. However, if the multiplicity of the first (or
    //! last) knot is less than Degree + 1, where
    //! Degree is the degree of the curve, it is not the first
    //! (or last) knot of the curve.
    Standard_Integer XGeom_BSplineCurve::FirstUKnotIndex() {
        return NativeHandle()->FirstUKnotIndex();
    };

    //! Returns the value of the first parameter of this
    //! BSpline curve. This is a knot value.
    //! The first parameter is the one of the start point of the BSpline curve.
    Standard_Real XGeom_BSplineCurve::FirstParameter() {
        return NativeHandle()->FirstParameter();
    };


    //! Returns the knot of range Index. When there is a knot
    //! with a multiplicity greater than 1 the knot is not repeated.
    //! The method Multiplicity can be used to get the multiplicity
    //! of the Knot.
    //! Raised if Index < 1 or Index > NbKnots
    Standard_Real XGeom_BSplineCurve::Knot(Standard_Integer Index) {
        return NativeHandle()->Knot(Index);
    };

    //! returns the knot values of the B-spline curve;
    //! Warning
    //! A knot with a multiplicity greater than 1 is not
    //! repeated in the knot table. The Multiplicity function
    //! can be used to obtain the multiplicity of each knot.
    //!
    //! Raised K.Lower() is less than number of first knot or
    //! K.Upper() is more than number of last knot.
    void XGeom_BSplineCurve::Knots(array<Standard_Real>^ K) {
        TColStd_Array1OfReal XK;
        Standard_Integer i = 0, j = 0;
        for each (Standard_Real xReal in K)
            XK.SetValue(i++, xReal);
        NativeHandle()->Knots(XK);
    };

    //! returns the knot values of the B-spline curve;
    //! Warning
    //! A knot with a multiplicity greater than 1 is not
    //! repeated in the knot table. The Multiplicity function
    //! can be used to obtain the multiplicity of each knot.
    array<Standard_Real>^ XGeom_BSplineCurve::Knots() {
        TColStd_Array1OfReal XK = NativeHandle()->Knots();
        array<Standard_Real>^ K = gcnew array<Standard_Real>(XK.Length());
        Standard_Integer i = 0;
        for each (Standard_Real xReal in XK)
            K->SetValue(xReal, i++);
        return K;
    };

    //! Returns K, the knots sequence of this BSpline curve.
    //! In this sequence, knots with a multiplicity greater than 1 are repeated.
    //! In the case of a non-periodic curve the length of the
    //! sequence must be equal to the sum of the NbKnots
    //! multiplicities of the knots of the curve (where
    //! NbKnots is the number of knots of this BSpline
    //! curve). This sum is also equal to : NbPoles + Degree + 1
    //! where NbPoles is the number of poles and
    //! Degree the degree of this BSpline curve.
    //! In the case of a periodic curve, if there are k periodic
    //! knots, the period is Knot(k+1) - Knot(1).
    //! The initial sequence is built by writing knots 1 to k+1,
    //! which are repeated according to their corresponding multiplicities.
    //! If Degree is the degree of the curve, the degree of
    //! continuity of the curve at the knot of index 1 (or k+1)
    //! is equal to c = Degree + 1 - Mult(1). c
    //! knots are then inserted at the beginning and end of
    //! the initial sequence:
    //! - the c values of knots preceding the first item
    //! Knot(k+1) in the initial sequence are inserted
    //! at the beginning; the period is subtracted from these c values;
    //! - the c values of knots following the last item
    //! Knot(1) in the initial sequence are inserted at
    //! the end; the period is added to these c values.
    //! The length of the sequence must therefore be equal to:
    //! NbPoles + 2*Degree - Mult(1) + 2.
    //! Example
    //! For a non-periodic BSpline curve of degree 2 where:
    //! - the array of knots is: { k1 k2 k3 k4 },
    //! - with associated multiplicities: { 3 1 2 3 },
    //! the knot sequence is:
    //! K = { k1 k1 k1 k2 k3 k3 k4 k4 k4 }
    //! For a periodic BSpline curve of degree 4 , which is
    //! "C1" continuous at the first knot, and where :
    //! - the periodic knots are: { k1 k2 k3 (k4) }
    //! (3 periodic knots: the points of parameter k1 and k4
    //! are identical, the period is p = k4 - k1),
    //! - with associated multiplicities: { 3 1 2 (3) },
    //! the degree of continuity at knots k1 and k4 is:
    //! Degree + 1 - Mult(i) = 2.
    //! 2 supplementary knots are added at the beginning
    //! and end of the sequence:
    //! - at the beginning: the 2 knots preceding k4 minus
    //! the period; in this example, this is k3 - p both times;
    //! - at the end: the 2 knots following k1 plus the period;
    //! in this example, this is k2 + p and k3 + p.
    //! The knot sequence is therefore:
    //! K = { k3-p k3-p k1 k1 k1 k2 k3 k3
    //! k4 k4 k4 k2+p k3+p }
    //! Exceptions
    //! Raised if K.Lower() is less than number of first knot
    //! in knot sequence with repetitions or K.Upper() is more
    //! than number of last knot in knot sequence with repetitions.
    void XGeom_BSplineCurve::KnotSequence(array<Standard_Real>^ K) {
        TColStd_Array1OfReal XK;
        Standard_Integer i = 0;
        for each (Standard_Real xReal in K)
            XK.SetValue(i++, xReal);
        NativeHandle()->KnotSequence(XK);
    };

    //! returns the knots of the B-spline curve.
    //! Knots with multiplicit greater than 1 are repeated
    array<Standard_Real>^ XGeom_BSplineCurve::KnotSequence() {
        TColStd_Array1OfReal XK = NativeHandle()->KnotSequence();
        array<Standard_Real>^ K = gcnew array<Standard_Real>(XK.Length());
        Standard_Integer i = 0;
        for each (Standard_Real xReal in XK)
            K->SetValue(xReal, i++);
        return K;
    };


    //! Returns NonUniform or Uniform or QuasiUniform or PiecewiseBezier.
    //! If all the knots differ by a positive constant from the
    //! preceding knot the BSpline Curve can be :
    //! - Uniform if all the knots are of multiplicity 1,
    //! - QuasiUniform if all the knots are of multiplicity 1 except for
    //! the first and last knot which are of multiplicity Degree + 1,
    //! - PiecewiseBezier if the first and last knots have multiplicity
    //! Degree + 1 and if interior knots have multiplicity Degree
    //! A piecewise Bezier with only two knots is a BezierCurve.
    //! else the curve is non uniform.
    //! The tolerance criterion is Epsilon from class Real.
    XGeomAbs_BSplKnotDistribution XGeom_BSplineCurve::KnotDistribution() {
        return safe_cast<XGeomAbs_BSplKnotDistribution>(NativeHandle()->KnotDistribution());
    };


    //! For a BSpline curve the last parameter (which gives the
    //! end point of the curve) is a knot value but if the
    //! multiplicity of the last knot index is lower than
    //! Degree + 1 it is not the last knot of the curve. This
    //! method computes the index of the knot corresponding to
    //! the last parameter.
    Standard_Integer XGeom_BSplineCurve::LastUKnotIndex() {
        return NativeHandle()->LastUKnotIndex();
    };


    //! Computes the parametric value of the end point of the curve.
    //! It is a knot value.
    Standard_Real XGeom_BSplineCurve::LastParameter() {
        return NativeHandle()->LastParameter();
    };


    //! Locates the parametric value U in the sequence of knots.
    //! If "WithKnotRepetition" is True we consider the knot's
    //! representation with repetition of multiple knot value,
    //! otherwise  we consider the knot's representation with
    //! no repetition of multiple knot values.
    //! Knots (I1) <= U <= Knots (I2)
    //! . if I1 = I2  U is a knot value (the tolerance criterion
    //! ParametricTolerance is used).
    //! . if I1 < 1  => U < Knots (1) - Abs(ParametricTolerance)
    //! . if I2 > NbKnots => U > Knots (NbKnots) + Abs(ParametricTolerance)
    //! Standard_Boolean WithKnotRepetition = Standard_False
    void XGeom_BSplineCurve::LocateU(Standard_Real U, Standard_Real ParametricTolerance, Standard_Integer^ I1, Standard_Integer^ I2, Standard_Boolean WithKnotRepetition) {
        Standard_Integer XI1 = *I1; Standard_Integer XI2 = *I2;
        NativeHandle()->LocateU(U, ParametricTolerance,XI1, XI2, WithKnotRepetition);
        I1 = XI1; I2 = XI2;
    };


    //! Returns the multiplicity of the knots of range Index.
    //! Raised if Index < 1 or Index > NbKnots
    Standard_Integer XGeom_BSplineCurve::Multiplicity(Standard_Integer Index) {
        return NativeHandle()->Multiplicity(Index);
    };


    //! Returns the multiplicity of the knots of the curve.
    //!
    //! Raised if the length of M is not equal to NbKnots.
    void XGeom_BSplineCurve::Multiplicities(array<Standard_Integer>^ M) {
        TColStd_Array1OfInteger XM;
        Standard_Integer i = 0;
        for each (Standard_Integer xInteger in M)
            XM.SetValue(i++, xInteger);
        return NativeHandle()->Multiplicities(XM);
    };

    //! returns the multiplicity of the knots of the curve.
    array<Standard_Integer>^ XGeom_BSplineCurve::Multiplicities() {
        TColStd_Array1OfInteger XM = NativeHandle()->Multiplicities();
        array<Standard_Integer>^ M = gcnew array<Standard_Integer>(XM.Length());
        Standard_Integer i = 0;
        for each (Standard_Integer xInteger in XM)
            M->SetValue(xInteger, i++);
        return M;
    };


    //! Returns the number of knots. This method returns the number of
    //! knot without repetition of multiple knots.
    Standard_Integer XGeom_BSplineCurve::NbKnots() {
        return NativeHandle()->NbKnots();
    };

    //! Returns the number of poles
    Standard_Integer XGeom_BSplineCurve::NbPoles() {
        return NativeHandle()->NbPoles();
    };

    //! Returns the pole of range Index.
    //! Raised if Index < 1 or Index > NbPoles.
    xgp_Pnt^ XGeom_BSplineCurve::Pole(Standard_Integer Index) {
        gp_Pnt* temp = new gp_Pnt(NativeHandle()->Pole(Index));
        return gcnew xgp_Pnt(temp);
    };

    //! Returns the poles of the B-spline curve;
    //!
    //! Raised if the length of P is not equal to the number of poles.
    void XGeom_BSplineCurve::Poles(array<xgp_Pnt^>^ P) {
        TColgp_Array1OfPnt XP; Standard_Integer i = 0;
        for each (xgp_Pnt ^ xPnt in P) 
            XP.SetValue(i++, *xPnt->GetPnt());
        return NativeHandle()->Poles(XP);
    };

    //! Returns the poles of the B-spline curve;
    array<xgp_Pnt^>^ XGeom_BSplineCurve::Poles() {
        TColgp_Array1OfPnt XP = NativeHandle()->Poles();
        array<xgp_Pnt^>^ P = gcnew array<xgp_Pnt^>(XP.Length());
        Standard_Integer i = 0;
        for each (gp_Pnt xPnt in XP) {
            gp_Pnt* gpPnt = new gp_Pnt(xPnt);
            xgp_Pnt^ temp = gcnew xgp_Pnt(gpPnt);
            P->SetValue(temp, i++);
        }
        return P;
    };


    //! Returns the start point of the curve.
    //! Warnings :
    //! This point is different from the first pole of the curve if the
    //! multiplicity of the first knot is lower than Degree.
    xgp_Pnt^ XGeom_BSplineCurve::StartPoint() {
        gp_Pnt* temp = new gp_Pnt(NativeHandle()->StartPoint());
        return gcnew xgp_Pnt(temp);
    };

    //! Returns the weight of the pole of range Index .
    //! Raised if Index < 1 or Index > NbPoles.
    Standard_Real XGeom_BSplineCurve::Weight(Standard_Integer Index) {
        return NativeHandle()->Weight(Index);
    };

    //! Returns the weights of the B-spline curve;
    //!
    //! Raised if the length of W is not equal to NbPoles.
    void XGeom_BSplineCurve::Weights(array<Standard_Real>^ W) {
        TColStd_Array1OfReal XW; Standard_Integer i = 0;
        for each (Standard_Real xReal in W)
            XW.SetValue(i++, xReal);
        return NativeHandle()->Weights(XW);
    };

    //! Returns the weights of the B-spline curve;
    array<Standard_Real>^ XGeom_BSplineCurve::Weights() {
        const TColStd_Array1OfReal* XW = NativeHandle()->Weights();
        array<Standard_Real>^ W = gcnew array<Standard_Real>(XW->Length());
        Standard_Integer i = 0;
        for (Standard_Integer i = 0; i < XW->Length(); i++)
            W->SetValue(XW->Value(i), i++);
        return W;
    };

    //! Applies the transformation T to this BSpline curve.
    void XGeom_BSplineCurve::Transform(xgp_Trsf^ T) {
        NativeHandle()->Transform(*T->GetTrsf());
    };


    //! Returns the value of the maximum degree of the normalized
    //! B-spline basis functions in this package.
    // static 
    Standard_Integer XGeom_BSplineCurve::MaxDegree() {
        return Geom_BSplineCurve::MaxDegree();
    };

    //! Computes for this BSpline curve the parametric
    //! tolerance UTolerance for a given 3D tolerance Tolerance3D.
    //! If f(t) is the equation of this BSpline curve,
    //! UTolerance ensures that:
    //! | t1 - t0| < Utolerance ===>
    //! |f(t1) - f(t0)| < Tolerance3D
    void XGeom_BSplineCurve::Resolution(Standard_Real Tolerance3D, Standard_Real^ UTolerance) {
        Standard_Real XUTolerance = Standard_Real(UTolerance);
        NativeHandle()->Resolution(Tolerance3D, XUTolerance);
        UTolerance = XUTolerance;
    };

    //! Creates a new object which is a copy of this BSpline curve.
    XGeom_Geometry^ XGeom_BSplineCurve::Copy() {
        return gcnew XGeom_Geometry(NativeHandle()->Copy());
    };

    //! Comapare two Bspline curve on identity;
    Standard_Boolean XGeom_BSplineCurve::IsEqual(XGeom_BSplineCurve^ theOther, Standard_Real thePreci) {
        return NativeHandle()->IsEqual(theOther->GetBSplineCurve(), thePreci);
    };
}
