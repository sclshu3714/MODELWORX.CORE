#include <XGraphic3d_Aspects.h>
namespace TKService {
    //! Creates a context table for drawing primitives defined with the following default values:
    XGraphic3d_Aspects::XGraphic3d_Aspects() {
        NativeHandle() = new Graphic3d_Aspects();
    };

    XGraphic3d_Aspects::!XGraphic3d_Aspects() { 
    
    };// { IHandle = NULL; };

    XGraphic3d_Aspects::~XGraphic3d_Aspects() { 
        IHandle = NULL; 
    };

    void XGraphic3d_Aspects::SetAspectsHandle(Handle(Graphic3d_Aspects) pos) {
        NativeHandle() = pos;
    };

    Handle(Graphic3d_Aspects) XGraphic3d_Aspects::GetAspectsHandle() {
        return NativeHandle();
    };

    //! Return interior rendering style; Aspect_IS_SOLID by default.
    XAspect_InteriorStyle XGraphic3d_Aspects::InteriorStyle() {
        return safe_cast<XAspect_InteriorStyle>(NativeHandle()->InteriorStyle());
    };

    //! Modifies the interior type used for rendering
    void XGraphic3d_Aspects::SetInteriorStyle(XAspect_InteriorStyle theStyle) {
        NativeHandle()->SetInteriorStyle(safe_cast<Aspect_InteriorStyle>(theStyle));
    };

    //! Returns shading model; Graphic3d_TOSM_DEFAULT by default.
    //! Graphic3d_TOSM_DEFAULT means that Shading Model set as default for entire Viewer will be used.
    XGraphic3d_TypeOfShadingModel XGraphic3d_Aspects::ShadingModel() {
        return safe_cast<XGraphic3d_TypeOfShadingModel>(NativeHandle()->ShadingModel());
    };

    //! Sets shading model
    void XGraphic3d_Aspects::SetShadingModel(XGraphic3d_TypeOfShadingModel theShadingModel) {
        NativeHandle()->SetShadingModel(safe_cast<Graphic3d_TypeOfShadingModel>(theShadingModel));
    };

    //! Returns the way how alpha value should be treated (Graphic3d_AlphaMode_BlendAuto by default, for backward compatibility).
    XGraphic3d_AlphaMode XGraphic3d_Aspects::AlphaMode() {
        return safe_cast<XGraphic3d_AlphaMode>(NativeHandle()->AlphaMode());
    };

    //! Returns alpha cutoff threshold, for discarding fragments within Graphic3d_AlphaMode_Mask mode (0.5 by default).
    //! If the alpha value is greater than or equal to this value then it is rendered as fully opaque, otherwise, it is rendered as fully transparent.
    Standard_ShortReal XGraphic3d_Aspects::AlphaCutoff() {
        return NativeHandle()->AlphaCutoff();
    };

    //! Defines the way how alpha value should be treated.
    //! Standard_ShortReal theAlphaCutoff = 0.5f
    void XGraphic3d_Aspects::SetAlphaMode(XGraphic3d_AlphaMode theMode, Standard_ShortReal theAlphaCutoff) {
        NativeHandle()->SetAlphaMode(safe_cast<Graphic3d_AlphaMode>(theMode), theAlphaCutoff);
    };

    //! Return color
    XQuantity_ColorRGBA^ XGraphic3d_Aspects::ColorRGBA() {
        Quantity_ColorRGBA* pos = new Quantity_ColorRGBA(NativeHandle()->ColorRGBA());
        return gcnew XQuantity_ColorRGBA(pos);
    };

    //! Return the color.
    XQuantity_Color^ XGraphic3d_Aspects::Color() {
        return gcnew XQuantity_Color(NativeHandle()->Color());
    };

    //! Modifies the color.
    void XGraphic3d_Aspects::SetColor(XQuantity_Color^ theColor) {
        NativeHandle()->SetColor(*theColor->GetColor());
    };

    //! Return interior color.
    XQuantity_Color^ XGraphic3d_Aspects::InteriorColor() {
        return gcnew XQuantity_Color(NativeHandle()->InteriorColor());
    };

    //! Return interior color.
    XQuantity_ColorRGBA^ XGraphic3d_Aspects::InteriorColorRGBA() {
        Quantity_ColorRGBA* pos = new Quantity_ColorRGBA(NativeHandle()->InteriorColorRGBA());
        return gcnew XQuantity_ColorRGBA(pos);
    };

