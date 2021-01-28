// Created on: 2000-05-11
// Created by: Edward AGAPOV
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

#ifndef _XXCAFDoc_ColorTool_HeaderFile
#define _XXCAFDoc_ColorTool_HeaderFile
#pragma once
#include "NCollection_Haft.h"
#include "XCAFDoc_ColorTool.hxx"
#include "XStandard_GUID.h"
#include "XTDF_Label.h"
#include "XTDF_Attribute.h"
#include <XTDF_LabelSequence.h>
#include "XTopLoc_Location.h"
#include <XTopoDS_Shape.h>
#include <XXCAFDoc_ShapeTool.h>
#include <XQuantity_Color.h>
#include <XXCAFDoc_ColorType.h>

#include <Standard.hxx>
#include <Standard_Type.hxx>

#include <TDF_Attribute.hxx>
#include <Standard_Boolean.hxx>
#include <TDF_LabelSequence.hxx>
#include <XCAFDoc_ColorType.hxx>
class XCAFDoc_ShapeTool;
class TDF_Label;
class Standard_GUID;
class Quantity_Color;
class Quantity_ColorRGBA;
class TopoDS_Shape;
class TDF_Attribute;
class TDF_RelocationTable;
//class XCAFDoc_ColorTool;
//DEFINE_STANDARD_HANDLE(XCAFDoc_ColorTool, TDF_Attribute)

