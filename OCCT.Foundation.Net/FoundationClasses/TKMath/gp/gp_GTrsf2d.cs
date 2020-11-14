using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using TKMath;

namespace OCCT.TKMath.GP
{
    public class gp_GTrsf2d : xgp_GTrsf2d
    {
        public gp_GTrsf2d()
            : base() {

        }

        public gp_GTrsf2d(gp_Trsf2d T)
            : base(T) {

        }
        public gp_GTrsf2d(gp_Mat2d M, gp_XY V)
            : base(M, V) {

        }
    }
}