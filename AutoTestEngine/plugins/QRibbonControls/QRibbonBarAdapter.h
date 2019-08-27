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
    //app 的事件过滤
    virtual void appEventFilter(QObject *obj, QEvent *event) override;
    // 判断当前 控件是否匹配
    virtual bool isMatchControl(QObject *objControl) override;
    // 获得对应的Case实例
    virtual ICase* getCase(QObject *object) override;
private:
    Qtitan::RibbonPage* getCurRibbonPage(QObject *obj);
};


#endif // QRIBBONBARADAPTER_H
