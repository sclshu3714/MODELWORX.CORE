// Created on: 1991-01-28
// Created by: Remi Lequette
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

#ifndef _XBnd_Box_HeaderFile
#define _XBnd_Box_HeaderFile
#pragma once
#include <Bnd_Box.hxx>
#include <xgp_Pnt.h>
#include <xgp_Dir.h>
#include <xgp_Trsf.h>
#include <xgp_Lin.h>
#include <xgp_Pln.h>

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <gp_Pnt.hxx>
#include <Standard_Real.hxx>
#include <Standard_Integer.hxx>
#include <Standard_Boolean.hxx>
class Standard_ConstructionError;
class gp_Pnt;
class gp_Dir;
class gp_Trsf;
class gp_Lin;
class gp_Pln;

namespace TKMath {
    //! Bit flags.
    public enum class XMaskFlags
    {
        VoidMask = 0x01,
        XminMask = 0x02,
        XmaxMask = 0x04,
        YminMask = 0x08,
        YmaxMask = 0x10,
        ZminMask = 0x20,
        ZmaxMask = 0x40,
        WholeMask = 0x7e
    };

    ref class xgp_Pnt;
    ref class xgp_Dir;
    ref class xgp_Trsf;
    ref class xgp_Lin;
    ref class xgp_Pln;

