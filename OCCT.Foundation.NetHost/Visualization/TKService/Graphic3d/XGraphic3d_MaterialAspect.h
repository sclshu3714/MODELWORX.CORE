// Created by: NW,JPB,CAL
// Copyright (c) 1991-1999 Matra Datavision
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

#ifndef _XGraphic3d_MaterialAspect_HeaderFile
#define _XGraphic3d_MaterialAspect_HeaderFile
#pragma once
#include <NCollection_Haft.h>
#include <Graphic3d_MaterialAspect.hxx>
#include <Quantity_Color.hxx>
#include <XGraphic3d_NameOfMaterial.h>
#include <XTCollection_AsciiString.h>
#include <XQuantity_Color.h>
#include <XGraphic3d_TypeOfReflection.h>
#include <XGraphic3d_TypeOfMaterial.h>
#include <XStandard_Helper.h>

#include <Graphic3d_BSDF.hxx>

using namespace TKernel;

//! This class allows the definition of the type of a surface.
//! Aspect attributes of a 3d face.
//! Keywords: Material, FillArea, Shininess, Ambient, Color, Diffuse,
//! Specular, Transparency, Emissive, ReflectionMode,
//! BackFace, FrontFace, Reflection, Absorbtion
namespace TKService {
    ref class TKernel::XStandard_Helper;
    public ref class XGraphic3d_MaterialAspect
    {
    public:
        //! DEFINE_STANDARD_ALLOC

        //! Returns the number of predefined textures.
        static Standard_Integer NumberOfMaterials();

        //! Returns the name of the predefined material of specified rank within range [1, NumberOfMaterials()].
        static System::String^ MaterialName(const Standard_Integer theRank);

        //! Returns the type of the predefined material of specified rank within range [1, NumberOfMaterials()].
        static XGraphic3d_TypeOfMaterial MaterialType(const Standard_Integer theRank);

        //! Finds the material for specified name.
        //! @param theName [in]  name to find
        //! @param theMat  [out] found material
        //! @return FALSE if name was unrecognized
        static Standard_Boolean MaterialFromName(System::String^ theName, XGraphic3d_NameOfMaterial theMat);

        //! Returns the material for specified name or Graphic3d_NOM_DEFAULT if name is unknown.
        static XGraphic3d_NameOfMaterial MaterialFromName(System::String^ theName)
        {
            XGraphic3d_NameOfMaterial aMat = XGraphic3d_NameOfMaterial(Graphic3d_NOM_DEFAULT);
            MaterialFromName(theName, aMat);
            return aMat;
        }

    public:

        //! Creates a material from default values.
        XGraphic3d_MaterialAspect();
        !XGraphic3d_MaterialAspect() { IHandle = NULL; };
        ~XGraphic3d_MaterialAspect() { IHandle = NULL; };
        //! Creates a generic material.
        XGraphic3d_MaterialAspect(XGraphic3d_NameOfMaterial theName);

        XGraphic3d_MaterialAspect(Graphic3d_MaterialAspect* pos);

        virtual Graphic3d_MaterialAspect* GetMaterialAspect();

        //! Returns the material name (within predefined enumeration).
        XGraphic3d_NameOfMaterial Name();

        //! Returns the material name within predefined enumeration which has been requested (before modifications).
        XGraphic3d_NameOfMaterial RequestedName();

        //! Returns the given name of this material. This might be:
        //! - given name set by method ::SetMaterialName()
        //! - standard name for a material within enumeration
        //! - "UserDefined" for non-standard material without name specified externally.
        XTCollection_AsciiString^ StringName();

        //! Returns the given name of this material. This might be:
        System::String^ MaterialName();

        //! The current material become a "UserDefined" material.
        //! Set the name of the "UserDefined" material.
        void SetMaterialName(XTCollection_AsciiString^ theName);

        //! Resets the material with the original values according to
        //! the material name but leave the current color values untouched
        //! for the material of type ASPECT.
        void Reset();

        //! Returns the diffuse color of the surface.
        //! WARNING! This method does NOT return color for Graphic3d_MATERIAL_ASPECT material (color is defined by Graphic3d_Aspects::InteriorColor()).
        XQuantity_Color^ Color();

        //! Modifies the ambient and diffuse color of the surface.
        //! WARNING! Has no effect for Graphic3d_MATERIAL_ASPECT material (color should be set to Graphic3d_Aspects::SetInteriorColor()).
        void SetColor(XQuantity_Color^ theColor);

        //! Returns the transparency coefficient of the surface (1.0 - Alpha); 0.0 means opaque.
        Standard_ShortReal Transparency();

        //! Returns the alpha coefficient of the surface (1.0 - Transparency); 1.0 means opaque.
        Standard_ShortReal Alpha();

        //! Modifies the transparency coefficient of the surface, where 0 is opaque and 1 is fully transparent.
        //! Transparency is applicable to materials that have at least one of reflection modes (ambient, diffuse, specular or emissive) enabled.
        //! See also SetReflectionModeOn() and SetReflectionModeOff() methods.
        //!
        //! Warning: Raises MaterialDefinitionError if given value is a negative value or greater than 1.0.
        void SetTransparency(const Standard_ShortReal theValue);

        //! Modifies the alpha coefficient of the surface, where 1.0 is opaque and 0.0 is fully transparent.
        void SetAlpha(Standard_ShortReal theValue);

        //! Returns the ambient color of the surface.
        XQuantity_Color^ AmbientColor();

        //! Modifies the ambient color of the surface.
        void SetAmbientColor(XQuantity_Color^ theColor);

        //! Returns the diffuse color of the surface.
        XQuantity_Color^ DiffuseColor();

        //! Modifies the diffuse color of the surface.
        void SetDiffuseColor(XQuantity_Color^ theColor);

        //! Returns the specular color of the surface.
        XQuantity_Color^ SpecularColor();

        //! Modifies the specular color of the surface.
        void SetSpecularColor(XQuantity_Color^ theColor);

        //! Returns the emissive color of the surface.
        XQuantity_Color^ EmissiveColor();

        //! Modifies the emissive color of the surface.
        void SetEmissiveColor(XQuantity_Color^ theColor);

        //! Returns the luminosity of the surface.
        Standard_ShortReal Shininess();

        //! Modifies the luminosity of the surface.
        //! Warning: Raises MaterialDefinitionError if given value is a negative value or greater than 1.0.
        void SetShininess(const Standard_ShortReal theValue);

        //! Increases or decreases the luminosity.
        //! @param theDelta a signed percentage
        void IncreaseShine(const Standard_ShortReal theDelta);

        //! Returns the refraction index of the material
        Standard_ShortReal RefractionIndex();

        //! Modifies the refraction index of the material.
        //! Warning: Raises MaterialDefinitionError if given value is a lesser than 1.0.
        void SetRefractionIndex(const Standard_ShortReal theValue);

        //! Returns BSDF (bidirectional scattering distribution function).
        const Graphic3d_BSDF& BSDF();

        //! Modifies the BSDF (bidirectional scattering distribution function).
        void SetBSDF(const Graphic3d_BSDF& theBSDF);

        //! Returns TRUE if the reflection mode is active, FALSE otherwise.
        Standard_Boolean ReflectionMode(XGraphic3d_TypeOfReflection theType);

        //! Returns material type.
        XGraphic3d_TypeOfMaterial MaterialType();

        //! Returns TRUE if type of this material is equal to specified type.
        Standard_Boolean MaterialType(XGraphic3d_TypeOfMaterial theType);

        //! Set material type.
        void SetMaterialType(XGraphic3d_TypeOfMaterial theType);

        //! Returns TRUE if this material differs from specified one.
        Standard_Boolean IsDifferent(XGraphic3d_MaterialAspect^ theOther);

        //! Returns TRUE if this material differs from specified one.
        Standard_Boolean operator!= (XGraphic3d_MaterialAspect^ theOther) { return IsDifferent(theOther); }

        //! Returns TRUE if this material is identical to specified one.
        Standard_Boolean IsEqual(XGraphic3d_MaterialAspect^ theOther);

        //! Returns TRUE if this material is identical to specified one.
        Standard_Boolean operator== (XGraphic3d_MaterialAspect^ theOther) { return IsEqual(theOther); }

        /// <summary>
        /// ±¾µØ¾ä±ú
        /// </summary>
        property Graphic3d_MaterialAspect* IHandle
        {
            Graphic3d_MaterialAspect* get() {
                return NativeHandle;
            }
            void set(Graphic3d_MaterialAspect* handle) {
                NativeHandle = handle;
            }
        };
    private:
        Graphic3d_MaterialAspect* NativeHandle;

    };
}
#endif // _XGraphic3d_MaterialAspect_HeaderFile
