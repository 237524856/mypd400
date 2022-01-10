
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


    QLabel *dianping = new QLabel(this);
    dianping->resize(26,12);
    dianping->move(105,148);
    dianping->setText("主音源");
    dianping->setStyleSheet("font-size:9px;color:rgb(113,113,113);qproperty-alignment: AlignCenter;");

    QCheckBox *didianping_btn = new QCheckBox(back_left_image);
    didianping_btn->resize(64,28);
    didianping_btn->move(86,164);

    didianping_btn->setStyleSheet(
                "QCheckBox::indicator{width: 64px;height: 28px;color:rgb(255, 0, 0);}"
                "QCheckBox::indicator:unchecked{border-image:url(:images/dianyuan_yinyuan_btn.png) 0 192 0 0;}"
                "QCheckBox::indicator:unchecked:hover{border-image:url(:images/dianyuan_yinyuan_btn.png) 0 128 0 64;}"
                "QCheckBox::indicator:checked{border-image:url(:images/dianyuan_yinyuan_btn.png) 0 64 0 128;}");
    connect(didianping_btn, SIGNAL(clicked(bool)), this, SLOT(dianpin_click_status(bool)));

    QLabel *dianping_label = new QLabel(didianping_btn);
    dianping_label->resize(64,28);
    dianping_label->move(0,0);
    dianping_label->setText("低电平");
    dianping_label->setStyleSheet("qproperty-alignment: AlignCenter;font-size:12px;color:rgb(255,255,255)");

    QCheckBox *guanbi_btn = new QCheckBox(back_left_image);
    guanbi_btn->resize(64,28);
    guanbi_btn->move(86,385);
    guanbi_btn->setStyleSheet(
                "QCheckBox::indicator{width: 64px;height: 28px;color:rgb(255, 0, 0);}"
                "QCheckBox::indicator:unchecked{border-image:url(:images/dianyuan_yinyuan_btn.png) 0 192 0 0;}"
                "QCheckBox::indicator:unchecked:hover{border-image:url(:images/dianyuan_yinyuan_btn.png) 0 128 0 64;}"
                "QCheckBox::indicator:checked{border-image:url(:images/dianyuan_yinyuan_btn.png) 0 64 0 128;}");
    connect(guanbi_btn, SIGNAL(clicked(bool)), this, SLOT(guanbi_click_status(bool)));

    QLabel *guanbi_label = new QLabel(guanbi_btn);
    guanbi_label->resize(64,28);
    guanbi_label->move(0,0);
    guanbi_label->setText("关闭");
    guanbi_label->setStyleSheet("qproperty-alignment: AlignCenter;font-size:12px;color:rgb(255,255,255)");

    QLabel *guanbi = new QLabel(this);
    guanbi->resize(64,12);
    guanbi->move(86,417);
    guanbi->setText("辅助音源");
    guanbi->setStyleSheet("font-size:9px;color:rgb(113,113,113);qproperty-alignment: AlignCenter;");


    QLabel *main_vol_bgimg = new QLabel(this);
    main_vol_bgimg->move(78,199);
    main_vol_bgimg->resize(78,176);
    main_vol_bgimg->setPixmap(QPixmap(":images/main_vol_bgimg.png"));

    QLabel *main_vol_label = new QLabel(main_vol_bgimg);
    main_vol_label->resize(78,12);
    main_vol_label->move(0,18);
    main_vol_label->setText("总音量");
    main_vol_label->setStyleSheet("font-size:9px;color:rgb(113,113,113);qproperty-alignment: AlignCenter;");

    QLabel *main_vol_num = new QLabel(main_vol_bgimg);
    main_vol_num->resize(78,199);
    main_vol_num->move(0,0);
    main_vol_num->setText("50");
    main_vol_num->setStyleSheet("font-size:21px;color:rgb(113,113,113);qproperty-alignment: AlignCenter;");

    QCheckBox *mute_btn = new QCheckBox(main_vol_bgimg);
    mute_btn->resize(28,28);
    mute_btn->move(26,119);
    mute_btn->setStyleSheet(
                "QCheckBox::indicator{width: 28px;height: 28px;color:rgb(255, 0, 0);}"
                "QCheckBox::indicator:unchecked{border-image:url(:images/vlume_mute.png) 0 196 0 0;}"
                "QCheckBox::indicator:unchecked:hover{border-image:url(:images/vlume_mute.png) 0 128 0 64;}"
                "QCheckBox::indicator:checked{border-image:url(:images/vlume_mute.png) 0 64 0 128;}");
    connect(mute_btn, SIGNAL(clicked(bool)), this, SLOT(volue_mute_btn_click_status(bool)));


    for (int i=0;i<2;i++) {
        QCheckBox *xiaolaba_btn = new QCheckBox(this);
        xiaolaba_btn->resize(20,20);
        xiaolaba_btn->move(37+ i*145,126 );
        xiaolaba_btn->setStyleSheet(
                    "QCheckBox::indicator{width: 20px;height: 20px;color:rgb(255, 0, 0);}"
                    "QCheckBox::indicator:unchecked{border-image:url(:images/xiaolaba_btn.png) 0 140 0 0;}"
                    "QCheckBox::indicator:unchecked:hover{border-image:url(:images/xiaolaba_btn.png) 0 120 0 20;}"
                    "QCheckBox::indicator:checked{border-image:url(:images/xiaolaba_btn.png) 0 100 0 40;}");
        connect(xiaolaba_btn, SIGNAL(clicked(bool)), this, SLOT(volue_mute_btn_click_status(bool)));
    }


    m_buttonGroup = new QButtonGroup();
}
void car_midView::dianpin_click_status(bool is_open){

}
void car_midView::guanbi_click_status(bool is_open){

}
