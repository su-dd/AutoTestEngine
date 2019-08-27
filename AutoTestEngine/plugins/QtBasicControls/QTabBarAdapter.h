#ifndef QTABBARADAPTER_H
#define QTABBARADAPTER_H
#include "QtAdapter.h"

class QTabBarAdapter : public QtAdapter
{
    Q_OBJECT
    ADAPTER
public:
    Q_INVOKABLE QTabBarAdapter();
    static int supportLevel(QObject *pObject);
    // �жϵ�ǰ �ؼ��Ƿ�ƥ��
    virtual bool isMatchControl(QObject *objControl) override;
    // ��ö�Ӧ��Caseʵ��
    virtual ICase* getCase(QObject *object) override;
};

#endif // QTABBARADAPTER_H
