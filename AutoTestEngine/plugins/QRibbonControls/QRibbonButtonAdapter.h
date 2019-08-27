#ifndef QRIBBONBUTTONADAPTER_H
#define QRIBBONBUTTONADAPTER_H

#include "QtAdapter.h"
#include <QtitanRibbon.h>

class QRibbonButtonAdapter  : public QtAdapter
{
    Q_OBJECT
    ADAPTER
public:
    Q_INVOKABLE QRibbonButtonAdapter();
    static int supportLevel(QObject *pObject);
    // �жϵ�ǰ �ؼ��Ƿ�ƥ��
    virtual bool isMatchControl(QObject *objControl) override;
    // ��ö�Ӧ��Caseʵ��
    virtual ICase* getCase(QObject *object) override;
};

#endif // QRIBBONBUTTONADAPTER_H
