#include "mix_main_view.h"
#include <QFontDatabase>
#include <QLabel>

mix_main_view::mix_main_view(QWidget *parent) : QMainWindow(parent)
{

    setFixedSize(802,824);
    this->setWindowFlags(this->windowFlags() | Qt::WindowStaysOnTopHint);
    QFontDatabase::addApplicationFont(":/images/SourceHanSansCN Medium.ttf");
    QLabel *back_left_image = new QLabel(this);
    back_left_image->move(0,0);
    back_left_image->resize(this->width(),this->height());
    back_left_image->setPixmap(QPixmap(":images/mix/bg.png"));

}