    //! Modifies the color of the interior of the face
    void XGraphic3d_Aspects::SetInteriorColor(XQuantity_Color^ theColor) {
        NativeHandle()->SetInteriorColor(*theColor->GetColor());
    };

    //! Modifies the color of the interior of the face
    void XGraphic3d_Aspects::SetInteriorColor(XQuantity_ColorRGBA^ theColor) {
        NativeHandle()->SetInteriorColor(*theColor->GetColorRGBA());
    };

    //! Return back interior color.
    XQuantity_Color^ XGraphic3d_Aspects::BackInteriorColor() {
        return gcnew XQuantity_Color(NativeHandle()->BackInteriorColor());
    };

    //! Return back interior color.
    XQuantity_ColorRGBA^ XGraphic3d_Aspects::BackInteriorColorRGBA() {
        Quantity_ColorRGBA* pos = new Quantity_ColorRGBA(NativeHandle()->BackInteriorColorRGBA());
        return gcnew XQuantity_ColorRGBA(pos);
    };

    //! Modifies the color of the interior of the back face
    void XGraphic3d_Aspects::SetBackInteriorColor(XQuantity_Color^ theColor) {
        NativeHandle()->SetBackInteriorColor(*theColor->GetColor());
    };

    //! Modifies the color of the interior of the back face
    void XGraphic3d_Aspects::SetBackInteriorColor(XQuantity_ColorRGBA^ theColor) {
        NativeHandle()->SetBackInteriorColor(*theColor->GetColorRGBA());
    };

    //! Returns the surface material of external faces
    XGraphic3d_MaterialAspect^ XGraphic3d_Aspects::FrontMaterial() {
        Graphic3d_MaterialAspect* pos = new Graphic3d_MaterialAspect(NativeHandle()->FrontMaterial());
        return gcnew XGraphic3d_MaterialAspect(pos);
    };

    //! Returns the surface material of external faces
    XGraphic3d_MaterialAspect^ XGraphic3d_Aspects::ChangeFrontMaterial() {
        Graphic3d_MaterialAspect* pos = new Graphic3d_MaterialAspect(NativeHandle()->ChangeFrontMaterial());
        return gcnew XGraphic3d_MaterialAspect(pos);
    };

    //! Modifies the surface material of external faces
    void XGraphic3d_Aspects::SetFrontMaterial(XGraphic3d_MaterialAspect^ theMaterial) {
        NativeHandle()->SetFrontMaterial(*theMaterial->GetMaterialAspect());
    };

    //! Returns the surface material of internal faces
    XGraphic3d_MaterialAspect^ XGraphic3d_Aspects::BackMaterial() {
        Graphic3d_MaterialAspect* pos = new Graphic3d_MaterialAspect(NativeHandle()->BackMaterial());
        return gcnew XGraphic3d_MaterialAspect(pos);
    };

    //! Returns the surface material of internal faces
    XGraphic3d_MaterialAspect^ XGraphic3d_Aspects::ChangeBackMaterial() {
        Graphic3d_MaterialAspect* pos = new Graphic3d_MaterialAspect(NativeHandle()->ChangeBackMaterial());
        return gcnew XGraphic3d_MaterialAspect(pos);
    };

    //! Modifies the surface material of internal faces
    void XGraphic3d_Aspects::SetBackMaterial(XGraphic3d_MaterialAspect^ theMaterial) {
        NativeHandle()->SetBackMaterial(*theMaterial->GetMaterialAspect());
    };

    //! Returns true if back faces should be suppressed (true by default).
    bool XGraphic3d_Aspects::ToSuppressBackFaces() {
        return NativeHandle()->ToSuppressBackFaces();
    };

    //! Assign back faces culling flag.
    void XGraphic3d_Aspects::SetSuppressBackFaces(bool theToSuppress) {
        NativeHandle()->SetSuppressBackFaces(theToSuppress);
    };

    //! Returns true if back faces should be suppressed (true by default).
    bool XGraphic3d_Aspects::BackFace() {
        return NativeHandle()->BackFace();
    };

