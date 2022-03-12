#include "custom_list_item.h"
#include <QDebug>

custom_list_item::custom_list_item(QWidget *parent) : QWidget(parent)
{
    this->setAttribute(Qt::WA_StyledBackground,true);
    m_subView = new sub_show_list_view();
    m_subView->resize(78,24*6+2);
    m_subView->move(20,20);
}
void custom_list_item::enterEvent(QEvent *qevent){

    qDebug()<<"eeeeeeeeeeeeeeeee";
    m_str_name = this->objectName();

    this->setStyleSheet("background-color:rgb(49,145,255)");
    QPoint GlobalPoint(this->mapToGlobal(QPoint(0, 0)));//获取控件在窗体中的坐标
    int x = GlobalPoint.x();
    int y = GlobalPoint.y();
    m_subView->move(x+78,y);
    m_subView->setFocus();


        m_subView->show();



    emit item_enter();
}

void custom_list_item::leaveEvent(QEvent *qevent){

    emit item_leave();


    qDebug()<<"lllllllllllllllll";
    if(m_str_name!=m_str_leave_name){
        m_subView->hide();
    }else{

    }
    m_str_leave_name = this->objectName();

    this->setStyleSheet("background-color:rgb(62,62,62)");
}
