//---------------------------------------------------------------------------

#pragma hdrstop

#include "LocalHook.h"
//---------------------------------------------------------------------------

static CLocalHook* _shareInstance = NULL;

CLocalHook* CLocalHook::shareInstance(HINSTANCE hInst)
{
    if (NULL == _shareInstance) {
        _shareInstance = new CLocalHook(hInst);
    }

    return _shareInstance;
}

CLocalHook::CLocalHook(HINSTANCE hInst)
{
    _hInst = hInst;
    _activeKey = 0;
    _oldHook = NULL;
}

void CLocalHook::setActiveKey(int key)
{
    _activeKey = key;
}

void CLocalHook::setHookDelegate(ILocalHookDelegate* hookDelegate)
{
    _hookDelegate = hookDelegate;
}

long CALLBACK CLocalHook::keyProc(int code, WPARAM wParam, LPARAM lParam)
{
    if (NULL == _shareInstance) {
        return 1;
    }

    if (HC_ACTION == code) {
        int keyStatus = (DWORD)lParam & 0x80000000;

        if (keyStatus != 0) //键盘按下
        {
        }
        if (keyStatus == 0) //键盘起来
        {
            int key = wParam;

            if (NULL != _shareInstance->_hookDelegate) {
                if (key == _shareInstance->_activeKey) {
                    _shareInstance->_hookDelegate->onHookKeyPressed(key);
                }
            }
        }
    }

    return CallNextHookEx(_shareInstance->_oldHook, code, wParam, lParam);
}

void CLocalHook::startLocalHook()
{
    if (NULL == _oldHook) {
        _oldHook = SetWindowsHookEx(WH_KEYBOARD, (FARPROC)keyProc, _hInst, NULL);
    }
    return;
}

void CLocalHook::stopLocalHook()
{
    if (NULL != _oldHook) {
        UnhookWindowsHookEx(_oldHook);
        _oldHook = NULL;
    }
    return;
}
