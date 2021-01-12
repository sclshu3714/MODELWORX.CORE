// Created on: 1996-12-11
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

#ifndef _XAIS_HeaderFile
#define _XAIS_HeaderFile
#pragma once
#include <AIS.hxx>
#include <XBnd_Box.h>
#include <XGeom_Curve.h>
#include <XGeom_Plane.h>
#include <XGeom_Surface.h>
#include <XTopoDS_Edge.h>
#include <XTopoDS_Face.h>
#include <XTopoDS_Shape.h>
#include <XTopoDS_Vertex.h>
#include <XAIS_KindOfSurface.h>
#include <XPrs3d_Drawer.h>
#include <XAspect_TypeOfMarker.h>
#include <XPrs3d_Presentation.h>
#include <xgp_Elips.h>

#include <AIS_KindOfSurface.hxx>
#include <Aspect_TypeOfLine.hxx>
#include <Aspect_TypeOfMarker.hxx>
#include <gp_Dir.hxx>
#include <gp_Pnt.hxx>
#include <Quantity_NameOfColor.hxx>
#include <Prs3d_Drawer.hxx>
#include <Prs3d_Presentation.hxx>
#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

class Bnd_Box;
class Geom_Curve;
class Geom_Plane;
class Geom_Surface;
class TopoDS_Edge;
class TopoDS_Face;
class TopoDS_Shape;
class TopoDS_Vertex;

using namespace TKMath;
using namespace TKBRep;
namespace TKV3d {
	ref class XGeom_Curve;
	ref class XGeom_Plane;
	ref class XGeom_Surface;
	ref class XPrs3d_Presentation;
	ref class TKBRep::XTopoDS_Edge;
	ref class TKBRep::XTopoDS_Face;
	ref class TKBRep::XTopoDS_Shape;
	ref class TKBRep::XTopoDS_Vertex;
	ref class TKMath::XBnd_Box;
	ref class TKMath::xgp_Elips;
	//! Application Interactive Services provide the means to create links between an application GUI viewer and
	//! the packages which are used to manage selection and presentation.
	//! The tools AIS defined in order to do this include different sorts of entities:
	//! both the selectable viewable objects themselves and the context and attribute managers to define their selection and display.
	//! To orient the user as he works in a modeling environment, views and selections must be comprehensible.
	//! There must be several different sorts of selectable and viewable object defined.
	//! These must also be interactive, that is, connecting graphic representation and the underlying reference geometry.
	//! These entities are called Interactive Objects, and are divided into four types:
	//! -   the Datum
	//! -   the Relation
	//! -   the Object
	//! -   None.
	//! The Datum groups together theruction elements such as lines, circles, points, trihedra, plane trihedra, planes and axes.
	//! The Relation is made up ofraints on one or more interactive shapes and the corresponding reference geometry.
	//! For example, you might want torain two edges in a parallel relation.
	//! This contraint is considered as an object in its own right, and is shown as a sensitive primitive.
	//! This takes the graphic form of a perpendicular arrow marked with the || symbol and lying between the two edges.
	//! The Object type includes topological shapes, and connections between shapes.
	//! None, in order not to eliminate the object, tells the application to look further until it finds an object definition in its generation which is accepted.
	//! Inside these categories, you have the possibility of an additional characterization by means of a signature.
	//! The signature provides an index to the further characterization.
	//! By default, the Interactive Object has a None type and a signature of 0 (equivalent to None.)
	//! If you want to give a particular type and signature to your interactive object, you must redefine the two virtual methods: Type and Signature.
	//! In the C++ inheritance structure of the package, each class representing a specific Interactive Object inherits AIS_InteractiveObject.
	//! Among these inheriting classes, AIS_Relation functions as the abstract mother class for tinheriting classes defining display of specific relationalraints and types of dimension.
	//! Some of these include:
	//! -   display ofraints based on relations of symmetry, tangency, parallelism and concentricity
	//! -   display of dimensions for angles, offsets, diameters, radii and chamfers.
	//! No viewer can show everything at once with any coherence or clarity.
	//! Views must be managed carefully both sequentially and at any given instant.
	//! Another function of the view is that of a context to carry out design in.
	//! The design changes are applied to the objects in the view and then extended to the underlying reference geometry by a solver.
	//! To make sense of this complicated visual data, several display and selection tools are required.
	//! To facilitate management, each object and eachruction element has a selection priority.
	//! There are also means to modify the default priority.
	//! To define an environment of dynamic detection, you can use standard filter classes or create your own.
	//! A filter questions the owner of the sensitive primitive to determine if it has the the desired qualities.
	//! If it answers positively, it is kept. If not, it is rejected.
	//! The standard filters supplied in AIS include:
	//! - AIS_AttributeFilter
	//! - AIS_SignatureFilter
	//! - AIS_TypeFilter.
	//! A set of functions allows you to choose the interactive objects which you want to act on, the selection modes which you want to activate.
	//! An interactive object can have a certain number of graphic attributes which are specific to it, such as visualization mode, color, and material.
	//! By the same token, the interactive context has a set of graphic attributes, the Drawer which is valid by default for the objects it controls.
	//! When an interactive object is visualized, the required graphic attributes are first taken from the object's own Drawer if one exists, or from the context drawer for the others.
	class AIS
	{
	public:

