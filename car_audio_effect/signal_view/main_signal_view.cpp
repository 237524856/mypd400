#include "main_signal_view.h"
#include "QDesktopWidget"
#include <QFontDatabase>
#include <QVector>
#include <QCheckBox>

main_signal_view::main_signal_view(QWidget *parent) : QMainWindow(parent)
{

    setFixedSize(454,582);
    QFontDatabase::addApplicationFont(":/images/SourceHanSansCN Medium.ttf");
    this->setStyleSheet("background-color:rgb(52,54,56)");

    QLabel *back_left_image = new QLabel(this);
    back_left_image->move(0,0);
    back_left_image->resize(this->width(),this->height());
    back_left_image->setPixmap(QPixmap(":images/sing_view_bgImg.png"));

    QLabel *dianping = new QLabel(back_left_image);
    dianping->resize(100,18);
    dianping->move(30,20);
    dianping->setText("信号发生器选择");
    dianping->setStyleSheet("font-family:'SourceHanSansCN Medium';font-size:10px;color:rgb(255,255,255);background-color:transparent");

    QVector<QString>titles={"关","粉红噪音","白噪音","正弦波","正弦波(正半周)"};
    m_buttonGroup = new QButtonGroup();
    m_buttonGroup->setExclusive(true);
    for (int i=0;i<titles.count();i++) {

        //按钮
        QCheckBox *fasheqi_btn = new QCheckBox(this);
        fasheqi_btn->resize(12,12);
        fasheqi_btn->move(30,53 + 30*i);
        fasheqi_btn->setStyleSheet(
                    "QCheckBox::indicator{width: 12px;height: 12px;background-color:rgb(52,54,56);}"
                    "QCheckBox::indicator:unchecked{border-image:url(:images/signal/top_select.png) 0 84 0 0;}"
                    "QCheckBox::indicator:unchecked:hover{border-image:url(:images/signal/top_select.png) 0 72 0 12;}"
                    "QCheckBox::indicator:checked{border-image:url(:images/signal/top_select.png) 0 36 0 48;}"
                    );
        m_buttonGroup->addButton(fasheqi_btn,i);


        QLabel *dianping = new QLabel(back_left_image);
        dianping->resize(100,18);
        dianping->move(50,50 + 30*i);
        dianping->setText(titles.at(i));
        dianping->setStyleSheet("font-family:'SourceHanSansCN Medium';font-size:10px;color:rgb(255,255,255);background-color:transparent");
    }
//显示的LABEL
    m_left_label = new QLabel(back_left_image);
    m_left_label->move(30,237);
    m_left_label->resize(60,32);
    //m_left_label->setPixmap(QPixmap(":images/signal/show_label.png"));
    m_left_label->setText("800Hz");
    m_left_label->setStyleSheet("border-image:url(:images/signal/show_label.png);font-family:'SourceHanSansCN Medium';font-size:11px;color:rgb(255,255,255);qproperty-alignment: AlignCenter;");

    m_right_label = new QLabel(back_left_image);
    m_right_label->move(113,237);
    m_right_label->resize(60,32);
    //m_left_label->setPixmap(QPixmap(":images/signal/show_label.png"));
    m_right_label->setText("-24dB");
    m_right_label->setStyleSheet("border-image:url(:images/signal/show_label.png);font-family:'SourceHanSansCN Medium';font-size:11px;color:rgb(255,255,255);qproperty-alignment: AlignCenter;");


    //右边部分
    QLabel *shuchu_signal = new QLabel(back_left_image);
    shuchu_signal->resize(100,18);
    shuchu_signal->move(205,20);
    shuchu_signal->setText("信号信号选择");
    shuchu_signal->setStyleSheet("font-family:'SourceHanSansCN Medium';font-size:10px;color:rgb(255,255,255);background-color:transparent");

    for(int i=0 ;i< 15;i++){

        QCheckBox *open_btn = new QCheckBox(back_left_image);
        open_btn->resize(50,24);
        open_btn->move(243,43 + 34*i);
        open_btn->setStyleSheet(
                    "QCheckBox::indicator{width: 50px;height: 24px;background-color:rgb(52,54,56);}"
                    "QCheckBox::indicator:unchecked{border-image:url(:images/signal/left_btn.png) 0 350 0 0;}"
                    "QCheckBox::indicator:unchecked:hover{border-image:url(:images/signal/left_btn.png) 0 300 0 50;}"
                    "QCheckBox::indicator:checked{border-image:url(:images/signal/left_btn.png) 0 150 0 200;}"
                    );
        QLabel *open_label = new QLabel(open_btn);
        open_label->resize(50,24);
        open_label->move(0,0);
        open_label->setText("开");
        open_label->setStyleSheet("font-family:'SourceHanSansCN Medium';font-size:10px;color:rgb(255,255,255);background-color:transparent;qproperty-alignment: AlignCenter;");

        QButtonGroup *open_btns = new QButtonGroup();
        open_btns->setExclusive(true);
        open_btns->addButton(open_btn,0);

        QCheckBox *close_btn = new QCheckBox(back_left_image);
        close_btn->resize(50,24);
        close_btn->move(243+52,43 + 34*i);
        close_btn->setStyleSheet(
                    "QCheckBox::indicator{width: 50px;height: 24px;background-color:rgb(52,54,56);}"
                    "QCheckBox::indicator:unchecked{border-image:url(:images/signal/right_btn.png) 0 350 0 0;}"
                    "QCheckBox::indicator:unchecked:hover{border-image:url(:images/signal/right_btn.png) 0 300 0 50;}"
                    "QCheckBox::indicator:checked{border-image:url(:images/signal/right_btn.png) 0 150 0 200;}"
                    );
        QLabel *close_label = new QLabel(close_btn);
        close_label->resize(50,24);
        close_label->move(0,0);
        close_label->setText("关");
        close_label->setStyleSheet("font-family:'SourceHanSansCN Medium';font-size:10px;color:rgb(255,255,255);background-color:transparent;qproperty-alignment: AlignCenter;");
        open_btns->addButton(close_btn,1);

        //右边的输入LABEL
        QLabel *shuru_label = new QLabel(back_left_image);
        shuru_label->resize(50,24);
        shuru_label->move(243+52+53,43 + 34*i);
        shuru_label->setText("输出"+QString::number(i+1,10));
        shuru_label->setStyleSheet("font-family:'SourceHanSansCN Medium';font-size:10px;color:rgb(255,255,255);background-color:transparent;qproperty-alignment: AlignCenter;");
    }





}
