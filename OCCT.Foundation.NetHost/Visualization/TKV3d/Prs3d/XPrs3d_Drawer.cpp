#include "XPrs3d_Drawer.h"

namespace TKV3d {

    //! Default constructor.
    XPrs3d_Drawer::XPrs3d_Drawer() {
        NativeHandle() = new Prs3d_Drawer();
        SetNativeHandle(NativeHandle());
    };

    //! Default constructor.
    XPrs3d_Drawer::XPrs3d_Drawer(Handle(Prs3d_Drawer) pos) {
        NativeHandle() = pos;
        SetNativeHandle(NativeHandle());
    };

    Handle(Prs3d_Drawer) XPrs3d_Drawer::GetDrawer() {
        return NativeHandle();
    };

    //! Sets the type of chordal deflection.
    //! This indicates whether the deflection value is absolute or relative to the size of the object.
    void XPrs3d_Drawer::SetTypeOfDeflection(XAspect_TypeOfDeflection theTypeOfDeflection) {
        NativeHandle()->SetTypeOfDeflection(safe_cast<Aspect_TypeOfDeflection>(theTypeOfDeflection));
    };

    //! Returns the type of chordal deflection.
    //! This indicates whether the deflection value is absolute or relative to the size of the object.
    XAspect_TypeOfDeflection XPrs3d_Drawer::TypeOfDeflection() {
        return safe_cast<XAspect_TypeOfDeflection>(NativeHandle()->TypeOfDeflection());
    };

    //! Returns true if the drawer has a type of deflection setting active.
    Standard_Boolean XPrs3d_Drawer::HasOwnTypeOfDeflection() {
        return NativeHandle()->HasOwnTypeOfDeflection();
    };

    //! Defines the maximal chordial deviation when drawing any curve.
    //! Even if the type of deviation is set to TOD_Relative, this value is used by: 
    //!   Prs3d_DeflectionCurve
    //!   Prs3d_WFDeflectionSurface
    //!   Prs3d_WFDeflectionRestrictedFace
    void XPrs3d_Drawer::SetMaximalChordialDeviation(const Standard_Real theChordialDeviation) {
        NativeHandle()->SetMaximalChordialDeviation(theChordialDeviation);
    };

    //! Returns the maximal chordal deviation. The default value is 0.1.
    //! Drawings of curves or patches are made with respect to an absolute maximal chordal deviation.
    Standard_Real XPrs3d_Drawer::MaximalChordialDeviation() {
        return NativeHandle()->MaximalChordialDeviation();
    };

    //! Returns true if the drawer has a maximal chordial deviation setting active.
    Standard_Boolean XPrs3d_Drawer::HasOwnMaximalChordialDeviation() {
        return NativeHandle()->HasOwnMaximalChordialDeviation();
    };

    //! Sets the type of HLR algorithm used by drawer's interactive objects
    void XPrs3d_Drawer::SetTypeOfHLR(const XPrs3d_TypeOfHLR theTypeOfHLR) {
        NativeHandle()->SetTypeOfHLR(safe_cast<Prs3d_TypeOfHLR>(theTypeOfHLR));
    };

    //! Returns the type of HLR algorithm currently in use.
    XPrs3d_TypeOfHLR XPrs3d_Drawer::TypeOfHLR() {
        return safe_cast<XPrs3d_TypeOfHLR>(NativeHandle()->TypeOfHLR());
    };

    //! Returns true if the type of HLR is not equal to Prs3d_TOH_NotSet.
    Standard_Boolean XPrs3d_Drawer::HasOwnTypeOfHLR() {
        return NativeHandle()->HasOwnTypeOfHLR();
    };

    //! Defines the maximum value allowed for the first and last
    //! parameters of an infinite curve.
    void XPrs3d_Drawer::SetMaximalParameterValue(const Standard_Real theValue) {
        NativeHandle()->SetMaximalParameterValue(theValue);
    };

    //! Sets the maximum value allowed for the first and last
    //! parameters of an infinite curve. By default, this value is 500000.
    Standard_Real XPrs3d_Drawer::MaximalParameterValue() {
        return NativeHandle()->MaximalParameterValue();
    };

    //! Returns true if the drawer has a maximum value allowed for the first and last
    //! parameters of an infinite curve setting active.
    Standard_Boolean XPrs3d_Drawer::HasOwnMaximalParameterValue() {
        return NativeHandle()->HasOwnMaximalParameterValue();
    };

    //! Sets IsoOnPlane on or off by setting the parameter theIsEnabled to true or false.
    void XPrs3d_Drawer::SetIsoOnPlane(const Standard_Boolean theIsEnabled) {
        NativeHandle()->SetIsoOnPlane(theIsEnabled);
    };

    //! Returns True if the drawing of isos on planes is enabled.
    Standard_Boolean XPrs3d_Drawer::IsoOnPlane() {
        return NativeHandle()->IsoOnPlane();
    };

    //! Returns true if the drawer has IsoOnPlane setting active.
    Standard_Boolean XPrs3d_Drawer::HasOwnIsoOnPlane() {
        return NativeHandle()->HasOwnIsoOnPlane();
    };

    //! Returns True if the drawing of isos on triangulation is enabled.
    Standard_Boolean XPrs3d_Drawer::IsoOnTriangulation() {
        return NativeHandle()->IsoOnTriangulation();
    };

    //! Returns true if the drawer has IsoOnTriangulation setting active.
    Standard_Boolean XPrs3d_Drawer::HasOwnIsoOnTriangulation() {
        return NativeHandle()->HasOwnIsoOnTriangulation();
    };

    //! Enables or disables isolines on triangulation by setting the parameter theIsEnabled to true or false.
    void XPrs3d_Drawer::SetIsoOnTriangulation(const Standard_Boolean theToEnable) {
        NativeHandle()->SetIsoOnTriangulation(theToEnable);
    };

    //! Sets the discretisation parameter theValue.
    void XPrs3d_Drawer::SetDiscretisation(const Standard_Integer theValue) {
        NativeHandle()->SetDiscretisation(theValue);
    };