//! Provides tools to store and retrieve attributes (colors)
//! of TopoDS_Shape in and from TDocStd_Document
//! A Document is intended to hold different
//! attributes of ONE shape and it's sub-shapes
//! Provide tools for management of Colors section of document.
using namespace TKLCAF;
using namespace TKernel;
using namespace TKMath;
using namespace TKBRep;
namespace TKXCAF {
    ref class TKernel::XStandard_GUID;
    ref class TKernel::XQuantity_Color;
    ref class TKLCAF::XTDF_Attribute;
    ref class TKLCAF::XTDF_Label;
    ref class TKMath::XTopLoc_Location;
    ref class TKBRep::XTopoDS_Shape;
    ref class XXCAFDoc_ShapeTool;
    public ref class XXCAFDoc_ColorTool : public XTDF_Attribute
    {

    public:


        XXCAFDoc_ColorTool();

        //! Creates (if not exist) ColorTool.
        static XXCAFDoc_ColorTool^ Set(XTDF_Label^ L);

        static XStandard_GUID^ GetID();

        //! returns the label under which colors are stored
        XTDF_Label^ BaseLabel();

        //! Returns internal XCAFDoc_ShapeTool tool
        XXCAFDoc_ShapeTool^ ShapeTool();

        //! Returns True if label belongs to a colortable and
        //! is a color definition
        Standard_Boolean IsColor(XTDF_Label^ lab);

        //! Returns color defined by label lab
        //! Returns False if the label is not in colortable
        //! or does not define a color
        Standard_Boolean GetColor(XTDF_Label^ lab, XQuantity_Color^ col);

        //! Returns color defined by label lab
        //! Returns False if the label is not in colortable
        //! or does not define a color
        Standard_Boolean GetColor(XTDF_Label^ lab, Quantity_ColorRGBA col);

        //! Finds a color definition in a colortable and returns
        //! its label if found
        //! Returns False if color is not found in colortable
        Standard_Boolean FindColor(XQuantity_Color^ col, XTDF_Label^ lab);

        //! Finds a color definition in a colortable and returns
        //! its label if found
        //! Returns False if color is not found in colortable
        Standard_Boolean FindColor(Quantity_ColorRGBA& col, XTDF_Label^ lab);

        //! Finds a color definition in a colortable and returns
        //! its label if found (or Null label else)
        XTDF_Label^ FindColor(XQuantity_Color^ col);

        //! Finds a color definition in a colortable and returns
        //! its label if found (or Null label else)
        XTDF_Label^ FindColor(Quantity_ColorRGBA& col);

        //! Adds a color definition to a colortable and returns
        //! its label (returns existing label if the same color
        //! is already defined)
        XTDF_Label^ AddColor(XQuantity_Color^ col);

        //! Adds a color definition to a colortable and returns
        //! its label (returns existing label if the same color
        //! is already defined)
        XTDF_Label^ AddColor(Quantity_ColorRGBA& col);

        //! Removes color from the colortable
        void RemoveColor(XTDF_Label^ lab);

        //! Returns a sequence of colors currently stored
        //! in the colortable
        void GetColors(XTDF_LabelSequence^ Labels);

        //! Sets a link with GUID defined by <type> (see
        //! XCAFDoc::ColorRefGUID()) from label <L> to color
        //! defined by <colorL>. Color of shape is defined following way
        //! in dependance with type of color.
        //! If type of color is XCAFDoc_ColorGen - then this color
        //! defines default color for surfaces and curves.
        //! If for shape color with types XCAFDoc_ColorSurf or XCAFDoc_ColorCurv is specified
        //! then such color overrides generic color.
        void SetColor(XTDF_Label^ L, XTDF_Label^ colorL, XXCAFDoc_ColorType type);

        //! Sets a link with GUID defined by <type> (see
        //! XCAFDoc::ColorRefGUID()) from label <L> to color <Color>
        //! in the colortable
        //! Adds a color as necessary
        void SetColor(XTDF_Label^ L, XQuantity_Color^ Color, XXCAFDoc_ColorType type);

        //! Sets a link with GUID defined by <type> (see
        //! XCAFDoc::ColorRefGUID()) from label <L> to color <Color>
        //! in the colortable
        //! Adds a color as necessary
        void SetColor(XTDF_Label^ L, Quantity_ColorRGBA& Color, XXCAFDoc_ColorType type);

        //! Removes a link with GUID defined by <type> (see
        //! XCAFDoc::ColorRefGUID()) from label <L> to color
        void UnSetColor(XTDF_Label^ L, XXCAFDoc_ColorType type);

        //! Returns True if label <L> has a color assignment
        //! of the type <type>
        Standard_Boolean IsSet(XTDF_Label^ L, XXCAFDoc_ColorType type);

        //! Returns label with color assigned to <L> as <type>
        //! Returns False if no such color is assigned
        static Standard_Boolean GetColor(XTDF_Label^ L, XXCAFDoc_ColorType type, XTDF_Label^% colorL);

        //! Returns color assigned to <L> as <type>
        //! Returns False if no such color is assigned
        Standard_Boolean GetColor(XTDF_Label^ L, XXCAFDoc_ColorType type, XQuantity_Color^% color);

        //! Returns color assigned to <L> as <type>
        //! Returns False if no such color is assigned
        Standard_Boolean GetColor(XTDF_Label^ L, XXCAFDoc_ColorType type, Quantity_ColorRGBA& color);

        //! Sets a link with GUID defined by <type> (see
        //! XCAFDoc::ColorRefGUID()) from label <L> to color
        //! defined by <colorL>
        //! Returns False if cannot find a label for shape S
        Standard_Boolean SetColor(XTopoDS_Shape^ S, XTDF_Label^% colorL, XXCAFDoc_ColorType type);

        //! Sets a link with GUID defined by <type> (see
        //! XCAFDoc::ColorRefGUID()) from label <L> to color <Color>
        //! in the colortable
        //! Adds a color as necessary
        //! Returns False if cannot find a label for shape S
        Standard_Boolean SetColor(XTopoDS_Shape^ S, XQuantity_Color^ Color, XXCAFDoc_ColorType type);

        //! Sets a link with GUID defined by <type> (see
        //! XCAFDoc::ColorRefGUID()) from label <L> to color <Color>
        //! in the colortable
        //! Adds a color as necessary
        //! Returns False if cannot find a label for shape S
        Standard_Boolean SetColor(XTopoDS_Shape^ S, Quantity_ColorRGBA& Color, XXCAFDoc_ColorType type);

        //! Removes a link with GUID defined by <type> (see
        //! XCAFDoc::ColorRefGUID()) from label <L> to color
        //! Returns True if such link existed
        Standard_Boolean UnSetColor(XTopoDS_Shape^ S, XXCAFDoc_ColorType type);

        //! Returns True if label <L> has a color assignment
        //! of the type <type>
        Standard_Boolean IsSet(XTopoDS_Shape^ S, XXCAFDoc_ColorType type);

        //! Returns label with color assigned to <L> as <type>
        //! Returns False if no such color is assigned
        Standard_Boolean GetColor(XTopoDS_Shape^ S, XXCAFDoc_ColorType type, XTDF_Label^ colorL);

        //! Returns color assigned to <L> as <type>
        //! Returns False if no such color is assigned
        Standard_Boolean GetColor(XTopoDS_Shape^ S, XXCAFDoc_ColorType type, XQuantity_Color^ color);

        //! Returns color assigned to <L> as <type>
        //! Returns False if no such color is assigned
        Standard_Boolean GetColor(XTopoDS_Shape^ S, XXCAFDoc_ColorType type, Quantity_ColorRGBA& color);

        //! Return TRUE if object on this label is visible, FALSE if invisible.
        Standard_Boolean IsVisible(XTDF_Label^ L);

        //! Set the visibility of object on label. Do nothing if there no any object.
        //! Set UAttribute with corresponding GUID.
        //! Standard_Boolean isvisible = Standard_True
        void SetVisibility(XTDF_Label^ shapeLabel, Standard_Boolean isvisible);

        //! Return TRUE if object color defined by its Layer, FALSE if not.
        Standard_Boolean IsColorByLayer(XTDF_Label^ L);

        //! Set the Color defined by Layer flag on label. Do nothing if there no any object.
        //! Set UAttribute with corresponding GUID.
        //! Standard_Boolean isColorByLayer = Standard_False
        void SetColorByLayer(XTDF_Label^ shapeLabel, Standard_Boolean isColorByLayer);

        //! Sets the color of component that styled with SHUO structure
        //! Returns FALSE if no sush component found
        //! NOTE: create SHUO structeure if it is necessary and if <isCreateSHUO>
        //! Standard_Boolean isCreateSHUO = Standard_True
        Standard_Boolean SetInstanceColor(XTopoDS_Shape^ theShape, XXCAFDoc_ColorType type, XQuantity_Color^ color, Standard_Boolean isCreateSHUO);

        //! Sets the color of component that styled with SHUO structure
        //! Returns FALSE if no sush component found
        //! NOTE: create SHUO structeure if it is necessary and if <isCreateSHUO>
        //! Standard_Boolean isCreateSHUO = Standard_True
        Standard_Boolean SetInstanceColor(XTopoDS_Shape^ theShape, XXCAFDoc_ColorType type, Quantity_ColorRGBA& color, Standard_Boolean isCreateSHUO);

        //! Gets the color of component that styled with SHUO structure
        //! Returns FALSE if no sush component or color type
        Standard_Boolean GetInstanceColor(XTopoDS_Shape^ theShape, XXCAFDoc_ColorType type, XQuantity_Color^% color);

        //! Gets the color of component that styled with SHUO structure
        //! Returns FALSE if no sush component or color type
        Standard_Boolean GetInstanceColor(XTopoDS_Shape^ theShape, XXCAFDoc_ColorType type, Quantity_ColorRGBA& color);

        //! Gets the visibility status of component that styled with SHUO structure
        //! Returns FALSE if no sush component
        Standard_Boolean IsInstanceVisible(XTopoDS_Shape^ theShape);

        //! Reverses order in chains of TreeNodes (from Last to First) under
        //! each Color Label since we became to use function ::Prepend()
        //! instead of ::Append() in method SetColor() for acceleration
        Standard_Boolean ReverseChainsOfTreeNodes();

        XStandard_GUID^ ID() Standard_OVERRIDE;

        void Restore(XTDF_Attribute^ with) Standard_OVERRIDE;

        XTDF_Attribute^ NewEmpty() Standard_OVERRIDE;

        void Paste(XTDF_Attribute^ into, Handle(TDF_RelocationTable)& RT) Standard_OVERRIDE;

        //DEFINE_STANDARD_RTTIEXT(XCAFDoc_ColorTool, TDF_Attribute)
        /// <summary>
        /// ±¾µØ¾ä±ú
        /// </summary>
        virtual property Handle(Standard_Transient) IHandle {
            Handle(Standard_Transient) get() Standard_OVERRIDE {
                return NativeHandle();
            }
            void set(Handle(Standard_Transient) handle) Standard_OVERRIDE {
                if (!handle.IsNull())
                    NativeHandle() = Handle(XCAFDoc_ColorTool)::DownCast(handle);
                else if (!NativeHandle().IsNull())
                    NativeHandle() = NULL;
            }
        }
    private:
        NCollection_Haft<Handle(XCAFDoc_ColorTool)> NativeHandle;
    };
}
#endif // _XXCAFDoc_ColorTool_HeaderFile