    //! Allows the display of back-facing filled polygons.
    void XGraphic3d_Aspects::AllowBackFace() {
        NativeHandle()->AllowBackFace();
    };

    //! Suppress the display of back-facing filled polygons.
    //! A back-facing polygon is defined as a polygon whose
    //! vertices are in a clockwise order with respect to screen coordinates.
    void XGraphic3d_Aspects::SuppressBackFace() {
        NativeHandle()->SuppressBackFace();
    };

    //! Returns true if material properties should be distinguished for back and front faces (false by default).
    bool XGraphic3d_Aspects::Distinguish() {
        return NativeHandle()->Distinguish();
    };

    //! Set material distinction between front and back faces.
    void XGraphic3d_Aspects::SetDistinguish(bool toDistinguish) {
        NativeHandle()->SetDistinguish(toDistinguish);
    };

    //! Allows material distinction between front and back faces.
    void XGraphic3d_Aspects::SetDistinguishOn() {
        NativeHandle()->SetDistinguishOn();
    };

    //! Forbids material distinction between front and back faces.
    void XGraphic3d_Aspects::SetDistinguishOff() {
        NativeHandle()->SetDistinguishOff();
    };

    //! Return shader program.
    Handle(Graphic3d_ShaderProgram) XGraphic3d_Aspects::ShaderProgram() {
        return NativeHandle()->ShaderProgram();
    };

    //! Sets up OpenGL/GLSL shader program.
    void XGraphic3d_Aspects::SetShaderProgram(const Handle(Graphic3d_ShaderProgram) theProgram) {
        NativeHandle()->SetShaderProgram(theProgram);
    };

    //! Return texture array to be mapped.
    Handle(Graphic3d_TextureSet) XGraphic3d_Aspects::TextureSet() {
        return NativeHandle()->TextureSet();
    };

    //! Setup texture array to be mapped.
    void XGraphic3d_Aspects::SetTextureSet(Handle(Graphic3d_TextureSet) theTextures) {
        NativeHandle()->SetTextureSet(theTextures);
    };

    //! Return texture to be mapped.
    //Standard_DEPRECATED("Deprecated method, TextureSet() should be used instead")
    Handle(Graphic3d_TextureMap) XGraphic3d_Aspects::TextureMap() {
        return NativeHandle()->TextureMap();
    };

    //! Assign texture to be mapped.
    //! See also SetTextureMapOn() to actually activate texture mapping.
    //Standard_DEPRECATED("Deprecated method, SetTextureSet() should be used instead")
    void XGraphic3d_Aspects::SetTextureMap(Handle(Graphic3d_TextureMap) theTexture) {
        NativeHandle()->SetTextureMap(theTexture);
    };

    //! Return true if texture mapping is enabled (false by default).
    bool XGraphic3d_Aspects::ToMapTexture() {
        return NativeHandle()->ToMapTexture();
    };

    //! Return true if texture mapping is enabled (false by default).
    bool XGraphic3d_Aspects::TextureMapState() {
        return NativeHandle()->TextureMapState();
    };

    //! Enable or disable texture mapping (has no effect if texture is not set).
    void XGraphic3d_Aspects::SetTextureMapOn(bool theToMap) {
        NativeHandle()->SetTextureMapOn(theToMap);
    };

    //! Enable texture mapping (has no effect if texture is not set).
    void XGraphic3d_Aspects::SetTextureMapOn() {
        NativeHandle()->SetTextureMapOn();
    };

    //! Disable texture mapping.
    void XGraphic3d_Aspects::SetTextureMapOff() {
        NativeHandle()->SetTextureMapOff();
    };

    //! Returns current polygon offsets settings.
    Graphic3d_PolygonOffset XGraphic3d_Aspects::PolygonOffset() {
        return NativeHandle()->PolygonOffset();
    };

    //! Sets polygon offsets settings.
    void XGraphic3d_Aspects::SetPolygonOffset(Graphic3d_PolygonOffset theOffset) {
        NativeHandle()->SetPolygonOffset(theOffset);
    };

