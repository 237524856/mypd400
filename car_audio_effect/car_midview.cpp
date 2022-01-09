
#pragma once
#pragma execution_character_set("utf-8")
#include "car_midview.h"
#include <QCheckBox>

car_midView::car_midView(QWidget *parent) : QWidget(parent)
{

}
void car_midView::createUI(){

    QLabel *back_left_image = new QLabel(this);
    back_left_image->move(0,0);
    back_left_image->resize(this->width(),this->height());
    back_left_image->setPixmap(QPixmap(":images/mid_bgimage.png"));


    QLabel *top_image = new QLabel(this);
    top_image->move((this->width()-207)/2,30);
    top_image->resize(207,132);
    top_image->setPixmap(QPixmap(":images/mid_top.png"));


    QCheckBox *didianping_btn = new QCheckBox(back_left_image);
    didianping_btn->resize(64,28);
    didianping_btn->move(86,164);

    didianping_btn->setStyleSheet(
                "QCheckBox::indicator{width: 64px;height: 28px;color:rgb(255, 0, 0);}"
                "QCheckBox::indicator:unchecked{border-image:url(:images/dianyuan_yinyuan_btn.png) 0 192 0 0;}"
                "QCheckBox::indicator:unchecked:hover{border-image:url(:images/dianyuan_yinyuan_btn.png) 0 128 0 64;}"
                "QCheckBox::indicator:checked{border-image:url(:images/dianyuan_yinyuan_btn.png) 0 64 0 128;}");
    connect(didianping_btn, SIGNAL(clicked(bool)), this, SLOT(mute_click_status(bool)));


    QLabel *dianping_label = new QLabel(didianping_btn);
    dianping_label->resize(64,28);
    dianping_label->move(0,0);
    dianping_label->setText("低电平");
    dianping_label->setStyleSheet("qproperty-alignment: AlignCenter;");


}
