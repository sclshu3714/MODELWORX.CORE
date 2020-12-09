#include <XBRepTools.h>
namespace TKBRep {
    //! Returns in UMin,  UMax, VMin,  VMax  the  bounding
    //! values in the parametric space of F.
    //! static 
    void XBRepTools::UVBounds(XTopoDS_Face^ F, Standard_Real UMin, Standard_Real UMax, Standard_Real VMin, Standard_Real VMax) {
        BRepTools::UVBounds(*F->GetFace(), UMin, UMax, VMin, VMax);
    };

    //! Returns in UMin,  UMax, VMin,  VMax  the  bounding
    //! values of the wire in the parametric space of F.
    //! static 
    void XBRepTools::UVBounds(XTopoDS_Face^ F, XTopoDS_Wire^ W, Standard_Real UMin, Standard_Real UMax, Standard_Real VMin, Standard_Real VMax) {
        BRepTools::UVBounds(*F->GetFace(), *W->GetWire(), UMin, UMax, VMin, VMax);
    };

    //! Returns in UMin,  UMax, VMin,  VMax  the  bounding
    //! values of the edge in the parametric space of F.
    //! static 
    void XBRepTools::UVBounds(XTopoDS_Face^ F, XTopoDS_Edge^ E, Standard_Real UMin, Standard_Real UMax, Standard_Real VMin, Standard_Real VMax) {
        BRepTools::UVBounds(*F->GetFace(), *E->GetEdge(), UMin, UMax, VMin, VMax);
    };

    //! Adds  to  the box <B>  the bounding values in  the
    //! parametric space of F.
    //! static 
    void XBRepTools::AddUVBounds(XTopoDS_Face^ F, Bnd_Box2d& B) {
        BRepTools::AddUVBounds(*F->GetFace(), B);
    };

    //! Adds  to the box  <B>  the bounding  values of the
    //! wire in the parametric space of F.
    //! static 
    void XBRepTools::AddUVBounds(XTopoDS_Face^ F, XTopoDS_Wire^ W, Bnd_Box2d& B) {
        BRepTools::AddUVBounds(*F->GetFace(), *W->GetWire(), B);
    };

    //! Adds to  the box <B>  the  bounding values  of the
    //! edge in the parametric space of F.
    //! static 
    void XBRepTools::AddUVBounds(XTopoDS_Face^ F, XTopoDS_Edge^ E, Bnd_Box2d& B) {
        BRepTools::AddUVBounds(*F->GetFace(), *E->GetEdge(), B);
    };

    //! Update a vertex (nothing is done)
    //! static 
    void XBRepTools::Update(XTopoDS_Vertex^ V) {
        BRepTools::Update(*V->GetVertex());
    };

    //! Update an edge, compute 2d bounding boxes.
    //! static 
    void XBRepTools::Update(XTopoDS_Edge^ E) {
        BRepTools::Update(*E->GetEdge());
    };

    //! Update a wire (nothing is done)
    //! static 
    void XBRepTools::Update(XTopoDS_Wire^ W) {
        BRepTools::Update(*W->GetWire());
    };

    //! Update a Face, update UV points.
    //! static 
    void XBRepTools::Update(XTopoDS_Face^ F) {
        BRepTools::Update(*F->GetFace());
    };

    //! Update a shell (nothing is done)
    //! static 
    void XBRepTools::Update(XTopoDS_Shell^ S) {
        BRepTools::Update(*S->GetShell());
    };

    //! Update a solid (nothing is done)
    //! static 
    void XBRepTools::Update(XTopoDS_Solid^ S) {
        BRepTools::Update(*S->GetSolid());
    };

    //! Update a composite solid (nothing is done)
    //! static 
    void XBRepTools::Update(XTopoDS_CompSolid^ C) {
        BRepTools::Update(*C->GetCompSolid());
    };

    //! Update a compound (nothing is done)
    //! static 
    void XBRepTools::Update(XTopoDS_Compound^ C) {
        BRepTools::Update(*C->GetCompound());
    };

    //! Update a shape, call the corect update.
    //! static 
    void XBRepTools::Update(XTopoDS_Shape^ S) {
        BRepTools::Update(*S->GetShape());
    };

    //! For each edge of the face <F> reset the UV points
    //! to the bounding points of the parametric curve of the
    //! edge on the face.
    //! static 
    void XBRepTools::UpdateFaceUVPoints(XTopoDS_Face^ theF) {
        BRepTools::UpdateFaceUVPoints(*theF->GetFace());
    };

    //! Removes all the triangulations of the faces of <S>
    //! and removes all polygons on triangulations of the
    //! edges.
    //! static 
    void XBRepTools::Clean(XTopoDS_Shape^ S) {
        BRepTools::Clean(*S->GetShape());
    };

    //! Removes geometry (curves and surfaces) from all edges and faces of the shape
    //! static 
    void XBRepTools::CleanGeometry(XTopoDS_Shape^ theShape) {
        BRepTools::CleanGeometry(*theShape->GetShape());
    };

    //! Removes all the pcurves of the edges of <S> that
    //! refer to surfaces not belonging to any face of <S>
    //! static 
    void XBRepTools::RemoveUnusedPCurves(XTopoDS_Shape^ S) {
        BRepTools::RemoveUnusedPCurves(*S->GetShape());
    };

