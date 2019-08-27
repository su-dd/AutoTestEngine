#ifndef QRIBBONBARCASE_H
#define QRIBBONBARCASE_H

#include <QtitanRibbon.h>
#include <QString>
#include "QtCase.h"

class QRibbonBarCase : public QtCase
{
    Q_OBJECT
public:
    QRibbonBarCase(QObject *object);
    virtual ~QRibbonBarCase();
    virtual ICase* takeNote(QObject *obj, QEvent *event) override;
    virtual QString actionKey() override;
    virtual QString property() override;
    virtual QString toString() override;
    virtual QString toRuby() override;

private:
    QRibbonBarCase(QObject *object, QString lastString);
    void refreshValue();

private:
    Qtitan::RibbonBar *m_pControl;
    QStringList m_oTabStrs;
    QString m_sCurText;
    QString m_sLateText;
};


#endif // QRIBBONBARCASE_H
