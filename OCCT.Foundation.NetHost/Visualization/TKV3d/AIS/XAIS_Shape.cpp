#include <XAIS_Shape.h>
namespace TKV3d {
    //! Initializes construction of the shape shap from wires,
        //! edges and vertices.
    XAIS_Shape::XAIS_Shape(TopoDS_Shape shap) {
        NativeHandle() = new AIS_Shape(shap);
    };

    XAIS_Shape::XAIS_Shape(XTopoDS_Shape^ shap) {
        NativeHandle() = new AIS_Shape(shap->GetShape());
    };

    XAIS_Shape::XAIS_Shape(Handle(AIS_Shape) pos) {
        NativeHandle() = pos;
    };
    //! Returns index 0. This value refers to SHAPE from TopAbs_ShapeEnum
    Standard_Integer XAIS_Shape::Signature() {
        return NativeHandle()->Signature();
    };

    //! Returns Object as the type of Interactive Object.
    XAIS_KindOfInteractive XAIS_Shape::Type() {
        return safe_cast<XAIS_KindOfInteractive>(NativeHandle()->Type());
    };

    //! Returns true if the Interactive Object accepts shape decomposition.
    Standard_Boolean XAIS_Shape::AcceptShapeDecomposition() {
        return NativeHandle()->AcceptShapeDecomposition();
    };

    //! Return true if specified display mode is supported.
    Standard_Boolean XAIS_Shape::AcceptDisplayMode(const Standard_Integer theMode) {
        return NativeHandle()->AcceptDisplayMode(theMode);
    };

    //! Returns this shape object.
    XTopoDS_Shape^ XAIS_Shape::Shape() {
        return gcnew XTopoDS_Shape(NativeHandle()->Shape());
    };

    //! Constructs an instance of the shape object theShape.
    void XAIS_Shape::SetShape(XTopoDS_Shape^ theShape) {
        NativeHandle()->SetShape(theShape->GetShape());
    };

    //! Sets a local value for deviation coefficient for this specific shape.
    Standard_Boolean XAIS_Shape::SetOwnDeviationCoefficient() {
        return NativeHandle()->SetOwnDeviationCoefficient();
    };

    //! Sets a local value for HLR deviation coefficient for this specific shape.
    Standard_Boolean XAIS_Shape::SetOwnHLRDeviationCoefficient() {
        return NativeHandle()->SetOwnHLRDeviationCoefficient();
    };

    //! Sets a local value for deviation angle for this specific shape.
    Standard_Boolean XAIS_Shape::SetOwnDeviationAngle() {
        return NativeHandle()->SetOwnDeviationAngle();
    };

    //! Sets a local value for HLR deviation angle for this specific shape.
    Standard_Boolean XAIS_Shape::SetOwnHLRDeviationAngle() {
        return NativeHandle()->SetOwnHLRDeviationAngle();
    };

    //! Sets a local value for deviation coefficient for this specific shape.
    void XAIS_Shape::SetOwnDeviationCoefficient(const Standard_Real aCoefficient) {
        return NativeHandle()->SetOwnDeviationCoefficient(aCoefficient);
    };

    //! sets myOwnHLRDeviationCoefficient field in Prs3d_Drawer &
    //! recomputes presentation
    void XAIS_Shape::SetOwnHLRDeviationCoefficient(const Standard_Real aCoefficient) {
        NativeHandle()->SetOwnHLRDeviationCoefficient(aCoefficient);
    };

    //! this compute a new angle and Deviation from the value anAngle
    //! and set the values stored in myDrawer with these that become local to the shape
    void XAIS_Shape::SetAngleAndDeviation(const Standard_Real anAngle) {
        NativeHandle()->SetAngleAndDeviation(anAngle);
    };

    //! gives back the angle initial value put by the User.
    Standard_Real XAIS_Shape::UserAngle() {
        return NativeHandle()->UserAngle();
    };

    //! sets myOwnDeviationAngle field in Prs3d_Drawer & recomputes presentation
    void XAIS_Shape::SetOwnDeviationAngle(const Standard_Real anAngle) {
        NativeHandle()->SetOwnDeviationAngle(anAngle);
    };

    //! this compute a new Angle and Deviation from the value anAngle for HLR
    //! and set the values stored in myDrawer for with these that become local to the shape
    void XAIS_Shape::SetHLRAngleAndDeviation(const Standard_Real anAngle) {
        NativeHandle()->SetHLRAngleAndDeviation(anAngle);
    };