    //! Describes a bounding box in 3D space.
    //! A bounding box is parallel to the axes of the coordinates
    //! system. If it is finite, it is defined by the three intervals:
    //! -   [ Xmin,Xmax ],
    //! -   [ Ymin,Ymax ],
    //! -   [ Zmin,Zmax ].
    //! A bounding box may be infinite (i.e. open) in one or more
    //! directions. It is said to be:
    //! -   OpenXmin if it is infinite on the negative side of the   "X Direction";
    //! -   OpenXmax if it is infinite on the positive side of the "X Direction";
    //! -   OpenYmin if it is infinite on the negative side of the   "Y Direction";
    //! -   OpenYmax if it is infinite on the positive side of the "Y Direction";
    //! -   OpenZmin if it is infinite on the negative side of the   "Z Direction";
    //! -   OpenZmax if it is infinite on the positive side of the "Z Direction";
    //! -   WholeSpace if it is infinite in all six directions. In this
    //! case, any point of the space is inside the box;
    //! -   Void if it is empty. In this case, there is no point included in the box.
    //! A bounding box is defined by:
    //! -   six bounds (Xmin, Xmax, Ymin, Ymax, Zmin and
    //! Zmax) which limit the bounding box if it is finite,
    //! -   eight flags (OpenXmin, OpenXmax, OpenYmin,
    //! OpenYmax, OpenZmin, OpenZmax,
    //! WholeSpace and Void) which describe the
    //! bounding box if it is infinite or empty, and
    //! -   a gap, which is included on both sides in any direction
    //! when consulting the finite bounds of the box.
    public ref class XBnd_Box
    {
    public:

        //! DEFINE_STANDARD_ALLOC


        //! Creates an empty Box.
        //! The constructed box is qualified Void. Its gap is null.
        XBnd_Box();

        XBnd_Box(Bnd_Box* pos);

        void SetBndBoxHandle(Bnd_Box* pos);

        Bnd_Box* GetBndBox();

        //! Creates a bounding box, it contains:
        //! -   minimum/maximum point of bouning box,
        //! The constructed box is qualified Void. Its gap is null.
        XBnd_Box(xgp_Pnt^ theMin, xgp_Pnt^ theMax);

        //! Sets this bounding box so that it  covers the whole of 3D space.
        //! It is infinitely  long in all directions.
        void SetWhole();

        //! Sets this bounding box so that it is empty. All points are outside a void box.
        void SetVoid();

        //! Sets this bounding box so that it bounds
        //! -   the point P. This involves first setting this bounding box
        //! to be void and then adding the point P.
        void Set(xgp_Pnt^ P);

        //! Sets this bounding box so that it bounds
        //! the half-line defined by point P and direction D, i.e. all
        //! points M defined by M=P+u*D, where u is greater than
        //! or equal to 0, are inside the bounding volume. This
        //! involves first setting this box to be void and then adding   the half-line.
        void Set(xgp_Pnt^ P, xgp_Dir^ D);

        //! Enlarges this bounding box, if required, so that it
        //! contains at least:
        //! -   interval [ aXmin,aXmax ] in the "X Direction",
        //! -   interval [ aYmin,aYmax ] in the "Y Direction",
        //! -   interval [ aZmin,aZmax ] in the "Z Direction";
        void Update(Standard_Real aXmin, Standard_Real aYmin, Standard_Real aZmin, Standard_Real aXmax, Standard_Real aYmax, Standard_Real aZmax);

        //! Adds a point of coordinates (X,Y,Z) to this bounding box.
        void Update(Standard_Real X, Standard_Real Y, Standard_Real Z);

        //! Returns the gap of this bounding box.
        Standard_Real GetGap();

        //! Set the gap of this bounding box to abs(Tol).
        void SetGap(Standard_Real Tol);

        //! Enlarges the      box    with    a   tolerance   value.
        //! (minvalues-Abs(<tol>) and maxvalues+Abs(<tol>))
        //! This means that the minimum values of its X, Y and Z
        //! intervals of definition, when they are finite, are reduced by
        //! the absolute value of Tol, while the maximum values are
        //! increased by the same amount.
        void Enlarge(Standard_Real Tol);

        //! Returns the bounds of this bounding box. The gap is included.
        //! If this bounding box is infinite (i.e. "open"), returned values
        //! may be equal to +/- Precision::Infinite().
        //! Standard_ConstructionError exception will be thrown if the box is void.
        //! if IsVoid()
        void Get(Standard_Real% theXmin, Standard_Real% theYmin, Standard_Real% theZmin, Standard_Real% theXmax, Standard_Real% theYmax, Standard_Real% theZmax);

        //! Returns the lower corner of this bounding box. The gap is included.
        //! If this bounding box is infinite (i.e. "open"), returned values
        //! may be equal to +/- Precision::Infinite().
        //! Standard_ConstructionError exception will be thrown if the box is void.
        //! if IsVoid()
        xgp_Pnt^ CornerMin();

        //! Returns the upper corner of this bounding box. The gap is included.
        //! If this bounding box is infinite (i.e. "open"), returned values
        //! may be equal to +/- Precision::Infinite().
        //! Standard_ConstructionError exception will be thrown if the box is void.
        //! if IsVoid()
        xgp_Pnt^ CornerMax();

        //! The   Box will be   infinitely   long  in the Xmin
        //! direction.
        void OpenXmin();

        //! The   Box will be   infinitely   long  in the Xmax
        //! direction.
        void OpenXmax();

        //! The   Box will be   infinitely   long  in the Ymin
        //! direction.
        void OpenYmin();

        //! The   Box will be   infinitely   long  in the Ymax
        //! direction.
        void OpenYmax();

        //! The   Box will be   infinitely   long  in the Zmin
        //! direction.
        void OpenZmin();

        //! The   Box will be   infinitely   long  in the Zmax
        //! direction.
        void OpenZmax();

        //! Returns true if this bounding box has at least one open direction.
        Standard_Boolean IsOpen();

        //! Returns true if this bounding box is open in the  Xmin direction.
        Standard_Boolean IsOpenXmin();

        //! Returns true if this bounding box is open in the  Xmax direction.
        Standard_Boolean IsOpenXmax();

        //! Returns true if this bounding box is open in the  Ymix direction.
        Standard_Boolean IsOpenYmin();

        //! Returns true if this bounding box is open in the  Ymax direction.
        Standard_Boolean IsOpenYmax();

        //! Returns true if this bounding box is open in the  Zmin direction.
        Standard_Boolean IsOpenZmin();

        //! Returns true if this bounding box is open in the  Zmax  direction.
        Standard_Boolean IsOpenZmax();

        //! Returns true if this bounding box is infinite in all 6 directions (WholeSpace flag).
        Standard_Boolean IsWhole();

        //! Returns true if this bounding box is empty (Void flag).
        Standard_Boolean IsVoid();

        //! true if xmax-xmin < tol.
        Standard_Boolean IsXThin(Standard_Real tol);

        //! true if ymax-ymin < tol.
        Standard_Boolean IsYThin(Standard_Real tol);

        //! true if zmax-zmin < tol.
        Standard_Boolean IsZThin(Standard_Real tol);

        //! Returns true if IsXThin, IsYThin and IsZThin are all true,
        //! i.e. if the box is thin in all three dimensions.
        Standard_Boolean IsThin(Standard_Real tol);

        //! Returns a bounding box which is the result of applying the
        //! transformation T to this bounding box.
        //! Warning
        //! Applying a geometric transformation (for example, a
        //! rotation) to a bounding box generally increases its
        //! dimensions. This is not optimal for algorithms which use it.
        XBnd_Box^ Transformed(xgp_Trsf^ T);

        //! Adds the box <Other> to <me>.
        void Add(XBnd_Box^ Other);

        //! Adds a Pnt to the box.
        void Add(xgp_Pnt^ P);

        //! Extends  <me> from the Pnt <P> in the direction <D>.
        void Add(xgp_Pnt^ P, xgp_Dir^ D);

        //! Extends the Box  in the given Direction, i.e. adds
        //! an  half-line. The   box  may become   infinite in
        //! 1,2 or 3 directions.
        void Add(xgp_Dir^ D);

        //! Returns True if the Pnt is out the box.
        Standard_Boolean IsOut(xgp_Pnt^ P);

        //! Returns False if the line intersects the box.
        Standard_Boolean IsOut(xgp_Lin^ L);

        //! Returns False if the plane intersects the box.
        Standard_Boolean IsOut(xgp_Pln^ P);

        //! Returns False if the <Box> intersects or is inside <me>.
        Standard_Boolean IsOut(XBnd_Box^ Other);

        //! Returns False if  the transformed <Box> intersects
        //! or  is inside <me>.
        Standard_Boolean IsOut(XBnd_Box^ Other, xgp_Trsf^ T);

        //! Returns False  if the transformed <Box> intersects
        //! or  is inside the transformed box <me>.
        Standard_Boolean IsOut(xgp_Trsf^ T1, XBnd_Box^ Other, xgp_Trsf^ T2);

        //! Returns False  if the flat band lying between two parallel
        //! lines represented by their reference points <P1>, <P2> and
        //! direction <D> intersects the box.
        Standard_Boolean IsOut(xgp_Pnt^ P1, xgp_Pnt^ P2, xgp_Dir^ D);

        //! Computes the minimum distance between two boxes.
        Standard_Real Distance(XBnd_Box^ Other);

        void Dump();

        //! Computes the squared diagonal of me.
        Standard_Real SquareExtent();

        //! Returns a finite part of an infinite bounding box (returns self if this is already finite box).
        //! This can be a Void box in case if its sides has been defined as infinite (Open) without adding any finite points.
        //! WARNING! This method relies on Open flags, the infinite points added using Add() method will be returned as is.
        XBnd_Box^ FinitePart();

        //! Returns TRUE if this box has finite part.
        Standard_Boolean HasFinitePart();

        //! Dumps the content of me into the stream
        //! Standard_Integer theDepth = -1
        void DumpJson(Standard_OStream& theOStream, Standard_Integer theDepth);

        /// <summary>
        /// ±¾µØ¾ä±ú
        /// </summary>
        virtual property Bnd_Box* IHandle {
            Bnd_Box* get() { // Standard_OVERRIDE {
                return NativeHandle;
            }
            void set(Bnd_Box* handle) { // Standard_OVERRIDE {
                NativeHandle = handle;
            }
        }
    private:
        Bnd_Box* NativeHandle;
    };
}
#endif // _XBnd_Box_HeaderFile
