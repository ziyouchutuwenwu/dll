//---------------------------------------------------------------------------

#ifndef ModuleHelperH
#define ModuleHelperH

#include <vcl.h>

const AnsiString TARGET_EXE_NAME = "regedit.exe";

//---------------------------------------------------------------------------
class CModuleHelper
{
public:
    static BOOL isTargetExe(AnsiString targetName);
};

#endif
