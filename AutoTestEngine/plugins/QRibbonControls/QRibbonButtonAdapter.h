#ifndef QRIBBONBUTTONADAPTER_H
#define QRIBBONBUTTONADAPTER_H

#include "QtAdapter.h"
#include <QtitanRibbon.h>

class QRibbonButtonAdapter  : public QtAdapter
{
    Q_OBJECT
    ADAPTER
public:
    Q_INVOKABLE QRibbonButtonAdapter();
    static int supportLevel(QObject *pObject);
    // 判断当前 控件是否匹配
    virtual bool isMatchControl(QObject *objControl) override;
    // 获得对应的Case实例
    virtual ICase* getCase(QObject *object) override;
};

#endif // QRIBBONBUTTONADAPTER_H
