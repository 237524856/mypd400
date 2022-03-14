#include "sub_custom_list_item.h"

sub_custom_list_item::sub_custom_list_item(QWidget *parent) : QWidget(parent)
{

}
void sub_custom_list_item::enterEvent(QEvent *){

    this->setStyleSheet("background-color:rgb(49,145,255)");
}
void sub_custom_list_item::leaveEvent(QEvent *){

    this->setStyleSheet("background-color:rgb(62,62,62)");
}
void sub_custom_list_item::mousePressEvent(QMouseEvent *qevent)            //鼠标按下事件
{
    this->hide();

}
void sub_custom_list_item::mouseReleaseEvent(QMouseEvent *qevent)         //鼠标释放事件
{

}
void sub_custom_list_item::mouseMoveEvent(QMouseEvent *qevent)            //鼠标移动事件
{

}
