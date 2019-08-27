#include "QtAdapter.h"
#include "AutoTestApp.h"
#include "CaseManager.h"

/***************************************************************
 *
 * ÊÊÅäÆ÷»ùÀà
 *
 *
****************************************************************/
QtAdapter::QtAdapter()
{

}

QtAdapter::~QtAdapter()
{
}

bool QtAdapter::isAddControlCondition(QObject *obj, QEvent *event)
{
    Q_UNUSED(obj);
    return (event->type() == QEvent::Show) || (event->type() == QEvent::WindowActivate);
}

bool QtAdapter::isRemoveControlCondition(QObject *obj, QEvent *event)
{
    Q_UNUSED(obj);
    return (event->type() == QEvent::Hide) || (event->type() == QEvent::WindowDeactivate);
}

bool QtAdapter::isMatchControl(QObject *objControl)
{
    Q_UNUSED(objControl);
    return false;
}

void QtAdapter::addControl(QObject *objControl)
{
    if (!m_oCaseObjectManager.contains(objControl))
    {
        ICase *pCase = getCase(objControl);
        m_oCaseObjectManager.add(pCase);
        ControlCaseObjectManager::instance().add(pCase);
        objControl->installEventFilter(this);
    }
}

void QtAdapter::removeControl(QObject *objControl)
{
    ICase *pCase = m_oCaseObjectManager.findCase(objControl);
    if (nullptr != pCase)
    {
        m_oCaseObjectManager.remove(pCase);
        ControlCaseObjectManager::instance().remove(pCase);
        objControl->removeEventFilter(this);
    }
}

bool QtAdapter::eventFilter(QObject *obj, QEvent *event)
{
    return QObject::eventFilter(obj, event);
}

void QtAdapter::appEventFilter(QObject *obj, QEvent *event)
{
    Q_UNUSED(obj);
    Q_UNUSED(event);
}

bool QtAdapter::isMatchSignal(QObject *object, const QMetaObject *obj, int local_signal_index, void **argv)
{
    Q_UNUSED(object);
    Q_UNUSED(argv);
    foreach (SignalsStruct str, m_oSignalsList)
    {
        if (QString::compare(str.metaObjStr, QString::fromLocal8Bit(obj->className())) == 0
                && str.signals_index == local_signal_index)
        {
            return true;
        }
    }
    return false;
}

void QtAdapter::signalAddCase(QObject *sender, const QMetaObject *obj, int local_signal_index, void **argv)
{
    if (AutoTestApp::instance().isNote())
    {
        ICase* pCase = m_oCaseObjectManager.findCase(sender);
        if (nullptr != pCase)
        {
            pCase->signalChange();
            ICase* pActionCase = pCase->signalTakeNote(sender, obj, local_signal_index, argv);
            UserOperationCaseManager::instance().add(pActionCase);
        }
    }
}

void QtAdapter::eventAddCase(QObject *obj, QEvent *event, bool add)
{
    if (AutoTestApp::instance().isNote())
    {
        ICase* pCase = m_oCaseObjectManager.findCase(obj);
        if (nullptr != pCase)
        {
            pCase->controlActive();
            if (add)
            {
                ICase* pActionCase = pCase->eventTakeNote(obj, event);
                UserOperationCaseManager::instance().add(pActionCase);
            }
        }
    }
}

ICase *QtAdapter::getCase(QObject *object)
{
    Q_UNUSED(object);
    return nullptr;
}
