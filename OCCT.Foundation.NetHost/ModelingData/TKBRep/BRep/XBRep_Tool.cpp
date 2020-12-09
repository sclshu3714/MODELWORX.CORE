#include <XBRep_Tool.h>
namespace TKBRep {

    //! If S is Shell, returns True if it has no free boundaries (edges).
    //! If S is Wire, returns True if it has no free ends (vertices).
    //! (Internal and External sub-shepes are ignored in these checks)
    //! If S is Edge, returns True if its vertices are the same.
    //! For other shape types returns S.Closed().
    // 
    //! static 
    Standard_Boolean XBRep_Tool::IsClosed(XTopoDS_Shape^ S) {
        return BRep_Tool::IsClosed(*S->GetShape());
    };

    //! Returns the geometric surface of the face. Returns
    //! in <L> the location for the surface.
    //! static 
    XGeom_Surface^ XBRep_Tool::Surface(XTopoDS_Face^ F, XTopLoc_Location^ L) {
        Handle(Geom_Surface) temp = BRep_Tool::Surface(*F->GetFace(), *L->GetLocation());
        return gcnew XGeom_Surface(temp);
    };

    //! Returns the geometric  surface of the face. It can
    //! be a copy if there is a Location.
    //! static 
    XGeom_Surface^ XBRep_Tool::Surface(XTopoDS_Face^ F) {
        Handle(Geom_Surface) temp = BRep_Tool::Surface(*F->GetFace());
        return gcnew XGeom_Surface(temp);
    };

    //! Returns  the Triangulation of  the  face. It  is a
    //! null handle if there is no triangulation.
    //! static 
    Handle(Poly_Triangulation) XBRep_Tool::Triangulation(XTopoDS_Face^ F, XTopLoc_Location^ L) {
        return BRep_Tool::Triangulation(*F->GetFace(),*L->GetLocation());
    };

    //! Returns the tolerance of the face.
    //! static 
    Standard_Real XBRep_Tool::Tolerance(XTopoDS_Face^ F) {
        return BRep_Tool::Tolerance(*F->GetFace());
    };

    //! Returns the  NaturalRestriction  flag of the  face.
    //! static 
    Standard_Boolean XBRep_Tool::NaturalRestriction(XTopoDS_Face^ F) {
        return BRep_Tool::NaturalRestriction(*F->GetFace());
    };

    //! Returns True if <E> is a 3d curve or a curve on
    //! surface.
    //! static 
    Standard_Boolean XBRep_Tool::IsGeometric(XTopoDS_Edge^ E) {
        return BRep_Tool::IsGeometric(*E->GetEdge());
    };

    //! Returns the 3D curve  of the edge.  May be  a Null
    //! handle. Returns in <L> the location for the curve.
    //! In <First> and <Last> the parameter range.
    //! static 
    XGeom_Curve^ XBRep_Tool::Curve(XTopoDS_Edge^ E, XTopLoc_Location^ L, Standard_Real First, Standard_Real Last) {
        Handle(Geom_Curve) temp = BRep_Tool::Curve(*E->GetEdge(),*L->GetLocation(), First, Last);
        return gcnew XGeom_Curve(temp);
    };

    //! Returns the 3D curve  of the edge. May be a Null handle.
    //! In <First> and <Last> the parameter range.
    //! It can be a copy if there is a Location.
    //! static 
    XGeom_Curve^ XBRep_Tool::Curve(XTopoDS_Edge^ E, Standard_Real First, Standard_Real Last) {
        Handle(Geom_Curve) temp = BRep_Tool::Curve(*E->GetEdge(), First, Last);
        return gcnew XGeom_Curve(temp);
    };

    //! Returns the 3D polygon of the edge. May be   a Null
    //! handle. Returns in <L> the location for the polygon.
    //! static 
    Handle(Poly_Polygon3D) XBRep_Tool::Polygon3D(XTopoDS_Edge^ E, XTopLoc_Location^ L) {
        return BRep_Tool::Polygon3D(*E->GetEdge(), *L->GetLocation());
    };

