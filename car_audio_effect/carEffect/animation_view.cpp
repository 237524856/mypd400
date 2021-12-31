#include "animation_view.h"
#include "qlabel.h"

animation_view::animation_view(QWidget *parent) : QWidget(parent)
{
    this->setAttribute(Qt::WA_StyledBackground,true);
    this->setStyleSheet("background-color:red");


    for (int i =0;i<10;i++) {
        QLabel *back_left_image = new QLabel(this);
        back_left_image->resize(38,24);
        back_left_image->move(i*24,0);
        back_left_image->setPixmap(QPixmap(":/images/back_round.png"));
    }


}
