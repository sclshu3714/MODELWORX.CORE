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

#include <XGraphic3d_MaterialAspect.h>


namespace TKV3d  {

    //! Returns the number of predefined textures.
    //! static 
    Standard_Integer XGraphic3d_MaterialAspect::NumberOfMaterials() {
        return Graphic3d_MaterialAspect::NumberOfMaterials();
    };

    //! Returns the name of the predefined material of specified rank within range [1, NumberOfMaterials()].
    //! static 
    System::String^ XGraphic3d_MaterialAspect::MaterialName(const Standard_Integer theRank) {
        Standard_CString SCString = Graphic3d_MaterialAspect::MaterialName(theRank);
        return XStandard_Helper::toString(SCString);
    };
    //! Returns the type of the predefined material of specified rank within range [1, NumberOfMaterials()].
    //! static 
    XGraphic3d_TypeOfMaterial XGraphic3d_MaterialAspect::MaterialType(const Standard_Integer theRank) {
        return safe_cast<XGraphic3d_TypeOfMaterial>(Graphic3d_MaterialAspect::MaterialType(theRank));
    };

    //! Finds the material for specified name.
    //! @param theName [in]  name to find
    //! @param theMat  [out] found material
    //! @return FALSE if name was unrecognized
    //! static                       
    Standard_Boolean XGraphic3d_MaterialAspect::MaterialFromName(System::String^ theName, XGraphic3d_NameOfMaterial theMat) {
        TCollection_AsciiString TAsciiString = XStandard_Helper::toAsciiString(theName);
        Graphic3d_NameOfMaterial thegMat = safe_cast<Graphic3d_NameOfMaterial>(theMat);
        return Graphic3d_MaterialAspect::MaterialFromName(TAsciiString.ToCString(), thegMat);
    };


    //! Creates a material from default values.
    XGraphic3d_MaterialAspect::XGraphic3d_MaterialAspect() {
        NativeHandle = new Graphic3d_MaterialAspect();
    };

    //! Creates a generic material.
    XGraphic3d_MaterialAspect::XGraphic3d_MaterialAspect(XGraphic3d_NameOfMaterial theName) {
        NativeHandle = new Graphic3d_MaterialAspect(safe_cast<Graphic3d_NameOfMaterial>(theName));
    };

    Graphic3d_MaterialAspect XGraphic3d_MaterialAspect::GetMaterialAspect() {
        return *NativeHandle;
    };

    //! Returns the material name (within predefined enumeration).
    XGraphic3d_NameOfMaterial XGraphic3d_MaterialAspect::Name() {
        return safe_cast<XGraphic3d_NameOfMaterial>(NativeHandle->Name());
    };

    //! Returns the material name within predefined enumeration which has been requested (before modifications).
    XGraphic3d_NameOfMaterial XGraphic3d_MaterialAspect::RequestedName() {
        return safe_cast<XGraphic3d_NameOfMaterial>(NativeHandle->RequestedName());
    };

    //! Returns the given name of this material. This might be:
    //! - given name set by method ::SetMaterialName()
    //! - standard name for a material within enumeration
    //! - "UserDefined" for non-standard material without name specified externally.
    XTCollection_AsciiString^ XGraphic3d_MaterialAspect::StringName() {
        return gcnew XTCollection_AsciiString(NativeHandle->StringName());
    };

    //! Returns the given name of this material. This might be:
    System::String^ XGraphic3d_MaterialAspect::MaterialName() {
        Standard_CString SCString = NativeHandle->MaterialName();
        return XStandard_Helper::toString(SCString);
    };

    //! The current material become a "UserDefined" material.
    //! Set the name of the "UserDefined" material.
    void XGraphic3d_MaterialAspect::SetMaterialName(XTCollection_AsciiString^ theName) {
        NativeHandle->SetMaterialName(theName->GetAsciiString());
    };

    //! Resets the material with the original values according to
    //! the material name but leave the current color values untouched
    //! for the material of type ASPECT.
    void XGraphic3d_MaterialAspect::Reset() {
        NativeHandle->Reset();
    };

    //! Returns the diffuse color of the surface.
    //! WARNING! This method does NOT return color for Graphic3d_MATERIAL_ASPECT material (color is defined by Graphic3d_Aspects::InteriorColor()).
    XQuantity_Color^ XGraphic3d_MaterialAspect::Color() {
        return gcnew XQuantity_Color(NativeHandle->Color());
    };

    //! Modifies the ambient and diffuse color of the surface.
    //! WARNING! Has no effect for Graphic3d_MATERIAL_ASPECT material (color should be set to Graphic3d_Aspects::SetInteriorColor()).
    void XGraphic3d_MaterialAspect::SetColor(XQuantity_Color^ theColor) {
        NativeHandle->SetColor(theColor->GetColor());
    };

    //! Returns the transparency coefficient of the surface (1.0 - Alpha); 0.0 means opaque.
    Standard_ShortReal XGraphic3d_MaterialAspect::Transparency() {
        return NativeHandle->Transparency();
    };

    //! Returns the alpha coefficient of the surface (1.0 - Transparency); 1.0 means opaque.
    Standard_ShortReal XGraphic3d_MaterialAspect::Alpha() {
        return NativeHandle->Alpha();
    };

    //! Modifies the transparency coefficient of the surface, where 0 is opaque and 1 is fully transparent.
    //! Transparency is applicable to materials that have at least one of reflection modes (ambient, diffuse, specular or emissive) enabled.
    //! See also SetReflectionModeOn() and SetReflectionModeOff() methods.
    //!
    //! Warning: Raises MaterialDefinitionError if given value is a negative value or greater than 1.0.
    void XGraphic3d_MaterialAspect::SetTransparency(const Standard_ShortReal theValue) {
        NativeHandle->SetTransparency(theValue);
    };

