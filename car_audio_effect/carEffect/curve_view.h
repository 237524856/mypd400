#ifndef CURVE_VIEW_H
#define CURVE_VIEW_H

#include <QWidget>
#include <QVector>
#include "dragpushbutton.h"
#include <QLabel>
#include "chlider_curve_view.h"




class curve_view : public QWidget
{
    Q_OBJECT
public:
    explicit curve_view(QWidget *parent = nullptr);
    void createUI();

    chlider_curve_view* m_chlider_view ;
    QPoint m_mouse_point;
    QVector<dragpushbutton *> mybuttons;
    //保存freq的距离
    QVector<double>m_spaces;

    QVector<double>m_bottomlabel_spaces;

    QVector<int>m_bottomtitleArrs;


signals:

public slots:

    //void receive_btn_location(QPoint,QString);


};
class CEqData{
public:
    CEqData();
    ~CEqData();
public:
    //BOOL Init(const PK_Filter_UI *pParam, int nParam);
    bool Init(const EqParam *pParam, int nParam);
protected:
//    EqParam* GetEqData() { return m_pEqParam; }




};
#endif // CURVE_VIEW_H
