// Created on: 2000-06-16
// Copyright (c) 2000-2014 OPEN CASCADE SAS
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

#ifndef _XGraphic3d_ArrayOfPrimitives_HeaderFile
#define _XGraphic3d_ArrayOfPrimitives_HeaderFile
#pragma once
#include <Graphic3d_ArrayOfPrimitives.hxx>
#include <xgp_Dir.h>
#include <xgp_Pnt.h>
#include <XQuantity_Color.h>
#include <XGraphic3d_TypeOfPrimitiveArray.h>
#include <XGraphic3d_Buffer.h>

#include <Graphic3d_BoundBuffer.hxx>
#include <Graphic3d_ArrayFlags.hxx>
#include <Graphic3d_Buffer.hxx>
#include <Graphic3d_IndexBuffer.hxx>
#include <Graphic3d_TypeOfPrimitiveArray.hxx>
#include <gp_Dir.hxx>
#include <gp_Pnt.hxx>
#include <Standard_OutOfRange.hxx>
#include <Standard_TypeMismatch.hxx>
#include <Quantity_Color.hxx>
#include <XGraphic3d_BoundBuffer.h>
#include <XGraphic3d_Vec3.h>

class Graphic3d_ArrayOfPrimitives;
//DEFINE_STANDARD_HANDLE(Graphic3d_ArrayOfPrimitives, Standard_Transient)

