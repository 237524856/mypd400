#ifndef CHLIDER_CURVE_VIEW_H
#define CHLIDER_CURVE_VIEW_H

#include <QWidget>
#include "dragpushbutton.h"
#include <QMap>

#define NUM_EQ_GRAPHIC_POINT     1024
#define eTabCount     12
#define PI    3.14159265358979
#define FS    48000
#define FN    24000
/* HPF_FREQ查询数据表 */
const uint32_t YY_FreqHPFx10[206] = {
    0,
    197,201,205,209,213,217,221,225,230,234,239,243,248,253,258,263,
    268,273,278,284,289,295,301,307,313,319,325,331,338,344,351,358,
    365,372,379,386,394,401,409,417,425,434,442,451,459,468,477,487,
    496,506,516,526,536,546,557,568,579,590,601,613,625,637,650,662,
    675,688,702,715,729,743,758,772,787,803,818,834,850,867,884,901,
    919,940,950,970,990,         // 0 ~ 85

    1010,1030,1050,1070,1090,1110,1140,1160,1180,1200,1230,1250,1270,1300,1320,1350,
    1380,1400,1430,1460,1490,1520,1540,1570,1610,1640,1670,1700,1730,1770,1800,1840,
    1870,1910,1950,1980,2020,2060,2100,2140,2180,2230,2270,2310,2360,2410,2450,2500,
    2550,2600,2650,2700,2750,2810,2860,2920,2970,3030,  //86 ~ 143

    3090,3150,3210,3270,3340,3400,3470,3540,3600,3670,3750,3820,3890,3970,4050,4120,
    4200,4290,4370,4450,4540,4630,4720,4810,4900,5000,5100,5200,5300,5400,5510,5610,
    5720,5830,5950,6060,6180,6300,6420,6550,6670,6800,6940,7070,7210,7350,7490,7640,
    7790,7940,8090,8250,8410,8570,8740,8910,9080,9260,9440,9620,9810,10000,     //144 ~ 205
};
/* LPF_FREQ查询数据表 */
const uint32_t YY_FreqLPF[66] = {
    5990,6110,6230,6350,6470,6660,6730,6860,6990,7130,7270,7410,7550,
    7700,7850,8000,8160,8310,8480,8640,8810,8980,9150,9330,9510,9700,
    9890,  // 0 ~ 26

    10100,10300,10500,10700,10900,11100,11300,11500,11800,12000,12200,
    12500,12700,12900,13200,13500,13700,14000,14300,14500,14800,15100,
    15400,15700,16000,16300,16600,17000,17300,17600,18000,18300,18700,
    19000,19400,19800,20200,                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            20600, 21000    // 26 ~ 66
};
/* EQ_FREQ查询数据表 数值x10 */
const uint32_t YY_Freqx10[362] = {
    197,201,205,209,213,217,221,225,230,234,239,243,248,253,258,263,
    268,273,278,284,289,295,301,307,313,319,325,331,338,344,351,358,
    365,372,379,386,394,401,409,417,425,434,442,451,459,468,477,487,
    496,506,516,526,536,546,557,568,579,590,601,613,625,637,650,662,
    675,688,702,715,729,743,758,772,787,803,818,834,850,867,884,901,
    919,940,950,970,990,                                             //0 ~ 84 (16*5+5=85个)

    1010,1030,1050,1070,1090,1110,1140,1160,1180,1200,1230,1250,1270,1300,1320,1350,
    1380,1400,1430,1460,1490,1520,1540,1570,1610,1640,1670,1700,1730,1770,1800,1840,
    1870,1910,1950,1980,2020,2060,2100,2140,2180,2230,2270,2310,2360,2410,2450,2500,
    2550,2600,2650,2700,2750,2810,2860,2920,2970,3030,//-----------------85~142
    3090,3150,3210,3270,3340,3400,
    3470,3540,3600,3670,3750,3820,3890,3970,4050,4120,4200,4290,4370,4450,4540,4630,
    4720,4810,4900,5000,5100,5200,5300,5400,5510,5610,5720,5830,5950,6060,6180,6300,
    6420,6550,6670,6800,6940,7070,7210,7350,7490,7640,7790,7940,8090,8250,8410,8570,//85~196 (16*7=112个）

    8740,8910,9080,9260,9440,9620,9810,10000,//-----------------
    10200,10400,10600,10800,11000,11200, //197~210 （14个）

    11400,11700,11900,12100,12400,12600,12800,13100,13300,13600,13900,14100,14400,
    14700,15000,15300,15600,15900,16200,16500,16800,17100,17500,17800,18200,18500,
    18900,19200,19600,20000,20400,20800,21200,21600,22000,22400,22900,23300,23800,
    24200,24700,25200,25700,26200,26700,27200,27700,28300,28800,29400,30000,30500,
    31100,31700,32400,33000,33600,34300,35000,35600,36300,37000,37800,38500,39200,
    40000,40800,41600,42400,43200,44000,44900,45800,46700,47600,48500,49400,50400,
    51400,52400,53400,54400,55500,56600,57700,58800,59900,61100,62300,63500,64700,
    66000,67300,68600,69900,71300,72700,74100,75500,77000,78500,80000,81600,83100,//211~314（13*8=104）

    84800,86400,88100,89800,91500,93300,95100,97000,98900,101000,103000,105000,//315~326 (12)

    107000,109000,111000,113000,115000,118000,120000,122000,125000,127000,129000,
    132000,135000,137000,140000,143000,145000,148000,151000,154000,157000,160000,
    163000,166000,170000,173000,176000,180000,183000,187000,190000,194000,198000, //327~361 （11*3+2=35）

    202000,206000
};
/* Q值查询数据表 */
const uint16_t YY_Qx100[101] = {
    40,42,45,47,50,53,56,59,63,67,71,75,79,
    84,89,94,100,106,112,119,126, //0 ~ 20

    130,140,150,160,170,180,190,200, //21-28

    210,220,240,250,270,280,300,320,340,360,380,400,420,
    450,480,500,530,570,600,630,670,710,760,800,850,900,
    950,1010,1070,1130,1200,1270,1350, //29 ~ 61

    1400,1500,1600,1700,1800,1900,2000,2100,2300,2400,
    2500,2700,2900,3000,3200,3400,3600,3800,4000,4300,
    4500,4800,5100,5400,5700,6000,6400,6800,7200,7600,
    8100,8500,9100,9600,10200,10800,11400,12100,12800 //62 ~ 100
};

