#include <XV3d_Viewer.h>

namespace TKV3d {
    //! Create a Viewer with the given graphic driver and with default parameters:
    //! - View orientation: V3d_XposYnegZpos
    //! - View background: Quantity_NOC_GRAY30
    //! - Shading model: V3d_GOURAUD
    XV3d_Viewer::XV3d_Viewer(Handle(Graphic3d_GraphicDriver)& theDriver) {
        NativeHandle() = new V3d_Viewer(theDriver);
    };

    XV3d_Viewer::XV3d_Viewer(Handle(V3d_Viewer) pos) {
        NativeHandle() = pos;
    };

    void XV3d_Viewer::SetViewerHandle(Handle(V3d_Viewer) pos) {
        NativeHandle() = pos;
    };

    Handle(V3d_Viewer) XV3d_Viewer::GetViewer() {
        return NativeHandle();
    };

    //! Returns True if One View more can be defined in this Viewer.
    Standard_Boolean XV3d_Viewer::IfMoreViews() {
        return NativeHandle()->IfMoreViews();
    };

    //! Creates a view in the viewer according to its default parameters.
    XV3d_View^ XV3d_Viewer::CreateView() {
        return gcnew XV3d_View(NativeHandle()->CreateView());
    };

    //! Activates all of the views of a viewer attached to a window.
    void XV3d_Viewer::SetViewOn() {
        NativeHandle()->SetViewOn();
    };

    //! Activates a particular view in the Viewer.
    //! Must be call if the Window attached to the view has been Deiconified.
    void XV3d_Viewer::SetViewOn(XV3d_View^ theView) {
        NativeHandle()->SetViewOn(theView->GetView());
    };

    //! Deactivates all the views of a Viewer
    //! attached to a window.
    void XV3d_Viewer::SetViewOff() {
        NativeHandle()->SetViewOff();
    };

    //! Deactivates a particular view in the Viewer.
    //! Must be call if the Window attached to the view
    //! has been Iconified .
    void XV3d_Viewer::SetViewOff(XV3d_View^ theView) {
        NativeHandle()->SetViewOff(theView->GetView());
    };

    //! Deprecated, Redraw() should be used instead.
    void XV3d_Viewer::Update() {
        Redraw();
    };// { Redraw(); }

    //! Redraws all the views of the Viewer even if no
    //! modification has taken place. Must be called if
    //! all the views of the Viewer are exposed, as for
    //! example in a global DeIconification.
    void XV3d_Viewer::Redraw() {
        NativeHandle()->Redraw();
    };

    //! Updates layer of immediate presentations.
    void XV3d_Viewer::RedrawImmediate() {
        NativeHandle()->RedrawImmediate();
    };

    //! Invalidates viewer content but does not redraw it.
    void XV3d_Viewer::Invalidate() {
        NativeHandle()->Invalidate();
    };

    //! Suppresses the Viewer.
    void XV3d_Viewer::Remove() {
        NativeHandle()->Remove();
    };

    //! Return Graphic Driver instance.
    Handle(Graphic3d_GraphicDriver) XV3d_Viewer::Driver() {
        return NativeHandle()->Driver();
    };// { return myDriver; }

    //! Returns the structure manager associated to this viewer.
    Handle(Graphic3d_StructureManager) XV3d_Viewer::StructureManager() {
        return NativeHandle()->StructureManager();
    };// { return myStructureManager; }

    //! Return default Rendering Parameters.
    //! By default these parameters are set in a new V3d_View.
    Graphic3d_RenderingParams XV3d_Viewer::DefaultRenderingParams() {
        return NativeHandle()->DefaultRenderingParams();
    };// { return myDefaultRenderingParams; }

    //! Set default Rendering Parameters.
    void XV3d_Viewer::SetDefaultRenderingParams(Graphic3d_RenderingParams& theParams) {
        NativeHandle()->SetDefaultRenderingParams(theParams);
    };// { myDefaultRenderingParams = theParams; }

    //! Defines the default background colour of views
    //! attached to the viewer by supplying the color object
    void XV3d_Viewer::SetDefaultBackgroundColor(XQuantity_Color^ theColor) {
        NativeHandle()->SetDefaultBackgroundColor(*theColor->GetColor());
    };// { myBackground.SetColor(theColor); }

