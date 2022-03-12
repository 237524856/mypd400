#include "sub_show_list_view.h"
#include <QDebug>

sub_show_list_view::sub_show_list_view(QWidget *parent) : QDialog(parent)
{

    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    is_sub_enter = false;
    this->setStyleSheet("background:red");
}
void sub_show_list_view::enterEvent(QEvent *qevent){

    //this->show();
    is_sub_enter = true;
    qDebug()<<"eeekkkkeeeeeeeeeeeeee";


}

void sub_show_list_view::leaveEvent(QEvent *qevent){


    //this->hide();
    is_sub_enter = false;
    qDebug()<<"lllllllkkkkkkllllllllll";

}
