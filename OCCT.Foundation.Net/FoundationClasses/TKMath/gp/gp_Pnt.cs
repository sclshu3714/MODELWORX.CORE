using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using TKMath;

namespace OCCT.TKMath.GP
{
    public class gp_Pnt : xgp_Pnt
    {
        public gp_Pnt() : base() {

        }

        public gp_Pnt(gp_XYZ Coord) : base(Coord) {

        }
        public gp_Pnt(double Xp, double Yp, double Zp) : base(Xp, Yp, Zp) {

        }
    }
}