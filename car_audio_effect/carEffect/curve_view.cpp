#include "curve_view.h"

#include <QVector>
#include <QLabel>
#include <QPainter>


//线段
typedef struct myLine{
    QPoint startPnt;
    QPoint endPnt;
}myLine;

curve_view::curve_view(QWidget *parent) : QWidget(parent)
{
    this->setAttribute(Qt::WA_StyledBackground,true);


}


void curve_view::createUI(){

    QVector<QString>bottomtitleArrs = {"20","50","100","200","500","1000","2000","5000","10000","20000"};
    m_bottomtitleArrs = {20,50,100,200,500,1000,2000,5000,10000,20000};
    double index = log10 ((double)10);
    QVector<QString>arrs = {"10","20","30","40","50","60","70","80","90","100","200","300","400","500","600","700","800","900","1000","2000","3000","4000","5000","6000","7000","8000","9000","10000","20000"};
    QVector<QString>spotArrs = {"20","25","32","42.5","91.9","198","292","630","1360","2940","6350","13700","20200"};
    //垂直网格线
    for (int i=0;i<29;i++) {
        int number = arrs.at(i).toInt();
        double space = (log10 ((double)number) - index) * ((double)this->width()) / (log10 ((double)24000) - index);
        QLabel*gridLevelLbl = new QLabel(this);
        gridLevelLbl->setGeometry(space, 0, 1, (double)this->height());
        gridLevelLbl->setStyleSheet("background-color:rgb(0,180,0)");
        m_spaces.push_back(space);
        //下面的数字
        for (int k =0;k<bottomtitleArrs.count();k++) {
            if(arrs.at(i)==bottomtitleArrs.at(k)){
                m_bottomlabel_spaces.push_back(space);
            }
        }

    }
    //水平网格线
    for (int j = 0; j < 9; j ++) {
        QLabel *gridVerticalLbl = new QLabel(this);
        gridVerticalLbl->setGeometry(0, (double)(this->height()-0.3) / 8 * j , this->width(), 1);
        gridVerticalLbl->setStyleSheet("background-color:rgb(0,180,0)");
    }

    //画button


        m_chlider_view = new chlider_curve_view(this);
        m_chlider_view->resize(this->width(),this->height());
        m_chlider_view->move(0,0);
        m_chlider_view->setStyleSheet("background-color:transparent");
        m_chlider_view->createUI();
        m_chlider_view->create_datasource(19.7,0,0);

        m_chlider_view->m_bottomlabel_spaces =m_bottomlabel_spaces;

}

//void curve_view::receive_btn_location(QPoint btn_point,QString btn_name){

//    m_chlider_view->m_mouse_point = btn_point;
//        int value_gain =    (double)btn_point.y() / (((double)this->height()-17) /240.0);

//        int value_freq =0;

//        for (int i= 1;i<m_bottomlabel_spaces.count();i++) {
//            //qDebug()<<"hhhhhhhhh"<<i;

//            if(btn_point.x()>=m_bottomlabel_spaces.at(i-1) && btn_point.x()<m_bottomlabel_spaces.at(i)){
//                int qq = 0;
//                if(i!=1){
//                    qq=  m_bottomtitleArrs.at(i-1);
//                }

//                else{
//                    qq = 20;
//                };
//                //qDebug()<<"hhhhhhhhh"<<qq <<i<<m_bottomtitleArrs.at(i-1);
//                int myvalue =  qq + ((double)btn_point.x()-m_bottomlabel_spaces.at(i-1))/((m_bottomlabel_spaces.at(i)-m_bottomlabel_spaces.at(i-1))/(m_bottomtitleArrs.at(i)-m_bottomtitleArrs.at(i-1)));
//              // qDebug()<<"jjjjj"<<myvalue;
//               value_freq =  qq + ((double)btn_point.x()-m_bottomlabel_spaces.at(i-1))/((m_bottomlabel_spaces.at(i)-m_bottomlabel_spaces.at(i-1))/(m_bottomtitleArrs.at(i)-m_bottomtitleArrs.at(i-1)));
//            }
//        }



////                if(btn_point.x()<=m_bottomlabel_spaces.at(0)){
////                    value_freq =    ((double)btn_point.x() -8)/ ((m_bottomlabel_spaces.at(0)-8)/20.0);
////                }else if(btn_point.x()>=m_bottomlabel_spaces.at(0)&&btn_point.x()<m_bottomlabel_spaces.at(1)){
////                    value_freq =    ((double)btn_point.x()-8) / ((m_bottomlabel_spaces.at(1)-m_bottomlabel_spaces.at(0))/30.0);
////                }else if(btn_point.x()>=m_bottomlabel_spaces.at(1)&&btn_point.x()<m_bottomlabel_spaces.at(2)){
////                    value_freq =   50+ ((double)btn_point.x()-m_bottomlabel_spaces.at(1)) / ((m_bottomlabel_spaces.at(2)-m_bottomlabel_spaces.at(1))/50.0);
////                }

//             // mybuttons.at(0)->move(value_freq*(((m_bottomlabel_spaces.at(1)-m_bottomlabel_spaces.at(0))/30.0))+8,btn_point.y());
//        //qDebug()<<"xxxx"<<value_freq<<btn_point.x();



//    if(value_gain-120>= 0){
//         m_chlider_view->create_datasource(value_freq,(0-(value_gain-120)),btn_name.toUInt()-100);
//    }else{
//         m_chlider_view->create_datasource(value_freq,120-value_gain,btn_name.toUInt()-100);
//    }

//foreach(double number, m_spaces){

////qDebug()<<"yyyyy"<<number<<btn_point.x();
//}



//   // m_chlider_view->update();
//}

