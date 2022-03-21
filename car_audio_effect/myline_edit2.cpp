#include "myline_edit2.h"
#include "QKeyEvent"
#include <QDebug>

myline_edit2::myline_edit2(QWidget *parent) : QLineEdit(parent)
{
    //this->setStyleSheet("color:white;background-color:transparent;border: 2px solid rgb(57,57,57);border-radius:3px;font-size:9px;font-family:'Source Han Sans CN Medium'");

    this->setStyleSheet("color:white;qproperty-alignment: AlignCenter;background-color:transparent;border-radius:3px;font-size:10px;");
}
void myline_edit2::set_mystyle(){


}
void myline_edit2::keyPressEvent(QKeyEvent *event){


    switch (event->key())

    {

    case Qt::Key_Right :

        qDebug()<<"right-------";

        break ;

    case Qt::Key_Up :
    {
        int block_value = this->text().toInt()+1;
        emit block_key_up(block_value);
    }

        break ;

    case Qt::Key_Left :

        qDebug()<<"Key_Left-------";

        break ;

    case Qt::Key_Down :
    {
        int block_value = this->text().toInt()-1;
        emit block_key_up(block_value);
    }
       // qDebug()<<"Key_Down-------";


        break ;

    default :

        QLineEdit::keyPressEvent(event);

        break ;

    }
}