    //! Returns current polygon offsets settings.
    void XGraphic3d_Aspects::PolygonOffsets(Standard_Integer% theMode, Standard_ShortReal% theFactor, Standard_ShortReal% theUnits) {
        Standard_Integer theModex; Standard_ShortReal theFactorx; Standard_ShortReal theUnitsx;
        NativeHandle()->PolygonOffsets(theModex, theFactorx, theUnitsx);
        theMode = theModex; theFactor = theFactorx; theUnits = theUnitsx;
    };

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
    void XGraphic3d_Aspects::SetPolygonOffsets(Standard_Integer   theMode, Standard_ShortReal theFactor, Standard_ShortReal theUnits) {
        NativeHandle()->SetPolygonOffsets(theMode, theFactor, theUnits);
    };

    //! @name parameters specific to Line primitive rendering

    //! Return line type; Aspect_TOL_SOLID by default.
    XAspect_TypeOfLine XGraphic3d_Aspects::LineType() {
        return safe_cast<XAspect_TypeOfLine>(NativeHandle()->LineType());
    };

    //! Modifies the line type
    void XGraphic3d_Aspects::SetLineType(XAspect_TypeOfLine theType) {
        NativeHandle()->SetLineType(safe_cast<Aspect_TypeOfLine>(theType));
    };

    //! Return width for edges in pixels; 1.0 by default.
    Standard_ShortReal XGraphic3d_Aspects::LineWidth() {
        return NativeHandle()->LineWidth();
    };

    //! Modifies the line thickness
    //! Warning: Raises Standard_OutOfRange if the width is a negative value.
    void XGraphic3d_Aspects::SetLineWidth(Standard_ShortReal theWidth) {
        NativeHandle()->SetLineWidth(theWidth);
    };

    //! @name parameters specific to Point (Marker) primitive rendering

    //! Return marker type; Aspect_TOM_POINT by default.
    XAspect_TypeOfMarker XGraphic3d_Aspects::MarkerType() {
        return safe_cast<XAspect_TypeOfMarker>(NativeHandle()->MarkerType());
    };

    //! Modifies the type of marker.
    void XGraphic3d_Aspects::SetMarkerType(XAspect_TypeOfMarker theType) {
        NativeHandle()->SetMarkerType(safe_cast<Aspect_TypeOfMarker>(theType));
    };

    //! Return marker scale factor; 1.0 by default.
    Standard_ShortReal XGraphic3d_Aspects::MarkerScale() {
        return NativeHandle()->MarkerScale();
    };

    //! Modifies the scale factor.
    //! Marker type Aspect_TOM_POINT is not affected by the marker size scale factor.
    //! It is always the smallest displayable dot.
    //! Warning: Raises Standard_OutOfRange if the scale is a negative value.
    void XGraphic3d_Aspects::SetMarkerScale(Standard_ShortReal theScale) {
        NativeHandle()->SetMarkerScale(theScale);
    };

    //! Returns marker's image texture.
    //! Could be null handle if marker aspect has been initialized as default type of marker.
    Handle(Graphic3d_MarkerImage) XGraphic3d_Aspects::MarkerImage() {
        return NativeHandle()->MarkerImage();
    };

    //! Set marker's image texture.
    void XGraphic3d_Aspects::SetMarkerImage(const Handle(Graphic3d_MarkerImage) theImage) {
        NativeHandle()->SetMarkerImage(theImage);
    };

    //! Returns TRUE if marker should be drawn using marker sprite (either user-provided or generated).
    bool XGraphic3d_Aspects::IsMarkerSprite() {
        return NativeHandle()->IsMarkerSprite();
    };

    //! @name parameters specific to text rendering

    //! Returns the font; NULL string by default.
    Handle(TCollection_HAsciiString) XGraphic3d_Aspects::TextFont() {
        return NativeHandle()->TextFont();
    };

    //! Modifies the font.
    void XGraphic3d_Aspects::SetTextFont(const Handle(TCollection_HAsciiString) theFont) {
        NativeHandle()->SetTextFont(theFont);
    };

    //! Returns text FontAspect
    XFont_FontAspect XGraphic3d_Aspects::TextFontAspect() {
        return safe_cast<XFont_FontAspect>(NativeHandle()->TextFontAspect());
    };

    //! Turns usage of Aspect text
    void XGraphic3d_Aspects::SetTextFontAspect(XFont_FontAspect theFontAspect) {
        NativeHandle()->SetTextFontAspect(safe_cast<Font_FontAspect>(theFontAspect));
    };

