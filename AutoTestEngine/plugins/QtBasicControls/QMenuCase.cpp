#include "QMenuCase.h"

QMenuCase::QMenuCase(QObject *object)
    : QtCase(object)
{
    m_pControl = dynamic_cast<QMenu*> (object);

    if (nullptr != m_pControl)
    {
        m_oActiveAction = m_pControl->activeAction();
        if (nullptr != m_oActiveAction)
        {
            m_sActionPath = getMenuPath(m_pControl) + m_oActiveAction->text();
        }
    }
}

QMenuCase::~QMenuCase()
{
    m_oActiveAction = nullptr;
    m_pControl = nullptr;
}

ICase *QMenuCase::takeNote(QObject *sender, const QMetaObject *obj, int local_signal_index, void **argv)
{
    if (NULL != sender)
    {
        return new QMenuCase(sender);
    }
    return QtCase::takeNote(sender, obj, local_signal_index, argv);
}

QString QMenuCase::property()
{
    return m_sTitleParentText + "#" + m_sActionPath;
}

QString QMenuCase::toString()
{
    QStringList oStrList;
    if (!m_sTitleParentText.isEmpty())
    {
        oStrList.append(
                    QString("{From:%1}").arg(m_sTitleParentText));
    }
    if (!m_sActionPath.isEmpty())
    {
        oStrList.append(
                    QString("{Button:%1 #%2}")
                    .arg(m_sActionPath)
                    .arg(m_nPropertyIndex));
    }
    return oStrList.join("#");
}

QString QMenuCase::toRuby()
{
    QStringList oStrList;
//    if (!m_sTitleParentText.isEmpty())
//    {
//        oStrList.append(
//                    QString("from('%1')").arg(m_sTitleParentText));
//    }
    if (!m_sActionPath.isEmpty())
    {
        oStrList.append(
                    QString("button(\"%1 #%2\")")
                    .arg(m_sActionPath)
                    .arg(m_nPropertyIndex));
    }
    oStrList.append(QString("click(:pw)"));
    return oStrList.join(".");
}

QString QMenuCase::getMenuPath(QMenu *control)
{
    QObject *pObject = control->parent();
    if (nullptr != pObject)
    {
        QMenu *pControl = dynamic_cast<QMenu *>(pObject);
        if (nullptr != pControl)
        {
            return getMenuPath(pControl) + control->title()+"/";
        }
    }

    return control->title()+"/";
}

