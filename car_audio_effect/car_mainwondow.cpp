
#pragma once
#pragma execution_character_set("utf-8")
#include "car_mainwondow.h"
#include <QPushButton>
#include <QApplication>
#include "QDesktopWidget"
#include <QFontDatabase>
#include <QDebug>
#include <QStandardPaths>


car_mainWondow::car_mainWondow(QWidget *parent) : basewindow(parent)
{

    setFixedSize(1008,723);
    QFontDatabase::addApplicationFont(":/image/MBS_400/SourceHanSansCN Medium.ttf");
    createUI();
}

void car_mainWondow::createUI(){

    QLabel *back_left_image = new QLabel(this);
    back_left_image->move(0,723-700);
    back_left_image->resize(this->width(),700);
    back_left_image->setPixmap(QPixmap(":images/bg_image.png"));

//左边的视图
    m_leftView = new car_leftView(this);
    m_leftView->resize(356,700);
    m_leftView->move(0,23);
    m_leftView->createUI();
    m_leftView->show();


    //中间的视图
    m_mid_midView = new car_midView(this);
    m_mid_midView->move(360,161);
    m_mid_midView->resize(235,491);
    m_mid_midView->createUI();
    m_mid_midView->show();


    status = new QStatusBar(this);

    menu[0] = new QMenu("名称");
    menu[0]->addAction("编辑");
    menu[0]->addAction("查看");
    menu[0]->addAction("工具");

    act[0] = new QAction("新建",this);
    act[0]->setShortcut(Qt::CTRL | Qt::Key_A );
    act[0]->setToolTip("这是");

    act[1] = new QAction("打开",this);
    act[1]->setCheckable(true);

    menu[1] = new QMenu("选项");
    menu[1]->addAction(act[0]);
    menu[1]->addAction(act[1]);

    menu[2] = new QMenu("加密");
    menu[2]->addAction("打印设置");
    menu[2]->addMenu(menu[1]);

    menuBar = new QMenuBar(this);
    menuBar->addMenu(menu[0]);
    menuBar->addMenu(menu[1]);
    menuBar->addMenu(menu[2]);

    menuBar->setStyleSheet("QMenuBar{background-color:red;}");
    menuBar->setGeometry(61,0,220,23);


    connect(menuBar,SIGNAL(triggered(QAction*)),this,SLOT(m_trigerMenu(QAction*)));
}
void car_mainWondow::m_trigerMenu(QAction* act)
{


    m_effect_mainView.show();
//    if(act->text() == "新建")
//    {
        qDebug()<<"新建菜单被按下";
//    }
}
