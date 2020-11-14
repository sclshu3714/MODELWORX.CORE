using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using TKMath;

namespace OCCT.TKMath.GP
{
    public class gp_Lin : xgp_Lin
    {
        public gp_Lin()
            : base() {

        }
        public gp_Lin(gp_Ax1 A1)
            : base(A1) {

        }
        public gp_Lin(gp_Pnt P, gp_Dir V)
            : base(P, V) {

        }
    }
}