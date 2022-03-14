#pragma once
#pragma execution_character_set("utf-8")
#include "custom_list_item.h"
#include <QDebug>
#include <QThread>

custom_list_item::custom_list_item(QWidget *parent) : QWidget(parent)
{
    this->setAttribute(Qt::WA_StyledBackground,true);
    m_subView = new sub_show_list_view();
    m_subView->move(20,20);

    //根据不同的列切换不同的
    m_pTimer = new QTimer(this);
    connect(m_pTimer, SIGNAL(timeout()), this, SLOT(handleTimeout()));
}

void custom_list_item::createUI(){
    QVector<QString> list_title ={"左","高频","中频","低频","中低频","全频","右","高频","中频","低频","中低频","全频"};
        if(this->objectName()=="空"){

        }else if(this->objectName()=="前置"){
            m_subView->resize(76,24*12+2);
            QVector<QString> list_title ={"左","高频","中频","低频","中低频","全频","右","高频","中频","低频","中低频","全频"};
            m_subView->createUI(list_title);

        }else if(this->objectName()=="后置"){
            m_subView->resize(76,24*12+2);
            QVector<QString> list_title ={"左","高频","中频","低频","中低频","全频","右","高频","中频","低频","中低频","全频"};
            m_subView->createUI(list_title);

        }else if(this->objectName()=="中置"){
            m_subView->resize(76,24*4+2);
            QVector<QString> list_title ={"前中置","后中置","前中置高频","后中置高频"};
            m_subView->createUI(list_title);

        }else if(this->objectName()=="超低"){
            m_subView->resize(76,24*3+2);
            QVector<QString> list_title ={"左超低","右超低","超低"};
            m_subView->createUI(list_title);

        }else if(this->objectName()=="环绕"){
            m_subView->resize(76,24*2+2);
            QVector<QString> list_title ={"左环绕","右环绕"};
            m_subView->createUI(list_title);
        }

}
void custom_list_item::enterEvent(QEvent *qevent){

    m_str_name = this->objectName();
    this->setStyleSheet("background-color:rgb(49,145,255)");
    QPoint GlobalPoint(this->mapToGlobal(QPoint(0, 0)));//获取控件在窗体中的坐标
    int x = GlobalPoint.x();
    int y = GlobalPoint.y();
    m_subView->move(x+78,y);
    m_subView->setFocus();

    m_subView->is_sub_enter =true;
    if(this->objectName()!="空")
    m_subView->show();
    m_pTimer->start(50);
    emit item_enter();
}

void custom_list_item::leaveEvent(QEvent *qevent){

    emit item_leave();


    m_subView->is_sub_enter =false;


}
void custom_list_item::handleTimeout(){

    if(!m_subView->is_sub_enter){

        m_subView->hide();
        this->setStyleSheet("background-color:rgb(62,62,62)");
    }

    //qDebug()<<"llllxxxxxxxx555555lllllllllllll";
}
