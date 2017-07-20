//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "../dll/dll.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
//---------------------------------------------------------------------------

__fastcall TForm1::TForm1(TComponent* Owner)
  : TForm(Owner)
{
    _localHook = CLocalHook::shareInstance(dllHinstance);
    _localHook->setActiveKey(VK_F11);
    _localHook->setHookDelegate(this);
    _localHook->startLocalHook();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::onSysCommand(TMessage &msg)
{
    int key = msg.WParam;
    if( SC_CLOSE == key || SC_MAXIMIZE == key || SC_MINIMIZE == key )
    {
        if ( this->Showing )
        {
            this->Hide();
        }
        return;
    }

   TForm::Dispatch(&msg);
}

void TForm1::onHookKeyPressed(int key)
{
    if ( Showing )
    {
        Hide();
    }
    else
    {
        Show();
    }
}