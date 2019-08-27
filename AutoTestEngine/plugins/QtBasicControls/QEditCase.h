#ifndef QEDITCASE_H
#define QEDITCASE_H

#include <QLineEdit>
#include <QTextEdit>
#include <QString>
#include "QtCase.h"

/*********************************************
 *
 * QLineEdit ÊÂÀý
 *
 *********************************************/
class QLineEditCase : public QtCase
{
    Q_OBJECT
public:
    QLineEditCase(QObject *object);
    virtual ~QLineEditCase();
    virtual ICase*  takeNote(QObject *sender, const QMetaObject *obj, int local_signal_index, void **argv) override;
    virtual QString property() override;
    virtual QString toString() override;
    virtual QString toRuby() override;

private:
    QLineEdit *m_pControl;
    QString m_sObjectName;
    QString m_sCurText;
    QString m_sLeftText;
};


/*********************************************
 *
 * QTextEdit ÊÂÀý
 *
 *********************************************/
class QTextEditCase : public QtCase
{
    Q_OBJECT
public:
    QTextEditCase(QObject *object);
    virtual ~QTextEditCase();
    virtual ICase*  takeNote(QObject *sender, const QMetaObject *obj, int local_signal_index, void **argv) override;
    virtual QString property() override;
    virtual QString toString() override;
    virtual QString toRuby() override;

private:
    QTextEdit *m_pControl;
    QString m_sObjectName;
    QString m_sCurText;
    QString m_sLeftText;
};

#endif // QEDITCASE_H
