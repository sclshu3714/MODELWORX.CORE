using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using TKMath;

namespace OCCT.TKMath.GP
{
    public class gp_Pln : xgp_Pln
    {
        public gp_Pln()
            : base() {

        }

        public gp_Pln(gp_Ax3 A3)
            : base(A3) {

        }
        public gp_Pln(gp_Pnt P, gp_Dir V)
            : base(P, V) {

        }
        public gp_Pln(double A, double B, double C, double D)
            : base(A, B, C, D) {

        }
    }
}