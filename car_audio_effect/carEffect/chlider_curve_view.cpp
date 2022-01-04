#include "chlider_curve_view.h"
#include <QPainter>
#include <QDebug>

#define  DB_NUMBER 8
chlider_curve_view::chlider_curve_view(QWidget *parent) : QWidget(parent)
{
    this->setAttribute(Qt::WA_StyledBackground,true);

    QVector<QString>spotArrs = {"20","25","32","42","92","198","292","630","1360","2940","6350","13700","20200"};
    for (int i = 0;i<30;i++) {
        m_pass_eq[i] = {};
        m_pass_eq[i].zoom_space = 16;
    }
    for (int i = 0;i<30;i++) {


    }
    for (int i = 0;i<spotArrs.count();i++) {
        m_pass_eq[i].freq = spotArrs.at(i).toInt();
        //if(i==1)m_pass_eq[i].gain=30;
    }

    for (int i = 0;i<30;i++) {
        mEqParams[i] = {};
    }
    btn_spaceX=16;

}

void chlider_curve_view::createUI(){

    m_bottomtitleArrs = {20,50,100,200,500,1000,2000,5000,10000,20000};
    double index = log10 ((double)10);
    QVector<QString>spotArrs = {"20","25","32","42.5","91.9","198","292","630","1360","2940","6350","13700","20200"};
    for (int k = 0; k < spotArrs.count(); ++k) {

        double spotX = (log10 (spotArrs.at(k).toDouble()) - index) * (this->width()) / (log10 ((double)24000) - index);
        dragpushbutton *btn = new dragpushbutton(this);
        btn->setGeometry(spotX-8,(double)(this->height()-0.3) / 2-(16/2),16,16);

        btn->setText(QString::number(k+1,10));
        btn->setObjectName(QString::number(k+100,10));
        mybuttons.push_back(btn);
        connect(btn,SIGNAL(refresh_btn_location(QPoint,QString)),this,SLOT(receive_btn_location(QPoint,QString)));

    }
    //添加多L、H的按钮
    for (int i = 0;i<2;i++) {
        dragpushbutton *btn = new dragpushbutton(this);
        btn->setGeometry(60000,0,16,16);
        i==0?btn->setText("H"):btn->setText("L");
        btn->setObjectName(QString::number(i+100+spotArrs.count(),10));
        connect(btn,SIGNAL(refresh_btn_location(QPoint,QString)),this,SLOT(receive_btn_location(QPoint,QString)));

        mybuttons.push_back(btn);
    }

    //添加多拖拉的按钮
    for (int i = 0;i<2;i++) {
        dragpushbutton *btn = new dragpushbutton(this);
        btn->setGeometry(0+200*i,0,16,16);
        i==0?btn->setText("K"):btn->setText("R");
        btn->setObjectName(QString::number(i+102+spotArrs.count(),10));
        connect(btn,SIGNAL(refresh_btn_location(QPoint,QString)),this,SLOT(receive_btn_location(QPoint,QString)));
        //btn->hide();
        mybuttons.push_back(btn);
    }
}

