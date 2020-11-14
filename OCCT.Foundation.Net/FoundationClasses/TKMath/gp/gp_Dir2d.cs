using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using TKMath;

namespace OCCT.TKMath.GP
{
    public class gp_Dir2d : xgp_Dir2d
    {
        public gp_Dir2d() : base() {

        }
        public gp_Dir2d(gp_XY Coord) : base(Coord) {

        }
        public gp_Dir2d(gp_Vec2d V) : base(V) {

        }
        public gp_Dir2d(double Xv, double Yv) : base(Xv, Yv) {

        }
    }
}