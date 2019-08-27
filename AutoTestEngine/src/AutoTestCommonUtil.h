#ifndef AUTOTESTCOMMONUTIL_H
#define AUTOTESTCOMMONUTIL_H

#include <QtCore/QString>

enum AutoTestExceptionType
{
    E_NotFoundError = 1
};


void raiseAutoTestException(const QString &EXMsg, AutoTestExceptionType exceptionType);

#endif // AUTOTESTCOMMONUTIL_H
