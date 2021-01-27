#include "XStandard_Helper.h"
//#include <WinUser.h>
//#include <afxwin.h>
using namespace System;
namespace TKernel {
    //! Auxiliary tool for converting C# string into UTF-8 string.
    TCollection_AsciiString XStandard_Helper::toAsciiString(String^ theString) {
        if (theString == nullptr) {
            return TCollection_AsciiString();
        }

        pin_ptr<const wchar_t> aPinChars = PtrToStringChars(theString);
        const wchar_t* aWCharPtr = aPinChars;
        if (aWCharPtr == NULL
            || *aWCharPtr == L'\0') {
            return TCollection_AsciiString();
        }
        return TCollection_AsciiString(aWCharPtr);
    }

    Standard_CString XStandard_Helper::toCString(TCollection_AsciiString AString) {
        return AString.ToCString();
    };

    String^ XStandard_Helper::toString(Standard_CString CString) {
        TCollection_AsciiString AString = TCollection_AsciiString(CString);
        char buff[255];
        for (int ic = 1; ic <= AString.Length(); ic++)
            buff[ic - 1] = AString.Value(ic);
        buff[AString.Length()] = '\0';
        char* ch1 = buff;
        String^ sString = System::Runtime::InteropServices::Marshal::PtrToStringAnsi((IntPtr)ch1);
        //System::String^ sString = gcnew System::String(CString);
        return sString;
    };

    String^ XStandard_Helper::toString(TCollection_AsciiString AString) {
        char buff[255];
        for (int ic = 1; ic <= AString.Length(); ic++)
            buff[ic - 1] = AString.Value(ic);
        buff[AString.Length()] = '\0';
        char* ch1 = buff;
        String^ sString = System::Runtime::InteropServices::Marshal::PtrToStringAnsi((IntPtr)ch1);
        //System::String^ sString = gcnew System::String(AString.ToCString());
        return sString;
    };

    Object^ XStandard_Helper::toObject(Standard_Address SAddress) {
        GCHandle gcHandle = GCHandle::FromIntPtr(IntPtr(SAddress));
        Object^ ObjectResult = gcHandle.Target;
        gcHandle.Free();
        return ObjectResult;
    };

    //Standard_Boolean XStandard_Helper::ActivateValidation(HWND hWnd, Standard_Real X, Standard_Real Y) {

    //    //CWnd wnd;
    //    //wnd.Attach(hWnd);//句柄到对象
    //    //CDC* cdc = wnd.GetDC();
    //    //HDC hdc = cdc->GetSafeHdc();
    //    ////CDC* pDC = CDC::FromHandle(CHWND);
    //    ////HDC hdc = GetDC(hWND);//或者hdc=GetWindowDC(hwnd);两者有一点差别
    //    ////MoveToEx(hdc, 100, 100, NULL);//起点定在坐标(100,100)处
    //    ////LineTo(hdc, 200, 200);//画一个（100，100）到（200，200）的线条
    //    ////ReleaseDC(reinterpret_cast<HWND> (theWnd.ToPointer()), hdc);//Over
    //    return Standard_False;
    //};

    XStandard_Helper::XStandard_Helper(void) {

    };

    //Standard_Boolean XStandard_Helper::AddDelayImportDll(LPCTSTR pszDllFileName)
    //{
    //    HMODULE hModule = ::LoadLibrary(pszDllFileName);
    //    if (hModule == NULL)
    //        return Standard_False;
    //    m_Modeules->push_back(hModule);
    //    return Standard_True;
    //};

    void XStandard_Helper::OnFreeDll()
    {
        for (size_t i = 0; i < m_Modeules->size(); ++i)
            ::FreeLibrary(m_Modeules->at(i));
        m_Modeules->clear();
    };

    // 提取资源
    Standard_Boolean XStandard_Helper::FreeEmbedResourse(UINT uiResouceName, char* lpszResourceType, char* lpszSaveFileName)
    {
        HRSRC hRsrc = FindResource(NULL, MAKEINTRESOURCE(uiResouceName), lpszResourceType);
        if (hRsrc == NULL)
        {
            printf("can't find the resource!\n");
            return Standard_False;
        }
        DWORD dwSize = SizeofResource(NULL, hRsrc);
        if (dwSize <= 0)
        {
            printf("the resource's size is error!\n");
            return Standard_False;
        }
        HGLOBAL hGlobal = LoadResource(NULL, hRsrc);
        if (hGlobal == NULL)
        {
            printf("load resource error!\n");
            return Standard_False;
        }
        LPVOID lpVoid = LockResource(hGlobal);
        if (lpVoid == NULL)
        {
            printf("lock resource error!\n");
            return Standard_False;
        }
        FILE* fp = NULL;
        fopen_s(&fp, lpszSaveFileName, "wb+");
        if (fp == NULL)
        {
            printf("open file error!\n");
            return Standard_False;
        }
        fwrite(lpVoid, sizeof(char), dwSize, fp);
        fclose(fp);
        return Standard_True;
    };
}