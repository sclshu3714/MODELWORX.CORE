// Created on: 1993-03-10
// Created by: JCV
// Copyright (c) 1993-1999 Matra Datavision
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

#ifndef _XGeom_Hyperbola_HeaderFile
#define _XGeom_Hyperbola_HeaderFile
#pragma once
#include <NCollection_Haft.h>
#include <Geom_Hyperbola.hxx>
#include <XGeom_Conic.h>  
#include <xgp_Hypr.h>
#include <xgp_Ax2.h>
#include <xgp_Ax1.h>
#include <xgp_Pnt.h>
#include <xgp_Vec.h>
#include <xgp_Trsf.h>
#include <XGeom_Geometry.h>

#include <Standard.hxx>
#include <Standard_Type.hxx>

#include <Standard_Real.hxx>
#include <Geom_Conic.hxx>
#include <Standard_Boolean.hxx>
#include <Standard_Integer.hxx>
class Standard_ConstructionError;
class Standard_DomainError;
class Standard_RangeError;
class gp_Hypr;
class gp_Ax2;
class gp_Ax1;
class gp_Pnt;
class gp_Vec;
class gp_Trsf;
class Geom_Geometry;
class Geom_Hyperbola;
//DEFINE_STANDARD_HANDLE(Geom_Hyperbola, Geom_Conic)
using namespace TKMath;
namespace TKG3d {
	ref class TKMath::xgp_Hypr;
	ref class TKMath::xgp_Ax2;
	ref class TKMath::xgp_Ax1;
	ref class TKMath::xgp_Pnt;
	ref class TKMath::xgp_Vec;
	ref class TKMath::xgp_Trsf;
	ref class XGeom_Geometry;
	ref class XGeom_Hyperbola;
	//! Describes a branch of a hyperbola in 3D space.
	//! A hyperbola is defined by its major and minor radii
	//! and, as with any conic curve, is positioned in space
	//! with a right-handed coordinate system (gp_Ax2 object) where:
	//! - the origin is the center of the hyperbola,
	//! - the "X Direction" defines the major axis, and
	//! - the "Y Direction" defines the minor axis.
	//! The origin, "X Direction" and "Y Direction" of this
	//! coordinate system define the plane of the hyperbola.
	//! The coordinate system is the local coordinate
	//! system of the hyperbola.
	//! The branch of the hyperbola described is the one
	//! located on the positive side of the major axis.
	//! The "main Direction" of the local coordinate system is
	//! a vector normal to the plane of the hyperbola. The
	//! axis, of which the origin and unit vector are
	//! respectively the origin and "main Direction" of the
	//! local coordinate system, is termed the "Axis" or "main
	//! Axis" of the hyperbola.
	//! The "main Direction" of the local coordinate system
	//! gives an explicit orientation to the hyperbola,
	//! determining the direction in which the parameter
	//! increases along the hyperbola.
	//! The Geom_Hyperbola hyperbola is parameterized as follows:
	//! P(U) = O + MajRad*Cosh(U)*XDir + MinRad*Sinh(U)*YDir, where:
	//! - P is the point of parameter U,
	//! - O, XDir and YDir are respectively the origin, "X
	//! Direction" and "Y Direction" of its local coordinate system,
	//! - MajRad and MinRad are the major and minor radii of the hyperbola.
	//! The "X Axis" of the local coordinate system therefore
	//! defines the origin of the parameter of the hyperbola.
	//! The parameter range is ] -infinite, +infinite [.
	//! The following diagram illustrates the respective
	//! positions, in the plane of the hyperbola, of the three
	//! branches of hyperbolas constructed using the
	//! functions OtherBranch, ConjugateBranch1 and
	//! ConjugateBranch2: Defines the main branch of an hyperbola.
	//! ^YAxis
	//! |
	//! FirstConjugateBranch
	//! |
	//! Other            |                Main
	//! --------------------- C ------------------------------>XAxis
	//! Branch           |                Branch
	//! |
	//! SecondConjugateBranch
	//! |
	//! Warning
	//! The value of the major radius (on the major axis) can
	//! be less than the value of the minor radius (on the minor axis).
	public ref class XGeom_Hyperbola : public XGeom_Conic
	{

	public:
		!XGeom_Hyperbola() { IHandle = NULL; };
		~XGeom_Hyperbola() { IHandle = NULL; };

		XGeom_Hyperbola();

		XGeom_Hyperbola(Handle(Geom_Hyperbola) pos);

		void SetHyperbolaHandle(Handle(Geom_Hyperbola) pos);

		virtual Handle(Geom_Hyperbola) GetHyperbola();

		virtual Handle(Geom_Conic) GetConic() Standard_OVERRIDE;

		//!
		virtual Handle(Geom_Curve) GetCurve() Standard_OVERRIDE;

		//!
		virtual Handle(Geom_Geometry) GetGeometry() Standard_OVERRIDE;

		//! Constructs a hyperbola by conversion of the gp_Hypr hyperbola H.
		XGeom_Hyperbola(xgp_Hypr^ H);

		//! Constructs a hyperbola defined by its major and
		//! minor radii, MajorRadius and MinorRadius, where A2 locates the
		//! hyperbola and defines its orientation in 3D space such that:
		//! - the center of the hyperbola is the origin of A2,
		//! - the "X Direction" of A2 defines the major axis
		//! of the hyperbola, i.e. the major radius
		//! MajorRadius is measured along this axis,
		//! - the "Y Direction" of A2 defines the minor axis
		//! of the hyperbola, i.e. the minor radius
		//! MinorRadius is measured along this axis,
		//! - A2 is the local coordinate system of the   hyperbola.
		//! Exceptions
		//! Standard_ConstructionError if:
		//! - MajorRadius is less than 0.0,
		//! - MinorRadius is less than 0.0.
		XGeom_Hyperbola(xgp_Ax2^ A2, Standard_Real MajorRadius, Standard_Real MinorRadius);

		//! Converts the gp_Hypr hyperbola H into this hyperbola.
		void SetHypr(xgp_Hypr^ H);

		//! Assigns a value to the major radius of this hyperbola.
		//! Exceptions
		//! Standard_ConstructionError if:
		//! - MajorRadius is less than 0.0, or
		//! - MinorRadius is less than 0.0.Raised if MajorRadius < 0.0
		void SetMajorRadius(Standard_Real MajorRadius);

		//! Assigns a value to the minor radius of this hyperbola.
		//! Exceptions
		//! Standard_ConstructionError if:
		//! - MajorRadius is less than 0.0, or
		//! - MinorRadius is less than 0.0.Raised if MajorRadius < 0.0
		void SetMinorRadius(Standard_Real MinorRadius);


		//! returns the non transient parabola from gp with the same
		//! geometric properties as <me>.
		xgp_Hypr^ Hypr();

		//! Computes the parameter on the reversed hyperbola,
		//! for the point of parameter U on this hyperbola.
		//! For a hyperbola, the returned value is: -U.
		Standard_Real ReversedParameter(Standard_Real U) Standard_OVERRIDE;

		//! Returns RealFirst from Standard.
		Standard_Real FirstParameter() Standard_OVERRIDE;

		//! returns RealLast from Standard.
		Standard_Real LastParameter() Standard_OVERRIDE;

		//! Returns False.
		Standard_Boolean IsClosed() Standard_OVERRIDE;

		//! return False for an hyperbola.
		Standard_Boolean IsPeriodic() Standard_OVERRIDE;


		//! In the local coordinate system of the hyperbola the equation of
		//! the hyperbola is (X*X)/(A*A) - (Y*Y)/(B*B) = 1.0 and the
		//! equation of the first asymptote is Y = (B/A)*X.
		//! Raises ConstructionError if MajorRadius = 0.0
		xgp_Ax1^ Asymptote1();


		//! In the local coordinate system of the hyperbola the equation of
		//! the hyperbola is (X*X)/(A*A) - (Y*Y)/(B*B) = 1.0 and the
		//! equation of the first asymptote is Y = -(B/A)*X.
		//! Raises ConstructionError if MajorRadius = 0.0
		xgp_Ax1^ Asymptote2();


		//! This branch of hyperbola is on the positive side of the
		//! YAxis of <me>.
		xgp_Hypr^ ConjugateBranch1();


		//! This branch of hyperbola is on the negative side of the
		//! YAxis of <me>.
		//! Note: The diagram given under the class purpose
		//! indicates where these two branches of hyperbola are
		//! positioned in relation to this branch of hyperbola.
		xgp_Hypr^ ConjugateBranch2();


		//! This directrix is the line normal to the XAxis of the hyperbola
		//! in the local plane (Z = 0) at a distance d = MajorRadius / e
		//! from the center of the hyperbola, where e is the eccentricity of
		//! the hyperbola.
		//! This line is parallel to the YAxis. The intersection point between
		//! directrix1 and the XAxis is the location point of the directrix1.
		//! This point is on the positive side of the XAxis.
		xgp_Ax1^ Directrix1();


		//! This line is obtained by the symmetrical transformation
		//! of "directrix1" with respect to the YAxis of the hyperbola.
		xgp_Ax1^ Directrix2();


		//! Returns the excentricity of the hyperbola (e > 1).
		//! If f is the distance between the location of the hyperbola
		//! and the Focus1 then the eccentricity e = f / MajorRadius.
		//! raised if MajorRadius = 0.0
		Standard_Real Eccentricity() Standard_OVERRIDE;


		//! Computes the focal distance. It is the distance between the
		//! two focus of the hyperbola.
		Standard_Real Focal();


		//! Returns the first focus of the hyperbola. This focus is on the
		//! positive side of the XAxis of the hyperbola.
		xgp_Pnt^ Focus1();


		//! Returns the second focus of the hyperbola. This focus is on the
		//! negative side of the XAxis of the hyperbola.
		xgp_Pnt^ Focus2();

		//! Returns the major or minor radius of this hyperbola.
		//! The major radius is also the distance between the
		//! center of the hyperbola and the apex of the main
		//! branch (located on the "X Axis" of the hyperbola).
		Standard_Real MajorRadius();

		//! Returns the major or minor radius of this hyperbola.
		//! The minor radius is also the distance between the
		//! center of the hyperbola and the apex of a conjugate
		//! branch (located on the "Y Axis" of the hyperbola).
		Standard_Real MinorRadius();

		//! Computes the "other" branch of this hyperbola. This
		//! is the symmetrical branch with respect to the center of this hyperbola.
		//! Note: The diagram given under the class purpose
		//! indicates where the "other" branch is positioned in
		//! relation to this branch of the hyperbola.
		xgp_Hypr^ OtherBranch();


		//! Returns p = (e * e - 1) * MajorRadius where e is the
		//! eccentricity of the hyperbola.
		//! raised if MajorRadius = 0.0
		Standard_Real Parameter();

		//! Returns in P the point of parameter U.
		//! P = C + MajorRadius * Cosh (U) * XDir +
		//! MinorRadius * Sinh (U) * YDir
		//! where C is the center of the hyperbola , XDir the XDirection and
		//! YDir the YDirection of the hyperbola's local coordinate system.
		void D0(Standard_Real U, xgp_Pnt^ P) Standard_OVERRIDE;


		//! Returns the point P of parameter U and the first derivative V1.
		void D1(Standard_Real U, xgp_Pnt^ P, xgp_Vec^ V1) Standard_OVERRIDE;


		//! Returns the point P of parameter U, the first and second
		//! derivatives V1 and V2.
		void D2(Standard_Real U, xgp_Pnt^ P, xgp_Vec^ V1, xgp_Vec^ V2) Standard_OVERRIDE;


		//! Returns the point P of parameter U, the first second and
		//! third derivatives V1 V2 and V3.
		void D3(Standard_Real U, xgp_Pnt^ P, xgp_Vec^ V1, xgp_Vec^ V2, xgp_Vec^ V3) Standard_OVERRIDE;


		//! The returned vector gives the value of the derivative for the
		//! order of derivation N.
		//! Raised if N < 1.
		xgp_Vec^ DN(Standard_Real U, Standard_Integer N) Standard_OVERRIDE;

		//! Applies the transformation T to this hyperbola.
		void Transform(xgp_Trsf^ T) Standard_OVERRIDE;

		//! Creates a new object which is a copy of this hyperbola.
		XGeom_Geometry^ Copy() Standard_OVERRIDE;

		/// <summary>
		/// ±¾µØ¾ä±ú
		/// </summary>
		virtual property Handle(Standard_Transient) IHandle {
			Handle(Standard_Transient) get() Standard_OVERRIDE {
				return 	NativeHandle();
			}
			void set(Handle(Standard_Transient) handle) Standard_OVERRIDE {
				NativeHandle() = Handle(Geom_Hyperbola)::DownCast(handle);
			}
		}

	private:
		NCollection_Haft<Handle(Geom_Hyperbola)> NativeHandle;
	};
}
#endif // _XGeom_Hyperbola_HeaderFile
