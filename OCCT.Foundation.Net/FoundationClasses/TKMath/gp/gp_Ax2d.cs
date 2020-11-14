using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using TKMath;

namespace OCCT.TKMath.GP
{
    public class gp_Ax2d : xgp_Ax2d
    {
        public gp_Ax2d() : base() {

        }

        public gp_Ax2d(gp_Pnt2d P, gp_Dir2d V) : base(P, V) {

        }
    }
}