    //! Returns the gradient background of the view.
    Aspect_GradientBackground XV3d_Viewer::GetGradientBackground() {
        return  NativeHandle()->GetGradientBackground();
    };// { return myGradientBackground; }

    //! Defines the default gradient background colours of views
    //! attached to the viewer by supplying the colour objects
    //! Aspect_GradientFillMethod theFillStyle = Aspect_GFM_HOR
    void XV3d_Viewer::SetDefaultBgGradientColors(XQuantity_Color^ theColor1, XQuantity_Color^ theColor2, XAspect_GradientFillMethod theFillStyle) {
        NativeHandle()->SetDefaultBgGradientColors(*theColor1->GetColor(), *theColor2->GetColor(), safe_cast<Aspect_GradientFillMethod>(theFillStyle));
    };

    //! Returns the default size of the view.
    Standard_Real XV3d_Viewer::DefaultViewSize() {
        return  NativeHandle()->DefaultViewSize();
    };// { return myViewSize; }

    //! Gives a default size for the creation of views of the viewer.
    void XV3d_Viewer::SetDefaultViewSize(Standard_Real theSize) {
        NativeHandle()->SetDefaultViewSize(theSize);
    };

    //! Returns the default Projection.
    XV3d_TypeOfOrientation XV3d_Viewer::DefaultViewProj() {
        return safe_cast<XV3d_TypeOfOrientation>(NativeHandle()->DefaultViewProj());
    };// { return myViewProj; }

    //! Sets the default projection for creating views in the viewer.
    void XV3d_Viewer::SetDefaultViewProj(XV3d_TypeOfOrientation theOrientation) {
        NativeHandle()->SetDefaultViewProj(safe_cast<V3d_TypeOfOrientation>(theOrientation));
    };// { myViewProj = theOrientation; }

    //! Returns the default type of Visualization.
    XV3d_TypeOfVisualization XV3d_Viewer::DefaultVisualization() {
        return safe_cast<XV3d_TypeOfVisualization>(NativeHandle()->DefaultVisualization());
    };// { return myVisualization; }

    //! Gives the default visualization mode.
    void XV3d_Viewer::SetDefaultVisualization(XV3d_TypeOfVisualization theType) {
        return  NativeHandle()->SetDefaultVisualization(safe_cast<V3d_TypeOfVisualization>(theType));
    };// { myVisualization = theType; }

    //! Returns the default type of Shading
    XGraphic3d_TypeOfShadingModel XV3d_Viewer::DefaultShadingModel() {
        return safe_cast<XGraphic3d_TypeOfShadingModel>(NativeHandle()->DefaultShadingModel());
    };// { return myShadingModel; }

    //! Gives the default type of SHADING.
    void XV3d_Viewer::SetDefaultShadingModel(XGraphic3d_TypeOfShadingModel theType) {
        NativeHandle()->SetDefaultShadingModel(safe_cast<Graphic3d_TypeOfShadingModel>(theType));
    };// { myShadingModel = theType; }

    //! Returns the default type of View (orthographic or perspective projection) to be returned by CreateView() method.
    XV3d_TypeOfView XV3d_Viewer::DefaultTypeOfView() {
        return safe_cast<XV3d_TypeOfView>(NativeHandle()->DefaultTypeOfView());
    };// { return myDefaultTypeOfView; }

    //! Set the default type of View (orthographic or perspective projection) to be returned by CreateView() method.
    void XV3d_Viewer::SetDefaultTypeOfView(XV3d_TypeOfView theType) {
        NativeHandle()->SetDefaultTypeOfView(safe_cast<V3d_TypeOfView>(theType));
    };// { myDefaultTypeOfView = theType; }

    //! Returns the default background colour object.
    XQuantity_Color^ XV3d_Viewer::DefaultBackgroundColor() {
        Quantity_Color* temp = new Quantity_Color(NativeHandle()->DefaultBackgroundColor());
        return gcnew XQuantity_Color(temp);
    };// { return myBackground.Color(); }

