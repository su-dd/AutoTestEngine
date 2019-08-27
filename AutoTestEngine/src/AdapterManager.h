/*!
 * @brief 头文件说明
 *
 * 适配器管理类
 * @author  sul-a
 * @date:    2019/07/03
 * @remarks
 * Copyright   (c) 1998-2012 Glodon Corporation
*/
#ifndef AdapterManager_H
#define AdapterManager_H

// 设置强制寻找，如果找不到则报异常
//#define STRONGSEARCH

#include <QObject>
#include "IAdapter.h"

//声明一个方法指针类型，便于静态调用适配器的此方法，不用每次都生成相应的实例对象
typedef int (*pSupportLevel)(QObject*);

class AdapterManager : public QObject
{
    Q_OBJECT
public:
    template <class T>
    static bool registerAdapter()
    {
        if (!adapterListInstance().contains(&(T::staticMetaObject)))
        {
            adapterListInstance().append(&(T::staticMetaObject));
            adapterMethodListInstance().append(&(T::supportLevel));
            adapterObjectListInstance().append(new T());
            return true;
        }
        return false;
    }

    static int calcInheritedLevel(const QMetaObject* AObject, const QMetaObject ABaseObject);
    static int calcInheritedLevel(const QMetaObject* AObject, const QString &ABaseObjectName);

    static IAdapter* createAdapter(QObject* AControl, const QString &strAdapterName);
    static IAdapter* createAdapter(QObject* AControl, const QMetaObject &AStaticMetaObject);
    static IAdapter* createAdapter(QObject* AControl);

    static IAdapter* findAdapter(QObject* AControl, const QString &strAdapterName);
    static IAdapter* findAdapter(QObject* AControl);

private:
    static QList<IAdapter*> &adapterObjectListInstance();
    static QList<const QMetaObject*> &adapterListInstance();
    static QList<pSupportLevel> &adapterMethodListInstance();
};

//定义几个宏，可以在每个适配器单元编译时就注册进来，不用再每次主动调用注册方法
#define ADAPTER static bool isRegister;
#define REGISTER_ADAPTER(type) bool type::isRegister = AdapterManager::registerAdapter<type>();

#endif // AdapterManager_H
