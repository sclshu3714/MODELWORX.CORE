#include <XV3d_View.h>
namespace TKV3d {
    //! Initializes the view.
        //! V3d_TypeOfView theType = V3d_ORTHOGRAPHIC
    XV3d_View::XV3d_View(XV3d_Viewer^ theViewer, XV3d_TypeOfView theType) {
        NativeHandle() = new V3d_View(theViewer->GetViewer(), safe_cast<V3d_TypeOfView>(theType));
    };

    //! Initializes the view by copying.
    XV3d_View::XV3d_View(XV3d_Viewer^ theViewer, XV3d_View^ theView) {
        NativeHandle() = new V3d_View(theViewer->GetViewer(), theView->GetView());
    };

    XV3d_View::XV3d_View(Handle(V3d_View) pos) {
        NativeHandle() = pos;
    };

    void XV3d_View::SetViewHandle(Handle(V3d_View) pos) {
        NativeHandle() = pos;
    };

    Handle(V3d_View) XV3d_View::GetView() {
        return NativeHandle();
    };

    //! Default destructor.
    XV3d_View::~XV3d_View() {
        NativeHandle()->~V3d_View();
        NativeHandle() = NULL;
    };

    //! Activates the view in the specified Window
    //! If <aContext> is not NULL the graphic context is used
    //! to draw something in this view.
    //! Otherwise an internal graphic context is created.
    //! Warning: The view is centered and resized to preserve
    //! the height/width ratio of the window.
    //! Aspect_RenderingContext theContext = NULL
    void XV3d_View::SetWindow(Handle(Aspect_Window)& theWindow, Aspect_RenderingContext theContext) {
        NativeHandle()->SetWindow(theWindow, theContext);
    };

    void XV3d_View::SetMagnify(Handle(Aspect_Window)& theWindow, XV3d_View^ thePreviousView, Standard_Integer theX1, Standard_Integer theY1, Standard_Integer theX2, Standard_Integer theY2) {
        NativeHandle()->SetMagnify(theWindow, thePreviousView->GetView(), theX1, theY1, theX2, theY2);
    };

    //! Destroys the view.
    void XV3d_View::Remove() {
        NativeHandle()->Remove();
    };

    //! Deprecated, Redraw() should be used instead.
    void XV3d_View::Update() {
        NativeHandle()->Update();
    };

    //! Redisplays the view even if there has not
    //! been any modification.
    //! Must be called if the view is shown.
    //! (Ex: DeIconification ) .
    void XV3d_View::Redraw() {
        NativeHandle()->Redraw();
    };

    //! Updates layer of immediate presentations.
    void XV3d_View::RedrawImmediate() {
        NativeHandle()->RedrawImmediate();
    };

    //! Invalidates view content but does not redraw it.
    void XV3d_View::Invalidate() {
        NativeHandle()->Invalidate();
    };

    //! Returns true if cached view content has been invalidated.
    Standard_Boolean XV3d_View::IsInvalidated() {
        return NativeHandle()->IsInvalidated();
    };

    //! Returns true if immediate layer content has been invalidated.
    Standard_Boolean XV3d_View::IsInvalidatedImmediate() {
        return NativeHandle()->IsInvalidatedImmediate();
    };// { return myIsInvalidatedImmediate; }

    //! Invalidates view content within immediate layer but does not redraw it.
    void XV3d_View::InvalidateImmediate() {
        NativeHandle()->InvalidateImmediate();
    };// { myIsInvalidatedImmediate = Standard_True; }

    //! Must be called when the window supporting the
    //! view changes size.
    //! if the view is not mapped on a window.
    //! Warning: The view is centered and resized to preserve
    //! the height/width ratio of the window.
    void XV3d_View::MustBeResized() {
        NativeHandle()->MustBeResized();
    };

    //! Must be called when the window supporting the
    //! view is mapped or unmapped.
    void XV3d_View::DoMapping() {
        NativeHandle()->DoMapping();
    };

    //! Returns the status of the view regarding
    //! the displayed structures inside
    //! Returns True is The View is empty
    Standard_Boolean XV3d_View::IsEmpty() {
        return NativeHandle()->IsEmpty();
    };

    //! Updates the lights of the view.
    void XV3d_View::UpdateLights() {
        NativeHandle()->UpdateLights();
    };

    //! Sets the automatic z-fit mode and its parameters.
    //! The auto z-fit has extra parameters which can controlled from application level
    //! to ensure that the size of viewing volume will be sufficiently large to cover
    //! the depth of unmanaged objects, for example, transformation persistent ones.
    //! @param theScaleFactor [in] the scale factor for Z-range.
    //! The range between Z-min, Z-max projection volume planes
    //! evaluated by z fitting method will be scaled using this coefficient.
    //! Program error exception is thrown if negative or zero value
    //! is passed.
    //! Standard_Real theScaleFactor = 1.0
    void XV3d_View::SetAutoZFitMode(Standard_Boolean theIsOn, Standard_Real theScaleFactor) {
        NativeHandle()->SetAutoZFitMode(theIsOn, theScaleFactor);
    };

    //! returns TRUE if automatic z-fit mode is turned on.
    Standard_Boolean XV3d_View::AutoZFitMode() {
        return NativeHandle()->AutoZFitMode();
    };// { return myAutoZFitIsOn; }

    //! returns scale factor parameter of automatic z-fit mode.
    Standard_Real XV3d_View::AutoZFitScaleFactor() {
        return NativeHandle()->AutoZFitScaleFactor();
    };// { return myAutoZFitScaleFactor; }

    //! If automatic z-range fitting is turned on, adjusts Z-min and Z-max
    //! projection volume planes with call to ZFitAll.
    void XV3d_View::AutoZFit() {
        NativeHandle()->AutoZFit();
    };

    //! Change Z-min and Z-max planes of projection volume to match the
    //! displayed objects.
    //! Standard_Real theScaleFactor = 1.0
    void XV3d_View::ZFitAll(Standard_Real theScaleFactor) {
        NativeHandle()->ZFitAll(theScaleFactor);
    };

    //! Defines the background color of the view by the color definition type and the three corresponding values.
    void XV3d_View::SetBackgroundColor(XQuantity_TypeOfColor theType, Standard_Real theV1, Standard_Real theV2, Standard_Real theV3) {
        NativeHandle()->SetBackgroundColor(safe_cast<Quantity_TypeOfColor>(theType), theV1, theV2, theV3);
    };

    //! Defines the background color of the view.
    void XV3d_View::SetBackgroundColor(XQuantity_Color^ theColor) {
        NativeHandle()->SetBackgroundColor(*theColor->GetColor());
    };

    //! Defines the gradient background colors of the view by supplying the colors
    //! and the fill method (horizontal by default).
    //! Aspect_GradientFillMethod theFillStyle = Aspect_GFM_HOR,  Standard_Boolean theToUpdate = Standard_False
    void XV3d_View::SetBgGradientColors(XQuantity_Color^ theColor1, XQuantity_Color^ theColor2, XAspect_GradientFillMethod theFillStyle, Standard_Boolean theToUpdate) {
        NativeHandle()->SetBgGradientColors(*theColor1->GetColor(), *theColor2->GetColor(), safe_cast<Aspect_GradientFillMethod>(theFillStyle), theToUpdate);
    };

