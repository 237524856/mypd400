#include "car_effect_mainview.h"
#include "curve_view.h"



car_effect_mainView::car_effect_mainView(QWidget *parent) : QMainWindow(parent)
{

    this->setAttribute(Qt::WA_StyledBackground,true);
    //this->setStyleSheet("background-color:yellow");
    this->resize(992,692);

    QLabel *bg_title_image = new QLabel(this);
    bg_title_image->move(0,0);
    bg_title_image->resize(992,44);
    bg_title_image->setPixmap(QPixmap(":images/eq/bg_title.png"));

    QLabel *main_bg_image = new QLabel(this);
    main_bg_image->move(0,44);
    main_bg_image->resize(992,648);
    main_bg_image->setPixmap(QPixmap(":images/eq/bg.png"));

    //曲线视图
    curve_view *view =new curve_view(this);
    view->resize(900,240); //800,500  880,230
    view->move(55,55);
    view->setStyleSheet("background-color:black");
    view->createUI();

    //中间视图
    QWidget *midView= new QWidget(this);
    midView->setGeometry(QRect(-5, 300, 992, 160));
    //    midView->setStyleSheet("background-color:yellow");

    QHBoxLayout *hLayout = new QHBoxLayout();
    hLayout->setAlignment(Qt::AlignLeft); //水平向左
    hLayout->setSpacing(0); //控件间间隔
    midView->setLayout(hLayout); //设置窗口布局

    //垂直窗口
    QWidget *vLayoutWidget= new QWidget();
    vLayoutWidget->setFixedSize(35,140);
    //    vLayoutWidget->setStyleSheet("background-color:black");
    QVBoxLayout *vLayout = new QVBoxLayout();
    vLayoutWidget->setLayout(vLayout); //设置窗口布局
    QVector<QString>out_put_labels={QString::fromUtf8("标号"),"频率","Q值","增益","直通"};
    for (int i=0;i<5;i++)
    {
        QLabel *label = new QLabel();
        label->setText(out_put_labels.at(i));
        label->setStyleSheet("font-size:10px;color:rgb(255,255,255);qproperty-alignment: AlignCenter;font-family:'Source Han Sans CN Medium'");
        vLayout->addWidget(label);
    }
    hLayout->addWidget(vLayoutWidget); //水平布局 添加窗口

    for (int i=0;i<31;i++)
    {
        QWidget *widget= new QWidget();
        widget->setFixedSize(45,140);
        //        widget->setStyleSheet("background-color:green");

        QVBoxLayout *vLayout = new QVBoxLayout();
        vLayout->setAlignment(Qt::AlignTop); //水平向上
        vLayout->setSpacing(10); //控件间间隔
        widget->setLayout(vLayout); //设置窗口布局


        QLabel *label = new QLabel();
        label->setText(QString::number(i+1));
        label->setStyleSheet("font-size:10px;color:rgb(255,255,255);qproperty-alignment: AlignCenter;font-family:'Source Han Sans CN Medium'");
        vLayout->addWidget(label); //添加控件

        edit[i] = new myline_edit2();
        edit2[i] = new myline_edit2();
        edit3[i] = new myline_edit2();

        connect(edit[i], SIGNAL(block_key_up(int)), this, SLOT(myline_edit_keyup(int)));
        connect(edit[i], SIGNAL(block_key_up(int)), this, SLOT(myline_edit_keydown(int)));
        connect(edit2[i], SIGNAL(block_key_up(int)), this, SLOT(myline_edit_keyup(int)));
        connect(edit2[i], SIGNAL(block_key_up(int)), this, SLOT(myline_edit_keydown(int)));
        connect(edit3[i], SIGNAL(block_key_up(int)), this, SLOT(myline_edit_keyup(int)));
        connect(edit3[i], SIGNAL(block_key_up(int)), this, SLOT(myline_edit_keydown(int)));

        edit[i]->setText(QString::number(20002,10));
        edit2[i]->setText(QString::number(20002,10));
        edit3[i]->setText(QString::number(20002,10));

        vLayout->addWidget(edit[i]);  //添加控件
        vLayout->addWidget(edit2[i]); //添加控件
        vLayout->addWidget(edit3[i]); //添加控件

        status_btn[i] = new QCheckBox(this);
        status_btn[i]->setStyleSheet(
                    "QCheckBox::indicator{width:19px;height:19px;color:rgb(255, 0, 0);}"
                    "QCheckBox::indicator:unchecked{border-image:url(:images/eq/btn_circle.png) 0 133 0 0;}"
                    "QCheckBox::indicator:unchecked:hover{border-image:url(:images/eq/btn_circle.png) 0 114 0 19;}"
                    "QCheckBox::indicator:checked{border-image:url(:images/eq/btn_circle.png) 0 57 0 76;}");

        //connect(status_btn, SIGNAL(clicked(bool)), this, SLOT(volue_mute_btn_click_status(bool)));
        vLayout->addWidget(status_btn[i]); //垂直布局 添加控件

        hLayout->addWidget(widget); //水平布局 添加控件
    }


    QPushButton *reset_btn = new QPushButton(this);
    reset_btn->move(20,450);
    reset_btn->resize(84,32);
    reset_btn->setText("重置均衡");
    reset_btn->setStyleSheet(
                "QPushButton{color:white;border-image:url(:/images/eq/btn_huifu.png) 0 252 0 0;}"
                "QPushButton:hover{border-image:url(:/images/eq/btn_huifu.png) 0 0 0 252;}"
                "QPushButton:pressed{border-image:url(:/images/eq/btn_huifu.png) 0 84 0 168;}"
                );

    QPushButton *recover_btn = new QPushButton(this);
    recover_btn->move(109,450);
    recover_btn->resize(84,32);
    recover_btn->setText("恢复均衡");
    recover_btn->setStyleSheet(
                "QPushButton{color:white;border-image:url(:/images/eq/btn_huifu.png) 0 252 0 0;}"
                "QPushButton:hover{border-image:url(:/images/eq/btn_huifu.png) 0 0 0 252;}"
                "QPushButton:pressed{border-image:url(:/images/eq/btn_huifu.png) 0 84 0 168;}"
                );


    QPushButton *graphical_btn = new QPushButton(this);
    graphical_btn->move(791,450);
    graphical_btn->resize(84,32);
    graphical_btn->setText("图示均衡");
    graphical_btn->setStyleSheet(
                "QPushButton{color:white;border-image:url(:/images/eq/btn_huifu.png) 0 252 0 0;}"
                "QPushButton:hover{border-image:url(:/images/eq/btn_huifu.png) 0 0 0 252;}"
                "QPushButton:pressed{border-image:url(:/images/eq/btn_huifu.png) 0 84 0 168;}"
                );

    QPushButton *parameter_btn = new QPushButton(this);
    parameter_btn->move(880,450);
    parameter_btn->resize(84,32);
    parameter_btn->setText("参量均衡");
    parameter_btn->setStyleSheet(
                "QPushButton{color:white;border-image:url(:/images/eq/btn_huifu.png) 0 252 0 0;}"
                "QPushButton:hover{border-image:url(:/images/eq/btn_huifu.png) 0 0 0 252;}"
                "QPushButton:pressed{border-image:url(:/images/eq/btn_huifu.png) 0 84 0 168;}"
                );


    //高通
    QWidget *hpView= new QWidget(this);
    hpView->setGeometry(QRect(43, 508, 430, 138));
    //    hpView->setStyleSheet("background-color:yellow");

    QLabel *hplabel = new QLabel(hpView);
    hplabel->setText("高通");
    hplabel->move(160,5);
    hplabel->setStyleSheet("font-size:20px;color:rgb(255,255,255);qproperty-alignment: AlignCenter;font-family:'Source Han Sans CN Medium'");

    QCheckBox *hpstatus_btn = new QCheckBox(hpView);
    hpstatus_btn->move(372,0);
    hpstatus_btn->setStyleSheet(
                "QCheckBox::indicator{width:62px;height:36px;color:rgb(255, 0, 0);}"
                "QCheckBox::indicator:unchecked{border-image:url(:images/eq/btn_switch.png) 0 434 0 0;}"
                "QCheckBox::indicator:unchecked:hover{border-image:url(:images/eq/btn_switch.png) 0 372 0 62;}"
                "QCheckBox::indicator:checked{border-image:url(:images/eq/btn_switch.png) 0 186 0 248;}");

    //类型-高通
    QWidget *qwType= new QWidget(hpView);
    qwType->setGeometry(QRect(18, 40, 140, 100));
    //    qwType->setStyleSheet("background-color:yellow");

    QLabel *qwType_label = new QLabel(qwType);
    qwType_label->setText("类型");
    qwType_label->move(50,15);
    qwType_label->setStyleSheet("font-size:13px;color:rgb(255,255,255);qproperty-alignment: AlignCenter;font-family:'Source Han Sans CN Medium'");

    QComboBox *qwType_com = new QComboBox(qwType);
    qwType_com->move(0,40);
    qwType_com->resize(128,32); //设置QComboBox 大小
    qwType_com->addItem("111");
    qwType_com->addItem("222");
    qwType_com->addItem("333");
    qwType_com->addItem("444");

    //     QLineEdit *lineEdit = new QLineEdit;
    //     lineEdit->setReadOnly(true);
    //     lineEdit->setAlignment(Qt::AlignCenter);
    //     lineEdit->setStyleSheet("font-size:15px;");
    //    qwType_com->setLineEdit(lineEdit);

    //    qwType_com->setStyleSheet("background-color:yellow"); //下拉列表样式
    qwType_com->setStyleSheet("color:red;background-color:yellow;"); //下拉列表样式

    qwType_com->setStyleSheet(
                "QComboBox{padding-left:50px;background:transparent;font-size:17px; color:white; border-image:url(:/images/eq/bg_combobox.png) 0 384 0 0;}"

                //                "QComboBox::down-arrow{image:url(:/images/eq/三角下拉.png)0 98 0 0;}"
                //                "QComboBox::down-arrow:hover{image:url(:/images/eq/三角下拉.png)0 0 0 14;}"
                //                "QComboBox::down-arrow:pressed{image:url(:/images/eq/三角下拉.png)0 42 0 56;}"

                //                "QComboBox QAbstractitemView::item {min-height: 60px;}"
                //                "QComboBox QAbstractItemView { background: transparent;}"
                ); //未下拉时，QComboBox的样式

    //频率-高通
    QWidget *qwHz= new QWidget(hpView);
    qwHz->setGeometry(QRect(155, 40, 140, 100));
    //    qwHz->setStyleSheet("background-color:yellow");

    QLabel *qwHz_label = new QLabel(qwHz);
    qwHz_label->setText("频率");
    qwHz_label->move(50,15);
    qwHz_label->setStyleSheet("font-size:13px;color:rgb(255,255,255);qproperty-alignment: AlignCenter;font-family:'Source Han Sans CN Medium'");

    QLabel *qwHz_label2 = new QLabel(qwHz);
    qwHz_label2->move(0,40);
    qwHz_label2->resize(128,32); //设置QComboBox 大小
    qwHz_label2->setText("5000Hz");
    qwHz_label2->setStyleSheet("qproperty-alignment: AlignCenter;background:transparent;font-size:17px; color:white; border-image:url(:/images/eq/bg_frequency.png) 0 384 0 0;");




    //斜率-高通
    QWidget *qwSlope= new QWidget(hpView);
    qwSlope->setGeometry(QRect(290, 40, 140, 100));
    //    qwSlope->setStyleSheet("background-color:yellow");

    QLabel *qwSlope_label = new QLabel(qwSlope);
    qwSlope_label->setText("斜率");
    qwSlope_label->move(50,15);
    qwSlope_label->setStyleSheet("font-size:13px;color:rgb(255,255,255);qproperty-alignment: AlignCenter;font-family:'Source Han Sans CN Medium'");

    QComboBox *qwSlope_com = new QComboBox(qwSlope);
    qwSlope_com->move(0,40);
    qwSlope_com->resize(128,32); //设置QComboBox 大小
    qwSlope_com->addItem("111");
    qwSlope_com->addItem("222");
    qwSlope_com->addItem("333");
    qwSlope_com->addItem("444");

    qwSlope_com->setStyleSheet("color:red;background-color:yellow;"); //下拉列表样式
    qwSlope_com->setStyleSheet(
                "QComboBox{padding-left:50px;background:transparent;font-size:17px; color:white; border-image:url(:/images/eq/bg_combobox.png) 0 384 0 0;}"
                ); //未下拉时，QComboBox的样式



    //低通
    QWidget *lpView= new QWidget(this);
    lpView->setGeometry(QRect(515, 508, 430, 138));
    //    lpView->setStyleSheet("background-color:yellow");

    QLabel *lplabel = new QLabel(lpView);
    lplabel->setText("低通");
    lplabel->move(160,5);
    lplabel->setStyleSheet("font-size:20px;color:rgb(255,255,255);qproperty-alignment: AlignCenter;font-family:'Source Han Sans CN Medium'");

    QCheckBox *lpstatus_btn = new QCheckBox(lpView);
    lpstatus_btn->move(372,0);
    lpstatus_btn->setStyleSheet(
                "QCheckBox::indicator{width:62px;height:36px;color:rgb(255, 0, 0);}"
                "QCheckBox::indicator:unchecked{border-image:url(:images/eq/btn_switch.png) 0 434 0 0;}"
                "QCheckBox::indicator:unchecked:hover{border-image:url(:images/eq/btn_switch.png) 0 372 0 62;}"
                "QCheckBox::indicator:checked{border-image:url(:images/eq/btn_switch.png) 0 186 0 248;}");

    //类型-低通
    QWidget *qwType2= new QWidget(lpView);
    qwType2->setGeometry(QRect(18, 40, 140, 100));
    //    qwType->setStyleSheet("background-color:yellow");

    QLabel *qwType2_label = new QLabel(qwType2);
    qwType2_label->setText("类型");
    qwType2_label->move(50,15);
    qwType2_label->setStyleSheet("font-size:13px;color:rgb(255,255,255);qproperty-alignment: AlignCenter;font-family:'Source Han Sans CN Medium'");

    QComboBox *qwType2_com = new QComboBox(qwType2);
    qwType2_com->move(0,40);
    qwType2_com->resize(128,32); //设置QComboBox 大小
    qwType2_com->addItem("111");
    qwType2_com->addItem("222");
    qwType2_com->addItem("333");
    qwType2_com->addItem("444");

    qwType2_com->setStyleSheet("color:red;background-color:yellow;"); //下拉列表样式
    qwType2_com->setStyleSheet(
                "QComboBox{padding-left:50px;background:transparent;font-size:17px; color:white; border-image:url(:/images/eq/bg_combobox.png) 0 384 0 0;}"

                //                "QComboBox::down-arrow{image:url(:/images/eq/三角下拉.png)0 98 0 0;}"
                //                "QComboBox::down-arrow:hover{image:url(:/images/eq/三角下拉.png)0 0 0 14;}"
                //                "QComboBox::down-arrow:pressed{image:url(:/images/eq/三角下拉.png)0 42 0 56;}"

                //                "QComboBox QAbstractitemView::item {min-height: 60px;}"
                //                "QComboBox QAbstractItemView { background: transparent;}"
                ); //未下拉时，QComboBox的样式

    //频率-低通
    QWidget *qwHz2= new QWidget(lpView);
    qwHz2->setGeometry(QRect(155, 40, 140, 100));
    //    qwHz->setStyleSheet("background-color:yellow");

    QLabel *qwHz2_label = new QLabel(qwHz2);
    qwHz2_label->setText("频率");
    qwHz2_label->move(50,15);
    qwHz2_label->setStyleSheet("font-size:13px;color:rgb(255,255,255);qproperty-alignment: AlignCenter;font-family:'Source Han Sans CN Medium'");

    QLabel *qwHz2_label2 = new QLabel(qwHz2);
    qwHz2_label2->move(0,40);
    qwHz2_label2->resize(128,32); //设置QComboBox 大小
    qwHz2_label2->setText("5000Hz");
    qwHz2_label2->setStyleSheet("qproperty-alignment: AlignCenter;background:transparent;font-size:17px; color:white; border-image:url(:/images/eq/bg_frequency.png) 0 384 0 0;");


    //斜率-低通
    QWidget *qwSlope2= new QWidget(lpView);
    qwSlope2->setGeometry(QRect(290, 40, 140, 100));
    //    qwSlope->setStyleSheet("background-color:yellow");

    QLabel *qwSlope2_label = new QLabel(qwSlope2);
    qwSlope2_label->setText("斜率");
    qwSlope2_label->move(50,15);
    qwSlope2_label->setStyleSheet("font-size:13px;color:rgb(255,255,255);qproperty-alignment: AlignCenter;font-family:'Source Han Sans CN Medium'");

    QComboBox *qwSlope2_com = new QComboBox(qwSlope2);
    qwSlope2_com->move(0,40);
    qwSlope2_com->resize(128,32); //设置QComboBox 大小
    qwSlope2_com->addItem("111");
    qwSlope2_com->addItem("222");
    qwSlope2_com->addItem("333");
    qwSlope2_com->addItem("444");

    qwSlope2_com->setStyleSheet("color:red;background-color:yellow;"); //下拉列表样式
    qwSlope2_com->setStyleSheet(
                "QComboBox{padding-left:50px;background:transparent;font-size:17px; color:white; border-image:url(:/images/eq/bg_combobox.png) 0 384 0 0;}"
                ); //未下拉时，QComboBox的样式


}

void car_effect_mainView::myline_edit_keyup(int block_value){

    myline_edit2 *edit = dynamic_cast<myline_edit2 *>(sender());
    edit->setText(QString::number(block_value,10));
    qDebug()<<"xxxx"<<block_value;
}
void car_effect_mainView::myline_edit_keydown(int block_value){
    myline_edit2 *edit = dynamic_cast<myline_edit2 *>(sender());
    edit->setText(QString::number(block_value,10));
    qDebug()<<"xxxx"<<block_value;
}
