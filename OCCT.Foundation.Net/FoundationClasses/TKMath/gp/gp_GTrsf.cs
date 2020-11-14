using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using TKMath;

namespace OCCT.TKMath.GP
{
    public class gp_GTrsf : xgp_GTrsf
    {
        public gp_GTrsf()
            : base() {

        }

        public gp_GTrsf(gp_Trsf T)
            : base(T) {

        }
        public gp_GTrsf(gp_Mat M, gp_XYZ V)
            : base(M, V) {

        }
}
}