    //! Returns the discretisation setting. 
    Standard_Integer XPrs3d_Drawer::Discretisation() {
        return NativeHandle()->Discretisation();
    };

    //! Returns true if the drawer has discretisation setting active.
    Standard_Boolean XPrs3d_Drawer::HasOwnDiscretisation() {
        return NativeHandle()->HasOwnDiscretisation();
    };

    //! Sets the deviation coefficient theCoefficient.
    //! Also sets the hasOwnDeviationCoefficient flag to Standard_True and myPreviousDeviationCoefficient
    void XPrs3d_Drawer::SetDeviationCoefficient(const Standard_Real theCoefficient) {
        NativeHandle()->SetDeviationCoefficient(theCoefficient);
    };

    //! Returns the deviation coefficient.
    //! Drawings of curves or patches are made with respect
    //! to a maximal chordal deviation. A Deviation coefficient
    //! is used in the shading display mode. The shape is
    //! seen decomposed into triangles. These are used to
    //! calculate reflection of light from the surface of the
    //! object. The triangles are formed from chords of the
    //! curves in the shape. The deviation coefficient gives
    //! the highest value of the angle with which a chord can
    //! deviate from a tangent to a   curve. If this limit is
    //! reached, a new triangle is begun.
    //! This deviation is absolute and is set through the
    //! method: SetMaximalChordialDeviation. The default value is 0.001.
    //! In drawing shapes, however, you are allowed to ask
    //! for a relative deviation. This deviation will be:
    //! SizeOfObject * DeviationCoefficient.
    Standard_Real XPrs3d_Drawer::DeviationCoefficient() {
        return NativeHandle()->DeviationCoefficient();
    };

    //! Sets the hasOwnDeviationCoefficient flag to Standard_False
    void XPrs3d_Drawer::SetDeviationCoefficient() {
        NativeHandle()->SetDeviationCoefficient();
    };

    //! Returns true if there is a local setting for deviation
    //! coefficient in this framework for a specific interactive object.
    Standard_Boolean XPrs3d_Drawer::HasOwnDeviationCoefficient() {
        return  NativeHandle()->HasOwnDeviationCoefficient();
    };

    //! Saves the previous value used for the chordal
    //! deviation coefficient. 
    Standard_Real XPrs3d_Drawer::PreviousDeviationCoefficient() {
        return  NativeHandle()->PreviousDeviationCoefficient();
    };

    //! Updates the previous value used for the chordal deviation coefficient to the current state.
    void XPrs3d_Drawer::UpdatePreviousDeviationCoefficient() {
        return  NativeHandle()->UpdatePreviousDeviationCoefficient();
    };

    //! Sets the deviation coefficient aCoefficient for removal
    //! of hidden lines created by different viewpoints in
    //! different presentations. The Default value is 0.02.
    //! Also sets the hasOwnHLRDeviationCoefficient flag to Standard_True and myPreviousHLRDeviationCoefficient
    void XPrs3d_Drawer::SetHLRDeviationCoefficient(const Standard_Real theCoefficient) {
        NativeHandle()->SetHLRDeviationCoefficient(theCoefficient);
    };

    //! Returns the real number value of the hidden line
    //! removal deviation coefficient in this framework, if the flag
    //! hasOwnHLRDeviationCoefficient is true or there is no Link.
    //! Else the shape's HLR deviation coefficient is used.
    //! A Deviation coefficient is used in the shading display
    //! mode. The shape is seen decomposed into triangles.
    //! These are used to calculate reflection of light from the
    //! surface of the object.
    //! The triangles are formed from chords of the curves in
    //! the shape. The deviation coefficient give the highest
    //! value of the angle with which a chord can deviate
    //! from a tangent to a curve. If this limit is reached, a new triangle is begun.
    //! To find the hidden lines, hidden line display mode
    //! entails recalculation of the view at each different projector perspective.
    //! Since hidden lines entail calculations of more than
    //! usual complexity to decompose them into these
    //! triangles, a deviation coefficient allowing greater
    //! tolerance is used. This increases efficiency in calculation.
    //! The Default value is 0.02.
    Standard_Real XPrs3d_Drawer::HLRDeviationCoefficient() {
        return  NativeHandle()->HLRDeviationCoefficient();
    };

    //! Sets the hasOwnHLRDeviationCoefficient flag to Standard_False 
    void XPrs3d_Drawer::SetHLRDeviationCoefficient() {
        NativeHandle()->SetHLRDeviationCoefficient();
    };

    //! Returns true if the there is a setting for HLR deviation
    //! coefficient in this framework for a specific interactive object.
    Standard_Boolean XPrs3d_Drawer::HasOwnHLRDeviationCoefficient() {
        return  NativeHandle()->HasOwnHLRDeviationCoefficient();
    };

    //! Returns the previous value of the hidden line removal deviation coefficient.
    Standard_Real XPrs3d_Drawer::PreviousHLRDeviationCoefficient() {
        return  NativeHandle()->PreviousHLRDeviationCoefficient();
    };

    //! Sets the deviation angle theAngle.
    //! Also sets the hasOwnDeviationAngle flag to Standard_True, and myPreviousDeviationAngle.
    void XPrs3d_Drawer::SetDeviationAngle(const Standard_Real theAngle) {
        NativeHandle()->SetDeviationAngle(theAngle);
    };

    //! Returns the value for deviation angle.
    Standard_Real XPrs3d_Drawer::DeviationAngle() {
        return  NativeHandle()->DeviationAngle();
    };

    //! Sets the hasOwnDeviationAngle flag to Standard_False
    void XPrs3d_Drawer::SetDeviationAngle() {
        NativeHandle()->SetDeviationAngle();
    };

    //! Returns true if the there is a local setting for deviation
    //! angle in this framework for a specific interactive object.
    Standard_Boolean XPrs3d_Drawer::HasOwnDeviationAngle() {
        return  NativeHandle()->HasOwnDeviationAngle();
    };

