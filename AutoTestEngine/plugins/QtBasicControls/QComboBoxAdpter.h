#ifndef QComboBoxAdpter_H
#define QComboBoxAdpter_H
#include "QtAdapter.h"

class QComboBoxAdpter : public QtAdapter
{
    Q_OBJECT
    ADAPTER
public:
    Q_INVOKABLE QComboBoxAdpter();
    static int supportLevel(QObject *pObject);
    // �жϵ�ǰ �ؼ��Ƿ�ƥ��
    virtual bool isMatchControl(QObject *objControl) override;
    // ��ö�Ӧ��Caseʵ��
    virtual ICase* getCase(QObject *object) override;
    // �¼�����
    virtual bool eventFilter(QObject *obj, QEvent *event) override;
};

#endif // QComboBoxAdpter_H
