using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using TKMath;

namespace OCCT.TKMath.GP
{
    public class gp_Lin2d : xgp_Lin2d
    {
        public gp_Lin2d()
            : base() {

        }
        public gp_Lin2d(gp_Ax2d A)
            : base(A) {

        }
        public gp_Lin2d(gp_Pnt2d P, gp_Dir2d V)
            : base(P, V) {

        }
        public gp_Lin2d(double A, double B, double C)
            : base(A, B, C) {

        }
    }
}