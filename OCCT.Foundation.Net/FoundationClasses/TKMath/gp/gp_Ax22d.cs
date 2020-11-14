using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using TKMath;

namespace OCCT.TKMath.GP
{
    public class gp_Ax22d : xgp_Ax22d
    {
        public gp_Ax22d() : base() {

        }

        public gp_Ax22d(gp_Pnt2d P, gp_Dir2d Vx, gp_Dir2d Vy) : base(P, Vx, Vy) {

        }

        public gp_Ax22d(gp_Pnt2d P, gp_Dir2d V, bool Sense) : base(P, V, Sense) {

        }

        public gp_Ax22d(gp_Ax2d A, bool Sense) : base(A, Sense) {

        }
    }
}