//---------------------------------------------------------------------------
#include <vcl.h>
#include <windows.h>
#include <process.h>
#include "dll.h"
#include "../Unit1/Unit1.h"
#include "../ModuleHelper/ModuleHelper.h"

#pragma hdrstop
#pragma argsused

//用于局部钩子
HINSTANCE dllHinstance;

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fwdreason, LPVOID lpvReserved)
{
    BOOL result = true;

    switch( fwdreason)
    {
        case DLL_PROCESS_ATTACH:
            if ( !CModuleHelper::isTargetExe(TARGET_EXE_NAME) )
            {
                result = false;
            }
            else
            {
                dllHinstance = hinstDLL;
                asyncLoadForm();
            }
            break;
        case DLL_PROCESS_DETACH:
            if ( CModuleHelper::isTargetExe(TARGET_EXE_NAME) )
            {
                FreeLibraryAndExitThread(hinstDLL, 0);
            }
            break;
    }
    
    return result;
}

void __stdcall asyncLoadForm()
{
    _beginthread(threadProc, NULL, NULL);
    return;
}

void threadProc(void* param)
{
    loadFormAndShow(true);
}

void loadFormAndShow(bool shouldShow)
{
    static TForm1* mainForm = NULL;

    if ( NULL == mainForm )
    {
        mainForm = new TForm1(Application);
        mainForm->ShowModal();

        return;
    }

    if ( shouldShow ) mainForm->ShowModal();
    
    return;
}
