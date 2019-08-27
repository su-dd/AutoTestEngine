/*!
 * @brief ͷ�ļ�˵��.
 *
 * ��ѯ�ؼ�������Ϣ�Ľӿ�
 * @author sul-a
* @date 2019.7.2
* @remarks ��ע
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
    // �жϵ�ǰ �ؼ��Ƿ�ƥ��
    virtual bool isMatchControl(QObject *objControl) = 0;
    // ��ӵ� ��� �б�
    virtual void addControl(QObject *objControl) = 0;
    // ɾ�����
    virtual void removeControl(QObject *objControl) = 0;
    //app ���¼�����
    virtual void appEventFilter(QObject *obj, QEvent *event) = 0;
    // �жϵ�ǰ �ͺ��Ƿ�ƥ��
    virtual bool isMatchSignal(QObject *object, const QMetaObject *obj, int local_signal_index, void **argv) = 0;
    // ��ö�Ӧ��Caseʵ��
    virtual void signalAddCase(QObject *sender, const QMetaObject *obj, int local_signal_index, void **argv) = 0;
    virtual void eventAddCase(QObject *obj, QEvent *event, bool add) = 0;
    virtual ICase* getCase(QObject *object) = 0;
};

#endif // Iadapter_H