void chlider_curve_view::create_datasource(int freq,double gain,int select_btn_tag){
    m_selectIndex = 0;
    //根据不同的按钮选择相对的高通还是低通
    select_btn_tag == 13?isHfpSelect = 1:isHfpSelect = 0;
    select_btn_tag == 14?isLfpSelect = 1:isLfpSelect = 0;
    //isLfpSelect = 1;
    //全部清空
    m_EQArrs.clear();
    m_gainArrs.clear();
    m_QArrs.clear();
    m_Q2Arrs.clear();
    m_EQModeleArrs.clear();


    if(m_selectcurrent_btnName == "115"){

        if(m_leftmouse_point.x()<m_mouse_point.x()-116){
            btn_spaceX = 116;

        }else if(m_leftmouse_point.x()>=m_mouse_point.x()-16){
           btn_spaceX = 16;
        }
        else{
            btn_spaceX = m_mouse_point.x()-m_leftmouse_point.x();
        }
    }

    if(m_selectcurrent_btnName == "116"){
        if(m_rightmouse_point.x()>m_mouse_point.x()+116){
           btn_spaceX = 116;
        }else if(m_rightmouse_point.x()<=m_mouse_point.x()+16){
           btn_spaceX = 16;
        }
        else{
           btn_spaceX = m_rightmouse_point.x()-m_mouse_point.x();
        }
    }

qDebug()<<"kkk------33333xxxxxx-------------"<<btn_spaceX<<m_pass_eq[select_btn_tag].zoom_space;
    m_pass_eq[select_btn_tag].zoom_space = btn_spaceX;

    m_pass_eq[select_btn_tag].freq = freq;
    m_pass_eq[select_btn_tag].gain = gain;
    m_pass_eq[select_btn_tag].Q = (double)YY_Qx100[116-m_pass_eq[select_btn_tag].zoom_space]/100.f/3;






    for (int j = 0; j < mEqNum+2; j ++) {
        for (int i = 0 ; i < 1024; i ++) {
            mEqParams[j].pts[i] = 0;
        }
    }

    for (int i = 0 ; i < 1024; i ++) {
        m_pSumY[i] = 0;
    }
    QVector<QString>spotArrs = {"20","25","32","42.5","91.9","198","292","630","1360","2940","6350","13700","20200"};

    for (int i =0;i<spotArrs.count();i++) {
        mEqParams[i].type = 0;
        mEqParams[i].filter = 0;
        mEqParams[i].freq = m_pass_eq[i].freq;
        mEqParams[i].gain = m_pass_eq[i].gain/10;
        mEqParams[i].Q = m_pass_eq[i].Q;
        mEqParams[i].Q2 = (double)YY_Qx100[100];

        //qDebug()<<"hhhhhhh"<<mEqParams[i].freq;
        m_EQArrs.push_back(mEqParams[i].freq);
        m_gainArrs.push_back(mEqParams[i].gain);
        m_QArrs.push_back(mEqParams[i].Q);
        m_Q2Arrs.push_back(mEqParams[i].Q2);
        //m_EQModeleArrs.push_back()

    }
    //添加高通低通的点

    addEffectEparamsTwoHFilter_Freq(m_pass_eq[spotArrs.count()].freq+20,m_pass_eq[spotArrs.count()+1].freq+50,m_EQArrs,m_gainArrs,spotArrs.count()-1);
    //qDebug()<<"xkxkxk"<<select_btn_tag;
    //设置每个点的阴影部分
    setCalcEqeal(spotArrs.count()+1,mEqParams,select_btn_tag);
    //重新规划各个点
    createEQpointView(m_EQArrs,m_gainArrs,m_QArrs,m_Q2Arrs,m_EQModeleArrs,select_btn_tag);

    m_select_btn_numbers.insert(m_iCurrent,m_iCurrent);
    QMap<int,int>::Iterator it=m_select_btn_numbers.begin();
    while(it!=m_select_btn_numbers.end())
    {
        //qDebug()<<it.key()<<"\t"<<it.value();
        it++;
    }
    this->update();
}

