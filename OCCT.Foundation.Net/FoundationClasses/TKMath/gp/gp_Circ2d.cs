using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using TKMath;

namespace OCCT.TKMath.GP
{
    public class gp_Circ2d : xgp_Circ2d
    {
        public gp_Circ2d() : base() {

        }

        public gp_Circ2d(gp_Ax22d Axis, double Radius) : base(Axis, Radius) {

        }
        public gp_Circ2d(gp_Ax2d XAxis, double Radius, double Sense) : base(XAxis, Radius, Sense) {

        }
    }
}