
#pragma once
#pragma execution_character_set("utf-8")
#include "car_leftview.h"
#include "qlabel.h"
#include "QPushButton"
#include <QVector>

car_leftView::car_leftView(QWidget *parent) : QWidget(parent)
{

}
void car_leftView::createUI(){

    QLabel *back_left_image = new QLabel(this);
    back_left_image->move(25,4);
    back_left_image->resize(16,16);
    back_left_image->setPixmap(QPixmap(":images/icon_shuru.png"));

    QLabel *dianping = new QLabel(this);
    dianping->resize(20,13);
    dianping->move(23,22);
    dianping->setText("输入");
    dianping->setStyleSheet("font-size:9px;color:rgb(113,113,113);qproperty-alignment: AlignCenter;");

    QPushButton *shuru_btn = new QPushButton(this);
    shuru_btn->move(105,12);
    shuru_btn->resize(48,22);
    shuru_btn->setStyleSheet(
                                "QPushButton{border-image:url(:/images/shuru_shuchu_btn.png) 0 144 0 0;}"
                                "QPushButton:hover{border-image:url(:/images/shuru_shuchu_btn.png) 0 96 0 48;}"
                                "QPushButton:pressed{border-image:url(:/images/shuru_shuchu_btn.png) 0 48 0 96;}"
                                );
    QLabel *shuru_btn_label = new QLabel(shuru_btn);
    shuru_btn_label->resize(48,15);
    shuru_btn_label->move(0,0);
    shuru_btn_label->setText("输入类型");
    shuru_btn_label->setStyleSheet("font-size:10px;color:rgb(255,255,255);qproperty-alignment: AlignCenter;");



    QVector<QString> mytitles={"分频器","相位","音量(dB)","静音"};
    for (int i=0;i<4;i++) {
        QLabel *title_label = new QLabel(this);
        title_label->resize(42,175/4);
        title_label->move(175/4*i+182,0);
        title_label->setText(mytitles.at(i));
        title_label->setStyleSheet("font-size:10px;color:rgb(255,255,255);qproperty-alignment: AlignCenter;");

    }


    QVector<QString>out_put_titles={"QPushButton{border-image:url(:/images/guangqian.png);}","QPushButton{border-image:url(:/images/tongzhou_shuru.png);}","QPushButton{border-image:url(:/images/lanya.png);}"};
    QVector<QString>out_put_labels={"光纤","同轴","蓝牙"};
    for (int i=0;i<3;i++) {
        QPushButton *out_put_btn = new QPushButton(this);
        out_put_btn->move(8,50+33*i);
        out_put_btn->resize(32,32);
        out_put_btn->setStyleSheet(out_put_titles[i]);


    }

}
