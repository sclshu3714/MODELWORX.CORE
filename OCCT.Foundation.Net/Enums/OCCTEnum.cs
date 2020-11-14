using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OCCT.Foundation.Net
{
	public enum CurrentModel
	{
		Zero = 0,
		Left = 1,
		Middle = 2,
		Right = 4,
		LeftRight = 5,
		LeftMiddle = 3,
		RightMiddle = 6,
		All = 7
	}

	[Flags]
	public enum CurrentUpdateFlags
	{
		Model = 1,
		Selection = 2,
		Material = 4,
		Camera = 0x10,
		Light = 0x20,
		Scene = 0x40
	}

	[Flags]
	public enum CurrentAction3d
	{
		CurAction3d_Nothing,
		CurAction3d_DynamicZooming,
		CurAction3d_WindowZooming,
		CurAction3d_DynamicPanning,
		CurAction3d_GlobalPanning,
		CurAction3d_DynamicRotation
	}

	[Flags]
	public enum CurrentPressedKey
	{
		CurPressedKey_Nothing,
		CurPressedKey_Ctrl,
		CurPressedKey_Shift,
		CurPressedKey_Alt
	}

	public enum CurrentModelFormat
	{
		BREP,
		STEP,
		IGES,
		VRML,
		STL,
		IMAGE
	}

	public enum Graphic3d_NameOfMaterial
	{
		/// <summary>
		/// 黄铜
		/// </summary>
		Graphic3d_NOM_BRASS,
		/// <summary>
		/// 青铜色
		/// </summary>
		Graphic3d_NOM_BRONZE,
		/// <summary>
		/// 铜
		/// </summary>
		Graphic3d_NOM_COPPER,
		/// <summary>
		/// 黄金
		/// </summary>
		Graphic3d_NOM_GOLD,
		/// <summary>
		/// 白蜡
		/// </summary>
		Graphic3d_NOM_PEWTER,
		/// <summary>
		/// 灰泥
		/// </summary>
		Graphic3d_NOM_PLASTER,
		/// <summary>
		/// 塑料
		/// </summary>
		Graphic3d_NOM_PLASTIC,
		/// <summary>
		/// 银
		/// </summary>
		Graphic3d_NOM_SILVER,
		/// <summary>
		/// 钢
		/// </summary>
		Graphic3d_NOM_STEEL,
		/// <summary>
		/// 石头
		/// </summary>
		Graphic3d_NOM_STONE,
		/// <summary>
		/// 闪亮的塑料
		/// </summary>
		Graphic3d_NOM_SHINY_PLASTIC,
		/// <summary>
		/// 缎子
		/// </summary>
		Graphic3d_NOM_SATIN,
		/// <summary>
		/// 金属化
		/// </summary>
		Graphic3d_NOM_METALIZED,
		/// <summary>
		/// 
		/// </summary>
		Graphic3d_NOM_NEON_GNC,
		/// <summary>
		/// 铬
		/// </summary>
		Graphic3d_NOM_CHROME,
		/// <summary>
		/// 铝
		/// </summary>
		Graphic3d_NOM_ALUMINIUM,
		/// <summary>
		/// 黑曜石
		/// </summary>
		Graphic3d_NOM_OBSIDIAN,
		/// <summary>
		/// 
		/// </summary>
		Graphic3d_NOM_NEON_PHC,
		/// <summary>
		/// 玉
		/// </summary>
		Graphic3d_NOM_JADE,
		/// <summary>
		/// 木炭
		/// </summary>
		Graphic3d_NOM_CHARCOAL,
		/// <summary>
		/// 水
		/// </summary>
		Graphic3d_NOM_WATER,
		/// <summary>
		/// 玻璃
		/// </summary>
		Graphic3d_NOM_GLASS,
		/// <summary>
		/// 钻石
		/// </summary>
		Graphic3d_NOM_DIAMOND,
		/// <summary>
		/// 透明的
		/// </summary>
		Graphic3d_NOM_TRANSPARENT,
		/// <summary>
		/// 默认
		/// </summary>
		Graphic3d_NOM_DEFAULT,
		/// <summary>
		/// 自定义
		/// </summary>
		Graphic3d_NOM_UserDefined
	};
	enum gp_TrsfForm
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

	enum gp_EulerSequence
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

	enum TopAbs_ShapeEnum
	{
		TopAbs_COMPOUND,
		TopAbs_COMPSOLID,
		TopAbs_SOLID,
		TopAbs_SHELL,
		TopAbs_FACE,
		TopAbs_WIRE,
		TopAbs_EDGE,
		TopAbs_VERTEX,
		TopAbs_SHAPE
	};
}
