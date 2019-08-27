#ifndef QMENUADAPTER_H
#define QMENUADAPTER_H

#include "QtAdapter.h"

class QMenuAdapter : public QtAdapter
{
    Q_OBJECT
    ADAPTER
public:
    Q_INVOKABLE QMenuAdapter();
    static int supportLevel(QObject *pObject);
    virtual bool isAddControlCondition(QObject *obj, QEvent *event) override;
    virtual bool isRemoveControlCondition(QObject *obj, QEvent *event) override;
    // �жϵ�ǰ �ؼ��Ƿ�ƥ��
    virtual bool isMatchControl(QObject *objControl) override;
    // ��ö�Ӧ��Caseʵ��
    virtual ICase* getCase(QObject *object) override;
};

#endif // QMENUADAPTER_H
