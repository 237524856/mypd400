#ifndef SHOW_LIST_VIEW_H
#define SHOW_LIST_VIEW_H

#include <QWidget>
#include "qdialog.h"
#include <QPushButton>
#include <QLabel>
#include <QMouseEvent>
#include <QLineEdit>
#include <QListWidget>
#include "custom_list_item.h"

class show_list_view : public QDialog
{
    Q_OBJECT
public:
    explicit show_list_view(QWidget *parent = nullptr);
    ~show_list_view();
    QListWidget *m_listWidget_default;

    void createUI();
    bool is_enter;

protected:
    QPoint move_point;                                    //移动的距离
    bool mouse_press;                                    //鼠标按下
    void mousePressEvent(QMouseEvent *qevent);            //鼠标按下事件
    void mouseReleaseEvent(QMouseEvent *qevent);         //鼠标释放事件
    void mouseMoveEvent(QMouseEvent *qevent);             //鼠标移动事件

    void enterEvent(QEvent *);                      //进入QWidget瞬间事件
    void leaveEvent(QEvent *);                      //离开QWidget瞬间事件


    //非活跃状态的
    virtual void focusOutEvent(QFocusEvent *e);


public slots:
    void audio_click(int);
    void select_item(QListWidgetItem*);

    void item_enter_clike();
    void item_leave_clike();

signals:

};

#endif // SHOW_LIST_VIEW_H
