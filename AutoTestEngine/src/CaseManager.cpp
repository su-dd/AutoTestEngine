#include "CaseManager.h"
#include "AutoTestApp.h"
//#include ""

/**********************************
 *
 * �û�����Case����
 *
 * *********************************/
UserOperationCaseManager &UserOperationCaseManager::instance()
{
    static UserOperationCaseManager oUserOperationCaseManager;
    return oUserOperationCaseManager;
}

UserOperationCaseManager::~UserOperationCaseManager()
{
    clean();
}

void UserOperationCaseManager::add(ICase *pCase)
{
    if (pCase != NULL)
    {
        // todo ��Ϊͬһʱ��ֻ����һ����Ч��Ϊ������������Ч�ġ����״̬�ȴ��ٴμ�¼
        ControlCaseObjectManager::instance().cleanAllCaseState();
        if (m_oCaseList.count() > 0)
        {
            if (QString::compare(m_oCaseList.last()->actionKey(), pCase->actionKey()) == 0)
            {
                // ȥ�أ��������µ���Ч����
                ICase *lastCase = m_oCaseList.takeLast();
                delete lastCase;
                lastCase = nullptr;
            }
        }
        m_oCaseList.append(pCase);
    }
}

void UserOperationCaseManager::clean()
{
    foreach (ICase* pCase, m_oCaseList)
    {
        delete pCase;
        pCase = NULL;
    }
    m_oCaseList.clear();
}

ICase *UserOperationCaseManager::take()
{
    if (!m_oCaseList.isEmpty())
    {
        return m_oCaseList.takeFirst();
    }
    return nullptr;
}

UserOperationCaseManager::UserOperationCaseManager()
{

}

/**********************************
 *
 * �ؼ�Case�������� ���棬�ͷŵ�
 *
 * *********************************/

ControlCaseObjectManager &ControlCaseObjectManager::instance()
{
    static ControlCaseObjectManager oControlCaseObjectManager;
    return oControlCaseObjectManager;
}

ControlCaseObjectManager::~ControlCaseObjectManager()
{
    foreach (ICase *caseObj, m_oCaseMap.values())
    {
        if (nullptr != caseObj)
        {
            delete caseObj;
            caseObj = nullptr;
        }
    }
}

void ControlCaseObjectManager::add(ICase *caseObj)
{
    if (nullptr == caseObj)
    {
        return;
    }

    if (m_oCaseMap.contains(caseObj->key()))
    {
        return;
    }

    m_oCaseMap.insert(caseObj->key(), caseObj);
}

void ControlCaseObjectManager::remove(ICase *caseObj)
{
    m_oCaseMap.remove(caseObj->key());
    delete caseObj;
    caseObj = nullptr;
}

ICase *ControlCaseObjectManager::findCase(QObject *obj)
{
    if (contains(obj))
    {
        return m_oCaseMap.find(CaseUnit::getControlKey(obj)).value();
    }
    return nullptr;
}

bool ControlCaseObjectManager::contains(QObject *obj)
{
    return m_oCaseMap.contains(CaseUnit::getControlKey(obj));
}

void ControlCaseObjectManager::cleanAllCaseState()
{
    foreach (ICase *caseObj, m_oCaseMap.values())
    {
        if (nullptr != caseObj)
        {
            caseObj->initialiseCaseState();
        }
    }
}

ControlCaseObjectManager::ControlCaseObjectManager()
{
}



/***************************************************************
 *
 * �ؼ�Case �����������ֵ�Ĺ���
 * ���ã�������ֵ��ͬ�Ķ�������
 *
****************************************************************/
void CaseObjectManager::add(ICase *caseObj)
{
    if (nullptr == caseObj)
    {
        return;
    }

    if (m_oCaseMap.contains(caseObj->key()))
    {
        return;
    }

    m_oCaseMap.insert(caseObj->key(), caseObj);
    m_oPropertyMap.insert(caseObj->key(), caseObj->property());
    caseObj->setPropertyIndex(
                m_oPropertyMap.values().count(caseObj->property()));
}

void CaseObjectManager::remove(ICase *caseObj)
{
    m_oCaseMap.remove(caseObj->key());
    m_oPropertyMap.remove(caseObj->key());
}

ICase *CaseObjectManager::findCase(QObject *obj)
{
    if (contains(obj))
    {
        return m_oCaseMap.find(CaseUnit::getControlKey(obj)).value();
    }
    return nullptr;
}

bool CaseObjectManager::contains(QObject *obj)
{
    return m_oCaseMap.contains(CaseUnit::getControlKey(obj));
}
