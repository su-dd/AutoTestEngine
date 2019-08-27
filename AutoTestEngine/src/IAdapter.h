/*!
 * @brief 头文件说明.
 *
 * 查询控件各类信息的接口
 * @author sul-a
* @date 2019.7.2
* @remarks 备注
* Copyright (c) 1998-2011 Glodon Corporation
*/
#ifndef Iadapter_H
#define Iadapter_H
#include <QObject>
#include <QEvent>
#include "ICase.h"

class IAdapter : public QObject
{
    Q_OBJECT
public:
    virtual ~IAdapter() {}
    virtual bool isAddControlCondition(QObject *obj, QEvent *event) = 0;
    virtual bool isRemoveControlCondition(QObject *obj, QEvent *event) = 0;
    // 判断当前 控件是否匹配
    virtual bool isMatchControl(QObject *objControl) = 0;
    // 添加到 监控 列表
    virtual void addControl(QObject *objControl) = 0;
    // 删除监控
    virtual void removeControl(QObject *objControl) = 0;
    //app 的事件过滤
    virtual void appEventFilter(QObject *obj, QEvent *event) = 0;
    // 判断当前 型号是否匹配
    virtual bool isMatchSignal(QObject *object, const QMetaObject *obj, int local_signal_index, void **argv) = 0;
    // 获得对应的Case实例
    virtual void signalAddCase(QObject *sender, const QMetaObject *obj, int local_signal_index, void **argv) = 0;
    virtual void eventAddCase(QObject *obj, QEvent *event, bool add) = 0;
    virtual ICase* getCase(QObject *object) = 0;
};

#endif // Iadapter_H