    //! Returns display type; Aspect_TODT_NORMAL by default.
    XAspect_TypeOfDisplayText XGraphic3d_Aspects::TextDisplayType() {
        return safe_cast<XAspect_TypeOfDisplayText>(NativeHandle()->TextDisplayType());
    };

    //! Sets display type.
    void XGraphic3d_Aspects::SetTextDisplayType(XAspect_TypeOfDisplayText theType) {
        NativeHandle()->SetTextDisplayType(safe_cast<Aspect_TypeOfDisplayText>(theType));
    };

    //! Returns text background/shadow color; equals to EdgeColor() property.
    XQuantity_ColorRGBA^ XGraphic3d_Aspects::ColorSubTitleRGBA() {
        Quantity_ColorRGBA* pos = new Quantity_ColorRGBA(NativeHandle()->ColorSubTitleRGBA());
        return gcnew XQuantity_ColorRGBA(pos);
    };

    //! Return text background/shadow color; equals to EdgeColor() property.
    XQuantity_Color^ XGraphic3d_Aspects::ColorSubTitle() {
        return gcnew XQuantity_Color(NativeHandle()->ColorSubTitle());
    };

    //! Modifies text background/shadow color; equals to EdgeColor() property.
    void XGraphic3d_Aspects::SetColorSubTitle(XQuantity_Color^ theColor) {
        NativeHandle()->SetColorSubTitle(*theColor->GetColor());
    };

    //! Modifies text background/shadow color; equals to EdgeColor() property.
    void XGraphic3d_Aspects::SetColorSubTitle(XQuantity_ColorRGBA^ theColor) {
        NativeHandle()->SetColorSubTitle(*theColor->GetColorRGBA());
    };

    //! Returns TRUE when the Text Zoomable is on.
    bool XGraphic3d_Aspects::IsTextZoomable() {
        return NativeHandle()->IsTextZoomable();
    };

    //! Turns usage of text zoomable on/off
    void XGraphic3d_Aspects::SetTextZoomable(bool theFlag) {
        NativeHandle()->SetTextZoomable(theFlag);
    };

    //! Returns the text style; Aspect_TOST_NORMAL by default.
    XAspect_TypeOfStyleText XGraphic3d_Aspects::TextStyle() {
        return safe_cast<XAspect_TypeOfStyleText>(NativeHandle()->TextStyle());
    };

    //! Modifies the style of the text.
    void XGraphic3d_Aspects::SetTextStyle(XAspect_TypeOfStyleText theStyle) {
        NativeHandle()->SetTextStyle(safe_cast<Aspect_TypeOfStyleText>(theStyle));
    };

    //! Returns Angle of degree
    Standard_ShortReal XGraphic3d_Aspects::TextAngle() {
        return NativeHandle()->TextAngle();
    };

    //! Turns usage of text rotated
    void XGraphic3d_Aspects::SetTextAngle(Standard_ShortReal theAngle) {
        NativeHandle()->SetTextAngle(theAngle);
    };

    //! @name parameters specific to Mesh Edges (of triangulation primitive) rendering

    //! Returns true if mesh edges should be drawn (false by default).
    bool XGraphic3d_Aspects::ToDrawEdges() {
        return NativeHandle()->ToDrawEdges();
    };

    //! Set if mesh edges should be drawn or not.
    void XGraphic3d_Aspects::SetDrawEdges(bool theToDraw) {
        NativeHandle()->SetDrawEdges(theToDraw);
    };

    //! The edges of FillAreas are drawn.
    void XGraphic3d_Aspects::SetEdgeOn() {
        NativeHandle()->SetEdgeOn();
    };// { SetDrawEdges(true); }

    //! The edges of FillAreas are not drawn.
    void XGraphic3d_Aspects::SetEdgeOff() {
        NativeHandle()->SetEdgeOff();
    };// { SetDrawEdges(false); }

    //! Return color of edges.
    XQuantity_Color^ XGraphic3d_Aspects::EdgeColor() {
        return gcnew XQuantity_Color(NativeHandle()->EdgeColor());
    };

    //! Return color of edges.
    XQuantity_ColorRGBA^ XGraphic3d_Aspects::EdgeColorRGBA() {
        Quantity_ColorRGBA* pos = new Quantity_ColorRGBA(NativeHandle()->EdgeColorRGBA());
        return gcnew XQuantity_ColorRGBA(pos);
    };

