#ifndef DLL_H
#define DLL_H
//---------------------------------------------------------------------------

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fwdreason, LPVOID lpvReserved);

//这里注释掉，关闭导出
//extern "C" __declspec(dllexport)
void __stdcall asyncLoadForm();

static BOOL isApplicationTarget(AnsiString targetName);
static void loadFormAndShow(bool shouldShow);
static void threadProc(void* param);

extern HINSTANCE dllHinstance;

#endif
