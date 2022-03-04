
#pragma once
#pragma execution_character_set("utf-8")
#include "car_rightview.h"
#include <QLabel>
#include <QCheckBox>
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


    for (int i=0;i<19;i++) {

        //分频器
        fenpinqi_view *fenpinView = new fenpinqi_view(this);
        fenpinView->resize(23,17);
        fenpinView->move(10,13+43+ (19+17)*i);

        //延时
        myline_edit *edit = new myline_edit(this);
        edit->resize(43,17);
        edit->move(33+27,13+43+i*36);
        qDebug()<<"xxxx"<<volumes;
        edit->setText(QString::number(volumes.at(i),10));
        connect(edit, SIGNAL(block_key_up(int)), this, SLOT(myline_edit_keyup(int)));
        connect(edit, SIGNAL(block_key_up(int)), this, SLOT(myline_edit_keydown(int)));
        //相位
        QCheckBox *xiangwei_btn = new QCheckBox(this);
        xiangwei_btn->resize(20,20);
        xiangwei_btn->move(33+27*2+43,10+43+i*36);
        xiangwei_btn->setStyleSheet(
                    "QCheckBox::indicator{width:20px;height:20px;color:rgb(255, 0, 0);}"
                    "QCheckBox::indicator:unchecked{border-image:url(:images/yinliang_jia.png) 0 140 0 0;}"
                    "QCheckBox::indicator:unchecked:hover{border-image:url(:images/yinliang_jia.png) 0 120 0 20;}"
                    "QCheckBox::indicator:checked{border-image:url(:images/yinliang_jia.png) 0 60 0 80;}");
        connect(xiangwei_btn, SIGNAL(clicked(bool)), this, SLOT(volue_mute_btn_click_status(bool)));

        //音量
        myline_edit *yinliang_edit = new myline_edit(this);
        yinliang_edit->resize(20,20);
        yinliang_edit->move(33+27*3+43+20,10+43+i*36);
        qDebug()<<"xxxx"<<volumes;
        yinliang_edit->setText(QString::number(volumes.at(i),10));
        connect(yinliang_edit, SIGNAL(block_key_up(int)), this, SLOT(myline_edit_keyup(int)));
        connect(yinliang_edit, SIGNAL(block_key_up(int)), this, SLOT(myline_edit_keydown(int)));


        //静音
        QCheckBox *mute_btn = new QCheckBox(this);
        mute_btn->resize(20,20);
        mute_btn->move(33+27*4+43+20*2,10+43+i*36);
        mute_btn->setStyleSheet(
                    "QCheckBox::indicator{width:20px;height:20px;color:rgb(255, 0, 0);}"
                    "QCheckBox::indicator:unchecked{border-image:url(:images/main_mute.png) 0 140 0 0;}"
                    "QCheckBox::indicator:unchecked:hover{border-image:url(:images/main_mute.png) 0 120 0 20;}"
                    "QCheckBox::indicator:checked{border-image:url(:images/main_mute.png) 0 60 0 80;}");
        connect(mute_btn, SIGNAL(clicked(bool)), this, SLOT(volue_mute_btn_click_status(bool)));

        //输出类型
        QPushButton *ch_shuchu_btn = new QPushButton(this);
        ch_shuchu_btn->resize(50,20);
        ch_shuchu_btn->move(33+27*5+43+20*3,10+43+i*36);
        ch_shuchu_btn->setText("前左高频");
        ch_shuchu_btn->setStyleSheet("color:white;background-color:transparent;border: 2px solid rgb(57,57,57);font-size:9px;font-family:'Source Han Sans CN Medium'");
        connect(ch_shuchu_btn, SIGNAL(clicked()), this, SLOT(shuchu_click()));

        QLabel *shuchu_lab = new QLabel(this);
        shuchu_lab->resize(30,32);
        shuchu_lab->move(33+27*6+43+20*3+50,10+43+i*36);
        shuchu_lab->setText("输出"+QString::number(i+1,10));
        shuchu_lab->setStyleSheet("color:white;background-color:transparent;font-size:9px;font-family:'Source Han Sans CN Medium'");

       //最右边的图片
        QPushButton *shuchu_img_btn = new QPushButton(this);
        shuchu_img_btn->resize(32,32);
        shuchu_img_btn->move(33+27*7+43+20*3+50,10+43+i*36);
        shuchu_img_btn->setStyleSheet("QPushButton{border-image:url(:images/right_shuru_img.png);}"
                                  );
//        "QPushButton:pressed{border-image:url(:/image/images/pd400_ba_hi_lig_btn.png);}"
//        "QPushButton:checked{border-image:url(:/image/images/pd400_ba_hi_lig_btn.png);}"
        //shuchu_img_btn->setStyleSheet("color:white;background-color:transparent;border: 2px solid rgb(57,57,57);font-size:9px;font-family:'Source Han Sans CN Medium'");
        connect(shuchu_img_btn, SIGNAL(clicked()), this, SLOT(shuchu_click()));


    }
}
void car_rightView::shuchu_click(){

}
