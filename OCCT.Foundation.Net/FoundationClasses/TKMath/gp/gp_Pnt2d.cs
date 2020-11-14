using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using TKMath;

namespace OCCT.TKMath.GP
{
    public class gp_Pnt2d : xgp_Pnt2d
    {
        public gp_Pnt2d() : base() {

        }

        public gp_Pnt2d(gp_XY Coord) : base(Coord) {

        }
        public gp_Pnt2d(double Xp, double Yp) : base(Xp, Yp) {

        }
    }
}