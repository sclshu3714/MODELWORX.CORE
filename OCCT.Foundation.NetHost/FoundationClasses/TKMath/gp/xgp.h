#pragma once
#include "gp.hxx"
#include <xgp_Ax1.h>
#include <xgp_Ax2.h>
#include <xgp_Ax2d.h>
#include <xgp_Dir.h>
#include <xgp_Dir2d.h>
#include <xgp_Pnt.h>
#include <xgp_Pnt2d.h>

namespace TKMath
{
    ref class xgp_Pnt;
    ref class xgp_Dir;
    ref class xgp_Ax1;
    ref class xgp_Ax2;
    ref class xgp_Ax2d;
    ref class xgp_Pnt2d;
    ref class xgp_Dir2d;
    public ref class xgp
    {
    public:
        //! Method of package gp
        //!
        //! In geometric computations, defines the tolerance criterion
        //! used to determine when two numbers can be considered equal.
        //! Manynamespace TKMath  {  public ref class functions use this tolerance criterion, for
        //! example, to avoid division by zero in geometric
        //! computations. In the documentation, tolerance criterion is
        //! always referred to as gp::Resolution().
        static Standard_Real^ Resolution();

        //! Identifies a Cartesian point with coordinates X = Y = Z = 0.0.0
        static xgp_Pnt^ Origin();

        //! Returns a unit vector with the combination (1,0,0)
        static xgp_Dir^ DX();

        //! Returns a unit vector with the combination (0,1,0)
        static xgp_Dir^ DY();

        //! Returns a unit vector with the combination (0,0,1)
        static xgp_Dir^ DZ();

        //! Identifies an axis where its origin is Origin
        //! and its unit vector coordinates  X = 1.0,  Y = Z = 0.0
        static xgp_Ax1^ OX();

        //! Identifies an axis where its origin is Origin
        //! and its unit vector coordinates Y = 1.0,  X = Z = 0.0
        static xgp_Ax1^ OY();

        //! Identifies an axis where its origin is Origin
        //! and its unit vector coordinates Z = 1.0,  Y = X = 0.0
        static xgp_Ax1^ OZ();

        //! Identifies a coordinate system where its origin is Origin,
        //! and its "main Direction" and "X Direction" coordinates
        //! Z = 1.0, X = Y =0.0 and X direction coordinates X = 1.0, Y = Z = 0.0
        static xgp_Ax2^ XOY();

        //! Identifies a coordinate system where its origin is Origin,
        //! and its "main Direction" and "X Direction" coordinates
        //! Y = 1.0, X = Z =0.0 and X direction coordinates Z = 1.0, X = Y = 0.0
        static xgp_Ax2^ ZOX();

        //! Identifies a coordinate system where its origin is Origin,
        //! and its "main Direction" and "X Direction" coordinates
        //! X = 1.0, Z = Y =0.0 and X direction coordinates Y = 1.0, X = Z = 0.0
        //! In 2D space
        static xgp_Ax2^ YOZ();

        //! Identifies a Cartesian point with coordinates X = Y = 0.0
        static xgp_Pnt2d^ Origin2d();

        //! Returns a unit vector with the combinations (1,0)
        static xgp_Dir2d^ DX2d();

        //! Returns a unit vector with the combinations (0,1)
        static xgp_Dir2d^ DY2d();

        //! Identifies an axis where its origin is Origin2d
        //! and its unit vector coordinates are: X = 1.0,  Y = 0.0
        static xgp_Ax2d^ OX2d();

        //! Identifies an axis where its origin is Origin2d
        //! and its unit vector coordinates are Y = 1.0,  X = 0.0
        static xgp_Ax2d^ OY2d();

        /// <summary>
        /// ±¾µØ¾ä±ú
        /// </summary>
        property gp* Handle
        {
            gp* get() {
                return NativeHandle;
            }
        }

    private:
        gp* NativeHandle;
    };
};