    //! Returns the curve  associated to the  edge in  the
    //! parametric  space of  the  face.  Returns   a NULL
    //! handle  if this curve  does not exist.  Returns in
    //! <First> and <Last> the parameter range.
    //! If the surface is a plane the curve can be not stored but created a new
    //! each time. The flag pointed by <theIsStored> serves to indicate storage status. 
    //! It is valued if the pointer is non-null.
    //! Standard_Boolean* theIsStored = NULL
    //! static 
    XGeom2d_Curve^ XBRep_Tool::CurveOnSurface(XTopoDS_Edge^ E, XTopoDS_Face^ F, Standard_Real First, Standard_Real Last, Standard_Boolean theIsStoredX) {
        Standard_Boolean* theIsStored = &theIsStoredX;
        Handle(Geom2d_Curve) temp = BRep_Tool::CurveOnSurface(*E->GetEdge(), *F->GetFace(), First, Last, theIsStored);
        return gcnew XGeom2d_Curve(temp);
    };

    //! Returns the  curve associated to   the edge in the
    //! parametric  space of the   surface. Returns a NULL
    //! handle  if this curve does  not exist.  Returns in
    //! <First> and <Last> the parameter range.
    //! If the surface is a plane the curve can be not stored but created a new
    //! each time. The flag pointed by <theIsStored> serves to indicate storage status. 
    //! It is valued if the pointer is non-null.
    //! Standard_Boolean* theIsStored = NULL
    //! static 
    XGeom2d_Curve^ XBRep_Tool::CurveOnSurface(XTopoDS_Edge^ E, XGeom_Surface^ S, XTopLoc_Location^ L, Standard_Real First, Standard_Real Last, Standard_Boolean theIsStoredX) {
        Standard_Boolean* theIsStored = &theIsStoredX;
        Handle(Geom2d_Curve) temp = BRep_Tool::CurveOnSurface(*E->GetEdge(), S->GetSurface(), *L->GetLocation(), First, Last, theIsStored);
        return gcnew XGeom2d_Curve(temp);
    };

    //! For the planar surface builds the 2d curve for the edge
    //! by projection of the edge on plane.
    //! Returns a NULL handle if the surface is not planar or
    //! the projection failed.
    //! static 
    XGeom2d_Curve^ XBRep_Tool::CurveOnPlane(XTopoDS_Edge^ E, XGeom_Surface^ S, XTopLoc_Location^ L, Standard_Real First, Standard_Real Last) {
        Handle(Geom2d_Curve) temp = BRep_Tool::CurveOnPlane(*E->GetEdge(), S->GetSurface(), *L->GetLocation(), First, Last);
        return gcnew XGeom2d_Curve(temp);
    };

    //! Returns in <C>, <S>, <L> a 2d curve, a surface and
    //! a location for the edge <E>. <C> and <S>  are null
    //! if the  edge has no curve on  surface.  Returns in
    //! <First> and <Last> the parameter range.
    //! static 
    void XBRep_Tool::CurveOnSurface(XTopoDS_Edge^ E, XGeom2d_Curve^ C, XGeom_Surface^ S, XTopLoc_Location^ L, Standard_Real First, Standard_Real Last) {
        BRep_Tool::CurveOnSurface(*E->GetEdge(), C->GetCurve(), S->GetSurface(), *L->GetLocation(), First, Last);
    };

    //! Returns in <C>, <S>, <L> the 2d curve, the surface
    //! and the location for the edge <E> of rank <Index>.
    //! <C> and <S> are null if the index is out of range.
    //! Returns in <First> and <Last> the parameter range.
    //! static 
    void XBRep_Tool::CurveOnSurface(XTopoDS_Edge^ E, XGeom2d_Curve^ C, XGeom_Surface^ S, XTopLoc_Location^ L, Standard_Real First, Standard_Real Last, Standard_Integer Index) {
        BRep_Tool::CurveOnSurface(*E->GetEdge(), C->GetCurve(), S->GetSurface(), *L->GetLocation(), First, Last, Index);
    };

    //! Returns the polygon associated to the  edge in  the
    //! parametric  space of  the  face.  Returns   a NULL
    //! handle  if this polygon  does not exist.
    //! static 
    Handle(Poly_Polygon2D) XBRep_Tool::PolygonOnSurface(XTopoDS_Edge^ E, XTopoDS_Face^ F) {
        return BRep_Tool::PolygonOnSurface(*E->GetEdge(), *F->GetFace());
    };

    //! Returns the polygon associated to the  edge in  the
    //! parametric  space of  the surface. Returns   a NULL
    //! handle  if this polygon  does not exist.
    //! static 
    Handle(Poly_Polygon2D) XBRep_Tool::PolygonOnSurface(XTopoDS_Edge^ E, XGeom_Surface^ S, XTopLoc_Location^ L) {
        return BRep_Tool::PolygonOnSurface(*E->GetEdge(), S->GetSurface(), *L->GetLocation());
    };

