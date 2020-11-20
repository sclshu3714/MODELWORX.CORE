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

#ifndef _XPrs3d_Drawer_HeaderFile
#define _XPrs3d_Drawer_HeaderFile
#pragma once
#include <Prs3d_Drawer.hxx>
#include "XGraphic3d_PresentationAttributes.h"
#include "XAspect_TypeOfDeflection.h"
#include "XStandard_Helper.h"
#include "NCollection_Haft.h"
#include "XPrs3d_TypeOfHLR.h"
#include "XPrs3d_VertexDrawMode.h"
#include "XGraphic3d_TypeOfShadingModel.h"

#include <Standard.hxx>
#include <Standard_Type.hxx>

#include <Standard_Integer.hxx>
#include <Standard_Boolean.hxx>
#include <Aspect_TypeOfDeflection.hxx>
#include <Graphic3d_GroupAspect.hxx>
#include <Graphic3d_PresentationAttributes.hxx>
#include <Graphic3d_ShaderProgram.hxx>
#include <Standard_Real.hxx>
#include <Prs3d_VertexDrawMode.hxx>
#include <Prs3d_DimensionUnits.hxx>
#include <Prs3d_TypeOfHLR.hxx>
#include <Standard_Transient.hxx>
#include <GeomAbs_Shape.hxx>

class Prs3d_IsoAspect;
class Prs3d_LineAspect;
class Prs3d_TextAspect;
class Prs3d_ShadingAspect;
class Prs3d_PointAspect;
class Prs3d_PlaneAspect;
class Prs3d_ArrowAspect;
class Prs3d_DatumAspect;
class Prs3d_DimensionAspect;
class TCollection_AsciiString;

//£¡ DEFINE_STANDARD_HANDLE(Prs3d_Drawer, Graphic3d_PresentationAttributes)