    //! Returns the gradient background colour objects of the view.
    void XV3d_Viewer::DefaultBgGradientColors(XQuantity_Color^ theColor1, XQuantity_Color^ theColor2) {
        NativeHandle()->DefaultBgGradientColors(*theColor1->GetColor(), *theColor2->GetColor());
    };// { myGradientBackground.Colors(theColor1, theColor2); }

    //! Return all Z layer ids in sequence ordered by overlay level from lowest layer to highest ( foreground ).
    //! The first layer ID in sequence is the default layer that can't be removed.
    void XV3d_Viewer::GetAllZLayers(TColStd_SequenceOfInteger& theLayerSeq) {
        NativeHandle()->GetAllZLayers(theLayerSeq);
    };

    //! Add a new top-level Z layer to all managed views and get its ID as <theLayerId> value.
    //! The Z layers are controlled entirely by viewer, it is not possible to add a layer to a particular view.
    //! Custom layers will be inserted before Graphic3d_ZLayerId_Top (e.g. between Graphic3d_ZLayerId_Default and before Graphic3d_ZLayerId_Top).
    //! @param theLayerId [out] id of created layer
    //! @param theSettings [in] new layer settings
    //! @return FALSE if the layer can not be created
    //! Graphic3d_ZLayerSettings& theSettings = Graphic3d_ZLayerSettings()
    Standard_Boolean XV3d_Viewer::AddZLayer(Graphic3d_ZLayerId& theLayerId, Graphic3d_ZLayerSettings& theSettings) {
        return NativeHandle()->AddZLayer(theLayerId, theSettings);
    };

    //! Add a new top-level Z layer to all managed views and get its ID as <theLayerId> value.
    //! The Z layers are controlled entirely by viewer, it is not possible to add a layer to a particular view.
    //! Layer rendering order is defined by its position in list (altered by theLayerAfter)
    //! and IsImmediate() flag (all layers with IsImmediate() flag are drawn afterwards);
    //! @param theNewLayerId [out] id of created layer; layer id is arbitrary and does not depend on layer position in the list
    //! @param theSettings    [in] new layer settings
    //! @param theLayerAfter  [in] id of layer to append new layer before
    //! @return FALSE if the layer can not be created
    Standard_Boolean XV3d_Viewer::InsertLayerBefore(Graphic3d_ZLayerId& theNewLayerId, Graphic3d_ZLayerSettings& theSettings, Graphic3d_ZLayerId theLayerAfter) {
        return NativeHandle()->InsertLayerBefore(theNewLayerId, theSettings, theLayerAfter);
    };

    //! Add a new top-level Z layer to all managed views and get its ID as <theLayerId> value.
    //! The Z layers are controlled entirely by viewer, it is not possible to add a layer to a particular view.
    //! Layer rendering order is defined by its position in list (altered by theLayerAfter)
    //! and IsImmediate() flag (all layers with IsImmediate() flag are drawn afterwards);
    //! @param theNewLayerId [out] id of created layer; layer id is arbitrary and does not depend on layer position in the list
    //! @param theSettings    [in] new layer settings
    //! @param theLayerBefore [in] id of layer to append new layer after
    //! @return FALSE if the layer can not be created
    Standard_Boolean XV3d_Viewer::InsertLayerAfter(Graphic3d_ZLayerId& theNewLayerId, Graphic3d_ZLayerSettings& theSettings, Graphic3d_ZLayerId theLayerBefore) {
        return NativeHandle()->InsertLayerAfter(theNewLayerId, theSettings, theLayerBefore);
    };

    //! Remove Z layer with ID <theLayerId>.
    //! Method returns Standard_False if the layer can not be removed or doesn't exists.
    //! By default, there are always default bottom-level layer that can't be removed.
    Standard_Boolean XV3d_Viewer::RemoveZLayer(Graphic3d_ZLayerId theLayerId) {
        return NativeHandle()->RemoveZLayer(theLayerId);
    };

    //! Returns the settings of a single Z layer.
    Graphic3d_ZLayerSettings XV3d_Viewer::ZLayerSettings(Graphic3d_ZLayerId theLayerId) {
        return NativeHandle()->ZLayerSettings(theLayerId);
    };