    //! Returns in <C>, <S>, <L> a 2d curve, a surface and
    //! a location for the edge <E>. <C> and <S>  are null
    //! if the  edge has no polygon on  surface.
    //! static 
    void XBRep_Tool::PolygonOnSurface(XTopoDS_Edge^ E, Handle(Poly_Polygon2D)& C, XGeom_Surface^ S, XTopLoc_Location^ L) {
        BRep_Tool::PolygonOnSurface(*E->GetEdge(), C, S->GetSurface(), *L->GetLocation());
    };

    //! Returns in <C>, <S>, <L> the 2d curve, the surface
    //! and the location for the edge <E> of rank <Index>.
    //! <C> and <S> are null if the index is out of range.
    //! static 
    void XBRep_Tool::PolygonOnSurface(XTopoDS_Edge^ E, Handle(Poly_Polygon2D)& C, XGeom_Surface^ S, XTopLoc_Location^ L, Standard_Integer Index) {
        BRep_Tool::PolygonOnSurface(*E->GetEdge(), C, S->GetSurface(), *L->GetLocation(), Index);
    };

    //! Returns the polygon associated to the  edge in  the
    //! parametric  space of  the  face.  Returns   a NULL
    //! handle  if this polygon  does not exist.
    //! static 
    Handle(Poly_PolygonOnTriangulation) XBRep_Tool::PolygonOnTriangulation(XTopoDS_Edge^ E, Handle(Poly_Triangulation)& T, XTopLoc_Location^ L) {
        return BRep_Tool::PolygonOnTriangulation(*E->GetEdge(), T, *L->GetLocation());
    };

    //! Returns in <P>, <T>, <L> a polygon on triangulation, a
    //! triangulation and a location for the edge <E>.
    //! <P>  and  <T>  are null  if  the  edge has no
    //! polygon on  triangulation.
    //! static 
    void XBRep_Tool::PolygonOnTriangulation(XTopoDS_Edge^ E, Handle(Poly_PolygonOnTriangulation)& P, Handle(Poly_Triangulation)& T, XTopLoc_Location^ L) {
        BRep_Tool::PolygonOnTriangulation(*E->GetEdge(), P, T, *L->GetLocation());
    };

    //! Returns   in   <P>,  <T>,    <L> a     polygon  on
    //! triangulation,   a triangulation  and a  location for
    //! the edge <E> for the range index.  <C> and <S> are
    //! null if the edge has no polygon on triangulation.
    //! static 
    void XBRep_Tool::PolygonOnTriangulation(XTopoDS_Edge^ E, Handle(Poly_PolygonOnTriangulation)& P, Handle(Poly_Triangulation)& T, XTopLoc_Location^ L, Standard_Integer Index) {
        BRep_Tool::PolygonOnTriangulation(*E->GetEdge(),P, T, *L->GetLocation(), Index);
    };

    //! Returns  True  if  <E>  has  two  PCurves  in  the
    //! parametric space of <F>. i.e.  <F>  is on a closed
    //! surface and <E> is on the closing curve.
    //! static 
    Standard_Boolean XBRep_Tool::IsClosed(XTopoDS_Edge^ E, XTopoDS_Face^ F) {
        return BRep_Tool::IsClosed(*E->GetEdge(), *F->GetFace());
    };

    //! Returns  True  if  <E>  has  two  PCurves  in  the
    //! parametric space  of <S>.  i.e.   <S>  is a closed
    //! surface and <E> is on the closing curve.
    //! static 
    Standard_Boolean XBRep_Tool::IsClosed(XTopoDS_Edge^ E, XGeom_Surface^ S, XTopLoc_Location^ L) {
        return BRep_Tool::IsClosed(*E->GetEdge(), S->GetSurface(), *L->GetLocation());
    };

    //! Returns  True  if <E> has two arrays of indices in
    //! the triangulation <T>.
    //! static 
    Standard_Boolean XBRep_Tool::IsClosed(XTopoDS_Edge^ E, Handle(Poly_Triangulation)& T, XTopLoc_Location^ L) {
        return BRep_Tool::IsClosed(*E->GetEdge(), T, *L->GetLocation());
    };

