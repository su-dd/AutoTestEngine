#include "QRibbonBarAdapter.h"

#include "QRibbonBarCase.h"
#include "AutoTestSignalsIndexConst.h"

QRibbonBarAdapter::QRibbonBarAdapter()
    : QtAdapter()
{
    m_oSignalsList.append(
                SignalsStruct(&Qtitan::RibbonBar::staticMetaObject, n_QRibbonBar_currentChanged));
}

int QRibbonBarAdapter::supportLevel(QObject *pObject)
{
    return AdapterManager::calcInheritedLevel(
                pObject->metaObject(), Qtitan::RibbonBar::staticMetaObject);
}

bool QRibbonBarAdapter::isAddControlCondition(QObject *obj, QEvent *event)
{
    if ((nullptr != event) && (nullptr != getCurRibbonPage(obj)))
    {
        return (event->type() == QEvent::LayoutRequest);
    }
    return false;
}

bool QRibbonBarAdapter::isRemoveControlCondition(QObject *obj, QEvent *event)
{
    if ((nullptr != event) && (nullptr != getCurRibbonPage(obj)))
    {
        return (event->type() == QEvent::HoverMove);
    }
    return false;
}

void QRibbonBarAdapter::appEventFilter(QObject *obj, QEvent *event)
{
    if ((nullptr != event) && (nullptr != getCurRibbonPage(obj)))
    {
        if (event->type() == QEvent::MouseButtonRelease)
        {
            eventAddCase(obj, event, true);
        }
    }
}

bool QRibbonBarAdapter::isMatchControl(QObject *objControl)
{
    return (nullptr != dynamic_cast<Qtitan::RibbonBar*> (objControl));
}

ICase *QRibbonBarAdapter::getCase(QObject *object)
{
    return new QRibbonBarCase(object);
}

RibbonPage *QRibbonBarAdapter::getCurRibbonPage(QObject *obj)
{
    if (nullptr != obj)
    {
        Qtitan::RibbonBar* pRibbonBar = dynamic_cast<Qtitan::RibbonBar*>(obj);
        if ((nullptr != pRibbonBar))
        {
            if (pRibbonBar->getPageCount() > 0)
            {
                int nPage = pRibbonBar->currentIndexPage();
                if (nPage >= 0)
                {
                    return pRibbonBar->getPage(nPage);
                }
            }
        }
    }
    return nullptr;
}
