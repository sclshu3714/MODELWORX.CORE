using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using TKMath;

namespace OCCT.TKMath.GP
{
    public class gp_Parab2d : xgp_Parab2d
    {
        public gp_Parab2d()
            : base() {

        }
        public gp_Parab2d(gp_Ax22d theAxes, double theFocalLength)
            : base(theAxes, theFocalLength) {

        }
        public gp_Parab2d(gp_Ax2d theDirectrix, gp_Pnt2d theFocus, double theSense)
            : base(theDirectrix, theFocus, theSense) {

        }
        public gp_Parab2d(gp_Ax2d theMirrorAxis, double theFocalLength, double theSense)
            : base(theMirrorAxis, theFocalLength, theSense) {

        }
    }
}