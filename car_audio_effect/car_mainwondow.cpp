
#pragma once
#pragma execution_character_set("utf-8")
#include "car_mainwondow.h"
#include <QDebug>


car_mainWondow::car_mainWondow(QWidget *parent) : basewindow(parent)
{

    setFixedSize(1023,737);
    createUI();
}

void car_mainWondow::createUI(){

    status = new QStatusBar(this);

    menu[0] = new QMenu("文件");
    menu[0]->addAction("编辑");
    menu[0]->addAction("查看");
    menu[0]->addAction("工具");

    act[0] = new QAction("新建",this);
    act[0]->setShortcut(Qt::CTRL | Qt::Key_A );
    act[0]->setToolTip("这是");

    act[1] = new QAction("打开",this);
    act[1]->setCheckable(true);

    menu[1] = new QMenu("保存");
    menu[1]->addAction(act[0]);
    menu[1]->addAction(act[1]);

    menu[2] = new QMenu("打印");
    menu[2]->addAction("打印设置");
    menu[2]->addMenu(menu[1]);

    menuBar = new QMenuBar(this);
    menuBar->addMenu(menu[0]);
    menuBar->addMenu(menu[1]);
    menuBar->addMenu(menu[2]);
    menuBar->setGeometry(0,0,this->width()-300,30);

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
