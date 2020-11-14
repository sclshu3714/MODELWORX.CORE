using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using TKMath;

namespace OCCT.TKMath.GP
{
    public class gp_Ax1 : xgp_Ax1
    {
        public gp_Ax1() : base() { 
            
        }
        //! P is the location point and V is the direction of <me>.
        public gp_Ax1(gp_Pnt P, gp_Dir V) : base(P, V) { 
            
        }
    }
}
