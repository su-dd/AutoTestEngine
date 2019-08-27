#include "ControlManage.h"
#include "AdapterManager.h"
#include <QEvent>

ControlManage &ControlManage::instance()
{
    static ControlManage oControlManage;
    return oControlManage;
}

#include <QtitanRibbon.h>
#include <QDebug>
#include <QToolButton>
bool ControlManage::appEventFilter(QObject *obj, QEvent *event)
{
//    if ((nullptr != obj) && (nullptr != event))
//    {
//        QToolButton* pRibbon = dynamic_cast<QToolButton*>(obj);
//        if (pRibbon)
//        {
//            qDebug() << CaseUnit::getControlKey(pRibbon)
//                     << " # " << pRibbon->metaObject()->className()
//                     << " : " << event->type()
//                     << " : " << pRibbon->text();
//        }
//    }


    IAdapter * pAdapter = AdapterManager::findAdapter(obj);
    if (pAdapter && pAdapter->isMatchControl(obj))
    {
        if (pAdapter->isAddControlCondition(obj, event))
        {
            pAdapter->addControl(obj);
        }
        else if (pAdapter->isRemoveControlCondition(obj, event))
        {
            pAdapter->removeControl(obj);
        }
        else
        {
            pAdapter->appEventFilter(obj, event);
        }
    }

    return QObject::eventFilter(obj, event);
}

ControlManage::ControlManage()
{
}

