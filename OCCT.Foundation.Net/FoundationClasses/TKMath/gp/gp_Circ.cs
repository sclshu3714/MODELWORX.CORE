using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using TKMath;

namespace OCCT.TKMath.GP
{
    public class gp_Circ : xgp_Circ
    {
        public gp_Circ() : base() {

        }

        public gp_Circ(gp_Ax2 A2, double Radius): base(A2, Radius) {

        }
}
}