#ifndef QTABBARCASE_H
#define QTABBARCASE_H

#include <QTabBar>
#include <QString>
#include "QtCase.h"

class QTabBarCase : public QtCase
{
    Q_OBJECT
public:
    QTabBarCase(QObject *object);
    virtual ~QTabBarCase();
    virtual ICase* takeNote(QObject *sender, const QMetaObject *obj, int local_signal_index, void **argv) override;
    virtual QString actionKey() override;
    virtual QString property() override;
    virtual QString toString() override;
    virtual QString toRuby() override;

private:
    QTabBarCase(QObject *object, QString lastString);
    void refreshValue();

private:
    QTabBar *m_pControl;
    QStringList m_oTabStrs;
    QString m_sCurText;
    QString m_sLateText;
};

#endif // QTABBARCASE_H
