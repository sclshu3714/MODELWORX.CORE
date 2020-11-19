#ifndef _XStandard_Helper_HeaderFile
#define _XStandard_Helper_HeaderFile
#pragma once
#include <vcclr.h>
#include <TCollection_AsciiString.hxx>

using namespace System;
namespace TKernel {

	public ref class XStandard_Helper
	{
	public:
        XStandard_Helper();
        //! Auxiliary tool for converting C# string into UTF-8 string.
        static TCollection_AsciiString toAsciiString(String^ theString);
	};
}
#endif _XStandard_Helper_HeaderFile

