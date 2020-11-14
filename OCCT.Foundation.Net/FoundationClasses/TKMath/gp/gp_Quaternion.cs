using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using TKMath;

namespace OCCT.TKMath.GP
{
    public class gp_Quaternion : xgp_Quaternion
    {
        public gp_Quaternion()
            : base() {

        }
        public gp_Quaternion(gp_Mat theMat)
            : base(theMat) {

        }
        public gp_Quaternion(gp_Quaternion theToCopy)
            : base(theToCopy) {

        }
        public gp_Quaternion(gp_Vec theAxis, double theAngle)
            : base(theAxis, theAngle) {

        }
        public gp_Quaternion(gp_Vec theVecFrom, gp_Vec theVecTo)
            : base(theVecFrom, theVecTo) {

        }
        public gp_Quaternion(gp_Vec theVecFrom, gp_Vec theVecTo, gp_Vec theHelpCrossVec)
            : base(theVecFrom, theVecTo, theHelpCrossVec) {

        }
        public gp_Quaternion(double x, double y, double z, double w)
            : base(x, y, z, w) {

        }
    }
}