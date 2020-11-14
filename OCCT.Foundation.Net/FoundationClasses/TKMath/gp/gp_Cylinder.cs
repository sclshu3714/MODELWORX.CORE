using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using TKMath;

namespace OCCT.TKMath.GP
{
    public class gp_Cylinder : xgp_Cylinder
    {
        public gp_Cylinder() : base() {

        }

        public gp_Cylinder(gp_Ax3 A3, double Radius) : base(A3, Radius) {

        }
    }
}