    //! Returns the previous deviation angle
    Standard_Real XPrs3d_Drawer::PreviousDeviationAngle() {
        return  NativeHandle()->PreviousDeviationAngle();
    };

    //! Updates the previous deviation angle to the current value
    void XPrs3d_Drawer::UpdatePreviousDeviationAngle() {
        NativeHandle()->UpdatePreviousDeviationAngle();
    };

    //! Sets anAngle, the angle of maximum chordal deviation for removal of hidden lines created by
    //! different viewpoints in different presentations.
    //! The default value is 20 * M_PI / 180.
    //! Also sets the hasOwnHLRDeviationAngle flag to Standard_True and myPreviousHLRDeviationAngle.
    void XPrs3d_Drawer::SetHLRAngle(const Standard_Real theAngle) {
        NativeHandle()->SetHLRAngle(theAngle);
    };

    //! Returns the real number value of the deviation angle
    //! in hidden line removal views. The default value is 20 * M_PI / 180.
    Standard_Real XPrs3d_Drawer::HLRAngle() {
        return  NativeHandle()->HLRAngle();
    };

    //! Sets the hasOwnHLRDeviationAngle flag to Standard_False
    void XPrs3d_Drawer::SetHLRAngle() {
        NativeHandle()->SetHLRAngle();
    };

    //! Returns true if the there is a setting for HLR deviation
    //! angle in this framework for a specific interactive object.
    Standard_Boolean XPrs3d_Drawer::HasOwnHLRDeviationAngle() {
        return  NativeHandle()->HasOwnHLRDeviationAngle();
    };

    //! Returns the previous value of the HLR deviation angle.
    Standard_Real XPrs3d_Drawer::PreviousHLRDeviationAngle() {
        return  NativeHandle()->PreviousHLRDeviationAngle();
    };

    //! Sets IsAutoTriangulated on or off by setting the parameter theIsEnabled to true or false.
    //! If this flag is True automatic re-triangulation with deflection-check logic will be applied.
    //! Else this feature will be disable and triangulation is expected to be computed by application itself
    //! and no shading presentation at all if unavailable.
    void XPrs3d_Drawer::SetAutoTriangulation(const Standard_Boolean theIsEnabled) {
        NativeHandle()->SetAutoTriangulation(theIsEnabled);
    };

    //! Returns True if automatic triangulation is enabled.
    Standard_Boolean XPrs3d_Drawer::IsAutoTriangulation() {
        return  NativeHandle()->IsAutoTriangulation();
    };

    //! Returns true if the drawer has IsoOnPlane setting active.
    Standard_Boolean XPrs3d_Drawer::HasOwnIsAutoTriangulation() {
        return  NativeHandle()->HasOwnIsAutoTriangulation();
    };

    //! Defines the attributes which are used when drawing an
    //! U isoparametric curve of a face. Defines the number
    //! of U isoparametric curves to be drawn for a single face.
    //! The LineAspect for U isoparametric lines can be edited
    //! (methods SetColor, SetTypeOfLine, SetWidth, SetNumber)
    //! The default values are:
    //!   COLOR       : Quantity_NOC_GRAY75
    //!   TYPE OF LINE: Aspect_TOL_SOLID
    //!   WIDTH       : 0.5
    //!
    //! These attributes are used by the following algorithms:
    //!   Prs3d_WFDeflectionSurface
    //!   Prs3d_WFDeflectionRestrictedFace
    Handle(Prs3d_IsoAspect) XPrs3d_Drawer::UIsoAspect() {
        return  NativeHandle()->UIsoAspect();
    };

    void XPrs3d_Drawer::SetUIsoAspect(const Handle(Prs3d_IsoAspect)& theAspect) {
        NativeHandle()->SetUIsoAspect(theAspect);
    };

    //! Returns true if the drawer has its own attribute for
    //! UIso aspect that overrides the one in the link.
    Standard_Boolean XPrs3d_Drawer::HasOwnUIsoAspect() {
        return  NativeHandle()->HasOwnUIsoAspect();
    };

    //! Defines the attributes which are used when drawing an
    //! V isoparametric curve of a face. Defines the number
    //! of V isoparametric curves to be drawn for a single face.
    //! The LineAspect for V isoparametric lines can be edited
    //! (methods SetColor, SetTypeOfLine, SetWidth, SetNumber)
    //! The default values are:
    //!   COLOR       : Quantity_NOC_GRAY82
    //!   TYPE OF LINE: Aspect_TOL_SOLID
    //!   WIDTH       : 0.5
    //!
    //! These attributes are used by the following algorithms:
    //!   Prs3d_WFDeflectionSurface
    //!   Prs3d_WFDeflectionRestrictedFace
    Handle(Prs3d_IsoAspect) XPrs3d_Drawer::VIsoAspect() {
        return  NativeHandle()->VIsoAspect();
    };

    //! Sets the appearance of V isoparameters - theAspect.
    void XPrs3d_Drawer::SetVIsoAspect(const Handle(Prs3d_IsoAspect)& theAspect) {
        NativeHandle()->SetVIsoAspect(theAspect);
    };

    //! Returns true if the drawer has its own attribute for
    //! VIso aspect that overrides the one in the link.
    Standard_Boolean XPrs3d_Drawer::HasOwnVIsoAspect() {
        return  NativeHandle()->HasOwnVIsoAspect();
    };

    //! Returns wire aspect settings.
    //! The LineAspect for the free boundaries can be edited.
    //! The default values are:
    //!   Color: Quantity_NOC_GREEN
    //!   Type of line: Aspect_TOL_SOLID
    //!   Width: 1.0
    //! These attributes are used by the algorithm Prs3d_WFShape.
    Handle(Prs3d_LineAspect) XPrs3d_Drawer::WireAspect() {
        return  NativeHandle()->WireAspect();
    };

    //! Sets the parameter theAspect for display of wires.
    void XPrs3d_Drawer::SetWireAspect(const Handle(Prs3d_LineAspect)& theAspect) {
        NativeHandle()->SetWireAspect(theAspect);
    };

