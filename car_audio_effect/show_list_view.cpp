
#pragma once
#pragma execution_character_set("utf-8")
#include "show_list_view.h"
#include <QDebug>
#include "QListWidgetItem"
#include <QHBoxLayout>
#include "custom_list_item.h"

show_list_view::show_list_view(QWidget *parent) : QDialog(parent)
{
    //设置标题栏隐藏
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
   // this->setStyleSheet("background:red");
    this->setFocus();

    is_enter =false;
    //m_subView->createUI();

}
show_list_view::~show_list_view(){

    qDebug()<<"9999999999";
}
void show_list_view::createUI(){

    QVector<QString> list_title ={"空","前置","后置","中置","超低","环绕"};
    m_listWidget_default = new QListWidget(this);
    m_listWidget_default->resize(this->width(),this->height());
    m_listWidget_default->move(0 ,0);
    for (int i =0;i<list_title.count();i++) {
        QListWidgetItem * IconItem = new QListWidgetItem(m_listWidget_default);
        IconItem->setSizeHint(QSize(70,24));

        //m_listWidget_default->insertItem(list_title.count(),IconItem);
        custom_list_item *custom_item = new custom_list_item(m_listWidget_default);
        custom_item->setObjectName(QString::number(i+100,10));
        custom_item->setStyleSheet("background-color:rgb(62,62,62)");
        connect(custom_item, SIGNAL(item_enter()), this, SLOT(item_enter_clike()));
        connect(custom_item, SIGNAL(item_leave()), this, SLOT(item_leave_clike()));

        QLabel *lbl2 = new QLabel(custom_item);
        lbl2->setFixedSize(10, 24);
        //lbl2->setText(list_title.at(i));
        lbl2->setStyleSheet("color:rgb(27,27,27);font-size:10px;font-family:'Source Han Sans CN Medium'");

        QLabel *lbl3 = new QLabel(custom_item);
        //lbl3->setFixedSize(20, 32);
        lbl3->setText(list_title.at(i));
        lbl3->setStyleSheet("color:rgb(255,255,255);font-size:10px;font-family:'Source Han Sans CN Medium'");
        QHBoxLayout *horLayout = new QHBoxLayout;
        horLayout->setContentsMargins(0, 0, 0, 0);
        horLayout->setMargin(0);
        horLayout->setSpacing(0);
        horLayout->addWidget(lbl2);
        horLayout->addWidget(lbl3);
        custom_item->setLayout(horLayout);

        m_listWidget_default->setItemWidget(IconItem,custom_item);
    }


    m_listWidget_default->setStyleSheet(

                "QListWidget{background-color:transparent;border:1px solid white; color:rgb(27,27,27);font-size:10px;font-family:'Source Han Sans CN Medium'}"

                "QListWidget::Item{border-bottom: 1px solid black;height:10px;}"



                "QScrollBar:vertical{width:8px;background-color:rgb(45,45,45);border-radius:4px;margin-top:20px;margin-bottom:20px;}"

                "QScrollBar::handle:vertical{background-color:rgb(245,179,53);width:8px;border-radius:4px;}"

                "QScrollBar::add-page:vertical,QScrollBar::sub-page:vertical{background:rgba(45,45,45,100%);border-radius:4px;}"

                "QScrollBar::sub-line:vertical{height:0px;width:0px;subcontrol-position:top;}"
                );

    m_listWidget_default->setMouseTracking(true);


    connect(m_listWidget_default,SIGNAL(currentRowChanged(int)),this,SLOT(audio_click(int)));
    connect(m_listWidget_default,SIGNAL(itemEntered(QListWidgetItem*)),this,SLOT(select_item(QListWidgetItem*)));
}

void show_list_view::audio_click(int audio_index){


    qDebug()<<"xxxx"<<audio_index;
    this->hide();
}
void show_list_view::select_item(QListWidgetItem* item){

     //qDebug()<<"JINRU123456"<<item;
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
    qDebug()<<"123456";
}
void show_list_view::mouseReleaseEvent(QMouseEvent *qevent)
{
    //设置鼠标为未被按下
    //mouse_press = false;
}
void show_list_view::enterEvent(QEvent *qevent){


}

void show_list_view::leaveEvent(QEvent *qevent){

    //qDebug()<<"LIKAI123456";
}

void show_list_view::focusOutEvent(QFocusEvent *e){

    if(is_enter ==false)
    this->hide();
}
void show_list_view::item_enter_clike(){

    is_enter =true;
}
void show_list_view::item_leave_clike(){
    is_enter =false;
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
