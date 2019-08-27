#include "QRibbonButtonCase.h"

QRibbonButtonCase::QRibbonButtonCase(QObject *object)
    : QtCase(object)
{
    m_pControl = dynamic_cast<QToolButton *> (object);
    if (nullptr == m_pControl)
    {
        m_sText = m_pControl->text();
    }
}

QRibbonButtonCase::~QRibbonButtonCase()
{
    m_pControl = nullptr;
}

ICase *QRibbonButtonCase::takeNote(QObject *obj, QEvent *event)
{
    return nullptr;
}

QString QRibbonButtonCase::actionKey()
{
    return "";
}

QString QRibbonButtonCase::property()
{
    return "";
}

QString QRibbonButtonCase::toString()
{
    return "";
}

QString QRibbonButtonCase::toRuby()
{
    return "";
}

