// Created on: 1996-12-20
// Created by: Robert COUBLANC
// Copyright (c) 1996-1999 Matra Datavision
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

#ifndef _XAIS_Shape_HeaderFile
#define _XAIS_Shape_HeaderFile
#pragma once
#include <AIS_Shape.hxx>
#include <XAIS_InteractiveObject.h>
#include <XTopoDS_Shape.h>
#include <XPrs3d_Drawer.h>
#include <XPrs3d_TypeOfHLR.h>
#include "XQuantity_Color.h"
#include "xgp_Pnt2d.h"

#include <Bnd_Box.hxx>

//! A framework to manage presentation and selection of shapes.
//! AIS_Shape is the interactive object which is used the
//! most by   applications. There are standard functions
//! available which allow you to prepare selection
//! operations on the constituent elements of shapes -
//! vertices, edges, faces etc - in an open local context.
//! The selection modes specific to "Shape" type objects
//! are referred to as Standard Activation Mode. These
//! modes are only taken into account in open local
//! context and only act on Interactive Objects which
//! have redefined the virtual method
//! AcceptShapeDecomposition so that it returns true.
//! Several advanced functions are also available. These
//! include functions to manage deviation angle and
//! deviation coefficient - both HLR and non-HLR - of
//! an inheriting shape class. These services allow you to
//! select one type of shape interactive object for higher
//! precision drawing. When you do this, the
//! Prs3d_Drawer::IsOwn... functions corresponding to the
//! above deviation angle and coefficient functions return
//! true indicating that there is a local setting available
//! for the specific object.
//!
//! This class allows to map textures on shapes using native UV parametric space of underlying surface of each Face
//! (this means that texture will be visually duplicated on all Faces).
//! To generate texture coordinates, appropriate shading attribute should be set before computing presentation in AIS_Shaded display mode:
//! @code
//!   Handle(AIS_Shape) aPrs = new AIS_Shape();
//!   aPrs->Attributes()->SetupOwnShadingAspect();
//!   aPrs->Attributes()->ShadingAspect()->Aspect()->SetTextureMapOn();
//!   aPrs->Attributes()->ShadingAspect()->Aspect()->SetTextureMap (new Graphic3d_Texture2Dmanual (Graphic3d_NOT_2D_ALUMINUM));
//! @endcode
//! The texture itself is parametrized in (0,1)x(0,1).

using namespace TKBRep;
using namespace TKernel;
using namespace TKMath;
namespace TKV3d {

