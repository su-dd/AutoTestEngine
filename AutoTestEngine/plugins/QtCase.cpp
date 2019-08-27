#include "QtCase.h"
#include <QDebug>
#include <QLabel>
#include <QAbstractButton>
#include <QMenu>
QtCase::QtCase(QObject *object)
    : m_nKeyID(0),
      m_nPropertyIndex(1),
      m_pCurObject(object),
      m_pTitleParentWidget(nullptr)
{
    initialiseCaseState();
    m_nKeyID = CaseUnit::getControlKey(object);
    initParentInfo();
}

QtCase::~QtCase()
{
    m_pCurObject = nullptr;
    m_pTitleParentWidget = nullptr;
}

long QtCase::key()
{
    return m_nKeyID;
}

QString QtCase::actionKey()
{
    return QString("%1#%2#%3").arg(m_nKeyID).arg(property()).arg(m_nPropertyIndex);
}

void QtCase::setPropertyIndex(int index)
{
    m_nPropertyIndex = index;
}

ICase *QtCase::takeNote(QObject *sender, const QMetaObject *obj, int local_signal_index, void **argv)
{
    Q_UNUSED(sender);
    Q_UNUSED(obj);
    Q_UNUSED(local_signal_index);
    Q_UNUSED(argv);
    return nullptr;
}

ICase *QtCase::takeNote(QObject *obj, QEvent *event)
{
    Q_UNUSED(obj);
    Q_UNUSED(event);
    return nullptr;
}

QString QtCase::getControlLeftText(QObject *control)
{
    QWidget *pWidget = this->getParentWidget(control);
    if (nullptr != pWidget)
    {
        return this->getLeftSiblingControlName(pWidget->layout(), control);
    }
    return "";
}

QWidget *QtCase::getParentWidget(QObject *object)
{
    if (NULL != object->parent())
    {
        QWidget *pWidget = dynamic_cast<QWidget*> (object->parent());
        if ((NULL != pWidget))
        {
            m_sTitleParentObjectName = pWidget->objectName();
            return pWidget;
        }
        else
        {
            return getTitleParentWidget(object->parent());
        }
    }
    return nullptr;
}

QString QtCase::getLeftSiblingControlName(QLayout *layout, QObject *object)
{
    if (nullptr == layout)
    {
        return "";
    }
    int nIndex = -1;
    for (int i = 0; i < layout->count(); i++)
    {
        QLayoutItem *item = layout->itemAt(i);
        if (item->widget() == object)
        {
            nIndex = i;
            break;
        }
        else if (!getLeftSiblingControlName(item->layout(), object).isEmpty())
        {
            return getLeftSiblingControlName(item->layout(), object);
        }
    }

    if (nIndex == -1 || nIndex == 0)
    {
        return "";
    }

    QLayoutItem *item = layout->itemAt(nIndex - 1);
    if (dynamic_cast<QLabel*>(item->widget()) != NULL)
    {
        return reinterpret_cast<QLabel*>(item->widget())->text();
    }
    else if (dynamic_cast<QAbstractButton*>(item->widget()))
    {
         return reinterpret_cast<QAbstractButton*>(item->widget())->text();
    }
    return "";
}

/**************************************************
 * 如果找到title则用title，如果找不到title用ObjectName
 *
 * 获得第一个带标题的窗体为止，否则获得最外层窗体的ObjectName
 *
***************************************************/
void QtCase::initParentInfo()
{
    m_pTitleParentWidget = getTitleParentWidget(m_pCurObject);
    if (nullptr != m_pTitleParentWidget)
    {
        m_sTitleParentText = m_pTitleParentWidget->windowTitle();
    }
    else
    {
        m_sTitleParentText = m_sTitleParentObjectName;
    }
}

/**************************************************
 * 找带标题的 父widget
 *
 * 同时记录找到的父窗体的objectName，供找不到title时使用
 *
***************************************************/
QWidget *QtCase::getTitleParentWidget(QObject *object)
{
    if (NULL != object->parent())
    {
        QWidget *pWidget = dynamic_cast<QWidget*> (object->parent());
        if ((NULL != pWidget))
        {
            m_sTitleParentObjectName = pWidget->objectName();
            if (!pWidget->windowTitle().isEmpty())
            {
                return pWidget;
            }
            return getTitleParentWidget(object->parent());
        }
        else
        {
            return getTitleParentWidget(object->parent());
        }
    }
    return nullptr;
}
