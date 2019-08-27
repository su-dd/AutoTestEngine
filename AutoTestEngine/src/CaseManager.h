/*!
 * @brief 头文件说明
 *
 * 事例管理类
 * @author  sul-a
 * @date:    2019/07/03
 * @remarks
 * Copyright   (c) 1998-2012 Glodon Corporation
*/
#ifndef CASEMANAGER_H
#define CASEMANAGER_H

#include "ICase.h"
#include <QList>
#include <QVector>
#include <QMap>

/**********************************
 *
 * 用户操作Case管理
 *
 * *********************************/
class UserOperationCaseManager
{
public:
    static UserOperationCaseManager& instance();
    ~UserOperationCaseManager();

     void add(ICase* pCase);
     void clean();
     ICase* take();

private:
    UserOperationCaseManager();

private:
    QList<ICase*> m_oCaseList;
};

/**********************************
 *
 * 控件Case管理，处理 保存，释放等
 *
 * *********************************/
class ControlCaseObjectManager
{
public:
    static ControlCaseObjectManager& instance();
    ~ControlCaseObjectManager();
    // 添加实例
    void add(ICase * caseObj);
    // 删除实例
    void remove(ICase * caseObj);
    // 获得实例
    ICase* findCase(QObject* obj);
    bool contains(QObject* obj);

public:
    void cleanAllCaseState();
private:
    ControlCaseObjectManager();
private:
    // 控件map
    QMap<int, ICase *> m_oCaseMap;
};


/***************************************************************
 *
 * 控件Case 对象基于特征值的管理
 * 作用：给特征值相同的对象排序。
 *
****************************************************************/
class CaseObjectManager
{
public:
    // 添加实例
    void add(ICase * caseObj);
    // 删除实例
    void remove(ICase * caseObj);
    // 获得实例
    ICase* findCase(QObject* obj);
    bool contains(QObject* obj);
private:
    // 控件特征map
    QMap<int, QString> m_oPropertyMap;
    // 控件map
    QMap<int, ICase *> m_oCaseMap;
};


#endif // CASEMANAGER_H
