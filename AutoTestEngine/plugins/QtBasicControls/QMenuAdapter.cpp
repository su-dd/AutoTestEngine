#include "QMenuAdapter.h"

#include <QMenu>
#include "AutoTestSignalsIndexConst.h"
#include "CaseManager.h"
#include "QMenuCase.h"

QMenuAdapter::QMenuAdapter()
    : QtAdapter()
{
    m_oSignalsList.append(SignalsStruct(&QMenu::staticMetaObject, n_QMenu_Action_clicked));
}

int QMenuAdapter::supportLevel(QObject *pObject)
{
    return AdapterManager::calcInheritedLevel(pObject->metaObject(), QMenu::staticMetaObject);
}

bool QMenuAdapter::isAddControlCondition(QObject *obj, QEvent *event)
{
    Q_UNUSED(obj);
    return (event->type() == QEvent::Show);
}

bool QMenuAdapter::isRemoveControlCondition(QObject *obj, QEvent *event)
{
    Q_UNUSED(obj);
    return (event->type() == QEvent::Leave);
}

bool QMenuAdapter::isMatchControl(QObject *objControl)
{
    return (nullptr != dynamic_cast<QMenu*> (objControl));
}

ICase *QMenuAdapter::getCase(QObject *object)
{
    return new QMenuCase(object);
}