    //! Defines the gradient background fill method of the view.
    //! Aspect_GradientFillMethod theMethod = Aspect_GFM_HOR, Standard_Boolean theToUpdate = Standard_False
    void XV3d_View::SetBgGradientStyle(XAspect_GradientFillMethod theMethod, Standard_Boolean theToUpdate) {
        NativeHandle()->SetBgGradientStyle(safe_cast<Aspect_GradientFillMethod>(theMethod), theToUpdate);
    };

    //! Defines the background texture of the view by supplying the texture image file name
    //! and fill method (centered by default).
    //! Aspect_FillMethod theFillStyle = Aspect_FM_CENTERED, Standard_Boolean theToUpdate = Standard_False
    void XV3d_View::SetBackgroundImage(Standard_CString theFileName, XAspect_FillMethod theFillStyle, Standard_Boolean theToUpdate) {
        NativeHandle()->SetBackgroundImage(theFileName, safe_cast<Aspect_FillMethod>(theFillStyle), theToUpdate);
    };

    //! Defines the textured background fill method of the view.
    //! Standard_Boolean theToUpdate = Standard_False
    void XV3d_View::SetBgImageStyle(XAspect_FillMethod theFillStyle, Standard_Boolean theToUpdate) {
        NativeHandle()->SetBgImageStyle(safe_cast<Aspect_FillMethod>(theFillStyle), theToUpdate);
    };

    //! Sets environment cubemap as interactive background.
    //! Standard_Boolean theToUpdate = Standard_False
    void XV3d_View::SetBackgroundCubeMap(Handle(Graphic3d_CubeMap)& theCubeMap, Standard_Boolean theToUpdate) {
        NativeHandle()->SetBackgroundCubeMap(theCubeMap, theToUpdate);
    };

    //! Definition of an axis from its origin and
    //! its orientation .
    //! This will be the current axis for rotations and movements.
    //! Warning! raises BadValue from V3d if the vector normal is NULL. .
    void XV3d_View::SetAxis(Standard_Real X, Standard_Real Y, Standard_Real Z, Standard_Real Vx, Standard_Real Vy, Standard_Real Vz) {
        NativeHandle()->SetAxis(X, Y, Z, Vx, Vy, Vz);
    };

    //! Defines the shading model for the visualization. Various models are available.
    void XV3d_View::SetShadingModel(XGraphic3d_TypeOfShadingModel theShadingModel) {
        NativeHandle()->SetShadingModel(safe_cast<Graphic3d_TypeOfShadingModel>(theShadingModel));
    };

    //! Sets the environment texture to use. No environment texture by default.
    void XV3d_View::SetTextureEnv(Handle(Graphic3d_TextureEnv)& theTexture) {
        NativeHandle()->SetTextureEnv(theTexture);
    };

    //! Defines the visualization type in the view.
    void XV3d_View::SetVisualization(XV3d_TypeOfVisualization theType) {
        NativeHandle()->SetVisualization(safe_cast<V3d_TypeOfVisualization>(theType));
    };

    //! Activates theLight in the view.
    void XV3d_View::SetLightOn(Handle(V3d_Light)& theLight) {
        NativeHandle()->SetLightOn(theLight);
    };

    //! Activates all the lights defined in this view.
    void XV3d_View::SetLightOn() {
        NativeHandle()->SetLightOn();
    };

    //! Deactivate theLight in this view.
    void XV3d_View::SetLightOff(Handle(V3d_Light)& theLight) {
        NativeHandle()->SetLightOff(theLight);
    };

    //! Deactivate all the Lights defined in this view.
    void XV3d_View::SetLightOff() {
        NativeHandle()->SetLightOff();
    };

    //! Returns TRUE when the light is active in this view.
    Standard_Boolean XV3d_View::IsActiveLight(Handle(V3d_Light)& theLight) {
        return NativeHandle()->IsActiveLight(theLight);
    };

    //! sets the immediate update mode and returns the previous one.
    Standard_Boolean XV3d_View::SetImmediateUpdate(Standard_Boolean theImmediateUpdate) {
        return NativeHandle()->SetImmediateUpdate(theImmediateUpdate);
    };

    //! Customization of the ZBUFFER Triedron.
    //! XColor,YColor,ZColor - colors of axis
    //! SizeRatio - ratio of decreasing of the trihedron size when its physical
    //! position comes out of the view
    //! AxisDiametr - diameter relatively to axis length
    //! NbFacettes - number of facets of cylinders and cones
    //! Quantity_Color& theXColor = Quantity_NOC_RED, Quantity_Color& theYColor = Quantity_NOC_GREEN, Quantity_Color& theZColor = Quantity_NOC_BLUE1, Standard_Real theSizeRatio = 0.8, Standard_Real theAxisDiametr = 0.05, Standard_Integer theNbFacettes = 12
    void XV3d_View::ZBufferTriedronSetup(XQuantity_Color^ theXColor, XQuantity_Color^ theYColor, XQuantity_Color^ theZColor, Standard_Real theSizeRatio, Standard_Real theAxisDiametr, Standard_Integer theNbFacettes) {
        return NativeHandle()->ZBufferTriedronSetup(*theXColor->GetColor(), *theYColor->GetColor(), *theZColor->GetColor(), theSizeRatio, theAxisDiametr, theNbFacettes);
    };

    //! Display of the Triedron.
    //! Initialize position, color and length of Triedron axes.
    //! The scale is a percent of the window width.
    //! Aspect_TypeOfTriedronPosition thePosition = Aspect_TOTP_CENTER, Quantity_Color& theColor = Quantity_NOC_WHITE, Standard_Real theScale = 0.02, V3d_TypeOfVisualization theMode = V3d_WIREFRAME
    void XV3d_View::TriedronDisplay(XAspect_TypeOfTriedronPosition thePosition, XQuantity_Color^ theColor, Standard_Real theScale, XV3d_TypeOfVisualization theMode) {
        NativeHandle()->TriedronDisplay(safe_cast<Aspect_TypeOfTriedronPosition>(thePosition), *theColor->GetColor(), theScale, safe_cast<V3d_TypeOfVisualization>(theMode));
    };

    //! Erases the Triedron.
    void XV3d_View::TriedronErase() {
        NativeHandle()->TriedronErase();
    };

    //! Returns data of a graduated trihedron.
    Graphic3d_GraduatedTrihedron XV3d_View::GetGraduatedTrihedron() {
        return NativeHandle()->GetGraduatedTrihedron();
    };

    //! Displays a graduated trihedron.
    void XV3d_View::GraduatedTrihedronDisplay(Graphic3d_GraduatedTrihedron& theTrihedronData) {
        NativeHandle()->GraduatedTrihedronDisplay(theTrihedronData);
    };

    //! Erases a graduated trihedron from the view.
    void XV3d_View::GraduatedTrihedronErase() {
        NativeHandle()->GraduatedTrihedronErase();
    };

