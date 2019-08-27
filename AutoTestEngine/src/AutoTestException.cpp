#include "AutoTestException.h"

QStringList AutoTestExceptionCenter::m_slMessageList;

QString AutoTestExceptionCenter::takeExceptionMessage()
{
    if (!m_slMessageList.isEmpty())
    {
        return m_slMessageList.takeLast();
    }
    return "";
}

void AutoTestExceptionCenter::putExceptionMessage(const QString &strMessaget)
{
    m_slMessageList.append(strMessaget);
}