    //! Returns true if the drawer has its own attribute for
    //! wire aspect that overrides the one in the link.
    Standard_Boolean XPrs3d_Drawer::HasOwnWireAspect() {
        return  NativeHandle()->HasOwnWireAspect();
    };

    //! Sets WireDraw on or off by setting the parameter theIsEnabled to true or false.
    void XPrs3d_Drawer::SetWireDraw(const Standard_Boolean theIsEnabled) {
        NativeHandle()->SetWireDraw(theIsEnabled);
    };

    //! Returns True if the drawing of the wire is enabled.
    Standard_Boolean XPrs3d_Drawer::WireDraw() {
        return  NativeHandle()->WireDraw();
    };

    //! Returns true if the drawer has its own attribute for
    //! "draw wires" flag that overrides the one in the link.
    Standard_Boolean XPrs3d_Drawer::HasOwnWireDraw() {
        return  NativeHandle()->HasOwnWireDraw();
    };

    //! Returns the point aspect setting. The default values are
    //!   Color: Quantity_NOC_YELLOW
    //!   Type of marker: Aspect_TOM_PLUS
    //!   Scale: 1.0
    //! These attributes are used by the algorithms Prs3d_Point.
    Handle(Prs3d_PointAspect) XPrs3d_Drawer::PointAspect() {
        return  NativeHandle()->PointAspect();
    };

    //! Sets the parameter theAspect for display attributes of points
    void XPrs3d_Drawer::SetPointAspect(const Handle(Prs3d_PointAspect)& theAspect) {
        NativeHandle()->SetPointAspect(theAspect);
    };

    //! Returns true if the drawer has its own attribute for
    //! point aspect that overrides the one in the link.
    Standard_Boolean XPrs3d_Drawer::HasOwnPointAspect() {
        return  NativeHandle()->HasOwnPointAspect();
    };

    //! Sets own point aspect.
    //! Returns FALSE if the drawer already has its own attribute for point aspect.
    //! theDefaults = Handle(Prs3d_Drawer)()
    Standard_Boolean XPrs3d_Drawer::SetupOwnPointAspect(XPrs3d_Drawer^ theDefaults) {
        return  NativeHandle()->SetupOwnPointAspect(theDefaults->GetDrawer());
    };

    //! Returns settings for line aspects.
    //! These settings can be edited. The default values are:
    //!   Color: Quantity_NOC_YELLOW
    //!   Type of line: Aspect_TOL_SOLID
    //!   Width: 1.0
    //! These attributes are used by the following algorithms:
    //!   Prs3d_Curve
    //!   Prs3d_Line
    //!   Prs3d_HLRShape
    Handle(Prs3d_LineAspect) XPrs3d_Drawer::LineAspect() {
        return  NativeHandle()->LineAspect();
    };

    //! Sets the parameter theAspect for display attributes of lines.
    void XPrs3d_Drawer::SetLineAspect(const Handle(Prs3d_LineAspect)& theAspect) {
        NativeHandle()->SetLineAspect(theAspect);
    };

    //! Returns true if the drawer has its own attribute for
    //! line aspect that overrides the one in the link.
    Standard_Boolean XPrs3d_Drawer::HasOwnLineAspect() {
        return  NativeHandle()->HasOwnLineAspect();
    };

    //! Sets own line aspects.
    //! Returns FALSE if own line aspect are already set.
    //! theDefaults = Handle(Prs3d_Drawer)()
    Standard_Boolean XPrs3d_Drawer::SetOwnLineAspects(XPrs3d_Drawer^ theDefaults) {
        return  NativeHandle()->SetOwnLineAspects(theDefaults->GetDrawer());
    };

    //! Sets own line aspects for datums.
    //! Returns FALSE if own line for datums are already set.
    //! theDefaults = Handle(Prs3d_Drawer)()
    Standard_Boolean XPrs3d_Drawer::SetOwnDatumAspects(XPrs3d_Drawer^ theDefaults) {
        return  NativeHandle()->SetOwnDatumAspects(theDefaults->GetDrawer());
    };

    //! Returns settings for text aspect.
    //! These settings can be edited. The default value is:
    //! - Color: Quantity_NOC_YELLOW
    Handle(Prs3d_TextAspect) XPrs3d_Drawer::TextAspect() {
        return NativeHandle()->TextAspect();
    };

    //! Sets the parameter theAspect for display attributes of text.
    void XPrs3d_Drawer::SetTextAspect(const Handle(Prs3d_TextAspect)& theAspect) {
        NativeHandle()->SetTextAspect(theAspect);
    };

    //! Returns true if the drawer has its own attribute for
    //! text aspect that overrides the one in the link.
    Standard_Boolean XPrs3d_Drawer::HasOwnTextAspect() {
        return NativeHandle()->HasOwnTextAspect();
    };

    //! Returns settings for shading aspects.
    //! These settings can be edited. The default values are:
    //! -   Color: Quantity_NOC_YELLOW
    //! -   Material: Graphic3d_NOM_BRASS
    //! Shading aspect is obtained through decomposition of
    //! 3d faces into triangles, each side of each triangle
    //! being a chord of the corresponding curved edge in the face.
    //! Reflection of light in each projector perspective is then calculated for each of the
    //! resultant triangular planes.
    Handle(Prs3d_ShadingAspect) XPrs3d_Drawer::ShadingAspect() {
        return NativeHandle()->ShadingAspect();
    };

    //! Sets the parameter theAspect for display attributes of shading.
    void XPrs3d_Drawer::SetShadingAspect(const Handle(Prs3d_ShadingAspect)& theAspect) {
        NativeHandle()->SetShadingAspect(theAspect);
    };

    //! Returns true if the drawer has its own attribute for
    //! shading aspect that overrides the one in the link.
    Standard_Boolean XPrs3d_Drawer::HasOwnShadingAspect() {
        return NativeHandle()->HasOwnShadingAspect();
    };

