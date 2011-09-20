// adminred.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <tchar.h>
#include <Windows.h>
#include "resource.h"

int _tmain(int argc, _TCHAR* argv[])
{
    typedef DWORD (__stdcall *TSetConsoleIcon)(HICON);
    HMODULE hMod = LoadLibrary(_T("kernel32.dll"));
    TSetConsoleIcon SetConsoleIcon = reinterpret_cast<TSetConsoleIcon>(GetProcAddress(hMod, "SetConsoleIcon"));
    CONSOLE_SCREEN_BUFFER_INFOEX info;
    info.cbSize = sizeof(info);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfoEx(hConsole, &info);
    info.ColorTable[0] = RGB(0x30, 0x10, 0x10); 
    info.srWindow.Bottom++;
    info.srWindow.Right++;
    SetConsoleScreenBufferInfoEx(hConsole, &info);
    HICON hIcon=LoadIcon(GetModuleHandle(0),MAKEINTRESOURCE(IDI_PSRED));
    SetConsoleIcon(hIcon);
    return 0;
}

