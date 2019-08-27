/*!
 * @brief ͷ�ļ�˵��
 *
 * ������������
 * @author  sul-a
 * @date:    2019/07/03
 * @remarks
 * Copyright   (c) 1998-2012 Glodon Corporation
*/
#ifndef AdapterManager_H
#define AdapterManager_H

// ����ǿ��Ѱ�ң�����Ҳ������쳣
//#define STRONGSEARCH

#include <QObject>
#include "IAdapter.h"

//����һ������ָ�����ͣ����ھ�̬�����������Ĵ˷���������ÿ�ζ�������Ӧ��ʵ������
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

//���弸���꣬������ÿ����������Ԫ����ʱ��ע�������������ÿ����������ע�᷽��
#define ADAPTER static bool isRegister;
#define REGISTER_ADAPTER(type) bool type::isRegister = AdapterManager::registerAdapter<type>();

#endif // AdapterManager_H
