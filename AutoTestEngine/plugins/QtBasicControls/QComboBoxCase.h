#ifndef QCOMBOBOXCASE_H
#define QCOMBOBOXCASE_H

#include <QComboBox>
#include <QString>
#include "QtCase.h"

class QComboBoxCase: public QtCase
{
    Q_OBJECT
public:
    QComboBoxCase(QObject *object);
    virtual ~QComboBoxCase();
    virtual ICase* takeNote(QObject *sender, const QMetaObject *obj, int local_signal_index, void **argv) override;
    virtual ICase* takeNote(QObject *obj, QEvent *event) override;
    virtual QString property() override;
    virtual QString toString() override;
    virtual QString toRuby() override;

private:
    QComboBox *m_pControl;
    QString m_sCurText;
    QString m_sLeftText;
};

#endif // QCOMBOBOXCASE_H