    //! Modifies the color of the edge of the face
    void XGraphic3d_Aspects::SetEdgeColor(XQuantity_Color^ theColor) {
        NativeHandle()->SetEdgeColor(*theColor->GetColor());
    };

    //! Modifies the color of the edge of the face
    void XGraphic3d_Aspects::SetEdgeColor(XQuantity_ColorRGBA^ theColor) {
        NativeHandle()->SetEdgeColor(*theColor->GetColorRGBA());
    };

    //! Return edges line type (same as LineType()).
    XAspect_TypeOfLine XGraphic3d_Aspects::EdgeLineType() {
        return safe_cast<XAspect_TypeOfLine>(NativeHandle()->EdgeLineType());
    };

    //! Modifies the edge line type (same as SetLineType())
    void XGraphic3d_Aspects::SetEdgeLineType(XAspect_TypeOfLine theType) {
        NativeHandle()->SetEdgeLineType(safe_cast<Aspect_TypeOfLine>(theType));
    };

    //! Return width for edges in pixels (same as LineWidth()).
    Standard_ShortReal XGraphic3d_Aspects::EdgeWidth() {
        return NativeHandle()->EdgeWidth();
    };

    //! Modifies the edge thickness (same as SetLineWidth())
    void XGraphic3d_Aspects::SetEdgeWidth(Standard_Real theWidth) {
        NativeHandle()->SetEdgeWidth(theWidth);
    };// { SetLineWidth((Standard_ShortReal)theWidth); }

    //! Returns TRUE if drawing element edges should discard first edge in triangle; FALSE by default.
    //! Graphics hardware works mostly with triangles, so that wireframe presentation will draw triangle edges by default.
    //! This flag allows rendering wireframe presentation of quad-only array split into triangles.
    //! For this, quads should be split in specific order, so that the quad diagonal (to be NOT rendered) goes first:
    //!     1------2
    //!    /      /   Triangle #1: 2-0-1; Triangle #2: 0-2-3
    //!   0------3
    bool XGraphic3d_Aspects::ToSkipFirstEdge() {
        return NativeHandle()->ToSkipFirstEdge();
    };

    //! Set skip first triangle edge flag for drawing wireframe presentation of quads array split into triangles.
    void XGraphic3d_Aspects::SetSkipFirstEdge(bool theToSkipFirstEdge) {
        NativeHandle()->SetSkipFirstEdge(theToSkipFirstEdge);
    };

    //! Returns TRUE if silhouette (outline) should be drawn (with edge color and width); FALSE by default.
    bool XGraphic3d_Aspects::ToDrawSilhouette() {
        return NativeHandle()->ToDrawSilhouette();
    };

    //! Enables/disables drawing silhouette (outline).
    void XGraphic3d_Aspects::SetDrawSilhouette(bool theToDraw) {
        NativeHandle()->SetDrawSilhouette(theToDraw);
    };


    //! Returns the hatch type used when InteriorStyle is IS_HATCH
    Handle(Graphic3d_HatchStyle) XGraphic3d_Aspects::HatchStyle() {
        return NativeHandle()->HatchStyle();
    };

    //! Modifies the hatch type used when InteriorStyle is IS_HATCH
    void XGraphic3d_Aspects::SetHatchStyle(Handle(Graphic3d_HatchStyle) theStyle) {
        NativeHandle()->SetHatchStyle(theStyle);
    };

    //! Modifies the hatch type used when InteriorStyle is IS_HATCH
    //! @warning This method always creates a new handle for a given hatch style
    void XGraphic3d_Aspects::SetHatchStyle(XAspect_HatchStyle theStyle) {
        NativeHandle()->SetHatchStyle(safe_cast<Aspect_HatchStyle>(theStyle));
    };


    //! Check for equality with another aspects.
    bool XGraphic3d_Aspects::IsEqual(XGraphic3d_Aspects^ theOther) {
        return NativeHandle()->IsEqual(*theOther->GetAspectsHandle());
    };

    //! Dumps the content of me into the stream
    //! const Standard_Integer theDepth = -1
    void XGraphic3d_Aspects::DumpJson(Standard_OStream theOStream, Standard_Integer theDepth) {
        NativeHandle()->DumpJson(theOStream, theDepth);
    };
}