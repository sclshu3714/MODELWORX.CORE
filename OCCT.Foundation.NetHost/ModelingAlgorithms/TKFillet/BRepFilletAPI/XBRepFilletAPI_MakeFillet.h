// Created on: 1994-06-17
// Created by: Modeling
// Copyright (c) 1994-1999 Matra Datavision
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

#ifndef _XBRepFilletAPI_MakeFillet_HeaderFile
#define _XBRepFilletAPI_MakeFillet_HeaderFile
#pragma once
#include <BRepFilletAPI_MakeFillet.hxx>
#include <XBRepFilletAPI_LocalOperation.h>
#include <XTopoDS_Shape.h>
#include <XTopoDS_Edge.h>
#include <XTopoDS_Vertex.h>
#include <XGeom_Surface.h>
#include <XGeomAbs_Shape.h>
#include <XChFi3d_FilletShape.h>
#include <XChFiDS_ErrorStatus.h>
#include <XStandard_Helper.h>

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <ChFi3d_FilBuilder.hxx>
#include <TopTools_MapOfShape.hxx>
#include <BRepFilletAPI_LocalOperation.hxx>
#include <ChFi3d_FilletShape.hxx>
#include <Standard_Real.hxx>
#include <GeomAbs_Shape.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <Standard_Integer.hxx>
#include <Standard_Boolean.hxx>
#include <TopTools_ListOfShape.hxx>
#include <ChFiDS_SecHArray1.hxx>
#include <ChFiDS_ErrorStatus.hxx>

class StdFail_NotDone;
class Standard_NoSuchObject;
class Law_Function;
class TopoDS_Shape;
class TopoDS_Edge;
class TopoDS_Vertex;
class Geom_Surface;
class TopOpeBRepBuild_HBuilder;
class BRepFilletAPI_MakeFillet;

