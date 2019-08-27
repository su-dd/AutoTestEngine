#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QDialog>

#include <QPlainTextEdit>

class MainView : public QDialog
{
    Q_OBJECT
public:
    explicit MainView(QWidget *parent = 0);
    ~MainView();

    void initUI();
    void initData();

private:

    QPlainTextEdit *m_pTextEdit;

};

#endif // MAINVIEW_H
