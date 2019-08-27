#ifndef QMENUADAPTER_H
#define QMENUADAPTER_H

#include "QtAdapter.h"

class QMenuAdapter : public QtAdapter
{
    Q_OBJECT
    ADAPTER
public:
    Q_INVOKABLE QMenuAdapter();
    static int supportLevel(QObject *pObject);
    virtual bool isAddControlCondition(QObject *obj, QEvent *event) override;
    virtual bool isRemoveControlCondition(QObject *obj, QEvent *event) override;
    // 判断当前 控件是否匹配
    virtual bool isMatchControl(QObject *objControl) override;
    // 获得对应的Case实例
    virtual ICase* getCase(QObject *object) override;
};

#endif // QMENUADAPTER_H
