#ifndef QEDITADAPTER_H
#define QEDITADAPTER_H
#include "QtAdapter.h"

/*********************************************
 *
 * QLineEdit 适配
 *
 *********************************************/
class QLineEditAdapter : public QtAdapter
{
    Q_OBJECT
    ADAPTER
public:
    Q_INVOKABLE QLineEditAdapter();
    static int supportLevel(QObject *pObject);
    // 判断当前 控件是否匹配
    virtual bool isMatchControl(QObject *objControl) override;
    // 获得对应的Case实例
    virtual ICase* getCase(QObject *object) override;
};


/*********************************************
 *
 * QTextEdit 适配
 *
 *********************************************/
class QTextEditAdapter : public QtAdapter
{
    Q_OBJECT
    ADAPTER
public:
    Q_INVOKABLE QTextEditAdapter();
    static int supportLevel(QObject *pObject);
    // 判断当前 控件是否匹配
    virtual bool isMatchControl(QObject *objControl) override;
    // 获得对应的Case实例
    virtual ICase* getCase(QObject *object) override;
};

#endif // QEDITADAPTER_H
