#ifndef QTADAPTER_H
#define QTADAPTER_H
#include "IAdapter.h"
#include "ICase.h"
#include "AdapterManager.h"
#include "CaseManager.h"

/***************************************************************
 *
 * 适配器基类
 *
 *
****************************************************************/

class QtAdapter : public IAdapter
{
    Q_OBJECT
public:
    struct SignalsStruct
    {
        QString metaObjStr;   // 类定义中静态的 QMetaObject 对象的classname
        const int signals_index;      // 类定义中 信号的 位置

        SignalsStruct(const QMetaObject* Obj, const int index)
            :signals_index(index)
        {
            metaObjStr = QString::fromLocal8Bit(Obj->className());
        }

        SignalsStruct(QString & str, const int index)
            :metaObjStr(str), signals_index(index)
        {
        }
    };
    QtAdapter();
    virtual ~QtAdapter();
    // 添加的事件
    virtual bool isAddControlCondition(QObject *obj, QEvent *event) override;
    // 移除的事件
    virtual bool isRemoveControlCondition(QObject *obj, QEvent *event) override;
    // 判断当前 控件是否匹配
    virtual bool isMatchControl(QObject *objControl) override;
    // 添加到 监控 列表
    virtual void addControl(QObject *objControl) override;
    // 删除监控
    virtual void removeControl(QObject *objControl) override;
    // 事件过滤
    virtual bool eventFilter(QObject *obj, QEvent *event) override;
    //app 的事件过滤
    virtual void appEventFilter(QObject *obj, QEvent *event) override;
    // 判断当前 型号是否匹配
    virtual bool isMatchSignal(QObject *object, const QMetaObject *obj, int local_signal_index, void **argv) override;

    // 获得对应的Case实例
    virtual void signalAddCase(QObject *sender, const QMetaObject *obj, int local_signal_index, void **argv) override;
    virtual void eventAddCase(QObject *obj, QEvent *event, bool add);
    virtual ICase *getCase(QObject *object) override;
protected:
    // 信号列表
    QList <SignalsStruct> m_oSignalsList;
    // 监控 控件列表
    CaseObjectManager m_oCaseObjectManager;
};


#endif // QTADAPTER_H
