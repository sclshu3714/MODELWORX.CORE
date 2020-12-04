#include "xgp.h"

namespace TKMath
{
    //! Method of package gp
       //!
       //! In geometric computations, defines the tolerance criterion
       //! used to determine when two numbers can be considered equal.
       //! Manynamespace TKMath  {  public ref class functions use this tolerance criterion, for
       //! example, to avoid division by zero in geometric
       //! computations. In the documentation, tolerance criterion is
       //! always referred to as gp::Resolution().
    Standard_Real xgp::Resolution() {
        return gp::Resolution();
    };

    //! Identifies a Cartesian point with coordinates X = Y = Z = 0.0.0
    xgp_Pnt^ xgp::Origin() {
        return gcnew xgp_Pnt(gp::Origin());
    };

    //! Returns a unit vector with the combination (1,0,0)
    xgp_Dir^ xgp::DX() {
        return gcnew xgp_Dir(gp::DX());
    };

    //! Returns a unit vector with the combination (0,1,0)
    xgp_Dir^ xgp::DY() {
        return gcnew xgp_Dir(gp::DY());
    };

    //! Returns a unit vector with the combination (0,0,1)
    xgp_Dir^ xgp::DZ() {
        return gcnew xgp_Dir(gp::DZ());
    };

    //! Identifies an axis where its origin is Origin
    //! and its unit vector coordinates  X = 1.0,  Y = Z = 0.0
    xgp_Ax1^ xgp::OX() {
        gp_Ax1* temp = new gp_Ax1(gp::OX());
        return gcnew xgp_Ax1(temp);
    };

    //! Identifies an axis where its origin is Origin
    //! and its unit vector coordinates Y = 1.0,  X = Z = 0.0
    xgp_Ax1^ xgp::OY() {
        gp_Ax1* temp = new gp_Ax1(gp::OY());
        return gcnew xgp_Ax1(temp);
    };

    //! Identifies an axis where its origin is Origin
    //! and its unit vector coordinates Z = 1.0,  Y = X = 0.0
    xgp_Ax1^ xgp::OZ() {
        gp_Ax1* temp = new gp_Ax1(gp::OZ());
        return gcnew xgp_Ax1(temp);
    };

    //! Identifies a coordinate system where its origin is Origin,
    //! and its "main Direction" and "X Direction" coordinates
    //! Z = 1.0, X = Y =0.0 and X direction coordinates X = 1.0, Y = Z = 0.0
    xgp_Ax2^ xgp::XOY() {
        return gcnew xgp_Ax2(gp::XOY());
    };

    //! Identifies a coordinate system where its origin is Origin,
    //! and its "main Direction" and "X Direction" coordinates
    //! Y = 1.0, X = Z =0.0 and X direction coordinates Z = 1.0, X = Y = 0.0
    xgp_Ax2^ xgp::ZOX() {
        return gcnew xgp_Ax2(gp::ZOX());
    };

    //! Identifies a coordinate system where its origin is Origin,
    //! and its "main Direction" and "X Direction" coordinates
    //! X = 1.0, Z = Y =0.0 and X direction coordinates Y = 1.0, X = Z = 0.0
    //! In 2D space
    xgp_Ax2^ xgp::YOZ() {
        return gcnew xgp_Ax2(gp::YOZ());
    };

    //! Identifies a Cartesian point with coordinates X = Y = 0.0
    xgp_Pnt2d^ xgp::Origin2d() {
        return gcnew xgp_Pnt2d(gp::Origin2d());
    };

    //! Returns a unit vector with the combinations (1,0)
    xgp_Dir2d^ xgp::DX2d() {
        return gcnew xgp_Dir2d(gp::DX2d());
    };

    //! Returns a unit vector with the combinations (0,1)
    xgp_Dir2d^ xgp::DY2d() {
        return gcnew xgp_Dir2d(gp::DY2d());
    };

    //! Identifies an axis where its origin is Origin2d
    //! and its unit vector coordinates are: X = 1.0,  Y = 0.0
    xgp_Ax2d^ xgp::OX2d() {
        return gcnew xgp_Ax2d(gp::OX2d());
    };

    //! Identifies an axis where its origin is Origin2d
    //! and its unit vector coordinates are Y = 1.0,  X = 0.0
    xgp_Ax2d^ xgp::OY2d() {
        return gcnew xgp_Ax2d(gp::OY2d());
    };
};

