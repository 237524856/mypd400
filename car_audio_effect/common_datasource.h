#ifndef COMMON_DATASOURCE_H
#define COMMON_DATASOURCE_H

#include <QObject>
#include <QVector>
#include <QPushButton>
#include "show_list_view.h"

extern QVector<int>volumes;

extern QVector<QPushButton *>shuru_btns;

extern show_list_view *m_overshow_list_view;

//选中了那个输入的btn
extern int shuru_btn_index;

#endif // COMMON_DATASOURCE_H
