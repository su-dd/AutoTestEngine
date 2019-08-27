#include "QTabBarAdapter.h"

#include <QTabBar>
#include "AutoTestSignalsIndexConst.h"
#include "QTabBarCase.h"
#include "CaseManager.h"

QTabBarAdapter::QTabBarAdapter()
    : QtAdapter()
{
    m_oSignalsList.append(SignalsStruct(&QTabBar::staticMetaObject, n_QTabBar_currentChanged));
}

int QTabBarAdapter::supportLevel(QObject *pObject)
{
    return AdapterManager::calcInheritedLevel(pObject->metaObject(), QTabBar::staticMetaObject);
}

bool QTabBarAdapter::isMatchControl(QObject *objControl)
{
    return (nullptr != dynamic_cast<QTabBar*> (objControl));
}

ICase *QTabBarAdapter::getCase(QObject *object)
{
    return new QTabBarCase(object);
}

