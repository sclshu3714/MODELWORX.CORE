// Created on: 1995-08-31
// Created by: Remi LEQUETTE
// Copyright (c) 1995-1999 Matra Datavision
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

#ifndef _XBRepFilletAPI_MakeFillet2d_HeaderFile
#define _XBRepFilletAPI_MakeFillet2d_HeaderFile
#pragma once
#include <BRepFilletAPI_MakeFillet2d.hxx>
#include <XBRepBuilderAPI_MakeShape.h>
#include <XTopoDS_Shape.h>
#include <XTopoDS_Edge.h>
#include <XTopoDS_Vertex.h>
#include <XTopoDS_Face.h>
#include <XChFi2d_ConstructionError.h>

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <ChFi2d_Builder.hxx>
#include <BRepBuilderAPI_MakeShape.hxx>
#include <Standard_Real.hxx>
#include <Standard_Boolean.hxx>
#include <TopTools_SequenceOfShape.hxx>
#include <Standard_Integer.hxx>
#include <TopTools_ListOfShape.hxx>
#include <ChFi2d_ConstructionError.hxx>
class TopoDS_Face;
class TopoDS_Edge;
class TopoDS_Vertex;
class TopoDS_Shape;
class BRepFilletAPI_MakeFillet2d;

using namespace TKBRep;
using namespace TKTopAlgo;
namespace TKFillet {
    ref class TKBRep::XTopoDS_Shape;
    ref class TKBRep::XTopoDS_Edge;
    ref class TKBRep::XTopoDS_Vertex;
    ref class TKBRep::XTopoDS_Face;
    //! Describes functions to build fillets and chamfers on the
    //! vertices of a planar face.
    //! Fillets and Chamfers on the Vertices of a Planar Face
    //! A MakeFillet2d object provides a framework for:
    //! - initializing the construction algorithm with a given face,
    //! - acquiring the data characterizing the fillets and chamfers,
    //! -   building the fillets and chamfers, and constructing the
    //! resulting shape, and
    //! -   consulting the result.
    //! Warning
    //! Only segments of straight lines and arcs of circles are
    //! treated. BSplines are not processed.
    public ref class XBRepFilletAPI_MakeFillet2d : public XBRepBuilderAPI_MakeShape
    {
    public:

        //! DEFINE_STANDARD_ALLOC
        !XBRepFilletAPI_MakeFillet2d() { IHandle = NULL; };
        ~XBRepFilletAPI_MakeFillet2d() { IHandle = NULL; };

        //! Initializes an empty algorithm for computing fillets and
        //! chamfers. The face on which the fillets and
        //! chamfers are built is defined using the Init function.
        //! The vertices on which fillets or chamfers are built are
        //! defined using the AddFillet or AddChamfer function.
        //! Warning
        //! The status of the initialization, as given by the Status
        //! function, can be one of the following:
        //! -   ChFi2d_Ready if the initialization is correct,
        //! -   ChFi2d_NotPlanar if F is not planar,
        //! -   ChFi2d_NoFace if F is a null face.
        XBRepFilletAPI_MakeFillet2d();


        XBRepFilletAPI_MakeFillet2d(BRepFilletAPI_MakeFillet2d* handle);

        void SetMakeFillet2dHandle(BRepFilletAPI_MakeFillet2d* handle);

        virtual BRepFilletAPI_MakeFillet2d* GetMakeFillet2d();

        virtual BRepBuilderAPI_MakeShape* GetMakeShape() Standard_OVERRIDE;

        //! Returns a shape built by the shape construction algorithm.
        //! Raises exception StdFail_NotDone if the shape was not built.
        virtual XTopoDS_Shape^ Shape() Standard_OVERRIDE;


        //! Initializes this algorithm for constructing fillets or
        //! chamfers with the face F.
        //! Warning
        //! The status of the initialization, as given by the Status
        //! function, can be one of the following:
        //! -   ChFi2d_Ready if the initialization is correct,
        //! -   ChFi2d_NotPlanar if F is not planar,
        //! -   ChFi2d_NoFace if F is a null face.
        void Init(XTopoDS_Face^ F);

        //! This initialize  method allow  to init the builder
        //! from a  face <RefFace> and  another face <ModFace>
        //! which derive from  <RefFace>.  This  is usefull to
        //! modify a fillet or   a chamfer already created  on
        //! <ModFace> .
        void Init(XTopoDS_Face^ RefFace, XTopoDS_Face^ ModFace);

        //! Adds a fillet of radius Radius between the two edges
        //! adjacent to the vertex V on the face modified by this
        //! algorithm. The two edges do not need to be rectilinear.
        //! This function returns the fillet and builds the resulting face.
        //! Warning
        //! The status of the construction, as given by the Status
        //! function, can be one of the following:
        //! - ChFi2d_IsDone if the fillet is built,
        //! - ChFi2d_ConnexionError if V does not belong to the initial face,
        //! -   ChFi2d_ComputationError if Radius is too large
        //! to build a fillet between the two adjacent edges,
        //! -   ChFi2d_NotAuthorized
        //! -   if one of the two edges connected to V is a fillet or chamfer, or
        //! -   if a curve other than a straight line or an arc of a
        //! circle is used as E, E1 or E2.
        //! Do not use the returned fillet if the status of the construction is not ChFi2d_IsDone.
        //! Exceptions
        //! Standard_NegativeValue if Radius is less than or equal to zero.
        XTopoDS_Edge^ AddFillet(XTopoDS_Vertex^ V, Standard_Real Radius);

        //! Assigns the radius Radius to the fillet Fillet already
        //! built on the face modified by this algorithm.
        //! This function returns the new fillet and modifies the existing face.
        //! Warning
        //! The status of the construction, as given by the Status
        //! function, can be one of the following:
        //! -   ChFi2d_IsDone if the new fillet is built,
        //! -   ChFi2d_ConnexionError if Fillet does not
        //! belong to the existing face,
        //! -   ChFi2d_ComputationError if Radius is too
        //! large to build a fillet between the two adjacent edges.
        //! Do not use the returned fillet if the status of the
        //! construction is not ChFi2d_IsDone.
        //! Exceptions
        //! Standard_NegativeValue if Radius is less than or equal to zero.
        XTopoDS_Edge^ ModifyFillet(XTopoDS_Edge^ Fillet, Standard_Real Radius);

        //! Removes the fillet Fillet already built on the face
        //! modified by this algorithm.
        //! This function returns the vertex connecting the two
        //! adjacent edges of Fillet and modifies the existing face.
        //! Warning
        //! -   The returned vertex is only valid if the Status
        //! function returns ChFi2d_IsDone.
        //! -   A null vertex is returned if the edge Fillet does not
        //! belong to the initial face.
        XTopoDS_Vertex^ RemoveFillet(XTopoDS_Edge^ Fillet);

        //! Adds a chamfer on the face modified by this algorithm
        //! between the two adjacent edges E1 and E2, where
        //! the extremities of the chamfer are on E1 and E2 at
        //! distances D1 and D2 respectively
        //! In cases where the edges are not rectilinear, distances
        //! are measured using the curvilinear abscissa of the
        //! edges and the angle is measured with respect to the
        //! tangent at the corresponding point.
        //! The angle Ang is given in radians.
        //! This function returns the chamfer and builds the resulting face.
        XTopoDS_Edge^ AddChamfer(XTopoDS_Edge^ E1, XTopoDS_Edge^ E2, Standard_Real D1, Standard_Real D2);

        //! Adds a chamfer on the face modified by this algorithm
        //! between the two edges connected by the vertex V,
        //! where E is one of the two edges. The chamfer makes
        //! an angle Ang with E and one of its extremities is on
        //! E at distance D from V.
        //! In cases where the edges are not rectilinear, distances
        //! are measured using the curvilinear abscissa of the
        //! edges and the angle is measured with respect to the
        //! tangent at the corresponding point.
        //! The angle Ang is given in radians.
        //! This function returns the chamfer and builds the resulting face.
        //! Warning
        //! The status of the construction, as given by the Status function, can
        //! be one of the following:
        //! -          ChFi2d_IsDone if the chamfer is built,
        //! -  ChFi2d_ParametersError if D1, D2, D or Ang is less than or equal to zero,
        //! -          ChFi2d_ConnexionError if:
        //! - the edge E, E1 or E2 does not belong to the initial face, or
        //! -  the edges E1 and E2 are not adjacent, or
        //! -  the vertex V is not one of the limit points of the edge E,
        //! -          ChFi2d_ComputationError if the parameters of the chamfer
        //! are too large to build a chamfer between the two adjacent edges,
        //! -          ChFi2d_NotAuthorized if:
        //! - the edge E1, E2 or one of the two edges connected to V is a fillet or chamfer, or
        //! - a curve other than a straight line or an arc of a circle is used as E, E1 or E2.
        //! Do not use the returned chamfer if
        //! the status of the construction is not ChFi2d_IsDone.
        XTopoDS_Edge^ AddChamfer(XTopoDS_Edge^ E, XTopoDS_Vertex^ V, Standard_Real D, Standard_Real Ang);

        //! Modifies the chamfer Chamfer on the face modified
        //! by this algorithm, where:
        //! E1 and E2 are the two adjacent edges on which
        //! Chamfer is already built; the extremities of the new
        //! chamfer are on E1 and E2 at distances D1 and D2 respectively.
        XTopoDS_Edge^ ModifyChamfer(XTopoDS_Edge^ Chamfer, XTopoDS_Edge^ E1, XTopoDS_Edge^ E2, Standard_Real D1, Standard_Real D2);

        //! Modifies the chamfer Chamfer on the face modified
        //! by this algorithm, where:
        //! E is one of the two adjacent edges on which
        //! Chamfer is already built; the new chamfer makes
        //! an angle Ang with E and one of its extremities is
        //! on E at distance D from the vertex on which the chamfer is built.
        //! In cases where the edges are not rectilinear, the
        //! distances are measured using the curvilinear abscissa
        //! of the edges and the angle is measured with respect
        //! to the tangent at the corresponding point.
        //! The angle Ang is given in radians.
        //! This function returns the new chamfer and modifies the existing face.
        //! Warning
        //! The status of the construction, as given by the Status
        //! function, can be one of the following:
        //! -   ChFi2d_IsDone if the chamfer is built,
        //! -   ChFi2d_ParametersError if D1, D2, D or Ang is less than or equal to zero,
        //! -   ChFi2d_ConnexionError if:
        //! -   the edge E, E1, E2 or Chamfer does not belong
        //! to the existing face, or
        //! -   the edges E1 and E2 are not adjacent,
        //! -   ChFi2d_ComputationError if the parameters of
        //! the chamfer are too large to build a chamfer
        //! between the two adjacent edges,
        //! -   ChFi2d_NotAuthorized if E1 or E2 is a fillet or chamfer.
        //! Do not use the returned chamfer if the status of the
        //! construction is not ChFi2d_IsDone.
        XTopoDS_Edge^ ModifyChamfer(XTopoDS_Edge^ Chamfer, XTopoDS_Edge^ E, Standard_Real D, Standard_Real Ang);

        //! Removes the chamfer Chamfer already built on the face
        //! modified by this algorithm.
        //! This function returns the vertex connecting the two
        //! adjacent edges of Chamfer and modifies the existing face.
        //! Warning
        //! -   The returned vertex is only valid if the Status
        //! function returns ChFi2d_IsDone.
        //! -   A null vertex is returned if the edge Chamfer does
        //! not belong to the initial face.
        XTopoDS_Vertex^ RemoveChamfer(XTopoDS_Edge^ Chamfer);

        //! Returns true if the edge E on the face modified by this
        //! algorithm is chamfered or filleted.
        //! Warning
        //! Returns false if E does not belong to the face modified by this algorithm.
        Standard_Boolean IsModified(XTopoDS_Edge^ E);

        //! Returns the table of fillets on the face modified by this algorithm.
        TopTools_SequenceOfShape FilletEdges();

        //! Returns the number of fillets on the face modified by this algorithm.
        Standard_Integer NbFillet();

        //! Returns the table of chamfers on the face modified by this algorithm.
        TopTools_SequenceOfShape ChamferEdges();

        //! Returns the number of chamfers on the face modified by this algorithm.
        Standard_Integer NbChamfer();

        //! Returns the list  of shapes modified from the shape
        //! <S>.
        virtual XTopTools_ListOfShape^ Modified(XTopoDS_Shape^ S) Standard_OVERRIDE;

        //! returns the number of new curves
        //! after the shape creation.
        Standard_Integer NbCurves();

        //! Return the Edges created for curve I.
        XTopTools_ListOfShape^ NewEdges(Standard_Integer I);

        Standard_Boolean HasDescendant(XTopoDS_Edge^ E);

        //! Returns the chamfered or filleted edge built from the
        //! edge E on the face modified by this algorithm. If E has
        //! not been modified, this function returns E.
        //! Exceptions
        //! Standard_NoSuchObject if the edge E does not
        //! belong to the initial face.
        XTopoDS_Edge^ DescendantEdge(XTopoDS_Edge^ E);

        //! Returns the basis edge on the face modified by this
        //! algorithm from which the chamfered or filleted edge E is
        //! built. If E has not been modified, this function returns E.
        //! Warning
        //! E is returned if it does not belong to the initial face.
        XTopoDS_Edge^ BasisEdge(XTopoDS_Edge^ E);

        XChFi2d_ConstructionError Status();

        //! Update the result and set the Done flag
        virtual void Build() Standard_OVERRIDE;

        /// <summary>
        /// ±¾µØ¾ä±ú
        /// </summary>
        virtual property BRepBuilderAPI_MakeShape* IHandle {
            BRepBuilderAPI_MakeShape* get() Standard_OVERRIDE {
                return NativeHandle;
            }
            void set(BRepBuilderAPI_MakeShape* handle) Standard_OVERRIDE {
                NativeHandle = static_cast<BRepFilletAPI_MakeFillet2d*>(handle);
            }
        }

    private:
        BRepFilletAPI_MakeFillet2d* NativeHandle;
    };
}
#endif // _XBRepFilletAPI_MakeFillet2d_HeaderFile