    //! modify the Projection of the view perpendicularly to
    //! the privileged plane of the viewer.
    void XV3d_View::SetFront() {
        NativeHandle()->SetFront();
    };

    //! Rotates the eye about the coordinate system of
    //! reference of the screen
    //! for which the origin is the view point of the projection,
    //! with a relative angular value in RADIANS with respect to
    //! the initial position expressed by Start = Standard_True
    //! Warning! raises BadValue from V3d
    //! If the eye, the view point, or the high point are
    //! aligned or confused.
    //! Standard_Boolean Start = Standard_True
    void XV3d_View::Rotate(Standard_Real Ax, Standard_Real Ay, Standard_Real Az, Standard_Boolean Start) {
        NativeHandle()->Rotate(Ax, Ay, Az, Start);
    };

    //! Rotates the eye about the coordinate system of
    //! reference of the screen
    //! for which the origin is Gravity point {X,Y,Z},
    //! with a relative angular value in RADIANS with respect to
    //! the initial position expressed by Start = Standard_True
    //! If the eye, the view point, or the high point are
    //! aligned or confused.
    //! Standard_Boolean Start = Standard_True
    void XV3d_View::Rotate(Standard_Real Ax, Standard_Real Ay, Standard_Real Az, Standard_Real X, Standard_Real Y, Standard_Real Z, Standard_Boolean Start) {
        NativeHandle()->Rotate(Ax, Ay, Az, X, Y, Z, Start);
    };

    //! Rotates the eye about one of the coordinate axes of
    //! of the view for which the origin is the Gravity point{X,Y,Z}
    //! with an relative angular value in RADIANS with
    //! respect to the initial position expressed by
    //! Start = Standard_True
    void XV3d_View::Rotate(XV3d_TypeOfAxe Axe, Standard_Real Angle, Standard_Real X, Standard_Real Y, Standard_Real Z, Standard_Boolean Start) {
        NativeHandle()->Rotate(safe_cast<V3d_TypeOfAxe>(Axe), Angle, X, Y, Z, Start);
    };

    //! Rotates the eye about one of the coordinate axes of
    //! of the view for which the origin is the view point of the
    //! projection with an relative angular value in RADIANS with
    //! respect to the initial position expressed by
    //! Start = Standard_True
    void XV3d_View::Rotate(XV3d_TypeOfAxe Axe, Standard_Real Angle, Standard_Boolean Start) {
        NativeHandle()->Rotate(safe_cast<V3d_TypeOfAxe>(Axe), Angle, Start);
    };

    //! Rotates the eye around the current axis a relative
    //! angular value in RADIANS with respect to the initial
    //! position expressed by Start = Standard_True
    void XV3d_View::Rotate(Standard_Real Angle, Standard_Boolean Start) {
        NativeHandle()->Rotate(Angle, Start);
    };

    //! Movement of the eye parallel to the coordinate system
    //! of reference of the screen a distance relative to the
    //! initial position expressed by Start = Standard_True.
    void XV3d_View::Move(Standard_Real Dx, Standard_Real Dy, Standard_Real Dz, Standard_Boolean Start) {
        NativeHandle()->Move(Dx, Dy, Dz, Start);
    };

    //! Movement of the eye parallel to one of the axes of the
    //! coordinate system of reference of the view a distance
    //! relative to the initial position expressed by
    //! Start = Standard_True.
    void XV3d_View::Move(XV3d_TypeOfAxe Axe, Standard_Real Length, Standard_Boolean Start) {
        NativeHandle()->Move(safe_cast<V3d_TypeOfAxe>(Axe), Length, Start);
    };

    //! Movement of the eye parllel to the current axis
    //! a distance relative to the initial position
    //! expressed by Start = Standard_True
    void XV3d_View::Move(Standard_Real Length, Standard_Boolean Start) {
        NativeHandle()->Move(Length, Start);
    };

    //! Movement of the ye and the view point parallel to the
    //! frame of reference of the screen a distance relative
    //! to the initial position expressed by
    //! Start = Standard_True
    void XV3d_View::Translate(Standard_Real Dx, Standard_Real Dy, Standard_Real Dz, Standard_Boolean Start) {
        NativeHandle()->Translate(Dx, Dy, Dz, Start);
    };

    //! Movement of the eye and the view point parallel to one
    //! of the axes of the fame of reference of the view a
    //! distance relative to the initial position
    //! expressed by Start = Standard_True
    void XV3d_View::Translate(XV3d_TypeOfAxe Axe, Standard_Real Length, Standard_Boolean Start) {
        NativeHandle()->Translate(safe_cast<V3d_TypeOfAxe>(Axe), Length, Start);
    };

    //! Movement of the eye and view point parallel to
    //! the current axis a distance relative to the initial
    //! position expressed by Start = Standard_True
    void XV3d_View::Translate(Standard_Real Length, Standard_Boolean Start) {
        NativeHandle()->Translate(Length, Start);
    };

    //! places the point of the view corresponding
    //! at the pixel position x,y at the center of the window
    //! and updates the view.Standard_Real theZoomFactor = 1
    void XV3d_View::Place(Standard_Integer theXp, Standard_Integer theYp, Standard_Real theZoomFactor) {
        NativeHandle()->Place(theXp, theYp, theZoomFactor);
    };

    //! Rotation of the view point around the frame of reference
    //! of the screen for which the origin is the eye of the
    //! projection with a relative angular value in RADIANS
    //! with respect to the initial position expressed by
    //! Start = Standard_True
    void XV3d_View::Turn(Standard_Real Ax, Standard_Real Ay, Standard_Real Az, Standard_Boolean Start) {
        NativeHandle()->Turn(Ax, Ay, Az, Start);
    };

    //! Rotation of the view point around one of the axes of the
    //! frame of reference of the view for which the origin is
    //! the eye of the projection with an angular value in
    //! RADIANS relative to the initial position expressed by
    //! Start = Standard_True
    void XV3d_View::Turn(V3d_TypeOfAxe Axe, Standard_Real Angle, Standard_Boolean Start) {
        NativeHandle()->Turn(safe_cast<V3d_TypeOfAxe>(Axe), Angle, Start);
    };

    //! Rotation of the view point around the current axis an
    //! angular value in RADIANS relative to the initial
    //! position expressed by Start = Standard_True
    void XV3d_View::Turn(Standard_Real Angle, Standard_Boolean Start) {
        NativeHandle()->Turn(Angle, Start);
    };

    //! Defines the angular position of the high point of
    //! the reference frame of the view with respect to the
    //! Y screen axis with an absolute angular value in
    //! RADIANS.
    void XV3d_View::SetTwist(Standard_Real Angle) {
        NativeHandle()->SetTwist(Angle);
    };

    //! Defines the position of the eye..
    void XV3d_View::SetEye(Standard_Real X, Standard_Real Y, Standard_Real Z) {
        NativeHandle()->SetEye(X, Y, Z);
    };

    //! Defines the Depth of the eye from the view point
    //! without update the projection .
    void XV3d_View::SetDepth(Standard_Real Depth) {
        NativeHandle()->SetDepth(Depth);
    };

