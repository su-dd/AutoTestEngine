#include "AutoTestCommonUtil.h"

#include "AutoTestException.h"

void raiseAutoTestException(const QString &EXMsg, AutoTestExceptionType exceptionType)
{
    switch (exceptionType)
    {
    case E_NotFoundError:
        {
            Exception_NotFoundError ex;
            ex.raise(EXMsg);
        }
    }
}
