#ifndef _XStandard_Helper_HeaderFile
#define _XStandard_Helper_HeaderFile
#pragma once
#include <vcclr.h>
#include <TCollection_AsciiString.hxx>

using namespace System;
using namespace System::Runtime;
using namespace System::Runtime::InteropServices;
namespace TKernel {

	public ref class XStandard_Helper
	{
	public:
        XStandard_Helper();
        //! Auxiliary tool for converting C# string into UTF-8 string.
        static TCollection_AsciiString toAsciiString(String^ theString);
		static Standard_CString toCString(TCollection_AsciiString AsciiString);
		static String^ toString(TCollection_AsciiString AsciiString);
		static String^ toString(Standard_CString CString);
		static Object^ toObject(Standard_Address SAddress);
	};
}
#endif _XStandard_Helper_HeaderFile

