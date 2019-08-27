#include "QComboBoxAdpter.h"

#include <QKeyEvent>
#include <QEvent>
#include <QComboBox>
#include "AutoTestSignalsIndexConst.h"
#include "CaseManager.h"
#include "QComboBoxCase.h"
#include "qdebug.h"

QComboBoxAdpter::QComboBoxAdpter()
    : QtAdapter()
{
    m_oSignalsList.append(SignalsStruct(&QComboBox::staticMetaObject, n_QComboBox_currentIndexChanged));
}

int QComboBoxAdpter::supportLevel(QObject *pObject)
{
    return AdapterManager::calcInheritedLevel(pObject->metaObject(), QComboBox::staticMetaObject);
}

bool QComboBoxAdpter::isMatchControl(QObject *objControl)
{
    return (nullptr != dynamic_cast<QComboBox*> (objControl));
}

ICase *QComboBoxAdpter::getCase(QObject *object)
{
    return new QComboBoxCase(object);
}

bool QComboBoxAdpter::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonRelease ||
            (event->type() == QEvent::KeyRelease))
    {
        ICase *pCase = m_oCaseObjectManager.findCase(obj);
        if (nullptr != pCase)
        {
            switch (event->type())
            {
            case QEvent::MouseButtonRelease:
                this->eventAddCase(obj, event, false);
                break;
            case QEvent::KeyRelease:
                this->eventAddCase(obj, event, true);
                break;
            default:
                break;
            }
        }
    }
    return QtAdapter::eventFilter(obj, event);
}

