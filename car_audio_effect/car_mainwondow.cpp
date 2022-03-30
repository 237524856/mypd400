
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
    QFontDatabase::addApplicationFont(":/images/SourceHanSansCN Medium.ttf");
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

    //右边的视图
    m_rightView = new car_rightView(this);
    m_rightView->resize(616,700);
    m_rightView->move(360+235,23);
    m_rightView->createUI();
    m_rightView->show();


    status = new QStatusBar(this);

    menu[0] = new QMenu("名称");
    menu[0]->addAction("编辑");
    menu[0]->addAction("查看");
    menu[0]->addAction("工具");

    act[0] = new QAction("混音音频",this);
    //act[0]->setShortcut(Qt::CTRL | Qt::Key_A );
    act[0]->setToolTip("这是");

    act[1] = new QAction("信号发生器",this);
    act[1]->setCheckable(true);

    act[2] = new QAction("输入联调设置",this);
    act[2]->setCheckable(true);

    act[3] = new QAction("输出联调设置",this);
    act[3]->setCheckable(true);

    menu[1] = new QMenu("选项");
    menu[1]->addAction(act[0]);
    menu[1]->addAction(act[1]);
    menu[1]->addAction(act[2]);
    menu[1]->addAction(act[3]);

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


    //m_effect_mainView.show();
    if(act->text() == "信号发生器")
    {
        m_signal_view.show();
        qDebug()<<"新建菜单被按下";
    }else if(act->text() == "混音音频")
    {
        mix_view.show();
        qDebug()<<"新建菜单被按下";
    }

    else{
        m_effect_mainView.show();
    }
}
