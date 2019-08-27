#include "AdapterManager.h"

#include "AutoTestCommonUtil.h"
// ¼ÓÔØÀ©Õ¹
#include "Plugins.h"

int AdapterManager::calcInheritedLevel(const QMetaObject *AObject, const QMetaObject ABaseObject)
{
    const QMetaObject *pMetaObject = AObject;
    int nLevel = -1;
    while (pMetaObject != NULL)
    {
        nLevel = nLevel + 1;

        if (QString::compare(pMetaObject->className(), ABaseObject.className(), Qt::CaseSensitive) == 0)
        {
            return nLevel;
        }
        else
        {
            pMetaObject = pMetaObject->superClass();
        }
    }
    return INT_MAX;
}

int AdapterManager::calcInheritedLevel(const QMetaObject *AObject, const QString &ABaseObjectName)
{
    const QMetaObject *pMetaObject = AObject;
    int nLevel = -1;
    while (pMetaObject != NULL)
    {
        nLevel = nLevel + 1;

        if (pMetaObject->className() == ABaseObjectName)
        {
            return nLevel;
        }
        else
        {
            pMetaObject = pMetaObject->superClass();
        }
    }
    return INT_MAX;
}

IAdapter *AdapterManager::createAdapter(QObject *AControl, const QString &strAdapterName)
{
    Q_UNUSED(AControl);
    IAdapter *padapter = NULL;
    int nSize = adapterListInstance().size();

    for (int i=0; i<nSize; i++)
    {
        const char* cClassname = adapterListInstance().at(i)->className();
        QString strClassName = cClassname;

        if (strClassName.toLower() == strAdapterName.toLower())
        {
            padapter = dynamic_cast<IAdapter*>(
                adapterListInstance().at(i)->newInstance());
            return padapter;
        }
    }

    return padapter;
}

IAdapter *AdapterManager::createAdapter(QObject *AControl, const QMetaObject &AStaticMetaObject)
{
    Q_UNUSED(AControl);
    IAdapter *padapter = dynamic_cast<IAdapter*>(AStaticMetaObject.newInstance());
    return padapter;
}

IAdapter *AdapterManager::createAdapter(QObject *AControl)
{
    IAdapter* padapter = NULL;
    int nLowLevel = INT_MAX;
    int nIndex = -1;
    int nReLevel ;
    int nSize = adapterListInstance().size();

    for (int i = 0; i < nSize; i++)
    {
        pSupportLevel pSupport = adapterMethodListInstance().at(i);
        nReLevel = pSupport(AControl);
        if (nReLevel < nLowLevel)
        {
            nIndex = i;
            nLowLevel = nReLevel;
            if (nLowLevel == 0)
            {
                break;
            }
        }
    }

    if (nIndex != -1)
    {
        QObject* qb = adapterListInstance().at(nIndex)->newInstance();
        padapter = dynamic_cast<IAdapter*>(qb);
        return padapter;
    }

    return NULL;
}

IAdapter *AdapterManager::findAdapter(QObject *AControl, const QString &strAdapterName)
{
    Q_UNUSED(AControl);
    IAdapter *padapter = NULL;
    int nSize = adapterListInstance().size();

    for (int i=0; i<nSize; i++)
    {
        const char* cClassname = adapterListInstance().at(i)->className();
        QString strClassName = cClassname;

        if (strClassName.toLower() == strAdapterName.toLower())
        {
            padapter = dynamic_cast<IAdapter*>(adapterObjectListInstance().at(i));
            return padapter;
        }
    }

    return padapter;
}

IAdapter *AdapterManager::findAdapter(QObject *AControl)
{
    IAdapter* padapter = NULL;
    int nLowLevel = INT_MAX;
    int nIndex = -1;
    int nReLevel ;
    int nSize = adapterListInstance().size();

    for (int i = 0; i < nSize; i++)
    {
        pSupportLevel pSupport = adapterMethodListInstance().at(i);
        nReLevel = pSupport(AControl);
        if (nReLevel < nLowLevel)
        {
            nIndex = i;
            nLowLevel = nReLevel;
            if (nLowLevel == 0)
            {
                break;
            }
        }
    }

    if (nIndex != -1)
    {
        QObject* qb = adapterObjectListInstance().at(nIndex);
        padapter = dynamic_cast<IAdapter*>(qb);
        return padapter;
    }

    return NULL;
}

QList<IAdapter *> &AdapterManager::adapterObjectListInstance()
{
    static QList<IAdapter*> adapterObjectList;
    return adapterObjectList;
}

QList<const QMetaObject *> &AdapterManager::adapterListInstance()
{
    static QList<const QMetaObject*> adapterList;
    return adapterList;
}

QList<pSupportLevel> &AdapterManager::adapterMethodListInstance()
{
    static QList<pSupportLevel> adapterMethodList;
    return adapterMethodList;
}


