#include "QRibbonBarCase.h"

#include <QtnRibbonPage.h>

QRibbonBarCase::QRibbonBarCase(QObject *object)
    : QtCase(object)
{
    m_pControl = dynamic_cast<Qtitan::RibbonBar *> (object);
    refreshValue();
}

QRibbonBarCase::QRibbonBarCase(QObject *object, QString lastString)
    : QtCase(object),
      m_pControl(nullptr),
      m_sLateText(lastString)
{
    m_pControl = dynamic_cast<Qtitan::RibbonBar *> (object);
    refreshValue();
}

void QRibbonBarCase::refreshValue()
{
    if (NULL != m_pControl)
    {
        Qtitan::RibbonPage* pRibbonPage = m_pControl->getPage(
                    m_pControl->currentIndexPage());

        m_sCurText = pRibbonPage->title();

        m_oTabStrs.clear();
        for (int i = 0; i < m_pControl->getPageCount(); i++)
        {
            pRibbonPage = m_pControl->getPage(i);
            m_oTabStrs.append(pRibbonPage->title());
        }
    }
}

QRibbonBarCase::~QRibbonBarCase()
{
    m_pControl = nullptr;
    m_oTabStrs.clear();
}

ICase *QRibbonBarCase::takeNote(QObject *obj, QEvent *event)
{
    ICase * pCase = nullptr;
    if ((NULL != m_pControl))
    {
        Qtitan::RibbonPage* pRibbonPage = m_pControl->getPage(
                    m_pControl->currentIndexPage());
        if (NULL != pRibbonPage)
        {
            pCase = new QRibbonBarCase(m_pControl, m_sCurText);
            m_sCurText = pRibbonPage->title();
        }
        else
        {
            pCase = QtCase::takeNote(obj, event);
        }
    }
    else
    {
        pCase = QtCase::takeNote(obj, event);
    }
    return pCase;
}

QString QRibbonBarCase::actionKey()
{
    return QString("%1#%2#%3")
            .arg(m_nKeyID)
            .arg(property() + ":" + m_sCurText + "-" + m_sLateText )
            .arg(m_nPropertyIndex);
}

QString QRibbonBarCase::property()
{
    return m_sTitleParentText + "#" + m_oTabStrs.join("|");
}

QString QRibbonBarCase::toString()
{
    QStringList oStrList;
    if (!m_sTitleParentText.isEmpty())
    {
        oStrList.append(
                    QString("{From:%1}").arg(m_sTitleParentText));
    }
    oStrList.append(QString("{Qtitan::RibbonBar:%1}").arg(m_oTabStrs.join("|")));
    oStrList.append(QString("{LateText:%1}").arg(m_sLateText));
    oStrList.append(QString("{CurText:%1}").arg(m_sCurText));
    return oStrList.join("#");
}

QString QRibbonBarCase::toRuby()
{
    QStringList oStrList;
    if (m_sLateText.isEmpty())
    {
        oStrList.append(QString("pagecontrol('%1')").arg(m_sCurText));
    }
    else
    {
        oStrList.append(QString("pagecontrol('%1')").arg(m_sLateText));
    }
    oStrList.append(QString("select('%1', :pw)").arg(m_sCurText));
    return oStrList.join(".");
}

