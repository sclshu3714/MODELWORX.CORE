using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using TKMath;

namespace OCCT.TKMath.GP
{
    public class gp_Dir : xgp_Dir
    {
        public gp_Dir() : base() {

        }

        //! Normalizes the vector V and creates a direction. Raises ConstructionError if V.Magnitude() <= Resolution.
        public gp_Dir(gp_Vec V) : base(V) {

        }

        //! Creates a direction from a triplet of coordinates. Raises ConstructionError if Coord.Modulus() <= Resolution from gp.
        public gp_Dir(gp_XYZ Coord) : base(Coord) {

        }

        //! Creates a direction with its 3 cartesian coordinates. Raises ConstructionError if Sqrt(Xv*Xv + Yv*Yv + Zv*Zv) <= Resolution
        //! Modification of the direction's coordinates
        //! If Sqrt (X*X + Y*Y + Z*Z) <= Resolution from gp where
        //! X, Y ,Z are the new coordinates it is not possible to
        //! construct the direction and the method raises the
        //! exception ConstructionError.
        public gp_Dir(double Xv, double Yv, double Zv) : base(Xv, Yv, Zv) {

        }
    }
}