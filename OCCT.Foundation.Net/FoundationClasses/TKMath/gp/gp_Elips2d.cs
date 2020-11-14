using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using TKMath;

namespace OCCT.TKMath.GP
{
    public class gp_Elips2d : xgp_Elips2d
    {
        public gp_Elips2d() 
            : base() {

        }
        public gp_Elips2d(gp_Ax22d A, double MajorRadius, double MinorRadius) 
            : base(A, MajorRadius, MinorRadius) {

        }
        public gp_Elips2d(gp_Ax2d MajorAxis, double MajorRadius, double MinorRadius, double Sense) 
            : base(MajorAxis, MajorRadius, MinorRadius, Sense) {

        }
    }
}