    //! Sets the settings for a single Z layer.
    void XV3d_Viewer::SetZLayerSettings(Graphic3d_ZLayerId theLayerId, Graphic3d_ZLayerSettings& theSettings) {
        NativeHandle()->SetZLayerSettings(theLayerId, theSettings);
    };

    //! Return an iterator for active views.
    V3d_ListOfViewIterator XV3d_Viewer::ActiveViewIterator() {
        return NativeHandle()->ActiveViewIterator();
    };// { return V3d_ListOfViewIterator(myActiveViews); }

    //! Initializes an internal iterator on the active views.
    //void XV3d_Viewer::InitActiveViews() {
    //    NativeHandle()->InitActiveViews();
    //};// { myActiveViewsIterator.Initialize(myActiveViews); }

    //! Returns true if there are more active view(s) to return.
    //Standard_Boolean XV3d_Viewer::MoreActiveViews() {
    //    return NativeHandle()->MoreActiveViews();
    //};// { return myActiveViewsIterator.More(); }

    //! Go to the next active view (if there is not, ActiveView will raise an exception)
    //void XV3d_Viewer::NextActiveViews() {
    //    NativeHandle()->NextActiveViews();
    //};// { if (!myActiveViews.IsEmpty()) myActiveViewsIterator.Next(); }

    V3d_ListOfView XV3d_Viewer::ActiveViews() {
        return NativeHandle()->ActiveViews();
    };// { return myActiveViewsIterator.Value(); }

    //! returns true if there is only one active view.
    Standard_Boolean XV3d_Viewer::LastActiveView() {
        return NativeHandle()->LastActiveView();
    };// { return myActiveViews.Extent() == 1; }


    //! Return an iterator for defined views.
    V3d_ListOfViewIterator XV3d_Viewer::DefinedViewIterator() {
        return NativeHandle()->DefinedViewIterator();
    };// { return V3d_ListOfViewIterator(myDefinedViews); }

    //! Initializes an internal iterator on the Defined views.
    //void XV3d_Viewer::InitDefinedViews() {
    //    NativeHandle()->InitDefinedViews();
    //};// { myDefinedViewsIterator.Initialize(myDefinedViews); }

    //! returns true if there are more Defined view(s) to return.
    //Standard_Boolean XV3d_Viewer::MoreDefinedViews() {
    //    return NativeHandle()->MoreDefinedViews();
    //};// { return myDefinedViewsIterator.More(); }

    //! Go to the next Defined view (if there is not, DefinedView will raise an exception)
    //void XV3d_Viewer::NextDefinedViews() {
    //    NativeHandle()->NextDefinedViews();
    //};// { if (!myDefinedViews.IsEmpty()) myDefinedViewsIterator.Next(); }

    V3d_ListOfView XV3d_Viewer::DefinedViews() {
        return NativeHandle()->DefinedViews();
    };// { return myDefinedViewsIterator.Value(); }

    //! @name lights management

    //! Defines default lights:
    //!  positional-light 0.3 0. 0.
    //!  directional-light V3d_XnegYposZpos
    //!  directional-light V3d_XnegYneg
    //!  ambient-light
    void XV3d_Viewer::SetDefaultLights() {
        NativeHandle()->SetDefaultLights();
    };

    //! Activates MyLight in the viewer.
    void XV3d_Viewer::SetLightOn(Handle(V3d_Light)& theLight) {
        NativeHandle()->SetLightOn(theLight);
    };

    //! Activates all the lights defined in this viewer.
    void XV3d_Viewer::SetLightOn() {
        NativeHandle()->SetLightOn();
    };

    //! Deactivates MyLight in this viewer.
    void XV3d_Viewer::SetLightOff(Handle(V3d_Light)& theLight) {
        NativeHandle()->SetLightOff(theLight);
    };

    //! Deactivate all the Lights defined in this viewer.
    void XV3d_Viewer::SetLightOff() {
        NativeHandle()->SetLightOff();
    };

    //! Adds Light in Sequence Of Lights.
    void XV3d_Viewer::AddLight(Handle(V3d_Light)& theLight) {
        NativeHandle()->AddLight(theLight);
    };

