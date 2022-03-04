#ifndef CUSTOM_LIST_ITEM_H
#define CUSTOM_LIST_ITEM_H

#include <QWidget>


class custom_list_item : public QWidget
{
    Q_OBJECT
public:
    explicit custom_list_item(QWidget *parent = nullptr);

    void enterEvent(QEvent *);                      //进入QWidget瞬间事件
    void leaveEvent(QEvent *);                      //离开QWidget瞬间事件
signals:

};

#endif // CUSTOM_LIST_ITEM_H
