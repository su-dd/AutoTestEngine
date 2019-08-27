/*!
 * @brief ͷ�ļ�˵��.
 *
 * ����ؼ���������Ľӿ�
 * ���е�Case��������ڹ��캯���оͰ�Ҫ׼��������׼���ã���ֹ�������ͷź��Ӧ������ȡ����������
 * @author sul-a
* @date 2019.7.2
* @remarks ��ע
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

/********************************�ⲿ���ú���****************************************/
public:
    // ���Note��¼
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

    // ���Note��¼
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

    // ת��Ϊ�м��ļ�
    QString string()
    {
#ifdef AuToTestDebug
        return m_sDebug + toString();
#else
        return toString();
#endif
    }

    // ת��ΪRuby�ű�
    QString ruby()
    {
#ifdef AuToTestDebug
        return m_sDebug + toRuby();
#else
        return toRuby();
#endif
    }

    // ��ӵ�������
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


/***************************����ʹ�ú���************************************/
public:
    // ���ÿؼ�����״̬�� �ؼ���Ҫ��¼��������ͬ���������ö��״ֵ̬
    virtual void controlActive() { m_bControlActive = true; }
    virtual void signalChange() { m_bSignalChange = true; }
    virtual void initialiseCaseState()
    {
        m_bSignalChange = false;
        m_bControlActive = false;
    }

    // comboBox ���Լ�¼������
    virtual bool comboBoxNoteCondition() { return m_bSignalChange && m_bControlActive; }

protected:
    bool m_bSignalChange;
    bool m_bControlActive;
/***********************************************************************/


/****************************������д����******************************************/
public:
    // Ψһֵ������ʹ�ÿؼ���ָ���ַ
    virtual long key() = 0;
    // ��ʶ��ǰ���������ڵĶ����ͬ��key��ֻ��Ϊ���һ������Ч�ġ�
    virtual QString actionKey() = 0;
    // ����ֵ�����ڱ�ʾ��ǰ�ؼ���
    virtual QString property() = 0;
    // ����ֵ��ţ����ڱ�ʾ�ڼ���ӵ�е�ǰ�����Ŀؼ�
    virtual void setPropertyIndex(int index) = 0;
protected:
    // ���Note��¼
    virtual ICase* takeNote(QObject *sender, const QMetaObject *obj, int local_signal_index, void **argv) = 0;
    virtual ICase* takeNote(QObject *obj, QEvent *event) = 0;
    // ת��Ϊ�м��ļ�
    virtual QString toString() = 0;
    // ת��ΪRuby�ű�
    virtual QString toRuby() = 0;
/****************************������д����******************************************/

};

#endif // ICASE
