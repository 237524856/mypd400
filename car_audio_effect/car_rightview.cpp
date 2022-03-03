
#pragma once
#pragma execution_character_set("utf-8")
#include "car_rightview.h"
#include <QLabel>
#include "fenpinqi_view.h"
#include "myline_edit.h"
#include <QDebug>
#include "common_datasource.h"

car_rightView::car_rightView(QWidget *parent) : QWidget(parent)
{

}
void car_rightView::createUI(){

    QVector<QString> mytitles={"分频器","延时","相位","音量(dB)","静音"};
    for (int i=0;i<mytitles.count();i++) {
        QLabel *title_label = new QLabel(this);
        title_label->resize(42,175/4);
        title_label->move(175/4*i+10,0);
        title_label->setText(mytitles.at(i));
        title_label->setStyleSheet("font-size:10px;color:rgb(255,255,255);qproperty-alignment: AlignCenter;font-family:'Source Han Sans CN Medium'");

    }


    for (int i=0;i<18;i++) {

        //分频器
        fenpinqi_view *fenpinView = new fenpinqi_view(this);
        fenpinView->resize(23,17);
        fenpinView->move(10,82+9+ (19+17)*i);

        //延时
        myline_edit *edit = new myline_edit(this);
        edit->resize(43,17);
        edit->move(33+27,82+9+i*36);
        qDebug()<<"xxxx"<<volumes;
        edit->setText(QString::number(volumes.at(i),10));
        connect(edit, SIGNAL(block_key_up(int)), this, SLOT(myline_edit_keyup(int)));
        connect(edit, SIGNAL(block_key_up(int)), this, SLOT(myline_edit_keydown(int)));

//        if(i>2 ){
//            QPushButton *ch_shuru_btn = new QPushButton(this);
//            ch_shuru_btn->resize(55,20);
//            ch_shuru_btn->move(180-22-60,51+i*34);
//            ch_shuru_btn->setText("前左高频");
//            ch_shuru_btn->setStyleSheet("color:white;background-color:transparent;border: 2px solid rgb(57,57,57);font-size:9px;font-family:'Source Han Sans CN Medium'");
//            connect(ch_shuru_btn, SIGNAL(clicked()), this, SLOT(shuru_click()));
//        }


//        QCheckBox *xiangwei_btn = new QCheckBox(this);
//        xiangwei_btn->resize(20,20);
//        xiangwei_btn->move(235,51+i*34);
//        xiangwei_btn->setStyleSheet(
//                    "QCheckBox::indicator{width:20px;height:20px;color:rgb(255, 0, 0);}"
//                    "QCheckBox::indicator:unchecked{border-image:url(:images/yinliang_jia.png) 0 140 0 0;}"
//                    "QCheckBox::indicator:unchecked:hover{border-image:url(:images/yinliang_jia.png) 0 120 0 20;}"
//                    "QCheckBox::indicator:checked{border-image:url(:images/yinliang_jia.png) 0 60 0 80;}");
//        connect(xiangwei_btn, SIGNAL(clicked(bool)), this, SLOT(volue_mute_btn_click_status(bool)));

//        QCheckBox *mute_btn = new QCheckBox(this);
//        mute_btn->resize(20,20);
//        mute_btn->move(322,51+i*34);
//        mute_btn->setStyleSheet(
//                    "QCheckBox::indicator{width:20px;height:20px;color:rgb(255, 0, 0);}"
//                    "QCheckBox::indicator:unchecked{border-image:url(:images/main_mute.png) 0 140 0 0;}"
//                    "QCheckBox::indicator:unchecked:hover{border-image:url(:images/main_mute.png) 0 120 0 20;}"
//                    "QCheckBox::indicator:checked{border-image:url(:images/main_mute.png) 0 60 0 80;}");
//        connect(mute_btn, SIGNAL(clicked(bool)), this, SLOT(volue_mute_btn_click_status(bool)));

//        myline_edit *edit = new myline_edit(this);
//        edit->resize(20,20);
//        edit->move(280,51+i*34);
//        qDebug()<<"xxxx"<<volumes;
//        edit->setText(QString::number(volumes.at(i),10));
//        connect(edit, SIGNAL(block_key_up(int)), this, SLOT(myline_edit_keyup(int)));
//        connect(edit, SIGNAL(block_key_up(int)), this, SLOT(myline_edit_keydown(int)));
    }
}
