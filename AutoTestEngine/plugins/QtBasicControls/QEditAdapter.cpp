#include "QEditAdapter.h"

#include <QLineEdit>
#include <QTextEdit>
#include "AutoTestSignalsIndexConst.h"
#include "QEditCase.h"

/*********************************************
 *
 * QLineEdit ÊÊÅä
 *
 *********************************************/
QLineEditAdapter::QLineEditAdapter()
    : QtAdapter()
{
    m_oSignalsList.append(SignalsStruct(&QLineEdit::staticMetaObject, n_QLineEdit_textChanged ));
}

int QLineEditAdapter::supportLevel(QObject *pObject)
{
    return AdapterManager::calcInheritedLevel(pObject->metaObject(), QLineEdit::staticMetaObject);
}

bool QLineEditAdapter::isMatchControl(QObject *objControl)
{
    return (nullptr != dynamic_cast<QLineEdit*> (objControl));
}

ICase *QLineEditAdapter::getCase(QObject *object)
{
    return new QLineEditCase(object);
}


/*********************************************
 *
 * QTextEdit ÊÊÅä
 *
 *********************************************/
QTextEditAdapter::QTextEditAdapter()
    : QtAdapter()
{
    m_oSignalsList.append(SignalsStruct(&QTextEdit::staticMetaObject, n_QTextEdit_textChanged));
}

int QTextEditAdapter::supportLevel(QObject *pObject)
{
    return AdapterManager::calcInheritedLevel(pObject->metaObject(), QTextEdit::staticMetaObject);
}

bool QTextEditAdapter::isMatchControl(QObject *objControl)
{
    return (nullptr != dynamic_cast<QTextEdit*> (objControl));
}

ICase *QTextEditAdapter::getCase(QObject *object)
{
    return new QTextEditCase(object);
}