    //! sets myOwnHLRDeviationAngle field in Prs3d_Drawer & recomputes presentation
    void XAIS_Shape::SetOwnHLRDeviationAngle(const Standard_Real anAngle) {
        NativeHandle()->SetOwnHLRDeviationAngle(anAngle);
    };

    //! Returns true and the values of the deviation
    //! coefficient aCoefficient and the previous deviation
    //! coefficient aPreviousCoefficient. If these values are
    //! not already set, false is returned.
    Standard_Boolean XAIS_Shape::OwnDeviationCoefficient(Standard_Real aCoefficient, Standard_Real aPreviousCoefficient) {
        return NativeHandle()->OwnDeviationCoefficient(aCoefficient, aPreviousCoefficient);
    };

    //! Returns   true and the values of the HLR deviation
    //! coefficient aCoefficient and the previous HLR
    //! deviation coefficient aPreviousCoefficient. If these
    //! values are not already set, false is returned.
    Standard_Boolean XAIS_Shape::OwnHLRDeviationCoefficient(Standard_Real aCoefficient, Standard_Real aPreviousCoefficient) {
        return NativeHandle()->OwnHLRDeviationCoefficient(aCoefficient, aPreviousCoefficient);
    };

    //! Returns true and the values of the deviation angle
    //! anAngle and the previous deviation angle aPreviousAngle.
    //! If these values are not already set, false is returned.
    Standard_Boolean XAIS_Shape::OwnDeviationAngle(Standard_Real anAngle, Standard_Real aPreviousAngle) {
        return NativeHandle()->OwnDeviationAngle(anAngle, aPreviousAngle);
    };

    //! Returns true and the values   of the HLR deviation
    //! angle anAngle and of the previous HLR deviation
    //! angle aPreviousAngle. If these values are not
    //! already set, false is returned.
    Standard_Boolean XAIS_Shape::OwnHLRDeviationAngle(Standard_Real anAngle, Standard_Real aPreviousAngle) {
        return NativeHandle()->OwnHLRDeviationAngle(anAngle, aPreviousAngle);
    };

    //! Sets the type of HLR algorithm used by the shape
    void XAIS_Shape::SetTypeOfHLR(XPrs3d_TypeOfHLR theTypeOfHLR) {
        return NativeHandle()->SetTypeOfHLR(safe_cast<Prs3d_TypeOfHLR>(theTypeOfHLR));
    };

    //! Gets the type of HLR algorithm
    XPrs3d_TypeOfHLR XAIS_Shape::TypeOfHLR() {
        return safe_cast<XPrs3d_TypeOfHLR>(NativeHandle()->TypeOfHLR());
    };

    //! Sets the color aColor in the reconstructed
    //! compound shape. Acts via the Drawer methods below on the appearance of:
    //! -   free boundaries:
    //! Prs3d_Drawer_FreeBoundaryAspect,
    //! -   isos: Prs3d_Drawer_UIsoAspect,
    //! Prs3dDrawer_VIsoAspect,
    //! -   shared boundaries:
    //! Prs3d_Drawer_UnFreeBoundaryAspect,
    //! -   shading: Prs3d_Drawer_ShadingAspect,
    //! -   visible line color in hidden line mode:
    //! Prs3d_Drawer_SeenLineAspect
    //! -   hidden line color in hidden line mode:
    //! Prs3d_Drawer_HiddenLineAspect.
    void XAIS_Shape::SetColor(XQuantity_Color^ theColor) {
        NativeHandle()->SetColor(theColor->GetColor());
    };

    //! Removes settings for color in the reconstructed compound shape.
    void XAIS_Shape::UnsetColor() {
        NativeHandle()->UnsetColor();
    };

    //! Sets the value aValue for line width in the reconstructed compound shape.
    //! Changes line aspects for lines presentation.
    void XAIS_Shape::SetWidth(const Standard_Real aValue) {
        NativeHandle()->SetWidth(aValue);
    };

    //! Removes the setting for line width in the reconstructed compound shape.
    void XAIS_Shape::UnsetWidth() {
        NativeHandle()->UnsetWidth();
    };