    //! Sets own shading aspect.
    //! Returns FALSE if the drawer already has its own attribute for shading aspect.
    //! theDefaults = Handle(Prs3d_Drawer)()
    Standard_Boolean XPrs3d_Drawer::SetupOwnShadingAspect(XPrs3d_Drawer^ theDefaults) {
        return NativeHandle()->SetupOwnShadingAspect(theDefaults->GetDrawer());
    };

    //! Returns settings for seen line aspects.
    //! These settings can be edited. The default values are:
    //!   Color: Quantity_NOC_YELLOW
    //!   Type of line: Aspect_TOL_SOLID
    //!   Width: 1.0
    Handle(Prs3d_LineAspect) XPrs3d_Drawer::SeenLineAspect() {
        return NativeHandle()->SeenLineAspect();
    };

    //! Sets the parameter theAspect for the display of seen lines in hidden line removal mode.
    void XPrs3d_Drawer::SetSeenLineAspect(const Handle(Prs3d_LineAspect)& theAspect) {
        NativeHandle()->SetSeenLineAspect(theAspect);
    };

    //! Returns true if the drawer has its own attribute for
    //! seen line aspect that overrides the one in the link.
    Standard_Boolean XPrs3d_Drawer::HasOwnSeenLineAspect() {
        return NativeHandle()->HasOwnSeenLineAspect();
    };

    //! Returns settings for the appearance of planes.
    Handle(Prs3d_PlaneAspect) XPrs3d_Drawer::PlaneAspect() {
        return NativeHandle()->PlaneAspect();
    };

    //! Sets the parameter theAspect for the display of planes. 
    void XPrs3d_Drawer::SetPlaneAspect(const Handle(Prs3d_PlaneAspect)& theAspect) {
        NativeHandle()->SetPlaneAspect(theAspect);
    };

    //! Returns true if the drawer has its own attribute for
    //! plane aspect that overrides the one in the link.
    Standard_Boolean XPrs3d_Drawer::HasOwnPlaneAspect() {
        return NativeHandle()->HasOwnPlaneAspect();
    };

    //! Returns the attributes for display of arrows.
    Handle(Prs3d_ArrowAspect) XPrs3d_Drawer::ArrowAspect() {
        return NativeHandle()->ArrowAspect();
    };

    //! Sets the parameter theAspect for display attributes of arrows.
    void XPrs3d_Drawer::SetArrowAspect(const Handle(Prs3d_ArrowAspect)& theAspect) {
        return NativeHandle()->SetArrowAspect(theAspect);
    };

    //! Returns true if the drawer has its own attribute for
    //! arrow aspect that overrides the one in the link.
    Standard_Boolean XPrs3d_Drawer::HasOwnArrowAspect() {
        return NativeHandle()->HasOwnArrowAspect();
    };

    //! Enables the drawing of an arrow at the end of each line.
    //! By default the arrows are not drawn.
    void XPrs3d_Drawer::SetLineArrowDraw(const Standard_Boolean theIsEnabled) {
        NativeHandle()->SetLineArrowDraw(theIsEnabled);
    };

    //! Returns True if drawing an arrow at the end of each edge is enabled
    //! and False otherwise (the default).
    Standard_Boolean XPrs3d_Drawer::LineArrowDraw() {
        return NativeHandle()->LineArrowDraw();
    };

    //! Returns true if the drawer has its own attribute for
    //! "draw arrow" flag that overrides the one in the link.
    Standard_Boolean XPrs3d_Drawer::HasOwnLineArrowDraw() {
        return NativeHandle()->HasOwnLineArrowDraw();
    };

    //! Returns settings for hidden line aspects.
    //! These settings can be edited. The default values are:
    //!   Color: Quantity_NOC_YELLOW
    //!   Type of line: Aspect_TOL_DASH
    //!   Width: 1.0
    Handle(Prs3d_LineAspect) XPrs3d_Drawer::HiddenLineAspect() {
        return NativeHandle()->HiddenLineAspect();
    };

    //! Sets the parameter theAspect for the display of hidden lines in hidden line removal mode.
    void XPrs3d_Drawer::SetHiddenLineAspect(const Handle(Prs3d_LineAspect)& theAspect) {
        NativeHandle()->SetHiddenLineAspect(theAspect);
    };

    //! Returns true if the drawer has its own attribute for
    //! hidden lines aspect that overrides the one in the link.
    Standard_Boolean XPrs3d_Drawer::HasOwnHiddenLineAspect() {
        return NativeHandle()->HasOwnHiddenLineAspect();
    };

    //! Returns Standard_True if the hidden lines are to be drawn.
    //! By default the hidden lines are not drawn.
    Standard_Boolean XPrs3d_Drawer::DrawHiddenLine() {
        return NativeHandle()->DrawHiddenLine();
    };

    //! Enables the DrawHiddenLine function.
    void XPrs3d_Drawer::EnableDrawHiddenLine() {
        NativeHandle()->EnableDrawHiddenLine();
    };

    //! Disables the DrawHiddenLine function.
    void XPrs3d_Drawer::DisableDrawHiddenLine() {
        NativeHandle()->DisableDrawHiddenLine();
    };

    //! Returns true if the drawer has its own attribute for
    //! "draw hidden lines" flag that overrides the one in the link.
    Standard_Boolean XPrs3d_Drawer::HasOwnDrawHiddenLine() {
        return NativeHandle()->HasOwnDrawHiddenLine();
    };

    //! Returns settings for the appearance of vectors.
    //! These settings can be edited. The default values are:
    //!   Color: Quantity_NOC_SKYBLUE
    //!   Type of line: Aspect_TOL_SOLID
    //!   Width: 1.0
    Handle(Prs3d_LineAspect) XPrs3d_Drawer::VectorAspect() {
        return NativeHandle()->VectorAspect();
    };

    //! Sets the modality theAspect for the display of vectors.
    void XPrs3d_Drawer::SetVectorAspect(const Handle(Prs3d_LineAspect)& theAspect) {
        NativeHandle()->SetVectorAspect(theAspect);
    };

