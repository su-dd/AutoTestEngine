#ifndef QBUTTONADAPTER_H
#define QBUTTONADAPTER_H
#include "QtAdapter.h"

class QAbstractButtonAdapter : public QtAdapter
{
    Q_OBJECT
    ADAPTER
public:
    Q_INVOKABLE QAbstractButtonAdapter();
    static int supportLevel(QObject *pObject);
    // �жϵ�ǰ �ؼ��Ƿ�ƥ��
    virtual bool isMatchControl(QObject *objControl) override;
    // ��ö�Ӧ��Caseʵ��
    virtual ICase* getCase(QObject *object) override;
};

#endif // QBUTTONADAPTER_H