void chlider_curve_view::addEffectEparamsTwoHFilter_Freq(int HFilter_Freq,int LFilter_Freq,QVector<double>EQArrs,QVector<double>gainArrs,int alltotalNum){
    //添加高通
    mEqParams[alltotalNum+1].type = 1;
    mEqParams[alltotalNum+1].filter = 1;
    if (HFilter_Freq == 0) {
        mEqParams[alltotalNum+1].freq = 0;
    }else{
        //mEqParams[alltotalNum+1].freq = YY_FreqHPFx10[HFilter_Freq]/10;
        mEqParams[alltotalNum+1].freq = HFilter_Freq;
    }
    mEqParams[alltotalNum+1].gain = -12;
    mEqParams[alltotalNum+1].Q = 0;
    mEqParams[alltotalNum+1].Q2 = 0;
    m_EQArrs.push_back(mEqParams[alltotalNum+1].freq);
    m_gainArrs.push_back(mEqParams[alltotalNum+1].gain);
    //添加低通
    mEqParams[alltotalNum+2].type = 2;
    mEqParams[alltotalNum+2].filter = 1;
    mEqParams[alltotalNum+2].freq = LFilter_Freq;
    mEqParams[alltotalNum+2].gain = -12;
    mEqParams[alltotalNum+2].Q = 0;
    mEqParams[alltotalNum+2].Q2 = 0;
    m_EQArrs.push_back(mEqParams[alltotalNum+2].freq);
    m_gainArrs.push_back(mEqParams[alltotalNum+2].gain);

}
void chlider_curve_view::createEQpointView(QVector<double>EQtotalNumerArrs,QVector<double>gainArrs,
                                           QVector<double>QArrs,QVector<double>Q2Arrs,QVector<double>EQModelArrs,int eqIndex){
    double m_height = (double)this->height();
    double m_width= (double)this->width();
    double index = log10 ((double)10);
    double basicY = (m_height) / 24;
    //开始创建各种点
    QVector<double> spotArrs = m_EQArrs;

    for (int k = 0; k < spotArrs.count() ; ++k) {
        double spotX = (log10 ((double)spotArrs.at(k)) - index) * (m_width) / (log10 ((double)24000) - index);
        //点的Y位置
        double spotY = (gainArrs[k] + 12) * basicY;

        //qDebug()<<"hhhhhhh"<<gainArrs[k]<<basicY <<spotY;
        dragpushbutton *btn = mybuttons.at(k);

//        qDebug()<<"hhhhhhh"<<btn->objectName()<<spotArrs.at(k);
        btn->move(spotX ,m_height - spotY-8);
        if(k>=spotArrs.count()-2){//因为挡住了按钮
            btn->move(spotX ,m_height - spotY-16);
        }

        if (k == eqIndex) {
            dragpushbutton *left_btn = mybuttons.at(mybuttons.count()-2);
            dragpushbutton *right_btn = mybuttons.at(mybuttons.count()-1);
            //qDebug()<<"xxxxaaaaaa"<<m_pass_eq[m_current_btnName.toUInt()-100].zoom_space<<btn->x()<<m_current_btnName.toUInt()-100;
            left_btn->move(btn->x()-m_pass_eq[m_current_btnName.toUInt()-100].zoom_space,btn->y());
            right_btn->move(btn->x()+m_pass_eq[m_current_btnName.toUInt()-100].zoom_space,btn->y());

//            if(m_selectcurrent_btnName == "115"){

//                if(m_leftmouse_point.x()<btn->x()-116){
//                    btn_spaceX = 116;

//                }else if(m_leftmouse_point.x()>=btn->x()-16){
//                   btn_spaceX = 16;
//                }
//                else{
//                    btn_spaceX = btn->x()-m_leftmouse_point.x();
//                }
//                left_btn->move(btn->x()-btn_spaceX,btn->y());
//                right_btn->move(btn->x()+btn_spaceX,btn->y());
//                qDebug()<<"xxxxleft"<<btn_spaceX;
//            }

//            if(m_selectcurrent_btnName == "116"){
//                if(m_rightmouse_point.x()>btn->x()+116){
//                   btn_spaceX = 116;
//                }else if(m_rightmouse_point.x()<=btn->x()+16){
//                   btn_spaceX = 16;
//                }
//                else{
//                   btn_spaceX = m_rightmouse_point.x()-btn->x();
//                }
//                left_btn->move(btn->x()-btn_spaceX,btn->y());
//                right_btn->move(btn->x()+btn_spaceX,btn->y());
//                qDebug()<<"xxxxleft"<<btn_spaceX;
//            }
        }
    }
#if 0
    if (k == eqIndex) {
        [self setupHeartbeatAnimationInView:spotBtn];
        NSLog(@"-------------总共--%ld",EQModelArrs.count);
        if (EQModelArrs.count <= eqIndex) {
            return;
        }
        //添加展示的数字
        UIButton *showMessageBtn = [UIButton buttonWithType:UIButtonTypeCustom];
        showMessageBtn.frame = CGRectMake(spotBtn.mj_x-10, CGRectGetMaxY(spotBtn.frame)+3, 50, 40);
        if ([EQModelArrs[eqIndex] intValue] > 1) {
            [showMessageBtn setTitle:[NSString stringWithFormat:@"%@Hz\n%@dB\nQ:%@",EQtotalNumerArrs[eqIndex],gainArrs[eqIndex],Q2Arrs[eqIndex]] forState:UIControlStateNormal];
        }else{
            [showMessageBtn setTitle:[NSString stringWithFormat:@"%@Hz\n%@dB\nQ:%@",EQtotalNumerArrs[eqIndex],gainArrs[eqIndex],QArrs[eqIndex]] forState:UIControlStateNormal];
        }

        showMessageBtn.titleLabel.font = [UIFont systemFontOfSize:8];
        showMessageBtn.titleLabel.numberOfLines = 0;
        [showMessageBtn setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
        [self.curveSrollView addSubview:showMessageBtn];
    }
}
#endif
}
double chlider_curve_view::X2Freq(int x){

    double m_fLogZeroFreq = log10 ((double)10);
    double scaleX = ((double)this->width()) / (c_logfn-m_fLogZeroFreq);
    return pow(10.0, (x)/scaleX + m_fLogZeroFreq);
}