    //! Returns true if the drawer has its own attribute for
    //! vector aspect that overrides the one in the link.
    Standard_Boolean XPrs3d_Drawer::HasOwnVectorAspect() {
        return NativeHandle()->HasOwnVectorAspect();
    };

    //! Sets the mode of visualization of vertices of a TopoDS_Shape instance.
    //! By default, only stand-alone vertices (not belonging topologically to an edge) are drawn,
    //! that corresponds to Prs3d_VDM_Standalone mode. 
    //! Switching to Prs3d_VDM_Standalone mode makes all shape's vertices visible.
    //! To inherit this parameter from the global drawer instance ("the link") when it is present,
    //! Prs3d_VDM_Inherited value should be used.
    void XPrs3d_Drawer::SetVertexDrawMode(XPrs3d_VertexDrawMode theMode) {
        NativeHandle()->SetVertexDrawMode(safe_cast<Prs3d_VertexDrawMode>(theMode));
    };

    //! Returns the current mode of visualization of vertices of a TopoDS_Shape instance.
    XPrs3d_VertexDrawMode XPrs3d_Drawer::VertexDrawMode() {
        return safe_cast<XPrs3d_VertexDrawMode>(NativeHandle()->VertexDrawMode());
    };

    //! Returns true if the vertex draw mode is not equal to <b>Prs3d_VDM_Inherited</b>. 
    //! This means that individual vertex draw mode value (i.e. not inherited from the global 
    //! drawer) is used for a specific interactive object.
    Standard_Boolean XPrs3d_Drawer::HasOwnVertexDrawMode() {
        return NativeHandle()->HasOwnVertexDrawMode();
    };

    //! Returns settings for the appearance of datums.
    //! These settings can be edited. The default values for the three axes are:
    //!   Color: Quantity_NOC_PEACHPUFF
    //!   Type of line: Aspect_TOL_SOLID
    //!   Width: 1.0
    Handle(Prs3d_DatumAspect) XPrs3d_Drawer::DatumAspect() {
        return NativeHandle()->DatumAspect();
    };

    //! Sets the modality theAspect for the display of datums.
    void XPrs3d_Drawer::SetDatumAspect(const Handle(Prs3d_DatumAspect)& theAspect) {
        NativeHandle()->SetDatumAspect(theAspect);
    };

    //! Returns true if the drawer has its own attribute for
    //! datum aspect that overrides the one in the link.
    Standard_Boolean XPrs3d_Drawer::HasOwnDatumAspect() {
        return NativeHandle()->HasOwnDatumAspect();
    };

    //! The LineAspect for the wire can be edited.
    //! The default values are:
    //!   Color: Quantity_NOC_ORANGE
    //!   Type of line: Aspect_TOL_SOLID
    //!   Width: 1.0
    //! These attributes are used by the algorithm Prs3d_WFShape.
    Handle(Prs3d_LineAspect) XPrs3d_Drawer::SectionAspect() {
        return NativeHandle()->SectionAspect();
    };

    //! Sets the parameter theAspect for display attributes of sections. 
    void XPrs3d_Drawer::SetSectionAspect(const Handle(Prs3d_LineAspect)& theAspect) {
        NativeHandle()->SetSectionAspect(theAspect);
    };

    //! Returns true if the drawer has its own attribute for
    //! section aspect that overrides the one in the link.
    Standard_Boolean XPrs3d_Drawer::HasOwnSectionAspect() {
        return NativeHandle()->HasOwnSectionAspect();
    };

    //! Sets the parameter theAspect for the display of free boundaries.
    //! The method sets aspect owned by the drawer that will be used during
    //! visualization instead of the one set in link.
    void XPrs3d_Drawer::SetFreeBoundaryAspect(const Handle(Prs3d_LineAspect)& theAspect) {
        NativeHandle()->SetFreeBoundaryAspect(theAspect);
    };

    //! Returns the values for presentation of free boundaries,
    //! in other words, boundaries which are not shared.
    //! The LineAspect for the  free boundaries can be edited.
    //! The default values are:
    //!   Color: Quantity_NOC_GREEN
    //!   Type of line: Aspect_TOL_SOLID
    //!   Width: 1.0
    //! These attributes are used by the algorithm Prs3d_WFShape
    Handle(Prs3d_LineAspect) XPrs3d_Drawer::FreeBoundaryAspect() {
        return NativeHandle()->FreeBoundaryAspect();
    };

    //! Returns true if the drawer has its own attribute for
    //! free boundaries aspect that overrides the one in the link.
    Standard_Boolean XPrs3d_Drawer::HasOwnFreeBoundaryAspect() {
        return NativeHandle()->HasOwnFreeBoundaryAspect();
    };

    //! Enables or disables drawing of free boundaries for shading presentations.
    //! The method sets drawing flag owned by the drawer that will be used during
    //! visualization instead of the one set in link.
    //! theIsEnabled is a boolean flag indicating whether the free boundaries should be
    //! drawn or not.
    void XPrs3d_Drawer::SetFreeBoundaryDraw(const Standard_Boolean theIsEnabled) {
        NativeHandle()->SetFreeBoundaryDraw(theIsEnabled);
    };

    //! Returns True if the drawing of the free boundaries is enabled
    //! True is the default setting.
    Standard_Boolean XPrs3d_Drawer::FreeBoundaryDraw() {
        return NativeHandle()->FreeBoundaryDraw();
    };

    //! Returns true if the drawer has its own attribute for
    //! "draw free boundaries" flag that overrides the one in the link.
    Standard_Boolean XPrs3d_Drawer::HasOwnFreeBoundaryDraw() {
        return NativeHandle()->HasOwnFreeBoundaryDraw();
    };

    //! Sets the parameter theAspect for the display of shared boundaries.
    //! The method sets aspect owned by the drawer that will be used during
    //! visualization instead of the one set in link.
    void XPrs3d_Drawer::SetUnFreeBoundaryAspect(const Handle(Prs3d_LineAspect)& theAspect) {
        NativeHandle()->SetUnFreeBoundaryAspect(theAspect);
    };

