#ifndef CAR_LEFTVIEW_H
#define CAR_LEFTVIEW_H

#include <QWidget>
#include <QVector>
#include "myline_edit.h"
#include <QListWidget>
#include "show_list_view.h"

#include <QMouseEvent>

class car_leftView : public QWidget
{
    Q_OBJECT
public:
    explicit car_leftView(QWidget *parent = nullptr);

    void createUI();

    QVector<myline_edit *>mylines;

    QListWidget *m_listWidget_default;

    show_list_view *m_show_list_view;

    void mousePressEvent(QMouseEvent *qevent);            //鼠标按下事件

signals:

public slots:
    //键盘往上的方法
    void myline_edit_keyup(int);
    //键盘往下的方法
    void myline_edit_keydown(int);

    void shuru_click();


};

#endif // CAR_LEFTVIEW_H