using namespace TKBRep;
using namespace TKTopAlgo;
using namespace TKG3d;
using namespace TKernel;
namespace TKFillet {
	ref class TKBRep::XTopoDS_Shape;
	ref class TKBRep::XTopoDS_Edge;
	ref class TKBRep::XTopoDS_Vertex;
	ref class TKG3d::XGeom_Surface;
	ref class TKernel::XStandard_Helper;
	//! Describes functions to build fillets on the broken edges of a shell or solid.
	//! A MakeFillet object provides a framework for:
	//! -   initializing the construction algorithm with a given shape,
	//! -   acquiring the data characterizing the fillets,
	//! -   building the fillets and constructing the resulting shape, and
	//! -   consulting the result.
	public ref class XBRepFilletAPI_MakeFillet : public XBRepFilletAPI_LocalOperation
	{
	public:

		//! DEFINE_STANDARD_ALLOC

		XBRepFilletAPI_MakeFillet();
		//! Initializes   the computation    of   the  fillets.
		//! <FShape> sets   the type   of fillet  surface. The
		//! default value is ChFi3d_Rational (classical  nurbs
		//! representation of  circles).   ChFi3d_QuasiAngular
		//! corresponds to  a  nurbs representation of circles
		//! which   parameterisation matches  the  circle one.
		//! ChFi3d_Polynomial  corresponds to  a    polynomial
		//! representation of circles.
		//! ChFi3d_FilletShape FShape = ChFi3d_Rational
		XBRepFilletAPI_MakeFillet(XTopoDS_Shape^ S, XChFi3d_FilletShape FShape);


		XBRepFilletAPI_MakeFillet(BRepFilletAPI_MakeFillet* handle);

		void SetMakeFilletHandle(BRepFilletAPI_MakeFillet* handle);

		virtual BRepFilletAPI_MakeFillet* GetMakeFillet();

		virtual BRepFilletAPI_LocalOperation* GetLocalOperation() Standard_OVERRIDE;

		virtual BRepBuilderAPI_MakeShape* GetMakeShape() Standard_OVERRIDE;

		//! Returns a shape built by the shape construction algorithm.
		//! Raises exception StdFail_NotDone if the shape was not built.
		virtual XTopoDS_Shape^ Shape() Standard_OVERRIDE;

		void SetParams(Standard_Real Tang, Standard_Real Tesp, Standard_Real T2d, Standard_Real TApp3d, Standard_Real TolApp2d, Standard_Real Fleche);

		//! Changes     the      parameters     of  continiuity
		//! InternalContinuity to produce fillet'surfaces with
		//! an continuity   Ci (i=0,1 or    2).
		//! By defaultInternalContinuity = GeomAbs_C1.
		//! AngularTolerance  is the G1 tolerance between fillet
		//! and support'faces.
		void SetContinuity(XGeomAbs_Shape InternalContinuity, Standard_Real AngularTolerance);

		//! Adds a  fillet contour in  the  builder  (builds a
		//! contour  of tangent edges).
		//! The Radius must be set after.
		void Add(XTopoDS_Edge^ E) Standard_OVERRIDE;

		//! Adds a  fillet description in  the  builder
		//! - builds a contour  of tangent edges,
		//! - sets the radius.
		void Add(Standard_Real Radius, XTopoDS_Edge^ E);

		//! Adds a  fillet description in  the  builder
		//! - builds a contour  of tangent edges,
		//! - sets a linear radius evolution law between
		//! the first and last vertex of the spine.
		void Add(Standard_Real R1, Standard_Real R2, XTopoDS_Edge^ E);

		//! Adds a  fillet description in  the  builder
		//! - builds a contour  of tangent edges,
		//! - sest the radius evolution law.
		void Add(Handle(Law_Function)& L, XTopoDS_Edge^ E);

		//! Adds a  fillet description in  the  builder
		//! - builds a contour  of tangent edges,
		//! - sets the radius evolution law interpolating the values
		//! given in the array UandR :
		//!
		//! p2d.X() = relative parameter on the spine [0,1]
		//! p2d.Y() = value of the radius.
		void Add(TColgp_Array1OfPnt2d& UandR, XTopoDS_Edge^ E);

		//! Sets the parameters of the fillet
		//! along the contour of index IC generated using the Add function
		//! in the internal data structure of
		//! this algorithm, where Radius is the radius of the fillet.
		void SetRadius(Standard_Real Radius, Standard_Integer IC, Standard_Integer IinC);

		//! Sets the parameters of the fillet
		//! along the contour of index IC generated using the Add function
		//! in the internal data structure of this algorithm, where the radius of the
		//! fillet evolves according to a linear evolution law defined
		//! from R1 to R2, between the first and last vertices of the contour of index IC.
		void SetRadius(Standard_Real R1, Standard_Real R2, Standard_Integer IC, Standard_Integer IinC);

		//! Sets the parameters of the fillet
		//! along the contour of index IC generated using the Add function
		//! in the internal data structure of this algorithm, where the radius of the
		//! fillet evolves according to the evolution law L, between the
		//! first and last vertices of the contour of index IC.
		void SetRadius(Handle(Law_Function)& L, Standard_Integer IC, Standard_Integer IinC);

		//! Sets the parameters of the fillet
		//! along the contour of index IC generated using the Add function
		//! in the internal data structure of this algorithm,
		//! where the radius of the fillet evolves according to the evolution law
		//! which interpolates the set of parameter and radius pairs given
		//! in the array UandR as follows:
		//! -   the X coordinate of a point in UandR defines a
		//! relative parameter on the contour (i.e. a parameter between 0 and 1),
		//! -          the Y coordinate of a point in UandR gives the
		//! corresponding value of the radius, and the radius evolves
		//! between the first and last vertices of the contour of index IC.
		void SetRadius(TColgp_Array1OfPnt2d& UandR, Standard_Integer IC, Standard_Integer IinC);

		//! Erases the radius information on the contour of index
		//! IC in the internal data structure of this algorithm.
		//! Use the SetRadius function to reset this data.
		//! Warning
		//! Nothing is done if IC is outside the bounds of the table of contours.
		void ResetContour(Standard_Integer IC) Standard_OVERRIDE;

		//! Returns true if the radius of the fillet along the contour of index IC
		//! in the internal data structure of this algorithm is constant,
		//! Warning
		//! False is returned if IC is outside the bounds of the table
		//! of contours or if E does not belong to the contour of index IC.
		Standard_Boolean IsConstant(Standard_Integer IC);

		//! Returns the radius of the fillet along the contour of index IC in the
		//! internal data structure of this algorithm
		//! Warning
		//! -   Use this function only if the radius is constant.
		//! -   -1. is returned if IC is outside the bounds of the
		//! table of contours or if E does not belong to the contour of index IC.
		Standard_Real Radius(Standard_Integer IC);

		//! Returns true if the radius of the fillet along the edge E of the
		//! contour of index IC in the internal data structure of
		//! this algorithm is constant.
		//! Warning
		//! False is returned if IC is outside the bounds of the table
		//! of contours or if E does not belong to the contour of index IC.
		Standard_Boolean IsConstant(Standard_Integer IC, XTopoDS_Edge^ E);

		//! Returns the radius of the fillet along the edge E of the contour of index
		//! IC in the internal data structure of this algorithm.
		//! Warning
		//! -   Use this function only if the radius is constant.
		//! -   -1 is returned if IC is outside the bounds of the
		//! table of contours or if E does not belong to the contour of index IC.
		Standard_Real Radius(Standard_Integer IC, XTopoDS_Edge^ E);

		//! Assigns Radius as the radius of the fillet on the edge E
		void SetRadius(Standard_Real Radius, Standard_Integer IC, XTopoDS_Edge^ E);

		void SetRadius(Standard_Real Radius, Standard_Integer IC, XTopoDS_Vertex^ V);

		Standard_Boolean GetBounds(Standard_Integer IC, XTopoDS_Edge^ E, Standard_Real F, Standard_Real L);

		Handle(Law_Function) GetLaw(Standard_Integer IC, XTopoDS_Edge^ E);

		void SetLaw(Standard_Integer IC, XTopoDS_Edge^ E, Handle(Law_Function)& L);

		//! Assigns FShape as the type of fillet shape built by this algorithm.
		void SetFilletShape(XChFi3d_FilletShape FShape);

		//! Returns the type of fillet shape built by this algorithm.
		XChFi3d_FilletShape GetFilletShape();

		//! Returns the number of contours generated using the
		//! Add function in the internal data structure of this algorithm.
		Standard_Integer NbContours() Standard_OVERRIDE;

		//! Returns the index of the contour in the internal data
		//! structure of this algorithm which contains the edge E of the shape.
		//! This function returns 0 if the edge E does not belong to any contour.
		//! Warning
		//! This index can change if a contour is removed from the
		//! internal data structure of this algorithm using the function Remove.
		Standard_Integer Contour(XTopoDS_Edge^ E) Standard_OVERRIDE;

		//! Returns the number of edges in the contour of index I in
		//! the internal data structure of this algorithm.
		//! Warning
		//! Returns 0 if I is outside the bounds of the table of contours.
		Standard_Integer NbEdges(Standard_Integer I) Standard_OVERRIDE;

		//! Returns the edge of index J in the contour of index I in
		//! the internal data structure of this algorithm.
		//! Warning
		//! Returns a null shape if:
		//! -   I is outside the bounds of the table of contours, or
		//! -   J is outside the bounds of the table of edges of the index I contour.
		XTopoDS_Edge^ Edge(Standard_Integer I, Standard_Integer J) Standard_OVERRIDE;

		//! Removes the contour in the internal data structure of
		//! this algorithm which contains the edge E of the shape.
		//! Warning
		//! Nothing is done if the edge E does not belong to the
		//! contour in the internal data structure of this algorithm.
		void Remove(XTopoDS_Edge^ E) Standard_OVERRIDE;

		//! Returns the length of the contour of index IC in the
		//! internal data structure of this algorithm.
		//! Warning
		//! Returns -1. if IC is outside the bounds of the table of contours.
		Standard_Real Length(Standard_Integer IC) Standard_OVERRIDE;

		//! Returns the first vertex of the contour of index IC
		//! in the internal data structure of this algorithm.
		//! Warning
		//! Returns a null shape if IC is outside the bounds of the table of contours.
		XTopoDS_Vertex^ FirstVertex(Standard_Integer IC) Standard_OVERRIDE;

		//! Returns the  last vertex of the contour of index IC
		//! in the internal data structure of this algorithm.
		//! Warning
		//! Returns a null shape if IC is outside the bounds of the table of contours.
		XTopoDS_Vertex^ LastVertex(Standard_Integer IC) Standard_OVERRIDE;

		//! Returns the curvilinear abscissa of the vertex V on the
		//! contour of index IC in the internal data structure of this algorithm.
		//! Warning
		//! Returns -1. if:
		//! -   IC is outside the bounds of the table of contours, or
		//! -   V is not on the contour of index IC.
		Standard_Real Abscissa(Standard_Integer IC, XTopoDS_Vertex^ V) Standard_OVERRIDE;

		//! Returns the relative curvilinear abscissa (i.e. between 0
		//! and 1) of the vertex V on the contour of index IC in the
		//! internal data structure of this algorithm.
		//! Warning
		//! Returns -1. if:
		//! -   IC is outside the bounds of the table of contours, or
		//! -   V is not on the contour of index IC.
		Standard_Real RelativeAbscissa(Standard_Integer IC, XTopoDS_Vertex^ V) Standard_OVERRIDE;

		//! Returns true if the contour of index IC in the internal
		//! data structure of this algorithm is closed and tangential
		//! at the point of closure.
		//! Warning
		//! Returns false if IC is outside the bounds of the table of contours.
		Standard_Boolean ClosedAndTangent(Standard_Integer IC) Standard_OVERRIDE;

		//! Returns true if the contour of index IC in the internal
		//! data structure of this algorithm is closed.
		//! Warning
		//! Returns false if IC is outside the bounds of the table of contours.
		Standard_Boolean Closed(Standard_Integer IC) Standard_OVERRIDE;

		//! Builds the fillets on all the contours in the internal data
		//! structure of this algorithm and constructs the resulting shape.
		//! Use the function IsDone to verify that the filleted shape
		//! is built. Use the function Shape to retrieve the filleted shape.
		//! Warning
		//! The construction of fillets implements highly complex
		//! construction algorithms. Consequently, there may be
		//! instances where the algorithm fails, for example if the
		//! data defining the radius of the fillet is not compatible
		//! with the geometry of the initial shape. There is no initial
		//! analysis of errors and they only become evident at the
		//! construction stage.
		//! Additionally, in the current software release, the
		//! following cases are not handled:
		//! -   the end point of the contour is the point of
		//! intersection of 4 or more edges of the shape, or
		//! -   the intersection of the fillet with a face which limits
		//! the contour is not fully contained in this face.
		virtual void Build() Standard_OVERRIDE;

		//! Reinitializes this algorithm, thus canceling the effects of the Build function.
		//! This function allows modifications to be made to the
		//! contours and fillet parameters in order to rebuild the shape.
		void Reset() Standard_OVERRIDE;

		//! Returns the internal topology building algorithm.
		Handle(TopOpeBRepBuild_HBuilder) Builder();

		//! Returns the  list   of shapes generated   from the
		//! shape <EorV>.
		virtual XTopTools_ListOfShape^ Generated(XTopoDS_Shape^ EorV) Standard_OVERRIDE;

		//! Returns the list  of shapes modified from the shape
		//! <F>.
		virtual XTopTools_ListOfShape^ Modified(XTopoDS_Shape^ F) Standard_OVERRIDE;

		virtual Standard_Boolean IsDeleted(XTopoDS_Shape^ F) Standard_OVERRIDE;

		//! returns the number of surfaces
		//! after the shape creation.
		Standard_Integer NbSurfaces();

		//! Return the faces created for surface <I>.
		XTopTools_ListOfShape^ NewFaces(Standard_Integer I);

		void Simulate(Standard_Integer IC) Standard_OVERRIDE;

		Standard_Integer NbSurf(Standard_Integer IC) Standard_OVERRIDE;

		Handle(ChFiDS_SecHArray1) Sect(Standard_Integer IC, Standard_Integer IS) Standard_OVERRIDE;

		//! Returns the number of contours where the computation
		//! of the fillet failed
		Standard_Integer NbFaultyContours();

		//! for each I in [1.. NbFaultyContours] returns the index IC of
		//! the contour where the computation of the fillet failed.
		//! the method NbEdges(IC) gives the number of edges in the contour IC
		//! the method Edge(IC,ie) gives the edge number ie of the contour IC
		Standard_Integer FaultyContour(Standard_Integer I);

		//! returns the number of surfaces which have been
		//! computed on the contour IC
		Standard_Integer NbComputedSurfaces(Standard_Integer IC);

		//! returns the surface number IS concerning the contour IC
		XGeom_Surface^ ComputedSurface(Standard_Integer IC, Standard_Integer IS);

		//! returns the number of vertices where the computation failed
		Standard_Integer NbFaultyVertices();

		//! returns the vertex where the computation failed
		XTopoDS_Vertex^ FaultyVertex(Standard_Integer IV);

		//! returns true if a part of the result has been computed
		//! if the filling in a corner failed a shape with a hole is returned
		Standard_Boolean HasResult();

		//! if (HasResult()) returns the partial result
		XTopoDS_Shape^ BadShape();

		//! returns the status concerning the contour IC in case of error
		//! ChFiDS_Ok : the computation is Ok
		//! ChFiDS_StartsolFailure : the computation can't start, perhaps the
		//! the radius is too big
		//! ChFiDS_TwistedSurface : the computation failed because of a twisted
		//! surface
		//! ChFiDS_WalkingFailure : there is a problem in the walking
		//! ChFiDS_Error:  other error different from above
		XChFiDS_ErrorStatus StripeStatus(Standard_Integer IC);

		/// <summary>
		/// ±¾µØ¾ä±ú
		/// </summary>
		virtual property BRepBuilderAPI_MakeShape* IHandle {
			BRepBuilderAPI_MakeShape* get() Standard_OVERRIDE {
				return NativeHandle;
			}
			void set(BRepBuilderAPI_MakeShape* handle) Standard_OVERRIDE {
				NativeHandle = static_cast<BRepFilletAPI_MakeFillet*>(handle);
			}
		}

	private:
		BRepFilletAPI_MakeFillet* NativeHandle;
	};
}
#endif // _XBRepFilletAPI_MakeFillet_HeaderFile