    //! Defines the orientation of the projection.
    void XV3d_View::SetProj(Standard_Real Vx, Standard_Real Vy, Standard_Real Vz) {
        NativeHandle()->SetProj(Vx, Vy, Vz);
    };

    //! Defines the orientation of the projection .
    //! @param theOrientation camera direction
    //! @param theIsYup       flag indicating Y-up (TRUE) or Z-up (FALSE) convention
    //! Standard_Boolean theIsYup = Standard_False
    void XV3d_View::SetProj(XV3d_TypeOfOrientation theOrientation, Standard_Boolean theIsYup) {
        NativeHandle()->SetProj(safe_cast<V3d_TypeOfOrientation>(theOrientation), theIsYup);
    };

    //! Defines the position of the view point.
    void XV3d_View::SetAt(Standard_Real X, Standard_Real Y, Standard_Real Z) {
        NativeHandle()->SetAt(X, Y, Z);
    }; 

    //! Defines the orientation of the high point.
    void XV3d_View::SetUp(Standard_Real Vx, Standard_Real Vy, Standard_Real Vz) {
        NativeHandle()->SetUp(Vx, Vy, Vz);
    };

    //! Defines the orientation(SO) of the high point.
    void XV3d_View::SetUp(XV3d_TypeOfOrientation Orientation) {
        NativeHandle()->SetUp(safe_cast<V3d_TypeOfOrientation>(Orientation));
    };

    //! Saves the current state of the orientation of the view
    //! which will be the return state at ResetViewOrientation.
    void XV3d_View::SetViewOrientationDefault() {
        NativeHandle()->SetViewOrientationDefault();
    };

    //! Resets the orientation of the view.
    //! Updates the view
    void XV3d_View::ResetViewOrientation() {
        NativeHandle()->ResetViewOrientation();
    };

    //! Translates the center of the view along "x" and "y" axes of
    //! view projection. Can be used to perform interactive panning operation.
    //! In that case the DXv, DXy parameters specify panning relative to the
    //! point where the operation is started.
    //! @param theDXv [in] the relative panning on "x" axis of view projection, in view space coordinates.
    //! @param theDYv [in] the relative panning on "y" axis of view projection, in view space coordinates.
    //! @param theZoomFactor [in] the zooming factor.
    //! @param theToStart [in] pass TRUE when starting panning to remember view
    //! state prior to panning for relative arguments. If panning is started,
    //! passing {0, 0} for {theDXv, theDYv} will return view to initial state.
    //! Performs update of view.
    //! Standard_Real theZoomFactor = 1, Standard_Boolean theToStart = Standard_True
    void XV3d_View::Panning(Standard_Real theDXv, Standard_Real theDYv, Standard_Real theZoomFactor, Standard_Boolean theToStart) {
        NativeHandle()->Panning(theDXv, theDYv, theZoomFactor, theToStart);
    };

    //! Relocates center of screen to the point, determined by
    //! {Xp, Yp} pixel coordinates relative to the bottom-left corner of
    //! screen. To calculate pixel coordinates for any point from world
    //! coordinate space, it can be projected using "Project".
    //! @param theXp [in] the x coordinate.
    //! @param theYp [in] the y coordinate.
    void XV3d_View::SetCenter(Standard_Integer theXp, Standard_Integer theYp) {
        NativeHandle()->SetCenter(theXp, theYp);
    };

    //! Defines the view projection size in its maximum dimension,
    //! keeping the inital height/width ratio unchanged.
    void XV3d_View::SetSize(Standard_Real theSize) {
        NativeHandle()->SetSize(theSize);
    };

    //! Defines the Depth size of the view
    //! Front Plane will be set to Size/2.
    //! Back  Plane will be set to -Size/2.
    //! Any Object located Above the Front Plane or
    //! behind the Back Plane will be Clipped .
    //! NOTE than the XY Size of the View is NOT modified .
    void XV3d_View::SetZSize(Standard_Real SetZSize) {
        NativeHandle()->SetZSize(SetZSize);
    };

    //! Zooms the view by a factor relative to the initial
    //! value expressed by Start = Standard_True
    //! Updates the view.
    //! Standard_Boolean Start = Standard_True
    void XV3d_View::SetZoom(Standard_Real Coef, Standard_Boolean Start) {
        NativeHandle()->SetZoom(Coef, Start);
    };

    //! Zooms the view by a factor relative to the value
    //! initialised by SetViewMappingDefault().
    //! Updates the view.
    void XV3d_View::SetScale(Standard_Real Coef) {
        NativeHandle()->SetScale(Coef);
    };

    //! Sets  anisotropic (axial)  scale  factors  <Sx>, <Sy>, <Sz>  for  view <me>.
    //! Anisotropic  scaling  operation  is  performed  through  multiplying
    //! the current view  orientation  matrix  by  a  scaling  matrix:
    //! || Sx  0   0   0 ||
    //! || 0   Sy  0   0 ||
    //! || 0   0   Sz  0 ||
    //! || 0   0   0   1 ||
    //! Updates the view.
    void XV3d_View::SetAxialScale(Standard_Real Sx, Standard_Real Sy, Standard_Real Sz) {
        NativeHandle()->SetAxialScale(Sx, Sy, Sz);
    };

    //! Adjust view parameters to fit the displayed scene, respecting height / width ratio.
    //! The Z clipping range (depth range) is fitted if AutoZFit flag is TRUE.
    //! Throws program error exception if margin coefficient is < 0 or >= 1.
    //! Updates the view.
    //! @param theMargin [in] the margin coefficient for view borders.
    //! @param theToUpdate [in] flag to perform view update.
    //! Standard_Real theMargin = 0.01, Standard_Boolean theToUpdate = Standard_True
    void XV3d_View::FitAll(Standard_Real theMargin, Standard_Boolean theToUpdate) {
        NativeHandle()->FitAll(theMargin, theToUpdate);
    };

    //! Adjust view parameters to fit the displayed scene, respecting height / width ratio
    //! according to the custom bounding box given.
    //! Throws program error exception if margin coefficient is < 0 or >= 1.
    //! Updates the view.
    //! @param theBox [in] the custom bounding box to fit.
    //! @param theMargin [in] the margin coefficient for view borders.
    //! @param theToUpdate [in] flag to perform view update.
    //!  Standard_Real theMargin = 0.01, Standard_Boolean theToUpdate = Standard_True
    void XV3d_View::FitAll(XBnd_Box^ theBox, Standard_Real theMargin, Standard_Boolean theToUpdate) {
        NativeHandle()->FitAll(*theBox->GetBndBox(), theMargin, theToUpdate);
    };

    //! Adjusts the viewing volume so as not to clip the displayed objects by front and back
    //! and back clipping planes. Also sets depth value automatically depending on the
    //! calculated Z size and Aspect parameter.
    //! NOTE than the original XY size of the view is NOT modified .
    //! Standard_Real Aspect = 0.01, Standard_Real Margin = 0.01
    void XV3d_View::DepthFitAll(Standard_Real Aspect, Standard_Real Margin) {
        NativeHandle()->DepthFitAll(Aspect, Margin);
    };