typedef enum FILTER_TYPE_name{
    eParametric,//p
    eLinkWitz_Riley, //林氏滤波器
    eBessel,//贝塞尔
    eButterWorth, //巴特沃斯
    eShelving,//自定义的那2中类型////LS HS
    eUserFilter//Eq增益的类型
}FILTER_TYPE;
typedef struct EqParam_s
{
    int    type; //0--峰值  1--高通  2--低通
    int    filter; //滤波器类型，取ENUM_FILTER_TYPE中的值
    double freq;//滤波器的频率
    double gain;
    double Q;//p
    double Q2;//LS HS

    double a[3];
    double b[3];
    double pts[1024];  //各个点的系数//显示的是灰色的点

    double a2[3]; //用于两级串联的情况
    double b2[3];
}EqParam;

typedef struct pass_eq_s
{
    int freq;//滤波器的频率
    double gain;
    double Q;//p

    int zoom_space;

}pass_eq;

class chlider_curve_view : public QWidget
{
    Q_OBJECT
public:
    explicit chlider_curve_view(QWidget *parent = nullptr);

    void  paintEvent(QPaintEvent *event);

    void set_location(QPoint mouse_point);

    void createUI();


    QPoint m_mouse_point;
    //左边按钮的坐标
    QPoint m_leftmouse_point;
    QPoint m_oldleftmouse_point;
    //右边按钮的坐标
    QPoint m_rightmouse_point;
    //没有左右拖动的
    QString m_current_btnName;

    int btn_spaceX;

    QString m_selectcurrent_btnName;
    //算法的各种画线
    EqParam mEqParams[30];
    pass_eq m_pass_eq[30];

    void setCalcEqeal(int YmEqNum,EqParam* YmEqParams,int current);
    void CalcYSum();
    void CaclW(double freq);
    void CalcCurvePoints(EqParam *param);
    bool IsEqGainZero(int index);
    void CalcFactor(EqParam *param);
    void SetZeroXFreq(double xZerofreq,int current);



    double MIN_EQ_FREQ = 19.7;
    double MAX_EQ_FREQ = 20600;
    double c_log10 ;
    double c_logfn  = log10(FS/2.0);

    int m_iCurrent;//当前调节的是哪一段EQ    -1  全部重新计算  大于0  对应的段数

    double m_fMaxPoint;
    int mEqNum = 15;//15段eq


    //EqParam mEqParams[3];//eq 频段  +  高通1 低通1  高通2 低通2

    int m_iHPF = -1; //hpf在m_pEqParam中的index
    int m_iLPF = -1;//lpf在m_pEqParam中的index

    int m_iHPF2 = -1; //hpf2在m_pEqParam中的index
    int m_iLPF2 = -1;//lpf2在m_pEqParam中的index

    double m_pSumY[1024];   //Y轴上各个点是系数之和, 高通1，低通1 //显示的是亮色的点
    double m_pSumY2[1024];  //Y轴上各个点是系数之和, 高通2，低通2 //实际上用不到

    QMap<int,int>m_select_btn_numbers;

    double m_fZeroXFreq = -1.0;
    double  m_w[1024];

    double curverWidth = 571;


    //自身用的视图

    void create_datasource(int freq,double gain,int select_btn_tag);

    /**
     每组各添加2组数据，一个高通一个低通
     单独设置高通或者低通
     */
    void addEffectEparamsTwoHFilter_Freq(int HFilter_Freq,int LFilter_Freq,QVector<double>EQArrs,QVector<double>gainArrs,int alltotalNum);
    //设置高通低通
    void createEQpointView(QVector<double>EQtotalNumerArrs,QVector<double>gainArrs,
                           QVector<double>QArrs,QVector<double>Q2Arrs,QVector<double>EQModelArrs,int eqIndex);

    void update_datasource();

    int btnSelectNumber;//点击来那个按钮

    int totalNumber;//点击来那个按钮

    bool isHfpSelect;//是否选择了高通

    bool isLfpSelect;//是否选择了低高通

    int eqs;//判断交叉点
    double m_moveX;//视图移动了多少
    int m_selectIndex;//选中了EQ那段

     QVector<dragpushbutton *> mybuttons;
     QVector<double>m_bottomlabel_spaces;
     QVector<int>m_bottomtitleArrs;

     //保存各种参数，用于EQ_btn调节位置
     QVector<double>m_EQArrs;
     QVector<double>m_gainArrs;
     QVector<double>m_QArrs;
     QVector<double>m_Q2Arrs;
     QVector<double>m_EQModeleArrs;

     //由X坐标值转换为频率，X坐标是以整个窗口客户区的左上角为原点
     double X2Freq(int x);
     double m_fLogZeroFreq ;
     double scaleX;

const int g_Slope[9] = { -6, -12, -18, -24, -30, -36, -42, -48, 0 };
public slots:

    void receive_btn_location(QPoint,QString);
    //按钮按下去的方法
    void receive_btnpress_location(QPoint,QString);
signals:

};

#endif // CHLIDER_CURVE_VIEW_H
