/*!
 * @brief 头文件说明
 *
 * 用于管理钩子
 * @author  sul-a
 * @date:    2019/07/03
 * @remarks
 * Copyright   (c) 1998-2012 Glodon Corporation
*/
#ifndef HOOKMANAGER_H
#define HOOKMANAGER_H

#include "Windows.h"
#include <QList>

class HookManager
{
public:
    static HookManager& instance();

    ~HookManager();
    bool HookFunc(LPVOID pTarget, LPVOID pDetour, LPVOID *ppOriginal);

private:

    HookManager();
    bool initHook();
    void unAllHook();
    bool unHookFunc(LPVOID pTarget);
private:
    QList<LPVOID> m_oHookFuncList;
    bool m_bInit;
};

#endif // HOOKMANAGER_H
