#ifndef QTADAPTER_H
#define QTADAPTER_H
#include "IAdapter.h"
#include "ICase.h"
#include "AdapterManager.h"
#include "CaseManager.h"

/***************************************************************
 *
 * ����������
 *
 *
****************************************************************/

class QtAdapter : public IAdapter
{
    Q_OBJECT
public:
    struct SignalsStruct
    {
        QString metaObjStr;   // �ඨ���о�̬�� QMetaObject �����classname
        const int signals_index;      // �ඨ���� �źŵ� λ��

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
    // ��ӵ��¼�
    virtual bool isAddControlCondition(QObject *obj, QEvent *event) override;
    // �Ƴ����¼�
    virtual bool isRemoveControlCondition(QObject *obj, QEvent *event) override;
    // �жϵ�ǰ �ؼ��Ƿ�ƥ��
    virtual bool isMatchControl(QObject *objControl) override;
    // ��ӵ� ��� �б�
    virtual void addControl(QObject *objControl) override;
    // ɾ�����
    virtual void removeControl(QObject *objControl) override;
    // �¼�����
    virtual bool eventFilter(QObject *obj, QEvent *event) override;
    //app ���¼�����
    virtual void appEventFilter(QObject *obj, QEvent *event) override;
    // �жϵ�ǰ �ͺ��Ƿ�ƥ��
    virtual bool isMatchSignal(QObject *object, const QMetaObject *obj, int local_signal_index, void **argv) override;

    // ��ö�Ӧ��Caseʵ��
    virtual void signalAddCase(QObject *sender, const QMetaObject *obj, int local_signal_index, void **argv) override;
    virtual void eventAddCase(QObject *obj, QEvent *event, bool add);
    virtual ICase *getCase(QObject *object) override;
protected:
    // �ź��б�
    QList <SignalsStruct> m_oSignalsList;
    // ��� �ؼ��б�
    CaseObjectManager m_oCaseObjectManager;
};


#endif // QTADAPTER_H
