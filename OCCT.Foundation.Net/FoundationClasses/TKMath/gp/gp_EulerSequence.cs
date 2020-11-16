using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OCCT.Foundation.Net
{
    public enum gp_EulerSequence
	{
		//! Classic Euler angles, alias to Intrinsic_ZXZ
		gp_EulerAngles,

		//! Yaw Pitch Roll (or nautical) angles, alias to Intrinsic_ZYX
		gp_YawPitchRoll,

		// Tait-Bryan angles (using three different axes)
		gp_Extrinsic_XYZ,
		gp_Extrinsic_XZY,
		gp_Extrinsic_YZX,
		gp_Extrinsic_YXZ,
		gp_Extrinsic_ZXY,
		gp_Extrinsic_ZYX,

		gp_Intrinsic_XYZ,
		gp_Intrinsic_XZY,
		gp_Intrinsic_YZX,
		gp_Intrinsic_YXZ,
		gp_Intrinsic_ZXY,
		gp_Intrinsic_ZYX,

		// Proper Euler angles (using two different axes, first and third the same)
		gp_Extrinsic_XYX,
		gp_Extrinsic_XZX,
		gp_Extrinsic_YZY,
		gp_Extrinsic_YXY,
		gp_Extrinsic_ZYZ,
		gp_Extrinsic_ZXZ,

		gp_Intrinsic_XYX,
		gp_Intrinsic_XZX,
		gp_Intrinsic_YZY,
		gp_Intrinsic_YXY,
		gp_Intrinsic_ZXZ,
		gp_Intrinsic_ZYZ
	};
}
