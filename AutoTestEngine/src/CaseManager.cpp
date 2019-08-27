#include "CaseManager.h"
#include "AutoTestApp.h"
//#include ""

/**********************************
 *
 * 用户操作Case管理
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
        // todo 认为同一时刻只产生一次有效行为，其他都是无效的。清空状态等待再次记录
        ControlCaseObjectManager::instance().cleanAllCaseState();
        if (m_oCaseList.count() > 0)
        {
            if (QString::compare(m_oCaseList.last()->actionKey(), pCase->actionKey()) == 0)
            {
                // 去重，留下最新的有效操作
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
 * 控件Case管理，处理 保存，释放等
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
 * 控件Case 对象基于特征值的管理
 * 作用：给特征值相同的对象排序。
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