namespace TKV3d {
    //! A graphic attribute manager which governs how
    //! objects such as color, width, line thickness and deflection are displayed.
    //! A drawer includes an instance of the Aspect classes with particular default values.
    public ref class XPrs3d_Drawer : public XGraphic3d_PresentationAttributes
    {
        //! DEFINE_STANDARD_RTTIEXT(Prs3d_Drawer, Graphic3d_PresentationAttributes)
    public:

        //! Default constructor.
        XPrs3d_Drawer();

        //! Default constructor.
        XPrs3d_Drawer(Handle(Prs3d_Drawer) pos);

        Handle(Prs3d_Drawer) GetDrawer();

        //! Sets the type of chordal deflection.
        //! This indicates whether the deflection value is absolute or relative to the size of the object.
        void SetTypeOfDeflection(XAspect_TypeOfDeflection theTypeOfDeflection);

        //! Returns the type of chordal deflection.
        //! This indicates whether the deflection value is absolute or relative to the size of the object.
        XAspect_TypeOfDeflection TypeOfDeflection();

        //! Returns true if the drawer has a type of deflection setting active.
        Standard_Boolean HasOwnTypeOfDeflection();

        //! Defines the maximal chordial deviation when drawing any curve.
        //! Even if the type of deviation is set to TOD_Relative, this value is used by: 
        //!   Prs3d_DeflectionCurve
        //!   Prs3d_WFDeflectionSurface
        //!   Prs3d_WFDeflectionRestrictedFace
        void SetMaximalChordialDeviation(const Standard_Real theChordialDeviation);

        //! Returns the maximal chordal deviation. The default value is 0.1.
        //! Drawings of curves or patches are made with respect to an absolute maximal chordal deviation.
        Standard_Real MaximalChordialDeviation();

        //! Returns true if the drawer has a maximal chordial deviation setting active.
        Standard_Boolean HasOwnMaximalChordialDeviation();

        //! Sets the type of HLR algorithm used by drawer's interactive objects
        void SetTypeOfHLR(XPrs3d_TypeOfHLR theTypeOfHLR);

        //! Returns the type of HLR algorithm currently in use.
        XPrs3d_TypeOfHLR TypeOfHLR();

        //! Returns true if the type of HLR is not equal to Prs3d_TOH_NotSet.
        Standard_Boolean HasOwnTypeOfHLR();

        //! Defines the maximum value allowed for the first and last
        //! parameters of an infinite curve.
        void SetMaximalParameterValue(const Standard_Real theValue);

        //! Sets the maximum value allowed for the first and last
        //! parameters of an infinite curve. By default, this value is 500000.
        Standard_Real MaximalParameterValue();

        //! Returns true if the drawer has a maximum value allowed for the first and last
        //! parameters of an infinite curve setting active.
        Standard_Boolean HasOwnMaximalParameterValue();

        //! Sets IsoOnPlane on or off by setting the parameter theIsEnabled to true or false.
        void SetIsoOnPlane(const Standard_Boolean theIsEnabled);

        //! Returns True if the drawing of isos on planes is enabled.
        Standard_Boolean IsoOnPlane();

        //! Returns true if the drawer has IsoOnPlane setting active.
        Standard_Boolean HasOwnIsoOnPlane();

        //! Returns True if the drawing of isos on triangulation is enabled.
        Standard_Boolean IsoOnTriangulation();

        //! Returns true if the drawer has IsoOnTriangulation setting active.
        Standard_Boolean HasOwnIsoOnTriangulation();

        //! Enables or disables isolines on triangulation by setting the parameter theIsEnabled to true or false.
        void SetIsoOnTriangulation(const Standard_Boolean theToEnable);

        //! Sets the discretisation parameter theValue.
        void SetDiscretisation(const Standard_Integer theValue);

        //! Returns the discretisation setting. 
        Standard_Integer Discretisation();

        //! Returns true if the drawer has discretisation setting active.
        Standard_Boolean HasOwnDiscretisation();

        //! Sets the deviation coefficient theCoefficient.
        //! Also sets the hasOwnDeviationCoefficient flag to Standard_True and myPreviousDeviationCoefficient
        void SetDeviationCoefficient(const Standard_Real theCoefficient);

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
        Standard_Real DeviationCoefficient();

        //! Sets the hasOwnDeviationCoefficient flag to Standard_False
        void SetDeviationCoefficient();

        //! Returns true if there is a local setting for deviation
        //! coefficient in this framework for a specific interactive object.
        Standard_Boolean HasOwnDeviationCoefficient();

        //! Saves the previous value used for the chordal
        //! deviation coefficient. 
        Standard_Real PreviousDeviationCoefficient();

        //! Updates the previous value used for the chordal deviation coefficient to the current state.
        void UpdatePreviousDeviationCoefficient();

        //! Sets the deviation coefficient aCoefficient for removal
        //! of hidden lines created by different viewpoints in
        //! different presentations. The Default value is 0.02.
        //! Also sets the hasOwnHLRDeviationCoefficient flag to Standard_True and myPreviousHLRDeviationCoefficient
        void SetHLRDeviationCoefficient(const Standard_Real theCoefficient);

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
        Standard_Real HLRDeviationCoefficient();

        //! Sets the hasOwnHLRDeviationCoefficient flag to Standard_False 
        void SetHLRDeviationCoefficient();

        //! Returns true if the there is a setting for HLR deviation
        //! coefficient in this framework for a specific interactive object.
        Standard_Boolean HasOwnHLRDeviationCoefficient();

        //! Returns the previous value of the hidden line removal deviation coefficient.
        Standard_Real PreviousHLRDeviationCoefficient();

        //! Sets the deviation angle theAngle.
        //! Also sets the hasOwnDeviationAngle flag to Standard_True, and myPreviousDeviationAngle.
        void SetDeviationAngle(const Standard_Real theAngle);

        //! Returns the value for deviation angle.
        Standard_Real DeviationAngle();

        //! Sets the hasOwnDeviationAngle flag to Standard_False
        void SetDeviationAngle();

        //! Returns true if the there is a local setting for deviation
        //! angle in this framework for a specific interactive object.
        Standard_Boolean HasOwnDeviationAngle();

        //! Returns the previous deviation angle
        Standard_Real PreviousDeviationAngle();

        //! Updates the previous deviation angle to the current value
        void UpdatePreviousDeviationAngle();

        //! Sets anAngle, the angle of maximum chordal deviation for removal of hidden lines created by
        //! different viewpoints in different presentations.
        //! The default value is 20 * M_PI / 180.
        //! Also sets the hasOwnHLRDeviationAngle flag to Standard_True and myPreviousHLRDeviationAngle.
        void SetHLRAngle(const Standard_Real theAngle);

        //! Returns the real number value of the deviation angle
        //! in hidden line removal views. The default value is 20 * M_PI / 180.
        Standard_Real HLRAngle();

        //! Sets the hasOwnHLRDeviationAngle flag to Standard_False
        void SetHLRAngle();

        //! Returns true if the there is a setting for HLR deviation
        //! angle in this framework for a specific interactive object.
        Standard_Boolean HasOwnHLRDeviationAngle();

        //! Returns the previous value of the HLR deviation angle.
        Standard_Real PreviousHLRDeviationAngle();

        //! Sets IsAutoTriangulated on or off by setting the parameter theIsEnabled to true or false.
        //! If this flag is True automatic re-triangulation with deflection-check logic will be applied.
        //! Else this feature will be disable and triangulation is expected to be computed by application itself
        //! and no shading presentation at all if unavailable.
        void SetAutoTriangulation(const Standard_Boolean theIsEnabled);

        //! Returns True if automatic triangulation is enabled.
        Standard_Boolean IsAutoTriangulation();

        //! Returns true if the drawer has IsoOnPlane setting active.
        Standard_Boolean HasOwnIsAutoTriangulation();

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
        Handle(Prs3d_IsoAspect) UIsoAspect();

        void SetUIsoAspect(const Handle(Prs3d_IsoAspect)& theAspect);

        //! Returns true if the drawer has its own attribute for
        //! UIso aspect that overrides the one in the link.
        Standard_Boolean HasOwnUIsoAspect();

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
        Handle(Prs3d_IsoAspect) VIsoAspect();

        //! Sets the appearance of V isoparameters - theAspect.
        void SetVIsoAspect(const Handle(Prs3d_IsoAspect)& theAspect);

        //! Returns true if the drawer has its own attribute for
        //! VIso aspect that overrides the one in the link.
        Standard_Boolean HasOwnVIsoAspect();

        //! Returns wire aspect settings.
        //! The LineAspect for the free boundaries can be edited.
        //! The default values are:
        //!   Color: Quantity_NOC_GREEN
        //!   Type of line: Aspect_TOL_SOLID
        //!   Width: 1.0
        //! These attributes are used by the algorithm Prs3d_WFShape.
        Handle(Prs3d_LineAspect) WireAspect();

        //! Sets the parameter theAspect for display of wires.
        void SetWireAspect(const Handle(Prs3d_LineAspect)& theAspect);

        //! Returns true if the drawer has its own attribute for
        //! wire aspect that overrides the one in the link.
        Standard_Boolean HasOwnWireAspect();

        //! Sets WireDraw on or off by setting the parameter theIsEnabled to true or false.
        void SetWireDraw(const Standard_Boolean theIsEnabled);

        //! Returns True if the drawing of the wire is enabled.
        Standard_Boolean WireDraw();

        //! Returns true if the drawer has its own attribute for
        //! "draw wires" flag that overrides the one in the link.
        Standard_Boolean HasOwnWireDraw();

        //! Returns the point aspect setting. The default values are
        //!   Color: Quantity_NOC_YELLOW
        //!   Type of marker: Aspect_TOM_PLUS
        //!   Scale: 1.0
        //! These attributes are used by the algorithms Prs3d_Point.
        Handle(Prs3d_PointAspect) PointAspect();

        //! Sets the parameter theAspect for display attributes of points
        void SetPointAspect(const Handle(Prs3d_PointAspect)& theAspect);

        //! Returns true if the drawer has its own attribute for
        //! point aspect that overrides the one in the link.
        Standard_Boolean HasOwnPointAspect();

        //! Sets own point aspect.
        //! Returns FALSE if the drawer already has its own attribute for point aspect.
        //! theDefaults = Handle(Prs3d_Drawer)()
        Standard_Boolean SetupOwnPointAspect(XPrs3d_Drawer^ theDefaults);

        //! Returns settings for line aspects.
        //! These settings can be edited. The default values are:
        //!   Color: Quantity_NOC_YELLOW
        //!   Type of line: Aspect_TOL_SOLID
        //!   Width: 1.0
        //! These attributes are used by the following algorithms:
        //!   Prs3d_Curve
        //!   Prs3d_Line
        //!   Prs3d_HLRShape
        Handle(Prs3d_LineAspect) LineAspect();

        //! Sets the parameter theAspect for display attributes of lines.
        void SetLineAspect(const Handle(Prs3d_LineAspect)& theAspect);

        //! Returns true if the drawer has its own attribute for
        //! line aspect that overrides the one in the link.
        Standard_Boolean HasOwnLineAspect();

        //! Sets own line aspects.
        //! Returns FALSE if own line aspect are already set.
        //! theDefaults = Handle(Prs3d_Drawer)()
        Standard_Boolean SetOwnLineAspects(XPrs3d_Drawer^ theDefaults);

        //! Sets own line aspects for datums.
        //! Returns FALSE if own line for datums are already set.
        //! theDefaults = Handle(Prs3d_Drawer)()
        Standard_Boolean SetOwnDatumAspects(XPrs3d_Drawer^ theDefaults);

        //! Returns settings for text aspect.
        //! These settings can be edited. The default value is:
        //! - Color: Quantity_NOC_YELLOW
        Handle(Prs3d_TextAspect) TextAspect();

        //! Sets the parameter theAspect for display attributes of text.
        void SetTextAspect(const Handle(Prs3d_TextAspect)& theAspect);

        //! Returns true if the drawer has its own attribute for
        //! text aspect that overrides the one in the link.
        Standard_Boolean HasOwnTextAspect();

        //! Returns settings for shading aspects.
        //! These settings can be edited. The default values are:
        //! -   Color: Quantity_NOC_YELLOW
        //! -   Material: Graphic3d_NOM_BRASS
        //! Shading aspect is obtained through decomposition of
        //! 3d faces into triangles, each side of each triangle
        //! being a chord of the corresponding curved edge in the face.
        //! Reflection of light in each projector perspective is then calculated for each of the
        //! resultant triangular planes.
        Handle(Prs3d_ShadingAspect) ShadingAspect();

        //! Sets the parameter theAspect for display attributes of shading.
         void SetShadingAspect(const Handle(Prs3d_ShadingAspect)& theAspect);

        //! Returns true if the drawer has its own attribute for
        //! shading aspect that overrides the one in the link.
         Standard_Boolean HasOwnShadingAspect();

        //! Sets own shading aspect.
        //! Returns FALSE if the drawer already has its own attribute for shading aspect.
        //! theDefaults = Handle(Prs3d_Drawer)()
        Standard_Boolean SetupOwnShadingAspect(XPrs3d_Drawer^ theDefaults);

        //! Returns settings for seen line aspects.
        //! These settings can be edited. The default values are:
        //!   Color: Quantity_NOC_YELLOW
        //!   Type of line: Aspect_TOL_SOLID
        //!   Width: 1.0
        Handle(Prs3d_LineAspect) SeenLineAspect();

        //! Sets the parameter theAspect for the display of seen lines in hidden line removal mode.
        void SetSeenLineAspect(const Handle(Prs3d_LineAspect)& theAspect);

        //! Returns true if the drawer has its own attribute for
        //! seen line aspect that overrides the one in the link.
        Standard_Boolean HasOwnSeenLineAspect();

        //! Returns settings for the appearance of planes.
        Handle(Prs3d_PlaneAspect) PlaneAspect();

        //! Sets the parameter theAspect for the display of planes. 
        void SetPlaneAspect(const Handle(Prs3d_PlaneAspect)& theAspect);

        //! Returns true if the drawer has its own attribute for
        //! plane aspect that overrides the one in the link.
        Standard_Boolean HasOwnPlaneAspect();

        //! Returns the attributes for display of arrows.
        Handle(Prs3d_ArrowAspect) ArrowAspect();

        //! Sets the parameter theAspect for display attributes of arrows.
        void SetArrowAspect(const Handle(Prs3d_ArrowAspect)& theAspect);

        //! Returns true if the drawer has its own attribute for
        //! arrow aspect that overrides the one in the link.
        Standard_Boolean HasOwnArrowAspect();

        //! Enables the drawing of an arrow at the end of each line.
        //! By default the arrows are not drawn.
        void SetLineArrowDraw(const Standard_Boolean theIsEnabled);

        //! Returns True if drawing an arrow at the end of each edge is enabled
        //! and False otherwise (the default).
        Standard_Boolean LineArrowDraw();

        //! Returns true if the drawer has its own attribute for
        //! "draw arrow" flag that overrides the one in the link.
        Standard_Boolean HasOwnLineArrowDraw();

        //! Returns settings for hidden line aspects.
        //! These settings can be edited. The default values are:
        //!   Color: Quantity_NOC_YELLOW
        //!   Type of line: Aspect_TOL_DASH
        //!   Width: 1.0
        Handle(Prs3d_LineAspect) HiddenLineAspect();

        //! Sets the parameter theAspect for the display of hidden lines in hidden line removal mode.
        void SetHiddenLineAspect(const Handle(Prs3d_LineAspect)& theAspect);

        //! Returns true if the drawer has its own attribute for
        //! hidden lines aspect that overrides the one in the link.
        Standard_Boolean HasOwnHiddenLineAspect();

        //! Returns Standard_True if the hidden lines are to be drawn.
        //! By default the hidden lines are not drawn.
        Standard_Boolean DrawHiddenLine();

        //! Enables the DrawHiddenLine function.
        void EnableDrawHiddenLine();

        //! Disables the DrawHiddenLine function.
        void DisableDrawHiddenLine();

        //! Returns true if the drawer has its own attribute for
        //! "draw hidden lines" flag that overrides the one in the link.
        Standard_Boolean HasOwnDrawHiddenLine();

        //! Returns settings for the appearance of vectors.
        //! These settings can be edited. The default values are:
        //!   Color: Quantity_NOC_SKYBLUE
        //!   Type of line: Aspect_TOL_SOLID
        //!   Width: 1.0
        Handle(Prs3d_LineAspect) VectorAspect();

        //! Sets the modality theAspect for the display of vectors.
        void SetVectorAspect(const Handle(Prs3d_LineAspect)& theAspect);

        //! Returns true if the drawer has its own attribute for
        //! vector aspect that overrides the one in the link.
        Standard_Boolean HasOwnVectorAspect();

        //! Sets the mode of visualization of vertices of a TopoDS_Shape instance.
        //! By default, only stand-alone vertices (not belonging topologically to an edge) are drawn,
        //! that corresponds to Prs3d_VDM_Standalone mode. 
        //! Switching to Prs3d_VDM_Standalone mode makes all shape's vertices visible.
        //! To inherit this parameter from the global drawer instance ("the link") when it is present,
        //! Prs3d_VDM_Inherited value should be used.
        void SetVertexDrawMode(XPrs3d_VertexDrawMode theMode);

        //! Returns the current mode of visualization of vertices of a TopoDS_Shape instance.
        XPrs3d_VertexDrawMode VertexDrawMode();

        //! Returns true if the vertex draw mode is not equal to <b>Prs3d_VDM_Inherited</b>. 
        //! This means that individual vertex draw mode value (i.e. not inherited from the global 
        //! drawer) is used for a specific interactive object.
        Standard_Boolean HasOwnVertexDrawMode();

        //! Returns settings for the appearance of datums.
        //! These settings can be edited. The default values for the three axes are:
        //!   Color: Quantity_NOC_PEACHPUFF
        //!   Type of line: Aspect_TOL_SOLID
        //!   Width: 1.0
        Handle(Prs3d_DatumAspect) DatumAspect();

        //! Sets the modality theAspect for the display of datums.
        void SetDatumAspect(const Handle(Prs3d_DatumAspect)& theAspect);

        //! Returns true if the drawer has its own attribute for
        //! datum aspect that overrides the one in the link.
        Standard_Boolean HasOwnDatumAspect();

        //! The LineAspect for the wire can be edited.
        //! The default values are:
        //!   Color: Quantity_NOC_ORANGE
        //!   Type of line: Aspect_TOL_SOLID
        //!   Width: 1.0
        //! These attributes are used by the algorithm Prs3d_WFShape.
        Handle(Prs3d_LineAspect) SectionAspect();

        //! Sets the parameter theAspect for display attributes of sections. 
        void SetSectionAspect(const Handle(Prs3d_LineAspect)& theAspect);

        //! Returns true if the drawer has its own attribute for
        //! section aspect that overrides the one in the link.
        Standard_Boolean HasOwnSectionAspect();

        //! Sets the parameter theAspect for the display of free boundaries.
        //! The method sets aspect owned by the drawer that will be used during
        //! visualization instead of the one set in link.
        void SetFreeBoundaryAspect(const Handle(Prs3d_LineAspect)& theAspect);

        //! Returns the values for presentation of free boundaries,
        //! in other words, boundaries which are not shared.
        //! The LineAspect for the  free boundaries can be edited.
        //! The default values are:
        //!   Color: Quantity_NOC_GREEN
        //!   Type of line: Aspect_TOL_SOLID
        //!   Width: 1.0
        //! These attributes are used by the algorithm Prs3d_WFShape
        Handle(Prs3d_LineAspect) FreeBoundaryAspect();

        //! Returns true if the drawer has its own attribute for
        //! free boundaries aspect that overrides the one in the link.
        Standard_Boolean HasOwnFreeBoundaryAspect();

        //! Enables or disables drawing of free boundaries for shading presentations.
        //! The method sets drawing flag owned by the drawer that will be used during
        //! visualization instead of the one set in link.
        //! theIsEnabled is a boolean flag indicating whether the free boundaries should be
        //! drawn or not.
        void SetFreeBoundaryDraw(const Standard_Boolean theIsEnabled);

        //! Returns True if the drawing of the free boundaries is enabled
        //! True is the default setting.
        Standard_Boolean FreeBoundaryDraw();

        //! Returns true if the drawer has its own attribute for
        //! "draw free boundaries" flag that overrides the one in the link.
        Standard_Boolean HasOwnFreeBoundaryDraw();

        //! Sets the parameter theAspect for the display of shared boundaries.
        //! The method sets aspect owned by the drawer that will be used during
        //! visualization instead of the one set in link.
        void SetUnFreeBoundaryAspect(const Handle(Prs3d_LineAspect)& theAspect);

        //! Returns settings for shared boundary line aspects.
        //! The LineAspect for the unfree boundaries can be edited.
        //! The default values are:
        //! Color: Quantity_NOC_YELLOW
        //! Type of line: Aspect_TOL_SOLID
        //! Width: 1.
        //! These attributes are used by the algorithm Prs3d_WFShape
        Handle(Prs3d_LineAspect) UnFreeBoundaryAspect();

        //! Returns true if the drawer has its own attribute for
        //! unfree boundaries aspect that overrides the one in the link.
        Standard_Boolean HasOwnUnFreeBoundaryAspect();

        //! Enables or disables drawing of shared boundaries for shading presentations.
        //! The method sets drawing flag owned by the drawer that will be used during
        //! visualization instead of the one set in link.
        //! theIsEnabled is a boolean flag indicating whether the shared boundaries should be drawn or not.
        void SetUnFreeBoundaryDraw(const Standard_Boolean theIsEnabled);

        //! Returns True if the drawing of the shared boundaries is enabled.
        //! True is the default setting.
        Standard_Boolean UnFreeBoundaryDraw();

        //! Returns true if the drawer has its own attribute for
        //! "draw shared boundaries" flag that overrides the one in the link.
        Standard_Boolean HasOwnUnFreeBoundaryDraw();

        //! Sets line aspect for face boundaries.
        //! The method sets line aspect owned by the drawer that will be used during
        //! visualization instead of the one set in link.
        //! theAspect is the line aspect that determines the look of the face boundaries.
        void SetFaceBoundaryAspect(const Handle(Prs3d_LineAspect)& theAspect);

        //! Returns line aspect of face boundaries.
        Handle(Prs3d_LineAspect) FaceBoundaryAspect();

        //! Returns true if the drawer has its own attribute for
        //! face boundaries aspect that overrides the one in the link.
        Standard_Boolean HasOwnFaceBoundaryAspect();

        //! Sets own face boundary aspect.
        //! Returns FALSE if the drawer already has its own attribute for face boundary aspect.
        //! theDefaults = Handle(Prs3d_Drawer)()
        Standard_Boolean SetupOwnFaceBoundaryAspect(XPrs3d_Drawer^ theDefaults);

        //! Enables or disables face boundary drawing for shading presentations. 
        //! The method sets drawing flag owned by the drawer that will be used during
        //! visualization instead of the one set in link.
        //! theIsEnabled is a boolean flag indicating whether the face boundaries should be drawn or not.
        void SetFaceBoundaryDraw(const Standard_Boolean theIsEnabled);

        //! Checks whether the face boundary drawing is enabled or not.
        Standard_Boolean FaceBoundaryDraw();

        //! Returns true if the drawer has its own attribute for
        //! "draw face boundaries" flag that overrides the one in the link.
        Standard_Boolean HasOwnFaceBoundaryDraw();

        //! Returns true if the drawer has its own attribute for face boundaries upper edge continuity class that overrides the one in the link.
        Standard_Boolean HasOwnFaceBoundaryUpperContinuity();

        //! Get the most edge continuity class; GeomAbs_CN by default (all edges).
        GeomAbs_Shape FaceBoundaryUpperContinuity();

        //! Set the most edge continuity class for face boundaries.
        void SetFaceBoundaryUpperContinuity(GeomAbs_Shape theMostAllowedEdgeClass);

        //! Unset the most edge continuity class for face boundaries.
        void UnsetFaceBoundaryUpperContinuity();

        //! Returns settings for the appearance of dimensions. 
        Handle(Prs3d_DimensionAspect) DimensionAspect();

        //! Sets the settings for the appearance of dimensions.
        //! The method sets aspect owned by the drawer that will be used during
        //! visualization instead of the one set in link.
        void SetDimensionAspect(const Handle(Prs3d_DimensionAspect)& theAspect);

        //! Returns true if the drawer has its own attribute for
        //! the appearance of dimensions that overrides the one in the link.
        Standard_Boolean HasOwnDimensionAspect();

        //! Sets dimension length model units for computing of dimension presentation.
        //! The method sets value owned by the drawer that will be used during
        //! visualization instead of the one set in link.
        void SetDimLengthModelUnits(const TCollection_AsciiString& theUnits);

        //! Sets dimension angle model units for computing of dimension presentation.
        //! The method sets value owned by the drawer that will be used during
        //! visualization instead of the one set in link.
        void SetDimAngleModelUnits(const TCollection_AsciiString& theUnits);

        //! Returns length model units for the dimension presentation. 
        TCollection_AsciiString DimLengthModelUnits();

        //! Returns angle model units for the dimension presentation. 
        TCollection_AsciiString DimAngleModelUnits();

        //! Returns true if the drawer has its own attribute for
        //! dimension length model units that overrides the one in the link.
        Standard_Boolean HasOwnDimLengthModelUnits();

        //! Returns true if the drawer has its own attribute for
        //! dimension angle model units that overrides the one in the link.
        Standard_Boolean HasOwnDimAngleModelUnits();

        //! Sets length units in which value for dimension presentation is displayed.
        //! The method sets value owned by the drawer that will be used during
        //! visualization instead of the one set in link.
        void SetDimLengthDisplayUnits(const TCollection_AsciiString& theUnits);

        //! Sets angle units in which value for dimension presentation is displayed.
        //! The method sets value owned by the drawer that will be used during
        //! visualization instead of the one set in link.
        void SetDimAngleDisplayUnits(const TCollection_AsciiString& theUnits);

        //! Returns length units in which dimension presentation is displayed.
        TCollection_AsciiString DimLengthDisplayUnits();

        //! Returns angle units in which dimension presentation is displayed.
        TCollection_AsciiString DimAngleDisplayUnits();

        //! Returns true if the drawer has its own attribute for
        //! length units in which dimension presentation is displayed
        //! that overrides the one in the link.
        Standard_Boolean HasOwnDimLengthDisplayUnits();

        //! Returns true if the drawer has its own attribute for
        //! angle units in which dimension presentation is displayed
        //! that overrides the one in the link.
        Standard_Boolean HasOwnDimAngleDisplayUnits();

        //! Returns the drawer to which the current object references.
        XPrs3d_Drawer^ Link();

        //! Returns true if the current object has a link on the other drawer.
        Standard_Boolean HasLink();

        //! Sets theDrawer as a link to which the current object references.
        void Link(XPrs3d_Drawer^ theDrawer);

        //! Sets theDrawer as a link to which the current object references.
        void SetLink(XPrs3d_Drawer^ theDrawer);

        //! Removes local attributes. 
        void ClearLocalAttributes();

        //! Assign shader program for specified type of primitives.
        //! @param theProgram new program to set (might be NULL)
        //! @param theAspect  the type of primitives
        //! @param theToOverrideDefaults if true then non-overridden attributes using defaults will be allocated and copied from the Link;
        //!                              otherwise, only already customized attributes will be changed
        //! @return TRUE if presentation should be recomputed after creating aspects not previously customized (if theToOverrideDefaults is also TRUE)
        //! theToOverrideDefaults = false
        bool SetShaderProgram(const Handle(Graphic3d_ShaderProgram)& theProgram, Graphic3d_GroupAspect theAspect, bool theToOverrideDefaults);

        //! Sets Shading Model type for the shading aspect.
        //! theToOverrideDefaults = false
        bool SetShadingModel(XGraphic3d_TypeOfShadingModel theModel, bool theToOverrideDefaults);

        //! Dumps the content of me into the stream
        //! theDepth = -1
        void DumpJson(Standard_OStream& theOStream, Standard_Integer theDepth);
        /// <summary>
       /// ±¾µØ¾ä±ú
       /// </summary>
        property Handle(Prs3d_Drawer) Handle
        {
            Handle(Prs3d_Drawer) get() {
                return NativeHandle();
            }
        };
    private:
        NCollection_Haft<Handle(Prs3d_Drawer)> NativeHandle;
    };

   //! Standard_DEPRECATED("Class name is deprecated - use Prs3d_Drawer instead")
   //!     typedef Prs3d_Drawer Graphic3d_HighlightStyle;
}
#endif // _XPrs3d_Drawer_HeaderFile
