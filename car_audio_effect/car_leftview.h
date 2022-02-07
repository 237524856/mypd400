#ifndef CAR_LEFTVIEW_H
#define CAR_LEFTVIEW_H

#include <QWidget>
#include <QVector>
#include "myline_edit.h"

class car_leftView : public QWidget
{
    Q_OBJECT
public:
    explicit car_leftView(QWidget *parent = nullptr);

    void createUI();

    QVector<myline_edit *>mylines;
signals:

public slots:
    //键盘往上的方法
    void myline_edit_keyup(int);
    //键盘往下的方法
    void myline_edit_keydown(int);


};

#endif // CAR_LEFTVIEW_H
