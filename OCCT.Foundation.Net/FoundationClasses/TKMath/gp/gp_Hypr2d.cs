using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using TKMath;

namespace OCCT.TKMath.GP
{
    public class gp_Hypr2d : xgp_Hypr2d
    {
        public gp_Hypr2d()
            : base() {

        }
        public gp_Hypr2d(xgp_Ax22d A, double MajorRadius, double MinorRadius)
            : base(A, MajorRadius, MinorRadius) {

        }
        public gp_Hypr2d(xgp_Ax2d MajorAxis, double MajorRadius, double MinorRadius, double Sense)
            : base(MajorAxis, MajorRadius, MinorRadius, Sense) {

        }
    }
}