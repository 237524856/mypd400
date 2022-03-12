#include "sub_show_list_view.h"
#include <QDebug>

sub_show_list_view::sub_show_list_view(QWidget *parent) : QDialog(parent)
{

    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    is_sub_enter = false;
    this->setStyleSheet("background:red");



}
void sub_show_list_view::createUI(){

    QVector<QString> list_title ={"空","前置","后置","中置","超低","环绕"};
    m_listWidget_default = new QListWidget(this);
    m_listWidget_default->resize(this->width(),this->height());
    m_listWidget_default->move(0 ,0);
    m_listWidget_default->setStyleSheet(

                "QListWidget{background-color:transparent;border:1px solid white; color:rgb(27,27,27);font-size:10px;font-family:'Source Han Sans CN Medium'}"

                "QListWidget::Item{border-bottom: 1px solid black;height:10px;}"



                "QScrollBar:vertical{width:8px;background-color:rgb(45,45,45);border-radius:4px;margin-top:20px;margin-bottom:20px;}"

                "QScrollBar::handle:vertical{background-color:rgb(245,179,53);width:8px;border-radius:4px;}"

                "QScrollBar::add-page:vertical,QScrollBar::sub-page:vertical{background:rgba(45,45,45,100%);border-radius:4px;}"

                "QScrollBar::sub-line:vertical{height:0px;width:0px;subcontrol-position:top;}"
                );

    m_listWidget_default->setMouseTracking(true);

}
void sub_show_list_view::enterEvent(QEvent *qevent){

    //this->show();
    is_sub_enter = true;
    qDebug()<<"eeekkkkeeexeeeeeeeeeee";


}

void sub_show_list_view::leaveEvent(QEvent *qevent){


    //this->hide();
    is_sub_enter = false;
    qDebug()<<"lllllllkkkkkkllllllllll";

}