    //! Centers the defined projection window so that it occupies
    //! the maximum space while respecting the initial
    //! height/width ratio.
    //! NOTE than the original Z size of the view is NOT modified .
    void XV3d_View::FitAll(Standard_Real theMinXv, Standard_Real theMinYv, Standard_Real theMaxXv, Standard_Real theMaxYv) {
        NativeHandle()->FitAll(theMinXv, theMinYv, theMaxXv, theMaxYv);
    };

    //! Centers the defined PIXEL window so that it occupies
    //! the maximum space while respecting the initial height/width ratio.
    //! NOTE than the original Z size of the view is NOT modified.
    //! @param theMinXp [in] pixel coordinates of minimal corner on x screen axis.
    //! @param theMinYp [in] pixel coordinates of minimal corner on y screen axis.
    //! @param theMaxXp [in] pixel coordinates of maximal corner on x screen axis.
    //! @param theMaxYp [in] pixel coordinates of maximal corner on y screen axis.
    void XV3d_View::WindowFit(Standard_Integer theMinXp, Standard_Integer theMinYp, Standard_Integer theMaxXp, Standard_Integer theMaxYp) {
        NativeHandle()->WindowFit(theMinXp, theMinYp, theMaxXp, theMaxYp);
    };

    //! Saves the current view mapping. This will be the
    //! state returned from ResetViewmapping.
    void XV3d_View::SetViewMappingDefault() {
        NativeHandle()->SetViewMappingDefault();
    };

    //! Resets the centering of the view.
    //! Updates the view
    void XV3d_View::ResetViewMapping() {
        NativeHandle()->ResetViewMapping();
    };

    //! Resets the centering and the orientation of the view.
    //! Standard_Boolean theToUpdate = Standard_True
    void XV3d_View::Reset(Standard_Boolean theToUpdate) {
        NativeHandle()->Reset(theToUpdate);
    };

    //! Converts the PIXEL value
    //! to a value in the projection plane.
    Standard_Real XV3d_View::Convert(Standard_Integer Vp) {
        return NativeHandle()->Convert(Vp);
    };

    //! Converts the point PIXEL into a point projected
    //! in the reference frame of the projection plane.
    void XV3d_View::Convert(Standard_Integer Xp, Standard_Integer Yp, Standard_Real Xv, Standard_Real Yv) {
        return NativeHandle()->Convert(Xp, Yp, Xv, Yv);
    };

    //! Converts tha value of the projection plane into
    //! a PIXEL value.
    Standard_Integer XV3d_View::Convert(Standard_Real Vv) {
        return NativeHandle()->Convert(Vv);
    };

    //! Converts the point defined in the reference frame
    //! of the projection plane into a point PIXEL.
    void XV3d_View::Convert(Standard_Real Xv, Standard_Real Yv, Standard_Integer Xp, Standard_Integer Yp) {
        NativeHandle()->Convert(Xv, Yv, Xp, Yp);
    };

    //! Converts the projected point into a point
    //! in the reference frame of the view corresponding
    //! to the intersection with the projection plane
    //! of the eye/view point vector.
    void XV3d_View::Convert(Standard_Integer Xp, Standard_Integer Yp, Standard_Real X, Standard_Real Y, Standard_Real Z) {
        NativeHandle()->Convert(Xp, Yp, X, Y, Z);
    };

    //! Converts the projected point into a point
    //! in the reference frame of the view corresponding
    //! to the intersection with the projection plane
    //! of the eye/view point vector and returns the
    //! projection ray for further computations.
    void XV3d_View::ConvertWithProj(Standard_Integer Xp, Standard_Integer Yp, Standard_Real X, Standard_Real Y, Standard_Real Z, Standard_Real Vx, Standard_Real Vy, Standard_Real Vz) {
        NativeHandle()->ConvertWithProj(Xp, Yp, X, Y, Z, Vx, Vy, Vz);
    };

    //! Converts the projected point into the nearest grid point
    //! in the reference frame of the view corresponding
    //! to the intersection with the projection plane
    //! of the eye/view point vector and display the grid marker.
    //! Warning: When the grid is not active the result is identical to the above Convert() method.
    //! How to use:
    //! 1) Enable the grid echo display
    //! myViewer->SetGridEcho(Standard_True);
    //! 2) When application receive a move event:
    //! 2.1) Check if any object is detected
    //! if( myInteractiveContext->MoveTo(x,y) == AIS_SOD_Nothing ) {
    //! 2.2) Check if the grid is active
    //! if( myViewer->Grid()->IsActive() ) {
    //! 2.3) Display the grid echo and gets the grid point
    //! myView->ConvertToGrid(x,y,X,Y,Z);
    //! myView->Viewer()->ShowGridEcho (myView, Graphic3d_Vertex (X,Y,Z));
    //! myView->RedrawImmediate();
    //! 2.4) Else this is the standard case
    //! } else myView->Convert(x,y,X,Y,Z);
    void XV3d_View::ConvertToGrid(Standard_Integer Xp, Standard_Integer Yp, Standard_Real Xg, Standard_Real Yg, Standard_Real Zg) {
        NativeHandle()->ConvertToGrid(Xp, Yp, Xg, Yg, Zg);
    };

    //! Converts the point into the nearest grid point
    //! and display the grid marker.
    void XV3d_View::ConvertToGrid(Standard_Real X, Standard_Real Y, Standard_Real Z, Standard_Real Xg, Standard_Real Yg, Standard_Real Zg) {
        NativeHandle()->ConvertToGrid(X, Y, Z, Xg, Yg, Zg);
    };

    //! Projects the point defined in the reference frame of
    //! the view into the projected point in the associated window.
    void XV3d_View::Convert(Standard_Real X, Standard_Real Y, Standard_Real Z, Standard_Integer Xp, Standard_Integer Yp) {
        NativeHandle()->Convert(X, Y, Z, Xp, Yp);
    };

    //! Converts the point defined in the user space of
    //! the view to the projection plane at the depth
    //! relative to theZ.
    void XV3d_View::Project(Standard_Real theX, Standard_Real theY, Standard_Real theZ, Standard_Real theXp, Standard_Real theYp) {
        NativeHandle()->Project(theX, theY, theZ, theXp, theYp);
    };

    //! Converts the point defined in the user space of
    //! the view to the projection plane at the depth
    //! relative to theZ.
    void XV3d_View::Project(Standard_Real theX, Standard_Real theY, Standard_Real theZ, Standard_Real theXp, Standard_Real theYp, Standard_Real theZp) {
        NativeHandle()->Project(theX, theY, theZ, theXp, theYp, theZp);
    };

    //! Returns the Background color values of the view
    //! depending of the color Type.
    void XV3d_View::BackgroundColor(XQuantity_TypeOfColor Type, Standard_Real V1, Standard_Real V2, Standard_Real V3) {
        NativeHandle()->BackgroundColor(safe_cast<Quantity_TypeOfColor>(Type), V1, V2, V3);
    };

    //! Returns the Background color object of the view.
    XQuantity_Color^ XV3d_View::BackgroundColor() {
        Quantity_Color* temp = new Quantity_Color(NativeHandle()->BackgroundColor());
        return gcnew XQuantity_Color(temp);
    };

