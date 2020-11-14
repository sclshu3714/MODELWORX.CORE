using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using TKMath;

namespace OCCT.TKMath.GP
{
    public class gp_Ax2 : xgp_Ax2
    {
        public gp_Ax2() : base() {

        }

        //! Creates an axis placement with an origin P such that:
        //! -   N is the Direction, and
        //! -   the "X Direction" is normal to N, in the plane
        //! defined by the vectors (N, Vx): "X
        //! Direction" = (N ^ Vx) ^ N,
        //! Exception: raises ConstructionError if N and Vx are parallel (same or opposite orientation).
        public gp_Ax2(gp_Pnt P, gp_Dir N, gp_Dir Vx) : base(P, N, Vx) {

        }

        //! Creates -   a coordinate system with an origin P, where V
        //! gives the "main Direction" (here, "X Direction" and "Y
        //! Direction" are defined automatically).
        public gp_Ax2(gp_Pnt P, gp_Dir V) : base(P, V) {

        }
    }
}
