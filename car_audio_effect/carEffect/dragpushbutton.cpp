#include "dragpushbutton.h"
#include <QDebug>


dragpushbutton::dragpushbutton(QWidget *parent) : QPushButton(parent)
{

    this->setAttribute(Qt::WA_StyledBackground,true);
    this->setStyleSheet("color:white;background-color:rgb(255,0,0);border-radius:8px");
}
void dragpushbutton::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        this->raise(); //将此按钮移动到顶层显示
        this->pressPoint = event->pos();       
        emit btn_press_location(this->pos(),this->objectName());
    }
}

void dragpushbutton::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() == Qt::LeftButton){
        this->move(this->mapToParent(event->pos() - this->pressPoint));

        //防止按钮移出父窗口


            if(this->mapToParent(this->rect().topLeft()).x() <= 0){
                this->move(0, this->pos().y());
            }
            if(this->mapToParent(this->rect().bottomRight()).x() >= this->parentWidget()->rect().width()){
                this->move(this->parentWidget()->rect().width() - this->width(), this->pos().y());
            }
            if(this->mapToParent(this->rect().topLeft()).y() <= 0){
                this->move(this->pos().x(), 0);
            }
            if(this->mapToParent(this->rect().bottomRight()).y() >= this->parentWidget()->rect().height()){
                this->move(this->pos().x(), this->parentWidget()->rect().height() - this->height());
            }

            //左边拖动的按钮
            if(this->objectName() == "115"){
                //qDebug()<<"16-----";
                this->setCursor(Qt::SizeAllCursor);
            }else if(this->objectName() == "116"){
                this->setCursor(Qt::SizeAllCursor);
               // qDebug()<<"17-----";
            }




        //打印位置
        m_move_Point = this->pos();
        emit refresh_btn_location(this->pos(),this->objectName());
        //qDebug()<<this->pos().y()<<this->pos().x();
    }
}
