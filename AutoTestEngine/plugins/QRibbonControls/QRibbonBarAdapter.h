#ifndef QRIBBONBARADAPTER_H
#define QRIBBONBARADAPTER_H

#include "QtAdapter.h"
#include <QtitanRibbon.h>

class QRibbonBarAdapter : public QtAdapter
{
    Q_OBJECT
    ADAPTER
public:
    Q_INVOKABLE QRibbonBarAdapter();
    static int supportLevel(QObject *pObject);
    virtual bool isAddControlCondition(QObject *obj, QEvent *event) override;
    virtual bool isRemoveControlCondition(QObject *obj, QEvent *event) override;
    //app ���¼�����
    virtual void appEventFilter(QObject *obj, QEvent *event) override;
    // �жϵ�ǰ �ؼ��Ƿ�ƥ��
    virtual bool isMatchControl(QObject *objControl) override;
    // ��ö�Ӧ��Caseʵ��
    virtual ICase* getCase(QObject *object) override;
private:
    Qtitan::RibbonPage* getCurRibbonPage(QObject *obj);
};


#endif // QRIBBONBARADAPTER_H
