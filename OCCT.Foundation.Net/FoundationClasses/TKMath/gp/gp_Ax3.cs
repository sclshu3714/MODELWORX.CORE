using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using TKMath;

namespace OCCT.TKMath.GP
{
    public class gp_Ax3 : xgp_Ax3
    {
        public gp_Ax3() : base() {

        }

        public gp_Ax3(gp_Ax2 A) : base(A) {

        }

        public gp_Ax3(gp_Pnt P, gp_Dir N, gp_Dir Vx) : base(P, N, Vx) {

        }

        public gp_Ax3(gp_Pnt P, gp_Dir V) : base(P, V) {

        }
    }
}