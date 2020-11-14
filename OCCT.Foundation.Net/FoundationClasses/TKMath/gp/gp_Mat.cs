using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using TKMath;

namespace OCCT.TKMath.GP
{
    public class gp_Mat : xgp_Mat
    {
        public gp_Mat()
            : base() {

        }
        public gp_Mat(gp_XYZ Col1, gp_XYZ Col2, gp_XYZ Col3)
            : base(Col1, Col2, Col3) {

        }
        public gp_Mat(double a11, double a12, double a13, double a21, double a22, double a23, double a31, double a32, double a33)
            : base(a11, a12, a13, a21, a22, a23, a31, a32, a33) {

        }
    }
}