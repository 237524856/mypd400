#include "custom_list_item.h"
#include <QDebug>
#include <QThread>

custom_list_item::custom_list_item(QWidget *parent) : QWidget(parent)
{
    this->setAttribute(Qt::WA_StyledBackground,true);
    m_subView = new sub_show_list_view();
    m_subView->resize(76,24*12+2);
    m_subView->move(20,20);
    m_pTimer = new QTimer(this);
    connect(m_pTimer, SIGNAL(timeout()), this, SLOT(handleTimeout()));
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
    m_subView->is_sub_enter =true;

    m_pTimer->start(50);
    emit item_enter();
}

void custom_list_item::leaveEvent(QEvent *qevent){

    emit item_leave();

    qDebug()<<"lllllllllllllllll";

    m_subView->is_sub_enter =false;


}
void custom_list_item::handleTimeout(){

    if(!m_subView->is_sub_enter){

        m_subView->hide();
        this->setStyleSheet("background-color:rgb(62,62,62)");
    }

    //qDebug()<<"llllxxxxxxxx555555lllllllllllll";
}
