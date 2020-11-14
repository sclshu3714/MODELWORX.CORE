using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using TKMath;

namespace OCCT.TKMath.GP
{
    public class gp_Parab : xgp_Parab
    {
        public gp_Parab()
            : base() {

        }
        public gp_Parab(gp_Ax1 D, gp_Pnt F)
            : base(D, F) {

        }
        public gp_Parab(gp_Ax2 A2, double Focal)
            : base(A2, Focal) {

        }
    }
}