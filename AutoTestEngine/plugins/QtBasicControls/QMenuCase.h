#ifndef QMENUCASE_H
#define QMENUCASE_H

#include <QMenu>
#include <QAction>
#include <QString>
#include "QtCase.h"

class QMenuCase : public QtCase
{
    Q_OBJECT
public:
    QMenuCase(QObject *object);
    virtual ~QMenuCase();
    virtual ICase* takeNote(QObject *sender, const QMetaObject *obj, int local_signal_index, void **argv) override;
    virtual QString property() override;
    virtual QString toString() override;
    virtual QString toRuby() override;

private:
    QString getMenuPath(QMenu *control);

private:
    QMenu *m_pControl;
    QAction *m_oActiveAction;
    QString m_sActionPath;
};

#endif // QMENUCASE_H