    //! Returns settings for shared boundary line aspects.
    //! The LineAspect for the unfree boundaries can be edited.
    //! The default values are:
    //! Color: Quantity_NOC_YELLOW
    //! Type of line: Aspect_TOL_SOLID
    //! Width: 1.
    //! These attributes are used by the algorithm Prs3d_WFShape
    Handle(Prs3d_LineAspect) XPrs3d_Drawer::UnFreeBoundaryAspect() {
        return NativeHandle()->UnFreeBoundaryAspect();
    };

    //! Returns true if the drawer has its own attribute for
    //! unfree boundaries aspect that overrides the one in the link.
    Standard_Boolean XPrs3d_Drawer::HasOwnUnFreeBoundaryAspect() {
        return NativeHandle()->HasOwnUnFreeBoundaryAspect();
    };

    //! Enables or disables drawing of shared boundaries for shading presentations.
    //! The method sets drawing flag owned by the drawer that will be used during
    //! visualization instead of the one set in link.
    //! theIsEnabled is a boolean flag indicating whether the shared boundaries should be drawn or not.
    void XPrs3d_Drawer::SetUnFreeBoundaryDraw(const Standard_Boolean theIsEnabled) {
        return NativeHandle()->SetUnFreeBoundaryDraw(theIsEnabled);
    };

    //! Returns True if the drawing of the shared boundaries is enabled.
    //! True is the default setting.
    Standard_Boolean XPrs3d_Drawer::UnFreeBoundaryDraw() {
        return NativeHandle()->UnFreeBoundaryDraw();
    };

    //! Returns true if the drawer has its own attribute for
    //! "draw shared boundaries" flag that overrides the one in the link.
    Standard_Boolean XPrs3d_Drawer::HasOwnUnFreeBoundaryDraw() {
        return NativeHandle()->HasOwnUnFreeBoundaryDraw();
    };

    //! Sets line aspect for face boundaries.
    //! The method sets line aspect owned by the drawer that will be used during
    //! visualization instead of the one set in link.
    //! theAspect is the line aspect that determines the look of the face boundaries.
    void XPrs3d_Drawer::SetFaceBoundaryAspect(XPrs3d_LineAspect^ theAspect) {
        NativeHandle()->SetFaceBoundaryAspect(theAspect->GetLineAspect());
    };

    //! Returns line aspect of face boundaries.
    XPrs3d_LineAspect^ XPrs3d_Drawer::FaceBoundaryAspect() {
        return gcnew XPrs3d_LineAspect(NativeHandle()->FaceBoundaryAspect());
    };

    //! Returns true if the drawer has its own attribute for
    //! face boundaries aspect that overrides the one in the link.
    Standard_Boolean XPrs3d_Drawer::HasOwnFaceBoundaryAspect() {
        return NativeHandle()->HasOwnFaceBoundaryAspect();
    };

    //! Sets own face boundary aspect.
    //! Returns FALSE if the drawer already has its own attribute for face boundary aspect.
    //! theDefaults = Handle(Prs3d_Drawer)()
    Standard_Boolean XPrs3d_Drawer::SetupOwnFaceBoundaryAspect(XPrs3d_Drawer^ theDefaults) {
        return NativeHandle()->SetupOwnFaceBoundaryAspect(theDefaults->GetDrawer());
    };

    //! Enables or disables face boundary drawing for shading presentations. 
    //! The method sets drawing flag owned by the drawer that will be used during
    //! visualization instead of the one set in link.
    //! theIsEnabled is a boolean flag indicating whether the face boundaries should be drawn or not.
    void XPrs3d_Drawer::SetFaceBoundaryDraw(const Standard_Boolean theIsEnabled) {
        NativeHandle()->SetFaceBoundaryDraw(theIsEnabled);
    };

    //! Checks whether the face boundary drawing is enabled or not.
    Standard_Boolean XPrs3d_Drawer::FaceBoundaryDraw() {
        return NativeHandle()->FaceBoundaryDraw();
    };

    //! Returns true if the drawer has its own attribute for
    //! "draw face boundaries" flag that overrides the one in the link.
    Standard_Boolean XPrs3d_Drawer::HasOwnFaceBoundaryDraw() {
        return NativeHandle()->HasOwnFaceBoundaryDraw();
    };

    //! Returns true if the drawer has its own attribute for face boundaries upper edge continuity class that overrides the one in the link.
    Standard_Boolean XPrs3d_Drawer::HasOwnFaceBoundaryUpperContinuity() {
        return NativeHandle()->HasOwnFaceBoundaryUpperContinuity();
    };

    //! Get the most edge continuity class; GeomAbs_CN by default (all edges).
    GeomAbs_Shape XPrs3d_Drawer::FaceBoundaryUpperContinuity() {
        return NativeHandle()->FaceBoundaryUpperContinuity();
    };

    //! Set the most edge continuity class for face boundaries.
    void XPrs3d_Drawer::SetFaceBoundaryUpperContinuity(GeomAbs_Shape theMostAllowedEdgeClass) {
        NativeHandle()->SetFaceBoundaryUpperContinuity(theMostAllowedEdgeClass);
    };

    //! Unset the most edge continuity class for face boundaries.
    void XPrs3d_Drawer::UnsetFaceBoundaryUpperContinuity() {
        NativeHandle()->UnsetFaceBoundaryUpperContinuity();
    };

    //! Returns settings for the appearance of dimensions. 
    Handle(Prs3d_DimensionAspect) XPrs3d_Drawer::DimensionAspect() {
        return NativeHandle()->DimensionAspect();
    };

    //! Sets the settings for the appearance of dimensions.
    //! The method sets aspect owned by the drawer that will be used during
    //! visualization instead of the one set in link.
    void XPrs3d_Drawer::SetDimensionAspect(const Handle(Prs3d_DimensionAspect)& theAspect) {
        NativeHandle()->SetDimensionAspect(theAspect);
    };

