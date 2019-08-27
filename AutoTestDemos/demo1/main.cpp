#include "widget.h"
#include <QApplication>

#include <QToolButton>
#include <QComboBox>
#include <QDebug>
#include <QTime>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTime o1 = QTime::currentTime();
    qDebug() << o1;

    QTime o2 = QTime::currentTime();
    qDebug() << o2;
    Widget w;
    w.show();
    return a.exec();
}
