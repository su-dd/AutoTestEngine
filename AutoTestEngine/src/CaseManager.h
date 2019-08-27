/*!
 * @brief ͷ�ļ�˵��
 *
 * ����������
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
 * �û�����Case����
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
 * �ؼ�Case�������� ���棬�ͷŵ�
 *
 * *********************************/
class ControlCaseObjectManager
{
public:
    static ControlCaseObjectManager& instance();
    ~ControlCaseObjectManager();
    // ���ʵ��
    void add(ICase * caseObj);
    // ɾ��ʵ��
    void remove(ICase * caseObj);
    // ���ʵ��
    ICase* findCase(QObject* obj);
    bool contains(QObject* obj);

public:
    void cleanAllCaseState();
private:
    ControlCaseObjectManager();
private:
    // �ؼ�map
    QMap<int, ICase *> m_oCaseMap;
};


/***************************************************************
 *
 * �ؼ�Case �����������ֵ�Ĺ���
 * ���ã�������ֵ��ͬ�Ķ�������
 *
****************************************************************/
class CaseObjectManager
{
public:
    // ���ʵ��
    void add(ICase * caseObj);
    // ɾ��ʵ��
    void remove(ICase * caseObj);
    // ���ʵ��
    ICase* findCase(QObject* obj);
    bool contains(QObject* obj);
private:
    // �ؼ�����map
    QMap<int, QString> m_oPropertyMap;
    // �ؼ�map
    QMap<int, ICase *> m_oCaseMap;
};


#endif // CASEMANAGER_H
