#include "QRibbonButtonAdapter.h"

#include "QRibbonButtonCase.h"
#include "AutoTestSignalsIndexConst.h"

QRibbonButtonAdapter::QRibbonButtonAdapter()
{
    m_oSignalsList.append(
                SignalsStruct(QString("Qtitan::RibbonButton"), n_QRibbonButton_clicked));
}

int QRibbonButtonAdapter::supportLevel(QObject *pObject)
{
    return AdapterManager::calcInheritedLevel(
                pObject->metaObject(), QString("Qtitan::RibbonButton"));
}

bool QRibbonButtonAdapter::isMatchControl(QObject *objControl)
{
    Q_UNUSED(objControl)
    return true;
}

ICase *QRibbonButtonAdapter::getCase(QObject *object)
{
    return new QRibbonButtonCase(object);
}

