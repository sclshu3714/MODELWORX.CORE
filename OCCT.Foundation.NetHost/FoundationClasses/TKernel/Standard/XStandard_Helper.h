#ifndef _XStandard_Helper_HeaderFile
#define _XStandard_Helper_HeaderFile
#pragma once
#undef UNICODE
#include <vcclr.h>
#include <vector>
#include <TCollection_AsciiString.hxx>
#include <wtypes.h>
#include <vector>
#include <windows.h>
#include <stdio.h>
#include "resource.h"

#define MAKEINTRESOURCEA(i) ((LPSTR)((ULONG_PTR)((WORD)(i))))
#define MAKEINTRESOURCEW(i) ((LPWSTR)((ULONG_PTR)((WORD)(i))))
#ifdef UNICODE
#define MAKEINTRESOURCE  MAKEINTRESOURCEW
#else
#define MAKEINTRESOURCE  MAKEINTRESOURCEA
#endif // !UNICODE

using namespace std;
using namespace System;
using namespace System::Runtime;
using namespace System::Runtime::InteropServices;
namespace TKernel {

	public ref class XStandard_Helper
	{
	public:
        //! Auxiliary tool for converting C# string into UTF-8 string.
        static TCollection_AsciiString toAsciiString(String^ theString);
		static Standard_CString toCString(TCollection_AsciiString AsciiString);
		static String^ toString(TCollection_AsciiString AsciiString);
		static String^ toString(Standard_CString CString);
		static Object^ toObject(Standard_Address SAddress);
		//! ������
		XStandard_Helper(void);
		virtual ~XStandard_Helper() { OnFreeDll(); };

		////! �����Ҫ�ӳټ��ص�dll·��
		//Standard_Boolean AddDelayImportDll(LPCTSTR pszDllFileName);
		
		//! ��ȡ��Դ
		//! char lpszResourceType[20] = "DLLS";
		//! char szSaveFileName[20] = "myDll.dll";
		//! Standard_Boolean flag = FreeEmbedResourse(IDR_MYTYPES2, lpszResourceType, szSaveFileName);
		//! if (flag == Standard_True)
		//! {
		//! 	printf("the resource is free!\n");
		//! }
		//! return 0;
		Standard_Boolean FreeEmbedResourse(UINT uiResouceName, char* lpszResourceType, char* lpszSaveFileName);
	protected:
		void OnFreeDll();
	private:
		vector<HMODULE>* m_Modeules;
	};
}
#endif _XStandard_Helper_HeaderFile

