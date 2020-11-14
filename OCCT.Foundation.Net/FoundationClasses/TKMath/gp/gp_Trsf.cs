using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using TKMath;

namespace OCCT.TKMath.GP
{
    public class gp_Trsf : xgp_Trsf
    {
        public gp_Trsf()
            : base() {

        }

        public gp_Trsf(gp_Trsf2d T)
            : base(T) {

        }
    }
}