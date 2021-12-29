#include "mainwindow.h"
#include "car_mainwondow.h"

#include <QApplication>

int main(int argc, char *argv[])
{

    //屏幕自适应的办法
    if(QT_VERSION>=QT_VERSION_CHECK(5,6,0))
             QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication a(argc, argv);
    car_mainWondow *w;
    w = new car_mainWondow();
    w->show();
    return a.exec();
}
