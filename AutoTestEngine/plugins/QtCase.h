#ifndef QTCASE_H
#define QTCASE_H

#include "ICase.h"
#include <QObject>
#include <QWidget>
#include <QLayout>
#include <QString>

class QtCase : public ICase
{
public:
    QtCase(QObject *object);
    virtual ~QtCase();

    virtual long key() override;
    virtual QString actionKey() override;
    virtual void setPropertyIndex(int index) override;
    virtual ICase* takeNote(QObject *sender, const QMetaObject *obj, int local_signal_index, void **argv) override;
    virtual ICase* takeNote(QObject *obj, QEvent *event) override;
protected:
    QString getControlLeftText(QObject *control);
    QWidget *getParentWidget(QObject *object);
    QString getLeftSiblingControlName(QLayout *layout, QObject *object);
private:
    void initParentInfo();
    QWidget *getTitleParentWidget(QObject *object);
protected:
    long m_nKeyID;
    int m_nPropertyIndex;
    QObject *m_pCurObject;
    QWidget *m_pTitleParentWidget;
    QString m_sTitleParentText;
    QString m_sTitleParentObjectName;
};

#endif // QTCASE_H