    //! Returns the gradient background colors of the view.
    void XV3d_View::GradientBackgroundColors(XQuantity_Color^ theColor1, XQuantity_Color^ theColor2) {
        NativeHandle()->GradientBackgroundColors(*theColor1->GetColor(), *theColor2->GetColor());
    };

    //! Returns the gradient background of the view.
    Aspect_GradientBackground XV3d_View::GradientBackground() {
        return NativeHandle()->GradientBackground();
    };

    //! Returns the current value of the zoom expressed with
    //! respect to SetViewMappingDefault().
    Standard_Real XV3d_View::Scale() {
        return NativeHandle()->Scale();
    };

    //! Returns the current values of the anisotropic (axial) scale factors.
    void XV3d_View::AxialScale(Standard_Real Sx, Standard_Real Sy, Standard_Real Sz) {
        NativeHandle()->AxialScale(Sx, Sy, Sz);
    };

    //! Returns the height and width of the view.
    void XV3d_View::Size(Standard_Real Width, Standard_Real Height) {
        NativeHandle()->Size(Width, Height);
    };

    //! Returns the Depth of the view .
    Standard_Real XV3d_View::ZSize() {
        return NativeHandle()->ZSize();
    };

    //! Returns the position of the eye.
    void XV3d_View::Eye(Standard_Real X, Standard_Real Y, Standard_Real Z) {
        NativeHandle()->Eye(X, Y, Z);
    };

    //! Returns the position of point which emanating the projections.
    void XV3d_View::FocalReferencePoint(Standard_Real X, Standard_Real Y, Standard_Real Z) { Eye(X, Y, Z); }

    //! Returns the coordinate of the point (Xpix,Ypix)
    //! in the view (XP,YP,ZP), and the projection vector of the
    //! view passing by the point (for PerspectiveView).
    void XV3d_View::ProjReferenceAxe(Standard_Integer Xpix, Standard_Integer Ypix, Standard_Real XP, Standard_Real YP, Standard_Real ZP, Standard_Real VX, Standard_Real VY, Standard_Real VZ) {
        NativeHandle()->ProjReferenceAxe(Xpix, Ypix, XP, YP, ZP, VX, VY, VZ);
    };

    //! Returns the Distance between the Eye and View Point.
    Standard_Real XV3d_View::Depth() {
        return NativeHandle()->Depth();
    };

    //! Returns the projection vector.
    void XV3d_View::Proj(Standard_Real Vx, Standard_Real Vy, Standard_Real Vz) {
        NativeHandle()->Proj(Vx, Vy, Vz);
    };

    //! Returns the position of the view point.
    void XV3d_View::At(Standard_Real X, Standard_Real Y, Standard_Real Z) {
        NativeHandle()->At(X, Y, Z);
    };

    //! Returns the vector giving the position of the high point.
    void XV3d_View::Up(Standard_Real Vx, Standard_Real Vy, Standard_Real Vz) {
        NativeHandle()->Up(Vx, Vy, Vz);
    };

    //! Returns in RADIANS the orientation of the view around
    //! the visual axis measured from the Y axis of the screen.
    Standard_Real XV3d_View::Twist() {
        return NativeHandle()->Twist();
    };

    //! Returns the current shading model.
    XGraphic3d_TypeOfShadingModel XV3d_View::ShadingModel() {
        return safe_cast<XGraphic3d_TypeOfShadingModel>(NativeHandle()->ShadingModel());
    };

    Handle(Graphic3d_TextureEnv) XV3d_View::TextureEnv() {
        return NativeHandle()->TextureEnv();
    };

    //! Returns the current visualisation mode.
    XV3d_TypeOfVisualization XV3d_View::Visualization() {
        return safe_cast<XV3d_TypeOfVisualization>(NativeHandle()->Visualization());
    };

    //! Returns True if One light more can be
    //! activated in this View.
    Standard_Boolean XV3d_View::IfMoreLights() {
        return NativeHandle()->IfMoreLights();
    };

    //! Return iterator for defined lights.
    V3d_ListOfLightIterator XV3d_View::ActiveLightIterator() {
        return NativeHandle()->ActiveLightIterator();
    };// { return V3d_ListOfLightIterator(myActiveLights); }

    //! initializes an iteration on the active Lights.
    void XV3d_View::InitActiveLights() {
        NativeHandle()->InitActiveLights();
    };// { myActiveLightsIterator.Initialize(myActiveLights); }

    //! returns true if there are more active Light(s) to return.
    Standard_Boolean XV3d_View::MoreActiveLights() {
        return NativeHandle()->MoreActiveLights();
    };// { return myActiveLightsIterator.More(); }

    //! Go to the next active Light (if there is not, ActiveLight will raise an exception)
    void XV3d_View::NextActiveLights() {
        NativeHandle()->NextActiveLights();
    };// { myActiveLightsIterator.Next(); }

    Handle(V3d_Light) XV3d_View::ActiveLight() {
        return NativeHandle()->ActiveLight();
    };// { return myActiveLightsIterator.Value(); }

    //! Returns the MAX number of light associated to the view.
    Standard_Integer XV3d_View::LightLimit() {
        return NativeHandle()->LightLimit();
    };

    //! Returns the viewer in which the view has been created.
    XV3d_Viewer^ XV3d_View::Viewer() {
        return gcnew XV3d_Viewer(NativeHandle()->Viewer());
    };// { return MyViewer; }

    //! Returns True if MyView is associated with a window .
    Standard_Boolean XV3d_View::IfWindow() {
        return NativeHandle()->IfWindow();
    };

    //! Returns the Aspect Window associated with the view.
    Handle(Aspect_Window) XV3d_View::Window() {
        return NativeHandle()->Window();
    };// { return MyWindow; }

    //! Returns the Type of the View
    XV3d_TypeOfView XV3d_View::Type() {
        return safe_cast<XV3d_TypeOfView>(NativeHandle()->Type());
    };

    //! Translates the center of the view along "x" and "y" axes of
    //! view projection. Can be used to perform interactive panning operation.
    //! In that case the DXp, DXp parameters specify panning relative to the
    //! point where the operation is started.
    //! @param theDXp [in] the relative panning on "x" axis of view projection, in pixels.
    //! @param theDYp [in] the relative panning on "y" axis of view projection, in pixels.
    //! @param theZoomFactor [in] the zooming factor.
    //! @param theToStart [in] pass TRUE when starting panning to remember view
    //! state prior to panning for relative arguments. Passing 0 for relative
    //! panning parameter should return view panning to initial state.
    //! Performs update of view.
    //!  Standard_Real theZoomFactor = 1, Standard_Boolean theToStart = Standard_True
    void XV3d_View::Pan(Standard_Integer theDXp, Standard_Integer theDYp, Standard_Real theZoomFactor, Standard_Boolean theToStart) {
        NativeHandle()->Pan(theDXp, theDYp, theZoomFactor, theToStart);
    };

