#ifndef SUB_SHOW_LIST_VIEW_H
#define SUB_SHOW_LIST_VIEW_H

#include <QWidget>
#include "qdialog.h"
#include <QPushButton>
#include <QLabel>
#include <QMouseEvent>
#include <QLineEdit>
#include <QListWidget>

class sub_show_list_view : public QDialog
{
    Q_OBJECT
public:
    explicit sub_show_list_view(QWidget *parent = nullptr);

    QListWidget *m_listWidget_default;

    bool is_sub_enter;

    void enterEvent(QEvent *);                      //进入QWidget瞬间事件
    void leaveEvent(QEvent *);                      //离开QWidget瞬间事件

    void createUI();

signals:

};

#endif // SUB_SHOW_LIST_VIEW_H
