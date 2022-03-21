#ifndef CAR_EFFECT_MAINVIEW_H
#define CAR_EFFECT_MAINVIEW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QCheckBox>
#include <QComboBox>

//#pragma once
#pragma execution_character_set("utf-8")
#include "myline_edit2.h"


class car_effect_mainView : public QMainWindow
{
    Q_OBJECT
public:
    explicit car_effect_mainView(QWidget *parent = nullptr);


    myline_edit2 *edit[31];
    myline_edit2 *edit2[31];
    myline_edit2 *edit3[31];
    QCheckBox *status_btn[31];

signals:

public slots:
    //键盘往上的方法
    void myline_edit_keyup(int);
    //键盘往下的方法
    void myline_edit_keydown(int);

};

#endif // CAR_EFFECT_MAINVIEW_H