//按钮按下的方法
void chlider_curve_view::receive_btnpress_location(QPoint btn_point,QString btn_name){


//    QPoint mypoint (m_oldleftmouse_point.x()-m_pass_eq[m_current_btnName.toUInt()-100].zoom_space,m_leftmouse_point.y());
//    m_leftmouse_point =mypoint;

    if(btn_name == "115"){

    }else if(btn_name == "116"){

    }else{
        m_current_btnName = btn_name;
        m_oldleftmouse_point = btn_point;
    }
}

void chlider_curve_view::receive_btn_location(QPoint btn_point,QString btn_name){


    m_selectcurrent_btnName = btn_name;
    if(btn_name == "115"){
        m_leftmouse_point = btn_point;
    }else if(btn_name == "116"){
        m_rightmouse_point = btn_point;
    }else{

        this->m_mouse_point = btn_point;
        m_current_btnName = btn_name;

          btn_spaceX = m_pass_eq[m_current_btnName.toUInt()-100].zoom_space;

    }
    double yy = X2Freq(m_mouse_point.x());
    int value_gain =    (double)m_mouse_point.y() / (((double)this->height()-17) /240.0);
    int value_freq =X2Freq(m_mouse_point.x());
    //qDebug()<<"xxxxxxx"<<value_freq;

    if(value_gain-120>= 0){
        create_datasource(value_freq,(0-(value_gain-120)),m_current_btnName.toUInt()-100);
    }else{
        create_datasource(value_freq,120-value_gain,m_current_btnName.toUInt()-100);
    }


}
void  chlider_curve_view::paintEvent(QPaintEvent *event){

    double m_height = (double)this->height();
    double m_width= (double)this->width();
    QPainterPath *base_path = NULL;
    QPainterPath *back_path = NULL;
    base_path = new QPainterPath();
    back_path = new QPainterPath();
    QPen pen;                                 //创建一个画笔
    pen.setColor(Qt::red);
    pen.setWidth(2);
    QPainter painter2(this);
    QPen pen2;                                 //创建一个画笔
    pen2.setWidth(2);
    pen2.setColor(Qt::yellow);
    pen2.setStyle(Qt::SolidLine);
    painter2.setPen(pen2);
    painter2.setRenderHint(QPainter:: Antialiasing, true);

    //开始画Q部分
    if(!isHfpSelect){
        back_path->moveTo(0, m_height  / DB_NUMBER * 4);

    }else{
        if(!isHfpSelect && !isLfpSelect)
            back_path->moveTo(0, m_height/DB_NUMBER*4-mEqParams[m_iCurrent].pts[0]*20.5);

    }
    base_path->moveTo(0, m_height / (double)DB_NUMBER * 4- m_pSumY[0]*1.6);
    for (int i = 0 ; i < 1024; i ++) {
        double qq = mEqParams[m_iCurrent].pts[i];
        double hpf = m_pSumY[i];
        //qDebug()<<"qq="<<(m_height / DB_NUMBER * 4 - qq*20.5)<<qq*20.5;

        if ((m_height / DB_NUMBER * 4 - qq*20.5)  < m_height) {
            back_path->lineTo(m_width / 1024 * (double)i ,((double)this->height()) / DB_NUMBER * 4 - qq*20.5 );
        }else{
            if (isLfpSelect) {
                back_path->lineTo(((double)this->width()) / 1024 * (double)i ,(double)this->height());
            }
        }
        //qDebug()<<"xxxxxx"<<qq<<i;
        base_path->lineTo(m_width/1024.0 *(double)i, ((double)this->height()) / (double)DB_NUMBER * 4 - hpf*20.5);
    }

    //最后额外添加的点
    if(isLfpSelect){
        back_path->lineTo(0,m_height);
    }else{
        if(!isLfpSelect && !isHfpSelect)
            back_path->lineTo(0,m_height / DB_NUMBER * 4);
    }

    //给高通/低通添加多2个点
    if (isHfpSelect && mEqParams[m_iCurrent].pts[0] != 0) {
        back_path->lineTo(this->width(),this->height());
        back_path->lineTo(0,m_height);
    }
    if (isLfpSelect && mEqParams[m_iCurrent].pts[0] != 0) {
        back_path->lineTo(0,m_height);

    }
    //给EQ中HSEQ多1个点
    int typeEq = mEqParams[m_iCurrent].type;
    int typeSlect = mEqParams[m_iCurrent].filter;
    if (typeEq == 2 && typeSlect == 4) {
        back_path->lineTo(this->width(),11 + (this->height() -29) / DB_NUMBER * 4);
    }
    painter2.drawPath(*base_path);
    QColor color;
    color.setRgb(0,255,50,100);
    painter2.fillPath(*back_path,  QBrush(color));

}
//各种算法
void chlider_curve_view::setCalcEqeal(int YmEqNum,EqParam* YmEqParams,int current){

    if (current >= 0) {
        m_iCurrent = current;
    }else{
        m_iCurrent = 0;
    }
    //当前调节的
    mEqNum = YmEqNum;//总共段数
    //    m_iHPF = 1;
    m_iHPF = YmEqNum;//高通下标
    m_iLPF = YmEqNum + 1;//低通下标


    if (current == -1) {
        //        mEqParams = YmEqParams;
    } else if (current >= 0) {
        mEqParams[current] = YmEqParams[current];
    }

    for (int i = 0 ; i < 1024; i ++) {
        double qq = mEqParams[m_iCurrent].pts[i];
    }
    SetZeroXFreq(-1,current);

}
void chlider_curve_view::CalcYSum(){
    //未调用SetZeroXFreq设置频率的起点之前，不往下计算
    if ( m_fZeroXFreq < 0.0 )
        return;

    m_fMaxPoint = 0.0;
    double pt, pt2;
    for ( int i = 0; i < NUM_EQ_GRAPHIC_POINT; i++ )
    {
        pt = 0.0;
        for ( int k = 0; k < mEqNum; k++ )
        {
            pt += mEqParams[k].pts[i];
            //            NSLog(@"xxxxxxxxxxxxxx数据呀xxxxx%f----xx%d",mEqParams[k].pts[i],k);
            //             NSLog(@"xxxxxxxxxxxxxx数据呀xxxxx%f -----%d",mEqParams[k].pts[i],k);
        }

        {//高通1 低通1
            pt2 = pt;

            if ( m_iHPF >= 0 )
            {
                pt2 += mEqParams[m_iHPF].pts[i];
            }

            if ( m_iLPF >= 0 )
            {
                pt2 += mEqParams[m_iLPF].pts[i];
            }
            m_pSumY[i] = pt2;

            if ( pt2 > m_fMaxPoint )
                m_fMaxPoint = pt2;

        }
        //高通2 低通2
        if ( m_iHPF2 >= 0 || m_iLPF2 >= 0 )
        {
            pt2 = pt;
            if ( m_iHPF2 >= 0 )
                pt2 += mEqParams[m_iHPF2].pts[i];

            if ( m_iLPF2 >= 0 )
                pt2 += mEqParams[m_iLPF2].pts[i];

            m_pSumY2[i] = pt2;

            if ( pt2 > m_fMaxPoint )
                m_fMaxPoint = pt2;
        }
    }
}
void chlider_curve_view::CaclW(double freq){
    //只可设置一次
    if ( m_fZeroXFreq >= 0.0){
        return;
    }
    m_fZeroXFreq = freq;
    if ( m_fZeroXFreq < 10.0 )
        m_fZeroXFreq = 10.0;
    else if ( m_fZeroXFreq > 20.0 )
        m_fZeroXFreq = 20.0;
    double x0 = m_fZeroXFreq;
    double xn = FN;

    x0 = PI * x0 / FN;
    xn = PI * xn / FN;

    x0 = log10(x0);
    xn = log10(xn);

    double dx = (xn - x0) / NUM_EQ_GRAPHIC_POINT;
    double x;

    x = x0-dx;
    for ( int i = 0; i < NUM_EQ_GRAPHIC_POINT; i++ )
    {
        x += dx;
        m_w[i] = pow(10.0, x);
    }
}
void chlider_curve_view:: CalcCurvePoints(EqParam *param){
    //未调用SetZeroXFreq设置频率的起点之前，不往下计算
    if ( m_fZeroXFreq < 0.0 ){
        return;
    }

    //为提高效率，增益为0的都不计算
    if ( param->gain > -0.001 && param->gain < 0.001 )
    {
        for (int i = 0; i < NUM_EQ_GRAPHIC_POINT; i ++) {
            param->pts[i] = 0;
        }
        return;
    }
    double fcos_w, fcos_2w, fsin_w, fsin_2w;
    double w, bb0, bb1, aa0, aa1;

    double xN = param->gain / (-12.0);

    for ( int i = 0; i < NUM_EQ_GRAPHIC_POINT; i++ )
    {
        w = m_w[i];

        fcos_w = cos(-w);
        fcos_2w = cos(-2*w);
        fsin_w = sin(-w);
        fsin_2w = sin(-2*w);

        bb0 = param->b[0] + param->b[1] * fcos_w + param->b[2] * fcos_2w;
        aa0 = param->a[0] + param->a[1] * fcos_w + param->a[2] * fcos_2w;
        bb1 = param->b[1] * fsin_w + param->b[2] * fsin_2w;
        aa1 = param->a[1] * fsin_w + param->a[2] * fsin_2w;

        //                NSLog(@"--数据啊----x%f",20*log10(sqrt(bb0*bb0 + bb1*bb1) / sqrt(aa0*aa0 + aa1*aa1)));
        param->pts[i] = 20*log10(sqrt(bb0*bb0 + bb1*bb1) / sqrt(aa0*aa0 + aa1*aa1));
        switch ( param->filter )
        {
        case eLinkWitz_Riley:
        case eBessel:
        case eButterWorth:
        case eUserFilter:
            param->pts[i] *= xN;
            break;
        default:
            break;

        }
    }
}
bool chlider_curve_view::IsEqGainZero(int index){

    return ((mEqParams[index].gain > -0.01 &&
             mEqParams[index].gain < 0.01) ? true : false);
}
void chlider_curve_view::CalcFactor(EqParam *param){
    const double gainDb = 0.0;
    double omega = 2 * PI * param->freq / FS;
    double sn = sin(omega);
    double cs = cos(omega);
    switch (param->filter) {
    case eParametric:
    {
        double Ax = pow(10.0, param->gain/40.0);
        double alpha = sn / (2 * param->Q);
        double a0 = 1 + alpha / Ax;

        param->a[0] = 1;
        param->a[1] = -(2*cs)/a0;
        param->a[2] = (1-alpha/Ax)/a0;

        double gainlinear = pow(10.0, gainDb/20) / a0;

        param->b[0] = (1 + alpha * Ax) * gainlinear;
        param->b[1] = -(2*cs) * gainlinear;
        param->b[2] = (1-alpha*Ax)*gainlinear;
    }
        break;
    case eLinkWitz_Riley:
    {
        double alpha = sn / (2 / sqrt(2.0));
        double a0 = 1 + alpha;

        switch ( param->type )
        {
        case 0:

            break;

        case 1: //高通滤波器
        {
            param->a[0] = 1;
            param->a[1] = -2*cs/a0;
            param->a[2] = (1-alpha)/a0;

            param->b[1] = -(1+cs) * pow(10.0, gainDb/20) / a0;
            param->b[0] = -param->b[1] / 2;
            param->b[2] = param->b[0];
        }
            break;
        case 2: //低通滤波器
        {
            param->a[0] = 1;
            param->a[1] = -2*cs/a0;
            param->a[2] = (1-alpha)/a0;

            param->b[1] = (1-cs) * pow(10.0, gainDb/20) / a0;
            param->b[0] = param->b[1] / 2;
            param->b[2] = param->b[0];
        }
            break;
        }
    }
        break;
    case eBessel:
    {
        double alpha = sn/(2/sqrt(3.0));
        double a0 = 1+alpha;

        switch ( param->type )
        {
        case 0:
            break;

        case 1: //高通滤波器
        {
            param->a[0] = 1;
            param->a[1] = -2*cs/a0;
            param->a[2] = (1-alpha)/a0;

            param->b[1] = -(1+cs) * pow(10.0, gainDb/20) / a0;
            param->b[0] = -param->b[1] / 2;
            param->b[2] = param->b[0];
        }
            break;

        case 2: //低通滤波器
        {
            param->a[0] = 1;
            param->a[1] = -2*cs/a0;
            param->a[2] = (1-alpha)/a0;

            param->b[1] = (1-cs*pow(10.0, gainDb/20)) / a0;
            param->b[0] = param->b[1] / 2;
            param->b[2] = param->b[0];
        }
            break;
        }
    }
        break;
    case eButterWorth:
    {
        int i = 0;
        int orderIndex = 4;

        //double orderRangle = (pi/orderIndex)*(i+0.5);
        double alpha = (sn/(2*0.859));
        double a0 = 1+alpha;

        switch ( param->type )
        {
        case 0:
            //                    SASSERT(0);
            break;

        case 1: //高通滤波器
        {
            param->a[0] = 1;
            param->a[1] = -2*cs/a0;
            param->a[2] = (1-alpha)/a0;

            param->b[1] = -(1+cs) * pow(10.0, gainDb/20) / a0;
            param->b[0] = -param->b[1] / 2;
            param->b[2] = param->b[0];
        }
            break;

        case 2: //低通滤波器
        {
            param->a[0] = 1;
            param->a[1] = -2*cs/a0;
            param->a[2] = (1-alpha)/a0;

            param->b[1] = (1-cs)*pow(10.0, gainDb/20)/a0;
            param->b[0] = param->b[1] / 2;
            param->b[2] = param->b[0];
        }
            break;
        }


    }
        break;
    case eShelving:
    {


        double Q = param->Q2;
        double A = pow(10.0, param->gain/40);
        double alpha = sn/(2*Q);
        double beta = sqrt(2*A)/Q;

        param->a[0] = 1.0;
        param->a[1] = 0.0;
        param->a[2] = 0.0;
        param->b[0] = 1.0;
        param->b[1] = 0.0;
        param->b[2] = 0.0;

        if ( param->type == 1 )
        {
            double a0 = (A+1) + (A-1)*cs + beta*sn;

            param->a[0] = 1.0;
            param->a[1] = -2*((A-1)+(A+1)*cs)/a0;
            param->a[2] = ((A+1) + (A-1)*cs - beta*sn)/a0;

            param->b[0] = A*((A+1)-(A-1)*cs+beta*sn)/a0;
            param->b[1] = 2*A*((A-1)-(A+1)*cs)/a0;
            param->b[2] = A*((A+1)-(A-1)*cs - beta*sn)/a0;

        }
        else if ( param->type == 2)
        {
            double a0 = (A+1)-(A-1)*cs+beta*sn;

            param->a[0] = 1.0;
            param->a[1] = 2*((A-1)-(A+1)*cs)/a0;
            param->a[2] = ((A+1)-(A-1)*cs-beta*sn)/a0;

            param->b[0] = A*((A+1)+(A-1)*cs+beta*sn)/a0;
            param->b[1] = -2*A*((A-1)+(A+1)*cs)/a0;
            param->b[2] = A*((A+1)+(A-1)*cs - beta*sn)/a0;
        }


    }
        break;
    case eUserFilter:
    {

        double alpha = sn/(2*param->Q);
        double a0 = 1+alpha;

        switch ( param->type )
        {
        case 0:
            //                    SASSERT(0);
            break;

        case 1: //高通滤波器
        {
            param->a[0] = 1;
            param->a[1] = -2*cs/a0;
            param->a[2] = (1-alpha)/a0;

            param->b[1] = -(1+cs) * pow(10.0, gainDb/20) / a0;
            param->b[0] = -param->b[1] / 2;
            param->b[2] = param->b[0];
        }
            break;

        case 2: //低通滤波器
        {
            param->a[0] = 1;
            param->a[1] = -2*cs/a0;
            param->a[2] = (1-alpha)/a0;

            param->b[1] = (1-cs)*pow(10.0, gainDb/20) / a0;
            param->b[0] = param->b[1] / 2;
            param->b[2] = param->b[0];
        }
            break;
        }
    }
        break;

    default:
        break;
    }
}
void chlider_curve_view::SetZeroXFreq(double xZerofreq,int current){
    double freq = 0.0;
    CaclW(xZerofreq);
    for (int i = 0; i < 11; i ++) {

        //qDebug()<<"youwushuju"<<mEqParams[i].gain;

    }

    //重新计算各个点的值
    for (int i = 0; i < mEqNum; i++) {

        //        if (current == -1 || current == i) {

        //        NSLog(@"----要不要计算---%f",mEqParams[i].gain);
        freq = mEqParams[i].freq;

        //为提高效率，增益为0的都不计算
        if (!(IsEqGainZero(i))) {
            CalcFactor(&mEqParams[i]);
            CalcCurvePoints(&mEqParams[i]);
        }
        //        }
    }

    //高通
    if (m_iHPF != -1) {
        //        if (current == -1 || current == m_iHPF) {


        freq = mEqParams[m_iHPF].freq;
        if (freq >= MIN_EQ_FREQ && freq <= MAX_EQ_FREQ && !(IsEqGainZero(m_iHPF))) {
            CalcFactor(&mEqParams[m_iHPF]);
            CalcCurvePoints(&mEqParams[m_iHPF]);

        }
        //        }
    }

    //低通
    if (m_iLPF != -1) {

        //        if (current == -1 || current == m_iLPF) {

        freq = mEqParams[m_iLPF].freq;
        if (freq >= MIN_EQ_FREQ && freq <= MAX_EQ_FREQ && ! IsEqGainZero(m_iLPF)) {
            CalcFactor(&mEqParams[m_iLPF]);
            CalcCurvePoints(&mEqParams[m_iLPF]);
        }
        //        }
    }

    //高通2
    if (m_iHPF2 != -1) {

        //        if (current == -1 || current == m_iHPF2) {

        freq = mEqParams[m_iHPF2].freq;
        if (freq >= MIN_EQ_FREQ && freq <= MAX_EQ_FREQ && !IsEqGainZero(m_iHPF2)) {
            CalcFactor(&mEqParams[m_iHPF2]);
            CalcCurvePoints(&mEqParams[m_iHPF2]);
        }
        //        }
    }

    //低通2
    if (m_iLPF2 != -1) {
        //        if (current == -1 || current == m_iLPF2) {

        freq = mEqParams[m_iLPF2].freq;
        if (freq >= MIN_EQ_FREQ && freq <= MAX_EQ_FREQ && !IsEqGainZero(m_iLPF2)) {
            CalcFactor(&mEqParams[m_iLPF2]);
            CalcCurvePoints(&mEqParams[m_iLPF2]);
        }
        //        }
    }

    //各个点的叠加之和
    CalcYSum();
}
