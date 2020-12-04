#include <XBRep_Builder.h>
namespace TKBRep {

    //! Creates from a Builder.
    XBRep_Builder::XBRep_Builder(BRep_Builder* pos) : XTopoDS_Builder(pos) {
        NativeHandle = pos;
        SetTopoDSBuilderHandle(pos);
    };

    void XBRep_Builder::SetBRepBuilderHandle(BRep_Builder* pos) {
        NativeHandle = pos;
        SetTopoDSBuilderHandle(pos);
    };

    BRep_Builder* XBRep_Builder::GetBRepBuilder() {
        return NativeHandle;
    };

    TopoDS_Builder* XBRep_Builder::GetTopoDSBuilder() {
        return NativeHandle;
    };

    //! Makes an undefined Face.
    void XBRep_Builder::MakeFace(XTopoDS_Face^ F) {
        NativeHandle->MakeFace(*F->GetFace());
    };

    //! Makes a Face with a surface.
    void XBRep_Builder::MakeFace(XTopoDS_Face^ F, XGeom_Surface^ S, Standard_Real Tol) {
        NativeHandle->MakeFace(*F->GetFace(), S->GetSurface(), Tol);
    };

    //! Makes a Face with a surface and a location.
    void XBRep_Builder::MakeFace(XTopoDS_Face^ F, XGeom_Surface^ S, XTopLoc_Location^ L, Standard_Real Tol) {
        NativeHandle->MakeFace(*F->GetFace(), S->GetSurface(), *L->GetLocation(), Tol);
    };

    //! Makes a Face with a triangulation. The triangulation
    //! is in the same reference system than the TFace.
    void XBRep_Builder::MakeFace(XTopoDS_Face^ F, Handle(Poly_Triangulation)& T) {
        NativeHandle->MakeFace(*F->GetFace(),T);
    };

    //! Updates the face F using the tolerance value Tol,
    //! surface S and location Location.
    void XBRep_Builder::UpdateFace(XTopoDS_Face^ F, XGeom_Surface^ S, XTopLoc_Location^ L, Standard_Real Tol) {
        NativeHandle->UpdateFace(*F->GetFace(), S->GetSurface(), *L->GetLocation(), Tol);
    };

    //! Changes a  face triangulation.
    //!
    //! A null Triangulation removes the triangulation.
    void XBRep_Builder::UpdateFace(XTopoDS_Face^ F, Handle(Poly_Triangulation)& T) {
        NativeHandle->UpdateFace(*F->GetFace(), T);
    };

    //! Updates the face Tolerance.
    void XBRep_Builder::UpdateFace(XTopoDS_Face^ F, Standard_Real Tol) {
        NativeHandle->UpdateFace(*F->GetFace(), Tol);
    };

    //! Sets the  NaturalRestriction flag of  the face.
    void XBRep_Builder::NaturalRestriction(XTopoDS_Face^ F, Standard_Boolean N) {
        NativeHandle->NaturalRestriction(*F->GetFace(), N);
    };

    //! Makes an undefined Edge (no geometry).
    void XBRep_Builder::MakeEdge(XTopoDS_Edge^ E) {
        NativeHandle->MakeEdge(*E->GetEdge());
    };

    //! Makes an Edge with a curve.
    void XBRep_Builder::MakeEdge(XTopoDS_Edge^ E, XGeom_Curve^ C, Standard_Real Tol) {
        NativeHandle->MakeEdge(*E->GetEdge(),C->GetCurve(), Tol);
    };

    //! Makes an Edge with a curve and a location.
    void XBRep_Builder::MakeEdge(XTopoDS_Edge^ E, XGeom_Curve^ C, XTopLoc_Location^ L, Standard_Real Tol) {
        NativeHandle->MakeEdge(*E->GetEdge(), C->GetCurve(), *L->GetLocation(),  Tol);
    };

    //! Makes an Edge with a polygon 3d.
    void XBRep_Builder::MakeEdge(XTopoDS_Edge^ E, Handle(Poly_Polygon3D)& P) {
        NativeHandle->MakeEdge(*E->GetEdge(), P);
    };

    //! makes an Edge polygon on Triangulation.
    void XBRep_Builder::MakeEdge(XTopoDS_Edge^ E, Handle(Poly_PolygonOnTriangulation)& N, Handle(Poly_Triangulation)& T) {
        NativeHandle->MakeEdge(*E->GetEdge(), N, T);
    };

    //! makes an Edge polygon on Triangulation.
    void XBRep_Builder::MakeEdge(XTopoDS_Edge^ E, Handle(Poly_PolygonOnTriangulation)& N, Handle(Poly_Triangulation)& T, XTopLoc_Location^ L) {
        NativeHandle->MakeEdge(*E->GetEdge(), N, T, *L->GetLocation());
    };

