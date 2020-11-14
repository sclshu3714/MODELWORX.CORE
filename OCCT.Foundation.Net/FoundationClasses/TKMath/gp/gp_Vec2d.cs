using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using TKMath;

namespace OCCT.TKMath.GP
{
    public class gp_Vec2d : xgp_Vec2d
    {
        public gp_Vec2d() : base() {

        }
        public gp_Vec2d(gp_XY Coord) : base(Coord) {

        }
        public gp_Vec2d(gp_Dir2d V) : base(V) {

        }
        public gp_Vec2d(gp_Pnt2d P1, gp_Pnt2d P2) : base(P1, P2) {

        }
        public gp_Vec2d(double Xv, double Yv) : base(Xv, Yv) {

        }
    }
}