using namespace TKMath;
using namespace TKernel;
namespace TKV3d {
    ref class TKMath::xgp_Dir;
    ref class TKMath::xgp_Pnt;
    ref class TKernel::XQuantity_Color;
    //! This class furnish services to defined and fill an array of primitives
    //! which can be passed directly to graphics rendering API.
    //!
    //! The basic interface consists of the following parts:
    //! 1) Specifying primitive type.
    //!    WARNING! Particular primitive types might be unsupported by specific hardware/graphics API (like quads and polygons).
    //!             It is always preferred using one of basic types having maximum compatibility:
    //!             Point, Triangle (or Triangle strip), Segment aka Lines (or Polyline aka Line Strip).
    //!    Primitive strip types can be used to reduce memory usage as alternative to Indexed arrays.
    //! 2) Vertex array.
    //!    - Specifying the (maximum) number of vertexes within array.
    //!    - Specifying the vertex attributes, complementary to mandatory vertex Position (normal, color, UV texture coordinates).
    //!    - Defining vertex values by using various versions of AddVertex() or SetVertex*() methods.
    //! 3) Index array (optional).
    //!    - Specifying the (maximum) number of indexes (edges).
    //!    - Defining index values by using AddEdge() method; the index value should be within number of defined Vertexes.
    //!
    //!    Indexed array allows sharing vertex data across Primitives and thus reducing memory usage,
    //!    since index size is much smaller then size of vertex with all its attributes.
    //!    It is a preferred way for defining primitive array and main alternative to Primitive Strips for optimal memory usage,
    //!    although it is also possible (but unusual) defining Indexed Primitive Strip.
    //!    Note that it is NOT possible sharing Vertex Attributes partially (e.g. share Position, but have different Normals);
    //!    in such cases Vertex should be entirely duplicated with all Attributes.
    //! 4) Bounds array (optional).
    //!    - Specifying the (maximum) number of bounds.
    //!    - Defining bounds using AddBound() methods.
    //!
    //!    Bounds allow splitting Primitive Array into sub-groups.
    //!    This is useful only in two cases - for specifying per-group color and for restarting Primitive Strips.
    //!    WARNING! Bounds within Primitive Array break rendering batches into parts (additional for loops),
    //!             affecting rendering performance negatively (increasing CPU load).
    public ref class XGraphic3d_ArrayOfPrimitives //: public Standard_Transient
    {
        //DEFINE_STANDARD_RTTIEXT(Graphic3d_ArrayOfPrimitives, Standard_Transient)
    public:

        //! Create an array of specified type.
        static XGraphic3d_ArrayOfPrimitives^ CreateArray(XGraphic3d_TypeOfPrimitiveArray theType, Standard_Integer theMaxVertexs, Standard_Integer theMaxEdges, Graphic3d_ArrayFlags theArrayFlags);

        //! Create an array of specified type.
        static XGraphic3d_ArrayOfPrimitives^ CreateArray(XGraphic3d_TypeOfPrimitiveArray theType, Standard_Integer theMaxVertexs, Standard_Integer theMaxBounds, Standard_Integer theMaxEdges, Graphic3d_ArrayFlags theArrayFlags);
    public:

        //! Destructor.
        virtual ~XGraphic3d_ArrayOfPrimitives();

        //! Returns vertex attributes buffer (colors, normals, texture coordinates).
        XGraphic3d_Buffer^ Attributes();

        //! Returns the type of this primitive
        XGraphic3d_TypeOfPrimitiveArray Type();

        //! Returns the string type of this primitive
        Standard_CString StringType();

        //! Returns TRUE when vertex normals array is defined.
        Standard_Boolean HasVertexNormals();

        //! Returns TRUE when vertex colors array is defined.
        Standard_Boolean HasVertexColors();
        //! Returns TRUE when vertex texels array is defined.yColData != NULL; }

        Standard_Boolean HasVertexTexels();

        //! Returns the number of defined vertex
        Standard_Integer VertexNumber();

        //! Returns the number of allocated vertex
        Standard_Integer VertexNumberAllocated();

        //! Returns the number of total items according to the array type.
        Standard_Integer ItemNumber();

        //! Returns TRUE only when the contains of this array is available.
        Standard_Boolean IsValid();

        //! Adds a vertice in the array.
        //! @return the actual vertex number
        Standard_Integer AddVertex(xgp_Pnt^ theVertex);

        //! Adds a vertice in the array.
        //! @return the actual vertex number
        Standard_Integer AddVertex(XGraphic3d_Vec3^ theVertex);

        //! Adds a vertice in the array.
        //! @return the actual vertex number
        Standard_Integer AddVertex(Standard_Real theX, Standard_Real theY, Standard_Real theZ);

        //! Adds a vertice in the array.
        //! @return the actual vertex number.
        Standard_Integer AddVertex(Standard_ShortReal theX, Standard_ShortReal theY, Standard_ShortReal theZ);

        //! Adds a vertice and vertex color in the vertex array.
        //! Warning: theColor is ignored when the hasVColorsructor parameter is FALSE
        //! @return the actual vertex number
        Standard_Integer AddVertex(xgp_Pnt^ theVertex, XQuantity_Color^ theColor);

        //! Adds a vertice and vertex color in the vertex array.
        //! Warning: theColor is ignored when the hasVColorsructor parameter is FALSE
        //! @code
        //!   theColor32 = Alpha << 24 + Blue << 16 + Green << 8 + Red
        //! @endcode
        //! @return the actual vertex number
        Standard_Integer AddVertex(xgp_Pnt^ theVertex, Standard_Integer theColor32);

        //! Adds a vertice and vertex color in the vertex array.
        //! Warning: theColor is ignored when the hasVColorsructor parameter is FALSE
        //! @return the actual vertex number
        Standard_Integer AddVertex(xgp_Pnt^ theVertex, XGraphic3d_Vec4ub^ theColor);

        //! Adds a vertice and vertex normal in the vertex array.
        //! Warning: theNormal is ignored when the hasVNormalsructor parameter is FALSE.
        //! @return the actual vertex number
        Standard_Integer AddVertex(xgp_Pnt^ theVertex, xgp_Dir^ theNormal);

        //! Adds a vertice and vertex normal in the vertex array.
        //! Warning: Normal is ignored when the hasVNormalsructor parameter is FALSE.
        //! @return the actual vertex number
        Standard_Integer AddVertex(Standard_Real theX, Standard_Real theY, Standard_Real theZ, Standard_Real theNX, Standard_Real theNY, Standard_Real theNZ);

        //! Adds a vertice and vertex normal in the vertex array.
        //! Warning: Normal is ignored when the hasVNormalsructor parameter is FALSE.
        //! @return the actual vertex number
        Standard_Integer AddVertex(Standard_ShortReal theX, Standard_ShortReal theY, Standard_ShortReal theZ, Standard_ShortReal theNX, Standard_ShortReal theNY, Standard_ShortReal theNZ);

        //! Adds a vertice,vertex normal and color in the vertex array.
        //! Warning: theNormal is ignored when the hasVNormalsructor parameter is FALSE
        //! and      theColor  is ignored when the hasVColors ructor parameter is FALSE.
        //! @return the actual vertex number
        Standard_Integer AddVertex(xgp_Pnt^ theVertex, xgp_Dir^ theNormal, XQuantity_Color^ theColor);

        //! Adds a vertice,vertex normal and color in the vertex array.
        //! Warning: theNormal is ignored when the hasVNormalsructor parameter is FALSE
        //! and      theColor  is ignored when the hasVColors ructor parameter is FALSE.
        //! @code
        //!   theColor32 = Alpha << 24 + Blue << 16 + Green << 8 + Red
        //! @endcode
        //! @return the actual vertex number
        Standard_Integer AddVertex(xgp_Pnt^ theVertex, xgp_Dir^ theNormal, Standard_Integer theColor32);

        //! Adds a vertice and vertex texture in the vertex array.
        //! theTexel is ignored when the hasVTexelsructor parameter is FALSE.
        //! @return the actual vertex number
        Standard_Integer AddVertex(xgp_Pnt^ theVertex, xgp_Pnt2d^ theTexel);

        //! Adds a vertice and vertex texture coordinates in the vertex array.
        //! Texel is ignored when the hasVTexelsructor parameter is FALSE.
        //! @return the actual vertex number
        Standard_Integer AddVertex(Standard_Real theX, Standard_Real theY, Standard_Real theZ, Standard_Real theTX, Standard_Real theTY);

        //! Adds a vertice and vertex texture coordinates in the vertex array.
        //! Texel is ignored when the hasVTexelsructor parameter is FALSE.
        //! @return the actual vertex number
        Standard_Integer AddVertex(Standard_ShortReal theX, Standard_ShortReal theY, Standard_ShortReal theZ, Standard_ShortReal theTX, Standard_ShortReal theTY);

        //! Adds a vertice,vertex normal and texture in the vertex array.
        //! Warning: theNormal is ignored when the hasVNormalsructor parameter is FALSE
        //! and      theTexel  is ignored when the hasVTexels ructor parameter is FALSE.
        //! @return the actual vertex number
        Standard_Integer AddVertex(xgp_Pnt^ theVertex, xgp_Dir^ theNormal, xgp_Pnt2d^ theTexel);

        //! Adds a vertice,vertex normal and texture in the vertex array.
        //! Warning: Normal is ignored when the hasVNormalsructor parameter is FALSE
        //! and      Texel  is ignored when the hasVTexels ructor parameter is FALSE.
        //! @return the actual vertex number
        Standard_Integer AddVertex(Standard_Real theX, Standard_Real theY, Standard_Real theZ, Standard_Real theNX, Standard_Real theNY, Standard_Real theNZ, Standard_Real theTX, Standard_Real theTY);

        //! Adds a vertice,vertex normal and texture in the vertex array.
        //! Warning: Normal is ignored when the hasVNormalsructor parameter is FALSE
        //!     and  Texel  is ignored when the hasVTexels ructor parameter is FALSE.
        //! @return the actual vertex number
        Standard_Integer AddVertex(Standard_ShortReal theX, Standard_ShortReal theY, Standard_ShortReal theZ, Standard_ShortReal theNX, Standard_ShortReal theNY, Standard_ShortReal theNZ, Standard_ShortReal theTX, Standard_ShortReal theTY);

        //! Change the vertice of rank theIndex in the array.
        void SetVertice(Standard_Integer theIndex, xgp_Pnt^ theVertex);

        //! Change the vertice of rank theIndex in the array.
        void SetVertice(Standard_Integer theIndex, Standard_ShortReal theX, Standard_ShortReal theY, Standard_ShortReal theZ);

        //! Change the vertex color of rank theIndex in the array.
        void SetVertexColor(Standard_Integer theIndex, XQuantity_Color^ theColor);

        //! Change the vertex color of rank theIndex in the array.
        void SetVertexColor(Standard_Integer theIndex, Standard_Real theR, Standard_Real theG, Standard_Real theB);

        //! Change the vertex color of rank theIndex in the array.
        void SetVertexColor(Standard_Integer  theIndex, XGraphic3d_Vec4ub^ theColor);

        //! Change the vertex color of rank theIndex> in the array.
        //! @code
        //!   theColor32 = Alpha << 24 + Blue << 16 + Green << 8 + Red
        //! @endcode
        void SetVertexColor(Standard_Integer theIndex, Standard_Integer theColor32);

        //! Change the vertex normal of rank theIndex in the array.
        void SetVertexNormal(Standard_Integer theIndex, xgp_Dir^ theNormal);

        //! Change the vertex normal of rank theIndex in the array.
        void SetVertexNormal(Standard_Integer theIndex, Standard_Real theNX, Standard_Real theNY, Standard_Real theNZ);

        //! Change the vertex texel of rank theIndex in the array.
        void SetVertexTexel(Standard_Integer theIndex, xgp_Pnt2d^ theTexel);

        //! Change the vertex texel of rank theIndex in the array.
        void SetVertexTexel(Standard_Integer theIndex, Standard_Real theTX, Standard_Real theTY);

        //! Returns the vertice at rank theRank from the vertex table if defined.
        xgp_Pnt^ Vertice(Standard_Integer theRank);

        //! Returns the vertice coordinates at rank theRank from the vertex table if defined.
        void Vertice(Standard_Integer theRank, Standard_Real^ theX, Standard_Real^ theY, Standard_Real^ theZ);

        //! Returns the vertex color at rank theRank from the vertex table if defined.
        XQuantity_Color^ VertexColor(Standard_Integer theRank);

        //! Returns the vertex color at rank theIndex from the vertex table if defined.
        void VertexColor(Standard_Integer theIndex, Graphic3d_Vec4ub^ theColor);

        //! Returns the vertex color values at rank theRank from the vertex table if defined.
        void VertexColor(Standard_Integer theRank, Standard_Real% theR, Standard_Real% theG, Standard_Real% theB);

        //! Returns the vertex color values at rank theRank from the vertex table if defined.
        void VertexColor(Standard_Integer theRank, Standard_Integer% theColor);

        //! Returns the vertex normal at rank theRank from the vertex table if defined.
        xgp_Dir^ VertexNormal(Standard_Integer theRank);

        //! Returns the vertex normal coordinates at rank theRank from the vertex table if defined.
        void VertexNormal(Standard_Integer theRank, Standard_Real^ theNX, Standard_Real^ theNY, Standard_Real^ theNZ);

        //! Returns the vertex texture at rank theRank from the vertex table if defined.
        xgp_Pnt2d^ VertexTexel(Standard_Integer theRank);

        //! Returns the vertex texture coordinates at rank theRank from the vertex table if defined.
        void VertexTexel(Standard_Integer theRank, Standard_Real^ theTX, Standard_Real^ theTY);

        //! @name optional array of Indices/Edges for using shared Vertex data

        //! Returns optional index buffer.
        XGraphic3d_IndexBuffer^ Indices();

        //! Returns the number of defined edges
        Standard_Integer EdgeNumber();

        //! Returns the number of allocated edges
        Standard_Integer EdgeNumberAllocated();

        //! Returns the vertex index at rank theRank in the range [1,EdgeNumber()]
        Standard_Integer Edge(Standard_Integer theRank);

        //! Adds an edge in the range [1,VertexNumber()] in the array.
        //! @return the actual edges number
        Standard_Integer AddEdge(Standard_Integer theVertexIndex);

        //! Convenience method, adds two vertex indices (a segment) in the range [1,VertexNumber()] in the array.
        //! @return the actual edges number
        Standard_Integer AddEdges(Standard_Integer theVertexIndex1, Standard_Integer theVertexIndex2);

        //! Convenience method, adds two vertex indices (a segment) in the range [1,VertexNumber()] in the array of segments (Graphic3d_TOPA_SEGMENTS).
        //! Raises exception if array is not of type Graphic3d_TOPA_SEGMENTS.
        //! @return the actual edges number
        Standard_Integer AddSegmentEdges(Standard_Integer theVertexIndex1, Standard_Integer theVertexIndex2);

        //! Convenience method, adds three vertex indices (a triangle) in the range [1,VertexNumber()] in the array.
        //! @return the actual edges number
        Standard_Integer AddEdges(Standard_Integer theVertexIndex1, Standard_Integer theVertexIndex2, Standard_Integer theVertexIndex3);

        //! Convenience method, adds three vertex indices of triangle in the range [1,VertexNumber()] in the array of triangles.
        //! Raises exception if array is not of type Graphic3d_TOPA_TRIANGLES.
        //! @return the actual edges number
        Standard_Integer AddTriangleEdges(Standard_Integer theVertexIndex1, Standard_Integer theVertexIndex2, Standard_Integer theVertexIndex3);

        //! Convenience method, adds three vertex indices of triangle in the range [1,VertexNumber()] in the array of triangles.
        //! Raises exception if array is not of type Graphic3d_TOPA_TRIANGLES.
        //! @return the actual edges number
        Standard_Integer AddTriangleEdges(XGraphic3d_Vec3i^ theIndexes);

        //! Convenience method, adds three vertex indices (4th component is ignored) of triangle in the range [1,VertexNumber()] in the array of triangles.
        //! Raises exception if array is not of type Graphic3d_TOPA_TRIANGLES.
        //! @return the actual edges number
        Standard_Integer AddTriangleEdges(XGraphic3d_Vec4i^ theIndexes);

        //! Convenience method, adds four vertex indices (a quad) in the range [1,VertexNumber()] in the array.
        //! @return the actual edges number
        Standard_Integer AddEdges(Standard_Integer theVertexIndex1, Standard_Integer theVertexIndex2, Standard_Integer theVertexIndex3, Standard_Integer theVertexIndex4);

        //! Convenience method, adds four vertex indices (a quad) in the range [1,VertexNumber()] in the array of quads.
        //! Raises exception if array is not of type Graphic3d_TOPA_QUADRANGLES.
        //! @return the actual edges number
        Standard_Integer AddQuadEdges(Standard_Integer theVertexIndex1, Standard_Integer theVertexIndex2, Standard_Integer theVertexIndex3, Standard_Integer theVertexIndex4);

        //! Convenience method, adds quad indices in the range [1,VertexNumber()] into array or triangles as two triangles.
        //! Raises exception if array is not of type Graphic3d_TOPA_TRIANGLES.
        //! @return the actual edges number
        Standard_Integer AddQuadTriangleEdges(Standard_Integer theVertexIndex1, Standard_Integer theVertexIndex2, Standard_Integer theVertexIndex3, Standard_Integer theVertexIndex4);

        //! Convenience method, adds quad indices in the range [1,VertexNumber()] into array or triangles as two triangles.
        //! Raises exception if array is not of type Graphic3d_TOPA_TRIANGLES.
        //! @return the actual edges number
        Standard_Integer AddQuadTriangleEdges(XGraphic3d_Vec4i^ theIndexes);

        //! Add triangle strip into indexed triangulation array.
        //! N-2 triangles are added from N input nodes.
        //! Raises exception if array is not of type Graphic3d_TOPA_TRIANGLES.
        //! @param theVertexLower [in] index of first node defining triangle strip
        //! @param theVertexUpper [in] index of last  node defining triangle strip
        void AddTriangleStripEdges(Standard_Integer theVertexLower, Standard_Integer theVertexUpper);

        //! Add triangle fan into indexed triangulation array.
        //! N-2 triangles are added from N input nodes (or N-1 with closed flag).
        //! Raises exception if array is not of type Graphic3d_TOPA_TRIANGLES.
        //! @param theVertexLower [in] index of first node defining triangle fun (center)
        //! @param theVertexUpper [in] index of last  node defining triangle fun
        //! @param theToClose [in] close triangle fan (connect first and last points)
        void AddTriangleFanEdges(Standard_Integer theVertexLower, Standard_Integer theVertexUpper, Standard_Boolean theToClose);

        //! Add line strip (polyline) into indexed segments array.
        //! N-1 segments are added from N input nodes (or N with closed flag).
        //! Raises exception if array is not of type Graphic3d_TOPA_SEGMENTS.
        //! @param theVertexLower [in] index of first node defining line strip fun (center)
        //! @param theVertexUpper [in] index of last  node defining triangle fun
        //! @param theToClose [in] close triangle fan (connect first and last points)
        void AddPolylineEdges(Standard_Integer theVertexLower, Standard_Integer theVertexUpper, Standard_Boolean theToClose);

        //! @name optional array of Bounds/Subgroups within primitive array (e.g. restarting primitives / assigning colors)

        //! Returns optional bounds buffer.
        XGraphic3d_BoundBuffer^ Bounds();

        //! Returns TRUE when bound colors array is defined.
        Standard_Boolean HasBoundColors();

        //! Returns the number of defined bounds
        Standard_Integer BoundNumber();

        //! Returns the number of allocated bounds
        Standard_Integer BoundNumberAllocated();

        //! Returns the edge number at rank theRank.
        Standard_Integer Bound(Standard_Integer theRank);

        //! Returns the bound color at rank theRank from the bound table if defined.
        XQuantity_Color^ BoundColor(Standard_Integer theRank);

        //! Returns the bound color values at rank theRank from the bound table if defined.
        void BoundColor(Standard_Integer theRank, Standard_Real% theR, Standard_Real% theG, Standard_Real% theB);

        //! Adds a bound of length theEdgeNumber in the bound array
        //! @return the actual bounds number
        Standard_Integer AddBound(Standard_Integer theEdgeNumber);

        //! Adds a bound of length theEdgeNumber and bound color theBColor in the bound array.
        //! Warning: theBColor is ignored when the hasBColorsructor parameter is FALSE
        //! @return the actual bounds number
        Standard_Integer AddBound(Standard_Integer theEdgeNumber, XQuantity_Color^ theBColor);

        //! Adds a bound of length theEdgeNumber and bound color coordinates in the bound array.
        //! Warning: <theR,theG,theB> are ignored when the hasBColorsructor parameter is FALSE
        //! @return the actual bounds number
        Standard_Integer AddBound(Standard_Integer theEdgeNumber, Standard_Real theR, Standard_Real theG, Standard_Real theB);

        //! Change the bound color of rank theIndex in the array.
        void SetBoundColor(Standard_Integer theIndex, XQuantity_Color^ theColor);

        //! Change the bound color of rank theIndex in the array.
        void SetBoundColor(Standard_Integer theIndex, Standard_Real theR, Standard_Real theG, Standard_Real theB);
    };
}
#endif // _XGraphic3d_ArrayOfPrimitives_HeaderFile