    //! Sets a 3D curve for the edge.
    //! If <C> is a null handle, remove any existing 3d curve.
    void XBRep_Builder::UpdateEdge(XTopoDS_Edge^ E, XGeom_Curve^ C, Standard_Real Tol) {
        NativeHandle->UpdateEdge(*E->GetEdge(), C->GetCurve(), Tol);
    };

    //! Sets a 3D curve for the edge.
    //! If <C> is a null handle, remove any existing 3d curve.
    void XBRep_Builder::UpdateEdge(XTopoDS_Edge^ E, XGeom_Curve^ C, XTopLoc_Location^ L, Standard_Real Tol) {
        NativeHandle->UpdateEdge(*E->GetEdge(), C->GetCurve(), *L->GetLocation(), Tol);
    };

    //! Sets a pcurve for the edge on the face.
    //! If <C> is a null handle, remove any existing pcurve.
    void XBRep_Builder::UpdateEdge(XTopoDS_Edge^ E, XGeom2d_Curve^ C, XTopoDS_Face^ F, Standard_Real Tol) {
        NativeHandle->UpdateEdge(*E->GetEdge(), C->GetCurve(), *F->GetFace(), Tol);
    };

    //! Sets pcurves for the edge on the  closed face.  If
    //! <C1> or <C2> is a null handle, remove any existing
    //! pcurve.
    void XBRep_Builder::UpdateEdge(XTopoDS_Edge^ E, XGeom2d_Curve^ C1, XGeom2d_Curve^ C2, XTopoDS_Face^ F, Standard_Real Tol) {
        NativeHandle->UpdateEdge(*E->GetEdge(), C1->GetCurve(), C2->GetCurve(), *F->GetFace(), Tol);
    };

    //! Sets a pcurve for the edge on the face.
    //! If <C> is a null handle, remove any existing pcurve.
    void XBRep_Builder::UpdateEdge(XTopoDS_Edge^ E, XGeom2d_Curve^ C, XGeom_Surface^ S, XTopLoc_Location^ L, Standard_Real Tol) {
        NativeHandle->UpdateEdge(*E->GetEdge(), C->GetCurve(), S->GetSurface(), *L->GetLocation(), Tol);
    };

    //! Sets a pcurve for the edge on the face.
    //! If <C> is a null handle, remove any existing pcurve.
    //! Sets UV bounds for curve repsentation
    void XBRep_Builder::UpdateEdge(XTopoDS_Edge^ E, XGeom2d_Curve^ C, XGeom_Surface^ S, XTopLoc_Location^ L, Standard_Real Tol, xgp_Pnt2d^ Pf, xgp_Pnt2d^ Pl) {
        NativeHandle->UpdateEdge(*E->GetEdge(), C->GetCurve(), S->GetSurface(), *L->GetLocation(), Tol, *Pf->GetPnt2d(), *Pl->GetPnt2d());
    };

    //! Sets pcurves for the edge on the closed surface.
    //! <C1> or <C2> is a null handle, remove any existing
    //! pcurve.
    void XBRep_Builder::UpdateEdge(XTopoDS_Edge^ E, XGeom2d_Curve^ C1, XGeom2d_Curve^ C2, XGeom_Surface^ S, XTopLoc_Location^ L, Standard_Real Tol) {
        NativeHandle->UpdateEdge(*E->GetEdge(), C1->GetCurve(), C2->GetCurve(), S->GetSurface(), *L->GetLocation(), Tol);
    };

    //! Sets pcurves for the edge on the closed surface.
    //! <C1> or <C2> is a null handle, remove any existing
    //! pcurve.
    //! Sets UV bounds for curve repsentation
    void XBRep_Builder::UpdateEdge(XTopoDS_Edge^ E, XGeom2d_Curve^ C1, XGeom2d_Curve^ C2, XGeom_Surface^ S, XTopLoc_Location^ L, Standard_Real Tol, xgp_Pnt2d^ Pf, xgp_Pnt2d^ Pl) {
        NativeHandle->UpdateEdge(*E->GetEdge(), C1->GetCurve(), C2->GetCurve(), S->GetSurface(), *L->GetLocation(), Tol, *Pf->GetPnt2d(), *Pl->GetPnt2d());
    };

    //! Changes an Edge 3D polygon.
    //! A null Polygon removes the 3d Polygon.
    void XBRep_Builder::UpdateEdge(XTopoDS_Edge^ E, Handle(Poly_Polygon3D)& P) {
        NativeHandle->UpdateEdge(*E->GetEdge(), P);
    };

    //! Changes an Edge 3D polygon.
    //! A null Polygon removes the 3d Polygon.
    void XBRep_Builder::UpdateEdge(XTopoDS_Edge^ E, Handle(Poly_Polygon3D)& P, XTopLoc_Location^ L) {
        NativeHandle->UpdateEdge(*E->GetEdge(), P, *L->GetLocation());
    };

