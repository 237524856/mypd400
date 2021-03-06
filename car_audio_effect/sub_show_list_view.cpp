#pragma once
#pragma execution_character_set("utf-8")
#include "sub_show_list_view.h"
#include <QDebug>
#include <QHBoxLayout>
#include "sub_custom_list_item.h"
#include "common_datasource.h"

sub_show_list_view::sub_show_list_view(QWidget *parent) : QDialog(parent)
{

    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    is_sub_enter = false;
    this->setStyleSheet("background:red");



}
void sub_show_list_view::createUI(const QVector<QString>list_title){

    m_listWidget_default = new QListWidget(this);
    m_listWidget_default->resize(this->width(),this->height());
    m_listWidget_default->move(0 ,0);
    for (int i =0;i<list_title.count();i++) {
        QListWidgetItem * IconItem = new QListWidgetItem(m_listWidget_default);
        IconItem->setSizeHint(QSize(70,24));
        //m_listWidget_default->insertItem(list_title.count(),IconItem);
        sub_custom_list_item *custom_item = new sub_custom_list_item(m_listWidget_default);
        //custom_item->setObjectName(QString::number(i+100,10));
        custom_item->setObjectName(list_title.at(i));
        custom_item->setStyleSheet("background-color:rgb(62,62,62)");
        connect(custom_item, SIGNAL(hide_show_view()), this, SLOT(item_hide_clike()));
        //connect(custom_item, SIGNAL(item_enter()), this, SLOT(item_enter_clike()));
        //connect(custom_item, SIGNAL(item_leave()), this, SLOT(item_leave_clike()));

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

}


void sub_show_list_view::enterEvent(QEvent *qevent){

    //this->show();
    is_sub_enter = true;
    //qDebug()<<"eeekkkkeeexeeeeeeeeeee";

}

void sub_show_list_view::leaveEvent(QEvent *qevent){

    //this->hide();
    is_sub_enter = false;
    //qDebug()<<"lllllllkkkkkkllllllllll";

}

void sub_show_list_view::item_hide_clike(){

    this->hide();
    m_overshow_list_view->hide();
    qDebug()<<"lllllllkkkkkkllllllllll";
}
