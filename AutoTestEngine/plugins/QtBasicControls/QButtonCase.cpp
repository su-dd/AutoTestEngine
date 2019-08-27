#include "QButtonCase.h"
#include <QWidget>

QAbstractButtonCase::QAbstractButtonCase(QObject *object)
    : QtCase(object),
      m_pControl(nullptr)
{
    m_pControl = dynamic_cast<QAbstractButton*> (object);

    if (NULL != m_pControl)
    {
        m_sText = m_pControl->text();
        if (m_sText.isEmpty())
        {
            m_sText = m_pControl->objectName();
        }
    }
}

QAbstractButtonCase::~QAbstractButtonCase()
{
    m_pControl = nullptr;
}

ICase *QAbstractButtonCase::takeNote(QObject *sender, const QMetaObject *obj, int local_signal_index, void **argv)
{
    if (NULL != sender)
    {
        return new QAbstractButtonCase(sender);
    }
    return QtCase::takeNote(sender, obj, local_signal_index, argv);
}

QString QAbstractButtonCase::property()
{
    return m_sTitleParentText + "#" + m_sText;
}

QString QAbstractButtonCase::toString()
{
    QStringList oStrList;
    if (!m_sTitleParentText.isEmpty())
    {
        oStrList.append(
                    QString("{From:%1}").arg(m_sTitleParentText));
    }
    if (!m_sText.isEmpty())
    {
        oStrList.append(
                    QString("{Button:%1 #%2}")
                    .arg(m_sText)
                    .arg(m_nPropertyIndex));
    }
    return oStrList.join("#");
}

QString QAbstractButtonCase::toRuby()
{
    QStringList oStrList;
    if (!m_sTitleParentText.isEmpty())
    {
        oStrList.append(
                    QString("from(\"%1\")").arg(m_sTitleParentText));
    }
    if (!m_sText.isEmpty())
    {
        oStrList.append(
                    QString("button(\"%1 #%2\")")
                    .arg(m_sText)
                    .arg(m_nPropertyIndex));
    }
    oStrList.append(QString("click(:pw)"));
    return oStrList.join(".");
}

