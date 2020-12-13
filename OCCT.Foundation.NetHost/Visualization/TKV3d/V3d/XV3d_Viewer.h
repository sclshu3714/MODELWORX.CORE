// Created on: 1992-01-17
// Created by: GG
// Copyright (c) 1992-1999 Matra Datavision
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

#ifndef _XV3d_Viewer_HeaderFile
#define _XV3d_Viewer_HeaderFile
#pragma once
#include <V3d_Viewer.hxx>
#include <V3d_View.hxx>
#include <XV3d_View.h>
#include <NCollection_Haft.h>
#include <xgp_Ax3.h>
#include <XQuantity_Color.h>
#include <XAspect_GradientFillMethod.h>
#include <XV3d_TypeOfOrientation.h>
#include <XV3d_TypeOfVisualization.h>
#include <XGraphic3d_TypeOfShadingModel.h>
#include <XV3d_TypeOfView.h>
#include <XAspect_GridType.h>
#include <XAspect_GridDrawMode.h>

#include <Aspect_Background.hxx>
#include <Aspect_GenId.hxx>
#include <Aspect_GradientBackground.hxx>
#include <Aspect_GradientFillMethod.hxx>
#include <Aspect_GridDrawMode.hxx>
#include <Aspect_GridType.hxx>

#include <gp_Ax3.hxx>
#include <Graphic3d_StructureManager.hxx>
#include <Graphic3d_TypeOfShadingModel.hxx>
#include <Graphic3d_Vertex.hxx>
#include <Graphic3d_ZLayerSettings.hxx>

#include <Standard.hxx>
#include <Standard_Boolean.hxx>
#include <Standard_CString.hxx>
#include <Standard_ExtString.hxx>
#include <Standard_Integer.hxx>
#include <Standard_Real.hxx>
#include <Standard_Type.hxx>

#include <TColStd_MapOfInteger.hxx>
#include <TColStd_ListIteratorOfListOfTransient.hxx>
#include <TColStd_SequenceOfInteger.hxx>
#include <TCollection_AsciiString.hxx>
#include <TCollection_ExtendedString.hxx>

#include <V3d_ListOfLight.hxx>
#include <V3d_ListOfView.hxx>
#include <V3d_TypeOfOrientation.hxx>
#include <V3d_TypeOfView.hxx>
#include <V3d_TypeOfVisualization.hxx>

#include <Quantity_Color.hxx>



class Aspect_Grid;
class Graphic3d_AspectMarker3d;
class Graphic3d_GraphicDriver;
class Graphic3d_Group;
class Graphic3d_Structure;
class V3d_BadValue;
class V3d_CircularGrid;
class V3d_RectangularGrid;
class V3d_View;
class Quantity_Color;
class V3d_Viewer;