    //! Returns the tolerance for <E>.
    //! static 
    Standard_Real XBRep_Tool::Tolerance(XTopoDS_Edge^ E) {
        return BRep_Tool::Tolerance(*E->GetEdge());
    };

    //! Returns the SameParameter flag for the edge.
    //! static 
    Standard_Boolean XBRep_Tool::SameParameter(XTopoDS_Edge^ E) {
        return BRep_Tool::SameParameter(*E->GetEdge());
    };

    //! Returns the SameRange flag for the edge.
    //! static 
    Standard_Boolean XBRep_Tool::SameRange(XTopoDS_Edge^ E) {
        return BRep_Tool::SameRange(*E->GetEdge());
    };

    //! Returns True  if the edge is degenerated.
    //! static 
    Standard_Boolean XBRep_Tool::Degenerated(XTopoDS_Edge^ E) {
        return BRep_Tool::Degenerated(*E->GetEdge());
    };

    //! Gets the range of the 3d curve.
    //! static 
    void XBRep_Tool::Range(XTopoDS_Edge^ E, Standard_Real First, Standard_Real Last) {
        BRep_Tool::Range(*E->GetEdge(), First, Last);
    };

    //! Gets the range  of the edge  on the pcurve on  the
    //! surface.
    //! static 
    void XBRep_Tool::Range(XTopoDS_Edge^ E, XGeom_Surface^ S, XTopLoc_Location^ L, Standard_Real First, Standard_Real Last) {
        BRep_Tool::Range(*E->GetEdge(), S->GetSurface(), *L->GetLocation(), First, Last);
    };

    //! Gets the range of the edge on the pcurve on the face.
    //! static 
    void XBRep_Tool::Range(XTopoDS_Edge^ E, XTopoDS_Face^ F, Standard_Real First, Standard_Real Last) {
        BRep_Tool::Range(*E->GetEdge(), *F->GetFace(), First, Last);
    };

    //! Gets the UV locations of the extremities of the edge.
    //! static 
    void XBRep_Tool::UVPoints(XTopoDS_Edge^ E, XGeom_Surface^ S, XTopLoc_Location^ L, xgp_Pnt2d^ PFirst, xgp_Pnt2d^ PLast) {
        BRep_Tool::UVPoints(*E->GetEdge(), S->GetSurface(), *L->GetLocation(), *PFirst->GetPnt2d(), *PLast->GetPnt2d());
    };

    //! Gets the UV locations of the extremities of the edge.
    //! static 
    void XBRep_Tool::UVPoints(XTopoDS_Edge^ E, XTopoDS_Face^ F, xgp_Pnt2d^ PFirst, xgp_Pnt2d^ PLast) {
        BRep_Tool::UVPoints(*E->GetEdge(), *F->GetFace(), *PFirst->GetPnt2d(), *PLast->GetPnt2d());
    };

    //! Sets the UV locations of the extremities of the edge.
    //! static 
    void XBRep_Tool::SetUVPoints(XTopoDS_Edge^ E, XGeom_Surface^ S, XTopLoc_Location^ L, xgp_Pnt2d^ PFirst, xgp_Pnt2d^ PLast) {
        BRep_Tool::SetUVPoints(*E->GetEdge(),S->GetSurface(), *L->GetLocation(), *PFirst->GetPnt2d(), *PLast->GetPnt2d());
    };

    //! Sets the UV locations of the extremities of the edge.
    //! static 
    void XBRep_Tool::SetUVPoints(XTopoDS_Edge^ E, XTopoDS_Face^ F, xgp_Pnt2d^ PFirst, xgp_Pnt2d^ PLast) {
        BRep_Tool::SetUVPoints(*E->GetEdge(), *F->GetFace(), *PFirst->GetPnt2d(), *PLast->GetPnt2d());
    };

    //! Returns True if the edge is on the surfaces of the
    //! two faces.
    //! static 
    Standard_Boolean XBRep_Tool::HasContinuity(XTopoDS_Edge^ E, XTopoDS_Face^ F1, XTopoDS_Face^ F2) {
        return BRep_Tool::HasContinuity(*E->GetEdge(), *F1->GetFace(), *F2->GetFace());
    };

    //! Returns the continuity.
    //! static 
    XGeomAbs_Shape XBRep_Tool::Continuity(XTopoDS_Edge^ E, XTopoDS_Face^ F1, XTopoDS_Face^ F2) {
        return safe_cast<XGeomAbs_Shape>(BRep_Tool::Continuity(*E->GetEdge(), *F1->GetFace(), *F2->GetFace()));
    };

