#ifndef AUTOTESTAPP_H
#define AUTOTESTAPP_H

#include <QObject>
#include <windows.h>

class AutoTestApp : public QObject
{
    Q_OBJECT
public:
    static AutoTestApp& instance();
    ~AutoTestApp();
    void run();
    void done();

    bool isNote();

    void addEventFilter();

    bool doStartNote();
    bool doNoteInfo();
protected:
    virtual bool eventFilter(QObject *obj, QEvent *event);

private:
    AutoTestApp();
private:
    bool m_bNote;
    bool m_bTip;
    bool m_bAddEventFilter;
};


#endif // AUTOTESTAPP_H
