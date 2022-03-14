#ifndef SUB_CUSTOM_LIST_ITEM_H
#define SUB_CUSTOM_LIST_ITEM_H

#include <QWidget>
#include <QMouseEvent>

class sub_custom_list_item : public QWidget
{
    Q_OBJECT
public:
    explicit sub_custom_list_item(QWidget *parent = nullptr);

    void mousePressEvent(QMouseEvent *qevent);            //鼠标按下事件
    void mouseReleaseEvent(QMouseEvent *qevent);         //鼠标释放事件
    void mouseMoveEvent(QMouseEvent *qevent);             //鼠标移动事件
    void enterEvent(QEvent *);                      //进入QWidget瞬间事件
    void leaveEvent(QEvent *);                      //离开QWidget瞬间事件

signals:

};

#endif // SUB_CUSTOM_LIST_ITEM_H
