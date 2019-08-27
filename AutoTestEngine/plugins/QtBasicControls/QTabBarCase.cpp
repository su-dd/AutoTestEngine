#include "QTabBarCase.h"

QTabBarCase::QTabBarCase(QObject *object)
    : QtCase(object),
      m_pControl(nullptr)
{
    m_pControl = dynamic_cast<QTabBar*> (object);
    refreshValue();
}

QTabBarCase::QTabBarCase(QObject *object, QString lastString)
    : QtCase(object),
      m_pControl(nullptr),
      m_sLateText(lastString)
{
    m_pControl = dynamic_cast<QTabBar*> (object);
    refreshValue();
}

void QTabBarCase::refreshValue()
{
    if (NULL != m_pControl)
    {
        m_sCurText = m_pControl->tabText(m_pControl->currentIndex());

        m_oTabStrs.clear();

        for (int i = 0; i < m_pControl->count(); i++)
        {
            m_oTabStrs.append(m_pControl->tabText(i));
        }
    }
}

QTabBarCase::~QTabBarCase()
{
    m_pControl = nullptr;
    m_oTabStrs.clear();
}

ICase *QTabBarCase::takeNote(QObject *sender, const QMetaObject *obj, int local_signal_index, void **argv)
{
    ICase * pCase = nullptr;
    if (NULL != sender)
    {
        pCase = new QTabBarCase(sender, m_sCurText);
    }
    else
    {
        pCase = QtCase::takeNote(sender, obj, local_signal_index, argv);
    }
    m_sCurText = m_pControl->tabText(m_pControl->currentIndex());
    return pCase;
}

QString QTabBarCase::actionKey()
{
    return QString("%1#%2#%3")
            .arg(m_nKeyID)
            .arg(property() + ":" + m_sCurText + "-" + m_sLateText )
            .arg(m_nPropertyIndex);
}

QString QTabBarCase::property()
{
    return m_sTitleParentText + "#" + m_oTabStrs.join("|");
}

QString QTabBarCase::toString()
{
    QStringList oStrList;
    if (!m_sTitleParentText.isEmpty())
    {
        oStrList.append(
                    QString("{From:%1}").arg(m_sTitleParentText));
    }
    oStrList.append(QString("{QTabBar:%1}").arg(m_oTabStrs.join("|")));
    oStrList.append(QString("{LateText:%1}").arg(m_sLateText));
    oStrList.append(QString("{CurText:%1}").arg(m_sCurText));
    return oStrList.join("#");
}

QString QTabBarCase::toRuby()
{
    QStringList oStrList;
    oStrList.append(QString("pagecontrol('%1')").arg(m_sLateText));
    oStrList.append(QString("select('%1', :pw)").arg(m_sCurText));
    return oStrList.join(".");
}