		//! DEFINE_STANDARD_ALLOC



		//! Returns the nearest point in a shape. This is used by
		//! several classes in calculation of dimensions.
		static xgp_Pnt^ Nearest(XTopoDS_Shape^ aShape, xgp_Pnt^ aPoint);


		//! @return the nearest point on the line.
		static xgp_Pnt^ Nearest(xgp_Lin^ theLine, xgp_Pnt^ thePoint);


		//! For the given point finds nearest point on the curve,
		//! @return TRUE if found point is belongs to the curve
		//! and FALSE otherwise.
		static Standard_Boolean Nearest(XGeom_Curve^ theCurve, xgp_Pnt^ thePoint, xgp_Pnt^ theFirstPoint, xgp_Pnt^ theLastPoint, xgp_Pnt^ theNearestPoint);

		static xgp_Pnt^ Farest(XTopoDS_Shape^ aShape, xgp_Pnt^ aPoint);

		//! Used by 2d Relation only
		//! Computes the 3d geometry of <anEdge> in the current WorkingPlane
		//! and the extremities if any
		//! Return TRUE if ok.
		static Standard_Boolean ComputeGeometry(XTopoDS_Edge^ theEdge, XGeom_Curve^ theCurve, xgp_Pnt^ theFirstPnt, xgp_Pnt^ theLastPnt);

		//! Used by dimensions only.
		//! Computes the 3d geometry of <anEdge>.
		//! Return TRUE if ok.
		static Standard_Boolean ComputeGeometry(XTopoDS_Edge^ theEdge, XGeom_Curve^ theCurve, xgp_Pnt^ theFirstPnt, xgp_Pnt^ theLastPnt, Standard_Boolean% theIsInfinite);

		//! Used by 2d Relation only
		//! Computes the 3d geometry of <anEdge> in the current WorkingPlane
		//! and the extremities if any.
		//! If <aCurve> is not in the current plane, <extCurve> contains
		//! the not projected curve associated to <anEdge>.
		//! If <anEdge> is infinite, <isinfinite> = true and the 2
		//! parameters <FirstPnt> and <LastPnt> have no signification.
		//! Return TRUE if ok.
		static Standard_Boolean ComputeGeometry(XTopoDS_Edge^ theEdge, XGeom_Curve^ theCurve, xgp_Pnt^ theFirstPnt, xgp_Pnt^ theLastPnt, XGeom_Curve^ theExtCurve, Standard_Boolean% theIsInfinite, Standard_Boolean% theIsOnPlane, XGeom_Plane^ thePlane);

