using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using TKMath;

namespace OCCT.TKMath.GP
{
    public class gp_Mat2d : xgp_Mat2d
    {
        public gp_Mat2d()
            : base() {

        }
        public gp_Mat2d(gp_XY Col1, gp_XY Col2)
            : base(Col1, Col2) {

        }
    }
}