    //! Modifies the alpha coefficient of the surface, where 1.0 is opaque and 0.0 is fully transparent.
    void XGraphic3d_MaterialAspect::SetAlpha(Standard_ShortReal theValue) {
        NativeHandle->SetAlpha(theValue);
    };

    //! Returns the ambient color of the surface.
    XQuantity_Color^ XGraphic3d_MaterialAspect::AmbientColor() {
        return gcnew XQuantity_Color(NativeHandle->AmbientColor());
    };

    //! Modifies the ambient color of the surface.
    void XGraphic3d_MaterialAspect::SetAmbientColor(XQuantity_Color^ theColor) {
        NativeHandle->SetAmbientColor(theColor->GetColor());
    };

    //! Returns the diffuse color of the surface.
    XQuantity_Color^ XGraphic3d_MaterialAspect::DiffuseColor() {
        return gcnew XQuantity_Color(NativeHandle->DiffuseColor());
    };

    //! Modifies the diffuse color of the surface.
    void XGraphic3d_MaterialAspect::SetDiffuseColor(XQuantity_Color^ theColor) {
        NativeHandle->SetDiffuseColor(theColor->GetColor());
    };

    //! Returns the specular color of the surface.
    XQuantity_Color^ XGraphic3d_MaterialAspect::SpecularColor() {
        return gcnew XQuantity_Color(NativeHandle->SpecularColor());
    };

    //! Modifies the specular color of the surface.
    void XGraphic3d_MaterialAspect::SetSpecularColor(XQuantity_Color^ theColor) {
        NativeHandle->SetSpecularColor(theColor->GetColor());
    };

    //! Returns the emissive color of the surface.
    XQuantity_Color^ XGraphic3d_MaterialAspect::EmissiveColor() {
        return gcnew XQuantity_Color(NativeHandle->EmissiveColor());
    };

    //! Modifies the emissive color of the surface.
    void XGraphic3d_MaterialAspect::SetEmissiveColor(XQuantity_Color^ theColor) {
        NativeHandle->SetEmissiveColor(theColor->GetColor());
    };

    //! Returns the luminosity of the surface.
    Standard_ShortReal XGraphic3d_MaterialAspect::Shininess() {
        return NativeHandle->Shininess();
    };

    //! Modifies the luminosity of the surface.
    //! Warning: Raises MaterialDefinitionError if given value is a negative value or greater than 1.0.
    void XGraphic3d_MaterialAspect::SetShininess(const Standard_ShortReal theValue) {
        NativeHandle->SetShininess(theValue);
    };

    //! Increases or decreases the luminosity.
    //! @param theDelta a signed percentage
    void XGraphic3d_MaterialAspect::IncreaseShine(const Standard_ShortReal theDelta) {
        NativeHandle->IncreaseShine(theDelta);
    };

    //! Returns the refraction index of the material
    Standard_ShortReal XGraphic3d_MaterialAspect::RefractionIndex() {
        return NativeHandle->RefractionIndex();
    };

    //! Modifies the refraction index of the material.
    //! Warning: Raises MaterialDefinitionError if given value is a lesser than 1.0.
    void XGraphic3d_MaterialAspect::SetRefractionIndex(const Standard_ShortReal theValue) {
        NativeHandle->SetRefractionIndex(theValue);
    };

    //! Returns BSDF (bidirectional scattering distribution function).
    const Graphic3d_BSDF& XGraphic3d_MaterialAspect::BSDF() {
        return NativeHandle->BSDF();
    };

    //! Modifies the BSDF (bidirectional scattering distribution function).
    void XGraphic3d_MaterialAspect::SetBSDF(const Graphic3d_BSDF& theBSDF) {
        NativeHandle->SetBSDF(theBSDF);
    };

    //! Returns TRUE if the reflection mode is active, FALSE otherwise.
    Standard_Boolean XGraphic3d_MaterialAspect::ReflectionMode(XGraphic3d_TypeOfReflection theType) {
        return NativeHandle->ReflectionMode(safe_cast<Graphic3d_TypeOfReflection>(theType));
    };

    //! Returns material type.
    XGraphic3d_TypeOfMaterial XGraphic3d_MaterialAspect::MaterialType() {
        return safe_cast<XGraphic3d_TypeOfMaterial>(NativeHandle->MaterialType());
    };

    //! Returns TRUE if type of this material is equal to specified type.
    Standard_Boolean XGraphic3d_MaterialAspect::MaterialType(XGraphic3d_TypeOfMaterial theType) {
        return NativeHandle->MaterialType(safe_cast<Graphic3d_TypeOfMaterial>(theType));
    };

    //! Set material type.
    void XGraphic3d_MaterialAspect::SetMaterialType(XGraphic3d_TypeOfMaterial theType) {
        NativeHandle->SetMaterialType(safe_cast<Graphic3d_TypeOfMaterial>(theType));
    };

    //! Returns TRUE if this material differs from specified one.
    Standard_Boolean XGraphic3d_MaterialAspect::IsDifferent(XGraphic3d_MaterialAspect^ theOther) {
        return NativeHandle->IsDifferent(theOther->GetMaterialAspect());
    };


    //! Returns TRUE if this material is identical to specified one.
    Standard_Boolean XGraphic3d_MaterialAspect::IsEqual(XGraphic3d_MaterialAspect^ theOther) {
        return NativeHandle->IsEqual(theOther->GetMaterialAspect());
    };
}
