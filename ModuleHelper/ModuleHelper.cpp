//---------------------------------------------------------------------------

#pragma hdrstop

#include "ModuleHelper.h"

//---------------------------------------------------------------------------
BOOL CModuleHelper::isTargetExe(AnsiString targetName)
{
    AnsiString appName = ExtractFileName(Application->ExeName);

    if (targetName.LowerCase() != appName.LowerCase()) {
        return false;
    }

    return true;
}