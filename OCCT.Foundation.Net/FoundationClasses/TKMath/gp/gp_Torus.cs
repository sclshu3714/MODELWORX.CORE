using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using TKMath;

namespace OCCT.TKMath.GP
{
    public class gp_Torus : xgp_Torus
    {
        public gp_Torus() : base() {

        }

        public gp_Torus(gp_Ax3 A3, double MajorRadius, double MinorRadius) 
            : base(A3, MajorRadius, MinorRadius) {

        }
    }
}