// Copyright (c) 2019 OPEN CASCADE SAS
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

#ifndef _XGraphic3d_Aspects_HeaderFile
#define _XGraphic3d_Aspects_HeaderFile
#pragma once
#include <Graphic3d_Aspects.hxx>
#include <XAspect_InteriorStyle.h>
#include <XGraphic3d_TypeOfShadingModel.h>
#include <XGraphic3d_AlphaMode.h>
#include <XQuantity_ColorRGBA.h>
#include <XQuantity_Color.h>
#include <XGraphic3d_MaterialAspect.h>
#include <XAspect_TypeOfLine.h>
#include <XAspect_TypeOfMarker.h>
#include <XAspect_TypeOfDisplayText.h>
#include <XAspect_TypeOfStyleText.h>
#include <XAspect_HatchStyle.h>
#include <XFont_FontAspect.h>

#include <Aspect_PolygonOffsetMode.hxx>
#include <Aspect_InteriorStyle.hxx>
#include <Aspect_TypeOfDisplayText.hxx>
#include <Aspect_TypeOfLine.hxx>
#include <Aspect_TypeOfMarker.hxx>
#include <Aspect_TypeOfStyleText.hxx>
#include <Font_FontAspect.hxx>
#include <Font_NameOfFont.hxx>
#include <Graphic3d_AlphaMode.hxx>
#include <Graphic3d_MarkerImage.hxx>
#include <Graphic3d_HatchStyle.hxx>
#include <Graphic3d_MaterialAspect.hxx>
#include <Graphic3d_PolygonOffset.hxx>
#include <Graphic3d_ShaderProgram.hxx>
#include <Graphic3d_TextureMap.hxx>
#include <Graphic3d_TextureSet.hxx>
#include <Graphic3d_TypeOfShadingModel.hxx>
#include <TCollection_HAsciiString.hxx>

