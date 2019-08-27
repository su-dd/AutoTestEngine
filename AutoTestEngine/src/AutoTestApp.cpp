#include "AutoTestApp.h"

#include <QMessageBox>
#include <QApplication>
#include <QTime>
#include "IAdapter.h"
#include "AdapterManager.h"
#include "ControlManage.h"
#include "HookManager.h"
#include "MainView.h"

// 定义原有方法，钩住user32.dll中的showWindow
typedef BOOL (WINAPI *FuncShowWindow)(HWND hWnd, int nCmd);
static BOOL (WINAPI *sysShowWindow)(HWND hWnd, int nCmd) = NULL;
// 实现钩子方法,把事件的挂载放到界面显示时。
BOOL hookShowWindow(HWND hWnd, int nCmd)
{
    //如果窗体属于本进程，则挂事件
    DWORD nProcessID = 0;
    GetWindowThreadProcessId(hWnd, &nProcessID);
    if (nProcessID == GetCurrentProcessId())
    {
        AutoTestApp::instance().addEventFilter();
    }

    return sysShowWindow(hWnd, nCmd);
}

// QMetaObject::activate 钩子
typedef void (*FuncMetaObjectactivate)(QObject *sender, const QMetaObject *, int local_signal_index, void **argv);
static void (*OriginSignalFunc)(QObject *sender, const QMetaObject *, int local_signal_index, void **argv) = NULL;

#include <QDebug>
#include <QMenu>
#include <QMenuBar>
#include <QtitanRibbon.h>
#include <QDebug>
#include <QToolButton>
void allSignalsHook(QObject *sender, const QMetaObject *obj, int local_signal_index, void **argv)
{

    QToolButton* pRibbon = dynamic_cast<QToolButton*>(sender);
    if (pRibbon)
    {
        qDebug() << CaseUnit::getControlKey(pRibbon)
                 << " # " << pRibbon->metaObject()->className()
                 << " : " << local_signal_index
                 << " : " << pRibbon->text();
    }

    IAdapter * pAdapter = AdapterManager::findAdapter(sender);
    if (pAdapter && pAdapter->isMatchSignal(sender ,obj, local_signal_index, argv))
    {
        pAdapter->signalAddCase(sender, obj, local_signal_index, argv);
        (*OriginSignalFunc)(sender, obj, local_signal_index, argv);
        return;
    }

    (*OriginSignalFunc)(sender, obj, local_signal_index, argv);
}

// 键盘钩子
HHOOK sKeyBoardHook = NULL;
LRESULT CALLBACK keyProc(int nCode,WPARAM wParam,LPARAM lParam)
{
    //在WH_KEYBOARD_LL模式下lParam 是指向KBDLLHOOKSTRUCT类型地址
    KBDLLHOOKSTRUCT *pkbhs = (KBDLLHOOKSTRUCT *) lParam;
    //如果nCode等于HC_ACTION则处理该消息，如果小于0，则钩子子程就必须将该消息传递给 CallNextHookEx
    if (nCode == HC_ACTION)
    {
//        if(pkbhs->vkCode == VK_ESCAPE && GetAsyncKeyState(VK_CONTROL)& 0x8000 && GetAsyncKeyState(VK_SHIFT)&0x8000)
//        {
//            qDebug() << "Ctrl+Shift+Esc";
//        }
//        else if(pkbhs->vkCode == VK_ESCAPE && GetAsyncKeyState(VK_CONTROL) & 0x8000)
//        {
//            qDebug() << "Ctrl+Esc";
//        }
//        else if(pkbhs->vkCode == VK_TAB && pkbhs->flags & LLKHF_ALTDOWN)
//        {
//            qDebug() << "Alt+Tab";
//        }
//        else if(pkbhs->vkCode == VK_ESCAPE && pkbhs->flags &LLKHF_ALTDOWN)
//        {
//            qDebug() << "Alt+Esc";
//        }
//        else if(pkbhs->vkCode == VK_LWIN || pkbhs->vkCode == VK_RWIN)
//        {
//            qDebug() << "LWIN/RWIN";
//        }
//        else if(pkbhs->vkCode == VK_F4 && pkbhs->flags & LLKHF_ALTDOWN)
//        {
//            qDebug() << "Alt+F4";
//        }
        if (pkbhs->vkCode == VK_F1 && pkbhs->flags & LLKHF_ALTDOWN)
        {
            AutoTestApp::instance().doStartNote();
        }
        if (pkbhs->vkCode == VK_F2 && pkbhs->flags & LLKHF_ALTDOWN)
        {
            AutoTestApp::instance().doNoteInfo();
        }
    }
    return CallNextHookEx(sKeyBoardHook, nCode, wParam, lParam);
}


AutoTestApp &AutoTestApp::instance()
{
    static AutoTestApp app;
    return app;
}

AutoTestApp::AutoTestApp()
    : QObject(NULL),
      m_bNote(false),
      m_bTip(false),
      m_bAddEventFilter(false)
{

}

AutoTestApp::~AutoTestApp()
{
    qApp->removeEventFilter(this);
    if (sKeyBoardHook != NULL)
    {
        // 键盘钩子句不为空时销毁掉
        UnhookWindowsHookEx(sKeyBoardHook);
        sKeyBoardHook = NULL;
    }
}

void AutoTestApp::run()
{
    // 键盘钩子
    HINSTANCE hInstance = GetModuleHandle(NULL);
    sKeyBoardHook =SetWindowsHookEx( WH_KEYBOARD_LL, keyProc, hInstance, 0);

    // showWindow钩子
    FuncShowWindow pOrgFunc1 = &ShowWindow;
    FuncShowWindow pHooKFunc1 = &hookShowWindow;
    HookManager::instance().HookFunc(
                (PVOID&)pOrgFunc1,
                (PVOID&)pHooKFunc1,
                &(PVOID&)sysShowWindow);

    // QMetaObject::activate 钩子
    FuncMetaObjectactivate pOrgFunc2 = &(QMetaObject::activate);
    FuncMetaObjectactivate pHooKFunc2 = &allSignalsHook;
    HookManager::instance().HookFunc(
                (PVOID&)pOrgFunc2,
                (PVOID&)pHooKFunc2,
                &(PVOID&)OriginSignalFunc);

}

void AutoTestApp::done()
{
    // 结束处理
}

bool AutoTestApp::isNote()
{
    return m_bNote;
}

void AutoTestApp::addEventFilter()
{
    if (!m_bAddEventFilter)
    {
        qApp->installEventFilter(this);
        m_bAddEventFilter = true;
    }
}

bool AutoTestApp::eventFilter(QObject *obj, QEvent *event)
{
    return ControlManage::instance().appEventFilter(obj, event);
}

bool AutoTestApp::doStartNote()
{
    if (m_bTip == false)
    {
        m_bTip = true;
        QMessageBox::information(nullptr, QStringLiteral("自动化代码生成插件"), QStringLiteral("开始记录"));
        m_bNote = true;
    }
    return true;
}

bool AutoTestApp::doNoteInfo()
{
    if (m_bNote == true)
    {
        m_bNote = false;
        m_bTip = false;
        MainView oView;
        oView.exec();
    }
    return true;
}


