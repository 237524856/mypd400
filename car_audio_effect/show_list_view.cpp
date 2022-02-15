
#pragma once
#pragma execution_character_set("utf-8")
#include "show_list_view.h"
#include <QDebug>

show_list_view::show_list_view(QWidget *parent) : QDialog(parent)
{
    //设置标题栏隐藏
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    this->setStyleSheet("background:red");
    this->setFocus();

}

void show_list_view::createUI(){
    QVector<QString> list_title ={"空","前置","后置","中置","超低","环绕"};

    m_listWidget_default = new QListWidget(this);
    m_listWidget_default->resize(this->width(),this->height());
    m_listWidget_default->move(0 ,0);
    for (int i =0;i<list_title.count();i++) {
        m_listWidget_default->insertItem(0,list_title.at(i));
    }


    m_listWidget_default->setStyleSheet(

                "QListWidget{background-color:rgb(11,11,11);border:0px solid red; color:rgb(27,27,27);font-size:10px;font-family:'Source Han Sans CN Medium'}"

                "QListWidget::Item{color:rgb(175, 175, 175);height:20px;}"

                "QScrollBar:vertical{width:8px;background-color:rgb(45,45,45);border-radius:4px;margin-top:20px;margin-bottom:20px;}"

                "QScrollBar::handle:vertical{background-color:rgb(245,179,53);width:8px;border-radius:4px;}"

                "QScrollBar::add-page:vertical,QScrollBar::sub-page:vertical{background:rgba(45,45,45,100%);border-radius:4px;}"

                "QScrollBar::sub-line:vertical{height:0px;width:0px;subcontrol-position:top;}"
                );

    connect(m_listWidget_default,SIGNAL(currentRowChanged(int)),this,SLOT(audio_click(int)));
}

void show_list_view::audio_click(int audio_index){


    qDebug()<<"xxxx"<<audio_index;
    this->hide();
}

void show_list_view::mousePressEvent(QMouseEvent *qevent)
{


    if(qevent->button() == Qt::LeftButton)
    {
    //close();
    }
}
void show_list_view::mouseMoveEvent(QMouseEvent *qevent)
{
}
void show_list_view::mouseReleaseEvent(QMouseEvent *qevent)
{
    //设置鼠标为未被按下
    //mouse_press = false;
}
void show_list_view::focusOutEvent(QFocusEvent *e){

    this->hide();
}

//void show_list_view::okBtn_press()
//{
//    this->accept();
//}
//void show_list_view::cancleBtn_press()
//{
//     this->reject();
//}
//void show_list_view::closeBtn_press()
//{
//    close();
//}