using namespace TKernel;
namespace TKService {
    ref class TKernel::XQuantity_ColorRGBA;
    ref class TKernel::XQuantity_Color;
    ref class XGraphic3d_MaterialAspect;
    //! This class defines graphic attributes.
    public ref class XGraphic3d_Aspects //: public Standard_Transient
    {
    public:

        //! Creates a context table for drawing primitives defined with the following default values:
        XGraphic3d_Aspects();

        !XGraphic3d_Aspects();// { };// { IHandle = NULL; };
        ~XGraphic3d_Aspects();// { IHandle = NULL; };
        void SetAspectsHandle(Handle(Graphic3d_Aspects) pos);

        Handle(Graphic3d_Aspects) GetAspectsHandle();

        //! Return interior rendering style; Aspect_IS_SOLID by default.
        XAspect_InteriorStyle InteriorStyle();

        //! Modifies the interior type used for rendering
        void SetInteriorStyle(XAspect_InteriorStyle theStyle);

        //! Returns shading model; Graphic3d_TOSM_DEFAULT by default.
        //! Graphic3d_TOSM_DEFAULT means that Shading Model set as default for entire Viewer will be used.
        XGraphic3d_TypeOfShadingModel ShadingModel();

        //! Sets shading model
        void SetShadingModel(XGraphic3d_TypeOfShadingModel theShadingModel);

        //! Returns the way how alpha value should be treated (Graphic3d_AlphaMode_BlendAuto by default, for backward compatibility).
        XGraphic3d_AlphaMode AlphaMode();

        //! Returns alpha cutoff threshold, for discarding fragments within Graphic3d_AlphaMode_Mask mode (0.5 by default).
        //! If the alpha value is greater than or equal to this value then it is rendered as fully opaque, otherwise, it is rendered as fully transparent.
        Standard_ShortReal AlphaCutoff();

        //! Defines the way how alpha value should be treated.
        //! Standard_ShortReal theAlphaCutoff = 0.5f
        void SetAlphaMode(XGraphic3d_AlphaMode theMode, Standard_ShortReal theAlphaCutoff);

        //! Return color
        XQuantity_ColorRGBA^ ColorRGBA();

        //! Return the color.
        XQuantity_Color^ Color();

        //! Modifies the color.
        void SetColor(XQuantity_Color^ theColor);

        //! Return interior color.
        XQuantity_Color^ InteriorColor();

        //! Return interior color.
        XQuantity_ColorRGBA^ InteriorColorRGBA();

        //! Modifies the color of the interior of the face
        void SetInteriorColor(XQuantity_Color^ theColor);

        //! Modifies the color of the interior of the face
        void SetInteriorColor(XQuantity_ColorRGBA^ theColor);

        //! Return back interior color.
        XQuantity_Color^ BackInteriorColor();

        //! Return back interior color.
        XQuantity_ColorRGBA^ BackInteriorColorRGBA();

        //! Modifies the color of the interior of the back face
        void SetBackInteriorColor(XQuantity_Color^ theColor);

        //! Modifies the color of the interior of the back face
        void SetBackInteriorColor(XQuantity_ColorRGBA^ theColor);

        //! Returns the surface material of external faces
        XGraphic3d_MaterialAspect^ FrontMaterial();

        //! Returns the surface material of external faces
        XGraphic3d_MaterialAspect^ ChangeFrontMaterial();

        //! Modifies the surface material of external faces
        void SetFrontMaterial(XGraphic3d_MaterialAspect^ theMaterial);

        //! Returns the surface material of internal faces
        XGraphic3d_MaterialAspect^ BackMaterial();

        //! Returns the surface material of internal faces
        XGraphic3d_MaterialAspect^ ChangeBackMaterial();

        //! Modifies the surface material of internal faces
        void SetBackMaterial(XGraphic3d_MaterialAspect^ theMaterial);

        //! Returns true if back faces should be suppressed (true by default).
        bool ToSuppressBackFaces();

        //! Assign back faces culling flag.
        void SetSuppressBackFaces(bool theToSuppress);

        //! Returns true if back faces should be suppressed (true by default).
        bool BackFace();

        //! Allows the display of back-facing filled polygons.
        void AllowBackFace();

        //! Suppress the display of back-facing filled polygons.
        //! A back-facing polygon is defined as a polygon whose
        //! vertices are in a clockwise order with respect to screen coordinates.
        void SuppressBackFace();

        //! Returns true if material properties should be distinguished for back and front faces (false by default).
        bool Distinguish();

        //! Set material distinction between front and back faces.
        void SetDistinguish(bool toDistinguish);

        //! Allows material distinction between front and back faces.
        void SetDistinguishOn();

        //! Forbids material distinction between front and back faces.
        void SetDistinguishOff();

        //! Return shader program.
        Handle(Graphic3d_ShaderProgram) ShaderProgram();

        //! Sets up OpenGL/GLSL shader program.
        void SetShaderProgram( Handle(Graphic3d_ShaderProgram) theProgram);

        //! Return texture array to be mapped.
        Handle(Graphic3d_TextureSet) TextureSet();

        //! Setup texture array to be mapped.
        void SetTextureSet( Handle(Graphic3d_TextureSet) theTextures);

        //! Return texture to be mapped.
        //Standard_DEPRECATED("Deprecated method, TextureSet() should be used instead")
        Handle(Graphic3d_TextureMap) TextureMap();

        //! Assign texture to be mapped.
        //! See also SetTextureMapOn() to actually activate texture mapping.
        //Standard_DEPRECATED("Deprecated method, SetTextureSet() should be used instead")
        void SetTextureMap( Handle(Graphic3d_TextureMap) theTexture);

        //! Return true if texture mapping is enabled (false by default).
        bool ToMapTexture();

        //! Return true if texture mapping is enabled (false by default).
        bool TextureMapState();

        //! Enable or disable texture mapping (has no effect if texture is not set).
        void SetTextureMapOn(bool theToMap);

        //! Enable texture mapping (has no effect if texture is not set).
        void SetTextureMapOn();

        //! Disable texture mapping.
        void SetTextureMapOff();

        //! Returns current polygon offsets settings.
        Graphic3d_PolygonOffset PolygonOffset();

        //! Sets polygon offsets settings.
        void SetPolygonOffset( Graphic3d_PolygonOffset theOffset);

        //! Returns current polygon offsets settings.
        void PolygonOffsets(Standard_Integer% theMode, Standard_ShortReal% theFactor, Standard_ShortReal% theUnits);

        //! Sets up OpenGL polygon offsets mechanism.
        //! <aMode> parameter can contain various combinations of
        //! Aspect_PolygonOffsetMode enumeration elements (Aspect_POM_None means
        //! that polygon offsets are not changed).
        //! If <aMode> is different from Aspect_POM_Off and Aspect_POM_None, then <aFactor> and <aUnits>
        //! arguments are used by graphic renderer to calculate a depth offset value:
        //!
        //! offset = <aFactor> * m + <aUnits> * r, where
        //! m - maximum depth slope for the polygon currently being displayed,
        //! r - minimum window coordinates depth resolution (implementation-specific)
        //!
        //! Default settings for OCC 3D viewer: mode = Aspect_POM_Fill, factor = 1., units = 0.
        //!
        //! Negative offset values move polygons closer to the viewport,
        //! while positive values shift polygons away.
        //! Consult OpenGL reference for details (glPolygonOffset function description).
        //! Standard_ShortReal theFactor = 1.0f, Standard_ShortReal theUnits = 0.0f
        void SetPolygonOffsets(Standard_Integer   theMode, Standard_ShortReal theFactor, Standard_ShortReal theUnits);

        //! @name parameters specific to Line primitive rendering
    public:

        //! Return line type; Aspect_TOL_SOLID by default.
        XAspect_TypeOfLine LineType();

        //! Modifies the line type
        void SetLineType(XAspect_TypeOfLine theType);

        //! Return width for edges in pixels; 1.0 by default.
        Standard_ShortReal LineWidth();

        //! Modifies the line thickness
        //! Warning: Raises Standard_OutOfRange if the width is a negative value.
        void SetLineWidth(Standard_ShortReal theWidth);

        //! @name parameters specific to Point (Marker) primitive rendering
    public:

        //! Return marker type; Aspect_TOM_POINT by default.
        XAspect_TypeOfMarker MarkerType();

        //! Modifies the type of marker.
        void SetMarkerType(XAspect_TypeOfMarker theType);

        //! Return marker scale factor; 1.0 by default.
        Standard_ShortReal MarkerScale();

        //! Modifies the scale factor.
        //! Marker type Aspect_TOM_POINT is not affected by the marker size scale factor.
        //! It is always the smallest displayable dot.
        //! Warning: Raises Standard_OutOfRange if the scale is a negative value.
        void SetMarkerScale(Standard_ShortReal theScale);

        //! Returns marker's image texture.
        //! Could be null handle if marker aspect has been initialized as default type of marker.
        Handle(Graphic3d_MarkerImage) MarkerImage();

        //! Set marker's image texture.
        void SetMarkerImage( Handle(Graphic3d_MarkerImage) theImage);

        //! Returns TRUE if marker should be drawn using marker sprite (either user-provided or generated).
        bool IsMarkerSprite();

        //! @name parameters specific to text rendering
    public:

        //! Returns the font; NULL string by default.
         Handle(TCollection_HAsciiString) TextFont();

        //! Modifies the font.
        void SetTextFont( Handle(TCollection_HAsciiString) theFont);

        //! Returns text FontAspect
        XFont_FontAspect TextFontAspect();

        //! Turns usage of Aspect text
        void SetTextFontAspect(XFont_FontAspect theFontAspect);

        //! Returns display type; Aspect_TODT_NORMAL by default.
        XAspect_TypeOfDisplayText TextDisplayType();

        //! Sets display type.
        void SetTextDisplayType(XAspect_TypeOfDisplayText theType);

        //! Returns text background/shadow color; equals to EdgeColor() property.
        XQuantity_ColorRGBA^ ColorSubTitleRGBA();

        //! Return text background/shadow color; equals to EdgeColor() property.
        XQuantity_Color^ ColorSubTitle();

        //! Modifies text background/shadow color; equals to EdgeColor() property.
        void SetColorSubTitle(XQuantity_Color^ theColor);

        //! Modifies text background/shadow color; equals to EdgeColor() property.
        void SetColorSubTitle(XQuantity_ColorRGBA^ theColor);

        //! Returns TRUE when the Text Zoomable is on.
        bool IsTextZoomable();

        //! Turns usage of text zoomable on/off
        void SetTextZoomable(bool theFlag);

        //! Returns the text style; Aspect_TOST_NORMAL by default.
        XAspect_TypeOfStyleText TextStyle();

        //! Modifies the style of the text.
        void SetTextStyle(XAspect_TypeOfStyleText theStyle);

        //! Returns Angle of degree
        Standard_ShortReal TextAngle();

        //! Turns usage of text rotated
        void SetTextAngle(Standard_ShortReal theAngle);

        //! @name parameters specific to Mesh Edges (of triangulation primitive) rendering
    public:

        //! Returns true if mesh edges should be drawn (false by default).
        bool ToDrawEdges();

        //! Set if mesh edges should be drawn or not.
        void SetDrawEdges(bool theToDraw);

        //! The edges of FillAreas are drawn.
        void SetEdgeOn();// { SetDrawEdges(true); }

        //! The edges of FillAreas are not drawn.
        void SetEdgeOff();// { SetDrawEdges(false); }

        //! Return color of edges.
        XQuantity_Color^ EdgeColor();

        //! Return color of edges.
        XQuantity_ColorRGBA^ EdgeColorRGBA();

        //! Modifies the color of the edge of the face
        void SetEdgeColor(XQuantity_Color^ theColor);

        //! Modifies the color of the edge of the face
        void SetEdgeColor(XQuantity_ColorRGBA^ theColor);

        //! Return edges line type (same as LineType()).
        XAspect_TypeOfLine EdgeLineType();

        //! Modifies the edge line type (same as SetLineType())
        void SetEdgeLineType(XAspect_TypeOfLine theType);

        //! Return width for edges in pixels (same as LineWidth()).
        Standard_ShortReal EdgeWidth();

        //! Modifies the edge thickness (same as SetLineWidth())
        void SetEdgeWidth(Standard_Real theWidth);// { SetLineWidth((Standard_ShortReal)theWidth); }

        //! Returns TRUE if drawing element edges should discard first edge in triangle; FALSE by default.
        //! Graphics hardware works mostly with triangles, so that wireframe presentation will draw triangle edges by default.
        //! This flag allows rendering wireframe presentation of quad-only array split into triangles.
        //! For this, quads should be split in specific order, so that the quad diagonal (to be NOT rendered) goes first:
        //!     1------2
        //!    /      /   Triangle #1: 2-0-1; Triangle #2: 0-2-3
        //!   0------3
        bool ToSkipFirstEdge();

        //! Set skip first triangle edge flag for drawing wireframe presentation of quads array split into triangles.
        void SetSkipFirstEdge(bool theToSkipFirstEdge);

        //! Returns TRUE if silhouette (outline) should be drawn (with edge color and width); FALSE by default.
        bool ToDrawSilhouette();

        //! Enables/disables drawing silhouette (outline).
        void SetDrawSilhouette(bool theToDraw);

    public:

        //! Returns the hatch type used when InteriorStyle is IS_HATCH
        Handle(Graphic3d_HatchStyle) HatchStyle();

        //! Modifies the hatch type used when InteriorStyle is IS_HATCH
        void SetHatchStyle( Handle(Graphic3d_HatchStyle) theStyle);

        //! Modifies the hatch type used when InteriorStyle is IS_HATCH
        //! @warning This method always creates a new handle for a given hatch style
        void SetHatchStyle(XAspect_HatchStyle theStyle);

    public:

        //! Check for equality with another aspects.
        bool IsEqual(XGraphic3d_Aspects^ theOther);

        //! Dumps the content of me into the stream
        //!  Standard_Integer theDepth = -1
        void DumpJson(Standard_OStream theOStream, Standard_Integer theDepth);

        /// <summary>
        /// ±¾µØ¾ä±ú
        /// </summary>
        virtual property Handle(Standard_Transient) IHandle {
            Handle(Standard_Transient) get() {//Standard_OVERRIDE {
                return NativeHandle();
            }
            void set(Handle(Standard_Transient) handle) {//Standard_OVERRIDE {
                if (!handle.IsNull())
                    NativeHandle() = Handle(Graphic3d_Aspects)::DownCast(handle);
                else if (!NativeHandle().IsNull())
                    NativeHandle() = NULL;
            }
        }
    private:
        NCollection_Haft<Handle(Graphic3d_Aspects)> NativeHandle;
    };
}
#endif // _XGraphic3d_Aspects_HeaderFile