    //! Allows you to provide settings for the material aName
    //! in the reconstructed compound shape.
    void XAIS_Shape::SetMaterial(XGraphic3d_MaterialAspect^ aName) {
        NativeHandle()->SetMaterial(aName->GetMaterialAspect());
    };

    //! Removes settings for material in the reconstructed compound shape.
    void XAIS_Shape::UnsetMaterial() {
        NativeHandle()->UnsetMaterial();
    };

    //! Sets the value aValue for transparency in the reconstructed compound shape.
    //! Standard_Real aValue = 0.6
    void XAIS_Shape::SetTransparency(const Standard_Real aValue) {
        NativeHandle()->SetTransparency(aValue);
    };

    //! Removes the setting for transparency in the reconstructed compound shape.
    void XAIS_Shape::UnsetTransparency() {
        NativeHandle()->UnsetTransparency();
    };

    //! Constructs a bounding box with which to reconstruct
    //! compound topological shapes for presentation.
    Bnd_Box XAIS_Shape::BoundingBox() {
        return NativeHandle()->BoundingBox();
    };

    //! AIS_InteractiveObject defines another virtual method BoundingBox,
    //! which is not the same as above; keep it visible.
    //using AIS_InteractiveObject::BoundingBox;

    //! Returns the Color attributes of the shape accordingly to
    //! the current facing model;
    void XAIS_Shape::Color(XQuantity_Color^ aColor) {
        NativeHandle()->Color(aColor->GetColor());
    };

    //! Returns the NameOfMaterial attributes of the shape accordingly to
    //! the current facing model;
    XGraphic3d_NameOfMaterial XAIS_Shape::Material() {
        return safe_cast<XGraphic3d_NameOfMaterial>(NativeHandle()->Material());
    };

    //! Returns the transparency attributes of the shape accordingly to
    //! the current facing model;
    Standard_Real XAIS_Shape::Transparency() {
        return NativeHandle()->Transparency();
    };


  //! Return texture repeat UV values; (1, 1) by default.
    xgp_Pnt2d^ XAIS_Shape::TextureRepeatUV() {
        return gcnew xgp_Pnt2d(NativeHandle()->TextureRepeatUV());
    };

    //! Sets the number of occurrences of the texture on each face. The texture itself is parameterized in (0,1) by (0,1).
    //! Each face of the shape to be textured is parameterized in UV space (Umin,Umax) by (Vmin,Vmax).
    void XAIS_Shape::SetTextureRepeatUV(xgp_Pnt2d^ theRepeatUV) {
        NativeHandle()->SetTextureRepeatUV(theRepeatUV->GetPnt2d());
    };

    //! Return texture origin UV position; (0, 0) by default.
    xgp_Pnt2d^ XAIS_Shape::TextureOriginUV() {
        return gcnew xgp_Pnt2d(NativeHandle()->TextureOriginUV());
    };

    //! Use this method to change the origin of the texture.
    //! The texel (0,0) will be mapped to the surface (myUVOrigin.X(), myUVOrigin.Y()).
    void XAIS_Shape::SetTextureOriginUV(xgp_Pnt2d^ theOriginUV) {
        NativeHandle()->SetTextureOriginUV(theOriginUV->GetPnt2d());
    };

    //! Return scale factor for UV coordinates; (1, 1) by default.
    xgp_Pnt2d^ XAIS_Shape::TextureScaleUV() {
        return gcnew xgp_Pnt2d(NativeHandle()->TextureScaleUV());
    };

    //! Use this method to scale the texture (percent of the face).
    //! You can specify a scale factor for both U and V.
    //! Example: if you set ScaleU and ScaleV to 0.5 and you enable texture repeat,
    //!          the texture will appear twice on the face in each direction.
    void XAIS_Shape::SetTextureScaleUV(xgp_Pnt2d^ theScaleUV) {
        NativeHandle()->SetTextureScaleUV(theScaleUV->GetPnt2d());
    };

    //! Compute HLR presentation for specified shape.
    //! static 
    void XAIS_Shape::computeHlrPresentation(const Handle(Prs3d_Projector)& theProjector, Handle(Prs3d_Presentation)& thePrs, XTopoDS_Shape^ theShape, XPrs3d_Drawer^ theDrawer) {
        AIS_Shape::computeHlrPresentation(theProjector, thePrs, theShape->GetShape(), theDrawer->GetDrawer());
    };
}