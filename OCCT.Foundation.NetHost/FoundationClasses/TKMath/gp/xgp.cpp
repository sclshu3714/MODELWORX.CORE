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
        gp_Pnt* temp = new gp_Pnt(gp::Origin());
        return gcnew xgp_Pnt(temp);
    };

    //! Returns a unit vector with the combination (1,0,0)
    xgp_Dir^ xgp::DX() {
        gp_Dir* temp = new gp_Dir(gp::DX());
        return gcnew xgp_Dir(temp);
    };

    //! Returns a unit vector with the combination (0,1,0)
    xgp_Dir^ xgp::DY() {
        gp_Dir* temp = new gp_Dir(gp::DY());
        return gcnew xgp_Dir(temp);
    };

    //! Returns a unit vector with the combination (0,0,1)
    xgp_Dir^ xgp::DZ() {
        gp_Dir* temp = new gp_Dir(gp::DZ());
        return gcnew xgp_Dir(temp);
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
        gp_Ax2* temp = new gp_Ax2(gp::XOY());
        return gcnew xgp_Ax2(temp);
    };

    //! Identifies a coordinate system where its origin is Origin,
    //! and its "main Direction" and "X Direction" coordinates
    //! Y = 1.0, X = Z =0.0 and X direction coordinates Z = 1.0, X = Y = 0.0
    xgp_Ax2^ xgp::ZOX() {
        gp_Ax2* temp = new gp_Ax2(gp::ZOX());
        return gcnew xgp_Ax2(temp);
    };

    //! Identifies a coordinate system where its origin is Origin,
    //! and its "main Direction" and "X Direction" coordinates
    //! X = 1.0, Z = Y =0.0 and X direction coordinates Y = 1.0, X = Z = 0.0
    //! In 2D space
    xgp_Ax2^ xgp::YOZ() {
        gp_Ax2* temp = new gp_Ax2(gp::YOZ());
        return gcnew xgp_Ax2(temp);
    };

    //! Identifies a Cartesian point with coordinates X = Y = 0.0
    xgp_Pnt2d^ xgp::Origin2d() {
        gp_Pnt2d* temp = new gp_Pnt2d(gp::Origin2d());
        return gcnew xgp_Pnt2d(temp);
    };

    //! Returns a unit vector with the combinations (1,0)
    xgp_Dir2d^ xgp::DX2d() {
        gp_Dir2d* temp = new gp_Dir2d(gp::DX2d());
        return gcnew xgp_Dir2d(temp);
    };

    //! Returns a unit vector with the combinations (0,1)
    xgp_Dir2d^ xgp::DY2d() {
        gp_Dir2d* temp = new gp_Dir2d(gp::DY2d());
        return gcnew xgp_Dir2d(temp);
    };

    //! Identifies an axis where its origin is Origin2d
    //! and its unit vector coordinates are: X = 1.0,  Y = 0.0
    xgp_Ax2d^ xgp::OX2d() {
        gp_Ax2d* temp = new gp_Ax2d(gp::OX2d());
        return gcnew xgp_Ax2d(temp);
    };

    //! Identifies an axis where its origin is Origin2d
    //! and its unit vector coordinates are Y = 1.0,  X = 0.0
    xgp_Ax2d^ xgp::OY2d() {
        gp_Ax2d* temp = new gp_Ax2d(gp::OY2d());
        return gcnew xgp_Ax2d(temp);
    };
};

