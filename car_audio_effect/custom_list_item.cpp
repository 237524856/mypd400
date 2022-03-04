#include "custom_list_item.h"
#include <QDebug>

custom_list_item::custom_list_item(QWidget *parent) : QWidget(parent)
{
this->setAttribute(Qt::WA_StyledBackground,true);
}
void custom_list_item::enterEvent(QEvent *qevent){

qDebug()<<"eeeeeeeeeeeeeeeee";
this->setStyleSheet("background-color:rgb(0,255,0)");

}

void custom_list_item::leaveEvent(QEvent *qevent){

    qDebug()<<"lllllllllllllllll";
    this->setStyleSheet("background-color:rgb(255,0,0)");
}
