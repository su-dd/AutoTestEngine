#include <Windows.h>
#include <QObject>
#include "AutoTestApp.h"

BOOL WINAPI DllMain(HINSTANCE  hInstance, DWORD dwReason, LPVOID lpvReserved )
{
    Q_UNUSED(lpvReserved);
    Q_UNUSED(hInstance);
    switch (dwReason)
    {
        case DLL_PROCESS_ATTACH:
        {
            AutoTestApp::instance().run();
            break;
        }
        case DLL_PROCESS_DETACH:
        {
            AutoTestApp::instance().done();
            break;
        }
        default:
        {
            // do nothing
            break;
        }
    }
    return TRUE;
}