    //! Returns True if the edge is on the surfaces.
    //! static 
    Standard_Boolean XBRep_Tool::HasContinuity(XTopoDS_Edge^ E, XGeom_Surface^ S1, XGeom_Surface^ S2, XTopLoc_Location^ L1, XTopLoc_Location^ L2) {
        return BRep_Tool::HasContinuity(*E->GetEdge(), S1->GetSurface(), S2->GetSurface(), *L1->GetLocation(), *L2->GetLocation());
    };

    //! Returns the continuity.
    //! static 
    XGeomAbs_Shape XBRep_Tool::Continuity(XTopoDS_Edge^ E, XGeom_Surface^ S1, XGeom_Surface^ S2, XTopLoc_Location^ L1, XTopLoc_Location^ L2) {
        return safe_cast<XGeomAbs_Shape>(BRep_Tool::Continuity(*E->GetEdge(), S1->GetSurface(), S2->GetSurface(), *L1->GetLocation(), *L2->GetLocation()));
    };

    //! Returns True if the edge has regularity on some
    //! two surfaces
    //! static 
    Standard_Boolean XBRep_Tool::HasContinuity(XTopoDS_Edge^ E) {
        return BRep_Tool::HasContinuity(*E->GetEdge());
    };

    //! Returns the max continuity of edge between some surfaces or GeomAbs_C0 if there no such surfaces.
    //! static 
    XGeomAbs_Shape XBRep_Tool::MaxContinuity(XTopoDS_Edge^ theEdge) {
        return safe_cast<XGeomAbs_Shape>(BRep_Tool::MaxContinuity(*theEdge->GetEdge()));
    };

    //! Returns the 3d point.
    //! static 
    xgp_Pnt^ XBRep_Tool::Pnt(XTopoDS_Vertex^ V) {
        gp_Pnt* temp = new gp_Pnt(BRep_Tool::Pnt(*V->GetVertex()));
        return gcnew xgp_Pnt(temp);
    };

    //! Returns the tolerance.
    //! static 
    Standard_Real XBRep_Tool::Tolerance(XTopoDS_Vertex^ V) {
        return BRep_Tool::Tolerance(*V->GetVertex());
    };

    //! Returns the parameter of <V> on <E>.
    //! static 
    Standard_Real XBRep_Tool::Parameter(XTopoDS_Vertex^ V, XTopoDS_Edge^ E) {
        return BRep_Tool::Parameter(*V->GetVertex(), *E->GetEdge());
    };

    //! Returns the  parameters  of   the  vertex   on the
    //! pcurve of the edge on the face.
    //! static 
    Standard_Real XBRep_Tool::Parameter(XTopoDS_Vertex^ V, XTopoDS_Edge^ E, XTopoDS_Face^ F) {
        return BRep_Tool::Parameter(*V->GetVertex(), *E->GetEdge(), *F->GetFace());
    };

    //! Returns the  parameters  of   the  vertex   on the
    //! pcurve of the edge on the surface.
    //! static 
    Standard_Real XBRep_Tool::Parameter(XTopoDS_Vertex^ V, XTopoDS_Edge^ E, XGeom_Surface^ S, XTopLoc_Location^ L) {
        return BRep_Tool::Parameter(*V->GetVertex(), *E->GetEdge(), S->GetSurface(), *L->GetLocation());
    };

    //! Returns the parameters of the vertex on the face.
    //! static 
    xgp_Pnt2d^ XBRep_Tool::Parameters(XTopoDS_Vertex^ V, XTopoDS_Face^ F) {
        gp_Pnt2d* temp = new gp_Pnt2d(BRep_Tool::Parameters(*V->GetVertex(), *F->GetFace()));
        return gcnew xgp_Pnt2d(temp);
    };

    //! Returns the maximum tolerance of input shape subshapes.
    //@param theShape    - Shape to search tolerance.
    //@param theSubShape - Search subshape, only Face, Edge or Vertex are supported.
    //! static 
    Standard_Real XBRep_Tool::MaxTolerance(XTopoDS_Shape^ theShape, XTopAbs_ShapeEnum theSubShape) {
        return BRep_Tool::MaxTolerance(*theShape->GetShape(), safe_cast<TopAbs_ShapeEnum>(theSubShape));
    };
}