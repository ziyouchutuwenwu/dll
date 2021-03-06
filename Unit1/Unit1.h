//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include "../LocalHook/LocalHook.h"
#include <Classes.hpp>
#include <Controls.hpp>
#include <Forms.hpp>
#include <StdCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm, public ILocalHookDelegate {
    __published : // IDE-managed Components
                  private : // User declarations
                            void __fastcall onSysCommand(TMessage& msg);

    CLocalHook* _localHook;
    void onHookKeyPressed(int key);

public: // User declarations
    __fastcall TForm1(TComponent* Owner);

    BEGIN_MESSAGE_MAP
    MESSAGE_HANDLER(WM_SYSCOMMAND, TMessage, onSysCommand)
    END_MESSAGE_MAP(TForm)
};

#endif