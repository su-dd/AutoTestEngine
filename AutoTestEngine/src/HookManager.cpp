#include "HookManager.h"

#include <Windows.h>
#include "MinHook.h"

HookManager &HookManager::instance()
{
    static HookManager oHookManager;
    return oHookManager;
}

HookManager::HookManager()
    : m_bInit(false)
{
    m_bInit = initHook();
}

HookManager::~HookManager()
{
    unAllHook();
}

bool HookManager::HookFunc(LPVOID pTarget, LPVOID pDetour, LPVOID *ppOriginal)
{
    if (!m_bInit)
    {
        return false;
    }

    if (m_oHookFuncList.contains(pTarget))
    {
        OutputDebugString(L" hook �����ɹ�\r\n");
        return true;
    }

    if (MH_CreateHook(pTarget, pDetour, ppOriginal) != MH_OK)
    {
        OutputDebugString(L"hook ����ʧ��");
        return false;
    }
    if (MH_EnableHook(pTarget) != MH_OK)
    {
        OutputDebugString(L"hook ��ʼ������ʧ��");
        return false;
    }
    m_oHookFuncList.append(pTarget);
    OutputDebugString(L" hook �����ɹ�\r\n");
    return true;
}

bool HookManager::initHook()
{
    if (MH_Initialize() != MH_OK)
    {
        OutputDebugString(L"hook ��ʼ��ʧ��\r\n");
        return false;
    }
    OutputDebugString(L"hook ��ʼ���ɹ�\r\n");
    return true;
}

void HookManager::unAllHook()
{
    bool b_UnHookState = true;
    foreach (LPVOID pTarget, m_oHookFuncList)
    {
        b_UnHookState &= unHookFunc(pTarget);
    }

    if (b_UnHookState)
    {
        MH_Uninitialize();
        OutputDebugString(L"hook ж�سɹ�\r\n");
    }
}

bool HookManager::unHookFunc(LPVOID pTarget)
{
    if (MH_DisableHook(pTarget) != MH_OK)
    {
        OutputDebugString(L"hook ж��ʧ��\r\n");
        return false;
    }

    return true;
}
