#ifndef DLL_H
#define DLL_H
//---------------------------------------------------------------------------

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fwdreason, LPVOID lpvReserved);

extern "C" __declspec(dllexport) void __stdcall asyncLoadForm();

static BOOL isApplicationTarget(AnsiString targetName);
static void loadFormAndShow(bool shouldShow);
static void threadProc(void* param);

extern HINSTANCE dllHinstance;

#endif
