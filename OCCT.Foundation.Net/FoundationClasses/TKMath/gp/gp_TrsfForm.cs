﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OCCT.Foundation.Net.FoundationClasses.TKMath.gp
{
    public enum gp_TrsfForm
	{
		gp_Identity,     //!< No transformation (matrix is identity)
		gp_Rotation,     //!< Rotation
		gp_Translation,  //!< Translation
		gp_PntMirror,    //!< Central symmetry
		gp_Ax1Mirror,    //!< Rotational symmetry
		gp_Ax2Mirror,    //!< Bilateral symmetry
		gp_Scale,        //!< Scale
		gp_CompoundTrsf, //!< Combination of the above transformations
		gp_Other         //!< Transformation with not-orthogonal matrix
	};
}
