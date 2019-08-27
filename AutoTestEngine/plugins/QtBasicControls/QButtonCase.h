#ifndef QBUTTONCASE_H
#define QBUTTONCASE_H

#include <QAbstractButton>
#include <QString>
#include "QtCase.h"

class QAbstractButtonCase : public QtCase
{
    Q_OBJECT
public:
    QAbstractButtonCase(QObject *object);
    virtual ~QAbstractButtonCase();
    virtual ICase* takeNote(QObject *sender, const QMetaObject *obj, int local_signal_index, void **argv) override;
    virtual QString property() override;
    virtual QString toString() override;
    virtual QString toRuby() override;

private:
    QAbstractButton *m_pControl;
    QString m_sText;
};

#endif // QBUTTONCASE_H
