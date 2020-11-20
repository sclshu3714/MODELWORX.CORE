using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OCCT.Foundation.Net
{
    //! Definition of line types
    public enum Aspect_TypeOfLine
    {
        Aspect_TOL_EMPTY = -1, //!< hidden
        Aspect_TOL_SOLID = 0, //!< continuous
        Aspect_TOL_DASH,       //!< dashed 2.0,1.0 (MM)
        Aspect_TOL_DOT,        //!< dotted 0.2,0.5 (MM)
        Aspect_TOL_DOTDASH,    //!< mixed  10.0,1.0,2.0,1.0 (MM)
        Aspect_TOL_USERDEFINED //!< defined by Users
    };
}