   ref class TKBRep::XTopoDS_Shape;
   ref class TKernel::XQuantity_Color;
   ref class TKMath::xgp_Pnt2d;
   public ref class XAIS_Shape : public XAIS_InteractiveObject
    {
       //! DEFINE_STANDARD_RTTIEXT(AIS_Shape, AIS_InteractiveObject)
    public:

        //! Initializes construction of the shape shap from wires,
        //! edges and vertices.
        XAIS_Shape(TopoDS_Shape shap);

        XAIS_Shape(XTopoDS_Shape^ shap);

        XAIS_Shape(Handle(AIS_Shape) pos);
        //! Returns index 0. This value refers to SHAPE from TopAbs_ShapeEnum
        virtual Standard_Integer Signature() Standard_OVERRIDE;

        //! Returns Object as the type of Interactive Object.
        virtual XAIS_KindOfInteractive Type() Standard_OVERRIDE;

        //! Returns true if the Interactive Object accepts shape decomposition.
        virtual Standard_Boolean AcceptShapeDecomposition() Standard_OVERRIDE;

        //! Return true if specified display mode is supported.
        virtual Standard_Boolean AcceptDisplayMode(const Standard_Integer theMode) Standard_OVERRIDE;

        //! Returns this shape object.
        XTopoDS_Shape^ Shape();

        //! Constructs an instance of the shape object theShape.
        void SetShape(XTopoDS_Shape^ theShape);

        //! Alias for ::SetShape().
        void Set(XTopoDS_Shape^ theShape) { SetShape(theShape); }

        //! Sets a local value for deviation coefficient for this specific shape.
        Standard_Boolean SetOwnDeviationCoefficient();

        //! Sets a local value for HLR deviation coefficient for this specific shape.
        Standard_Boolean SetOwnHLRDeviationCoefficient();

        //! Sets a local value for deviation angle for this specific shape.
        Standard_Boolean SetOwnDeviationAngle();

        //! Sets a local value for HLR deviation angle for this specific shape.
        Standard_Boolean SetOwnHLRDeviationAngle();

        //! Sets a local value for deviation coefficient for this specific shape.
        void SetOwnDeviationCoefficient(const Standard_Real aCoefficient);

        //! sets myOwnHLRDeviationCoefficient field in Prs3d_Drawer &
        //! recomputes presentation
        void SetOwnHLRDeviationCoefficient(const Standard_Real aCoefficient);

        //! this compute a new angle and Deviation from the value anAngle
        //! and set the values stored in myDrawer with these that become local to the shape
        void SetAngleAndDeviation(const Standard_Real anAngle);

        //! gives back the angle initial value put by the User.
        Standard_Real UserAngle();

        //! sets myOwnDeviationAngle field in Prs3d_Drawer & recomputes presentation
        void SetOwnDeviationAngle(const Standard_Real anAngle);

        //! this compute a new Angle and Deviation from the value anAngle for HLR
        //! and set the values stored in myDrawer for with these that become local to the shape
        void SetHLRAngleAndDeviation(const Standard_Real anAngle);

        //! sets myOwnHLRDeviationAngle field in Prs3d_Drawer & recomputes presentation
        void SetOwnHLRDeviationAngle(const Standard_Real anAngle);

        //! Returns true and the values of the deviation
        //! coefficient aCoefficient and the previous deviation
        //! coefficient aPreviousCoefficient. If these values are
        //! not already set, false is returned.
        Standard_Boolean OwnDeviationCoefficient(Standard_Real aCoefficient, Standard_Real aPreviousCoefficient);

        //! Returns   true and the values of the HLR deviation
        //! coefficient aCoefficient and the previous HLR
        //! deviation coefficient aPreviousCoefficient. If these
        //! values are not already set, false is returned.
        Standard_Boolean OwnHLRDeviationCoefficient(Standard_Real aCoefficient, Standard_Real aPreviousCoefficient);

        //! Returns true and the values of the deviation angle
        //! anAngle and the previous deviation angle aPreviousAngle.
        //! If these values are not already set, false is returned.
        Standard_Boolean OwnDeviationAngle(Standard_Real anAngle, Standard_Real aPreviousAngle);

        //! Returns true and the values   of the HLR deviation
        //! angle anAngle and of the previous HLR deviation
        //! angle aPreviousAngle. If these values are not
        //! already set, false is returned.
        Standard_Boolean OwnHLRDeviationAngle(Standard_Real anAngle, Standard_Real aPreviousAngle);

        //! Sets the type of HLR algorithm used by the shape
        void SetTypeOfHLR(XPrs3d_TypeOfHLR theTypeOfHLR);

        //! Gets the type of HLR algorithm
        XPrs3d_TypeOfHLR TypeOfHLR();

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
        virtual void SetColor(XQuantity_Color^ theColor) Standard_OVERRIDE;

        //! Removes settings for color in the reconstructed compound shape.
        virtual void UnsetColor() Standard_OVERRIDE;

        //! Sets the value aValue for line width in the reconstructed compound shape.
        //! Changes line aspects for lines presentation.
        virtual void SetWidth(const Standard_Real aValue) Standard_OVERRIDE;

        //! Removes the setting for line width in the reconstructed compound shape.
        virtual void UnsetWidth() Standard_OVERRIDE;

        //! Allows you to provide settings for the material aName
        //! in the reconstructed compound shape.
        virtual void SetMaterial(XGraphic3d_MaterialAspect^ aName) Standard_OVERRIDE;

        //! Removes settings for material in the reconstructed compound shape.
        virtual void UnsetMaterial() Standard_OVERRIDE;

        //! Sets the value aValue for transparency in the reconstructed compound shape.
        //! Standard_Real aValue = 0.6
        virtual void SetTransparency(const Standard_Real aValue) Standard_OVERRIDE;

        //! Removes the setting for transparency in the reconstructed compound shape.
        virtual void UnsetTransparency() Standard_OVERRIDE;

        //! Constructs a bounding box with which to reconstruct
        //! compound topological shapes for presentation.
        virtual Bnd_Box BoundingBox();

        //! AIS_InteractiveObject defines another virtual method BoundingBox,
        //! which is not the same as above; keep it visible.
        //using AIS_InteractiveObject::BoundingBox;

        //! Returns the Color attributes of the shape accordingly to
        //! the current facing model;
        virtual void Color(XQuantity_Color^ aColor) Standard_OVERRIDE;

        //! Returns the NameOfMaterial attributes of the shape accordingly to
        //! the current facing model;
        virtual XGraphic3d_NameOfMaterial Material() Standard_OVERRIDE;

        //! Returns the transparency attributes of the shape accordingly to
        //! the current facing model;
        virtual Standard_Real Transparency() Standard_OVERRIDE;

        //! Return shape type for specified selection mode.
        static XTopAbs_ShapeEnum SelectionType(const Standard_Integer theSelMode)
        {
            switch (theSelMode)
            {
            case 1: return XTopAbs_ShapeEnum(TopAbs_VERTEX);
            case 2: return XTopAbs_ShapeEnum(TopAbs_EDGE);
            case 3: return XTopAbs_ShapeEnum(TopAbs_WIRE);
            case 4: return XTopAbs_ShapeEnum(TopAbs_FACE);
            case 5: return XTopAbs_ShapeEnum(TopAbs_SHELL);
            case 6: return XTopAbs_ShapeEnum(TopAbs_SOLID);
            case 7: return XTopAbs_ShapeEnum(TopAbs_COMPSOLID);
            case 8: return XTopAbs_ShapeEnum(TopAbs_COMPOUND);
            case 0: return XTopAbs_ShapeEnum(TopAbs_SHAPE);
            }
            return XTopAbs_ShapeEnum(TopAbs_SHAPE);
        }

        //! Return selection mode for specified shape type.
        static Standard_Integer SelectionMode(XTopAbs_ShapeEnum theShapeType)
        {
            switch (theShapeType)
            {
            case XTopAbs_ShapeEnum(TopAbs_VERTEX):    return 1;
            case XTopAbs_ShapeEnum(TopAbs_EDGE):      return 2;
            case XTopAbs_ShapeEnum(TopAbs_WIRE):      return 3;
            case XTopAbs_ShapeEnum(TopAbs_FACE):      return 4;
            case XTopAbs_ShapeEnum(TopAbs_SHELL):     return 5;
            case XTopAbs_ShapeEnum(TopAbs_SOLID):     return 6;
            case XTopAbs_ShapeEnum(TopAbs_COMPSOLID): return 7;
            case XTopAbs_ShapeEnum(TopAbs_COMPOUND):  return 8;
            case XTopAbs_ShapeEnum(TopAbs_SHAPE):     return 0;
            }
            return 0;
        }

    public: //! @name methods to alter texture mapping properties

      //! Return texture repeat UV values; (1, 1) by default.
        xgp_Pnt2d^ TextureRepeatUV();

        //! Sets the number of occurrences of the texture on each face. The texture itself is parameterized in (0,1) by (0,1).
        //! Each face of the shape to be textured is parameterized in UV space (Umin,Umax) by (Vmin,Vmax).
        void SetTextureRepeatUV(xgp_Pnt2d^ theRepeatUV);

        //! Return texture origin UV position; (0, 0) by default.
        xgp_Pnt2d^ TextureOriginUV();

        //! Use this method to change the origin of the texture.
        //! The texel (0,0) will be mapped to the surface (myUVOrigin.X(), myUVOrigin.Y()).
        void SetTextureOriginUV(xgp_Pnt2d^ theOriginUV);

        //! Return scale factor for UV coordinates; (1, 1) by default.
        xgp_Pnt2d^ TextureScaleUV();

        //! Use this method to scale the texture (percent of the face).
        //! You can specify a scale factor for both U and V.
        //! Example: if you set ScaleU and ScaleV to 0.5 and you enable texture repeat,
        //!          the texture will appear twice on the face in each direction.
        void SetTextureScaleUV(xgp_Pnt2d^ theScaleUV);

        //! Compute HLR presentation for specified shape.
        static void computeHlrPresentation(const Handle(Prs3d_Projector)& theProjector, Handle(Prs3d_Presentation)& thePrs, XTopoDS_Shape^ theShape, XPrs3d_Drawer^ theDrawer);


        /// <summary>
        /// ±¾µØ¾ä±ú
        /// </summary>
        virtual property Handle(AIS_InteractiveObject) Handle
        {
            Handle(AIS_InteractiveObject) get() Standard_OVERRIDE {
                return NativeHandle();
            }
        };

    private:
        NCollection_Haft<Handle(AIS_Shape)> NativeHandle;

    };
    //! DEFINE_STANDARD_HANDLE(AIS_Shape, AIS_InteractiveObject)
}
#endif // _XAIS_Shape_HeaderFile
