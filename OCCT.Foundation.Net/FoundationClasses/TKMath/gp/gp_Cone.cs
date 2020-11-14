using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using TKMath;

namespace OCCT.TKMath.GP
{
    public class gp_Cone : xgp_Cone
    {
        public gp_Cone() : base() {

        }

        public gp_Cone(gp_Ax3 A3, double Ang, double Radius) : base(A3, Ang, Radius) {

        }
    }
}