    //! Zoom the view according to a zoom factor computed
    //! from the distance between the 2 mouse position.
    //! @param theXp1 [in] the x coordinate of first mouse position, in pixels.
    //! @param theYp1 [in] the y coordinate of first mouse position, in pixels.
    //! @param theXp2 [in] the x coordinate of second mouse position, in pixels.
    //! @param theYp2 [in] the y coordinate of second mouse position, in pixels.
    void XV3d_View::Zoom(Standard_Integer theXp1, Standard_Integer theYp1, Standard_Integer theXp2, Standard_Integer theYp2) {
        NativeHandle()->Zoom(theXp1, theYp1, theXp2, theYp2);
    };

    //! Defines starting point for ZoomAtPoint view operation.
    //! @param theXp [in] the x mouse coordinate, in pixels.
    //! @param theYp [in] the y mouse coordinate, in pixels.
    void XV3d_View::StartZoomAtPoint(Standard_Integer theXp, Standard_Integer theYp) {
        NativeHandle()->StartZoomAtPoint(theXp, theYp);
    };

    //! Zooms the model at a pixel defined by the method StartZoomAtPoint().
    void XV3d_View::ZoomAtPoint(Standard_Integer theMouseStartX, Standard_Integer theMouseStartY, Standard_Integer theMouseEndX, Standard_Integer theMouseEndY) {
        NativeHandle()->ZoomAtPoint(theMouseStartX, theMouseStartY, theMouseEndX, theMouseEndY);
    };

    //! Performs  anisotropic scaling  of  <me>  view  along  the  given  <Axis>.
    //! The  scale  factor  is  calculated on a basis of
    //! the mouse pointer displacement <Dx,Dy>.
    //! The  calculated  scale  factor  is  then  passed  to  SetAxialScale(Sx,  Sy,  Sz)  method.
    void XV3d_View::AxialScale(Standard_Integer Dx, Standard_Integer Dy, XV3d_TypeOfAxe Axis) {
        NativeHandle()->AxialScale(Dx, Dy, safe_cast<V3d_TypeOfAxe>(Axis));
    };

    //! Begin the rotation of the view around the screen axis
    //! according to the mouse position <X,Y>.
    //! Warning: Enable rotation around the Z screen axis when <zRotationThreshold>
    //! factor is > 0 soon the distance from the start point and the center
    //! of the view is > (medium viewSize * <zRotationThreshold> ).
    //! Generally a value of 0.4 is usable to rotate around XY screen axis
    //! inside the circular threshold area and to rotate around Z screen axis
    //! outside this area.
    //!  Standard_Real zRotationThreshold = 0.0
    void XV3d_View::StartRotation(Standard_Integer X, Standard_Integer Y, Standard_Real zRotationThreshold) {
        NativeHandle()->StartRotation(X, Y, zRotationThreshold);
    };

    //! Continues the rotation of the view
    //! with an angle computed from the last and new mouse position <X,Y>.
    void XV3d_View::Rotation(Standard_Integer X, Standard_Integer Y) {
        NativeHandle()->Rotation(X, Y);
    };

    //! Change View Plane Distance for Perspective Views
    //! Warning! raises TypeMismatch from Standard if the view
    //! is not a perspective view.
    void XV3d_View::SetFocale(Standard_Real Focale) {
        NativeHandle()->SetFocale(Focale);
    };

    //! Returns the View Plane Distance for Perspective Views
    Standard_Real XV3d_View::Focale() {
        return NativeHandle()->Focale();
    };

    //! Returns the associated Graphic3d view.
    Handle(Graphic3d_CView) XV3d_View::View() {
        return NativeHandle()->View();
    };// { return myView; }

    //! Switches computed HLR mode in the view.
    void XV3d_View::SetComputedMode(Standard_Boolean theMode) {
        NativeHandle()->SetComputedMode(theMode);
    };

    //! Returns the computed HLR mode state.
    Standard_Boolean XV3d_View::ComputedMode() {
        return NativeHandle()->ComputedMode();
    };

    //! idem than WindowFit
    void XV3d_View::WindowFitAll(Standard_Integer Xmin, Standard_Integer Ymin, Standard_Integer Xmax, Standard_Integer Ymax)
    {
        WindowFit(Xmin, Ymin, Xmax, Ymax);
    }

    //! Transform camera eye, center and scale to fit in the passed bounding box specified in WCS.
    //! @param theCamera [in] the camera
    //! @param theBox    [in] the bounding box
    //! @param theMargin [in] the margin coefficient for view borders
    //! @param theResolution [in] the minimum size of projection of bounding box in Xv or Yv direction when it considered to be a thin plane or point (without a volume);
    //!                           in this case only the center of camera is adjusted
    //! @param theToEnlargeIfLine [in] when TRUE - in cases when the whole bounding box projected into thin line going along Z-axis of screen,
    //!                                the view plane is enlarged such thatwe see the whole line on rotation, otherwise only the center of camera is adjusted.
    //! @return TRUE if the fit all operation can be done
    //! Standard_Real theResolution = 0.0, Standard_Boolean theToEnlargeIfLine = Standard_True
    Standard_Boolean XV3d_View::FitMinMax(Handle(Graphic3d_Camera)& theCamera, XBnd_Box^ theBox, Standard_Real theMargin, Standard_Real theResolution, Standard_Boolean theToEnlargeIfLine) {
        return NativeHandle()->FitMinMax(theCamera, *theBox->GetBndBox(), theMargin, theResolution, theToEnlargeIfLine);
    };

    //! Defines or Updates the definition of the
    //! grid in <me>
    void XV3d_View::SetGrid(xgp_Ax3^ aPlane, Handle(Aspect_Grid)& aGrid) {
        NativeHandle()->SetGrid(*aPlane->GetAx3(), aGrid);
    };

    //! Defines or Updates the activity of the
    //! grid in <me>
    void XV3d_View::SetGridActivity(Standard_Boolean aFlag) {
        NativeHandle()->SetGridActivity(aFlag);
    };

    //! Dumps the full contents of the View into the image file. This is an alias for ToPixMap() with Image_AlienPixMap.
    //! @param theFile destination image file (image format is determined by file extension like .png, .bmp, .jpg)
    //! @param theBufferType buffer to dump
    //! @return FALSE when the dump has failed
    //! Graphic3d_BufferType& theBufferType = Graphic3d_BT_RGB
    Standard_Boolean XV3d_View::Dump(Standard_CString theFile, Graphic3d_BufferType& theBufferType) {
        return  NativeHandle()->Dump(theFile, theBufferType);
    };

    //! Dumps the full contents of the view to a pixmap with specified parameters.
    //! Internally this method calls Redraw() with an offscreen render buffer of requested target size (theWidth x theHeight),
    //! so that there is no need resizing a window control for making a dump of different size.
    Standard_Boolean XV3d_View::ToPixMap(Image_PixMap& theImage, V3d_ImageDumpOptions& theParams) {
        return  NativeHandle()->ToPixMap(theImage, theParams);
    };

