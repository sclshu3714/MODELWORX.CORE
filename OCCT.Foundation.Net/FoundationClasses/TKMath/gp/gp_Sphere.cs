using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using TKMath;

namespace OCCT.TKMath.GP
{
    public class gp_Sphere : xgp_Sphere
    {
        public gp_Sphere() 
            : base() {

        }

        public gp_Sphere(gp_Ax3 A3, double Radius)
            : base(A3, Radius) {

        }
    }
}