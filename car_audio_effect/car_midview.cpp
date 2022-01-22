
#pragma once
#pragma execution_character_set("utf-8")
#include "car_midview.h"
#include <QCheckBox>
#include <QButtonGroup>
#include <QDebug>
car_midView::car_midView(QWidget *parent) : QWidget(parent)
{

}
void car_midView::createUI(){

    m_back_left_image = new QLabel(this);
    m_back_left_image->move(0,0);
    m_back_left_image->resize(this->width(),this->height());
    m_back_left_image->setPixmap(QPixmap(":images/mid_bgimage.png"));


    m_top_image = new QLabel(this);
    m_top_image->move((this->width()-207)/2,30);
    m_top_image->resize(207,132);
    m_top_image->setPixmap(QPixmap(":images/mid_top.png"));


    QLabel *dianping = new QLabel(this);
    dianping->resize(26,12);
    dianping->move(105,148);
    dianping->setText("主音源");
    dianping->setStyleSheet("font-size:9px;color:rgb(113,113,113);qproperty-alignment: AlignCenter;");

    QCheckBox *didianping_btn = new QCheckBox(m_back_left_image);
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

    QCheckBox *guanbi_btn = new QCheckBox(m_back_left_image);
    guanbi_btn->resize(64,28);
    guanbi_btn->move(86,385);
    guanbi_btn->setStyleSheet(
                "QCheckBox::indicator{width: 64px;height: 28px;color:rgb(255, 0, 0);}"
                "QCheckBox::indicator:unchecked{border-image:url(:images/dianyuan_yinyuan_btn.png) 0 192 0 0;}"
                "QCheckBox::indicator:unchecked:hover{border-image:url(:images/dianyuan_yinyuan_btn.png) 0 128 0 64;}"
                "QCheckBox::indicator:checked{border-image:url(:images/dianyuan_yinyuan_btn.png) 0 64 0 128;}");
    connect(guanbi_btn, SIGNAL(stateChanged(int)), this, SLOT(guanbi_btn_click(int)));

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
    main_vol_num->setStyleSheet("font-family:'SourceHanSansCN Medium';font-size:21px;color:rgb(113,113,113);qproperty-alignment: AlignCenter;");

    //静音的按钮
    QCheckBox *mute_btn = new QCheckBox(main_vol_bgimg);
    mute_btn->resize(28,28);
    mute_btn->move(26,119);
    mute_btn->setStyleSheet(
                "QCheckBox::indicator{width: 28px;height: 28px;color:rgb(255, 0, 0);}"
                "QCheckBox::indicator:unchecked{border-image:url(:images/vlume_mute.png) 0 196 0 0;}"
                "QCheckBox::indicator:unchecked:hover{border-image:url(:images/vlume_mute.png) 0 128 0 64;}"
                "QCheckBox::indicator:checked{border-image:url(:images/vlume_mute.png) 0 64 0 128;}");
    connect(mute_btn, SIGNAL(stateChanged(int)), this, SLOT(mute_click(int)));




    //各种按钮
    m_buttonGroup = new QButtonGroup();
    m_buttonGroup->setExclusive(true);

    for (int j=0;j<2;j++) {
        for (int i=0;i<2;i++) {
            QCheckBox *xiaolaba_btn = new QCheckBox(this);
            xiaolaba_btn->resize(20,20);
            xiaolaba_btn->move(25+ i*165,126 +120*j);
            if(i==0){
                xiaolaba_btn->setStyleSheet(
                            "QCheckBox::indicator{width: 20px;height: 20px;color:rgb(255, 0, 0);}"
                            "QCheckBox::indicator:unchecked{border-image:url(:images/xiaolaba_btn.png) 0 140 0 0;}"
                            "QCheckBox::indicator:unchecked:hover{border-image:url(:images/xiaolaba_btn.png) 0 120 0 20;}"
                            "QCheckBox::indicator:checked{border-image:url(:images/xiaolaba_btn.png) 0 60 0 80;}");
            }else if(i==1){
                xiaolaba_btn->setStyleSheet(
                            "QCheckBox::indicator{width: 20px;height: 20px;color:rgb(255, 0, 0);}"
                            "QCheckBox::indicator:unchecked{border-image:url(:images/xiaolaba_left.png) 0 140 0 0;}"
                            "QCheckBox::indicator:unchecked:hover{border-image:url(:images/xiaolaba_left.png) 0 120 0 20;}"
                            "QCheckBox::indicator:checked{border-image:url(:images/xiaolaba_left.png) 0 60 0 80;}");
            }

            connect(xiaolaba_btn, SIGNAL(clicked(bool)), this, SLOT(volue_mute_btn_click_status(bool)));
            m_buttonGroup->addButton(xiaolaba_btn);



            QCheckBox *zhonglaba_btn = new QCheckBox(this);
            zhonglaba_btn->resize(25,25);
            zhonglaba_btn->move(22+ i*168,126+28 +120*j);
            if(i==0){
                zhonglaba_btn->setStyleSheet(
                            "QCheckBox::indicator{width: 25px;height: 25px;color:rgb(255, 0, 0);}"
                            "QCheckBox::indicator:unchecked{border-image:url(:images/zhonglaba_btn.png) 0 175 0 0;}"
                            "QCheckBox::indicator:unchecked:hover{border-image:url(:images/zhonglaba_btn.png) 0 150 0 25;}"
                            "QCheckBox::indicator:checked{border-image:url(:images/zhonglaba_btn.png) 0 75 0 100;}");
            }else{
                zhonglaba_btn->setStyleSheet(
                            "QCheckBox::indicator{width: 25px;height: 25px;color:rgb(255, 0, 0);}"
                            "QCheckBox::indicator:unchecked{border-image:url(:images/zhonglaba_left.png) 0 175 0 0;}"
                            "QCheckBox::indicator:unchecked:hover{border-image:url(:images/zhonglaba_left.png) 0 150 0 25;}"
                            "QCheckBox::indicator:checked{border-image:url(:images/zhonglaba_left.png) 0 75 0 100;}");
            }

            connect(zhonglaba_btn, SIGNAL(clicked(bool)), this, SLOT(volue_mute_btn_click_status(bool)));
            m_buttonGroup->addButton(zhonglaba_btn);


            QCheckBox *dalaba_zhongshangbtn = new QCheckBox(this);
            dalaba_zhongshangbtn->resize(30,30);
            dalaba_zhongshangbtn->move(22+ i*165,126+28+28 +120*j);
            if(i==0){
                dalaba_zhongshangbtn->setStyleSheet(
                            "QCheckBox::indicator{width: 30px;height: 30px;color:rgb(255, 0, 0);}"
                            "QCheckBox::indicator:unchecked{border-image:url(:images/laba_zhongshang.png) 0 210 0 0;}"
                            "QCheckBox::indicator:unchecked:hover{border-image:url(:images/laba_zhongshang.png) 0 180 0 30;}"
                            "QCheckBox::indicator:checked{border-image:url(:images/laba_zhongshang.png) 0 90 0 120;}");
            }else{
                dalaba_zhongshangbtn->setStyleSheet(
                            "QCheckBox::indicator{width: 30px;height: 30px;color:rgb(255, 0, 0);}"
                            "QCheckBox::indicator:unchecked{border-image:url(:images/laba_zhongshang_left.png) 0 210 0 0;}"
                            "QCheckBox::indicator:unchecked:hover{border-image:url(:images/laba_zhongshang_left.png) 0 180 0 30;}"
                            "QCheckBox::indicator:checked{border-image:url(:images/laba_zhongshang_left.png) 0 90 0 120;}");
            }

            connect(dalaba_zhongshangbtn, SIGNAL(clicked(bool)), this, SLOT(volue_mute_btn_click_status(bool)));
            m_buttonGroup->addButton(dalaba_zhongshangbtn);

            //最大的喇叭
            if(j==0){
                QCheckBox *dalaba_btn = new QCheckBox(this);
                dalaba_btn->resize(34,34);
                dalaba_btn->move(19+ i*165,367);
                if(i==0){
                    dalaba_btn->setStyleSheet(
                                "QCheckBox::indicator{width: 34px;height: 34px;color:rgb(255, 0, 0);}"
                                "QCheckBox::indicator:unchecked{border-image:url(:images/dalaba_btn.png) 0 238 0 0;}"
                                "QCheckBox::indicator:unchecked:hover{border-image:url(:images/dalaba_btn.png) 0 204 0 34;}"
                                "QCheckBox::indicator:checked{border-image:url(:images/dalaba_btn.png) 0 102 0 136;}");
                }else{
                    dalaba_btn->setStyleSheet(
                                "QCheckBox::indicator{width: 34px;height: 34px;color:rgb(255, 0, 0);}"
                                "QCheckBox::indicator:unchecked{border-image:url(:images/dalaba_btn_left.png) 0 238 0 0;}"
                                "QCheckBox::indicator:unchecked:hover{border-image:url(:images/dalaba_btn_left.png) 0 204 0 34;}"
                                "QCheckBox::indicator:checked{border-image:url(:images/dalaba_btn_left.png) 0 102 0 136;}");
                }

                connect(dalaba_btn, SIGNAL(clicked(bool)), this, SLOT(volue_mute_btn_click_status(bool)));
                m_buttonGroup->addButton(dalaba_btn);
            }

        }
    }


    QCheckBox *top_btn1 = new QCheckBox(this);
    top_btn1->resize(20,20);
    top_btn1->move(84,126);
    top_btn1->setStyleSheet(
                "QCheckBox::indicator{width: 20px;height: 20px;color:rgb(255, 0, 0);}"
                "QCheckBox::indicator:unchecked{border-image:url(:images/xiaolaba_btn_bottom.png) 0 140 0 0;}"
                "QCheckBox::indicator:unchecked:hover{border-image:url(:images/xiaolaba_btn_bottom.png) 0 120 0 20;}"
                "QCheckBox::indicator:checked{border-image:url(:images/xiaolaba_btn_bottom.png) 0 60 0 80;}");
    connect(top_btn1, SIGNAL(clicked(bool)), this, SLOT(volue_mute_btn_click_status(bool)));
    m_buttonGroup->addButton(top_btn1);

    QCheckBox *top_btn2 = new QCheckBox(this);
    top_btn2->resize(25,25);
    top_btn2->move(135,122);
    top_btn2->setStyleSheet(
                "QCheckBox::indicator{width: 25px;height: 25px;color:rgb(255, 0, 0);}"
                "QCheckBox::indicator:unchecked{border-image:url(:images/zhonglaba_btn_bottom.png) 0 175 0 0;}"
                "QCheckBox::indicator:unchecked:hover{border-image:url(:images/zhonglaba_btn_bottom.png) 0 150 0 25;}"
                "QCheckBox::indicator:checked{border-image:url(:images/zhonglaba_btn_bottom.png) 0 75 0 100;}");
    connect(top_btn2, SIGNAL(clicked(bool)), this, SLOT(volue_mute_btn_click_status(bool)));
    m_buttonGroup->addButton(top_btn2);




}

void car_midView::guanbi_btn_click(int status){

    if(status==0){
      m_top_image->setPixmap(QPixmap(":images/mid_top.png"));
      m_back_left_image->setPixmap(QPixmap(":images/mid_bgimage.png"));
    }else{
      m_top_image->setPixmap(QPixmap(":images/mid_top_high.png"));
      m_back_left_image->setPixmap(QPixmap(":images/mid_bgimage_high.png"));
    }
   qDebug()<<"xxxxxx"<<status;
}

void car_midView::mute_click(int status){

    qDebug()<<"xxxxxx"<<status;

}
void car_midView::dianpin_click_status(bool is_open){

}
void car_midView::guanbi_click_status(bool is_open){

}