    //! Dumps the full contents of the view to a pixmap.
    //! Internally this method calls Redraw() with an offscreen render buffer of requested target size (theWidth x theHeight),
    //! so that there is no need resizing a window control for making a dump of different size.
    //! @param theImage          target image, will be re-allocated to match theWidth x theHeight
    //! @param theWidth          target image width
    //! @param theHeight         target image height
    //! @param theBufferType     type of the view buffer to dump (color / depth)
    //! @param theToAdjustAspect when true, active view aspect ratio will be overridden by (theWidth / theHeight)
    //! @param theStereoOptions  how to dump stereographic camera
    //! Graphic3d_BufferType& theBufferType = Graphic3d_BT_RGB, Standard_Boolean      theToAdjustAspect = Standard_True, V3d_StereoDumpOptions theStereoOptions = V3d_SDO_MONO
    Standard_Boolean XV3d_View::ToPixMap(Image_PixMap& theImage, Standard_Integer theWidth, Standard_Integer theHeight, Graphic3d_BufferType& theBufferType, Standard_Boolean theToAdjustAspect, XV3d_StereoDumpOptions theStereoOptions)
    {
        V3d_ImageDumpOptions aParams;
        aParams.Width = theWidth;
        aParams.Height = theHeight;
        aParams.BufferType = theBufferType;
        aParams.StereoOptions = safe_cast<V3d_StereoDumpOptions>(theStereoOptions);
        aParams.ToAdjustAspect = theToAdjustAspect;
        return ToPixMap(theImage, aParams);
    }

    //! Manages display of the back faces
    //! When <aModel> is TOBM_AUTOMATIC the object backfaces
    //! are displayed only for surface objects and
    //! never displayed for solid objects.
    //! this was the previous mode.
    //! <aModel> is TOBM_ALWAYS_DISPLAYED the object backfaces
    //! are always displayed both for surfaces or solids.
    //! <aModel> is TOBM_NEVER_DISPLAYED the object backfaces
    //! are never displayed. V3d_TypeOfBackfacingModel theModel = V3d_TOBM_AUTOMATIC
    void XV3d_View::SetBackFacingModel(XV3d_TypeOfBackfacingModel theModel) {
         NativeHandle()->SetBackFacingModel(safe_cast<V3d_TypeOfBackfacingModel>(theModel));
    };

    //! Returns current state of the back faces display
    XV3d_TypeOfBackfacingModel XV3d_View::BackFacingModel() {
        return safe_cast<XV3d_TypeOfBackfacingModel>(NativeHandle()->BackFacingModel());
    };

    //! Adds clip plane to the view. The composition of clip planes truncates the
    //! rendering space to convex volume. Number of supported clip planes can be consulted
    //! by PlaneLimit method of associated Graphic3d_GraphicDriver.
    //! Please be aware that the planes which exceed the limit are ignored during rendering.
    //! @param thePlane [in] the clip plane to be added to view.
    void XV3d_View::AddClipPlane(Handle(Graphic3d_ClipPlane)& thePlane) {
        NativeHandle()->AddClipPlane(thePlane);
    };

    //! Removes clip plane from the view.
    //! @param thePlane [in] the clip plane to be removed from view.
    void XV3d_View::RemoveClipPlane(Handle(Graphic3d_ClipPlane)& thePlane) {
        NativeHandle()->RemoveClipPlane(thePlane);
    };

    //! Sets sequence of clip planes to the view. The planes that have been set
    //! before are removed from the view. The composition of clip planes
    //! truncates the rendering space to convex volume. Number of supported
    //! clip planes can be consulted by InquirePlaneLimit method of
    //! Graphic3d_GraphicDriver. Please be aware that the planes that
    //! exceed the limit are ignored during rendering.
    //! @param thePlanes [in] the clip planes to set.
    void XV3d_View::SetClipPlanes(Handle(Graphic3d_SequenceOfHClipPlane)& thePlanes) {
        NativeHandle()->SetClipPlanes(thePlanes);
    };

    //! Get clip planes.
    //! @return sequence clip planes that have been set for the view
    Handle(Graphic3d_SequenceOfHClipPlane) XV3d_View::ClipPlanes() {
        return NativeHandle()->ClipPlanes();
    };

    //! Returns the MAX number of clipping planes associated to the view.
    Standard_Integer XV3d_View::PlaneLimit() {
        return NativeHandle()->PlaneLimit();
    };

    //! Change camera used by view.
    void XV3d_View::SetCamera(Handle(Graphic3d_Camera)& theCamera) {
        return NativeHandle()->SetCamera(theCamera);
    };

    //! Returns camera object of the view.
    //! @return: handle to camera object, or NULL if 3D view does not use
    //! the camera approach.
    Handle(Graphic3d_Camera) XV3d_View::Camera() {
        return NativeHandle()->Camera();
    };

    //! Return default camera.
    Handle(Graphic3d_Camera) XV3d_View::DefaultCamera() {
        return NativeHandle()->DefaultCamera();
    };// { return myDefaultCamera; }

    //! Returns current rendering parameters and effect settings.
    //! By default it returns default parameters of current viewer.
    //! To define view-specific settings use method V3d_View::ChangeRenderingParams().
    //! @sa V3d_Viewer::DefaultRenderingParams()
    Graphic3d_RenderingParams XV3d_View::RenderingParams() {
        return NativeHandle()->RenderingParams();
    };

    //! Returns reference to current rendering parameters and effect settings.
    Graphic3d_RenderingParams XV3d_View::ChangeRenderingParams() {
        return NativeHandle()->ChangeRenderingParams();
    };

    //! @return flag value of objects culling mechanism
    Standard_Boolean XV3d_View::IsCullingEnabled() { 
        return NativeHandle()->IsCullingEnabled();;
    }

    //! Turn on/off automatic culling of objects outside frustum (ON by default)
    void XV3d_View::SetFrustumCulling(Standard_Boolean theMode) {
        NativeHandle()->SetFrustumCulling(theMode);
    }

    //! Fill in the dictionary with diagnostic info.
    //! Should be called within rendering thread.
    //!
    //! This API should be used only for user output or for creating automated reports.
    //! The format of returned information (e.g. key-value layout)
    //! is NOT part of this API and can be changed at any time.
    //! Thus application should not parse returned information to weed out specific parameters.
    //! @param theDict  destination map for information
    //! @param theFlags defines the information to be retrieved
    void XV3d_View::DiagnosticInformation(TColStd_IndexedDataMapOfStringString& theDict, XGraphic3d_DiagnosticInfo theFlags) {
        NativeHandle()->DiagnosticInformation(theDict, safe_cast<Graphic3d_DiagnosticInfo>(theFlags));
    };

    //! Returns string with statistic performance info.
    XTCollection_AsciiString^ XV3d_View::StatisticInformation() {
        TCollection_AsciiString* temp = new TCollection_AsciiString(NativeHandle()->StatisticInformation());
        return gcnew XTCollection_AsciiString(temp);
    };

    //! Fills in the dictionary with statistic performance info.
    void XV3d_View::StatisticInformation(TColStd_IndexedDataMapOfStringString& theDict) {
        NativeHandle()->StatisticInformation(theDict);
    };

    //! Returns the Objects number and the gravity center of ALL viewable points in the view
    xgp_Pnt^ XV3d_View::GravityPoint() {
        gp_Pnt* temp = new gp_Pnt(NativeHandle()->GravityPoint());
        return gcnew xgp_Pnt(temp);
    };
}