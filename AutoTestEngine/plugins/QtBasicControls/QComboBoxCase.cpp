#include "QComboBoxCase.h"

QComboBoxCase::QComboBoxCase(QObject *object)
    : QtCase(object),
      m_pControl(nullptr)
{
    m_pControl = dynamic_cast<QComboBox*> (object);

    if (NULL != m_pControl)
    {
        m_sCurText = m_pControl->currentText();
    }
    m_sLeftText = getControlLeftText(m_pControl);
}

QComboBoxCase::~QComboBoxCase()
{
    m_pControl = nullptr;
}

ICase *QComboBoxCase::takeNote(QObject *sender, const QMetaObject *obj, int local_signal_index, void **argv)
{
    if ((NULL != sender) && comboBoxNoteCondition())
    {
        return new QComboBoxCase(sender);
    }
    return QtCase::takeNote(sender, obj, local_signal_index, argv);
}

ICase *QComboBoxCase::takeNote(QObject *obj, QEvent *event)
{
    if ((NULL != obj) && comboBoxNoteCondition())
    {
        return new QComboBoxCase(obj);
    }
    return QtCase::takeNote(obj, event);
}


QString QComboBoxCase::property()
{
    return m_sTitleParentText + "#" + m_sLeftText;
}

QString QComboBoxCase::toString()
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
                    QString("{ComboBox:%1 #%2}")
                    .arg(m_sLeftText)
                    .arg(m_nPropertyIndex));
    }
    oStrList.append(QString("{CurText:%1}").arg(m_sCurText));
    return oStrList.join("#");
}

QString QComboBoxCase::toRuby()
{
    QStringList oStrList;
    if (!m_sTitleParentText.isEmpty())
    {
        oStrList.append(QString("from(\"%1\")").arg(m_sTitleParentText));
    }
    if (!m_sLeftText.isEmpty())
    {
        oStrList.append(
                    QString("comboBox(\"%1 #%2>\")")
                    .arg(m_sLeftText)
                    .arg(m_nPropertyIndex));
    }
    oStrList.append(QString("settext(\"%1\")").arg(m_sCurText));
    return oStrList.join(".");
}