    //! Changes an Edge polygon on Triangulation.
    void XBRep_Builder::UpdateEdge(XTopoDS_Edge^ E, Handle(Poly_PolygonOnTriangulation)& N, Handle(Poly_Triangulation)& T) {
        NativeHandle->UpdateEdge(*E->GetEdge(), N, T);
    };

    //! Changes an Edge polygon on Triangulation.
    void XBRep_Builder::UpdateEdge(XTopoDS_Edge^ E, Handle(Poly_PolygonOnTriangulation)& N, Handle(Poly_Triangulation)& T, XTopLoc_Location^ L) {
        NativeHandle->UpdateEdge(*E->GetEdge(), N, T,*L->GetLocation());
    };

    //! Changes an Edge polygon on Triangulation.
    void XBRep_Builder::UpdateEdge(XTopoDS_Edge^ E, Handle(Poly_PolygonOnTriangulation)& N1, Handle(Poly_PolygonOnTriangulation)& N2, Handle(Poly_Triangulation)& T) {
        NativeHandle->UpdateEdge(*E->GetEdge(), N1, N2, T);
    };

    //! Changes an Edge polygon on Triangulation.
    void XBRep_Builder::UpdateEdge(XTopoDS_Edge^ E, Handle(Poly_PolygonOnTriangulation)& N1, Handle(Poly_PolygonOnTriangulation)& N2, Handle(Poly_Triangulation)& T, XTopLoc_Location^ L) {
        NativeHandle->UpdateEdge(*E->GetEdge(), N1, N2, T, *L->GetLocation());
    };

    //! Changes Edge polygon on a face.
    void XBRep_Builder::UpdateEdge(XTopoDS_Edge^ E, Handle(Poly_Polygon2D)& P, XTopoDS_Face^ S) {
        NativeHandle->UpdateEdge(*E->GetEdge(), P, *S->GetFace());
    };

    //! Changes Edge polygon on a face.
    void XBRep_Builder::UpdateEdge(XTopoDS_Edge^ E, Handle(Poly_Polygon2D)& P, XGeom_Surface^ S, XTopLoc_Location^ T) {
        NativeHandle->UpdateEdge(*E->GetEdge(), P, S->GetSurface(), *T->GetLocation());
    };

    //! Changes Edge polygons on a face.
    //!
    //! A null Polygon removes the 2d Polygon.
    void XBRep_Builder::UpdateEdge(XTopoDS_Edge^ E, Handle(Poly_Polygon2D)& P1, Handle(Poly_Polygon2D)& P2, XTopoDS_Face^ S) {
        NativeHandle->UpdateEdge(*E->GetEdge(), P1, P2, *S->GetFace());
    };

    //! Changes Edge polygons on a face.
    //!
    //! A null Polygon removes the 2d Polygon.
    void XBRep_Builder::UpdateEdge(XTopoDS_Edge^ E, Handle(Poly_Polygon2D)& P1, Handle(Poly_Polygon2D)& P2, XGeom_Surface^ S, XTopLoc_Location^ L) {
        NativeHandle->UpdateEdge(*E->GetEdge(), P1, P2, S->GetSurface(), *L->GetLocation());
    };

    //! Updates the edge tolerance.
    void XBRep_Builder::UpdateEdge(XTopoDS_Edge^ E, Standard_Real Tol) {
        NativeHandle->UpdateEdge(*E->GetEdge(), Tol);
    };

    //! Sets the geometric continuity on the edge.
    void XBRep_Builder::Continuity(XTopoDS_Edge^ E, XTopoDS_Face^ F1, XTopoDS_Face^ F2, XGeomAbs_Shape C) {
        NativeHandle->Continuity(*E->GetEdge(), *F1->GetFace(), *F2->GetFace(), safe_cast<GeomAbs_Shape>(C));
    };

    //! Sets the geometric continuity on the edge.
    void XBRep_Builder::Continuity(XTopoDS_Edge^ E, XGeom_Surface^ S1, XGeom_Surface^ S2, XTopLoc_Location^ L1, XTopLoc_Location^ L2, XGeomAbs_Shape C) {
        NativeHandle->Continuity(*E->GetEdge(), S1->GetSurface(), S2->GetSurface(), *L1->GetLocation(), *L2->GetLocation(), safe_cast<GeomAbs_Shape>(C));
    };

    //! Sets the same parameter flag for the edge <E>.
    void XBRep_Builder::SameParameter(XTopoDS_Edge^ E, Standard_Boolean S) {
        NativeHandle->SameParameter(*E->GetEdge(), S);
    };

    //! Sets the same range flag for the edge <E>.
    void XBRep_Builder::SameRange(XTopoDS_Edge^ E, Standard_Boolean S) {
        NativeHandle->SameRange(*E->GetEdge(), S);
    };

