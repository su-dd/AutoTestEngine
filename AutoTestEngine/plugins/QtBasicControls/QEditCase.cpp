#include "QEditCase.h"



/*********************************************
 *
 * QLineEdit ÊÂÀý
 *
 *********************************************/
QLineEditCase::QLineEditCase(QObject *object)
    : QtCase(object),
      m_pControl(nullptr)
{
    m_pControl = dynamic_cast<QLineEdit*> (object);

    if (NULL != m_pControl)
    {
        m_sCurText = m_pControl->text();
    }
    m_sLeftText = getControlLeftText(m_pControl);
    m_sObjectName = m_pControl->objectName();
}

QLineEditCase::~QLineEditCase()
{
    m_pControl = nullptr;
}

ICase *QLineEditCase::takeNote(QObject *sender, const QMetaObject *obj, int local_signal_index, void **argv)
{
    if (NULL != sender)
    {
        return new QLineEditCase(sender);
    }
    return QtCase::takeNote(sender, obj, local_signal_index, argv);
}

QString QLineEditCase::property()
{
    return m_sTitleParentText + "#" + m_sLeftText;
}

QString QLineEditCase::toString()
{
    QStringList oStrList;
    if (!m_sTitleParentText.isEmpty())
    {
        oStrList.append(
                    QString("{From:%1}").arg(m_sTitleParentText));
    }

    if (!m_sLeftText.isEmpty())
    {
        oStrList.append(
                    QString("{QLineEdit:%1 #%2}")
                    .arg(m_sLeftText)
                    .arg(m_nPropertyIndex));
    }
    else
    {
        oStrList.append(
                    QString("{QLineEdit:%1 #%2}")
                    .arg(m_sObjectName)
                    .arg(m_nPropertyIndex));
    }
    oStrList.append(QString("{CurText:%1}").arg(m_sCurText));
    return oStrList.join("#");
}

QString QLineEditCase::toRuby()
{
    QStringList oStrList;
    if (!m_sTitleParentText.isEmpty())
    {
        oStrList.append(QString("from('%1')").arg(m_sTitleParentText));
    }

    if (!m_sLeftText.isEmpty())
    {
        oStrList.append(
                    QString("edit('%1 #%2>')")
                    .arg(m_sLeftText)
                    .arg(m_nPropertyIndex));
    }
    else
    {
        oStrList.append(
                    QString("edit('%1 #%2')")
                    .arg(m_sObjectName)
                    .arg(m_nPropertyIndex));
    }
    oStrList.append(QString("settext('%1')").arg(m_sCurText));
    return oStrList.join(".");
}


/*********************************************
 *
 * QTextEdit ÊÂÀý
 *
 *********************************************/
QTextEditCase::QTextEditCase(QObject *object)
    : QtCase(object),
      m_pControl(nullptr)
{
    m_pControl = dynamic_cast<QTextEdit*> (object);

    if (NULL != m_pControl)
    {
        m_sCurText = m_pControl->document()->toPlainText();
    }
    m_sLeftText = getControlLeftText(m_pControl);
    m_sObjectName = m_pControl->objectName();
}

QTextEditCase::~QTextEditCase()
{
    m_pControl = nullptr;
}

ICase *QTextEditCase::takeNote(QObject *sender, const QMetaObject *obj, int local_signal_index, void **argv)
{
    if (NULL != sender)
    {
        return new QTextEditCase(sender);
    }
    return QtCase::takeNote(sender, obj, local_signal_index, argv);
}

QString QTextEditCase::property()
{
    return m_sTitleParentText + "#" + m_sLeftText;
}

QString QTextEditCase::toString()
{
    QStringList oStrList;
    if (!m_sTitleParentText.isEmpty())
    {
        oStrList.append(
                    QString("{From:%1}").arg(m_sTitleParentText));
    }

    if (!m_sLeftText.isEmpty())
    {
        oStrList.append(
                    QString("{QTextEdit:%1 #%2}")
                    .arg(m_sLeftText)
                    .arg(m_nPropertyIndex));
    }
    else
    {
        oStrList.append(
                    QString("{QTextEdit:%1 #%2}")
                    .arg(m_sObjectName)
                    .arg(m_nPropertyIndex));
    }
    oStrList.append(QString("{CurText:%1}").arg(m_sCurText));
    return oStrList.join("#");
}

QString QTextEditCase::toRuby()
{
    QStringList oStrList;
    if (!m_sTitleParentText.isEmpty())
    {
        oStrList.append(QString("from(\"%1\")").arg(m_sTitleParentText));
    }

    if (!m_sLeftText.isEmpty())
    {
        oStrList.append(
                    QString("edit(\"%1 #%2>\")")
                    .arg(m_sLeftText)
                    .arg(m_nPropertyIndex));
    }
    else
    {
        oStrList.append(
                    QString("edit(\"%1 #%2\")")
                    .arg(m_sObjectName)
                    .arg(m_nPropertyIndex));
    }
    oStrList.append(QString("settext(\"%1\")").arg(m_sCurText));
    return oStrList.join(".");
}
