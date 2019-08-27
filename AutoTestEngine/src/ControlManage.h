/*!
 * @brief 头文件说明
 *
 * 控件管理类，记录当前进程的可用控件对象
 * @author  sul-a
 * @date:    2019/07/03
 * @remarks
 * Copyright   (c) 1998-2012 Glodon Corporation
*/
#ifndef CONTROLMANAGE_H
#define CONTROLMANAGE_H

#include <QObject>

class ControlManage : public QObject
{
    Q_OBJECT
public:
    static ControlManage& instance();

public:
    bool appEventFilter(QObject *obj, QEvent *event);

private:
    ControlManage();
};

#endif // CONTROLMANAGE_H