		//! Used by 2d Relation only
		//! Computes the 3d geometry of <anEdge> in the current WorkingPlane
		//! and the extremities if any
		//! Return TRUE if ok.
		static Standard_Boolean ComputeGeometry(XTopoDS_Edge^ theFirstEdge, XTopoDS_Edge^ theSecondEdge, XGeom_Curve^ theFirstCurve, XGeom_Curve^ theSecondCurve, xgp_Pnt^ theFirstPnt1, xgp_Pnt^ theLastPnt1, xgp_Pnt^ theFirstPnt2, xgp_Pnt^ theLastPnt2, XGeom_Plane^ thePlane);

		//! Used  by  dimensions  only.Computes  the  3d geometry
		//! of<anEdge1> and <anEdge2> and checks if they are infinite.
		static Standard_Boolean ComputeGeometry(XTopoDS_Edge^ theFirstEdge, XTopoDS_Edge^ theSecondEdge, XGeom_Curve^ theFirstCurve, XGeom_Curve^ theSecondCurve, xgp_Pnt^ theFirstPnt1, xgp_Pnt^ theLastPnt1, xgp_Pnt^ theFirstPnt2, xgp_Pnt^ theLastPnt2, Standard_Boolean% theIsinfinite1, Standard_Boolean% theIsinfinite2);

		//! Used  by  2d Relation  only Computes  the  3d geometry
		//! of<anEdge1> and <anEdge2> in the current Plane and the
		//! extremities if any.   Return in ExtCurve  the 3d curve
		//! (not projected  in the  plane)  of the  first edge  if
		//! <indexExt> =1 or of the 2nd edge if <indexExt> = 2. If
		//! <indexExt> = 0, ExtCurve is Null.  if there is an edge
		//! external to the  plane,  <isinfinite> is true if  this
		//! edge is infinite.  So, the extremities of it are not
		//! significant.  Return TRUE if ok
		static Standard_Boolean ComputeGeometry(XTopoDS_Edge^ theFirstEdge, XTopoDS_Edge^ theSecondEdge, Standard_Integer% theExtIndex, XGeom_Curve^ theFirstCurve, XGeom_Curve^ theSecondCurve, xgp_Pnt^ theFirstPnt1, xgp_Pnt^ theLastPnt1, xgp_Pnt^ theFirstPnt2, xgp_Pnt^ theLastPnt2, XGeom_Curve^ theExtCurve, Standard_Boolean% theIsinfinite1, Standard_Boolean% theIsinfinite2, XGeom_Plane^ thePlane);

		//! Checks if aCurve belongs to aPlane; if not, projects aCurve in aPlane
		//! and returns aCurve;
		//! Return TRUE if ok
		static Standard_Boolean ComputeGeomCurve(XGeom_Curve^ aCurve, Standard_Real first1, Standard_Real last1, xgp_Pnt^ FirstPnt1, xgp_Pnt^ LastPnt1, XGeom_Plane^ aPlane, Standard_Boolean% isOnPlane);

		static Standard_Boolean ComputeGeometry(XTopoDS_Vertex^ aVertex, xgp_Pnt^ point, XGeom_Plane^ aPlane, Standard_Boolean% isOnPlane);

		//! Tryes to get Plane from Face.  Returns Surface of Face
		//! in aSurf.  Returns Standard_True  and Plane of Face in
		//! aPlane in following  cases:
		//! Face is Plane, Offset of Plane,
		//! Extrusion of Line  and Offset of  Extrusion of Line
		//! Returns pure type of Surface which can be:
		//! Plane, Cylinder, Cone, Sphere, Torus,
		//! SurfaceOfRevolution, SurfaceOfExtrusion
		static Standard_Boolean GetPlaneFromFace(XTopoDS_Face^ aFace, xgp_Pln^ aPlane, XGeom_Surface^ aSurf, XAIS_KindOfSurface% aSurfType, Standard_Real% Offset);

		static void InitFaceLength(XTopoDS_Face^ aFace, xgp_Pln^ aPlane, XGeom_Surface^ aSurface, XAIS_KindOfSurface% aSurfaceType, Standard_Real% anOffset);

