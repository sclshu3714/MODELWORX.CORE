using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using TKMath;

namespace OCCT.TKMath.GP
{
    public class gp_Hypr : xgp_Hypr
    {
        public gp_Hypr()
            : base() {

        }

        public gp_Hypr(gp_Ax2 A2, double MajorRadius, double MinorRadius)
            : base(A2, MajorRadius, MinorRadius) {

        }
    }
}