    //! Delete Light in Sequence Of Lights.
    void XV3d_Viewer::DelLight(Handle(V3d_Light)& theLight) {
        NativeHandle()->DelLight(theLight);
    };

    //! Updates the lights of all the views of a viewer.
    void XV3d_Viewer::UpdateLights() {
        NativeHandle()->UpdateLights();
    };

    Standard_Boolean XV3d_Viewer::IsGlobalLight(Handle(V3d_Light)& TheLight) {
        return NativeHandle()->IsGlobalLight(TheLight);
    };

    //! Return an iterator for defined lights.
    V3d_ListOfLightIterator XV3d_Viewer::ActiveLightIterator() {
        return NativeHandle()->ActiveLightIterator();
    };// { return V3d_ListOfLightIterator(myActiveLights); }

    //! Initializes an internal iteratator on the active Lights.
    //void XV3d_Viewer::InitActiveLights() {
    //    NativeHandle()->InitActiveLights();
    //};// { myActiveLightsIterator.Initialize(myActiveLights); }

    //! returns true if there are more active Light(s) to return.
    //Standard_Boolean XV3d_Viewer::MoreActiveLights() {
    //    return NativeHandle()->MoreActiveLights();
    //};// { return myActiveLightsIterator.More(); }

    //! Go to the next active Light (if there is not, ActiveLight() will raise an exception)
    //void XV3d_Viewer::NextActiveLights() {
    //    NativeHandle()->NextActiveLights();
    //};// { myActiveLightsIterator.Next(); }

    V3d_ListOfLight XV3d_Viewer::ActiveLights() {
        return NativeHandle()->ActiveLights();
    };// { return myActiveLightsIterator.Value(); }

    //! Return an iterator for defined lights.
    V3d_ListOfLightIterator XV3d_Viewer::DefinedLightIterator() {
        return NativeHandle()->DefinedLightIterator();
    };// { return V3d_ListOfLightIterator(myDefinedLights); }

    //! Initializes an internal iterattor on the Defined Lights.
    //void XV3d_Viewer::InitDefinedLights() {
    //    NativeHandle()->InitDefinedLights();
    //};// { myDefinedLightsIterator.Initialize(myDefinedLights); }

    //! Returns true if there are more Defined Light(s) to return.
    //Standard_Boolean XV3d_Viewer::MoreDefinedLights() {
    //    return NativeHandle()->MoreDefinedLights();
    //};// { return myDefinedLightsIterator.More(); }

    //! Go to the next Defined Light (if there is not, DefinedLight() will raise an exception)
    //void XV3d_Viewer::NextDefinedLights() {
    //    NativeHandle()->NextDefinedLights();
    //};// { if (!myDefinedLights.IsEmpty()) myDefinedLightsIterator.Next(); }

    V3d_ListOfLight XV3d_Viewer::DefinedLights() {
        return NativeHandle()->DefinedLights();
    };// { return myDefinedLightsIterator.Value(); }

    //! @name objects management

    //! Erase all Objects in All the views.
    void XV3d_Viewer::Erase() {
        NativeHandle()->Erase();
    };

    //! UnHighlight all Objects in All the views.
    void XV3d_Viewer::UnHighlight() {
        NativeHandle()->UnHighlight();
    };


    //! returns true if the computed mode can be used.
    Standard_Boolean XV3d_Viewer::ComputedMode() {
        return NativeHandle()->ComputedMode();
    };// { return myComputedMode; }

    //! Set if the computed mode can be used.
    void XV3d_Viewer::SetComputedMode(Standard_Boolean theMode) {
        NativeHandle()->SetComputedMode(theMode);
    };// { myComputedMode = theMode; }

    //! returns true if by default the computed mode must be used.
    Standard_Boolean XV3d_Viewer::DefaultComputedMode() {
        return NativeHandle()->DefaultComputedMode();
    };// { return myDefaultComputedMode; }

    //! Set if by default the computed mode must be used.
    void XV3d_Viewer::SetDefaultComputedMode(Standard_Boolean theMode) {
        NativeHandle()->SetDefaultComputedMode(theMode);
    };// { myDefaultComputedMode = theMode; }

    //! @name privileged plane management

