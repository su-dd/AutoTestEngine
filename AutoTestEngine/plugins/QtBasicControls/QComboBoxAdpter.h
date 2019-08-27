#ifndef QComboBoxAdpter_H
#define QComboBoxAdpter_H
#include "QtAdapter.h"

class QComboBoxAdpter : public QtAdapter
{
    Q_OBJECT
    ADAPTER
public:
    Q_INVOKABLE QComboBoxAdpter();
    static int supportLevel(QObject *pObject);
    // 判断当前 控件是否匹配
    virtual bool isMatchControl(QObject *objControl) override;
    // 获得对应的Case实例
    virtual ICase* getCase(QObject *object) override;
    // 事件过滤
    virtual bool eventFilter(QObject *obj, QEvent *event) override;
};

#endif // QComboBoxAdpter_H
