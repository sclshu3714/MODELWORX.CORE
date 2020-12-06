using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using TKTopAlgo;
using OCCT.TKMath.GP;
using OCCT.Foundation.Net.TKBRep;
using TKBRep;

namespace OCCT.Foundation.Net.TKPrim
{
    public class BRepBuilderAPI_MakeVertex : XBRepBuilderAPI_MakeVertex
    {
        public BRepBuilderAPI_MakeVertex(gp_Pnt P) : base(P)
        {

        }

        //public new TopoDS_Vertex Vertex() {
        //    return base.Vertex() as TopoDS_Vertex;
        //}
    }
}