    xgp_Ax3^ XV3d_Viewer::PrivilegedPlane() {
        gp_Ax3* temp = new gp_Ax3(NativeHandle()->PrivilegedPlane());
        return gcnew xgp_Ax3(temp);
    };// { return myPrivilegedPlane; }

    void XV3d_Viewer::SetPrivilegedPlane(xgp_Ax3^ thePlane) {
        NativeHandle()->SetPrivilegedPlane(*thePlane->GetAx3());
    };

    //Standard_Real theSize = 1
    void XV3d_Viewer::DisplayPrivilegedPlane(Standard_Boolean theOnOff, Standard_Real theSize) {
        NativeHandle()->DisplayPrivilegedPlane(theOnOff, theSize);
    };

    //! @name grid management

    //! Activates the grid in all views of <me>.
    void XV3d_Viewer::ActivateGrid(XAspect_GridType aGridType, XAspect_GridDrawMode aGridDrawMode) {
        NativeHandle()->ActivateGrid(safe_cast<Aspect_GridType>(aGridType), safe_cast<Aspect_GridDrawMode>(aGridDrawMode));
    };

    //! Deactivates the grid in all views of <me>.
    void XV3d_Viewer::DeactivateGrid() {
        NativeHandle()->DeactivateGrid();
    };

    //! Show/Don't show grid echo to the hit point.
    //! If TRUE,the grid echo will be shown at ConvertToGrid() time.
    //! Standard_Boolean showGrid = Standard_True
    void XV3d_Viewer::SetGridEcho(Standard_Boolean showGrid) {
        NativeHandle()->SetGridEcho(showGrid);
    };

    //! Show grid echo <aMarker> to the hit point.
    //! Warning: When the grid echo marker is not set,
    //! a default marker is build with the attributes:
    //! marker type : Aspect_TOM_STAR
    //! marker color : Quantity_NOC_GRAY90
    //! marker size : 3.0
    void XV3d_Viewer::SetGridEcho(Handle(Graphic3d_AspectMarker3d)& aMarker) {
        NativeHandle()->SetGridEcho(aMarker);
    };

    //! Returns TRUE when grid echo must be displayed at hit point.
    Standard_Boolean XV3d_Viewer::GridEcho() {
        return NativeHandle()->GridEcho();
    };// { return myGridEcho; }

    //! Returns Standard_True if a grid is activated in <me>.
    Standard_Boolean XV3d_Viewer::IsActive() {
        return NativeHandle()->IsActive();
    };

    //! Returns the defined grid in <me>.
    Handle(Aspect_Grid) XV3d_Viewer::Grid() {
        return NativeHandle()->Grid();
    };

    //! Returns the current grid type defined in <me>.
    XAspect_GridType XV3d_Viewer::GridType() {
        return safe_cast<XAspect_GridType>(NativeHandle()->GridType());
    };// { return myGridType; }

    //! Returns the current grid draw mode defined in <me>.
    XAspect_GridDrawMode XV3d_Viewer::GridDrawMode() {
        return safe_cast<XAspect_GridDrawMode>(NativeHandle()->GridDrawMode());
    };

    //! Returns the definition of the rectangular grid.
    void XV3d_Viewer::RectangularGridValues(Standard_Real% XOrigin, Standard_Real% YOrigin, Standard_Real% XStep, Standard_Real% YStep, Standard_Real% RotationAngle) {
        Standard_Real SXOrigin(XOrigin); Standard_Real SYOrigin(YOrigin); Standard_Real SXStep(XStep); Standard_Real SYStep(YStep); Standard_Real SRotationAngle(RotationAngle);
        NativeHandle()->RectangularGridValues(SXOrigin, SYOrigin, SXStep, SYStep, SRotationAngle);
        XOrigin = SXOrigin; YOrigin = SYOrigin; XStep = SXStep; YStep = SYStep; RotationAngle = SRotationAngle;
    };

