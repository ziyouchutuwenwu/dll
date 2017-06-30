//---------------------------------------------------------------------------


#pragma hdrstop

#include "ModuleHelper.h"

const AnsiString TARGET_EXE_NAME = "regedit.exe";

//---------------------------------------------------------------------------
BOOL CModuleHelper::isTargetExe(AnsiString targetName)
{
    AnsiString appName = ExtractFileName(Application->ExeName);
    
    if ( targetName != appName )
    {
        return false;
    }
    
    return true;
}

#pragma package(smart_init)
