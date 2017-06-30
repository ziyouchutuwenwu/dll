//---------------------------------------------------------------------------

#ifndef LocalHookH
#define LocalHookH
//---------------------------------------------------------------------------
#include <windows.h>

class ILocalHookDelegate
{
public:
    virtual void onHookKeyPressed(int key) = 0;
};

class CLocalHook
{
public:
    void startLocalHook();
    void stopLocalHook();
    void setActiveKey(int key);

    void setHookDelegate(ILocalHookDelegate* hookDelegate);

    static CLocalHook* shareInstance(HINSTANCE hInst);
private:
    CLocalHook(HINSTANCE hInst);
    static long CALLBACK keyProc(int code, WPARAM wParam, LPARAM lParam);

    int _activeKey;
    ILocalHookDelegate* _hookDelegate;

    HINSTANCE _hInst;
    HHOOK     _oldHook;
};

#endif
