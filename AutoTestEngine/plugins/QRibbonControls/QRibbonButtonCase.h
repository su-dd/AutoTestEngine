#ifndef QRIBBONBUTTONCASE_H
#define QRIBBONBUTTONCASE_H

#include <QtitanRibbon.h>
#include <QString>
#include "QtCase.h"
#include <QToolButton>

class QRibbonButtonCase : public QtCase
{
public:
    QRibbonButtonCase(QObject *object);
    virtual ~QRibbonButtonCase();
    virtual ICase* takeNote(QObject *obj, QEvent *event) override;
    virtual QString actionKey() override;
    virtual QString property() override;
    virtual QString toString() override;
    virtual QString toRuby() override;

private:
    QToolButton * m_pControl;
    QString m_sText;
};

#endif // QRIBBONBUTTONCASE_H
