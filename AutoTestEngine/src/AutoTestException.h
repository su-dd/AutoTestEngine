#ifndef AUTOTESTEXCEPTION
#define AUTOTESTEXCEPTION
#include <QtCore>
#include <QMessageBox>
#include <QString>
#include <QStringList>
#include <QtConcurrent/QtConcurrent>


class AutoTestExceptionCenter
{
public:
    static QString takeExceptionMessage();
    static void putExceptionMessage(const QString &strMessaget);

private:
    static QStringList m_slMessageList;
};


class Exception_NotFoundError : public QtConcurrent::Exception
{
public:
    void raise(const QString &strMessage) const
    {
        AutoTestExceptionCenter::putExceptionMessage(strMessage);
        throw *this;
    }
};

#endif // AUTOTESTEXCEPTION