    //! Sets the degenerated flag for the edge <E>.
    void XBRep_Builder::Degenerated(XTopoDS_Edge^ E, Standard_Boolean D) {
        NativeHandle->Degenerated(*E->GetEdge(), D);
    };

    //! Sets the range of the 3d curve if Only3d=TRUE,
    //! otherwise sets the range to all the representations
    //!  Standard_Boolean Only3d = Standard_False
    void XBRep_Builder::Range(XTopoDS_Edge^ E, Standard_Real First, Standard_Real Last, Standard_Boolean Only3d) {
        NativeHandle->Range(*E->GetEdge(), First, Last, Only3d);
    };

    //! Sets the range  of the edge  on the pcurve on  the
    //! surface.
    void XBRep_Builder::Range(XTopoDS_Edge^ E, XGeom_Surface^ S, XTopLoc_Location^ L, Standard_Real First, Standard_Real Last) {
        NativeHandle->Range(*E->GetEdge(), S->GetSurface(), *L->GetLocation(), First, Last);
    };

    //! Sets the range of the edge on the pcurve on the face.
    void XBRep_Builder::Range(XTopoDS_Edge^ E, XTopoDS_Face^ F, Standard_Real First, Standard_Real Last) {
        NativeHandle->Range(*E->GetEdge(), *F->GetFace(), First, Last);
    };

    //! Add  to <Eout>  the  geometric representations  of
    //! <Ein>.
    void XBRep_Builder::Transfert(XTopoDS_Edge^ Ein, XTopoDS_Edge^ Eout) {
        NativeHandle->Transfert(*Ein->GetEdge(), *Eout->GetEdge());
    };

    //! Makes an udefined vertex without geometry.
    void XBRep_Builder::MakeVertex(XTopoDS_Vertex^ V) {
        NativeHandle->MakeVertex(*V->GetVertex());
    };

    //! Makes a vertex from a 3D point.
    void XBRep_Builder::MakeVertex(XTopoDS_Vertex^ V, xgp_Pnt^ P, Standard_Real Tol) {
        NativeHandle->MakeVertex(*V->GetVertex(), *P->GetPnt(), Tol);
    };

    //! Sets a 3D point on the vertex.
    void XBRep_Builder::UpdateVertex(XTopoDS_Vertex^ V, xgp_Pnt^ P, Standard_Real Tol) {
        NativeHandle->UpdateVertex(*V->GetVertex(), *P->GetPnt(), Tol);
    };

    //! Sets  the parameter  for the   vertex on the  edge
    //! curves.
    void XBRep_Builder::UpdateVertex(XTopoDS_Vertex^ V, Standard_Real P, XTopoDS_Edge^ E, Standard_Real Tol) {
        NativeHandle->UpdateVertex(*V->GetVertex(), P, *E->GetEdge(), Tol);
    };

    //! Sets  the parameter  for the  vertex  on the  edge
    //! pcurve  on the face.
    void XBRep_Builder::UpdateVertex(XTopoDS_Vertex^ V, Standard_Real P, XTopoDS_Edge^ E, XTopoDS_Face^ F, Standard_Real Tol) {
        NativeHandle->UpdateVertex(*V->GetVertex(), P, *E->GetEdge(), *F->GetFace(), Tol);
    };

    //! Sets  the parameter  for the  vertex  on the  edge
    //! pcurve  on the surface.
    void XBRep_Builder::UpdateVertex(XTopoDS_Vertex^ V, Standard_Real P, XTopoDS_Edge^ E, XGeom_Surface^ S, XTopLoc_Location^ L, Standard_Real Tol) {
        NativeHandle->UpdateVertex(*V->GetVertex(), P, *E->GetEdge(), S->GetSurface(), *L->GetLocation(), Tol);
    };

    //! Sets the parameters for the vertex on the face.
    void XBRep_Builder::UpdateVertex(XTopoDS_Vertex^ Ve, Standard_Real U, Standard_Real V, XTopoDS_Face^ F, Standard_Real Tol) {
        NativeHandle->UpdateVertex(*Ve->GetVertex(), U, V, *F->GetFace(), Tol);
    };

    //! Updates the vertex tolerance.
    void XBRep_Builder::UpdateVertex(XTopoDS_Vertex^ V, Standard_Real Tol) {
        NativeHandle->UpdateVertex(*V->GetVertex(), Tol);
    };

    //! Transfert the parameters  of   Vin on  Ein as  the
    //! parameter of Vout on Eout.
    void XBRep_Builder::Transfert(XTopoDS_Edge^ Ein, XTopoDS_Edge^ Eout, XTopoDS_Vertex^ Vin, XTopoDS_Vertex^ Vout) {
        NativeHandle->Transfert(*Ein->GetEdge(), *Eout->GetEdge(), *Vin->GetVertex(), *Vout->GetVertex());
    };
}