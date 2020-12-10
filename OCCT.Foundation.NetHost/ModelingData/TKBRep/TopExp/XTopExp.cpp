#include <XTopExp.h>
namespace TKBRep {

    //! Tool to explore a topological data structure.
    //! Stores in the map <M> all  the sub-shapes of <S>
    //! of type <T>.
    //!
    //! Warning: The map is not cleared at first.
    //! static 
    void XTopExp::MapShapes(XTopoDS_Shape^ S, XTopAbs_ShapeEnum T, TopTools_IndexedMapOfShape& M) {
        TopExp::MapShapes(*S->GetShape(),safe_cast<TopAbs_ShapeEnum>(T),  M);
    };

    //! Stores in the map <M> all  the sub-shapes of <S>.
    //! static 
    void XTopExp::MapShapes(XTopoDS_Shape^ S, TopTools_IndexedMapOfShape& M) {
        TopExp::MapShapes(*S->GetShape(), M);
    };

    //! Stores in the map <M> all  the sub-shapes of <S>.
    //! static 
    void XTopExp::MapShapes(XTopoDS_Shape^ S, TopTools_MapOfShape& M) {
        TopExp::MapShapes(*S->GetShape(), M);
    };

    //! Stores in the map <M> all the subshape of <S> of
    //! type <TS>  for each one append  to  the list all
    //! the ancestors of type <TA>.  For example map all
    //! the edges and bind the list of faces.
    //! Warning: The map is not cleared at first.
    //! static 
    void XTopExp::MapShapesAndAncestors(XTopoDS_Shape^ S, XTopAbs_ShapeEnum TS, XTopAbs_ShapeEnum TA, TopTools_IndexedDataMapOfShapeListOfShape& M) {
        TopExp::MapShapesAndAncestors(*S->GetShape(), safe_cast<TopAbs_ShapeEnum>(TS), safe_cast<TopAbs_ShapeEnum>(TA), M);
    };

    //! Stores in the map <M> all the subshape of <S> of
    //! type <TS> for each one append to the list all
    //! unique ancestors of type <TA>.  For example map all
    //! the edges and bind the list of faces.
    //! useOrientation = True : taking account the ancestor orientation
    //! Warning: The map is not cleared at first.
    //! Standard_Boolean useOrientation = Standard_False
    //! static 
    void XTopExp::MapShapesAndUniqueAncestors(XTopoDS_Shape^ S, XTopAbs_ShapeEnum TS, XTopAbs_ShapeEnum TA, TopTools_IndexedDataMapOfShapeListOfShape& M, Standard_Boolean useOrientation) {
        TopExp::MapShapesAndUniqueAncestors(*S->GetShape(), safe_cast<TopAbs_ShapeEnum>(TS), safe_cast<TopAbs_ShapeEnum>(TA), M, useOrientation);
    };

    //! Returns the Vertex of orientation FORWARD in E. If
    //! there is none returns a Null Shape.
    //! CumOri = True : taking account the edge 
    //! Standard_Boolean CumOri = Standard_False
    //! static 
    XTopoDS_Vertex^ XTopExp::FirstVertex(XTopoDS_Edge^ E, Standard_Boolean CumOri) {
        TopoDS_Vertex* temp = new TopoDS_Vertex(TopExp::FirstVertex(*E->GetEdge(), CumOri));
        return gcnew XTopoDS_Vertex(temp);
    };

    //! Returns the Vertex of orientation REVERSED in E. If
    //! there is none returns a Null Shape.
    //! CumOri = True : taking account the edge orientation
    //! Standard_Boolean CumOri = Standard_False
    //! static 
    XTopoDS_Vertex^ XTopExp::LastVertex(XTopoDS_Edge^ E, Standard_Boolean CumOri) {
        TopoDS_Vertex* temp = new TopoDS_Vertex(TopExp::LastVertex(*E->GetEdge(), CumOri));
        return gcnew XTopoDS_Vertex(temp);
    };

    //! Returns in Vfirst, Vlast the  FORWARD and REVERSED
    //! vertices of the edge <E>. May be null shapes.
    //! CumOri = True : taking account the edge orientation
    //! Standard_Boolean CumOri = Standard_False
    //! static 
    void XTopExp::Vertices(XTopoDS_Edge^ E, XTopoDS_Vertex^ Vfirst, XTopoDS_Vertex^ Vlast, Standard_Boolean CumOri) {
        TopExp::Vertices(*E->GetEdge(), *Vfirst->GetVertex(), *Vlast->GetVertex(), CumOri);
    };

    //! Returns  in  Vfirst,  Vlast   the first   and last
    //! vertices of the open wire <W>. May be null shapes.
    //! if   <W>  is closed Vfirst and Vlast  are a same
    //! vertex on <W>.
    //! if <W> is no manifold. VFirst and VLast are null
    //! shapes.
    //! static 
    void XTopExp::Vertices(XTopoDS_Wire^ W, XTopoDS_Vertex^ Vfirst, XTopoDS_Vertex^ Vlast) {
        TopExp::Vertices(*W->GetWire(), *Vfirst->GetVertex(), *Vlast->GetVertex());
    };

    //! Finds   the  vertex <V> common   to  the two edges
    //! <E1,E2>, returns True if this vertex exists.
    //!
    //! Warning: <V> has sense only if the value <True> is returned
    //! static 
    Standard_Boolean XTopExp::CommonVertex(XTopoDS_Edge^ E1, XTopoDS_Edge^ E2, XTopoDS_Vertex^ V) {
        return TopExp::CommonVertex(*E1->GetEdge(), *E2->GetEdge(), *V->GetVertex());
    };
}