    //! verifies that each face from the shape <S> has got
    //! a triangulation  with a  deflection <= deflec  and
    //! the edges a discretisation on  this triangulation.
    //! static 
    Standard_Boolean XBRepTools::Triangulation(XTopoDS_Shape^ S, Standard_Real deflec) {
        return BRepTools::Triangulation(*S->GetShape(), deflec);
    };

    //! Returns  True if  the    distance between the  two
    //! vertices is lower than their tolerance.
    //! static 
    Standard_Boolean XBRepTools::Compare(XTopoDS_Vertex^ V1, XTopoDS_Vertex^ V2) {
        return BRepTools::Compare(*V1->GetVertex(), *V2->GetVertex());
    };

    //! Returns  True if  the    distance between the  two
    //! edges is lower than their tolerance.
    //! static 
    Standard_Boolean XBRepTools::Compare(XTopoDS_Edge^ E1, XTopoDS_Edge^ E2) {
        return BRepTools::Compare(*E1->GetEdge(), *E2->GetEdge());
    };

    //! Returns the outer most wire of <F>. Returns a Null
    //! wire if <F> has no wires.
    //! static 
    XTopoDS_Wire^ XBRepTools::OuterWire(XTopoDS_Face^ F) {
        TopoDS_Wire* temp = new TopoDS_Wire(BRepTools::OuterWire(*F->GetFace()));
        return gcnew XTopoDS_Wire(temp);
    };

    //! Stores in the map  <M> all the 3D topology edges
    //! of <S>.
    //! static 
    void XBRepTools::Map3DEdges(XTopoDS_Shape^ S, TopTools_IndexedMapOfShape& M) {
        BRepTools::Map3DEdges(*S->GetShape(), M);
    };

    //! Verifies that the edge  <E> is found two  times on
    //! the face <F> before calling BRep_Tool::IsClosed.
    //! static 
    Standard_Boolean XBRepTools::IsReallyClosed(XTopoDS_Edge^ E, XTopoDS_Face^ F) {
        return BRepTools::IsReallyClosed(*E->GetEdge(), *F->GetFace());
    };

    //! Detect closedness of face in U and V directions
    //! static 
    void XBRepTools::DetectClosedness(XTopoDS_Face^ theFace, Standard_Boolean theUclosed, Standard_Boolean theVclosed) {
        BRepTools::DetectClosedness(*theFace->GetFace(), theUclosed, theVclosed);
    };

    //! Dumps the topological structure and the geometry
    //! of <Sh> on the stream <S>.
    //! static 
    void XBRepTools::Dump(XTopoDS_Shape^ Sh, Standard_OStream S) {
        BRepTools::Dump(*Sh->GetShape(), S);
    };

    //! Writes <Sh> on <S> in an ASCII format.
    //! PR = NULL
    //! static 
    void XBRepTools::Write(XTopoDS_Shape^ Sh, Standard_OStream S, Handle(Message_ProgressIndicator)& PR) {
        BRepTools::Write(*Sh->GetShape(), S, PR);
    };

    //! Reads a Shape  from <S> in  returns it in  <Sh>.
    //! <B> is used to build the shape.
    //! PR = NULL
    //! static 
    void XBRepTools::Read(XTopoDS_Shape^ Sh, Standard_IStream S, XBRep_Builder^ B, Handle(Message_ProgressIndicator)& PR) {
        BRepTools::Read(*Sh->GetShape(), S, *B->GetBRepBuilder(), PR);
    };

    //! Writes <Sh> in <File>.
    //! PR = NULL
    //! static 
    Standard_Boolean XBRepTools::Write(XTopoDS_Shape^ Sh, Standard_CString File, Handle(Message_ProgressIndicator)& PR) {
        return BRepTools::Write(*Sh->GetShape(), File, PR);
    };

    //! Reads a Shape  from <File>,  returns it in  <Sh>.
    //! <B> is used to build the shape.
    //! PR = NULL
    //! static 
    Standard_Boolean XBRepTools::Read(XTopoDS_Shape^ Sh, Standard_CString File, XBRep_Builder^ B, Handle(Message_ProgressIndicator)& PR) {
        return BRepTools::Read(*Sh->GetShape(), File,*B->GetBRepBuilder(), PR);
    };

    //! Evals real tolerance of edge  <theE>.
    //! <theC3d>, <theC2d>, <theS>, <theF>, <theL> are
    //! correspondently 3d curve of edge, 2d curve on surface <theS> and
    //! rang of edge
    //! If calculated tolerance is more then current edge tolerance, edge is updated.
    //! Method returns actual tolerance of edge
    //! static 
    Standard_Real XBRepTools::EvalAndUpdateTol(XTopoDS_Edge^ theE, XGeom_Curve^ theC3d, XGeom2d_Curve^ theC2d, XGeom_Surface^ theS, Standard_Real theF, Standard_Real theL) {
        return BRepTools::EvalAndUpdateTol(*theE->GetEdge(), theC3d->GetCurve(), theC2d->GetCurve(), theS->GetSurface(), theF, theL);
    };
}