    //! Sets the definition of the rectangular grid.
    //! <XOrigin>, <YOrigin> defines the origin of the grid.
    //! <XStep> defines the interval between 2 vertical lines.
    //! <YStep> defines the interval between 2 horizontal lines.
    //! <RotationAngle> defines the rotation angle of the grid.
    void XV3d_Viewer::SetRectangularGridValues(Standard_Real XOrigin, Standard_Real YOrigin, Standard_Real XStep, Standard_Real YStep, Standard_Real RotationAngle) {
        NativeHandle()->SetRectangularGridValues(XOrigin, YOrigin, XStep, YStep, RotationAngle);
    };

    //! Returns the definition of the circular grid.
    void XV3d_Viewer::CircularGridValues(Standard_Real% XOrigin, Standard_Real% YOrigin, Standard_Real% RadiusStep, Standard_Integer% DivisionNumber, Standard_Real% RotationAngle) {
        Standard_Real SXOrigin(XOrigin); Standard_Real SYOrigin(YOrigin); Standard_Real SRadiusStep(RadiusStep); Standard_Integer SDivisionNumber(DivisionNumber); Standard_Real SRotationAngle(RotationAngle);
        NativeHandle()->CircularGridValues(SXOrigin, SYOrigin, SRadiusStep, SDivisionNumber, SRotationAngle);
        XOrigin = SXOrigin; YOrigin = SYOrigin; RadiusStep = SRadiusStep; DivisionNumber = SDivisionNumber; RotationAngle = SRotationAngle;
    };

    //! Sets the definition of the circular grid.
    //! <XOrigin>, <YOrigin> defines the origin of the grid.
    //! <RadiusStep> defines the interval between 2 circles.
    //! <DivisionNumber> defines the section number of one half circle.
    //! <RotationAngle> defines the rotation angle of the grid.
    void XV3d_Viewer::SetCircularGridValues(Standard_Real XOrigin, Standard_Real YOrigin, Standard_Real RadiusStep, Standard_Integer DivisionNumber, Standard_Real RotationAngle) {
        NativeHandle()->SetCircularGridValues(XOrigin, YOrigin, RadiusStep, DivisionNumber, RotationAngle);
    };

    //! Returns the location and the size of the grid.
    void XV3d_Viewer::CircularGridGraphicValues(Standard_Real% Radius, Standard_Real% OffSet) {
        Standard_Real SRadius(Radius); Standard_Real SOffSet(OffSet);
        NativeHandle()->CircularGridGraphicValues(SRadius, SOffSet);
        Radius = SRadius; OffSet = SOffSet;
    };

    //! Sets the location and the size of the grid.
    //! <XSize> defines the width of the grid.
    //! <YSize> defines the height of the grid.
    //! <OffSet> defines the displacement along the plane normal.
    void XV3d_Viewer::SetCircularGridGraphicValues(Standard_Real Radius, Standard_Real OffSet) {
        NativeHandle()->SetCircularGridGraphicValues(Radius, OffSet);
    };

    //! Returns the location and the size of the grid.
    void XV3d_Viewer::RectangularGridGraphicValues(Standard_Real% XSize, Standard_Real% YSize, Standard_Real% OffSet) {
        Standard_Real SXSize(XSize); Standard_Real SYSize(YSize); Standard_Real SOffSet(OffSet);
        NativeHandle()->RectangularGridGraphicValues(SXSize, SYSize, SOffSet);
        XSize = SXSize; YSize = SYSize; OffSet = SOffSet;
    };

    //! Sets the location and the size of the grid.
    //! <XSize> defines the width of the grid.
    //! <YSize> defines the height of the grid.
    //! <OffSet> defines the displacement along the plane normal.
    void XV3d_Viewer::SetRectangularGridGraphicValues(Standard_Real XSize, Standard_Real YSize, Standard_Real OffSet) {
        NativeHandle()->RectangularGridGraphicValues(XSize, YSize, OffSet);
    };

    //! Display grid echo at requested point in the view.
    void XV3d_Viewer::ShowGridEcho(XV3d_View^ theView, Graphic3d_Vertex& thePoint) {
        NativeHandle()->ShowGridEcho(theView->GetView(), thePoint);
    };

    //! Temporarly hide grid echo.
    void XV3d_Viewer::HideGridEcho(XV3d_View^ theView) {
        NativeHandle()->HideGridEcho(theView->GetView());
    };
}