using namespace TKernel;
using namespace TKMath;
namespace TKV3d {
    ref class XV3d_View;
    ref class TKMath::xgp_Ax3;
    ref class TKernel::XQuantity_Color;
    //! Defines services on Viewer type objects.
    //! The methods of this class allow editing and
    //! interrogation of the parameters linked to the viewer
    //! its friend classes (View,light,plane).
    public ref class XV3d_Viewer //: public Standard_Transient
    {
        //! DEFINE_STANDARD_RTTIEXT(V3d_Viewer, Standard_Transient)
    public:

        //! Create a Viewer with the given graphic driver and with default parameters:
        //! - View orientation: V3d_XposYnegZpos
        //! - View background: Quantity_NOC_GRAY30
        //! - Shading model: V3d_GOURAUD
        XV3d_Viewer(Handle(Graphic3d_GraphicDriver)& theDriver);

        XV3d_Viewer(Handle(V3d_Viewer) pos);

        void SetViewerHandle(Handle(V3d_Viewer) pos);

        virtual Handle(V3d_Viewer) GetViewer();


        //! Returns True if One View more can be defined in this Viewer.
        Standard_Boolean IfMoreViews();

        //! Creates a view in the viewer according to its default parameters.
        XV3d_View^ CreateView();

        //! Activates all of the views of a viewer attached to a window.
        void SetViewOn();

        //! Activates a particular view in the Viewer.
        //! Must be call if the Window attached to the view has been Deiconified.
        void SetViewOn(XV3d_View^ theView);

        //! Deactivates all the views of a Viewer
        //! attached to a window.
        void SetViewOff();

        //! Deactivates a particular view in the Viewer.
        //! Must be call if the Window attached to the view
        //! has been Iconified .
        void SetViewOff(XV3d_View^ theView);

        //! Deprecated, Redraw() should be used instead.
        void Update();// { Redraw(); }

        //! Redraws all the views of the Viewer even if no
        //! modification has taken place. Must be called if
        //! all the views of the Viewer are exposed, as for
        //! example in a global DeIconification.
        void Redraw();

        //! Updates layer of immediate presentations.
        void RedrawImmediate();

        //! Invalidates viewer content but does not redraw it.
        void Invalidate();

        //! Suppresses the Viewer.
        void Remove();

        //! Return Graphic Driver instance.
        Handle(Graphic3d_GraphicDriver) Driver();// { return myDriver; }

        //! Returns the structure manager associated to this viewer.
        Handle(Graphic3d_StructureManager) StructureManager();// { return myStructureManager; }

        //! Return default Rendering Parameters.
        //! By default these parameters are set in a new V3d_View.
        Graphic3d_RenderingParams DefaultRenderingParams();// { return myDefaultRenderingParams; }

        //! Set default Rendering Parameters.
        void SetDefaultRenderingParams(Graphic3d_RenderingParams& theParams);// { myDefaultRenderingParams = theParams; }

        //! Defines the default background colour of views
        //! attached to the viewer by supplying the color object
        void SetDefaultBackgroundColor(XQuantity_Color^ theColor);// { myBackground.SetColor(theColor); }

        //! Returns the gradient background of the view.
        Aspect_GradientBackground GetGradientBackground();// { return myGradientBackground; }

        //! Defines the default gradient background colours of views
        //! attached to the viewer by supplying the colour objects
        //! Aspect_GradientFillMethod theFillStyle = Aspect_GFM_HOR
        void SetDefaultBgGradientColors(XQuantity_Color^ theColor1, XQuantity_Color^ theColor2, XAspect_GradientFillMethod theFillStyle);

        //! Returns the default size of the view.
        Standard_Real DefaultViewSize();// { return myViewSize; }

        //! Gives a default size for the creation of views of the viewer.
        void SetDefaultViewSize(Standard_Real theSize);

        //! Returns the default Projection.
        XV3d_TypeOfOrientation DefaultViewProj();// { return myViewProj; }

        //! Sets the default projection for creating views in the viewer.
        void SetDefaultViewProj(XV3d_TypeOfOrientation theOrientation);// { myViewProj = theOrientation; }

        //! Returns the default type of Visualization.
        XV3d_TypeOfVisualization DefaultVisualization();// { return myVisualization; }

        //! Gives the default visualization mode.
        void SetDefaultVisualization(XV3d_TypeOfVisualization theType);// { myVisualization = theType; }

        //! Returns the default type of Shading
        XGraphic3d_TypeOfShadingModel DefaultShadingModel();// { return myShadingModel; }

        //! Gives the default type of SHADING.
        void SetDefaultShadingModel(XGraphic3d_TypeOfShadingModel theType);// { myShadingModel = theType; }

        //! Returns the default type of View (orthographic or perspective projection) to be returned by CreateView() method.
        XV3d_TypeOfView DefaultTypeOfView();// { return myDefaultTypeOfView; }

        //! Set the default type of View (orthographic or perspective projection) to be returned by CreateView() method.
        void SetDefaultTypeOfView(XV3d_TypeOfView theType);// { myDefaultTypeOfView = theType; }

        //! Returns the default background colour object.
        XQuantity_Color^ DefaultBackgroundColor();// { return myBackground.Color(); }

        //! Returns the gradient background colour objects of the view.
        void DefaultBgGradientColors(XQuantity_Color^ theColor1, XQuantity_Color^ theColor2);// { myGradientBackground.Colors(theColor1, theColor2); }

        //! Return all Z layer ids in sequence ordered by overlay level from lowest layer to highest ( foreground ).
        //! The first layer ID in sequence is the default layer that can't be removed.
        void GetAllZLayers(TColStd_SequenceOfInteger& theLayerSeq);

        //! Add a new top-level Z layer to all managed views and get its ID as <theLayerId> value.
        //! The Z layers are controlled entirely by viewer, it is not possible to add a layer to a particular view.
        //! Custom layers will be inserted before Graphic3d_ZLayerId_Top (e.g. between Graphic3d_ZLayerId_Default and before Graphic3d_ZLayerId_Top).
        //! @param theLayerId [out] id of created layer
        //! @param theSettings [in] new layer settings
        //! @return FALSE if the layer can not be created
        //! Graphic3d_ZLayerSettings& theSettings = Graphic3d_ZLayerSettings()
        Standard_Boolean AddZLayer(Graphic3d_ZLayerId& theLayerId, Graphic3d_ZLayerSettings& theSettings);

        //! Add a new top-level Z layer to all managed views and get its ID as <theLayerId> value.
        //! The Z layers are controlled entirely by viewer, it is not possible to add a layer to a particular view.
        //! Layer rendering order is defined by its position in list (altered by theLayerAfter)
        //! and IsImmediate() flag (all layers with IsImmediate() flag are drawn afterwards);
        //! @param theNewLayerId [out] id of created layer; layer id is arbitrary and does not depend on layer position in the list
        //! @param theSettings    [in] new layer settings
        //! @param theLayerAfter  [in] id of layer to append new layer before
        //! @return FALSE if the layer can not be created
        Standard_Boolean InsertLayerBefore(Graphic3d_ZLayerId& theNewLayerId, Graphic3d_ZLayerSettings& theSettings, Graphic3d_ZLayerId theLayerAfter);

        //! Add a new top-level Z layer to all managed views and get its ID as <theLayerId> value.
        //! The Z layers are controlled entirely by viewer, it is not possible to add a layer to a particular view.
        //! Layer rendering order is defined by its position in list (altered by theLayerAfter)
        //! and IsImmediate() flag (all layers with IsImmediate() flag are drawn afterwards);
        //! @param theNewLayerId [out] id of created layer; layer id is arbitrary and does not depend on layer position in the list
        //! @param theSettings    [in] new layer settings
        //! @param theLayerBefore [in] id of layer to append new layer after
        //! @return FALSE if the layer can not be created
        Standard_Boolean InsertLayerAfter(Graphic3d_ZLayerId& theNewLayerId, Graphic3d_ZLayerSettings& theSettings, Graphic3d_ZLayerId theLayerBefore);

        //! Remove Z layer with ID <theLayerId>.
        //! Method returns Standard_False if the layer can not be removed or doesn't exists.
        //! By default, there are always default bottom-level layer that can't be removed.
        Standard_Boolean RemoveZLayer(Graphic3d_ZLayerId theLayerId);

        //! Returns the settings of a single Z layer.
        Graphic3d_ZLayerSettings ZLayerSettings(Graphic3d_ZLayerId theLayerId);

        //! Sets the settings for a single Z layer.
        void SetZLayerSettings(Graphic3d_ZLayerId theLayerId, Graphic3d_ZLayerSettings& theSettings);

        //! Return an iterator for active views.
        V3d_ListOfViewIterator ActiveViewIterator();// { return V3d_ListOfViewIterator(myActiveViews); }

        //! Initializes an internal iterator on the active views.
        void InitActiveViews();// { myActiveViewsIterator.Initialize(myActiveViews); }

        //! Returns true if there are more active view(s) to return.
        Standard_Boolean MoreActiveViews();// { return myActiveViewsIterator.More(); }

        //! Go to the next active view (if there is not, ActiveView will raise an exception)
        void NextActiveViews();// { if (!myActiveViews.IsEmpty()) myActiveViewsIterator.Next(); }

        XV3d_View^ ActiveView();// { return myActiveViewsIterator.Value(); }

        //! returns true if there is only one active view.
        Standard_Boolean LastActiveView();// { return myActiveViews.Extent() == 1; }


        //! Return an iterator for defined views.
        V3d_ListOfViewIterator DefinedViewIterator();// { return V3d_ListOfViewIterator(myDefinedViews); }

        //! Initializes an internal iterator on the Defined views.
        void InitDefinedViews();// { myDefinedViewsIterator.Initialize(myDefinedViews); }

        //! returns true if there are more Defined view(s) to return.
        Standard_Boolean MoreDefinedViews();// { return myDefinedViewsIterator.More(); }

        //! Go to the next Defined view (if there is not, DefinedView will raise an exception)
        void NextDefinedViews();// { if (!myDefinedViews.IsEmpty()) myDefinedViewsIterator.Next(); }

        XV3d_View^ DefinedView();// { return myDefinedViewsIterator.Value(); }

        //! @name lights management

        //! Defines default lights:
        //!  positional-light 0.3 0. 0.
        //!  directional-light V3d_XnegYposZpos
        //!  directional-light V3d_XnegYneg
        //!  ambient-light
        void SetDefaultLights();

        //! Activates MyLight in the viewer.
        void SetLightOn(Handle(V3d_Light)& theLight);

        //! Activates all the lights defined in this viewer.
        void SetLightOn();

        //! Deactivates MyLight in this viewer.
        void SetLightOff(Handle(V3d_Light)& theLight);

        //! Deactivate all the Lights defined in this viewer.
        void SetLightOff();

        //! Adds Light in Sequence Of Lights.
        void AddLight(Handle(V3d_Light)& theLight);

        //! Delete Light in Sequence Of Lights.
        void DelLight(Handle(V3d_Light)& theLight);

        //! Updates the lights of all the views of a viewer.
        void UpdateLights();

        Standard_Boolean IsGlobalLight(Handle(V3d_Light)& TheLight);

        //! Return an iterator for defined lights.
        V3d_ListOfLightIterator ActiveLightIterator();// { return V3d_ListOfLightIterator(myActiveLights); }

        //! Initializes an internal iteratator on the active Lights.
        void InitActiveLights();// { myActiveLightsIterator.Initialize(myActiveLights); }

        //! returns true if there are more active Light(s) to return.
        Standard_Boolean MoreActiveLights();// { return myActiveLightsIterator.More(); }

        //! Go to the next active Light (if there is not, ActiveLight() will raise an exception)
        void NextActiveLights();// { myActiveLightsIterator.Next(); }

        Handle(V3d_Light) ActiveLight();// { return myActiveLightsIterator.Value(); }

        //! Return an iterator for defined lights.
        V3d_ListOfLightIterator DefinedLightIterator();// { return V3d_ListOfLightIterator(myDefinedLights); }

        //! Initializes an internal iterattor on the Defined Lights.
        void InitDefinedLights();// { myDefinedLightsIterator.Initialize(myDefinedLights); }

        //! Returns true if there are more Defined Light(s) to return.
        Standard_Boolean MoreDefinedLights();// { return myDefinedLightsIterator.More(); }

        //! Go to the next Defined Light (if there is not, DefinedLight() will raise an exception)
        void NextDefinedLights();// { if (!myDefinedLights.IsEmpty()) myDefinedLightsIterator.Next(); }

        Handle(V3d_Light) DefinedLight();// { return myDefinedLightsIterator.Value(); }

        //! @name objects management

        //! Erase all Objects in All the views.
        void Erase();

        //! UnHighlight all Objects in All the views.
        void UnHighlight();


        //! returns true if the computed mode can be used.
        Standard_Boolean ComputedMode();// { return myComputedMode; }

        //! Set if the computed mode can be used.
        void SetComputedMode(Standard_Boolean theMode);// { myComputedMode = theMode; }

        //! returns true if by default the computed mode must be used.
        Standard_Boolean DefaultComputedMode();// { return myDefaultComputedMode; }

        //! Set if by default the computed mode must be used.
        void SetDefaultComputedMode(Standard_Boolean theMode);// { myDefaultComputedMode = theMode; }

        //! @name privileged plane management

        xgp_Ax3^ PrivilegedPlane();// { return myPrivilegedPlane; }

        void SetPrivilegedPlane(xgp_Ax3^ thePlane);

        //Standard_Real theSize = 1
        void DisplayPrivilegedPlane(Standard_Boolean theOnOff, Standard_Real theSize);

        //! @name grid management

        //! Activates the grid in all views of <me>.
        void ActivateGrid(XAspect_GridType aGridType, XAspect_GridDrawMode aGridDrawMode);

        //! Deactivates the grid in all views of <me>.
        void DeactivateGrid();

        //! Show/Don't show grid echo to the hit point.
        //! If TRUE,the grid echo will be shown at ConvertToGrid() time.
        //! Standard_Boolean showGrid = Standard_True
        void SetGridEcho(Standard_Boolean showGrid);

        //! Show grid echo <aMarker> to the hit point.
        //! Warning: When the grid echo marker is not set,
        //! a default marker is build with the attributes:
        //! marker type : Aspect_TOM_STAR
        //! marker color : Quantity_NOC_GRAY90
        //! marker size : 3.0
        void SetGridEcho(Handle(Graphic3d_AspectMarker3d)& aMarker);

        //! Returns TRUE when grid echo must be displayed at hit point.
        Standard_Boolean GridEcho();// { return myGridEcho; }

        //! Returns Standard_True if a grid is activated in <me>.
        Standard_Boolean IsActive();

        //! Returns the defined grid in <me>.
        Handle(Aspect_Grid) Grid();

        //! Returns the current grid type defined in <me>.
        XAspect_GridType GridType();// { return myGridType; }

        //! Returns the current grid draw mode defined in <me>.
        XAspect_GridDrawMode GridDrawMode();

        //! Returns the definition of the rectangular grid.
        void RectangularGridValues(Standard_Real% XOrigin, Standard_Real% YOrigin, Standard_Real% XStep, Standard_Real% YStep, Standard_Real% RotationAngle);

        //! Sets the definition of the rectangular grid.
        //! <XOrigin>, <YOrigin> defines the origin of the grid.
        //! <XStep> defines the interval between 2 vertical lines.
        //! <YStep> defines the interval between 2 horizontal lines.
        //! <RotationAngle> defines the rotation angle of the grid.
        void SetRectangularGridValues(Standard_Real XOrigin, Standard_Real YOrigin, Standard_Real XStep, Standard_Real YStep, Standard_Real RotationAngle);

        //! Returns the definition of the circular grid.
        void CircularGridValues(Standard_Real% XOrigin, Standard_Real% YOrigin, Standard_Real% RadiusStep, Standard_Integer% DivisionNumber, Standard_Real% RotationAngle);

        //! Sets the definition of the circular grid.
        //! <XOrigin>, <YOrigin> defines the origin of the grid.
        //! <RadiusStep> defines the interval between 2 circles.
        //! <DivisionNumber> defines the section number of one half circle.
        //! <RotationAngle> defines the rotation angle of the grid.
        void SetCircularGridValues(Standard_Real XOrigin, Standard_Real YOrigin, Standard_Real RadiusStep, Standard_Integer DivisionNumber, Standard_Real RotationAngle);

        //! Returns the location and the size of the grid.
        void CircularGridGraphicValues(Standard_Real% Radius, Standard_Real% OffSet);

        //! Sets the location and the size of the grid.
        //! <XSize> defines the width of the grid.
        //! <YSize> defines the height of the grid.
        //! <OffSet> defines the displacement along the plane normal.
        void SetCircularGridGraphicValues(Standard_Real Radius, Standard_Real OffSet);

        //! Returns the location and the size of the grid.
        void RectangularGridGraphicValues(Standard_Real% XSize, Standard_Real% YSize, Standard_Real% OffSet);

        //! Sets the location and the size of the grid.
        //! <XSize> defines the width of the grid.
        //! <YSize> defines the height of the grid.
        //! <OffSet> defines the displacement along the plane normal.
        void SetRectangularGridGraphicValues(Standard_Real XSize, Standard_Real YSize, Standard_Real OffSet);

        //! Display grid echo at requested point in the view.
        void ShowGridEcho(XV3d_View^ theView, Graphic3d_Vertex& thePoint);

        //! Temporarly hide grid echo.
        void HideGridEcho(XV3d_View^ theView);

        /// <summary>
        /// ±¾µØ¾ä±ú
        /// </summary>
        virtual property Handle(V3d_Viewer) IHandle {
            Handle(V3d_Viewer) get() { // Standard_OVERRIDE {
                return NativeHandle();
            }
            void set(Handle(V3d_Viewer) handle) { // Standard_OVERRIDE {
                NativeHandle() = handle;
            }
        }
    private:
        NCollection_Haft<Handle(V3d_Viewer)> NativeHandle;

    };
    //! DEFINE_STANDARD_HANDLE(V3d_Viewer, Standard_Transient)
}
#endif // _XV3d_Viewer_HeaderFile
