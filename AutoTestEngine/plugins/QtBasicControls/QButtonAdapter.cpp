#include "QButtonAdapter.h"

#include <QKeyEvent>
#include <QEvent>
#include <QAbstractButton>
#include "AutoTestSignalsIndexConst.h"
#include "QButtonCase.h"
#include "CaseManager.h"

QAbstractButtonAdapter::QAbstractButtonAdapter()
    : QtAdapter()
{
    m_oSignalsList.append(SignalsStruct(&QAbstractButton::staticMetaObject, n_QAbstractButton_clicked));
}

int QAbstractButtonAdapter::supportLevel(QObject *pObject)
{
    return AdapterManager::calcInheritedLevel(pObject->metaObject(), QAbstractButton::staticMetaObject);
}

bool QAbstractButtonAdapter::isMatchControl(QObject *objControl)
{
    return (nullptr != dynamic_cast<QAbstractButton*> (objControl));
}

ICase *QAbstractButtonAdapter::getCase(QObject *object)
{
    return new QAbstractButtonCase(object);
}