    //! Returns true if the drawer has its own attribute for
    //! the appearance of dimensions that overrides the one in the link.
    Standard_Boolean XPrs3d_Drawer::HasOwnDimensionAspect() {
        return NativeHandle()->HasOwnDimensionAspect();
    };

    //! Sets dimension length model units for computing of dimension presentation.
    //! The method sets value owned by the drawer that will be used during
    //! visualization instead of the one set in link.
    void XPrs3d_Drawer::SetDimLengthModelUnits(const TCollection_AsciiString& theUnits) {
        NativeHandle()->SetDimLengthModelUnits(theUnits);
    };

    //! Sets dimension angle model units for computing of dimension presentation.
    //! The method sets value owned by the drawer that will be used during
    //! visualization instead of the one set in link.
    void XPrs3d_Drawer::SetDimAngleModelUnits(const TCollection_AsciiString& theUnits) {
        NativeHandle()->SetDimAngleModelUnits(theUnits);
    };

    //! Returns length model units for the dimension presentation. 
    TCollection_AsciiString XPrs3d_Drawer::DimLengthModelUnits() {
        return NativeHandle()->DimLengthModelUnits();
    };

    //! Returns angle model units for the dimension presentation. 
    TCollection_AsciiString XPrs3d_Drawer::DimAngleModelUnits() {
        return NativeHandle()->DimAngleModelUnits();
    };

    //! Returns true if the drawer has its own attribute for
    //! dimension length model units that overrides the one in the link.
    Standard_Boolean XPrs3d_Drawer::HasOwnDimLengthModelUnits() {
        return NativeHandle()->HasOwnDimLengthModelUnits();
    };

    //! Returns true if the drawer has its own attribute for
    //! dimension angle model units that overrides the one in the link.
    Standard_Boolean XPrs3d_Drawer::HasOwnDimAngleModelUnits() {
        return NativeHandle()->HasOwnDimAngleModelUnits();
    };

    //! Sets length units in which value for dimension presentation is displayed.
    //! The method sets value owned by the drawer that will be used during
    //! visualization instead of the one set in link.
    void XPrs3d_Drawer::SetDimLengthDisplayUnits(const TCollection_AsciiString& theUnits) {
        NativeHandle()->SetDimLengthDisplayUnits(theUnits);
    };

    //! Sets angle units in which value for dimension presentation is displayed.
    //! The method sets value owned by the drawer that will be used during
    //! visualization instead of the one set in link.
    void XPrs3d_Drawer::SetDimAngleDisplayUnits(const TCollection_AsciiString& theUnits) {
        NativeHandle()->SetDimAngleDisplayUnits(theUnits);
    };

    //! Returns length units in which dimension presentation is displayed.
    TCollection_AsciiString XPrs3d_Drawer::DimLengthDisplayUnits() {
        return NativeHandle()->DimLengthDisplayUnits();
    };

    //! Returns angle units in which dimension presentation is displayed.
    TCollection_AsciiString XPrs3d_Drawer::DimAngleDisplayUnits() {
        return NativeHandle()->DimAngleDisplayUnits();
    };

    //! Returns true if the drawer has its own attribute for
    //! length units in which dimension presentation is displayed
    //! that overrides the one in the link.
    Standard_Boolean XPrs3d_Drawer::HasOwnDimLengthDisplayUnits() {
        return NativeHandle()->HasOwnDimLengthDisplayUnits();
    };

    //! Returns true if the drawer has its own attribute for
    //! angle units in which dimension presentation is displayed
    //! that overrides the one in the link.
    Standard_Boolean XPrs3d_Drawer::HasOwnDimAngleDisplayUnits() {
        return NativeHandle()->HasOwnDimAngleDisplayUnits();
    };

    //! Returns the drawer to which the current object references.
    XPrs3d_Drawer^ XPrs3d_Drawer::Link() {
        return gcnew XPrs3d_Drawer(NativeHandle()->Link());
    };

    //! Returns true if the current object has a link on the other drawer.
    Standard_Boolean XPrs3d_Drawer::HasLink() {
        return NativeHandle()->HasLink();
    };

    //! Sets theDrawer as a link to which the current object references.
    void XPrs3d_Drawer::Link(XPrs3d_Drawer^ theDrawer) {
        NativeHandle()->Link(theDrawer->GetDrawer());
    };

    //! Sets theDrawer as a link to which the current object references.
    void XPrs3d_Drawer::SetLink(XPrs3d_Drawer^ theDrawer) {
        NativeHandle()->SetLink(theDrawer->GetDrawer());
    };

    //! Removes local attributes. 
    void XPrs3d_Drawer::ClearLocalAttributes() {
        NativeHandle()->ClearLocalAttributes();
    };

    //! Assign shader program for specified type of primitives.
    //! @param theProgram new program to set (might be NULL)
    //! @param theAspect  the type of primitives
    //! @param theToOverrideDefaults if true then non-overridden attributes using defaults will be allocated and copied from the Link;
    //!                              otherwise, only already customized attributes will be changed
    //! @return TRUE if presentation should be recomputed after creating aspects not previously customized (if theToOverrideDefaults is also TRUE)
    //! theToOverrideDefaults = false
    bool XPrs3d_Drawer::SetShaderProgram(const Handle(Graphic3d_ShaderProgram)& theProgram, Graphic3d_GroupAspect theAspect, bool theToOverrideDefaults) {
        return NativeHandle()->SetShaderProgram(theProgram, theAspect, theToOverrideDefaults);
    };

    //! Sets Shading Model type for the shading aspect.
    //! theToOverrideDefaults = false
    bool XPrs3d_Drawer::SetShadingModel(XGraphic3d_TypeOfShadingModel theModel, bool theToOverrideDefaults) {
        return NativeHandle()->SetShadingModel(safe_cast<Graphic3d_TypeOfShadingModel>(theModel), theToOverrideDefaults);
    };

    //! Dumps the content of me into the stream
    //! theDepth = -1
    void XPrs3d_Drawer::DumpJson(Standard_OStream& theOStream, Standard_Integer theDepth) {
        NativeHandle()->DumpJson(theOStream, theDepth);
    };
}