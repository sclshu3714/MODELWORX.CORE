using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using TKMath;

namespace OCCT.TKMath.GP
{
    public class gp_Vec : xgp_Vec
    {
        public gp_Vec() : base() {

        }

        public gp_Vec(gp_Dir V) : base(V) {

        }

        public gp_Vec(gp_XYZ Coord) : base(Coord) {

        }

        public gp_Vec(double Xv, double Yv, double Zv) : base(Xv, Yv, Zv) {

        }

        public gp_Vec(gp_Pnt P1, gp_Pnt P2) : base(P1, P2) {

        }
    }
}
