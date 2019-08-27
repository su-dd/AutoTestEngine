#ifndef QEDITADAPTER_H
#define QEDITADAPTER_H
#include "QtAdapter.h"

/*********************************************
 *
 * QLineEdit ����
 *
 *********************************************/
class QLineEditAdapter : public QtAdapter
{
    Q_OBJECT
    ADAPTER
public:
    Q_INVOKABLE QLineEditAdapter();
    static int supportLevel(QObject *pObject);
    // �жϵ�ǰ �ؼ��Ƿ�ƥ��
    virtual bool isMatchControl(QObject *objControl) override;
    // ��ö�Ӧ��Caseʵ��
    virtual ICase* getCase(QObject *object) override;
};


/*********************************************
 *
 * QTextEdit ����
 *
 *********************************************/
class QTextEditAdapter : public QtAdapter
{
    Q_OBJECT
    ADAPTER
public:
    Q_INVOKABLE QTextEditAdapter();
    static int supportLevel(QObject *pObject);
    // �жϵ�ǰ �ؼ��Ƿ�ƥ��
    virtual bool isMatchControl(QObject *objControl) override;
    // ��ö�Ӧ��Caseʵ��
    virtual ICase* getCase(QObject *object) override;
};

#endif // QEDITADAPTER_H
