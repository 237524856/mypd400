#ifndef CUSTOM_LIST_ITEM_H
#define CUSTOM_LIST_ITEM_H

#include <QWidget>
#include "sub_show_list_view.h"
#include <QTimer>


class custom_list_item : public QWidget
{
    Q_OBJECT
public:
    explicit custom_list_item(QWidget *parent = nullptr);
//    ~custom_list_item();

    sub_show_list_view *m_subView;

    //计时器
    QTimer *m_pTimer;
    QString m_str_name;
    QString m_str_leave_name;
    void enterEvent(QEvent *);                      //进入QWidget瞬间事件
    void leaveEvent(QEvent *);                      //离开QWidget瞬间事件

public slots:

     void handleTimeout();
signals:
    void item_enter();
    void item_leave();

};

#endif // CUSTOM_LIST_ITEM_H
