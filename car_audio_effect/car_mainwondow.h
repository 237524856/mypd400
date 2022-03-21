#ifndef CAR_MAINWONDOW_H
#define CAR_MAINWONDOW_H

#include <QMainWindow>
#include "basewindow.h"
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
#include "carEffect/car_effect_mainview.h"
#include "car_leftview.h"
#include "car_rightview.h"
#include "car_midview.h"
#include "signal_view/main_signal_view.h"

class car_mainWondow : public basewindow
{
    Q_OBJECT
public:
    explicit car_mainWondow(QWidget *parent = nullptr);

    QMenu* menu[10];
    QAction* act[10];
    QMenuBar* menuBar ;
    QStatusBar* status ;

    void createUI();

    car_effect_mainView m_effect_mainView;
    main_signal_view m_signal_view;

    car_leftView *m_leftView;
    car_rightView *m_rightView;
    car_midView *m_mid_midView;


public slots:

    void m_trigerMenu(QAction* act);

signals:

};

#endif // CAR_MAINWONDOW_H
