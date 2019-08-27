/*!
 * @brief 头文件说明.
 *
 * 定义控件各类操作的接口
 * 所有的Case子类必须在构造函数中就把要准备的数据准备好；防止：控制释放后对应的数据取不到，报错。
 * @author sul-a
* @date 2019.7.2
* @remarks 备注
* Copyright (c) 1998-2011 Glodon Corporation
*/
#ifndef ICASE
#define ICASE
#include <QObject>
#include <QString>

#define AuToTestDebug

class CaseUnit
{
public:
    static long getControlKey(QObject* obj)
    {
        return reinterpret_cast<long>(obj);
    }
};


class ICase : public QObject
{
    Q_OBJECT
public:
    virtual ~ICase() {}

/********************************外部调用函数****************************************/
public:
    // 获得Note记录
    ICase* signalTakeNote(QObject *sender, const QMetaObject *obj, int local_signal_index, void **argv)
    {
        ICase* pCase = takeNote(sender, obj, local_signal_index, argv);
#ifdef AuToTestDebug
        if (NULL != pCase)
        {
            pCase->setDebugString(QString("signal:"));
        }
#endif
        return pCase;
    }

    // 获得Note记录
    ICase* eventTakeNote(QObject *obj, QEvent *event)
    {
        ICase* pCase = takeNote(obj, event);
#ifdef AuToTestDebug
        if (NULL != pCase)
        {
            pCase->setDebugString(QString("event:"));
        }
#endif
        return pCase;
    }

    // 转换为中间文件
    QString string()
    {
#ifdef AuToTestDebug
        return m_sDebug + toString();
#else
        return toString();
#endif
    }

    // 转换为Ruby脚本
    QString ruby()
    {
#ifdef AuToTestDebug
        return m_sDebug + toRuby();
#else
        return toRuby();
#endif
    }

    // 添加调试数据
#ifdef AuToTestDebug
    void setDebugString(QString str)
    {
        m_sDebug.append(str);
    }
#endif

private:
#ifdef AuToTestDebug
    QString m_sDebug;
#endif
/************************************************************************/


/***************************子类使用函数************************************/
public:
    // 设置控件触发状态： 控件需要记录的条件不同，所以设置多个状态值
    virtual void controlActive() { m_bControlActive = true; }
    virtual void signalChange() { m_bSignalChange = true; }
    virtual void initialiseCaseState()
    {
        m_bSignalChange = false;
        m_bControlActive = false;
    }

    // comboBox 可以记录的条件
    virtual bool comboBoxNoteCondition() { return m_bSignalChange && m_bControlActive; }

protected:
    bool m_bSignalChange;
    bool m_bControlActive;
/***********************************************************************/


/****************************子类重写函数******************************************/
public:
    // 唯一值，现在使用控件的指针地址
    virtual long key() = 0;
    // 标识当前操作，相邻的多个相同的key将只认为最后一个是有效的。
    virtual QString actionKey() = 0;
    // 特征值，用于表示当前控件的
    virtual QString property() = 0;
    // 特征值序号，用于表示第几个拥有当前特征的控件
    virtual void setPropertyIndex(int index) = 0;
protected:
    // 获得Note记录
    virtual ICase* takeNote(QObject *sender, const QMetaObject *obj, int local_signal_index, void **argv) = 0;
    virtual ICase* takeNote(QObject *obj, QEvent *event) = 0;
    // 转换为中间文件
    virtual QString toString() = 0;
    // 转换为Ruby脚本
    virtual QString toRuby() = 0;
/****************************子类重写函数******************************************/

};

#endif // ICASE
