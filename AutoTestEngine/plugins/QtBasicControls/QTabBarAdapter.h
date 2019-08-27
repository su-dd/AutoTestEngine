#ifndef QTABBARADAPTER_H
#define QTABBARADAPTER_H
#include "QtAdapter.h"

class QTabBarAdapter : public QtAdapter
{
    Q_OBJECT
    ADAPTER
public:
    Q_INVOKABLE QTabBarAdapter();
    static int supportLevel(QObject *pObject);
    // 判断当前 控件是否匹配
    virtual bool isMatchControl(QObject *objControl) override;
    // 获得对应的Case实例
    virtual ICase* getCase(QObject *object) override;
};

#endif // QTABBARADAPTER_H
