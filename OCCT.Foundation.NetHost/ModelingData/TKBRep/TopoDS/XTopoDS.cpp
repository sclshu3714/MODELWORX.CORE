#include <XTopoDS.h>
//! Provides methods to cast objects of class
//! TopoDS_Shape to be onjects of more specialized
//! sub-classes. Types are verified, thus in the example
//! below, the first two blocks are correct but the third is
//! rejected by the compiler.
namespace TKBRep {

    //! Basic tool to access the data structure.
    //! Casts shape S to the more specialized return type, Vertex.
    //! Exceptions
    //! Standard_TypeMismatch if S cannot be cast to this return type.
    //£¡static
    XTopoDS_Vertex^ XTopoDS::Vertex(XTopoDS_Shape^ S) {
        TopoDS_Vertex* temp = new TopoDS_Vertex(TopoDS::Vertex(*S->GetShape()));
        return gcnew XTopoDS_Vertex(temp);
    };

    //! Casts shape S to the more specialized return type, Edge
    //! Exceptions
    //! Standard_TypeMismatch if S cannot be cast to this return type.
    //£¡static
    XTopoDS_Edge^ XTopoDS::Edge(XTopoDS_Shape^ S) {
        TopoDS_Edge* temp = new TopoDS_Edge(TopoDS::Edge(*S->GetShape()));
        return gcnew XTopoDS_Edge(temp);
    };

    //! Casts shape S to the more specialized return type, Wire.
    //! Exceptions
    //! Standard_TypeMismatch if S cannot be cast to this return type.
    //£¡static
    XTopoDS_Wire^ XTopoDS::Wire(XTopoDS_Shape^ S) {
        TopoDS_Wire* temp = new TopoDS_Wire(TopoDS::Wire(*S->GetShape()));
        return gcnew XTopoDS_Wire(temp);
    };

    //! Casts shape S to the more specialized return type, Face.
    //! Exceptions
    //! Standard_TypeMismatch if S cannot be cast to this return type.
    //£¡static
    XTopoDS_Face^ XTopoDS::Face(XTopoDS_Shape^ S) {
        TopoDS_Face* temp = new TopoDS_Face(TopoDS::Face(*S->GetShape()));
        return gcnew XTopoDS_Face(temp);
    };

    //! Casts shape S to the more specialized return type, Shell.
    //! Exceptions
    //! Standard_TypeMismatch if S cannot be cast to this return type.
    //£¡static
    XTopoDS_Shell^ XTopoDS::Shell(XTopoDS_Shape^ S) {
        TopoDS_Shell* temp = new TopoDS_Shell(TopoDS::Shell(*S->GetShape()));
        return gcnew XTopoDS_Shell(temp);
    };

    //! Casts shape S to the more specialized return type, Solid.
    //! Exceptions
    //! Standard_TypeMismatch if S cannot be cast to this return type.
    //£¡static
    XTopoDS_Solid^ XTopoDS::Solid(XTopoDS_Shape^ S) {
        TopoDS_Solid* temp = new TopoDS_Solid(TopoDS::Solid(*S->GetShape()));
        return gcnew XTopoDS_Solid(temp);
    };

    //! Casts shape S to the more specialized return type, CompSolid.
    //! Exceptions
    //! Standard_TypeMismatch if S cannot be cast to this return type.
    //£¡static
    XTopoDS_CompSolid^ XTopoDS::CompSolid(XTopoDS_Shape^ S) {
        TopoDS_CompSolid* temp = new TopoDS_CompSolid(TopoDS::CompSolid(*S->GetShape()));
        return gcnew XTopoDS_CompSolid(temp);
    };

    //! Casts shape S to the more specialized return type, Compound.
    //! Exceptions
    //! Standard_TypeMismatch if S cannot be cast to this return type.
    //£¡static
    XTopoDS_Compound^ XTopoDS::Compound(XTopoDS_Shape^ S) {
        TopoDS_Compound* temp = new TopoDS_Compound(TopoDS::Compound(*S->GetShape()));
        return gcnew XTopoDS_Compound(temp);
    };
}