		//! Finds attachment points on two curvilinear faces for length dimension.
		//! @param thePlaneDir [in] the direction on the dimension plane to
		//! compute the plane automatically. It will not be taken into account if
		//! plane is defined by user.
		static void InitLengthBetweenCurvilinearFaces(XTopoDS_Face^ theFirstFace, XTopoDS_Face^ theSecondFace, XGeom_Surface^ theFirstSurf, XGeom_Surface^ theSecondSurf, xgp_Pnt^ theFirstAttach, xgp_Pnt^ theSecondAttach, xgp_Dir^ theDirOnPlane);

		//! Finds three points for the angle dimension between
		//! two planes.
		//! Standard_Boolean theIsFirstPointSet = Standard_False
		static Standard_Boolean InitAngleBetweenPlanarFaces(XTopoDS_Face^ theFirstFace, XTopoDS_Face^ theSecondFace, xgp_Pnt^ theCenter, xgp_Pnt^ theFirstAttach, xgp_Pnt^ theSecondAttach, Standard_Boolean theIsFirstPointSet);

		//! Finds three points for the angle dimension between
		//! two curvilinear surfaces.
		//! Standard_Boolean theIsFirstPointSet = Standard_False
		static Standard_Boolean InitAngleBetweenCurvilinearFaces(XTopoDS_Face^ theFirstFace, XTopoDS_Face^ theSecondFace, XAIS_KindOfSurface theFirstSurfType, XAIS_KindOfSurface theSecondSurfType, xgp_Pnt^ theCenter, xgp_Pnt^ theFirstAttach, xgp_Pnt^ theSecondAttach, Standard_Boolean theIsFirstPointSet);

		static xgp_Pnt^ ProjectPointOnPlane(xgp_Pnt^ aPoint, xgp_Pln^ aPlane);

		static xgp_Pnt^ ProjectPointOnLine(xgp_Pnt^ aPoint, xgp_Lin^ aLine);

		static xgp_Pnt^ TranslatePointToBound(xgp_Pnt^ aPoint, xgp_Dir^ aDir, XBnd_Box^ aBndBox);

		//! returns  True  if  point  with anAttachPar  is
		//! in  domain  of  arc
		static Standard_Boolean InDomain(Standard_Real aFirstPar, Standard_Real aLastPar, Standard_Real anAttachPar);

		//! computes  nearest  to  ellipse  arc  apex
		static xgp_Pnt^ NearestApex(xgp_Elips^ elips, xgp_Pnt^ pApex, xgp_Pnt^ nApex, Standard_Real fpara, Standard_Real lpara, Standard_Boolean% IsInDomain);

		//! computes  length  of  ellipse  arc  in  parametric  units
		static Standard_Real DistanceFromApex(xgp_Elips^ elips, xgp_Pnt^ Apex, Standard_Real par);

		//! Quantity_NameOfColor aColor = Quantity_NOC_PURPLE, Standard_Real aWidth = 2, Aspect_TypeOfLine aProjTOL = Aspect_TOL_DASH, Aspect_TypeOfLine aCallTOL = Aspect_TOL_DOT
		static void ComputeProjEdgePresentation(XPrs3d_Presentation^ aPres, XPrs3d_Drawer^ aDrawer, XTopoDS_Edge^ anEdge, XGeom_Curve^ ProjCurve, xgp_Pnt^ FirstP, xgp_Pnt^ LastP, XQuantity_NameOfColor aColor, Standard_Real aWidth, XAspect_TypeOfLine aProjTOL, XAspect_TypeOfLine aCallTOL);

		//! Quantity_NameOfColor aColor = Quantity_NOC_PURPLE, Standard_Real aWidth = 2, Aspect_TypeOfMarker aProjTOM = Aspect_TOM_PLUS, Aspect_TypeOfLine aCallTOL = Aspect_TOL_DOT
		static void ComputeProjVertexPresentation(XPrs3d_Presentation^ aPres, XPrs3d_Drawer^ aDrawer, XTopoDS_Vertex^ aVertex, xgp_Pnt^ ProjPoint, XQuantity_NameOfColor aColor, Standard_Real aWidth, XAspect_TypeOfMarker aProjTOM, XAspect_TypeOfLine aCallTOL);

	};
}
#endif // _XAIS_HeaderFile
