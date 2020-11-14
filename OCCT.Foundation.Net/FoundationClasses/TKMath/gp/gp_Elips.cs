using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using TKMath;

namespace OCCT.TKMath.GP
{
    public class gp_Elips : xgp_Elips
    {
        public gp_Elips() : base() {

        }
        public gp_Elips(xgp_Ax2 A2, double MajorRadius, double MinorRadius) : base(A2, MajorRadius, MinorRadius) {

        }
    }
}